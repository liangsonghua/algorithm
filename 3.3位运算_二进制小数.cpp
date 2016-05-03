#include<iostream>
#include<string>
using namespace std;
class BinDecimal {
public:
    string printBin(double num) {
        // write code here
       //乘二取整，顺序排列
       string res = doubleToBinary(num);
       if(res.length()>32){
           return "Error";
       }else{
           return "0."+res;
       }
    }
public:
    static string doubleToBinary(double num)
    {
       string str = "";
       if(num*2==0.0)return 0+"";
       if(num*2>1)
       {
           str = "1"+doubleToBinary(num*2-1);
       }
        else if(num*2==1)
        {
            return "1";
        }
        else{
            str = "0"+doubleToBinary(num*2);
        }
        return str;
    }
};