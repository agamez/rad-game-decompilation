;; fn0800_0024: 0800:0024
;;   Called from:
;;     0800:0297 (in fn0800_01FE)
;;     0800:0DEC (in fn0800_0D20)
;;     0800:108B (in fn0800_0D20)
;;     0800:113E (in fn0800_0D20)
;;     0800:1FB0 (in fn0800_1E3F)
;;     0800:320F (in fn0800_31B7)
;;     0800:3BED (in fn0800_391E)
fn0800_0024 proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	push	1h
	call	far 1AB8h:0F93h
	call	far 1AB8h:1028h
	push	0h
	push	0h
	call	far 1AB8h:10CEh
	push	ax
	call	far 1AB8h:10E1h
	push	ax
	push	1h
	call	far 1AB8h:0F93h
	leave
	ret	8h
