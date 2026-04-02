int collatz_steps(int n) {
    int steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = n * 3 + 1;
        }
        steps = steps + 1;
    }
    return steps;
}

int max_steps(int limite) {
    int max = 0;
    int best = 0;
    int n = 1;
    while (n <= limite) {
        int s = collatz_steps(n);
        if (s > max) {
            max = s;
            best = n;
        }
        n = n + 1;
    }
    return best;
}

int main() {
    return max_steps(100);
}
