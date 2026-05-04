#include <iostream>

using namespace std;

int max(int* arr, int n)
{
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void merge(int* arr, int p, int q, int r)
{   
    // inicialização da parte esquerda e da parte direita
    int n_1 = q - p + 1;
    int n_2 = r - q;

    // com mais um para os sentinelas
    int* L = new int[n_1 + 1];
    int* R = new int[n_2 + 1];

    for (int i = 0; i < n_1; i++)
    {
        L[i] = arr[p + i];
    }
    for (int i = 0; i < n_2; i++)
    {
        R[i] = arr[q + i + 1];
    }

    // sentinelas
    int sentinela = max(L, n_1) + max(R, n_2) + 1;

    L[n_1] = sentinela;
    R[n_2] = sentinela;

    int l_0 = 0;
    int r_0 = 0;

    for (int i = p; i <= r; i++)
    {
        if (L[l_0] <= R[r_0])
        {
            arr[i] = L[l_0];
            l_0++;
        } else
        {
            arr[i] = R[r_0];
            r_0++;
        }
        
    }
}

void merge_sort(int* arr, int p, int r)
{   
    int q;

    // condição necessaria para parar a recursividade
    // para quando p = r ou seja temos apenas 1 elemento
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
    int n = 5;

    int test[] = {9, 17 , 53, 44, 65};
    merge_sort(test, 0, n-1);

    for (int i = 0; i < n; i ++)
    {
        cout << test[i] << endl;
    }


    return 0;
}