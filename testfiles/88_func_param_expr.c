// testfiles/88_func_param_expr.c
// Expression comme argument de fonction
int inc(int x) {
    return x + 1;
}
int main() {
    int a;
    a = 10;
    return inc(a * 4 - 1);
}
// attendu : 40  (10*4-1=39, 39+1=40)
