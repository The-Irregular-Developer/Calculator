#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include "calculate.h"

double calculation(double numA, double numB, char oper);
static double question();
calculate cal;
std::string fileName = "history.txt";
extern std::ofstream writeHistory;
std::ifstream readHistory;
int HistoryShow();
double IntroductionInput();

int mainMenu()
{
    int choice;
    std::cout <<"\tMAIN MENU\n\n"<< "1. Use Calculator.\n" << "2. Show History.\n" << "3. Exit\n";
    while (true)
    {
        std::cout << "What is your choice? (0 - 2) ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            IntroductionInput();
            break;
        case 2:
            system("cls");
            HistoryShow();
        case 3:
            writeHistory.close();
            readHistory.close();
            exit(0);
        default:
            break;
        }
    }
}

void Introduction()
{
    std::cout << "\n\tHow to use the calculator: \n\n"<<"Just simply enter the first number of your problem then the operator and then the second number of your problem." << std::endl;
    std::cout << "Operators are: \"+ for adding, - for subtracting, * for multiplying, / for dividing, ^ for power, s for square root.\"" << std::endl << "\n";
}

int HistoryShow()
{
    int choiceHistory;
    std::string readHistoryTo;
    if (!readHistory.is_open())
    {
        readHistory.open(fileName);
    }
    else if(readHistory.is_open())
    {
        readHistory.close();
        readHistory.open(fileName);
    }
    while (!readHistory.eof())
    {
        std::getline(readHistory, readHistoryTo);
        std::cout << readHistoryTo<<std::endl;
    }
    while (true)
    {
        std::cout << "\n1. Clear History\n" << "2. Return to main menu\n\n";
        std::cout << "Your Choice? (1 - 2) ";
        std::cin >> choiceHistory;
        switch (choiceHistory)
        {
        case 1:
            if (writeHistory.is_open())
            {
                writeHistory.close();
                writeHistory.open(fileName, std::ios::out | std::ios::trunc);
            }
            else
            {
                writeHistory.open(fileName, std::ios::out | std::ios::trunc);
            }
            std::cout << "\nHistory Deleted!!\n";
            system("pause");
            system("cls");
            return mainMenu();
        case 2:
            system("cls");
            return mainMenu();
            break;
        default:
            if (!isdigit(choiceHistory))
            {
                std::cout << "\nINVALID INPUT\n";
                std::cout << "\nYou entered a letter. Only NUMBERS are allowed. To prevent computer damage, we will return you to main menu\n";
                system("pause");
                system("cls");
                return mainMenu();
            }
            else if (isdigit(choiceHistory))
            {
                std::cout << "\nINVALID INPUT\n";
            }

            break;
        }
    }
}

double IntroductionInput()
{
    double numA;
    double numB;
    char oper;
    bool CINFail = std::cin.fail();
    Introduction();
    std::cout << "Enter the first number: ";
    std::cin >> numA;
    try
    {
        if (std::cin.fail())
        {
            throw 1;
        }
    }
    catch (int error)
    {
        system("cls");
        std::cout << "ERROR NUMBER: " << error << std::endl;
        system("pause");
        return error;
    }
    std::cout << std::endl;
    std::cout << "Enter the operator: ";
    std::cin >> oper;
    std::cout << std::endl;
    if (oper == 's')
    {
        std::cin.ignore();
        return calculation(numA, 0, oper);
    }
    else
    {
        std::cout << "Enter the second number: ";
        std::cin >> numB;
        try
        {
            if (std::cin.fail())
            {
                throw 1;
            }
        }
        catch (int error)
        {
            system("cls");
            std::cout << "ERROR NUMBER: " << error << std::endl;
            system("pause");
            exit(error);
        }
        std::cout << std::endl;
        return calculation(numA, numB, oper);
    }
}

int main()
{
    writeHistory.open(fileName, std::ios::app);
    mainMenu();
}

double calculation(double numA, double numB, char oper)
{
    if (writeHistory.is_open())
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
    else
    {
        try
        {
            throw "ERROR WRITING HISTORY TO FILE";
        }
        catch (const char* e)
        {
            system("cls");
            std::cout << e << std::endl;
        }
    }
}

double question()
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
                return IntroductionInput();
            }
            else if (yn == "No" || yn == "NO" || yn == "nO" || yn == "no")
            {
                writeHistory.close();
                writeHistory.open(fileName, std::ios::app);
                system("cls");
                mainMenu();
            }
        }
        else
        {
            std::cout << "Invalid answer, try again.\a\n";
        }
    }


}
