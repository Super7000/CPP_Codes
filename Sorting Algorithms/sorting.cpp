#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void bubble_sort(int a[], int len)
{
    len++;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}
void selection_sort(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[min] > a[j])
                min = j;
        }
        if (min != i)
            swap(&a[min], &a[i]);
    }
}
void insertion_sort(int a[], int len)
{
    len++;
    for (int i = 1; i < len; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (key < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

// -------------QuickSort------------------

int partition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            if(j != i) swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return (i + 1);
}
void quick_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(a, l, r);
        quick_sort(a, l, pi - 1);
        quick_sort(a, pi + 1, r);
    }
}

// -------------MargeSort------------------

void marge(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int l[n1], m[n2];
    for (int i = 0; i < n1; i++)
        l[i] = a[p+i];
    for(int j = 0; j < n2; j++)
        m[j] = a[q+1+j];
    int i = 0, j = 0, k = p;
    while(i<n1 && j<n2)
    {
        if(l[i] <= m[j])
        {
            a[k] = l[i];
            i++;
        } else {
            a[k] = m[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        a[k] = l[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        a[k] = m[j];
        j++;
        k++;
    }
}

void marge_sort(int a[], int l, int r)
{
   if(l<r)
   {
        int m = l + (r-l) / 2;
        marge_sort(a, l, m);
        marge_sort(a, m + 1, r);
        marge(a,l,m,r);
   }
}

int main()
{
    auto start = chrono::steady_clock::now();
    int a[] = {21, 3, 4, 1, 4, 5, 8, 9, 12, 10, 55, 22, 41, 58, 70, 152, 100, 200, 111, 110, 112, 115, 114, 101, 77, 74};
    int len = (sizeof(a) / sizeof(a[0]));
    insertion_sort(a, len - 1);
    int k;
    for (k = 0; k < len-1; k++)
        cout << a[k] << ",";
    cout << a[k];
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "\n" << chrono::duration<double, milli>(diff).count() << "ms" << endl;
    return 0;
}