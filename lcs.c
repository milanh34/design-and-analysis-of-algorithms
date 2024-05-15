#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define l 50

int max(int a, int b){
    return a>b? a : b;
}

int main(){
    char x[l], y[l];
    int n, m, i, j, c[l][l], index;
    printf("Enter string 1: ");
    scanf("%s", x);
    printf("Enter string 2: ");
    scanf("%s", y);
    n = strlen(x);
    m = strlen(y);
    for(i = 0; i <= n; i++){
        for(j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                c[i][j] = 0;
            }
            else if(x[i - 1] == y[j - 1]){
                c[i][j] = 1 + c[i - 1][j - 1];
            }
            else{
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    for(i = 0; i <= n; i++){
        for(j = 0; j <= m; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    i = n;
    j = m;
    index = c[n][m];
    char lcs[index + 1];
    lcs[index] = '\0';
    while(i > 0 && j > 0){
        if(x[i - 1] == y[j - 1]){
            lcs[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        }
        else if(c[i - 1][j] > c[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }
    printf("\nLonngest Common Subsequence is: %s", lcs);
    return 0;
}