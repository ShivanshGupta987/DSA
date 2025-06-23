class Solution {
    long long createPalindrome(long long num , bool odd){
        long long x = num;
        if(odd) x/=10;
        while(x>0){
            num = num*10 + x%10;
            x/=10;
        }
        return num;
    }
    
   
    bool isPalindrome(long long num, int k){
        
        string str = "";
        while(num>0){
            str += '0' + (num%k);
            num/=k;
        }
        int i = 0, j = str.size()-1;
        while(i<j){
            if(str[i++]!=str[j--]) return false;
        }
        return true;
    }
    
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        for(long long len=1; n>0; len*=10){
            // inner loop for generating odd digit palindrome
            for(long long num = len; num<len*10 && n>0; num++){
                long long pal = createPalindrome(num, true);
                if(isPalindrome(pal, k)){
                    sum += pal;
                    n--;
                    // cout<<pal<<" ";
                }
            }
            // inner loop for generating even digit palindrome
            for(long long num = len; num<len*10 && n>0; num++){
                long long pal = createPalindrome(num, false);
                if(isPalindrome(pal, k)){
                    sum += pal;
                    // cout<<pal<<" ";
                    n--;
                }
            }
        }
        
        return sum;
    }
};