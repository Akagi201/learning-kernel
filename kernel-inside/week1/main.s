g:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax # eax = 8
	addl	$3, %eax # eax = 8 + 3 = 11
	popl	%ebp
	ret

f:
	pushl	%ebp
	movl	%esp, %ebp # 每个函数前两句都是这个, 用于保存上一个堆栈的栈顶, 跟清空出一个新的堆栈
	subl	$4, %esp
	movl	8(%ebp), %eax # eax = 8
	movl	%eax, (%esp) # 把8放到栈顶
	call	g # 跳到g标号
	leave
	ret

main:
	pushl	%ebp # 将当前ebp的值压栈, 同时esp的值被修改(即减4)
	movl	%esp, %ebp # 将ebp指向esp
	subl	$4, %esp # 将esp向下移动一个位置
	movl	$8, (%esp) # 将立即数8赋值给esp指向的位置(即当前的栈顶)
	call	f # 等价于两条语句 pushl eip; movl f eip => 当前eip实际指向addl $1, %eax这条指令, 跳转到f标号处执行
	addl	$1, %eax # eax = 11 + 1 = 12
	leave
	ret # 最终ebp, esp回到main函数最初的栈的位置.
