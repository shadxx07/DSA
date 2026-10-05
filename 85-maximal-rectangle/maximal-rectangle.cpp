class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {

            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] >= currHeight) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // Vertical prefix sum
        vector<vector<int>> pSum(n, vector<int>(m, 0));

        // Calculate consecutive 1s column-wise
        for (int j = 0; j < m; j++) {

            int sum = 0;

            for (int i = 0; i < n; i++) {

                if (matrix[i][j] == '0')
                    sum = 0;
                else
                    sum++;

                pSum[i][j] = sum;
            }
        }

        int maxArea = 0;

        // Every row becomes a histogram
        for (int i = 0; i < n; i++) {

            maxArea = max(maxArea,
                          largestRectangleArea(pSum[i]));
        }

        return maxArea;
    }
};