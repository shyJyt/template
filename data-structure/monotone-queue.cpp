/*
    单调队列
    借助 deque 实现，方便对队首和队尾进行操作
    维护当前位置之前一段范围内的最值下标，排除过期元素后队首即为有效元素中的最值下标，后续元素为将来可能成为最值的元素下标
    注意是下标而不是值，因为需要下标信息来判断是否过期

    单调栈
    相较于单调队列删除了有效期的概念，不会移出队首元素

    还有另外一种前缀数组 pre[i] = max(pre[i - 1], a[i])，这样维护的是当前位置之前所有数的最值
*/

void monotone() {
    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && a[dq.back()] <= a[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        // 如果是单调栈，就不用下面几行
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
    }
}