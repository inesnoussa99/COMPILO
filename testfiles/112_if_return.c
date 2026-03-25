// testfiles/112_if_return.c
// return dans une branche if
int main() {
    int x;
    x = 3;
    if (x > 2) {
        return 1;
    }
    return 0;
}
// attendu : 1
