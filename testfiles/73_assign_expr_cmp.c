// testfiles/73_assign_expr_cmp.c
// Affectation dans une comparaison
int main() {
    int a;
    int b;
    b = (a = 5) == 5;
    return b;
}
// attendu : 1
