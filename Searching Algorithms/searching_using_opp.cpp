#include <iostream>
using namespace std;
class searching
{
    private:
        int *a;
        int len;
    public:
        searching(int array[],int array_len)
        {
            a = array;
            len = array_len;
        }
        int linear_search(int s)
        {
            int i;
            for (i = 0; i < len; i++)
            {
                if (s == a[i]) return i;
            }
            return -1;
        }
        int binary_search(int s)
        {
            int min = 0, max = len-1, mid;
            while(min<=max)
            {
                mid = (min + max) / 2;  
                if(a[mid] == s) return mid;
                else if(s < a[mid]) max = mid-1;
                else min = mid+1;
            }
            return -1;
        }
};

int main()
{
    int a[] = {1, 3, 4, 4, 5, 8, 9, 10, 12, 21, 22, 41, 55, 58, 70, 74, 77, 100, 101, 110, 111, 112, 114, 115, 152, 200};
    int len = 26;
    int s;
    cout << "Enter a element to search: ";
    cin >> s;
    searching search_a(a,len);
    int f = -1;
    f = search_a.binary_search(s);
    if(f==-1)
    {
        cout << "Element not found";
    } else {
        cout << "Element found at index " << f;
    }
    return 0;
}