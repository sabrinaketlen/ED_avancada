#include <iostream>
#include <fstream>
#include "Edge.h"
#include "ListGraph.h"

using namespace std;
void questao_um(){

    fstream file;
    file.open("grafo.txt");
    int vertices;
    int arestas;

    while (file>>vertices){
        
        file >> arestas;

        cout << "vertices: "<< vertices << "arestas: " << arestas << endl;

        //ListGraph<int,double> grafo(vertices,false);

        int contador = 0;
        list<Edge<int,double>> _arestas;

        for(int i = 0; i < arestas; i++){
            int s;
            int d;
            file >> s ;
            file >> d ;
            Edge<int,double> novo(s,d);
            _arestas.push_back(novo);
        }
        cout << endl;
    }
    
    file.close();
}
