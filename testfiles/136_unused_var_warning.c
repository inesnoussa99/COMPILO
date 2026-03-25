// testfiles/136_unused_var_warning.c
// Variable déclarée mais jamais utilisée → warning, programme valide
int main() {
    int unused;
    return 0;
}
// attendu : 0 (warning émis, pas une erreur)
