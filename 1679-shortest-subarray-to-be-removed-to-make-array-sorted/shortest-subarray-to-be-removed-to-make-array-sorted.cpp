class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        // Find sorted prefix
        int left = n - 1;

        for(int i = 1; i < n; i++) {
            if(arr[i - 1] > arr[i]) {
                left = i - 1;
                break;
            }
        }

        if(left == n - 1)
            return 0;

        // Find sorted suffix
        int right = n - 1;

        for(int j = n - 1; j > 0; j--) {
            if(arr[j] < arr[j - 1]) {
                right = j;
                break;
            }
        }

     
        int ans = min(n - left - 1, right);

        int i = 0;
        int j = right;

        while(i <= left && j < n) {
            if(arr[i] <= arr[j]) {
                ans = min(ans, j - i - 1);
                i++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};