;; fn1AB8_0BAE: 1AB8:0BAE
;;   Called from:
;;     133F:006E (in fn133F_0056)
;;     13E2:0019 (in fn13E2_0001)
fn1AB8_0BAE proc
	push	bp
	mov	bp,sp
	sub	sp,208h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	mov	ax,2073h
	mov	dx,1AB8h
	mov	[0B820h],ax
	mov	[0B822h],dx
	push	word ptr [0B822h]
	push	word ptr [0B820h]
	les	di,[0B820h]
	push	es
	push	di
	les	di,[0B820h]
	add	di,2h
	push	es
	push	di
	call	0569h
	mov	[0B820h],ax
	mov	[0B822h],dx
	mov	byte ptr [bp+0FEF9h],0h
	les	di,[bp+0Eh]
	cmp	word ptr es:[di],0h
	jz	0C09h

l1AB8_0C06:
	jmp	0C86h

l1AB8_0C09:
	xor	ax,ax
	mov	[bp+0FEFCh],ax
	mov	word ptr [bp+0FEFAh],0FFFFh

l1AB8_0C15:
	mov	ax,[bp+0FEFCh]
	cmp	ax,[0B7B8h]
	jge	0C86h

l1AB8_0C1F:
	cmp	word ptr [bp+0FEFAh],0h
	jge	0C86h

l1AB8_0C26:
	mov	ax,1Ah
	mul	word ptr [bp+0FEFCh]
	mov	di,ax
	mov	ax,[di+510Eh]
	or	ax,[di+5110h]
	jz	0C80h

l1AB8_0C39:
	mov	ax,1Ah
	mul	word ptr [bp+0FEFCh]
	mov	di,ax
	mov	ax,[di+510Eh]
	mov	dx,[di+5110h]
	mov	[0B896h],ax
	mov	[0B898h],dx
	call	dword ptr [0B896h]
	mov	[bp+0FEFAh],ax
	cmp	word ptr [bp+0FEFAh],0h
	jl	0C80h

l1AB8_0C60:
	mov	ax,[bp+0FEFCh]
	mov	[0B814h],ax
	mov	ax,[bp+0FEFCh]
	les	di,[bp+0Eh]
	mov	es:[di],ax
	mov	ax,[bp+0FEFAh]
	les	di,[bp+0Ah]
	mov	es:[di],ax
	mov	byte ptr [bp+0FEF9h],1h

l1AB8_0C80:
	inc	word ptr [bp+0FEFCh]
	jmp	0C15h

l1AB8_0C86:
	cmp	byte ptr [bp+0FEF9h],0h
	jnz	0CA2h

l1AB8_0C8D:
	mov	di,0B814h
	push	ds
	push	di
	les	di,[bp+0Eh]
	push	es
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	push	cs
	call	19EEh
	jmp	0CCBh

l1AB8_0CA2:
	mov	ax,[0B814h]
	mov	[bp+0FEFCh],ax
	les	di,[bp+0Eh]
	mov	ax,es:[di]
	add	ax,80h
	mov	[bp+0FEFAh],ax
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	push	cs
	call	19EEh

l1AB8_0CCB:
	les	di,[bp+0Eh]
	cmp	word ptr es:[di],0h
	jge	0CE8h

l1AB8_0CD4:
	mov	word ptr [0B818h],0FFFEh
	les	di,[bp+0Eh]
	mov	word ptr es:[di],0FFFEh
	call	0813h
	jmp	0E82h

l1AB8_0CE8:
	les	di,[bp+0Ah]
	mov	ax,es:[di]
	mov	[0B816h],ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,0B764h
	push	ds
	push	di
	mov	ax,50h
	push	ax
	call	far 1EDAh:0A39h
	cmp	byte ptr [0B764h],0h
	jz	0D52h

l1AB8_0D0C:
	mov	al,[0B764h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+0B764h]
	mov	[bp+0FEFFh],al
	cmp	byte ptr [bp+0FEFFh],3Ah
	jz	0D52h

