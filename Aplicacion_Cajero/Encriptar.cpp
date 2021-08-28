#include <iostream>
#include <fstream>
#include<string>
#include<math.h>
#define Semilla 4

using namespace std;

void Decimal_Binario(int decimal, string &binario1){

    /**Esta funcion convierte un numero decimal a su representacion binaria
      *recibe como parametro un int decimal que es el numero que se va a representar como binario
      *y un strign binario que es la clase donde se va a almacenar la representacion binaria
    **/

    unsigned short int prueba = 0;
    unsigned short int *dir_prueba = &prueba;

    for(int i = 7; i >= 0; i--){
        *dir_prueba = pow(2,i);
        if( prueba <= decimal ){
            decimal -= prueba;
            binario1 += '1';
        }
        else{
            binario1 += '0';
        }
    }

}



int Binario_Decimal(string binario){

    /**Esta funcion recibe como parametro un string que contine una representacion
     * binaria de 8 bits y lo que hace es convertir esa representacion a un numero decimal
    **/

    int suma = 0;

    for(int i = 7; i >= 0; i--){
        if(binario.at(7-i) == '1' && binario.at(7-i) != '\n' ){
            suma += pow(2,i);
        }
    }
    return suma;
}

void Lectura_Archivos(string &texto, string nombre){

    /**Esta funcion lee el contenido de un archivo de texto
     * recibe como parametros dos variables tipo string
     * la variable texto es la que va a almacenar el contenido del archivo de texto
     * la variable nombre contiene el nombre del archivo de texto y nos permite localizar
     * donde se encuentra el archivo
    **/

    string add;

    ifstream archivo;

    archivo.open("../Aplicacion_Cajero/BD/"+nombre);

    if(!archivo.is_open()){
        cout << "El archivo " << nombre << " no pudo ser abierto" << endl;
        exit(1);
    }

    while(getline(archivo, add)){
        texto += add+'\n';
    }
    archivo.close();
}


void Escritura_Archivos(string texto[3], string nombreopen){

    /**Esta funcion escribe en un archivo de texto
     * recibe como parametro dos variables tipo string
     * la variable texto tiene almacenada la informacion que se desea
     * escribir en el archivo
     * la variable nombreopen tiene almacenado el nombre del archivo
     * donde se desea escribir
    **/


    string ruta = "../Aplicacion_Cajero/BD/";
    string prueba;
    Lectura_Archivos(prueba, nombreopen);

    ofstream archivo;
    ruta += nombreopen;

    archivo.open(ruta);

    if(!archivo.is_open()){
        cout << "El archivo " << nombreopen << " no pudo ser abierto" << endl;
        exit(1);
    }

    if(prueba != "\n"){
        archivo << prueba;
    }
    for(int i = 0; i < 3; i++)
        archivo << texto[i] << endl;

    archivo.close();

}


void Codificacion_Metodo2(string texto, string &salida){

    /**Esta funcion permite codificar un archivo de texto
     * recibe como parametro dos variables tipo string
     * la variable texto contiene lo que deseamos codificar y la codificacion se guardara en la variable salida
     * La variable semilla contiene el tamaño de los bloques que deseamos tomar
     * Reglas de codificacion:
     * Cada bit en cada bloque se desplazara una posicion a la derecha
    **/

    string binario;
    string bloque1;
    string codificado;

    unsigned int longi = texto.length();

    for(unsigned int i = 0; i < (longi); i++){
        Decimal_Binario(int(texto[i]),binario);
    }

    for(unsigned int n = 0; n < (longi*8); n++){
        bloque1 = binario.substr((Semilla*n),Semilla);
        if(bloque1 == ""){
            break;
        }
        codificado+= bloque1.at((bloque1.length())-1);
        for(unsigned int i = 0; i < bloque1.length()-1; i++){
            codificado += bloque1.at(i);
        }
        if(bloque1.length() < Semilla){
            break;
        }
    }
    salida = codificado;
}


void Decodificacion_Metodo2(string texto, string &decodificado){

    /**Esta funcion permite decodificar un archivo de texto previamente codificado
     * recibe como parametro dos variables tipo string
     * La variable decodificado va a almacenar el archivo de texto totalmente decodificado
     * la variable texto contiene el archivo codificado que deseamos codificar
     * La variable semilla contiene el tamaño de los bloques que deseamos tomar
     * Reglas de codificacion:
     * Cada bit en cada bloque se desplazara una posicion a la izquierda
    **/

    string binario;
    string bloque1;
    string codificado;

    unsigned int longi = texto.length()-1;

    for(unsigned int n = 0; n < (longi*8); n++){
        bloque1 = texto.substr((Semilla*n),Semilla);
        if(bloque1 == "" || bloque1 == "\n"){
            break;
        }
        codificado+= bloque1.at(1);
        for(unsigned int i = 2; i < bloque1.length(); i++){
            if(bloque1.at(i) != '\n'){
                codificado += bloque1.at(i);
             }
        }
        codificado+= bloque1.at(0);
        if(bloque1.length() < Semilla){
            break;
        }
    }
    unsigned int decima = 0;
    for(unsigned int n = 0; n < longi; n++){
        binario = codificado.substr(n*8,8);
        if(binario.length() < 8 || binario == ""){
            break;
        }
        decima = Binario_Decimal(binario);
        decodificado += char(decima);
    }
}

