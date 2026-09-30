;; fn1AB8_0E88: 1AB8:0E88
;;   Called from:
;;     0800:0008 (in fn0800_0000)
;;     0C74:03EA (in fn0C74_03D4)
;;     13E2:01AF (in fn13E2_0193)
;;     1AB8:0ECB (in fn1AB8_0EB5)
fn1AB8_0E88 proc
	push	bp
	mov	bp,sp
	push	cs
	call	18E3h
	mov	ax,[0B824h]
	or	ax,[0B826h]
	jnz	0EB3h

l1AB8_0E98:
	mov	ax,[0B820h]
	mov	dx,[0B822h]
	mov	[0B824h],ax
	mov	[0B826h],dx
	mov	ax,8Bh
	mov	dx,1AB8h
	mov	[0B820h],ax
	mov	[0B822h],dx

l1AB8_0EB3:
	pop	bp
	retf
