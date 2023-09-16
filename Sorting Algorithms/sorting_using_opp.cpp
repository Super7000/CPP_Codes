#include <iostream>
#include <chrono>
using namespace std;
class sorting
{
    private: 
        int *a;
        int len;
    public:
        sorting(int array[], int array_len)
        {
            a = array;
            len = array_len;
        }
        void swap(int *a, int *b)
        {
            int temp = *b;
            *b = *a;
            *a = temp;
        }
        void bubble_sort()
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
        void selection_sort()
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
        void insertion_sort()
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

        int partition(int l, int r)
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
        void quick_sort_func(int l, int r)
        {
            if (l < r)
            {
                int pi = partition(l, r);
                quick_sort_func(l, pi - 1);
                quick_sort_func(pi + 1, r);
            }
        }
        void quick_sort()
        {
            int l = 0, r = len -1;
            quick_sort_func(l,r);
        }
};

int main()
{
    int a[] = {21, 3, 4, 1, 4, 5, 8, 9, 12, 10, 55, 22, 41, 58, 70, 152, 100, 200, 111, 110, 112, 115, 114, 101, 77, 74};
    int len = 26;
    sorting sort(a,len);
    sort.quick_sort();
    int k;
    for (k = 0; k < len-1; k++)
        cout << a[k] << ",";
    cout << a[k];
    return 0;
}