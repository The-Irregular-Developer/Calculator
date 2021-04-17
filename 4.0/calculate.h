#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#pragma once

struct calculate
{
	std::string add(double numA, double numB);
	std::string subtract(double numA, double numB);
	std::string multiply(double numA, double numB);
	std::string divide(double numA, double numB);
	std::string power(double numA, double numB);
	std::string square(double numA, double numB);
};
