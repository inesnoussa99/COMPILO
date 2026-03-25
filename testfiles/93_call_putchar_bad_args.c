// testfiles/93_call_putchar_bad_args.c
#include <stdio.h>
// putchar attend 1 arg, on en passe 0 → doit être rejeté
int main() {
    putchar();
    return 0;
}
