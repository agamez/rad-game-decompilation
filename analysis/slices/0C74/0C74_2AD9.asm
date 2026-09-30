;; fn0C74_2AD9: 0C74:2AD9
;;   Called from:
;;     0C74:51EC (in fn0C74_51B2)
;;     0C74:5220 (in fn0C74_51B2)
;;     0C74:54E2 (in fn0C74_54B1)
;;     0C74:5521 (in fn0C74_54F0)
fn0C74_2AD9 proc
	enter	6h,0h
	cmp	word ptr [5968h],1h
	jnz	2AF1h

l0C74_2AE4:
	push	0C8h
	call	02D8h
	push	0Bh
	call	0D43h
	jmp	2AFCh

l0C74_2AF1:
	push	0C8h
	call	02D8h
	push	0Bh
	call	0D94h

l0C74_2AFC:
	push	0h
	push	0h
	push	1Ch
	push	2Bh
	call	far 1AB8h:13A3h
	mov	[595Eh],ax
	push	word ptr [595Eh]
	call	far 1EDAh:023Fh
	mov	[bp-6h],ax
	mov	[bp-4h],dx
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	ax,[58B4h]
	add	ax,2Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Ch
	push	ax
	les	di,[bp-6h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	call	1F08h
	or	al,al
	jz	2B70h

l0C74_2B42:
	mov	ax,[58BAh]
	sub	ax,2Bh
	cmp	ax,[58B8h]
	jbe	2B70h

l0C74_2B4E:
	push	0C8h
	push	14h
	call	070Dh
	inc	word ptr [58B8h]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	les	di,[bp-6h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	jmp	2B42h

l0C74_2B70:
	cmp	byte ptr [58B3h],0h
	jz	2B79h

l0C74_2B77:
	jmp	2BBBh

l0C74_2B79:
	mov	ax,[58E6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[4D0Ch]
	xor	dx,dx
	call	far 1EDAh:096Fh
	mov	cx,4h
	xor	bx,bx
	call	far 1EDAh:098Ah
	push	ax
	call	02D8h
	cmp	word ptr [5968h],1h
	jnz	2BA7h

l0C74_2BA0:
	push	0Bh
	call	0DE5h
	jmp	2BACh

l0C74_2BA7:
	push	0Bh
	call	0CFAh

l0C74_2BAC:
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	push	word ptr [595Eh]
	call	far 1EDAh:0254h

l0C74_2BBB:
	leave
	ret
