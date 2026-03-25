// testfiles/122_return_while_accumulate.c
// return après une boucle while
int sum_up_to(int n) {
    int s;
    int i;
    s = 0;
    i = 1;
    while (i < n + 1) {
        s = s + i;
        i = i + 1;
    }
    return s;
}
int main() {
    return sum_up_to(10);
}
// attendu : 55
