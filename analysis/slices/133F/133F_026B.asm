;; fn133F_026B: 133F:026B
;;   Called from:
;;     133F:070A (in fn133F_0528)
;;     133F:080B (in fn133F_0528)
fn133F_026B proc
	enter	108h,0h
	mov	ax,[6CC4h]
	sub	ax,[6CC8h]
	cwd
	idiv	word ptr [6CC0h]
	cwd
	push	dx
	push	ax
	push	2h
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0F26h
	mov	ax,[6CC6h]
	sub	ax,[6CCAh]
	cwd
	idiv	word ptr [6CC2h]
	cwd
	push	dx
	push	ax
	push	2h
	lea	di,[bp-8h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0F26h
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	0h
	push	1h
	lea	di,[bp+0FEF8h]
	push	ss
	push	di
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,269h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp-8h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	push	cs
	call	014Bh
	leave
	retf	4h
