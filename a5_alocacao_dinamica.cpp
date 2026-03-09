#include <iostream>
using namespace std;

// Utilizamos a passagem por referencia, pois se fosse por valor criariamos
// novas variaveis x, y dentro do escopo da funcao trocar e assim que finalice
// as novas variaveis são apagadas e nunca modificam os x e y reais

struct Student
{
    int Id;
    float grade;
};


void trocar(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int* multiplicar(int* arr, int size, int fator)
{
    int* resultado = new int[size];

    for(int i = 0; i < size; i++)
    {
        resultado[i] = fator*arr[i];
    }

    return resultado;
}

int main()
{
    // Trocar
    int a = 4;
    int b = 10;

    trocar(&a, &b);

    cout << a << endl;
    cout << b << endl;

    // Multiplicar
    int arr[] = {1,2,3,4,5};
    int* resultado;

    resultado = multiplicar(arr, 5, 2);
    for(int i = 0; i < 5; i++)
    {
        cout << resultado[i] << ",";
    }
    delete[] resultado;

    // Struct
    int x = 4;
    Student s = {100, 7.5};
    s.Id = 100;
    s.grade = 7.5;

    cout << s.Id << endl;
}