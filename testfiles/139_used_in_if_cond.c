// testfiles/139_used_in_if_cond.c
// Variable lue dans une condition if → pas de warning
int main() {
    int x;
    x = 1;
    if (x) return 1;
    return 0;
}
// attendu : 1
