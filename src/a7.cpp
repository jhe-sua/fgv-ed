#include <iostream>

using namespace std;

class ArrayDinamico
{
    int capacidade;
    int tamanho;
    int* dados;

    public:

    ArrayDinamico(int capacidade)
    {
    this->dados = new int[capacidade];

    for(int i=0; i < capacidade; i++)
    {
        this->dados[i] = 0;
    }
    
    this->capacidade = capacidade;
    this->tamanho = 0;
    }

    ~ArrayDinamico()
    {
        delete[] this->dados;
    }

    void display()
    {   
        cout << "Capacidade: " << this->capacidade << endl;
        cout << "Tamanho: " << this->tamanho << endl;

        cout << "[";
        for (int i = 0; i < this->tamanho - 1; i++)
        {
            cout << this->dados[i] << ", ";
        }
        cout << this->dados[this->tamanho - 1] << "]" << endl;
        
    }

    void resize(int nova_capacidade)
    {
        int* novos_dados = new int[nova_capacidade];
        for (int i = 0; i < this->capacidade; i++)
        {
            novos_dados[i] = this->dados[1];
        }
        delete[] this->dados;
        this->dados = novos_dados;
        this->capacidade = nova_capacidade;
    }

    void append(int value)
    {   
        if(this->capacidade == this->tamanho){
            resize(2*this->capacidade);
        }

        this->dados[this->tamanho] = value;
        this->tamanho++;
    }
};


class Notificacao
{
    std::string texto;

    public:

        Notificacao(std::string texto)
        {
            this->texto = texto;
        }

        virtual void enviar() = 0; //metodo abstrato
};

class SMS: public Notificacao
{
    public:

        SMS(std::string texto) : Notificacao(texto)
        {

        }

        void enviar() override
        {
            cout << "SMS" << endl;
        }
};
