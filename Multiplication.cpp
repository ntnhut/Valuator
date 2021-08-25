#include "Multiplication.h"

namespace pt = boost::property_tree;
#include <boost/foreach.hpp>
#include "Valuator.h"

int Multiplication::value() const {
    int result(1);
    for (const Expression* f : _factors) {
        result*=f->value();
    }
    return result;
}

Multiplication::~Multiplication() {
    for (auto f: _factors) {
        if (f!=nullptr) delete f;
    }
    _factors.clear();
}

Multiplication::Multiplication(const pt::ptree::value_type& v) {
    BOOST_FOREACH(const pt::ptree::value_type &vv, v.second.get_child("")) {
        if (vv.first=="factor") {
            Expression* e = Valuator::createExpression(vv);
            addFactor(e);
        }    
    }
}

