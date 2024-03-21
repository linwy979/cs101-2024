/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // 用於 sleep 函數

#define LOTTO_NUMBERS 7
#define MAX_NUMBER 69

void generateLottoNumbers(int lottoNumbers[], int numSets);

int main() {
    int numSets;

    // 獲取目前時間
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // 詢問使用者要輸入多少組樂透號碼
    printf("請輸入要產生多少組樂透號碼：");
    scanf("%d", &numSets);

    // 定義星期幾和月份的縮寫
    const char *weekdays[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // 輸出日期時間和樂透號碼
    printf("========lotto649========\n");
    printf("%s %s %d %02d:%02d:%02d %d\n", 
           weekdays[tm->tm_wday], months[tm->tm_mon], tm->tm_mday,
           tm->tm_hour, tm->tm_min, tm->tm_sec, tm->tm_year + 1900);

    // 產生樂透號碼
    int lottoNumbers[LOTTO_NUMBERS * numSets];
    generateLottoNumbers(lottoNumbers, numSets);

    // 輸出樂透號碼
    int setCounter = 0;
    for (int i = 0; i < numSets; i++) {
        if (i < 3) {
            printf("[%d]: ", i + 1);
        } else {
            printf("[%d]:  --  --  --  --  --  --  --\n", ++setCounter);
            continue;
        }
        for (int j = 0; j < LOTTO_NUMBERS; j++) {
            printf("%02d ", lottoNumbers[i * LOTTO_NUMBERS + j]);
        }
        printf("\n");
    }

    // 如果樂透號碼組數不足五組，後面的樂透號碼將以 "---" 標示
    for (int i = setCounter + 1; i <= 5; i++) {
        printf("[%d]:  -- -- -- -- -- -- --\n", i);
    }

    printf("========csie@CGU=========\n");
   
    return 0;
}

void generateLottoNumbers(int lottoNumbers[], int numSets) {
    srand(time(0)); // 初始化隨機數種子
    for (int i = 0; i < numSets; i++) {
        // 生成樂透號碼
        for (int j = 0; j < LOTTO_NUMBERS; j++) {
            lottoNumbers[i * LOTTO_NUMBERS + j] = rand() % MAX_NUMBER + 1;
        }
    }
}
