//
// Created by quincy on 2021-04-22.
//

#include <string>
#include <sstream>
#include <cmath>
#include "Calculate.h"

std::ofstream writeHistory;

std::string calculate::add(double numA, double numB)
{
    const double add = numA + numB;
    std::stringstream sAdd;
    sAdd << "The sum of the two numbers are ";
    sAdd << add;
    sAdd << std::endl;
    std::string fina = sAdd.str();
    writeHistory << numA << " + " << numB << " = " << add<<std::endl;
    return fina;
}
std::string calculate::subtract(double numA, double numB)
{
    const double subtract = numA - numB;
    std::stringstream sSub;
    sSub << "The difference of the two numbers are ";
    sSub << subtract;
    sSub << std::endl;
    std::string fins = sSub.str();
    writeHistory << numA << " - " << numB << " = " << subtract << std::endl;
    return fins;
}
std::string calculate::multiply(double numA, double numB)
{
    const double multiply = numA * numB;
    std::stringstream sMul;
    sMul << "The product of the two numbers you put in are ";
    sMul << multiply;
    sMul << std::endl;
    std::string finm = sMul.str();
    writeHistory << numA << " * " << numB << " = " << multiply << std::endl;
    return finm;
}
std::string calculate::divide(double numA, double numB)
{
    const double divide = numA / numB;
    std::stringstream sDiv;
    sDiv << "The dividend of the two numbers you put in are ";
    sDiv << divide;
    sDiv << std::endl;
    std::string find = sDiv.str();
    writeHistory << numA << " / " << numB << " = " << divide << std::endl;
    return find;
}
std::string calculate::power(double numA, double numB)
{
    const double power = pow(numA, numB);
    std::stringstream sPow;
    sPow << numA;
    sPow << " to the power of ";
    sPow << numB;
    sPow << " is ";
    sPow << power;
    sPow << std::endl;
    std::string finp = sPow.str();
    writeHistory << numA << " ^ " << numB << " = " << power << std::endl;
    return finp;
}
std::string calculate::square(double numA, double numB)
{
    const double square = sqrt(numA);
    std::stringstream sSqu;
    sSqu << "The square root of ";
    sSqu << numA;
    sSqu << " is ";
    sSqu << square;
    sSqu << std::endl;
    std::string fins = sSqu.str();
    writeHistory << "Square root of: " << numA << " = " << square << std::endl;
    return fins;
}
