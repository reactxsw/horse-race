#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int i, j, k;
void delay(int seconds) {
    clock_t start = clock();
    while (clock() < start + 1000 * seconds);
}

void load(int horse[]) {
    printf("==============================\n");
    for (j = 0; j < 5; j++) {
        printf("Horse %d", j + 1);
        for (k = 0; k < horse[j]; k++) {
            printf("-");
        }
        printf("X\n");
    }
}

int main() {
    srand(time(NULL));
    int horse[5] = {
        rand() % (4) + 3,
        rand() % (4) + 3,
        rand() % (4) + 3,
        rand() % (4) + 3,
        rand() % (4) + 3
    };
    int userhorse;
    int run = 1;
    printf("Choose a horse (1-5) :");
    scanf("%d", & userhorse);
    if (!(userhorse > 5 || userhorse < 1)) {
        load(horse);
        while (run == 1) {
            delay(1);
            int numOhorseMove = rand() % 5;
            for (i = 0; i < numOhorseMove; i++) {
                int x = rand() % 5;
                horse[x] = horse[x] - 1;
                load(horse);
                if (horse[x] == 0) {
                    run = 0;
                    printf("==============================\n");
                    printf("Horse [%d] won\n", x + 1);
                    if (x + 1 == userhorse) {
                        printf("You won");
                    } else {
                        printf("You lose");
                    }
                    break;
                }
            }
        }
    } else {
        printf("No horse %d",userhorse);
    }
    return 0;
}
