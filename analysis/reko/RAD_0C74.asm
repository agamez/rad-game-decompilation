;;; Segment 0C74 (0C74:0000)

;; fn0C74_0000: 0C74:0000
;;   Called from:
;;     0800:0161 (in fn0800_0147)
;;     0800:0404 (in fn0800_03F8)
;;     0800:1240 (in fn0800_11EF)
;;     0800:240A (in fn0800_2401)
;;     0800:2830 (in fn0800_2827)
;;     0800:4171 (in fn0800_4168)
;;     0C74:03DD (in fn0C74_03D4)
fn0C74_0000 proc
	enter	12Eh,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	push	3Fh
	lea	di,[bp+0FED2h]
	push	ss
	push	di
	call	far 1E5Fh:00DEh
	cmp	word ptr [0B8A6h],0h
	jz	0038h

l0C74_0031:
	mov	byte ptr [bp+0FEFDh],0h
	jmp	003Dh

l0C74_0038:
	mov	byte ptr [bp+0FEFDh],1h

l0C74_003D:
	mov	al,[bp+0FEFDh]
	mov	[bp-1h],al
	mov	al,[bp-1h]
	leave
	retf	4h

;; fn0C74_004B: 0C74:004B
;;   Called from:
;;     0800:052D (in fn0800_04E3)
;;     0800:0553 (in fn0800_04E3)
;;     0800:0579 (in fn0800_04E3)
;;     0800:05A6 (in fn0800_04E3)
;;     0800:05CC (in fn0800_04E3)
;;     0800:05F2 (in fn0800_04E3)
;;     0800:065F (in fn0800_0619)
;;     0800:0AB3 (in fn0800_0AA1)
;;     0800:0B54 (in fn0800_0B42)
;;     0800:225A (in fn0800_21E7)
;;     0C74:0130 (in fn0C74_011E)
;;     0C74:021E (in fn0C74_020C)
fn0C74_004B proc
	enter	100h,0h
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	0h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0F26h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	retf	4h

;; fn0C74_007C: 0C74:007C
;;   Called from:
;;     0C74:058E (in fn0C74_03D4)
fn0C74_007C proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	push	1h
	call	far 1AB8h:0F93h
	call	far 1AB8h:1028h
	push	0h
	push	0h
	call	far 1AB8h:10CEh
	push	ax
	call	far 1AB8h:10E1h
	push	ax
	push	1h
	call	far 1AB8h:0F93h
	leave
	ret	8h

;; fn0C74_00B2: 0C74:00B2
;;   Called from:
;;     0800:019E (in fn0800_0147)
;;     0800:0463 (in fn0800_03F8)
;;     0C74:0472 (in fn0C74_03D4)
fn0C74_00B2 proc
	push	bp
	mov	bp,sp
	push	word ptr [58E2h]
	push	1D5h
	mov	al,[bp+6h]
	xor	ah,ah
	add	ax,[58E2h]
	push	ax
	push	1DFh
	call	far 1AB8h:1B3Eh
	mov	al,[bp+6h]
	xor	ah,ah
	add	[58E2h],ax
	leave
	retf	2h

;; fn0C74_00DB: 0C74:00DB
;;   Called from:
;;     0C74:0198 (in fn0C74_011E)
;;     0C74:0286 (in fn0C74_020C)
fn0C74_00DB proc
	push	bp
	mov	bp,sp
	push	1h
	push	3h
	call	far 1AB8h:1175h
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	call	far 1AB8h:1B3Eh
	leave
	ret	0Ah
0C74:00FC                                     01 30 00 E2             .0..
0C74:0100 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0C74:0110 00 00 00 00 00 00 00 00 00 00 00 00 00 00       ..............  

;; fn0C74_011E: 0C74:011E
;;   Called from:
;;     0C74:035B (in fn0C74_02D8)
fn0C74_011E proc
	enter	106h,0h
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	push	word ptr [58DEh]
	push	word ptr [58DCh]
	push	cs
	call	004Bh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp-4h],2h
	jnc	016Ch

l0C74_0146:
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	mov	di,0FCh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h

l0C74_016C:
	call	far 1AB8h:1285h
	mov	[bp-6h],ax
	mov	al,[58E4h]
	push	ax
	mov	di,0FEh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	0189h

l0C74_0184:
	call	far 1206h:0066h

l0C74_0189:
	push	24Bh
	push	192h
	push	25Ch
	push	19Bh
	push	word ptr [bp+4h]
	call	00DBh
	push	8h
	call	far 1AB8h:1C32h
	push	253h
	push	196h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	254h
	push	197h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	mov	al,[58E4h]
	push	ax
	mov	di,0FEh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	01DEh

l0C74_01D9:
	call	far 1206h:0038h

l0C74_01DE:
	push	word ptr [bp-6h]
	call	far 1AB8h:1C32h
	leave
	ret	2h
0C74:01EA                               01 30 00 E2 01 00           .0....
0C74:01F0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0C74:0200 00 00 00 00 00 00 00 00 00 00 00 00             ............    

;; fn0C74_020C: 0C74:020C
;;   Called from:
;;     0C74:0389 (in fn0C74_02D8)
fn0C74_020C proc
	enter	106h,0h
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	push	word ptr [58CEh]
	push	word ptr [58CCh]
	push	cs
	call	004Bh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp-4h],2h
	jnc	025Ah

l0C74_0234:
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	mov	di,1EAh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h

l0C74_025A:
	call	far 1AB8h:1285h
	mov	[bp-6h],ax
	mov	al,[58E4h]
	push	ax
	mov	di,1ECh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	0277h

l0C74_0272:
	call	far 1206h:0066h

l0C74_0277:
	push	233h
	push	192h
	push	244h
	push	19Bh
	push	word ptr [bp+4h]
	call	00DBh
	push	8h
	call	far 1AB8h:1C32h
	push	23Bh
	push	196h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	23Ch
	push	197h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	word ptr [bp-6h]
	call	far 1AB8h:1C32h
	mov	al,[58E4h]
	push	ax
	mov	di,1ECh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	02D4h

l0C74_02CF:
	call	far 1206h:0038h

l0C74_02D4:
	leave
	ret	2h

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

;; fn0C74_03D4: 0C74:03D4
;;   Called from:
;;     0800:43F6 (in fn0800_4255)
fn0C74_03D4 proc
	enter	8Ah,0h
	mov	di,3B2h
	push	cs
	push	di
	push	cs
	call	0000h
	or	al,al
	jnz	0415h

l0C74_03E5:
	call	far 1AB8h:0EB5h
	call	far 1AB8h:0E88h
	push	word ptr [0B8ACh]
	call	far 1E78h:016Bh
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,3BAh
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	xor	ax,ax
	call	far 1EDAh:00E9h

l0C74_0415:
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	di,3B2h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	push	word ptr [4D0Eh]
	call	far 1EDAh:0FD0h
	push	0h
	push	0h
	push	2Bh
	push	18h
	call	far 1AB8h:13A3h
	mov	[bp+0FF78h],ax
	push	0h
	push	0h
	push	2Bh
	push	2Bh
	call	far 1AB8h:13A3h
	mov	[bp+0FF76h],ax
	push	word ptr [4D0Eh]
	call	far 1EDAh:023Fh
	mov	[bp+0FF7Ah],ax
	mov	[bp+0FF7Ch],dx
	mov	byte ptr [bp-1h],1h
	jmp	0470h

l0C74_046D:
	inc	byte ptr [bp-1h]

l0C74_0470:
	push	5h
	push	cs
	call	00B2h
	mov	al,[bp-1h]
	cmp	al,1h
	jc	04C4h

l0C74_047D:
	cmp	al,4h
	ja	04C4h

l0C74_0481:
	push	word ptr [4D0Eh]
	call	far 1EDAh:023Fh
	mov	cx,ax
	mov	bx,dx
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	mov	[di+58E4h],cx
	mov	[di+58E6h],bx
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+58E4h]
	push	es
	push	di
	push	1h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	jmp	0586h

l0C74_04C4:
	cmp	al,5h
	jc	0538h

l0C74_04C8:
	cmp	al,19h
	ja	0538h

l0C74_04CC:
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	les	di,[bp+0FF7Ah]
	push	es
	push	di
	push	1h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	push	0h
	push	0h
	les	di,[bp+0FF7Ah]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [bp+0FF78h]
	call	far 1EDAh:023Fh
	mov	cx,ax
	mov	bx,dx
	mov	al,[bp-1h]
	xor	ah,ah
	sub	ax,4h
	mov	di,ax
	shl	di,2h
	mov	[di+5904h],cx
	mov	[di+5906h],bx
	push	0h
	push	0h
	push	2Bh
	push	18h
	mov	al,[bp-1h]
	xor	ah,ah
	sub	ax,4h
	mov	di,ax
	shl	di,2h
	les	di,[di+5904h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	jmp	0586h

l0C74_0538:
	cmp	al,1Ah
	jc	0586h

l0C74_053C:
	cmp	al,1Dh
	ja	0586h

l0C74_0540:
	push	word ptr [4D0Eh]
	call	far 1EDAh:023Fh
	mov	cx,ax
	mov	bx,dx
	mov	al,[bp-1h]
	xor	ah,ah
	sub	ax,19h
	mov	di,ax
	shl	di,2h
	mov	[di+58F4h],cx
	mov	[di+58F6h],bx
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	al,[bp-1h]
	xor	ah,ah
	sub	ax,19h
	mov	di,ax
	shl	di,2h
	les	di,[di+58F4h]
	push	es
	push	di
	push	1h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh

l0C74_0586:
	push	0h
	push	0h
	push	2Ch
	push	2Ch
	call	007Ch
	cmp	byte ptr [bp-1h],1Dh
	jz	059Ah

l0C74_0597:
	jmp	046Dh

l0C74_059A:
	push	word ptr [bp+0FF7Ch]
	push	word ptr [bp+0FF7Ah]
	push	word ptr [4D0Eh]
	call	far 1EDAh:0254h
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	call	far 1EDAh:1051h
	leave
	retf

;; fn0C74_05B8: 0C74:05B8
;;   Called from:
;;     0C74:0705 (in fn0C74_06B7)
;;     0C74:1B2E (in fn0C74_0FA1)
;;     0C74:2AC8 (in fn0C74_1F08)
;;     0C74:524F (in fn0C74_522C)
fn0C74_05B8 proc
	enter	6h,0h
	call	far 1AB8h:10E1h
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58BAh]
	xor	dx,dx
	cmp	dx,bx
	jl	05DBh

l0C74_05CF:
	jle	05D4h

l0C74_05D1:
	jmp	06B5h

l0C74_05D4:
	cmp	ax,cx
	jc	05DBh

l0C74_05D8:
	jmp	06B5h

l0C74_05DB:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	05F0h

l0C74_05ED:
	jmp	06B5h

l0C74_05F0:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	0605h

l0C74_0602:
	jmp	06B5h

l0C74_0605:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	call	far 1AB8h:13A3h
	mov	[bp-6h],ax
	push	word ptr [bp-6h]
	call	far 1EDAh:023Fh
	mov	[bp-4h],ax
	mov	[bp-2h],dx
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	les	di,[bp-4h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh

l0C74_0645:
	call	far 1AB8h:10E1h
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58BAh]
	xor	dx,dx
	cmp	dx,bx
	jl	065Eh

l0C74_0658:
	jg	06A7h

l0C74_065A:
	cmp	ax,cx
	jnc	06A7h

l0C74_065E:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	06A7h

l0C74_0670:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	06A7h

