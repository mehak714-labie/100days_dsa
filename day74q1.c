#include <stdio.h>
#include <string.h>

#define MAX 1000   // maximum number of votes
#define LEN 50     // maximum length of candidate name

// Function to compare strings lexicographically
int isLexSmaller(char *a, char *b) {
    return strcmp(a, b) < 0;
}

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][LEN];
    int count[MAX] = {0};
    int unique = 0;

    // Read votes
    for (int i = 0; i < n; i++) {
        char temp[LEN];
        scanf("%s", temp);

        int found = -1;
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(names[unique], temp);
            count[unique] = 1;
            unique++;
        }
    }

    // Find winner
    int maxVotes = -1;
    char winner[LEN];
    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes || 
           (count[i] == maxVotes && isLexSmaller(names[i], winner))) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
    }

    printf("%s %d\n", winner, maxVotes);
    return 0;
}
