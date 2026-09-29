class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }


    vector<int>prevSmallerEle(vector<int>& pse) {
        int n = pse.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && pse[st.top()]>pse[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
  
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n  = arr.size();
        const long long MOD = 1e9 + 7;
        vector<int> pse = prevSmallerEle(arr);
        vector<int> nse = nextSmallerEle(arr);

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long contribution =
                (1LL * arr[i] * left * right) % MOD;

            ans = (ans + contribution) % MOD;
        }

        return ans;


    }
};