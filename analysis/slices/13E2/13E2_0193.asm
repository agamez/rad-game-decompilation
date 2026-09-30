;; fn13E2_0193: 13E2:0193
;;   Called from:
;;     0800:016F (in fn0800_0147)
;;     0800:0412 (in fn0800_03F8)
;;     0800:4362 (in fn0800_4255)
;;     13E2:0239 (in fn13E2_0220)
;;     13E2:0253 (in fn13E2_0220)
;;     13E2:026D (in fn13E2_0220)
fn13E2_0193 proc
	enter	200h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	call	far 1AB8h:0EB5h
	call	far 1AB8h:0E88h
	push	word ptr [0B8ACh]
	call	far 1E78h:016Bh
	mov	di,0B9BCh
	push	ds
	push	di
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,191h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,191h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,191h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	xor	ax,ax
	call	far 1EDAh:00E9h
	leave
	retf	4h
13E2:0208                         17 44 72 69 76 65 72 20         .Driver 
13E2:0210 67 72 61 70 68 69 71 75 65 20 61 62 73 65 6E 74 graphique absent
