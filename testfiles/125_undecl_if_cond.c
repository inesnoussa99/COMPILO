// testfiles/125_undecl_if_cond.c
// Variable non déclarée dans la condition d'un if → erreur
int main() {
    if (cond > 0) return 1;
    return 0;
}
