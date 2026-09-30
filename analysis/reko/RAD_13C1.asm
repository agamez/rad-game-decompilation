;;; Segment 13C1 (13C1:0000)

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

;; fn13C1_0036: 13C1:0036
;;   Called from:
;;     1229:0597 (in fn1229_050A)
fn13C1_0036 proc
	enter	100h,0h
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	0h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0F26h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	retf	4h

;; fn13C1_0067: 13C1:0067
;;   Called from:
;;     0800:426E (in fn0800_4255)
fn13C1_0067 proc
	push	bp
	mov	bp,sp
	push	cs
	call	0000h
	leave
	retf
