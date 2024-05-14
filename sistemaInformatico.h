  #ifndef SISTEMAINFORMATICO_H
  #define SistemaInformacion_H
  
  #include <bits/stdc++.h>
  #include "Articulo.h"
  using namespace std; 
  
  class sistemaInformatico{
  private:
    vector<Articulo> ListaArticulos;
    vector<vector<int>> MatrizAdyacencia;
    
  public:
    void imprimirMatriz(){
      for(int i = 0; i < MatrizAdyacencia.size(); i++){
        cout << "articulo " << i << ": ";
        for(int j = 0; j < MatrizAdyacencia[i].size(); j++){
          cout << MatrizAdyacencia[i][j] << " ";
        }
        cout << endl;
      }
    }
  
    //Crea una arista en la matriz de adyacencia
    void actualizarMatriz(int x, int y){
      if( x < MatrizAdyacencia.size() && y < MatrizAdyacencia[0].size())
        MatrizAdyacencia[x][y] = 1;
      else
        cout << "No se puede actualizar la matriz" << endl;
    }
  
    /*constructor*/
    sistemaInformatico(vector<Articulo>& newArticulos, int i){
      int newSize = newArticulos.size();
      MatrizAdyacencia.resize(newSize, vector<int>(newSize, 0));
      ListaArticulos = newArticulos;
      
    }
    /*4.1.3: algoritmo 1: Encontrar el Articulo con mayor citaciones.*/
    Articulo articuloMasCitado(){
      int max = 0;
      int artcl = 0;
      int i = 0;
      for( ; i < MatrizAdyacencia.size(); i++){
        int contador = 0;
        for(int j = 0 ; j < MatrizAdyacencia[i].size(); j++){
          if(MatrizAdyacencia[j][i] == 1)
            contador++;
        }
        if(contador > max){ 
          max = contador;
          artcl = i;
        }
      }
      
      return ListaArticulos[artcl];
    }
  
    /*4.1.4: algoritmo 2: dado un vertice, encontrar los grupos que quedan al quitar este vertice del grafo */
  
    int cntGrupos(int f){
      cout << "Calculando grupos despues de borrar el articulo con indice:" << f << endl;
      //crear copia de la matriz. 
      vector<vector<int>> matriz = MatrizAdyacencia;

      for(int i = 0; i < matriz.size(); i++){
        for(int j = 0; j < matriz.size(); j++){
          if(matriz[i][j] == 1 && i != j){
            matriz[j][i] = 1;
          }
          cout <<  matriz[i][j] <<" ";
        }
        cout << endl;
      } 
      
      //Crear array de visitados.
      vector<bool> visitado(matriz.size(), false);
      //marcar indice como visitado. 
      visitado[f] = true;
      //hacer algoritmo de dfs.
      int counter  = 0 ;
      for(int i  = 0 ;  i < matriz.size(); i++){
  
        if(!visitado[i]){
          cout << "grupo: ";
          dfsUtil(i,visitado,matriz);
          counter++;
          cout << "\n";
        }
      }
      cout << "Cantidad de grupos: " << counter << endl;
      return counter;
    }
  
    //funcion auxiliar: dado un indice, hace un dfs.
    void dfsUtil(int n, vector<bool>& visitado,vector<vector<int>> matriz){
      //marcar el indice como visitado.
      visitado[n] = true;
      cout << n << " ";
      for(int i = 0 ; i < matriz[i].size(); i++){
        if((matriz[n][i] == 1 ||matriz[n][i] == 2) && !visitado[i]){
          dfsUtil(i, visitado, matriz);
        }
      }
    }
  
    /*4.1.5: algoritmo 3: dado un articulo, calcular su inidce de referencia*/
  
    //funcion 1 auxiliar: calc el numero de articulos que citan al articulo. dado el arti
  
    int numIn(Articulo articulo){
      int indice = encontrarIndice(articulo);
      int contador = 0;
      for(int i = 0; i < MatrizAdyacencia.size(); i++){
        if(MatrizAdyacencia[i][indice] == 1)
          contador++;
      }
      return contador;
    }
    //funcion 2 auxiliar: calc el numero de articulos que este cita.
    int numOut(Articulo articulo){
      int indice = encontrarIndice(articulo);
      int contador = 0;
      for(int i = 0; i < MatrizAdyacencia.size(); i++){
        if(MatrizAdyacencia[indice][i] == 1)
          contador++;
      }
      return contador;
    }
  
    int indiceReferencia(Articulo articulo){
      int n1 = numIn(articulo);
      int n2 = numOut(articulo);
  
      return (n1/(n2*2));
    }
  
    /*4.1.6: algoritmo 4: Dado un articlo, encontrar el numero de citaciones indirectas. */
      int numIndirectas(Articulo articulo){
        int indice = encontrarIndice(articulo);
        int contador = 0;
        for(int i = 0; i < MatrizAdyacencia.size(); i++){
          if(MatrizAdyacencia[indice][i] == 1)
            for(int j = 0; j < MatrizAdyacencia[i].size(); j++){
              if(MatrizAdyacencia[i][j] == 1 && indice != j)
                contador++;
            }  
        }
        return contador;
      }
  
      // Getter for ListaArticulos attribute 
      vector<Articulo> getListaArticulos() const {
          return ListaArticulos;
      }
  
      // Getter for MatrizAdyacencia attribute
      vector<vector<int>> getMatrizAdyacencia() const {
          return MatrizAdyacencia;
      }
  
    void eliminarArticulo(int indice) {
        int n = MatrizAdyacencia.size();
        for (int i = 0; i < n; i++) {
            MatrizAdyacencia[indice][i] = 0;
            MatrizAdyacencia[i][indice] = 0;
        }
    }
    int encontrarIndice(const Articulo& articulo){
      for(int i = 0 ; i < ListaArticulos.size(); i++){
        if(ListaArticulos[i].getNombre() == articulo.getNombre())
          return i;
      }
      return -1;
    }
  
  };
  #endif