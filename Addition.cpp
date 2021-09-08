#include "Addition.h"

int Addition::value() const {
    int result(0);
    for (const Expression* i : _items) {
        if (i==nullptr) {
            continue;
        }
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