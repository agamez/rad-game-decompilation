;; fn11C8_0394: 11C8:0394
;;   Called from:
;;     0800:42C6 (in fn0800_4255)
fn11C8_0394 proc
	push	bp
	mov	bp,sp
	call	0092h
	cmp	byte ptr [5976h],0h
	jnz	03A3h

l11C8_03A1:
	jmp	03B9h

l11C8_03A3:
	mov	byte ptr [5975h],0h
	call	02ABh
	push	1h
	push	10h
	call	02DBh
	call	02F0h
	push	cs
	call	033Bh

l11C8_03B9:
	leave
	retf
