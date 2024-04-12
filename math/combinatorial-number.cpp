/*
    组合数
*/

// 1、范围较小时，利用递推公式预处理
int cmn[MAXN][MAXN];
void pre() {
	cmn[0][0] = 1, cmn[0][1] = 0;
	for (int i = 1; i <= 1000; i++) {
		cmn[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			cmn[i][j] = (cmn[i - 1][j] + cmn[i - 1][j - 1]) % MOD;
		}
	}
}

// 2、范围较大时，预处理阶乘和阶乘的逆元（快速幂），每次询问利用定义求