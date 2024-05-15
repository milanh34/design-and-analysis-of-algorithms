#include<stdio.h>
#include<stdlib.h>
#define n 50

void merge(int a[], int beg, int mid, int end){
    int c[n];
    int i = beg, j = mid + 1, k = 0;
    while(i <= mid && j <= end){
        if(a[i] < a[j]){
            c[k] = a[i];
            i++;
            k++;
        }
        else{
            c[k] = a[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        c[k] = a[i];
        i++;
        k++;
    }
    while(j <= end){
        c[k] = a[j];
        j++;
        k++;
    }
    for(i = beg, j = 0; i <= end; i++, j++){
        a[i] = c[j];
    }
}

void divide(int a[], int i, int j){
    int k;
    if(i < j){
        k = (i + j) / 2;
        divide(a, i, k);
        divide(a, k + 1, j);
        merge(a, i, k, j);
    }
}

int main(){
    int arr[n], m, i;
    printf("Enter number of elements: ");
    scanf("%d", &m);
    printf("Enter the elements: ");
    for(i = 0; i < m; i++){
        scanf("%d", &arr[i]);
    }
    divide(arr, 0, m-1);
    printf("Sorted array is: ");
    for(i = 0; i < m; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}