#include <stdio.h>


int remove_duplicates(int *a, int n) {
    int i = 0;
    int k = 0;

    for (i = 0; i < n; i++) {
        if (a[k] != a[i]) {
            k++;
            a[k] = a[i];
        }
    }
    return k+1;
}

int main() {
  // int arr[] = {1,1,1,2,2,3,3,5,5,6};
  // int arr[] = {1,2,3,4,5,6};
  int arr[] = {1,2,3,4,5,6,6};

  int remaining_arr_size = remove_duplicates(arr, sizeof(arr)/sizeof(arr[0]));

  printf("\n remaining size %d", remaining_arr_size);
  return 0;
}
