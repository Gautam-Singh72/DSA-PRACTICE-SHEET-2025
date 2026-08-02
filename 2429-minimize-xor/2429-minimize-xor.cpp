class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsCount=0;
        for(int i=31; i>=0; i--){
            if((num2 >> i) & 1 != 0)    setBitsCount++;
        }

        int x=0;
        int bitCount=0;
        for(int i=31; i>=0; i--){
            int bit=((num1 >> i) & 1) != 0;
            if(bit){
                x+=pow(2, i);
                bitCount++;
            }
        }
        if(bitCount == setBitsCount)    return x;
        if(bitCount > setBitsCount){
            int extraBit=bitCount-setBitsCount;
            for(int i=0; i<32; i++){
                int bit=((x >> i) & 1) != 0;
                if(bit){
                    x=(1 << i) ^ x;
                    extraBit--;
                    if(extraBit == 0)   return x;
                }
            }
        }else{
            int reqBits=setBitsCount-bitCount;
            for(int i=0; i<32; i++){
                int bit=((x >> i) & 1 ) != 0;
                if(!bit){
                    x=(1 << i) ^ x;
                    reqBits--;
                    if(reqBits==0)  return x;
                }
            }
        }

        return x;
    }
};