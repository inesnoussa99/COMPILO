// testfiles/132_double_decl_list.c
// Double déclaration dans une liste "int a, a;" → erreur
int main() {
    int a, a;
    return a;
}
