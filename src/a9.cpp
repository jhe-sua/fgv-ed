#include <iostream>

using namespace std;

class PilhaTad {
    public:
        virtual bool inserir(int value) = 0;
        virtual bool remover(int &value) = 0;
        virtual bool topo(int &value) = 0;
};

class PilhaArrays: public PilhaTad
{
    private:
        int* dados;
        int topoIdx;
        int capacidade;

    public:
        PilhaArrays(int capacidade)
        {
            this->capacidade = capacidade;
            this->topoIdx = -1;
            this->dados = new int[capacidade];
        }

        ~PilhaArrays()
        {
            delete[] dados;
        }

        bool inserir(int value) override
        {
            if (topoIdx == capacidade - 1)
            {
                return false;
            }

            topoIdx++;
            dados[topoIdx] = value;
            return true;   
        }

        bool remover(int &value) override
        {
            if (topoIdx < 0)
            {
                return false;
            }

            value = dados[topoIdx];
            topoIdx--;
            return true;   
        }

        bool topo(int &value) override
        {
            if (topoIdx < 0)
            {
                return false;
            }

            value = dados[topoIdx];
            return true;
        }
};

int main()
{
    PilhaArrays p(3);
    p.inserir(10);
    p.inserir(20);
    p.inserir(30);
    return 0;

    int ValoRetorno;
    cout << p.remover(ValoRetorno) << endl;
    cout << ValoRetorno << endl;
    cout << p.remover(ValoRetorno) << endl;
    cout << ValoRetorno << endl;
}
