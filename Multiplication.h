#include "Expression.h"
#include <vector>

class Multiplication : public Expression {
public:
    Multiplication() {}
    ~Multiplication();
    int value() const;
    void addFactor(const Expression* f) { 
        _factors.push_back(f); 
    }

private:
    std::vector<const Expression*> _factors;
};
