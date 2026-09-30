;;; Segment 1AB8 (1AB8:0000)

;; fn1AB8_0000: 1AB8:0000
;;   Called from:
;;     1AB8:04CD (in fn1AB8_027E)
fn1AB8_0000 proc
	push	bp
	mov	bp,sp
	sub	sp,8h
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	xor	ax,ax
	push	ax
	lea	di,[bp-8h]
	push	ss
	push	di
	mov	ax,6h
	push	ax
	call	far 1EDAh:0F26h
	lea	di,[bp-8h]
	push	ss
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	mov	sp,bp
	pop	bp
	ret	4h
1AB8:0036                   33 42 47 49 20 45 72 72 6F 72       3BGI Error
1AB8:0040 3A 20 47 72 61 70 68 69 63 73 20 6E 6F 74 20 69 : Graphics not i
1AB8:0050 6E 69 74 69 61 6C 69 7A 65 64 20 28 75 73 65 20 nitialized (use 
1AB8:0060 49 6E 69 74 47 72 61 70 68 29 20 42 47 49 20 45 InitGraph) BGI E
1AB8:0070 72 72 6F 72 3A 20 20 4E 6F 74 20 69 6E 20 67 72 rror:  Not in gr
1AB8:0080 61 70 68 69 63 73 20 6D 6F 64 65                aphics mode     

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

;; fn1AB8_027E: 1AB8:027E
;;   Called from:
;;     133F:009B (in fn133F_0056)
fn1AB8_027E proc
	push	bp
	mov	bp,sp
	sub	sp,200h
	mov	ax,[bp+6h]
	cmp	ax,0h
	jnz	02A3h

l1AB8_028D:
	mov	di,0D9h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_02A3:
	cmp	ax,0FFFFh
	jnz	02BEh

l1AB8_02A8:
	mov	di,0E2h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_02BE:
	cmp	ax,0FFFEh
	jnz	02D9h

l1AB8_02C3:
	mov	di,0FFh
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_02D9:
	cmp	ax,0FFFDh
	jnz	0313h

l1AB8_02DE:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,11Eh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,0B756h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,13Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0313:
	cmp	ax,0FFFCh
	jnz	034Dh

l1AB8_0318:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,13Fh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,0B756h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,13Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_034D:
	cmp	ax,0FFFBh
	jnz	0368h

l1AB8_0352:
	mov	di,15Ch
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0368:
	cmp	ax,0FFFAh
	jnz	0383h

l1AB8_036D:
	mov	di,17Dh
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0383:
	cmp	ax,0FFF9h
	jnz	039Eh

l1AB8_0388:
	mov	di,198h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_039E:
	cmp	ax,0FFF8h
	jnz	03D8h

l1AB8_03A3:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,1B4h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,0B74Ch
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,13Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_03D8:
	cmp	ax,0FFF7h
	jnz	03F3h

l1AB8_03DD:
	mov	di,1CAh
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_03F3:
	cmp	ax,0FFF6h
	jnz	040Eh

l1AB8_03F8:
	mov	di,1E9h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_040E:
	cmp	ax,0FFF5h
	jnz	0429h

l1AB8_0413:
	mov	di,213h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0429:
	cmp	ax,0FFF4h
	jnz	0444h

l1AB8_042E:
	mov	di,222h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0444:
	cmp	ax,0FFF3h
	jnz	047Dh

l1AB8_0449:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,235h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,0B74Ch
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,13Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_047D:
	cmp	ax,0FFF2h
	jnz	0497h

l1AB8_0482:
	mov	di,249h
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_0497:
	cmp	ax,0FFEEh
	jnz	04B1h

l1AB8_049C:
	mov	di,25Dh
	push	cs
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	jmp	04EDh

l1AB8_04B1:
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	mov	di,26Dh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	ax,[bp+6h]
	cwd
	push	dx
	push	ax
	call	0000h
	call	far 1EDAh:0AACh
	mov	di,13Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	les	di,[bp+8h]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h

l1AB8_04ED:
	mov	sp,bp
	pop	bp
	retf	2h

;; fn1AB8_04F3: 1AB8:04F3
;;   Called from:
;;     133F:0073 (in fn133F_0056)
;;     13E2:001E (in fn13E2_0001)
fn1AB8_04F3 proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	ax,[0B818h]
	mov	[bp-2h],ax
	xor	ax,ax
	mov	[0B818h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf
1AB8:050B                                  55 89 E5 83 EC            U....
1AB8:0510 02 C7 46 FE 01 00 8B 46 FE 89 EC 5D CA 02 00 55 ..F....F...]...U
1AB8:0520 89 E5 FF 76 06 9A 3F 02 DA 1E C4 7E 08 26 89 05 ...v..?....~.&..
1AB8:0530 26 89 55 02 5D CA 06 00 55 89 E5 C4 7E 08 26 8B &.U.]...U...~.&.
1AB8:0540 05 26 0B 45 02 74 12 C4 7E 08 26 FF 75 02 26 FF .&.E.t..~.&.u.&.
1AB8:0550 35 FF 76 06 9A 54 02 DA 1E C4 7E 08 31 C0 26 89 5.v..T....~.1.&.
1AB8:0560 05 26 89 45 02 5D CA 06 00                      .&.E.]...       

;; fn1AB8_0569: 1AB8:0569
;;   Called from:
;;     1AB8:0692 (in fn1AB8_05D3)
;;     1AB8:07DB (in fn1AB8_06CA)
;;     1AB8:0BEE (in fn1AB8_0BAE)
fn1AB8_0569 proc
	push	bp
	mov	bp,sp
	sub	sp,8h
	les	di,[bp+8h]
	mov	ax,es:[di]
	add	[bp+0Ch],ax
	mov	ax,[bp+0Ch]
	mov	cx,4h
	shr	ax,cl
	add	ax,[bp+0Eh]
	mov	dx,ax
	xor	ax,ax
	mov	[bp-8h],ax
	mov	[bp-6h],dx
	mov	ax,[bp+0Ch]
	and	ax,0Fh
	or	ax,ax
	jz	05B8h

l1AB8_0597:
	les	di,[bp+0Ch]
	push	es
	push	di
	les	di,[bp-8h]
	push	es
	push	di
	les	di,[bp+4h]
	push	word ptr es:[di]
	call	far 1EDAh:11DFh
	mov	ax,[bp+0Ch]
	and	ax,0Fh
	les	di,[bp+8h]
	sub	es:[di],ax

l1AB8_05B8:
	mov	ax,[bp-8h]
	mov	dx,[bp-6h]
	mov	[bp-4h],ax
	mov	[bp-2h],dx
	mov	ax,[bp-4h]
	mov	dx,[bp-2h]
	mov	sp,bp
	pop	bp
	ret	0Ch
1AB8:05D0 02 70 6B                                        .pk             

;; fn1AB8_05D3: 1AB8:05D3
;;   Called from:
;;     13E2:022B (in fn13E2_0220)
;;     1AB8:0AAC (in fn1AB8_097B)
fn1AB8_05D3 proc
	push	bp
	mov	bp,sp
	sub	sp,108h
	cmp	byte ptr [0B84Eh],0h
	jz	05EFh

l1AB8_05E1:
	mov	word ptr [0B818h],0FFF5h
	mov	word ptr [bp-2h],0FFF5h
	jmp	06BEh

l1AB8_05EF:
	mov	word ptr [0B818h],0FFFCh
	mov	word ptr [bp-2h],0FFFCh
	lea	di,[bp+0FEF8h]
	push	ss
	push	di
	les	di,[bp+6h]
	push	es
	push	di
	mov	ax,2h
	push	ax
	call	far 1EDAh:0B61h
	mov	di,5D0h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	061Dh

l1AB8_061A:
	jmp	06BEh

l1AB8_061D:
	mov	ax,[bp+6h]
	add	ax,80h
	mov	dx,[bp+8h]
	mov	[bp-6h],ax
	mov	[bp-4h],dx
	les	di,[bp-6h]
	mov	[bp-0Ch],di
	mov	[bp-0Ah],es
	les	di,[bp-0Ch]
	cmp	byte ptr es:[di+6h],2h
	jc	0649h

l1AB8_063F:
	les	di,[bp-0Ch]
	cmp	byte ptr es:[di+8h],1h
	jbe	064Bh

l1AB8_0649:
	jmp	06BEh

l1AB8_064B:
	mov	ax,[0B7B8h]
	mov	[bp-0Eh],ax
	xor	ax,ax
	cmp	ax,[bp-0Eh]
	jg	06BEh

l1AB8_0658:
	mov	[bp-8h],ax
	jmp	0660h

l1AB8_065D:
	inc	word ptr [bp-8h]

l1AB8_0660:
	mov	ax,1Ah
	mul	word ptr [bp-8h]
	mov	di,ax
	add	di,50FCh
	push	ds
	push	di
	les	di,[bp-0Ch]
	add	di,0Ah
	push	es
	push	di
	call	far 1EDAh:0B24h
	jnz	06B6h

l1AB8_067E:
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	les	di,[bp-0Ch]
	push	es
	push	di
	les	di,[bp-0Ch]
	add	di,4h
	push	es
	push	di
	call	0569h
	mov	cx,ax
	mov	bx,dx
	mov	ax,1Ah
	mul	word ptr [bp-8h]
	mov	di,ax
	mov	[di+5112h],cx
	mov	[di+5114h],bx
	mov	ax,[bp-8h]
	mov	[bp-2h],ax
	xor	ax,ax
	mov	[0B818h],ax
	jmp	06BEh

l1AB8_06B6:
	mov	ax,[bp-8h]
	cmp	ax,[bp-0Eh]
	jnz	065Dh

l1AB8_06BE:
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf	4h
1AB8:06C7                      02 50 4B                          .PK      

;; fn1AB8_06CA: 1AB8:06CA
;;   Called from:
;;     13E2:0245 (in fn13E2_0220)
;;     13E2:025F (in fn13E2_0220)
;;     1AB8:16F3 (in fn1AB8_1536)
fn1AB8_06CA proc
	push	bp
	mov	bp,sp
	sub	sp,112h
	mov	word ptr [0B818h],0FFF3h
	mov	ax,[0B818h]
	mov	[bp-2h],ax
	lea	di,[bp+0FEF6h]
	push	ss
	push	di
	les	di,[bp+6h]
	push	es
	push	di
	mov	ax,2h
	push	ax
	call	far 1EDAh:0B61h
	mov	di,6C7h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	0700h

l1AB8_06FD:
	jmp	080Ah

l1AB8_0700:
	xor	ax,ax
	mov	[bp-0Ah],ax

l1AB8_0705:
	mov	ax,[bp-0Ah]
	les	di,[bp+6h]
	add	di,ax
	cmp	byte ptr es:[di],1Ah
	jz	071Fh

l1AB8_0713:
	cmp	word ptr [bp-0Ah],101h
	jnc	071Fh

l1AB8_071A:
	inc	word ptr [bp-0Ah]
	jmp	0705h

l1AB8_071F:
	cmp	word ptr [bp-0Ah],100h
	jc	0729h

l1AB8_0726:
	jmp	080Ah

l1AB8_0729:
	les	di,[bp+6h]
	mov	ax,di
	add	ax,[bp-0Ah]
	inc	ax
	les	di,[bp+6h]
	mov	dx,es
	mov	[bp-6h],ax
	mov	[bp-4h],dx
	les	di,[bp-6h]
	mov	[bp-0Eh],di
	mov	[bp-0Ch],es
	les	di,[bp-0Eh]
	cmp	byte ptr es:[di+8h],1h
	jc	075Ah

l1AB8_0750:
	les	di,[bp-0Eh]
	cmp	byte ptr es:[di+0Ah],1h
	jbe	075Dh

l1AB8_075A:
	jmp	080Ah

l1AB8_075D:
	mov	word ptr [bp-8h],1h
	jmp	0767h

l1AB8_0764:
	inc	word ptr [bp-8h]

l1AB8_0767:
	mov	ax,0Fh
	mul	word ptr [bp-8h]
	mov	di,ax
	add	di,5215h
	push	ds
	push	di
	lea	di,[bp+0FEF2h]
	push	ss
	push	di
	les	di,[bp-0Eh]
	add	di,2h
	push	es
	push	di
	mov	ax,4h
	push	ax
	call	far 1EDAh:0B61h
	call	far 1EDAh:0B24h
	jnz	0801h

l1AB8_0794:
	mov	ax,0Fh
	mul	word ptr [bp-8h]
	mov	di,ax
	add	di,520Bh
	mov	[bp+0FEEEh],di
	mov	[bp+0FEF0h],ds
	les	di,[bp+0FEEEh]
	push	es
	push	di
	les	di,[bp+0FEEEh]
	push	word ptr es:[di+8h]
	call	dword ptr [0B6C6h]
	les	di,[bp+0FEEEh]
	xor	ax,ax
	mov	es:[di],ax
	mov	es:[di+2h],ax
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	les	di,[bp-0Eh]
	push	es
	push	di
	les	di,[bp-0Eh]
	add	di,6h
	push	es
	push	di
	call	0569h
	les	di,[bp+0FEEEh]
	mov	es:[di+4h],ax
	mov	es:[di+6h],dx
	les	di,[bp+0FEEEh]
	xor	ax,ax
	mov	es:[di+8h],ax
	mov	ax,[bp-8h]
	mov	[bp-2h],ax
	xor	ax,ax
	mov	[0B818h],ax
	jmp	080Ah

l1AB8_0801:
	cmp	word ptr [bp-8h],14h
	jz	080Ah

l1AB8_0807:
	jmp	0764h

l1AB8_080A:
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf	4h

;; fn1AB8_0813: 1AB8:0813
;;   Called from:
;;     1AB8:0CE2 (in fn1AB8_0BAE)
;;     1AB8:0D6B (in fn1AB8_0BAE)
;;     1AB8:0DDC (in fn1AB8_0BAE)
;;     1AB8:0E5C (in fn1AB8_0BAE)
;;     1AB8:0F05 (in fn1AB8_0EB5)
;;     1AB8:17C0 (in fn1AB8_17AE)
fn1AB8_0813 proc
	push	bp
	mov	bp,sp
	mov	ax,8Bh
	mov	dx,1AB8h
	mov	[0B820h],ax
	mov	[0B822h],dx
	mov	ax,8Bh
	mov	dx,1AB8h
	mov	[0B832h],ax
	mov	[0B834h],dx
	xor	ax,ax
	mov	[0B824h],ax
	mov	[0B826h],ax
	xor	ax,ax
	mov	[0B836h],ax
	mov	[0B838h],ax
	xor	ax,ax
	mov	[0B828h],ax
	mov	[0B82Ah],ax
	xor	ax,ax
	mov	[0B82Eh],ax
	mov	[0B830h],ax
	xor	ax,ax
	mov	[0B7E0h],ax
	mov	[0B7E2h],ax
	xor	ax,ax
	mov	[0B7E4h],ax
	xor	ax,ax
	mov	[0B7FAh],ax
	mov	[0B7FCh],ax
	xor	ax,ax
	mov	[0B7FEh],ax
	mov	byte ptr [0B7EAh],0h
	mov	word ptr [0B84Ah],1h
	mov	word ptr [0B84Ch],1h
	xor	ax,ax
	mov	[0B74Ah],ax
	mov	byte ptr [0B84Eh],0h
	pop	bp
	ret

;; fn1AB8_0887: 1AB8:0887
;;   Called from:
;;     1AB8:0A1C (in fn1AB8_097B)
;;     1AB8:1649 (in fn1AB8_1536)
fn1AB8_0887 proc
	push	bp
	mov	bp,sp
	sub	sp,302h
	les	di,[bp+0Eh]
	push	es
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	les	di,[bp+0Ah]
	push	es
	push	di
	lea	di,[bp+0FDFEh]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	mov	byte ptr [bp-1h],0h
	mov	word ptr [0B818h],0FFFDh
	les	di,[bp+6h]
	xor	ax,ax
	mov	es:[di],ax
	mov	di,0B6CAh
	push	ds
	push	di
	lea	di,[bp+0FCFEh]
	push	ss
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FDFEh]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1EDAh:0FA2h
	mov	di,0B6CAh
	push	ds
	push	di
	mov	ax,1h
	push	ax
	call	far 1EDAh:0FD0h
	call	far 1EDAh:04A2h
	or	ax,ax
	jz	0939h

l1AB8_0905:
	cmp	byte ptr [bp+0FEFEh],0h
	jnz	0910h

l1AB8_090C:
	jmp	096Dh
1AB8:090E                                           EB 29               .)

l1AB8_0910:
	mov	di,0B6CAh
	push	ds
	push	di
	lea	di,[bp+0FDFEh]
	push	ss
	push	di
	call	far 1EDAh:0FA2h
	mov	di,0B6CAh
	push	ds
	push	di
	mov	ax,1h
	push	ax
	call	far 1EDAh:0FD0h
	call	far 1EDAh:04A2h
	or	ax,ax
	jz	0939h

l1AB8_0937:
	jmp	096Dh

l1AB8_0939:
	xor	ax,ax
	mov	[0B818h],ax
	mov	di,0B6CAh
	push	ds
	push	di
	call	far 1EDAh:116Ah
	les	di,[bp+6h]
	mov	es:[di],ax
	les	di,[bp+6h]
	cmp	word ptr es:[di],0FFh
	jbe	0969h

l1AB8_0957:
	mov	ax,[bp+4h]
	mov	[0B818h],ax
	mov	di,0B6CAh
	push	ds
	push	di
	call	far 1EDAh:1051h
	jmp	096Dh

l1AB8_0969:
	mov	byte ptr [bp-1h],1h

l1AB8_096D:
	mov	al,[bp-1h]
	mov	sp,bp
	pop	bp
	ret	0Eh
1AB8:0976                   04 2E 42 47 49                      ..BGI     

;; fn1AB8_097B: 1AB8:097B
;;   Called from:
;;     1AB8:0D5B (in fn1AB8_0BAE)
fn1AB8_097B proc
	push	bp
	mov	bp,sp
	sub	sp,20Eh
	les	di,[bp+4h]
	push	es
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	mov	byte ptr [bp-1h],0h
	lea	di,[bp+0FDF2h]
	push	ss
	push	di
	mov	ax,1Ah
	mul	word ptr [bp+8h]
	mov	di,ax
	add	di,50FCh
	push	ds
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,976h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,0B756h
	push	ds
	push	di
	mov	ax,0Ch
	push	ax
	call	far 1EDAh:0A39h
	mov	ax,1Ah
	mul	word ptr [bp+8h]
	mov	di,ax
	mov	ax,[di+5112h]
	or	ax,[di+5114h]
	jz	0A08h

l1AB8_09DD:
	mov	ax,1Ah
	mul	word ptr [bp+8h]
	mov	di,ax
	mov	ax,[di+5112h]
	mov	dx,[di+5114h]
	mov	[0B832h],ax
	mov	[0B834h],dx
	xor	ax,ax
	mov	[0B828h],ax
	mov	[0B82Ah],ax
	xor	ax,ax
	mov	[0B82Ch],ax
	mov	byte ptr [bp-1h],1h
	jmp	0AE5h

l1AB8_0A08:
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	di,0B756h
	push	ds
	push	di
	mov	di,0B82Ch
	push	ds
	push	di
	mov	ax,0FFFCh
	push	ax
	call	0887h
	or	al,al
	jnz	0A26h

l1AB8_0A23:
	jmp	0AE5h

l1AB8_0A26:
	mov	ax,[536Eh]
	mov	dx,[5370h]
	mov	[0B7BCh],ax
	mov	[0B7BEh],dx
	mov	ax,50Bh
	mov	dx,1AB8h
	mov	[536Eh],ax
	mov	[5370h],dx
	mov	di,0B828h
	push	ds
	push	di
	push	word ptr [0B82Ch]
	call	dword ptr [0B6C2h]
	mov	ax,[0B7BCh]
	mov	dx,[0B7BEh]
	mov	[536Eh],ax
	mov	[5370h],dx
	mov	ax,[0B828h]
	or	ax,[0B82Ah]
	jnz	0A6Dh

l1AB8_0A65:
	mov	word ptr [0B818h],0FFFBh
	jmp	0AE5h

l1AB8_0A6D:
	mov	di,0B6CAh
	push	ds
	push	di
	les	di,[0B828h]
	push	es
	push	di
	push	word ptr [0B82Ch]
	lea	di,[bp+0FEF6h]
	push	ss
	push	di
	call	far 1EDAh:10BBh
	mov	di,0B6CAh
	push	ds
	push	di
	call	far 1EDAh:1051h
	call	far 1EDAh:04A2h
	or	ax,ax
	jnz	0AB5h

l1AB8_0A9A:
	mov	ax,[bp+0FEF6h]
	cmp	ax,[0B82Ch]
	jnz	0AB5h

l1AB8_0AA4:
	push	word ptr [0B82Ah]
	push	word ptr [0B828h]
	push	cs
	call	05D3h
	cmp	ax,[bp+8h]
	jz	0ACAh

l1AB8_0AB5:
	mov	word ptr [0B818h],0FFFCh
	mov	di,0B828h
	push	ds
	push	di
	push	word ptr [0B82Ch]
	call	dword ptr [0B6C6h]
	jmp	0AE5h

l1AB8_0ACA:
	mov	ax,1Ah
	mul	word ptr [bp+8h]
	mov	di,ax
	mov	ax,[di+5112h]
	mov	dx,[di+5114h]
	mov	[0B832h],ax
	mov	[0B834h],dx
	mov	byte ptr [bp-1h],1h

l1AB8_0AE5:
	mov	al,[bp-1h]
	mov	sp,bp
	pop	bp
	ret	6h

;; fn1AB8_0AEE: 1AB8:0AEE
;;   Called from:
;;     1AB8:0E79 (in fn1AB8_0BAE)
fn1AB8_0AEE proc
	push	bp
	mov	bp,sp
	sub	sp,8h
	cmp	byte ptr [0B84Eh],0h
	jnz	0AFFh

l1AB8_0AFB:
	push	cs
	call	008Bh

l1AB8_0AFF:
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	word ptr [0B7C2h]
	push	word ptr [0B7C4h]
	mov	al,1h
	push	ax
	push	cs
	call	0F93h
	mov	di,0B87Ah
	push	ds
	push	di
	push	cs
	call	1384h
	mov	di,0B87Ah
	push	ds
	push	di
	push	cs
	call	129Ah
	push	cs
	call	1C5Ah
	cmp	ax,1h
	jz	0B36h

l1AB8_0B2F:
	xor	ax,ax
	push	ax
	push	cs
	call	1250h

l1AB8_0B36:
	mov	byte ptr [0B840h],0h
	push	cs
	call	1C4Ah
	push	ax
	push	cs
	call	1C32h
	lea	di,[bp-8h]
	push	ss
	push	di
	mov	ax,8h
	push	ax
	mov	al,0FFh
	push	ax
	call	far 1EDAh:1202h
	lea	di,[bp-8h]
	push	ss
	push	di
	push	cs
	call	1C4Ah
	push	ax
	push	cs
	call	11A0h
	mov	ax,1h
	push	ax
	push	cs
	call	1C4Ah
	push	ax
	push	cs
	call	1175h
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	mov	ax,1h
	push	ax
	push	cs
	call	10F4h
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	mov	ax,1h
	push	ax
	push	cs
	call	1536h
	xor	ax,ax
	push	ax
	mov	ax,2h
	push	ax
	push	cs
	call	14F4h
	xor	ax,ax
	push	ax
	push	cs
	call	194Eh
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	cs
	call	108Bh
	mov	sp,bp
	pop	bp
	retf
1AB8:0BAC                                     01 5C                   .\  

;; fn1AB8_0BAE: 1AB8:0BAE
;;   Called from:
;;     133F:006E (in fn133F_0056)
;;     13E2:0019 (in fn13E2_0001)
fn1AB8_0BAE proc
	push	bp
	mov	bp,sp
	sub	sp,208h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	mov	ax,2073h
	mov	dx,1AB8h
	mov	[0B820h],ax
	mov	[0B822h],dx
	push	word ptr [0B822h]
	push	word ptr [0B820h]
	les	di,[0B820h]
	push	es
	push	di
	les	di,[0B820h]
	add	di,2h
	push	es
	push	di
	call	0569h
	mov	[0B820h],ax
	mov	[0B822h],dx
	mov	byte ptr [bp+0FEF9h],0h
	les	di,[bp+0Eh]
	cmp	word ptr es:[di],0h
	jz	0C09h

l1AB8_0C06:
	jmp	0C86h

l1AB8_0C09:
	xor	ax,ax
	mov	[bp+0FEFCh],ax
	mov	word ptr [bp+0FEFAh],0FFFFh

l1AB8_0C15:
	mov	ax,[bp+0FEFCh]
	cmp	ax,[0B7B8h]
	jge	0C86h

l1AB8_0C1F:
	cmp	word ptr [bp+0FEFAh],0h
	jge	0C86h

