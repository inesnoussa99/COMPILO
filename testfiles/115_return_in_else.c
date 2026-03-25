// testfiles/115_return_in_else.c
// return dans les deux branches d'un if/else
int main() {
    int x;
    x = 0;
    if (x) {
        return 1;
    } else {
        return 2;
    }
}
// attendu : 2
