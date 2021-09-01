#include "Expression.h"

class Division : public Expression {
public:
    Division() {}
    ~Division();
    int value() const { 
        if (_dividend==nullptr || _divisor==nullptr || _divisor->value()==0) {
            return 0; 
        }
        return _dividend->value() / _divisor->value(); 
    }
    void setDividend(const Expression* m) { 
        _dividend = m; 
    }
    void setDivisor(const Expression* s) { 
        _divisor = s; 
    }

private:
    const Expression* _dividend;
    const Expression* _divisor;
};
