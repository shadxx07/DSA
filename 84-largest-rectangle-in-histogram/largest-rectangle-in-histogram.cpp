class Solution {
public:
    vector<int>PSE(vector<int>& nums){
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i =0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
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
    vector<int>NSE(vector<int>& nums){
        int n  = nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] =n;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
           
        }
         return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>pse = PSE(heights);
        vector<int>nse = NSE(heights);
        int maxi = 0;
        for(int i = 0;i<n;i++){
            maxi = max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};