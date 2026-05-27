#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class simulador
{
    public:
        simulador();
        virtual ~simulador();
        void principal();
        void menu();
        void consultar();
        void deposito();
        void retirar();


    private:
        string idSesion, nombre, pinSesion, idArchivo, pinArchivo;
        float saldoSesion, saldoArchivo;
};

#endif // SIMULADOR_H
