#include <stdio.h>

int main() {
    int m, n;
    
    // Read dimensions
    scanf("%d %d", &m, &n);
    
    int a[m][n];
    
    // Read matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    // Check if square matrix
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }
    
    int symmetric = 1;  // assume symmetric
    
    // Check symmetry condition
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if (!symmetric) break;
    }
    
    if (symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");
    
    return 0;
}
