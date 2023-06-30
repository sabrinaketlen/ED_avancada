#include <iostream>
#include <fstream>
#include "Edge.h"
#include "ListGraph.h"
#include "files.h"
using namespace std;

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