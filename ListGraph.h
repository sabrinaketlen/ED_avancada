#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <limits>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include "Edge.h"
using std::list;
using std::vector;
using std::numeric_limits;
using std::queue;
using std::map;
using std::set;

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
    int _num_e {0};               // numero de arestas
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
     * @return O numero de vertices
     */
    int get_num_v() const { return _num_v; }

    /**
     * Retorna o numero de arestas
     * @return O numero de arestas
     */
    int get_num_e() const { return _num_e; }

    /**
     * Retorna as adjacencias do grafo
     * @return O vector contendo as adjacencias
     */
    vector<list<Edge<T, K>>> get_adj() const { // criei por conveniencia, achei que fosse usar, mas deixei ai
        return _adj;
    }

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
        int inseriu = 0;

        Edge<T, K> novo(edge.get_dest(), edge.get_source(), edge.get_weight());

        int indice_do_source;
        int indice_do_dest;

        for(int i = 0; i < _adj.size(); i++){
            indice_do_source = i;
            if(edge.get_source() == _adj[i].begin()->get_source()){
                existe_o_source = true;
                if(!is_edge(edge.get_source(),edge.get_dest())){
                    _adj[i].push_back(edge);
                    inseriu++;
                }
                break;
            }
        }

        for(int i = 0; i < _adj.size(); i++){
            indice_do_dest = i;
            if(edge.get_dest() == _adj[i].begin()->get_source()){
                existe_o_dest = true;
                if(!is_edge(novo.get_source(),novo.get_dest())){
                _adj[i].push_back(novo);
                inseriu++;
                }
                break;
            }
        }

        if(existe_o_source == false){
            list<Edge<T,K>> aux;
            aux.push_back(edge);
            _adj.push_back(aux);
            inseriu++;
        }

        if(existe_o_dest == false){
            list<Edge<T,K>> aux;
            aux.push_back(novo);
            _adj.push_back(aux);
            inseriu++;
        }
        if(inseriu != 0){
            this->_num_e++;
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
        int indice_do_source;
        for(int i = 0; i < _adj.size(); i++){
            if(source == _adj[i].begin()->get_source()){
                indice_do_source = i;
            }
        }
        
        return _adj[indice_do_source];
    }

    const list<Edge<T,K>>& neighbors(T source) const{
        int indice_do_source;
        for(int i = 0; i < _adj.size(); i++){
            if(source == _adj[i].begin()->get_source()){
                indice_do_source = i;
            }
        }
        return _adj[indice_do_source];
    }

    /*
    ListGraph<T, K>& operator=(const ListGraph<T, K>& other) { // possivel clone nao finalizado
        if (this == &other) {
            return *this;
        }

        this -> _num_v = other._num_v;
        this -> _num_e = other._num_e;
        this -> _directed = other._directed;

        

        return *this;
    }
    */

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



    /** Funcao que verifica se um grafo eh bipartido, o que infere que ele pode ter uma coloracao de exatamente duas cores
     * nao recebe nada como parametro pois usa atributos e funcoes da propria classe
     * @return False caso nao seja bipartido
     * @return True caso nao seja bipartido
    */
    bool bipartido() {
        // caso seja um grafo nulo (com 0 arestas) e com mais de 2 vertices, eh possivel colorir esses vertices com duas cores, ja que
        // nao tem como vizinhos terem a mesma cor por nao existirem vizinhos
        if((this->_num_e == 0) && (this->_num_v >=2)){
            return true;
        }
        else if(this->_num_v < 2){
            return false;
        }

        //define o vertice inicial
        int v = _adj[0].begin()->get_source();
        // reservo o tamanho exato dos vetores cores e visitado com a quantidade de vertices
        int quantos_vertices = this->_num_v;
        
        // inicialmente, todos os verticoes recebem cor 'n' (nenhuma)
        vector<char> cores;
        cores.reserve(quantos_vertices);
        for(int i = 0; i < quantos_vertices; i++){
            cores[i] = 'n';  
        }

        //alem disso, todos os vertices sao sinalizados como nao visitados
        vector<bool> visitado;
        visitado.reserve(quantos_vertices);
        for(int i = 0; i < quantos_vertices; i++){
            visitado[i] = false;  
        }

        // a partir do vertice inicial, eh feita uma busca em profundide de forma recursiva para verificar se a coloracao com 2 cores eh 
        //possivel
        if (!visitado[v]) {
            cores[v] = 'v';  // define a cor do vertice inicial como 'v' (vermelho), para que seus vizinhos possam ser coloridos corretamente
            if (!bipartido_DFS(v, cores, visitado)) {
                return false;
            }
        }
        // se a busca em profundidade nao retornou false, o grafo eh bipartido
        return true;
    }

    /** Funcao necessaria para classificar um grafo como bipartido ou nao
     * @param v O vertice a ter suas arestas analisadas
     * @param cores uma referencia para o vector que contem a definicao das cores dos vertices de acordo com os indices
     * @param visitado uma referencia para o vector que sinaliza se tal vertice ja foi visitado
     * @return true caso a coloracao seja aceitavel, e false caso nao
    */
    bool bipartido_DFS(int v, vector<char>& cores, vector<bool>& visitado) {
        // sinaliza o vertice recebido como resultado
        visitado[v] = true;  

        // obtem as arestas em que esse vertice faz parte como sources
        list<Edge<T, K>>& vizinhos = neighbors(v);

        // itera os vizinhos para definir as cores dos que ainda nao tiveram suas cores definidas (ou seja, ainda nao foram visitados)
        for (auto it = vizinhos.begin(); it != vizinhos.end(); it++) {
            int indice_do_vizinho = (*it).get_dest();
            if (!visitado[indice_do_vizinho]) {
                // Define a cor do vizinho com base na cor do vértice atual
                if (cores[v] == 'v') {
                    cores[indice_do_vizinho] = 'a';
                } else {
                    cores[indice_do_vizinho] = 'v';
                }

                // executa a busca em profundidade recursivamente para o vizinho
                // se retornar falso, nao eh bipartido
                if (!bipartido_DFS(indice_do_vizinho, cores, visitado)) {
                    return false;  
                }
            // se dois vertices vizinhos possuem a mesma cor, nao eh bipartido
            } else if (cores[indice_do_vizinho] == cores[v]) {
                return false;  
            }
        }
        return true;  // se nao houver nenhum retorno de false, significa que eh bipartido e retorna true
    }


    /** Funcao que faz busca em largura em um grafo com vertices em string e retorna o menor caminho entre os dois vértices dados.
     * 
     * @param G um grafo do tipo lista de adjacência
     * @param s vertice inicial
     * @param t vértice final
     * @return distância do caminho de S até T.
    */
    int BFS(ListGraph G, std::string s, std::string t){
        
        //utilizo a estrutura de dados map para mapear com int os valores em string do grafo dado
        map<T, int> m;
        int n = 0;
        for(auto &lista : G._adj){
            for(auto &a : lista){
                if(m.count(a.get_source()) == 0){
                    m[a.get_source()] = n;
                    n++;
                }
                
            }
        }
        int dist[n];
        int num[n];

        //inicio o vetor de distancia com infinito e o vetor de numeros visitados com -1
        //o -1 irá representar aqueles que não foram visitados ainda.
        for (int i = 0; i < n; i++){
            dist[i] = numeric_limits<int>::infinity();
            num[i] = -1;
        }

        int contador = 0;
        //crio uma fila para poder ir olhando os vizinhos do vértice informado e os vizinhos dos vizinhos.
        queue<int> fila;

        //como utilizei o map, na que eu for representar o indice do vetor, preciso utilizar m[s] para que assim ele retorne o int correspondente e assim coloque no vetor num e dist.
        num[m[s]] = contador;
        dist[m[s]] = 0;

        //mesma coisa no push
        fila.push(m[s]);

        contador++;
        
        //aqui começa a real busca em largura, em toda repetição do laço, checo se o i é igual ao map de t, caso seja, eu já posso retornar o valor que está em dist[i]. Caso não, eu faço um for com iterador percorrendo todos os indices da lista[i] do grafo informado e checo somente os vértices destino também utilizando o map. Caso no vetor de num esteja com -1, quer dizer que ainda não foi visitado. então eu marco ele com o contador para marcar que ele foi visitado, aumento a distancia dele em dist[i]+1 e coloco ele na pilha. Faço isso até achar o T. Caso não ache, retorno infinito.
        while(!fila.empty()){
            int i = fila.front();
            fila.pop();

            if(i == m[t]){
                return dist[i];
            }
            for(Edge<T, K> j: G._adj[i]){
                if(num[m[j.get_dest()]] == -1){
                    num[m[j.get_dest()]] = contador;
                    dist[m[j.get_dest()]] = dist[i] + 1;
                    fila.push(m[j.get_dest()]);
                }
            }
        }
        
        return numeric_limits<int>::infinity();
    }

    int Search_bridge(int s, int p, vector<std::pair<int, int>>& pontes, int& time_s, vector<int>& num){

        int menor = num[s] = time_s++;
        int filhos = 0;
        for (Edge<T, K> i : _adj[s]){
            if(num[i.get_dest()] == 0){
                filhos++;
                int m = Search_bridge(i.get_dest(), s, pontes, time_s, num);
                menor = std::min(menor, m);
                if(num[s] < m){
                    pontes.push_back(std::make_pair(s, i.get_dest()));
                }
            }
            else if(i.get_dest() != p){
                menor = std::min(menor, num[i.get_dest()]);
            }
        }
        return menor;
    }

    vector<std::pair<int, int>> get_pontes(int& time_s, vector<int>& num){
        vector<std::pair<int, int>> result;
        Search_bridge(0, -1, result, time_s, num);
        return result;
    }

    void converte(vector<std::pair<int, int>> pontes) {
        int qnt_vertices = this->_num_v;
        
        vector<std::pair<int, int>> direcoes;

        for (int i = 0; i < qnt_vertices; i++) {

            std::stack<int> pilha;
            pilha.push(i);

            while (!pilha.empty()) {
                int v = pilha.top();
                pilha.pop();

                list<Edge<int, double>> vizinhos = this->neighbors(v);
                 for(auto it = vizinhos.begin(); it!=vizinhos.end(); it++){
                    std::pair<int,int> are((*it).get_source(),(*it).get_dest());
                    std::pair<int,int> era((*it).get_dest(),(*it).get_source());

                    bool eh_ponte = false;;
                    for(int j = 0; j < pontes.size(); j++){
                        if(pontes[j] == are){
                            eh_ponte = true;

                        }
                    }

                    bool ja_ta = false;
                    for(int j = 0; j < direcoes.size(); j++){
                        if(direcoes[j] == are || direcoes[j] == era){
                            ja_ta = true;
                        }
                    }

                    if(!ja_ta){
                        if(eh_ponte){
                            direcoes.push_back(are);
                            direcoes.push_back(era);
                        }
                        else if(!eh_ponte){
                            direcoes.push_back(are);
                            pilha.push(are.second);
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < direcoes.size(); i++) {
            std::cout << direcoes[i].first << " " << direcoes[i].second << std::endl;
        }
    }

};
#endif

