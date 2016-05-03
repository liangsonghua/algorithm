<?php
/*
对于一个有序数组arr，再给定一个整数num，请在arr中找到num这个数出现的最左边的位置。若该元素在数组中未出现，请返回-1。
*/
$arr=array(1,3,3,3,4);
$num=3;
print_r(leftMostAppearance($arr, $num));
function leftMostAppearance($arr, $num)
{
	$left = 0;
	$right = sizeof($arr);
	while($left<$right) {
		$mid = $left+floor(($right-$left)/2);
		if($arr[$mid]==$num){
		   if($arr[$mid-1]!=$num){
		   	  return $mid;
		   }
		   $right=$mid-1;
		}else if($arr[$mid]>$num){
	        $right=$mid;
		}else{
			$left=$mid+1;
		}	
	}
   if($arr[$left]==$num){
   	 return $left;
   }
   return false;
}