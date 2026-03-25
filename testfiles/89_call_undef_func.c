// testfiles/89_call_undef_func.c
// Appel à une fonction non définie → doit être rejeté
int main() {
    return foo();
}
