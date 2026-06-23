#pragma once
#include <afx.h>
#include <stdexcept>

class OperationStrategy
{
public:
	virtual ~OperationStrategy() = default;
	virtual double Calculator(double firstOperand, double secondOperand) = 0;
};



