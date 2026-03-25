// testfiles/141_used_as_func_arg.c
// Variable passée en argument → pas de warning
int double_val(int a) { return a * 2; }
int main() {
    int x;
    x = 21;
    return double_val(x);
}
// attendu : 42
