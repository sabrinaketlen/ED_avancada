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


//função para retornar o filme baseado na string informada, criei para me ajudar a printar os filmes padronizados com a ordenação
string retorna_filme(vector<Edge<string, string>>& vec, string ator){
    if(ator == "Kevin Bacon"){
        return "";
    }
    for(int i = 0; i < vec.size(); i++){
        if(vec[i].get_source() == ator){
            return vec[i].get_weight();
        }
        
    }
}
/**
* funcao criada para ler o arquivo da questão 2 e já printar o resultado padronizado com o output.txt
* 
**/
void questao_dois(){
    ifstream ip("questao02.txt");

    if(!ip.is_open()){
        cout << "Error: File Open" << endl;
    }

    string Ator1;
    string filme;
    string Ator2;

    vector<Edge<string, string>> arestas;

    while(ip.peek() != EOF){

        getline(ip, Ator1, ';');
        getline(ip, filme, ';');
        getline(ip, Ator2, '\n');

        Edge<string, string> aux(Ator1, Ator2, filme);

        arestas.push_back(aux);
    }
    ip.close();

    list<string> atoresTotais; //contar quantos vértices terá  o grafo
    for (int i = 0; i < arestas.size(); i++)
    {
        atoresTotais.push_back(arestas[i].get_source());
        atoresTotais.push_back(arestas[i].get_dest());    
    }
    
    atoresTotais.sort(); //ordeno a lista para que o unique funcione corretamente

    atoresTotais.unique(); //retirar ocorrencias repetidas de atores.

    ListGraph<string, string> grafo (atoresTotais.size(), false);
    
    for (int i = 0; i < arestas.size(); i++)
    {
        grafo.insert(arestas.at(i));
    }
    cout << endl;
    
    //este for printa o resultado padronizado com o output.txt
    for(auto it = atoresTotais.begin(); it != atoresTotais.end(); it++){
        cout << "O numero de Bacon de " << (*it) << " eh " << grafo.BFS(grafo, (*it), "Kevin Bacon") <<" pelo filme " << retorna_filme(arestas, (*it)) << endl; 
    }
    
    
    

    
}

int main() {
    
    questao_um();
    questao_dois();

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




