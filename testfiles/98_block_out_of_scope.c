// testfiles/98_block_out_of_scope.c
// Variable utilisée hors de son bloc → doit être rejeté
int main() {
    {
        int x;
        x = 5;
    }
    return x;
}
