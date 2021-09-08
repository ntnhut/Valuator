#include "Multiplication.h"
#include <iostream>

int main() {
    Constant one(1);
    Constant two(2);
    Constant zero(0);
    Constant five(5);
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
        Multiplication m;        
        m.addFactor(&two);
        m.addFactor(&zero);
        const int answer = two.value() * zero.value();
        if (m.value() != answer) {
            std::cout<<"result of 2*0 should be " << answer << ", received " << m.value() <<"\n";
        }
    }    
    {
        Multiplication m;        
        m.addFactor(&two);
        m.addFactor(&one);
        const int answer = two.value() * one.value();
        if (m.value() != answer) {
            std::cout<<"result of 2*1 should be " << answer << ", received " << m.value() <<"\n";
        }
    }    

}