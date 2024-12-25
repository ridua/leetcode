#include <stdio.h>

void print_arr(int *a, int n) {
    int i ;
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int maxProfit(int* a, int n) {
    if (n ==0 || n == 1) {
        return 0;
    }
    int b = 0, s = 1, rv = 0;
    int max_txn = 0, profit = 0;
    for (s; s<n; s++) {
        profit = a[s] - a[b];
        if (profit < max_txn) {
            rv = rv + max_txn;
            b = s;
            max_txn = 0;
        } else {
            max_txn = profit;
        }
    }

    if (max_txn > 0) {
        rv += max_txn;
    }

    return rv;
}

int main()
{
    // int arr[] = {7,1,5,3,6,4};
    // int arr[] = {7,6,4};
    int arr[] = {2,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);        
    int rv = maxProfit(arr, n);
    printf("\n Max Profit: %d\n", rv);
    
    return 0;
}
