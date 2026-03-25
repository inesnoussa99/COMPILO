// testfiles/97_block_nested.c
// Blocs imbriqués — chaque bloc a son propre scope
int main() {
    int a;
    a = 1;
    {
        int b;
        b = 2;
        {
            int c;
            c = 3;
            a = a + b + c;
        }
    }
    return a;
}
// attendu : 6
