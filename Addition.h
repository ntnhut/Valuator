#include "Expression.h"
#include "Valuator.h"

class Addition : public Expression {
public:
    Addition(const int id=0, const bool complex=false): _id(id), _complex(complex) {
        _items.clear();
    }
    Addition(const boost::property_tree::ptree::value_type& v);
    ~Addition();
    int value() const;
    void addItem(const Expression* exp) { _items.push_back(exp); }
private:
    int _id;
    bool _complex;
    std::vector<const Expression*> _items;
};
