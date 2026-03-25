// testfiles/116_early_return.c
// return anticipé : la valeur renvoyée est celle du return, pas du bas de fonction
int abs_val(int n) {
    if (n < 0) {
        return 0 - n;
    }
    return n;
}
int main() {
    return abs_val(0 - 7);
}
// attendu : 7
