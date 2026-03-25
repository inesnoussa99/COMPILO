// testfiles/96_block_local_var.c
// Variable déclarée et utilisée dans un bloc
int main() {
    int result;
    result = 0;
    {
        int tmp;
        tmp = 42;
        result = tmp;
    }
    return result;
}
// attendu : 42
