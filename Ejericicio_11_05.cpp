// Materia: Programación I, Paralelo 1
// Autor: Jhair Anderson Cortez Peña
// Fecha creación: 25/11/2024
// Número de ejercicio: 5
// Problema planteado: Crear un programa que permita actualizar los precios de productos en un archivo "productos.txt". Si el producto no se encuentra, debe informar al usuario que no existe.
#include <iostream>
#include <fstream> 
#include <string>  
#include <sstream> 
#include <vector>
using namespace std;

void actualizarProducto(const string &nombreArchivo) 
{
    ifstream archivoLectura(nombreArchivo); 
    if (!archivoLectura) 
    {
        cerr << "Error: No se pudo abrir el archivo para lectura." << endl;
        return;
    }
    vector<string> productos;
    string linea;
    bool productoEncontrado = false;
    cout << "Ingrese el nombre del producto que desea actualizar: ";
    string nombreProducto;
    getline(cin, nombreProducto);
    cout << "Ingrese el nuevo precio: ";
    double nuevoPrecio;
    cin >> nuevoPrecio;
    cin.ignore(); 
    while (getline(archivoLectura, linea)) 
    {
        stringstream ss(linea);
        string producto;
        double precio;
        ss >> producto >> precio; 
        if (producto == nombreProducto) 
        {
            productos.push_back(producto + " " + to_string(nuevoPrecio));
            productoEncontrado = true;
        } else 
        {
            productos.push_back(linea);
        }
    }
    archivoLectura.close();
    if (!productoEncontrado) 
    {
        cout << "El producto '" << nombreProducto << "' no existe en el archivo." << endl;
        return;
    }
    ofstream archivoEscritura(nombreArchivo, ios::trunc); 
    if (!archivoEscritura) 
    {
        cerr << "Error: No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    for (const string &producto : productos) 
    {
        archivoEscritura << producto << endl;
    }
    archivoEscritura.close();
    cout << "El precio del producto '" << nombreProducto << "' ha sido actualizado." << endl;
}

int main() 
{
    const string nombreArchivo = "productos.txt";
    actualizarProducto(nombreArchivo);
    return 0;
}