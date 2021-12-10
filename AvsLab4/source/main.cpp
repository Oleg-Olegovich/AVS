#include <iostream>
#include <string>
#include "garden.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

void printGreeting() {
    cout << "Hello! There are 2 modes here:" << endl
         << "1. Inputting dimensions manually." << endl
         << "2. Random generation of dimensions in the range [1; 100]." << endl
         << "Input the mode number." << endl;
}

void printError() {
    cout << "Invalid input, try again." << endl;
}

void printManuallyMode() {
    cout << "You have selected manual mode." << endl
         << "Now you will need to input 2 numbers in different lines." << endl;
}

void printInputRows() {
    cout << "Input the number of rows. [1; 100]" << endl;
}

void printInputColumns() {
    cout << "Input the number of columns. [1; 100]" << endl;
}

void printRandomMode() {
    cout << "You have selected random mode. Now just enjoy." << endl;
}

void printDimensions(const int rows, const int columns) {
    cout << "The dimension of the garden: " << rows
         << " rows by " << columns << " columns." << endl;
}

bool tryParseInteger(const string &data, int &number, const int min, const int max) {
    for (const auto symbol: data) {
        if (symbol < '0' || symbol > '9') {
            return false;
        }
    }
    number = stoi(data);
    if (number < min || number > max) {
        return false;
    }
    return true;
}

int main() {
    printGreeting();
    string input;
    getline(cin, input);
    while (input != "1" && input != "2") {
        printError();
        getline(cin, input);
    }
    int rows, columns;
    if (input == "2") {
        printRandomMode();
        rows = rand() % 100 + 1;
        columns = rand() % 100 + 1;
    } else {
        printManuallyMode();
        printInputRows();
        getline(cin, input);
        while (!tryParseInteger(input, rows, 1, 100)) {
            printError();
            printInputRows();
            getline(cin, input);
        }
        printInputColumns();
        getline(cin, input);
        while (!tryParseInteger(input, columns, 1, 100)) {
            printError();
            printInputColumns();
            getline(cin, input);
        }
    }
    printDimensions(rows, columns);
    auto *garden = new Garden(rows, columns);
    garden->demonstrate();
    cout << endl;
    garden->demonstrate(1);
    delete garden;
    return 0;
}
