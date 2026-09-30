;; fn0C74_0DE5: 0C74:0DE5
;;   Called from:
;;     0C74:1D89 (in fn0C74_1B3B)
;;     0C74:2BA2 (in fn0C74_2AD9)
fn0C74_0DE5 proc
	enter	2h,0h
	mov	word ptr [5968h],0FFFFh
	mov	al,[bp+4h]
	cmp	al,15h
	ja	0E2Ah

l0C74_0DF6:
	mov	[bp-1h],al
	jmp	0DFEh

l0C74_0DFB:
	inc	byte ptr [bp-1h]

l0C74_0DFE:
	push	64h
	push	14h
	call	070Dh
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5904h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-1h],15h
	jnz	0DFBh

l0C74_0E2A:
	leave
	ret	2h