l0C74_0682:
	inc	word ptr [58B8h]
	inc	word ptr [58BAh]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	les	di,[bp-4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [58E6h]
	call	02D8h
	jmp	0645h

l0C74_06A7:
	push	word ptr [bp-2h]
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	call	far 1EDAh:0254h

l0C74_06B5:
	leave
	retf

;; fn0C74_06B7: 0C74:06B7
;;   Called from:
;;     0800:2631 (in fn0800_2401)
;;     0800:2960 (in fn0800_2827)
;;     0800:2DFE (in fn0800_2C0C)
;;     0800:3429 (in fn0800_31B7)
;;     0800:3E26 (in fn0800_3D9D)
fn0C74_06B7 proc
	push	bp
	mov	bp,sp
	mov	word ptr [5968h],1h
	mov	byte ptr [58B3h],0h
	mov	byte ptr [58B1h],1h
	mov	ax,[bp+8h]
	mov	[58B4h],ax
	mov	ax,[bp+6h]
	mov	[58B8h],ax
	mov	ax,[bp+8h]
	add	ax,2Bh
	mov	[58B6h],ax
	mov	ax,[bp+6h]
	add	ax,2Bh
	mov	[58BAh],ax
	mov	byte ptr [596Bh],2Ch
	mov	byte ptr [596Ah],2Ch
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	les	di,[58E8h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	cs
	call	05B8h
	leave
	retf	4h

;; fn0C74_070D: 0C74:070D
;;   Called from:
;;     0C74:0D17 (in fn0C74_0CFA)
;;     0C74:0D66 (in fn0C74_0D43)
;;     0C74:0DB7 (in fn0C74_0D94)
;;     0C74:0E02 (in fn0C74_0DE5)
;;     0C74:0F32 (in fn0C74_0E2E)
;;     0C74:129F (in fn0C74_0FA1)
;;     0C74:1372 (in fn0C74_0FA1)
;;     0C74:1427 (in fn0C74_0FA1)
;;     0C74:14D0 (in fn0C74_0FA1)
;;     0C74:1585 (in fn0C74_0FA1)
;;     0C74:16BB (in fn0C74_0FA1)
;;     0C74:17C5 (in fn0C74_0FA1)
;;     0C74:186B (in fn0C74_0FA1)
;;     0C74:194F (in fn0C74_0FA1)
;;     0C74:1A06 (in fn0C74_0FA1)
;;     0C74:1AAE (in fn0C74_0FA1)
;;     0C74:1BFE (in fn0C74_1B3B)
;;     0C74:1C73 (in fn0C74_1B3B)
;;     0C74:1D28 (in fn0C74_1B3B)
;;     0C74:1E99 (in fn0C74_1D95)
;;     0C74:2206 (in fn0C74_1F08)
;;     0C74:22D9 (in fn0C74_1F08)
;;     0C74:238E (in fn0C74_1F08)
;;     0C74:2437 (in fn0C74_1F08)
;;     0C74:24EC (in fn0C74_1F08)
;;     0C74:263E (in fn0C74_1F08)
;;     0C74:26EE (in fn0C74_1F08)
;;     0C74:2845 (in fn0C74_1F08)
;;     0C74:28E7 (in fn0C74_1F08)
;;     0C74:299E (in fn0C74_1F08)
;;     0C74:2A46 (in fn0C74_1F08)
;;     0C74:2B53 (in fn0C74_2AD9)
;;     0C74:30A6 (in fn0C74_2E5A)
;;     0C74:3139 (in fn0C74_2E5A)
;;     0C74:3179 (in fn0C74_2E5A)
;;     0C74:3481 (in fn0C74_3236)
;;     0C74:3514 (in fn0C74_3236)
;;     0C74:3558 (in fn0C74_3236)
;;     0C74:39BF (in fn0C74_396E)
;;     0C74:3A3B (in fn0C74_396E)
;;     0C74:3A7C (in fn0C74_396E)
;;     0C74:3AA5 (in fn0C74_396E)
;;     0C74:3BB7 (in fn0C74_396E)
;;     0C74:3C80 (in fn0C74_396E)
;;     0C74:3D56 (in fn0C74_396E)
;;     0C74:3E6E (in fn0C74_396E)
;;     0C74:3EEA (in fn0C74_396E)
;;     0C74:3F1A (in fn0C74_396E)
;;     0C74:3F62 (in fn0C74_396E)
;;     0C74:3FD6 (in fn0C74_3F74)
;;     0C74:407E (in fn0C74_3F74)
;;     0C74:40BD (in fn0C74_3F74)
;;     0C74:40E4 (in fn0C74_3F74)
;;     0C74:41FE (in fn0C74_3F74)
;;     0C74:42C8 (in fn0C74_3F74)
;;     0C74:439F (in fn0C74_3F74)
;;     0C74:44BF (in fn0C74_3F74)
;;     0C74:4537 (in fn0C74_3F74)
;;     0C74:4565 (in fn0C74_3F74)
;;     0C74:45BC (in fn0C74_3F74)
;;     0C74:461F (in fn0C74_45CE)
;;     0C74:469B (in fn0C74_45CE)
;;     0C74:486E (in fn0C74_45CE)
;;     0C74:4891 (in fn0C74_45CE)
;;     0C74:49FB (in fn0C74_4999)
;;     0C74:4AA3 (in fn0C74_4999)
;;     0C74:4C7F (in fn0C74_4999)
;;     0C74:4CA5 (in fn0C74_4999)
;;     0C74:4E21 (in fn0C74_4DAC)
;;     0C74:4EC9 (in fn0C74_4DAC)
;;     0C74:4F67 (in fn0C74_4DAC)
;;     0C74:4FC9 (in fn0C74_4DAC)
;;     0C74:5033 (in fn0C74_4FD7)
;;     0C74:50B2 (in fn0C74_4FD7)
;;     0C74:514B (in fn0C74_4FD7)
;;     0C74:519C (in fn0C74_4FD7)
fn0C74_070D proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+4h]
	mul	word ptr [58E6h]
	cwd
	mov	cx,9h
	idiv	cx
	mov	[bp+4h],ax
	cmp	byte ptr [58B0h],0h
	jz	072Fh

l0C74_0727:
	push	word ptr [bp+6h]
	call	far 11C8h:0354h

l0C74_072F:
	push	word ptr [bp+4h]
	call	02D8h
	cmp	byte ptr [58B0h],0h
	jz	0741h

l0C74_073C:
	call	far 11C8h:033Bh

l0C74_0741:
	push	word ptr [bp+4h]
	call	02D8h
	leave
	ret	4h
0C74:074B                                  21 20 00 00 00            ! ...
0C74:0750 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0C74:0760 00 00 00 00 00 00 00 00 00 00 00                ...........     

;; fn0C74_076B: 0C74:076B
;;   Called from:
;;     0800:0967 (in fn0800_08E9)
;;     0C74:2E52 (in fn0C74_2BBD)
;;     0C74:4975 (in fn0C74_45CE)
;;     0C74:4990 (in fn0C74_45CE)
;;     0C74:4D88 (in fn0C74_4999)
;;     0C74:4DA3 (in fn0C74_4999)
fn0C74_076B proc
	enter	30EEh,0h
	xor	ax,ax
	mov	[bp-6h],ax
	mov	ax,[bp+8h]
	sub	ax,[bp+0Ch]
	shr	ax,1h
	add	ax,[bp+0Ch]
	mov	[bp+0CF16h],ax
	mov	ax,[bp+6h]
	sub	ax,[bp+0Ah]
	shr	ax,1h
	add	ax,[bp+0Ah]
	mov	[bp+0CF14h],ax
	mov	ax,[bp+6h]
	sub	ax,[bp+0Ah]
	mov	dx,ax
	mov	ax,[bp+8h]
	sub	ax,[bp+0Ch]
	mul	dx
	imul	ax,ax,0Fh
	mov	[bp+0CF1Ah],ax
	mov	ax,[bp+0Ch]
	mov	[bp-0Ah],ax
	mov	ax,[bp+0Ah]
	mov	[bp-0Ch],ax
	mov	ax,[bp+0CF1Ah]
	mov	[bp+0CF12h],ax
	mov	ax,1h
	cmp	ax,[bp+0CF12h]
	jbe	07C9h

l0C74_07C6:
	jmp	09E1h

l0C74_07C9:
	mov	[bp-4h],ax
	jmp	07D1h

l0C74_07CE:
	inc	word ptr [bp-4h]

l0C74_07D1:
	mov	ax,[bp+8h]
	sub	ax,[bp+0Ch]
	inc	ax
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp+0Ch]
	mov	[bp-0Eh],ax
	mov	ax,[bp+6h]
	sub	ax,[bp+0Ah]
	inc	ax
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp+0Ah]
	mov	[bp-10h],ax
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1AB8h:1E3Ch
	mov	[bp+0CF19h],al
	mov	al,[bp+0CF19h]
	push	ax
	mov	di,74Bh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	081Ah

l0C74_0817:
	jmp	0918h

l0C74_081A:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	0h
	call	far 1AB8h:1E54h
	push	3h
	call	far 1EDAh:0D80h
	cmp	ax,1h
	jz	0836h

l0C74_0833:
	jmp	0915h

l0C74_0836:
	cmp	byte ptr [58B0h],0h
	jz	084Ah

l0C74_083D:
	push	64h
	call	far 1EDAh:0D80h
	push	ax
	call	far 11C8h:0354h

l0C74_084A:
	mov	ax,[58E6h]
	cwd
	mov	cx,4h
	idiv	cx
	push	ax
	call	far 1E78h:029Ch
	push	12Ch
	call	far 1EDAh:0D80h
	add	ax,[bp+0CF16h]
	sub	ax,96h
	mov	[bp-0Eh],ax
	cmp	word ptr [bp-0Eh],1h
	jnc	0876h

l0C74_0871:
	mov	word ptr [bp-0Eh],1h

l0C74_0876:
	cmp	word ptr [bp-0Eh],27Eh
	jbe	0882h

l0C74_087D:
	mov	word ptr [bp-0Eh],27Eh

l0C74_0882:
	push	0C8h
	call	far 1EDAh:0D80h
	add	ax,16h
	mov	dx,ax
	mov	ax,[bp+0CF14h]
	sub	ax,dx
	mov	[bp-10h],ax
	cmp	word ptr [bp-10h],1h
	jnc	08A3h

l0C74_089E:
	mov	word ptr [bp-10h],1h

l0C74_08A3:
	cmp	word ptr [bp-10h],177h
	jbe	08AFh

l0C74_08AA:
	mov	word ptr [bp-10h],1h

l0C74_08AF:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	0909h

