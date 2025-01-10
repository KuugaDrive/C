#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearBuffer() {
    while (getchar() != '\n');
}

int main() {
    int target, guess, attempts = 0;
    char playAgain;


    srand(time(0));

    do {

        target = rand() % 100 + 1;
        printf("\n=== Selamat datang di permainan Tebak Angka! ===\n");
        printf("Saya telah memilih angka antara 1 hingga 100.\n");
        printf("Cobalah untuk menebaknya!\n\n");

        do {
            printf("Masukkan tebakan Anda: ");
            if (scanf("%d", &guess) != 1) {
                printf("Input tidak valid! Masukkan angka.\n");
                clearBuffer();
                continue;
            }

            attempts++;

            if (guess < target) {
                printf("Terlalu kecil! Coba lagi.\n");
            } else if (guess > target) {
                printf("Terlalu besar! Coba lagi.\n");
            } else {
                printf("Selamat! Anda menebak dengan benar dalam %d percobaan.\n", attempts);
            }
        } while (guess != target);

        printf("\nApakah Anda ingin bermain lagi? (y/n): ");
        clearBuffer();
        scanf("%c", &playAgain);

        attempts = 0; 
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nTerima kasih telah bermain! Sampai jumpa lagi :)\n");
    return 0;
}