l1AB8_0C26:
	mov	ax,1Ah
	mul	word ptr [bp+0FEFCh]
	mov	di,ax
	mov	ax,[di+510Eh]
	or	ax,[di+5110h]
	jz	0C80h

l1AB8_0C39:
	mov	ax,1Ah
	mul	word ptr [bp+0FEFCh]
	mov	di,ax
	mov	ax,[di+510Eh]
	mov	dx,[di+5110h]
	mov	[0B896h],ax
	mov	[0B898h],dx
	call	dword ptr [0B896h]
	mov	[bp+0FEFAh],ax
	cmp	word ptr [bp+0FEFAh],0h
	jl	0C80h

l1AB8_0C60:
	mov	ax,[bp+0FEFCh]
	mov	[0B814h],ax
	mov	ax,[bp+0FEFCh]
	les	di,[bp+0Eh]
	mov	es:[di],ax
	mov	ax,[bp+0FEFAh]
	les	di,[bp+0Ah]
	mov	es:[di],ax
	mov	byte ptr [bp+0FEF9h],1h

l1AB8_0C80:
	inc	word ptr [bp+0FEFCh]
	jmp	0C15h

l1AB8_0C86:
	cmp	byte ptr [bp+0FEF9h],0h
	jnz	0CA2h

l1AB8_0C8D:
	mov	di,0B814h
	push	ds
	push	di
	les	di,[bp+0Eh]
	push	es
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	push	cs
	call	19EEh
	jmp	0CCBh

l1AB8_0CA2:
	mov	ax,[0B814h]
	mov	[bp+0FEFCh],ax
	les	di,[bp+0Eh]
	mov	ax,es:[di]
	add	ax,80h
	mov	[bp+0FEFAh],ax
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	push	cs
	call	19EEh

l1AB8_0CCB:
	les	di,[bp+0Eh]
	cmp	word ptr es:[di],0h
	jge	0CE8h

l1AB8_0CD4:
	mov	word ptr [0B818h],0FFFEh
	les	di,[bp+0Eh]
	mov	word ptr es:[di],0FFFEh
	call	0813h
	jmp	0E82h

l1AB8_0CE8:
	les	di,[bp+0Ah]
	mov	ax,es:[di]
	mov	[0B816h],ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,0B764h
	push	ds
	push	di
	mov	ax,50h
	push	ax
	call	far 1EDAh:0A39h
	cmp	byte ptr [0B764h],0h
	jz	0D52h

l1AB8_0D0C:
	mov	al,[0B764h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+0B764h]
	mov	[bp+0FEFFh],al
	cmp	byte ptr [bp+0FEFFh],3Ah
	jz	0D52h

l1AB8_0D22:
	cmp	byte ptr [bp+0FEFFh],5Ch
	jz	0D52h

l1AB8_0D29:
	lea	di,[bp+0FDF8h]
	push	ss
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,0BACh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,0B764h
	push	ds
	push	di
	mov	ax,50h
	push	ax
	call	far 1EDAh:0A39h

l1AB8_0D52:
	push	word ptr [0B814h]
	mov	di,0B764h
	push	ds
	push	di
	call	097Bh
	or	al,al
	jnz	0D71h

l1AB8_0D62:
	mov	ax,[0B818h]
	les	di,[bp+0Eh]
	mov	es:[di],ax
	call	0813h
	jmp	0E82h

l1AB8_0D71:
	mov	di,0B7D4h
	push	ds
	push	di
	mov	ax,3Fh
	push	ax
	mov	al,0h
	push	ax
	call	far 1EDAh:1202h
	mov	ax,[536Eh]
	mov	dx,[5370h]
	mov	[0B7BCh],ax
	mov	[0B7BEh],dx
	mov	ax,50Bh
	mov	dx,1AB8h
	mov	[536Eh],ax
	mov	[5370h],dx
	mov	di,0B7E0h
	push	ds
	push	di
	push	word ptr [0B7B6h]
	call	dword ptr [0B6C2h]
	mov	ax,[0B7BCh]
	mov	dx,[0B7BEh]
	mov	[536Eh],ax
	mov	[5370h],dx
	mov	ax,[0B7E0h]
	or	ax,[0B7E2h]
	jnz	0DE2h

l1AB8_0DC1:
	mov	word ptr [0B818h],0FFFBh
	les	di,[bp+0Eh]
	mov	word ptr es:[di],0FFFBh
	mov	di,0B828h
	push	ds
	push	di
	push	word ptr [0B82Ch]
	call	dword ptr [0B6C6h]
	call	0813h
	jmp	0E82h

l1AB8_0DE2:
	mov	byte ptr [0B7D5h],0h
	mov	byte ptr [0B7EAh],0h
	mov	ax,[0B7E0h]
	mov	dx,[0B7E2h]
	mov	[0B82Eh],ax
	mov	[0B830h],dx
	mov	ax,[0B7B6h]
	mov	[0B7E4h],ax
	mov	ax,[0B7E0h]
	mov	dx,[0B7E2h]
	mov	[0B7FAh],ax
	mov	[0B7FCh],dx
	mov	ax,[0B7B6h]
	mov	[0B7FEh],ax
	mov	ax,0B818h
	mov	dx,ds
	mov	[0B7EEh],ax
	mov	[0B7F0h],dx
	mov	di,0B7D4h
	push	ds
	push	di
	push	cs
	call	1855h
	mov	ax,[0B83Ah]
	mov	dx,[0B83Ch]
	mov	di,ax
	mov	es,dx
	push	es
	push	di
	mov	di,0B7C0h
	push	ds
	push	di
	mov	ax,13h
	push	ax
	call	far 1EDAh:11DFh
	mov	di,0B7D4h
	push	ds
	push	di
	push	cs
	call	1AA6h
	cmp	byte ptr [0B7C0h],0h
	jz	0E61h

l1AB8_0E54:
	mov	al,[0B7C0h]
	xor	ah,ah
	mov	[0B818h],ax
	call	0813h
	jmp	0E82h

l1AB8_0E61:
	push	cs
	call	1C93h
	mov	[0B848h],ax
	mov	ax,[0B7CEh]
	mov	[0B84Ah],ax
	mov	word ptr [0B84Ch],2710h
	mov	byte ptr [0B84Eh],1h
	push	cs
	call	0AEEh
	xor	ax,ax
	mov	[0B818h],ax

l1AB8_0E82:
	mov	sp,bp
	pop	bp
	retf	0Ch

;; fn1AB8_0E88: 1AB8:0E88
;;   Called from:
;;     0800:0008 (in fn0800_0000)
;;     0C74:03EA (in fn0C74_03D4)
;;     13E2:01AF (in fn13E2_0193)
;;     1AB8:0ECB (in fn1AB8_0EB5)
fn1AB8_0E88 proc
	push	bp
	mov	bp,sp
	push	cs
	call	18E3h
	mov	ax,[0B824h]
	or	ax,[0B826h]
	jnz	0EB3h

l1AB8_0E98:
	mov	ax,[0B820h]
	mov	dx,[0B822h]
	mov	[0B824h],ax
	mov	[0B826h],dx
	mov	ax,8Bh
	mov	dx,1AB8h
	mov	[0B820h],ax
	mov	[0B822h],dx

l1AB8_0EB3:
	pop	bp
	retf

;; fn1AB8_0EB5: 1AB8:0EB5
;;   Called from:
;;     0800:0003 (in fn0800_0000)
;;     0C74:03E5 (in fn0C74_03D4)
;;     13E2:01AA (in fn13E2_0193)
fn1AB8_0EB5 proc
	push	bp
	mov	bp,sp
	sub	sp,6h
	cmp	byte ptr [0B84Eh],0h
	jnz	0ECBh

l1AB8_0EC2:
	mov	word ptr [0B818h],0FFFFh
	jmp	0F7Ch

l1AB8_0ECB:
	push	cs
	call	0E88h
	mov	di,0B82Eh
	push	ds
	push	di
	push	word ptr [0B7B6h]
	call	dword ptr [0B6C6h]
	mov	ax,[0B828h]
	or	ax,[0B82Ah]
	jz	0EF8h

l1AB8_0EE5:
	mov	ax,1Ah
	mul	word ptr [0B814h]
	mov	di,ax
	xor	ax,ax
	mov	[di+5112h],ax
	mov	[di+5114h],ax

l1AB8_0EF8:
	mov	di,0B828h
	push	ds
	push	di
	push	word ptr [0B82Ch]
	call	dword ptr [0B6C6h]
	call	0813h
	mov	word ptr [bp-2h],1h
	jmp	0F12h

l1AB8_0F0F:
	inc	word ptr [bp-2h]

l1AB8_0F12:
	mov	ax,0Fh
	mul	word ptr [bp-2h]
	mov	di,ax
	add	di,520Bh
	mov	[bp-6h],di
	mov	[bp-4h],ds
	les	di,[bp-6h]
	cmp	byte ptr es:[di+0Ah],0h
	jz	0F76h

l1AB8_0F2E:
	les	di,[bp-6h]
	cmp	word ptr es:[di+8h],0h
	jz	0F76h

l1AB8_0F38:
	les	di,[bp-6h]
	mov	ax,es:[di]
	or	ax,es:[di+2h]
	jz	0F76h

l1AB8_0F44:
	les	di,[bp-6h]
	push	es
	push	di
	les	di,[bp-6h]
	push	word ptr es:[di+8h]
	call	dword ptr [0B6C6h]
	les	di,[bp-6h]
	xor	ax,ax
	mov	es:[di+8h],ax
	les	di,[bp-6h]
	xor	ax,ax
	mov	es:[di],ax
	mov	es:[di+2h],ax
	les	di,[bp-6h]
	xor	ax,ax
	mov	es:[di+4h],ax
	mov	es:[di+6h],ax

l1AB8_0F76:
	cmp	word ptr [bp-2h],14h
	jnz	0F0Fh

l1AB8_0F7C:
	mov	sp,bp
	pop	bp
	retf

;; fn1AB8_0F80: 1AB8:0F80
;;   Called from:
;;     0800:14A3 (in fn0800_149F)
;;     0800:1646 (in fn0800_149F)
;;     0800:1671 (in fn0800_166D)
;;     0800:1829 (in fn0800_166D)
;;     0800:1854 (in fn0800_184C)
;;     0800:3DAB (in fn0800_3D9D)
;;     1229:0CDC (in fn1229_0CCE)
;;     1229:0DE3 (in fn1229_0DCC)
;;     1229:110A (in fn1229_0DCC)
fn1AB8_0F80 proc
	push	bp
	mov	bp,sp
	push	cs
	call	1AC2h
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	cs
	call	108Bh
	pop	bp
	retf

;; fn1AB8_0F93: 1AB8:0F93
;;   Called from:
;;     0800:0035 (in fn0800_0024)
;;     0800:0051 (in fn0800_0024)
;;     0C74:008D (in fn0C74_007C)
;;     0C74:00A9 (in fn0C74_007C)
;;     1229:0011 (in fn1229_0000)
;;     1229:002D (in fn1229_0000)
;;     1229:0AB8 (in fn1229_0AA8)
;;     1229:0ACE (in fn1229_0AA8)
;;     1229:0B55 (in fn1229_0AA8)
;;     1229:0B6B (in fn1229_0AA8)
;;     133F:01CA (in fn133F_014B)
;;     133F:01E6 (in fn133F_014B)
;;     1AB8:0B10 (in fn1AB8_0AEE)
fn1AB8_0F93 proc
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+0Eh],0h
	jl	0FE0h

l1AB8_0F9C:
	cmp	word ptr [bp+0Ch],0h
	jl	0FE0h

l1AB8_0FA2:
	mov	ax,[0B7C2h]
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ah]
	cwd
	cmp	dx,bx
	jg	0FE0h

l1AB8_0FB3:
	jl	0FB9h

l1AB8_0FB5:
	cmp	ax,cx
	ja	0FE0h

l1AB8_0FB9:
	mov	ax,[0B7C4h]
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+8h]
	cwd
	cmp	dx,bx
	jg	0FE0h

l1AB8_0FCA:
	jl	0FD0h

l1AB8_0FCC:
	cmp	ax,cx
	ja	0FE0h

l1AB8_0FD0:
	mov	ax,[bp+0Ah]
	cmp	ax,[bp+0Eh]
	jl	0FE0h

l1AB8_0FD8:
	mov	ax,[bp+8h]
	cmp	ax,[bp+0Ch]
	jge	0FE8h

l1AB8_0FE0:
	mov	word ptr [0B818h],0FFF5h
	jmp	1024h

l1AB8_0FE8:
	mov	ax,[bp+0Eh]
	mov	[0B852h],ax
	mov	ax,[bp+0Ch]
	mov	[0B854h],ax
	mov	ax,[bp+0Ah]
	mov	[0B856h],ax
	mov	ax,[bp+8h]
	mov	[0B858h],ax
	mov	al,[bp+6h]
	mov	[0B85Ah],al
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	mov	al,[bp+6h]
	push	ax
	push	cs
	call	1895h
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	cs
	call	108Bh

l1AB8_1024:
	pop	bp
	retf	0Ah

;; fn1AB8_1028: 1AB8:1028
;;   Called from:
;;     0800:003A (in fn0800_0024)
;;     0C74:0092 (in fn0C74_007C)
;;     1229:0016 (in fn1229_0000)
;;     1229:0ABD (in fn1229_0AA8)
;;     1229:0B5A (in fn1229_0AA8)
;;     133F:01CF (in fn133F_014B)
fn1AB8_1028 proc
	push	bp
	mov	bp,sp
	sub	sp,4h
	mov	ax,[0B862h]
	mov	dx,[0B864h]
	mov	[bp-4h],ax
	mov	[bp-2h],dx
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	cs
	call	1175h
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	mov	ax,[0B856h]
	sub	ax,[0B852h]
	push	ax
	mov	ax,[0B858h]
	sub	ax,[0B854h]
	push	ax
	push	cs
	call	1B3Eh
	cmp	word ptr [bp-4h],0Ch
	jnz	1073h

l1AB8_1065:
	mov	di,0B866h
	push	ds
	push	di
	push	word ptr [bp-2h]
	push	cs
	call	11A0h
	jmp	107Dh

l1AB8_1073:
	push	word ptr [bp-4h]
	push	word ptr [bp-2h]
	push	cs
	call	1175h

l1AB8_107D:
	xor	ax,ax
	push	ax
	xor	ax,ax
	push	ax
	push	cs
	call	108Bh
	mov	sp,bp
	pop	bp
	retf

;; fn1AB8_108B: 1AB8:108B
;;   Called from:
;;     0800:0E68 (in fn0800_0D20)
;;     0800:0EC3 (in fn0800_0D20)
;;     0800:1096 (in fn0800_0D20)
;;     0800:1158 (in fn0800_0D20)
;;     1229:0124 (in fn1229_0040)
;;     1229:0330 (in fn1229_0040)
;;     1AB8:0BA4 (in fn1AB8_0AEE)
;;     1AB8:0F8D (in fn1AB8_0F80)
;;     1AB8:1020 (in fn1AB8_0F93)
;;     1AB8:1083 (in fn1AB8_1028)
;;     1AB8:14EA (in fn1AB8_1492)
fn1AB8_108B proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1ACEh
	mov	ax,[bp+8h]
	mov	[0B844h],ax
	mov	ax,[bp+6h]
	mov	[0B846h],ax
	pop	bp
	retf	4h

;; fn1AB8_10A8: 1AB8:10A8
;;   Called from:
;;     0800:0E6D (in fn0800_0D20)
;;     0800:0EE6 (in fn0800_0D20)
;;     0800:0EF4 (in fn0800_0D20)
;;     0800:0F1C (in fn0800_0D20)
;;     0800:0F2A (in fn0800_0D20)
;;     0800:0F50 (in fn0800_0D20)
;;     0800:0F5E (in fn0800_0D20)
;;     0800:0FD7 (in fn0800_0D20)
;;     0800:10A5 (in fn0800_0D20)
;;     0800:10C5 (in fn0800_0D20)
;;     0800:10DC (in fn0800_0D20)
;;     0800:1114 (in fn0800_0D20)
;;     1229:0129 (in fn1229_0040)
;;     1229:0155 (in fn1229_0040)
;;     1229:0163 (in fn1229_0040)
;;     1229:018B (in fn1229_0040)
;;     1229:0199 (in fn1229_0040)
;;     1229:01BF (in fn1229_0040)
;;     1229:01CD (in fn1229_0040)
;;     1229:0217 (in fn1229_0040)
;;     1229:027C (in fn1229_0040)
;;     1229:029C (in fn1229_0040)
;;     1229:02B3 (in fn1229_0040)
;;     1229:02EB (in fn1229_0040)
fn1AB8_10A8 proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	ax,[0B844h]
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf

;; fn1AB8_10BB: 1AB8:10BB
;;   Called from:
;;     0800:1052 (in fn0800_0D20)
;;     0800:107E (in fn0800_0D20)
;;     0800:10F9 (in fn0800_0D20)
;;     0800:1131 (in fn0800_0D20)
;;     1229:02D0 (in fn1229_0040)
;;     1229:0308 (in fn1229_0040)
fn1AB8_10BB proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	ax,[0B846h]
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf

;; fn1AB8_10CE: 1AB8:10CE
;;   Called from:
;;     0800:0043 (in fn0800_0024)
;;     0800:11FE (in fn0800_11EF)
;;     0800:1210 (in fn0800_11EF)
;;     0800:14B2 (in fn0800_149F)
;;     0800:1695 (in fn0800_166D)
;;     0800:1E5D (in fn0800_1E3F)
;;     0800:2485 (in fn0800_2401)
;;     0800:2497 (in fn0800_2401)
;;     0800:3963 (in fn0800_391E)
;;     0800:43BE (in fn0800_4255)
;;     0C74:009B (in fn0C74_007C)
;;     1229:001F (in fn1229_0000)
;;     1229:0527 (in fn1229_050A)
;;     1229:0545 (in fn1229_050A)
;;     1229:0629 (in fn1229_061B)
;;     1229:0647 (in fn1229_061B)
;;     1229:0744 (in fn1229_0735)
;;     1229:0762 (in fn1229_0735)
;;     1229:07D5 (in fn1229_0735)
;;     1229:07F3 (in fn1229_0735)
;;     1229:0D82 (in fn1229_0CCE)
;;     1229:0D97 (in fn1229_0CCE)
;;     133F:01D8 (in fn133F_014B)
;;     133F:04F9 (in fn133F_04DE)
fn1AB8_10CE proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	ax,[0B7C2h]
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf

;; fn1AB8_10E1: 1AB8:10E1
;;   Called from:
;;     0800:0049 (in fn0800_0024)
;;     0800:14BD (in fn0800_149F)
;;     0800:16A0 (in fn0800_166D)
;;     0C74:00A1 (in fn0C74_007C)
;;     0C74:05BC (in fn0C74_05B8)
;;     0C74:0645 (in fn0C74_05B8)
;;     1229:0025 (in fn1229_0000)
;;     1229:0536 (in fn1229_050A)
;;     1229:0554 (in fn1229_050A)
;;     1229:0638 (in fn1229_061B)
;;     1229:0656 (in fn1229_061B)
;;     1229:0753 (in fn1229_0735)
;;     1229:0771 (in fn1229_0735)
;;     1229:07E4 (in fn1229_0735)
;;     1229:0802 (in fn1229_0735)
;;     1229:0D88 (in fn1229_0CCE)
;;     1229:0D9D (in fn1229_0CCE)
;;     133F:01DE (in fn133F_014B)
;;     133F:04FF (in fn133F_04DE)
fn1AB8_10E1 proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	ax,[0B7C4h]
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf

;; fn1AB8_10F4: 1AB8:10F4
;;   Called from:
;;     0800:0A50 (in fn0800_09C2)
;;     0800:1327 (in fn0800_1315)
;;     0800:186B (in fn0800_184C)
;;     0800:1A17 (in fn0800_19E1)
;;     0800:31F0 (in fn0800_31B7)
;;     0800:36F8 (in fn0800_36E6)
;;     0800:3E0C (in fn0800_3D9D)
;;     0C74:10A3 (in fn0C74_0FA1)
;;     0C74:1756 (in fn0C74_0FA1)
;;     0C74:18E4 (in fn0C74_0FA1)
;;     0C74:200A (in fn0C74_1F08)
;;     0C74:287C (in fn0C74_1F08)
;;     0C74:2FA5 (in fn0C74_2E5A)
;;     0C74:3380 (in fn0C74_3236)
;;     0C74:3980 (in fn0C74_396E)
;;     0C74:3F86 (in fn0C74_3F74)
;;     0C74:45E0 (in fn0C74_45CE)
;;     0C74:49A3 (in fn0C74_4999)
;;     0C74:53D2 (in fn0C74_5258)
;;     1AB8:0B7A (in fn1AB8_0AEE)
fn1AB8_10F4 proc
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+0Ah],4h
	ja	1103h

l1AB8_10FD:
	cmp	word ptr [bp+6h],3h
	jbe	110Bh

l1AB8_1103:
	mov	word ptr [0B818h],0FFF5h
	jmp	112Ah

l1AB8_110B:
	mov	ax,[bp+0Ah]
	mov	[0B85Ch],ax
	mov	ax,[bp+8h]
	mov	[0B85Eh],ax
	mov	ax,[bp+6h]
	mov	[0B860h],ax
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1CFFh

l1AB8_112A:
	pop	bp
	retf	6h

;; fn1AB8_112E: 1AB8:112E
;;   Called from:
;;     0800:0A6E (in fn0800_09C2)
;;     0800:0DFB (in fn0800_0D20)
;;     0800:187A (in fn0800_184C)
;;     0800:1D22 (in fn0800_19E1)
;;     0800:31FF (in fn0800_31B7)
;;     0800:3E1C (in fn0800_3D9D)
;;     1229:00B7 (in fn1229_0040)
;;     1229:0CF2 (in fn1229_0CCE)
;;     133F:03C7 (in fn133F_0352)
fn1AB8_112E proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+0Ah]
	push	cs
	call	1AF6h
	push	word ptr [bp+8h]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1AF6h
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+6h]
	push	cs
	call	1AF6h
	push	word ptr [bp+0Ch]
	push	word ptr [bp+6h]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	cs
	call	1AF6h
	pop	bp
	retf	8h

;; fn1AB8_1175: 1AB8:1175
;;   Called from:
;;     0800:0061 (in fn0800_005A)
;;     0800:131C (in fn0800_1315)
;;     0800:1A0C (in fn0800_19E1)
;;     0800:36ED (in fn0800_36E6)
;;     0800:39AA (in fn0800_391E)
;;     0800:3A0F (in fn0800_391E)
;;     0800:3F65 (in fn0800_3D9D)
;;     0800:43E0 (in fn0800_4255)
;;     0C74:00E2 (in fn0C74_00DB)
;;     1AB8:0B6C (in fn1AB8_0AEE)
;;     1AB8:1041 (in fn1AB8_1028)
;;     1AB8:1079 (in fn1AB8_1028)
fn1AB8_1175 proc
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+8h],0Bh
	jbe	1186h

l1AB8_117E:
	mov	word ptr [0B818h],0FFF5h
	jmp	119Ch

l1AB8_1186:
	mov	ax,[bp+8h]
	mov	[0B862h],ax
	mov	ax,[bp+6h]
	mov	[0B864h],ax
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1D5Bh

l1AB8_119C:
	pop	bp
	retf	4h

;; fn1AB8_11A0: 1AB8:11A0
;;   Called from:
;;     1AB8:0B5F (in fn1AB8_0AEE)
;;     1AB8:106D (in fn1AB8_1028)
fn1AB8_11A0 proc
	push	bp
	mov	bp,sp
	sub	sp,8h
	les	di,[bp+8h]
	push	es
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	mov	ax,8h
	push	ax
	call	far 1EDAh:0953h
	push	cs
	call	1C4Ah
	cmp	ax,[bp+6h]
	jnc	11CAh

l1AB8_11C2:
	mov	word ptr [0B818h],0FFF5h
	jmp	11F5h

l1AB8_11CA:
	mov	word ptr [0B862h],0Ch
	mov	ax,[bp+6h]
	mov	[0B864h],ax
	lea	di,[bp-8h]
	push	ss
	push	di
	mov	di,0B866h
	push	ds
	push	di
	mov	ax,8h
	push	ax
	call	far 1EDAh:0953h
	lea	di,[bp-8h]
	push	ss
	push	di
	push	word ptr [bp+6h]
	push	cs
	call	1968h

l1AB8_11F5:
	mov	sp,bp
	pop	bp
	retf	6h

;; fn1AB8_11FB: 1AB8:11FB
;;   Called from:
;;     1AB8:1244 (in fn1AB8_122E)
fn1AB8_11FB proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	ax,[0B84Ch]
	xor	dx,dx
	push	dx
	push	ax
	mov	ax,[0B84Ah]
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+4h]
	xor	dx,dx
	call	far 1EDAh:096Fh
	pop	cx
	pop	bx
	call	far 1EDAh:098Ah
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	ret	2h