l0C74_08BE:
	inc	word ptr [bp-6h]
	mov	al,[bp+0CF19h]
	mov	di,[bp-6h]
	mov	[bp+di+0CF1Bh],al
	mov	ax,[bp-0Eh]
	mov	di,[bp-6h]
	shl	di,2h
	mov	[bp+di+0D8DCh],ax
	mov	ax,[bp-10h]
	mov	di,[bp-6h]
	shl	di,2h
	mov	[bp+di+0D8DEh],ax
	mov	di,[bp-6h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-6h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	mov	di,[bp-6h]
	mov	al,[bp+di+0CF1Bh]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1E54h

l0C74_0909:
	cmp	byte ptr [58B0h],0h
	jz	0915h

l0C74_0910:
	call	far 11C8h:033Bh

l0C74_0915:
	jmp	09D5h

l0C74_0918:
	cmp	word ptr [bp-6h],0h
	jnz	0921h

l0C74_091E:
	jmp	09D5h

l0C74_0921:
	push	word ptr [bp-6h]
	call	far 1EDAh:0D80h
	inc	ax
	mov	[bp-8h],ax
	mov	di,[bp-8h]
	shl	di,2h
	cmp	word ptr [bp+di+0D8DEh],1F4h
	jnz	093Eh

l0C74_093B:
	jmp	09D5h

l0C74_093E:
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	push	0h
	call	far 1AB8h:1E54h
	push	14h
	call	far 1EDAh:0D80h
	mov	[bp-0Eh],ax
	cmp	word ptr [bp-0Eh],1h
	jz	099Ah

l0C74_0969:
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	mov	ax,[bp+di+0D8DEh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	099Ah

l0C74_0988:
	mov	di,[bp-8h]
	shl	di,2h
	mov	ax,[bp+di+0D8DEh]
	inc	ax
	inc	ax
	cmp	ax,[58BAh]
	jc	09A8h

l0C74_099A:
	mov	di,[bp-8h]
	shl	di,2h
	mov	word ptr [bp+di+0D8DEh],1F4h
	jmp	09D5h

l0C74_09A8:
	mov	di,[bp-8h]
	shl	di,2h
	inc	word ptr [bp+di+0D8DEh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	mov	di,[bp-8h]
	mov	al,[bp+di+0CF1Bh]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1E54h

l0C74_09D5:
	mov	ax,[bp-4h]
	cmp	ax,[bp+0CF12h]
	jz	09E1h

l0C74_09DE:
	jmp	07CEh

l0C74_09E1:
	cmp	word ptr [bp-6h],0h
	jz	0A31h

l0C74_09E7:
	mov	ax,[bp-6h]
	mov	[bp+0CF12h],ax
	mov	ax,1h
	cmp	ax,[bp+0CF12h]
	ja	0A31h

l0C74_09F7:
	mov	[bp-8h],ax
	jmp	09FFh

l0C74_09FC:
	inc	word ptr [bp-8h]

l0C74_09FF:
	mov	di,[bp-8h]
	shl	di,2h
	cmp	word ptr [bp+di+0D8DEh],1F4h
	jz	0A28h

l0C74_0A0D:
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	push	0h
	call	far 1AB8h:1E54h

l0C74_0A28:
	mov	ax,[bp-8h]
	cmp	ax,[bp+0CF12h]
	jnz	09FCh

l0C74_0A31:
	leave
	retf	8h

;; fn0C74_0A35: 0C74:0A35
;;   Called from:
;;     0800:097B (in fn0800_08E9)
;;     0800:4151 (in fn0800_3D9D)
;;     0C74:1B32 (in fn0C74_0FA1)
;;     0C74:2ACC (in fn0C74_1F08)
fn0C74_0A35 proc
	enter	30ECh,0h
	xor	ax,ax
	mov	[bp-6h],ax
	mov	ax,[58BAh]
	sub	ax,[58B8h]
	shr	ax,1h
	mov	[bp+0CF18h],ax
	cmp	word ptr [bp+0CF18h],17h
	jnc	0A5Ah

l0C74_0A52:
	mov	word ptr [bp+0CF16h],61A8h
	jmp	0A60h

l0C74_0A5A:
	mov	word ptr [bp+0CF16h],0C350h

l0C74_0A60:
	mov	ax,[58B4h]
	add	ax,15h
	mov	[bp-0Ah],ax
	mov	ax,[58B8h]
	add	ax,[bp+0CF18h]
	mov	[bp-0Ch],ax
	mov	ax,[bp+0CF16h]
	mov	[bp+0CF14h],ax
	mov	ax,1h
	cmp	ax,[bp+0CF14h]
	jbe	0A87h

l0C74_0A84:
	jmp	0CA3h

l0C74_0A87:
	mov	[bp-4h],ax
	jmp	0A8Fh

l0C74_0A8C:
	inc	word ptr [bp-4h]

l0C74_0A8F:
	push	2Dh
	call	far 1EDAh:0D80h
	add	ax,[bp-0Ah]
	sub	ax,15h
	mov	[bp-0Eh],ax
	mov	ax,[bp-0Ah]
	add	ax,9h
	cmp	ax,[bp-0Eh]
	jnc	0AADh

l0C74_0AAA:
	dec	word ptr [bp-0Eh]

l0C74_0AAD:
	mov	ax,[bp+0CF18h]
	shl	ax,1h
	inc	ax
	inc	ax
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp-0Ch]
	sub	ax,[bp+0CF18h]
	mov	[bp-10h],ax
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1AB8h:1E3Ch
	mov	[bp+0CF1Bh],al
	cmp	byte ptr [bp+0CF1Bh],0h
	jnz	0ADEh

l0C74_0ADB:
	jmp	0BDAh

l0C74_0ADE:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	0h
	call	far 1AB8h:1E54h
	push	3h
	call	far 1EDAh:0D80h
	cmp	ax,1h
	jz	0AFAh

l0C74_0AF7:
	jmp	0BD7h

l0C74_0AFA:
	cmp	byte ptr [58B0h],0h
	jz	0B0Eh

l0C74_0B01:
	push	64h
	call	far 1EDAh:0D80h
	push	ax
	call	far 11C8h:0354h

l0C74_0B0E:
	mov	ax,[58E6h]
	cwd
	mov	cx,4h
	idiv	cx
	push	ax
	call	far 1E78h:029Ch
	push	12Ch
	call	far 1EDAh:0D80h
	add	ax,[bp-0Ah]
	sub	ax,96h
	mov	[bp-0Eh],ax
	cmp	word ptr [bp-0Eh],1h
	jnc	0B39h

l0C74_0B34:
	mov	word ptr [bp-0Eh],1h

l0C74_0B39:
	cmp	word ptr [bp-0Eh],27Eh
	jbe	0B45h

l0C74_0B40:
	mov	word ptr [bp-0Eh],27Eh

l0C74_0B45:
	push	0C8h
	call	far 1EDAh:0D80h
	add	ax,16h
	mov	dx,ax
	mov	ax,[bp-0Ch]
	sub	ax,dx
	mov	[bp-10h],ax
	cmp	word ptr [bp-10h],1h
	jnc	0B65h

l0C74_0B60:
	mov	word ptr [bp-10h],1h

l0C74_0B65:
	cmp	word ptr [bp-10h],177h
	jbe	0B71h

l0C74_0B6C:
	mov	word ptr [bp-10h],1h

l0C74_0B71:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	0BCBh

l0C74_0B80:
	inc	word ptr [bp-6h]
	mov	al,[bp+0CF1Bh]
	mov	di,[bp-6h]
	mov	[bp+di+0CF1Bh],al
	mov	ax,[bp-0Eh]
	mov	di,[bp-6h]
	shl	di,2h
	mov	[bp+di+0D8DCh],ax
	mov	ax,[bp-10h]
	mov	di,[bp-6h]
	shl	di,2h
	mov	[bp+di+0D8DEh],ax
	mov	di,[bp-6h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-6h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	mov	di,[bp-6h]
	mov	al,[bp+di+0CF1Bh]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1E54h

l0C74_0BCB:
	cmp	byte ptr [58B0h],0h
	jz	0BD7h

l0C74_0BD2:
	call	far 11C8h:033Bh

l0C74_0BD7:
	jmp	0C97h

l0C74_0BDA:
	cmp	word ptr [bp-6h],0h
	jnz	0BE3h

l0C74_0BE0:
	jmp	0C97h

l0C74_0BE3:
	push	word ptr [bp-6h]
	call	far 1EDAh:0D80h
	inc	ax
	mov	[bp-8h],ax
	mov	di,[bp-8h]
	shl	di,2h
	cmp	word ptr [bp+di+0D8DEh],1F4h
	jnz	0C00h

l0C74_0BFD:
	jmp	0C97h

l0C74_0C00:
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	push	0h
	call	far 1AB8h:1E54h
	push	14h
	call	far 1EDAh:0D80h
	mov	[bp-0Eh],ax
	cmp	word ptr [bp-0Eh],1h
	jz	0C5Ch

l0C74_0C2B:
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	mov	ax,[bp+di+0D8DEh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	0C5Ch

l0C74_0C4A:
	mov	di,[bp-8h]
	shl	di,2h
	mov	ax,[bp+di+0D8DEh]
	inc	ax
	inc	ax
	cmp	ax,[58BAh]
	jc	0C6Ah

l0C74_0C5C:
	mov	di,[bp-8h]
	shl	di,2h
	mov	word ptr [bp+di+0D8DEh],1F4h
	jmp	0C97h

l0C74_0C6A:
	mov	di,[bp-8h]
	shl	di,2h
	inc	word ptr [bp+di+0D8DEh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	mov	di,[bp-8h]
	mov	al,[bp+di+0CF1Bh]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1E54h

l0C74_0C97:
	mov	ax,[bp-4h]
	cmp	ax,[bp+0CF14h]
	jz	0CA3h

l0C74_0CA0:
	jmp	0A8Ch

l0C74_0CA3:
	cmp	word ptr [bp-6h],0h
	jz	0CF3h

l0C74_0CA9:
	mov	ax,[bp-6h]
	mov	[bp+0CF14h],ax
	mov	ax,1h
	cmp	ax,[bp+0CF14h]
	ja	0CF3h

l0C74_0CB9:
	mov	[bp-8h],ax
	jmp	0CC1h

l0C74_0CBE:
	inc	word ptr [bp-8h]

l0C74_0CC1:
	mov	di,[bp-8h]
	shl	di,2h
	cmp	word ptr [bp+di+0D8DEh],1F4h
	jz	0CEAh

l0C74_0CCF:
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	push	0h
	call	far 1AB8h:1E54h

l0C74_0CEA:
	mov	ax,[bp-8h]
	cmp	ax,[bp+0CF14h]
	jnz	0CBEh

l0C74_0CF3:
	mov	byte ptr [58B3h],1h
	leave
	retf

;; fn0C74_0CFA: 0C74:0CFA
;;   Called from:
;;     0C74:1CC5 (in fn0C74_1B3B)
;;     0C74:1CDD (in fn0C74_1B3B)
;;     0C74:1D90 (in fn0C74_1B3B)
;;     0C74:2BA9 (in fn0C74_2AD9)
;;     0C74:3636 (in fn0C74_3615)
fn0C74_0CFA proc
	enter	2h,0h
	mov	word ptr [5968h],1h
	mov	al,[bp+4h]
	cmp	al,1h
	jc	0D3Fh

l0C74_0D0B:
	mov	[bp-1h],al
	jmp	0D13h

l0C74_0D10:
	dec	byte ptr [bp-1h]

l0C74_0D13:
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
	cmp	byte ptr [bp-1h],1h
	jnz	0D10h

l0C74_0D3F:
	leave
	ret	2h

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

;; fn0C74_0D94: 0C74:0D94
;;   Called from:
;;     0C74:1CF3 (in fn0C74_1B3B)
;;     0C74:2AF9 (in fn0C74_2AD9)
fn0C74_0D94 proc
	enter	2h,0h
	mov	word ptr [5968h],1h
	mov	al,[bp+4h]
	mov	[bp-2h],al
	mov	al,15h
	cmp	al,[bp-2h]
	jc	0DE1h

l0C74_0DAB:
	mov	[bp-1h],al
	jmp	0DB3h

l0C74_0DB0:
	dec	byte ptr [bp-1h]

l0C74_0DB3:
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
	jnz	0DB0h

l0C74_0DE1:
	leave
	ret	2h

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

;; fn0C74_0E2E: 0C74:0E2E
;;   Called from:
;;     0C74:12E9 (in fn0C74_0FA1)
;;     0C74:1461 (in fn0C74_0FA1)
;;     0C74:15B1 (in fn0C74_0FA1)
;;     0C74:1AE3 (in fn0C74_0FA1)
fn0C74_0E2E proc
	enter	0Eh,0h
	mov	ax,[58B4h]
	add	ax,19h
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Dh
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-4h],ax
	mov	ax,[58B4h]
	add	ax,0Dh
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-6h],ax
	push	word ptr [bp-6h]
	call	far 1EDAh:023Fh
	mov	[bp-0Ah],ax
	mov	[bp-8h],dx
	push	word ptr [bp-4h]
	call	far 1EDAh:023Fh
	mov	[bp-0Eh],ax
	mov	[bp-0Ch],dx
	mov	ax,[58B4h]
	add	ax,19h
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Dh
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-0Eh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,0Dh
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-0Ah]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	di,[bp+4h]
	mov	al,ss:[di-4h]
	or	al,al
	jc	0F81h

l0C74_0F25:
	mov	[bp-1h],al
	jmp	0F2Dh

l0C74_0F2A:
	dec	byte ptr [bp-1h]

l0C74_0F2D:
	push	0E6h
	push	0Ah
	call	070Dh
	mov	al,[bp-1h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-0Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	al,[bp-1h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-0Ah]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-1h],0h
	jnz	0F2Ah

l0C74_0F81:
	push	word ptr [bp-8h]
	push	word ptr [bp-0Ah]
	push	word ptr [bp-6h]
	call	far 1EDAh:0254h
	push	word ptr [bp-0Ch]
	push	word ptr [bp-0Eh]
	push	word ptr [bp-4h]
	call	far 1EDAh:0254h
	leave
	ret	2h

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

;; fn0C74_1B3B: 0C74:1B3B
;;   Called from:
;;     0C74:51AD (in fn0C74_51AA)
fn0C74_1B3B proc
	enter	6h,0h
	mov	ax,[58B4h]
	add	ax,17h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Ch
	push	ax
	push	3h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,18h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Ch
	push	ax
	push	1h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Ch
	push	ax
	push	1h
	call	far 1AB8h:1E54h
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	ax,[58B4h]
	add	ax,2Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Ch
	push	ax
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
	mov	byte ptr [bp-1h],0h

l0C74_1BCF:
	cmp	byte ptr [bp-1h],58h
	jnc	1C1Eh

l0C74_1BD5:
	push	word ptr [58B4h]
	mov	ax,[58B8h]
	dec	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1C1Eh

l0C74_1BE7:
	push	word ptr [58B6h]
	mov	ax,[58B8h]
	dec	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1C1Eh

l0C74_1BF9:
	push	0C8h
	push	0Ah
	call	070Dh
	dec	word ptr [58B8h]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	les	di,[bp-6h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	inc	byte ptr [bp-1h]
	jmp	1BCFh

l0C74_1C1E:
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

l0C74_1C3E:
	cmp	byte ptr [bp-1h],0h
	jbe	1C93h

l0C74_1C44:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,2Ch
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1C93h

l0C74_1C59:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,2Ch
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1C93h

l0C74_1C6E:
	push	0C8h
	push	0Ah
	call	070Dh
	inc	word ptr [58B8h]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	les	di,[bp-6h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	dec	byte ptr [bp-1h]
	jmp	1C3Eh

l0C74_1C93:
	cmp	byte ptr [bp-1h],0h
	jnz	1CABh

l0C74_1C99:
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	push	word ptr [595Eh]
	call	far 1EDAh:0254h
	jmp	1D93h

l0C74_1CAB:
	cmp	word ptr [5968h],1h
	jnz	1CD5h

l0C74_1CB2:
	push	0C8h
	call	02D8h
	push	15h
	call	0D43h
	push	0C8h
	call	02D8h
	push	15h
	call	0CFAh
	push	0C8h
	call	02D8h
	push	0Bh
	call	0D43h
	jmp	1CF6h

l0C74_1CD5:
	push	0C8h
	call	02D8h
	push	15h
	call	0CFAh
	push	0C8h
	call	02D8h
	push	15h
	call	0D43h
	push	0C8h
	call	02D8h
	push	0Bh
	call	0D94h

l0C74_1CF6:
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
	call	0FA1h
	or	al,al
	jnz	1D48h

l0C74_1D1D:
	cmp	byte ptr [bp-1h],0h
	jbe	1D48h

l0C74_1D23:
	push	0C8h
	push	0Ah
	call	070Dh
	inc	word ptr [58B8h]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	les	di,[bp-6h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	dec	byte ptr [bp-1h]
	jmp	1D1Dh

l0C74_1D48:
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	push	word ptr [595Eh]
	call	far 1EDAh:0254h
	cmp	byte ptr [58B3h],0h
	jz	1D60h

l0C74_1D5E:
	jmp	1D93h

l0C74_1D60:
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
	jnz	1D8Eh

l0C74_1D87:
	push	0Bh
	call	0DE5h
	jmp	1D93h

l0C74_1D8E:
	push	0Bh
	call	0CFAh

l0C74_1D93:
	leave
	ret

;; fn0C74_1D95: 0C74:1D95
;;   Called from:
;;     0C74:2250 (in fn0C74_1F08)
;;     0C74:23BA (in fn0C74_1F08)
;;     0C74:2518 (in fn0C74_1F08)
;;     0C74:2A7B (in fn0C74_1F08)
fn0C74_1D95 proc
	enter	0Eh,0h
	mov	ax,[58B4h]
	add	ax,19h
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Dh
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-4h],ax
	mov	ax,[58B4h]
	add	ax,0Dh
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-6h],ax
	push	word ptr [bp-6h]
	call	far 1EDAh:023Fh
	mov	[bp-0Ah],ax
	mov	[bp-8h],dx
	push	word ptr [bp-4h]
	call	far 1EDAh:023Fh
	mov	[bp-0Eh],ax
	mov	[bp-0Ch],dx
	mov	ax,[58B4h]
	add	ax,19h
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Dh
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-0Eh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,0Dh
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-0Ah]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	di,[bp+4h]
	mov	al,ss:[di-4h]
	or	al,al
	jc	1EE8h

l0C74_1E8C:
	mov	[bp-1h],al
	jmp	1E94h

l0C74_1E91:
	dec	byte ptr [bp-1h]

l0C74_1E94:
	push	0E6h
	push	0Ah
	call	070Dh
	mov	al,[bp-1h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-0Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	al,[bp-1h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-0Ah]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-1h],0h
	jnz	1E91h

l0C74_1EE8:
	push	word ptr [bp-8h]
	push	word ptr [bp-0Ah]
	push	word ptr [bp-6h]
	call	far 1EDAh:0254h
	push	word ptr [bp-0Ch]
	push	word ptr [bp-0Eh]
	push	word ptr [bp-4h]
	call	far 1EDAh:0254h
	leave
	ret	2h

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

;; fn0C74_2BBD: 0C74:2BBD
;;   Called from:
;;     0C74:315F (in fn0C74_2E5A)
;;     0C74:353E (in fn0C74_3236)
;;     0C74:53FB (in fn0C74_5258)
fn0C74_2BBD proc
	enter	12h,0h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:13A3h
	mov	[bp-0Ch],ax
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+8h]
	call	far 1AB8h:13A3h
	mov	[bp-0Ah],ax
	push	word ptr [bp-0Ch]
	call	far 1EDAh:023Fh
	mov	[bp-4h],ax
	mov	[bp-2h],dx
	push	word ptr [bp-0Ah]
	call	far 1EDAh:023Fh
	mov	[bp-8h],ax
	mov	[bp-6h],dx
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+8h]
	les	di,[bp-8h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	push	0h
	call	far 1AB8h:1C32h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+8h]
	call	far 1AB8h:1AF6h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	les	di,[bp-4h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	les	di,[bp-8h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [bp-6h]
	push	word ptr [bp-8h]
	push	word ptr [bp-0Ah]
	call	far 1EDAh:0254h
	mov	ax,[bp+0Ah]
	add	ax,0Bh
	push	ax
	push	word ptr [bp+4h]
	call	far 1AB8h:1E3Ch
	mov	[bp-0Fh],al
	xor	ax,ax
	mov	[bp-0Eh],ax

l0C74_2C80:
	mov	ax,[bp+0Ah]
	add	ax,0Bh
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	2C98h

l0C74_2C95:
	jmp	2E23h

l0C74_2C98:
	mov	ax,[58E6h]
	cwd
	mov	cx,4h
	idiv	cx
	push	ax
	call	far 1E78h:029Ch
	inc	word ptr [bp+8h]
	inc	word ptr [bp+4h]
	inc	word ptr [bp-0Eh]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	les	di,[bp-4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	word ptr [bp+4h],176h
	jz	2CCCh

l0C74_2CC9:
	jmp	2E20h

l0C74_2CCC:
	cmp	byte ptr [bp-0Fh],0Fh
	jz	2CD5h

l0C74_2CD2:
	jmp	2E20h

l0C74_2CD5:
	mov	byte ptr [bp-12h],0Fh
	jmp	2CDEh

l0C74_2CDB:
	dec	byte ptr [bp-12h]

l0C74_2CDE:
	mov	byte ptr [bp-11h],0h
	jmp	2CE7h

l0C74_2CE4:
	inc	byte ptr [bp-11h]

l0C74_2CE7:
	mov	byte ptr [bp-10h],1h
	jmp	2CF0h

l0C74_2CED:
	inc	byte ptr [bp-10h]

l0C74_2CF0:
	cmp	byte ptr [58B0h],0h
	jz	2D15h

l0C74_2CF7:
	mov	al,[bp-10h]
	xor	ah,ah
	mov	cx,ax
	mov	al,[bp-11h]
	xor	ah,ah
	inc	ax
	mov	dx,ax
	mov	al,[bp-12h]
	xor	ah,ah
	mul	dx
	mul	cx
	push	ax
	call	far 11C8h:0354h

l0C74_2D15:
	push	1h
	call	far 1E78h:029Ch
	mov	al,[bp-10h]
	xor	ah,ah
	cwd
	mov	cx,3h
	div	cx
	xchg	dx,ax
	or	ax,ax
	jnz	2D4Ch

l0C74_2D2C:
	mov	al,[bp-11h]
	xor	ah,ah
	add	ax,[bp+0Ah]
	push	ax
	mov	al,[bp-10h]
	xor	ah,ah
	add	ax,160h
	inc	ax
	push	ax
	mov	al,[bp-12h]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1E54h
	jmp	2D6Dh

l0C74_2D4C:
	mov	al,[bp-11h]
	xor	ah,ah
	add	ax,[bp+0Ah]
	push	ax
	mov	al,[bp-10h]
	xor	ah,ah
	inc	ax
	add	ax,160h
	push	ax
	mov	al,[bp-12h]
	xor	ah,ah
	sub	ax,8h
	push	ax
	call	far 1AB8h:1E54h

l0C74_2D6D:
	mov	al,[bp-10h]
	xor	ah,ah
	cwd
	mov	cx,3h
	div	cx
	xchg	dx,ax
	or	ax,ax
	jnz	2DA4h

l0C74_2D7D:
	mov	al,[bp-11h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[bp+0Ah]
	add	ax,15h
	sub	ax,dx
	push	ax
	mov	al,[bp-10h]
	xor	ah,ah
	add	ax,160h
	inc	ax
	push	ax
	mov	al,[bp-12h]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1E54h
	jmp	2DCCh

l0C74_2DA4:
	mov	al,[bp-11h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[bp+0Ah]
	add	ax,15h
	sub	ax,dx
	push	ax
	mov	al,[bp-10h]
	xor	ah,ah
	inc	ax
	add	ax,160h
	push	ax
	mov	al,[bp-12h]
	xor	ah,ah
	sub	ax,8h
	push	ax
	call	far 1AB8h:1E54h

l0C74_2DCC:
	cmp	byte ptr [bp-10h],15h
	jz	2DD5h

l0C74_2DD2:
	jmp	2CEDh

l0C74_2DD5:
	cmp	byte ptr [bp-11h],0Ah
	jz	2DDEh

l0C74_2DDB:
	jmp	2CE4h

l0C74_2DDE:
	cmp	byte ptr [bp-12h],8h
	jz	2DE7h

l0C74_2DE4:
	jmp	2CDBh

l0C74_2DE7:
	mov	al,[bp-0Fh]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1C32h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+4h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	push	word ptr [bp+0Ah]
	push	161h
	push	word ptr [bp+6h]
	push	161h
	call	far 1AB8h:1AF6h
	call	far 11C8h:033Bh

l0C74_2E20:
	jmp	2C80h

l0C74_2E23:
	push	word ptr [bp-2h]
	push	word ptr [bp-4h]
	push	word ptr [bp-0Ch]
	call	far 1EDAh:0254h
	mov	al,[4D0Ah]
	xor	ah,ah
	cmp	ax,[bp-0Eh]
	jnc	2E56h

l0C74_2E3B:
	cmp	word ptr [bp+4h],172h
	jnc	2E56h

l0C74_2E42:
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	mov	ax,[bp+4h]
	add	ax,16h
	push	ax
	push	cs
	call	076Bh

l0C74_2E56:
	leave
	ret	8h

;; fn0C74_2E5A: 0C74:2E5A
;;   Called from:
;;     0C74:5249 (in fn0C74_522C)
fn0C74_2E5A proc
	enter	1Eh,0h
	mov	byte ptr [bp-1h],0h
	cmp	word ptr [58B4h],1h
	ja	2E6Ch

l0C74_2E69:
	jmp	3231h

l0C74_2E6C:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	2ED2h

l0C74_2E7E:
	mov	ax,[58B4h]
	sub	ax,9h
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	2ED2h

l0C74_2E95:
	mov	ax,[58B4h]
	sub	ax,17h
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2ED2h

l0C74_2EA9:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	push	word ptr [58B8h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2ED2h

l0C74_2EBB:
	mov	ax,[58B4h]
	sub	ax,17h
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	2ED5h

l0C74_2ED2:
	jmp	3231h

l0C74_2ED5:
	mov	byte ptr [bp-1h],1h
	mov	ax,[58B4h]
	sub	ax,16h
	push	ax
	mov	ax,[58B8h]
	add	ax,15h
	push	ax
	push	word ptr [58B4h]
	push	word ptr [58BAh]
	call	far 1AB8h:13A3h
	mov	[bp-10h],ax
	push	word ptr [bp-10h]
	call	far 1EDAh:023Fh
	mov	[bp-0Eh],ax
	mov	[bp-0Ch],dx
	mov	ax,[58B4h]
	sub	ax,16h
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	push	word ptr [58B4h]
	push	word ptr [58BAh]
	les	di,[bp-0Eh]
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
	call	far 1AB8h:13A3h
	mov	[bp-12h],ax
	push	word ptr [bp-12h]
	call	far 1EDAh:023Fh
	mov	[bp-1Eh],ax
	mov	[bp-1Ch],dx
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
	les	di,[bp-1Eh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,0Dh
	mov	[bp-0Ah],ax
	dec	word ptr [bp-0Ah]
	push	word ptr [bp-0Ah]
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	call	far 1AB8h:1C32h
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
	push	word ptr [bp-1Ch]
	push	word ptr [bp-1Eh]
	push	word ptr [bp-12h]
	call	far 1EDAh:0254h
	mov	ax,[58B4h]
	add	ax,0Ch
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
	call	far 1AB8h:13A3h
	mov	[bp-12h],ax
	push	word ptr [bp-12h]
	call	far 1EDAh:023Fh
	mov	[bp-1Eh],ax
	mov	[bp-1Ch],dx
	mov	ax,[58B4h]
	add	ax,0Ch
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
	les	di,[bp-1Eh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	byte ptr [bp-2h],1h

l0C74_307B:
	cmp	byte ptr [bp-2h],14h
	jnc	30D1h

l0C74_3081:
	mov	al,[bp-2h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	30D1h

l0C74_30A1:
	push	0E6h
	push	0Ah
	call	070Dh
	mov	al,[bp-2h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	inc	byte ptr [bp-2h]
	jmp	307Bh

l0C74_30D1:
	mov	al,[bp-2h]
	xor	ah,ah
	mov	[bp-8h],ax
	mov	ax,[58B4h]
	sub	ax,16h
	mov	[bp-14h],ax
	mov	ax,[58B4h]
	dec	ax
	mov	[bp-16h],ax
	mov	ax,[58B8h]
	add	ax,15h
	mov	[bp-18h],ax
	mov	ax,[58BAh]
	mov	[bp-1Ah],ax
	mov	byte ptr [bp-3h],1h
	jmp	3101h

l0C74_30FE:
	inc	byte ptr [bp-3h]

l0C74_3101:
	dec	word ptr [bp-14h]
	dec	word ptr [bp-16h]
	push	word ptr [bp-14h]
	mov	ax,[bp-18h]
	inc	ax
	push	ax
	les	di,[bp-0Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	ax,[bp-16h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	0E6h
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],16h
	jnz	30FEh

l0C74_3142:
	push	word ptr [bp-16h]
	mov	ax,[bp-1Ah]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3162h

l0C74_3153:
	push	word ptr [bp-14h]
	push	word ptr [bp-18h]
	push	word ptr [bp-16h]
	push	word ptr [bp-1Ah]
	call	2BBDh

l0C74_3162:
	mov	ax,[bp-8h]
	add	ax,16h
	or	al,al
	jc	31A5h

l0C74_316C:
	mov	[bp-3h],al
	jmp	3174h

l0C74_3171:
	dec	byte ptr [bp-3h]

l0C74_3174:
	push	0E6h
	push	5h
	call	070Dh
	mov	al,[bp-3h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-3h],0h
	jnz	3171h

l0C74_31A5:
	push	word ptr [bp-1Ch]
	push	word ptr [bp-1Eh]
	push	word ptr [bp-12h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-2h],5h
	mov	byte ptr [bp-3h],1h
	jmp	31C0h

l0C74_31BD:
	inc	byte ptr [bp-3h]

l0C74_31C0:
	mov	ax,[58E6h]
	cwd
	mov	cx,2h
	idiv	cx
	push	ax
	call	far 1E78h:029Ch
	push	0Ah
	call	02D8h
	dec	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],0h
	jnz	31F1h

l0C74_31DD:
	mov	byte ptr [bp-2h],4h
	cmp	byte ptr [58B0h],0h
	jz	31EFh

l0C74_31E8:
	push	32h
	call	far 11C8h:0354h

l0C74_31EF:
	jmp	31F6h

l0C74_31F1:
	call	far 11C8h:033Bh

l0C74_31F6:
	dec	word ptr [58B4h]
	dec	word ptr [58B6h]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	al,[bp-2h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+58F4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-3h],16h
	jnz	31BDh

l0C74_3223:
	push	word ptr [bp-0Ch]
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1EDAh:0254h

l0C74_3231:
	mov	al,[bp-1h]
	leave
	ret

;; fn0C74_3236: 0C74:3236
;;   Called from:
;;     0C74:523C (in fn0C74_522C)
fn0C74_3236 proc
	enter	1Ch,0h
	mov	byte ptr [bp-1h],0h
	cmp	word ptr [58B4h],27Eh
	jc	3249h

l0C74_3246:
	jmp	3610h

l0C74_3249:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	32ADh

l0C74_325B:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	32ADh

l0C74_3270:
	mov	ax,[58B6h]
	add	ax,17h
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	32ADh

l0C74_3284:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	push	word ptr [58B8h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	32ADh

l0C74_3296:
	mov	ax,[58B6h]
	add	ax,17h
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	32B0h

l0C74_32AD:
	jmp	3610h

l0C74_32B0:
	mov	byte ptr [bp-1h],1h
	push	word ptr [58B6h]
	mov	ax,[58B8h]
	add	ax,15h
	push	ax
	mov	ax,[58B6h]
	add	ax,16h
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:13A3h
	mov	[bp-0Eh],ax
	push	word ptr [bp-0Eh]
	call	far 1EDAh:023Fh
	mov	[bp-0Ch],ax
	mov	[bp-0Ah],dx
	push	word ptr [58B6h]
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	mov	ax,[58B6h]
	add	ax,16h
	push	ax
	push	word ptr [58BAh]
	les	di,[bp-0Ch]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
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
	call	far 1AB8h:13A3h
	mov	[bp-10h],ax
	push	word ptr [bp-10h]
	call	far 1EDAh:023Fh
	mov	[bp-1Ch],ax
	mov	[bp-1Ah],dx
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
	les	di,[bp-1Ch]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,19h
	mov	[bp-8h],ax
	inc	word ptr [bp-8h]
	push	word ptr [bp-8h]
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
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
	push	word ptr [bp-1Ah]
	push	word ptr [bp-1Ch]
	push	word ptr [bp-10h]
	call	far 1EDAh:0254h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Eh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-10h],ax
	push	word ptr [bp-10h]
	call	far 1EDAh:023Fh
	mov	[bp-1Ch],ax
	mov	[bp-1Ah],dx
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Eh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-1Ch]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	byte ptr [bp-2h],1h

l0C74_3456:
	cmp	byte ptr [bp-2h],14h
	jnc	34ACh

l0C74_345C:
	mov	al,[bp-2h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	34ACh

l0C74_347C:
	push	0E6h
	push	0Ah
	call	070Dh
	mov	al,[bp-2h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	inc	byte ptr [bp-2h]
	jmp	3456h

l0C74_34AC:
	mov	al,[bp-2h]
	xor	ah,ah
	mov	[bp-6h],ax
	mov	ax,[58B6h]
	mov	[bp-12h],ax
	mov	ax,[58B6h]
	add	ax,16h
	mov	[bp-14h],ax
	mov	ax,[58B8h]
	add	ax,15h
	mov	[bp-16h],ax
	mov	ax,[58BAh]
	mov	[bp-18h],ax
	mov	byte ptr [bp-3h],1h
	jmp	34DBh

l0C74_34D8:
	inc	byte ptr [bp-3h]

l0C74_34DB:
	inc	word ptr [bp-12h]
	inc	word ptr [bp-14h]
	push	word ptr [bp-12h]
	mov	ax,[bp-16h]
	inc	ax
	push	ax
	les	di,[bp-0Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	ax,[bp-12h]
	sub	ax,5h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	0E6h
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],16h
	jnz	34D8h

l0C74_351D:
	mov	ax,[bp-12h]
	inc	ax
	push	ax
	mov	ax,[bp-18h]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3541h

l0C74_3530:
	mov	ax,[bp-12h]
	inc	ax
	push	ax
	push	word ptr [bp-16h]
	push	word ptr [bp-14h]
	push	word ptr [bp-18h]
	call	2BBDh

l0C74_3541:
	mov	ax,[bp-6h]
	add	ax,15h
	or	al,al
	jc	3584h

l0C74_354B:
	mov	[bp-3h],al
	jmp	3553h

l0C74_3550:
	dec	byte ptr [bp-3h]

l0C74_3553:
	push	0E6h
	push	5h
	call	070Dh
	mov	al,[bp-3h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-3h],0h
	jnz	3550h

l0C74_3584:
	push	word ptr [bp-1Ah]
	push	word ptr [bp-1Ch]
	push	word ptr [bp-10h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-2h],1h
	mov	byte ptr [bp-3h],1h
	jmp	359Fh

l0C74_359C:
	inc	byte ptr [bp-3h]

l0C74_359F:
	mov	ax,[58E6h]
	cwd
	mov	cx,2h
	idiv	cx
	push	ax
	call	far 1E78h:029Ch
	push	0Ah
	call	02D8h
	inc	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],5h
	jnz	35D0h

l0C74_35BC:
	mov	byte ptr [bp-2h],1h
	cmp	byte ptr [58B0h],0h
	jz	35CEh

l0C74_35C7:
	push	32h
	call	far 11C8h:0354h

l0C74_35CE:
	jmp	35D5h

l0C74_35D0:
	call	far 11C8h:033Bh

l0C74_35D5:
	inc	word ptr [58B4h]
	inc	word ptr [58B6h]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	al,[bp-2h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+58E4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-3h],16h
	jnz	359Ch

l0C74_3602:
	push	word ptr [bp-0Ah]
	push	word ptr [bp-0Ch]
	push	word ptr [bp-0Eh]
	call	far 1EDAh:0254h

l0C74_3610:
	mov	al,[bp-1h]
	leave
	ret

;; fn0C74_3615: 0C74:3615
;;   Called from:
;;     0C74:5467 (in fn0C74_542B)
;;     0C74:54E5 (in fn0C74_54B1)
fn0C74_3615 proc
	enter	4h,0h
	mov	byte ptr [bp-1h],0h
	cmp	word ptr [58B6h],27Eh
	jc	3628h

l0C74_3625:
	jmp	37BEh

l0C74_3628:
	mov	byte ptr [58B1h],0h
	cmp	word ptr [5968h],0FFh
	jnz	3640h

l0C74_3634:
	push	15h
	call	0CFAh
	mov	byte ptr [bp-1h],1h
	jmp	37BEh

l0C74_3640:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	368Fh

l0C74_3652:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	368Fh

l0C74_3667:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	sub	ax,29h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	368Fh

l0C74_367C:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3692h

l0C74_368F:
	jmp	37BEh

l0C74_3692:
	mov	byte ptr [bp-1h],1h
	mov	byte ptr [bp-2h],0h

l0C74_369A:
	mov	byte ptr [bp-3h],1h
	jmp	36A3h

l0C74_36A0:
	inc	byte ptr [bp-3h]

l0C74_36A3:
	mov	ax,[58E6h]
	shl	ax,1h
	push	ax
	call	02D8h
	inc	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],5h
	jnz	36C9h

l0C74_36B5:
	mov	byte ptr [bp-2h],1h
	cmp	byte ptr [58B0h],0h
	jz	36C7h

l0C74_36C0:
	push	32h
	call	far 11C8h:0354h

l0C74_36C7:
	jmp	36CEh

l0C74_36C9:
	call	far 11C8h:033Bh

l0C74_36CE:
	cmp	word ptr [58B6h],27Eh
	jnc	36DEh

l0C74_36D6:
	inc	word ptr [58B4h]
	inc	word ptr [58B6h]

l0C74_36DE:
	cmp	byte ptr [58B2h],0h
	jz	370Ah

l0C74_36E5:
	call	far 1E78h:02FBh
	or	al,al
	jz	36F3h

l0C74_36EE:
	mov	byte ptr [58B1h],1h

l0C74_36F3:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	3708h

l0C74_36FE:
	mov	byte ptr [58E0h],1h
	mov	byte ptr [58B1h],1h

l0C74_3708:
	jmp	3718h

l0C74_370A:
	mov	al,[58BCh]
	cmp	al,[58BDh]
	jnz	3718h

l0C74_3713:
	mov	byte ptr [58B1h],1h

l0C74_3718:
	cmp	word ptr [58B6h],27Eh
	jc	3725h

l0C74_3720:
	mov	byte ptr [58B1h],1h

l0C74_3725:
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3770h

l0C74_3736:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3770h

l0C74_374A:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	sub	ax,29h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3770h

l0C74_375E:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3781h

l0C74_3770:
	dec	word ptr [58B4h]
	dec	word ptr [58B6h]
	call	far 11C8h:033Bh
	jmp	37BEh
0C74:377F                                              EB                .
0C74:3780 1F                                              .               

l0C74_3781:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	al,[bp-2h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+58E4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-3h],16h
	jz	37A9h

l0C74_37A6:
	jmp	36A0h

l0C74_37A9:
	cmp	byte ptr [58B1h],0h
	jnz	37B4h

l0C74_37B0:
	inc	byte ptr [58BCh]

l0C74_37B4:
	cmp	byte ptr [58B1h],0h
	jnz	37BEh

l0C74_37BB:
	jmp	369Ah

l0C74_37BE:
	mov	al,[bp-1h]
	leave
	ret

;; fn0C74_37C3: 0C74:37C3
;;   Called from:
;;     0C74:54A3 (in fn0C74_542B)
;;     0C74:5524 (in fn0C74_54F0)
fn0C74_37C3 proc
	enter	4h,0h
	mov	byte ptr [bp-1h],0h
	cmp	word ptr [58B4h],1h
	ja	37D5h

l0C74_37D2:
	jmp	3969h

l0C74_37D5:
	mov	byte ptr [58B1h],0h
	cmp	word ptr [5968h],1h
	jnz	37EDh

l0C74_37E1:
	push	15h
	call	0D43h
	mov	byte ptr [bp-1h],1h
	jmp	3969h

l0C74_37ED:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	383Ch

l0C74_37FF:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	383Ch

l0C74_3814:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	sub	ax,29h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	383Ch

l0C74_3829:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	383Fh

l0C74_383C:
	jmp	3969h

l0C74_383F:
	mov	byte ptr [bp-1h],1h
	mov	byte ptr [bp-2h],5h

l0C74_3847:
	mov	byte ptr [bp-3h],1h
	jmp	3850h

l0C74_384D:
	inc	byte ptr [bp-3h]

l0C74_3850:
	mov	ax,[58E6h]
	shl	ax,1h
	push	ax
	call	02D8h
	dec	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],0h
	jnz	3876h

l0C74_3862:
	mov	byte ptr [bp-2h],4h
	cmp	byte ptr [58B0h],0h
	jz	3874h

l0C74_386D:
	push	32h
	call	far 11C8h:0354h

l0C74_3874:
	jmp	387Bh

l0C74_3876:
	call	far 11C8h:033Bh

l0C74_387B:
	cmp	word ptr [58B4h],1h
	jbe	388Ah

l0C74_3882:
	dec	word ptr [58B4h]
	dec	word ptr [58B6h]

l0C74_388A:
	cmp	byte ptr [58B2h],0h
	jz	38B6h

l0C74_3891:
	call	far 1E78h:02FBh
	or	al,al
	jz	389Fh

l0C74_389A:
	mov	byte ptr [58B1h],1h

l0C74_389F:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	38B4h

l0C74_38AA:
	mov	byte ptr [58E0h],1h
	mov	byte ptr [58B1h],1h

l0C74_38B4:
	jmp	38C4h

l0C74_38B6:
	mov	al,[58BCh]
	cmp	al,[58BDh]
	jnz	38C4h

l0C74_38BF:
	mov	byte ptr [58B1h],1h

l0C74_38C4:
	cmp	word ptr [58B4h],1h
	ja	38D0h

l0C74_38CB:
	mov	byte ptr [58B1h],1h

l0C74_38D0:
	push	word ptr [58B4h]
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	391Bh

l0C74_38E1:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	391Bh

l0C74_38F5:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,29h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	391Bh

l0C74_3909:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	392Ch

l0C74_391B:
	inc	word ptr [58B4h]
	inc	word ptr [58B6h]
	call	far 11C8h:033Bh
	jmp	3969h
0C74:392A                               EB 1F                       ..    

l0C74_392C:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	al,[bp-2h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+58F4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-3h],16h
	jz	3954h

l0C74_3951:
	jmp	384Dh

l0C74_3954:
	cmp	byte ptr [58B1h],0h
	jnz	395Fh

l0C74_395B:
	inc	byte ptr [58BCh]

l0C74_395F:
	cmp	byte ptr [58B1h],0h
	jnz	3969h

l0C74_3966:
	jmp	3847h

l0C74_3969:
	mov	al,[bp-1h]
	leave
	ret

;; fn0C74_396E: 0C74:396E
;;   Called from:
;;     0C74:5291 (in fn0C74_5258)
fn0C74_396E proc
	enter	8h,0h
	mov	byte ptr [bp-1h],1h
	dec	word ptr [58B4h]
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0Ch
	call	far 1AB8h:1C32h
	mov	byte ptr [bp-2h],1Dh

l0C74_3990:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	inc	byte ptr [bp-2h]
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-2h],39h
	jz	39F0h

l0C74_39C8:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	39F0h

l0C74_39E2:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	cmp	ax,27Eh
	jc	3990h

l0C74_39F0:
	cmp	byte ptr [bp-2h],39h
	jz	3A4Fh

l0C74_39F6:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-2h]
	xor	ah,ah
	dec	ax
	cmp	al,1Dh
	jc	3A44h

l0C74_3A07:
	mov	[bp-3h],al
	jmp	3A0Fh

l0C74_3A0C:
	dec	byte ptr [bp-3h]

l0C74_3A0F:
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],1Dh
	jnz	3A0Ch

l0C74_3A44:
	inc	word ptr [58B4h]
	mov	byte ptr [bp-1h],0h
	jmp	3F6Fh

l0C74_3A4F:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,2Ah
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	mov	ax,[58B4h]
	add	ax,2Ah
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	mov	byte ptr [bp-3h],3h
	jmp	3AB1h

l0C74_3AAE:
	inc	byte ptr [bp-3h]

l0C74_3AB1:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	190h
	push	32h
	call	070Dh
	cmp	byte ptr [bp-3h],14h
	jz	3BC3h

l0C74_3BC0:
	jmp	3AAEh

l0C74_3BC3:
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	mov	ax,[58B8h]
	add	ax,6h
	push	ax
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	mov	ax,[58B8h]
	add	ax,10h
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B8h]
	add	ax,6h
	mov	[bp-6h],ax
	mov	ax,[58B8h]
	add	ax,14h
	mov	[bp-8h],ax
	mov	byte ptr [bp-3h],1h
	jmp	3C14h

l0C74_3C11:
	inc	byte ptr [bp-3h]

l0C74_3C14:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-6h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-6h]
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	push	word ptr [bp-8h]
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,39h
	push	ax
	push	word ptr [bp-8h]
	push	0h
	call	far 1AB8h:1E54h
	inc	word ptr [bp-6h]
	inc	word ptr [bp-8h]
	push	64h
	push	64h
	call	070Dh
	cmp	byte ptr [bp-3h],0Bh
	jnz	3C11h

l0C74_3C89:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	push	word ptr [bp-8h]
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,39h
	push	ax
	push	word ptr [bp-8h]
	push	0h
	call	far 1AB8h:1E54h
	push	1F4h
	call	02D8h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	mov	ax,[58B8h]
	add	ax,10h
	mov	[bp-6h],ax
	mov	ax,[58B8h]
	add	ax,1Eh
	mov	[bp-8h],ax
	mov	byte ptr [bp-3h],1h
	jmp	3D0Ch

l0C74_3D09:
	inc	byte ptr [bp-3h]

l0C74_3D0C:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-6h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-6h]
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	dec	word ptr [bp-6h]
	dec	word ptr [bp-8h]
	push	64h
	push	64h
	call	070Dh
	cmp	byte ptr [bp-3h],0Bh
	jnz	3D09h

l0C74_3D5F:
	mov	byte ptr [bp-3h],14h
	jmp	3D68h

l0C74_3D65:
	dec	byte ptr [bp-3h]

l0C74_3D68:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	190h
	push	32h
	call	070Dh
	cmp	byte ptr [bp-3h],3h
	jz	3E7Ah

l0C74_3E77:
	jmp	3D65h

l0C74_3E7A:
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	mov	ax,[58B8h]
	add	ax,10h
	push	ax
	push	0h
	call	far 1AB8h:1E54h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,2Ah
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	1F4h
	call	02D8h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,2Ah
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,2Ah
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-2h]
	xor	ah,ah
	dec	ax
	cmp	al,1Dh
	jc	3F6Bh

l0C74_3F2E:
	mov	[bp-3h],al
	jmp	3F36h

l0C74_3F33:
	dec	byte ptr [bp-3h]

l0C74_3F36:
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],1Dh
	jnz	3F33h

