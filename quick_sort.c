#include<stdio.h>
#include<stdlib.h>
#define n 50

int quick(int a[], int beg, int end){
    int i = beg, j = end + 1, v = a[beg], temp;
    do{
        do{
            i++;
        }while(a[i] < v && i <= j);
        do{
            j--;
        }while(v < a[j]);
        if(i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }while(i < j);
    a[beg] = a[j];
    a[j] = v;
    return j;
}

void divide(int a[], int i, int j){
    int k;
    if(i < j){
        k = quick(a, i, j);
        divide(a, i, k - 1);
        divide(a, k + 1, j);
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