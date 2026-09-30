;; fn1AB8_1342: 1AB8:1342
;;   Called from:
;;     0800:2946 (in fn0800_2827)
;;     0800:2DE4 (in fn0800_2C0C)
;;     0800:3414 (in fn0800_31B7)
;;     0800:3DFA (in fn0800_3D9D)
;;     0800:40A4 (in fn0800_3D9D)
;;     0800:40B2 (in fn0800_3D9D)
;;     0800:43A5 (in fn0800_4255)
;;     13E2:0072 (in fn13E2_003B)
;;     13E2:00ED (in fn13E2_0080)
;;     13E2:0183 (in fn13E2_00FB)
fn1AB8_1342 proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [0B84Eh],0h
	jz	135Dh

l1AB8_134C:
	mov	al,[0B87Ah]
	xor	ah,ah
	dec	ax
	cmp	ax,[bp+8h]
	jc	135Dh

l1AB8_1357:
	cmp	byte ptr [bp+6h],0h
	jge	135Fh

l1AB8_135D:
	jmp	1380h

l1AB8_135F:
	mov	al,[bp+6h]
	mov	di,[bp+8h]
	mov	[di+0B87Bh],al
	cmp	word ptr [bp+8h],0h
	jnz	1374h

l1AB8_136F:
	mov	byte ptr [0B840h],0h

l1AB8_1374:
	push	word ptr [bp+8h]
	mov	al,[bp+6h]
	cbw
	push	ax
	push	cs
	call	1CD7h

l1AB8_1380:
	pop	bp
	retf	4h