l0C74_3F6B:
	inc	word ptr [58B4h]

l0C74_3F6F:
	mov	al,[bp-1h]
	leave
	ret

;; fn0C74_3F74: 0C74:3F74
;;   Called from:
;;     0C74:52D3 (in fn0C74_5258)
fn0C74_3F74 proc
	enter	0Ah,0h
	mov	byte ptr [bp-1h],1h
	inc	word ptr [58B4h]
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0Ch
	call	far 1AB8h:1C32h
	mov	word ptr [bp-4h],0Dh

l0C74_3F97:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	dec	word ptr [bp-4h]
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-4h],0F3h
	jz	4024h

l0C74_3FDF:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4024h

l0C74_4001:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	cmp	dx,0h
	jl	4024h

l0C74_4017:
	jle	401Ch

l0C74_4019:
	jmp	3F97h

l0C74_401C:
	cmp	ax,1h
	jbe	4024h

l0C74_4021:
	jmp	3F97h

l0C74_4024:
	cmp	word ptr [bp-4h],0F3h
	jz	4092h

l0C74_402A:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	inc	ax
	cmp	ax,0Dh
	jg	4087h

l0C74_403A:
	mov	[bp-6h],ax
	jmp	4042h

l0C74_403F:
	inc	word ptr [bp-6h]

