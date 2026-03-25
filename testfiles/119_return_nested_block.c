// testfiles/119_return_nested_block.c
// return dans un bloc imbriqué
int main() {
    int x;
    x = 1;
    {
        {
            return 99;
        }
    }
    return 0;
}
// attendu : 99
