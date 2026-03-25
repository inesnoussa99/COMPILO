// testfiles/71_chained_assign_b.c
// Vérifie que b reçoit aussi la valeur dans un chaînage
int main() {
    int a;
    int b;
    a = b = 13;
    return b;
}
// attendu : 13
