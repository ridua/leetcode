#include <stdio.h>

void print_arr(int *a, int n) {
    int i ;
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void reverse (int *a, int s, int e) {
    while(s < e) {
        swap(&a[s], &a[e]);
        s++;
        e--;
    }
}

void rotate(int *a, int n, int k) {
    if (k >= n) {
        k = k %n ;
    }    
    reverse(a, 0, n-1);
    print_arr(a, n);

    reverse(a, 0, k - 1);
    print_arr(a, n);

    reverse(a, k, n-1);
    print_arr(a, n);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);        
    int k = 3;
    rotate(arr, n, k);
    print_arr(arr, n);
    return 0;
}
