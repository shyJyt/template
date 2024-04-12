/*
    埃氏筛
*/

bool vis[MAXN];
// 最小质因数
int minpd[MAXN];

void sieve() {
	for (int i = 2; i < MAXN; i++) {
		if (!vis[i]) {
        	minpd[i] = i;
	        for (int j = i + i; j < MAXN; j += i) {
		    	if(!vis[j]) {
		    		vis[j] = 1, minpd[j] = i;
				}
		    }  
	    }
	}
}