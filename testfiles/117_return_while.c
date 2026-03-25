// testfiles/117_return_while.c
// return dans une boucle while (sortie anticipée)
int find_first(int n) {
    int i;
    i = 1;
    while (i < n) {
        if (i * i == n) {
            return i;
        }
        i = i + 1;
    }
    return 0 - 1;
}
int main() {
    return find_first(9);
}
// attendu : 3  (3*3 == 9)
