#include <stdio.h>
int main() {
    int n, at[20], bt[20], ct=0, tat, wt;
    float total_wt=0, total_tat=0;

    printf("Enter n: "); scanf("%d", &n);
    printf("Enter AT and BT:\n");
    for(int i=0; i<n; i++) scanf("%d %d", &at[i], &bt[i]);

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) {
        if(ct < at[i]) ct = at[i]; // CPU Idle handling
        ct += bt[i];
        tat = ct - at[i];
        wt = tat - bt[i];
        total_wt += wt; total_tat += tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct, tat, wt);
    }
    printf("\nAvg WT = %.2f, Avg TAT = %.2f\n", total_wt/n, total_tat/n);
    return 0;
}
