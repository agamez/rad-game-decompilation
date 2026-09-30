;; fn1229_0CCE: 1229:0CCE
;;   Called from:
;;     1229:0E21 (in fn1229_0DCC)
fn1229_0CCE proc
	enter	104h,0h
	call	far 133Fh:0137h
	call	far 133Fh:04A7h
	call	far 1AB8h:0F80h
	push	0Fh
	call	far 1AB8h:1C32h
	push	0h
	push	0h
	push	27Fh
	push	177h
	call	far 1AB8h:112Eh
	call	0AA8h
	call	0C58h
	push	53h
	push	5h
	push	180h
	push	57h
	push	191h
	mov	di,0CB4h
	push	cs
	push	di
	call	far 133Fh:0352h
	push	2Dh
	push	5h
	push	198h
	push	2Bh
	push	1A9h
	mov	di,0CB9h
	push	cs
	push	di
	call	far 133Fh:0352h
	push	2Bh
	push	30h
	push	198h
	push	57h
	push	1A9h
	mov	di,0CBDh
	push	cs
	push	di
	call	far 133Fh:0352h
	push	54h
	push	5h
	push	1B0h
	push	57h
	push	1C1h
	mov	di,0CC1h
	push	cs
	push	di
	call	far 133Fh:0352h
	push	51h
	push	5h
	push	1C8h
	push	57h
	push	1D9h
	mov	di,0CC6h
	push	cs
	push	di
	call	far 133Fh:0352h
	push	64h
	push	192h
	push	0h
	push	0h
	mov	di,0CCBh
	push	cs
	push	di
	call	far 133Fh:04DEh
	push	0h
	push	0h
	call	far 1AB8h:10CEh
	push	ax
	call	far 1AB8h:10E1h
	push	ax
	call	far 133Fh:0200h
	push	1h
	push	1h
	call	far 1AB8h:10CEh
	push	ax
	call	far 1AB8h:10E1h
	push	ax
	call	far 133Fh:04B1h
	push	16h
	push	16h
	call	far 133Fh:0256h
	mov	di,0CCCh
	push	cs
	push	di
	mov	di,62DEh
	push	ds
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	ret
1229:0DC5                06 4E 4F 4E 41 4D 45                  .NONAME
