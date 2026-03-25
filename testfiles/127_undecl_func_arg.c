// testfiles/127_undecl_func_arg.c
// Variable non déclarée passée en argument → erreur
int f(int a) { return a; }
int main() {
    return f(undef);
}
