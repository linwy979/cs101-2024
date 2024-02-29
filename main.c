/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void print_sp(int i, int n){
    for(int sp=0;sp<n-i;sp++){
        printf(" ");
    }
}
void print_num(int n){
    for(int i=0; i<n;i++){
        printf("%d" , n);
        printf(" ");
    }
    printf("\n");
    
}
int main(){
    int row=6;
    for(int i=0; i<=row;i++){
        print_sp(i, row);
        print_num(i);
    }
    return 0;
}