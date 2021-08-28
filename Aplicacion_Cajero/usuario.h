#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <fstream>
#include<string>
#include "Encriptar.h"
#include"Interfaz.h"

using namespace std;

/*Esta clase hace las diferentes tareas que tiene permitido hacer el Usuario
 * como lo es retirar saldo o consultar el saldo disponible
 * */
class Usuario
{
public:
    Usuario();
    int cadena_numero(string cadena, int longi);

    int Numero_Caracter(int numero, char numero_car[10] );

private:
    string documento = "";
    string clave = "";
    string Usuario1 = "";
    string verificacion = "";
    string saldo = "", saldo1 = "";
    string nuevo_saldo = "";
    char numero_car[10] = "";
    int doc_existencia = 0, linea = 0, dinero = 0, opcion = 0, retiro = 0, cont = 0, cont2 = 0;
    ifstream archivo;
};
#endif // USUARIO_H
