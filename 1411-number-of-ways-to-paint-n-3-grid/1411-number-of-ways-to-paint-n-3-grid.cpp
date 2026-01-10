class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1000000007;
        long long typeA = 6;
        long long typeB = 6;
        for (int i = 1; i < n; ++i) {
            long long newTypeA = (typeA * 3 + typeB * 2) % MOD;
            long long newTypeB = (typeA * 2 + typeB * 2) % MOD;

            typeA = newTypeA;
            typeB = newTypeB;
        }
        return (typeA + typeB) % MOD;
    }
};