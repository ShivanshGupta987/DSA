class Solution {
public:
    int maxDiff(int num) {
        // candidate digit to be replaced in case of creating smallest number

        string s = to_string(num);
        char a = '*';
        char target = '*';
        char first_char = s[0];
        int n = s.size();
        int i = 0;
        while(s[i]<='1' && i<n){
                i++;
        }
        if(i<n) target = s[i];
        for(;s[i];i++){
            if(s[i]==target) s[i] = (s[i]==first_char?'1':'0');  
        }
        int mini = stoi(s);
        
        
        s = to_string(num);
        // candidate digit to be replaced in case of creating smallest number
        char b = '*';
        for(int i=0;s[i];i++){
            if(b=='*'){
                if(s[i]<'9'){
                    b = s[i];
                    s[i] ='9';
                } 
                else continue;
            }
            else if(s[i]==b) s[i] = '9';
        }
        int maxi = stoi(s);
        cout<<maxi<<" "<<mini;
        return maxi-mini;
        
    }
};