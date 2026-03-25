// testfiles/99_block_sequential.c
// Deux blocs séquentiels — même nom de variable dans deux blocs distincts
// (pas de shadowing : chaque bloc a son propre scope)
int main() {
    int total;
    total = 0;
    {
        int x;
        x = 10;
        total = total + x;
    }
    {
        int y;
        y = 32;
        total = total + y;
    }
    return total;
}
// attendu : 42
