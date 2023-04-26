#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    int len1, len2, i, j;

    printf("Enter string 1: ");
    scanf("%s", str1);
    len1 = strlen(str1);

    printf("Enter string 2: ");
    scanf("%s", str2);
    len2 = strlen(str2);

    int lcs[len1 + 1][len2 + 1];

    // Initialize the LCS table
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else {
                lcs[i][j] = (lcs[i - 1][j] > lcs[i][j - 1]) ? lcs[i - 1][j] : lcs[i][j - 1];
            }
        }
    }

    // Print the length of LCS
    printf("Length of LCS: %d\n", lcs[len1][len2]);

    // Print the characters in LCS
    printf("Characters in LCS: ");
    i = len1;
    j = len2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            printf("%c", str1[i - 1]);
            i--;
            j--;
        }
        else if (lcs[i - 1][j] > lcs[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    printf("\n");

    return 0;
}
