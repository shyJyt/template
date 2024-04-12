/*
    归并排序，合并过程可以计算逆序对
*/
int a[MAXN], tmp[MAXN];
ll ans = 0;

void msort(int l, int r) {
    if(l == r) return;
    
    int mid = (l + r) >> 1;
    msort(l, mid), msort(mid + 1, r);
    
    // [l, mid], [mid + 1, r] 各自有序
    int i = l, j = mid + 1, k = l;
    
    while (i <= mid && j <= r) {
    	if (a[i] <= a[j]) tmp[k++] = a[i++];
    	else {
    		tmp[k++] = a[j++];
			ans += mid - i + 1;
		}
	}
    	
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    
    for (int p = l; p <= r; p++) a[p] = tmp[p];
}