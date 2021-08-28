#include "administrador.h"

Administrador::Administrador(){

    InterAdministrador(0);
    cin >> verificacion;

    if(Verificacion() == false){// Se verifica si la contraseña ingresada es la contraseña de Administrador

        Limpiar_Pantalla();
        InterAdministrador(-1);
        exit(1);
    }
    else{

        Limpiar_Pantalla();
        InterAdministrador(1);
        cin >> opcion;
        cin.ignore();

        if(opcion == 1){
            AgregarUsuario();
        }

        Limpiar_Pantalla();
        InterFinal();

        Escritura_Archivos(Codificado, Archivo);

        exit(1);
    }
}

bool Administrador::Verificacion(){
    string contra;
    Lectura_Archivos(encriptado, "sudo.txt");
    Decodificacion_Metodo2(encriptado, Clave); // Se almacena la clave que esta encriptada en sudo.txt en la variable Clave
    if(Clave != verificacion){
        return false;
    }
    else{
        return true;
    }
}

void Administrador::AgregarUsuario(){

    /*Se le pide al administrador ingresar un usuario con el formato de entrada <Documento Identidad>,<Clave>,<Saldo>
     * ejemplo: 123456789,1234,80000
     * */

    Limpiar_Pantalla();
    InterAdministrador(2);
    getline(cin,usuario);
    cin.ignore();

    int coma1 = usuario.find(','), coma2 = usuario.rfind(',');

    /*Se codifican todos los datos del usuario nuevo para luego ingresarlo a la
     * base de datos
     * */

    Codificacion_Metodo2(usuario.substr(0,coma1), Codificado[0]);
    Codificacion_Metodo2(usuario.substr(coma1+1,4), Codificado[1]);
    Codificacion_Metodo2(usuario.substr((coma2+1)), Codificado[2]);
}
