;; fn1AB8_108B: 1AB8:108B
;;   Called from:
;;     0800:0E68 (in fn0800_0D20)
;;     0800:0EC3 (in fn0800_0D20)
;;     0800:1096 (in fn0800_0D20)
;;     0800:1158 (in fn0800_0D20)
;;     1229:0124 (in fn1229_0040)
;;     1229:0330 (in fn1229_0040)
;;     1AB8:0BA4 (in fn1AB8_0AEE)
;;     1AB8:0F8D (in fn1AB8_0F80)
;;     1AB8:1020 (in fn1AB8_0F93)
;;     1AB8:1083 (in fn1AB8_1028)
;;     1AB8:14EA (in fn1AB8_1492)
fn1AB8_108B proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1ACEh
	mov	ax,[bp+8h]
	mov	[0B844h],ax
	mov	ax,[bp+6h]
	mov	[0B846h],ax
	pop	bp
	retf	4h
