#include <iostream>
#include <cmath>

double calculation(double numA, double numB, char oper)
{
    if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^' || oper == 's')
    {
        if (oper == '+')
        {
            double add = numA + numB;
            std::cout << "The sum of the two numbers are " << add << std::endl;
        }
        else if (oper == '-')
        {
            double subtract = numA - numB;
            std::cout << "The difference of the two numbers are " << subtract << std::endl;
        }
        else if (oper == '*')
        {
            double multiply = numA * numB;
            std::cout << "The product of the two numbers you put in are " << multiply << std::endl;
        }
        else if (oper == '/')
        {
            double divide = numA / numB;
            std::cout << "The dividend of the two numbers you put in are " << divide << std::endl;

        }
        else if (oper == '^')
        {
            double power = pow(numA, numB);
            std::cout << numA << " to the power of " << numB << " is " << power << std::endl;
        }
        else if (oper == 's')
        {
            double square = sqrt(numA);
            std::cout << "The square root of " << numA << " is " << square << std::endl;
        }
        return system("pause");
    }
    else
    {
        std::cout << "\nYou have put in an invalid operator/number!\n\a";
        return system("pause");
    }
}

int main()
{
    double numA;
    double numB;
    char oper;
    std::cout << "Hello and Welcome to this simple calculator. It was made by: Quincy" << std::endl;
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
