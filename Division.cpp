#include "Division.h"

Division::~Division() {
    if (_dividend != nullptr) {
        delete _dividend;
    }
    if (_divisor != nullptr) {
        delete _divisor;
    }
}
