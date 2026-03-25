// testfiles/107_if_false.c
// if simple : condition fausse → branche non exécutée
int main() {
    int x;
    x = 7;
    if (0) x = 99;
    return x;
}
// attendu : 7
