// testfiles/138_used_in_return.c
// Variable lue dans return → pas de warning
int main() {
    int x;
    x = 7;
    return x;
}
// attendu : 7
