;; fn0C74_0D43: 0C74:0D43
;;   Called from:
;;     0C74:1CBA (in fn0C74_1B3B)
;;     0C74:1CD0 (in fn0C74_1B3B)
;;     0C74:1CE8 (in fn0C74_1B3B)
;;     0C74:2AEC (in fn0C74_2AD9)
;;     0C74:37E3 (in fn0C74_37C3)
fn0C74_0D43 proc
	enter	2h,0h
	mov	word ptr [5968h],0FFFFh
	mov	al,[bp+4h]
	mov	[bp-2h],al
	mov	al,1h
	cmp	al,[bp-2h]
	ja	0D90h

l0C74_0D5A:
	mov	[bp-1h],al
	jmp	0D62h

l0C74_0D5F:
	inc	byte ptr [bp-1h]

l0C74_0D62:
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
	mov	al,[bp-1h]
	cmp	al,[bp-2h]
	jnz	0D5Fh

l0C74_0D90:
	leave
	ret	2h
