;; fn0800_2004: 0800:2004
;;   Called from:
;;     0800:40F8 (in fn0800_3D9D)
fn0800_2004 proc
	enter	0Ah,0h
	mov	byte ptr [53D8h],0h
	mov	word ptr [bp-2h],9Ch
	mov	word ptr [bp-6h],14h
	mov	word ptr [bp-4h],1E0h
	mov	word ptr [bp-8h],16Ah
	push	word ptr [bp-2h]
	push	word ptr [bp-6h]
	push	word ptr [bp-4h]
	push	word ptr [bp-8h]
	call	1315h
	mov	ax,[bp-2h]
	add	ax,8h
	mov	[bp-2h],ax
	mov	ax,[bp-6h]
	add	ax,0Ch
	mov	[bp-6h],ax
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	mov	byte ptr [bp-9h],1h
	jmp	205Fh

l0800_205C:
	inc	byte ptr [bp-9h]

l0800_205F:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	sub	ax,[bp-2h]
	shr	ax,1h
	add	ax,[bp-2h]
	dec	ax
	push	ax
	mov	al,[bp-9h]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	dec	ax
	push	ax
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,3706h
	push	ds
	push	di
	call	far 1AB8h:1D82h
	mov	al,[bp-9h]
	push	ax
	mov	di,1FB5h
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	20AEh

l0800_20A5:
	push	0Ah
	call	far 1AB8h:1C32h
	jmp	20B5h

l0800_20AE:
	push	0Bh
	call	far 1AB8h:1C32h

l0800_20B5:
	mov	ax,[bp-4h]
	sub	ax,[bp-2h]
	shr	ax,1h
	add	ax,[bp-2h]
	push	ax
	mov	al,[bp-9h]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	push	ax
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,3706h
	push	ds
	push	di
	call	far 1AB8h:1D82h
	cmp	byte ptr [bp-9h],15h
	jz	20EBh

l0800_20E8:
	jmp	205Ch

l0800_20EB:
	push	5h
	push	140h
	push	14Ah
	mov	di,1FD5h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_20FD:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2111h

l0800_2106:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	20FDh

l0800_2111:
	call	far 1E78h:02FBh
	or	al,al
	jz	2131h

l0800_211A:
	call	far 1E78h:030Dh
	push	ax
	mov	di,1FE4h
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	2131h

l0800_212C:
	mov	byte ptr [53D8h],1h

l0800_2131:
	push	5h
	push	140h
	push	14Ah
	mov	di,1FD5h
	push	cs
	push	di
	push	1h
	call	19E1h
	call	far 1206h:0066h
	push	96h
	call	far 1E78h:029Ch
	call	1E3Fh
	leave
	ret
0800:2155                03 52 41 44 16 56 65 72 73 69 6F      .RAD.Versio
0800:2160 6E 20 65 6E 72 65 67 69 73 74 72 82 65 20 3A 20 n enregistr.e : 
0800:2170 09 20 74 61 62 6C 65 61 75 78 03 46 31 3A 01 20 . tableaux.F1:. 
0800:2180 0B 20 20 46 31 3A 4A 45 55 20 20 20 0A 46 32 3A .  F1:JEU   .F2:
0800:2190 4D 49 53 53 49 4F 4E 0A 20 20 46 33 3A 44 45 4D MISSION.  F3:DEM
0800:21A0 4F 20 0A 46 34 3A 53 49 4C 45 4E 43 45 0B 20 20 O .F4:SILENCE.  
0800:21B0 46 35 3A 45 44 49 54 20 20 0B 20 20 46 35 3A 49 F5:EDIT  .  F5:I
0800:21C0 4E 46 4F 20 20 0A 46 36 3A 4E 4F 54 49 43 45 20 NFO  .F6:NOTICE 
0800:21D0 16 20 20 20 46 37 3A 52 45 54 4F 55 52 20 41 55 .   F7:RETOUR AU
0800:21E0 20 44 4F 53 20 20 20                             DOS
