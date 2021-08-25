#include "Multiplication.h"
#include "Valuator.h"

int Multiplication::value() const {
    int result(1);
    for (const Expression* f : _factors) {
        result *= f->value();
    }
    return result;
}

Multiplication::~Multiplication() {
    for (const Expression* f: _factors) {
        if (f != nullptr) {
            delete f;
        }
    }
    _factors.clear();
}

Multiplication::Multiplication(const boost::property_tree::ptree::value_type& v) {
    for (const boost::property_tree::ptree::value_type &w : v.second.get_child("")) {
        if (w.first == "factor") {
            Expression* e = Valuator::createExpression(w);
            addFactor(e);
        }    
    }
}
