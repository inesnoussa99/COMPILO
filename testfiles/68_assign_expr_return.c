// testfiles/68_assign_expr_return.c
// return (a = valeur) retourne la valeur assignée
int main() {
    int a;
    return (a = 42);
}
// attendu : 42
