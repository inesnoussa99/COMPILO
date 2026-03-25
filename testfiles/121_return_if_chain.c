// testfiles/121_return_if_chain.c
// chaîne de if/else if simulée avec if/else imbriqués
int classify(int n) {
    if (n < 0) {
        return 0 - 1;
    } else {
        if (n == 0) {
            return 0;
        } else {
            return 1;
        }
    }
}
int main() {
    return classify(5);
}
// attendu : 1
