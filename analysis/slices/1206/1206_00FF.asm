;; fn1206_00FF: 1206:00FF
;;   Called from:
;;     0800:339C (in fn0800_31B7)
;;     0800:4409 (in fn0800_4255)
;;     1206:01FB (in fn1206_01AC)
fn1206_00FF proc
	enter	14h,0h
	cmp	byte ptr [597Eh],0h
	jnz	010Ch

l1206_010A:
	jmp	0129h

l1206_010C:
	mov	word ptr [bp-14h],7h
	mov	ax,[bp+8h]
	mov	[bp-10h],ax
	mov	ax,[bp+6h]
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh

l1206_0129:
	leave
	retf	4h
