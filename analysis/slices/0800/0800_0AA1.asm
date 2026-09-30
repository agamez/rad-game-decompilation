;; fn0800_0AA1: 0800:0AA1
;;   Called from:
;;     0800:0C6C (in fn0800_0BEC)
;;     0800:0CBB (in fn0800_0C71)
fn0800_0AA1 proc
	enter	104h,0h
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	push	word ptr [58DEh]
	push	word ptr [58DCh]
	call	far 0C74h:004Bh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp-4h],2h
	jnc	0AF0h

l0800_0ACA:
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,0A9Fh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h

l0800_0AF0:
	call	far 1206h:0066h
	push	24Bh
	push	192h
	push	25Ch
	push	19Bh
	call	005Ah
	push	8h
	call	far 1AB8h:1C32h
	push	253h
	push	196h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	254h
	push	197h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	call	far 1206h:0038h
	push	0h
	call	far 1AB8h:1C32h
	leave
	ret
0800:0B40 01 30                                           .0
