;; fn1E78_00E5: 1E78:00E5
;;   Called from:
;;     1E78:0041 (in fn1E78_002E)
;;     1E78:0174 (in fn1E78_016B)
fn1E78_00E5 proc
	mov	ah,0Fh
	call	0609h
	push	ax
	mov	ax,1130h
	mov	bh,0h
	mov	dl,0h
	call	0609h
	pop	ax
	mov	cl,0h
	or	dl,dl
	jnz	0104h

l1E78_00FC:
	mov	dl,18h
	cmp	al,3h
	ja	0104h

l1E78_0102:
	mov	cl,1h

l1E78_0104:
	mov	dh,dl
	mov	dl,ah
	dec	dl
	mov	ah,0h
	cmp	dh,18h
	jbe	0113h

l1E78_0111:
	mov	ah,1h

l1E78_0113:
	mov	[0B8ACh],ax
	mov	[0B8B6h],dx
	mov	[0B8ABh],cl
	mov	byte ptr [0B8AAh],1h
	xor	ax,ax
	mov	[0B8B0h],ax
	mov	[0B8B2h],dx
	ret
1E78:012D                                        50 1E B8              P..
1E78:0130 14 20 8E D8 80 3E A8 B8 00 74 05 C6 06 BA B8 01 . ...>...t......
1E78:0140 1F 58 CF                                        .X.
