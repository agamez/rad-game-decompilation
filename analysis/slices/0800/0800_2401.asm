;; fn0800_2401: 0800:2401
;;   Called from:
;;     0800:2F51 (in fn0800_2C0C)
fn0800_2401 proc
	enter	282h,0h
	mov	di,236Ah
	push	cs
	push	di
	call	far 0C74h:0000h
	or	al,al
	jnz	2416h

l0800_2413:
	jmp	280Eh

l0800_2416:
	call	far 1E78h:02FBh
	or	al,al
	jz	2426h

l0800_241F:
	call	far 1E78h:030Dh
	jmp	2416h

l0800_2426:
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	mov	di,2372h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	push	100h
	call	far 1EDAh:0FD0h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	push	word ptr [5990h]
	push	word ptr [598Eh]
	call	far 1EDAh:1123h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:1085h
	add	sp,4h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	cmp	byte ptr [bp+0FF01h],20h
	jnz	2480h

l0800_247D:
	jmp	280Eh

l0800_2480:
	call	far 1206h:0066h
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,82h
	push	ax
	push	96h
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,82h
	push	ax
	push	0E6h
	call	1315h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	4h
	call	far 1AB8h:1C32h
	push	140h
	push	0A4h
	mov	di,237Ah
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	1h
	call	far 1AB8h:1C32h
	push	140h
	push	0B4h
	mov	di,238Eh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	140h
	push	0C0h
	mov	di,23ACh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	140h
	push	0CCh
	mov	di,23C3h
	push	cs
	push	di
	call	far 1AB8h:1D82h

l0800_2505:
	call	far 1E78h:02FBh
	or	al,al
	jz	2505h

l0800_250E:
	mov	al,[5CDEh]
	mov	[53D9h],al
	mov	al,[5CDFh]
	mov	[53DAh],al
	mov	al,[5CDAh]
	mov	[53DBh],al
	mov	al,[5CDBh]
	mov	[53DCh],al
	cmp	byte ptr [5CDCh],0Ah
	jbe	2532h

l0800_252D:
	mov	byte ptr [5CDCh],0Ah

l0800_2532:
	mov	al,[5CDCh]
	mov	[53DDh],al
	mov	al,[5CDDh]
	mov	[53DEh],al
	xor	ax,ax
	mov	[53D6h],ax
	jmp	2549h

l0800_2545:
	inc	word ptr [53D6h]

l0800_2549:
	xor	ax,ax
	mov	[53D4h],ax
	jmp	2554h

l0800_2550:
	inc	word ptr [53D4h]

