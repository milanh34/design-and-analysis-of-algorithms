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

int binary_search(int a[], int m, int x){
    int beg, mid, end;
    beg = 0;
    end = m - 1;
    while(beg <= end){
        mid = (beg + end) / 2;
        if(a[mid] == x){
            return 1;
        }
        else if(x > a[mid]){
            beg = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return 0;
}

int main(){
    int arr[n], m, i, x, y;
    printf("Enter number of elements: ");
    scanf("%d", &m);
    printf("Enter the elements: ");
    for(i = 0; i < m; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x);
    divide(arr, 0, m-1);
    y = binary_search(arr, m, x);
    if(y == 1){
        printf("\nElement found!");
    }
    else{
        printf("\nElement not found!");
    }
    return 0;
}