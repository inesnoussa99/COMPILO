// testfiles/66_decl_sum_of_vars.c
// Déclaration initialisée avec expression de plusieurs variables
int main() {
    int a;
    int b;
    a = 3;
    b = 4;
    int c = a * a + b * b;
    return c;
}
// attendu : 25  (3*3 + 4*4)
