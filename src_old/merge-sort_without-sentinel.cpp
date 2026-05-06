#include <iostream>

using namespace std;

void merge(int* arr, int p, int q, int r)
{   
    // Definições necessarias
    int idL = 0;         // indice atual de L
    int idR = 0;         // indice atual de R
    int idxA = p;         // indice atual do segemento do array a ser ordenado (arr)
    int* arr_r = nullptr; // elementos que sobraram apos L ou R esgotar

    int n_1 = q - p + 1;  // numero de elementos em L
    int n_2 = r - q;      // numero de elementos em R
    int n_3 = 0;              // numero de elementos em arr_r

    int* L = new int[n_1];
    int* R = new int[n_2];


    // criação do left e do right
    for (int i = 0; i < n_1; i++)
    {
        L[i] = arr[p+i];
    }

    for (int i = 0; i < n_2; i++)
    {
        R[i] = arr[q+i+1];
    }


    // algortimo merge ate L ou R acabar
    while (idL < n_1 && idR < n_2)
    {
        if (L[idL] <= R[idR])
        {
            arr[idxA] = L[idL];
            idL++;
        } else
        {
            arr[idxA] = R[idR];
            idR++;
        }
        idxA++;
    }

    // verificamos se L ou R acabou continuamos no outro
    if (idL == n_1) // L acabou continuamos no R
    {
        n_3 = n_2 - idR; // numero de elementos que faltam
        arr_r = R + idR; // ponteiro do primeiro elemento da lista que acabou
    } else if (idR = n_2) // R acabou continuamos no L
    {
        n_3 = n_1 - idL; // numero de elementos que faltam
        arr_r = L + idL; // ponteiro do primeiro elemento da lista que acabou
    }

    // sempre vai acabar L ou R primeiro sobrando 1 elemento no outro
    for (int i = 0; i < n_3; i++)
    {
        arr[idxA + i] = arr_r[i];
    }
    
    delete[] L;
    delete[] R;
}

/// @brief Algoritmo merge-sort, merge sem sentinela
/// @param arr Array a ser ordenado do index p ate o index r
/// @param p indice do elemento inicial
/// @param r indice do elemento final
void merge_sort(int* arr, int p, int r)
{   
    int q; // elemento entre p e r para dividir em dois sub-arranjos
    if (p < r)
    {
        q = (p+r)/2; // divisão inteira pegando o piso
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
    
}

int main(void)
{   
    int n = 8; //numero de elementos no array

    int test[] = {19, 19, 19, 19, 24, 22, 78, 21};
    merge_sort(test, 0, n-1);

    for (int i = 0; i < n; i ++)
    {
        cout << test[i] << endl;
    }


    return 0;
}