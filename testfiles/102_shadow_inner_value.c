// testfiles/102_shadow_inner_value.c
// Retourne la valeur de la variable interne (shadowée)
int main() {
    int x;
    x = 1;
    int r;
    {
        int x;
        x = 42;
        r = x;
    }
    return r;
}
// attendu : 42
