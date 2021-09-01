#include "Expression.h"
#include <vector>

class Addition : public Expression {
public:
    Addition() {}
    ~Addition();
    int value() const;
    void addItem(const Expression* exp) {
        _items.push_back(exp); 
    }
private:
    std::vector<const Expression*> _items;
};
