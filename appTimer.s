	.file	"appTimer.c"
	.comm	_ulEpoch, 4, 2
	.comm	_ulEpochPST, 4, 2
	.comm	_ulEpochIST, 4, 2
	.comm	_ulEpochUTC, 4, 2
.lcomm _ucFlag,1,1
.lcomm _cYear,4,4
.lcomm _cMonth,4,4
.lcomm _cHour,4,4
.lcomm _cMiniute,4,4
.lcomm _cSeconds,4,4
.lcomm _cDay,4,4
.lcomm _unIndex,2,2
	.data
	.align 32
_ucMonth:
	.long	31
	.long	28
	.long	31
	.long	30
	.long	31
	.long	30
	.long	31
	.long	31
	.long	30
	.long	31
	.long	30
	.long	31
	.section .rdata,"dr"
LC0:
	.ascii "UTC (0:0)\0"
LC1:
	.ascii "-----------------------\0"
LC2:
	.ascii "Time  : %02d:%02d:%02d \0"
LC3:
	.ascii "PM\0"
LC4:
	.ascii "AM\0"
LC5:
	.ascii "\12Date  : %02d/%02d/%02d\12\0"
LC6:
	.ascii "Epoch  : %d\12\0"
	.text
	.globl	_appTimerUTC
	.def	_appTimerUTC;	.scl	2;	.type	32;	.endef
_appTimerUTC:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	L2
	movl	$0, %eax
	jmp	L3
L2:
	movb	$0, _ucFlag
	movl	8(%ebp), %eax
	movl	$1142465659, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$23, %eax
	movl	%eax, _cYear
	movl	_cYear, %eax
	imull	$31536000, %eax, %eax
	subl	%eax, 8(%ebp)
	movl	_cYear, %eax
	addl	$1970, %eax
	movl	%eax, _cYear
	movl	8(%ebp), %eax
	movl	$-1037155065, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$16, %eax
	movl	%eax, _cDay
	movl	_cDay, %eax
	imull	$86400, %eax, %eax
	subl	%eax, 8(%ebp)
	movw	$1970, _unIndex
	jmp	L4
L8:
	movzwl	_unIndex, %eax
	andl	$3, %eax
	testw	%ax, %ax
	jne	L5
	movzwl	_unIndex, %ecx
	movl	%ecx, %eax
	shrw	$2, %ax
	movzwl	%ax, %eax
	imull	$5243, %eax, %eax
	shrl	$16, %eax
	movl	%eax, %edx
	shrw	%dx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	addl	%edx, %eax
	sall	$2, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	testw	%dx, %dx
	jne	L6
L5:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	andl	$3, %eax
	imull	$100, %eax, %eax
	testl	%eax, %eax
	jne	L7
L6:
	movzbl	_ucFlag, %eax
	addl	$1, %eax
	movb	%al, _ucFlag
L7:
	movzwl	_unIndex, %eax
	addl	$1, %eax
	movw	%ax, _unIndex
L4:
	movzwl	_unIndex, %eax
	movzwl	%ax, %edx
	movl	_cYear, %eax
	cmpl	%eax, %edx
	jbe	L8
	movl	_cDay, %edx
	movzbl	_ucFlag, %eax
	movzbl	%al, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, _cDay
	movw	$0, _unIndex
	jmp	L9
L16:
	movzwl	_unIndex, %eax
	andl	$3, %eax
	testw	%ax, %ax
	jne	L10
	movzwl	_unIndex, %ecx
	movl	%ecx, %eax
	shrw	$2, %ax
	movzwl	%ax, %eax
	imull	$5243, %eax, %eax
	shrl	$16, %eax
	movl	%eax, %edx
	shrw	%dx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	addl	%edx, %eax
	sall	$2, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	testw	%dx, %dx
	jne	L11
L10:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	andl	$3, %eax
	imull	$100, %eax, %eax
	testl	%eax, %eax
	jne	L12
L11:
	movl	$29, _ucMonth+8
L12:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	movl	_ucMonth(,%eax,4), %edx
	movl	_cDay, %eax
	cmpl	%eax, %edx
	jnb	L13
	movl	_cDay, %edx
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	movl	_ucMonth(,%eax,4), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, _cDay
	jmp	L19
L13:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	addl	$2, %eax
	movl	%eax, _cMonth
	jmp	L15
L19:
	movzwl	_unIndex, %eax
	addl	$1, %eax
	movw	%ax, _unIndex
L9:
	movzwl	_unIndex, %eax
	cmpw	$11, %ax
	jbe	L16
L15:
	movl	8(%ebp), %eax
	movl	$-1851608123, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$11, %eax
	movl	%eax, _cHour
	movl	8(%ebp), %ecx
	movl	$-1851608123, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$11, %eax
	imull	$3600, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	movl	$-2004318071, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$5, %eax
	movl	%eax, _cMiniute
	movl	8(%ebp), %ecx
	movl	$-2004318071, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$5, %eax
	imull	$60, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, _cSeconds
	movl	$10, (%esp)
	call	_putchar
	movl	$LC0, (%esp)
	call	_puts
	movl	$LC1, (%esp)
	call	_puts
	movl	_cSeconds, %ecx
	movl	_cMiniute, %edx
	movl	_cHour, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	_cHour, %eax
	cmpl	$11, %eax
	jbe	L17
	movl	$LC3, (%esp)
	call	_printf
	jmp	L18
