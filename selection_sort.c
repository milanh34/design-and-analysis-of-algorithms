#include<stdio.h>
#include<stdlib.h>
#define n 50

int smallest(int a[], int i, int m){
    int j, k = i, small = a[k];
    for(j = k + 1; j < m; j++){
        if(small > a[j]){
            k = j;
            small = a[j];
        }
    }
    return k;
}

void selection(int a[], int m){
    int i, j, temp;
    for(i = 0; i < m; i++){
        j = smallest(a, i, m);
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
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
    selection(arr,m);
    printf("Sorted array is: ");
    for(i = 0; i < m; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}