// testfiles/53_lt_eq.c
int main() {
    int a;
    int b;
    a = 3;
    b = 3;
    return a < b == 0;
}
// attendu : 1  (3 < 3 → 0, 0 == 0 → 1)
