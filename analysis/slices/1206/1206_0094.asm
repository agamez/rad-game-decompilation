;; fn1206_0094: 1206:0094
;;   Called from:
;;     0800:1D68 (in fn0800_1D55)
;;     0800:3863 (in fn0800_3850)
;;     1206:017B (in fn1206_015B)
;;     1206:01F1 (in fn1206_01AC)
fn1206_0094 proc
	enter	14h,0h
	cmp	byte ptr [597Eh],0h
	jnz	00A1h

l1206_009F:
	jmp	00CDh

l1206_00A1:
	mov	word ptr [bp-14h],3h
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	mov	ax,[bp-10h]
	les	di,[bp+0Ah]
	mov	es:[di],ax
	mov	ax,[bp-0Eh]
	les	di,[bp+6h]
	mov	es:[di],ax
	mov	ax,[bp-12h]
	les	di,[bp+0Eh]
	mov	es:[di],ax

l1206_00CD:
	leave
	retf	0Ch
