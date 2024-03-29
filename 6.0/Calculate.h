//
// Created by quinc on 2021-04-22.
//

#ifndef CALCULATOR_CALCULATE_H
#define CALCULATOR_CALCULATE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#pragma once

struct calculate {
private:
    std::vector<std::string> vt;
    std::ifstream readHistory;
    std::ofstream writeHistory;
    char oper;

    std::string writetoVector(std::string st, const double value, double numA, double numB);
public:
    std::string fileName = "history.txt";
public:
    void openCalculator();

    void writeToFile();

    void readHistoryandShow();

    void deleteHistory();

    std::string add(double numA, double numB);

    std::string subtract(double numA, double numB);

    std::string multiply(double numA, double numB);

    std::string divide(double numA, double numB);

    std::string power(double numA, double numB);

    std::string square(double numA, double numB);

    void setOperator(char oper);

    std::ofstream& getWriteHistory();

    void closeCalculator();
};

#endif //CALCULATOR_CALCULATE_H
