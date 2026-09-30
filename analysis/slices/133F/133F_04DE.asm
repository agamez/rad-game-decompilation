;; fn133F_04DE: 133F:04DE
;;   Called from:
;;     1229:0D79 (in fn1229_0CCE)
fn133F_04DE proc
	enter	106h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	push	0h
	push	0h
	call	far 1AB8h:10CEh
	push	ax
	call	far 1AB8h:10E1h
	push	ax
	push	cs
	call	04B1h
	mov	ax,[bp+10h]
	mov	[0B6B6h],ax
	mov	ax,[bp+0Eh]
	mov	[0B6B8h],ax
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	call	far 13C8h:009Ah
	push	cs
	call	0141h
	leave
	retf	0Ch
