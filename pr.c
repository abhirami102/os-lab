#include <stdio.h>
int main() {
    int n, at[20], bt[20], pri[20], ct[20], comp[20]={0}, count=0, cur=0;
    float t_wt=0, t_tat=0;

    printf("Enter n: "); scanf("%d", &n);
    printf("Enter AT, BT and Priority:\n");
    for(int i=0; i<n; i++) scanf("%d %d %d", &at[i], &bt[i], &pri[i]);

    printf("\nPID\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    while(count < n) {
        int idx = -1, min = 1e9;
        for(int i=0; i<n; i++) {
            if(at[i] <= cur && !comp[i] && pri[i] < min) {
                min = pri[i]; idx = i;
            }
        }
        if(idx != -1) {
            cur += bt[idx]; ct[idx] = cur;
            comp[idx] = 1; count++;
            int tat = ct[idx] - at[idx], wt = tat - bt[idx];
            t_wt += wt; t_tat += tat;
            printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", idx+1, at[idx], bt[idx], pri[idx], ct[idx], tat, wt);
        } else cur++;
    }
    printf("\nAvg WT = %.2f, Avg TAT = %.2f\n", t_wt/n, t_tat/n);
    return 0;
}
