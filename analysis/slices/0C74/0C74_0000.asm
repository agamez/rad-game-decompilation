;; fn0C74_0000: 0C74:0000
;;   Called from:
;;     0800:0161 (in fn0800_0147)
;;     0800:0404 (in fn0800_03F8)
;;     0800:1240 (in fn0800_11EF)
;;     0800:240A (in fn0800_2401)
;;     0800:2830 (in fn0800_2827)
;;     0800:4171 (in fn0800_4168)
;;     0C74:03DD (in fn0C74_03D4)
fn0C74_0000 proc
	enter	12Eh,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	push	3Fh
	lea	di,[bp+0FED2h]
	push	ss
	push	di
	call	far 1E5Fh:00DEh
	cmp	word ptr [0B8A6h],0h
	jz	0038h

l0C74_0031:
	mov	byte ptr [bp+0FEFDh],0h
	jmp	003Dh

l0C74_0038:
	mov	byte ptr [bp+0FEFDh],1h

l0C74_003D:
	mov	al,[bp+0FEFDh]
	mov	[bp-1h],al
	mov	al,[bp-1h]
	leave
	retf	4h
