// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 25/11/2024
// Número de ejercicio: 4
// Problema planteado: Crear un programa que lea un archivo llamado "datos.txt" y permita al usuario buscar una palabra o frase específica. El programa debe contar cuántas veces aparece en el archivo.
#include <iostream>
#include <fstream> 
#include <string>  
using namespace std;

int buscarTexto(const string &nombreArchivo, const string &textoBuscado) 
{
    ifstream archivo(nombreArchivo);
    if (!archivo) 
    {
        cerr << "Error: No se pudo abrir el archivo para lectura." << endl;
        return -1;
    }
    string linea;
    int contador = 0;
    while (getline(archivo, linea)) 
    {
        size_t pos = linea.find(textoBuscado);
        while (pos != string::npos) 
        {
            contador++;
            pos = linea.find(textoBuscado, pos + textoBuscado.length());
        }
    }
    archivo.close();
    return contador;
}

int main() 
{
    const string nombreArchivo = "datos.txt";
    cout << "Ingrese la palabra o frase que desea buscar: ";
    string textoBuscado;
    getline(cin, textoBuscado);
    int ocurrencias = buscarTexto(nombreArchivo, textoBuscado);
    if (ocurrencias == -1) 
    {
        cout << "No se pudo realizar la búsqueda porque el archivo no está disponible." << endl;
    } else {
        cout << "El texto '" << textoBuscado << "' aparece " << ocurrencias << " veces en el archivo '" << nombreArchivo << "'." << endl;
    }
    return 0;
}