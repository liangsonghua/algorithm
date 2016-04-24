#include<iostream>
#include<vector>
using namespace std;
class OddAppearance {
public:
    vector<int> findOdds(vector<int> arr, int n) {
        // write code here
        //比如出现奇数次的a,b
        //定义ec=0遍历arr依次异或，结果为ec=a^b
        //因为a、b互异，所有ec不等于0，设ec的第k位为1
        //定义变量ec1 = 0;与arr中第k位为1的值进行依次异或，结果ec1 = a或ec =b
        //通过ec^ec1求得别人一个数
        int eO = 0, eOhasOne = 0;
        for (int curNum : arr) {
            eO ^= curNum;
        }
        int rightOne = eO & (~eO + 1);//取反后加1变换符号
        for (int cur : arr) {
            if ((cur & rightOne) != 0) {
                eOhasOne ^= cur;
            }
        }
        int small = Math.min(eOhasOne, (eO ^ eOhasOne));
        int big = Math.max(eOhasOne, (eO ^ eOhasOne));
        return new int[] { small, big };
    }
};