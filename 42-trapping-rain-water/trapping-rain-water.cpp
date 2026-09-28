class Solution {
public:
    int trap(vector<int>& height) {
        int n  = height.size();
        int left = 0;
        int leftMax = 0;
        int rightMax =0;
        int right = n-1;
        int Total = 0;
        while(left<right){
            if(height[left]<=height[right]){
                if(leftMax>height[left]){
                    Total+=leftMax-height[left];
                }
                else{
                    leftMax =  height[left];
                }
                left++;
            }
            
            else{
                if(rightMax>height[right]){
                    Total+=rightMax-height[right];
                }
                else{
                    rightMax = height[right];
                }
                right--;
            }
        }
        return Total;

    }
};