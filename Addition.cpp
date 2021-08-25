#include "Addition.h"
#include "Valuator.h"

int Addition::value() const {
    int result(0);
    for (const Expression* i : _items) {
        result += i->value();
    }
    return result;
}

Addition::~Addition() {
    for (const Expression* i : _items) {
        if (i != nullptr) {
            delete i;
        }
    }
    _items.clear();
}

Addition::Addition(const boost::property_tree::ptree::value_type& v) {
    for (const boost::property_tree::ptree::value_type &w : v.second.get_child("")) {
        if (w.first == "item") {
            Expression* e = Valuator::createExpression(w);
            addItem(e);
        }
    }
}