l1AB8_0D22:
	cmp	byte ptr [bp+0FEFFh],5Ch
	jz	0D52h

l1AB8_0D29:
	lea	di,[bp+0FDF8h]
	push	ss
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,0BACh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,0B764h
	push	ds
	push	di
	mov	ax,50h
	push	ax
	call	far 1EDAh:0A39h

l1AB8_0D52:
	push	word ptr [0B814h]
	mov	di,0B764h
	push	ds
	push	di
	call	097Bh
	or	al,al
	jnz	0D71h

l1AB8_0D62:
	mov	ax,[0B818h]
	les	di,[bp+0Eh]
	mov	es:[di],ax
	call	0813h
	jmp	0E82h

l1AB8_0D71:
	mov	di,0B7D4h
	push	ds
	push	di
	mov	ax,3Fh
	push	ax
	mov	al,0h
	push	ax
	call	far 1EDAh:1202h
	mov	ax,[536Eh]
	mov	dx,[5370h]
	mov	[0B7BCh],ax
	mov	[0B7BEh],dx
	mov	ax,50Bh
	mov	dx,1AB8h
	mov	[536Eh],ax
	mov	[5370h],dx
	mov	di,0B7E0h
	push	ds
	push	di
	push	word ptr [0B7B6h]
	call	dword ptr [0B6C2h]
	mov	ax,[0B7BCh]
	mov	dx,[0B7BEh]
	mov	[536Eh],ax
	mov	[5370h],dx
	mov	ax,[0B7E0h]
	or	ax,[0B7E2h]
	jnz	0DE2h

l1AB8_0DC1:
	mov	word ptr [0B818h],0FFFBh
	les	di,[bp+0Eh]
	mov	word ptr es:[di],0FFFBh
	mov	di,0B828h
	push	ds
	push	di
	push	word ptr [0B82Ch]
	call	dword ptr [0B6C6h]
	call	0813h
	jmp	0E82h

l1AB8_0DE2:
	mov	byte ptr [0B7D5h],0h
	mov	byte ptr [0B7EAh],0h
	mov	ax,[0B7E0h]
	mov	dx,[0B7E2h]
	mov	[0B82Eh],ax
	mov	[0B830h],dx
	mov	ax,[0B7B6h]
	mov	[0B7E4h],ax
	mov	ax,[0B7E0h]
	mov	dx,[0B7E2h]
	mov	[0B7FAh],ax
	mov	[0B7FCh],dx
	mov	ax,[0B7B6h]
	mov	[0B7FEh],ax
	mov	ax,0B818h
	mov	dx,ds
	mov	[0B7EEh],ax
	mov	[0B7F0h],dx
	mov	di,0B7D4h
	push	ds
	push	di
	push	cs
	call	1855h
	mov	ax,[0B83Ah]
	mov	dx,[0B83Ch]
	mov	di,ax
	mov	es,dx
	push	es
	push	di
	mov	di,0B7C0h
	push	ds
	push	di
	mov	ax,13h
	push	ax
	call	far 1EDAh:11DFh
	mov	di,0B7D4h
	push	ds
	push	di
	push	cs
	call	1AA6h
	cmp	byte ptr [0B7C0h],0h
	jz	0E61h

l1AB8_0E54:
	mov	al,[0B7C0h]
	xor	ah,ah
	mov	[0B818h],ax
	call	0813h
	jmp	0E82h

l1AB8_0E61:
	push	cs
	call	1C93h
	mov	[0B848h],ax
	mov	ax,[0B7CEh]
	mov	[0B84Ah],ax
	mov	word ptr [0B84Ch],2710h
	mov	byte ptr [0B84Eh],1h
	push	cs
	call	0AEEh
	xor	ax,ax
	mov	[0B818h],ax

l1AB8_0E82:
	mov	sp,bp
	pop	bp
	retf	0Ch
