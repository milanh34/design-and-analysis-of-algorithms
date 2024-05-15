#include<stdio.h>
#include<stdlib.h>
#define n 50
#define INF 9999

int main(){
    int a[n][n], path[n], distance[n], visited[n], current, v, nv, e, v1, v2, wt, min, i, j, t, source, destination;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    for(i = 1; i <= v; i++){
        for(j = 1; j <= v; j++){
            a[i][j] = 0;
        }
    }
    printf("Enter the two vertices and weight of each edge\n");
    for(i = 0; i < e; i++){
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &v1, &v2, &wt);
        a[v1][v2] = wt;
    }
    for(i = 1; i <= v; i++){
        path[i] = 0;
        distance[i] = INF;
        visited[i] = 0;
    }
    printf("Enter the source: ");
    scanf("%d", &source);
    current = source;
    visited[current] = 1;
    nv = 1;
    t = 0;
    while(nv != v){
        for(i = 1; i <= v; i++){
            if(a[current][i] != 0){
                if(visited[i] != 1){
                    if(distance[i] > a[current][i] + t){
                        distance[i] = a[current][i] + t;
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
        t = distance[current];
        nv++;
    }
    printf("Enter destination: ");
    scanf("%d", &destination);
    printf("Shortest distance from source to destination is: %d\n", distance[destination]);
    printf("Shortest path from source to destination is:\n");
    j = destination;
    do{
        i = path[j];
        printf("\nVertex %d is connected to vertex %d", j, i);
        j = i;
    }while(j != source);
    return 0;
}