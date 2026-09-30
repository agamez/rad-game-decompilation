;; fn0C74_0FA1: 0C74:0FA1
;;   Called from:
;;     0C74:1D16 (in fn0C74_1B3B)
fn0C74_0FA1 proc
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

l0C74_11EC:
	cmp	word ptr [bp-4h],14h
	jc	11F5h

l0C74_11F2:
	jmp	12E2h

l0C74_11F5:
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	1212h

l0C74_120F:
	jmp	12E2h

l0C74_1212:
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	122Fh

l0C74_122C:
	jmp	12E2h

l0C74_122F:
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	124Ch

l0C74_1249:
	jmp	12E2h

l0C74_124C:
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	12E2h

l0C74_1266:
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	12E2h

l0C74_1280:
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	12E2h

l0C74_129A:
	push	0E6h
	push	19h
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
	jmp	11ECh

l0C74_12E2:
	cmp	word ptr [bp-4h],14h
	jz	130Fh

l0C74_12E8:
	push	bp
	call	0E2Eh
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	push	word ptr [bp-12h]
	push	word ptr [bp-14h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-1h],0h
	jmp	1B36h

l0C74_130F:
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
	jz	1333h

l0C74_1330:
	jmp	1487h

l0C74_1333:
	cmp	word ptr [bp-4h],41h
	jnc	1397h

l0C74_1339:
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1397h

l0C74_1353:
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1397h

l0C74_136D:
	push	0E6h
	push	19h
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
	jmp	1333h

l0C74_1397:
	cmp	word ptr [bp-4h],41h
	jnz	13A0h

l0C74_139D:
	jmp	147Bh

l0C74_13A0:
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
	jc	144Dh

l0C74_141A:
	mov	[bp-6h],ax
	jmp	1422h

l0C74_141F:
	dec	word ptr [bp-6h]

l0C74_1422:
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
	jnz	141Fh

l0C74_144D:
	push	word ptr [bp-12h]
	push	word ptr [bp-14h]
	push	word ptr [bp-22h]
	call	far 1EDAh:0254h
	mov	word ptr [bp-4h],14h
	push	bp
	call	0E2Eh
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-1h],0h
	jmp	1B36h
0C74:1479                            EB 0C                         ..     

l0C74_147B:
	mov	ax,[58B4h]
	add	ax,1Ah
	add	ax,[bp-4h]
	mov	[bp-0Ah],ax

l0C74_1487:
	cmp	word ptr [5968h],1h
	jz	1491h

l0C74_148E:
	jmp	15E7h

l0C74_1491:
	cmp	word ptr [bp-4h],41h
	jnc	14F5h

l0C74_1497:
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	14F5h

l0C74_14B1:
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,[bp-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	14F5h

l0C74_14CB:
	push	0E6h
	push	19h
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
	jmp	1491h

l0C74_14F5:
	cmp	word ptr [bp-4h],41h
	jnz	14FEh

l0C74_14FB:
	jmp	15D9h

l0C74_14FE:
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
	jc	15ABh

l0C74_1578:
	mov	[bp-6h],ax
	jmp	1580h

l0C74_157D:
	dec	word ptr [bp-6h]

l0C74_1580:
	push	0E6h
	push	19h
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
	jnz	157Dh

l0C74_15AB:
	mov	word ptr [bp-4h],14h
	push	bp
	call	0E2Eh
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-22h]
	call	far 1EDAh:0254h
	push	word ptr [bp-12h]
	push	word ptr [bp-14h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-1h],0h
	jmp	1B36h
0C74:15D7                      EB 0E                             ..       

l0C74_15D9:
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,[bp-4h]
	inc	ax
	inc	ax
	mov	[bp-0Ch],ax

l0C74_15E7:
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

