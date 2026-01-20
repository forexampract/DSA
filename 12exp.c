#include <stdio.h>

int main() {
    int ht[50], n, m, k, i, h;

    printf("Enter the number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter the two digit memory locations (m) for hash table: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
        ht[i] = -1;

    printf("Enter the four digit key values (K) for N Employee Records:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &k);
        h = k % m;

        while (ht[h] != -1)
            h = (h + 1) % m;   // Linear probing

        ht[h] = k;
    }

    printf("Hash Table contents are:\n");
    for (i = 0; i < m; i++)
        printf("T[%d] -> %d\n", i, ht[i]);

    return 0;
}
