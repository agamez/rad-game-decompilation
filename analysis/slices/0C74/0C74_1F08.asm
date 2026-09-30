;; fn0C74_1F08: 0C74:1F08
;;   Called from:
;;     0C74:2B3B (in fn0C74_2AD9)
fn0C74_1F08 proc
	enter	2Ah,0h
	push	19h
	push	0Dh
	push	1Ch
	push	1Bh
	call	far 1AB8h:13A3h
	mov	[bp-20h],ax
	push	word ptr [bp-20h]
	call	far 1EDAh:023Fh
	mov	[bp-10h],ax
	mov	[bp-0Eh],dx
	push	word ptr [bp-20h]
	call	far 1EDAh:023Fh
	mov	[bp-14h],ax
	mov	[bp-12h],dx
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-14h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,0Eh
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-10h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,0Eh
	mov	[bp-24h],ax
	mov	ax,[58B4h]
	add	ax,19h
	mov	[bp-26h],ax
	dec	word ptr [bp-24h]
	inc	word ptr [bp-26h]
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
	push	word ptr [bp-24h]
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-10h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [bp-26h]
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-14h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	push	word ptr [bp-12h]
	push	word ptr [bp-14h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	push	0Bh
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	push	3h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	push	9h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	push	0Bh
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	push	3h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	push	9h
	call	far 1AB8h:1E54h
	push	19h
	push	0Dh
	push	1Dh
	push	1Bh
	call	far 1AB8h:13A3h
	mov	[bp-20h],ax
	push	word ptr [bp-20h]
	call	far 1EDAh:023Fh
	mov	[bp-10h],ax
	mov	[bp-0Eh],dx
	push	word ptr [bp-20h]
	call	far 1EDAh:023Fh
	mov	[bp-14h],ax
	mov	[bp-12h],dx
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Dh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-14h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-10h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	word ptr [bp-4h],1h

l0C74_2153:
	cmp	word ptr [bp-4h],14h
	jc	215Ch

l0C74_2159:
	jmp	2249h

l0C74_215C:
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	2179h

l0C74_2176:
	jmp	2249h

l0C74_2179:
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	2196h

l0C74_2193:
	jmp	2249h

l0C74_2196:
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	21B3h

l0C74_21B0:
	jmp	2249h

l0C74_21B3:
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2249h

l0C74_21CD:
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2249h

l0C74_21E7:
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2249h

l0C74_2201:
	push	0E6h
	push	0Fh
	call	070Dh
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-10h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-14h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	inc	word ptr [bp-4h]
	jmp	2153h

l0C74_2249:
	cmp	word ptr [bp-4h],14h
	jz	2276h

l0C74_224F:
	push	bp
	call	1D95h
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	push	word ptr [bp-12h]
	push	word ptr [bp-14h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-1h],0h
	jmp	2AD4h

l0C74_2276:
	mov	ax,[58B4h]
	add	ax,1Ah
	add	ax,[bp-4h]
	mov	[bp-0Ah],ax
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,[bp-4h]
	inc	ax
	inc	ax
	mov	[bp-0Ch],ax
	cmp	word ptr [5968h],0FFh
	jz	229Ah

l0C74_2297:
	jmp	23EEh

l0C74_229A:
	cmp	word ptr [bp-4h],41h
	jnc	22FEh

l0C74_22A0:
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	22FEh

l0C74_22BA:
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	22FEh

l0C74_22D4:
	push	0E6h
	push	0Fh
	call	070Dh
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-14h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	inc	word ptr [bp-4h]
	jmp	229Ah

l0C74_22FE:
	cmp	word ptr [bp-4h],41h
	jnz	2307h

l0C74_2304:
	jmp	23E2h

l0C74_2307:
	push	word ptr [bp-12h]
	push	word ptr [bp-14h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Dh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-22h],ax
	push	word ptr [bp-22h]
	call	far 1EDAh:023Fh
	mov	[bp-14h],ax
	mov	[bp-12h],dx
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Dh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-14h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[bp-4h]
	cmp	ax,13h
	jc	23B4h

l0C74_2381:
	mov	[bp-6h],ax
	jmp	2389h

l0C74_2386:
	dec	word ptr [bp-6h]

l0C74_2389:
	push	0E6h
	push	19h
	call	070Dh
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,[bp-6h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-14h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	word ptr [bp-6h],13h
	jnz	2386h

l0C74_23B4:
	mov	word ptr [bp-4h],14h
	push	bp
	call	1D95h
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	push	word ptr [bp-12h]
	push	word ptr [bp-14h]
	push	word ptr [bp-22h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-1h],0h
	jmp	2AD4h
0C74:23E0 EB 0C                                           ..              

l0C74_23E2:
	mov	ax,[58B4h]
	add	ax,1Ah
	add	ax,[bp-4h]
	mov	[bp-0Ah],ax

l0C74_23EE:
	cmp	word ptr [5968h],1h
	jz	23F8h

l0C74_23F5:
	jmp	254Eh

l0C74_23F8:
	cmp	word ptr [bp-4h],41h
	jnc	245Ch

l0C74_23FE:
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	245Ch

l0C74_2418:
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	245Ch

l0C74_2432:
	push	0E6h
	push	0Fh
	call	070Dh
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-10h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	inc	word ptr [bp-4h]
	jmp	23F8h

l0C74_245C:
	cmp	word ptr [bp-4h],41h
	jnz	2465h

l0C74_2462:
	jmp	2540h

l0C74_2465:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-22h],ax
	push	word ptr [bp-22h]
	call	far 1EDAh:023Fh
	mov	[bp-10h],ax
	mov	[bp-0Eh],dx
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-10h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[bp-4h]
	cmp	ax,13h
	jc	2512h

l0C74_24DF:
	mov	[bp-6h],ax
	jmp	24E7h

l0C74_24E4:
	dec	word ptr [bp-6h]

l0C74_24E7:
	push	0E6h
	push	0Fh
	call	070Dh
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,[bp-6h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-10h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	word ptr [bp-6h],13h
	jnz	24E4h

l0C74_2512:
	mov	word ptr [bp-4h],14h
	push	bp
	call	1D95h
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-22h]
	call	far 1EDAh:0254h
	push	word ptr [bp-12h]
	push	word ptr [bp-14h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-1h],0h
	jmp	2AD4h
0C74:253E                                           EB 0E               ..

l0C74_2540:
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,[bp-4h]
	inc	ax
	inc	ax
	mov	[bp-0Ch],ax

l0C74_254E:
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
	mov	ax,[58B8h]
	add	ax,1Ch
	mov	[bp-4h],ax
	mov	ax,[58B8h]
	add	ax,1Ch
	mov	[bp-6h],ax

l0C74_2580:
	push	word ptr [bp-0Ch]
	push	word ptr [bp-6h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	25A1h

l0C74_258F:
	push	word ptr [bp-0Ah]
	push	word ptr [bp-4h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	25A1h

l0C74_259E:
	jmp	2644h

l0C74_25A1:
	mov	ax,[58BAh]
	add	ax,59h
	cmp	ax,[bp-4h]
	ja	25AFh

l0C74_25AC:
	jmp	2644h

l0C74_25AF:
	mov	ax,[58BAh]
	add	ax,59h
	cmp	ax,[bp-6h]
	ja	25BDh

l0C74_25BA:
	jmp	2644h

l0C74_25BD:
	push	word ptr [bp-0Ch]
	push	word ptr [bp-6h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	25FBh

l0C74_25CC:
	push	word ptr [bp-0Ch]
	push	word ptr [bp-6h]
	push	0Bh
	call	far 1AB8h:1E54h
	mov	ax,[bp-0Ch]
	inc	ax
	push	ax
	push	word ptr [bp-6h]
	push	3h
	call	far 1AB8h:1E54h
	mov	ax,[bp-0Ch]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp-6h]
	push	9h
	call	far 1AB8h:1E54h
	inc	word ptr [bp-6h]

l0C74_25FB:
	push	word ptr [bp-0Ah]
	push	word ptr [bp-4h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2639h

l0C74_260A:
	push	word ptr [bp-0Ah]
	push	word ptr [bp-4h]
	push	0Bh
	call	far 1AB8h:1E54h
	mov	ax,[bp-0Ah]
	inc	ax
	push	ax
	push	word ptr [bp-4h]
	push	3h
	call	far 1AB8h:1E54h
	mov	ax,[bp-0Ah]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp-4h]
	push	9h
	call	far 1AB8h:1E54h
	inc	word ptr [bp-4h]

l0C74_2639:
	push	0FAh
	push	0Fh
	call	070Dh
	jmp	2580h

l0C74_2644:
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
	mov	ax,[58BAh]
	add	ax,59h
	cmp	ax,[bp-4h]
	ja	2672h

l0C74_266F:
	jmp	2761h

l0C74_2672:
	mov	ax,[58BAh]
	add	ax,59h
	cmp	ax,[bp-6h]
	ja	2680h

l0C74_267D:
	jmp	2761h

l0C74_2680:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	call	far 1AB8h:13A3h
	mov	[bp-28h],ax
	push	word ptr [bp-28h]
	call	far 1EDAh:023Fh
	mov	[bp-1Ch],ax
	mov	[bp-1Ah],dx
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	les	di,[bp-1Ch]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
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
	mov	word ptr [bp-8h],1h
	jmp	26EAh

l0C74_26E7:
	inc	word ptr [bp-8h]

l0C74_26EA:
	push	32h
	push	14h
	call	070Dh
	mov	ax,[5968h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	mov	[58B4h],ax
	mov	ax,[5968h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B6h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	mov	[58B6h],ax
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	les	di,[bp-1Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	word ptr [bp-8h],2Ch
	jnz	26E7h

l0C74_2733:
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
	push	word ptr [bp-1Ah]
	push	word ptr [bp-1Ch]
	push	word ptr [bp-28h]
	call	far 1EDAh:0254h

l0C74_2761:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	2776h

l0C74_2773:
	jmp	2876h

l0C74_2776:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	278Bh

l0C74_2788:
	jmp	2876h

l0C74_278B:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,0Eh
	push	ax
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	call	far 1AB8h:13A3h
	mov	[bp-1Eh],ax
	mov	ax,[58B4h]
	add	ax,17h
	push	ax
	mov	ax,[58BAh]
	sub	ax,0Eh
	push	ax
	push	3h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,18h
	push	ax
	mov	ax,[58BAh]
	sub	ax,0Eh
	push	ax
	push	1h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58BAh]
	sub	ax,0Eh
	push	ax
	push	1h
	call	far 1AB8h:1E54h
	push	word ptr [bp-1Eh]
	call	far 1EDAh:023Fh
	mov	[bp-18h],ax
	mov	[bp-16h],dx
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,0Eh
	push	ax
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	les	di,[bp-18h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	xor	ax,ax
	mov	[bp-8h],ax

l0C74_2815:
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2868h

l0C74_2828:
	mov	ax,[58B6h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2868h

l0C74_283B:
	cmp	word ptr [bp-8h],59h
	jnc	2868h

l0C74_2841:
	push	64h
	push	1Eh
	call	070Dh
	inc	word ptr [58BAh]
	inc	word ptr [bp-8h]
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,0Eh
	push	ax
	les	di,[bp-18h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	jmp	2815h

l0C74_2868:
	push	word ptr [bp-16h]
	push	word ptr [bp-18h]
	push	word ptr [bp-1Eh]
	call	far 1EDAh:0254h

l0C74_2876:
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	call	far 1AB8h:1C32h

l0C74_2888:
	mov	ax,[58B8h]
	add	ax,1Ch
	cmp	ax,[bp-6h]
	jc	289Eh

l0C74_2893:
	mov	ax,[58B8h]
	add	ax,1Ch
	cmp	ax,[bp-4h]
	jnc	28ECh

l0C74_289E:
	mov	ax,[58B8h]
	add	ax,1Ch
	cmp	ax,[bp-6h]
	jnc	28C0h

l0C74_28A9:
	dec	word ptr [bp-6h]
	push	word ptr [bp-0Ch]
	push	word ptr [bp-6h]
	mov	ax,[bp-0Ch]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp-6h]
	call	far 1AB8h:1AF6h

l0C74_28C0:
	mov	ax,[58B8h]
	add	ax,1Ch
	cmp	ax,[bp-4h]
	jnc	28E2h

l0C74_28CB:
	dec	word ptr [bp-4h]
	push	word ptr [bp-0Ah]
	push	word ptr [bp-4h]
	mov	ax,[bp-0Ah]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp-4h]
	call	far 1AB8h:1AF6h

l0C74_28E2:
	push	0FAh
	push	0Fh
	call	070Dh
	jmp	2888h

l0C74_28EC:
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
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	push	word ptr [bp-12h]
	push	word ptr [bp-14h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	mov	ax,[bp-0Ah]
	dec	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[bp-0Ah]
	add	ax,4h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-20h],ax
	push	word ptr [bp-20h]
	call	far 1EDAh:023Fh
	mov	[bp-14h],ax
	mov	[bp-12h],dx
	mov	ax,[bp-0Ah]
	dec	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[bp-0Ah]
	add	ax,4h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-14h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,13h
	mov	[bp-2Ah],ax
	mov	ax,[bp-0Ah]
	dec	ax
	cmp	ax,[bp-2Ah]
	jc	29BFh

l0C74_2991:
	mov	[bp-6h],ax
	jmp	2999h

l0C74_2996:
	dec	word ptr [bp-6h]

l0C74_2999:
	push	0E6h
	push	0Ch
	call	070Dh
	push	word ptr [bp-6h]
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-14h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	ax,[bp-6h]
	cmp	ax,[bp-2Ah]
	jnz	2996h

l0C74_29BF:
	push	word ptr [bp-12h]
	push	word ptr [bp-14h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	mov	ax,[bp-0Ch]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[bp-0Ch]
	add	ax,3h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-20h],ax
	push	word ptr [bp-20h]
	call	far 1EDAh:023Fh
	mov	[bp-10h],ax
	mov	[bp-0Eh],dx
	mov	ax,[bp-0Ch]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[bp-0Ch]
	add	ax,3h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-10h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,13h
	mov	[bp-2Ah],ax
	mov	ax,[bp-0Ch]
	dec	ax
	dec	ax
	cmp	ax,[bp-2Ah]
	ja	2A67h

l0C74_2A39:
	mov	[bp-6h],ax
	jmp	2A41h

l0C74_2A3E:
	inc	word ptr [bp-6h]

l0C74_2A41:
	push	0E6h
	push	0Ch
	call	070Dh
	push	word ptr [bp-6h]
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-10h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	ax,[bp-6h]
	cmp	ax,[bp-2Ah]
	jnz	2A3Eh

l0C74_2A67:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	mov	word ptr [bp-4h],13h
	push	bp
	call	1D95h
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
	mov	byte ptr [bp-1h],1h
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2AD4h

l0C74_2AB5:
	mov	ax,[58B6h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2AD4h

l0C74_2AC8:
	push	cs
	call	05B8h
	push	cs
	call	0A35h
	mov	byte ptr [bp-1h],0h

l0C74_2AD4:
	mov	al,[bp-1h]
	leave
	ret
