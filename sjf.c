#include <stdio.h>
int main() {
    int n, at[20], bt[20], ct[20], comp[20]={0}, count=0, cur=0;
    float t_wt=0, t_tat=0;

    printf("Enter n: "); scanf("%d", &n);
    printf("Enter AT and BT:\n");
    for(int i=0; i<n; i++) scanf("%d %d", &at[i], &bt[i]);

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    while(count < n) {
        int idx = -1, min = 1e9;
        for(int i=0; i<n; i++) {
            if(at[i] <= cur && !comp[i] && bt[i] < min) {
                min = bt[i]; idx = i;
            }
        }
        if(idx != -1) {
            cur += bt[idx]; ct[idx] = cur;
            comp[idx] = 1; count++;
            int tat = ct[idx] - at[idx], wt = tat - bt[idx];
            t_wt += wt; t_tat += tat;
            printf("P%d\t%d\t%d\t%d\t%d\t%d\n", idx+1, at[idx], bt[idx], ct[idx], tat, wt);
        } else cur++;
    }
    printf("\nAvg WT = %.2f, Avg TAT = %.2f\n", t_wt/n, t_tat/n);
    return 0;
}
