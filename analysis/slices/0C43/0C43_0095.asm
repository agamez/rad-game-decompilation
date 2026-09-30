;; fn0C43_0095: 0C43:0095
;;   Called from:
;;     0C43:0148 (in fn0C43_00B9)
;;     0C43:0264 (in fn0C43_00B9)
;;     0C43:02F4 (in fn0C43_00B9)
fn0C43_0095 proc
	push	bp
	mov	bp,sp
	mov	di,[bp+4h]
	add	di,0FF2Ch
	push	ss
	push	di
	call	far 1EDAh:1051h
	push	word ptr [5886h]
	push	word ptr [5884h]
	push	0F1h
	call	far 1EDAh:0254h
	leave
	ret	2h
