struct kitai{
    static int get_a(vi divs, vi ost){
        int ans = 0; int proiz = 1;
        for (int i = 0; i < ost.size(); ++i){
            int n1 = proiz;
            int n2 = divs[i];
            int a1 = ans;
            int a2 = ost[i];
            int a = n1;
            int b = -n2;
            int c = a2 - a1;
            int x = 0, y = 0, g = 0;
            diofant::find_any_solution(a, b, c, x, y, g);
            ans = a1 + x * n1;
            proiz = proiz * divs[i];
        }
        return ans;
    }
};
