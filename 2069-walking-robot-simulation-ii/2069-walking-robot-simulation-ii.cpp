class Robot {
public:
    int x=0, y=0;
    char dir='E';
    int p, q, k;
    Robot(int width, int height) {
        p=width-1;
        q=height-1;
        k=(p+q)*2;
    }
    
    void step(int num) {
        num=num%(k);
        if(num==0 && x==0 && y==0)  dir='S';
        while(num>0){
            if(dir=='E'){
                if(x+num>p){ 
                    int steps=p-x;
                    x=x+steps;
                    num-=steps;
                    dir='N';
                }else{
                    x+=num;
                    num=0;
                }  
            }else if(dir=='N'){
                if(y+num>q){
                    int steps=q-y;
                    y+=steps;
                    num-=steps;
                    dir='W';
                }  
                else{
                    y+=num;
                    num=0;
                }
            }else if(dir=='W'){
                if(x-num<0){
                    int steps=x;
                    x-=steps;
                    num-=steps;
                    dir='S';
                }
                else{
                    x-=num;
                    num=0;
                } 
            }else{
                if(y-num<0){
                    int steps=y;
                    y-=steps;
                    num-=steps;
                    dir='E';
                }
                else{
                    y-=num;
                    num=0;
                } 
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if(dir=='E')    return "East";
        else if(dir=='W')   return "West";
        else if(dir=='N')   return "North";
        else    return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */