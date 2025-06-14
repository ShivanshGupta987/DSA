class Solution {
public:
    int minMaxDifference(int num) {
        // candidate digit to be replaced in case of creating smallest number

        string s = to_string(num);
        char a = s[0];  
        for(int i=0;s[i];i++){
            if(s[i]==a)s[i] = '0';
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