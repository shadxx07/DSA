class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        unordered_map<int, int> mp;

        long long sum = 0;
        long long count = 0;
        int MOD = 1e9 + 7;

        mp[0] = 1;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            int parity = sum % 2;

            count = (count + mp[1 - parity]) % MOD;

            mp[parity]++;
        }

        return count;
    }
};