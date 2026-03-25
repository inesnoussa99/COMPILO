// testfiles/91_call_too_many_args.c
// Trop d'arguments → doit être rejeté
int inc(int x) {
    return x + 1;
}
int main() {
    return inc(1, 2, 3);
}
