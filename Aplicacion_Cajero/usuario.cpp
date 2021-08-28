#include "usuario.h"

Usuario::Usuario() {

    InterUsuario(1);
    cin >> documento;

    Limpiar_Pantalla();

    InterUsuario(2);
    cin >> clave;
    archivo.open("../Aplicacion_Cajero/BD/Usuarios.txt"); //Se abre la base de datos para luego verificar la identidad el usuario

    if(!archivo.is_open()){
        cout << "El archivo Usuarios.txt no pudo ser abierto" << endl;
        exit(1);
    }

    while(getline(archivo, Usuario1)){

        /* de la linea 23 a la 36 se verifica la identidad del usuario. Primero se verifica la exixtencia
         * del documento en la base de datos y luego se verifica la cotraseña correspondiente
         * */

        linea += 1;
        verificacion = "";
        Decodificacion_Metodo2(Usuario1, verificacion);

        if(verificacion == documento){

            doc_existencia += 1;
            getline(archivo, Usuario1);
            linea +=1;
            verificacion = "";
            Decodificacion_Metodo2(Usuario1, verificacion);

            if(verificacion != clave){

                Limpiar_Pantalla();
                InterUsuario(-1);
                archivo.close();
                exit(1);
            }

            else{

                getline(archivo, saldo1); // Una vez verificada la identidad del Usuario se extrae el saldo
                linea += 1;               // disponible para poder realizar transacciones
                Decodificacion_Metodo2(saldo1, saldo);
                dinero = cadena_numero(saldo, saldo.length());

                Limpiar_Pantalla();
                InterUsuario(0);
                cin >> opcion;

                if(opcion == 3){

                    Limpiar_Pantalla();
                    InterFinal();
                    archivo.close();
                    exit(1);
                }

                else if (opcion == 2){

                    Limpiar_Pantalla();
                    InterUsuario(3);
                    cin >> retiro;
                    dinero -= 1000;

                    if(retiro >= dinero){

                        Limpiar_Pantalla();
                        InterUsuario(-2);
                        exit(1);
                        break;
                    }

                    else{

                        dinero -= retiro;
                        break;
                    }
                }

                else if (opcion == 1){

                    Limpiar_Pantalla();
                    InterUsuario(4);
                    cout << dinero <<endl <<endl;
                    dinero -=1000;
                    break;
                }
            }
        }
    }

    if(doc_existencia == 0){

        Limpiar_Pantalla();
        InterUsuario(-1);
        archivo.close();
        exit(1);
    }

    InterFinal();
    archivo.close();

    Numero_Caracter(dinero, numero_car);

    saldo = numero_car;
    Codificacion_Metodo2(saldo, nuevo_saldo);
    Usuario1 = "";

    Lectura_Archivos(Usuario1,"Usuarios.txt");//se copia toda la base de datos a una variable tipo string llamada Usuario1

    for(int i = 0; i < Usuario1.length(); i++){

        /*En este bucle se busca el apartado donde se ubica el saldo del usuario que acabo
         * de realizar una transaccion y se modifica
         * */

        if(Usuario1[i] == '\n')
            cont ++;
        if(cont == (linea-1)){

            Usuario1[i+1] = nuevo_saldo[cont2];
            cont2++;
        }
    }

    // Se vuelve a escribir la base de datos con el saldo del usuario actualizado
    ofstream archivo1;

    archivo1.open("../Aplicacion_Cajero/BD/Usuarios.txt");

    if(!archivo1.is_open()){
        cout << "El archivo Usuarios.txt no pudo ser abierto" << endl;
        exit(1);
    }

    Usuario1[Usuario1.length()-1] = '\n';
    archivo1 << Usuario1;

    archivo1.close();
}

int Usuario::cadena_numero(string cadena, int longi){

    //Esta funcion pasa una cadena de caracteres numereicos a un numero decimal

    int valores[10] = {14,74,21,49,65,32,47,85,67,34};
    unsigned int cont = 0,numero = 0;
    unsigned long long int unidad = 1000000000;

    for(int i = 0; i < longi; i++){
        cont = 0;
        for(int n = 48; n < 58; n++){

            if( cadena[i] == char(n) ){

                valores[i] = cont;
                break;
            }
            cont++;
        }
    }
    for(int i = 0; i < 10; i++){

        if((valores[i]/10) != 0 ){

            unidad /= 10;
        }
    }
    for(int v = 0; v < 10; v++){

        numero += valores[v]*unidad;
        unidad /= 10;
    }
    return numero;
}

int Usuario::Numero_Caracter(int numero, char numero_car[]){

    //Esta funcion pasa un numero decimal a una cadena de caracteres numericos

    int cifras = 1, cont = 0, tem_numero = 0, restador = 10, cont2 = 0;

    for(int i = 0; i < 9; i++){

        if((numero/cifras) != 0){
            cifras *= 10;
            cont++;
        }
    }
    for(int c = cont-1; c >= 0; c--){

        tem_numero = numero%restador;
        numero /= restador;
        cont2 = 0;

        for(int n = 48; n < 58; n++){

            if((tem_numero) == cont2){
                *(numero_car+c) = char(n);
            }
            cont2++;
        }
    }
    return 0;
}
