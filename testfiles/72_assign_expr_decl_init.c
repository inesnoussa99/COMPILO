// testfiles/72_assign_expr_decl_init.c
// Initialisation avec une affectation-expression
int main() {
    int a;
    int b = (a = 10);
    return a + b;
}
// attendu : 20
