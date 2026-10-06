class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int x : num){
            while(!st.empty() && k>0 && st.top() > x){
                st.pop();
                k--;
            }
            st.push(x);
        }
        while(k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        while(res.size()!=0 && res.back() == '0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.empty()) return "0";
        return res;
    }
};