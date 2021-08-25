#include "Expression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

namespace pt = boost::property_tree;

Expression* Valuator::createExpression(const pt::ptree::value_type& v) {
    if (v.second.empty()) {
        Constant* c = new Constant(std::stoi(v.second.data()));
        return c;
    }
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
    auto subexp = v.second.get_child("").front();
    return createExpression(subexp);
}

int main(int argc, char *argv[]) {

    pt::ptree inputTree;
    pt::ptree outputTree;
    pt::read_xml(argv[1], inputTree);

    BOOST_FOREACH(pt::ptree::value_type &v, inputTree.get_child("expressions")) {
    
        std::string id = v.second.get_child("<xmlattr>.id").data();
        Expression* e = Valuator::createExpression(v);
        if (e!=nullptr) {
            pt::ptree& result = outputTree.add("expressions.result", e->value());
            result.put("<xmlattr>.id", id);
        }
        delete e;
    }

    pt::write_xml(argv[2], outputTree);
}