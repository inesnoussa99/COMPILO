// testfiles/131_double_decl_inner_block.c
// Double déclaration dans un bloc interne → erreur
int main() {
    {
        int x;
        int x;
    }
    return 0;
}
