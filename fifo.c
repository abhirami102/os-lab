#include <stdio.h>
int main() {
    int n, f_cnt, pages[50], f[10], faults = 0, pos = 0;

    printf("Enter n and frame count: "); scanf("%d %d", &n, &f_cnt);
    printf("Enter pages:\n");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    for (int i = 0; i < f_cnt; i++) f[i] = -1; // Initialize frames as empty

    printf("\nPage\tFrames\t\tStatus\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f_cnt; j++) {
            if (f[j] == pages[i]) { found = 1; break; }
        }

        printf("%d\t", pages[i]);
        if (found) {
            for (int j = 0; j < f_cnt; j++) printf("%d ", f[j]);
            printf("\tH\n");
        } else {
            f[pos] = pages[i];        // Put page in current position
            pos = (pos + 1) % f_cnt;  // Move pointer circularly (FIFO)
            faults++;
            for (int j = 0; j < f_cnt; j++) printf("%d ", f[j]);
            printf("\tM\n");
        }
    }
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
