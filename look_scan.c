#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, head, max, req[30], total = 0;
    printf("Enter n, Head, Max Disk size: "); 
    scanf("%d %d %d", &n, &head, &max);
    printf("Enter requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }
    
    // ==========================================
    // THE ONLY DIFFERENCE IS RIGHT HERE:
    // ==========================================
    // For SCAN: Keep these next 2 lines.
    // For LOOK: Delete these next 2 lines entirely.
    req[n] = max - 1; 
    n++; 
    // ==========================================

    // Simple Bubble Sort (Rest of the code stays 100% identical)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) { 
                int t = req[j]; 
                req[j] = req[j + 1]; 
                req[j + 1] = t; 
            }
        }
    }

    // Find the split point where head sits
    int idx = 0;
    for (int i = 0; i < n; i++) { 
        if (head < req[i]) { 
            idx = i; 
            break; 
        } 
    }

    printf("\nMovement Map:\nFrom\t->\tTo\n");
    for (int i = idx; i < n; i++) { 
        printf("%d\t->\t%d\n", head, req[i]); 
        total += abs(req[i] - head); 
        head = req[i]; 
    }
    for (int i = idx - 1; i >= 0; i--) { 
        printf("%d\t->\t%d\n", head, req[i]); 
        total += abs(req[i] - head); 
        head = req[i]; 
    }
    
    printf("Total Head Movements = %d\n", total);
    return 0;
}
