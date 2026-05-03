class Solution {
public:
    int rotatedDigits(int n) {
        int count=0;
        for(int k=1; k<=n; k++){
            int num=k;
            bool flag=true;
            int cnt1=0, cnt2=0;
            while(num>0){
                int digit=num%10;
                if(digit==0 || digit==1 || digit==8){
                    cnt1++;
                }else if(digit==2 || digit==5 || digit==6 || digit==9){
                    cnt2++;
                }else{
                    flag=false;
                    break;
                }
                num/=10;
            }
            if(flag && cnt2)    count++;
        }
        return count;
    }
};