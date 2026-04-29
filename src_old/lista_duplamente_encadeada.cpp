class no
{
private:
    int value;
public:
    no* bellow;
    no* next;

    no(int value);
    ~no();
};

no::no(int value)
{
    this->value = value;
    this->next = nullptr;
}

no::~no()
{
}



class lde
{
private:
    int tamanho;
    int capacidade;
    no* head;
    no* tail;
public:
    lde();
    ~lde();
};

lde::lde()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->tamanho = 0;
}

lde::~lde()
{
}

