#include <iostream>

using namespace std;

class no
{
public:
    int valor;
    no* next;
    no(int valor);
    ~no();
};

no::no(int valor)
{
    this->valor = valor;
    this->next = nullptr;
}

no::~no()
{
    delete next;
}

///////////////////////////////////////////////////////////////////////////////

class le
{
private:
    no* head;
    no* tail;
    int tamanho;
    int capacidade;
public:
    le();
    ~le();
    void inserir(int pos, int valor);
    void print();
};

le::le()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->tamanho = 0;
}

le::~le()
{   
    no* atual = head;
    no* anterior = nullptr;
    while (atual != nullptr)
    {   
        anterior = atual;
        atual = atual->next;
        delete anterior;
        anterior = nullptr;
    }
}

void le::inserir(int pos, int valor)
{
    // caso de contorno
    if (tamanho == 0)
    {
        no* temp = new no(valor);
        head = temp;
        tail = temp;
        tamanho++;
        return;
    }

    if (pos == 0)
    {
        no* temp = new no(valor);
        temp->next = head;
        head = temp;
        tamanho++;
        return;
    }

    if (pos == tamanho)
    {
        no* temp = new no(valor);
        tail->next = temp;
        tail = temp;
        tamanho++;
        return;
    }


    int i = 0;
    no* atual = this->head;
    while (i < pos)
    {
        atual = atual->next;
        i++;
    }
    no* temp = new no(valor);
    temp->next = atual->next;
    atual->next = temp;
    this->tamanho++;
    
}

void le::print()
{   
    no* atual = head;
    cout << "[" << atual->valor << ", ";
    for(int i = 1; i < tamanho - 1; i++)
    {
        atual = atual->next;
        cout << atual->valor << ", ";
    }
    cout << atual->valor << "]";
    
}

int main()
{   
    le teste;
    teste.inserir(0, 8);
    teste.inserir(1, 9);
    teste.inserir(2, 20);
    teste.print();
    return 0;
}
