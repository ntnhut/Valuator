#include "Expression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include <iostream>

int main() {
    Constant two(2);
    Constant three(3);
    Constant four(4);
    Constant five(5);
    Constant six(6);
    Constant nine(9);
    Constant ten(10);
   
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
        Multiplication result;
        Addition a;
        a.addItem(&two);
        a.addItem(&three);
        a.addItem(&four);
        result.addFactor(&a);
        result.addFactor(&six);
        Multiplication m;
        m.addFactor(&three);
        m.addFactor(&four);
        m.addFactor(&five);
        m.addFactor(&ten);
        Constant fivesix(56);
        m.addFactor(&fivesix);
        result.addFactor(&m);
        const int factora = two.value() + three.value() + four.value();
        const int factorm = three.value() * four.value() * five.value() * ten.value() * fivesix.value();
        const int answer = factora * six.value() * factorm;
        if (result.value() != answer) {
            std::cout<< "result of (2+3+4)*6*(3*4*5*10*56) should be " << answer << ", received " << result.value() << "\n";
        }
    }
}