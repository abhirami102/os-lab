#include <stdio.h>

int main() {
    int n, frames;
    printf("Enter reference string length: ");
    scanf("%d", &n);
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int pages[50], f[10];
    printf("Enter pages:\n");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);
    for (int i = 0; i < frames; i++) f[i] = -1;

    int pos = 0, faults = 0;

    // Header Row
    printf("\nPage\t");
    for (int i = 0; i < frames; i++) printf("F%d\t", i + 1);
    printf("Status\n");

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (f[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        printf("%d\t", pages[i]);
        if (found) {
            for (int j = 0; j < frames; j++) printf("%d\t", f[j]);
            printf("H\n");
        } else {
            f[pos] = pages[i];
            pos = (pos + 1) % frames;
            faults++;
            for (int j = 0; j < frames; j++) printf("%d\t", f[j]);
            printf("M\n");
        }
    }
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
