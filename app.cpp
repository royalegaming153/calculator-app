#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

// Functions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}

double squareroot(double a) {
    if (a < 0) {
        cout << "Error: Negative number!" << endl;
        return 0;
    }
    return sqrt(a);
}

// Save history
void saveToFile(string operation, double result) {
    ofstream file("history.txt", ios::app);
    file << operation << " = " << result << endl;
    file.close();
}

int main() {
    int choice;
    double a, b, result;

    while (true) {
        cout << "\n===== CALCULATOR =====\n";
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
        cout << "5. Power\n6. Square Root\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 7) {
            cout << "Exiting..." << endl;
            break;
        }

        switch (choice) {
        case 1:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            result = add(a, b);
            cout << "Result: " << result << endl;
            saveToFile("Addition", result);
            break;

        case 2:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            result = subtract(a, b);
            cout << "Result: " << result << endl;
            saveToFile("Subtraction", result);
            break;

        case 3:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            result = multiply(a, b);
            cout << "Result: " << result << endl;
            saveToFile("Multiplication", result);
            break;

        case 4:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            result = divide(a, b);
            cout << "Result: " << result << endl;
            saveToFile("Division", result);
            break;

        case 5:
            cout << "Enter base and exponent: ";
            cin >> a >> b;
            result = power(a, b);
            cout << "Result: " << result << endl;
            saveToFile("Power", result);
            break;

        case 6:
            cout << "Enter number: ";
            cin >> a;
            result = squareroot(a);
            cout << "Result: " << result << endl;
            saveToFile("Square Root", result);
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}