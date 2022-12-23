struct fenwik{
    unordered_map<int, int> t;
    int n = 0;
 
    fenwik(int nn)
    {
        n = nn;
    }
 
    int func(int x, int y){
        return max(x, y);
    }
 
    int func_elem (int r)
    {
        int result = 0;
        for (; r >= 0; r = (r & (r+1)) - 1){
            result = func(result, t[r]);
 
        }
        return result;
    }
 
    void modify (int i, int delta)
    {
        for (; i < n; i = (i | (i+1)))
            t[i] = func(t[i], delta); ///тут очень аккуратно, здесь происходит не изменение, а добавление к элементу при сумме
    }
};
