#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include "Calculate.h"

double calculation(double numA, double numB, char oper);

static double question();

calculate cal;

int HistoryShow();

double IntroductionInput();

int mainMenu() {
    int choice;
    std::cout << "\tMAIN MENU\n\n" << "1. Use Calculator.\n" << "2. Show History.\n" << "3. Exit\n";
    while (true) {
        std::cout << "What is your choice? (1 - 3) ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                system("cls");
                IntroductionInput();
                break;
            case 2:
                system("cls");
                HistoryShow();
                break;
            case 3:
                cal.closeCalculator();
                exit(0);
            default:
                while (std::cin.fail()) {
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else {
                        break;
                    }
                    break;
                }
        }
    }
}

int HistoryShow() {
    int choiceHistory;
    std::string readHistoryTo;
    cal.readHistoryandShow();
    std::cout << "\n1. Clear History\n" << "2. Return to main menu\n\n";
    while (true) {
        std::cout << "Your Choice? (1 - 2) ";
        std::cin >> choiceHistory;
        switch (choiceHistory) {
            case 1:
                cal.deleteHistory();
                return mainMenu();
            case 2:
                system("cls");
                return mainMenu();
            default:
                while (std::cin.fail()) {
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else {
                        break;
                    }
                    std::cout << "Your Choice? (1 - 2) ";
                    std::cin >> choiceHistory;
                }
                break;
        }
    }
}

double IntroductionInput() {
    double numA;
    double numB;
    char oper;
    std::cout << "\n\tHow to use the calculator: \n\n"
              << "Just simply enter the first number of your problem then the operator and then the second number of your problem."
              << std::endl;
    std::cout
            << "Operators are: \"+ for adding, - for subtracting, * for multiplying, / for dividing, ^ for power, s for square root.\""
            << std::endl << "\n";
    std::cout << "Enter the first number: ";
    std::cin >> numA;
    while (std::cin.fail()) {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
        std::cout << "Enter the first number: ";
        std::cin >> numA;
    }
    std::cout << std::endl;
    std::cout << "Enter the operator: ";
    std::cin >> oper;
    cal.setOperator(oper);
    std::cin.clear();
    std::cout << std::endl;
    if (oper == 's') {
        std::cin.ignore();
        return calculation(numA, 0, oper);
    } else {
        std::cout << "Enter the second number: ";
        std::cin >> numB;
        while (std::cin.fail()) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
            std::cout << "Enter the second number: ";
            std::cin >> numB;
        }
    }
    std::cout << std::endl;
    return calculation(numA, numB, oper);
}

int main() {
    cal.openCalculator();
    mainMenu();
}

double calculation(double numA, double numB, char oper) {
    if (oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '^' || oper == 's') {
        if (oper == '+') {
            std::cout << cal.add(numA, numB);
        } else if (oper == '-') {
            std::cout << cal.subtract(numA, numB);
        } else if (oper == '*') {
            std::cout << cal.multiply(numA, numB);
        } else if (oper == '/') {
            std::cout << cal.divide(numA, numB);

        } else if (oper == '^') {
            std::cout << cal.power(numA, numB);
        } else if (oper == 's') {
            std::cout << cal.square(numA, numB);
        }
        return question();
    } else {
        std::cout << "\nYou have put in an invalid operator/number!\n\a";
        return question();
    }
}

double question() {
    while (true) {
        std::string yn;
        std::cout << "\nDo you want to use the calculator again? ";
        std::cin >> yn;
        std::cout << std::endl;
        if (yn == "Yes" || yn == "No" || yn == "YES" || yn == "NO" || yn == "YEs" || yn == "nO" || yn == "yes" ||
            yn == "no" || yn == "y" || yn == "n") {
            if (yn == "Yes" || yn == "YES" || yn == "YEs" || yn == "yes" || yn == "y") {
                return IntroductionInput();
            } else if (yn == "No" || yn == "NO" || yn == "nO" || yn == "no" || yn == "n") {
                cal.getWriteHistory().close();
                cal.getWriteHistory().open(cal.fileName, std::ios::app);
                system("cls");
                mainMenu();
            }
        } else {
            std::cout << "Invalid answer, try again.\a\n";
        }
    }
}
