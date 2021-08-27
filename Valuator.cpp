#include "Valuator.h"
#include "Expression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace pt = boost::property_tree;

//! @brief: create the expression given an xml structure 
Expression* Valuator::createExpression(const boost::property_tree::ptree::value_type& v) {

    // if the field has no child, it contains only the constant
    // for example <item>3</item>
    if (v.second.empty()) {
        Constant* c = new Constant(std::stoi(v.second.data()));
        return c;
    }
    // <addition>...</addition>
    if (v.first == "addition") {
        Addition* a = new Addition(v);
        return a;

    } else if (v.first == "subtraction") {
        Subtraction* s = new Subtraction(v);
        return s;

    } else if (v.first == "multiplication") {
        Multiplication* m = new Multiplication(v);
        return m;

    } else if (v.first == "division") {
        Division* d = new Division(v);
        return d;
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
        }  
        delete e;
    }

    pt::write_xml(outputFileName, outputTree);
}
