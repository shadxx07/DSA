class Solution {
public:
    vector<int>NSE(vector<int>nums){
        int n  = nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
               ans[i] = n;
            }
            else{
                ans[i] =st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int>PSE(vector<int>nums){
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] =-1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int>NGE(vector<int>nums){
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;
        
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }
            else{
                ans[i] =st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int>PGE(vector<int>nums){
        int n  = nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i = 0;i<n;i++){
            while(!st.empty()  && nums[st.top()]< nums[i]){
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
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>pse = PSE(nums);
        vector<int>nse = NSE(nums);
        vector<int>pge = PGE(nums);
        vector<int>nge = NGE(nums);
        long long  sum1 = 0;
        long long sum2 = 0;
        
        for(int i = 0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            long long contribution = 1LL* nums[i]*left*right;
            sum1+=contribution;

            int lef = i - pge[i];
            int righ = nge[i] - i;
            long long cntribution = 1LL* nums[i]*lef*righ;
            sum2+=cntribution;
        }
        long long ans = sum2 -sum1;
        return ans; 
    }
};