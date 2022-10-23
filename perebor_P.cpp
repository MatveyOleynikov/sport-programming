struct perebor_P{
    int calc(vi& a){
        return 0;
    }

    int P(int n, int k, vi& a, vi& us){
        if (n == k){
            return calc(a);
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
