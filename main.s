	.file	"main.c"
	.comm	_ulEpoch, 4, 2
	.comm	_ulEpochPST, 4, 2
	.comm	_ulEpochIST, 4, 2
	.comm	_ulEpochUTC, 4, 2
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB26:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$36, %esp
	call	___main
L2:
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_time
	movl	%eax, _ulEpoch
	leal	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_localtime
	movl	%eax, -12(%ebp)
	movl	_ulEpoch, %eax
	movl	%eax, _ulEpochUTC
	movl	_ulEpochUTC, %eax
	movl	%eax, (%esp)
	call	_appTimerUTC
	movl	_ulEpoch, %eax
	addl	$19800, %eax
	movl	%eax, _ulEpochIST
	movl	_ulEpochIST, %eax
	movl	%eax, (%esp)
	call	_appTimerIST
	movl	_ulEpoch, %eax
	subl	$25200, %eax
	movl	%eax, _ulEpochPST
	movl	_ulEpochPST, %eax
	movl	%eax, (%esp)
	call	_appTimerPST
	movl	$1000, (%esp)
	call	_Sleep@4
	subl	$4, %esp
	jmp	L2
	.cfi_endproc
LFE26:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_time;	.scl	2;	.type	32;	.endef
	.def	_localtime;	.scl	2;	.type	32;	.endef
	.def	_appTimerUTC;	.scl	2;	.type	32;	.endef
	.def	_appTimerIST;	.scl	2;	.type	32;	.endef
	.def	_appTimerPST;	.scl	2;	.type	32;	.endef
	.def	_Sleep@4;	.scl	2;	.type	32;	.endef
