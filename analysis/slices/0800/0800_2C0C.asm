;; fn0800_2C0C: 0800:2C0C
;;   Called from:
;;     0800:3F26 (in fn0800_3D9D)
;;     0800:400E (in fn0800_3D9D)
fn0800_2C0C proc
	enter	102h,0h

l0800_2C10:
	call	far 1E78h:02FBh
	or	al,al
	jz	2C20h

l0800_2C19:
	call	far 1E78h:030Dh
	jmp	2C10h

l0800_2C20:
	call	far 1206h:0066h
	call	far 13E2h:003Bh
	call	01FEh
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B43h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	2C4Dh

l0800_2C3E:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	jmp	3110h

l0800_2C4D:
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	2C61h

l0800_2C5E:
	jmp	2D2Bh

l0800_2C61:
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	di,2B4Fh
	push	cs
	push	di
	call	far 1EDAh:04F5h
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	call	far 1EDAh:056Ah
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	di,5ECEh
	push	ds
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	call	far 1EDAh:05BFh
	call	far 1EDAh:04A2h
	or	ax,ax
	jnz	2CAAh

l0800_2CA7:
	jmp	2D2Bh

l0800_2CAA:
	push	word ptr [0B8ACh]
	call	far 1E78h:016Bh
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,2B57h
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	call	far 1EDAh:04A9h
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,2B82h
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	call	far 1EDAh:04A9h
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,2BAFh
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	call	far 1EDAh:04A9h
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,2BDAh
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	call	far 1EDAh:04A9h
	call	far 1E78h:030Dh
	xor	ax,ax
	call	far 1EDAh:00E9h

l0800_2D2B:
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
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	2D77h

l0800_2D65:
	push	93h
	push	189h
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	jmp	2D87h

l0800_2D77:
	push	93h
	push	189h
	mov	di,2BEDh
	push	cs
	push	di
	call	far 1AB8h:1D82h

l0800_2D87:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	2DB1h

l0800_2D9F:
	push	94h
	push	18Ah
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	jmp	2DC1h

l0800_2DB1:
	push	94h
	push	18Ah
	mov	di,2BEDh
	push	cs
	push	di
	call	far 1AB8h:1D82h

l0800_2DC1:
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
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	2E37h

l0800_2E19:
	push	0Bh
	call	09C2h

l0800_2E1E:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2E32h

l0800_2E27:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	2E1Eh

l0800_2E32:
	push	2h
	call	09C2h

l0800_2E37:
	mov	al,[53DDh]
	xor	ah,ah
	imul	ax,ax,3Ch
	cwd
	push	dx
	push	ax
	call	00C1h
	mov	byte ptr [bp-1h],1h

l0800_2E49:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2E71h

l0800_2E52:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jnz	2E71h

l0800_2E5D:
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	2E71h

l0800_2E6E:
	jmp	3087h

l0800_2E71:
	call	far 1E78h:02FBh
	or	al,al
	jz	2EA3h

l0800_2E7A:
	call	far 1E78h:030Dh
	mov	[53D2h],al
	cmp	byte ptr [53D2h],0h
	jnz	2E91h

l0800_2E89:
	call	far 1E78h:030Dh
	mov	[53D2h],al

l0800_2E91:
	call	far 1E78h:02FBh
	or	al,al
	jz	2EA1h

l0800_2E9A:
	call	far 1E78h:030Dh
	jmp	2E91h

l0800_2EA1:
	jmp	2EA9h

l0800_2EA3:
	call	031Bh
	mov	[53D2h],al

l0800_2EA9:
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	2ED2h

l0800_2EBA:
	cmp	byte ptr [53D2h],1Bh
	jz	2ECFh

l0800_2EC1:
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+5CBBh]
	mov	[53D2h],al

l0800_2ECF:
	inc	byte ptr [bp-1h]

l0800_2ED2:
	mov	al,[53D2h]
	cmp	al,3Bh
	jnz	2EFAh

l0800_2ED9:
	push	0Eh
	call	09C2h
	cmp	byte ptr [53DBh],0h
	jbe	2EF2h

l0800_2EE5:
	call	far 0C74h:522Ch
	or	al,al
	jz	2EF2h

l0800_2EEE:
	dec	byte ptr [53DBh]

l0800_2EF2:
	push	5h
	call	09C2h
	jmp	3087h

l0800_2EFA:
	cmp	al,3Ch
	jnz	2F1Fh

l0800_2EFE:
	push	0Fh
	call	09C2h
	cmp	byte ptr [53DCh],0h
	jbe	2F17h

l0800_2F0A:
	call	far 0C74h:542Bh
	or	al,al
	jz	2F17h

l0800_2F13:
	dec	byte ptr [53DCh]

l0800_2F17:
	push	6h
	call	09C2h
	jmp	3087h

l0800_2F1F:
	cmp	al,3Dh
	jnz	2F44h

l0800_2F23:
	push	10h
	call	09C2h
	cmp	byte ptr [53DEh],0h
	jbe	2F3Ch

