class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        if(n==1) return str;
        while(n>1){
            string  temp = "";
            int sz = str.size();
            for(int i=0;i<sz;i++){
                int cnt = 1;
                int j = i;
                while(j+1<sz && str[j]==str[j+1]){
                    cnt++; j++;
                }
                temp += '0'+cnt;
                temp += str[i];
                i = j;
            }
            str = temp;
            n--;
        }
        return str;
    }
};