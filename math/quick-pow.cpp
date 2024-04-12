/*
    快速幂，常用于求模意义下的乘法逆元
    对于 x ，其乘法逆元为 qpow(x, MOD - 2LL);
*/
ll qpow(ll base, ll power) {
    ll res = 1LL;
    while (power) {
        if (power & 1LL) {
            res = (res * base) % MOD;
        }
        power >>= 1;
        base = (base * base) % MOD;
    }
    return res;
}