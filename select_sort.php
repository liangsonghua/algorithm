<?php
  function swap(&$a,&$b){
	$temp=$a;
	$a=$b;
	$b=$temp;
  }
  function select_sort(&$arr){
     $len=count($arr);
	 for($i=0;$i<$len-1;$i++){
		 $min=$i;
      for($j=$i+1;$j<$len;$j++){
	    if($arr[$j]<$arr[$min]){
				 swap($arr[$j],$arr[$min]);
			 }
		 }
	 }
 }
 $arr = array(21, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70);
 select_sort($arr);
for($i=0;$i<count($arr);$i++){
	echo "<br/>".$arr[$i];
}

?>