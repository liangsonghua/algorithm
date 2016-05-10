#include <iostream>
#include <vector>
using namespace std;
class FoldPaper {
public:
    vector<string> foldPaper(int n) {
       vector<string> ret;
       fold(1,n,true,ret);
       return ret;
    }
    void fold(int i,int N,bool down,vector<string> &ret)
    {
        if(i>N) return ;
        fold(i+1,N,true,ret);
        ret.push_back(down?"down":"up");
        fold(i+1,N,false,ret);
    }
};