#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <limits>
#include "Edge.h"
using std::list;
using std::vector;
using std::numeric_limits;

/**
 * Classe que especifica um TAD ListGraph que implementa um 
 * grafo como uma lista de adjacencias.
 * Um grafo é um conjunto de vertices e um conjunto de arestas.
 * Vertices sao representados pelos inteiros 0 a n-1.
 * Arestas sao pares ordenados de vertices.
*/
template<typename T, typename K>
class ListGraph {
private:
    int _num_v;               // numero de vertices
    int _num_e;               // numero de arestas
    bool _directed;          // flag para indicar se eh direcionado
    vector<list<Edge<T, K>>> _adj;  // listas de adjacencias

public:
    /**
     * Construtor. Constroi o grafo
     * @param n O numero de vertices
     * @param d True se esse eh um grafo direcionado
    */
    ListGraph(int n, bool d){
        this-> _num_v = n;
        this-> _directed = d;
    }

    // Destrutor
    ~ListGraph() = default;

    /**
     * Retorna o numero de vertices
     * @param O numero de vertices
     */
    int get_num_v() const { return _num_v; }

    /**
     * Retorna o numero de arestas
     * @param O numero de arestas
     */
    int get_num_e() const { return _num_e; }

    /**
     * Determina se esse eh um grafo direcionado
     * @return true se e somente se esse eh um grafo direcionado
     */
    bool is_directed() const { return _directed; }

    /**
     * Insere uma nova aresta no grafo
     * @param edge A nova aresta
     */
    void insert(const Edge<T,K>& edge){
        bool existe_o_source = false;
        bool existe_o_dest = false;

        Edge<int,double> novo(edge.get_dest(), edge.get_source());

        int indice_do_source;
        int indice_do_dest;

        for(int i = 0; i < _adj.size(); i++){
            indice_do_source = i;
            if(edge.get_source() == _adj[i].begin()->get_source()){
                existe_o_source = true;
                _adj[i].push_back(edge);
                break;
            }
        }

        for(int i = 0; i < _adj.size(); i++){
            indice_do_dest = i;
            if(edge.get_dest() == _adj[i].begin()->get_dest()){
                existe_o_dest = true;
                _adj[i].push_back(edge);
                break;
            }
        }

        if(existe_o_source == false){
            list<Edge<T,K>> aux;
            aux.push_back(edge);
            _adj.push_back(aux);
        }

        if(existe_o_dest == false){
            list<Edge<T,K>> aux;
            aux.push_back(novo);
            _adj.push_back(aux);
        }        
    }

    /**
     * Determina se uma aresta existe
     * @param source O vertice de origem
     * @param dext O vertice de destino
     * @return true se existe uma aresta de source para dest
    */
    bool is_edge(T source, T dest) const{
        int indice = 0;
        for (int i = 0; i < _adj.size(); i++){
            indice = i;
            if(_adj[i].begin()->get_source() == source){
                break;
            }
        }

        for (auto it = _adj[indice].begin(); it != _adj[indice].end(); it++){
            if((*it).get_source() == source && (*it).get_dest() == dest && (*it).get_weight() != numeric_limits<K>::infinity()){
                return true;
            }
        }
        return false;
        
    }

    /** Obtem a aresta entre dois vertices
     * @param source O vertice origem
     * @param dest O vertice destino
     * @return A aresta entre os dois vertices ou uma aresta
     * com peso igual a numeric_limits<double>::infinity() se nao existe nenhuma aresta
     */
    //Edge<T,K> get_edge(T source, T dest) const;

    /**
     * Retorna uma referencia para a lista de adjacencias de um vertice
     * @param source O vertice origem
     * @return Uma const reference para a lista de adjacencias de um vertice
    */
    list<Edge<T,K>>& neighbors(T source){
        bool existe_o_source = false;
        int indice_do_source;
        for(int i = 0; i < _adj.size(); i++){
            if(source == _adj[i].begin().get_source()){
                existe_o_source = true;
                indice_do_source = i;
            }
        }
        if(existe_o_source){
            return _adj[indice_do_source];
        }
        else{
            return list<Edge<T, K>>(); //forma correta de retornar uma lista vazia
        }
    }
    const list<Edge<T,K>>& neighbors(T source) const{
        bool existe_o_source = false;
        int indice_do_source;
        for(int i = 0; i < _adj.size(); i++){
            if(source == _adj[i].begin().get_source()){
                existe_o_source = true;
                indice_do_source = i;
            }
        }
        if(existe_o_source){
            return _adj[indice_do_source];
        }
        else{
            return list<Edge<T, K>>(); //forma correta de retornar uma lista vazia
        }
    }

    /** 
     * Retorna um iterator para a primeira aresta adjacent ao vertice especificado.
     * @param source O vertice origem
     * @return Um iterador para as arestas adjacentes a source
    */
    //list<Edge<T,K>>::iterator begin(T source);
    //list<Edge<T,K>>::const_iterator begin(T source) const;

    /** Retorna um iterador uma posicao apos a ultima aresta 
     * adjacente ao vertice especificado
     * @param source O vertice origem
     */
    //list<Edge<T,K>>::iterator end(T source);
    //list<Edge<T,K>>::const_iterator end(T source) const;

    // Funcoes deletadas
    //ListGraph(const ListGraph&) = delete;
    //ListGraph& operator=(const ListGraph&) = delete;

};


#endif