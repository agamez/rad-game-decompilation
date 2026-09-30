;; fn1AB8_1A84: 1AB8:1A84
;;   Called from:
;;     1AB8:17BC (in fn1AB8_17AE)
fn1AB8_1A84 proc
	xor	ax,ax
	mov	byte ptr [0B89Ah],0FFh
	mov	[0B89Bh],al
	mov	[0B89Ch],al
	mov	[0B89Dh],al
	mov	[0B89Eh],al
	mov	[0B89Fh],ax
	mov	[0B8A1h],ax
	mov	byte ptr [0B8A3h],0FFh
	mov	[0B8A4h],al
	retf
