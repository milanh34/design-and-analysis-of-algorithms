#include<stdio.h>
#include<stdlib.h>
#define n 50
#define INF 9999

int min(int a, int b){
    return a>b? b : a;
}

void show(int c[][n], int v){
    int i, j;
    for(i = 1; i <= v; i++){
        for(j = 1; j <= v; j++){
            if(c[i][j] == INF){
                printf("- ");
            }
            else{
                printf("%d ", c[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    int a[n][n], c[n][n], i, j, k, v, e, v1, v2, wt;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for(i = 1; i <= v; i++){
        for(j = 1; j <= v; j++){
            if(i == j){
                a[i][j] = 0;
            }
            else{
                a[i][j] = INF;
            }
        }
    }
    printf("Enter the two vertices and weight for each edge\n");
    for(i = 0; i < e; i++){
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &v1, &v2, &wt);
        a[v1][v2] = wt;
    }
    for(i = 1; i <= v; i++){
        for(j = 1; j <= v; j++){
            c[i][j] = a[i][j];
        }
    }
    for(k = 1; k <= v; k++){
        for(i = 1; i <= v; i++){
            for(j = 1; j <= v; j++){
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
        show(c, v);
        printf("\n");
    }
    return 0;
}