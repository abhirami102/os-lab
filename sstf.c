#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, head, req[20], vis[20]={0}, total=0;
    printf("Enter n and Head: "); scanf("%d %d", &n, &head);
    for(int i=0; i<n; i++) scanf("%d", &req[i]);

    printf("\nMovement Map:\nFrom\t->\tTo\tTracks\n");
    for(int i=0; i<n; i++) {
        int min = 1e9, idx = -1;
        for(int j=0; j<n; j++) {
            if(!vis[j] && abs(req[j] - head) < min) { min = abs(req[j] - head); idx = j; }
        }
        vis[idx] = 1; total += min;
        printf("%d\t->\t%d\t(%d)\n", head, req[idx], min);
        head = req[idx];
    }
    printf("Total Movements = %d\n", total);
    return 0;
}
