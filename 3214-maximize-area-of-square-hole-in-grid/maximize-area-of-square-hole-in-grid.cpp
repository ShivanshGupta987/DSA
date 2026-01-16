class Solution {
    // TC : O(H log H + V log V)
    // WHERE, H : hBars.size()
    // V : vBars.size()
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int cnt1 = 0, cnt2 = 0;
        int cur1=0, cur2=0;
        int hsz = hBars.size(), vsz = vBars.size();
        for(int i=0;i<hsz;i++){
            if(hBars[0]==1) continue;
            else if(i==0)cur1++;
            else if(hBars[i]==n+2){}
            else if(hBars[i-1]+1==hBars[i]){
                cur1++;
            }
            else{
                cur1 = 1;
            }
            cnt1 = max(cnt1, cur1);
        }

        for(int i=0;i<vsz;i++){
            if(vBars[0]==1) continue;
            else if(i==0)cur2++;
            else if(vBars[i]==m+2){}
            else if(vBars[i-1]+1==vBars[i]){
                cur2++;
            }
            else{
                cur2 = 1;
            }
            cnt2 = max(cnt2, cur2);
        }
        int side = min(cnt1+1, cnt2+1);
        return side*side;
    }
};