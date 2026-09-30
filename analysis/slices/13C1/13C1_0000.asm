;; fn13C1_0000: 13C1:0000
;;   Called from:
;;     13C1:006A (in fn13C1_0067)
fn13C1_0000 proc
	enter	14h,0h
	mov	byte ptr [bp-13h],0Fh
	push	10h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	mov	byte ptr [bp-13h],3h
	push	10h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	mov	al,[bp-0Fh]
	xor	ah,ah
	mov	[0B6A8h],ax
	mov	al,[bp-10h]
	xor	ah,ah
	mov	[0B6AAh],ax
	leave
	retf
