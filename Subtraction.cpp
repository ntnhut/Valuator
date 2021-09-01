#include "Subtraction.h"

Subtraction::~Subtraction() {
    if (_subtrahend != nullptr) {
        delete _subtrahend;
    }
    if (_minuend != nullptr) {
        delete _minuend;
    }
}
