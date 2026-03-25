// testfiles/137_unused_var_inner_block.c
// Variable inutilisée dans un bloc interne → warning
int main() {
    int x;
    x = 5;
    {
        int local;
    }
    return x;
}
// attendu : 5
