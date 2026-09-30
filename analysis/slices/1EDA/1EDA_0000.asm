;; fn1EDA_0000: 1EDA:0000
;;   Called from:
;;     0800:4255 (in fn0800_4255)
fn1EDA_0000 proc
	mov	dx,2014h
	mov	ds,dx
	mov	[537Ch],es
	xor	bp,bp
	mov	ax,sp
	add	ax,13h
	mov	cl,4h
	shr	ax,cl
	mov	dx,ss
	add	ax,dx
	mov	[534Eh],ax
	mov	[5350h],ax
	add	ax,[5348h]
	mov	[5352h],ax
	mov	[535Ch],ax
	mov	[5360h],ax
	mov	[5368h],ax
	mov	dx,es:[0002h]
	mov	[5364h],dx
	mov	word ptr [536Eh],0A9h
	mov	[5370h],cs
	mov	di,0BABCh
	mov	si,1EEh
	mov	cx,13h
	nop

l1EDA_004B:
	cld
	lodsb	al,cs:[si]
	mov	ah,35h
	int	21h
	mov	[di],bx
	mov	[di+2h],es
	add	di,4h
	loop	004Bh

l1EDA_005C:
	push	ds
	push	cs
	pop	ds
	mov	dx,0DFh
	mov	ax,2500h
	int	21h
	mov	dx,0E6h
	mov	ax,2523h
	int	21h
	mov	dx,0AEh
	mov	ax,2524h
	int	21h
	mov	dx,0D7h
	mov	ax,253Fh
	int	21h
	pop	ds
	mov	ax,0B8BCh
	push	ds
	push	ax
	push	ds
	push	ax
	mov	ax,218h
	push	cs
	push	ax
	push	cs
	call	04F5h
	push	cs
	call	0565h
	mov	ax,0B9BCh
	push	ds
	push	ax
	push	ds
	push	ax
	mov	ax,218h
	push	cs
	push	ax
	push	cs
	call	04F5h
	push	cs
	call	056Ah
	retf
1EDA:00A9                            33 C0 CA 02 00 FB 83          3......
1EDA:00B0 C4 06 58 83 E7 1F 81 C7 96 00 80 FC 39 73 03 BF ..X.........9s..
1EDA:00C0 FF FF 57 B4 54 CD 21 8B EC 80 4E 16 01 58 5B 59 ..W.T.!...N..X[Y
1EDA:00D0 5A 5E 5F 5D 1F 07 CF B8 D0 00 83 C4 06 EB 03 B8 Z^_]............
1EDA:00E0 C8 00                                           ..
