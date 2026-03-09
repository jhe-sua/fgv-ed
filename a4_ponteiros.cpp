#include <iostream>

using namespace std;

int main()
{   
    int arr[5] = {1,2,3,4,5};

    // descobrimos que arr guarda apenas o endereço da memoria do primeiro 
    // elemento, ouseja um array é um ponteiro, ele não guarda o valor
    // mas guarda o endereço

    cout << "Valor: " << arr[0] << endl;
    cout << "Endereço: " << &arr[0] << endl;
    cout << "Valor: " << arr[1] << endl;
    cout << "Endereço: " << &arr[1] << endl;

    cout << "Endereço 1 elemento: " << arr << endl;
    cout << "valor: " << *arr << endl;

    cout << "Endereço 2 elemento: " << arr + 1 << endl;
    cout << "valor: " << *(arr + 1) << endl;

    int k[] = {1,2,3,4,5};
    int* point;

    point = &k[0];

    cout << "Valor pepe: " << point << endl;
    cout << "Valor pepe: " << point[3] << endl;

    point = point + 1;

    cout << "Valor pepe: " << point << endl;
    cout << "Valor pepe: " << point[-1] << endl;



    cout << "\n\n\n\n\n\n\n";
    // Ponteiros
    int a;
    int* p = &a;

    a = 2;
    *p = a;

    // endereco de a
    cout << "Endereco de a: " << p << endl;

    // valor de a
    cout << "valor de a: " << *p << endl;

    // endereco de p
    cout << "Endereco de p: " << &p << endl;

    // evitar acentos
    cout << "CIÊNCIA" << endl;
    return 0;
}