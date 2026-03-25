// testfiles/103_shadow_nested.c
// Shadowing à plusieurs niveaux
int main() {
    int x;
    x = 10;
    {
        int x;
        x = 20;
        {
            int x;
            x = 30;
        }
        x = x + 1;
    }
    return x;
}
// attendu : 10  (x externe inchangé)
