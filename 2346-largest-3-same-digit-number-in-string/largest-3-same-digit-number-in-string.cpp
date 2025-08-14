class Solution {
    // TC : O(N)
    // SC : O(1)
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int maxx = -1;
        for(int i=2;i<n;i++){
            if(num[i]==num[i-1] && num[i]==num[i-2]){
                maxx = max(maxx, num[i]-'0');
            }
        }
        if(maxx==-1) return "";
        else return string(3, maxx+'0');
    }
};