#include <stdio.h>
#include "sort.h"
int main()
{
    int a[] = {21, 3, 4, 1, 4, 5, 8, 9, 12, 10, 55, 22, 41, 58, 70, 152, 100, 200, 111, 110, 112, 115, 114, 101, 77, 74};
    int len = (sizeof(a) / sizeof(a[0]));
    quick_sort(a, 0, len - 1);
    int k;
    for (k = 0; k < len-1; k++)
        printf("%d,",a[k]);
    printf("%d,",a[k]);
    return 0;
}