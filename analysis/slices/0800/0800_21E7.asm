;; fn0800_21E7: 0800:21E7
;;   Called from:
;;     0800:3DBF (in fn0800_3D9D)
;;     0800:40FB (in fn0800_3D9D)
;;     0800:412C (in fn0800_3D9D)
fn0800_21E7 proc
	enter	200h,0h
	push	1h
	push	0h
	push	18h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	9Ch
	push	14h
	push	1E0h
	push	16Ah
	call	1315h
	push	0Ah
	call	far 1AB8h:1C32h
	push	140h
	push	47h
	mov	di,2155h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	cmp	byte ptr [0002h],1Eh
	jbe	2273h

l0800_222A:
	push	2h
	push	0h
	push	4h
	call	far 1AB8h:1536h
	push	140h
	push	96h
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	mov	di,2159h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	al,[5CB2h]
	xor	ah,ah
	xor	dx,dx
	push	dx
	push	ax
	call	far 0C74h:004Bh
	call	far 1EDAh:0AACh
	mov	di,2170h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	call	far 1AB8h:1D82h

l0800_2273:
	cmp	word ptr [5990h],0h
	jnz	2281h

l0800_227A:
	cmp	word ptr [598Eh],1h
	jz	22B4h

l0800_2281:
	push	1h
	push	0F0h
	push	0B4h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,217Ah
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,5ED6h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,217Eh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	0h
	call	19E1h
	jmp	22C6h

l0800_22B4:
	push	1h
	push	0F0h
	push	0B4h
	mov	di,2180h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_22C6:
	push	2h
	push	190h
	push	0B4h
	mov	di,218Ch
	push	cs
	push	di
	push	0h
	call	19E1h
	push	3h
	push	0F0h
	push	0E6h
	mov	di,2197h
	push	cs
	push	di
	push	0h
	call	19E1h
	cmp	byte ptr [58B0h],0h
	jz	2305h

l0800_22F1:
	push	4h
	push	190h
	push	0E6h
	mov	di,21A2h
	push	cs
	push	di
	push	0h
	call	19E1h
	jmp	2317h

l0800_2305:
	push	4h
	push	190h
	push	0E6h
	mov	di,21A2h
	push	cs
	push	di
	push	1h
	call	19E1h

l0800_2317:
	cmp	byte ptr [0002h],1Eh
	jbe	2332h

l0800_231E:
	push	5h
	push	0F0h
	push	118h
	mov	di,21ADh
	push	cs
	push	di
	push	0h
	call	19E1h
	jmp	2344h

l0800_2332:
	push	5h
	push	0F0h
	push	118h
	mov	di,21B9h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_2344:
	push	6h
	push	190h
	push	118h
	mov	di,21C5h
	push	cs
	push	di
	push	0h
	call	19E1h
	push	7h
	push	140h
	push	14Ah
	mov	di,21D0h
	push	cs
	push	di
	push	0h
	call	19E1h
	leave
	ret
0800:236A                               07 52 61 64 2E 68           .Rad.h
0800:2370 6C 70 07 52 41 44 2E 48 4C 50 13 45 4E 54 52 45 lp.RAD.HLP.ENTRE
0800:2380 45 20 45 4E 20 4D 4F 44 45 20 41 55 54 4F 1D 50 E EN MODE AUTO.P
0800:2390 72 65 73 73 65 7A 20 75 6E 65 20 74 6F 75 63 68 ressez une touch
0800:23A0 65 20 71 75 65 6C 63 6F 6E 71 75 65 16 70 6F 75 e quelconque.pou
0800:23B0 72 20 6C 27 61 63 74 69 6F 6E 20 73 75 69 76 61 r l'action suiva
0800:23C0 6E 74 65 1D 6F 75 20 45 53 43 20 70 6F 75 72 20 nte.ou ESC pour 
0800:23D0 72 65 70 72 65 6E 64 72 65 20 6C 61 20 6D 61 69 reprendre la mai
0800:23E0 6E 06 4E 4F 4E 41 4D 45 18 4D 4F 44 45 20 41 55 n.NONAME.MODE AU
0800:23F0 54 4F 20 28 45 53 43 20 3D 20 52 45 54 4F 55 52 TO (ESC = RETOUR
0800:2400 29                                              )
