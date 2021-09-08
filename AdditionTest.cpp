#include "Addition.h"
#include <iostream>
int main() {
    Constant one(1);
    Constant two(2);
    Constant minusone(-1);
    Constant zero(0);
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
        Addition a;
        a.addItem(&one);
        a.addItem(&minusone);
        const int answer = one.value() + minusone.value();
        if (a.value() != answer) {
            std::cout << "result of 1-1 should be " << answer << ", received " << a.value() << "\n";
        }
    }
    {
        Addition a;
        a.addItem(&one);
        a.addItem(&zero);
        const int answer = one.value() + zero.value();
        if (a.value() != answer) {
            std::cout << "result of 1+0 should be " << answer << ", received " << a.value() << "\n";
        }
    }

}