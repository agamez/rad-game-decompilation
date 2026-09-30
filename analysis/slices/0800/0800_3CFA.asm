;; fn0800_3CFA: 0800:3CFA
;;   Called from:
;;     0800:3DB7 (in fn0800_3D9D)
fn0800_3CFA proc
	enter	2h,0h
	mov	byte ptr [53DFh],1h
	xor	ax,ax
	mov	[bp-2h],ax
	push	0h
	call	far 1AB8h:1C32h
	mov	di,555Eh
	push	ds
	push	di
	push	cs
	call	3BF2h

l0800_3D18:
	push	64h
	push	64h
	push	5Ah
	call	far 1AB8h:122Eh
	inc	word ptr [bp-2h]
	mov	di,555Eh
	push	ds
	push	di
	push	cs
	call	3C72h
	cmp	dx,0h
	jg	3D3Bh

l0800_3D34:
	jl	3D18h

l0800_3D36:
	cmp	ax,64h
	jbe	3D18h

l0800_3D3B:
	mov	ax,[bp-2h]
	shl	ax,3h
	xor	dx,dx
	mov	cx,64h
	div	cx
	mov	[58E6h],ax
	cmp	word ptr [58E6h],7h
	jge	3D58h

l0800_3D52:
	mov	word ptr [58E6h],7h

l0800_3D58:
	leave
	ret
0800:3D5A                               24 55 4E 20 4C 4F           $UN LO
0800:3D60 47 49 43 49 45 4C 20 4E 45 58 54 44 4F 4F 52 20 GICIEL NEXTDOOR 
0800:3D70 44 45 20 4D 41 58 20 47 41 49 4C 4C 41 52 44 03 DE MAX GAILLARD.
0800:3D80 46 31 3A 01 20 0B 20 20 46 31 3A 4A 45 55 20 20 F1:. .  F1:JEU  
0800:3D90 20 04 44 45 4D 4F 06 4E 4F 4E 41 4D 45           .DEMO.NONAME
