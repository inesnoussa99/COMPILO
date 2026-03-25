// testfiles/106_if_simple.c
// if simple : condition vraie
int main() {
    int x;
    x = 0;
    if (1) x = 42;
    return x;
}
// attendu : 42
