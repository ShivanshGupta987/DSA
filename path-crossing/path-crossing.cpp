class Solution {
public:
    bool isPathCrossing(string s) {
        vector<pair<int,int>>cood;
            cood.push_back({0,0});
            for(int i=0;s[i];i++){
                  auto it=cood.end()-1;  
                 int prev_x=it->first;
                 int prev_y=it->second;
                 int x,y;
                 if(s[i]=='N'){x=prev_x;y=prev_y+1;}
                 if(s[i]=='E'){x=prev_x+1;y=prev_y;}
                 if(s[i]=='W'){x=prev_x-1;y=prev_y;}
                 if(s[i]=='S'){x=prev_x;y=prev_y-1;}
                 for(auto &[a,b]:cood){
                         if(a==x && b==y)return true;
                }
                cood.push_back({x,y});
            }
            return false;
    }
};