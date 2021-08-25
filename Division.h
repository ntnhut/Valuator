#include "Expression.h"
#include <boost/property_tree/ptree.hpp>

class Division : public Expression {
public:
    Division(const int id=0, const bool complex=false): _id(id), _complex(complex) {}
    Division(const boost::property_tree::ptree::value_type& v);
    ~Division();
    int value() const { 
        return _dividend->value() / _divisor->value(); 
    }
    void setDividend(const Expression* m) { 
        _dividend = m; 
    }
    void setDivisor(const Expression* s) { 
        _divisor = s; 
    }

private:
    int _id;
    bool _complex;
    const Expression* _dividend;
    const Expression* _divisor;
};
