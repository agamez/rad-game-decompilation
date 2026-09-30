;; fn1229_0DCC: 1229:0DCC
;;   Called from:
;;     0800:40DE (in fn0800_3D9D)
fn1229_0DCC proc
	enter	102h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	call	far 1AB8h:0F80h
	push	0Fh
	push	3Fh
	push	3Fh
	push	3Fh
	call	far 1AB8h:1CBAh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,6BBAh
	push	ds
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	mov	byte ptr [62DBh],0h
	mov	byte ptr [62CBh],1h
	mov	byte ptr [6CBAh],0h
	push	1h
	call	far 13C8h:0111h
	call	039Dh
	call	0CCEh
	call	far 133Fh:0141h
	mov	byte ptr [bp+0FEFFh],0h

l1229_0E2E:
	mov	di,62CEh
	push	ds
	push	di
	mov	di,62D0h
	push	ds
	push	di
	mov	di,62D2h
	push	ds
	push	di
	mov	al,[50C7h]
	push	ax
	call	far 133Fh:0528h
	or	al,al
	jnz	0E4Dh

l1229_0E4A:
	jmp	10EFh

l1229_0E4D:
	cmp	word ptr [62CEh],1h
	jnz	0EA2h

l1229_0E54:
	cmp	word ptr [62D0h],59h
	jle	0EA2h

l1229_0E5B:
	cmp	word ptr [62D2h],187h
	jle	0EA2h

l1229_0E63:
	push	0F0h
	call	far 1E78h:02C7h
	push	64h
	call	far 1E78h:029Ch
	mov	ax,[62D2h]
	sub	ax,187h
	cwd
	mov	cx,16h
	idiv	cx
	imul	ax,ax,19h
	mov	bx,ax
	mov	ax,[62D0h]
	sub	ax,59h
	cwd
	mov	cx,16h
	idiv	cx
	add	ax,bx
	mov	dx,ax
	mov	al,[6CBAh]
	xor	ah,ah
	add	ax,dx
	mov	[62CBh],al
	call	far 1E78h:02F4h

l1229_0EA2:
	cmp	word ptr [62CEh],1h
	jnz	0F19h

l1229_0EA9:
	cmp	word ptr [62D2h],177h
	jge	0F19h

