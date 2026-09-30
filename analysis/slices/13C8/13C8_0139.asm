;; fn13C8_0139: 13C8:0139
;;   Called from:
;;     0800:4269 (in fn0800_4255)
fn13C8_0139 proc
	push	bp
	mov	bp,sp
	mov	byte ptr [0B6B2h],0h
	push	cs
	call	0000h
	or	al,al
	jz	018Fh

l13C8_0149:
	mov	di,0B6AEh
	push	ds
	push	di
	mov	di,0B6B0h
	push	ds
	push	di
	push	cs
	call	000Dh
	cmp	word ptr [0B6AEh],0h
	jz	0163h

l13C8_015E:
	mov	byte ptr [0B6B2h],1h

l13C8_0163:
	cmp	byte ptr [0B6B2h],0h
	jz	018Fh

l13C8_016A:
	mov	di,0B6B4h
	push	ds
	push	di
	mov	di,0B6B6h
	push	ds
	push	di
	mov	di,0B6B8h
	push	ds
	push	di
	push	cs
	call	0066h
	push	0h
	push	280h
	push	cs
	call	00BFh
	push	0h
	push	1E0h
	push	cs
	call	00E4h

l13C8_018F:
	leave
	retf
13C8:0191    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ...............
