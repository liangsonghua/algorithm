<?php
/*
在一个数组中找到出现的次数大于一半的数值
如果存在只能有一个
每次删除两个不同的数到最后如果只留下一种数则只有它有可能
推广：有几个数出现了k份之一次??候选筛选方式不一样而已
不用哈希表
1 2 1 1 3
cand
times
遍历到1时没有候选则把它设为候选
遍历到2时不等于候选值，则候选和2一样删除
推广:n张选票，一个机器只能判断两张选票是否为一个人
*/
$arr=array(2, 2, 3, 3, 3);
print_r(appearHalf($arr));
function appearHalf($arr){
	$cand = 0;//记录候选值
	$times =0;//记录出现次数
	foreach ($arr as $key => $value) {
		if($times==0){
			$cand = $value;
			$times =1;
		}else{
			if($cand==$value){
                $times++;
			}else{
				$times--;
			}
		}
	}
  return $cand;
}