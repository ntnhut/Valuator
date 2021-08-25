#include "Valuator.h"
#include "Expression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <boost/property_tree/ptree.hpp>

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
