;; fn133F_0528: 133F:0528
;;   Called from:
;;     1229:0E41 (in fn1229_0DCC)
;;     1229:0FDE (in fn1229_0DCC)
;;     1229:1042 (in fn1229_0DCC)
;;     1229:1081 (in fn1229_0DCC)
;;     1229:10E6 (in fn1229_0DCC)
fn133F_0528 proc
	enter	6h,0h
	mov	byte ptr [bp-1h],0h
	les	di,[bp+10h]
	xor	ax,ax
	mov	es:[di],ax
	mov	ax,[6CC4h]
	les	di,[bp+0Ch]
	mov	es:[di],ax
	mov	ax,[6CC6h]
	les	di,[bp+8h]
	mov	es:[di],ax
	call	far 1E78h:02FBh
	or	al,al
	jnz	0556h

l133F_0553:
	jmp	0715h

l133F_0556:
	call	far 1E78h:030Dh
	mov	[bp-2h],al
	mov	al,[bp-2h]
	cmp	al,0Dh
	jnz	0570h

l133F_0565:
	les	di,[bp+10h]
	mov	word ptr es:[di],1h
	jmp	065Dh

l133F_0570:
	cmp	al,1Bh
	jnz	057Fh

l133F_0574:
	les	di,[bp+10h]
	mov	word ptr es:[di],1Bh
	jmp	065Dh

l133F_057F:
	cmp	al,21h
	jc	059Bh

l133F_0583:
	cmp	al,7Dh
	ja	059Bh

l133F_0587:
	mov	al,[bp-2h]
	push	ax
	call	far 1EDAh:1384h
	xor	ah,ah
	les	di,[bp+10h]
	mov	es:[di],ax
	jmp	065Dh

l133F_059B:
	cmp	al,0h
	jz	05A2h

l133F_059F:
	jmp	065Dh

l133F_05A2:
	call	far 1E78h:030Dh
	mov	[bp-2h],al
	mov	al,[bp-2h]
	cmp	al,3Bh
	jc	05C3h

l133F_05B1:
	cmp	al,40h
	ja	05C3h

l133F_05B5:
	mov	al,[bp-2h]
	xor	ah,ah
	les	di,[bp+10h]
	mov	es:[di],ax
	jmp	065Dh

l133F_05C3:
	cmp	al,4Bh
	jnz	05EAh

l133F_05C7:
	mov	ax,[6CC4h]
	sub	ax,[6CC0h]
	push	ax
	push	word ptr [6CC6h]
	call	far 13C8h:009Ah
	mov	ax,[6CC4h]
	sub	ax,[6CC0h]
	push	ax
	push	word ptr [6CC6h]
	push	cs
	call	021Fh
	jmp	065Dh

l133F_05EA:
	cmp	al,48h
	jnz	0611h

l133F_05EE:
	push	word ptr [6CC4h]
	mov	ax,[6CC6h]
	sub	ax,[6CC2h]
	push	ax
	call	far 13C8h:009Ah
	push	word ptr [6CC4h]
	mov	ax,[6CC6h]
	sub	ax,[6CC2h]
	push	ax
	push	cs
	call	021Fh
	jmp	065Dh

l133F_0611:
	cmp	al,50h
	jnz	0638h

l133F_0615:
	push	word ptr [6CC4h]
	mov	ax,[6CC6h]
	add	ax,[6CC2h]
	push	ax
	call	far 13C8h:009Ah
	push	word ptr [6CC4h]
	mov	ax,[6CC6h]
	add	ax,[6CC2h]
	push	ax
	push	cs
	call	021Fh
	jmp	065Dh

l133F_0638:
	cmp	al,4Dh
	jnz	065Dh

l133F_063C:
	mov	ax,[6CC4h]
	add	ax,[6CC0h]
	push	ax
	push	word ptr [6CC6h]
	call	far 13C8h:009Ah
	mov	ax,[6CC4h]
	add	ax,[6CC0h]
	push	ax
	push	word ptr [6CC6h]
	push	cs
	call	021Fh

l133F_065D:
	les	di,[bp+10h]
	cmp	word ptr es:[di],0h
	jnz	0669h

