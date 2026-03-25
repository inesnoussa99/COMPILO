// testfiles/39_bitwise_or_zero.c
int main() {
    int a;
    a = 42;
    return a | 0;
}
// attendu : 42  (x | 0 = x)
