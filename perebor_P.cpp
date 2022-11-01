struct perebor_P{
    static int calc_mas(vi &b){
        return 0;
    }
    /// можно переписывать
    static int calc(vi& per, vi &a){
        vi b;
        for (int i = 0; i < per.size(); ++i){
            b.push_back(a[per[i]]);
        }

        return calc_mas(b);;
    }

    static int P(int n, int k, vi& a, vi& us){
        if (n == k){
            return calc(a, our);
        }

        int res = 0;

        for (int i = 0; i < n; ++i){
            if (!us[i]){
                us[i] = 1;
                a.push_back(i);
                P(n, k + 1, a, us);
                us[i] = 0;
                a.pop_back();
            }
        }

        return res;
    }
};
