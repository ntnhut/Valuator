#include "Valuator.h"
#include <boost/property_tree/xml_parser.hpp>

namespace pt = boost::property_tree;

Addition* Valuator::createAddition(const boost::property_tree::ptree::value_type& v) {
    Addition* a = new Addition;
    for (const boost::property_tree::ptree::value_type &w : v.second.get_child("")) {
        if (w.first == "item") {
            Expression* e = createExpression(w);
            a->addItem(e);
        }
    }
    return a;
}


Division* Valuator::createDivision(const boost::property_tree::ptree::value_type& v) {
    Division* d = new Division;
    for (const boost::property_tree::ptree::value_type &w : v.second.get_child("")) {
        if (w.first == "dividend") {
            Expression* e = createExpression(w);
            d->setDividend(e);
        } else if (w.first == "divisor") {
            Expression* e = createExpression(w);
            d->setDivisor(e);
        }   
    }
    return d;
}


Multiplication* Valuator::createMultiplication(const boost::property_tree::ptree::value_type& v) {
    Multiplication* m = new Multiplication;
    for (const boost::property_tree::ptree::value_type &w : v.second.get_child("")) {
        if (w.first == "factor") {
            Expression* e = createExpression(w);
            m->addFactor(e);
        }    
    }
    return m;
}

Subtraction* Valuator::createSubtraction(const boost::property_tree::ptree::value_type& v) {
    Subtraction* s = new Subtraction;
    for (const boost::property_tree::ptree::value_type &w : v.second.get_child("")) {
        if (w.first == "minuend") {
            Expression* e = createExpression(w);
            s->setMinuend(e);
        } else if (w.first == "subtrahend") {
            Expression* e = createExpression(w);
            s->setSubtrahend(e);
        }    
    }
    return s;
}

//! @brief: create the expression given an xml structure 
Expression* Valuator::createExpression(const boost::property_tree::ptree::value_type& v) {

    // if the field has no child, it contains only the constant
    // for example <item>3</item>
    if (v.second.empty()) {
        return new Constant(std::stoi(v.second.data()));
    }
    // <addition>...</addition>
    if (v.first == "addition") {
        return createAddition(v);

    } else if (v.first == "subtraction") {
        return createSubtraction(v);

    } else if (v.first == "multiplication") {
        return createMultiplication(v);

    } else if (v.first == "division") {
        return createDivision(v);
    }
    // if the child is another expression 
    // for example <item><subtraction>...</subtraction></item>
    auto subexp = v.second.get_child("").front();
    return createExpression(subexp);
}

void Valuator::evaluate(const std::string& inputFileName, const std::string& outputFileName) {
    pt::ptree inputTree;
    pt::read_xml(inputFileName, inputTree);

    pt::ptree outputTree;
    for (pt::ptree::value_type &v : inputTree.get_child("expressions")) {

        std::string id = v.second.get_child("<xmlattr>.id").data();
        Expression* e = Valuator::createExpression(v);
        if (e != nullptr) {
            pt::ptree& result = outputTree.add("expressions.result", e->value());
            result.put("<xmlattr>.id", id);
            delete e;
        }  
    }

    pt::write_xml(outputFileName, outputTree);
}
