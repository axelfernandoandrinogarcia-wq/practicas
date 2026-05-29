#include <iostream>
#include "DivideByZeroException.h"

using namespace std;

double quotient(int numerator, int denominator) {

    if (denominator == 0) {
        throw DivideByZeroException{};
    }

    return static_cast<double>(numerator) / denominator;
}

int main() {
    int number1;
    int number2;

    cout << "Ingrese dos numeros enteros (fin de archivo para finalizar): ";

    while (cin >> number1 >> number2) {

        try {
            double result{quotient(number1, number2)};
            cout << "El cociente es: " << result << endl;
        }

        catch (const DivideByZeroException& divideByZeroException) {
            cerr << "Ocurrio una excepcion: "
                 << divideByZeroException.what() << endl;
        }

        cout << "\nIngrese dos números enteros (fin de archivo para finalizar)): ";
    }

    cout << endl;
}
