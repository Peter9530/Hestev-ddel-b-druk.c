#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_HORSES 5
#define TRACK_LENGTH 50

void print_track(int positions[], char horses[]) {
    for (int i = 0; i < NUM_HORSES; i++) {
        for (int j = 0; j < TRACK_LENGTH; j++) {
            if (j == positions[i])
                printf("%c", horses[i]);
            else
                printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    printf("Velkommen til det store hestevaeddelob\n"
           "Reglerne er simple, hvis du taber skal du drikke\n"
           "Nu skal du vaelge din hest:\n"
           "Lucky Strike, bedre kendt som A\n"
           "Ginger Babe, bedre kendt som B\n"
           "Man o' War, bedre kendt som C\n"
           "Black Caviar, bedre kendt som D\n"
           "Smarty Jones, bedre kendt som E\n"
           "Saa snart du har valgt en hest, begynder spillet\n");
    scanf("Din hest: %c");
    int positions[NUM_HORSES] = {0};
    char horses[NUM_HORSES] = {'A', 'B', 'C', 'D', 'E'};
    int winner = -1;

    srand(time(NULL));


    while (winner == -1) {
        for (int i = 0; i < NUM_HORSES; i++) {
            if (positions[i] < TRACK_LENGTH - 1) {
                positions[i] += rand() % 3;
            }

            if (positions[i] >= TRACK_LENGTH - 1) {
                winner = i;
            }
        }

        print_track(positions, horses);

        usleep(200000);  // svarer til 200 ms
    }

    printf("Hest %c vinder løbet!\n", horses[winner]);
    printf("Hvis dette ikke er din hest, skal du drikke!!");
    return 0;
}
