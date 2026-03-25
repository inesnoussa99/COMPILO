// testfiles/104_shadow_init_from_outer.c
// La variable interne peut être initialisée depuis l'externe
int main() {
    int x;
    x = 7;
    {
        int x = x + 1;
        x = x * 2;
    }
    return x;
}
// attendu : 7  (x externe inchangé)
