#include <iostream>
#include "usuario.h"
#include "administrador.h"

using namespace std;
/*Contraseña Administrador = WDp7
 * Advetencias:
 *  -Evite poner numeros con mas de 10 cifras para no generar un posible desbordamiento en los diferentes tipos de
 *  datos(estos numeros pueden ser el documento de identidad o el saldo)
 *  -Las contraseñas de los usuarion deben de ser de 4 cifras
 * En la base de datos hay un usuario de prueba que tiene:
 *  *Documento = 123456789
 *  *Contraseña = 1234
 *  *Saldo = 80000
 * */

int main()
{
    unsigned int option;
    InterInicio();
    cin >> option;
    Limpiar_Pantalla();
    if(option == 3){
        InterFinal();
        exit(1);
    }
    else if(option == 2){
        Usuario unico;
    }
    else if (option == 1){
        Administrador unico;
    }
    return 0;
}



