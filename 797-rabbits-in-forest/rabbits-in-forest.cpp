class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        int cnt[1001];
        memset(cnt, 0, sizeof cnt);
        int zeros = 0;
        for(int i=0;i<answers.size();i++){
            cnt[answers[i]]++ ;
            if(answers[i]==0)zeros++;
        }
        for(int i=1;i<1001;i++){
            if(cnt[i]==0)continue;
            ans += ((i+1)*(cnt[i]/(i+1)))  + ((cnt[i]%(i+1))!=0 ? i+1:0);
            
        }
        return ans+zeros;
    }
};