L17:
	movl	$LC4, (%esp)
	call	_printf
L18:
	movl	_cYear, %ecx
	movl	_cMonth, %edx
	movl	_cDay, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	_ulEpoch, %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_printf
	movl	$1, %eax
L3:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.section .rdata,"dr"
LC7:
	.ascii "IST (5:30)\0"
	.text
	.globl	_appTimerIST
	.def	_appTimerIST;	.scl	2;	.type	32;	.endef
_appTimerIST:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	_ulEpochPST, %eax
	testl	%eax, %eax
	jne	L21
	movl	$0, %eax
	jmp	L22
L21:
	movb	$0, _ucFlag
	movl	8(%ebp), %eax
	movl	$1142465659, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$23, %eax
	movl	%eax, _cYear
	movl	_cYear, %eax
	imull	$31536000, %eax, %eax
	subl	%eax, 8(%ebp)
	movl	_cYear, %eax
	addl	$1970, %eax
	movl	%eax, _cYear
	movl	8(%ebp), %eax
	movl	$-1037155065, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$16, %eax
	movl	%eax, _cDay
	movl	_cDay, %eax
	imull	$86400, %eax, %eax
	subl	%eax, 8(%ebp)
	movw	$1970, _unIndex
	jmp	L23
L27:
	movzwl	_unIndex, %eax
	andl	$3, %eax
	testw	%ax, %ax
	jne	L24
	movzwl	_unIndex, %ecx
	movl	%ecx, %eax
	shrw	$2, %ax
	movzwl	%ax, %eax
	imull	$5243, %eax, %eax
	shrl	$16, %eax
	movl	%eax, %edx
	shrw	%dx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	addl	%edx, %eax
	sall	$2, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	testw	%dx, %dx
	jne	L25
L24:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	andl	$3, %eax
	imull	$100, %eax, %eax
	testl	%eax, %eax
	jne	L26
L25:
	movzbl	_ucFlag, %eax
	addl	$1, %eax
	movb	%al, _ucFlag
L26:
	movzwl	_unIndex, %eax
	addl	$1, %eax
	movw	%ax, _unIndex
L23:
	movzwl	_unIndex, %eax
	movzwl	%ax, %edx
	movl	_cYear, %eax
	cmpl	%eax, %edx
	jbe	L27
	movl	_cDay, %edx
	movzbl	_ucFlag, %eax
	movzbl	%al, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, _cDay
	movw	$0, _unIndex
	jmp	L28
L35:
	movzwl	_unIndex, %eax
	andl	$3, %eax
	testw	%ax, %ax
	jne	L29
	movzwl	_unIndex, %ecx
	movl	%ecx, %eax
	shrw	$2, %ax
	movzwl	%ax, %eax
	imull	$5243, %eax, %eax
	shrl	$16, %eax
	movl	%eax, %edx
	shrw	%dx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	addl	%edx, %eax
	sall	$2, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	testw	%dx, %dx
	jne	L30
L29:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	andl	$3, %eax
	imull	$100, %eax, %eax
	testl	%eax, %eax
	jne	L31
L30:
	movl	$29, _ucMonth+8
L31:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	movl	_ucMonth(,%eax,4), %edx
	movl	_cDay, %eax
	cmpl	%eax, %edx
	jnb	L32
	movl	_cDay, %edx
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	movl	_ucMonth(,%eax,4), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, _cDay
	jmp	L38
L32:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	addl	$2, %eax
	movl	%eax, _cMonth
	jmp	L34
L38:
	movzwl	_unIndex, %eax
	addl	$1, %eax
	movw	%ax, _unIndex
L28:
	movzwl	_unIndex, %eax
	cmpw	$11, %ax
	jbe	L35
L34:
	movl	8(%ebp), %ecx
	movl	$-1037155065, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$16, %eax
	imull	$86400, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	movl	$-1851608123, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$11, %eax
	movl	%eax, _cHour
	movl	8(%ebp), %ecx
	movl	$-1851608123, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$11, %eax
	imull	$3600, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	movl	$-2004318071, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$5, %eax
	movl	%eax, _cMiniute
	movl	8(%ebp), %ecx
	movl	$-2004318071, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$5, %eax
	imull	$60, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, _cSeconds
	movl	$10, (%esp)
	call	_putchar
	movl	$LC7, (%esp)
	call	_puts
	movl	$LC1, (%esp)
	call	_puts
	movl	_cSeconds, %ecx
	movl	_cMiniute, %edx
	movl	_cHour, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	_cHour, %eax
	cmpl	$11, %eax
	jbe	L36
	movl	$LC3, (%esp)
	call	_printf
	jmp	L37