l0C74_4042:
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	403Fh

l0C74_4087:
	dec	word ptr [58B4h]
	mov	byte ptr [bp-1h],0h
	jmp	45C9h

l0C74_4092:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	mov	word ptr [bp-6h],3h
	jmp	40F1h

l0C74_40EE:
	inc	word ptr [bp-6h]

l0C74_40F1:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	di,[bp-6h]
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	190h
	push	32h
	call	070Dh
	cmp	word ptr [bp-6h],14h
	jz	420Ah

l0C74_4207:
	jmp	40EEh

l0C74_420A:
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,6h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,10h
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B8h]
	add	ax,6h
	mov	[bp-8h],ax
	mov	ax,[58B8h]
	add	ax,14h
	mov	[bp-0Ah],ax
	mov	word ptr [bp-6h],1h
	jmp	425Ch

l0C74_4259:
	inc	word ptr [bp-6h]

l0C74_425C:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-0Ah]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-0Ah]
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	push	word ptr [bp-0Ah]
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	sub	ax,0Eh
	push	ax
	push	word ptr [bp-0Ah]
	push	0h
	call	far 1AB8h:1E54h
	inc	word ptr [bp-8h]
	inc	word ptr [bp-0Ah]
	push	64h
	push	64h
	call	070Dh
	cmp	word ptr [bp-6h],0Bh
	jnz	4259h

