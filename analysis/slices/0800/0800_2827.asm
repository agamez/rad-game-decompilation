;; fn0800_2827: 0800:2827
;;   Called from:
;;     0800:3EF3 (in fn0800_3D9D)
fn0800_2827 proc
	enter	282h,0h

l0800_282B:
	mov	di,2810h
	push	cs
	push	di
	call	far 0C74h:0000h
	or	al,al
	jnz	283Ch

l0800_2839:
	jmp	2B41h

l0800_283C:
	call	far 1E78h:02FBh
	or	al,al
	jz	284Ch

l0800_2845:
	call	far 1E78h:030Dh
	jmp	283Ch

l0800_284C:
	call	far 1206h:0066h
	call	far 13E2h:003Bh
	call	01FEh
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2818h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	2879h

l0800_286A:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	jmp	2B41h

l0800_2879:
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	mov	di,281Fh
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
	jnz	28D3h

l0800_28D0:
	jmp	2B41h

l0800_28D3:
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
	push	94h
	push	18Ah
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	94h
	push	18Ah
	mov	di,5CBBh
	push	ds
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
	call	far 13E2h:00FBh
	push	8h
	push	0h
	call	far 1AB8h:1342h
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

l0800_297D:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2991h

l0800_2986:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	2997h

l0800_2991:
	call	0103h
	jmp	2B41h

l0800_2997:
	cmp	byte ptr [bp+0FE7Fh],0FFh
	jnc	29B1h

l0800_299E:
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[53D2h],al
	inc	byte ptr [bp+0FE7Fh]

l0800_29B1:
	mov	al,[53D2h]
	cmp	al,3Bh
	jnz	29D9h

l0800_29B8:
	push	0Eh
	call	09C2h
	cmp	byte ptr [53DBh],0h
	jbe	29D1h

l0800_29C4:
	call	far 0C74h:522Ch
	or	al,al
	jz	29D1h

l0800_29CD:
	dec	byte ptr [53DBh]

l0800_29D1:
	push	5h
	call	09C2h
	jmp	2ADEh

l0800_29D9:
	cmp	al,3Ch
	jnz	2A11h

l0800_29DD:
	push	0Fh
	call	09C2h
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[58BDh],al
	inc	byte ptr [bp+0FE7Fh]
	cmp	byte ptr [53DCh],0h
	jbe	2A09h

l0800_29FC:
	call	far 0C74h:542Bh
	or	al,al
	jz	2A09h

l0800_2A05:
	dec	byte ptr [53DCh]

l0800_2A09:
	push	6h
	call	09C2h
	jmp	2ADEh

l0800_2A11:
	cmp	al,3Dh
	jnz	2A36h

l0800_2A15:
	push	10h
	call	09C2h
	cmp	byte ptr [53DEh],0h
	jbe	2A2Eh

l0800_2A21:
	call	far 0C74h:5258h
	or	al,al
	jz	2A2Eh

l0800_2A2A:
	dec	byte ptr [53DEh]

l0800_2A2E:
	push	7h
	call	09C2h
	jmp	2ADEh

l0800_2A36:
	cmp	al,1Bh
	jnz	2A43h

l0800_2A3A:
	call	0103h
	jmp	2B41h
0800:2A40 E9 9B 00                                        ...             

l0800_2A43:
	cmp	al,48h
	jnz	2A59h

l0800_2A47:
	push	9h
	call	09C2h
	call	far 0C74h:51AAh
	push	0h
	call	09C2h
	jmp	2ADEh

l0800_2A59:
	cmp	al,4Bh
	jnz	2A92h

l0800_2A5D:
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
	jnz	2A8Bh

l0800_2A7E:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_2A8B:
	push	1h
	call	09C2h
	jmp	2ADEh

l0800_2A92:
	cmp	al,4Dh
	jnz	2ACBh

l0800_2A96:
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
	jnz	2AC4h

l0800_2AB7:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_2AC4:
	push	3h
	call	09C2h
	jmp	2ADEh

l0800_2ACB:
	cmp	al,50h
	jnz	2ADEh

l0800_2ACF:
	push	0Dh
	call	09C2h
	call	far 0C74h:51B2h
	push	4h
	call	09C2h

l0800_2ADE:
	call	0C71h
	call	0877h
	or	al,al
	jnz	2AF2h

l0800_2AE8:
	cmp	byte ptr [58B3h],0h
	jnz	2AF2h

l0800_2AEF:
	jmp	297Dh

l0800_2AF2:
	call	0103h
	call	0877h
	or	al,al
	jz	2B39h

l0800_2AFC:
	add	word ptr [598Eh],1h
	adc	word ptr [5990h],0h
	mov	al,[0002h]
	xor	ah,ah
	xor	dx,dx
	cmp	dx,[5990h]
	jnz	2B1Eh

l0800_2B13:
	cmp	ax,[598Eh]
	jnz	2B1Eh

l0800_2B19:
	call	166Dh
	jmp	2B41h

l0800_2B1E:
	cmp	word ptr [5990h],0h
	jnz	2B39h

l0800_2B25:
	cmp	word ptr [598Eh],0FAh
	jnz	2B39h

l0800_2B2D:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h

l0800_2B39:
	call	far 1206h:0066h
	jmp	282Bh

l0800_2B41:
	leave
	ret
0800:2B43          06 4E 4F 4E 41 4D 45 04 44 45 4D 4F 07    .NONAME.DEMO.
0800:2B50 52 41 44 2E 4D 45 4D 2A 49 6D 70 6F 73 73 69 62 RAD.MEM*Impossib
0800:2B60 6C 65 20 64 27 61 63 63 82 64 65 72 20 85 20 52 le d'acc.der . R
0800:2B70 61 64 2E 6D 65 6D 20 65 6E 20 82 63 72 69 74 75 ad.mem en .critu
0800:2B80 72 65 2C 76 82 72 69 66 69 65 7A 20 71 75 65 20 re,v.rifiez que 
0800:2B90 6C 61 20 64 69 73 71 75 65 74 74 65 20 6E 27 65 la disquette n'e
0800:2BA0 73 74 20 70 61 73 20 70 72 6F 74 82 67 82 65 2A st pas prot.g.e*
0800:2BB0 6F 75 20 74 72 61 6E 73 66 82 72 65 7A 20 6C 65 ou transf.rez le
0800:2BC0 20 70 72 6F 67 72 61 6D 6D 65 20 73 75 72 20 64  programme sur d
0800:2BD0 69 73 71 75 65 20 64 75 72 2E 12 50 52 45 53 53 isque dur..PRESS
0800:2BE0 45 5A 20 55 4E 45 20 54 4F 55 43 48 45 1E 44 45 EZ UNE TOUCHE.DE
0800:2BF0 4D 4F 3A 50 72 65 73 73 65 7A 20 45 73 63 61 70 MO:Pressez Escap
0800:2C00 65 20 70 6F 75 72 20 66 69 6E 69 72             e pour finir
