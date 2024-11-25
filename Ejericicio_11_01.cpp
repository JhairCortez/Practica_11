// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 25/11/2024
// Número de ejercicio: 1
// Problema planteado: Crear un programa que permita al usuario ingresar una lista de nombres
#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

void escribirNombres(const string &nombreArchivo) 
{
    ofstream archivo(nombreArchivo);
    if (!archivo) 
    {
        cerr << "Error: No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    cout << "Ingrese nombres (escriba 'FIN' para terminar):" << endl;
    string nombre;
    while (true) 
    {
        getline(cin, nombre);
        if (nombre == "FIN") break;
        archivo << nombre << endl;
    }
    archivo.close();
    cout << "Los nombres se guardaron correctamente en el archivo '" << nombreArchivo << "'." << endl;
}

void leerNombres(const string &nombreArchivo) 
{
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error: No se pudo abrir el archivo para lectura." << endl;
        return;
    }
    cout << "Contenido del archivo '" << nombreArchivo << "':" << endl;
    string linea;
    while (getline(archivo, linea)) 
    {
        cout << linea << endl; 
    }
    archivo.close();
}

int main() 
{
    const string nombreArchivo = "nombres.txt";
    escribirNombres(nombreArchivo);
    leerNombres(nombreArchivo);
    return 0;
}