
/*
1）哈希法首先char类型判断重复，用hash数组最方便，只需要256个bool类型即可，
O(n)的时间（其实只要判断前257个就行了O(1)，抽屉原理）
2）遍历那么只能用两层for循环遍历，时间复杂度为O(n*n)，
但是根据抽屉原理，没必要遍历到N，只需要遍历到前257就够了，
如果N<257就遍历到N，所以时间复杂度其实为O(1)!!!
3）排序既然题目要求不能使用额外空间，而参数列表没有const或引用，
那么就可以对字符串排序，然后再判断，需要O（nlogn)排序，
然后再遍历一遍O(n)。其实也没必要全都排序，只需前257个，同抽屉原理。
4）Parition基于快速排序的partition，可以边排序边找重复，
也即是每次partition之后，判断基准key元素与两边元素是否相同，相同则返回false，
不同再进行下一轮partition.时间复杂度也是O(nlongn)，但要比排序速度快。
*/
class Different {   
	bool quick_check(string &str,int low,int high)
	{

			int first = low,last = high;

			char key = str[first];

			if (low>=high)

				return true;

			while(first<last){

				while(first <last && str[last] >= key)

					last--;            

				str[first] = str[last];

				while(first<last && str[first] <= key)

					first++;

				str[last] = str[first];

			}

			str[first] = key;

			if (first>low && str[first] == str[first-1])

				return false;

			if (first<high && str[first] == str[first+1])

				return false;

			return quick_check(str,low,first-1) && quick_check(str,first+1,high);

		}

	public:

		bool checkDifferent(string iniString) 
		{

			// write code here

			return quick_check(iniString,0,iniString.size()-1);

		}
};