l1229_0EB1:
	call	far 133Fh:0137h
	mov	al,[62CBh]
	push	ax
	mov	ax,[62D0h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	mov	bx,ax
	mov	ax,[62D2h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	di,ax,1Dh
	add	di,bx
	pop	ax
	mov	[di+5CE0h],al
	mov	ax,[62D0h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	ax,[62D2h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[62CBh]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5992h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	byte ptr [bp+0FEFFh],1h
	call	far 133Fh:0141h

l1229_0F19:
	cmp	word ptr [62CEh],2h
	jnz	0F82h

l1229_0F20:
	cmp	word ptr [62D2h],177h
	jge	0F82h

l1229_0F28:
	call	far 133Fh:0137h
	mov	ax,[62D0h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	mov	bx,ax
	mov	ax,[62D2h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	di,ax,1Dh
	add	di,bx
	mov	byte ptr [di+5CE0h],0h
	mov	ax,[62D0h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	ax,[62D2h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	ax,ax,16h
	inc	ax
	push	ax
	les	di,[5992h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	byte ptr [bp+0FEFFh],1h
	call	far 133Fh:0141h

l1229_0F82:
	mov	ax,[62CEh]
	cmp	ax,2Bh
	jnz	0FEAh

l1229_0F8A:
	cmp	word ptr [5990h],0h
	jl	0F9Bh

l1229_0F91:
	jg	0FE7h

l1229_0F93:
	cmp	word ptr [598Eh],0FAh
	jnc	0FE7h

l1229_0F9B:
	call	far 133Fh:0137h
	cmp	byte ptr [bp+0FEFFh],0h
	jz	0FB1h

l1229_0FA7:
	call	061Bh
	or	al,al
	jz	0FB1h

l1229_0FAE:
	call	0735h

l1229_0FB1:
	add	word ptr [598Eh],1h
	adc	word ptr [5990h],0h
	call	0486h
	mov	byte ptr [bp+0FEFFh],0h
	call	0AA8h
	call	far 133Fh:0141h

l1229_0FCB:
	mov	di,62CEh
	push	ds
	push	di
	mov	di,62D0h
	push	ds
	push	di
	mov	di,62D2h
	push	ds
	push	di
	mov	al,[50C7h]
	push	ax
	call	far 133Fh:0528h
	or	al,al
	jnz	0FCBh

l1229_0FE7:
	jmp	10EFh

l1229_0FEA:
	cmp	ax,2Dh
	jnz	104Eh

l1229_0FEF:
	cmp	word ptr [5990h],0h
	jg	0FFFh

l1229_0FF6:
	jl	104Bh

l1229_0FF8:
	cmp	word ptr [598Eh],1h
	jbe	104Bh

l1229_0FFF:
	call	far 133Fh:0137h
	cmp	byte ptr [bp+0FEFFh],0h
	jz	1015h

l1229_100B:
	call	061Bh
	or	al,al
	jz	1015h

l1229_1012:
	call	0735h

l1229_1015:
	sub	word ptr [598Eh],1h
	sbb	word ptr [5990h],0h
	call	0486h
	mov	byte ptr [bp+0FEFFh],0h
	call	0AA8h
	call	far 133Fh:0141h

l1229_102F:
	mov	di,62CEh
	push	ds
	push	di
	mov	di,62D0h
	push	ds
	push	di
	mov	di,62D2h
	push	ds
	push	di
	mov	al,[50C7h]
	push	ax
	call	far 133Fh:0528h
	or	al,al
	jnz	102Fh

l1229_104B:
	jmp	10EFh

l1229_104E:
	cmp	ax,51h
	jnz	108Ch

l1229_1053:
	mov	byte ptr [62DBh],1h
	mov	byte ptr [5CB3h],1h
	cmp	byte ptr [bp+0FEFFh],0h
	jz	106Eh

l1229_1064:
	call	061Bh
	or	al,al
	jz	106Eh

l1229_106B:
	call	0735h

l1229_106E:
	mov	di,62CEh
	push	ds
	push	di
	mov	di,62D0h
	push	ds
	push	di
	mov	di,62D2h
	push	ds
	push	di
	mov	al,[50C7h]
	push	ax
	call	far 133Fh:0528h
	or	al,al
	jnz	106Eh

l1229_108A:
	jmp	10EFh

l1229_108C:
	cmp	ax,54h
	jnz	10AEh

l1229_1091:
	mov	byte ptr [5CB3h],0h
	mov	byte ptr [62DBh],1h
	cmp	byte ptr [bp+0FEFFh],0h
	jz	10ACh

l1229_10A2:
	call	061Bh
	or	al,al
	jz	10ACh

l1229_10A9:
	call	0735h

l1229_10AC:
	jmp	10EFh

l1229_10AE:
	cmp	ax,53h
	jnz	10EFh

l1229_10B3:
	cmp	byte ptr [6CBAh],64h
	jnz	10C1h

l1229_10BA:
	mov	byte ptr [6CBAh],0h
	jmp	10C6h

l1229_10C1:
	mov	byte ptr [6CBAh],64h

l1229_10C6:
	call	far 133Fh:0137h
	call	0C58h
	call	far 133Fh:0141h

l1229_10D3:
	mov	di,62CEh
	push	ds
	push	di
	mov	di,62D0h
	push	ds
	push	di
	mov	di,62D2h
	push	ds
	push	di
	mov	al,[50C7h]
	push	ax
	call	far 133Fh:0528h
	or	al,al
	jnz	10D3h

l1229_10EF:
	cmp	byte ptr [62DBh],0h
	jnz	10F9h

l1229_10F6:
	jmp	0E2Eh

l1229_10F9:
	call	far 133Fh:04A7h
	call	far 133Fh:0137h
	cmp	byte ptr [5CB3h],0h
	jz	1150h

l1229_110A:
	call	far 1AB8h:0F80h
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,0DC5h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	112Eh

l1229_1120:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	jmp	1150h

l1229_112E:
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,5ED6h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	mov	di,5ED6h
	push	ds
	push	di
	mov	di,5ECEh
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h

l1229_1150:
	leave
	retf	4h
1229:1154             00 00 00 00 00 00 00 00 00 00 00 00     ............
