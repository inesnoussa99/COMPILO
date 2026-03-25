// testfiles/110_while_simple.c
// while : boucle simple
int main() {
    int i;
    int s;
    i = 0;
    s = 0;
    while (i < 5) {
        s = s + i;
        i = i + 1;
    }
    return s;
}
// attendu : 0+1+2+3+4 = 10
