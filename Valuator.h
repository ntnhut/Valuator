#ifndef VALUATOR_H
#define VALUATOR_H

#include "Expression.h"
#include <boost/property_tree/ptree.hpp>

class Valuator {
public:
    static Expression* createExpression(const boost::property_tree::ptree::value_type& v);
};

#endif