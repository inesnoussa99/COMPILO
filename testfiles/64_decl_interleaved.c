// testfiles/64_decl_interleaved.c
// Déclarations entrelacées avec des affectations
int main() {
    int a;
    a = 1;
    int b;
    b = 2;
    int c;
    c = 3;
    return a + b + c;
}
// attendu : 6
