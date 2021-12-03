#define ll long long int
class Solution {
private:
        const ll mod = 1e9+7;
        ll notPrime[10000+100];
        ll fact[10000+100];
void sieve(){
        notPrime[1]=1;
        for(int i=2;i<=10000+50;i++){
                if(!notPrime[i]){
                        for(int j=2*i;j<=10000+50;j+=i)
                                notPrime[j]=1;
                }
        }
}    

unsigned ll modExpo(ll n,ll r){
  if(r==0)return 1;
  if(r&1)return (n*modExpo(n*n %mod,r/2) %mod);
  else return (modExpo(n*n %mod,r/2) %mod);
}

unsigned ll invMod(ll n){
        return modExpo(n,mod-2);
}

void facto(){
        fact[0]=1;
        for(int i=1;i<=10000+50;i++){
                fact[i]=fact[i-1]*i % mod;
        }
}
        
ll nCr(ll n, ll r){
        if(n<r)return 0;
        if(r==0)return 1;
        return (fact[n]*invMod(fact[r]) % mod *invMod(fact[n-r] % mod)) % mod;
}
        
        
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
            vector<int>ans;
            sieve();
            facto();
        int s=queries.size();
           for(int i=0;i<s;i++){
                   int n=queries[i][0];
                   int k=queries[i][1];
                   int sol=1;
                   for(int i=1;i<=k;i++){
                           if(notPrime[i]==0){
                                   int count=0;
                                   while(k%i==0)
                                   {
                                      count++; 
                                      k=k/i;
                                   }
                               sol = sol * nCr(n+count-1,count) % mod;    
                           }
                   }
                   ans.push_back(sol);

           }
          return ans;  
    }
};