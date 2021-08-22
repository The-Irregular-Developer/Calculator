//
// Created by quinc on 2021-04-22.
//

#include <string>
#include <sstream>
#include <cmath>
#include "Calculate.h"

//TODO Remake calculate struct completely.
std::string calculate::add(double numA, double numB) {
    const double add = numA + numB;
    return writetoVector("The sum of the two numbers are ", add, numA, numB);
}

std::string calculate::subtract(double numA, double numB) {
    const double subtract = numA - numB;
    return writetoVector("The difference of the two numbers are ", subtract, numA, numB);
}

std::string calculate::multiply(double numA, double numB) {
    const double multiply = numA * numB;
    return writetoVector("The product of the two numbers you put in are ", multiply, numA, numB);
}

std::string calculate::divide(double numA, double numB) {
    const double divide = numA / numB;
    return writetoVector("The dividend of the two numbers you put in are ", divide, numA, numB);
}

std::string calculate::power(double numA, double numB) {
    const double power = pow(numA, numB);
    return writetoVector(" to the power of ", power, numA, numB);
}

std::string calculate::square(double numA, double numB) {
    const double square = sqrt(numA);
    return writetoVector("The square root of ", square, numA, numB);
}

std::string calculate::writetoVector(std::string st, const double value, double numA, double numB) {
    std::stringstream outputStream;
    std::stringstream writeStream;
    if (oper == 's') {
        outputStream << st;
        outputStream << numA;
        outputStream << " is ";
        outputStream << value;
        outputStream << std::endl;
    } else if (oper == '^') {
        outputStream << numA;
        outputStream << st;
        outputStream << numB;
        outputStream << " is ";
        outputStream << value;
        outputStream << std::endl;
    } else {
        outputStream << st;
        outputStream << value;
        outputStream << std::endl;
    }

    if (oper == 's') {
        writeStream << "Square root of: " << numA << " = " << value;
    } else {
        writeStream << numA << " " << oper << " " << numB << " = " << value;
    }

    vt.push_back(writeStream.str());

    return outputStream.str();
}

void calculate::setOperator(char oper) {
    this->oper = oper;
}

//TODO
void calculate::openCalculator() {
    writeHistory.open(fileName, std::ios::app);
    readHistory.open(fileName);
    while (!readHistory.eof()) {
        std::string readHistoryto;
        std::getline(readHistory, readHistoryto);
        vt.push_back(readHistoryto);
    }
    std::reverse(vt.begin(), vt.end());

}

void calculate::closeCalculator() {
    writeToFile();
    if (writeHistory.is_open()) {
        writeHistory.close();

    }
    if (readHistory.is_open()) {
        readHistory.close();
    }

}

[[deprecated("Try not to use this")]]
std::ofstream &calculate::getWriteHistory() {
    return writeHistory;
}

void calculate::readHistoryandShow() {
    for (int i = vt.size() - 1; i >= 0; i--) {
        std::cout << vt[i] << std::endl;
    }
}

void calculate::deleteHistory() {
    if (writeHistory.is_open()) {
        writeHistory.close();
        writeHistory.open(fileName, std::ios::out | std::ios::trunc);
        vt.clear();
    } else {
        writeHistory.open(fileName, std::ios::out | std::ios::trunc);
        vt.clear();
    }
    std::cout << "\nHistory Deleted!!\n";
    system("pause");
    system("cls");
}

//TODO
void calculate::writeToFile() {
    if (writeHistory.is_open()) {
        writeHistory.close();
        writeHistory.open(fileName, std::ios::out | std::ios::trunc);
        for (int i = vt.size() - 1; i >= 0; i--) {
            if (i != 0) {
                writeHistory << vt[i] << std::endl;

            } else {
                writeHistory << vt[i];
            }

        }
    } else if (!writeHistory.is_open()) {
        writeHistory.open(fileName, std::ios::out | std::ios::trunc);
        for (int i = vt.size() - 1; i >= 0; i--) {
            if (i != 0) {
                writeHistory << vt[i] << std::endl;

            } else {
                writeHistory << vt[i];
            }

        }
    } else {
        try {
            throw "ERROR WRITING HISTORY TO FILE";
        }
        catch (
                const char *e
        ) {
            system("cls");
            std::cout << e << std::endl;
        }
    }

}

