class Solution {
public:
    int digitProduct(int n){
        if(n < 10)return n;
        int digit = 1;
        while(n > 0){
            digit *= n%10;
            n = n/10;
        }
        return digit;
    }
    int smallestNumber(int n, int t) {
        
        int x = digitProduct(n);
        while(x%t != 0){
            n++;
            x = digitProduct(n);
        }
        return n;
    }
};