#include "simulador.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;


simulador::simulador()
{
    idSesion = "";
    nombre = "";
    pinSesion = "";
    saldoSesion = 0.0;
    idArchivo = "";
    pinArchivo = "";
    saldoArchivo = 0.0;
    //ctor
}

simulador::~simulador()
{
    //dtor
}
//Menu principal
void simulador::principal(){
system("cls");
int opcionPrin;
do {
cout<<"------Menu principal------" << endl;
cout<<"1. Crear un usuario" << endl;
cout<<"2. Ingresar a mi usuario" << endl;
cout<<"3. Salir del cajero" << endl;
cout<<"--------------------------"<< endl;
cout<<"Seleccione una opcion" << endl;
cin >> opcionPrin;
ofstream archivoSesion;
archivoSesion.open("Usuario.txt", ios::app);
switch(opcionPrin){
case 1:
    cout<<"Ingrese un ID: " << endl;
    cin >> idSesion;
    cout<<"Ingrese un Nombre: " << endl;
    cin >> nombre;
    cout<<"Ingrese un Pin: " << endl;
    cin >> pinSesion;
    cout<<"Ingrese su saldo "<<endl;
    cin>>saldoSesion;
    if(archivoSesion){
        archivoSesion << idSesion << " " << nombre << " " << pinSesion << " " << saldoSesion << "\n";
        cout<<"Usuario creado con exito" << endl;
        archivoSesion.close();
    }
    break;

case 2:{
    string idBuscar, pinBusca;
    cout<<"Ingrese su ID: " << endl;
    cin >> idBuscar;
    cout<<"Ingrese su Pin: " << endl;
    cin>>pinBusca;
    ifstream leerArchivo("Usuario.txt");
    bool ingresoExitoso = false;
    if(!leerArchivo){
        cout<<"No hay datos registrados" << endl;
    }
    else {
        while(leerArchivo >> idArchivo >> nombre >> pinArchivo >> saldoArchivo){
            if(idArchivo == idBuscar && pinArchivo == pinBusca){
                idSesion = idArchivo;
                pinSesion = pinArchivo;
                saldoSesion = saldoArchivo;
                ingresoExitoso = true;
            }
        }
        leerArchivo.close();
    }
    if(ingresoExitoso){
    menu();
}
else {
    cout<<"El ID o el Pin no coinciden" << endl;
}
    break;
}

case 3:
    exit(0);
}
}while(opcionPrin!=3);
}

void simulador::menu(){
system("cls");
int MENU;
do{
cout<<"------------Cajero Menu------------" << endl;
cout<<"1. Consultar su saldo actual" << endl;
cout<<"2. Retirar de su saldo" << endl;
cout<<"3. Depositar a su saldo" << endl;
cout<<"4. Salir de este menu"<<endl;
cout<<"-----------------------------------"<<endl;
cout<<"Seleccione una opcion: " << endl;
cin>> MENU;
switch(MENU){
case 1:
   consultar();
    break;
case 2:
    retirar();
    break;
case 3:
    deposito();
    break;
case 4:
   cout<<"Su saldo final quedo en: Q" << saldoSesion << endl;
   system("pause");
   system("cls");
   break;
}
}while(MENU !=4);
}

void simulador::consultar(){
system("cls");
    cout<<"----------Consultar Salso----------" << endl;
    cout<<"ID de la cuenta: " << idSesion << endl;
    cout<<"Su saldo actual es de: Q" << saldoSesion << endl;
    cout<<"-----------------------------------"<<endl;
    system("pause");
    system("cls");
}



void simulador::retirar(){
system("cls");
float retiros;
cout <<"Ingrese la cantidad que desea retirar: " << endl;
cin >> retiros;
if(retiros > saldoSesion){
    cout<<"Error. fondos insufisientes " << endl;
    system("pause");
    system("cls");
    return;
}
 saldoSesion = saldoSesion - retiros;
fstream archivoSesion, archivoNuevo;
archivoSesion.open("Usuario.txt", ios::in);
if(!archivoSesion){
    cout<<"No hay datos" << endl;
}
else {
        archivoNuevo.open("Temporal.txt", ios::out);
while(archivoSesion >> idArchivo >> nombre >> pinArchivo >> saldoArchivo){
        if(idSesion == idArchivo){
            archivoNuevo << idArchivo << " " << nombre << " " << pinArchivo << " " << saldoSesion << "\n";
        }
        else {
            archivoNuevo << idArchivo << " " << nombre << " " << pinArchivo << " " << saldoArchivo << "\n";
        }

}
archivoSesion.close();
archivoNuevo.close();



remove("Usuario.txt");
rename("Temporal.txt", "Usuario.txt");

cout<<"--------------------------------"<<endl;
cout<<"Su retiro fue de: Q" <<retiros << endl;
cout<<"--------------------------------"<<endl;
}
system("pause");
system("cls");


}

void simulador::deposito(){
system("cls");
float depositoIn;
cout <<"Ingrese la cantidad que desea depositar: " << endl;
cin >> depositoIn;
saldoSesion = saldoSesion + depositoIn;
ifstream archivoSesion("Usuario.txt");
ofstream archivoNuevo("Temporal.txt");
if(!archivoSesion){
    cout<<"No hay datos" << endl;
}
else {
while(archivoSesion >> idArchivo >> nombre >> pinArchivo >> saldoArchivo){
        if(idArchivo == idSesion){
            archivoNuevo << idArchivo << " " << nombre << " " << pinArchivo << " " << saldoSesion << "\n";
        }
        else {
            archivoNuevo << idArchivo << " " << nombre << " " << pinArchivo << " " << saldoArchivo << "\n";
        }


}
    archivoSesion.close();
    archivoNuevo.close();

remove("Usuario.txt");
rename("Temporal.txt", "Usuario.txt");

    cout<<"-----------------------" <<endl;
    cout<<"Su retiro fue de : Q" << depositoIn<< endl;
    cout<<"-----------------------"<<endl;

system("pause");
system("cls");

}
}





