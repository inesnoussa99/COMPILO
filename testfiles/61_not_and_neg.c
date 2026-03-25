// testfiles/61_not_and_neg.c
int main() {
    int a;
    a = 0;
    return -(!a);
}
// attendu : 255  (-1 en unsigned byte = 255)
