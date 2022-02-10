class Solution {
        // TC: O(k) 
        // k-> no. of valid permutations
        // SC: O(n)
        int count;
        void bt(vector<int>&v,int ind,int n){
                if(ind==n){count++;return;}
                
                for(int i=ind;i<n;i++){
                         swap(v[ind],v[i]);
    if((ind+1)% v[ind]==0 || v[ind]%(ind+1)==0)bt(v,ind+1,n);     
                         swap(v[ind],v[i]);
                }
        }
public:
    int countArrangement(int n) {
        count =0;
            vector<int>v;
            for(int i=0;i<n;i++)v.push_back(i+1);
            bt(v,0,n);
            return count;
    }
};