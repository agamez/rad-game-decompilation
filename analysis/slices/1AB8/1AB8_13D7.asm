;; fn1AB8_13D7: 1AB8:13D7
;;   Called from:
;;     0800:0306 (in fn0800_01FE)
;;     0800:0A45 (in fn0800_09C2)
;;     0800:11AB (in fn0800_0D20)
;;     0800:257F (in fn0800_2401)
;;     0C74:04EF (in fn0C74_03D4)
;;     0C74:0699 (in fn0C74_05B8)
;;     0C74:0700 (in fn0C74_06B7)
;;     0C74:0D34 (in fn0C74_0CFA)
;;     0C74:0D83 (in fn0C74_0D43)
;;     0C74:0DD4 (in fn0C74_0D94)
;;     0C74:0E1F (in fn0C74_0DE5)
;;     0C74:0F53 (in fn0C74_0E2E)
;;     0C74:0F76 (in fn0C74_0E2E)
;;     0C74:1066 (in fn0C74_0FA1)
;;     0C74:107C (in fn0C74_0FA1)
;;     0C74:12BA (in fn0C74_0FA1)
;;     0C74:12D7 (in fn0C74_0FA1)
;;     0C74:138D (in fn0C74_0FA1)
;;     0C74:1442 (in fn0C74_0FA1)
;;     0C74:14EB (in fn0C74_0FA1)
;;     0C74:15A0 (in fn0C74_0FA1)
;;     0C74:173D (in fn0C74_0FA1)
;;     0C74:17DE (in fn0C74_0FA1)
;;     0C74:18A5 (in fn0C74_0FA1)
;;     0C74:1A1A (in fn0C74_0FA1)
;;     0C74:1AC2 (in fn0C74_0FA1)
;;     0C74:1C14 (in fn0C74_1B3B)
;;     0C74:1C89 (in fn0C74_1B3B)
;;     0C74:1D3E (in fn0C74_1B3B)
;;     0C74:1EBA (in fn0C74_1D95)
;;     0C74:1EDD (in fn0C74_1D95)
;;     0C74:1FCD (in fn0C74_1F08)
;;     0C74:1FE3 (in fn0C74_1F08)
;;     0C74:2221 (in fn0C74_1F08)
;;     0C74:223E (in fn0C74_1F08)
;;     0C74:22F4 (in fn0C74_1F08)
;;     0C74:23A9 (in fn0C74_1F08)
;;     0C74:2452 (in fn0C74_1F08)
;;     0C74:2507 (in fn0C74_1F08)
;;     0C74:2728 (in fn0C74_1F08)
;;     0C74:2861 (in fn0C74_1F08)
;;     0C74:29B2 (in fn0C74_1F08)
;;     0C74:2A5A (in fn0C74_1F08)
;;     0C74:2B69 (in fn0C74_2AD9)
;;     0C74:2C56 (in fn0C74_2BBD)
;;     0C74:2CBD (in fn0C74_2BBD)
;;     0C74:2F9A (in fn0C74_2E5A)
;;     0C74:30C7 (in fn0C74_2E5A)
;;     0C74:3116 (in fn0C74_2E5A)
;;     0C74:312F (in fn0C74_2E5A)
;;     0C74:319A (in fn0C74_2E5A)
;;     0C74:3218 (in fn0C74_2E5A)
;;     0C74:3375 (in fn0C74_3236)
;;     0C74:34A2 (in fn0C74_3236)
;;     0C74:34F0 (in fn0C74_3236)
;;     0C74:350A (in fn0C74_3236)
;;     0C74:3579 (in fn0C74_3236)
;;     0C74:35F7 (in fn0C74_3236)
;;     0C74:379B (in fn0C74_3615)
;;     0C74:3946 (in fn0C74_37C3)
;;     0C74:4937 (in fn0C74_45CE)
;;     0C74:4D4A (in fn0C74_4999)
;;     0C74:4F5D (in fn0C74_4DAC)
;;     0C74:5141 (in fn0C74_4FD7)
;;     0C74:540D (in fn0C74_5258)
;;     1229:0361 (in fn1229_0040)
;;     1229:0B35 (in fn1229_0AA8)
;;     1229:0C9E (in fn1229_0C58)
;;     1229:0F0A (in fn1229_0DCC)
;;     1229:0F73 (in fn1229_0DCC)
fn1AB8_13D7 proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	les	di,[bp+8h]
	mov	ax,es:[di+2h]
	mov	[bp-2h],ax
	mov	ax,[bp+0Ch]
	add	ax,[0B854h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[0B7C4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	les	di,[bp+8h]
	mov	es:[di+2h],ax
	les	di,[bp+8h]
	mov	ax,es:[di+2h]
	cmp	ax,[bp-2h]
	jbe	1419h

l1AB8_140F:
	mov	ax,[bp-2h]
	les	di,[bp+8h]
	mov	es:[di+2h],ax

l1AB8_1419:
	les	di,[bp+8h]
	mov	ax,es:[di]
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Eh]
	add	ax,[0B852h]
	cwd
	add	ax,cx
	adc	dx,bx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[0B7C2h]
	xor	dx,dx
	cmp	dx,bx
	jl	1464h

l1AB8_143E:
	jg	1444h

l1AB8_1440:
	cmp	ax,cx
	jc	1464h

l1AB8_1444:
	mov	ax,[bp+0Eh]
	add	ax,[0B852h]
	or	ax,ax
	jl	1464h

l1AB8_144F:
	les	di,[bp+8h]
	cmp	word ptr es:[di+2h],0h
	jc	1464h

l1AB8_1459:
	mov	ax,[bp+0Ch]
	add	ax,[0B854h]
	or	ax,ax
	jge	1470h

l1AB8_1464:
	mov	ax,[bp-2h]
	les	di,[bp+8h]
	mov	es:[di+2h],ax
	jmp	148Ch

l1AB8_1470:
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	les	di,[bp+8h]
	push	es
	push	di
	push	word ptr [bp+6h]
	push	cs
	call	1E9Fh
	mov	ax,[bp-2h]
	les	di,[bp+8h]
	mov	es:[di+2h],ax

l1AB8_148C:
	mov	sp,bp
	pop	bp
	retf	0Ah
