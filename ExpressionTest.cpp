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
        Addition a;
        a.addItem(&one);
        a.addItem(&two);
        const int answer = one.value() + two.value();
        if (a.value() != answer) {
            std::cout << "result of 1+2 should be " << answer << ", received " << a.value() << "\n";
        }
    }
    {
        Subtraction s;
        s.setMinuend(&two);
        s.setSubtrahend(&one);
        const int answer = two.value() - one.value();
        if (s.value() != answer) {
            std::cout<<"result of 2-1 should be " << answer << ", received " << s.value() << "\n";
        }
    }
    {
        Multiplication m;        
        m.addFactor(&two);
        m.addFactor(&five);
        const int answer = two.value() * five.value();
        if (m.value() != answer) {
            std::cout<<"result of 2*5 should be " << answer << ", received " << m.value() <<"\n";
        }
    }    
    {
        Division d;
        d.setDividend(&ten);
        d.setDivisor(&two);
        const int answer = ten.value() / two.value();
        if (d.value() != answer) {
            std::cout<<"result of 10/2 should be " << answer << ", received "<< d.value() <<"\n";
        }
    }
    {
        Addition a;
        a.addItem(&two);
        Subtraction s;
        s.setMinuend(&nine);
        s.setSubtrahend(&six);
        a.addItem(&s);
        const int answer = two.value() + (nine.value() - six.value());
        if (a.value() != answer) {
            std::cout<< "result of 2+(9-6) should be " << answer << ", received " << a.value() << "\n";
        }
    }
    {
        Multiplication m;
        Addition a;
        a.addItem(&two);
        a.addItem(&three);
        a.addItem(&four);
        m.addFactor(&a);
        m.addFactor(&six);
        Multiplication m2;
        m2.addFactor(&three);
        m2.addFactor(&four);
        m2.addFactor(&five);
        m2.addFactor(&ten);
        Constant fivesix(56);
        m2.addFactor(&fivesix);
        m.addFactor(&m2);
        const int factora = two.value() + three.value() + four.value();
        const int factorm2 = three.value() * four.value() * five.value() * ten.value() * fivesix.value();
        const int answer = factora * six.value() * factorm2;
        if (m.value() != answer) {
            std::cout<< "result of (2+3+4)*6*(3*4*5*10*56) should be " << answer << ", received " << m.value() << "\n";
        }
    }
}