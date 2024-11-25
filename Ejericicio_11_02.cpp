// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 25/11/2024
// Número de ejercicio: 2
// Problema planteado: Crear un programa que lea un archivo de texto llamado "texto.txt" y cuente la cantidad total de palabras contenidas en el archivo. Una "palabra" se define como cualquier secuencia de caracteres separada por espacios o saltos de línea.
#include <iostream>
#include <fstream> 
#include <string> 
#include <sstream> 
using namespace std;

int contarPalabras(const string &nombreArchivo) 
{
    ifstream archivo(nombreArchivo); 
    if (!archivo) 
    {
        cerr << "Error: No se pudo abrir el archivo para lectura." << endl;
        return -1; 
    }
    int contadorPalabras = 0;
    string linea;
    while (getline(archivo, linea)) 
    {
        stringstream ss(linea); 
        string palabra;
        while (ss >> palabra) 
        { 
            contadorPalabras++;
        }
    }
    archivo.close();
    return contadorPalabras;
}

int main() 
{
    const string nombreArchivo = "texto.txt";
    int totalPalabras = contarPalabras(nombreArchivo);
    if (totalPalabras != -1) 
    {
        cout << "El archivo '" << nombreArchivo << "' contiene " << totalPalabras << " palabras." << endl;
    }
    return 0;
}