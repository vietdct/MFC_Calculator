#pragma once
#include "OperationStrategy.h"

class DivStrategy : public OperationStrategy
{
public:
	double Calculator(double firstOperand, double secondOperand) override;
};

