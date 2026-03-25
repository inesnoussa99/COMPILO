// testfiles/126_undecl_while_cond.c
// Variable non déclarée dans la condition d'un while → erreur
int main() {
    int i;
    i = 0;
    while (n > 0) {
        i = i + 1;
    }
    return i;
}
