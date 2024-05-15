#include<stdio.h>
#include<stdlib.h>
#define n 50

void minmax(int a[], int lb, int ub, int *max, int *min){
    int k, max1, min1;
    if(lb == ub){
        *max = *min = a[lb];
    }
    else if(lb + 1 == ub){
        if(a[lb] > a[ub]){
            *max = a[lb];
            *min = a[ub];
        }
        else{
            *max = a[ub];
            *min = a[lb];
        }
    }
    else{
        k = (lb + ub) / 2;
        minmax(a, lb, k, max, min);
        minmax(a, k + 1, ub, &max1, &min1);
        if(max1 > *max){
            *max = max1;
        }
        if(min1 < *min){
            *min = min1;
        }
    }
}

int main(){
    int arr[n], m, i, min, max;
    printf("Enter number of elements: ");
    scanf("%d", &m);
    printf("Enter the elements: ");
    for(i = 0; i < m; i++){
        scanf("%d", &arr[i]);
    }
    minmax(arr, 0, m - 1, &max, &min);
    printf("\nLargest element is %d and smallest element is %d", max, min);
    return 0;
}