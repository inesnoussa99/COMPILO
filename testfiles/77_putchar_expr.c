// testfiles/77_putchar_expr.c
#include <stdio.h>
int main() {
    int a;
    a = 60;
    putchar(a + 7);
    return 0;
}
// attendu : 0  (60+7=67='C')
