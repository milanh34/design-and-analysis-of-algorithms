#include<stdio.h>
#include<stdlib.h>
#define n 10

int place(int r, int c, int column[]){
    int i;
    for(i = 1; i < r; i++){
        if(column[i] == c || abs(column[i] - c) == abs(i - r)){
            return 0;
        }
    }
    return 1;
}

void nqueens(int r, int m, int column[]){
    int i, c;
    for(c = 1; c <= m; c++){
        if(place(r, c, column) == 1){
            column[r] = c;
            if(r == m){
                for(i = 1; i <= m; i++){
                    printf("(%d, %d) ", i, column[i]);
                }
                printf("\n");
            }
            else{
                nqueens(r + 1, m, column);
            }
        }
    }
}

int main(){
    int m, i, column[n];
    printf("Enter the number of queens: ");
    scanf("%d", &m);
    for(i = 0; i < m; i++){
        column[i] = 0;
    }
    nqueens(1, m, column);
    return 0;
}