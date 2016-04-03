# 1.排序 #

## 冒泡排序 bubble sort ##

 核心思想交换区间进行比较，首先在数组最大区间内两两比较，逐渐减小区间

## 选择排序select_sort ##
核心思想第一次选择最小的数放在下标0的位置下，然后在1-maxsize-1区间选择最小的放在1的位置....
## 插入排序insert_sort ##
首先下标1和下标0的数进行比较，判断是否需要交换，然后下标2和0，1比较，交换位置插入适当位置
## 归并排序mergesort ##
相邻有序空间合并，每次改变空间大小，直到合并成一个整体的有序集
## 快速排序 ##
随机选择一个数，比它小的数放在左边，比它大的数放在右边，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行
## 堆排序 ##
建成一个n的大根堆，堆顶部和末端的值交换，然后从根堆脱离，接下来再对大根堆进行调整，使得堆顶值为最大
## 希尔排序 ##
插入排序的一种变形，关键是步长的调整，比如选步长为3，则第4个和向前3个进行比较，判断是否需要交换，
          则继续向前跳3位，重复，直到越界，则对第5个进行，执行完一轮后对步长进行减小

# 2.二分搜索 #

  常见的是在有序序列中查找一个数,并不一定非要在有序序列中才能得到应用，二分搜索问题要注意边界<br/>
 **示例1**：在无序数组中找局部最小出现的位置(`geLessIndex.php`)<br/>
         在有序数组中找到一个数出现的最左边的位置(`leftMostAppearance.php`)<br/>
        循环有序数组最小值(`getMinValue.php`)

# 3.字符串 #

  字符替换、旋转、查找、字符移位、字符计数、字符相等判断

# 4.数组 #
  
  **示例1**：在一个数组中找到出现的次数大于一半的数值(不用哈希表)<br/>(`appearHalf.php`)
        分析:如果存在只能有一个,每次删除两个不同的数到最后如果只留下一种数则只有它有可能<br/>
        推广：有几个数出现了k份之一次??候选筛选方式不一样而已


# 5.队列和栈 #

## 队列 ##
先进先出，比如排队一样;宽度优先遍历用队列实现，进队列顺序就是访问顺序
## 栈 ##
先进后出，限线性表中元素的插入和删除只能在一端进行，比如子弹;深度优先遍历用栈实现，进栈顺序就是访问顺序<br/>
  **示例1**：请看用数组实现对栈操作`stack.php`(有变量$top总是指向最上面的元素，堆栈为空时$top=-1,将 array 当成一个栈，
  并将传入的变量压入 array 的末尾。array 的长度将根据入栈变量的数目增加)<br/>
 **示例2**:使用栈实现高级计算器(代码`calculator.php`)，数字直接入数栈，当扫描到符号时符号栈为空则直接入栈，不为空，就判断当前运算符的优先级小于等于符号栈顶的运算符，
 则计算,计算结果入栈,一直到当前符号栈的优先级小于栈顶的运算符，才将当前运算符入栈;当扫描完成后就依次弹出栈和符号栈的数据，最后留在数栈的就是最终结果

# 6、链表 #

  链表空间不一定保证连续，为临时空间，不能直接通过下标访问，只能使用指针next遍历
  单链表和双链表、普通和循环链表<br/>
  注意：链表为空和长度为1的情况还有对头和尾插入和删除<br/>
 **示例**：请看环形链表解决约瑟夫问题`Josephu.php`