l0800_2554:
	imul	ax,[53D4h],16h
	inc	ax
	push	ax
	imul	ax,[53D6h],16h
	inc	ax
	push	ax
	mov	ax,[53D4h]
	imul	di,[53D6h],1Dh
	add	di,ax
	mov	al,[di+5CE0h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5992h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	word ptr [53D4h],1Ch
	jnz	2550h

l0800_258B:
	cmp	word ptr [53D6h],10h
	jnz	2545h

l0800_2592:
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,23E1h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	25B2h

l0800_25A3:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	jmp	280Eh

l0800_25B2:
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	0Fh
	push	184h
	push	114h
	push	18Fh
	call	005Ah
	push	8h
	call	far 1AB8h:1C32h
	push	93h
	push	189h
	mov	di,23E8h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0Ch
	call	far 1AB8h:1C32h
	push	94h
	push	18Ah
	mov	di,23E8h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	call	04E3h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,5ED6h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	call	0619h
	call	0BECh
	call	far 1206h:0066h
	mov	al,[53D9h]
	push	ax
	call	04CCh
	push	ax
	mov	al,[53DAh]
	push	ax
	call	04CCh
	push	ax
	call	far 0C74h:06B7h
	call	far 1206h:0038h
	mov	al,[53DDh]
	xor	ah,ah
	imul	ax,ax,3Ch
	cwd
	push	dx
	push	ax
	call	00C1h
	mov	byte ptr [bp+0FE7Fh],1h

l0800_264E:
	call	far 1E78h:02FBh
	or	al,al
	jz	265Eh

l0800_2657:
	call	far 1E78h:030Dh
	jmp	264Eh

l0800_265E:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2672h

l0800_2667:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	265Eh

l0800_2672:
	call	far 1E78h:02FBh
	or	al,al
	jz	2692h

l0800_267B:
	call	far 1E78h:030Dh
	mov	[53D2h],al
	cmp	byte ptr [53D2h],1Bh
	jnz	2690h

l0800_268A:
	call	0103h
	jmp	280Eh

l0800_2690:
	jmp	26A3h

l0800_2692:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	26A3h

l0800_269D:
	call	031Bh
	mov	[53D2h],al

l0800_26A3:
	cmp	byte ptr [53D2h],1Bh
	jnz	26B0h

l0800_26AA:
	call	0103h
	jmp	280Eh

l0800_26B0:
	cmp	byte ptr [bp+0FE7Fh],0FFh
	jnc	26CAh

l0800_26B7:
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[53D2h],al
	inc	byte ptr [bp+0FE7Fh]

l0800_26CA:
	mov	al,[53D2h]
	cmp	al,3Bh
	jnz	26F2h

l0800_26D1:
	push	0Eh
	call	09C2h
	cmp	byte ptr [53DBh],0h
	jbe	26EAh

l0800_26DD:
	call	far 0C74h:522Ch
	or	al,al
	jz	26EAh

l0800_26E6:
	dec	byte ptr [53DBh]

l0800_26EA:
	push	5h
	call	09C2h
	jmp	27F7h

l0800_26F2:
	cmp	al,3Ch
	jnz	272Ah

l0800_26F6:
	push	0Fh
	call	09C2h
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[58BDh],al
	inc	byte ptr [bp+0FE7Fh]
	cmp	byte ptr [53DCh],0h
	jbe	2722h

l0800_2715:
	call	far 0C74h:542Bh
	or	al,al
	jz	2722h

l0800_271E:
	dec	byte ptr [53DCh]

l0800_2722:
	push	6h
	call	09C2h
	jmp	27F7h

l0800_272A:
	cmp	al,3Dh
	jnz	274Fh

l0800_272E:
	push	10h
	call	09C2h
	cmp	byte ptr [53DEh],0h
	jbe	2747h

l0800_273A:
	call	far 0C74h:5258h
	or	al,al
	jz	2747h

l0800_2743:
	dec	byte ptr [53DEh]

l0800_2747:
	push	7h
	call	09C2h
	jmp	27F7h

l0800_274F:
	cmp	al,1Bh
	jnz	275Ch

l0800_2753:
	call	0103h
	jmp	280Eh
0800:2759                            E9 9B 00                      ...    

l0800_275C:
	cmp	al,48h
	jnz	2772h

l0800_2760:
	push	9h
	call	09C2h
	call	far 0C74h:51AAh
	push	0h
	call	09C2h
	jmp	27F7h

l0800_2772:
	cmp	al,4Bh
	jnz	27ABh

l0800_2776:
	push	0Ah
	call	09C2h
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[58BDh],al
	inc	byte ptr [bp+0FE7Fh]
	call	far 0C74h:54F0h
	or	al,al
	jnz	27A4h

l0800_2797:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_27A4:
	push	1h
	call	09C2h
	jmp	27F7h

l0800_27AB:
	cmp	al,4Dh
	jnz	27E4h

l0800_27AF:
	push	0Ch
	call	09C2h
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[58BDh],al
	inc	byte ptr [bp+0FE7Fh]
	call	far 0C74h:54B1h
	or	al,al
	jnz	27DDh

l0800_27D0:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_27DD:
	push	3h
	call	09C2h
	jmp	27F7h

l0800_27E4:
	cmp	al,50h
	jnz	27F7h

l0800_27E8:
	push	0Dh
	call	09C2h
	call	far 0C74h:51B2h
	push	4h
	call	09C2h

l0800_27F7:
	call	0C71h
	call	0877h
	or	al,al
	jnz	280Bh

l0800_2801:
	cmp	byte ptr [58B3h],0h
	jnz	280Bh

l0800_2808:
	jmp	264Eh

l0800_280B:
	call	0103h

l0800_280E:
	leave
	ret
0800:2810 07 52 61 64 2E 68 6C 70 06 4E 4F 4E 41 4D 45 07 .Rad.hlp.NONAME.
0800:2820 52 41 44 2E 48 4C 50                            RAD.HLP
