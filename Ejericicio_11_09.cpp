// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 25/11/2024
// Número de ejercicio: 9
// Problema planteado: Crear un programa que lea un archivo de texto "mensaje.txt", aplique un cifrado César con desplazamiento de 3 sobre el texto, y guarde el resultado en "mensaje_cifrado.txt".
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

string cifrarCesar(const string &texto) 
{
    string textoCifrado = "";

    for (char c : texto) 
    {
        if (isalpha(c)) 
        { 
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + 3) % 26 + base; 
        }
        textoCifrado += c; 
    }

    return textoCifrado;
}

void cifrarArchivo(const string &archivoEntrada, const string &archivoSalida) 
{
    ifstream archivoLectura(archivoEntrada);
    if (!archivoLectura) {
        cerr << "Error: No se pudo abrir el archivo para lectura." << endl;
        return;
    }
    ofstream archivoEscritura(archivoSalida); 
    if (!archivoEscritura) 
    {
        cerr << "Error: No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    string linea;
    while (getline(archivoLectura, linea)) 
    {
        string lineaCifrada = cifrarCesar(linea);
        archivoEscritura << lineaCifrada << endl;
    }
    archivoLectura.close();
    archivoEscritura.close();
    cout << "El archivo ha sido cifrado y guardado en '" << archivoSalida << "'." << endl;
}

int main() 
{
    const string archivoEntrada = "mensaje.txt";
    const string archivoSalida = "mensaje_cifrado.txt";
    cifrarArchivo(archivoEntrada, archivoSalida);
    return 0;
}