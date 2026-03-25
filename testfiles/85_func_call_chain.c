// testfiles/85_func_call_chain.c
// Appel enchaîné de fonctions
int square(int x) {
    return x * x;
}
int add(int a, int b) {
    return a + b;
}
int main() {
    return add(square(3), square(4));
}
// attendu : 25  (9 + 16)
