#include <stdio.h>

void readString(char *s, int n, const char *m) {
    printf("%s", m);
    fgets(s, n, stdin);
    for (int i = 0; s[i]; i++)
        if (s[i] == '\n') { s[i] = 0; break; }
}

int find(const char *s, const char *p, int k) {
    for (int i = k, j; s[i]; i++) {
        for (j = 0; p[j] && s[i + j] == p[j]; j++);
        if (!p[j]) return i;
    }
    return -1;
}

void replace(char *s, const char *p, const char *r) {
    char t[1024];
    int pos, f = 0;

    while ((pos = find(s, p, 0)) != -1) {
        f = 1;
        int i = 0, j = pos, k = 0;

        while (i < pos) t[i++] = s[k++];
        while (r[k]) t[i++] = r[k++];
        k = pos;
        while (s[k] && p[k - pos]) k++;
        while (s[k]) t[i++] = s[k++];

        t[i] = 0;
        for (i = 0; (s[i] = t[i]); i++);
    }
    if (!f) printf("Pattern not found in the string.\n");
}

int main() {
    char S[1024], P[100], R[100];
    readString(S,1024,"Enter the main string (STR): ");
    readString(P,100,"Enter the pattern string (PAT): ");
    readString(R,100,"Enter the replace string (REP): ");
    replace(S,P,R);
    printf("Modified String: %s\n", S);
}
