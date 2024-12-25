#include <stdio.h>

void print_arr(int *a, int n) {
    int i ;
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}



int max(int a, int b) {
    return (a>b ? a : b);
}
int maxProfit(int* a, int n) {
    if (n == 0 || n==1) {
        return 0;
    }

    int b = 0, s = 1;
    int profit, rv = 0;
    for (s; s<n;s++) {
        profit = a[s] -a[b];
        if (profit < 0) {
            while((a[s] - a[b] < 0) && s > b) {
                b++;
            }
        }
        rv = max(rv, profit);
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
