// testfiles/63_decl_init_from_var.c
// Déclaration avec init utilisant une variable déjà déclarée
int main() {
    int a;
    a = 10;
    int b = a * 2;
    return b;
}
// attendu : 20
