;; fn0800_4168: 0800:4168
;;   Called from:
;;     0800:43FE (in fn0800_4255)
fn0800_4168 proc
	enter	80h,0h
	mov	di,4160h
	push	cs
	push	di
	call	far 0C74h:0000h
	or	al,al
	jnz	417Dh

l0800_417A:
	call	0000h

l0800_417D:
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,4160h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp-80h]
	push	ss
	push	di
	push	219h
	call	far 1EDAh:0FD0h
	call	far 1EDAh:04A9h
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:116Ah
	call	far 1EDAh:04A9h
	sub	ax,2h
	sbb	dx,0h
	mov	[5CB2h],al
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	call	far 1EDAh:04A9h
	leave
	ret
0800:41C7                      01 53 01 73 FE FF FF FF FF        .S.s.....
0800:41D0 FF FF FF FF FF FF FF 0F 00 00 00 00 00 00 00 00 ................
0800:41E0 00 00 00 00 00 00 00 00 00 00 00 07 52 41 44 2E ............RAD.
0800:41F0 54 49 54 2A 44 82 73 6F 6C 82 2C 20 6A 65 20 6E TIT*D.sol., je n
0800:4200 65 20 66 6F 6E 63 74 69 6F 6E 6E 65 20 71 75 65 e fonctionne que
0800:4210 20 73 75 72 20 63 61 72 74 65 20 56 47 41 00 00  sur carte VGA..
0800:4220 00 00 00 00 00 00 06 00 00 00 06 00 00 00 00 00 ................
0800:4230 00 00 00 00 00 00 00 00 00 00 00 00 00 00 16 43 ...............C
0800:4240 68 61 72 67 65 6D 65 6E 74 20 65 6E 20 63 6F 75 hargement en cou
0800:4250 72 73 2E 2E 2E                                  rs...
