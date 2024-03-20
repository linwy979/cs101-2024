/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // 打開自己的源文件
    FILE *fp = fopen(__FILE__, "r");
    if (fp == NULL) {
        printf("無法打開文件\n");
        return 1;
    }

    // 定義讀取行數的變數和計數器
    int lineNumber = 0;
    int mainLineNumber = -1;
    char line[1000];

    // 逐行讀取文件，直到找到 main 函數或達到文件末尾
    while (fgets(line, sizeof(line), fp) != NULL) {
        lineNumber++;
        if (strstr(line, "int main") != NULL) {
            mainLineNumber = lineNumber;
            break;
        }
    }

    // 如果找到 main 函數，輸出其所在行數
    if (mainLineNumber != -1) {
        printf("%d int main(){\n", mainLineNumber);
    } else {
        printf("未找到 main 函數\n");
    }

    // 關閉文件
    fclose(fp);

    return 0;
}