#ifndef EDGE_H
#define EDGE_H
#include <string>
#include <iostream>
#include <limits>
#include <sstream>

template<typename T, typename K>
class Edge {
private:
    T _source;      // o vertice de origem da aresta
    T _dest;        // o vertice de destino da aresta
    K _weight;   // o peso da aresta

public:
    // Constroi uma aresta de source para dest com peso w
    // Se w nao for especificado ele eh setado para 1.0
    Edge(T source, T dest, K w = 1.0){
        this->_source = source;
        this->_dest = dest;
        this->_weight = w;
    }

    // Constroi uma aresta falsa com source e dest igual a -1 e 
    // weight igual a infinito
    Edge(){
        this->_source = -1;
        this->_dest = -1;
        this->_weight = std::numeric_limits<K>::infinity(); //faz a aresta ter peso inifinito de acordo com o K tipo informado para o peso, eu acho.
    }

    // Constroi uma aresta que eh uma copia de outra
    Edge(const Edge<T,K>& other){
        this->_dest = other._dest;
        this->_source = other._source;
        this->_weight = other._weight;
    }

    // Compara se duas arestas sao iguais. Duas arestas sao iguais se 
    // seus vertices de origem e destino sao iguais. O peso eh desconsiderado.
    bool operator==(const Edge<T,K>& other) const{
        return ((this->_dest == other._dest) && (this->_source == other._source));
    }

    T get_dest() const{ // retorna o destino
        return this->_dest;
    } 

    T get_source() const{ // retorna a origem
        return this->_source;
    } 

    K get_weight() const{ // retorna o peso
        return this->_weight;
    } 

    //std::string to_string() const; // retorna uma representacao de string da aresta

    // sobrecarga do operador de insercao
    //friend std::ostream& operator<<(std::ostream&, const Edge<T,K>&);
};

#endif