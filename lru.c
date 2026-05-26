#include <stdio.h>
int main() {
    int n, f_cnt, pages[50], f[10], faults=0;
    printf("Enter n and frame count: "); scanf("%d %d", &n, &f_cnt);
    for(int i=0; i<n; i++) scanf("%d", &pages[i]);
    for(int i=0; i<f_cnt; i++) f[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");
    for(int i=0; i<n; i++) {
        int found = 0, pos = 0;
        for(int j=0; j<f_cnt; j++) if(f[j] == pages[i]) { found = 1; break; }

        printf("%d\t", pages[i]);
        if(!found) {
            int max_dist = -1;
            for(int j=0; j<f_cnt; j++) {
                if(f[j] == -1) { pos = j; break; } // Take empty frame if available

                int dist = 1e9;
                for(int k = i - 1; k >= 0; k--) { // Scan backward into history
                    if(f[j] == pages[k]) { dist = i - k; break; }
                }
                if(dist > max_dist) { max_dist = dist; pos = j; }
            }
            f[pos] = pages[i]; faults++;
        }
        for(int j=0; j<f_cnt; j++) printf("%d ", f[j]);
        printf("\t%c\n", found ? 'H' : 'M');
    }
    printf("Total Page Faults = %d\n", faults);
    return 0;
}
