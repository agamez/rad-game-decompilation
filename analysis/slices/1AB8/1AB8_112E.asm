;; fn1AB8_112E: 1AB8:112E
;;   Called from:
;;     0800:0A6E (in fn0800_09C2)
;;     0800:0DFB (in fn0800_0D20)
;;     0800:187A (in fn0800_184C)
;;     0800:1D22 (in fn0800_19E1)
;;     0800:31FF (in fn0800_31B7)
;;     0800:3E1C (in fn0800_3D9D)
;;     1229:00B7 (in fn1229_0040)
;;     1229:0CF2 (in fn1229_0CCE)
;;     133F:03C7 (in fn133F_0352)
fn1AB8_112E proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+0Ah]
	push	cs
	call	1AF6h
	push	word ptr [bp+8h]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1AF6h
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+6h]
	push	cs
	call	1AF6h
	push	word ptr [bp+0Ch]
	push	word ptr [bp+6h]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	cs
	call	1AF6h
	pop	bp
	retf	8h
