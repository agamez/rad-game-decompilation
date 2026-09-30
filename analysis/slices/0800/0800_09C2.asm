;; fn0800_09C2: 0800:09C2
;;   Called from:
;;     0800:18AB (in fn0800_184C)
;;     0800:26D3 (in fn0800_2401)
;;     0800:26EC (in fn0800_2401)
;;     0800:26F8 (in fn0800_2401)
;;     0800:2724 (in fn0800_2401)
;;     0800:2730 (in fn0800_2401)
;;     0800:2749 (in fn0800_2401)
;;     0800:2762 (in fn0800_2401)
;;     0800:276C (in fn0800_2401)
;;     0800:2778 (in fn0800_2401)
;;     0800:2799 (in fn0800_2401)
;;     0800:27A1 (in fn0800_2401)
;;     0800:27A6 (in fn0800_2401)
;;     0800:27B1 (in fn0800_2401)
;;     0800:27D2 (in fn0800_2401)
;;     0800:27DA (in fn0800_2401)
;;     0800:27DF (in fn0800_2401)
;;     0800:27EA (in fn0800_2401)
;;     0800:27F4 (in fn0800_2401)
;;     0800:29BA (in fn0800_2827)
;;     0800:29D3 (in fn0800_2827)
;;     0800:29DF (in fn0800_2827)
;;     0800:2A0B (in fn0800_2827)
;;     0800:2A17 (in fn0800_2827)
;;     0800:2A30 (in fn0800_2827)
;;     0800:2A49 (in fn0800_2827)
;;     0800:2A53 (in fn0800_2827)
;;     0800:2A5F (in fn0800_2827)
;;     0800:2A80 (in fn0800_2827)
;;     0800:2A88 (in fn0800_2827)
;;     0800:2A8D (in fn0800_2827)
;;     0800:2A98 (in fn0800_2827)
;;     0800:2AB9 (in fn0800_2827)
;;     0800:2AC1 (in fn0800_2827)
;;     0800:2AC6 (in fn0800_2827)
;;     0800:2AD1 (in fn0800_2827)
;;     0800:2ADB (in fn0800_2827)
;;     0800:2E1B (in fn0800_2C0C)
;;     0800:2E34 (in fn0800_2C0C)
;;     0800:2EDB (in fn0800_2C0C)
;;     0800:2EF4 (in fn0800_2C0C)
;;     0800:2F00 (in fn0800_2C0C)
;;     0800:2F19 (in fn0800_2C0C)
;;     0800:2F25 (in fn0800_2C0C)
;;     0800:2F3E (in fn0800_2C0C)
;;     0800:2FD0 (in fn0800_2C0C)
;;     0800:2FE9 (in fn0800_2C0C)
;;     0800:3019 (in fn0800_2C0C)
;;     0800:3023 (in fn0800_2C0C)
;;     0800:302E (in fn0800_2C0C)
;;     0800:303C (in fn0800_2C0C)
;;     0800:3044 (in fn0800_2C0C)
;;     0800:3049 (in fn0800_2C0C)
;;     0800:3054 (in fn0800_2C0C)
;;     0800:3062 (in fn0800_2C0C)
;;     0800:306A (in fn0800_2C0C)
;;     0800:306F (in fn0800_2C0C)
;;     0800:307A (in fn0800_2C0C)
;;     0800:3084 (in fn0800_2C0C)
;;     0800:327F (in fn0800_31B7)
;;     0800:3430 (in fn0800_31B7)
;;     0800:3449 (in fn0800_31B7)
;;     0800:34B6 (in fn0800_31B7)
;;     0800:34CF (in fn0800_31B7)
;;     0800:34DB (in fn0800_31B7)
;;     0800:34F4 (in fn0800_31B7)
;;     0800:3500 (in fn0800_31B7)
;;     0800:3519 (in fn0800_31B7)
;;     0800:3543 (in fn0800_31B7)
;;     0800:355C (in fn0800_31B7)
;;     0800:358C (in fn0800_31B7)
;;     0800:3596 (in fn0800_31B7)
;;     0800:35A1 (in fn0800_31B7)
;;     0800:35AF (in fn0800_31B7)
;;     0800:35B7 (in fn0800_31B7)
;;     0800:35BC (in fn0800_31B7)
;;     0800:35C7 (in fn0800_31B7)
;;     0800:35D5 (in fn0800_31B7)
;;     0800:35DD (in fn0800_31B7)
;;     0800:35E2 (in fn0800_31B7)
;;     0800:35ED (in fn0800_31B7)
;;     0800:35F7 (in fn0800_31B7)
fn0800_09C2 proc
	enter	2h,0h
	mov	al,[bp+4h]
	mov	[58E4h],al
	mov	al,[bp+4h]
	cmp	al,0h
	jc	09F6h

l0800_09D3:
	cmp	al,8h
	ja	09F6h

l0800_09D7:
	mov	al,[bp+4h]
	xor	ah,ah
	shl	ax,1h
	push	ax
	call	04CCh
	add	ax,16h
	mov	dx,ax
	mov	al,[bp+4h]
	xor	ah,ah
	shl	ax,3h
	add	ax,dx
	mov	[bp-2h],ax
	jmp	0A21h

l0800_09F6:
	cmp	al,9h
	jc	0A21h

l0800_09FA:
	cmp	al,10h
	ja	0A21h

l0800_09FE:
	mov	al,[bp+4h]
	xor	ah,ah
	sub	ax,9h
	shl	ax,1h
	push	ax
	call	04CCh
	add	ax,16h
	mov	dx,ax
	mov	al,[bp+4h]
	xor	ah,ah
	sub	ax,9h
	shl	ax,3h
	add	ax,dx
	mov	[bp-2h],ax

l0800_0A21:
	push	0Bh
	call	far 1AB8h:1C32h
	call	far 1206h:0066h
	push	word ptr [bp-2h]
	push	198h
	mov	al,[bp+4h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5388h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-2h]
	dec	ax
	push	ax
	push	197h
	mov	ax,[bp-2h]
	add	ax,2Ch
	push	ax
	push	1C4h
	call	far 1AB8h:112Eh
	mov	al,[bp+4h]
	push	ax
	mov	di,982h
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	0A86h

l0800_0A83:
	call	04E3h

l0800_0A86:
	mov	al,[bp+4h]
	push	ax
	mov	di,9A2h
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	0A9Bh

l0800_0A96:
	call	far 1206h:0038h

l0800_0A9B:
	leave
	ret	2h
0800:0A9F                                              01                .
0800:0AA0 30                                              0
