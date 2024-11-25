// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 25/11/2024
// Número de ejercicio: 3
// Problema planteado: Crear un programa que permita registrar la información de varios estudiantes
#include <iostream>
#include <fstream> 
#include <string>
#include <iomanip>
using namespace std;

void registrarEstudiantes(const string &nombreArchivo) 
{
    ofstream archivo(nombreArchivo, ios::app); 
    if (!archivo) 
    {
        cerr << "Error: No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    cout << "Ingrese la información de los estudiantes. Escriba 'FIN' como nombre para terminar." << endl;
    while (true) 
    {
        string nombre;
        int edad;
        double promedio;
        cout << "Nombre: ";
        getline(cin, nombre);
        if (nombre == "FIN") break;
        cout << "Edad: ";
        cin >> edad;
        cout << "Promedio: ";
        cin >> promedio;
        cin.ignore();
        archivo << nombre << "," << edad << "," << promedio << endl;
    }
    archivo.close();
    cout << "Los registros se han guardado en el archivo '" << nombreArchivo << "'." << endl;
}

void mostrarEstudiantes(const string &nombreArchivo) 
{
    ifstream archivo(nombreArchivo); 
    if (!archivo) 
    {
        cerr << "Error: No se pudo abrir el archivo para lectura." << endl;
        return;
    }
    cout << left << setw(20) << "Nombre" << setw(10) << "Edad" << setw(10) << "Promedio" << endl;
    cout << string(40, '-') << endl;
    string linea;
    while (getline(archivo, linea)) 
    {
        size_t pos1 = linea.find(',');
        size_t pos2 = linea.find(',', pos1 + 1);
        string nombre = linea.substr(0, pos1);
        int edad = stoi(linea.substr(pos1 + 1, pos2 - pos1 - 1));
        double promedio = stod(linea.substr(pos2 + 1));
        cout << left << setw(20) << nombre << setw(10) << edad << setw(10) << promedio << endl;
    }
    archivo.close();
}

int main() 
{
    const string nombreArchivo = "estudiantes.txt";
    int opcion;
    do 
    {
        cout << "\nMenú:\n";
        cout << "1. Registrar estudiantes\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) 
        {
            case 1:
                registrarEstudiantes(nombreArchivo);
                break;
            case 2:
                mostrarEstudiantes(nombreArchivo);
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
    return 0;
}