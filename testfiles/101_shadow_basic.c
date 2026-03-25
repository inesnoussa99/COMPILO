// testfiles/101_shadow_basic.c
// Variable interne qui shadow la variable externe
int main() {
    int x;
    x = 1;
    {
        int x;
        x = 42;
    }
    return x;
}
// attendu : 1  (x externe inchangé)