;; fn1AB8_122E: 1AB8:122E
;;   Called from:
;;     0800:3D1E (in fn0800_3CFA)
fn1AB8_122E proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	xor	ax,ax
	push	ax
	mov	ax,168h
	push	ax
	push	word ptr [bp+6h]
	push	word ptr [bp+6h]
	call	11FBh
	push	ax
	push	cs
	call	1B90h
	pop	bp
	retf	6h

;; fn1AB8_1250: 1AB8:1250
;;   Called from:
;;     133F:0129 (in fn133F_0056)
;;     1AB8:0B32 (in fn1AB8_0AEE)
fn1AB8_1250 proc
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+6h],0Fh
	jbe	125Bh

l1AB8_1259:
	jmp	1281h

l1AB8_125B:
	mov	al,[bp+6h]
	mov	[0B840h],al
	cmp	word ptr [bp+6h],0h
	jnz	126Eh

l1AB8_1267:
	mov	byte ptr [0B87Bh],0h
	jmp	1278h

l1AB8_126E:
	mov	di,[bp+6h]
	mov	al,[di+0B87Bh]
	mov	[0B87Bh],al

l1AB8_1278:
	mov	al,[0B87Bh]
	cbw
	push	ax
	push	cs
	call	1CA4h

l1AB8_1281:
	pop	bp
	retf	2h

;; fn1AB8_1285: 1AB8:1285
;;   Called from:
;;     0C74:016C (in fn0C74_011E)
;;     0C74:025A (in fn0C74_020C)
fn1AB8_1285 proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	al,[0B83Eh]
	xor	ah,ah
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf

;; fn1AB8_129A: 1AB8:129A
;;   Called from:
;;     1AB8:0B22 (in fn1AB8_0AEE)
fn1AB8_129A proc
	push	bp
	mov	bp,sp
	sub	sp,1Ch
	cmp	byte ptr [0B84Eh],0h
	jnz	12AAh

l1AB8_12A7:
	jmp	133Ch

l1AB8_12AA:
	les	di,[bp+6h]
	mov	[bp-1Ah],di
	mov	[bp-18h],es
	les	di,[bp-1Ah]
	cmp	byte ptr es:[di],10h
	jbe	12C2h

l1AB8_12BC:
	mov	byte ptr [bp-3h],10h
	jmp	12CBh

l1AB8_12C2:
	les	di,[bp-1Ah]
	mov	al,es:[di]
	mov	[bp-3h],al

l1AB8_12CB:
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	[bp-1Ch],ax
	xor	ax,ax
	cmp	ax,[bp-1Ch]
	jg	130Dh

l1AB8_12DB:
	mov	[bp-2h],ax
	jmp	12E3h

l1AB8_12E0:
	inc	word ptr [bp-2h]

l1AB8_12E3:
	mov	ax,[bp-2h]
	les	di,[bp-1Ah]
	add	di,ax
	cmp	byte ptr es:[di+1h],0FFh
	jle	1305h

l1AB8_12F2:
	mov	ax,[bp-2h]
	les	di,[bp-1Ah]
	add	di,ax
	mov	al,es:[di+1h]
	mov	di,[bp-2h]
	mov	[di+0B87Bh],al

l1AB8_1305:
	mov	ax,[bp-2h]
	cmp	ax,[bp-1Ch]
	jnz	12E0h

l1AB8_130D:
	les	di,[bp-1Ah]
	cmp	byte ptr es:[di+1h],0FFh
	jz	131Ch

l1AB8_1317:
	mov	byte ptr [0B840h],0h

l1AB8_131C:
	mov	di,0B87Ah
	push	ds
	push	di
	lea	di,[bp-16h]
	push	ss
	push	di
	mov	ax,11h
	push	ax
	call	far 1EDAh:11DFh
	mov	byte ptr [bp-5h],0h
	lea	di,[bp-16h]
	push	ss
	push	di
	push	cs
	call	1CEDh

l1AB8_133C:
	mov	sp,bp
	pop	bp
	retf	4h

;; fn1AB8_1342: 1AB8:1342
;;   Called from:
;;     0800:2946 (in fn0800_2827)
;;     0800:2DE4 (in fn0800_2C0C)
;;     0800:3414 (in fn0800_31B7)
;;     0800:3DFA (in fn0800_3D9D)
;;     0800:40A4 (in fn0800_3D9D)
;;     0800:40B2 (in fn0800_3D9D)
;;     0800:43A5 (in fn0800_4255)
;;     13E2:0072 (in fn13E2_003B)
;;     13E2:00ED (in fn13E2_0080)
;;     13E2:0183 (in fn13E2_00FB)
fn1AB8_1342 proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [0B84Eh],0h
	jz	135Dh

l1AB8_134C:
	mov	al,[0B87Ah]
	xor	ah,ah
	dec	ax
	cmp	ax,[bp+8h]
	jc	135Dh

l1AB8_1357:
	cmp	byte ptr [bp+6h],0h
	jge	135Fh

l1AB8_135D:
	jmp	1380h

l1AB8_135F:
	mov	al,[bp+6h]
	mov	di,[bp+8h]
	mov	[di+0B87Bh],al
	cmp	word ptr [bp+8h],0h
	jnz	1374h

l1AB8_136F:
	mov	byte ptr [0B840h],0h

l1AB8_1374:
	push	word ptr [bp+8h]
	mov	al,[bp+6h]
	cbw
	push	ax
	push	cs
	call	1CD7h

l1AB8_1380:
	pop	bp
	retf	4h

;; fn1AB8_1384: 1AB8:1384
;;   Called from:
;;     1AB8:0B19 (in fn1AB8_0AEE)
fn1AB8_1384 proc
	push	bp
	mov	bp,sp
	push	cs
	call	1C6Ah
	mov	di,ax
	mov	es,dx
	push	es
	push	di
	les	di,[bp+6h]
	push	es
	push	di
	mov	ax,11h
	push	ax
	call	far 1EDAh:0953h
	pop	bp
	retf	4h

;; fn1AB8_13A3: 1AB8:13A3
;;   Called from:
;;     0800:0153 (in fn0800_0147)
;;     0800:043E (in fn0800_03F8)
;;     0800:0DAF (in fn0800_0D20)
;;     0C74:043C (in fn0C74_03D4)
;;     0C74:044D (in fn0C74_03D4)
;;     0C74:0615 (in fn0C74_05B8)
;;     0C74:0E5C (in fn0C74_0E2E)
;;     0C74:0E8E (in fn0C74_0E2E)
;;     0C74:0FAD (in fn0C74_0FA1)
;;     0C74:1177 (in fn0C74_0FA1)
;;     0C74:13D0 (in fn0C74_0FA1)
;;     0C74:152E (in fn0C74_0FA1)
;;     0C74:16F4 (in fn0C74_0FA1)
;;     0C74:178D (in fn0C74_0FA1)
;;     0C74:180D (in fn0C74_0FA1)
;;     0C74:19AA (in fn0C74_0FA1)
;;     0C74:1A50 (in fn0C74_0FA1)
;;     0C74:1B94 (in fn0C74_1B3B)
;;     0C74:1DC3 (in fn0C74_1D95)
;;     0C74:1DF5 (in fn0C74_1D95)
;;     0C74:1F14 (in fn0C74_1F08)
;;     0C74:20DE (in fn0C74_1F08)
;;     0C74:2337 (in fn0C74_1F08)
;;     0C74:2495 (in fn0C74_1F08)
;;     0C74:2690 (in fn0C74_1F08)
;;     0C74:279E (in fn0C74_1F08)
;;     0C74:2942 (in fn0C74_1F08)
;;     0C74:29E8 (in fn0C74_1F08)
;;     0C74:2B04 (in fn0C74_2AD9)
;;     0C74:2BCD (in fn0C74_2BBD)
;;     0C74:2BE1 (in fn0C74_2BBD)
;;     0C74:2EEF (in fn0C74_2E5A)
;;     0C74:2F41 (in fn0C74_2E5A)
;;     0C74:303B (in fn0C74_2E5A)
;;     0C74:32CA (in fn0C74_3236)
;;     0C74:331C (in fn0C74_3236)
;;     0C74:3416 (in fn0C74_3236)
;;     0C74:4EF9 (in fn0C74_4DAC)
;;     0C74:50E4 (in fn0C74_4FD7)
;;     0C74:539E (in fn0C74_5258)
;;     1229:006A (in fn1229_0040)
fn1AB8_13A3 proc
	push	bp
	mov	bp,sp
	sub	sp,4h
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	19A6h
	mov	[bp-4h],ax
	cmp	word ptr [bp-4h],0FFh
	jnz	13C8h

l1AB8_13C2:
	mov	word ptr [0B818h],0FFF5h

l1AB8_13C8:
	mov	ax,[bp-4h]
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf	8h

;; fn1AB8_13D7: 1AB8:13D7
;;   Called from:
;;     0800:0306 (in fn0800_01FE)
;;     0800:0A45 (in fn0800_09C2)
;;     0800:11AB (in fn0800_0D20)
;;     0800:257F (in fn0800_2401)
;;     0C74:04EF (in fn0C74_03D4)
;;     0C74:0699 (in fn0C74_05B8)
;;     0C74:0700 (in fn0C74_06B7)
;;     0C74:0D34 (in fn0C74_0CFA)
;;     0C74:0D83 (in fn0C74_0D43)
;;     0C74:0DD4 (in fn0C74_0D94)
;;     0C74:0E1F (in fn0C74_0DE5)
;;     0C74:0F53 (in fn0C74_0E2E)
;;     0C74:0F76 (in fn0C74_0E2E)
;;     0C74:1066 (in fn0C74_0FA1)
;;     0C74:107C (in fn0C74_0FA1)
;;     0C74:12BA (in fn0C74_0FA1)
;;     0C74:12D7 (in fn0C74_0FA1)
;;     0C74:138D (in fn0C74_0FA1)
;;     0C74:1442 (in fn0C74_0FA1)
;;     0C74:14EB (in fn0C74_0FA1)
;;     0C74:15A0 (in fn0C74_0FA1)
;;     0C74:173D (in fn0C74_0FA1)
;;     0C74:17DE (in fn0C74_0FA1)
;;     0C74:18A5 (in fn0C74_0FA1)
;;     0C74:1A1A (in fn0C74_0FA1)
;;     0C74:1AC2 (in fn0C74_0FA1)
;;     0C74:1C14 (in fn0C74_1B3B)
;;     0C74:1C89 (in fn0C74_1B3B)
;;     0C74:1D3E (in fn0C74_1B3B)
;;     0C74:1EBA (in fn0C74_1D95)
;;     0C74:1EDD (in fn0C74_1D95)
;;     0C74:1FCD (in fn0C74_1F08)
;;     0C74:1FE3 (in fn0C74_1F08)
;;     0C74:2221 (in fn0C74_1F08)
;;     0C74:223E (in fn0C74_1F08)
;;     0C74:22F4 (in fn0C74_1F08)
;;     0C74:23A9 (in fn0C74_1F08)
;;     0C74:2452 (in fn0C74_1F08)
;;     0C74:2507 (in fn0C74_1F08)
;;     0C74:2728 (in fn0C74_1F08)
;;     0C74:2861 (in fn0C74_1F08)
;;     0C74:29B2 (in fn0C74_1F08)
;;     0C74:2A5A (in fn0C74_1F08)
;;     0C74:2B69 (in fn0C74_2AD9)
;;     0C74:2C56 (in fn0C74_2BBD)
;;     0C74:2CBD (in fn0C74_2BBD)
;;     0C74:2F9A (in fn0C74_2E5A)
;;     0C74:30C7 (in fn0C74_2E5A)
;;     0C74:3116 (in fn0C74_2E5A)
;;     0C74:312F (in fn0C74_2E5A)
;;     0C74:319A (in fn0C74_2E5A)
;;     0C74:3218 (in fn0C74_2E5A)
;;     0C74:3375 (in fn0C74_3236)
;;     0C74:34A2 (in fn0C74_3236)
;;     0C74:34F0 (in fn0C74_3236)
;;     0C74:350A (in fn0C74_3236)
;;     0C74:3579 (in fn0C74_3236)
;;     0C74:35F7 (in fn0C74_3236)
;;     0C74:379B (in fn0C74_3615)
;;     0C74:3946 (in fn0C74_37C3)
;;     0C74:4937 (in fn0C74_45CE)
;;     0C74:4D4A (in fn0C74_4999)
;;     0C74:4F5D (in fn0C74_4DAC)
;;     0C74:5141 (in fn0C74_4FD7)
;;     0C74:540D (in fn0C74_5258)
;;     1229:0361 (in fn1229_0040)
;;     1229:0B35 (in fn1229_0AA8)
;;     1229:0C9E (in fn1229_0C58)
;;     1229:0F0A (in fn1229_0DCC)
;;     1229:0F73 (in fn1229_0DCC)
fn1AB8_13D7 proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	les	di,[bp+8h]
	mov	ax,es:[di+2h]
	mov	[bp-2h],ax
	mov	ax,[bp+0Ch]
	add	ax,[0B854h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[0B7C4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	les	di,[bp+8h]
	mov	es:[di+2h],ax
	les	di,[bp+8h]
	mov	ax,es:[di+2h]
	cmp	ax,[bp-2h]
	jbe	1419h

l1AB8_140F:
	mov	ax,[bp-2h]
	les	di,[bp+8h]
	mov	es:[di+2h],ax

l1AB8_1419:
	les	di,[bp+8h]
	mov	ax,es:[di]
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Eh]
	add	ax,[0B852h]
	cwd
	add	ax,cx
	adc	dx,bx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[0B7C2h]
	xor	dx,dx
	cmp	dx,bx
	jl	1464h

l1AB8_143E:
	jg	1444h

l1AB8_1440:
	cmp	ax,cx
	jc	1464h

l1AB8_1444:
	mov	ax,[bp+0Eh]
	add	ax,[0B852h]
	or	ax,ax
	jl	1464h

l1AB8_144F:
	les	di,[bp+8h]
	cmp	word ptr es:[di+2h],0h
	jc	1464h

l1AB8_1459:
	mov	ax,[bp+0Ch]
	add	ax,[0B854h]
	or	ax,ax
	jge	1470h

l1AB8_1464:
	mov	ax,[bp-2h]
	les	di,[bp+8h]
	mov	es:[di+2h],ax
	jmp	148Ch

l1AB8_1470:
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	les	di,[bp+8h]
	push	es
	push	di
	push	word ptr [bp+6h]
	push	cs
	call	1E9Fh
	mov	ax,[bp-2h]
	les	di,[bp+8h]
	mov	es:[di+2h],ax

l1AB8_148C:
	mov	sp,bp
	pop	bp
	retf	0Ah

;; fn1AB8_1492: 1AB8:1492
;;   Called from:
;;     0800:0FF9 (in fn0800_0D20)
;;     1229:0239 (in fn1229_0040)
fn1AB8_1492 proc
	push	bp
	mov	bp,sp
	sub	sp,100h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	push	word ptr [0B844h]
	push	word ptr [0B846h]
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	cs
	call	1D82h
	cmp	word ptr [0B892h],0h
	jnz	14EEh

l1AB8_14C6:
	cmp	word ptr [0B88Eh],0h
	jnz	14EEh

l1AB8_14CD:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	cs
	call	1E0Bh
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[0B844h]
	cwd
	add	ax,cx
	adc	dx,bx
	push	ax
	push	word ptr [0B846h]
	push	cs
	call	108Bh

l1AB8_14EE:
	mov	sp,bp
	pop	bp
	retf	4h

;; fn1AB8_14F4: 1AB8:14F4
;;   Called from:
;;     0800:0505 (in fn0800_04E3)
;;     0800:063B (in fn0800_0619)
;;     0800:077B (in fn0800_0768)
;;     0800:0E0F (in fn0800_0D20)
;;     0800:14ED (in fn0800_149F)
;;     0800:16D0 (in fn0800_166D)
;;     0800:18C9 (in fn0800_184C)
;;     0800:1A20 (in fn0800_19E1)
;;     0800:1E97 (in fn0800_1E3F)
;;     0800:2046 (in fn0800_2004)
;;     0800:21FA (in fn0800_21E7)
;;     0800:25C1 (in fn0800_2401)
;;     0800:28E2 (in fn0800_2827)
;;     0800:2D3A (in fn0800_2C0C)
;;     0800:2F68 (in fn0800_2C0C)
;;     0800:329C (in fn0800_31B7)
;;     0800:33C6 (in fn0800_31B7)
;;     0800:3A44 (in fn0800_391E)
;;     0800:43B9 (in fn0800_4255)
;;     1229:00CB (in fn1229_0040)
;;     1229:0B74 (in fn1229_0AA8)
;;     133F:0166 (in fn133F_014B)
;;     1AB8:0B93 (in fn1AB8_0AEE)
fn1AB8_14F4 proc
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+8h],0h
	jc	150Fh

l1AB8_14FD:
	cmp	word ptr [bp+8h],2h
	ja	150Fh

l1AB8_1503:
	cmp	word ptr [bp+6h],0h
	jc	150Fh

l1AB8_1509:
	cmp	word ptr [bp+6h],2h
	jbe	1517h

l1AB8_150F:
	mov	word ptr [0B818h],0FFF5h
	jmp	152Dh

l1AB8_1517:
	mov	ax,[bp+8h]
	mov	[0B892h],ax
	mov	ax,[bp+6h]
	mov	[0B894h],ax
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1992h

l1AB8_152D:
	pop	bp
	retf	4h
1AB8:1531    04 2E 43 48 52                                ..CHR          

;; fn1AB8_1536: 1AB8:1536
;;   Called from:
;;     0800:04FC (in fn0800_04E3)
;;     0800:0632 (in fn0800_0619)
;;     0800:0772 (in fn0800_0768)
;;     0800:0E06 (in fn0800_0D20)
;;     0800:14F8 (in fn0800_149F)
;;     0800:16DB (in fn0800_166D)
;;     0800:18C0 (in fn0800_184C)
;;     0800:1A03 (in fn0800_19E1)
;;     0800:1EA2 (in fn0800_1E3F)
;;     0800:2051 (in fn0800_2004)
;;     0800:21F1 (in fn0800_21E7)
;;     0800:2230 (in fn0800_21E7)
;;     0800:24B2 (in fn0800_2401)
;;     0800:25B8 (in fn0800_2401)
;;     0800:28D9 (in fn0800_2827)
;;     0800:2D31 (in fn0800_2C0C)
;;     0800:2F5F (in fn0800_2C0C)
;;     0800:3293 (in fn0800_31B7)
;;     0800:33BD (in fn0800_31B7)
;;     0800:3A4F (in fn0800_391E)
;;     0800:3DCF (in fn0800_3D9D)
;;     0800:43B0 (in fn0800_4255)
;;     1229:00C2 (in fn1229_0040)
;;     1229:0B7F (in fn1229_0AA8)
;;     133F:0173 (in fn133F_014B)
;;     1AB8:0B88 (in fn1AB8_0AEE)
fn1AB8_1536 proc
	push	bp
	mov	bp,sp
	sub	sp,10Ah
	cmp	word ptr [bp+0Ah],14h
	ja	155Eh

l1AB8_1543:
	cmp	word ptr [bp+0Ah],0h
	jc	155Eh

l1AB8_1549:
	cmp	word ptr [bp+0Ah],0h
	jz	1571h

l1AB8_154F:
	mov	ax,0Fh
	mul	word ptr [bp+0Ah]
	mov	di,ax
	cmp	byte ptr [di+5215h],0h
	jnz	1571h

l1AB8_155E:
	mov	word ptr [0B818h],0FFF2h
	xor	ax,ax
	mov	[bp+0Ah],ax
	mov	word ptr [bp+6h],1h
	jmp	175Eh

l1AB8_1571:
	cmp	word ptr [bp+0Ah],0h
	jnz	157Ah

l1AB8_1577:
	jmp	175Eh

l1AB8_157A:
	mov	ax,[bp+0Ah]
	cmp	ax,[0B88Ch]
	jnz	1586h

l1AB8_1583:
	jmp	175Eh

l1AB8_1586:
	mov	ax,[bp+0Ah]
	cmp	ax,[0B74Ah]
	jnz	1592h

l1AB8_158F:
	jmp	1747h

l1AB8_1592:
	cmp	word ptr [0B74Ah],0h
	jz	15E8h

l1AB8_1599:
	mov	ax,0Fh
	mul	word ptr [0B74Ah]
	mov	di,ax
	add	di,520Bh
	mov	[bp-0Ah],di
	mov	[bp-8h],ds
	les	di,[bp-0Ah]
	cmp	word ptr es:[di+8h],0h
	jz	15E8h

l1AB8_15B6:
	les	di,[bp-0Ah]
	push	es
	push	di
	les	di,[bp-0Ah]
	push	word ptr es:[di+8h]
	call	dword ptr [0B6C6h]
	les	di,[bp-0Ah]
	xor	ax,ax
	mov	es:[di],ax
	mov	es:[di+2h],ax
	les	di,[bp-0Ah]
	xor	ax,ax
	mov	es:[di+4h],ax
	mov	es:[di+6h],ax
	les	di,[bp-0Ah]
	xor	ax,ax
	mov	es:[di+8h],ax

l1AB8_15E8:
	mov	ax,0Fh
	mul	word ptr [bp+0Ah]
	mov	di,ax
	add	di,520Bh
	mov	[bp-0Ah],di
	mov	[bp-8h],ds
	les	di,[bp-0Ah]
	mov	ax,es:[di+4h]
	or	ax,es:[di+6h]
	jz	160Ah

l1AB8_1607:
	jmp	1741h

l1AB8_160A:
	lea	di,[bp+0FEF6h]
	push	ss
	push	di
	les	di,[bp-0Ah]
	add	di,0Ah
	push	es
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,1531h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,0B74Ch
	push	ds
	push	di
	mov	ax,8h
	push	ax
	call	far 1EDAh:0A39h
	mov	di,0B764h
	push	ds
	push	di
	mov	di,0B74Ch
	push	ds
	push	di
	lea	di,[bp-2h]
	push	ss
	push	di
	mov	ax,0FFF3h
	push	ax
	call	0887h
	or	al,al
	jnz	166Ah

l1AB8_1650:
	cmp	word ptr [0B818h],0FDh
	jnz	165Dh

l1AB8_1657:
	mov	word ptr [0B818h],0FFF8h

l1AB8_165D:
	xor	ax,ax
	mov	[bp+0Ah],ax
	mov	word ptr [bp+6h],1h
	jmp	175Eh

l1AB8_166A:
	mov	ax,[536Eh]
	mov	dx,[5370h]
	mov	[0B7BCh],ax
	mov	[0B7BEh],dx
	mov	ax,50Bh
	mov	dx,1AB8h
	mov	[536Eh],ax
	mov	[5370h],dx
	lea	di,[bp-6h]
	push	ss
	push	di
	push	word ptr [bp-2h]
	call	dword ptr [0B6C2h]
	mov	ax,[0B7BCh]
	mov	dx,[0B7BEh]
	mov	[536Eh],ax
	mov	[5370h],dx
	mov	ax,[bp-6h]
	or	ax,[bp-4h]
	jnz	16C4h

l1AB8_16A7:
	mov	di,0B6CAh
	push	ds
	push	di
	call	far 1EDAh:1051h
	mov	word ptr [0B818h],0FFF7h
	xor	ax,ax
	mov	[bp+0Ah],ax
	mov	word ptr [bp+6h],1h
	jmp	175Eh

l1AB8_16C4:
	mov	di,0B6CAh
	push	ds
	push	di
	les	di,[bp-6h]
	push	es
	push	di
	push	word ptr [bp-2h]
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	mov	di,0B6CAh
	push	ds
	push	di
	call	far 1EDAh:1051h
	call	far 1EDAh:04A2h
	or	ax,ax
	jnz	1709h

l1AB8_16ED:
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	push	cs
	call	06CAh
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ah]
	xor	dx,dx
	cmp	dx,bx
	jnz	1709h

l1AB8_1705:
	cmp	ax,cx
	jz	1727h

l1AB8_1709:
	mov	word ptr [0B818h],0FFF3h
	lea	di,[bp-6h]
	push	ss
	push	di
	push	word ptr [bp-2h]
	call	dword ptr [0B6C6h]
	xor	ax,ax
	mov	[bp+0Ah],ax
	mov	word ptr [bp+6h],1h
	jmp	175Eh

l1AB8_1727:
	mov	ax,[bp-2h]
	les	di,[bp-0Ah]
	mov	es:[di+8h],ax
	mov	ax,[bp-6h]
	mov	dx,[bp-4h]
	les	di,[bp-0Ah]
	mov	es:[di],ax
	mov	es:[di+2h],dx

l1AB8_1741:
	mov	ax,[bp+0Ah]
	mov	[0B74Ah],ax

l1AB8_1747:
	mov	ax,0Fh
	mul	word ptr [bp+0Ah]
	mov	di,ax
	mov	ax,[di+520Fh]
	mov	dx,[di+5211h]
	mov	[0B836h],ax
	mov	[0B838h],dx

