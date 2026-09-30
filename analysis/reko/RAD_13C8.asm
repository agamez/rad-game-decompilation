;;; Segment 13C8 (13C8:0000)

;; fn13C8_0000: 13C8:0000
;;   Called from:
;;     133F:00E0 (in fn133F_0056)
;;     13C8:0141 (in fn13C8_0139)
fn13C8_0000 proc
	enter	6h,0h
	mov	byte ptr [bp-1h],1h
	mov	al,[bp-1h]
	leave
	retf

;; fn13C8_000D: 13C8:000D
;;   Called from:
;;     133F:00F3 (in fn133F_0056)
;;     13C8:0153 (in fn13C8_0139)
fn13C8_000D proc
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

;; fn13C8_0038: 13C8:0038
;;   Called from:
;;     133F:0144 (in fn133F_0141)
fn13C8_0038 proc
	enter	14h,0h
	mov	word ptr [bp-14h],1h
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	leave
	retf

;; fn13C8_004F: 13C8:004F
;;   Called from:
;;     133F:013A (in fn133F_0137)
fn13C8_004F proc
	enter	14h,0h
	mov	word ptr [bp-14h],2h
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	leave
	retf

;; fn13C8_0066: 13C8:0066
;;   Called from:
;;     133F:072E (in fn133F_0528)
;;     13C8:0179 (in fn13C8_0139)
fn13C8_0066 proc
	enter	14h,0h
	mov	word ptr [bp-14h],3h
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	mov	ax,[bp-10h]
	les	di,[bp+0Ah]
	mov	es:[di],ax
	mov	ax,[bp-0Eh]
	les	di,[bp+6h]
	mov	es:[di],ax
	mov	ax,[bp-12h]
	les	di,[bp+0Eh]
	mov	es:[di],ax
	leave
	retf	0Ch

;; fn13C8_009A: 13C8:009A
;;   Called from:
;;     133F:051B (in fn133F_04DE)
;;     133F:05D3 (in fn133F_0528)
;;     133F:05FA (in fn133F_0528)
;;     133F:0621 (in fn133F_0528)
;;     133F:0648 (in fn133F_0528)
fn13C8_009A proc
	enter	14h,0h
	mov	word ptr [bp-14h],4h
	mov	ax,[bp+8h]
	mov	[bp-10h],ax
	mov	ax,[bp+6h]
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	leave
	retf	4h

;; fn13C8_00BF: 13C8:00BF
;;   Called from:
;;     133F:0104 (in fn133F_0056)
;;     133F:04CA (in fn133F_04B1)
;;     13C8:0182 (in fn13C8_0139)
fn13C8_00BF proc
	enter	14h,0h
	mov	word ptr [bp-14h],7h
	mov	ax,[bp+8h]
	mov	[bp-10h],ax
	mov	ax,[bp+6h]
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	leave
	retf	4h

;; fn13C8_00E4: 13C8:00E4
;;   Called from:
;;     133F:010E (in fn133F_0056)
;;     133F:04D5 (in fn133F_04B1)
;;     13C8:018B (in fn13C8_0139)
fn13C8_00E4 proc
	enter	14h,0h
	mov	word ptr [bp-14h],8h
	mov	ax,[bp+8h]
	mov	[bp-10h],ax
	mov	ax,[bp+6h]
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	leave
	retf	4h
13C8:0109                            00 00 00 00 FF FF 00          .......
13C8:0110 00                                              .               

;; fn13C8_0111: 13C8:0111
;;   Called from:
;;     1229:0E19 (in fn1229_0DCC)
fn13C8_0111 proc
	enter	14h,0h
	mov	word ptr [bp-14h],13h
	mov	ax,[bp+6h]
	cwd
	mov	di,109h
	call	far 1EDAh:04B7h
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	leave
	retf	2h

;; fn13C8_0139: 13C8:0139
;;   Called from:
;;     0800:4269 (in fn0800_4255)
fn13C8_0139 proc
	push	bp
	mov	bp,sp
	mov	byte ptr [0B6B2h],0h
	push	cs
	call	0000h
	or	al,al
	jz	018Fh

l13C8_0149:
	mov	di,0B6AEh
	push	ds
	push	di
	mov	di,0B6B0h
	push	ds
	push	di
	push	cs
	call	000Dh
	cmp	word ptr [0B6AEh],0h
	jz	0163h

l13C8_015E:
	mov	byte ptr [0B6B2h],1h

l13C8_0163:
	cmp	byte ptr [0B6B2h],0h
	jz	018Fh

l13C8_016A:
	mov	di,0B6B4h
	push	ds
	push	di
	mov	di,0B6B6h
	push	ds
	push	di
	mov	di,0B6B8h
	push	ds
	push	di
	push	cs
	call	0066h
	push	0h
	push	280h
	push	cs
	call	00BFh
	push	0h
	push	1E0h
	push	cs
	call	00E4h

l13C8_018F:
	leave
	retf
13C8:0191    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ...............
