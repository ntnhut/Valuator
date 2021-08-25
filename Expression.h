#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
    virtual int value() const { return 0; }  
};

class Constant : public Expression {
public:
    Constant(const int v=0) : _value(v) {}
    void setValue(const int v) {
        _value = v;
    }
    int value() const { 
        return _value; 
    }
private:
    int _value;
};

#endif