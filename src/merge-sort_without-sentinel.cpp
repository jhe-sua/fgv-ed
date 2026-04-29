#include <iostream>

using namespace std;

void merge(int* arr, int p, int q, int r)
{   
    // Definições necessarias
    int idL = 0;         // indice atual de L
    int idR = 0;         // indice atual de R
    int idxA = p;         // indice atual de arr
    int* arr_r = nullptr; // elementos que sobraram apos L ou R esgotar

    int n_1 = q - p + 1;  // numero de elementos em L
    int n_2 = r - q;      // numero de elementos em R
    int n_3;              // numero de elementos em arr_r

    int* L = new int[n_1];
    int* R = new int[n_2];

    for (int i = 0; i < n_1; i++)
    {
        L[i] = arr[p+i];
    }

    for (int i = 0; i < n_2; i++)
    {
        R[i] = arr[q+i+1];
    }

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

    if (idL == n_1)
    {
        n_3 = n_2 - idR;
        arr_r = R + idR;
    } else if (idR = n_2)
    {
        n_3 = n_1 - idL;
        arr_r = L + idL;
    }

    for (int i = 0; i < n_3; i++)
    {
        arr[idxA + i] = arr_r[i];
    }
    
    delete[] L;
    delete[] R;
}

void merge_sort(int* arr, int p, int r)
{   
    int q;
    if (p < r)
    {
        q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
    
}

int main(void)
{   
    int n = 1;

    int test[] = {9};
    merge_sort(test, 0, n-1);

    for (int i = 0; i < n; i ++)
    {
        cout << test[i] << endl;
    }


    return 0;
}