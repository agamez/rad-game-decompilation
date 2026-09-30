;; fn0800_0B42: 0800:0B42
;;   Called from:
;;     0800:0C69 (in fn0800_0BEC)
;;     0800:0CDF (in fn0800_0C71)
fn0800_0B42 proc
	enter	104h,0h
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	push	word ptr [58CEh]
	push	word ptr [58CCh]
	call	far 0C74h:004Bh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp-4h],2h
	jnc	0B91h

l0800_0B6B:
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,0B40h
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

l0800_0B91:
	call	far 1206h:0066h
	push	233h
	push	192h
	push	244h
	push	19Bh
	call	005Ah
	push	8h
	call	far 1AB8h:1C32h
	push	23Bh
	push	196h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	23Ch
	push	197h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	0h
	call	far 1AB8h:1C32h
	call	far 1206h:0038h
	leave
	ret
0800:0BE1    0A 54 49 4D 45 3A 30 30 2E 30 30              .TIME:00.00
