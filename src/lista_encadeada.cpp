#include <iostream>

using namespace std;

class no
{
public:
    int valor;
    no* next;
    no(int valor);
};

no::no(int valor)
{
    this->valor = valor;
    this->next = nullptr;
}

///////////////////////////////////////////////////////////////////////////////

class le
{
private:
no* tail;
int tamanho;
int capacidade;
public:
    no* head;
    le();
    ~le();
    void inserir(int pos, int valor);
    void append(int value);
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

    if (pos <= 0)
    {
        no* temp = new no(valor);
        temp->next = head;
        head = temp;
        tamanho++;
        return;
    }

    if (pos >= tamanho)
    {
        no* temp = new no(valor);
        tail->next = temp;
        tail = temp;
        tamanho++;
        return;
    }


    int i = 0;
    no* atual = this->head;
    while (i < pos - 1)
    {
        atual = atual->next;
        i++;
    }
    no* temp = new no(valor);
    temp->next = atual->next;
    atual->next = temp;
    this->tamanho++;
    
}

void le::append(int value)
{   
    no* end = new no(value);
    if (tamanho == 0)
    {   
        head = end;
        tail = end;
    } else
    {
        tail->next = end;
        tail = end;
    }
    tamanho++;
}

void le::print()
{   
    if (head == nullptr)
    {
        cout << "[]" << endl;
        return;
    }
    

    no* atual = head;

    cout << "[";
    while (atual->next != nullptr)
    {
        cout << atual->valor << ", ";
        atual = atual->next;
    }
    cout << atual->valor << "]" << endl;
}

// Funções adicionais

int list_size(no* head)
{
    int size = 0;
    if(head != nullptr)
    {
        size += 1 + list_size(head->next);
    }
    return size;
}

no* remove_all(no* &head, int x){

    // Caso base 
    if (head == nullptr)
    {
        return nullptr;
    }

    // divisão e conquista
    no* new_head = remove_all(head->next, x); // problema k=n-1

    if (head->valor == x) // problema k=1
    {   
        delete head;
        head = new_head;
        return new_head;
    } else
    {
        head->next = new_head;
        return head;
    }
}

/*int main()
{
    le teste;

    int tam = list_size(teste.head);
    cout <<"tamanho: " << tam << endl;

    teste.append(1);
    teste.append(2);
    teste.append(3);
    
    cout << "Lista apos appends: ";
    teste.print();

    tam = list_size(teste.head);
    cout <<"tamanho: " << tam << endl;

    teste.inserir(1, 99); // Inserir 99 na posição do índice 1
    
    cout <<"Lista apos inserir 99 na pos 1: ";
    teste.print();

    tam = list_size(teste.head);
    cout <<"tamanho: " << tam << endl;
    
    return 0;
}*/

int main()
{
    le teste;
    teste.append(1);
    teste.append(92);
    teste.append(92);
    teste.append(23);
    teste.append(1);
    teste.append(2);
    teste.print();

    remove_all(teste.head, 92);
    teste.print();

    remove_all(teste.head, 1);
    teste.print();

}