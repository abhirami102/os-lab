#include <stdio.h>
int main() {
    int n, tq, at[20], bt[20], rem[20], cur=0, comp=0;
    float t_wt=0, t_tat=0;

    printf("Enter n and TQ: "); scanf("%d %d", &n, &tq);
    for(int i=0; i<n; i++) { scanf("%d %d", &at[i], &bt[i]); rem[i] = bt[i]; }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    while(comp < n) {
        int idle = 1;
        for(int i=0; i<n; i++) {
            if(at[i] <= cur && rem[i] > 0) {
                idle = 0;
                int take = (rem[i] > tq) ? tq : rem[i];
                cur += take; rem[i] -= take;
                if(rem[i] == 0) {
                    comp++;
                    int tat = cur - at[i], wt = tat - bt[i];
                    t_wt += wt; t_tat += tat;
                    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], cur, tat, wt);
                }
            }
        }
        if(idle) cur++;
    }
    printf("\nAvg WT = %.2f, Avg TAT = %.2f\n", t_wt/n, t_tat/n);
    return 0;
}
