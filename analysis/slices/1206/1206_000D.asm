;; fn1206_000D: 1206:000D
;;   Called from:
;;     1206:01C6 (in fn1206_01AC)
fn1206_000D proc
	enter	14h,0h
	xor	ax,ax
	mov	[bp-14h],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	mov	ax,[bp-14h]
	les	di,[bp+0Ah]
	mov	es:[di],ax
	mov	ax,[bp-12h]
	les	di,[bp+6h]
	mov	es:[di],ax
	leave
	retf	8h
