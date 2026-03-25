// testfiles/114_while_countdown.c
// while : compte à rebours, retourne la valeur finale
int main() {
    int n;
    n = 10;
    while (n > 0) {
        n = n - 1;
    }
    return n;
}
// attendu : 0