l0C74_42D1:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-0Ah]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-0Ah]
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	push	word ptr [bp-0Ah]
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	sub	ax,0Eh
	push	ax
	push	word ptr [bp-0Ah]
	push	0h
	call	far 1AB8h:1E54h
	push	1F4h
	call	02D8h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-0Ah]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-0Ah]
	call	far 1AB8h:1AF6h
	mov	ax,[58B8h]
	add	ax,10h
	mov	[bp-8h],ax
	mov	ax,[58B8h]
	add	ax,1Eh
	mov	[bp-0Ah],ax
	mov	word ptr [bp-6h],1h
	jmp	4355h

l0C74_4352:
	inc	word ptr [bp-6h]

l0C74_4355:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-0Ah]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-0Ah]
	call	far 1AB8h:1AF6h
	dec	word ptr [bp-8h]
	dec	word ptr [bp-0Ah]
	push	64h
	push	64h
	call	070Dh
	cmp	word ptr [bp-6h],0Bh
	jnz	4352h

l0C74_43A8:
	mov	word ptr [bp-6h],14h
	jmp	43B2h

l0C74_43AF:
	dec	word ptr [bp-6h]

l0C74_43B2:
	push	0h
	call	far 1AB8h:1C32h
	mov	di,[bp-6h]
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	190h
	push	32h
	call	070Dh
	cmp	word ptr [bp-6h],3h
	jz	44CBh

l0C74_44C8:
	jmp	43AFh

l0C74_44CB:
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,10h
	push	ax
	push	0h
	call	far 1AB8h:1E54h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	1F4h
	call	02D8h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	inc	ax
	cmp	ax,0Dh
	jg	45C5h

l0C74_4578:
	mov	[bp-6h],ax
	jmp	4580h

l0C74_457D:
	inc	word ptr [bp-6h]

l0C74_4580:
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	457Dh

l0C74_45C5:
	dec	word ptr [58B4h]

l0C74_45C9:
	mov	al,[bp-1h]
	leave
	ret

;; fn0C74_45CE: 0C74:45CE
;;   Called from:
;;     0C74:529D (in fn0C74_5258)
fn0C74_45CE proc
	enter	8h,0h
	mov	byte ptr [bp-1h],1h
	dec	word ptr [58B4h]
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0Ch
	call	far 1AB8h:1C32h
	mov	byte ptr [bp-2h],1Dh

l0C74_45F0:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	inc	byte ptr [bp-2h]
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-2h],3Ah
	jz	4650h

l0C74_4628:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4650h

l0C74_4642:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	cmp	ax,27Eh
	jc	45F0h

l0C74_4650:
	cmp	byte ptr [bp-2h],3Ah
	jz	46AFh

l0C74_4656:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-2h]
	xor	ah,ah
	dec	ax
	cmp	al,1Dh
	jc	46A4h

l0C74_4667:
	mov	[bp-3h],al
	jmp	466Fh

l0C74_466C:
	dec	byte ptr [bp-3h]

l0C74_466F:
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],1Dh
	jnz	466Ch

l0C74_46A4:
	inc	word ptr [58B4h]
	mov	byte ptr [bp-1h],0h
	jmp	4994h

l0C74_46AF:
	push	1F4h
	call	02D8h
	mov	ax,[58B8h]
	add	ax,12h
	mov	[bp-6h],ax
	mov	ax,[58B8h]
	add	ax,14h
	mov	[bp-8h],ax

l0C74_46C7:
	mov	ax,[58B4h]
	add	ax,39h
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	472Eh

l0C74_46DA:
	cmp	word ptr [bp-8h],1DEh
	jnc	472Eh

l0C74_46E1:
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	add	ax,3Ah
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	push	word ptr [bp-6h]
	mov	ax,[58B4h]
	add	ax,3Ah
	push	ax
	push	word ptr [bp-6h]
	call	far 1AB8h:1AF6h
	push	1Eh
	call	02D8h
	inc	word ptr [bp-6h]
	inc	word ptr [bp-8h]
	jmp	46C7h

l0C74_472E:
	mov	ax,[58B6h]
	inc	ax
	mov	[596Ch],ax
	mov	ax,[58B6h]
	add	ax,2Ch
	mov	[5970h],ax
	cmp	word ptr [5970h],27Eh
	jle	474Ch

l0C74_4746:
	mov	word ptr [5970h],27Eh

l0C74_474C:
	mov	ax,[bp-8h]
	cmp	ax,[58BAh]
	jnc	4763h

l0C74_4755:
	mov	ax,[58B8h]
	mov	[596Eh],ax
	mov	ax,[58BAh]
	mov	[5972h],ax
	jmp	4775h

l0C74_4763:
	mov	ax,[bp-8h]
	sub	ax,16h
	mov	[596Eh],ax
	mov	ax,[bp-8h]
	add	ax,15h
	mov	[5972h],ax

l0C74_4775:
	cmp	word ptr [5972h],176h
	jle	4789h

l0C74_477D:
	mov	word ptr [5972h],176h
	mov	word ptr [596Eh],14Ah

l0C74_4789:
	mov	ax,[5970h]
	sub	ax,15h
	push	ax
	mov	ax,[5972h]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	47BCh

l0C74_47A0:
	mov	ax,[5970h]
	sub	ax,15h
	push	ax
	mov	ax,[5972h]
	sub	ax,2Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	47BCh

