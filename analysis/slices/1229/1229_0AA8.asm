;; fn1229_0AA8: 1229:0AA8
;;   Called from:
;;     1229:0CF7 (in fn1229_0CCE)
;;     1229:0FC3 (in fn1229_0DCC)
;;     1229:1027 (in fn1229_0DCC)
fn1229_0AA8 proc
	enter	602h,0h
	push	1h
	push	1h
	push	27Eh
	push	176h
	push	1h
	call	far 1AB8h:0F93h
	call	far 1AB8h:1028h
	push	0h
	push	0h
	push	27Fh
	push	1DFh
	push	1h
	call	far 1AB8h:0F93h
	mov	byte ptr [bp-2h],0h
	jmp	0ADCh

l1229_0AD9:
	inc	byte ptr [bp-2h]

l1229_0ADC:
	mov	byte ptr [bp-1h],0h
	jmp	0AE5h

l1229_0AE2:
	inc	byte ptr [bp-1h]

l1229_0AE5:
	mov	al,[bp-1h]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-2h]
	xor	ah,ah
	imul	di,ax,1Dh
	add	di,dx
	cmp	byte ptr [di+5CE0h],0h
	jz	0B3Ah

l1229_0AFD:
	mov	al,[bp-1h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp-1h]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-2h]
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

l1229_0B3A:
	cmp	byte ptr [bp-1h],1Ch
	jnz	0AE2h

l1229_0B40:
	cmp	byte ptr [bp-2h],10h
	jnz	0AD9h

l1229_0B46:
	push	word ptr [50C4h]
	push	178h
	push	27Eh
	push	182h
	push	1h
	call	far 1AB8h:0F93h
	call	far 1AB8h:1028h
	push	0h
	push	0h
	push	27Fh
	push	1DFh
	push	1h
	call	far 1AB8h:0F93h
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	push	2h
	push	0h
	push	4h
	call	far 1AB8h:1536h
	lea	di,[bp+0FDFEh]
	push	ss
	push	di
	mov	al,[598Eh]
	push	ax
	call	09F9h
	mov	di,0A8Bh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,0A8Bh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,0A8Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FCFEh]
	push	ss
	push	di
	mov	al,[5CDCh]
	push	ax
	call	09F9h
	call	far 1EDAh:0AACh
	mov	di,0A93h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FBFEh]
	push	ss
	push	di
	mov	al,[5CDAh]
	push	ax
	call	09F9h
	call	far 1EDAh:0AACh
	mov	di,0A9Ah
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FAFEh]
	push	ss
	push	di
	mov	al,[5CDDh]
	push	ax
	call	09F9h
	call	far 1EDAh:0AACh
	mov	di,0AA1h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0F9FEh]
	push	ss
	push	di
	mov	al,[5CDBh]
	push	ax
	call	09F9h
	call	far 1EDAh:0AACh
	mov	di,0A8Bh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	mov	ax,[50C4h]
	add	ax,16h
	push	ax
	push	17Dh
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	leave
	ret
