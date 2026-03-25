// testfiles/133_double_param.c
// Double déclaration d'un paramètre dans la signature → erreur
int f(int x, int x) {
    return x;
}
int main() {
    return f(1, 2);
}
