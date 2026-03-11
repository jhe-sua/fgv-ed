#include <iostream>

using namespace std;

// Prototipos
struct ListaDinamica;
ListaDinamica* inicializar(int capacidade);
void deletar(ListaDinamica* p);
void resize(ListaDinamica* p, int nova_capacidade);
void append(ListaDinamica* p, int value);
void display(ListaDinamica* p);

struct ListaDinamica
{
    int capacidade;
    int tamanho;
    int* dados;
};

ListaDinamica* inicializar(int capacidade)
{
    ListaDinamica* arr = new ListaDinamica;
    (*arr).dados = new int[capacidade];
    (*arr).capacidade = capacidade;
    (*arr).tamanho = 0;

    for(int i=0; i < capacidade; i++)
    {
        (*arr).dados[i] = 0;
    }
    return arr;
}

void deletar(ListaDinamica* p)
{
    delete[] (*p).dados;
    delete p;
}

void resize(ListaDinamica* p, int nova_capacidade){
    int* novos_dados = new int[nova_capacidade];
    for (int i = 0; i < (*p).capacidade; i++)
    {
        novos_dados[i] = (*p).dados[1];
    }
    delete[] (*p).dados;
    (*p).dados = novos_dados;
    (*p).capacidade = nova_capacidade;
}

void append(ListaDinamica* p, int value)
{   
    if((*p).capacidade == (*p).tamanho){
        resize(p, 2*(*p).capacidade);
    }

    (*p).dados[(*p).tamanho] = value;
    (*p).tamanho++;
}

void display(ListaDinamica* p)
{   
    cout << "Capacidade: " << (*p).capacidade << endl;
    cout << "Tamanho: " << (*p).tamanho << endl;

    cout << "[";
    for (int i = 0; i < (*p).tamanho - 1; i++)
    {
        cout << (*p).dados[i] << ", ";
    }
    cout << (*p).dados[(*p).tamanho - 1] << "]" << endl;
    
}