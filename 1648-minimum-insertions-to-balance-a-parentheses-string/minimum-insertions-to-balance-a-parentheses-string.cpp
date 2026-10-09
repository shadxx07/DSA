class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                open++;
            }
            else {
                // No '(' available for this ')'
                if (open == 0) {
                    ans++;
                    open++;
                }

                // We have a pair ))
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;          // consume second ')'
                }
                else {
                    // Only one ')' available, insert another ')'
                    ans++;
                }

                // One '(' is completely satisfied
                open--;
            }
        }

        // Every remaining '(' needs two ')'
        ans += 2 * open;

        return ans;
    }
};