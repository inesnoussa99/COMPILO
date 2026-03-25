// testfiles/90_call_too_few_args.c
// Trop peu d'arguments → doit être rejeté
int add(int a, int b) {
    return a + b;
}
int main() {
    return add(1);
}
