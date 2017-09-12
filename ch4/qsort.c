#include <stdio.h>

void swap(int v[], int i, int j)
{
    int c = v[i];
    v[i] = v[j];
    v[j] = c;
}


void sort(int v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left + 1; i <= right; ++i)
        if (v[i] < v[left])
            swap(v, ++last, i);

    swap(v, last, left);
    sort(v, left, last - 1);
    sort(v, last + 1, right);
}


void print_arr(int a[], int sz)
{
    int i;
    for (i = 0; i < sz; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {3, 34, 2, 6, -1};
    sort(a, 0, 4);
    print_arr(a, 5);
}
