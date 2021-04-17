#include <iostream>
#include <cmath>
#include <string>
#include "calculate.h"

double calculation(double numA, double numB, char oper);
int question();
calculate cal;


int main()
{
    double numA;
    double numB;
    char oper;
    std::cout << "\nHello and Welcome to this simple calculator. It was made by: Quincy" << std::endl;
    std::cout << "Just simply enter the first number of your problem then the operator and then the second number of your problem."<<std::endl;
    std::cout << "Operators are: \"+ for adding, - for subtracting, * for multiplying, / for dividing, ^ for power, s for square root.\""<<std::endl<<"\n";
    std::cout << "Enter the first number: ";
    std::cin >> numA;
    std::cout << std::endl;
    std::cout << "Enter the operator: ";
    std::cin >> oper;
    std::cout << std::endl;
    if (oper == 's')
    {
        std::cin.ignore();
        calculation(numA, 0, oper);
    }
    else
    {
        std::cout << "Enter the second number: ";
        std::cin >> numB;
        std::cout << std::endl;
        calculation(numA, numB, oper);
    }
}

double calculation(double numA, double numB, char oper)
{
    if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^' || oper == 's')
    {
        if (oper == '+')
        {
            std::cout << cal.add(numA, numB);
        }
        else if (oper == '-')
        {
            std::cout << cal.subtract(numA, numB);
        }
        else if (oper == '*')
        {
            std::cout << cal.multiply(numA, numB);
        }
        else if (oper == '/')
        {
            std::cout << cal.divide(numA, numB);

        }
        else if (oper == '^')
        {
            std::cout << cal.power(numA, numB);
        }
        else if (oper == 's')
        {
            std::cout << cal.square(numA, numB);
        }
        return question();
    }
    else
    {
        std::cout << "\nYou have put in an invalid operator/number!\n\a";
        return question();
    }
}

int question()
{
    while (true)
    {
        std::string yn;
        std::cout << "\nDo you want to use the calculator again? ";
        std::cin >> yn;
        std::cout << std::endl;
        if (yn == "Yes" || yn == "No" || yn == "YES" || yn == "NO" || yn == "YEs" || yn == "nO" || yn == "yes" || yn == "no")
        {
            if (yn == "Yes" || yn == "YES" || yn == "YEs" || yn == "yes")
            {
                return main();
            }
            else if (yn == "No" || yn == "NO" || yn == "nO" || yn == "no")
            {
                return 0;
            }
        }
        else
        {
            std::cout << "Invalid answer, try again.\a\n";
        }
    }

    
}
