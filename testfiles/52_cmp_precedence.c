// testfiles/52_cmp_precedence.c
int main() {
    int a;
    int b;
    int c;
    a = 1;
    b = 2;
    c = 3;
    return a + b == c;
}
// attendu : 1  (1+2 == 3 → vrai)
