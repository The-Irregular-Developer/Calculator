//
// Created by quincy on 2021-04-22.
//

#ifndef CALCULATOR_CALCULATE_H
#define CALCULATOR_CALCULATE_H

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

#endif //CALCULATOR_CALCULATE_H