l133F_0666:
	jmp	06FEh

l133F_0669:
	mov	byte ptr [bp-1h],1h
	les	di,[bp+10h]
	cmp	word ptr es:[di],1h
	jz	0679h

l133F_0676:
	jmp	06FEh

l133F_0679:
	mov	al,[6CD0h]
	mov	[bp-5h],al
	mov	al,1h
	cmp	al,[bp-5h]
	ja	06FEh

l133F_0686:
	mov	[bp-4h],al
	jmp	068Eh

l133F_068B:
	inc	byte ptr [bp-4h]

l133F_068E:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6CD2h]
	cmp	ax,[6CC4h]
	jge	06F6h

l133F_06A1:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D10h]
	cmp	ax,[6CC4h]
	jle	06F6h

l133F_06B4:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D4Eh]
	cmp	ax,[6CC6h]
	jge	06F6h

l133F_06C7:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D8Ch]
	cmp	ax,[6CC6h]
	jle	06F6h

l133F_06DA:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+6DCAh]
	mov	[bp-3h],al
	mov	al,[bp-3h]
	xor	ah,ah
	les	di,[bp+10h]
	mov	es:[di],ax
	jmp	080Fh

l133F_06F6:
	mov	al,[bp-4h]
	cmp	al,[bp-5h]
	jnz	068Bh

l133F_06FE:
	cmp	byte ptr [bp+6h],0h
	jz	070Eh

l133F_0704:
	push	26Ah
	push	17Fh
	push	cs
	call	026Bh

l133F_070E:
	mov	byte ptr [bp-1h],1h
	jmp	080Fh

l133F_0715:
	cmp	byte ptr [0B6B2h],0h
	jnz	071Fh

l133F_071C:
	jmp	080Fh

l133F_071F:
	les	di,[bp+10h]
	push	es
	push	di
	les	di,[bp+0Ch]
	push	es
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	call	far 13C8h:0066h
	les	di,[bp+10h]
	cmp	word ptr es:[di],0h
	jnz	073Fh

l133F_073C:
	jmp	07D3h

l133F_073F:
	mov	byte ptr [bp-1h],1h
	les	di,[bp+10h]
	cmp	word ptr es:[di],1h
	jz	074Fh

l133F_074C:
	jmp	07D3h

l133F_074F:
	mov	al,[6CD0h]
	mov	[bp-5h],al
	mov	al,1h
	cmp	al,[bp-5h]
	ja	07D3h

l133F_075C:
	mov	[bp-4h],al
	jmp	0764h

l133F_0761:
	inc	byte ptr [bp-4h]

l133F_0764:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6CD2h]
	cmp	ax,[6CC4h]
	jge	07CBh

l133F_0777:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D10h]
	cmp	ax,[6CC4h]
	jle	07CBh

l133F_078A:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D4Eh]
	cmp	ax,[6CC6h]
	jge	07CBh

l133F_079D:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D8Ch]
	cmp	ax,[6CC6h]
	jle	07CBh

l133F_07B0:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+6DCAh]
	mov	[bp-3h],al
	mov	al,[bp-3h]
	xor	ah,ah
	les	di,[bp+10h]
	mov	es:[di],ax
	jmp	080Fh

l133F_07CB:
	mov	al,[bp-4h]
	cmp	al,[bp-5h]
	jnz	0761h

l133F_07D3:
	les	di,[bp+0Ch]
	mov	ax,es:[di]
	cmp	ax,[6CC4h]
	jnz	07EBh

l133F_07DF:
	les	di,[bp+8h]
	mov	ax,es:[di]
	cmp	ax,[6CC6h]
	jz	080Fh

l133F_07EB:
	les	di,[bp+0Ch]
	push	word ptr es:[di]
	les	di,[bp+8h]
	push	word ptr es:[di]
	push	cs
	call	021Fh
	mov	byte ptr [bp-1h],1h
	cmp	byte ptr [bp+6h],0h
	jz	080Fh

l133F_0805:
	push	26Ah
	push	17Fh
	push	cs
	call	026Bh

l133F_080F:
	mov	al,[bp-1h]
	leave
	retf	0Eh
