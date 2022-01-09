class Solution {
        private:
        
        int rec(string &s,int i,vector<int>&mem){
             if(mem[i]>-1) return mem[i]; 
             if(s[i]=='0')return mem[i]=0;
                
          int res=rec(s,i+1,mem);
        
        if(i<s.size()-1){
                int num=stoi(s.substr(i,2));
                if(num>9 && num<27)res+=rec(s,i+2,mem);
        }
                return mem[i]=res;
                
                
        }
public:
    int numDecodings(string s) {
             int n=s.size();
            vector<int>mem(n+1,-1);
            mem[n]=1;
     return s.empty()?0:rec(s,0,mem);
            
    }
};