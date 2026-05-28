#include "mascota.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
mascota::mascota()
{
    //ctor
}

mascota::~mascota()
{
    //dtor
}

void mascota::menu(){
int opcion;
do {
cout <<"============Menu Petshop============" << endl;
cout <<"1. Registrar mascotas" << endl;
cout <<"2. Historial de mascotas" << endl;
cout <<"3. Buscar mascota" << endl;
cout <<"4. Salir del programa" << endl;
cout <<"====================================" << endl;
cout <<"Seleccione un numero: " << endl;
cin >> opcion;
switch(opcion){
case 1:
    Registrar();
    break;
case 2:
    Historial();
    break;
case 3:
    Buscar();
    break;
case 4:
    exit(0);
}// llave switch

}while (opcion!=4); //llave while

}//llave void menu

void mascota::Registrar(){
    system("cls");
char masc;

cout<<"Ingrese el ID de la mascota: " << endl;
cin >> id;
cout<<"Ingrese el nombre de la mascota: " << endl;
cin >> nombre;
cout<<"Ingrese la especie de la mascota: " << endl;
cin >> especie;
cout<<"Ingrese la edad de la mascota: " << endl;
cin >> edad;
cout<<"Ingrese el nombre del Dueno: " << endl;
cin >> nombreDueno;
cout <<"Mascota registrada con exito. " << endl;
cout <<"Desea visualizar la ficha de la mascota? (S/N)" << endl;
cin >> masc;
if(masc == 'S' || masc == 's'){
    cout<<"-------Ficha de la mascota----------" << endl;
    cout<<"ID de la mascota: " << id << endl;
    cout<<"Nombre de la mascota: " << nombre << endl;
    cout<<"Especie: " << especie << endl;
    cout<<"Edad: " << edad <<" Allos" << endl;
    cout<<"Nombre del dueno: " << nombreDueno << endl;
    cout<<"------------------------------------" << endl;
}
ofstream archivoMasc;
archivoMasc.open("Mascotas.txt", ios::app);
archivoMasc << id << " " << nombre << " " << especie << " " << edad << " " << nombreDueno << "\n";
archivoMasc.close();
  Bitacora("Se registro una mascota con el ID " + id);

}

void mascota::Historial(){
system("cls");
fstream archivoMasc;
archivoMasc.open("Mascotas.txt", ios::in);
if(!archivoMasc){
    cout<<"No hay mascotas registradas..." << endl;
}
else {
    while(archivoMasc >> id >> nombre >> especie >> edad >> nombreDueno){
        cout<<"---------Historial de mascotas---------" << endl;
        cout<<"ID de la mascota: " << id << endl;
        cout<<"Nombre de la mascota: " << nombre << endl;
        cout<<"Especie: " << especie << endl;
        cout<<"Edad: " << edad << " Allos" << endl;
        cout<<"Nombre del dueno: " << nombreDueno << endl;
        cout<<"---------------------------------------"<< endl;
    }//llave while

}//llave else
archivoMasc.close();
  Bitacora("Se desplego el historial de cada mascota");

}//llave desplegar

void mascota::Buscar(){
    system("cls");
string idBusc;
fstream archivoMasc;
archivoMasc.open("Mascotas.txt", ios::in);
cout<<"Ingrese el ID de la mascota que desea buscar: " << endl;
cin >> idBusc;
bool encontrado = false;
if(!archivoMasc){
    cout<<"No hay mascotas registradas..." << endl;
}
else {
    while(archivoMasc >> id >> nombre >> especie >> edad >> nombreDueno){
    if(id == idBusc){
        cout<<"---------Ficha de la mascota--------" << endl;
        cout<<"ID de la mascota: " << id << endl;
        cout<<"Nombre de la mascota: " << nombre << endl;
        cout<<"Especie: " << especie << endl;
        cout<<"Edad: " << edad << " Allos" << endl;
        cout<<"Nombre del dueno: " << nombreDueno << endl;
        cout<<"------------------------------------"<< endl;
        encontrado = true;
    }//llave if ID comparacion
    }//llave while
    if(encontrado == false){
        cout<<"No hay ninguna mascota que coincida con ese ID." << endl;
        Bitacora("No se encontro ninguna mascota con el ID: " + idBusc);
    }// llave if ID no encontrado
    else {
        Bitacora("Se busco la mascota con el ID: " + idBusc + " con el nombre " + nombre + " y es de especie " + especie);
    }
    archivoMasc.close();

}//llave else


}//llave del void Buscar()

void mascota::Bitacora(string pasa){
ofstream archivoBitacora;
archivoBitacora.open("BitacoraMasc.txt", ios::app);
if (archivoBitacora){
    archivoBitacora <<"[QUE ACCION PASO]: " << pasa << "\n";
}
archivoBitacora.close();
}
