//对二维数组按指定字段排序
<?php
$arr=array(
     array('name'=>'pidan','age'=>'21'),
     array('name'=>'tom','age'=>'25'),
     array('name'=>'jack','age'=>'20')
	);
usort($arr,'cmp');
function cmp($a,$b){
	if($a['age']==$b['age']){
		return 0;
	}
	return ($a['age']<$b['age'])?-1:1;
}
echo "<pre/>";
var_dump($arr);