// testfiles/128_undecl_out_of_scope.c
// Variable utilisée après la fermeture de son bloc → erreur
int main() {
    {
        int local;
        local = 42;
    }
    return local;
}
