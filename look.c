#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, head, req[30], total=0;
    printf("Enter n, Head: "); scanf("%d %d", &n, &head);
    printf("Enter requests:\n");
    for(int i=0; i<n; i++) scanf("%d", &req[i]);

    // Bubble Sort (No boundary added!)
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(req[j] > req[j+1]) { int t=req[j]; req[j]=req[j+1]; req[j+1]=t; }

    // Find split point
    int idx = 0;
    for(int i=0; i<n; i++) { if(head < req[i]) { idx = i; break; } }

    printf("\nMovement Map:\nFrom\t->\tTo\n");
    // Serve Right side up to the highest request
    for(int i = idx; i < n; i++) { printf("%d\t->\t%d\n", head, req[i]); total += abs(req[i]-head); head = req[i]; }
    // Reverse and serve Left side down to the lowest request
    for(int i = idx - 1; i >= 0; i--) { printf("%d\t->\t%d\n", head, req[i]); total += abs(req[i]-head); head = req[i]; }

    printf("Total Head Movements = %d\n", total);
    return 0;
}
