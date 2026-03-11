#ifndef DINAMICO_N
#define DINAMICO_H

// Prototipos

namespace emap {

struct ListaDinamica
{
    int capacidade;
    int tamanho;
    int* dados;
};

ListaDinamica* inicializar(int capacidade);
void deletar(ListaDinamica* p);
void resize(ListaDinamica* p, int nova_capacidade);
void append(ListaDinamica* p, int value);
void display(ListaDinamica* p);
}

#endif