;; fn11C8_0354: 11C8:0354
;;   Called from:
;;     0800:0359 (in fn0800_031B)
;;     0C74:072A (in fn0C74_070D)
;;     0C74:0845 (in fn0C74_076B)
;;     0C74:0B09 (in fn0C74_0A35)
;;     0C74:2D10 (in fn0C74_2BBD)
;;     0C74:31EA (in fn0C74_2E5A)
;;     0C74:35C9 (in fn0C74_3236)
;;     0C74:36C2 (in fn0C74_3615)
;;     0C74:386F (in fn0C74_37C3)
;;     0C74:48AF (in fn0C74_45CE)
;;     0C74:4CC4 (in fn0C74_4999)
fn11C8_0354 proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [5976h],0h
	jnz	0368h

l11C8_035E:
	push	word ptr [bp+6h]
	call	far 1E78h:02C7h
	jmp	0390h

l11C8_0368:
	mov	al,[5975h]
	xor	ah,ah
	add	ax,0A0h
	push	ax
	mov	al,[bp+6h]
	push	ax
	call	02DBh
	mov	al,[5975h]
	xor	ah,ah
	add	ax,0B0h
	push	ax
	mov	al,[bp+7h]
	or	al,10h
	push	ax
	call	02DBh
	push	0C8h
	push	cs
	call	0236h

l11C8_0390:
	leave
	retf	2h
