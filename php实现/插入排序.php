<?php
/*
从第一个元素开始，该元素可以认为已经被排序
取出下一个元素，在已经排序的元素序列中从后向前扫描
如果该元素（已排序）大于新元素，将该元素移到下一位置
重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
将新元素插入到该位置后
重复步骤2~
*/
 function swap(&$a,&$b){
	$temp=$a;
	$a=$b;
	$b=$temp;
  }

  function insert_sort(&$arr){
	  $len=count($arr);
	    for($i=1;$i<$len;$i++){
	    $flag=$i;
        for($j=$i-1;$j>=0;$j--){ 
	     if($arr[$flag]<$arr[$j]){
				swap($arr[$flag],$arr[$j]);
		         	$flag--;
			}
	
	  }
	   
  }
  }
   $arr = array(21, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70);
 insert_sort($arr);
  for($i=0;$i<count($arr);$i++){
	echo "<br/>".$arr[$i];
  }


?>