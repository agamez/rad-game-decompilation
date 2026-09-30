;; fn0800_01FE: 0800:01FE
;;   Called from:
;;     0800:2856 (in fn0800_2827)
;;     0800:2C2A (in fn0800_2C0C)
fn0800_01FE proc
	enter	84h,0h
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,1F6h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp-80h]
	push	ss
	push	di
	push	219h
	call	far 1EDAh:0FD0h
	lea	di,[bp-80h]
	push	ss
	push	di
	push	word ptr [5990h]
	push	word ptr [598Eh]
	call	far 1EDAh:1123h
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:1085h
	add	sp,4h
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,5ECEh
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	mov	al,[5CDEh]
	mov	[53D9h],al
	mov	al,[5CDFh]
	mov	[53DAh],al
	mov	al,[5CDAh]
	mov	[53DBh],al
	mov	al,[5CDBh]
	mov	[53DCh],al
	cmp	byte ptr [5CDCh],0Ah
	jbe	0281h

l0800_027C:
	mov	byte ptr [5CDCh],0Ah

l0800_0281:
	mov	al,[5CDCh]
	mov	[53DDh],al
	mov	al,[5CDDh]
	mov	[53DEh],al
	push	1h
	push	1h
	push	27Eh
	push	176h
	call	0024h
	mov	byte ptr [bp+0FF7Eh],0h
	jmp	02A5h

l0800_02A1:
	inc	byte ptr [bp+0FF7Eh]

l0800_02A5:
	mov	byte ptr [bp+0FF7Fh],0h
	jmp	02B0h

l0800_02AC:
	inc	byte ptr [bp+0FF7Fh]

l0800_02B0:
	mov	al,[bp+0FF7Fh]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp+0FF7Eh]
	xor	ah,ah
	imul	di,ax,1Dh
	add	di,dx
	cmp	byte ptr [di+5CE0h],0h
	jz	030Bh

l0800_02CA:
	mov	al,[bp+0FF7Fh]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp+0FF7Eh]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp+0FF7Fh]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp+0FF7Eh]
	xor	ah,ah
	imul	di,ax,1Dh
	add	di,dx
	mov	al,[di+5CE0h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5992h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h

l0800_030B:
	cmp	byte ptr [bp+0FF7Fh],1Ch
	jnz	02ACh

l0800_0312:
	cmp	byte ptr [bp+0FF7Eh],10h
	jnz	02A1h

l0800_0319:
	leave
	ret
