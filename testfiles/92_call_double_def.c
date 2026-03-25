// testfiles/92_call_double_def.c
// Définition double de fonction → doit être rejeté
int foo() { return 1; }
int foo() { return 2; }
int main() { return foo(); }
