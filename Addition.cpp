#include "Addition.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/foreach.hpp>
namespace pt = boost::property_tree;

int Addition::value() const {
    int result(0);
    for (const Expression* i : _items) {
        result+=i->value();
    }
    return result;
}

Addition::~Addition() {
    for (auto i:_items) {
        if (i!=nullptr) delete i;
    }
    _items.clear();
}

Addition::Addition(const pt::ptree::value_type& v) {
    BOOST_FOREACH(const pt::ptree::value_type &vv, v.second.get_child("")) {
        if (vv.first=="item") {
            Expression* e = Valuator::createExpression(vv);
            addItem(e);
        }
    }
}
