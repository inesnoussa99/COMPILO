// testfiles/86_func_local_vars.c
// Fonction avec paramètres et variables locales
int sum3(int a, int b, int c) {
    int total;
    total = a + b + c;
    return total;
}
int main() {
    return sum3(10, 15, 17);
}
// attendu : 42
