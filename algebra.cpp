namespace algebra {
    //int mas = 1e6 + 1; /// важно чекнуть mas
    //int mod = 998244353; /// важно чекнуть модуль

    int add(const int a, const int b) {
        if (a + b < mod) {
            return a + b;
        }
        return a + b - mod;
    }

    int mns(const int a, const int b) {
        if (a >= b) {
            return a - b;
        }
        return a - b + mod;
    }

    int mul(const int a, const int b) {
        return a * b % mod;
    }

    int binpow(const int n, const int k) {
        if (k == 0) {
            return 1;
        }
        if (k % 2 == 1) {
            return mul(n, binpow(n, k - 1));

        }
        return binpow(mul(n, n), k / 2);
    }

    int div(const int a, const int b) {
        return mul(a, binpow(b, mod - 2));
    }

    vector<int> calc_fac() {
        vector<int> fac(mas + 1);
        fac[0] = 1;
        for (long long i = 1; i <= mas; ++i) {
            fac[i] = mul(i, fac[i - 1]);
        }
        return fac;
    }

    int fac(int n) {
        static vector<int> fac = calc_fac();
        return fac[n];
    }

    vector<int> calc_ifac() {
        vector<int> fac(mas + 1);
        fac[0] = 1;
        for (long long i = 1; i <= mas; ++i) {
            fac[i] = mul(fac[i - 1], div(1, i));
        }
        return fac;
    }

    int ifac(int n) {
        static vector<int> ifac = calc_ifac();
        return ifac[n];
    }

    int C(int n, int k) {
        return fac(n) * ifac(k) * ifac(n - k);
    }

    int P(int n) {
        return fac(n);
    }

    int A(int n, int k) {
        return fac(n) * ifac(n - k);
    }
};

using namespace algebra;
