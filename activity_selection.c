#include<stdio.h>
#include<stdlib.h>
#define n 10

int main(){
    int job[n], start[n], end[n], m, i, j, done = 0, temp, curr_time;
    printf("Enter the number of jobs: ");
    scanf("%d", &m);
    printf("Enter start time and end time for each job\n");
    for(i = 0; i < m; i++){
        job[i] = i + 1;
        printf("Job %d: ", job[i]);
        scanf("%d %d", &start[i], &end[i]);
    }
    for(i = 0; i < m; i++){
        for(j = i + 1; j < m; j++){
            if(end[j] < end[i]){
                temp = job[i];
                job[i] = job[j];
                job[j] = temp;
                
                temp = start[j];
                start[j] = start[i];
                start[i] = temp;
                
                temp = end[j];
                end[j] = end[i];
                end[i] = temp;
            }
        }
    }
    printf("\nJob %d done from %d to %d\n", job[0], start[0], end[0]);
    done++;
    curr_time = end[0];
    for(i = 1; i < m; i++){
        if(start[i] >= curr_time){
            printf("\nJob %d done from %d to %d\n", job[i], start[i], end[i]);
            done++;
            curr_time = end[i];
        }
    }
    printf("Total jobs done: %d", done);
    return 0;
}