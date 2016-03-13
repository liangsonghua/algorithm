<?php
/*****************************************************
归并操作（merge），也叫归并算法，指的是将两个已经排序的序列合并成一个序列的操作。
第一次扫描数组，将数组中相邻的两个元素merge为有序数组
第二次扫描，将相邻的有序数组再合并为更大的一个有序数组
再进行n次扫描，不断合并数组，直到排序完成
归并排序算法依赖归并操作。
迭代法
申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
设定两个指针，最初位置分别为两个已经排序序列的起始位置
比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
重复步骤3直到某一指针到达序列尾
将另一序列剩下的所有元素直接复制到合并序列尾

递归法
原理如下（假设序列共有n个元素）：
将序列每相邻两个数字进行归并操作，形成floor(n/2)个序列，排序后每个序列包含两个元素
将上述序列再次归并，形成floor(n/4)个序列，每个序列包含四个元素
重复步骤2，直到所有元素排序完毕


对两个有序数组中的各个值按key值从小到大的顺序进行value值比较，
当两个数组的key值分别都在各自的数组长度范围内的时候，
进行一对一的比较，将比较中较小的value值存放在一个新的数组内
。并且该value值对应的key值向前递增1。由于两个数组的各个value值都比较完之后，
最后的一组比较中，较大值不能进行下一轮比较，所以将此时该value值放进新数组中，
作为新数组中的最大值
*****************************************************/
<?php
    function array_all($array_all){
        $i=0;
        $count_array_all=count($array_all);
        //echo $count_array_all;exit;
 
        if($count_array_all>=2){
            $arr_merge=merge_sort();
            for($i;$i<$count_array_all;$i++){
                $arr_merge=merge_sort($arr_merge,$array_all[$i]);
            }
        }else{
            $arr_merge=$array_all[$i];
        }
        return $arr_merge;
    }
 
    function merge_sort($arrA=array(), $arrB=array()) {
        $a_i = $b_i = 0;//设置两个起始位置标记
        $lenA = count($arrA);
        $lenB = count($arrB);
        $arrC=array();
        if($lenB==0){
            return $arrA;
        }else if($lenA==0){
            return $arrB;
        }else{
            while($a_i<$lenA && $b_i<$lenB) {
            //当数组A和数组B的指针位置在数组界内时
                if($arrA[$a_i] < $arrB[$b_i]) {
                    $arrC[] = $arrA[$a_i++];
                } else {
                    $arrC[] = $arrB[$b_i++];
                }
            }
            //判断 数组A内的元素是否都用完了，没有的话将其全部插入到C数组内：
            while($a_i < $lenA) {
                $arrC[] = $arrA[$a_i++];
            }
            //判断 数组B内的元素是否都用完了，没有的话将其全部插入到C数组内：
            while($b_i < $lenB) {
                $arrC[] = $arrB[$b_i++];
            }
            //merge_sort($arrC,$arrD=array());
            return $arrC;
        }
         
    }
 
    // $arr=merge_sort(array(1,3,5),array(2,4,6));
    // stamp($arr);
 
    function stamp($arr){
        echo "<pre>";
        return print_r($arr);
    }
 
    // $arr=array(array(1,4,12,23),array(2,6,98),array(9,20,35));
    // stamp(array_all($arr));
?>
?>