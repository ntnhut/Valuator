#include "Expression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <iostream>

int main() {
    Constant one(1);
    Constant two(2);
    Constant three(3);
    Constant four(4);
    Constant five(5);
    Constant six(6);
    Constant seven(7);
    Constant eight(8);
    Constant nine(9);
    Constant ten(10);
    {
        Addition s(2,false);
        s.addItem(&one);
        s.addItem(&two);
        if (s.value()!=3) {
            std::cout<<"result of 1+2 should be 3, received "<< s.value() <<"\n";
        }
    }
    {
        Subtraction su(3,false);
        su.setMinuend(&two);
        su.setSubtrahend(&one);
        if (su.value()!=1) {
            std::cout<<"result of 2-1 should be 1, received "<<su.value() <<"\n";
        }
    }
    {
        Multiplication m(4, false);
        
        m.addFactor(&two);
        m.addFactor(&five);
        if (m.value()!=10) {
            std::cout<<"result of 2*5 should 10, received "<<m.value() <<"\n";
        }
    }    
    {
        Division d(5, false);
        d.setDividend(&ten);
        d.setDivisor(&two);
        if (d.value()!=5) {
            std::cout<<"result of 10/2 should be 5, received "<<d.value() <<"\n";
        }
    }
    {
        Addition a(10, true);
        a.addItem(&two);
        Subtraction s(11, false);
        s.setMinuend(&nine);
        s.setSubtrahend(&six);
        a.addItem(&s);
        if (a.value()!=5) {
            std::cout<< "result of 2+(9-6) should be 5, received " << a.value() << "\n";
        }
    }
    {
        Multiplication m(13, true);
        Addition a(21, false);
        a.addItem(&two);
        a.addItem(&three);
        a.addItem(&four);
        m.addFactor(&a);
        m.addFactor(&six);
        Multiplication mm(100, false);
        mm.addFactor(&three);
        mm.addFactor(&four);
        mm.addFactor(&five);
        mm.addFactor(&ten);
        Constant fivesix(56);
        mm.addFactor(&fivesix);
        m.addFactor(&mm);
        if (m.value()!=1814400) {
            std::cout<< "result of (2+3+4)*6*(3*4*5*10*56) should be 1814400, received " << m.value() << "\n";
        }
    }
    {
        Addition* a = new Addition();
        Constant* oneseven = new Constant(177);
        a->addItem(oneseven);
        Expression* e = a;
        std::cout<< e->value();
        delete oneseven;
        delete a;
    }
}