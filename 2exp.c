#include <stdio.h>

void readString(char string[], int size, char message[]) {
    int i;
    printf("%s", message);
    fgets(string, size, stdin);
    for (i = 0; string[i]; i++)
        if (string[i] == '\n')
            string[i] = '\0';
}

void findAndReplace(char mainString[], char patternString[], char replaceString[]) {
    char resultString[200];
    int i = 0, j = 0, k, m;
    int found = 0;

    while (mainString[i] != '\0') {
        for (k = 0, m = i;
             patternString[k] != '\0' && mainString[m] == patternString[k];
             k++, m++);

        if (patternString[k] == '\0') {   // Pattern found
            found = 1;
            for (k = 0; replaceString[k] != '\0'; k++)
                resultString[j++] = replaceString[k];
            i = m;
        } else {
            resultString[j++] = mainString[i++];
        }
    }

    resultString[j] = '\0';

    if (found)
        printf("Modified String: %s\n", resultString);
    else
        printf("Pattern string not found\n");
}

int main() {
    char mainString[100], patternString[50], replaceString[50];

    readString(mainString, 100, "Enter the main string: ");
    readString(patternString, 50, "Enter the pattern string: ");
    readString(replaceString, 50, "Enter the replace string: ");

    findAndReplace(mainString, patternString, replaceString);
    return 0;
}
