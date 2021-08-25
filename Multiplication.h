#include "Expression.h"
#include <boost/property_tree/ptree.hpp>
class Multiplication : public Expression {
public:
    Multiplication(const int id=0, const bool complex=false): _id(id), _complex(complex) {
        _factors.clear();
    }
    Multiplication(const boost::property_tree::ptree::value_type& v);
    ~Multiplication();
    int value() const;
    void addFactor(const Expression* f) { _factors.push_back(f); }

private:
    int _id;
    bool _complex;
    std::vector<const Expression*> _factors;
};
