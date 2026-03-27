// testfiles/144_char_const_putchar.c
// Constante caractère passée à putchar
#include <stdio.h>
int main() {
    putchar('H');
    putchar('i');
    putchar('\n');
    return 0;
}
// attendu : 0 (affiche "Hi\n")