l1AB8_175E:
	mov	ax,[bp+0Ah]
	mov	[0B88Ch],ax
	mov	ax,[bp+8h]
	mov	[0B88Eh],ax
	mov	ax,[bp+6h]
	mov	[0B890h],ax
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1DA6h
	mov	sp,bp
	pop	bp
	retf	6h

;; fn1AB8_1783: 1AB8:1783
;;   Called from:
;;     0800:1047 (in fn0800_0D20)
;;     0800:1073 (in fn0800_0D20)
;;     0800:10EE (in fn0800_0D20)
;;     0800:1126 (in fn0800_0D20)
;;     0800:1A7F (in fn0800_19E1)
;;     0800:1AA3 (in fn0800_19E1)
;;     1229:02C5 (in fn1229_0040)
;;     1229:02FD (in fn1229_0040)
;;     133F:0194 (in fn133F_014B)
;;     133F:01BC (in fn133F_014B)
fn1AB8_1783 proc
	push	bp
	mov	bp,sp
	sub	sp,102h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	push	cs
	call	1E26h
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf	4h

;; fn1AB8_17AE: 1AB8:17AE
;;   Called from:
;;     0800:425F (in fn0800_4255)
fn1AB8_17AE proc
	push	bp
	mov	bp,sp
	xor	ax,ax
	mov	[0B818h],ax
	mov	word ptr [0B7B6h],1000h
	push	cs
	call	1A84h
	call	0813h
	mov	ax,51Fh
	mov	dx,1AB8h
	mov	[0B6C2h],ax
	mov	[0B6C4h],dx
	mov	ax,538h
	mov	dx,1AB8h
	mov	[0B6C6h],ax
	mov	[0B6C8h],dx
	mov	byte ptr [0B74Ch],0h
	mov	byte ptr [0B756h],0h
	mov	word ptr [0B7B8h],6h
	mov	word ptr [0B7BAh],0Ah
	mov	word ptr [fn0800_3850],1h
	mov	word ptr [0B84Ah],1h
	mov	word ptr [0B84Ch],1h
	pop	bp
	retf

;; fn1AB8_1807: 1AB8:1807
;;   Called from:
;;     1AB8:1946 (in fn1AB8_194E)
;;     1AB8:19C9 (in fn1AB8_19A6)
fn1AB8_1807 proc
	push	es
	push	bx
	retf

;; fn1AB8_180A: 1AB8:180A
;;   Called from:
;;     1AB8:1AA9 (in fn1AB8_1AA6)
fn1AB8_180A proc
	cmp	byte ptr [0B8A3h],0FFh
	jnz	1848h

l1AB8_1811:
	cmp	byte ptr [fn0800_3850],0A5h
	jnz	181Eh

l1AB8_1818:
	mov	byte ptr [0B8A3h],0h
	ret

l1AB8_181E:
	mov	ah,0Fh
	int	10h
	mov	[0B8A3h],al
	mov	ax,40h
	mov	es,ax
	mov	bx,10h
	mov	al,es:[bx]
	mov	[0B8A4h],al
	cmp	byte ptr [0B89Ch],5h
	jz	1848h

l1AB8_183A:
	cmp	byte ptr [0B89Ch],7h
	jz	1848h

l1AB8_1841:
	and	al,0CFh
	or	al,20h
	mov	es:[bx],al

l1AB8_1848:
	ret
1AB8:1849                            55 8B EC BE 06 00 FF          U......
1AB8:1850 1E 20 B8 5D CB                                  . .].           

;; fn1AB8_1855: 1AB8:1855
;;   Called from:
;;     1AB8:0E25 (in fn1AB8_0BAE)
fn1AB8_1855 proc
	mov	byte ptr [0B8A3h],0FFh
	push	bp
	mov	bp,sp
	xor	ax,ax
	mov	ch,[0B89Dh]
	cmp	byte ptr [0B89Ch],5h
	jnz	186Ch

l1AB8_186A:
	mov	ch,3h

l1AB8_186C:
	mov	cl,[0B89Bh]
	les	bx,[bp+6h]
	mov	ah,1h
	cmp	byte ptr es:[bx+16h],0h
	jnz	1882h

l1AB8_187C:
	xor	ah,ah
	les	bx,[0B832h]

l1AB8_1882:
	mov	si,0h
	call	dword ptr [0B820h]
	mov	[0B83Ah],bx
	mov	[0B83Ch],es
	pop	bp
	retf	4h

;; fn1AB8_1895: 1AB8:1895
;;   Called from:
;;     1AB8:1016 (in fn1AB8_0F93)
fn1AB8_1895 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Eh]
	mov	bx,[bp+0Ch]
	mov	cx,[bp+0Ah]
	mov	dx,[bp+8h]
	cmp	byte ptr [bp+6h],0h
	jnz	18ADh

l1AB8_18AA:
	or	ah,80h

l1AB8_18AD:
	mov	si,38h
	call	dword ptr [0B820h]
	pop	bp
	retf	0Ah
1AB8:18B8                         55 8B EC E8 4C FF 8A 46         U...L..F
1AB8:18C0 06 3C 0A 73 0F A2 9B B8 FF 36 A1 B8 FF 36 9F B8 .<.s.....6...6..
1AB8:18D0 0E E8 86 FF C4 1E 9F B8 BE 02 00 FF 1E 20 B8 5D ............. .]
1AB8:18E0 CA 02 00                                        ...             

;; fn1AB8_18E3: 1AB8:18E3
;;   Called from:
;;     1AB8:0E8B (in fn1AB8_0E88)
fn1AB8_18E3 proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [0B8A3h],0FFh
	jz	1910h

l1AB8_18ED:
	mov	si,6h
	call	dword ptr [0B820h]
	cmp	byte ptr [fn0800_3850],0A5h
	jz	1910h

l1AB8_18FB:
	mov	ax,40h
	mov	es,ax
	mov	bx,10h
	mov	al,[0B8A4h]
	mov	es:[bx],al
	xor	ah,ah
	mov	al,[0B8A3h]
	int	10h

l1AB8_1910:
	mov	byte ptr [0B8A3h],0FFh
	pop	bp
	retf
1AB8:1917                      55 8B EC 8A 46 06 32 E4 50        U...F.2.P
1AB8:1920 BE 32 00 FF 1E 20 B8 26 8B 5F 0C EB 18 5D CA 02 .2... .&._...]..
1AB8:1930 00 55 8B EC 8A 46 06 32 E4 50 BE 32 00 FF 1E 20 .U...F.2.P.2... 
1AB8:1940 B8 26 8B 5F 0A                                  .&._.           

l1AB8_1945:
	pop	ax
	push	cs
	call	1807h
	pop	bp
	retf	2h

;; fn1AB8_194E: 1AB8:194E
;;   Called from:
;;     1AB8:0B9A (in fn1AB8_0AEE)
fn1AB8_194E proc
	push	bp
	mov	bp,sp
	mov	al,[bp+6h]
	xor	ah,ah
	push	ax
	mov	si,32h
	call	dword ptr [0B820h]
	mov	bx,es:[bx+0Eh]
	jmp	1945h
1AB8:1964             5D CA 02 00                             ]...        

;; fn1AB8_1968: 1AB8:1968
;;   Called from:
;;     1AB8:11F1 (in fn1AB8_11A0)
fn1AB8_1968 proc
	push	bp
	mov	bp,sp
	mov	ah,[bp+6h]
	mov	[0B83Fh],ah
	mov	al,[0B83Eh]
	mov	si,1Eh
	call	dword ptr [0B820h]
	mov	byte ptr [0B842h],0Ch
	les	bx,[bp+8h]
	mov	ax,0FFFFh
	mov	si,20h
	call	dword ptr [0B820h]
	pop	bp
	retf	6h

;; fn1AB8_1992: 1AB8:1992
;;   Called from:
;;     1AB8:1529 (in fn1AB8_14F4)
fn1AB8_1992 proc
	push	bp
	mov	bp,sp
	mov	ah,[bp+8h]
	mov	al,[bp+6h]
	mov	si,2Ah
	call	dword ptr [0B820h]
	pop	bp
	retf	4h

;; fn1AB8_19A6: 1AB8:19A6
;;   Called from:
;;     1AB8:13B5 (in fn1AB8_13A3)
fn1AB8_19A6 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+8h]
	sub	ax,[bp+0Ch]
	jns	19B3h

l1AB8_19B1:
	neg	ax

l1AB8_19B3:
	inc	ax
	add	ax,7h
	shr	ax,1h
	shr	ax,1h
	shr	ax,1h
	push	ax
	mov	si,32h
	call	dword ptr [0B820h]
	mov	bx,es:[bx+8h]
	push	cs
	call	1807h
	pop	bx
	mul	bx
	mov	cx,[bp+6h]
	sub	cx,[bp+0Ah]
	jns	19DAh

l1AB8_19D8:
	neg	cx

l1AB8_19DA:
	inc	cx
	mul	cx
	add	ax,6h
	jc	19E6h

l1AB8_19E2:
	and	dx,dx
	jz	19EAh

l1AB8_19E6:
	xor	ax,ax
	mov	dx,ax

l1AB8_19EA:
	pop	bp
	retf	8h

;; fn1AB8_19EE: 1AB8:19EE
;;   Called from:
;;     1AB8:0C9C (in fn1AB8_0BAE)
;;     1AB8:0CC7 (in fn1AB8_0BAE)
fn1AB8_19EE proc
	push	bp
	mov	bp,sp
	mov	byte ptr [0B89Ah],0FFh
	mov	byte ptr [0B89Bh],0h
	mov	byte ptr [0B89Dh],0Ah
	les	di,[bp+0Ah]
	mov	al,es:[di]
	mov	[0B89Ch],al
	and	al,al
	jnz	1A15h

l1AB8_1A0D:
	call	1A62h
	mov	al,[0B89Ah]
	jmp	1A44h

l1AB8_1A15:
	les	di,[bp+6h]
	mov	al,es:[di]
	mov	[0B89Bh],al
	les	di,[bp+0Ah]
	mov	bl,es:[di]
	and	bl,bl
	js	1A4Ch

l1AB8_1A28:
	mov	al,0Ah
	sub	al,bl
	jnc	1A32h

l1AB8_1A2E:
	neg	al
	jmp	1A44h

l1AB8_1A32:
	xor	bh,bh
	mov	al,cs:[bx+1ED5h]
	mov	[0B89Dh],al
	mov	al,cs:[bx+1EB9h]
	mov	[0B89Ah],al

l1AB8_1A44:
	les	di,[bp+0Eh]
	xor	ah,ah
	mov	es:[di],ax

l1AB8_1A4C:
	pop	bp
	retf	0Ch
1AB8:1A50 55 8B EC FF 36 9A B8 E8 08 00 8F 06 9A B8 5D CA U...6.........].
1AB8:1A60 08 00                                           ..              

;; fn1AB8_1A62: 1AB8:1A62
;;   Called from:
;;     1AB8:1A0D (in fn1AB8_19EE)
fn1AB8_1A62 proc
	push	bp
	call	1EE3h
	pop	bp
	les	di,[bp+0Ah]
	mov	al,[0B89Ch]
	xor	ah,ah
	cmp	al,0FFh
	jnz	1A75h

l1AB8_1A73:
	mov	ah,al

l1AB8_1A75:
	mov	es:[di],ax
	xor	ah,ah
	mov	al,[0B89Bh]
	les	di,[bp+6h]
	mov	es:[di],ax
	ret

;; fn1AB8_1A84: 1AB8:1A84
;;   Called from:
;;     1AB8:17BC (in fn1AB8_17AE)
fn1AB8_1A84 proc
	xor	ax,ax
	mov	byte ptr [0B89Ah],0FFh
	mov	[0B89Bh],al
	mov	[0B89Ch],al
	mov	[0B89Dh],al
	mov	[0B89Eh],al
	mov	[0B89Fh],ax
	mov	[0B8A1h],ax
	mov	byte ptr [0B8A3h],0FFh
	mov	[0B8A4h],al
	retf

;; fn1AB8_1AA6: 1AB8:1AA6
;;   Called from:
;;     1AB8:0E49 (in fn1AB8_0BAE)
fn1AB8_1AA6 proc
	push	bp
	mov	bp,sp
	call	180Ah
	les	bx,[bp+6h]
	mov	[0B89Fh],bx
	mov	[0B8A1h],es
	mov	si,2h
	call	dword ptr [0B820h]
	pop	bp
	retf	4h

;; fn1AB8_1AC2: 1AB8:1AC2
;;   Called from:
;;     1AB8:0F83 (in fn1AB8_0F80)
fn1AB8_1AC2 proc
	push	bp
	mov	bp,sp
	mov	si,4h
	call	dword ptr [0B820h]
	pop	bp
	retf

;; fn1AB8_1ACE: 1AB8:1ACE
;;   Called from:
;;     1AB8:1094 (in fn1AB8_108B)
fn1AB8_1ACE proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+8h]
	mov	bx,[bp+6h]
	mov	si,8h
	call	dword ptr [0B820h]
	pop	bp
	retf	4h
1AB8:1AE2       55 8B EC 8B 46 08 8B 5E 06 BE 0A 00 FF 1E   U...F..^......
1AB8:1AF0 20 B8 5D CA 04 00                                .]...          

;; fn1AB8_1AF6: 1AB8:1AF6
;;   Called from:
;;     0800:0F02 (in fn0800_0D20)
;;     0800:0F38 (in fn0800_0D20)
;;     0800:0F6C (in fn0800_0D20)
;;     0800:1358 (in fn0800_1315)
;;     0800:1372 (in fn0800_1315)
;;     0800:138B (in fn0800_1315)
;;     0800:13A7 (in fn0800_1315)
;;     0800:13C2 (in fn0800_1315)
;;     0800:13DA (in fn0800_1315)
;;     0800:13FC (in fn0800_1315)
;;     0800:1415 (in fn0800_1315)
;;     0800:142F (in fn0800_1315)
;;     0800:144C (in fn0800_1315)
;;     0800:1465 (in fn0800_1315)
;;     0800:1476 (in fn0800_1315)
;;     0800:1B6B (in fn0800_19E1)
;;     0800:1B89 (in fn0800_19E1)
;;     0800:1BAD (in fn0800_19E1)
;;     0800:1BDA (in fn0800_19E1)
;;     0800:1BF9 (in fn0800_19E1)
;;     0800:1C1C (in fn0800_19E1)
;;     0800:1C4F (in fn0800_19E1)
;;     0800:1C6C (in fn0800_19E1)
;;     0800:1C91 (in fn0800_19E1)
;;     0800:1CBF (in fn0800_19E1)
;;     0800:1CDC (in fn0800_19E1)
;;     0800:1CF8 (in fn0800_19E1)
;;     0800:3729 (in fn0800_36E6)
;;     0800:3743 (in fn0800_36E6)
;;     0800:375C (in fn0800_36E6)
;;     0800:3778 (in fn0800_36E6)
;;     0800:3793 (in fn0800_36E6)
;;     0800:37AB (in fn0800_36E6)
;;     0800:37CD (in fn0800_36E6)
;;     0800:37E6 (in fn0800_36E6)
;;     0800:3800 (in fn0800_36E6)
;;     0800:381D (in fn0800_36E6)
;;     0800:3836 (in fn0800_36E6)
;;     0800:3847 (in fn0800_36E6)
;;     0C74:10CB (in fn0C74_0FA1)
;;     0C74:10EC (in fn0C74_0FA1)
;;     0C74:1774 (in fn0C74_0FA1)
;;     0C74:1923 (in fn0C74_0FA1)
;;     0C74:1945 (in fn0C74_0FA1)
;;     0C74:2032 (in fn0C74_1F08)
;;     0C74:2053 (in fn0C74_1F08)
;;     0C74:28BB (in fn0C74_1F08)
;;     0C74:28DD (in fn0C74_1F08)
;;     0C74:2C2E (in fn0C74_2BBD)
;;     0C74:2DFE (in fn0C74_2BBD)
;;     0C74:2E16 (in fn0C74_2BBD)
;;     0C74:2FCD (in fn0C74_2E5A)
;;     0C74:33A8 (in fn0C74_3236)
;;     0C74:39B2 (in fn0C74_396E)
;;     0C74:3A31 (in fn0C74_396E)
;;     0C74:3A72 (in fn0C74_396E)
;;     0C74:3A9B (in fn0C74_396E)
;;     0C74:3B08 (in fn0C74_396E)
;;     0C74:3B5C (in fn0C74_396E)
;;     0C74:3BAD (in fn0C74_396E)
;;     0C74:3BF4 (in fn0C74_396E)
;;     0C74:3C2F (in fn0C74_396E)
;;     0C74:3C4F (in fn0C74_396E)
;;     0C74:3CA4 (in fn0C74_396E)
;;     0C74:3CEC (in fn0C74_396E)
;;     0C74:3D27 (in fn0C74_396E)
;;     0C74:3D47 (in fn0C74_396E)
;;     0C74:3DB7 (in fn0C74_396E)
;;     0C74:3E13 (in fn0C74_396E)
;;     0C74:3E64 (in fn0C74_396E)
;;     0C74:3EB2 (in fn0C74_396E)
;;     0C74:3EE0 (in fn0C74_396E)
;;     0C74:3F10 (in fn0C74_396E)
;;     0C74:3F58 (in fn0C74_396E)
;;     0C74:3FC9 (in fn0C74_3F74)
;;     0C74:4074 (in fn0C74_3F74)
;;     0C74:40B3 (in fn0C74_3F74)
;;     0C74:40DA (in fn0C74_3F74)
;;     0C74:414D (in fn0C74_3F74)
;;     0C74:419E (in fn0C74_3F74)
;;     0C74:41F4 (in fn0C74_3F74)
;;     0C74:423B (in fn0C74_3F74)
;;     0C74:4277 (in fn0C74_3F74)
;;     0C74:4297 (in fn0C74_3F74)
;;     0C74:42EC (in fn0C74_3F74)
;;     0C74:4334 (in fn0C74_3F74)
;;     0C74:4370 (in fn0C74_3F74)
;;     0C74:4390 (in fn0C74_3F74)
;;     0C74:43FE (in fn0C74_3F74)
;;     0C74:445F (in fn0C74_3F74)
;;     0C74:44B5 (in fn0C74_3F74)
;;     0C74:4501 (in fn0C74_3F74)
;;     0C74:452D (in fn0C74_3F74)
;;     0C74:455B (in fn0C74_3F74)
;;     0C74:45B2 (in fn0C74_3F74)
;;     0C74:4612 (in fn0C74_45CE)
;;     0C74:4691 (in fn0C74_45CE)
;;     0C74:46FC (in fn0C74_45CE)
;;     0C74:471C (in fn0C74_45CE)
;;     0C74:4805 (in fn0C74_45CE)
;;     0C74:4824 (in fn0C74_45CE)
;;     0C74:4864 (in fn0C74_45CE)
;;     0C74:49EE (in fn0C74_4999)
;;     0C74:4A99 (in fn0C74_4999)
;;     0C74:4B04 (in fn0C74_4999)
;;     0C74:4B24 (in fn0C74_4999)
;;     0C74:4C07 (in fn0C74_4999)
;;     0C74:4C26 (in fn0C74_4999)
;;     0C74:4C75 (in fn0C74_4999)
;;     0C74:4EBF (in fn0C74_4DAC)
;;     0C74:4FBF (in fn0C74_4DAC)
;;     0C74:50A8 (in fn0C74_4FD7)
;;     0C74:5192 (in fn0C74_4FD7)
;;     0C74:53EA (in fn0C74_5258)
;;     1229:0171 (in fn1229_0040)
;;     1229:01A7 (in fn1229_0040)
;;     1229:01DB (in fn1229_0040)
;;     133F:03E2 (in fn133F_0352)
;;     133F:0407 (in fn133F_0352)
;;     133F:042C (in fn133F_0352)
;;     133F:0447 (in fn133F_0352)
;;     133F:0462 (in fn133F_0352)
;;     1AB8:113D (in fn1AB8_112E)
;;     1AB8:114D (in fn1AB8_112E)
;;     1AB8:115D (in fn1AB8_112E)
;;     1AB8:116D (in fn1AB8_112E)
fn1AB8_1AF6 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Ch]
	mov	bx,[bp+0Ah]
	mov	cx,[bp+8h]
	mov	dx,[bp+6h]
	mov	si,0Ch
	call	dword ptr [0B820h]
	pop	bp
	retf	8h
1AB8:1B10 55 8B EC 8B 4E 0A C4 5E 06 B8 06 00 BE 0E 00 FF U...N..^........
1AB8:1B20 1E 20 B8 5D CA 06 00 55 8B EC 8B 4E 0A C4 5E 06 . .]...U...N..^.
1AB8:1B30 B8 07 00 BE 0E 00 FF 1E 20 B8 5D CA 06 00       ........ .]...  

;; fn1AB8_1B3E: 1AB8:1B3E
;;   Called from:
;;     0800:0072 (in fn0800_005A)
;;     0800:1338 (in fn0800_1315)
;;     0800:1B3A (in fn0800_19E1)
;;     0800:3709 (in fn0800_36E6)
;;     0800:39CB (in fn0800_391E)
;;     0800:3A30 (in fn0800_391E)
;;     0800:3F84 (in fn0800_3D9D)
;;     0C74:00C9 (in fn0C74_00B2)
;;     0C74:00F3 (in fn0C74_00DB)
;;     1AB8:105B (in fn1AB8_1028)
fn1AB8_1B3E proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Ch]
	mov	bx,[bp+0Ah]
	mov	cx,[bp+8h]
	mov	dx,[bp+6h]
	mov	si,12h
	call	dword ptr [0B820h]
	pop	bp
	retf	8h
1AB8:1B58                         55 8B EC 8B 46 10 8B 5E         U...F..^
1AB8:1B60 0E 8B 4E 0C 8B 56 0A 3B C1 72 01 91 3B DA 73 02 ..N..V.;.r..;.s.
1AB8:1B70 87 DA 51 52 BE 08 00 FF 1E 20 B8 5B 58 8B 4E 08 ..QR..... .[X.N.
1AB8:1B80 8A 56 06 32 F6 BE 10 00 FF 1E 20 B8 5D CA 0C 00 .V.2...... .]...

;; fn1AB8_1B90: 1AB8:1B90
;;   Called from:
;;     1AB8:1248 (in fn1AB8_122E)
fn1AB8_1B90 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+10h]
	mov	bx,[bp+0Eh]
	mov	si,8h
	call	dword ptr [0B820h]
	mov	ax,[bp+0Ch]
	mov	bx,[bp+0Ah]
	mov	cx,[bp+8h]
	mov	dx,[bp+6h]
	mov	si,14h
	call	dword ptr [0B820h]
	pop	bp
	retf	0Ch
1AB8:1BB7                      55 8B EC 8B 46 0C 8B 5E 0A        U...F..^.
1AB8:1BC0 BE 08 00 FF 1E 20 B8 8B 46 08 8B 5E 06 BE 18 00 ..... ..F..^....
1AB8:1BD0 FF 1E 20 B8 B8 00 00 BB 68 01 8B 4E 08 8B 56 06 .. .....h..N..V.
1AB8:1BE0 BE 14 00 FF 1E 20 B8 5D CA 08 00 55 8B EC 8B 46 ..... .]...U...F
1AB8:1BF0 10 8B 5E 0E BE 08 00 FF 1E 20 B8 8B 46 0C 8B 5E ..^...... ..F..^
1AB8:1C00 0A 8B 4E 08 8B 56 06 BE 16 00 FF 1E 20 B8 5D CA ..N..V...... .].
1AB8:1C10 0C 00 55 8B EC 1E B8 FF FF BE 14 00 FF 1E 20 B8 ..U........... .
1AB8:1C20 8B F3 06 1F C4 7E 06 FC B9 06 00 F3 A5 1F 5D CA .....~........].
1AB8:1C30 04 00                                           ..              

