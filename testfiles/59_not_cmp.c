// testfiles/59_not_cmp.c
int main() {
    int a;
    int b;
    a = 3;
    b = 5;
    return !(a == b);
}
// attendu : 1  (3==5 → 0, !0 → 1)
