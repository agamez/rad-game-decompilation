;; fn133F_04B1: 133F:04B1
;;   Called from:
;;     1229:0DA3 (in fn1229_0CCE)
;;     133F:0505 (in fn133F_04DE)
fn133F_04B1 proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	0200h
	push	word ptr [bp+0Ch]
	push	word ptr [bp+8h]
	call	far 13C8h:00BFh
	push	word ptr [bp+0Ah]
	push	word ptr [bp+6h]
	call	far 13C8h:00E4h
	leave
	retf	8h
