#include <stdio.h>
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

void print_arr(int *a, int n) {
    int i = 0;
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}


void merge(int* a, int nums1Size, int m, int* b, int nums2Size, int n) {
    int k = m+n-1;
    int i = m - 1;
    int j = n - 1;


    while ( i >= 0 && i < k && j >= 0) {
        if (b[j] > a[i]) {
            a[k] = b[j];
            j--;
        } else {
            a[k] = a[i];
            i--;
        }
        k--;
    }

    if (i < 0) {
        // there are elements in second array that need to be copied
        while ( j >= 0) {
            a[k] = b[j];
            j--;
            k--;
        }
    }
}

int main() {
    int a[] = {1,2,3,0,0,0};
    int b[] = {2,3,5};

    merge(a, 6, 3, b, 3, 3);
    return 0;
}
