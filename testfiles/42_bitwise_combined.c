// testfiles/42_bitwise_combined.c
int main() {
    int a;
    int b;
    int c;
    a = 12;
    b = 10;
    c = 6;
    return a & b | c;
}
// attendu : 14  ((1100 & 1010) | 0110 = 1000 | 0110 = 1110)
