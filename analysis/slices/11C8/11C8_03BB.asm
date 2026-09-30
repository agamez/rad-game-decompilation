;; fn11C8_03BB: 11C8:03BB
;;   Called from:
;;     0800:0016 (in fn0800_0000)
fn11C8_03BB proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [5976h],0h
	jnz	03C7h

l11C8_03C5:
	jmp	03CDh

l11C8_03C7:
	call	02CCh
	call	02ABh

l11C8_03CD:
	leave
	retf
