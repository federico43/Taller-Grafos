#ifndef ARTICULO_H
#define ARTICULO_H

#include <bits/stdc++.h>
using namespace std; 
class Articulo{
private:
  string nombre;
  vector<string> Autores;
  string editorial;
  string volumen;
  int año;

public:
    Articulo(string n, vector<string> a, string e, string v, int year) :
    nombre(n), Autores(a), editorial(e), volumen(v), año(year) {}
    
    Articulo() :
    nombre(""), Autores({}), editorial(""), volumen(""), año(0) {}

	// Getter and setters for private members
    string getNombre() const {
        return this->nombre;
    }
    void setNombre(const string& newNombre) {
        nombre = newNombre;
    }
    vector<string> getAutores() const {
        return Autores;
    }
    void setAutores(const vector<string>& newAutores) {
        Autores = newAutores;
    } 
    string getEditorial() const {
        return editorial;
    }
    void setEditorial(const string& newEditorial) {
        editorial = newEditorial;
    }
    string getVolumen() const {
        return volumen;
    }
    void setVolumen(const string& newVolumen) {
        volumen = newVolumen;
    }
    int getAño() const {
        return año;
    }
    void setAño(int newAño) {
        año = newAño;
    }

    
    
    void printAttributes() {
        cout << "Nombre: " << nombre << endl;
        cout << "Autores: ";
        for (const string& autor : Autores) {
            cout << autor << ", ";
        }
        cout << endl;
        cout << "Editorial: " << editorial << endl;
        cout << "Volumen: " << volumen << endl;
        cout << "Año: " << año << endl;
    }
};

#endif