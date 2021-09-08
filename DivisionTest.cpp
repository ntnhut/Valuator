#include "Division.h"
#include <iostream>

int main() {
    Constant zero(0);
    Constant one(1);
    Constant two(2);
    Constant ten(10);
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
        Division d;
        d.setDividend(&ten);
        d.setDivisor(&one);
        const int answer = ten.value() / one.value();
        if (d.value() != answer) {
            std::cout<<"result of 10/1 should be " << answer << ", received "<< d.value() <<"\n";
        }
    }
    {
        Division d;
        d.setDividend(&zero);
        d.setDivisor(&one);
        const int answer = zero.value() / one.value();
        if (d.value() != answer) {
            std::cout<<"result of 0/1 should be " << answer << ", received "<< d.value() <<"\n";
        }
    }
    {
        Division d;
        d.setDividend(&zero);
        d.setDivisor(&one);
        const int answer = one.value() / zero.value();
        if (d.value() != answer) {
            std::cout<<"result of 1/0 should be " << answer << ", received "<< d.value() <<"\n";
        }
    }

}