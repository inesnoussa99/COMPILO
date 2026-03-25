// testfiles/58_neg_expr.c
int main() {
    int a;
    int b;
    a = 3;
    b = 4;
    return -(a + b);
}
// attendu : 246  (-(3+4) = -7, code retour = 256-7 = 249... non, en unsigned : 249)
// attendu : 249
