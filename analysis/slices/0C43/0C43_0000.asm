;; fn0C43_0000: 0C43:0000
;;   Called from:
;;     0C43:00D0 (in fn0C43_00B9)
fn0C43_0000 proc
	push	bp
	mov	bp,sp
	mov	byte ptr [589Dh],0h
	mov	al,[bp+4h]
	mov	[589Ch],al
	push	10h
	mov	di,589Ch
	push	ds
	push	di
	call	far 1E5Fh:000Bh
	leave
	ret	2h
