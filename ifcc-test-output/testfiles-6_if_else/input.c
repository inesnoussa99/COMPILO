int main() {
    int a;
    int b;
    int c;
    int res;

    a = 10;
    b = 5;
    c = 20;

    if (a > b) {
        res = 100;
    } else {
        res = 200;
    }

    if (res == 100) {
        if (c < a) {
            res = 1;
        } else {
            int temp;
            temp = 50;
            res = temp;
        }
    } else {
        res = 0;
    }

    return res;
}