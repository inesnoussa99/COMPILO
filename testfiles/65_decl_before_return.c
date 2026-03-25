// testfiles/65_decl_before_return.c
// Déclaration juste avant le return
int main() {
    int a;
    a = 42;
    int b = a + 1;
    return b;
}
// attendu : 43
