;; fn0C74_02D8: 0C74:02D8
;;   Called from:
;;     0C74:06A2 (in fn0C74_05B8)
;;     0C74:0732 (in fn0C74_070D)
;;     0C74:0744 (in fn0C74_070D)
;;     0C74:1052 (in fn0C74_0FA1)
;;     0C74:1604 (in fn0C74_0FA1)
;;     0C74:16DE (in fn0C74_0FA1)
;;     0C74:185A (in fn0C74_0FA1)
;;     0C74:18CD (in fn0C74_0FA1)
;;     0C74:198D (in fn0C74_0FA1)
;;     0C74:1B03 (in fn0C74_0FA1)
;;     0C74:1C3B (in fn0C74_1B3B)
;;     0C74:1CB5 (in fn0C74_1B3B)
;;     0C74:1CC0 (in fn0C74_1B3B)
;;     0C74:1CCB (in fn0C74_1B3B)
;;     0C74:1CD8 (in fn0C74_1B3B)
;;     0C74:1CE3 (in fn0C74_1B3B)
;;     0C74:1CEE (in fn0C74_1B3B)
;;     0C74:1D7D (in fn0C74_1B3B)
;;     0C74:1FB9 (in fn0C74_1F08)
;;     0C74:256B (in fn0C74_1F08)
;;     0C74:2661 (in fn0C74_1F08)
;;     0C74:26DD (in fn0C74_1F08)
;;     0C74:2750 (in fn0C74_1F08)
;;     0C74:2909 (in fn0C74_1F08)
;;     0C74:2A9B (in fn0C74_1F08)
;;     0C74:2AE7 (in fn0C74_2AD9)
;;     0C74:2AF4 (in fn0C74_2AD9)
;;     0C74:2B96 (in fn0C74_2AD9)
;;     0C74:31D1 (in fn0C74_2E5A)
;;     0C74:35B0 (in fn0C74_3236)
;;     0C74:36A9 (in fn0C74_3615)
;;     0C74:3856 (in fn0C74_37C3)
;;     0C74:3CCE (in fn0C74_396E)
;;     0C74:3EBA (in fn0C74_396E)
;;     0C74:4316 (in fn0C74_3F74)
;;     0C74:4509 (in fn0C74_3F74)
;;     0C74:46B2 (in fn0C74_45CE)
;;     0C74:4723 (in fn0C74_45CE)
;;     0C74:4896 (in fn0C74_45CE)
;;     0C74:4ABA (in fn0C74_4999)
;;     0C74:4B2B (in fn0C74_4999)
;;     0C74:4CAA (in fn0C74_4999)
;;     0C74:4EDC (in fn0C74_4DAC)
;;     0C74:4F6C (in fn0C74_4DAC)
;;     0C74:50C5 (in fn0C74_4FD7)
;;     0C74:5150 (in fn0C74_4FD7)
fn0C74_02D8 proc
	enter	4h,0h
	cmp	byte ptr [58BEh],0h
	jnz	02EEh

l0C74_02E3:
	push	word ptr [bp+4h]
	call	far 1E78h:029Ch
	jmp	03AEh

l0C74_02EE:
	mov	ax,[bp+4h]
	xor	dx,dx
	mov	cx,7h
	div	cx
	mov	[bp+4h],ax
	mov	ax,[bp+4h]
	mov	[bp-4h],ax
	xor	ax,ax
	cmp	ax,[bp-4h]
	jbe	030Bh

l0C74_0308:
	jmp	03AEh

l0C74_030B:
	mov	[bp-2h],ax
	jmp	0313h

l0C74_0310:
	inc	word ptr [bp-2h]

l0C74_0313:
	mov	ax,[58D8h]
	mov	dx,[58DAh]
	mov	cx,3Ch
	xor	bx,bx
	call	far 1EDAh:098Ah
	mov	[58CCh],ax
	mov	[58CEh],dx
	mov	ax,[58D8h]
	mov	dx,[58DAh]
	mov	cx,3Ch
	xor	bx,bx
	call	far 1EDAh:098Ah
	mov	ax,cx
	mov	dx,bx
	mov	[58DCh],ax
	mov	[58DEh],dx
	mov	ax,[58DCh]
	mov	dx,[58DEh]
	cmp	dx,[58CAh]
	jnz	035Ah

l0C74_0354:
	cmp	ax,[58C8h]
	jz	036Eh

l0C74_035A:
	push	bp
	call	011Eh
	mov	ax,[58DCh]
	mov	dx,[58DEh]
	mov	[58C8h],ax
	mov	[58CAh],dx
	jmp	0375h

l0C74_036E:
	push	2h
	call	far 1E78h:029Ch

l0C74_0375:
	mov	ax,[58CCh]
	mov	dx,[58CEh]
	cmp	dx,[58C6h]
	jnz	0388h

l0C74_0382:
	cmp	ax,[58C4h]
	jz	039Ch

l0C74_0388:
	push	bp
	call	020Ch
	mov	ax,[58CCh]
	mov	dx,[58CEh]
	mov	[58C4h],ax
	mov	[58C6h],dx
	jmp	03A3h

l0C74_039C:
	push	2h
	call	far 1E78h:029Ch

l0C74_03A3:
	mov	ax,[bp-2h]
	cmp	ax,[bp-4h]
	jz	03AEh

l0C74_03AB:
	jmp	0310h

l0C74_03AE:
	leave
	ret	2h
0C74:03B2       07 52 41 44 2E 44 45 53 19 46 69 63 68 69   .RAD.DES.Fichi
0C74:03C0 65 72 20 64 65 20 44 6F 6E 6E 82 65 73 20 41 62 er de Donn.es Ab
0C74:03D0 73 65 6E 74                                     sent
