#include <iostream>
#include "../tarefa1/ReservationSystem.hpp"

using namespace std;

class ArrReservaDinamico
{
private:
    int capacidade;
    int tamanho;
    Reserva* dados;
public:
    ArrReservaDinamico(int capacidade);
    ~ArrReservaDinamico();
    void resize(int nova_capacidade);
    void append(Reserva value);
};

ArrReservaDinamico::ArrReservaDinamico(int capacidade)
{
    this->dados = new Reserva[capacidade];
    this->capacidade = capacidade;
    this->tamanho = 0;

    for(int i=0; i < capacidade; i++)
    {
        this->dados[i] = Reserva();
    }
}

ArrReservaDinamico::~ArrReservaDinamico()
{
    delete[] this->dados;
}

void ArrReservaDinamico::resize(int nova_capacidade)
{
    Reserva* novos_dados = new Reserva[nova_capacidade];
    for (int i = 0; i < this->capacidade; i++)
    {
        novos_dados[i] = this->dados[i];
    }
    delete[] this->dados;
    this->dados = novos_dados;
    this->capacidade = nova_capacidade;
}

void ArrReservaDinamico::append(Reserva value)
{
    if(this->capacidade == this->tamanho){
    resize(2*this->capacidade);
    }

    this->dados[this->tamanho] = value;
    this->tamanho++;
}

// void display(ListaDinamica* p)
// {   
//     cout << "Capacidade: " << (*p).capacidade << endl;
//     cout << "Tamanho: " << (*p).tamanho << endl;

//     cout << "[";
//     for (int i = 0; i < (*p).tamanho - 1; i++)
//     {
//         cout << (*p).dados[i] << ", ";
//     }
//     cout << (*p).dados[(*p).tamanho - 1] << "]" << endl;
    
// }