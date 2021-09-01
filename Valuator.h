#ifndef VALUATOR_H
#define VALUATOR_H

#include "Expression.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <boost/property_tree/ptree.hpp>

class Valuator {
public:
    Expression* createExpression(const boost::property_tree::ptree::value_type& v);
    Addition* createAddition(const boost::property_tree::ptree::value_type& v);
    Division* createDivision(const boost::property_tree::ptree::value_type& v);
    Multiplication* createMultiplication(const boost::property_tree::ptree::value_type& v);
    Subtraction* createSubtraction(const boost::property_tree::ptree::value_type& v);

    void evaluate(const std::string& inputFileName, const std::string& outputFileName);
};

#endif