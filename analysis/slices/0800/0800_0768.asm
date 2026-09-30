;; fn0800_0768: 0800:0768
;;   Called from:
;;     0800:30B8 (in fn0800_2C0C)
;;     0800:36CC (in fn0800_31B7)
fn0800_0768 proc
	enter	2h,0h
	push	0h
	push	0h
	push	0h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	8h
	call	far 1AB8h:1C32h
	push	204h
	push	1A7h
	push	264h
	push	1CFh
	call	005Ah
	push	233h
	push	1AEh
	mov	di,755h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	233h
	push	1C6h
	mov	di,75Dh
	push	cs
	push	di
	call	far 1AB8h:1D82h

l0800_07B6:
	push	0Bh
	call	far 1AB8h:1C32h
	push	234h
	push	1AFh
	mov	di,755h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	234h
	push	1C7h
	mov	di,75Dh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	mov	word ptr [bp-2h],1h
	jmp	07E7h

l0800_07E4:
	inc	word ptr [bp-2h]

l0800_07E7:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jnz	07FBh

l0800_07F2:
	call	far 1E78h:02FBh
	or	al,al
	jz	07FDh

l0800_07FB:
	jmp	0875h

l0800_07FD:
	cmp	word ptr [bp-2h],9C4h
	jnz	07E4h

l0800_0804:
	push	0Eh
	call	far 1AB8h:1C32h
	push	234h
	push	1AFh
	mov	di,755h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	234h
	push	1C7h
	mov	di,75Dh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	mov	word ptr [bp-2h],1h
	jmp	0835h

l0800_0832:
	inc	word ptr [bp-2h]

l0800_0835:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jnz	0849h

l0800_0840:
	call	far 1E78h:02FBh
	or	al,al
	jz	084Bh

l0800_0849:
	jmp	0875h

l0800_084B:
	cmp	word ptr [bp-2h],1388h
	jnz	0832h

l0800_0852:
	call	far 1E78h:02FBh
	or	al,al
	jnz	085Eh

l0800_085B:
	jmp	07B6h

l0800_085E:
	call	far 1E78h:02FBh
	or	al,al
	jz	086Eh

l0800_0867:
	call	far 1E78h:030Dh
	jmp	085Eh

l0800_086E:
	push	0h
	call	far 1AB8h:1C32h

l0800_0875:
	leave
	ret
