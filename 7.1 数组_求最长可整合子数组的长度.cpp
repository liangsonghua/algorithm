class Solution {
public:
	/**
	 *	在数组中求长度最大的可整合子数组长度
	 *	arr：输入数组
	 *	返回：最大的可整合子数组的长度
	 */
	int getMaxLength(vector<int> arr, int len) {
        //可整合子数组没有重复(一旦出现就没有必要往右继续找了)
        //最大值-最小值+1 =  长度
        int res = 0;
        map<int,int>help;
        for(int i=0;i<len;i++)
        {
            int max=0x80000000;  
            int min=0x7fffffff;
            for(int j=i;j<len;j++)
            {
               if(help[arr[j]]!=0)
                {
                    break;
                }
                help[arr[j]]++;
                max = max>arr[j]?max:arr[j];
                min = min<arr[j]?min:arr[j];
                if(max-min == (j-i))
                {
                   res = res>(max-min+1)?res:(max-min+1);
                }
            }
            help.clear();
        }
       return res;
    }
};