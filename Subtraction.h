#include "Expression.h"
#include "Valuator.h"

class Subtraction : public Expression {
public:
    Subtraction(const int id=0, const bool complex=false): _id(id), _complex(complex) {}
    Subtraction(const boost::property_tree::ptree::value_type& v);
    ~Subtraction();
    int value() const { 
        return _minuend->value() - _subtrahend->value(); 
    }
    void setMinuend(const Expression* m) { 
        _minuend = m; 
    }
    void setSubtrahend(const Expression* s) { 
        _subtrahend = s; 
    }

private:
    int _id;
    bool _complex;
    const Expression* _minuend;
    const Expression* _subtrahend;
};
