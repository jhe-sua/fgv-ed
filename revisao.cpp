#include <iostream>
using namespace std;
// Funcoes

// Neste caso fazemos uma passagem por valor
// quer dizer que criamos outra variavel na memoria
int func_val(int i)
{
    i = i - 1;
    return i;
}

int func_ref(int &i)
{
    i = i - 1;
    return i;
}

// Arrays

void exibir_array(int arr[4])
{
    cout << "[";
    for(int i = 0; i < 3; i++)
    {
        cout << arr[i];
        cout << ",";
    }
    cout << arr[3] << "]";
}

int main()
{   
    int i = 1;
    func_val(i);
    cout << i;

    func_ref(i);
    cout << i;

    int arr[4] = {1, 2, 3, 4};
    exibir_array(arr);

    return 0;
}