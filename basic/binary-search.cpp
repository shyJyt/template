/*
    二分的前提一定是问题单调，必须确保。

    一对常用的库函数，可以处理数组、vector等，返回的是地址 / 迭代器

    a 单增时：
        第一个大于等于 x 的元素位置
        int pos1 = lower_bound(a + 1, a + 1 + n, x) - a;
        第一个大于 x 的
        int pos2 = upper_bound(a + 1, a + 1 + n, x) - a;

    a 单减时，需要修改默认的比较器
        第一个小于等于 x 的元素位置
        int pos1 = lower_bound(a + 1, a + 1 + n, x, greater<int>()) - a;
        第一个小于 x 的
        int pos2 = upper_bound(a + 1, a + 1 + n, x, greater<int>()) - a;

    总之，[pos1, pos2) 之间的元素均等于 x ，或者说这是 x 可以插入的范围

    对于不支持随机访问的有序容器，比如 set 需要使用 set.lower_bound()，且无法得到类似偏移量的东西。
*/

bool cheak(int x) {
    return true;
}

void solve() {
    int l = 1, r = n;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
            // r = mid + 1;
        }
        else {
            r = mid - 1;
            // l = mid - 1;
        }
    }

    // 分别考虑答案在 l, r 处，跳出循环时 l, r 谁指向答案
    // 考虑是否需要进一步的 check 或者出现越界
    cout << r << '\n';
}