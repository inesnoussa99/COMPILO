// testfiles/84_func_void_no_return.c
#include <stdio.h>
// Fonction void sans return explicite
void print_B() {
    putchar(66);
}
int main() {
    print_B();
    return 0;
}
// attendu : 0  (affiche 'B')
