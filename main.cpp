#include <iostream>
#include <fstream>
#include "Edge.h"
#include "ListGraph.h"
using namespace std;

/**
* funcao criada somente para ler o arquivo que sera utilizado na questao 1.
* 
**/
void questao_um(){

    fstream file;
    file.open("grafo.txt");
    int vertices;
    int arestas;

    while (file>>vertices){
        
        file >> arestas;
        int contador = 0;
        int vertice_inicial;

        ListGraph<int,double> grafo(vertices,false);

        for(int i = 0; i < arestas; i++){
            int s;
            int d;
            file >> s ;
            file >> d ;
            Edge<int,double> novo(s,d);
            grafo.insert(novo);
        }

        bool eh = grafo.bipartido();
        cout << eh;
        // testa se eh bipartido
       
    }
    
    file.close();
}

int main() {
    
    questao_um();

    /*
    list<Edge<int, double>> teste; //criei uma lista teste vazia
    
    Edge<int, double> a(1, 2); //edge com saída do 1 e destino 2
    
    teste.push_back(a); //coloquei na lista

    ListGraph<int, double> grafoTeste (3, false); //criei um grafo com 3 vertices
    
    grafoTeste.insert(a); //coloquei o edge no grafo

    if(grafoTeste.is_edge(2, 2)){ //teste do isEdge com um edge que não foi inserido
        cout << "Verdade" << endl;
    }
    else{
        cout << "Falso" << endl;
    }

    if(grafoTeste.is_edge(1, 2)){ //teste do isEdge com um edge que foi inserido.
        cout << "Verdade" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
    */
    
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