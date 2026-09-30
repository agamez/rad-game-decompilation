;; fn1AB8_1250: 1AB8:1250
;;   Called from:
;;     133F:0129 (in fn133F_0056)
;;     1AB8:0B32 (in fn1AB8_0AEE)
fn1AB8_1250 proc
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+6h],0Fh
	jbe	125Bh

l1AB8_1259:
	jmp	1281h

l1AB8_125B:
	mov	al,[bp+6h]
	mov	[0B840h],al
	cmp	word ptr [bp+6h],0h
	jnz	126Eh

l1AB8_1267:
	mov	byte ptr [0B87Bh],0h
	jmp	1278h

l1AB8_126E:
	mov	di,[bp+6h]
	mov	al,[di+0B87Bh]
	mov	[0B87Bh],al

l1AB8_1278:
	mov	al,[0B87Bh]
	cbw
	push	ax
	push	cs
	call	1CA4h

l1AB8_1281:
	pop	bp
	retf	2h