;; fn1AB8_1C32: 1AB8:1C32
;;   Called from:
;;     0800:050C (in fn0800_04E3)
;;     0800:0585 (in fn0800_04E3)
;;     0800:05FE (in fn0800_04E3)
;;     0800:06DD (in fn0800_0619)
;;     0800:0719 (in fn0800_0619)
;;     0800:0782 (in fn0800_0768)
;;     0800:07B8 (in fn0800_0768)
;;     0800:0806 (in fn0800_0768)
;;     0800:0870 (in fn0800_0768)
;;     0800:0A23 (in fn0800_09C2)
;;     0800:0A57 (in fn0800_09C2)
;;     0800:0B06 (in fn0800_0AA1)
;;     0800:0B1D (in fn0800_0AA1)
;;     0800:0B39 (in fn0800_0AA1)
;;     0800:0BA7 (in fn0800_0B42)
;;     0800:0BBE (in fn0800_0B42)
;;     0800:0BD5 (in fn0800_0B42)
;;     0800:0C3D (in fn0800_0BEC)
;;     0800:0C54 (in fn0800_0BEC)
;;     0800:0D9E (in fn0800_0D20)
;;     0800:0E78 (in fn0800_0D20)
;;     0800:0EE1 (in fn0800_0D20)
;;     0800:0F17 (in fn0800_0D20)
;;     0800:0F4B (in fn0800_0D20)
;;     0800:0F73 (in fn0800_0D20)
;;     0800:133F (in fn0800_1315)
;;     0800:13E1 (in fn0800_1315)
;;     0800:152B (in fn0800_149F)
;;     0800:1598 (in fn0800_149F)
;;     0800:15A1 (in fn0800_149F)
;;     0800:170E (in fn0800_166D)
;;     0800:177B (in fn0800_166D)
;;     0800:1784 (in fn0800_166D)
;;     0800:1860 (in fn0800_184C)
;;     0800:18D0 (in fn0800_184C)
;;     0800:1946 (in fn0800_184C)
;;     0800:19BC (in fn0800_184C)
;;     0800:1B41 (in fn0800_19E1)
;;     0800:1B4E (in fn0800_19E1)
;;     0800:1B90 (in fn0800_19E1)
;;     0800:1BBA (in fn0800_19E1)
;;     0800:1C00 (in fn0800_19E1)
;;     0800:1C23 (in fn0800_19E1)
;;     0800:1C30 (in fn0800_19E1)
;;     0800:1C73 (in fn0800_19E1)
;;     0800:1C9E (in fn0800_19E1)
;;     0800:1CE3 (in fn0800_19E1)
;;     0800:1CFF (in fn0800_19E1)
;;     0800:1D29 (in fn0800_19E1)
;;     0800:1D36 (in fn0800_19E1)
;;     0800:1EB2 (in fn0800_1E3F)
;;     0800:1EF0 (in fn0800_1E3F)
;;     0800:1EF9 (in fn0800_1E3F)
;;     0800:2061 (in fn0800_2004)
;;     0800:20A7 (in fn0800_2004)
;;     0800:20B0 (in fn0800_2004)
;;     0800:220F (in fn0800_21E7)
;;     0800:24B9 (in fn0800_2401)
;;     0800:24D0 (in fn0800_2401)
;;     0800:25D6 (in fn0800_2401)
;;     0800:25ED (in fn0800_2401)
;;     0800:28F7 (in fn0800_2827)
;;     0800:290E (in fn0800_2827)
;;     0800:2D4F (in fn0800_2C0C)
;;     0800:2D89 (in fn0800_2C0C)
;;     0800:2F7D (in fn0800_2C0C)
;;     0800:2F94 (in fn0800_2C0C)
;;     0800:31E5 (in fn0800_31B7)
;;     0800:32A3 (in fn0800_31B7)
;;     0800:3319 (in fn0800_31B7)
;;     0800:338F (in fn0800_31B7)
;;     0800:33DB (in fn0800_31B7)
;;     0800:33F2 (in fn0800_31B7)
;;     0800:3710 (in fn0800_36E6)
;;     0800:37B2 (in fn0800_36E6)
;;     0800:3A3B (in fn0800_391E)
;;     0800:3D0A (in fn0800_3CFA)
;;     0800:3DC4 (in fn0800_3D9D)
;;     0800:3E01 (in fn0800_3D9D)
;;     0C74:019D (in fn0C74_011E)
;;     0C74:01B4 (in fn0C74_011E)
;;     0C74:01E1 (in fn0C74_011E)
;;     0C74:028B (in fn0C74_020C)
;;     0C74:02A2 (in fn0C74_020C)
;;     0C74:02BA (in fn0C74_020C)
;;     0C74:10AA (in fn0C74_0FA1)
;;     0C74:175D (in fn0C74_0FA1)
;;     0C74:18EB (in fn0C74_0FA1)
;;     0C74:2011 (in fn0C74_1F08)
;;     0C74:2883 (in fn0C74_1F08)
;;     0C74:2C1D (in fn0C74_2BBD)
;;     0C74:2DED (in fn0C74_2BBD)
;;     0C74:2E05 (in fn0C74_2BBD)
;;     0C74:2FAC (in fn0C74_2E5A)
;;     0C74:3387 (in fn0C74_3236)
;;     0C74:3987 (in fn0C74_396E)
;;     0C74:39F8 (in fn0C74_396E)
;;     0C74:3A51 (in fn0C74_396E)
;;     0C74:3AB3 (in fn0C74_396E)
;;     0C74:3B0F (in fn0C74_396E)
;;     0C74:3C16 (in fn0C74_396E)
;;     0C74:3C36 (in fn0C74_396E)
;;     0C74:3C8B (in fn0C74_396E)
;;     0C74:3CD3 (in fn0C74_396E)
;;     0C74:3D0E (in fn0C74_396E)
;;     0C74:3D2E (in fn0C74_396E)
;;     0C74:3D6A (in fn0C74_396E)
;;     0C74:3DBE (in fn0C74_396E)
;;     0C74:3E91 (in fn0C74_396E)
;;     0C74:3EBF (in fn0C74_396E)
;;     0C74:3EEF (in fn0C74_396E)
;;     0C74:3F1F (in fn0C74_396E)
;;     0C74:3F8D (in fn0C74_3F74)
;;     0C74:402C (in fn0C74_3F74)
;;     0C74:4094 (in fn0C74_3F74)
;;     0C74:40F3 (in fn0C74_3F74)
;;     0C74:4154 (in fn0C74_3F74)
;;     0C74:425E (in fn0C74_3F74)
;;     0C74:427E (in fn0C74_3F74)
;;     0C74:42D3 (in fn0C74_3F74)
;;     0C74:431B (in fn0C74_3F74)
;;     0C74:4357 (in fn0C74_3F74)
;;     0C74:4377 (in fn0C74_3F74)
;;     0C74:43B4 (in fn0C74_3F74)
;;     0C74:4405 (in fn0C74_3F74)
;;     0C74:44E2 (in fn0C74_3F74)
;;     0C74:450E (in fn0C74_3F74)
;;     0C74:453C (in fn0C74_3F74)
;;     0C74:456A (in fn0C74_3F74)
;;     0C74:45E7 (in fn0C74_45CE)
;;     0C74:4658 (in fn0C74_45CE)
;;     0C74:46E3 (in fn0C74_45CE)
;;     0C74:4703 (in fn0C74_45CE)
;;     0C74:47E8 (in fn0C74_45CE)
;;     0C74:482B (in fn0C74_45CE)
;;     0C74:49AA (in fn0C74_4999)
;;     0C74:4A51 (in fn0C74_4999)
;;     0C74:4AEB (in fn0C74_4999)
;;     0C74:4B0B (in fn0C74_4999)
;;     0C74:4BEA (in fn0C74_4999)
;;     0C74:4C2D (in fn0C74_4999)
;;     0C74:4E77 (in fn0C74_4DAC)
;;     0C74:506F (in fn0C74_4FD7)
;;     0C74:53D9 (in fn0C74_5258)
;;     1229:0059 (in fn1229_0040)
;;     1229:0150 (in fn1229_0040)
;;     1229:0186 (in fn1229_0040)
;;     1229:01BA (in fn1229_0040)
;;     1229:01E2 (in fn1229_0040)
;;     1229:06B0 (in fn1229_061B)
;;     1229:0902 (in fn1229_0735)
;;     1229:0CE3 (in fn1229_0CCE)
;;     133F:0130 (in fn133F_0056)
;;     1AB8:0B40 (in fn1AB8_0AEE)
fn1AB8_1C32 proc
	push	bp
	mov	bp,sp
	mov	al,[bp+6h]
	mov	[0B83Eh],al
	mov	ah,[0B83Fh]
	mov	si,1Eh
	call	dword ptr [0B820h]
	pop	bp
	retf	2h

;; fn1AB8_1C4A: 1AB8:1C4A
;;   Called from:
;;     1AB8:0B3B (in fn1AB8_0AEE)
;;     1AB8:0B5A (in fn1AB8_0AEE)
;;     1AB8:0B67 (in fn1AB8_0AEE)
;;     1AB8:11B9 (in fn1AB8_11A0)
fn1AB8_1C4A proc
	push	bp
	mov	bp,sp
	xor	al,al
	mov	si,3Ah
	call	dword ptr [0B820h]
	mov	ax,cx
	pop	bp
	retf

;; fn1AB8_1C5A: 1AB8:1C5A
;;   Called from:
;;     1AB8:0B26 (in fn1AB8_0AEE)
fn1AB8_1C5A proc
	push	bp
	mov	bp,sp
	xor	al,al
	mov	si,3Ah
	call	dword ptr [0B820h]
	mov	ax,bx
	pop	bp
	retf

;; fn1AB8_1C6A: 1AB8:1C6A
;;   Called from:
;;     1AB8:1387 (in fn1AB8_1384)
fn1AB8_1C6A proc
	push	bp
	mov	bp,sp
	mov	al,1h
	mov	si,3Ah
	call	dword ptr [0B820h]
	mov	dx,es
	mov	ax,bx
	pop	bp
	retf
1AB8:1C7C                                     55 8B EC B0             U...
1AB8:1C80 02 8B 4E 06 BE 00 00 FF 1E 20 B8 8C C2 8B C3 5D ..N...... .....]
1AB8:1C90 CA 02 00                                        ...             

;; fn1AB8_1C93: 1AB8:1C93
;;   Called from:
;;     1AB8:0E61 (in fn1AB8_0BAE)
fn1AB8_1C93 proc
	push	bp
	mov	bp,sp
	mov	al,1h
	mov	si,0h
	call	dword ptr [0B820h]
	mov	ax,cx
	dec	ax
	pop	bp
	retf

;; fn1AB8_1CA4: 1AB8:1CA4
;;   Called from:
;;     1AB8:127D (in fn1AB8_1250)
fn1AB8_1CA4 proc
	push	bp
	mov	bp,sp
	mov	bl,[bp+6h]
	xor	bh,bh
	mov	ax,0FFFFh
	mov	si,1Ah
	call	dword ptr [0B820h]
	pop	bp
	retf	2h

;; fn1AB8_1CBA: 1AB8:1CBA
;;   Called from:
;;     0800:3DF1 (in fn0800_3D9D)
;;     0800:409B (in fn0800_3D9D)
;;     0800:439C (in fn0800_4255)
;;     1229:0DF0 (in fn1229_0DCC)
;;     13E2:0063 (in fn13E2_003B)
;;     13E2:00DE (in fn13E2_0080)
;;     13E2:012B (in fn13E2_00FB)
;;     13E2:0174 (in fn13E2_00FB)
fn1AB8_1CBA proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Ch]
	or	ah,80h
	mov	bx,[bp+0Ah]
	mov	cx,[bp+8h]
	mov	dx,[bp+6h]
	mov	si,1Ah
	call	dword ptr [0B820h]
	pop	bp
	retf	8h

;; fn1AB8_1CD7: 1AB8:1CD7
;;   Called from:
;;     1AB8:137C (in fn1AB8_1342)
fn1AB8_1CD7 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+8h]
	xor	ah,ah
	mov	bx,[bp+6h]
	mov	si,1Ah
	call	dword ptr [0B820h]
	pop	bp
	retf	4h

;; fn1AB8_1CED: 1AB8:1CED
;;   Called from:
;;     1AB8:1338 (in fn1AB8_129A)
fn1AB8_1CED proc
	push	bp
	mov	bp,sp
	les	bx,[bp+6h]
	inc	bx
	mov	si,1Ch
	call	dword ptr [0B820h]
	pop	bp
	retf	4h

;; fn1AB8_1CFF: 1AB8:1CFF
;;   Called from:
;;     1AB8:1126 (in fn1AB8_10F4)
fn1AB8_1CFF proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Ah]
	mov	[0B841h],al
	mov	bx,[bp+8h]
	mov	cl,[bp+6h]
	mov	[0B89Eh],cl
	xor	ch,ch
	mov	si,22h
	call	dword ptr [0B820h]
	pop	bp
	retf	6h
1AB8:1D1F                                              55                U
1AB8:1D20 8B EC 8B 46 0A 8B 5E 08 8B 4E 06 C4 36 9F B8 26 ...F..^..N..6..&
1AB8:1D30 8B 7C 0C 26 8B 54 0E 26 03 7C 10 83 EF 02 FA 87 .|.&.T.&.|......
1AB8:1D40 E7 8C D5 8E D2 FB 57 55 BE 2C 00 FF 1E 20 B8 5B ......WU.,... .[
1AB8:1D50 58 FA 8E D3 8B E0 FB 5D CA 06 00                X......]...     

;; fn1AB8_1D5B: 1AB8:1D5B
;;   Called from:
;;     1AB8:1198 (in fn1AB8_1175)
fn1AB8_1D5B proc
	push	bp
	mov	bp,sp
	mov	ah,[bp+6h]
	mov	[0B83Fh],ah
	mov	al,[0B83Eh]
	mov	si,1Eh
	call	dword ptr [0B820h]
	mov	al,[bp+8h]
	mov	[0B842h],al
	mov	ah,al
	mov	si,20h
	call	dword ptr [0B820h]
	pop	bp
	retf	4h

;; fn1AB8_1D82: 1AB8:1D82
;;   Called from:
;;     0800:0532 (in fn0800_04E3)
;;     0800:0558 (in fn0800_04E3)
;;     0800:057E (in fn0800_04E3)
;;     0800:05AB (in fn0800_04E3)
;;     0800:05D1 (in fn0800_04E3)
;;     0800:05F7 (in fn0800_04E3)
;;     0800:0702 (in fn0800_0619)
;;     0800:0712 (in fn0800_0619)
;;     0800:073E (in fn0800_0619)
;;     0800:074E (in fn0800_0619)
;;     0800:07A1 (in fn0800_0768)
;;     0800:07B1 (in fn0800_0768)
;;     0800:07C8 (in fn0800_0768)
;;     0800:07D8 (in fn0800_0768)
;;     0800:0816 (in fn0800_0768)
;;     0800:0826 (in fn0800_0768)
;;     0800:0B16 (in fn0800_0AA1)
;;     0800:0B2D (in fn0800_0AA1)
;;     0800:0BB7 (in fn0800_0B42)
;;     0800:0BCE (in fn0800_0B42)
;;     0800:0C4D (in fn0800_0BEC)
;;     0800:0C64 (in fn0800_0BEC)
;;     0800:0E3B (in fn0800_0D20)
;;     0800:0E8B (in fn0800_0D20)
;;     0800:156D (in fn0800_149F)
;;     0800:15E1 (in fn0800_149F)
;;     0800:1750 (in fn0800_166D)
;;     0800:17C4 (in fn0800_166D)
;;     0800:18DF (in fn0800_184C)
;;     0800:18EF (in fn0800_184C)
;;     0800:18FF (in fn0800_184C)
;;     0800:190F (in fn0800_184C)
;;     0800:191F (in fn0800_184C)
;;     0800:192F (in fn0800_184C)
;;     0800:193F (in fn0800_184C)
;;     0800:1955 (in fn0800_184C)
;;     0800:1965 (in fn0800_184C)
;;     0800:1975 (in fn0800_184C)
;;     0800:1985 (in fn0800_184C)
;;     0800:1995 (in fn0800_184C)
;;     0800:19A5 (in fn0800_184C)
;;     0800:19B5 (in fn0800_184C)
;;     0800:1D47 (in fn0800_19E1)
;;     0800:1ED9 (in fn0800_1E3F)
;;     0800:1F1D (in fn0800_1E3F)
;;     0800:2090 (in fn0800_2004)
;;     0800:20DD (in fn0800_2004)
;;     0800:221E (in fn0800_21E7)
;;     0800:226E (in fn0800_21E7)
;;     0800:24C9 (in fn0800_2401)
;;     0800:24E0 (in fn0800_2401)
;;     0800:24F0 (in fn0800_2401)
;;     0800:2500 (in fn0800_2401)
;;     0800:25E6 (in fn0800_2401)
;;     0800:25FD (in fn0800_2401)
;;     0800:2907 (in fn0800_2827)
;;     0800:291E (in fn0800_2827)
;;     0800:2D70 (in fn0800_2C0C)
;;     0800:2D82 (in fn0800_2C0C)
;;     0800:2DAA (in fn0800_2C0C)
;;     0800:2DBC (in fn0800_2C0C)
;;     0800:2F8D (in fn0800_2C0C)
;;     0800:2FA4 (in fn0800_2C0C)
;;     0800:32B2 (in fn0800_31B7)
;;     0800:32C2 (in fn0800_31B7)
;;     0800:32D2 (in fn0800_31B7)
;;     0800:32E2 (in fn0800_31B7)
;;     0800:32F2 (in fn0800_31B7)
;;     0800:3302 (in fn0800_31B7)
;;     0800:3312 (in fn0800_31B7)
;;     0800:3328 (in fn0800_31B7)
;;     0800:3338 (in fn0800_31B7)
;;     0800:3348 (in fn0800_31B7)
;;     0800:3358 (in fn0800_31B7)
;;     0800:3368 (in fn0800_31B7)
;;     0800:3378 (in fn0800_31B7)
;;     0800:3388 (in fn0800_31B7)
;;     0800:33EB (in fn0800_31B7)
;;     0800:3402 (in fn0800_31B7)
;;     0800:3A90 (in fn0800_391E)
;;     0800:3DE4 (in fn0800_3D9D)
;;     0800:43D2 (in fn0800_4255)
;;     0C74:01AD (in fn0C74_011E)
;;     0C74:01C4 (in fn0C74_011E)
;;     0C74:029B (in fn0C74_020C)
;;     0C74:02B2 (in fn0C74_020C)
;;     1229:00F7 (in fn1229_0040)
;;     1229:0C51 (in fn1229_0AA8)
;;     133F:01F7 (in fn133F_014B)
;;     1AB8:14BB (in fn1AB8_1492)
fn1AB8_1D82 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Ch]
	mov	bx,[bp+0Ah]
	mov	si,8h
	call	dword ptr [0B820h]
	les	bx,[bp+6h]
	mov	cl,es:[bx]
	xor	ch,ch
	inc	bx
	mov	si,26h
	call	dword ptr [0B820h]
	pop	bp
	retf	8h

;; fn1AB8_1DA6: 1AB8:1DA6
;;   Called from:
;;     1AB8:1779 (in fn1AB8_1536)
fn1AB8_1DA6 proc
	push	bp
	mov	bp,sp
	les	bx,[0B83Ah]
	mov	bx,es:[bx+10h]
	and	bx,7F7Fh
	mov	dl,[bp+6h]
	mov	al,bh
	mul	dl
	mov	cx,ax
	mov	al,bl
	mul	dl
	mov	bx,ax
	mov	al,[bp+0Ah]
	mov	ah,[bp+8h]
	and	al,al
	jz	1DE3h

l1AB8_1DCE:
	les	di,[0B83Ah]
	cmp	byte ptr es:[di+1h],3h
	jz	1DE3h

l1AB8_1DD9:
	mov	cl,dl
	xor	ch,ch
	mov	bx,cx
	mov	dx,[0B838h]

l1AB8_1DE3:
	mov	si,24h
	call	dword ptr [0B820h]
	pop	bp
	retf	6h
1AB8:1DEE                                           55 8B               U.
1AB8:1DF0 EC 8B 46 0C 8B 5E 0A 8B 4E 08 8B 56 06 80 CC 80 ..F..^..N..V....
1AB8:1E00 BE 24 00 FF 1E 20 B8 5D CA 08 00                .$... .]...     

;; fn1AB8_1E0B: 1AB8:1E0B
;;   Called from:
;;     0800:0E28 (in fn0800_0D20)
;;     0800:0E5B (in fn0800_0D20)
;;     0800:0EB6 (in fn0800_0D20)
;;     0800:0FC7 (in fn0800_0D20)
;;     0800:1064 (in fn0800_0D20)
;;     0800:10D3 (in fn0800_0D20)
;;     0800:110B (in fn0800_0D20)
;;     0800:1146 (in fn0800_0D20)
;;     0800:1A2B (in fn0800_19E1)
;;     0800:1A55 (in fn0800_19E1)
;;     1229:00E4 (in fn1229_0040)
;;     1229:0117 (in fn1229_0040)
;;     1229:0207 (in fn1229_0040)
;;     1229:02AA (in fn1229_0040)
;;     1229:02E2 (in fn1229_0040)
;;     1229:031E (in fn1229_0040)
;;     133F:017E (in fn133F_014B)
;;     133F:01AA (in fn133F_014B)
;;     1AB8:14D3 (in fn1AB8_1492)
fn1AB8_1E0B proc
	push	bp
	mov	bp,sp
	les	bx,[bp+6h]
	mov	cl,es:[bx]
	xor	ch,ch
	inc	bx
	mov	si,28h
	call	dword ptr [0B820h]
	mov	ax,bx
	pop	bp
	retf	4h
1AB8:1E24             4D 00                                   M.          

;; fn1AB8_1E26: 1AB8:1E26
;;   Called from:
;;     1AB8:179E (in fn1AB8_1783)
fn1AB8_1E26 proc
	push	bp
	mov	bp,sp
	mov	cx,1h
	push	cs
	pop	es
	mov	bx,1E24h
	mov	si,28h
	call	dword ptr [0B820h]
	mov	ax,cx
	pop	bp
	retf

;; fn1AB8_1E3C: 1AB8:1E3C
;;   Called from:
;;     0800:08A5 (in fn0800_0877)
;;     0800:0931 (in fn0800_08E9)
;;     0C74:05E4 (in fn0C74_05B8)
;;     0C74:05F9 (in fn0C74_05B8)
;;     0C74:0667 (in fn0C74_05B8)
;;     0C74:0679 (in fn0C74_05B8)
;;     0C74:07FD (in fn0C74_076B)
;;     0C74:08B5 (in fn0C74_076B)
;;     0C74:097F (in fn0C74_076B)
;;     0C74:0ACB (in fn0C74_0A35)
;;     0C74:0B77 (in fn0C74_0A35)
;;     0C74:0C41 (in fn0C74_0A35)
;;     0C74:1206 (in fn0C74_0FA1)
;;     0C74:1223 (in fn0C74_0FA1)
;;     0C74:1240 (in fn0C74_0FA1)
;;     0C74:125D (in fn0C74_0FA1)
;;     0C74:1277 (in fn0C74_0FA1)
;;     0C74:1291 (in fn0C74_0FA1)
;;     0C74:134A (in fn0C74_0FA1)
;;     0C74:1364 (in fn0C74_0FA1)
;;     0C74:14A8 (in fn0C74_0FA1)
;;     0C74:14C2 (in fn0C74_0FA1)
;;     0C74:161F (in fn0C74_0FA1)
;;     0C74:162E (in fn0C74_0FA1)
;;     0C74:1640 (in fn0C74_0FA1)
;;     0C74:167E (in fn0C74_0FA1)
;;     0C74:1B13 (in fn0C74_0FA1)
;;     0C74:1B25 (in fn0C74_0FA1)
;;     0C74:1BDE (in fn0C74_1B3B)
;;     0C74:1BF0 (in fn0C74_1B3B)
;;     0C74:1C50 (in fn0C74_1B3B)
;;     0C74:1C65 (in fn0C74_1B3B)
;;     0C74:216D (in fn0C74_1F08)
;;     0C74:218A (in fn0C74_1F08)
;;     0C74:21A7 (in fn0C74_1F08)
;;     0C74:21C4 (in fn0C74_1F08)
;;     0C74:21DE (in fn0C74_1F08)
;;     0C74:21F8 (in fn0C74_1F08)
;;     0C74:22B1 (in fn0C74_1F08)
;;     0C74:22CB (in fn0C74_1F08)
;;     0C74:240F (in fn0C74_1F08)
;;     0C74:2429 (in fn0C74_1F08)
;;     0C74:2586 (in fn0C74_1F08)
;;     0C74:2595 (in fn0C74_1F08)
;;     0C74:25C3 (in fn0C74_1F08)
;;     0C74:2601 (in fn0C74_1F08)
;;     0C74:276A (in fn0C74_1F08)
;;     0C74:277F (in fn0C74_1F08)
;;     0C74:281F (in fn0C74_1F08)
;;     0C74:2832 (in fn0C74_1F08)
;;     0C74:2AAC (in fn0C74_1F08)
;;     0C74:2ABF (in fn0C74_1F08)
;;     0C74:2C73 (in fn0C74_2BBD)
;;     0C74:2C8C (in fn0C74_2BBD)
;;     0C74:2E75 (in fn0C74_2E5A)
;;     0C74:2E8C (in fn0C74_2E5A)
;;     0C74:2EA0 (in fn0C74_2E5A)
;;     0C74:2EB2 (in fn0C74_2E5A)
;;     0C74:2EC9 (in fn0C74_2E5A)
;;     0C74:3098 (in fn0C74_2E5A)
;;     0C74:314A (in fn0C74_2E5A)
;;     0C74:3252 (in fn0C74_3236)
;;     0C74:3267 (in fn0C74_3236)
;;     0C74:327B (in fn0C74_3236)
;;     0C74:328D (in fn0C74_3236)
;;     0C74:32A4 (in fn0C74_3236)
;;     0C74:3473 (in fn0C74_3236)
;;     0C74:3527 (in fn0C74_3236)
;;     0C74:3649 (in fn0C74_3615)
;;     0C74:365E (in fn0C74_3615)
;;     0C74:3673 (in fn0C74_3615)
;;     0C74:3686 (in fn0C74_3615)
;;     0C74:372D (in fn0C74_3615)
;;     0C74:3741 (in fn0C74_3615)
;;     0C74:3755 (in fn0C74_3615)
;;     0C74:3767 (in fn0C74_3615)
;;     0C74:37F6 (in fn0C74_37C3)
;;     0C74:380B (in fn0C74_37C3)
;;     0C74:3820 (in fn0C74_37C3)
;;     0C74:3833 (in fn0C74_37C3)
;;     0C74:38D8 (in fn0C74_37C3)
;;     0C74:38EC (in fn0C74_37C3)
;;     0C74:3900 (in fn0C74_37C3)
;;     0C74:3912 (in fn0C74_37C3)
;;     0C74:39D9 (in fn0C74_396E)
;;     0C74:3FF8 (in fn0C74_3F74)
;;     0C74:4639 (in fn0C74_45CE)
;;     0C74:46D1 (in fn0C74_45CE)
;;     0C74:4797 (in fn0C74_45CE)
;;     0C74:47AE (in fn0C74_45CE)
;;     0C74:47C7 (in fn0C74_45CE)
;;     0C74:47D8 (in fn0C74_45CE)
;;     0C74:48DC (in fn0C74_45CE)
;;     0C74:48F0 (in fn0C74_45CE)
;;     0C74:4902 (in fn0C74_45CE)
;;     0C74:4A1D (in fn0C74_4999)
;;     0C74:4AD9 (in fn0C74_4999)
;;     0C74:4B9C (in fn0C74_4999)
;;     0C74:4BAD (in fn0C74_4999)
;;     0C74:4BC6 (in fn0C74_4999)
;;     0C74:4BDA (in fn0C74_4999)
;;     0C74:4CF3 (in fn0C74_4999)
;;     0C74:4D07 (in fn0C74_4999)
;;     0C74:4D19 (in fn0C74_4999)
;;     0C74:4E43 (in fn0C74_4DAC)
;;     0C74:504D (in fn0C74_4FD7)
;;     0C74:51CC (in fn0C74_51B2)
;;     0C74:51E1 (in fn0C74_51B2)
;;     0C74:5200 (in fn0C74_51B2)
;;     0C74:5215 (in fn0C74_51B2)
;;     0C74:5271 (in fn0C74_5258)
;;     0C74:5288 (in fn0C74_5258)
;;     0C74:52B3 (in fn0C74_5258)
;;     0C74:52CA (in fn0C74_5258)
;;     0C74:5328 (in fn0C74_5258)
;;     0C74:533B (in fn0C74_5258)
;;     0C74:5375 (in fn0C74_5258)
;;     0C74:5445 (in fn0C74_542B)
;;     0C74:5458 (in fn0C74_542B)
;;     0C74:5481 (in fn0C74_542B)
;;     0C74:5494 (in fn0C74_542B)
;;     0C74:54C4 (in fn0C74_54B1)
;;     0C74:54D9 (in fn0C74_54B1)
;;     0C74:5503 (in fn0C74_54F0)
;;     0C74:5518 (in fn0C74_54F0)
fn1AB8_1E3C proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+8h]
	mov	bx,[bp+6h]
	mov	si,2Eh
	call	dword ptr [0B820h]
	xor	ah,ah
	mov	al,dl
	pop	bp
	retf	4h

