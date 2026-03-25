// testfiles/120_return_func_call.c
// return d'un appel de fonction
int double_val(int n) {
    return n * 2;
}
int main() {
    return double_val(21);
}
// attendu : 42
