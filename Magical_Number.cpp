class Solution {
public:
    const int MOD = 1e9+7;
    int nthMagicalNumber(int N, int A, int B) {
        long LCM = lcm(A, B), L = min(A, B), R = N*L, mid, ans;
        auto magicNumbersLessEqual = [&](long x) { return (x/A) + (x/B) - (x/LCM); };
        while(L <= R) {
            mid = L + (R-L) / 2;
            if(magicNumbersLessEqual(mid) < N) L = mid + 1; 
            else R = mid - 1, ans = mid;           
        }
        return ans % MOD;
    }
};