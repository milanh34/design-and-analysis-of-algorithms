#include<stdio.h>
#include<stdlib.h>
#define n 50

void insertion(int a[], int m){
    int i, j, temp;
    for(i = 1; i < m; i++){
        temp = a[i];
        for(j = i - 1; j >= 0 && a[j] > temp; j--){
            a[j+1] = a[j];
        }
        a[j+1] = temp;
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
    insertion(arr,m);
    printf("Sorted array is: ");
    for(i = 0; i < m; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}