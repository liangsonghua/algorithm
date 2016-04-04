<?php
/*
顺时针打印矩阵
*/
/*
//转圈打印
/*
1  2   3  4

5  6   7  8

9  10  11  12

13  14 15 16

*/
/**
1和16的位置标记为子矩阵
1  2  3   4
5         8
9        12
13 14 15 16
然后1的位置往右下移动
16的位置往左上移动
标记得到子矩阵
6  7
10 11
两个子矩阵连接起来即可
*/
$mat=array(
	array(1,2,3,4),
	array(5,6,7,8),
	array(9,10,11,12),
	array(13,14,15,16)
	);
$m=4;$n=4;
echo "<pre/>";
print_r(shunShiZhenDaYin($mat, $m, $n));
function shunShiZhenDaYin($mat, $m, $n)
{
   $result = array();
   $startX = 0;
   $startY = 0;
   $endX = $m-1;
   $endY = $n-1;
   $i = 0;
   $j = 0;
   while ($startX<=$endX&&$startY<=$endY) {
   	 //只有一行
   	 if($startX==$endX){
   	 	 for ( ;$i <$endY ; $i++) { 
   	 	 	$result[] = $mat[$startX][$i];
   	 	 }
   	 	return $result;
   	 }
   	 //只有一列
   	 if($startY==$endY){
   	 	 for (;$i <$endX ; $i++) { 
   	 	 	$result[] = $mat[$i][$startY];
   	 	 }
   	 	return $result;
   	 }
   	 for (;$j <$endY ; $j++) { 
   	 	$result[] = $mat[$i][$j];
   	 }
   	 for (;$i <$endX ; $i++) { 
   	 	$result[] = $mat[$i][$j];
   	 }
   	 for (;$j >$startY ; $j--) { 
   	 	$result[] = $mat[$i][$j];
   	 }
   	 for (;$i >$startX ; $i--) { 
   	 	$result[] = $mat[$i][$j];
   	 }       
   	    $i++;
        $j++;
        $startX++;
        $startY++;
        $endY--;
        $endX--;
   }
   return $result;
}