L36:
	movl	$LC4, (%esp)
	call	_printf
L37:
	movl	_cYear, %ecx
	movl	_cMonth, %edx
	movl	_cDay, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$1, %eax
L22:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.section .rdata,"dr"
LC8:
	.ascii "PST (7:00)\0"
	.text
	.globl	_appTimerPST
	.def	_appTimerPST;	.scl	2;	.type	32;	.endef
_appTimerPST:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$0, 8(%ebp)
	jne	L40
	movl	$0, %eax
	jmp	L41
L40:
	movb	$0, _ucFlag
	movl	8(%ebp), %eax
	movl	$1142465659, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$23, %eax
	movl	%eax, _cYear
	movl	_cYear, %eax
	imull	$31536000, %eax, %eax
	subl	%eax, 8(%ebp)
	movl	_cYear, %eax
	addl	$1970, %eax
	movl	%eax, _cYear
	movl	8(%ebp), %eax
	movl	$-1037155065, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$16, %eax
	movl	%eax, _cDay
	movl	_cDay, %eax
	imull	$86400, %eax, %eax
	subl	%eax, 8(%ebp)
	movw	$1970, _unIndex
	jmp	L42
L46:
	movzwl	_unIndex, %eax
	andl	$3, %eax
	testw	%ax, %ax
	jne	L43
	movzwl	_unIndex, %ecx
	movl	%ecx, %eax
	shrw	$2, %ax
	movzwl	%ax, %eax
	imull	$5243, %eax, %eax
	shrl	$16, %eax
	movl	%eax, %edx
	shrw	%dx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	addl	%edx, %eax
	sall	$2, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	testw	%dx, %dx
	jne	L44
L43:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	andl	$3, %eax
	imull	$100, %eax, %eax
	testl	%eax, %eax
	jne	L45
L44:
	movzbl	_ucFlag, %eax
	addl	$1, %eax
	movb	%al, _ucFlag
L45:
	movzwl	_unIndex, %eax
	addl	$1, %eax
	movw	%ax, _unIndex
L42:
	movzwl	_unIndex, %eax
	movzwl	%ax, %edx
	movl	_cYear, %eax
	cmpl	%eax, %edx
	jbe	L46
	movl	_cDay, %edx
	movzbl	_ucFlag, %eax
	movzbl	%al, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, _cDay
	movw	$0, _unIndex
	jmp	L47
L54:
	movzwl	_unIndex, %eax
	andl	$3, %eax
	testw	%ax, %ax
	jne	L48
	movzwl	_unIndex, %ecx
	movl	%ecx, %eax
	shrw	$2, %ax
	movzwl	%ax, %eax
	imull	$5243, %eax, %eax
	shrl	$16, %eax
	movl	%eax, %edx
	shrw	%dx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	addl	%edx, %eax
	sall	$2, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	testw	%dx, %dx
	jne	L49
L48:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	andl	$3, %eax
	imull	$100, %eax, %eax
	testl	%eax, %eax
	jne	L50
L49:
	movl	$29, _ucMonth+8
L50:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	movl	_ucMonth(,%eax,4), %edx
	movl	_cDay, %eax
	cmpl	%eax, %edx
	jnb	L51
	movl	_cDay, %edx
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	movl	_ucMonth(,%eax,4), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, _cDay
	jmp	L57
L51:
	movzwl	_unIndex, %eax
	movzwl	%ax, %eax
	addl	$2, %eax
	movl	%eax, _cMonth
	jmp	L53
L57:
	movzwl	_unIndex, %eax
	addl	$1, %eax
	movw	%ax, _unIndex
L47:
	movzwl	_unIndex, %eax
	cmpw	$11, %ax
	jbe	L54
L53:
	movl	8(%ebp), %ecx
	movl	$-1037155065, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$16, %eax
	imull	$86400, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	movl	$-1851608123, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$11, %eax
	movl	%eax, _cHour
	movl	8(%ebp), %ecx
	movl	$-1851608123, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$11, %eax
	imull	$3600, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	movl	$-2004318071, %edx
	mull	%edx
	movl	%edx, %eax
	shrl	$5, %eax
	movl	%eax, _cMiniute
	movl	8(%ebp), %ecx
	movl	$-2004318071, %edx
	movl	%ecx, %eax
	mull	%edx
	movl	%edx, %eax
	shrl	$5, %eax
	imull	$60, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, _cSeconds
	movl	$10, (%esp)
	call	_putchar
	movl	$LC8, (%esp)
	call	_puts
	movl	$LC1, (%esp)
	call	_puts
	movl	_cSeconds, %ecx
	movl	_cMiniute, %edx
	movl	_cHour, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	_cHour, %eax
	cmpl	$11, %eax
	jbe	L55
	movl	$LC3, (%esp)
	call	_printf
	jmp	L56
L55:
	movl	$LC4, (%esp)
	call	_printf
L56:
	movl	_cYear, %ecx
	movl	_cMonth, %edx
	movl	_cDay, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC5, (%esp)
	call	_printf
	movl	$1, %eax
L41:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
