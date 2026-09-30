;; fn1AB8_0000: 1AB8:0000
;;   Called from:
;;     1AB8:04CD (in fn1AB8_027E)
fn1AB8_0000 proc
	push	bp
	mov	bp,sp
	sub	sp,8h
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	xor	ax,ax
	push	ax
	lea	di,[bp-8h]
	push	ss
	push	di
	mov	ax,6h
	push	ax
	call	far 1EDAh:0F26h
	lea	di,[bp-8h]
	push	ss
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	mov	sp,bp
	pop	bp
	ret	4h
1AB8:0036                   33 42 47 49 20 45 72 72 6F 72       3BGI Error
1AB8:0040 3A 20 47 72 61 70 68 69 63 73 20 6E 6F 74 20 69 : Graphics not i
1AB8:0050 6E 69 74 69 61 6C 69 7A 65 64 20 28 75 73 65 20 nitialized (use 
1AB8:0060 49 6E 69 74 47 72 61 70 68 29 20 42 47 49 20 45 InitGraph) BGI E
1AB8:0070 72 72 6F 72 3A 20 20 4E 6F 74 20 69 6E 20 67 72 rror:  Not in gr
1AB8:0080 61 70 68 69 63 73 20 6D 6F 64 65                aphics mode
