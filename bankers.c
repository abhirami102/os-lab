#include <stdio.h>
int main() {
    int p, r, alloc[10][10], max[10][10], need[10][10], avail[10], fin[10]={0}, seq[10], cnt=0;
    printf("Enter P and R count: "); scanf("%d %d", &p, &r);

    printf("Enter Allocation Matrix:\n");
    for(int i=0; i<p; i++) for(int j=0; j<r; j++) scanf("%d", &alloc[i][j]);
    printf("Enter Max Matrix:\n");
    for(int i=0; i<p; i++) for(int j=0; j<r; j++) { scanf("%d", &max[i][j]); need[i][j] = max[i][j] - alloc[i][j]; }
    printf("Enter Available Resource Vector: ");
    for(int i=0; i<r; i++) scanf("%d", &avail[i]);

    printf("\nPID\tAlloc\tMax\tNeed\n");
    for(int i=0; i<p; i++) {
        printf("P%d\t", i);
        for(int j=0; j<r; j++) printf("%d ", alloc[i][j]); printf("\t");
        for(int j=0; j<r; j++) printf("%d ", max[i][j]);   printf("\t");
        for(int j=0; j<r; j++) printf("%d ", need[i][j]);  printf("\n");
    }
    while (cnt<p){
        int found=0;
        for (int i=0;i<p;i++){
            if(!fin[i]){
                int j;
                for(j=0;j<r;j++){
                    if(need[i][j]>avail[j]){
                        break;
                    }
                }
                if(j==r){
                    for(int k=0;k<r;k++){
                        avail[k]+=alloc[i][k];
                    }
                        seq[cnt++]=i,found=1,fin[i]=1;
                }
            }
        }
            if(!found){
                printf("unsafe state");
                return 0;
            }
    }

       printf("safe sate, sequence");
       for(int i=0;i<p;i++)printf("P%d ",seq[i]);
       return 0;
}

}
