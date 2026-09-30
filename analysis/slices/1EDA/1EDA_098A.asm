;; fn1EDA_098A: 1EDA:098A
;;   Called from:
;;     0800:0C80 (in fn0800_0C71)
;;     0800:0C98 (in fn0800_0C71)
;;     0C74:031F (in fn0C74_02D8)
;;     0C74:0337 (in fn0C74_02D8)
;;     0C74:104C (in fn0C74_0FA1)
;;     0C74:15FE (in fn0C74_0FA1)
;;     0C74:16D8 (in fn0C74_0FA1)
;;     0C74:1854 (in fn0C74_0FA1)
;;     0C74:18C7 (in fn0C74_0FA1)
;;     0C74:1987 (in fn0C74_0FA1)
;;     0C74:1AFD (in fn0C74_0FA1)
;;     0C74:1C35 (in fn0C74_1B3B)
;;     0C74:1D77 (in fn0C74_1B3B)
;;     0C74:1FB3 (in fn0C74_1F08)
;;     0C74:2565 (in fn0C74_1F08)
;;     0C74:265B (in fn0C74_1F08)
;;     0C74:26D7 (in fn0C74_1F08)
;;     0C74:274A (in fn0C74_1F08)
;;     0C74:2903 (in fn0C74_1F08)
;;     0C74:2A95 (in fn0C74_1F08)
;;     0C74:2B90 (in fn0C74_2AD9)
;;     1AB8:121D (in fn1AB8_11FB)
;;     1EDA:117E (in fn1EDA_116A)
fn1EDA_098A proc
	push	bp
	mov	bp,cx
	or	bp,bx
	jz	09F1h

l1EDA_0991:
	or	bx,bx
	pushf
	jns	09A0h

l1EDA_0996:
	not	cx
	not	bx
	add	cx,1h
	adc	bx,0h

l1EDA_09A0:
	or	dx,dx
	pushf
	jns	09AFh

l1EDA_09A5:
	not	ax
	not	dx
	add	ax,1h
	adc	dx,0h

l1EDA_09AF:
	mov	si,cx
	mov	di,bx
	xor	cx,cx
	xor	bx,bx
	mov	bp,21h

l1EDA_09BA:
	rcl	cx,1h
	rcl	bx,1h
	sub	cx,si
	sbb	bx,di
	jnc	09C8h

l1EDA_09C4:
	add	cx,si
	adc	bx,di

l1EDA_09C8:
	cmc
	rcl	ax,1h
	rcl	dx,1h
	dec	bp
	jnz	09BAh

l1EDA_09D0:
	popf
	jns	09E2h

l1EDA_09D3:
	not	cx
	not	bx
	add	cx,1h
	adc	bx,0h
	popf
	jns	09E5h

l1EDA_09E0:
	jmp	09EFh

l1EDA_09E2:
	popf
	jns	09EFh

l1EDA_09E5:
	not	ax
	not	dx
	add	ax,1h
	adc	dx,0h

l1EDA_09EF:
	pop	bp
	retf

l1EDA_09F1:
	pop	bp
	mov	ax,0C8h
	jmp	00E2h
1EDA:09F8                         83 E1 1F 74 06 D1 EA D1         ...t....
1EDA:0A00 D8 E2 FA CB 83 E1 1F 74 06 D1 E0 D1 D2 E2 FA CB .......t........
1EDA:0A10 0B D2 7D 0A F7 D0 F7 D2 05 01 00 83 D2 00 CB    ..}............
