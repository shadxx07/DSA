class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        long long num = x;
        int sign = 1;
        if(num<0){
            num = -num;
            sign = -sign;
        }
        while(num>0){
            int digit = num%10;
            ans = ans*10 + digit;
            num = num/10;
        }
        if(sign == -1)ans*=sign;

        if(ans>=INT_MIN && ans<=INT_MAX){
            return ans;
        }
        else{
            return 0;
        }
        return ans;
    }  
};