l0800_2F2F:
	call	far 0C74h:5258h
	or	al,al
	jz	2F3Ch

l0800_2F38:
	dec	byte ptr [53DEh]

l0800_2F3C:
	push	7h
	call	09C2h
	jmp	3087h

l0800_2F44:
	cmp	al,3Fh
	jz	2F4Ch

l0800_2F48:
	cmp	al,2Ch
	jnz	2FACh

l0800_2F4C:
	mov	byte ptr [58B2h],0h
	call	2401h
	mov	byte ptr [58B2h],1h
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
	jmp	3087h

l0800_2FAC:
	cmp	al,1Bh
	jnz	2FB9h

l0800_2FB0:
	call	0103h
	jmp	3110h
0800:2FB6                   E9 CE 00                            ...       

l0800_2FB9:
	cmp	al,20h
	jnz	2FFAh

l0800_2FBD:
	mov	ax,[58D8h]
	mov	dx,[58DAh]
	mov	[58D0h],ax
	mov	[58D2h],dx
	call	0103h
	push	0Bh
	call	09C2h

l0800_2FD3:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2FE7h

l0800_2FDC:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	2FD3h

l0800_2FE7:
	push	2h
	call	09C2h
	push	word ptr [58D2h]
	push	word ptr [58D0h]
	call	00C1h
	jmp	3087h

l0800_2FFA:
	cmp	al,44h
	jnz	3013h

l0800_2FFE:
	cmp	byte ptr [58B0h],0h
	jz	300Ch

l0800_3005:
	mov	byte ptr [58B0h],0h
	jmp	3011h

l0800_300C:
	mov	byte ptr [58B0h],1h

l0800_3011:
	jmp	3087h

l0800_3013:
	cmp	al,48h
	jnz	3028h

l0800_3017:
	push	9h
	call	09C2h
	call	far 0C74h:51AAh
	push	0h
	call	09C2h
	jmp	3087h

l0800_3028:
	cmp	al,4Bh
	jnz	304Eh

l0800_302C:
	push	0Ah
	call	09C2h
	call	far 0C74h:54F0h
	or	al,al
	jnz	3047h

l0800_303A:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_3047:
	push	1h
	call	09C2h
	jmp	3087h

l0800_304E:
	cmp	al,4Dh
	jnz	3074h

l0800_3052:
	push	0Ch
	call	09C2h
	call	far 0C74h:54B1h
	or	al,al
	jnz	306Dh

l0800_3060:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_306D:
	push	3h
	call	09C2h
	jmp	3087h

l0800_3074:
	cmp	al,50h
	jnz	3087h

l0800_3078:
	push	0Dh
	call	09C2h
	call	far 0C74h:51B2h
	push	4h
	call	09C2h

l0800_3087:
	call	0C71h
	call	0877h
	or	al,al
	jnz	309Bh

l0800_3091:
	cmp	byte ptr [58B3h],0h
	jnz	309Bh

l0800_3098:
	jmp	2E49h

l0800_309B:
	call	0103h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	30B1h

l0800_30AF:
	jmp	3110h

l0800_30B1:
	call	0877h
	or	al,al
	jz	3108h

l0800_30B8:
	call	0768h

l0800_30BB:
	call	far 1E78h:02FBh
	or	al,al
	jz	30CBh

l0800_30C4:
	call	far 1E78h:030Dh
	jmp	30BBh

l0800_30CB:
	add	word ptr [598Eh],1h
	adc	word ptr [5990h],0h
	mov	al,[0002h]
	xor	ah,ah
	xor	dx,dx
	cmp	dx,[5990h]
	jnz	30EDh

l0800_30E2:
	cmp	ax,[598Eh]
	jnz	30EDh

l0800_30E8:
	call	166Dh
	jmp	3110h

l0800_30ED:
	cmp	word ptr [5990h],0h
	jnz	3108h

l0800_30F4:
	cmp	word ptr [598Eh],0FAh
	jnz	3108h

l0800_30FC:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h

l0800_3108:
	call	far 1206h:0066h
	jmp	2C20h

l0800_3110:
	leave
	ret
0800:3112       40 20 20 20 20 20 20 20 20 20 20 20 20 20   @             
0800:3120 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20                 
0800:3130 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20                 
0800:3140 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20                 
0800:3150 20 20 20 07 46 4C 45 43 48 45 53 06 45 53 50 41    .FLECHES.ESPA
0800:3160 43 45 02 46 31 02 46 32 02 46 33 03 45 53 43 00 CE.F1.F2.F3.ESC.
0800:3170 00 00 00 00 00 00 38 00 29 01 00 00 00 00 00 00 ......8.).......
0800:3180 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:3190 00 00 00 00 00 00 10 00 28 00 00 00 00 00 00 00 ........(.......
0800:31A0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 07 ................
0800:31B0 52 41 44 2E 48 4C 50                            RAD.HLP
