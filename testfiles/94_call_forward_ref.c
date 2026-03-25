// testfiles/94_call_forward_ref.c
// Référence en avant : main appelle helper défini après
int helper(int x) {
    return x * 2;
}
int main() {
    return helper(21);
}
// attendu : 42
