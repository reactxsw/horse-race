#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

void delay(int number_of_seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + 1000 * number_of_seconds);
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
    int userhorse, i, j, k;
    int run = 1;
    printf("Choose a horse (1-5) :");
    scanf("%d", & userhorse);
    printf("==============================\n");
    for (j = 0; j < 5; j++) {
        printf("Horse %d", j + 1);
        for (k = 0; k < horse[j]; k++) {
            printf("-");
        }
        printf("X\n");
    }
    while (run == 1) {
        delay(1);
        int numOhorseMove = rand() % 5;
        for (i = 0; i < numOhorseMove; i++) {
            int x = rand() % 5;
            horse[x] = horse[x] - 1;
            printf("==============================\n");
            for (j = 0; j < 5; j++) {
                printf("Horse %d", j + 1);
                for (k = 0; k < horse[j]; k++) {
                    printf("-");
                }
                printf("X\n");
            }
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

    return 0;

}