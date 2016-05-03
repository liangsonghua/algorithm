<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>高级计算器</title>
</head>
<body>
<?php
// if($_POST){
	 // $exp=$_POST['exp']+0;
  //    echo "运算结果是=".$exp;
     require 'stack.php';
     $numStack=new MyStack();
     $expStack=new MyStack();
     /*数栈、符号栈、当前优先级*/
     //数字直接入数栈
     /*符号栈是否为空*/
     //不为空，就判断当前运算符的优先级小于等于符号栈顶的运算符，则计算,计算结果入栈,一直到当前符号栈的优先级小于栈顶的运算符，才将当前运算符入栈
     //当扫描完成后就依次弹出栈和符号栈的数据，最后留在数栈的就是最终结果
     //有两个减号时
     $exp='3+2*6-2';
     // $exp='7*2-5*2-2';
     $index=0;
     while(true){
     	$ch=substr($exp, $index,1);
     	// $index++;
     	if($expStack->isOper($ch)){
           if($expStack->isEmpty()){
                 $expStack->push($ch);
           }else{
           	  while(!$expStack->isEmpty()&&$expStack->PRI($ch)<=$expStack->PRI($expStack->getTop())){
                   $num1=$numStack->pop();
                   $num2=$numStack->pop();
                   $result=$numStack->calculator($num1,$num2,$expStack->PRI($expStack->getTop()));
                   $numStack->push($result);
                   $expStack->push($expStack->PRI($ch));
           	  }
                $expStack->push($ch);
           }
     	}else{
     		while(!$expStack->isOper(substr($exp,$index++,1))){
                     $num.=substr($exp,$index++,1);
     		}
     		$numStack->push($num);
     	}
     	//当扫描完成后就break;
     	$index++;
     	if($index==strlen($exp)){
     		break;
     	}
     }
     while(!$expStack->isEmpty()){
     	   $stackPRI=$expStack->pop();
           $num1=$numStack->pop();
           $num2=$numStack->pop();
           $result=$numStack->calculator($num1,$num2,$stackPRI);
           $numStack->push($result);
     }
     echo "运算结果是=".$numStack->show();
// }
?>
<form action="" method="post">
	请输出一个运算表达式：<input type="text" name="exp"/>
	<input type="submit" value="计算"/>
</form>
</body>
</html>