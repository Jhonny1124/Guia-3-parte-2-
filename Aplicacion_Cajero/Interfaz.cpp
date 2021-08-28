#include <iostream>
using namespace std;

/*Estas funciones imprimen un menu
 * simulando la interfaz de un cajero
 * */

void InterInicio(){
    cout << "**********************" << endl;
    cout << "*     BIENVENIDO     *" << endl;
    cout << "**********************" << endl;
    cout << "* Elija una opcion:  *" << endl;
    cout << "**********************" << endl;
    cout << "* 1 -> Administrador *" << endl;
    cout << "* 2 -> Usuario       *" << endl;
    cout << "* 3 -> Salir         *" << endl;
    cout << "**********************" << endl;
    cout << "->";
}

void InterAdministrador(int ver){

    if(ver == 0){
        cout << "*************************************" << endl;
        cout << "* Ingrese la Clave de Administrador *" << endl;
        cout << "*************************************" << endl;
        cout << "->";
    }

    else if(ver == -1){
        cout << "*************************************" << endl;
        cout << "* Acceso Denegado                   *" << endl;
        cout << "*************************************" << endl;
    }

    else if(ver == 1){
        cout << "************************************" << endl;
        cout << "*     BIENVENIDO ADMINISTRADOR     *" << endl;
        cout << "************************************" << endl;
        cout << "* Elija una opcion:                *" << endl;
        cout << "************************************" << endl;
        cout << "* 1 -> Registrar Usuario           *" << endl;
        cout << "* 2 -> Salir                       *" << endl;
        cout << "************************************" << endl;
        cout << "->";
    }
    else{
        cout << "************************************" << endl;
        cout << "* ADMINISTRADOR                    *" << endl;
        cout << "************************************" << endl;
        cout << "* Formato de Ingreso:              *" << endl;
        cout << "* <Identificacion>,<Clave>,<Saldo> *" << endl;
        cout << "************************************" << endl;
        cout << "->";
    }
}

void InterUsuario(int ver){
    if(ver == 0){
        cout << "*****************************" << endl;
        cout << "*     BIENVENIDO USUARIO    *" << endl;
        cout << "*****************************" << endl;
        cout << "* Elija una opcion:         *" << endl;
        cout << "*****************************" << endl;
        cout << "* 1 -> Consultar Saldo      *" << endl;
        cout << "* 2 -> Retirar Dinero       *" << endl;
        cout << "* 3 -> Salir                *" << endl;
        cout << "*****************************" << endl;
        cout << "->";
    }
    else if(ver == -1){
        cout << "*************************************" << endl;
        cout << "*           Acceso Denegado         *" << endl;
        cout << "*************************************" << endl;
    }

    else if (ver == 1){
        cout << "***********************************" << endl;
        cout << "* Ingrese el documento de Usuario *" << endl;
        cout << "***********************************" << endl;
        cout << "->";
    }
    else if (ver == 2){
        cout << "*************************************" << endl;
        cout << "* Ingrese la Clave de Usuario       *" << endl;
        cout << "*************************************" << endl;
        cout << "->";
    }
    else if (ver == 3){
        cout << "************************************" << endl;
        cout << "* Usuario                          *" << endl;
        cout << "************************************" << endl;
        cout << "* Ingrese la cantidad de dinero    *" << endl;
        cout << "* que desea retirar                *" << endl;
        cout << "************************************" << endl;
        cout << "->";
    }
    else if(ver == -2){
        cout << "*************************************" << endl;
        cout << "*         Saldo Insuficiente        *" << endl;
        cout << "*************************************" << endl;
    }
    else if (ver == 4){
        cout << "************************************" << endl;
        cout << "* Usuario                          *" << endl;
        cout << "************************************" << endl;
        cout << "* Saldo Disponible                 *" << endl;
        cout << "************************************" << endl;
        cout << "->";
    }
}

void InterFinal(){
    cout << "*************************************" << endl;
    cout << "* GRACIAS POR UTILIZAR ESTE CAJERO  *" << endl;
    cout << "*           VUELVA PRONTO           *" << endl;
    cout << "*************************************" << endl;
}

void Limpiar_Pantalla(){
    for(int i = 0; i < 40; i++)
        cout << endl;
}
