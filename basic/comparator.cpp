// 0、尽量利用默认的比较器，比如说用 pair 代替简单的结构体，默认按 first 升序
// 但 pair 只能通过 first, second 获取成员变量，也舍弃了一定的语义可读性

// 1、允许提供自定义比较函数，比如 sort(), lower_bound() 的最后一个参数
// C++ 规定比较函数在两参数相等时必须返回 false，也就是说比较时不能带上等于号
bool cmp(node x, node y) {
    // 错误写法：return x.v <= y.v 
    return x.v < y.v
}

// 2、不能用到自定义的比较函数，比如说优先队列的最后一个构造参数，需要重载运算符
struct node {
    int id;
};

bool operator<(node a, node b) {
    return a.id < b.id;
}
