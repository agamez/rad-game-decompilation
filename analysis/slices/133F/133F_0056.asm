;; fn133F_0056: 133F:0056
;;   Called from:
;;     133F:0819 (in fn133F_0816)
fn133F_0056 proc
	enter	20Ch,0h
	xor	ax,ax
	mov	[bp-2h],ax
	lea	di,[bp-2h]
	push	ss
	push	di
	lea	di,[bp-4h]
	push	ss
	push	di
	mov	di,0h
	push	cs
	push	di
	call	far 1AB8h:0BAEh
	call	far 1AB8h:04F3h
	mov	[bp-6h],ax
	cmp	word ptr [bp-6h],0h
	jz	00E0h

l133F_0081:
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,1h
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	lea	di,[bp+0FDF4h]
	push	ss
	push	di
	push	word ptr [bp-6h]
	call	far 1AB8h:027Eh
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,14h
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,3Dh
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	mov	ax,1h
	call	far 1EDAh:00E9h

l133F_00E0:
	call	far 13C8h:0000h
	or	al,al
	jz	0113h

l133F_00E9:
	mov	di,0B6AEh
	push	ds
	push	di
	mov	di,0B6B0h
	push	ds
	push	di
	call	far 13C8h:000Dh
	cmp	word ptr [0B6AEh],0h
	jz	0113h

l133F_00FF:
	push	0h
	push	27Fh
	call	far 13C8h:00BFh
	push	0h
	push	1DFh
	call	far 13C8h:00E4h

l133F_0113:
	mov	byte ptr [0B59Dh],0h
	mov	byte ptr [0B5A2h],0h
	mov	byte ptr [6CD0h],0h
	mov	byte ptr [0B59Ch],0h
	push	0h
	call	far 1AB8h:1250h
	push	0Fh
	call	far 1AB8h:1C32h
	leave
	retf
