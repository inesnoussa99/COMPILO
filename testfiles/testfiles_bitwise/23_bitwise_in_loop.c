int main() {
    int acc = 0;
    int i = 1;
    while (i < 5) {
        acc = acc | i;
        i = i + 1;
    }
    return acc;
}
