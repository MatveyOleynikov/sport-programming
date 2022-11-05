struct perebor_C{
    static int calc(vi& a){
        return 0;
    }

    static int C(int n, int k, vi& a){
        if (n == k){
            return calc(a);
        }

        int res = 0;

        a.push_back(0);
        res = max(res, C(n, k + 1, a));
        a.pop_back();

        a.push_back(1);
        res = max(res, C(n, k + 1, a));
        a.pop_back();
        
        return res;
    }
};
