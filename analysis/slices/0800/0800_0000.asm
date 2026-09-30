;; fn0800_0000: 0800:0000
;;   Called from:
;;     0800:1249 (in fn0800_11EF)
;;     0800:415B (in fn0800_3D9D)
;;     0800:417A (in fn0800_4168)
fn0800_0000 proc
	push	bp
	mov	bp,sp
	call	far 1AB8h:0EB5h
	call	far 1AB8h:0E88h
	push	word ptr [0B8ACh]
	call	far 1E78h:016Bh
	call	far 11C8h:03BBh
	xor	ax,ax
	call	far 1EDAh:00E9h
	leave
	ret
