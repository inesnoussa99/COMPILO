// testfiles/123_undecl_assign.c
// Affectation à une variable non déclarée → erreur
int main() {
    x = 5;
    int x;
    return x;
}
