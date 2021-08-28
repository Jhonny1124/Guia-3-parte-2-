#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include <iostream>
#include <fstream>
#include<string>
#include "Encriptar.h"
#include"Interfaz.h"

using namespace std;

/*Esta clase hle permite al Administrador registrar usuarios nuevos
 * */
class Administrador
{
public:
    Administrador();
    bool Verificacion();
    void AgregarUsuario();
private:
    string encriptado;
    string Clave;
    string verificacion;
    string usuario;
    string Archivo = "Usuarios.txt";
    string Codificado[3];
    int opcion = 1;
};

#endif // ADMINISTRADOR_H
