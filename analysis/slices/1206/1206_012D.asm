;; fn1206_012D: 1206:012D
;;   Called from:
;;     0800:33A7 (in fn0800_31B7)
;;     0800:4414 (in fn0800_4255)
;;     1206:0205 (in fn1206_01AC)
fn1206_012D proc
	enter	14h,0h
	cmp	byte ptr [597Eh],0h
	jnz	013Ah

l1206_0138:
	jmp	0157h

l1206_013A:
	mov	word ptr [bp-14h],8h
	mov	ax,[bp+8h]
	mov	[bp-10h],ax
	mov	ax,[bp+6h]
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh

l1206_0157:
	leave
	retf	4h
