class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        if(n==0)    return 0;
        int start=0;
        while(start<n && s[start]==' '){
            start++;
        }
        if(start==n)    return 0;
        bool negative=false;
        if(s[start]=='-'){
            negative=true;
        }
        int end=(s[start]=='+' || s[start]=='-') ? start+1 : start;
        while(end<n && s[end]-'0'>=0 && s[end]-'0'<=9)  end++;

        string temp=s.substr(start, end-start);
        // cout<<"["<<temp<<"]"<<endl;
        if(temp.empty())    return 0;
        int j=(temp[0]=='-' || temp[0]=='+') ? 1 : 0;
        while(j<temp.size() && temp[j]=='0')    j++;
        if(temp.size()-j>13 && negative)  return INT_MIN;
        if(temp.size()-j>12 && !negative) return INT_MAX;
        long long res=0;
        long long mul=1;
        for(int i=temp.size()-1; i>=j; i--){
            if(i==0 && (temp[i]=='-' || temp[i]=='+'))    continue;
            res+=(temp[i]-'0')*mul;
            mul*=10;
        }
        if(negative){
            res*=-1;
        }
        if(res>INT_MAX) return INT_MAX;
        if(res<INT_MIN) return INT_MIN;
        return (int)res;
    }
};