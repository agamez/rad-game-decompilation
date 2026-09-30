;; fn1229_0486: 1229:0486
;;   Called from:
;;     1229:0FBB (in fn1229_0DCC)
;;     1229:101F (in fn1229_0DCC)
fn1229_0486 proc
	enter	82h,0h
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,47Eh
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp-80h]
	push	ss
	push	di
	push	219h
	call	far 1EDAh:0FD0h
	lea	di,[bp-80h]
	push	ss
	push	di
	push	word ptr [5990h]
	push	word ptr [598Eh]
	call	far 1EDAh:1123h
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:1085h
	add	sp,4h
	call	far 1EDAh:04A2h
	or	ax,ax
	jz	04F2h

l1229_04D3:
	sub	word ptr [598Eh],1h
	sbb	word ptr [5990h],0h
	push	96h
	call	far 1E78h:02C7h
	push	1F4h
	call	far 1E78h:029Ch
	call	far 1E78h:02F4h

l1229_04F2:
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	call	far 1EDAh:04A9h
	leave
	ret
1229:0503          01 20 01 28 02 29 3A                      . .(.):
