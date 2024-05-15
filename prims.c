#include<stdio.h>
#include<stdlib.h>
#define n 50
#define INF 9999

int main(){
    int a[n][n], path[n], distance[n], visited[n], current, v, nv, e, i, j, v1, v2, wt, min, c;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for(i = 1; i <= v; i++){
        for(j = 1; j <= v; j++){
            a[i][j] = 0;
        }
    }
    printf("Enter the two vertices and weight for each edge\n");
    for(i = 0; i < e; i++){
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &v1, &v2, &wt);
        a[v1][v2] = wt;
        a[v2][v1] = wt;
    }
    for(i = 1; i <= v; i++){
        path[i] = 0;
        distance[i] = INF;
        visited[i] = 0;
    }
    current = 1;
    visited[current] = 1;
    nv = 1;
    while(nv != v){
        for(i = 1; i <= v; i++){
            if(a[current][i] != 0){
                if(visited[i] != 1){
                    if(distance[i] > a[current][i]){
                        distance[i] = a[current][i];
                        path[i] = current;
                    }
                }
            }
        }
        min = INF;
        for(i = 1; i <= v; i++){
            if(visited[i] != 1){
                if(min > distance[i]){
                    min = distance[i];
                    current = i;
                }
            }
        }
        visited[current] = 1;
        nv++;
    }
    c = 0;
    for(i = 2; i <= v; i++){
        c += distance[i];
        printf("Vertex %d is connected to vertex %d with cost %d\n", i, path[i], distance[i]);
    }
    printf("\nMinimum cost is %d", c);
    return 0;
}