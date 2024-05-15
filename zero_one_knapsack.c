#include<stdio.h>
#include<stdlib.h>
#define n 10

int max(int a, int b){
    return a>b? a : b;
}

int main(){
    int p[n], w[n], v[n][n], o, c, i, j;
    printf("Enter number of objects: ");
    scanf("%d", &o);
    printf("Enter capacity of sack: ");
    scanf("%d", &c);
    printf("Enter profit ad weight for each object\n");
    for(i = 1; i <= o; i++){
        printf("Object %d: ", i);
        scanf("%d %d", &p[i], &w[i]);
    }
    for(i = 0; i <= o; i++){
        v[i][0] = 0;
        v[0][i] = 0;
    }
    for(i = 1; i <= o; i++){
        for(j = 1; j <= c; j++){
            if(i == 1){
                if(j < w[i]){
                    v[i][j] = 0;
                }
                else{
                    v[i][j] = p[i];
                }
            }
            else if(j < w[i]){
                v[i][j] = v[i - 1][j];
            }
            else{
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
        }
    }
    printf("\nTotal profit: %d\n", v[o][c]);
    for(i = 0; i <= o; i++){
        for(j = 0; j <= c; j++){
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    printf("\nObjects included are: ");
    i = o;
    j = c;
    while(i > 0 && j > 0){
        if(v[i][j] != v[i - 1][j]){
            printf("obj%d ", i);
            j = j - w[i];
        }
        i--;
    }
    return 0;
}