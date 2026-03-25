// testfiles/87_func_retval_used.c
// Valeur de retour stockée dans une variable
int triple(int x) {
    return x * 3;
}
int main() {
    int a;
    a = triple(7);
    return a;
}
// attendu : 21
