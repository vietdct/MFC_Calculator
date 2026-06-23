#pragma once
#include "OperationStrategy.h"
class AddStrategy :public OperationStrategy
{
	double Calculator(double firstOperand, double secondOperand) override;
};

