;; fn1206_00D1: 1206:00D1
;;   Called from:
;;     0800:33B2 (in fn0800_31B7)
;;     0800:441E (in fn0800_4255)
;;     1206:020F (in fn1206_01AC)
fn1206_00D1 proc
	enter	14h,0h
	cmp	byte ptr [597Eh],0h
	jnz	00DEh

l1206_00DC:
	jmp	00FBh

l1206_00DE:
	mov	word ptr [bp-14h],4h
	mov	ax,[bp+8h]
	mov	[bp-10h],ax
	mov	ax,[bp+6h]
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh

l1206_00FB:
	leave
	retf	4h
