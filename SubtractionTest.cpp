#include "Subtraction.h"
#include <iostream>

int main() {
    Constant one(1);
    Constant two(2);
    Constant zero(0);
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
        Subtraction s;
        s.setMinuend(&two);
        s.setSubtrahend(&zero);
        const int answer = two.value() - zero.value();
        if (s.value() != answer) {
            std::cout<<"result of 2-0 should be " << answer << ", received " << s.value() << "\n";
        }
    }

}