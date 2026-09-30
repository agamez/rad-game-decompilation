;; fn1E78_0000: 1E78:0000
;;   Called from:
;;     0800:425A (in fn0800_4255)
fn1E78_0000 proc
	push	bp
	mov	bp,sp
	call	002Eh
	mov	di,0B8BCh
	push	ds
	push	di
	push	cs
	call	032Fh
	mov	di,0B8BCh
	push	ds
	push	di
	call	far 1EDAh:0565h
	mov	di,0B9BCh
	push	ds
	push	di
	push	cs
	call	032Fh
	mov	di,0B9BCh
	push	ds
	push	di
	call	far 1EDAh:056Ah
	pop	bp
	retf
