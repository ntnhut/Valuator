#include "Subtraction.h"
#include <boost/property_tree/ptree.hpp>

Subtraction::~Subtraction() {
    if (_subtrahend != nullptr) {
        delete _subtrahend;
    }
    if (_minuend != nullptr) {
        delete _minuend;
    }
}

Subtraction::Subtraction(const boost::property_tree::ptree::value_type& v) {
    for (const boost::property_tree::ptree::value_type &w : v.second.get_child("")) {
        if (w.first == "minuend") {
            Expression* e = Valuator::createExpression(w);
            setMinuend(e);
        } else if (w.first == "subtrahend") {
            Expression* e = Valuator::createExpression(w);
            setSubtrahend(e);
        }    
    }
}