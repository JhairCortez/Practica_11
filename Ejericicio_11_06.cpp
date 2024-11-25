// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 25/11/2024
// Número de ejercicio: 6
// Problema planteado: Crear un programa que lea el archivo "temperaturas.txt" que contiene el nombre de las ciudades y sus temperaturas promedio, y genere un archivo "altas_temperaturas.txt" que solo contenga las ciudades con temperaturas superiores a N°C.
#include <iostream>
#include <fstream>
#include <string>  
#include <sstream> 
#include <iomanip> 
using namespace std;

void filtrarTemperaturas(const string &archivoEntrada, const string &archivoSalida, double temperaturaLimite) {
    ifstream archivoLectura(archivoEntrada); 
    if (!archivoLectura) {
        cerr << "Error: No se pudo abrir el archivo para lectura." << endl;
        return;
    }
    ofstream archivoEscritura(archivoSalida); 
    if (!archivoEscritura) {
        cerr << "Error: No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    string linea;
    bool hayTemperaturasAltas = false;
    while (getline(archivoLectura, linea)) 
    {
        stringstream ss(linea);
        string ciudad;
        double temperatura;
        ss >> ciudad >> temperatura; 
        if (temperatura > temperaturaLimite) 
        {
            archivoEscritura << ciudad << " " << fixed << setprecision(2) << temperatura << endl;
            hayTemperaturasAltas = true;
        }
    }
    archivoLectura.close();
    archivoEscritura.close();
    if (!hayTemperaturasAltas) 
    {
        cout << "No hay ciudades con temperaturas superiores a " << temperaturaLimite << "°C." << endl;
    } else 
    {
        cout << "Las ciudades con temperaturas superiores a " << temperaturaLimite << "°C se han guardado en '" << archivoSalida << "'." << endl;
    }
}

int main() 
{
    const string archivoEntrada = "temperaturas.txt";
    const string archivoSalida = "altas_temperaturas.txt";
    double temperaturaLimite;
    cout << "Ingrese la temperatura límite (en °C): ";
    cin >> temperaturaLimite;
    filtrarTemperaturas(archivoEntrada, archivoSalida, temperaturaLimite);
    return 0;
}