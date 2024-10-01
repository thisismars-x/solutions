#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

int parent[1001]; 

int find(int u) {
    return u == parent[u] ? u : parent[u] = find(parent[u]);
}

void union_sets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    parent[u] = v; 
}

bool same(int u, int v) {
    return find(u) == find(v);
}

int main() {
    int ncase; 
    scanf("%d", &ncase);

    for (int i = 1; i <= ncase; i++) {
        if (i != 1) putchar('\n');

        char str[100];
        int sure = 0, unsure = 0;
        int n;

        scanf("%d", &n);
        for (int j = 1; j <= n; j++) parent[j] = j;

        getchar(); 

        while (fgets(str, sizeof(str), stdin)) { 
            if (str[0] == '\n') break; 

            char temp;
            int a = 0, b = 0;

            sscanf(str, "%c %d %d", &temp, &a, &b); 

            if (temp == 'c') {
                union_sets(a, b);
            } else if (same(a, b)) {
                sure++;
            } else {
                unsure++;
            }
        }

        printf("%d,%d\n", sure, unsure);
    }

    return 0;
}