;; fn1AB8_1E54: 1AB8:1E54
;;   Called from:
;;     0800:163A (in fn0800_149F)
;;     0800:181D (in fn0800_166D)
;;     0C74:0822 (in fn0C74_076B)
;;     0C74:0904 (in fn0C74_076B)
;;     0C74:0954 (in fn0C74_076B)
;;     0C74:09D0 (in fn0C74_076B)
;;     0C74:0A23 (in fn0C74_076B)
;;     0C74:0AE6 (in fn0C74_0A35)
;;     0C74:0BC6 (in fn0C74_0A35)
;;     0C74:0C16 (in fn0C74_0A35)
;;     0C74:0C92 (in fn0C74_0A35)
;;     0C74:0CE5 (in fn0C74_0A35)
;;     0C74:1101 (in fn0C74_0FA1)
;;     0C74:1116 (in fn0C74_0FA1)
;;     0C74:112B (in fn0C74_0FA1)
;;     0C74:1140 (in fn0C74_0FA1)
;;     0C74:1155 (in fn0C74_0FA1)
;;     0C74:116A (in fn0C74_0FA1)
;;     0C74:1651 (in fn0C74_0FA1)
;;     0C74:1660 (in fn0C74_0FA1)
;;     0C74:1670 (in fn0C74_0FA1)
;;     0C74:168F (in fn0C74_0FA1)
;;     0C74:169E (in fn0C74_0FA1)
;;     0C74:16AE (in fn0C74_0FA1)
;;     0C74:1B4F (in fn0C74_1B3B)
;;     0C74:1B64 (in fn0C74_1B3B)
;;     0C74:1B79 (in fn0C74_1B3B)
;;     0C74:2068 (in fn0C74_1F08)
;;     0C74:207D (in fn0C74_1F08)
;;     0C74:2092 (in fn0C74_1F08)
;;     0C74:20A7 (in fn0C74_1F08)
;;     0C74:20BC (in fn0C74_1F08)
;;     0C74:20D1 (in fn0C74_1F08)
;;     0C74:25D4 (in fn0C74_1F08)
;;     0C74:25E3 (in fn0C74_1F08)
;;     0C74:25F3 (in fn0C74_1F08)
;;     0C74:2612 (in fn0C74_1F08)
;;     0C74:2621 (in fn0C74_1F08)
;;     0C74:2631 (in fn0C74_1F08)
;;     0C74:27B6 (in fn0C74_1F08)
;;     0C74:27CB (in fn0C74_1F08)
;;     0C74:27E0 (in fn0C74_1F08)
;;     0C74:2D45 (in fn0C74_2BBD)
;;     0C74:2D68 (in fn0C74_2BBD)
;;     0C74:2D9D (in fn0C74_2BBD)
;;     0C74:2DC7 (in fn0C74_2BBD)
;;     0C74:2FE2 (in fn0C74_2E5A)
;;     0C74:2FF7 (in fn0C74_2E5A)
;;     0C74:300C (in fn0C74_2E5A)
;;     0C74:33BD (in fn0C74_3236)
;;     0C74:33D2 (in fn0C74_3236)
;;     0C74:33E7 (in fn0C74_3236)
;;     0C74:3BD3 (in fn0C74_396E)
;;     0C74:3C60 (in fn0C74_396E)
;;     0C74:3C71 (in fn0C74_396E)
;;     0C74:3CB5 (in fn0C74_396E)
;;     0C74:3CC6 (in fn0C74_396E)
;;     0C74:3E8A (in fn0C74_396E)
;;     0C74:421A (in fn0C74_3F74)
;;     0C74:42A8 (in fn0C74_3F74)
;;     0C74:42B9 (in fn0C74_3F74)
;;     0C74:42FD (in fn0C74_3F74)
;;     0C74:430E (in fn0C74_3F74)
;;     0C74:44DB (in fn0C74_3F74)
;;     0C74:4DD4 (in fn0C74_4DAC)
;;     0C74:4DF4 (in fn0C74_4DAC)
;;     0C74:4E14 (in fn0C74_4DAC)
;;     0C74:4FF6 (in fn0C74_4FD7)
;;     0C74:500E (in fn0C74_4FD7)
;;     0C74:5026 (in fn0C74_4FD7)
;;     0C74:5355 (in fn0C74_5258)
fn1AB8_1E54 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Ah]
	mov	bx,[bp+8h]
	mov	dl,[bp+6h]
	mov	si,30h
	call	dword ptr [0B820h]
	pop	bp
	retf	6h

;; fn1AB8_1E6B: 1AB8:1E6B
;;   Called from:
;;     0800:0DDB (in fn0800_0D20)
;;     0C74:0531 (in fn0C74_03D4)
;;     0C74:0640 (in fn0C74_05B8)
;;     0C74:0EE1 (in fn0C74_0E2E)
;;     0C74:0F15 (in fn0C74_0E2E)
;;     0C74:0FF2 (in fn0C74_0FA1)
;;     0C74:1018 (in fn0C74_0FA1)
;;     0C74:11BC (in fn0C74_0FA1)
;;     0C74:11E2 (in fn0C74_0FA1)
;;     0C74:140D (in fn0C74_0FA1)
;;     0C74:156B (in fn0C74_0FA1)
;;     0C74:1722 (in fn0C74_0FA1)
;;     0C74:17BC (in fn0C74_0FA1)
;;     0C74:1838 (in fn0C74_0FA1)
;;     0C74:19DF (in fn0C74_0FA1)
;;     0C74:1A86 (in fn0C74_0FA1)
;;     0C74:1BC6 (in fn0C74_1B3B)
;;     0C74:1D11 (in fn0C74_1B3B)
;;     0C74:1E48 (in fn0C74_1D95)
;;     0C74:1E7C (in fn0C74_1D95)
;;     0C74:1F59 (in fn0C74_1F08)
;;     0C74:1F7F (in fn0C74_1F08)
;;     0C74:2123 (in fn0C74_1F08)
;;     0C74:2149 (in fn0C74_1F08)
;;     0C74:2374 (in fn0C74_1F08)
;;     0C74:24D2 (in fn0C74_1F08)
;;     0C74:26BB (in fn0C74_1F08)
;;     0C74:280B (in fn0C74_1F08)
;;     0C74:2977 (in fn0C74_1F08)
;;     0C74:2A1E (in fn0C74_1F08)
;;     0C74:2B36 (in fn0C74_2AD9)
;;     0C74:2C16 (in fn0C74_2BBD)
;;     0C74:2C44 (in fn0C74_2BBD)
;;     0C74:2F20 (in fn0C74_2E5A)
;;     0C74:2F78 (in fn0C74_2E5A)
;;     0C74:3072 (in fn0C74_2E5A)
;;     0C74:32FB (in fn0C74_3236)
;;     0C74:3353 (in fn0C74_3236)
;;     0C74:344D (in fn0C74_3236)
;;     0C74:4F2E (in fn0C74_4DAC)
;;     0C74:511B (in fn0C74_4FD7)
;;     0C74:53C7 (in fn0C74_5258)
;;     1229:0096 (in fn1229_0040)
fn1AB8_1E6B proc
	push	bp
	mov	bp,sp
	les	bx,[bp+6h]
	mov	cx,[bp+10h]
	mov	dx,[bp+0Eh]
	mov	si,[bp+0Ch]
	mov	di,[bp+0Ah]
	cmp	cx,si
	jc	1E83h

l1AB8_1E81:
	xchg	cx,si

l1AB8_1E83:
	cmp	dx,di
	jc	1E89h

l1AB8_1E87:
	xchg	dx,di

l1AB8_1E89:
	sub	si,cx
	mov	es:[bx],si
	sub	di,dx
	mov	es:[bx+2h],di
	mov	si,34h
	call	dword ptr [0B820h]
	pop	bp
	retf	0Ch

;; fn1AB8_1E9F: 1AB8:1E9F
;;   Called from:
;;     1AB8:147E (in fn1AB8_13D7)
fn1AB8_1E9F proc
	push	bp
	mov	bp,sp
	les	bx,[bp+8h]
	mov	cx,[bp+0Eh]
	mov	dx,[bp+0Ch]
	mov	al,[bp+6h]
	mov	si,36h
	call	dword ptr [0B820h]
	pop	bp
	retf	0Ah
1AB8:1EB9                            00 00 00 01 01 01 02          .......
1AB8:1EC0 03 04 01 05 06 07 FF 00 04 05 01 00 00 00 00 05 ................
1AB8:1ED0 02 00 00 00 00 00 04 05 01 01 00 01 00 05 02 00 ................
1AB8:1EE0 00 00 7F                                        ...             

;; fn1AB8_1EE3: 1AB8:1EE3
;;   Called from:
;;     1AB8:1A63 (in fn1AB8_1A62)
fn1AB8_1EE3 proc
	mov	byte ptr [0B89Ah],0FFh
	mov	byte ptr [0B89Ch],0FFh
	mov	byte ptr [0B89Bh],0h
	call	1F19h
	mov	bl,[0B89Ch]
	cmp	bl,0FFh
	jz	1F18h

l1AB8_1EFE:
	xor	bh,bh
	mov	al,cs:[bx+1EB9h]
	mov	[0B89Ah],al
	mov	al,cs:[bx+1EC7h]
	mov	[0B89Bh],al
	mov	al,cs:[bx+1ED5h]
	mov	[0B89Dh],al

l1AB8_1F18:
	ret

;; fn1AB8_1F19: 1AB8:1F19
;;   Called from:
;;     1AB8:1EF2 (in fn1AB8_1EE3)
fn1AB8_1F19 proc
	mov	ah,0Fh
	int	10h
	cmp	al,7h
	jz	1F52h

l1AB8_1F21:
	call	200Eh
	jnc	1F2Ch

l1AB8_1F26:
	mov	byte ptr [0B89Ch],6h
	ret

l1AB8_1F2C:
	call	1F80h
	jnc	1F35h

l1AB8_1F31:
	call	1F9Eh
	ret

l1AB8_1F35:
	call	2043h
	and	ax,ax
	jz	1F42h

l1AB8_1F3C:
	mov	byte ptr [0B89Ch],0Ah
	ret

l1AB8_1F42:
	mov	byte ptr [0B89Ch],1h
	call	1FEDh
	jnc	1F51h

l1AB8_1F4C:
	mov	byte ptr [0B89Ch],2h

l1AB8_1F51:
	ret

l1AB8_1F52:
	call	1F80h
	jc	1F31h

l1AB8_1F57:
	call	2011h
	and	al,al
	jz	1F64h

l1AB8_1F5E:
	mov	byte ptr [0B89Ch],7h
	ret

l1AB8_1F64:
	mov	si,0B800h
	mov	es,si
	xor	si,si
	mov	ax,es:[si]
	not	ax
	not	word ptr es:[si]
	nop
	nop
	cmp	ax,es:[si]
	jnz	1F7Fh

l1AB8_1F7A:
	mov	byte ptr [0B89Ch],1h

l1AB8_1F7F:
	ret

;; fn1AB8_1F80: 1AB8:1F80
;;   Called from:
;;     1AB8:1F2C (in fn1AB8_1F19)
;;     1AB8:1F52 (in fn1AB8_1F19)
fn1AB8_1F80 proc
	mov	ax,1200h
	mov	bl,10h
	mov	bh,0FFh
	mov	cl,0Fh
	int	10h
	cmp	cl,0Ch
	jge	1F9Ch

l1AB8_1F90:
	cmp	bh,1h
	jg	1F9Ch

l1AB8_1F95:
	cmp	bl,3h
	jg	1F9Ch

l1AB8_1F9A:
	stc
	ret

l1AB8_1F9C:
	clc
	ret

;; fn1AB8_1F9E: 1AB8:1F9E
;;   Called from:
;;     1AB8:1F31 (in fn1AB8_1F19)
fn1AB8_1F9E proc
	mov	byte ptr [0B89Ch],4h
	cmp	bh,1h
	jz	1FD8h

l1AB8_1FA8:
	call	1FDEh
	jc	1FD7h

l1AB8_1FAD:
	and	bl,bl
	jz	1FD7h

l1AB8_1FB1:
	mov	byte ptr [0B89Ch],3h
	call	1FEDh
	jc	1FD2h

l1AB8_1FBB:
	mov	bx,0C000h
	mov	es,bx
	mov	bx,39h
	cmp	word ptr es:[bx],345Ah
	jnz	1FD7h

l1AB8_1FCA:
	cmp	word ptr es:[bx+2h],3934h
	jnz	1FD7h

l1AB8_1FD2:
	mov	byte ptr [0B89Ch],9h

l1AB8_1FD7:
	ret

l1AB8_1FD8:
	mov	byte ptr [0B89Ch],5h
	ret

;; fn1AB8_1FDE: 1AB8:1FDE
;;   Called from:
;;     1AB8:1FA8 (in fn1AB8_1F9E)
fn1AB8_1FDE proc
	cmp	cl,2h
	jc	1FECh

l1AB8_1FE3:
	cmp	cl,6h
	cmc
	jnc	1FECh

l1AB8_1FE9:
	cmp	cl,8h

l1AB8_1FEC:
	ret

;; fn1AB8_1FED: 1AB8:1FED
;;   Called from:
;;     1AB8:1F47 (in fn1AB8_1F19)
;;     1AB8:1FB6 (in fn1AB8_1F9E)
fn1AB8_1FED proc
	mov	ax,1A00h
	int	10h
	cmp	al,1Ah
	jnz	200Ch

l1AB8_1FF6:
	cmp	bl,7h
	jz	200Ah

l1AB8_1FFB:
	cmp	bl,8h
	jz	200Ah

l1AB8_2000:
	cmp	bl,0Bh
	jc	200Ch

l1AB8_2005:
	cmp	bl,0Ch
	ja	200Ch

l1AB8_200A:
	stc
	ret

l1AB8_200C:
	clc
	ret

;; fn1AB8_200E: 1AB8:200E
;;   Called from:
;;     1AB8:1F21 (in fn1AB8_1F19)
fn1AB8_200E proc
	xor	al,al
	ret

;; fn1AB8_2011: 1AB8:2011
;;   Called from:
;;     1AB8:1F57 (in fn1AB8_1F19)
fn1AB8_2011 proc
	mov	dx,3BAh
	xor	bl,bl
	in	al,dx
	and	al,80h
	mov	ah,al
	mov	cx,8000h

l1AB8_201E:
	in	al,dx
	and	al,80h
	cmp	al,ah
	jz	202Ch

l1AB8_2025:
	inc	bl
	cmp	bl,0Ah
	jnc	2031h

l1AB8_202C:
	loop	201Eh

l1AB8_202E:
	xor	al,al
	ret

l1AB8_2031:
	mov	cx,8000h

l1AB8_2034:
	in	al,dx
	and	al,30h
	cmp	al,10h
	jnz	2040h

l1AB8_203B:
	loop	2034h

l1AB8_203D:
	mov	al,2h
	ret

l1AB8_2040:
	mov	al,1h
	ret

;; fn1AB8_2043: 1AB8:2043
;;   Called from:
;;     1AB8:1F35 (in fn1AB8_1F19)
fn1AB8_2043 proc
	mov	al,6h
	xor	cx,cx
	xor	dx,dx
	mov	ah,30h
	int	10h
	mov	ax,cx
	or	ax,dx
	jz	2070h

l1AB8_2053:
	push	ds
	mov	ds,cx
	mov	bx,dx
	mov	al,[bx+2h]
	pop	ds
	or	al,al
	jz	2064h

l1AB8_2060:
	cmp	al,2h
	jnz	2070h

l1AB8_2064:
	mov	dx,188h
	in	al,dx
	test	al,4h
	jz	2070h

l1AB8_206C:
	mov	ax,1h
	ret

l1AB8_2070:
	xor	ax,ax
	ret
