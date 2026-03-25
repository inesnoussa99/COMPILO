// testfiles/134_param_redecl_in_body.c
// Paramètre redéclaré comme variable locale → erreur
int f(int x) {
    int x;
    return x;
}
int main() {
    return f(1);
}
