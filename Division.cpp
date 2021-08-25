#include "Division.h"
#include "Valuator.h"

Division::~Division() {
    if (_dividend != nullptr) {
        delete _dividend;
    }
    if (_divisor != nullptr) {
        delete _divisor;
    }
}

Division::Division(const boost::property_tree::ptree::value_type& v) {
    for (const boost::property_tree::ptree::value_type &w : v.second.get_child("")) {
        if (w.first == "dividend") {
            Expression* e = Valuator::createExpression(w);
            setDividend(e);
        } else if (w.first == "divisor") {
            Expression* e = Valuator::createExpression(w);
            setDivisor(e);
        }   
    }
}

