class Solution {
    // TC : O(N)
public:
    string makeFancyString(string s) {
        string str = "";
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n; i++){
            if(i && s[i]==s[i-1]){
                cnt++;
            }
            else cnt = 1;
            if(cnt>2) continue;
            str += s[i];
            
        }
        return str;
    }
};