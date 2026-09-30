;; fn0800_184C: 0800:184C
;;   Called from:
;;     0800:3EEB (in fn0800_3D9D)
;;     0800:3F23 (in fn0800_3D9D)
;;     0800:400B (in fn0800_3D9D)
fn0800_184C proc
	push	bp
	mov	bp,sp
	call	far 1206h:0066h
	call	far 1AB8h:0F80h
	call	far 13E2h:003Bh
	push	8h
	call	far 1AB8h:1C32h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	push	0h
	push	27Fh
	push	177h
	call	far 1AB8h:112Eh
	push	3h
	push	17Bh
	push	27Ch
	push	1DAh
	call	1315h
	mov	byte ptr [53DEh],0h
	mov	byte ptr [53DCh],0h
	mov	byte ptr [53DBh],0h
	xor	ax,ax
	mov	[53D4h],ax
	jmp	18A7h

l0800_18A3:
	inc	word ptr [53D4h]

l0800_18A7:
	mov	al,[53D4h]
	push	ax
	call	09C2h
	call	far 1206h:0066h
	cmp	word ptr [53D4h],8h
	jnz	18A3h

l0800_18BA:
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	8h
	call	far 1AB8h:1C32h
	push	43h
	push	1CEh
	mov	di,1830h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	93h
	push	1CEh
	mov	di,1838h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0E3h
	push	1CEh
	mov	di,1830h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	12Fh
	push	1CEh
	mov	di,183Fh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	163h
	push	1CEh
	mov	di,1842h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	197h
	push	1CEh
	mov	di,1845h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	1CBh
	push	1CEh
	mov	di,1848h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0Bh
	call	far 1AB8h:1C32h
	push	44h
	push	1CFh
	mov	di,1830h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	94h
	push	1CFh
	mov	di,1838h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0E4h
	push	1CFh
	mov	di,1830h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	130h
	push	1CFh
	mov	di,183Fh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	164h
	push	1CFh
	mov	di,1842h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	198h
	push	1CFh
	mov	di,1845h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	1CCh
	push	1CFh
	mov	di,1848h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0h
	call	far 1AB8h:1C32h
	push	1h
	push	198h
	push	16h
	call	04CCh
	push	ax
	push	1D1h
	push	9Ch
	push	1B4h
	call	far 1206h:01ACh
	call	far 1206h:0038h
	leave
	ret
