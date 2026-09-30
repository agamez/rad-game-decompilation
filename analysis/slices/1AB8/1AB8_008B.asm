;; fn1AB8_008B: 1AB8:008B
;;   Called from:
;;     1AB8:0AFB (in fn1AB8_0AEE)
fn1AB8_008B proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [0B84Eh],0h
	jnz	00B3h

l1AB8_0095:
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,36h
	push	cs
	push	di
	xor	ax,ax
	push	ax
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	call	far 1EDAh:04A9h
	jmp	00CFh

l1AB8_00B3:
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,6Ah
	push	cs
	push	di
	xor	ax,ax
	push	ax
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	call	far 1EDAh:04A9h

l1AB8_00CF:
	mov	ax,1h
	call	far 1EDAh:00E9h
	pop	bp
	retf
1AB8:00D9                            08 4E 6F 20 65 72 72          .No err
1AB8:00E0 6F 72 1C 28 42 47 49 29 20 67 72 61 70 68 69 63 or.(BGI) graphic
1AB8:00F0 73 20 6E 6F 74 20 69 6E 73 74 61 6C 6C 65 64 1E s not installed.
1AB8:0100 47 72 61 70 68 69 63 73 20 68 61 72 64 77 61 72 Graphics hardwar
1AB8:0110 65 20 6E 6F 74 20 64 65 74 65 63 74 65 64 1E 44 e not detected.D
1AB8:0120 65 76 69 63 65 20 64 72 69 76 65 72 20 66 69 6C evice driver fil
1AB8:0130 65 20 6E 6F 74 20 66 6F 75 6E 64 20 28 01 29 1C e not found (.).
1AB8:0140 49 6E 76 61 6C 69 64 20 64 65 76 69 63 65 20 64 Invalid device d
1AB8:0150 72 69 76 65 72 20 66 69 6C 65 20 28 20 4E 6F 74 river file ( Not
1AB8:0160 20 65 6E 6F 75 67 68 20 6D 65 6D 6F 72 79 20 74  enough memory t
1AB8:0170 6F 20 6C 6F 61 64 20 64 72 69 76 65 72 1A 4F 75 o load driver.Ou
1AB8:0180 74 20 6F 66 20 6D 65 6D 6F 72 79 20 69 6E 20 73 t of memory in s
1AB8:0190 63 61 6E 20 66 69 6C 6C 1B 4F 75 74 20 6F 66 20 can fill.Out of 
1AB8:01A0 6D 65 6D 6F 72 79 20 69 6E 20 66 6C 6F 6F 64 20 memory in flood 
1AB8:01B0 66 69 6C 6C 15 46 6F 6E 74 20 66 69 6C 65 20 6E fill.Font file n
1AB8:01C0 6F 74 20 66 6F 75 6E 64 20 28 1E 4E 6F 74 20 65 ot found (.Not e
1AB8:01D0 6E 6F 75 67 68 20 6D 65 6D 6F 72 79 20 74 6F 20 nough memory to 
1AB8:01E0 6C 6F 61 64 20 66 6F 6E 74 29 49 6E 76 61 6C 69 load font)Invali
1AB8:01F0 64 20 67 72 61 70 68 69 63 73 20 6D 6F 64 65 20 d graphics mode 
1AB8:0200 66 6F 72 20 73 65 6C 65 63 74 65 64 20 64 72 69 for selected dri
1AB8:0210 76 65 72 0E 47 72 61 70 68 69 63 73 20 65 72 72 ver.Graphics err
1AB8:0220 6F 72 12 47 72 61 70 68 69 63 73 20 49 2F 4F 20 or.Graphics I/O 
1AB8:0230 65 72 72 6F 72 13 49 6E 76 61 6C 69 64 20 66 6F error.Invalid fo
1AB8:0240 6E 74 20 66 69 6C 65 20 28 13 49 6E 76 61 6C 69 nt file (.Invali
1AB8:0250 64 20 66 6F 6E 74 20 6E 75 6D 62 65 72 0F 49 6E d font number.In
1AB8:0260 76 61 6C 69 64 20 76 65 72 73 69 6F 6E 10 47 72 valid version.Gr
1AB8:0270 61 70 68 69 63 73 20 65 72 72 6F 72 20 28       aphics error (
