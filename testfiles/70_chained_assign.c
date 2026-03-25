// testfiles/70_chained_assign.c
// Affectation chaînée : a = b = valeur
int main() {
    int a;
    int b;
    a = b = 7;
    return a;
}
// attendu : 7
