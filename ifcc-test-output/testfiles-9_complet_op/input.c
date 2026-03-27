int main() {
    int a;
    int b;
    int c;
    int res;
    int arr[10];
    int results[2];

    a = 15;
    b = 4;
    c = 2;

    // 1. 复杂算术与位运算组合：测试寄存器分配压力与算术优先级
    // 计算：(15 * 4 + (2 << 3)) ^ (~(15 / 2) & 255) | (100 >> 1)
    // 预期：(60 + 16) ^ (~7 & 255) | 50 => 76 ^ 248 | 50
    res = (a * b + (c << 3)) ^ (~(a / c) & 255) | (100 >> 1);

    // 2. 数组深度操作：使用数组的值作为另一个数组的索引
    arr[0] = 1;
    arr[1] = 5;
    arr[2] = 8;
    arr[arr[0]] = a + b;           // arr[1] = 19
    arr[arr[1] - 17] = arr[2] * c; // arr[2] = 16

    // 3. 嵌套块与变量作用域（Shadowing）：测试栈帧偏移管理
    {
        int a; 
        int inner_res;
        a = 100;
        inner_res = a / 2; // 50
        res = res + inner_res;
        {
            int b;
            b = 1000;
            res = res - b + a; // 在此处 a 是 100，b 是 1000
        }
        // inner_res 离开作用域
    }
    // 外部的 a 应该恢复为 15

    // 4. 复杂的逻辑嵌套：测试条件跳转指令的生成
    if (a > b && (c == 2 || res < 0)) {
        if (!(res == 0)) {
            results[0] = 42;
        } else {
            results[0] = 0;
        }
    } else {
        results[0] = 1;
    }

    // 5. 混合逻辑与位运算作为表达式
    // 测试表达式作为 return 语句的一部分
    results[1] = (a != b) ^ (c <= 10) & (res > 100);

    // 最终返回：确保所有计算结果都参与运算，防止被优化掉（如果你的编译器有优化的话）
    return (results[0] + results[1] + arr[2]) * (a - 14);
}