;; fn133F_0200: 133F:0200
;;   Called from:
;;     1229:0D8E (in fn1229_0CCE)
;;     133F:04C0 (in fn133F_04B1)
fn133F_0200 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Ch]
	mov	[6CC8h],ax
	mov	ax,[bp+0Ah]
	mov	[6CCAh],ax
	mov	ax,[bp+8h]
	mov	[6CCCh],ax
	mov	ax,[bp+6h]
	mov	[6CCEh],ax
	leave
	retf	8h
