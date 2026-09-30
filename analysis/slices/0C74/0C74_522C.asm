;; fn0C74_522C: 0C74:522C
;;   Called from:
;;     0800:08D1 (in fn0800_08C0)
;;     0800:26DD (in fn0800_2401)
;;     0800:29C4 (in fn0800_2827)
;;     0800:2EE5 (in fn0800_2C0C)
;;     0800:34C0 (in fn0800_31B7)
fn0C74_522C proc
	enter	2h,0h
	mov	byte ptr [bp-1h],1h
	mov	ax,[5968h]
	cmp	ax,1h
	jnz	5244h

l0C74_523C:
	call	3236h
	mov	[bp-1h],al
	jmp	524Fh

l0C74_5244:
	cmp	ax,0FFFFh
	jnz	524Fh

l0C74_5249:
	call	2E5Ah
	mov	[bp-1h],al

l0C74_524F:
	push	cs
	call	05B8h
	mov	al,[bp-1h]
	leave
	retf
