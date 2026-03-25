// testfiles/100_block_compute.c
// Bloc utilisant variables externes et locales pour un calcul
int main() {
    int a;
    int b;
    a = 6;
    b = 7;
    {
        int prod;
        prod = a * b;
        a = prod;
    }
    return a;
}
// attendu : 42
