<html>
<head>
<meta http-equiv='content-type' content='text/html;charset=utf-8'/>
</head>
<h1>约瑟夫问题解决</h1>
<?php


		//1(1)	构建一个环形链表,链表上的每个节点，表示一个小朋友
		//小孩类
		class Child{
			public $no;
			public $next=null;
			//构造函数
			public function __construct($no){
				$this->no=$no;
			}
		}

		//定义一个指向第一个小朋友的引用
		$first=null;
		$n=4000;//$n表示有几个小朋友
		//写一个函数来创建一个四个小朋友的环形链表
		//一会，我们深入的分析&$first

		/**
			addChild函数的作用是: 把$n个小孩构建成一个环形链表，$first变量就指向该
			环形链表的第一个小孩子

		*/
		function addChild(&$first,$n){
				//死去活来
				//1. 头结点不能动 $first不能动.
				$cur=null; 
				for($i=0;$i<$n;$i++){
					
					$child=new Child($i+1);
					//怎么构成一个环形链表.
					if($i==0){
						
							$first=$child;
							$first->next=$child;
							$cur=$first;
					}else{
							
							$cur->next=$child;
							$child->next=$first;
							$cur=$cur->next;
						   
					}

				}

		}

		//遍历所有的小孩，显示,必须把头$first 给函数.
		 function showChild($first){
			
			//遍历 $cur变量是帮助我们遍历环形链表，所以不能动.
			$cur=$first;

			while($cur->next!=$first){
		
				//显示
				echo '<br/>小孩的编号是'.$cur->no;
				$cur=$cur->next;
			}

			//当退出while循环时，已经到了环形链表的最后，所以还要处理一下最后这个
			//小孩节点
			//显示
				echo '<br/>小孩的编号是'.$cur->no;


		}

		$m=31;
		$k=20;
		//问题简化,从第一个小孩开始数,数2.看看出圈的顺序
		function  countChild($first,$m,$k){

				//可以加入一些判断条件.

				//思考:因为我们找到一个小孩，就要把他从环形链表删除，
				// 为了能够删除某个小孩，我们需要一个辅助变量，该变量指向的小孩
				//在 $first前面.
				$tail=$first;

				while($tail->next!=$first){
					$tail=$tail->next;
				}

				//考虑是从第几个人开始数数
				for($i=0;$i<$k-1;$i++){
					$tail=$tail->next;
					$first=$first->next;
				}
			
				//当退出while时，我们的$tail就指向了最后这个小孩
				//让$first和$tail向后移动.
				//移动一次，相当于数2下.
				//移动2次，相当于数了3下,因为自己数的时候是不需要动的.
				while($tail!=$first){ //当$tail==$first则说明只有最后一个人了.
					for($i=0;$i<$m-1;$i++){
						
						$tail=$tail->next;
						$first=$first->next;
					}

					echo '<br/>出圈额人的编号是'.$first->no;
					//把$first指向的节点小孩删除环形链表
					$first=$first->next;
					$tail->next=$first;
					
				}

				echo '<br/>最后留在圈圈的人的编号是'.$tail->no;
	
		}

		addChild($first,$n);
		showChild($first);//死悄悄
		//真正的来玩游戏.
		countChild($first,$m,$k);

			

?>
</html>