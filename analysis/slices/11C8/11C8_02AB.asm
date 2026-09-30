;; fn11C8_02AB: 11C8:02AB
;;   Called from:
;;     11C8:03A8 (in fn11C8_0394)
;;     11C8:03CA (in fn11C8_03BB)
fn11C8_02AB proc
	enter	2h,0h
	mov	byte ptr [bp-1h],1h
	jmp	02B8h

l11C8_02B5:
	inc	byte ptr [bp-1h]

l11C8_02B8:
	mov	al,[bp-1h]
	push	ax
	call	0282h
	push	0h
	call	0296h
	cmp	byte ptr [bp-1h],0F5h
	jnz	02B5h

l11C8_02CA:
	leave
	ret
