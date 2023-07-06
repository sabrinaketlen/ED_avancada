#include <iostream>
#include <fstream>
#include "Edge.h"
#include "ListGraph.h"
using namespace std;


/**PROJETO 02, TRABALHO FINAL DE ESTRUTURA DE DADOS AVANCADA
 * ALUNOS:
 * Sabrina Ketlen Colares Santos
 * Juliano Magalhães Jurity
*/

/**COMENTARIOS GERAIS SOBRE O CODIGO
 * 1. Cada uma das questoes faz uma leitura de arquivo. Quando o arquivo é lido, o grafo eh testado e a resposta eh printada.
 * 2. As leituras dos arquivos foram feitas foram da main. A main apenas chama as funcoes que le os arquivos individuais de cada
 * questao e as responde.
 * 3. Essas sao as funcoes criadas especificamente para cada questao:
 * Primeira -> "questao_um", "bipartido", "bipartido_DFS";
 * Segunda -> "questao_dois", "BFS", "retorna_filme";
 * Terceira -> "questao_tres","get_bridges", "search_bridges", "converte".
 * 4. Os arquivos estao identificados de acordo com a questao que os le.
 * 5. Os arquivos contem grafos presentes nos arquivos de teste enviado pelo professor no moodle, e no caso da primeira questao
 * contem grafos considerados casos especificos para a questao.
 * 6. Ao executar o codigo (testamos com "g++ main.cpp -o teste.exe" e "./teste.exe") as respostas de todas as questoes serao
 * printadas juntas, com um cabecalho sinalizando qual eh qual.
 * 7. Se o professor quiser a resposta de uma questao por vez, basta ir na main e comentar (por "//" antes d)as funcoes que tratam
 * das outras questoes.
 * 8. O arquivo contem o exe usado para testar. ("./teste.exe")
*/

/**
* funcao criada somente para ler o arquivo que sera utilizado na questao.
* printa o resultado de cada grafo lido, de acordo com o retorno da funcao publica "bipartido"
**/
void questao_um(){
     cout <<"--------------------" << endl
          <<"  PRIMEIRA QUESTAO  " << endl
          <<"--------------------" << endl;

    fstream file;
    file.open("primeiraquestao.txt");
    if(!file.is_open()){
        cout << "Error: File Open" << endl;
    }
    int vertices;
    int arestas;

    while (file>>vertices){
        
        file >> arestas;

        ListGraph<int,double> grafo(vertices,false);

        for(int i = 0; i < arestas; i++){
            int s;
            int d;
            file >> s ;
            file >> d ;
            Edge<int,double> novo(s,d);
            grafo.insert(novo);
        }

        if(grafo.bipartido()){
            cout << "SIM" << endl;
        }
        else{
            cout << "NAO" << endl;
        }
       
    }
    
    file.close();
}


//função para retornar o filme baseado na string informada, criei para me ajudar a printar os filmes padronizados com a ordenação
string retorna_filme(vector<Edge<string, string>>& vec, string ator){
    if(ator != "Kevin Bacon"){
        for(int i = 0; i < vec.size(); i++){
            if(vec[i].get_source() == ator){
            return vec[i].get_weight();
            }
        }
    }
    return "";
}
/**
* funcao criada para ler o arquivo da questão 2 e já printar o resultado padronizado com o output.txt
* 
**/
void questao_dois(){

    cout <<"--------------------" << endl
         <<"   SEGUNDA QUESTAO  " << endl
         <<"--------------------" << endl;

    ifstream ip("segundaquestao.txt");

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

/**
 * funcao criada para ler o arquivo da questao 3.
 * identifica as pontes do grafo atraves da funcao "get_pontes"
 * e responde a questao dando as direcoes das pontes e demais arestas do grafo.
*/
void questao_tres(){

    cout <<"--------------------" << endl
         <<"  TERCEIRA QUESTAO  " << endl
         <<"--------------------" << endl;

    fstream file;
    file.open("terceiraquestao.txt");

    if(!file.is_open()){
        cout << "Error: File Open" << endl;
    }

    int vertices;
    int arestas;
    int contador = 0;

    while (file>>vertices){
        
        file >> arestas;
        
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

        int time_s = 1;
        vector<int> num;
        num.resize(vertices);
        for (int i = 0; i < num.size(); i++)
        {
            num[i] = 0;
        }
        
        vector<pair<int, int>> auxiliar = grafo.get_bridges(time_s, num);
        cout << "Caso " << contador+1 << endl;
        grafo.converte(auxiliar);
        cout << "#" << endl;
        
        contador++;
       
    }
    
    file.close();
}

int main() {
    
    questao_um();
    questao_dois();
    questao_tres();
    
}




