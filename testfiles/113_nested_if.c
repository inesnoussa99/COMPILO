// testfiles/113_nested_if.c
// if imbriqué
int main() {
    int x;
    int y;
    x = 2;
    y = 0;
    if (x > 0) {
        if (x > 1) {
            y = 42;
        }
    }
    return y;
}
// attendu : 42
