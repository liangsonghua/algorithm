<?php
//回文子串之Manacher算法
//一般做法
//ab1234321cd
//奇回文，可以括
//1 2 2 1偶回文，就不能用括方式了
/**************思路********/
// 1 2 2 1
// 字符左右各加一个特殊字符
// #1#2#2#1#
// 特殊字符(无论什么都可以)也算字符作括处理
// 找到后除2往下取整就是原来的回文子串长度
/************实现********/
/*
三个变量:
1.回文变量pArr[i];表示以i为中心的回文半径，
比如#1#2#1#3
    01234567
 pArr[3]=4;
2.Pr=0 即将到达的位置
比如#1#2#1#3
    01234567
    当从1开始括时，Pr=3
3.index 回文中心位置，从哪开始括
比如#1#2#1#3
    01234567
   Pr更新时，index跟着更新
前面做的工作可以优化后面的工作，因为对称性
情况一:i的回文半径在左大和右大间
#c(#a#b#a#)d#d(#a#b#a#)c#
      i     k     j
情况二：
[#a(#b#a# ]c# a[#b#])d# 
     i     k     j
情况一和二可直接确定i的回文串半径
情况三:左小和左大重合
#d([# a # b# a#]c# a# b# a#)c#
          i     k     j
情况四:暴力括
*/
$str="abc1234321ab";
$length=12;
var_dump(manacher($str, $length));
function manacher($str, $length)
{
  $tempStr = '';
  $tempStr[0] = '#';
  //构造填充字符串  
  for ($i=0; $i < $length; $i++) { 
  	 $tempStr[2*$i+1] = $str[$i];
  	 $tempStr[2*$i+2] = '#';
  }
  $length = 2*$length+2;
  $len = 1;
  $pArr = array();
  $pr = 0;
  $index = 0;
  for ($i=0; $i <$length ; $i++) { 
  	 if($pr>$i){
  	 	 //2*$index-$i是$i关于$index的对称点
  	 	 //由于对称点的回文半径可能超过$pr-$i,因为$pr后面的还没有配过
         //所以要取小的。
  	 	$pArr[$i] = min($pArr[2*$index-$i],$pr-$i);
  	 }else{
  	 	//至少是1
  	 	 $pArr[$i] = 1;
  	 }
  	 //向两端匹配
  	 while ($tempStr[$i+$pArr[$i]]==$tempStr[$i-$pArr[$i]]) {
  	 	$pArr[$i]++;
  	 }
  	 while ($pArr[$i]+$i>$pr) {
  	 	$pr = $pArr[$i]+$i;
  	 	$index = $i;
  	 }
  	 if($len<$pArr[$i]){
  	 	$len = $pArr[$i];
  	 }
  }
  return $len;
}