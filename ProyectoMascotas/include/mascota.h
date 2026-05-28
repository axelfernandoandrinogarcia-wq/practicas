#ifndef MASCOTA_H
#define MASCOTA_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class mascota
{
    private:
        string id, nombre, especie, nombreDueno;
        int edad;

    public:
        mascota();
        ~mascota();
        void menu();
        void Registrar();
        void Historial();
        void Buscar();
        void Bitacora(string pasa);
};

#endif // MASCOTA_H
