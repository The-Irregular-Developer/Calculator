#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "calculate.h"

std::string calculate::add(double numA, double numB)
{
	double add = numA + numB;
	std::stringstream sadd;
	sadd << "The sum of the two numbers are ";
	sadd << add;
	sadd << std::endl;
	std::string fina = sadd.str();
	return fina;
}
std::string calculate::subtract(double numA, double numB)
{
	double subtract = numA - numB;
	std::stringstream ssub;
	ssub << "The difference of the two numbers are ";
	ssub << subtract;
	ssub << std::endl;
	std::string fins = ssub.str();
	return fins;
}
std::string calculate::multiply(double numA, double numB)
{
	double multiply = numA * numB;
	std::stringstream smul;
	smul << "The product of the two numbers you put in are ";
	smul << multiply;
	smul << std::endl;
	std::string finm = smul.str();
	return finm;
}
std::string calculate::divide(double numA, double numB)
{
	double divide = numA / numB;
	std::stringstream sdiv;
	sdiv << "The dividend of the two numbers you put in are ";
	sdiv << divide;
	sdiv << std::endl;
	std::string find = sdiv.str();
	return find;
}
std::string calculate::power(double numA, double numB)
{
	double power = pow(numA, numB);
	std::stringstream spow;
	spow << numA;
	spow << " to the power of ";
	spow << numB;
	spow << " is ";
	spow << power;
	spow << std::endl;
	std::string finp = spow.str();
	return finp;
}
std::string calculate::square(double numA, double numB)
{
	double square = sqrt(numA);
	std::stringstream ssqu;
	ssqu << "The square root of ";
	ssqu << numA;
	ssqu << " is ";
	ssqu << square;
	ssqu << std::endl;
	std::string fins = ssqu.str();
	return fins;
}
