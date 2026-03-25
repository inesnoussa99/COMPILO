// testfiles/83_func_void.c
#include <stdio.h>
// Fonction void qui appelle putchar
void print_A() {
    putchar(65);
    return;
}
int main() {
    print_A();
    return 0;
}
// attendu : 0  (affiche 'A')
