// testfiles/43_bitwise_precedence.c
int main() {
    int a;
    int b;
    int c;
    a = 7;
    b = 5;
    c = 3;
    return a ^ b & c;
}
// attendu : 6  (7 ^ (5 & 3) = 0111 ^ (0101 & 0011) = 0111 ^ 0001 = 0110)
