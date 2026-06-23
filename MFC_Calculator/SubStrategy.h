#pragma once
#include "OperationStrategy.h"
class SubStrategy : public OperationStrategy
{
	double Calculator(double firstOperand, double secondOperand) override;
};