l0C74_47B7:
	sub	word ptr [5970h],16h

l0C74_47BC:
	mov	ax,[596Ch]
	add	ax,16h
	push	ax
	push	word ptr [596Eh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	47E6h

l0C74_47D0:
	push	word ptr [596Ch]
	push	word ptr [596Eh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	47E6h

l0C74_47E1:
	add	word ptr [596Eh],12h

l0C74_47E6:
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	push	ax
	mov	ax,[58B4h]
	add	ax,3Ah
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[58B4h]
	add	ax,3Ah
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-2h]
	xor	ah,ah
	dec	ax
	cmp	al,1Dh
	jc	4877h

l0C74_483A:
	mov	[bp-3h],al
	jmp	4842h

l0C74_483F:
	dec	byte ptr [bp-3h]

l0C74_4842:
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],1Dh
	jnz	483Fh

l0C74_4877:
	inc	word ptr [58B4h]
	mov	byte ptr [bp-2h],5h
	mov	byte ptr [bp-4h],1h
	mov	byte ptr [bp-3h],1h
	jmp	488Ch

l0C74_4889:
	inc	byte ptr [bp-3h]

l0C74_488C:
	push	12Ch
	push	14h
	call	070Dh
	push	0Ah
	call	02D8h
	dec	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],0h
	jnz	48B6h

l0C74_48A2:
	mov	byte ptr [bp-2h],4h
	cmp	byte ptr [58B0h],0h
	jz	48B4h

l0C74_48AD:
	push	32h
	call	far 11C8h:0354h

l0C74_48B4:
	jmp	48BBh

l0C74_48B6:
	call	far 11C8h:033Bh

l0C74_48BB:
	cmp	word ptr [58B4h],0h
	jbe	48CDh

l0C74_48C2:
	inc	byte ptr [bp-4h]
	dec	word ptr [58B4h]
	dec	word ptr [58B6h]

l0C74_48CD:
	cmp	word ptr [58B6h],0h
	jbe	490Bh

l0C74_48D4:
	push	word ptr [58B4h]
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	490Bh

l0C74_48E5:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	490Bh

l0C74_48F9:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	491Dh

l0C74_490B:
	dec	byte ptr [bp-4h]
	inc	word ptr [58B4h]
	inc	word ptr [58B6h]
	call	far 11C8h:033Bh
	jmp	493Ch

l0C74_491D:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	al,[bp-2h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+58E4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h

l0C74_493C:
	cmp	byte ptr [bp-3h],2Ch
	jz	4945h

l0C74_4942:
	jmp	4889h

l0C74_4945:
	cmp	byte ptr [bp-4h],16h
	jnc	4980h

l0C74_494B:
	mov	ax,[58BAh]
	add	ax,17h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[5972h]
	cwd
	cmp	dx,bx
	jl	4965h

l0C74_495F:
	jg	4980h

l0C74_4961:
	cmp	ax,cx
	ja	4980h

l0C74_4965:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	push	word ptr [5970h]
	push	word ptr [5972h]
	push	cs
	call	076Bh
	mov	byte ptr [58B3h],1h
	jmp	4994h

l0C74_4980:
	push	word ptr [596Ch]
	push	word ptr [596Eh]
	push	word ptr [5970h]
	push	word ptr [5972h]
	push	cs
	call	076Bh

l0C74_4994:
	mov	al,[bp-1h]
	leave
	ret

;; fn0C74_4999: 0C74:4999
;;   Called from:
;;     0C74:52DF (in fn0C74_5258)
fn0C74_4999 proc
	enter	0Ch,0h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0Ch
	call	far 1AB8h:1C32h
	mov	word ptr [bp-4h],0Dh
	inc	word ptr [58B4h]
	mov	byte ptr [bp-1h],1h

l0C74_49BC:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	dec	word ptr [bp-4h]
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-4h],0F1h
	jz	4A49h

l0C74_4A04:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4A49h

l0C74_4A26:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	cmp	dx,0h
	jl	4A49h

l0C74_4A3C:
	jle	4A41h

l0C74_4A3E:
	jmp	49BCh

l0C74_4A41:
	cmp	ax,0h
	jbe	4A49h

l0C74_4A46:
	jmp	49BCh

l0C74_4A49:
	cmp	word ptr [bp-4h],0F1h
	jz	4AB7h

l0C74_4A4F:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	inc	ax
	cmp	ax,0Dh
	jg	4AACh

l0C74_4A5F:
	mov	[bp-6h],ax
	jmp	4A67h

l0C74_4A64:
	inc	word ptr [bp-6h]

l0C74_4A67:
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	4A64h

l0C74_4AAC:
	dec	word ptr [58B4h]
	mov	byte ptr [bp-1h],0h
	jmp	4DA7h

l0C74_4AB7:
	push	1F4h
	call	02D8h
	mov	ax,[58B8h]
	add	ax,12h
	mov	[bp-0Ah],ax
	mov	ax,[58B8h]
	add	ax,14h
	mov	[bp-0Ch],ax

l0C74_4ACF:
	mov	ax,[58B4h]
	sub	ax,0Eh
	push	ax
	push	word ptr [bp-0Ch]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4B36h

l0C74_4AE2:
	cmp	word ptr [bp-0Ch],1DEh
	jnc	4B36h

l0C74_4AE9:
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	push	word ptr [bp-0Ch]
	mov	ax,[58B4h]
	sub	ax,0Fh
	push	ax
	push	word ptr [bp-0Ch]
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	push	word ptr [bp-0Ah]
	mov	ax,[58B4h]
	sub	ax,0Fh
	push	ax
	push	word ptr [bp-0Ah]
	call	far 1AB8h:1AF6h
	push	28h
	call	02D8h
	inc	word ptr [bp-0Ah]
	inc	word ptr [bp-0Ch]
	jmp	4ACFh

l0C74_4B36:
	mov	ax,[58B4h]
	sub	ax,2Dh
	mov	[596Ch],ax
	mov	ax,[58B4h]
	dec	ax
	dec	ax
	mov	[5970h],ax
	cmp	word ptr [596Ch],1h
	jge	4B54h

l0C74_4B4E:
	mov	word ptr [596Ch],1h

l0C74_4B54:
	mov	ax,[bp-0Ch]
	cmp	ax,[58BAh]
	jnc	4B6Bh

l0C74_4B5D:
	mov	ax,[58B8h]
	mov	[596Eh],ax
	mov	ax,[58BAh]
	mov	[5972h],ax
	jmp	4B7Dh

l0C74_4B6B:
	mov	ax,[bp-0Ch]
	sub	ax,16h
	mov	[596Eh],ax
	mov	ax,[bp-0Ch]
	add	ax,15h
	mov	[5972h],ax

l0C74_4B7D:
	cmp	word ptr [5972h],176h
	jle	4B91h

l0C74_4B85:
	mov	word ptr [5972h],176h
	mov	word ptr [596Eh],14Ah

l0C74_4B91:
	push	word ptr [596Ch]
	mov	ax,[5972h]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4BBBh

l0C74_4BA5:
	push	word ptr [596Ch]
	push	word ptr [596Eh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4BBBh

l0C74_4BB6:
	add	word ptr [596Ch],16h

l0C74_4BBB:
	mov	ax,[5970h]
	sub	ax,15h
	push	ax
	push	word ptr [596Eh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4BE8h

l0C74_4BCF:
	mov	ax,[5970h]
	sub	ax,2Bh
	push	ax
	push	word ptr [596Eh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4BE8h

l0C74_4BE3:
	add	word ptr [596Eh],12h

l0C74_4BE8:
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[bp-0Ah]
	dec	ax
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Fh
	push	ax
	mov	ax,[bp-0Ah]
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[bp-0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Fh
	push	ax
	mov	ax,[bp-0Ah]
	dec	ax
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	inc	ax
	cmp	ax,0Dh
	jg	4C88h

l0C74_4C3B:
	mov	[bp-6h],ax
	jmp	4C43h

l0C74_4C40:
	inc	word ptr [bp-6h]

l0C74_4C43:
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	4C40h

l0C74_4C88:
	dec	word ptr [58B4h]
	xor	ax,ax
	mov	[bp-4h],ax
	mov	word ptr [bp-8h],1h
	mov	word ptr [bp-6h],1h
	jmp	4CA0h

l0C74_4C9D:
	inc	word ptr [bp-6h]

l0C74_4CA0:
	push	12Ch
	push	14h
	call	070Dh
	push	0Ah
	call	02D8h
	inc	word ptr [bp-4h]
	cmp	word ptr [bp-4h],5h
	jnz	4CCBh

l0C74_4CB6:
	mov	word ptr [bp-4h],1h
	cmp	byte ptr [58B0h],0h
	jz	4CC9h

l0C74_4CC2:
	push	32h
	call	far 11C8h:0354h

l0C74_4CC9:
	jmp	4CD0h

l0C74_4CCB:
	call	far 11C8h:033Bh

l0C74_4CD0:
	cmp	word ptr [58B6h],27Fh
	jnc	4CE3h

l0C74_4CD8:
	inc	word ptr [58B4h]
	inc	word ptr [58B6h]
	inc	word ptr [bp-8h]

l0C74_4CE3:
	cmp	word ptr [58B6h],27Fh
	jnc	4D22h

l0C74_4CEB:
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4D22h

l0C74_4CFC:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4D22h

l0C74_4D10:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4D34h

l0C74_4D22:
	dec	word ptr [58B4h]
	dec	word ptr [58B6h]
	dec	word ptr [bp-8h]
	call	far 11C8h:033Bh
	jmp	4D4Fh

l0C74_4D34:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	di,[bp-4h]
	shl	di,2h
	les	di,[di+58F4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h

l0C74_4D4F:
	cmp	word ptr [bp-6h],2Ch
	jz	4D58h

l0C74_4D55:
	jmp	4C9Dh

l0C74_4D58:
	cmp	word ptr [bp-8h],16h
	jge	4D93h

l0C74_4D5E:
	mov	ax,[58BAh]
	add	ax,17h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[5972h]
	cwd
	cmp	dx,bx
	jl	4D78h

l0C74_4D72:
	jg	4D93h

l0C74_4D74:
	cmp	ax,cx
	ja	4D93h

l0C74_4D78:
	push	word ptr [596Ch]
	push	word ptr [596Eh]
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	push	cs
	call	076Bh
	mov	byte ptr [58B3h],1h
	jmp	4DA7h

l0C74_4D93:
	push	word ptr [596Ch]
	push	word ptr [596Eh]
	push	word ptr [5970h]
	push	word ptr [5972h]
	push	cs
	call	076Bh

l0C74_4DA7:
	mov	al,[bp-1h]
	leave
	ret

;; fn0C74_4DAC: 0C74:4DAC
;;   Called from:
;;     0C74:549D (in fn0C74_542B)
fn0C74_4DAC proc
	enter	0Ch,0h
	mov	word ptr [bp-4h],0Dh
	mov	byte ptr [bp-1h],1h

l0C74_4DB9:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	push	0Ah
	call	far 1AB8h:1E54h
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	push	2h
	call	far 1AB8h:1E54h
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	push	8h
	call	far 1AB8h:1E54h
	dec	word ptr [bp-4h]
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-4h],0E9h
	jz	4E6Fh

l0C74_4E2A:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4E6Fh

l0C74_4E4C:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	cmp	dx,0h
	jl	4E6Fh

l0C74_4E62:
	jle	4E67h

l0C74_4E64:
	jmp	4DB9h

l0C74_4E67:
	cmp	ax,1h
	jbe	4E6Fh

l0C74_4E6C:
	jmp	4DB9h

l0C74_4E6F:
	cmp	word ptr [bp-4h],0E9h
	jz	4ED9h

l0C74_4E75:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	inc	ax
	cmp	ax,0Dh
	jg	4ED2h

l0C74_4E85:
	mov	[bp-6h],ax
	jmp	4E8Dh

l0C74_4E8A:
	inc	word ptr [bp-6h]

l0C74_4E8D:
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	4E8Ah

l0C74_4ED2:
	mov	byte ptr [bp-1h],0h
	jmp	4FD2h

l0C74_4ED9:
	push	1F4h
	call	02D8h
	mov	ax,[58B4h]
	sub	ax,16h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-8h],ax
	push	word ptr [bp-8h]
	call	far 1EDAh:023Fh
	mov	[bp-0Ch],ax
	mov	[bp-0Ah],dx
	mov	ax,[58B4h]
	sub	ax,16h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	les	di,[bp-0Ch]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	word ptr [bp-4h],12h
	jmp	4F3Dh

l0C74_4F3A:
	inc	word ptr [bp-4h]

l0C74_4F3D:
	mov	ax,[58B4h]
	sub	ax,16h
	push	ax
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B8h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	les	di,[bp-0Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	12Ch
	push	14h
	call	070Dh
	push	28h
	call	02D8h
	cmp	word ptr [bp-4h],2Bh
	jnz	4F3Ah

l0C74_4F75:
	push	word ptr [bp-0Ah]
	push	word ptr [bp-0Ch]
	push	word ptr [bp-8h]
	call	far 1EDAh:0254h
	mov	word ptr [bp-6h],0FFEAh
	jmp	4F8Dh

l0C74_4F8A:
	inc	word ptr [bp-6h]

l0C74_4F8D:
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	4F8Ah

l0C74_4FD2:
	mov	al,[bp-1h]
	leave
	ret

;; fn0C74_4FD7: 0C74:4FD7
;;   Called from:
;;     0C74:5461 (in fn0C74_542B)
fn0C74_4FD7 proc
	enter	0Ah,0h
	mov	byte ptr [bp-1h],1h
	mov	byte ptr [bp-2h],1Dh

l0C74_4FE3:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	push	0Ah
	call	far 1AB8h:1E54h
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	push	2h
	call	far 1AB8h:1E54h
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	push	8h
	call	far 1AB8h:1E54h
	inc	byte ptr [bp-2h]
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-2h],42h
	jz	5067h

l0C74_503C:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	5067h

l0C74_5056:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	cmp	ax,27Eh
	jnc	5067h

l0C74_5064:
	jmp	4FE3h

l0C74_5067:
	cmp	byte ptr [bp-2h],42h
	jz	50C2h

l0C74_506D:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-2h]
	xor	ah,ah
	dec	ax
	cmp	al,1Dh
	jc	50BBh

l0C74_507E:
	mov	[bp-3h],al
	jmp	5086h

l0C74_5083:
	dec	byte ptr [bp-3h]

l0C74_5086:
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],1Dh
	jnz	5083h

l0C74_50BB:
	mov	byte ptr [bp-1h],0h
	jmp	51A5h

l0C74_50C2:
	push	1F4h
	call	02D8h
	mov	ax,[58B4h]
	add	ax,2Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	add	ax,41h
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-6h],ax
	push	word ptr [bp-6h]
	call	far 1EDAh:023Fh
	mov	[bp-0Ah],ax
	mov	[bp-8h],dx
	mov	ax,[58B4h]
	add	ax,2Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	add	ax,41h
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	les	di,[bp-0Ah]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	byte ptr [bp-2h],12h
	jmp	5129h

