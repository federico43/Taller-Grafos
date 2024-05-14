#include <iostream>
#include "sistemaInformatico.h"

using namespace std;
int main() {
  vector<Articulo> articulos;
  articulos.push_back(Articulo("Exercise and Cognitive Function", {"A. F. Kramer", "et al."}, "J Appl Physiol", "101:1237", 2006));
  articulos.push_back(Articulo("Neural Mechanisms of Aging", {"R.S. Wilson", "et al."}, "Neurology", "59:1910", 2002));
  articulos.push_back(Articulo("Proteins in Neurological Diseases", {"E. Carro", "et al."}, "J Neurosci", "21:5678", 2001));
  articulos.push_back(Articulo("Public Health and Aging", {"J. Weuve", "et al."}, "JAMA", "292:1454", 2004));
  articulos.push_back(Articulo("Geriatric Care Management", {"E. B. Larson", "et al."}, "Ann Intern Med", "144:73", 2006));
  articulos.push_back(Articulo("Cognitive Decline in the Elderly", {"K. Yaffe", "et al."}, "Arch Intern Med", "161:1703", 2001));
  articulos.push_back(Articulo("Impact of Fitness on Brain and Cognition", {"S. J. Colcombe", "et al."}, "PNAS", "101:3316", 2004));
  articulos.push_back(Articulo("Brain Size and Aging", {"N. Raz", "et al."}, "Cereb Cortex", "15:1670", 2005));
  int size = articulos.size();
  sistemaInformatico sistema(articulos,size);

  sistema.actualizarMatriz(0,1);
  sistema.actualizarMatriz(0,3);
  sistema.actualizarMatriz(1,3);
  sistema.actualizarMatriz(2,3);
  sistema.actualizarMatriz(3,4);
  sistema.actualizarMatriz(4,3);
  

  cout << "Taller Grafos...\n " << endl;
  cout << "Articulos a usar para este ejemplo:" << endl<< endl;

  for(int i = 0 ; i < size ; i++){
    cout << i << " " <<  articulos[i].getNombre() << endl << endl;
  };

  cout << "\n Representamos las relaciones entre estos articulos por medio de una matriz de adyacencia:" << endl;
  sistema.imprimirMatriz();

  //funciones a usar:
  //1. 
  cout<< "\n encontrando articulo mas citado: " << endl;
  Articulo articuloMasCitado = sistema.articuloMasCitado();
  cout << articuloMasCitado.getNombre();
  cout<< endl;
  //2.
  cout << "\n encontrando la cantidad de grupos al eliminar articulo con indice 3"<<endl;
  cout << sistema.cntGrupos(3);
  cout<< endl;
  //3
  //cout << "\n encontrando el indice de referencia para el articulo con indice 3"<<endl;
  cout << sistema.indiceReferencia(articulos[3]);
  cout<< endl;
  //4
  cout << "\n encontrando el numero de referencias inderectas al articulo con indice 3" << endl;
  cout << sistema.numIndirectas(articulos[3]);
  cout<< endl;
}