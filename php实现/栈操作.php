<?php
//堆栈:
//使用:子程序调用，在跳转子程序前，会先将下指令的地址存到堆栈中，直到子程序执行完成后再将其取出
//表达式的转换与求值 二叉树的遍历 图形的深度优先
//先入后出的有序列表，限制线性表中元素的插入和删除只能在一端进行
//有变量$top总是指向最上面的元素，堆栈为空时$top=-1
//array_push() 将 array 当成一个栈，并将传入的变量压入 array 的末尾。array 的长度将根据入栈变量的数目增加
//编号越大就在栈顶
//数组实现栈
header('Content-type:text/html;charset=utf8');
class MyStack{
	private $top=-1;
	private $maxsize=5;
	private $stack=array();
	//入
	public function push($val){
		if($this->top==$this->maxsize-1){
           return ;
		}
         $this->top++;
         $this->stack[$this->top]=$val;
	}
	//出
	public function pop(){
		if($this->top==-1){
			return ;
		}
		echo $this->stack[$this->top];
		$this->top--;
	}
	//显示
	public function show(){
		if($this->top==-1){
			return ;
		}
		for($i=$this->top;$i>-1;$i--){
			echo $this->stack[$i];
		}
	}
}
?>