;; fn1229_050A: 1229:050A
;;   Called from:
;;     1229:0897 (in fn1229_0735)
;;     1229:08A6 (in fn1229_0735)
;;     1229:08B5 (in fn1229_0735)
;;     1229:08C4 (in fn1229_0735)
;;     1229:08D3 (in fn1229_0735)
;;     1229:08EE (in fn1229_0735)
fn1229_050A proc
	enter	40Ah,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	lea	di,[bp+0FBF6h]
	push	ss
	push	di
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,68h
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
	add	ax,68h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,10h
	push	ax
	lea	di,[bp+0FDF6h]
	push	ss
	push	di
	mov	di,503h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	mov	di,505h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FCF6h]
	push	ss
	push	di
	mov	al,[bp+4h]
	xor	ah,ah
	xor	dx,dx
	push	dx
	push	ax
	call	far 13C1h:0036h
	call	far 1EDAh:0AACh
	mov	di,507h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	cs
	call	0040h
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	lea	di,[bp+0FEF8h]
	push	ss
	push	di
	call	far 1EDAh:0F71h
	mov	[bp+0FEF6h],ax
	cmp	word ptr [bp+0FEF8h],0h
	jz	05E1h

l1229_05D8:
	mov	al,[bp+4h]
	xor	ah,ah
	mov	[bp+0FEF6h],ax

l1229_05E1:
	mov	al,[bp+0FEF6h]
	mov	[bp-1h],al

l1229_05E8:
	call	far 1E78h:02FBh
	or	al,al
	jnz	05E8h

l1229_05F1:
	mov	al,[bp-1h]
	leave
	ret	6h
1229:05F8                         01 20 1E 20 41 20 45 54         . . A ET
1229:0600 45 20 4D 4F 44 49 46 49 45 2E 20 53 41 55 56 45 E MODIFIE. SAUVE
1229:0610 52 28 4F 2F 4E 29 20 3F 3A 01 4F                R(O/N) ?:.O
