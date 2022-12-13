struct fenwik{
    unordered_map<int, int> t;
    int n = 0;
 
    fenwik(int nn)
    {
        n = nn;
    }
 
    int sum_elem (int r)
    {
        int result = 0;
        for (; r >= 0; r = (r & (r+1)) - 1)
            result += t[r];
        return result;
    }
 
    void inc (int i, int delta)
    {
        for (; i < n; i = (i | (i+1)))
            t[i] += delta;
    }
 
    int sum_otr (int l, int r)
    {
        return sum_elem (r) - sum_elem (l-1);
    }
};
 
