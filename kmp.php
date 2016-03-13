<?php
//kmp算法：问题由模式串决定
//对回溯法的改进
/*思路启发 1.i1=j1 i2=j2如果i1不等于i2，所以i1不可能与j2相等。没有必要回溯就是i1没必要和j2匹配
           2.比如bbsbbc有两处多个一样的，匹配bbsbbs时，则应该bbsbbc右移3位再与bbsbbs匹配
 */
 /*前缀和后缀有多少个重复
        str 9 a b a b a a a b a
       下标:0 1 2 3 4 5 6 7 8 9
demo_next  :x 0 1 1 2 3 4 2 2 3
code_next  :x 0 1 1 2 3 4 2 2 3


后缀 i：1 2 。 3 4 5 6 7 。 8 9
前缀 j: 0 1 0  1 2 3 4 2 1  2 3
*/
//next数组：当模式匹配串str失配时，NEXT数组对应的元素指导应该用T串的哪个元素进行下一轮的匹配
//下标0号的值表示字符串的长度
//KMP算法之NEXT数组代码原理分析
$i=1;
$j=0;
$next=array();
$next[1]=0;
while($i<$str[0]){
	if(0==$j||$str[$i]==$str[$j]){
	  $i++;
	  $j++;
	  //改进：如果s=a a a a b c d e
   //             t=a a a a x
	  if($str[$i]!=$str[$j]){
         $next[$i]=$j;
	  }else{
         $next[$i]=$next[$j];
	  }
	 
	}
	else{
		//回溯
	  $j=$next[$j];
	}	
}

?>