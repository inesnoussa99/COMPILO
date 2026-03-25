// testfiles/130_undecl_while_body.c
// Variable non déclarée dans le corps d'un while → erreur
int main() {
    int i;
    i = 0;
    while (i < 5) {
        i = i + phantom;
    }
    return i;
}
