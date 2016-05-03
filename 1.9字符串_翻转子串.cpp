#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        if(size1 == 0 || size2 == 0){
            return false;
        }
        if(size1 != size2){
            return false;
        }
        string str = s1 + s1;
        if(str.find(s2) == -1){
            return false;
        }
        return true;
    }
};