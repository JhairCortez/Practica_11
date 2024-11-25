// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 25/11/2024
// Número de ejercicio: 8
// Problema planteado: Crear un programa que lea un archivo de texto llamado "documento.txt" y cuente el número total de líneas, palabras y caracteres. El programa debe mostrar estos totales en la consola.
#include <iostream>
#include <fstream> 
#include <string> 
#include <sstream> 
using namespace std;

void contarContenido(const string &nombreArchivo) 
{
    ifstream archivo(nombreArchivo); 
    if (!archivo) 
    {
        cerr << "Error: No se pudo abrir el archivo para lectura." << endl;
        return;
    }
    int numLineas = 0;
    int numPalabras = 0;
    int numCaracteres = 0;
    string linea;
    while (getline(archivo, linea)) {
        numLineas++; 
        stringstream ss(linea);
        string palabra;
        while (ss >> palabra) 
        {
            numPalabras++; 
        }
        numCaracteres += linea.length();
    }
    archivo.close();
    cout << "Total de líneas: " << numLineas << endl;
    cout << "Total de palabras: " << numPalabras << endl;
    cout << "Total de caracteres: " << numCaracteres << endl;
}

int main() 
{
    const string nombreArchivo = "documento.txt";
    contarContenido(nombreArchivo);
    return 0;
}