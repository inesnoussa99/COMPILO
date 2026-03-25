// testfiles/105_shadow_double_decl_error.c
// Double déclaration dans le MÊME scope → erreur
int main() {
    int x;
    int x;
    return x;
}
