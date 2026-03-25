// testfiles/62_decl_after_assign.c
// Déclaration après une affectation
int main() {
    int a;
    a = 5;
    int b;
    b = 3;
    return a + b;
}
// attendu : 8
