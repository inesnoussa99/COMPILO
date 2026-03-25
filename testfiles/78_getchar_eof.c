// testfiles/78_getchar_eof.c
#include <stdio.h>
int main() {
    int c;
    c = getchar();
    return c == -1;
}
// attendu : 1  (EOF détecté sur stdin vide)
