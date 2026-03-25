// testfiles/67_decl_reuse.c
// Réaffectation d'une variable déclarée au milieu
int main() {
    int a;
    a = 10;
    int b;
    b = a - 3;
    a = b * 2;
    return a;
}
// attendu : 14  (b=7, a=7*2)
