;; fn13E2_003B: 13E2:003B
;;   Called from:
;;     0800:1859 (in fn0800_184C)
;;     0800:2851 (in fn0800_2827)
;;     0800:2C25 (in fn0800_2C0C)
;;     0800:3DA6 (in fn0800_3D9D)
;;     0800:4371 (in fn0800_4255)
fn13E2_003B proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [0B6C1h],0h
	jnz	0047h

l13E2_0045:
	jmp	007Eh

l13E2_0047:
	mov	byte ptr [0B6C1h],0h
	mov	byte ptr [0B6BEh],0Fh
	jmp	0057h

l13E2_0053:
	dec	byte ptr [0B6BEh]

l13E2_0057:
	mov	al,[0B6BEh]
	xor	ah,ah
	push	ax
	push	0h
	push	0h
	push	0h
	call	far 1AB8h:1CBAh
	mov	al,[0B6BEh]
	xor	ah,ah
	push	ax
	mov	al,[0B6BEh]
	push	ax
	call	far 1AB8h:1342h
	cmp	byte ptr [0B6BEh],0h
	jnz	0053h

l13E2_007E:
	leave
	retf
