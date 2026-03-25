// testfiles/111_while_zero.c
// while : condition fausse dès le départ → corps jamais exécuté
int main() {
    int x;
    x = 5;
    while (0) {
        x = 99;
    }
    return x;
}
// attendu : 5
