#include <iostream>
#include <fstream>
#include "Edge.h"
#include "ListGraph.h"
using namespace std;

/**
* funcao criada somente para ler o arquivo que sera utilizado na questao 1.
* funcao ainda fantasma, pois nao insere no grafico ja que a funcao insert ainda esta sendo feita
**/
void questao_um(){

    fstream file;
    file.open("grafo.txt");
    int vertices;
    int arestas;

    while (file>>vertices){
        
        file >> arestas;

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
    }
    
    file.close();
}

int main() {
    questao_um();
}

/*
void print(const ListGraph<int, double>& graph) {
    for(int i = 0; i < graph.get_num_v(); ++i) {
        cout << i << ": ";
        for(auto v = graph.begin(i); v != graph.end(i); ++v) {
            cout << *v << " ";
        }
        cout << endl;
    }
}
*/

/*
int main() {
    ListGraph<int, double> graph(5, false); // grafo com 5 vertices V = {0,1,2,3,4} nao direcionado
    graph.insert(Edge<int, double>(0,1));
    graph.insert(Edge<int, double>(1,2));
    graph.insert(Edge<int, double>(2,3));
    graph.insert(Edge<int, double>(3,4));
    graph.insert(Edge<int, double>(4,0));
    print(graph);
}
*/