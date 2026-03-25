// testfiles/135_shadow_different_scopes_ok.c
// Même nom dans des scopes différents = shadowing valide, pas d'erreur
int main() {
    int x;
    x = 10;
    {
        int x;
        x = 20;
    }
    return x;
}
// attendu : 10
