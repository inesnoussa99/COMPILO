// testfiles/143_char_const_arithmetic.c
// Constante caractère dans une expression arithmétique
int main() {
    return 'a' - 'A';
}
// attendu : 32 (différence ASCII minuscule/majuscule)
