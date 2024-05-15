#include<stdio.h>
#include<stdlib.h>
#define n 10

struct object{
    float p, w, f;
};

int main(){
    struct object o[n], t;
    int m, i, j;
    float c, profit = 0;
    printf("Enter number of objects: ");
    scanf("%d", &m);
    printf("Enter capacity of sack: ");
    scanf("%f", &c);
    printf("Enter profit and weight for each object\n");
    for(i = 0; i < m; i++){
        printf("Object %d: ", i + 1);
        scanf("%f %f", &o[i].p, &o[i].w);
        o[i].f = 0;
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            if(o[j].p / o[j].w < o[i].p / o[i].w){
                t = o[j];
                o[j] = o[i];
                o[i] = t;
            }
        }
    }
    for(i = 0; i < m; i++){
        if(o[i].w <= c){
            c -= o[i].w;
            profit += o[i].p;
            o[i].f = 0;
        }
        else{
            break;
        }
    }
    if(c != 0){
        o[i].f = c / o[i].w;
        profit += o[i].p * o[i].f;
        c = 0;
    }
    printf("\nFraction remaining: ");
    for(i = 0; i < m; i++){
        printf("%f ", o[i].f);
    }
    printf("\nTotal profit: %f", profit);
    return 0;
}