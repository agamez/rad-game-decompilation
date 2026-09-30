;; fn0800_0619: 0800:0619
;;   Called from:
;;     0800:2616 (in fn0800_2401)
;;     0800:2937 (in fn0800_2827)
;;     0800:2DD5 (in fn0800_2C0C)
;;     0800:340A (in fn0800_31B7)
fn0800_0619 proc
	enter	104h,0h
	push	204h
	push	1A7h
	push	264h
	push	1CFh
	call	005Ah
	push	0h
	push	0h
	push	0h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,605h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	0672h

l0800_0651:
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	push	word ptr [5990h]
	push	word ptr [598Eh]
	call	far 0C74h:004Bh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	3h
	call	far 1EDAh:0A39h
	jmp	0683h

l0800_0672:
	mov	di,60Ah
	push	cs
	push	di
	lea	di,[bp-4h]
	push	ss
	push	di
	push	3h
	call	far 1EDAh:0A39h

l0800_0683:
	cmp	byte ptr [bp-4h],2h
	jnc	06AFh

l0800_0689:
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,60Eh
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
	push	3h
	call	far 1EDAh:0A39h

l0800_06AF:
	cmp	byte ptr [bp-4h],3h
	jnc	06DBh

l0800_06B5:
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,60Eh
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
	push	3h
	call	far 1EDAh:0A39h

l0800_06DB:
	push	8h
	call	far 1AB8h:1C32h
	push	233h
	push	1AEh
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,610h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1AB8h:1D82h
	push	233h
	push	1C6h
	mov	di,5ECEh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	push	0Bh
	call	far 1AB8h:1C32h
	push	234h
	push	1AFh
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,610h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1AB8h:1D82h
	push	234h
	push	1C7h
	mov	di,5ECEh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	leave
	ret
0800:0755                07 50 52 45 53 53 45 5A 0A 55 4E      .PRESSEZ.UN
0800:0760 45 20 54 4F 55 43 48 45                         E TOUCHE
