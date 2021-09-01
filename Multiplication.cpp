#include "Multiplication.h"

int Multiplication::value() const {
    int result(1);
    for (const Expression* f : _factors) {
        if (f==nullptr) continue;
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
