#include<iostream>
using namespace std;
int query(string s,string t)
{
    //用还钱来解释 remain表示还欠多少，有效归还才自减
    //right表示继续还款
    //left表示多还的能收回多少
    /*
    比如s=aabbcdcba t=abc
    */
    int remain = t.size();
    int map[256]={0};
    int left = 0,right = 0,len=0x7ffffff;
    for(int i=0;i!=t.size();i++)
    {
       map[t[i]]++;
    }
    while(right!=s.size())
    {
        map[s[right]]--;
        if(map[s[right]]>=0)//有效还款
        {
            remain--;
        }
        if(remain==0)
        {
            while(map[s[left]]<0)
            {
              map[s[left++]]++;
            }
            len = min(len,right-left+1);
            remain++;
            map[s[left++]]++;//以left的下一个位置继续找
        }
        right++;
    }
    return len;
}
int main()
{
    string s="aabbcdcba";
    string t="abc";
    int len = query(s,t);
    printf("%d\n",len);
    system("pause");
    return 0;
}