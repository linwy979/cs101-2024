/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

// 定義書籍結構
struct Book {
    int id;
    int price;
    char title[100];
};

// 計算所有書籍的總價格
float total_price(struct Book books[], int num_books) {
    float total = 0.0;
    for (int i = 0; i < num_books; i++) {
        total += books[i].price;
    }
    return total;
}

// 輸出書籍資料
void list_books(struct Book books[], int num_books) {
    printf("書籍資料：\n");
    for (int i = 0; i < num_books; i++) {
        printf("ID：%d\n", books[i].id);
        printf("書名：%s\n", books[i].title);
        printf("價格：$%d\n", books[i].price);
        printf("\n");
    }
}

int main() {
    // 建立書籍資料
    struct Book books[6] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300, "The 38 Letters from J.D Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550, "Killers of the Flower Moon"},
        {5, 870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    // 輸出書籍資料
    list_books(books, 6);

    // 計算總價格並輸出
    float total = total_price(books, 6);
    printf("所有書籍的總價格為：$%.2f\n", total);

    return 0;
}