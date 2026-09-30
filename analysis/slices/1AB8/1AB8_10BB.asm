;; fn1AB8_10BB: 1AB8:10BB
;;   Called from:
;;     0800:1052 (in fn0800_0D20)
;;     0800:107E (in fn0800_0D20)
;;     0800:10F9 (in fn0800_0D20)
;;     0800:1131 (in fn0800_0D20)
;;     1229:02D0 (in fn1229_0040)
;;     1229:0308 (in fn1229_0040)
fn1AB8_10BB proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	ax,[0B846h]
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf
