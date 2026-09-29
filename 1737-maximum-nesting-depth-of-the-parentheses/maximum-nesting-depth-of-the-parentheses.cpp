class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int count  = 0;
        int countmax = 0;
        for(char ch:s){
            if(ch == '('){
                st.push(ch);
                count++;
                countmax = max(count,countmax);
            }
            else if(ch == ')'){
                st.pop();
                count--;
            }
        }
        return countmax;
    }
};