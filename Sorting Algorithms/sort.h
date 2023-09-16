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
            ++i;
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

void marge_sort()
{
    
}