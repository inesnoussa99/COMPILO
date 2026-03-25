// testfiles/109_if_else_false.c
// if/else : condition fausse → branche else exécutée
int main() {
    int x;
    int cond;
    cond = 0;
    if (cond) {
        x = 10;
    } else {
        x = 20;
    }
    return x;
}
// attendu : 20
