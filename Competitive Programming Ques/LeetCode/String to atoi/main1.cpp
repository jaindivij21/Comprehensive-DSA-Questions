class Solution {
public:
     int myAtoi(string s) {
        int n=s.size();
        int sign=1;
        int i=0;
        while((i<n) && s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            sign=0;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        long int ans=0;
        while((s[i]>='0')&&(s[i]<='9')){
            ans=(ans*10)+(s[i]-'0');
            if(ans<=INT_MIN || ans>=INT_MAX)
                break;
            i++;
        }
        if(sign==0){
            ans=-1*ans;
        }
        if(ans<=INT_MIN){
            return INT_MIN;
        }
        if(ans>=INT_MAX){
            return INT_MAX;
        }
        return ans;
        
    }
};