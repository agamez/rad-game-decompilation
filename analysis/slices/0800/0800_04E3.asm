;; fn0800_04E3: 0800:04E3
;;   Called from:
;;     0800:0A83 (in fn0800_09C2)
;;     0800:2602 (in fn0800_2401)
;;     0800:2923 (in fn0800_2827)
;;     0800:2DC1 (in fn0800_2C0C)
;;     0800:3407 (in fn0800_31B7)
fn0800_04E3 proc
	enter	100h,0h
	push	120h
	push	189h
	push	1A0h
	push	193h
	call	005Ah
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	8h
	call	far 1AB8h:1C32h
	cmp	byte ptr [53DBh],0h
	jbe	0537h

l0800_0518:
	push	12Fh
	push	18Dh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	al,[53DBh]
	xor	ah,ah
	xor	dx,dx
	push	dx
	push	ax
	call	far 0C74h:004Bh
	call	far 1AB8h:1D82h

l0800_0537:
	cmp	byte ptr [53DCh],0h
	jbe	055Dh

l0800_053E:
	push	163h
	push	18Dh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	al,[53DCh]
	xor	ah,ah
	xor	dx,dx
	push	dx
	push	ax
	call	far 0C74h:004Bh
	call	far 1AB8h:1D82h

l0800_055D:
	cmp	byte ptr [53DEh],0h
	jbe	0583h

l0800_0564:
	push	197h
	push	18Dh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	al,[53DEh]
	xor	ah,ah
	xor	dx,dx
	push	dx
	push	ax
	call	far 0C74h:004Bh
	call	far 1AB8h:1D82h

l0800_0583:
	push	0Eh
	call	far 1AB8h:1C32h
	cmp	byte ptr [53DBh],0h
	jbe	05B0h

l0800_0591:
	push	130h
	push	18Eh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	al,[53DBh]
	xor	ah,ah
	xor	dx,dx
	push	dx
	push	ax
	call	far 0C74h:004Bh
	call	far 1AB8h:1D82h

l0800_05B0:
	cmp	byte ptr [53DCh],0h
	jbe	05D6h

l0800_05B7:
	push	164h
	push	18Eh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	al,[53DCh]
	xor	ah,ah
	xor	dx,dx
	push	dx
	push	ax
	call	far 0C74h:004Bh
	call	far 1AB8h:1D82h

l0800_05D6:
	cmp	byte ptr [53DEh],0h
	jbe	05FCh

l0800_05DD:
	push	198h
	push	18Eh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	al,[53DEh]
	xor	ah,ah
	xor	dx,dx
	push	dx
	push	ax
	call	far 0C74h:004Bh
	call	far 1AB8h:1D82h

l0800_05FC:
	push	0h
	call	far 1AB8h:1C32h
	leave
	ret
0800:0605                04 44 45 4D 4F 03 30 30 30 01 30      .DEMO.000.0
0800:0610 08 4D 49 53 53 49 4F 4E 20                      .MISSION
