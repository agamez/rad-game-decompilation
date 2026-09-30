;; fn0C43_001E: 0C43:001E
;;   Called from:
;;     0C43:02F0 (in fn0C43_00B9)
fn0C43_001E proc
	push	bp
	mov	bp,sp
	mov	byte ptr [589Dh],10h
	mov	byte ptr [589Ch],12h
	les	di,[bp+4h]
	mov	ax,es
	mov	[58ACh],ax
	les	di,[bp+4h]
	mov	ax,di
	mov	[58A2h],ax
	xor	ax,ax
	mov	[589Eh],ax
	mov	word ptr [58A0h],100h
	push	10h
	mov	di,589Ch
	push	ds
	push	di
	call	far 1E5Fh:000Bh
	leave
	ret	4h
