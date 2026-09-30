;; fn1229_061B: 1229:061B
;;   Called from:
;;     1229:0FA7 (in fn1229_0DCC)
;;     1229:100B (in fn1229_0DCC)
;;     1229:1064 (in fn1229_0DCC)
;;     1229:10A2 (in fn1229_0DCC)
fn1229_061B proc
	enter	208h,0h
	mov	byte ptr [bp-1h],0h
	lea	di,[bp+0FDF8h]
	push	ss
	push	di
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,0B0h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,10h
	push	ax
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,0B0h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,10h
	push	ax
	lea	di,[bp+0FEF8h]
	push	ss
	push	di
	mov	di,5F8h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,5FAh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	cs
	call	0040h
	lea	di,[bp-4h]
	push	ss
	push	di
	push	1h
	call	far 1EDAh:0A39h
	lea	di,[bp-4h]
	push	ss
	push	di
	mov	di,619h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	06AEh

l1229_06AA:
	mov	byte ptr [bp-1h],1h

l1229_06AE:
	push	0Fh
	call	far 1AB8h:1C32h

l1229_06B5:
	call	far 1E78h:02FBh
	or	al,al
	jnz	06B5h

l1229_06BE:
	mov	al,[bp-1h]
	leave
	ret
1229:06C3          05 4E 6F 6D 20 28 03 29 20 3A 05 41 69    .Nom (.) :.Ai
1229:06D0 64 65 28 01 29 02 20 3A 0C 4E 6F 6D 62 72 65 20 de(.). :.Nombre 
1229:06E0 50 75 73 68 73 0C 4E 6F 6D 62 72 65 20 70 6F 6E Pushs.Nombre pon
1229:06F0 74 73 0C 4E 6F 6D 62 72 65 20 42 6C 61 73 74 0C ts.Nombre Blast.
1229:0700 43 6F 6F 72 64 58 20 52 6F 62 6F 74 0C 43 6F 6F CoordX Robot.Coo
1229:0710 72 64 59 20 52 6F 62 6F 74 0C 44 82 6C 61 69 20 rdY Robot.D.lai 
1229:0720 64 65 20 6A 65 75 07 52 41 44 2E 44 41 54 06 4E de jeu.RAD.DAT.N
1229:0730 4F 4E 41 4D 45                                  ONAME
