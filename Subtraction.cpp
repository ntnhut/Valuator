#include "Subtraction.h"
#include <boost/property_tree/ptree.hpp>
namespace pt = boost::property_tree;
#include <boost/foreach.hpp>

Subtraction::~Subtraction() {
    if (_subtrahend!=nullptr) delete _subtrahend;
    if (_minuend!=nullptr) delete _minuend;
}

Subtraction::Subtraction(const boost::property_tree::ptree::value_type& v) {
    BOOST_FOREACH(const pt::ptree::value_type &vv, v.second.get_child("")) {
        if (vv.first=="minuend") {
            Expression* e = Valuator::createExpression(vv);
            setMinuend(e);
        } else if (vv.first=="subtrahend") {
            Expression* e = Valuator::createExpression(vv);
            setSubtrahend(e);
        }    
    }
}