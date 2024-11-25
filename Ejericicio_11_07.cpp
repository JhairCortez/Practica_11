// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 25/11/2024
// Número de ejercicio: 7
// Problema planteado: Crear un programa que lea un archivo "calificaciones.txt" que contiene el nombre de un estudiante seguido de varias calificaciones, calcule el promedio de cada estudiante y escriba el resultado en un archivo "promedios.txt" en el formato: Nombre Promedio.
#include <iostream>
#include <fstream> 
#include <string> 
#include <sstream> 
#include <iomanip>
using namespace std;

void calcularPromedios(const string &archivoEntrada, const string &archivoSalida) 
{
    ifstream archivoLectura(archivoEntrada);
    if (!archivoLectura) 
    {
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
        stringstream ss(linea);
        string nombre;
        double calificacion;
        double sumaCalificaciones = 0;
        int contadorCalificaciones = 0;
        ss >> nombre;
        while (ss >> calificacion) 
        {
            sumaCalificaciones += calificacion;
            contadorCalificaciones++;
        }
        if (contadorCalificaciones > 0) 
        {
            double promedio = sumaCalificaciones / contadorCalificaciones;
            archivoEscritura << nombre << " " << fixed << setprecision(2) << promedio << endl;
        }
    }
    archivoLectura.close();
    archivoEscritura.close();
    cout << "Los promedios de los estudiantes se han guardado en '" << archivoSalida << "'." << endl;
}

int main() 
{
    const string archivoEntrada = "calificaciones.txt";
    const string archivoSalida = "promedios.txt";
    calcularPromedios(archivoEntrada, archivoSalida);
    return 0;
}