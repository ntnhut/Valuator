#include "Division.h"
#include "Valuator.h"

namespace pt = boost::property_tree;
#include <boost/foreach.hpp>

Division::~Division() {
    if (_dividend!=nullptr) delete _dividend;
    if (_divisor!=nullptr) delete _divisor;
}

Division::Division(const boost::property_tree::ptree::value_type& v) {
    BOOST_FOREACH(const pt::ptree::value_type &vv, v.second.get_child("")) {
        if (vv.first=="dividend") {
            Expression* e = Valuator::createExpression(vv);
            setDividend(e);
        } else if (vv.first == "divisor") {
            Expression* e = Valuator::createExpression(vv);
            setDivisor(e);
        }   
    }
}

