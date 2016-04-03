<?php
//循环有序数组最小值
/*
对于一个有序循环数组arr，返回arr中的最小值。
有序循环数组是指，有序数组左边任意长度的部分放到右边去，右边的部分拿到左边来。比如数组[1,2,3,3,4]，是有序循环数组，[4,1,2,3,3]也是。
给定数组arr及它的大小n，请返回最小值。
*/
/*
L=0 R=N-1
L<R L
L>=R 可能包括循环数组
     l>m 7 8 9 1 2 3 4 5 6
     M>R 4 5 6 7 8 9 1 2 3
     L=M=R 2 2 2 1 2 2 2 2只能遍历了
*/
// 在有序序列中查找一个数,并不一定非要在有序序列中才能得到应用，,二分搜索要注意边界
$arr = array(3,4,5,6,7,2);
// $arr = array(4, 5, 6, 7, 8, 9, 1, 2, 3);
print_r(getMinValue($arr));
function getMinValue($arr)
{
	if(is_null($arr))return -1;
	$left  = 0;
	$right = count($arr)-1;
	$mid   = 0;
	while($left<$right){
		if($left==$right-1){
	          if($arr[$left]<$arr[$right]){
		     return $arr[$left];
	           }
		   return $arr[$right];
		}
		if($arr[$left]<$arr[$right]){
		  return $arr[$left];
		}
		$mid = $left+floor(($right-$left)/2);
		if($arr[$left]>$arr[$mid]){
			//说明左边包括循环数组
			$right = $mid;
		}else if($arr[$mid]>$arr[$right]){
            $left  = $mid;
		}
		else{
		//说明left right mid三者相等
			$min=$arr[0];
			for($i=0; $i <count($arr)-1; $i++) {    
			   if($arr[$i]<$min){
                  $min=$arr[$i];
				}
			}
		   return $min;
		}
	}
}
