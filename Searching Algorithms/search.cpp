#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int linear_search(int a[], int len, int s)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (s == a[i]) return i;
    }
    return -1;
}
int binary_search(int a[], int min, int max, int s)
{
    if (min > max)
        return -1;
    else
    {
        int mid = (min + max) / 2;
        if(a[mid] == s) return mid;
        else if(s < a[mid]) binary_search(a, 0, mid-1, s);
        else binary_search(a, mid+1, max, s);
    }
}
int main()
{
    auto start = chrono::steady_clock::now();
    int a[] = {1, 3, 4, 4, 5, 8, 9, 10, 12, 21, 22, 41, 55, 58, 70, 74, 77, 100, 101, 110, 111, 112, 114, 115, 152, 200};
    int len = (sizeof(a) / sizeof(a[0]));
    int s = 22;
    int f = binary_search(a, 0, len-1, 0);
    f != -1 ? cout << "Element found at index " << f : cout << "Element not found";
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "\n" << chrono::duration<double, milli>(diff).count() << "ms" << endl;
    return 0;
}