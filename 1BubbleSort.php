<?php
 function swap(&$x,&$y){
	 $t=$x;
	 $x=$y;
	 $y=$t;
 }
 	
 function bubblesort(&$arr){
   $num=count($arr);
	 if($num<2){
		 return $arr;
	 }
  else{
	  	 for($i=0;$i<$num;$i++){
		 for($j=0;$j<$num-1-$i;$j++){
			 if($arr[$j]>$arr[$j+1]){
				swap($arr[$j],$arr[$j+1]);
			 }
		 }
	 }
	 return $arr;
  }
 }
$arr = array(21, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70);
bubblesort($arr);
for($i=0;$i<count($arr);$i++){
	echo  "<br/>".$arr[$i];
}
?>