#include "pch.h"
#include "DivStrategy.h"

double DivStrategy::Calculator(double firstOperand, double secondOperand) {
	if (secondOperand == 0.0) {
		AfxMessageBox(_T("Error: Division by zero"));
		throw std::runtime_error("Division by zero");
	}
	return firstOperand / secondOperand;
}