l0C74_1619:
	push	word ptr [bp-0Ch]
	push	word ptr [bp-6h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	163Ah

l0C74_1628:
	push	word ptr [bp-0Ah]
	push	word ptr [bp-4h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	163Ah

l0C74_1637:
	jmp	16C1h

l0C74_163A:
	push	word ptr [bp-0Ch]
	push	word ptr [bp-6h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1678h

l0C74_1649:
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

l0C74_1678:
	push	word ptr [bp-0Ah]
	push	word ptr [bp-4h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	16B6h

l0C74_1687:
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

l0C74_16B6:
	push	0FAh
	push	1Eh
	call	070Dh
	jmp	1619h

l0C74_16C1:
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
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,0Eh
	push	ax
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	call	far 1AB8h:13A3h
	mov	[bp-1Eh],ax
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
	dec	word ptr [58BAh]
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,0Eh
	push	ax
	les	di,[bp-18h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [bp-16h]
	push	word ptr [bp-18h]
	push	word ptr [bp-1Eh]
	call	far 1EDAh:0254h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	call	far 1AB8h:1C32h
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,0Dh
	push	ax
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-1Eh],ax
	push	word ptr [bp-1Eh]
	call	far 1EDAh:023Fh
	mov	[bp-18h],ax
	mov	[bp-16h],dx
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,0Dh
	push	ax
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	les	di,[bp-18h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh

l0C74_17C1:
	push	64h
	push	3Ch
	call	070Dh
	dec	word ptr [58BAh]
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,0Dh
	push	ax
	les	di,[bp-18h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	ax,[58B8h]
	add	ax,2Bh
	cmp	ax,[58BAh]
	jnz	17C1h

l0C74_17EF:
	push	word ptr [bp-16h]
	push	word ptr [bp-18h]
	push	word ptr [bp-1Eh]
	call	far 1EDAh:0254h
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
	jmp	1867h

l0C74_1864:
	inc	word ptr [bp-8h]

l0C74_1867:
	push	32h
	push	28h
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
	jnz	1864h

l0C74_18B0:
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
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	call	far 1AB8h:1C32h

l0C74_18F0:
	mov	ax,[58B8h]
	add	ax,1Ch
	cmp	ax,[bp-6h]
	jc	1906h

l0C74_18FB:
	mov	ax,[58B8h]
	add	ax,1Ch
	cmp	ax,[bp-4h]
	jnc	1954h

l0C74_1906:
	mov	ax,[58B8h]
	add	ax,1Ch
	cmp	ax,[bp-6h]
	jnc	1928h

l0C74_1911:
	dec	word ptr [bp-6h]
	push	word ptr [bp-0Ch]
	push	word ptr [bp-6h]
	mov	ax,[bp-0Ch]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp-6h]
	call	far 1AB8h:1AF6h

l0C74_1928:
	mov	ax,[58B8h]
	add	ax,1Ch
	cmp	ax,[bp-4h]
	jnc	194Ah

l0C74_1933:
	dec	word ptr [bp-4h]
	push	word ptr [bp-0Ah]
	push	word ptr [bp-4h]
	mov	ax,[bp-0Ah]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp-4h]
	call	far 1AB8h:1AF6h

l0C74_194A:
	push	0FAh
	push	1Eh
	call	070Dh
	jmp	18F0h

l0C74_1954:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	push	word ptr [bp-12h]
	push	word ptr [bp-14h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
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
	jc	1A27h

l0C74_19F9:
	mov	[bp-6h],ax
	jmp	1A01h

l0C74_19FE:
	dec	word ptr [bp-6h]

l0C74_1A01:
	push	0E6h
	push	19h
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
	jnz	19FEh

l0C74_1A27:
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
	ja	1ACFh

l0C74_1AA1:
	mov	[bp-6h],ax
	jmp	1AA9h

l0C74_1AA6:
	inc	word ptr [bp-6h]

l0C74_1AA9:
	push	0E6h
	push	19h
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
	jnz	1AA6h

l0C74_1ACF:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	word ptr [bp-20h]
	call	far 1EDAh:0254h
	mov	word ptr [bp-4h],13h
	push	bp
	call	0E2Eh
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
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1B36h

l0C74_1B1C:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1B36h

l0C74_1B2E:
	push	cs
	call	05B8h
	push	cs
	call	0A35h

l0C74_1B36:
	mov	al,[bp-1h]
	leave
	ret
