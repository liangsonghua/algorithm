<?php
//  定义局部最小的概念。arr长度为1时，arr[0]是局部最小。
// arr的长度为N(N>1)时，
// 如果arr[0]<arr[1]，那么arr[0]是局部最小；如果arr[N-1]<arr[N-2]，那么arr[N-1]是局部最小；
// 如果0<i<N-1，既有arr[i]<arr[i-1]又有arr[i]<arr[i+1]，那么arr[i]是局部最小。
//  给定无序数组arr，已知arr中任意两个相邻的数都不相等，写一个函数，只需返回arr中任意一个局部最小出现的位置即可。
function getLessIndex($arr)
{
  if(is_null($arr))return false;
  if(count($arr)==1||$arr[0]<$arr[1]){
  	//如果不成立说明前面是递减的
  	 return $arr[0];
  }
  if($arr[count($arr)-1]<$arr[count($arr)-2]){
    	//如果不成立说明后面是递增的
       return $arr[count($arr)-1];
   }
   $left=1;
   $right=count($arr)-2;
   while($left<$right){
   	$mid=$left+floor(($right-$left)/2);//不会溢出
      if($arr[$mid]>$arr[$mid-1]){
         $right=$mid-1;
      }else if($arr[$mid]>$arr[$mid+1]){
         $left=$mid;
      }else{
      	 return $mid;
      }
    }
   return $left;
}
$arr=array(7,5,3,4,9,7,52);
print_r(getLessIndex($arr));