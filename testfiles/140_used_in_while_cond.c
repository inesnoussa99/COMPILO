// testfiles/140_used_in_while_cond.c
// Variable lue dans une condition while → pas de warning
int main() {
    int n;
    n = 5;
    while (n) n = n - 1;
    return n;
}
// attendu : 0
