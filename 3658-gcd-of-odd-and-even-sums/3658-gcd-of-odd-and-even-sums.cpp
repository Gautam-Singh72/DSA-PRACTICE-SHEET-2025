class Solution {
public:

    int gcd(int a, int b){ // log(min(a, b))
        while(a>0 && b>0){
            if(a>b){
                a=a%b;
                continue;
            }
            b=b%a;
        }
        return a==0 ? b : a;
    }
    //T.C->O(log(min(a, b)))
    //S.C->O(1) 
    int gcdOfOddEvenSums(int n) {
        
        int oddSum=n*n; //O(1)
        int evenSum=n*(n+1); //O(1)

        return gcd(oddSum, evenSum); 
    }
};