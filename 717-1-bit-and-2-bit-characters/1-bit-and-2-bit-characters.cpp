class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        bool ans = true;
        for(int i=0;i<n;i++){
            int j = i;
            int cnt = 0;
            ans = true;
            while(j<n && bits[j]==1){
                j++; cnt++;
            }
            if(cnt&1)ans = false;
            i = j;
        }
        return ans;
    }
};