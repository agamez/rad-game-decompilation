;; fn1E5F_00A2: 1E5F:00A2
;;   Called from:
;;     0800:3C15 (in fn0800_3BF2)
;;     0800:3C8A (in fn0800_3C72)
fn1E5F_00A2 proc
	push	bp
	mov	bp,sp
	mov	ah,2Ch
	int	21h
	xor	ah,ah
	mov	al,dl
	les	di,[bp+6h]
	stosw
	mov	al,dh
	les	di,[bp+0Ah]
	stosw
	mov	al,cl
	les	di,[bp+0Eh]
	stosw
	mov	al,ch
	les	di,[bp+12h]
	stosw
	pop	bp
	retf	10h
1E5F:00C7                      55 8B EC 8A 6E 0C 8A 4E 0A        U...n..N.
1E5F:00D0 8A 76 08 8A 56 06 B4 2D CD 21 5D CA 08 00       .v..V..-.!]...
