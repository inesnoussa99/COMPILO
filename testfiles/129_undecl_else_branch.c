// testfiles/129_undecl_else_branch.c
// Variable non déclarée dans la branche else → erreur
int main() {
    int x;
    x = 1;
    if (x) {
        return 1;
    } else {
        return ghost;
    }
}
