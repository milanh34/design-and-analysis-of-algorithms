#include<stdio.h>
#include<stdlib.h>
#define n 50

struct edge{
    int u, v, w;
};

int check_cycle(int u, int v, int w, int path[]){
    while(path[u] > 0){
        u = path[u];
    }
    while(path[v] > 0){
        v = path[v];
    }
    if(u != v){
        path[u] = v;
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    struct edge e[n], temp;
    int path[n], v, edge, i, j, min;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &edge);
    printf("Enter the two vertices and weight for each edge\n");
    for(i = 0; i < edge; i++){
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    for(i = 0; i < edge; i++){
        for(j = i + 1; j < edge; j++){
            if(e[j].w < e[i].w){
                temp = e[j];
                e[j] = e[i];
                e[i] = temp;
            }
        }
    }
    for(i = 1; i <= v; i++){
        path[i] = 0;
    }
    i = 0;
    j = 0;
    min = 0;
    while(i != v - 1 && j != edge){
        if(check_cycle(e[j].u, e[j].v, e[j].w, path) == 1){
            min = min + e[j].w;
            i++;
            printf("\nVertex %d is connected to vertex %d with cost %d", e[j].u, e[j].v, e[j].w);
        }
        j++;
    }
    if(i == v - 1){
        printf("\nMinimum cost is %d", min);
    }
    else{
        printf("\nMinimum Spanning Tree cannot be formed!");
    }
    return 0;
}