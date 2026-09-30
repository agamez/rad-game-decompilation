;; fn0800_00C1: 0800:00C1
;;   Called from:
;;     0800:2646 (in fn0800_2401)
;;     0800:2975 (in fn0800_2827)
;;     0800:2E42 (in fn0800_2C0C)
;;     0800:2FF4 (in fn0800_2C0C)
;;     0800:3457 (in fn0800_31B7)
;;     0800:3567 (in fn0800_31B7)
fn0800_00C1 proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [58BEh],0h
	jz	00CDh

l0800_00CB:
	jmp	00FFh

l0800_00CD:
	xor	ax,ax
	mov	[53E2h],ax
	mov	ax,[bp+4h]
	mov	dx,[bp+6h]
	mov	[58D8h],ax
	mov	[58DAh],dx
	push	1Ch
	mov	di,58C0h
	push	ds
	push	di
	call	far 1E5Fh:0159h
	push	1Ch
	mov	di,7Bh
	mov	ax,800h
	push	ax
	push	di
	call	far 1E5Fh:0171h
	mov	byte ptr [58BEh],1h

l0800_00FF:
	leave
	ret	4h
