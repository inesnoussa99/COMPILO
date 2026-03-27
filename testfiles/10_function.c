// 1. 测试短路逻辑的“护身符”效应
int safety_check(int x, int y) {
    // 奇葩点：如果 y 是 0，正常程序会崩溃。
    // 但因为 && 的短路特性，右边的 (x / y) 永远不应该被执行。
    // 这考验编译器的 Operation::jmp_if_zero 是否真的跳过了右侧 IR 生成。
    return (y != 0) && (x / y > 0);
}

// 2. 测试布尔值的“算术化”
int weight_sum(int a, int b) {
    // 奇葩点：一般人写 if (a > b) return a;
    // 我们用：(a > b) 产生的 0 或 1 直接参与乘法。
    // 考验编译器对 RelationalExpr 结果（%al -> %eax）的转换处理。
    int res;
    res = (a > b) * a + (a <= b) * b;
    return res;
}

int main() {
    int x; x = 0;
    int y; y = 42;

    // 3. 俄罗斯套娃作用域 (Ghosting)
    int target;
    target = 1;
    {
        int target; target = 10;
        {
            int target; target = 100;
            x = target; // 应该是 100
        }
        x = x + target; // 100 + 10 = 110
    }
    x = x + target; // 110 + 1 = 111

    // 4. 深度递归 + 逻辑陷阱
    // 如果编译器不老实，先算右边，那么 (1 / 0) 会让你的程序直接报 SIGFPE 崩溃。
    int bomb;
    int zero; 
    zero = 0;
    
    // 终极考验：|| 的左边为真 (1)，右边的除以 zero 绝对不能执行！
    if (weight_sum(y, x) > 0 || (1 / zero == 0)) {
        int arr[2];
        int idx;
        idx = safety_check(10, 0); // 返回 0
        arr[idx] = x;              // arr[0] = 111
        return arr[0] - 11;        // 预期返回 100
    }

    return -1;
}