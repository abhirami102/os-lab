#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, head, max, req[30], total=0;
    printf("Enter n, Head, Max Disk size: "); scanf("%d %d %d", &n, &head, &max);
    for(int i=0; i<n; i++) scanf("%d", &req[i]);

    // Add the two absolute boundaries to the request list
    req[n] = 0; req[n+1] = max - 1;
    n += 2;

    // Simple Bubble Sort
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(req[j] > req[j+1]) { int t=req[j]; req[j]=req[j+1]; req[j+1]=t; }

    // Find where the head currently sits in the sorted list
    int idx = 0;
    for(int i=0; i<n; i++) { if(head < req[i]) { idx = i; break; } }

    printf("\nMovement Map:\nFrom\t->\tTo\n");

    // 1. Move right from current head to the very end boundary (max - 1)
    for(int i = idx; i < n; i++) { printf("%d\t->\t%d\n", head, req[i]); total += abs(req[i]-head); head = req[i]; }

    // 2. Giant circular jump back to track 0 (Add this distance to total)
    printf("%d\t->\t0\t(Reset Jump)\n", head);
    total += head;
    head = 0;

    // 3. Keep moving right from 0 up to the original split point
    for(int i = 0; i < idx; i++) { printf("%d\t->\t%d\n", head, req[i]); total += abs(req[i]-head); head = req[i]; }

    printf("Total Head Movements = %d\n", total);
    return 0;
}
