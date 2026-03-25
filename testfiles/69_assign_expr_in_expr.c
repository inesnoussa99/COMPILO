// testfiles/69_assign_expr_in_expr.c
// L'affectation retourne sa valeur, utilisable dans une expression
int main() {
    int a;
    int b;
    b = (a = 5) + 3;
    return b;
}
// attendu : 8
