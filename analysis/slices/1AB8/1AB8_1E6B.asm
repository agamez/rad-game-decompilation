;; fn1AB8_1E6B: 1AB8:1E6B
;;   Called from:
;;     0800:0DDB (in fn0800_0D20)
;;     0C74:0531 (in fn0C74_03D4)
;;     0C74:0640 (in fn0C74_05B8)
;;     0C74:0EE1 (in fn0C74_0E2E)
;;     0C74:0F15 (in fn0C74_0E2E)
;;     0C74:0FF2 (in fn0C74_0FA1)
;;     0C74:1018 (in fn0C74_0FA1)
;;     0C74:11BC (in fn0C74_0FA1)
;;     0C74:11E2 (in fn0C74_0FA1)
;;     0C74:140D (in fn0C74_0FA1)
;;     0C74:156B (in fn0C74_0FA1)
;;     0C74:1722 (in fn0C74_0FA1)
;;     0C74:17BC (in fn0C74_0FA1)
;;     0C74:1838 (in fn0C74_0FA1)
;;     0C74:19DF (in fn0C74_0FA1)
;;     0C74:1A86 (in fn0C74_0FA1)
;;     0C74:1BC6 (in fn0C74_1B3B)
;;     0C74:1D11 (in fn0C74_1B3B)
;;     0C74:1E48 (in fn0C74_1D95)
;;     0C74:1E7C (in fn0C74_1D95)
;;     0C74:1F59 (in fn0C74_1F08)
;;     0C74:1F7F (in fn0C74_1F08)
;;     0C74:2123 (in fn0C74_1F08)
;;     0C74:2149 (in fn0C74_1F08)
;;     0C74:2374 (in fn0C74_1F08)
;;     0C74:24D2 (in fn0C74_1F08)
;;     0C74:26BB (in fn0C74_1F08)
;;     0C74:280B (in fn0C74_1F08)
;;     0C74:2977 (in fn0C74_1F08)
;;     0C74:2A1E (in fn0C74_1F08)
;;     0C74:2B36 (in fn0C74_2AD9)
;;     0C74:2C16 (in fn0C74_2BBD)
;;     0C74:2C44 (in fn0C74_2BBD)
;;     0C74:2F20 (in fn0C74_2E5A)
;;     0C74:2F78 (in fn0C74_2E5A)
;;     0C74:3072 (in fn0C74_2E5A)
;;     0C74:32FB (in fn0C74_3236)
;;     0C74:3353 (in fn0C74_3236)
;;     0C74:344D (in fn0C74_3236)
;;     0C74:4F2E (in fn0C74_4DAC)
;;     0C74:511B (in fn0C74_4FD7)
;;     0C74:53C7 (in fn0C74_5258)
;;     1229:0096 (in fn1229_0040)
fn1AB8_1E6B proc
	push	bp
	mov	bp,sp
	les	bx,[bp+6h]
	mov	cx,[bp+10h]
	mov	dx,[bp+0Eh]
	mov	si,[bp+0Ch]
	mov	di,[bp+0Ah]
	cmp	cx,si
	jc	1E83h

l1AB8_1E81:
	xchg	cx,si

l1AB8_1E83:
	cmp	dx,di
	jc	1E89h

l1AB8_1E87:
	xchg	dx,di

l1AB8_1E89:
	sub	si,cx
	mov	es:[bx],si
	sub	di,dx
	mov	es:[bx+2h],di
	mov	si,34h
	call	dword ptr [0B820h]
	pop	bp
	retf	0Ch