1AB8:2073          20 00 D0 19 00 00 00 00 00 00 00 00 00     ............
1AB8:2080 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
1AB8:2090 00 00 00 1E 0E 1F 56 FF 94 13 00 5E 1F 2E FF 2E ......V....^....
1AB8:20A0 70 00 90 20 20 00 0C 02 96 02 D4 00 D4 00 3A 01 p..  .........:.
1AB8:20B0 45 01 92 01 D6 00 89 01 A8 01 B1 01 D4 00 D4 00 E...............
1AB8:20C0 D4 00 D4 00 E1 02 F0 02 21 03 20 14 D8 01 DE 01 ........!. .....
1AB8:20D0 02 02 61 01 89 01 80 01 D4 00 9E 01 9E 01 DD 00 ..a.............
1AB8:20E0 D4 00 D5 00 DB 00 D4 00 D4 00 D4 00 D4 00 D4 00 ................
1AB8:20F0 D4 00 D4 00 D4 00 D4 00 D4 00 D4 00 D4 00 D4 00 ................
1AB8:2100 D4 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
1AB8:2110 00 00 00 00 10 27 00 00 00 00 00 00 00 00 00 00 .....'..........
1AB8:2120 08 00 08 01 00 00 00 00 64 00 64 00 00 01 00 00 ........d.d.....
1AB8:2130 00 00 01 00 00 00 20 41 58 3D 00 20 42 58 3D 00 ...... AX=. BX=.
1AB8:2140 20 43 58 3D 00 20 44 58 3D 00 20 53 49 3D 00 20  CX=. DX=. SI=. 
1AB8:2150 44 49 3D 00 20 45 53 3D 00 20 44 53 3D 00 20 43 DI=. ES=. DS=. C
1AB8:2160 53 3D 00 5E 5E 1F CB C3 C3 E8 64 04 EB F5 EB F3 S=.^^.....d.....
1AB8:2170 50 C7 06 84 00 00 00 C7 06 86 00 00 00 80 E4 7F P...............
1AB8:2180 3B C1 72 01 91 3B DA 72 02 87 DA 23 C0 78 21 23 ;.r..;.r...#.x!#
1AB8:2190 DB 78 1D 83 F9 01 7C 18 83 FA 01 7C 13 A3 84 00 .x....|....|....
1AB8:21A0 89 1E 86 00 E8 16 00 58 22 E4 79 03 E8 02 00 C3 .......X".y.....
1AB8:21B0 58 33 C0 8B D8 8B 0E 7D 00 8B 16 7F 00 A3 88 00 X3.....}........
1AB8:21C0 89 1E 8A 00 89 0E 8C 00 89 16 8E 00 C3 E8 4C 00 ..............L.
1AB8:21D0 A3 80 03 89 1E 82 03 C3 8B 0E 80 03 8B 16 82 03 ................
1AB8:21E0 E8 EA FF 50 53 E8 80 03 5B 58 BE 08 00 FF 1E 70 ...PS...[X.....p
1AB8:21F0 00 E9 6F FF E8 25 00 E8 76 12 73 14 BE 2C 00 FF ..o..%..v.s..,..
1AB8:2200 1E 70 00 3C FF 75 09 C4 1E 78 00 26 C7 07 F9 FF .p.<.u...x.&....
1AB8:2210 E9 50 FF E8 06 00 E8 57 12 73 F5 C3 03 06 84 00 .P.....W.s......
1AB8:2220 03 1E 86 00 C3 E8 06 00 E8 3D 03 E9 35 FF E8 EB .........=..5...
1AB8:2230 FF 91 87 DA E8 E5 FF 91 87 DA C3 E8 F0 FF E8 E2 ................
1AB8:2240 11 73 CD C3 3D FF FF 74 1A FF 36 80 03 FF 36 82 .s..=..t..6...6.
1AB8:2250 03 BE 14 00 FF 1E 70 00 8F 06 82 03 8F 06 80 03 ......p.........
1AB8:2260 E9 00 FF 0E 07 BB 84 03 E9 F8 FE E8 32 12 E9 F2 ............2...
1AB8:2270 FE 80 3E 99 00 00 74 06 E8 2B 15 E9 E5 FE 80 3E ..>...t..+.....>
1AB8:2280 6F 00 00 74 0F 8B C1 F7 26 04 14 8B D8 8B 0E 06 o..t....&.......
1AB8:2290 14 E9 CF FE C3 88 26 02 14 A2 03 14 E9 C4 FE 22 ......&........"
1AB8:22A0 C0 74 01 C3 C6 06 92 00 00 C6 06 7C 00 00 89 1E .t.........|....
1AB8:22B0 70 00 8C 06 72 00 A2 6F 00 33 C0 8B F0 FF 1E 70 p...r..o.3.....p
1AB8:22C0 00 89 1E 74 00 8C 06 76 00 06 53 C4 3E 70 00 83 ...t...v..S.>p..
1AB8:22D0 C7 10 B0 9A FC AA B8 C8 03 AB 8C C8 AB 2E C4 36 ...............6
1AB8:22E0 74 00 83 C6 02 26 8B 04 A3 7D 00 2E C4 36 74 00 t....&...}...6t.
1AB8:22F0 83 C6 04 26 8B 04 A3 7F 00 A1 7D 00 B9 E8 03 F7 ...&......}.....
1AB8:2300 E1 2E C4 36 74 00 83 C6 0A 26 F7 34 40 A3 95 00 ...6t....&.4@...
1AB8:2310 A1 7F 00 F7 E1 2E C4 36 74 00 83 C6 0C 26 F7 34 .......6t....&.4
1AB8:2320 40 A3 97 00 5B 07 E9 3A FE 50 53 51 52 06 26 8B @...[..:.PSQR.&.
1AB8:2330 47 0C 40 40 A3 33 05 26 8B 47 0E A3 35 05 26 8B G.@@.3.&.G..5.&.
1AB8:2340 47 10 33 D2 B9 06 00 F7 F1 A3 2F 05 26 C4 5F 1A G.3......./.&._.
1AB8:2350 89 1E 78 00 8C 06 7A 00 07 5A 59 5B 58 FF 1E 70 ..x...z..ZY[X..p
1AB8:2360 00 C6 06 99 00 00 E9 FA FD A3 9A 00 BE 1E 00 FF ................
1AB8:2370 1E 70 00 C3 A3 9A 00 C3 A3 90 00 BE 20 00 FF 1E .p.......... ...
1AB8:2380 70 00 C3 3C FF 75 07 C7 06 90 00 0C 0C C3 A3 90 p..<.u..........
1AB8:2390 00 C3 32 C0 8B 1E A1 00 B9 01 00 EB 05 32 C0 B9 ..2..........2..
1AB8:23A0 03 00 A2 9E 00 88 0E 9F 00 B9 01 00 BE 22 00 FF ............."..
1AB8:23B0 1E 70 00 C3 A2 9E 00 88 0E 9F 00 89 1E A1 00 C3 .p..............
1AB8:23C0 2E 8A 07 0A C0 74 06 E8 38 00 43 EB F3 C3 B1 64 .....t..8.C....d
1AB8:23D0 E8 07 00 B1 0A E8 02 00 EB 04 32 E4 F6 F1 04 30 ..........2....0
1AB8:23E0 50 E8 1E 00 58 8A C4 C3 50 8A C4 E8 01 00 58 50 P...X...P.....XP
1AB8:23F0 B1 04 D2 E8 E8 03 00 58 24 0F 04 30 3C 3A 72 02 .......X$..0<:r.
1AB8:2400 04 07 8A D0 B4 06 CD 21 C3 00 00 00 00 00 00 00 .......!........
1AB8:2410 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
; ...
1AB8:2430 00 10 00 1A 07 12 00 93 04 20 00 5A 04 26 00 C9 ......... .Z.&..
1AB8:2440 18 24 00 37 14 28 00 13 17 16 00 A2 08 18 00 7F .$.7.(..........
1AB8:2450 08 0E 00 83 0B 14 00 23 08 00 00 1E 0E 1F 50 8B .......#......P.
1AB8:2460 FE BE 9E 03 AD 23 C0 74 0C 3B C7 AD 75 F6 8B F8 .....#.t.;..u...
1AB8:2470 58 FF D7 1F CB 58 1F CB A1 80 03 8B 1E 82 03 EB X....X..........
1AB8:2480 0A 2E A3 80 03 2E 89 1E 82 03 C3 E8 9A 02 72 0E ..............r.
1AB8:2490 A3 80 03 89 1E 82 03 BE 08 00 FF 1E 70 00 C3 03 ............p...
1AB8:24A0 06 80 03 03 1E 82 03 A3 80 03 89 1E 82 03 EB DB ................
1AB8:24B0 03 06 80 03 03 1E 82 03 50 53 E8 0A 00 5B 58 A3 ........PS...[X.
1AB8:24C0 80 03 89 1E 82 03 C3 E8 5E 02 72 13 51 52 8B C8 ........^.r.QR..
1AB8:24D0 8B D3 87 06 80 03 87 1E 82 03 E8 8B 00 5A 59 C3 .............ZY.
1AB8:24E0 E8 40 0F 73 07 BE 12 00 FF 1E 70 00 C3 A3 90 00 .@.s......p.....
1AB8:24F0 C6 06 82 0B FF C3 00 00 00 00 00 00 00 00 00 00 ................
1AB8:2500 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
; ...
1AB8:2520 00 00 00 00 00 00 0E 07 43 41 8B FB BB 63 04 89 ........CA...c..
1AB8:2530 07 89 7F 02 89 47 04 89 57 06 89 4F 08 89 57 0A .....G..W..O..W.
1AB8:2540 89 4F 0C 89 7F 0E 89 47 10 89 7F 12 B8 00 80 89 .O.....G........
1AB8:2550 47 14 89 47 16 B8 06 00 B9 08 00 BE 0E 00 FF 1E G..G............
1AB8:2560 70 00 C3 E8 C2 01 72 13 80 3E 9F 00 03 73 0D E8 p.....r..>...s..
1AB8:2570 FD 0C 73 07 BE 0C 00 FF 1E 70 00 C3 E8 34 00 8B ..s......p...4..
1AB8:2580 F8 2B F9 79 02 F7 DF 8B F3 2B F2 79 02 F7 DE 3B .+.y.....+.y...;
1AB8:2590 FE 8B 3E 80 0B 73 0F 2B C7 2B CF E8 15 00 D1 E7 ..>..s.+.+......
1AB8:25A0 03 C7 03 CF EB 0D 2B DF 2B D7 E8 06 00 D1 E7 03 ......+.+.......
1AB8:25B0 DF 03 D7 50 53 51 52 57 E8 B4 FF 5F 5A 59 5B 58 ...PSQRW..._ZY[X
1AB8:25C0 C3 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
1AB8:25D0 3C 08 72 02 B0 05 32 E4 D0 E0 8B F8 FF A5 4D 05 <.r...2.......M.
1AB8:25E0 5D 05 C1 05 FF 05 C6 05 6F 05 EB 05 75 05 79 05 ].......o...u.y.
1AB8:25F0 C6 06 2E 05 01 C7 06 31 05 00 00 C7 06 37 05 00 .......1.....7..
1AB8:2600 00 C3 C6 06 2E 05 02 C3 32 C0 EB 02 B0 FF E3 43 ........2......C
1AB8:2610 50 06 53 51 33 C0 E8 B7 FF 59 5F 07 E8 F0 00 E8 P.SQ3....Y_.....
1AB8:2620 FA FB E8 E0 00 23 C9 75 F3 58 22 C0 B8 01 00 74 .....#.u.X"....t
1AB8:2630 1F C4 1E 33 05 26 8B 07 26 8B 5F 02 C7 06 37 05 ...3.&..&._...7.
1AB8:2640 00 00 E8 46 FE B8 03 00 80 3E 9A 00 00 74 01 48 ...F.....>...t.H
1AB8:2650 E8 7D FF C3 E8 2D 00 EB 58 E8 28 00 A1 31 05 3B .}...-..X.(..1.;
1AB8:2660 06 2F 05 73 19 3D 04 00 72 14 C4 1E 33 05 8B 0E ./.s.=..r...3...
1AB8:2670 2F 05 C6 06 2E 05 00 BE 0E 00 FF 1E 70 00 C6 06 /...........p...
1AB8:2680 2E 05 00 C3 B8 00 80 8B D8 E8 FF FD C6 06 2E 05 ................
1AB8:2690 00 C3 81 3E 97 00 B4 00 72 05 C6 06 82 0B FF 80 ...>....r.......
1AB8:26A0 3E 82 0B 00 74 08 E8 DB FF E8 05 00 EB AE E8 A8 >...t...........
1AB8:26B0 FF C6 06 2E 05 00 C4 3E 33 05 8B 0E 31 05 3B 0E .......>3...1.;.
1AB8:26C0 2F 05 72 03 E9 D7 00 83 F9 02 72 B2 FF 36 80 03 /.r.......r..6..
1AB8:26D0 FF 36 82 03 E8 2B 00 E8 35 00 80 FF 80 75 0D 22 .6...+..5....u."
1AB8:26E0 DB 74 16 E8 1C 00 23 C9 75 ED EB 0D 06 57 51 E8 .t....#.u....WQ.
1AB8:26F0 D5 FD 59 5F 07 23 C9 75 DE 8F 06 82 03 8F 06 80 ..Y_.#.u........
1AB8:2700 03 C3 E8 0A 00 06 57 51 E8 80 FD 59 5F 07 C3 BB ......WQ...Y_...
1AB8:2710 00 80 E3 0B 26 8B 05 47 47 26 8B 1D 47 47 49 C3 ....&..GG&..GGI.
1AB8:2720 1E 0E 1F E8 02 00 1F C3 80 3E 2E 05 00 74 6E 80 .........>...tn.
1AB8:2730 3E 2E 05 02 74 10 83 3E 37 05 00 75 1A A3 39 05 >...t..>7..u..9.
1AB8:2740 89 1E 3B 05 EB 36 8A 16 9A 00 E8 23 0D 73 07 BE ..;..6.....#.s..
1AB8:2750 30 00 FF 1E 70 00 C3 3B 06 39 05 75 1F 3B 1E 3B 0...p..;.9.u.;.;
1AB8:2760 05 75 19 83 3E 37 05 01 74 32 E8 0F 00 B8 01 80 .u..>7..t2......
1AB8:2770 8B D8 E8 07 00 C7 06 37 05 00 00 C3 FF 06 37 05 .......7......7.
1AB8:2780 8B 3E 31 05 3B 3E 2F 05 73 14 D1 E7 D1 E7 C4 36 .>1.;>/.s......6
1AB8:2790 33 05 03 FE AB 26 89 1D FF 06 31 05 F9 C3 06 53 3....&....1....S
1AB8:27A0 C4 1E 78 00 26 C7 07 FA FF 5B 07 F9 C3 51 52 A3 ..x.&....[...QR.
1AB8:27B0 94 03 89 1E 96 03 8B 0E 80 03 8B 16 82 03 89 0E ................
1AB8:27C0 90 03 89 16 92 03 E8 D1 00 A1 9A 00 72 09 86 E0 ............r...
1AB8:27D0 BE 1E 00 FF 1E 70 00 8B 1E 96 03 53 A1 90 03 E8 .....p.....S....
1AB8:27E0 E5 FC A1 94 03 5B 50 E8 DD FC 58 8B 1E 92 03 53 .....[P...X....S
1AB8:27F0 E8 D4 FC 5B A1 90 03 E8 CD FC A1 94 03 8B 1E 92 ...[............
1AB8:2800 03 50 E8 86 FC 58 5A 59 0B C9 74 3F 52 8B D1 8B .P...XZY..t?R...
1AB8:2810 FA D1 E2 03 D7 D1 EA D1 EA 80 3E 92 00 00 74 0F ..........>...t.
1AB8:2820 8B CA F7 D9 5F 23 FF 75 05 E8 4F 00 EB 1D 57 03 ...._#.u..O...W.
1AB8:2830 C1 2B DA 50 E8 90 FC 58 8B 1E 96 03 2B DA 53 E8 .+.P...X....+.S.
1AB8:2840 85 FC 5B 5F 23 FF 74 03 E8 0B 00 A1 9A 00 BE 1E ..[_#.t.........
1AB8:2850 00 FF 1E 70 00 C3 A1 90 03 03 C1 E8 69 FC A1 90 ...p........i...
1AB8:2860 03 8B 1E 96 03 53 E8 5E FC 5B A1 94 03 50 53 E8 .....S.^.[...PS.
1AB8:2870 19 FC 5B 58 03 C1 2B DA E9 4C FC A1 90 03 8B 1E ..[X..+..L......
1AB8:2880 96 03 53 50 E8 04 FC 58 5B 2B DA 03 C1 53 E8 36 ..SP...X[+...S.6
1AB8:2890 FC A1 94 03 03 C1 5B E9 2D FC 3B C1 7C 01 91 3B ......[.-.;.|..;
1AB8:28A0 DA 7D 02 87 DA 40 49 4B 42 E8 34 FC F9 C3 F8 C3 .}...@IKB.4.....
1AB8:28B0 00 00 00 00 00 FF C6 06 22 08 00 E8 44 01 80 3E ........"...D..>
1AB8:28C0 9F 00 03 73 12 BE 04 00 80 3E 82 0B 00 75 08 81 ...s.....>...u..
1AB8:28D0 3E 97 00 B4 00 72 2F 50 53 32 C0 B9 01 00 BE 22 >....r/PS2....."
1AB8:28E0 00 FF 1E 70 00 33 C0 E8 E6 FC 5B 58 E8 A5 02 E8 ...p.3....[X....
1AB8:28F0 76 02 B8 01 00 E8 D8 FC A0 9E 00 B9 01 00 BE 22 v.............."
1AB8:2900 00 FF 1E 70 00 C3 E8 10 01 E8 5C 02 B8 05 00 E9 ...p......\.....
1AB8:2910 BE FC FF 36 80 03 FF 36 82 03 50 53 FF 36 9A 00 ...6...6..PS.6..
1AB8:2920 33 FF 57 8B 3E 80 03 03 F8 8B 36 82 03 57 56 57 3.W.>.....6..WVW
1AB8:2930 56 E8 4F 05 C3 C6 06 22 08 FF 80 3E 92 00 00 74 V.O...."...>...t
1AB8:2940 02 87 CA E8 BC 00 80 3E 82 0B 00 75 08 81 3E 97 .......>...u..>.
1AB8:2950 00 B4 00 72 03 E9 8F 02 33 D2 88 16 21 08 89 16 ...r....3...!...
1AB8:2960 1D 08 89 16 1F 08 89 16 94 03 89 16 96 03 89 16 ................
1AB8:2970 98 03 89 16 9A 03 E8 D0 01 50 53 33 D2 B9 5A 00 .........PS3..Z.
1AB8:2980 F7 F1 8B F8 8B C3 33 D2 F7 F1 3D 04 00 72 03 B8 ......3...=..r..
1AB8:2990 03 00 8B F0 5B 58 3B F7 74 1E 53 50 B8 5A 00 47 ....[X;.t.SP.Z.G
1AB8:29A0 F7 E7 8B D8 58 53 33 F6 3B C3 9C E8 6B 00 9D 74 ....XS3.;...k..t
1AB8:29B0 03 E8 0E 01 58 5B EB C1 33 F6 3B C3 9C E8 59 00 ....X[..3.;...Y.
1AB8:29C0 9D 74 03 E8 FC 00 A1 80 03 8B 1E 82 03 8B 0E 1D .t..............
1AB8:29D0 08 89 0E 94 03 8B 16 1F 08 89 16 96 03 80 3E 22 ..............>"
1AB8:29E0 08 00 74 1A 03 C8 03 D3 50 53 E8 76 FB 5B 58 8B ..t.....PS.v.[X.
1AB8:29F0 0E 98 03 8B 16 9A 03 03 C8 03 D3 E8 65 FB E8 67 ............e..g
1AB8:2A00 01 C3 89 0E 90 03 89 16 92 03 50 A1 80 03 A3 84 ..........P.....
1AB8:2A10 03 A1 82 03 A3 86 03 58 C3 8B 0E 90 03 8B 16 92 .......X........
1AB8:2A20 03 80 3E 92 00 00 74 06 05 5A 00 83 C3 5A 8B FB ..>...t..Z...Z..
1AB8:2A30 2B F8 89 3E 93 00 23 FF 75 03 E9 BF 00 FF 36 80 +..>..#.u.....6.
1AB8:2A40 03 FF 36 82 03 51 52 FF 36 9A 00 BF FF FF 57 56 ..6..QR.6.....WV
1AB8:2A50 53 53 50 50 E8 BE 00 A3 94 03 58 E8 C4 00 A3 96 SSPP......X.....
1AB8:2A60 03 58 E8 B0 00 A3 98 03 58 E8 B6 00 A3 9A 03 5E .X......X......^
1AB8:2A70 5E FF 36 94 03 FF 36 96 03 FF 36 98 03 50 8B C6 ^.6...6...6..P..
1AB8:2A80 E8 4D FB A1 94 03 3B 06 98 03 75 16 A1 96 03 3B .M....;...u....;
1AB8:2A90 06 9A 03 75 0D 81 3E 93 00 5E 01 73 21 83 C4 14 ...u..>..^.s!...
1AB8:2AA0 EB 0A 83 3E 93 00 02 73 15 83 C4 14 A1 98 03 8B ...>...s........
1AB8:2AB0 1E 9A 03 03 06 80 03 03 1E 82 03 E9 CD F9 E8 C2 ................
1AB8:2AC0 03 C3 80 3E 22 08 00 75 08 B8 01 00 E8 01 FB EB ...>"..u........
1AB8:2AD0 2B E8 A4 F9 C4 1E 33 05 26 8B 07 26 8B 5F 02 C7 +.....3.&..&._..
1AB8:2AE0 06 37 05 00 00 E8 A3 F9 B8 03 00 E8 E2 FA A1 31 .7.............1
1AB8:2AF0 05 2D 03 00 72 06 A3 31 05 E8 B5 FB 80 3E 21 08 .-..r..1.....>!.
1AB8:2B00 00 75 11 C6 06 21 08 FF A1 94 03 A3 1D 08 A1 96 .u...!..........
1AB8:2B10 03 A3 1F 08 C3 5F E8 D1 06 8B 0E 90 03 E8 11 00 ....._..........
1AB8:2B20 FF E7 5F E8 D1 06 8B 0E 92 03 E8 04 00 F7 D8 FF .._.............
1AB8:2B30 E7 8B D0 8B C3 8B D9 E8 03 00 8B C2 C3 8B C8 8B ................
1AB8:2B40 C2 F7 E3 91 F7 E3 03 D1 C3 51 52 B9 68 01 33 D2 .........QR.h.3.
1AB8:2B50 F7 F1 52 3B D9 74 08 33 D2 8B C3 F7 F1 8B DA 58 ..R;.t.3.......X
1AB8:2B60 3B C3 72 01 93 5A 59 C3 0E 07 FC BE 84 03 8B FE ;.r..ZY.........
1AB8:2B70 AD 2B 06 84 00 AB 8B D8 AD 2B 06 86 00 AB 8B C8 .+.......+......
1AB8:2B80 BE 94 03 AD 03 C3 AB AD 03 C1 AB AD 03 C3 AB AD ................
1AB8:2B90 03 C1 AB C3 3B C3 72 0B 81 C3 68 01 EB 05 3B C3 ....;.r...h...;.
1AB8:2BA0 72 01 93 80 3E 92 00 00 74 06 05 5A 00 83 C3 5A r...>...t..Z...Z
1AB8:2BB0 8B 0E 90 03 89 0E 90 03 8B 0E 92 03 89 0E 92 03 ................
1AB8:2BC0 53 50 50 50 E8 4E FF A3 9C 03 58 E8 54 FF 8B D8 SPPP.N....X.T...
1AB8:2BD0 A1 9C 03 03 06 80 03 03 1E 82 03 E8 AD F8 58 58 ..............XX
1AB8:2BE0 5B 40 3B C3 7E DA C3 50 53 33 C0 E8 E2 F9 5B 58 [@;.~..PS3....[X
1AB8:2BF0 E8 AB FF E8 82 F8 C4 1E 33 05 26 8B 07 26 8B 5F ........3.&..&._
1AB8:2C00 02 E8 87 F8 B8 02 00 E9 C6 F9 00 00 00 00 00 00 ................
1AB8:2C10 00 00 00 01 00 00 81 3E 97 00 B4 00 72 05 C6 06 .......>....r...
1AB8:2C20 82 0B FF 8B EC 83 EC 18 3D 03 00 72 26 89 4E F0 ........=..r&.N.
1AB8:2C30 89 5E FE 89 46 F8 D1 E0 D1 E0 03 D8 89 5E FC FF .^..F........^..
1AB8:2C40 36 9A 00 E8 D2 01 73 0B E8 0F 00 E8 2A 02 73 03 6.....s.....*.s.
1AB8:2C50 E8 07 00 58 83 C4 18 E9 0F F7 06 1F E8 DA 00 8B ...X............
1AB8:2C60 46 F4 89 46 F6 C7 46 EE 00 00 E8 2E 00 E8 F8 00 F..F..F.........
1AB8:2C70 8B 46 EC 80 7E E8 02 72 12 FF 46 EE 8B 5E EA 3B .F..~..r..F..^.;
1AB8:2C80 5E EE 75 07 C7 46 EE 00 00 F7 EB 01 46 F6 8B 46 ^.u..F......F..F
1AB8:2C90 F6 3B 46 F2 7C D4 1E 07 0E 1F C3 C7 46 FA 00 00 .;F.|.......F...
1AB8:2CA0 8B 5E FE 43 43 8B 0F 8B 46 F6 83 C3 04 8B F9 8B .^.CC...F.......
1AB8:2CB0 17 8B CA 80 FE 80 74 1A 3B D7 7C 02 87 D7 3B C2 ......t.;.|...;.
1AB8:2CC0 7C E8 3B C7 7D E4 53 51 E8 17 00 E8 3B 00 59 5B |.;.}.SQ....;.Y[
1AB8:2CD0 EB D5 80 FA 01 75 0A 83 C3 04 8B 0F 80 FD 80 75 .....u.........u
1AB8:2CE0 C6 C3 8B 77 FA 8B 7F FC 8B 4F FE 8B 17 3B D7 7C ...w.....O...;.|
1AB8:2CF0 04 87 CE 87 D7 8B C1 2B FA 74 0D 8B 46 F6 2B C2 .......+.t..F.+.
1AB8:2D00 2B F1 F7 EE F7 FF 03 C1 C3 8B D0 8B 76 FC 8B 46 +...........v..F
1AB8:2D10 FA 3B 46 F0 73 22 FF 46 FA 23 C0 74 15 48 8B D8 .;F.s".F.#.t.H..
1AB8:2D20 D1 E3 8B 08 40 3B CA 7C 09 8B D8 D1 E3 89 08 48 ....@;.|.......H
1AB8:2D30 75 EB 8B D8 D1 E3 89 10 C3 C7 46 F4 FF 7F C7 46 u.........F....F
1AB8:2D40 F2 00 80 8B 5E FE 43 43 8B 07 43 43 80 FC 80 75 ....^.CC..CC...u
1AB8:2D50 05 3C 01 74 F1 C3 3B 46 F4 7D 03 89 46 F4 3B 46 .<.t..;F.}..F.;F
1AB8:2D60 F2 7C E3 89 46 F2 EB DE 8B 76 FC 33 C0 8B 4E FA .|..F....v.3..N.
1AB8:2D70 E3 26 8B D8 D1 E3 50 56 1E 55 A9 01 00 8B 00 8B .&....PV.U......
1AB8:2D80 5E F6 0E 1F 75 05 E8 14 00 EB 03 E8 21 00 5D 1F ^...u.......!.].
1AB8:2D90 5E 58 40 3B 46 FA 72 DA C3 00 00 00 00 83 3E E3 ^X@;F.r.......>.
1AB8:2DA0 0D 00 74 03 E8 D1 00 A3 06 0D 89 1E 08 0D C3 83 ..t.............
1AB8:2DB0 3E E3 0D 00 74 03 E8 BF 00 8B C8 8B D3 87 0E 06 >...t...........
1AB8:2DC0 0D 87 16 08 0D 3B C1 72 01 91 80 3E 82 0B 00 75 .....;.r...>...u
1AB8:2DD0 03 E9 0C F7 BE 0C 00 FF 1E 70 00 C3 00 00 01 00 .........p......
1AB8:2DE0 00 02 04 02 00 5A 00 00 0A E1 87 02 0A 01 E1 87 .....Z..........
1AB8:2DF0 02 02 05 87 E1 03 02 05 87 87 01 5A 0A 00 00 01 ...........Z....
1AB8:2E00 87 11 E1 E1 03 05 01 00 00 03 0A 01 00 00 03 05 ................
1AB8:2E10 02 00 00 00 00 01 00 00 C7 06 E3 0D 00 00 A0 90 ................
1AB8:2E20 00 FE C8 F8 78 4F 80 3E 82 0B 00 75 02 32 C0 8A ....xO.>...u.2..
1AB8:2E30 D8 D0 E3 D0 E3 02 D8 32 FF 81 C3 49 0D 8B F3 AC .......2...I....
1AB8:2E40 88 46 E8 AC 32 E4 89 46 EA AC F7 2E 80 0B 89 46 .F..2..F.......F
1AB8:2E50 EC AC 32 E4 80 3E 92 00 00 74 08 80 3E 82 0B 00 ..2..>...t..>...
1AB8:2E60 74 01 AC E8 12 00 06 A0 9B 00 8A E0 BE 1E 00 FF t...............
1AB8:2E70 1E 70 00 07 F9 C3 00 00 32 C0 C3 00 00 00 00 00 .p......2.......
1AB8:2E80 00 00 00 55 8B EC 83 EC 2A 8B 46 0E E8 72 02 89 ...U....*.F..r..
1AB8:2E90 46 0E A3 9A 00 8B 46 0A 8B 5E 08 E8 15 02 89 46 F.....F..^.....F
1AB8:2EA0 DA 8B 46 06 8B 5E 04 E8 09 02 C6 46 D6 00 3B 46 ..F..^.....F..;F
1AB8:2EB0 DA 7F 04 C6 46 D6 FF 89 46 D8 F7 46 12 FF FF 75 ....F...F..F...u
1AB8:2EC0 03 FF 46 12 F7 46 10 FF FF 75 03 FF 46 10 8B 46 ..F..F...u..F..F
1AB8:2ED0 10 8B 5E 12 3B C3 77 02 8B C3 F7 E0 BB 64 00 E8 ..^.;.w......d..
1AB8:2EE0 0A 02 73 03 E9 D1 00 89 46 DC 89 56 DE 8B 5E 12 ..s.....F..V..^.
1AB8:2EF0 E8 E7 01 E8 E4 01 89 46 F8 89 56 FA 33 C0 89 46 .......F..V.3..F
1AB8:2F00 FE 89 46 EC 89 46 EE 8B 46 DC 8B 56 DE 8B 5E 10 ..F..F..F..V..^.
1AB8:2F10 89 5E FC E8 C4 01 E8 C1 01 89 46 F4 89 56 F6 E8 .^........F..V..
1AB8:2F20 CA 01 73 03 E9 91 00 8B F2 8B F8 E8 BE 01 73 03 ..s...........s.
1AB8:2F30 E9 85 00 2B 46 DC 1B 56 DE 89 46 F0 89 56 F2 D1 ...+F..V..F..V..
1AB8:2F40 E7 D1 D6 89 7E E8 89 76 EA E8 DE 00 E8 72 00 8B ....~..v.....r..
1AB8:2F50 46 F0 8B 5E F2 03 C0 13 DB 03 46 E4 13 5E E6 03 F..^......F..^..
1AB8:2F60 46 E4 13 5E E6 3B 5E E2 7C 0A 75 05 3B 46 E0 72 F..^.;^.|.u.;F.r
1AB8:2F70 03 E8 94 00 E8 6F 00 8B 46 EE 3B 46 EA 7C CA 75 .....o..F.;F.|.u
1AB8:2F80 08 8B 46 EC 3B 46 E8 72 C0 E8 9E 00 E8 32 00 8B ..F.;F.r.....2..
1AB8:2F90 46 E4 8B 5E E6 D1 EB D1 D8 03 46 F0 13 5E F2 3B F..^......F..^.;
1AB8:2FA0 5E E2 7F 0A 75 05 3B 46 E0 77 03 E8 38 00 E8 57 ^...u.;F.w..8..W
1AB8:2FB0 00 F7 46 FC 00 80 74 D1 8B E5 5D E8 58 01 C2 14 ..F...t...].X...
1AB8:2FC0 00 8B 46 EC 03 46 F8 89 46 E4 8B 46 EE 13 46 FA ..F..F..F..F..F.
1AB8:2FD0 89 46 E6 8B 46 E8 2B 46 F4 89 46 E0 8B 46 EA 1B .F..F.+F..F..F..
1AB8:2FE0 46 F6 89 46 E2 C3 FF 46 FE 8B 46 E4 01 46 F0 8B F..F...F..F..F..
1AB8:2FF0 46 E6 11 46 F2 8B 46 E4 03 46 F8 89 46 EC 8B 46 F..F..F..F..F..F
1AB8:3000 E6 13 46 FA 89 46 EE C3 FF 4E FC 8B 46 E0 29 46 ..F..F...N..F.)F
1AB8:3010 F0 8B 46 E2 19 46 F2 8B 46 E0 2B 46 F4 89 46 E8 ..F..F..F.+F..F.
1AB8:3020 8B 46 E2 1B 46 F6 89 46 EA C3 8B 56 0E 8B 76 FE .F..F..F...V..v.
1AB8:3030 8B 7E FC F7 46 0C 00 80 75 37 56 57 8B C6 8B DF .~..F...u7VW....
1AB8:3040 8B C8 8B D3 F7 D8 E8 16 00 5F 5E 56 57 F7 DF 8B ........._^VW...
1AB8:3050 C6 8B DF 8B C8 8B D3 F7 D8 E8 03 00 5F 5E C3 03 ............_^..
1AB8:3060 46 16 03 5E 14 03 4E 16 03 56 14 55 E8 71 F4 5D F..^..N..V.U.q.]
1AB8:3070 C3 E8 0E 00 F7 DE E8 09 00 F7 DE F7 DF E8 02 00 ................
1AB8:3080 F7 DE 8B C6 8B DF E8 2A 00 80 7E D6 00 75 0B 3B .......*..~..u.;
1AB8:3090 46 DA 7C 05 3B 46 D8 7E 0C C3 3B 46 DA 7D 06 3B F.|.;F.~..;F.}.;
1AB8:30A0 46 D8 7E 01 C3 57 56 03 76 16 03 7E 14 E8 4A 00 F.~..WV.v..~..J.
1AB8:30B0 5E 5F C3 F7 DB 0A E4 78 0F 0A FF 78 05 2B D8 8B ^_.....x...x.+..
1AB8:30C0 C3 C3 05 70 17 03 C3 C3 0A FF 78 08 F7 D8 05 D0 ...p......x.....
1AB8:30D0 07 2B C3 C3 05 A0 0F 2B C3 C3 0B DB F9 74 0C 33 .+.....+.....t.3
1AB8:30E0 C9 87 CA 91 F7 F3 91 F7 F3 87 CA C3 8B C8 8B C2 ................
1AB8:30F0 F7 E3 72 05 91 F7 E3 03 D1 C3 8B C6 8B DF E9 8A ..r.............
1AB8:3100 F3 80 3E 6F 00 00 75 24 50 BE 32 00 FF 1E 70 00 ..>o..u$P.2...p.
1AB8:3110 26 8B 1F 58 EB 12 80 3E 6F 00 00 75 0F BE 32 00 &..X...>o..u..2.
1AB8:3120 FF 1E 70 00 26 8B 5F 02 0E E8 01 00 C3 06 53 CB ..p.&._.......S.
1AB8:3130 00 00 00 00 00 00 3B 02 77 04 B2 06 ED 08 27 0B ......;.w.....'.
1AB8:3140 61 0D 99 0F D0 11 06 14 3A 16 6C 18 9C 1A CB 1C a.......:.l.....
1AB8:3150 F7 1E 20 21 48 23 6C 25 8D 27 AC 29 C7 2B DF 2D .. !H#l%.'.).+.-
1AB8:3160 F3 2F 03 32 0F 34 18 36 1C 38 1C 3A 17 3C 0E 3E ./.2.4.6.8.:.<.>
1AB8:3170 00 40 EC 41 D4 43 B6 45 93 47 6A 49 3C 4B 08 4D .@.A.C.E.GjI<K.M
1AB8:3180 CD 4E 8D 50 46 52 F9 53 A6 55 4B 57 EA 58 82 5A .N.PFR.S.UKW.X.Z
1AB8:3190 13 5C 9C 5D 1F 5F 9A 60 0D 62 79 63 DD 64 39 66 .\.]._.`.byc.d9f
1AB8:31A0 8D 67 D9 68 1D 6A 59 6B 8C 6C B7 6D D9 6E F3 6F .g.h.jYk.l.m.n.o
1AB8:31B0 04 71 0C 72 0B 73 01 74 EF 74 D3 75 AD 76 7F 77 .q.r.s.t.t.u.v.w
1AB8:31C0 47 78 06 79 BC 79 68 7A 0A 7B A3 7B 32 7C B8 7C Gx.y.yhz.{.{2|.|
1AB8:31D0 33 7D A5 7D 0E 7E 6C 7E C1 7E 0B 7F 4C 7F 83 7F 3}.}.~l~.~..L...
1AB8:31E0 B0 7F D3 7F EC 7F FB 7F 00 80 55 83 EC 00 8B EC ..........U.....
1AB8:31F0 83 46 04 5A EB 07 90 55 83 EC 00 8B EC C6 06 A0 .F.Z...U........
1AB8:3200 10 00 8B 46 04 85 C0 7D 06 F7 D8 F6 16 A0 10 33 ...F...}.......3
1AB8:3210 D2 B9 68 01 F7 F9 8B C2 3D B4 00 7E 07 2D B4 00 ..h.....=..~.-..
1AB8:3220 F6 16 A0 10 3D 5A 00 7E 05 F7 D8 05 B4 00 D1 E0 ....=Z.~........
1AB8:3230 8B F0 8B 9C A1 10 8B CB 33 C0 F8 D1 D3 D1 D0 80 ........3.......
1AB8:3240 3E A0 10 00 74 0A F7 D3 F7 D0 83 C3 01 15 00 00 >...t...........
1AB8:3250 83 C4 00 5D C3 00 00 00 00 00 00 00 00 00 00 00 ...]............
1AB8:3260 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 C6 ................
1AB8:3270 06 83 00 01 80 3E 92 00 00 75 39 E8 F2 01 73 0C .....>...u9...s.
1AB8:3280 91 87 DA E8 EA 01 91 87 DA 73 01 C3 A3 D4 11 89 .........s......
1AB8:3290 1E D6 11 89 0E D8 11 89 16 DA 11 E8 28 00 80 3E ............(..>
1AB8:32A0 83 00 00 74 11 A1 D4 11 8B 1E D6 11 8B 0E D8 11 ...t............
1AB8:32B0 8B 16 DA 11 F9 C3 B8 FF FF 8B D8 8B C8 8B D0 C6 ................
1AB8:32C0 06 83 00 00 F8 C3 BB D4 11 E8 F4 00 8A E8 BB D8 ................
1AB8:32D0 11 E8 EC 00 0A C5 75 01 C3 A1 D8 11 2B 06 D4 11 ......u.....+...
1AB8:32E0 70 D4 A3 D0 11 A1 DA 11 2B 06 D6 11 70 C8 A3 D2 p.......+...p...
1AB8:32F0 11 BB D4 11 E8 C9 00 8A E8 BB D8 11 E8 C1 00 8A ................
1AB8:3300 D0 0A C5 75 01 C3 22 D5 74 06 C6 06 83 00 00 C3 ...u..".t.......
1AB8:3310 22 ED 75 03 E8 D5 00 C6 06 83 00 02 83 3E D0 11 ".u..........>..
1AB8:3320 00 75 1E A1 D6 11 3B 06 8A 00 7D 06 A1 8A 00 A3 .u....;...}.....
1AB8:3330 D6 11 A1 8E 00 3B 06 D6 11 7D 03 A3 D6 11 EB 76 .....;...}.....v
1AB8:3340 90 83 3E D2 11 00 75 1E A1 D4 11 3B 06 88 00 7D ..>...u....;...}
1AB8:3350 06 A1 88 00 A3 D4 11 A1 8C 00 3B 06 D4 11 7D 03 ..........;...}.
1AB8:3360 A3 D4 11 EB 51 90 A1 D4 11 3B 06 88 00 7D 0D A1 ....Q....;...}..
1AB8:3370 88 00 50 E8 9C 00 8F 06 D4 11 EB 3A A1 8C 00 3B ..P........:...;
1AB8:3380 06 D4 11 7D 0A 50 E8 89 00 8F 06 D4 11 EB 27 A1 ...}.P........'.
1AB8:3390 D6 11 3B 06 8A 00 7D 0D A1 8A 00 50 E8 62 00 8F ..;...}....P.b..
1AB8:33A0 06 D6 11 EB 11 A1 8E 00 3B 06 D6 11 7D 08 50 E8 ........;...}.P.
1AB8:33B0 4F 00 8F 06 D6 11 22 ED 75 03 E8 2F 00 E9 31 FF O.....".u../..1.
1AB8:33C0 32 D2 8B 07 3B 06 88 00 7D 02 B2 01 3B 06 8C 00 2...;...}...;...
1AB8:33D0 7E 02 B2 02 8B 47 02 3B 06 8A 00 7D 03 80 C2 04 ~....G.;...}....
1AB8:33E0 3B 06 8E 00 7E 03 80 C2 08 8A C2 C3 A1 D4 11 87 ;...~...........
1AB8:33F0 06 D8 11 A3 D4 11 A1 D6 11 87 06 DA 11 A3 D6 11 ................
1AB8:3400 C3 2B 06 D6 11 F7 2E D0 11 F7 3E D2 11 01 06 D4 .+........>.....
1AB8:3410 11 C3 2B 06 D4 11 F7 2E D2 11 F7 3E D0 11 01 06 ..+........>....
1AB8:3420 D6 11 C3 80 3E 92 00 00 75 36 50 53 51 52 E8 3E ....>...u6PSQR.>
1AB8:3430 FE 72 05 87 DA E8 37 FE 5A 59 5B 58 73 23 8B 3E .r....7.ZY[Xs#.>
1AB8:3440 88 00 8B 36 8C 00 E8 19 00 91 E8 15 00 91 8B 3E ...6...........>
1AB8:3450 8A 00 8B 36 8E 00 93 E8 08 00 93 92 E8 03 00 92 ...6............
1AB8:3460 F9 C3 3B C7 7D 03 8B C7 C3 3B C6 76 02 8B C6 C3 ..;.}....;.v....
1AB8:3470 80 3E 92 00 00 75 18 3B 06 8C 00 77 14 3B 1E 8E .>...u.;...w.;..
1AB8:3480 00 77 0E 3B 06 88 00 7C 08 3B 1E 8A 00 7C 02 F9 .w.;...|.;...|..
1AB8:3490 C3 F8 C3 00 00 00 00 00 00 00 00 08 00 00 00 00 ................
1AB8:34A0 32 ED E3 0E 53 06 88 0E 0C 14 E8 0E 01 07 5B E8 2...S.........[.
1AB8:34B0 3B 01 C3 80 3E 6F 00 00 75 06 E8 0D 00 E9 A3 EC ;...>o..u.......
1AB8:34C0 BE 24 00 FF 1E 70 00 E9 99 EC 22 E4 79 28 80 3E .$...p....".y(.>
1AB8:34D0 6F 00 00 75 18 50 53 51 52 BE 24 00 FF 1E 70 00 o..u.PSQR.$...p.
1AB8:34E0 E8 0A 00 5A 59 5B 58 80 E4 7F E9 DB 01 89 1E 04 ...ZY[X.........
1AB8:34F0 14 89 0E 06 14 C3 A3 00 14 89 1E 04 14 89 0E 06 ................
1AB8:3500 14 C7 06 08 14 08 00 C6 06 99 00 00 C7 06 0A 14 ................
1AB8:3510 00 00 C7 06 08 16 00 00 80 3E 7C 00 03 74 17 22 .........>|..t."
1AB8:3520 C0 74 19 E8 4F 02 83 3E 08 16 00 74 0F C6 06 99 .t..O..>...t....
1AB8:3530 00 FF 89 1E 08 14 C7 06 0A 14 FF FF 8B 1E 04 14 ................
1AB8:3540 8B 0E 06 14 80 3E 99 00 00 74 03 E8 54 00 A1 00 .....>...t..T...
1AB8:3550 14 8B 16 02 14 80 3E 99 00 00 74 05 E8 46 01 EB ......>...t..F..
1AB8:3560 19 0B DB 75 05 BB 08 00 8B CB 33 D2 80 3E 6F 00 ...u......3..>o.
1AB8:3570 00 75 07 BE 24 00 FF 1E 70 00 89 1E 04 14 89 0E .u..$...p.......
1AB8:3580 06 14 C3 00 00 03 05 02 03 03 04 01 01 04 03 05 ................
1AB8:3590 03 02 01 05 02 03 01 04 01 E8 06 00 A1 00 14 E9 ................
1AB8:35A0 03 01 8B 1E 08 14 83 FB 0A 72 03 BB 0A 00 D0 E3 .........r......
1AB8:35B0 8B 9F F0 14 8A CF 32 ED 32 FF C3 A1 80 03 8B 1E ......2.2.......
1AB8:35C0 82 03 53 8B D8 80 3E 0A 14 00 75 03 E8 4F 00 58 ..S...>...u..O.X
1AB8:35D0 53 8B D8 80 3E 0B 14 00 75 03 E8 68 00 58 A3 80 S...>...u..h.X..
1AB8:35E0 03 89 1E 82 03 BE 08 00 FF 1E 70 00 C3 80 3E 0A ..........p...>.
1AB8:35F0 14 00 75 08 A1 80 03 23 C0 79 01 C3 8A 0E 0C 14 ..u....#.y......
1AB8:3600 32 ED A1 02 14 80 3E 7C 00 00 75 0A 80 3E 99 00 2.....>|..u..>..
1AB8:3610 00 74 03 E9 46 03 BE 26 00 FF 1E 70 00 C3 A1 06 .t..F..&...p....
1AB8:3620 14 80 3E 01 14 01 74 10 80 3E 02 14 00 74 15 A0 ..>...t..>...t..
1AB8:3630 0C 14 32 E4 F7 26 04 14 80 3E 02 14 01 75 03 D1 ..2..&...>...u..
1AB8:3640 E8 48 2B D8 C3 A1 06 14 80 3E 01 14 01 75 09 A0 .H+......>...u..
1AB8:3650 0C 14 32 E4 F7 26 04 14 80 3E 03 14 02 74 0B 80 ..2..&...>...t..
1AB8:3660 3E 03 14 01 75 02 D1 E8 2B D8 C3 00 00 00 00 00 >...u...+.......
1AB8:3670 00 00 00 FF 00 01 00 01 00 01 00 01 00 01 00 01 ................
1AB8:3680 00 01 00 01 00 2B 00 00 00 00 00 00 00 00 00 00 .....+..........
1AB8:3690 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
1AB8:36A0 00 00 00 00 00 80 3E 7C 00 03 74 1B 88 26 E1 15 ......>|..t..&..
1AB8:36B0 3A 06 E0 15 74 27 A2 E0 15 53 51 E8 85 00 59 5B :...t'...SQ...Y[
1AB8:36C0 72 1B C6 06 E0 15 FF C3 A3 EA 15 89 1E EC 15 89 r...............
1AB8:36D0 0E EE 15 89 16 F0 15 33 DB 89 1E 08 14 23 DB 75 .......3.....#.u
1AB8:36E0 24 A1 EA 15 A3 E2 15 A1 EE 15 A3 E6 15 A1 EC 15 $...............
1AB8:36F0 23 C0 75 01 40 A3 E4 15 A1 F0 15 23 C0 75 01 40 #.u.@......#.u.@
1AB8:3700 A3 E8 15 EB 31 89 1E E2 15 89 1E E6 15 89 0E E4 ....1...........
1AB8:3710 15 89 0E E8 15 80 3E E1 15 00 75 1A 8B 1E 81 00 ......>...u.....
1AB8:3720 B9 10 27 3B D9 73 0F F7 E1 F7 F3 8B D8 23 DB 75 ..';.s.......#.u
1AB8:3730 01 43 89 1E E2 15 E8 4B 00 8B 1E 0A 16 8B 0E 0C .C.....K........
1AB8:3740 16 F9 C3 A1 08 16 23 C0 75 06 C6 06 E0 15 FF C3 ......#.u.......
1AB8:3750 C7 06 06 16 00 00 C5 36 06 16 B9 10 00 BF F2 15 .......6........
1AB8:3760 0E 07 F3 A4 0E 1F 80 3E F2 15 2B C6 06 F9 15 00 .......>..+.....
1AB8:3770 F9 74 01 F5 C3 8E C2 33 F6 26 80 3C 2B 75 04 89 .t.....3.&.<+u..
1AB8:3780 16 08 16 C3 A0 FA 15 2A 06 FC 15 32 E4 50 F7 26 .......*...2.P.&
1AB8:3790 E2 15 F7 36 E4 15 A3 0A 16 58 F7 26 E6 15 F7 36 ...6.....X.&...6
1AB8:37A0 E8 15 A3 0C 16 C3 E8 09 00 8B 1E 0E 16 8B 0E 0C ................
1AB8:37B0 16 C3 53 51 E8 CD FF A1 F3 15 D1 E0 05 10 00 C5 ..SQ............
1AB8:37C0 3E 06 16 03 F8 33 D2 E3 1E 26 8A 07 43 2E 2A 06 >....3...&..C.*.
1AB8:37D0 F6 15 2E 3A 06 F3 15 73 0C 32 E4 8B F7 03 F0 02 ...:...s.2......
1AB8:37E0 14 73 02 FE C6 E2 E2 0E 1F 8B C2 F7 26 E2 15 F7 .s..........&...
1AB8:37F0 36 E4 15 A3 0E 16 59 5B C3 C7 06 02 16 00 00 C7 6.....Y[........
1AB8:3800 06 04 16 00 00 2A 06 F6 15 3A 06 F3 15 72 01 C3 .....*...:...r..
1AB8:3810 32 E4 D1 E0 C4 3E 06 16 8B DF 83 C3 10 03 D8 26 2....>.........&
1AB8:3820 03 3F 03 3E F7 15 80 3E F9 15 00 74 05 EB 77 90 .?.>...>...t..w.
1AB8:3830 5F 07 E8 59 00 06 57 D0 E0 32 E4 8B F8 FF A5 AE _..Y..W..2......
1AB8:3840 17 B6 17 E5 17 DB 17 E7 17 A1 02 16 8B 1E 04 16 ................
1AB8:3850 8A 0E 92 00 80 E1 01 8A 2E E1 15 3A CD 75 08 22 ...........:.u."
1AB8:3860 C9 74 05 F7 D8 EB 01 93 E8 AB 01 5F 07 C3 E8 93 .t........._....
1AB8:3870 00 A3 02 16 89 1E 04 16 EB B6 E8 87 00 8B C8 8B ................
1AB8:3880 D3 87 0E 02 16 87 16 04 16 E8 95 01 EB A2 26 8B ..............&.
1AB8:3890 0D 86 E9 47 47 32 C0 F6 C5 80 74 02 04 02 F6 C1 ...GG2....t.....
1AB8:38A0 80 74 02 FE C0 C3 06 57 33 C0 E8 23 ED 5F 07 E8 .t.....W3..#._..
1AB8:38B0 DC FF 06 57 D0 E0 32 E4 8B F8 FF 95 2F 18 5F 07 ...W..2...../._.
1AB8:38C0 EB ED 37 18 45 18 50 18 50 18 FF 0E 31 05 B8 03 ..7.E.P.P...1...
1AB8:38D0 00 E8 FC EC 58 E9 71 FF B8 03 00 E8 F2 EC 33 C0 ....X.q.......3.
1AB8:38E0 E9 ED EC E8 1E 00 A3 02 16 89 1E 04 16 F7 DB 80 ................
1AB8:38F0 3E 92 00 00 74 03 F7 D8 93 03 06 80 03 03 1E 82 >...t...........
1AB8:3900 03 E9 87 EB 8A C5 E8 10 00 E8 22 00 50 8A C1 E8 ..........".P...
1AB8:3910 07 00 E8 30 00 8B D8 58 C3 33 D2 24 7F 8A D8 32 ...0...X.3.$...2
1AB8:3920 FF 24 40 74 06 FE CF 4A 80 CB 80 8B C3 C3 8B 1E .$@t...J........
1AB8:3930 E2 15 83 FB 01 74 02 F7 EB 8B 1E E4 15 83 FB 01 .....t..........
1AB8:3940 74 02 F7 FB C3 8B 1E E6 15 83 FB 01 74 02 F7 EB t...........t...
1AB8:3950 8B 1E E8 15 83 FB 01 74 02 F7 FB C3 80 3E E0 15 .......t.....>..
1AB8:3960 FF 74 45 E3 43 FF 36 9E 00 A3 10 16 06 53 E8 38 .tE.C.6......S.8
1AB8:3970 00 51 32 C0 B9 01 00 E8 1A EA 80 3E F9 15 00 74 .Q2........>...t
1AB8:3980 08 A1 9A 00 86 C4 E8 E0 E9 59 5B 07 26 8A 07 22 .........Y[.&.."
1AB8:3990 C0 74 0C 06 53 51 E8 60 FE 59 5B 07 43 E2 ED 58 .t..SQ.`.Y[.C..X
1AB8:39A0 50 E8 F0 E9 8F 06 9E 00 C3 51 E8 05 FE E8 05 00 P........Q......
1AB8:39B0 E8 35 00 59 C3 A1 0E 16 80 3E E1 15 00 74 07 A1 .5.Y.....>...t..
1AB8:39C0 0C 16 01 06 80 03 80 3E 10 16 00 74 1A 80 3E 10 .......>...t..>.
1AB8:39D0 16 01 75 03 D1 E8 48 80 3E 92 00 00 74 05 01 06 ..u...H.>...t...
1AB8:39E0 82 03 C3 29 06 80 03 C3 A1 0E 16 80 3E E1 15 00 ...)........>...
1AB8:39F0 75 03 A1 0C 16 80 3E 11 16 00 74 19 80 3E 11 16 u.....>...t..>..
1AB8:3A00 01 75 02 D1 E8 80 3E 92 00 00 74 05 01 06 80 03 .u....>...t.....
1AB8:3A10 C3 01 06 82 03 C3 F7 DB 01 1E 82 03 01 06 80 03 ................
1AB8:3A20 C3 50 A0 92 00 24 01 8A 26 E1 15 3A C4 75 0B 22 .P...$..&..:.u."
1AB8:3A30 C0 58 74 0E F7 D8 F7 D9 EB 0C 58 93 87 CA F7 D8 .Xt.......X.....
1AB8:3A40 F7 D9 F7 DB F7 DA 03 06 80 03 03 1E 82 03 03 0E ................
1AB8:3A50 80 03 03 16 82 03 E8 16 F8 73 07 BE 0C 00 FF 1E .........s......
1AB8:3A60 70 00 C3 00 00 00 00 00 00 00 00 00 00 00 00 00 p...............