l0C74_5126:
	inc	byte ptr [bp-2h]

l0C74_5129:
	mov	ax,[58B4h]
	add	ax,2Ch
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	les	di,[bp-0Ah]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	12Ch
	push	14h
	call	070Dh
	push	28h
	call	02D8h
	cmp	byte ptr [bp-2h],2Bh
	jnz	5126h

l0C74_5159:
	push	word ptr [bp-8h]
	push	word ptr [bp-0Ah]
	push	word ptr [bp-6h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-3h],2Ch
	jmp	5170h

l0C74_516D:
	dec	byte ptr [bp-3h]

l0C74_5170:
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],1Dh
	jnz	516Dh

l0C74_51A5:
	mov	al,[bp-1h]
	leave
	ret

;; fn0C74_51AA: 0C74:51AA
;;   Called from:
;;     0800:2765 (in fn0800_2401)
;;     0800:2A4C (in fn0800_2827)
;;     0800:301C (in fn0800_2C0C)
;;     0800:358F (in fn0800_31B7)
;;     0800:3F19 (in fn0800_3D9D)
fn0C74_51AA proc
	push	bp
	mov	bp,sp
	call	1B3Bh
	leave
	retf

;; fn0C74_51B2: 0C74:51B2
;;   Called from:
;;     0800:27ED (in fn0800_2401)
;;     0800:2AD4 (in fn0800_2827)
;;     0800:307D (in fn0800_2C0C)
;;     0800:35F0 (in fn0800_31B7)
fn0C74_51B2 proc
	enter	2h,0h
	mov	byte ptr [bp-1h],0h
	mov	ax,[5968h]
	cmp	ax,1h
	jnz	51F1h

l0C74_51C2:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	51EAh

l0C74_51D5:
	mov	ax,[58B6h]
	add	ax,17h
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	51ECh

l0C74_51EA:
	jmp	5227h

l0C74_51EC:
	call	2AD9h
	jmp	5223h

l0C74_51F1:
	cmp	ax,0FFFFh
	jnz	5223h

l0C74_51F6:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	521Eh

l0C74_5209:
	mov	ax,[58B4h]
	sub	ax,17h
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	5220h

l0C74_521E:
	jmp	5227h

l0C74_5220:
	call	2AD9h

l0C74_5223:
	mov	byte ptr [bp-1h],1h

l0C74_5227:
	mov	al,[bp-1h]
	leave
	retf

;; fn0C74_522C: 0C74:522C
;;   Called from:
;;     0800:08D1 (in fn0800_08C0)
;;     0800:26DD (in fn0800_2401)
;;     0800:29C4 (in fn0800_2827)
;;     0800:2EE5 (in fn0800_2C0C)
;;     0800:34C0 (in fn0800_31B7)
fn0C74_522C proc
	enter	2h,0h
	mov	byte ptr [bp-1h],1h
	mov	ax,[5968h]
	cmp	ax,1h
	jnz	5244h

l0C74_523C:
	call	3236h
	mov	[bp-1h],al
	jmp	524Fh

l0C74_5244:
	cmp	ax,0FFFFh
	jnz	524Fh

l0C74_5249:
	call	2E5Ah
	mov	[bp-1h],al

l0C74_524F:
	push	cs
	call	05B8h
	mov	al,[bp-1h]
	leave
	retf

;; fn0C74_5258: 0C74:5258
;;   Called from:
;;     0800:273A (in fn0800_2401)
;;     0800:2A21 (in fn0800_2827)
;;     0800:2F2F (in fn0800_2C0C)
;;     0800:350A (in fn0800_31B7)
fn0C74_5258 proc
	enter	10h,0h
	mov	byte ptr [bp-2h],1h
	mov	ax,[5968h]
	cmp	ax,1h
	jnz	52A5h

l0C74_5268:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	5297h

l0C74_527A:
	mov	ax,[58B6h]
	add	ax,0Ch
	push	ax
	mov	ax,[58BAh]
	sub	ax,0Ch
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	5297h

l0C74_5291:
	call	396Eh
	mov	[bp-2h],al

l0C74_5297:
	cmp	byte ptr [bp-2h],0h
	jz	52A3h

l0C74_529D:
	call	45CEh
	mov	[bp-2h],al

l0C74_52A3:
	jmp	52E5h

l0C74_52A5:
	cmp	ax,0FFFFh
	jnz	52E5h

l0C74_52AA:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	52D9h

l0C74_52BC:
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	mov	ax,[58BAh]
	sub	ax,0Ch
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	52D9h

l0C74_52D3:
	call	3F74h
	mov	[bp-2h],al

l0C74_52D9:
	cmp	byte ptr [bp-2h],0h
	jz	52E5h

l0C74_52DF:
	call	4999h
	mov	[bp-2h],al

l0C74_52E5:
	cmp	byte ptr [bp-2h],0h
	jnz	52EEh

l0C74_52EB:
	jmp	5420h

l0C74_52EE:
	cmp	word ptr [5968h],1h
	jnz	5300h

l0C74_52F5:
	mov	ax,[5970h]
	sub	ax,15h
	mov	[bp-4h],ax
	jmp	5306h

l0C74_5300:
	mov	ax,[596Ch]
	mov	[bp-4h],ax

l0C74_5306:
	cmp	word ptr [5968h],1h
	jnz	5315h

l0C74_530D:
	mov	ax,[5970h]
	mov	[bp-8h],ax
	jmp	531Eh

l0C74_5315:
	mov	ax,[596Ch]
	add	ax,15h
	mov	[bp-8h],ax

l0C74_531E:
	push	word ptr [bp-8h]
	mov	ax,[596Eh]
	add	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	535Ch

l0C74_5331:
	push	word ptr [bp-8h]
	mov	ax,[596Eh]
	add	ax,14h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	535Ch

l0C74_5344:
	mov	ax,[596Eh]
	add	ax,15h
	mov	[bp-6h],ax
	push	word ptr [bp-8h]
	push	word ptr [bp-6h]
	push	8h
	call	far 1AB8h:1E54h
	jmp	5363h

l0C74_535C:
	mov	ax,[596Eh]
	dec	ax
	mov	[bp-6h],ax

l0C74_5363:
	mov	ax,[bp-6h]
	mov	[bp-0Ah],ax

l0C74_5369:
	cmp	word ptr [bp-6h],2h
	jbe	5385h

l0C74_536F:
	push	word ptr [bp-8h]
	push	word ptr [bp-6h]
	call	far 1AB8h:1E3Ch
	cmp	ax,8h
	jnz	5385h

l0C74_537F:
	sub	word ptr [bp-6h],16h
	jmp	5369h

l0C74_5385:
	mov	ax,[bp-6h]
	cmp	ax,[bp-0Ah]
	jnz	5390h

l0C74_538D:
	jmp	5420h

l0C74_5390:
	push	word ptr [bp-4h]
	mov	ax,[bp-6h]
	dec	ax
	push	ax
	push	word ptr [bp-8h]
	push	word ptr [bp-6h]
	call	far 1AB8h:13A3h
	mov	[bp-10h],ax
	push	word ptr [bp-10h]
	call	far 1EDAh:023Fh
	mov	[bp-0Eh],ax
	mov	[bp-0Ch],dx
	push	word ptr [bp-4h]
	mov	ax,[bp-6h]
	dec	ax
	push	ax
	push	word ptr [bp-8h]
	push	word ptr [bp-6h]
	les	di,[bp-0Eh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	call	far 1AB8h:1C32h
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	push	word ptr [bp-8h]
	push	word ptr [bp-6h]
	call	far 1AB8h:1AF6h
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	push	word ptr [bp-8h]
	push	word ptr [bp-0Ah]
	call	2BBDh
	push	word ptr [bp-4h]
	mov	ax,[bp-6h]
	dec	ax
	push	ax
	les	di,[bp-0Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [bp-0Ch]
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1EDAh:0254h

l0C74_5420:
	mov	al,[bp-2h]
	mov	[bp-1h],al
	mov	al,[bp-1h]
	leave
	retf

;; fn0C74_542B: 0C74:542B
;;   Called from:
;;     0800:2715 (in fn0800_2401)
;;     0800:29FC (in fn0800_2827)
;;     0800:2F0A (in fn0800_2C0C)
;;     0800:34E5 (in fn0800_31B7)
fn0C74_542B proc
	enter	2h,0h
	mov	byte ptr [bp-1h],1h
	mov	ax,[5968h]
	cmp	ax,1h
	jnz	5472h

l0C74_543B:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	546Ch

l0C74_544E:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	dec	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	546Ch

l0C74_5461:
	call	4FD7h
	mov	[bp-1h],al
	call	3615h
	jmp	5470h

l0C74_546C:
	mov	byte ptr [bp-1h],0h

l0C74_5470:
	jmp	54ACh

l0C74_5472:
	cmp	ax,0FFFFh
	jnz	54ACh

l0C74_5477:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	54A8h

l0C74_548A:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	dec	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	54A8h

l0C74_549D:
	call	4DACh
	mov	[bp-1h],al
	call	37C3h
	jmp	54ACh

l0C74_54A8:
	mov	byte ptr [bp-1h],0h

l0C74_54AC:
	mov	al,[bp-1h]
	leave
	retf

;; fn0C74_54B1: 0C74:54B1
;;   Called from:
;;     0800:27C7 (in fn0800_2401)
;;     0800:2AAE (in fn0800_2827)
;;     0800:3057 (in fn0800_2C0C)
;;     0800:35CA (in fn0800_31B7)
;;     0800:3E5F (in fn0800_3D9D)
;;     0800:3E74 (in fn0800_3D9D)
fn0C74_54B1 proc
	enter	2h,0h
	mov	byte ptr [58BCh],1h
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	54E5h

l0C74_54CD:
	mov	ax,[58B6h]
	add	ax,17h
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	54E5h

l0C74_54E2:
	call	2AD9h

l0C74_54E5:
	call	3615h
	mov	[bp-1h],al
	mov	al,[bp-1h]
	leave
	retf

;; fn0C74_54F0: 0C74:54F0
;;   Called from:
;;     0800:278E (in fn0800_2401)
;;     0800:2A75 (in fn0800_2827)
;;     0800:3031 (in fn0800_2C0C)
;;     0800:35A4 (in fn0800_31B7)
;;     0800:3E89 (in fn0800_3D9D)
;;     0800:3E9E (in fn0800_3D9D)
fn0C74_54F0 proc
	enter	2h,0h
	mov	byte ptr [58BCh],1h
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	5524h

l0C74_550C:
	mov	ax,[58B4h]
	sub	ax,17h
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	5524h

l0C74_5521:
	call	2AD9h

l0C74_5524:
	call	37C3h
	mov	[bp-1h],al
	mov	al,[bp-1h]
	leave
	retf

;; fn0C74_552F: 0C74:552F
;;   Called from:
;;     0800:4282 (in fn0800_4255)
fn0C74_552F proc
	push	bp
	mov	bp,sp
	mov	byte ptr [58B2h],1h
	leave
	retf
0C74:5539                            00 00 00 00 00 00 00          .......
