class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int maxx = 0;
        for(int i = 0;i<arr.size();i++){
            maxx= max(arr[i],maxx);
            if(i==maxx)count++;
        }
        return count;
    }
};