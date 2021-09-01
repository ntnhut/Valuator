#include "Expression.h"

class Subtraction : public Expression {
public:
    Subtraction() {}
    ~Subtraction();
    int value() const { 
        if (_minuend==nullptr || _subtrahend==nullptr) {
            return 0;
        }
        return _minuend->value() - _subtrahend->value(); 
    }
    void setMinuend(const Expression* m) { 
        _minuend = m; 
    }
    void setSubtrahend(const Expression* s) { 
        _subtrahend = s; 
    }

private:
    const Expression* _minuend;
    const Expression* _subtrahend;
};
