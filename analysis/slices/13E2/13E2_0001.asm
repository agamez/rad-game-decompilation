;; fn13E2_0001: 13E2:0001
;;   Called from:
;;     0800:4354 (in fn0800_4255)
fn13E2_0001 proc
	enter	8h,0h
	xor	ax,ax
	mov	[bp-4h],ax
	lea	di,[bp-4h]
	push	ss
	push	di
	lea	di,[bp-6h]
	push	ss
	push	di
	mov	di,0h
	push	cs
	push	di
	call	far 1AB8h:0BAEh
	call	far 1AB8h:04F3h
	mov	[bp-8h],ax
	cmp	word ptr [bp-8h],0h
	jz	0032h

l13E2_002C:
	mov	byte ptr [bp-1h],0h
	jmp	0036h

l13E2_0032:
	mov	byte ptr [bp-1h],1h

l13E2_0036:
	mov	al,[bp-1h]
	leave
	retf
