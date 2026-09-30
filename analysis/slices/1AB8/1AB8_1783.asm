;; fn1AB8_1783: 1AB8:1783
;;   Called from:
;;     0800:1047 (in fn0800_0D20)
;;     0800:1073 (in fn0800_0D20)
;;     0800:10EE (in fn0800_0D20)
;;     0800:1126 (in fn0800_0D20)
;;     0800:1A7F (in fn0800_19E1)
;;     0800:1AA3 (in fn0800_19E1)
;;     1229:02C5 (in fn1229_0040)
;;     1229:02FD (in fn1229_0040)
;;     133F:0194 (in fn133F_014B)
;;     133F:01BC (in fn133F_014B)
fn1AB8_1783 proc
	push	bp
	mov	bp,sp
	sub	sp,102h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	push	cs
	call	1E26h
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf	4h
