class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> result(n, 0);
        result[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i < n; i++){
            result[i] = min(min(result[p2]*2, result[p3]*3), result[p5]*5);
            if(result[i] == result[p2]*2) p2++;
            if(result[i] == result[p3]*3) p3++;
            if(result[i] == result[p5]*5) p5++;
        }
        return result[n-1];
    }
};
