;;; Segment 0800 (0800:0000)

;; fn0800_0000: 0800:0000
;;   Called from:
;;     0800:1249 (in fn0800_11EF)
;;     0800:415B (in fn0800_3D9D)
;;     0800:417A (in fn0800_4168)
fn0800_0000 proc
	push	bp
	mov	bp,sp
	call	far 1AB8h:0EB5h
	call	far 1AB8h:0E88h
	push	word ptr [0B8ACh]
	call	far 1E78h:016Bh
	call	far 11C8h:03BBh
	xor	ax,ax
	call	far 1EDAh:00E9h
	leave
	ret

;; fn0800_0024: 0800:0024
;;   Called from:
;;     0800:0297 (in fn0800_01FE)
;;     0800:0DEC (in fn0800_0D20)
;;     0800:108B (in fn0800_0D20)
;;     0800:113E (in fn0800_0D20)
;;     0800:1FB0 (in fn0800_1E3F)
;;     0800:320F (in fn0800_31B7)
;;     0800:3BED (in fn0800_391E)
fn0800_0024 proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	push	1h
	call	far 1AB8h:0F93h
	call	far 1AB8h:1028h
	push	0h
	push	0h
	call	far 1AB8h:10CEh
	push	ax
	call	far 1AB8h:10E1h
	push	ax
	push	1h
	call	far 1AB8h:0F93h
	leave
	ret	8h

;; fn0800_005A: 0800:005A
;;   Called from:
;;     0800:04F3 (in fn0800_04E3)
;;     0800:0629 (in fn0800_0619)
;;     0800:0793 (in fn0800_0768)
;;     0800:0B01 (in fn0800_0AA1)
;;     0800:0BA2 (in fn0800_0B42)
;;     0800:25D1 (in fn0800_2401)
;;     0800:28F2 (in fn0800_2827)
;;     0800:2D4A (in fn0800_2C0C)
;;     0800:2F78 (in fn0800_2C0C)
;;     0800:33D6 (in fn0800_31B7)
;;     0800:3AC9 (in fn0800_391E)
fn0800_005A proc
	push	bp
	mov	bp,sp
	push	1h
	push	3h
	call	far 1AB8h:1175h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:1B3Eh
	leave
	ret	8h
0800:007B                                  50 53 51 52 56            PSQRV
0800:0080 57 1E 06 55 89 E5 B8 14 20 8E D8 83 06 E2 53 37 W..U.... .....S7
0800:0090 81 3E E2 53 E8 03 72 1F 31 C0 A3 E2 53 83 3E DA .>.S..r.1...S.>.
0800:00A0 58 00 7F 09 7C 11 83 3E D8 58 00 76 0A 83 2E D8 X...|..>.X.v....
0800:00B0 58 01 83 1E DA 58 00 C9 07 1F 5F 5E 5A 59 5B 58 X....X...._^ZY[X
0800:00C0 CF                                              .               

;; fn0800_00C1: 0800:00C1
;;   Called from:
;;     0800:2646 (in fn0800_2401)
;;     0800:2975 (in fn0800_2827)
;;     0800:2E42 (in fn0800_2C0C)
;;     0800:2FF4 (in fn0800_2C0C)
;;     0800:3457 (in fn0800_31B7)
;;     0800:3567 (in fn0800_31B7)
fn0800_00C1 proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [58BEh],0h
	jz	00CDh

l0800_00CB:
	jmp	00FFh

l0800_00CD:
	xor	ax,ax
	mov	[53E2h],ax
	mov	ax,[bp+4h]
	mov	dx,[bp+6h]
	mov	[58D8h],ax
	mov	[58DAh],dx
	push	1Ch
	mov	di,58C0h
	push	ds
	push	di
	call	far 1E5Fh:0159h
	push	1Ch
	mov	di,7Bh
	mov	ax,800h
	push	ax
	push	di
	call	far 1E5Fh:0171h
	mov	byte ptr [58BEh],1h

l0800_00FF:
	leave
	ret	4h

;; fn0800_0103: 0800:0103
;;   Called from:
;;     0800:268A (in fn0800_2401)
;;     0800:26AA (in fn0800_2401)
;;     0800:2753 (in fn0800_2401)
;;     0800:280B (in fn0800_2401)
;;     0800:2991 (in fn0800_2827)
;;     0800:2A3A (in fn0800_2827)
;;     0800:2AF2 (in fn0800_2827)
;;     0800:2FB0 (in fn0800_2C0C)
;;     0800:2FCB (in fn0800_2C0C)
;;     0800:309B (in fn0800_2C0C)
;;     0800:3523 (in fn0800_31B7)
;;     0800:353E (in fn0800_31B7)
;;     0800:36C9 (in fn0800_31B7)
fn0800_0103 proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [58BEh],0h
	jnz	010Fh

l0800_010D:
	jmp	0123h

l0800_010F:
	push	1Ch
	push	word ptr [58C2h]
	push	word ptr [58C0h]
	call	far 1E5Fh:0171h
	mov	byte ptr [58BEh],0h

l0800_0123:
	leave
	ret
0800:0125                07 52 41 44 2E 53 54 52 19 46 69      .RAD.STR.Fi
0800:0130 63 68 69 65 72 20 64 65 20 64 6F 6E 6E 82 65 73 chier de donn.es
0800:0140 20 61 62 73 65 6E 74                             absent         

;; fn0800_0147: 0800:0147
;;   Called from:
;;     0800:03FC (in fn0800_03F8)
fn0800_0147 proc
	enter	84h,0h
	push	0h
	push	0h
	push	15h
	push	15h
	call	far 1AB8h:13A3h
	mov	[bp+0FF7Ch],ax
	mov	di,125h
	push	cs
	push	di
	call	far 0C74h:0000h
	or	al,al
	jnz	0174h

l0800_016A:
	mov	di,12Dh
	push	cs
	push	di
	call	far 13E2h:0193h

l0800_0174:
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	di,125h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	push	word ptr [bp+0FF7Ch]
	call	far 1EDAh:0FD0h
	mov	byte ptr [bp-1h],0h
	jmp	019Ch

l0800_0199:
	inc	byte ptr [bp-1h]

l0800_019C:
	push	2h
	call	far 0C74h:00B2h
	push	word ptr [bp+0FF7Ch]
	call	far 1EDAh:023Fh
	mov	cx,ax
	mov	bx,dx
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	mov	[di+5992h],cx
	mov	[di+5994h],bx
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5992h]
	push	es
	push	di
	push	1h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	cmp	byte ptr [bp-1h],0C7h
	jnz	0199h

l0800_01E9:
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	call	far 1EDAh:1051h
	leave
	ret
0800:01F6                   07 52 41 44 2E 44 41 54             .RAD.DAT  

;; fn0800_01FE: 0800:01FE
;;   Called from:
;;     0800:2856 (in fn0800_2827)
;;     0800:2C2A (in fn0800_2C0C)
fn0800_01FE proc
	enter	84h,0h
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,1F6h
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
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,5ECEh
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	mov	al,[5CDEh]
	mov	[53D9h],al
	mov	al,[5CDFh]
	mov	[53DAh],al
	mov	al,[5CDAh]
	mov	[53DBh],al
	mov	al,[5CDBh]
	mov	[53DCh],al
	cmp	byte ptr [5CDCh],0Ah
	jbe	0281h

l0800_027C:
	mov	byte ptr [5CDCh],0Ah

l0800_0281:
	mov	al,[5CDCh]
	mov	[53DDh],al
	mov	al,[5CDDh]
	mov	[53DEh],al
	push	1h
	push	1h
	push	27Eh
	push	176h
	call	0024h
	mov	byte ptr [bp+0FF7Eh],0h
	jmp	02A5h

l0800_02A1:
	inc	byte ptr [bp+0FF7Eh]

l0800_02A5:
	mov	byte ptr [bp+0FF7Fh],0h
	jmp	02B0h

l0800_02AC:
	inc	byte ptr [bp+0FF7Fh]

l0800_02B0:
	mov	al,[bp+0FF7Fh]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp+0FF7Eh]
	xor	ah,ah
	imul	di,ax,1Dh
	add	di,dx
	cmp	byte ptr [di+5CE0h],0h
	jz	030Bh

l0800_02CA:
	mov	al,[bp+0FF7Fh]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp+0FF7Eh]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp+0FF7Fh]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp+0FF7Eh]
	xor	ah,ah
	imul	di,ax,1Dh
	add	di,dx
	mov	al,[di+5CE0h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5992h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h

l0800_030B:
	cmp	byte ptr [bp+0FF7Fh],1Ch
	jnz	02ACh

l0800_0312:
	cmp	byte ptr [bp+0FF7Eh],10h
	jnz	02A1h

l0800_0319:
	leave
	ret

;; fn0800_031B: 0800:031B
;;   Called from:
;;     0800:269D (in fn0800_2401)
;;     0800:2EA3 (in fn0800_2C0C)
;;     0800:34A7 (in fn0800_31B7)
fn0800_031B proc
	enter	8h,0h
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jnz	032Dh

l0800_032A:
	jmp	03D2h

l0800_032D:
	mov	ax,[5982h]
	sub	ax,17h
	cwd
	mov	cx,34h
	idiv	cx
	mov	[bp-4h],ax
	cmp	word ptr [5984h],198h
	jg	0347h

l0800_0344:
	jmp	03C7h

l0800_0347:
	cmp	word ptr [5984h],1C4h
	jge	03C7h

l0800_034F:
	cmp	byte ptr [58B0h],0h
	jz	035Eh

l0800_0356:
	push	190h
	call	far 11C8h:0354h

l0800_035E:
	mov	ax,[bp-4h]
	cmp	ax,0h
	jnz	036Ch

l0800_0366:
	mov	byte ptr [bp-7h],48h
	jmp	03C2h

l0800_036C:
	cmp	ax,1h
	jnz	0377h

l0800_0371:
	mov	byte ptr [bp-7h],4Bh
	jmp	03C2h

l0800_0377:
	cmp	ax,2h
	jnz	0382h

l0800_037C:
	mov	byte ptr [bp-7h],20h
	jmp	03C2h

l0800_0382:
	cmp	ax,3h
	jnz	038Dh

l0800_0387:
	mov	byte ptr [bp-7h],4Dh
	jmp	03C2h

l0800_038D:
	cmp	ax,4h
	jnz	0398h

l0800_0392:
	mov	byte ptr [bp-7h],50h
	jmp	03C2h

l0800_0398:
	cmp	ax,5h
	jnz	03A3h

l0800_039D:
	mov	byte ptr [bp-7h],3Bh
	jmp	03C2h

l0800_03A3:
	cmp	ax,6h
	jnz	03AEh

l0800_03A8:
	mov	byte ptr [bp-7h],3Ch
	jmp	03C2h

l0800_03AE:
	cmp	ax,7h
	jnz	03B9h

l0800_03B3:
	mov	byte ptr [bp-7h],3Dh
	jmp	03C2h

l0800_03B9:
	cmp	ax,8h
	jnz	03C2h

l0800_03BE:
	mov	byte ptr [bp-7h],1Bh

l0800_03C2:
	call	far 11C8h:033Bh

l0800_03C7:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jnz	03C7h

l0800_03D2:
	mov	al,[bp-7h]
	mov	[bp-1h],al
	mov	al,[bp-1h]
	leave
	ret
0800:03DD                                        07 52 41              .RA
0800:03E0 44 2E 42 55 54 12 46 69 63 68 69 65 72 20 6E 6F D.BUT.Fichier no
0800:03F0 6E 20 74 72 6F 75 76 82                         n trouv.        

;; fn0800_03F8: 0800:03F8
;;   Called from:
;;     0800:43FB (in fn0800_4255)
fn0800_03F8 proc
	enter	88h,0h
	call	0147h
	mov	di,3DDh
	push	cs
	push	di
	call	far 0C74h:0000h
	or	al,al
	jnz	0417h

l0800_040D:
	mov	di,3E5h
	push	cs
	push	di
	call	far 13E2h:0193h

l0800_0417:
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	di,3DDh
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	push	word ptr [0004h]
	call	far 1EDAh:0FD0h
	push	0h
	push	0h
	push	2Bh
	push	2Bh
	call	far 1AB8h:13A3h
	mov	[bp+0FF78h],ax
	push	word ptr [0004h]
	call	far 1EDAh:023Fh
	mov	[bp+0FF7Ah],ax
	mov	[bp+0FF7Ch],dx
	mov	byte ptr [bp-1h],0h
	jmp	0461h

l0800_045E:
	inc	byte ptr [bp-1h]

l0800_0461:
	push	5h
	call	far 0C74h:00B2h
	push	word ptr [bp+0FF78h]
	call	far 1EDAh:023Fh
	mov	cx,ax
	mov	bx,dx
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	mov	[di+5388h],cx
	mov	[di+538Ah],bx
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5388h]
	push	es
	push	di
	push	1h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	cmp	byte ptr [bp-1h],10h
	jnz	045Eh

l0800_04AE:
	push	word ptr [bp+0FF7Ch]
	push	word ptr [bp+0FF7Ah]
	push	word ptr [0004h]
	call	far 1EDAh:0254h
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	call	far 1EDAh:1051h
	leave
	ret

;; fn0800_04CC: 0800:04CC
;;   Called from:
;;     0800:09DF (in fn0800_09C2)
;;     0800:0A09 (in fn0800_09C2)
;;     0800:19C8 (in fn0800_184C)
;;     0800:2625 (in fn0800_2401)
;;     0800:262D (in fn0800_2401)
;;     0800:2954 (in fn0800_2827)
;;     0800:295C (in fn0800_2827)
;;     0800:2DF2 (in fn0800_2C0C)
;;     0800:2DFA (in fn0800_2C0C)
;;     0800:3398 (in fn0800_31B7)
;;     0800:341D (in fn0800_31B7)
;;     0800:3425 (in fn0800_31B7)
;;     0800:4405 (in fn0800_4255)
fn0800_04CC proc
	enter	2h,0h
	mov	al,[bp+4h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	leave
	ret	2h

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

;; fn0800_0619: 0800:0619
;;   Called from:
;;     0800:2616 (in fn0800_2401)
;;     0800:2937 (in fn0800_2827)
;;     0800:2DD5 (in fn0800_2C0C)
;;     0800:340A (in fn0800_31B7)
fn0800_0619 proc
	enter	104h,0h
	push	204h
	push	1A7h
	push	264h
	push	1CFh
	call	005Ah
	push	0h
	push	0h
	push	0h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,605h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	0672h

l0800_0651:
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	push	word ptr [5990h]
	push	word ptr [598Eh]
	call	far 0C74h:004Bh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	3h
	call	far 1EDAh:0A39h
	jmp	0683h

l0800_0672:
	mov	di,60Ah
	push	cs
	push	di
	lea	di,[bp-4h]
	push	ss
	push	di
	push	3h
	call	far 1EDAh:0A39h

l0800_0683:
	cmp	byte ptr [bp-4h],2h
	jnc	06AFh

l0800_0689:
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,60Eh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	3h
	call	far 1EDAh:0A39h

l0800_06AF:
	cmp	byte ptr [bp-4h],3h
	jnc	06DBh

l0800_06B5:
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,60Eh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	3h
	call	far 1EDAh:0A39h

l0800_06DB:
	push	8h
	call	far 1AB8h:1C32h
	push	233h
	push	1AEh
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,610h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1AB8h:1D82h
	push	233h
	push	1C6h
	mov	di,5ECEh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	push	0Bh
	call	far 1AB8h:1C32h
	push	234h
	push	1AFh
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,610h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1AB8h:1D82h
	push	234h
	push	1C7h
	mov	di,5ECEh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	leave
	ret
0800:0755                07 50 52 45 53 53 45 5A 0A 55 4E      .PRESSEZ.UN
0800:0760 45 20 54 4F 55 43 48 45                         E TOUCHE        

;; fn0800_0768: 0800:0768
;;   Called from:
;;     0800:30B8 (in fn0800_2C0C)
;;     0800:36CC (in fn0800_31B7)
fn0800_0768 proc
	enter	2h,0h
	push	0h
	push	0h
	push	0h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	8h
	call	far 1AB8h:1C32h
	push	204h
	push	1A7h
	push	264h
	push	1CFh
	call	005Ah
	push	233h
	push	1AEh
	mov	di,755h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	233h
	push	1C6h
	mov	di,75Dh
	push	cs
	push	di
	call	far 1AB8h:1D82h

l0800_07B6:
	push	0Bh
	call	far 1AB8h:1C32h
	push	234h
	push	1AFh
	mov	di,755h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	234h
	push	1C7h
	mov	di,75Dh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	mov	word ptr [bp-2h],1h
	jmp	07E7h

l0800_07E4:
	inc	word ptr [bp-2h]

l0800_07E7:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jnz	07FBh

l0800_07F2:
	call	far 1E78h:02FBh
	or	al,al
	jz	07FDh

l0800_07FB:
	jmp	0875h

l0800_07FD:
	cmp	word ptr [bp-2h],9C4h
	jnz	07E4h

l0800_0804:
	push	0Eh
	call	far 1AB8h:1C32h
	push	234h
	push	1AFh
	mov	di,755h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	234h
	push	1C7h
	mov	di,75Dh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	mov	word ptr [bp-2h],1h
	jmp	0835h

l0800_0832:
	inc	word ptr [bp-2h]

l0800_0835:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jnz	0849h

l0800_0840:
	call	far 1E78h:02FBh
	or	al,al
	jz	084Bh

l0800_0849:
	jmp	0875h

l0800_084B:
	cmp	word ptr [bp-2h],1388h
	jnz	0832h

l0800_0852:
	call	far 1E78h:02FBh
	or	al,al
	jnz	085Eh

l0800_085B:
	jmp	07B6h

l0800_085E:
	call	far 1E78h:02FBh
	or	al,al
	jz	086Eh

l0800_0867:
	call	far 1E78h:030Dh
	jmp	085Eh

l0800_086E:
	push	0h
	call	far 1AB8h:1C32h

l0800_0875:
	leave
	ret

;; fn0800_0877: 0800:0877
;;   Called from:
;;     0800:27FA (in fn0800_2401)
;;     0800:2AE1 (in fn0800_2827)
;;     0800:2AF5 (in fn0800_2827)
;;     0800:308A (in fn0800_2C0C)
;;     0800:30B1 (in fn0800_2C0C)
;;     0800:364D (in fn0800_31B7)
;;     0800:365E (in fn0800_31B7)
fn0800_0877 proc
	enter	2h,0h
	mov	byte ptr [bp-1h],0h
	mov	byte ptr [bp-2h],0h
	jmp	0888h

l0800_0885:
	inc	byte ptr [bp-2h]

l0800_0888:
	mov	al,[bp-2h]
	xor	ah,ah
	mov	di,ax
	cmp	byte ptr [di+5EB0h],5Eh
	jnz	08B1h

l0800_0896:
	mov	al,[bp-2h]
	xor	ah,ah
	imul	ax,ax,16h
	add	ax,0Bh
	push	ax
	push	176h
	call	far 1AB8h:1E3Ch
	cmp	ax,0Fh
	jz	08B1h

l0800_08AF:
	jmp	08BBh

l0800_08B1:
	cmp	byte ptr [bp-2h],1Ch
	jnz	0885h

l0800_08B7:
	mov	byte ptr [bp-1h],1h

l0800_08BB:
	mov	al,[bp-1h]
	leave
	ret

;; fn0800_08C0: 0800:08C0
;;   Called from:
;;     0800:279C (in fn0800_2401)
;;     0800:27D5 (in fn0800_2401)
;;     0800:2A83 (in fn0800_2827)
;;     0800:2ABC (in fn0800_2827)
;;     0800:303F (in fn0800_2C0C)
;;     0800:3065 (in fn0800_2C0C)
;;     0800:35B2 (in fn0800_31B7)
;;     0800:35D8 (in fn0800_31B7)
fn0800_08C0 proc
	enter	2h,0h
	mov	byte ptr [bp-1h],0h
	cmp	byte ptr [53DBh],0h
	ja	08D1h

l0800_08CF:
	jmp	08E4h

l0800_08D1:
	call	far 0C74h:522Ch
	or	al,al
	jnz	08DCh

l0800_08DA:
	jmp	08E4h

l0800_08DC:
	mov	byte ptr [bp-1h],1h
	dec	byte ptr [53DBh]

l0800_08E4:
	mov	al,[bp-1h]
	leave
	ret

;; fn0800_08E9: 0800:08E9
;;   Called from:
;;     0800:0D00 (in fn0800_0C71)
fn0800_08E9 proc
	enter	4h,0h
	mov	byte ptr [bp-2h],0h
	jmp	08F6h

l0800_08F3:
	inc	byte ptr [bp-2h]

l0800_08F6:
	mov	byte ptr [bp-1h],0h
	jmp	08FFh

l0800_08FC:
	inc	byte ptr [bp-1h]

l0800_08FF:
	call	far 1E78h:02FBh
	or	al,al
	jz	091Dh

l0800_0908:
	call	far 1E78h:030Dh
	mov	[bp-3h],al
	cmp	byte ptr [bp-3h],1Bh
	jnz	091Dh

l0800_0916:
	mov	byte ptr [58B3h],1h
	jmp	0980h

l0800_091D:
	mov	al,[bp-1h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	cmp	ax,0Fh
	jnz	096Ch

l0800_093B:
	mov	al,[bp-1h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp-1h]
	xor	ah,ah
	imul	ax,ax,16h
	add	ax,16h
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	imul	ax,ax,16h
	add	ax,16h
	push	ax
	call	far 0C74h:076Bh

l0800_096C:
	cmp	byte ptr [bp-1h],1Dh
	jnz	08FCh

l0800_0972:
	cmp	byte ptr [bp-2h],11h
	jz	097Bh

l0800_0978:
	jmp	08F3h

l0800_097B:
	call	far 0C74h:0A35h

l0800_0980:
	leave
	ret
0800:0982       EA 00 00 00 00 00 00 00 00 00 00 00 00 00   ..............
0800:0990 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:09A0 00 00 00 E2 01 00 00 00 00 00 00 00 00 00 00 00 ................
0800:09B0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:09C0 00 00                                           ..              

;; fn0800_09C2: 0800:09C2
;;   Called from:
;;     0800:18AB (in fn0800_184C)
;;     0800:26D3 (in fn0800_2401)
;;     0800:26EC (in fn0800_2401)
;;     0800:26F8 (in fn0800_2401)
;;     0800:2724 (in fn0800_2401)
;;     0800:2730 (in fn0800_2401)
;;     0800:2749 (in fn0800_2401)
;;     0800:2762 (in fn0800_2401)
;;     0800:276C (in fn0800_2401)
;;     0800:2778 (in fn0800_2401)
;;     0800:2799 (in fn0800_2401)
;;     0800:27A1 (in fn0800_2401)
;;     0800:27A6 (in fn0800_2401)
;;     0800:27B1 (in fn0800_2401)
;;     0800:27D2 (in fn0800_2401)
;;     0800:27DA (in fn0800_2401)
;;     0800:27DF (in fn0800_2401)
;;     0800:27EA (in fn0800_2401)
;;     0800:27F4 (in fn0800_2401)
;;     0800:29BA (in fn0800_2827)
;;     0800:29D3 (in fn0800_2827)
;;     0800:29DF (in fn0800_2827)
;;     0800:2A0B (in fn0800_2827)
;;     0800:2A17 (in fn0800_2827)
;;     0800:2A30 (in fn0800_2827)
;;     0800:2A49 (in fn0800_2827)
;;     0800:2A53 (in fn0800_2827)
;;     0800:2A5F (in fn0800_2827)
;;     0800:2A80 (in fn0800_2827)
;;     0800:2A88 (in fn0800_2827)
;;     0800:2A8D (in fn0800_2827)
;;     0800:2A98 (in fn0800_2827)
;;     0800:2AB9 (in fn0800_2827)
;;     0800:2AC1 (in fn0800_2827)
;;     0800:2AC6 (in fn0800_2827)
;;     0800:2AD1 (in fn0800_2827)
;;     0800:2ADB (in fn0800_2827)
;;     0800:2E1B (in fn0800_2C0C)
;;     0800:2E34 (in fn0800_2C0C)
;;     0800:2EDB (in fn0800_2C0C)
;;     0800:2EF4 (in fn0800_2C0C)
;;     0800:2F00 (in fn0800_2C0C)
;;     0800:2F19 (in fn0800_2C0C)
;;     0800:2F25 (in fn0800_2C0C)
;;     0800:2F3E (in fn0800_2C0C)
;;     0800:2FD0 (in fn0800_2C0C)
;;     0800:2FE9 (in fn0800_2C0C)
;;     0800:3019 (in fn0800_2C0C)
;;     0800:3023 (in fn0800_2C0C)
;;     0800:302E (in fn0800_2C0C)
;;     0800:303C (in fn0800_2C0C)
;;     0800:3044 (in fn0800_2C0C)
;;     0800:3049 (in fn0800_2C0C)
;;     0800:3054 (in fn0800_2C0C)
;;     0800:3062 (in fn0800_2C0C)
;;     0800:306A (in fn0800_2C0C)
;;     0800:306F (in fn0800_2C0C)
;;     0800:307A (in fn0800_2C0C)
;;     0800:3084 (in fn0800_2C0C)
;;     0800:327F (in fn0800_31B7)
;;     0800:3430 (in fn0800_31B7)
;;     0800:3449 (in fn0800_31B7)
;;     0800:34B6 (in fn0800_31B7)
;;     0800:34CF (in fn0800_31B7)
;;     0800:34DB (in fn0800_31B7)
;;     0800:34F4 (in fn0800_31B7)
;;     0800:3500 (in fn0800_31B7)
;;     0800:3519 (in fn0800_31B7)
;;     0800:3543 (in fn0800_31B7)
;;     0800:355C (in fn0800_31B7)
;;     0800:358C (in fn0800_31B7)
;;     0800:3596 (in fn0800_31B7)
;;     0800:35A1 (in fn0800_31B7)
;;     0800:35AF (in fn0800_31B7)
;;     0800:35B7 (in fn0800_31B7)
;;     0800:35BC (in fn0800_31B7)
;;     0800:35C7 (in fn0800_31B7)
;;     0800:35D5 (in fn0800_31B7)
;;     0800:35DD (in fn0800_31B7)
;;     0800:35E2 (in fn0800_31B7)
;;     0800:35ED (in fn0800_31B7)
;;     0800:35F7 (in fn0800_31B7)
fn0800_09C2 proc
	enter	2h,0h
	mov	al,[bp+4h]
	mov	[58E4h],al
	mov	al,[bp+4h]
	cmp	al,0h
	jc	09F6h

l0800_09D3:
	cmp	al,8h
	ja	09F6h

l0800_09D7:
	mov	al,[bp+4h]
	xor	ah,ah
	shl	ax,1h
	push	ax
	call	04CCh
	add	ax,16h
	mov	dx,ax
	mov	al,[bp+4h]
	xor	ah,ah
	shl	ax,3h
	add	ax,dx
	mov	[bp-2h],ax
	jmp	0A21h

l0800_09F6:
	cmp	al,9h
	jc	0A21h

l0800_09FA:
	cmp	al,10h
	ja	0A21h

l0800_09FE:
	mov	al,[bp+4h]
	xor	ah,ah
	sub	ax,9h
	shl	ax,1h
	push	ax
	call	04CCh
	add	ax,16h
	mov	dx,ax
	mov	al,[bp+4h]
	xor	ah,ah
	sub	ax,9h
	shl	ax,3h
	add	ax,dx
	mov	[bp-2h],ax

l0800_0A21:
	push	0Bh
	call	far 1AB8h:1C32h
	call	far 1206h:0066h
	push	word ptr [bp-2h]
	push	198h
	mov	al,[bp+4h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5388h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-2h]
	dec	ax
	push	ax
	push	197h
	mov	ax,[bp-2h]
	add	ax,2Ch
	push	ax
	push	1C4h
	call	far 1AB8h:112Eh
	mov	al,[bp+4h]
	push	ax
	mov	di,982h
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	0A86h

l0800_0A83:
	call	04E3h

l0800_0A86:
	mov	al,[bp+4h]
	push	ax
	mov	di,9A2h
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	0A9Bh

l0800_0A96:
	call	far 1206h:0038h

l0800_0A9B:
	leave
	ret	2h
0800:0A9F                                              01                .
0800:0AA0 30                                              0               

;; fn0800_0AA1: 0800:0AA1
;;   Called from:
;;     0800:0C6C (in fn0800_0BEC)
;;     0800:0CBB (in fn0800_0C71)
fn0800_0AA1 proc
	enter	104h,0h
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	push	word ptr [58DEh]
	push	word ptr [58DCh]
	call	far 0C74h:004Bh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp-4h],2h
	jnc	0AF0h

l0800_0ACA:
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,0A9Fh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h

l0800_0AF0:
	call	far 1206h:0066h
	push	24Bh
	push	192h
	push	25Ch
	push	19Bh
	call	005Ah
	push	8h
	call	far 1AB8h:1C32h
	push	253h
	push	196h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	254h
	push	197h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	call	far 1206h:0038h
	push	0h
	call	far 1AB8h:1C32h
	leave
	ret
0800:0B40 01 30                                           .0              

;; fn0800_0B42: 0800:0B42
;;   Called from:
;;     0800:0C69 (in fn0800_0BEC)
;;     0800:0CDF (in fn0800_0C71)
fn0800_0B42 proc
	enter	104h,0h
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	push	word ptr [58CEh]
	push	word ptr [58CCh]
	call	far 0C74h:004Bh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp-4h],2h
	jnc	0B91h

l0800_0B6B:
	lea	di,[bp+0FEFCh]
	push	ss
	push	di
	mov	di,0B40h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h

l0800_0B91:
	call	far 1206h:0066h
	push	233h
	push	192h
	push	244h
	push	19Bh
	call	005Ah
	push	8h
	call	far 1AB8h:1C32h
	push	23Bh
	push	196h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	23Ch
	push	197h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	0h
	call	far 1AB8h:1C32h
	call	far 1206h:0038h
	leave
	ret
0800:0BE1    0A 54 49 4D 45 3A 30 30 2E 30 30              .TIME:00.00    

;; fn0800_0BEC: 0800:0BEC
;;   Called from:
;;     0800:2619 (in fn0800_2401)
;;     0800:293A (in fn0800_2827)
;;     0800:2DD8 (in fn0800_2C0C)
;;     0800:340D (in fn0800_31B7)
fn0800_0BEC proc
	push	bp
	mov	bp,sp
	mov	al,[53DDh]
	xor	ah,ah
	xor	dx,dx
	mov	[58CCh],ax
	mov	[58CEh],dx
	xor	ax,ax
	mov	[58DCh],ax
	mov	[58DEh],ax
	mov	ax,[58CCh]
	mov	dx,[58CEh]
	mov	[58C4h],ax
	mov	[58C6h],dx
	mov	ax,[58DCh]
	mov	dx,[58DEh]
	mov	[58C8h],ax
	mov	[58CAh],dx
	mov	byte ptr [53E0h],0h
	mov	byte ptr [53E1h],0h
	mov	al,[53DDh]
	xor	ah,ah
	imul	ax,ax,5Fh
	cwd
	mov	[58D4h],ax
	mov	[58D6h],dx
	push	8h
	call	far 1AB8h:1C32h
	push	233h
	push	196h
	mov	di,0BE1h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	234h
	push	197h
	mov	di,0BE1h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	call	0B42h
	call	0AA1h
	leave
	ret

;; fn0800_0C71: 0800:0C71
;;   Called from:
;;     0800:27F7 (in fn0800_2401)
;;     0800:2ADE (in fn0800_2827)
;;     0800:3087 (in fn0800_2C0C)
;;     0800:364A (in fn0800_31B7)
fn0800_0C71 proc
	push	bp
	mov	bp,sp
	mov	ax,[58D8h]
	mov	dx,[58DAh]
	mov	cx,3Ch
	xor	bx,bx
	call	far 1EDAh:098Ah
	mov	[58CCh],ax
	mov	[58CEh],dx
	mov	ax,[58D8h]
	mov	dx,[58DAh]
	mov	cx,3Ch
	xor	bx,bx
	call	far 1EDAh:098Ah
	mov	ax,cx
	mov	dx,bx
	mov	[58DCh],ax
	mov	[58DEh],dx
	mov	ax,[58DCh]
	mov	dx,[58DEh]
	cmp	dx,[58CAh]
	jnz	0CBBh

l0800_0CB5:
	cmp	ax,[58C8h]
	jz	0CCCh

l0800_0CBB:
	call	0AA1h
	mov	ax,[58DCh]
	mov	dx,[58DEh]
	mov	[58C8h],ax
	mov	[58CAh],dx

l0800_0CCC:
	mov	ax,[58CCh]
	mov	dx,[58CEh]
	cmp	dx,[58C6h]
	jnz	0CDFh

l0800_0CD9:
	cmp	ax,[58C4h]
	jz	0CF0h

l0800_0CDF:
	call	0B42h
	mov	ax,[58CCh]
	mov	dx,[58CEh]
	mov	[58C4h],ax
	mov	[58C6h],dx

l0800_0CF0:
	cmp	word ptr [58DAh],0h
	jl	0D00h

l0800_0CF7:
	jg	0D05h

l0800_0CF9:
	cmp	word ptr [58D8h],0h
	ja	0D05h

l0800_0D00:
	call	08E9h
	jmp	0D05h

l0800_0D05:
	leave
	ret
0800:0D07                      07 52 41 44 2E 4D 45 4D 02        .RAD.MEM.
0800:0D10 41 41 04 41 41 41 41 01 41 06 41 41 41 41 41 41 AA.AAAA.A.AAAAAA

;; fn0800_0D20: 0800:0D20
;;   Called from:
;;     0800:1227 (in fn0800_11EF)
fn0800_0D20 proc
	enter	518h,0h
	les	di,[bp+4h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	mov	byte ptr [bp+0FDFAh],0h
	mov	byte ptr [bp+0FCE8h],0h
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	mov	di,0D07h
	push	cs
	push	di
	call	far 1EDAh:04F5h
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	call	far 1EDAh:0565h
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	lea	di,[bp+0FCE8h]
	push	ss
	push	di
	push	6h
	call	far 1EDAh:0896h
	call	far 1EDAh:086Ch
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	call	far 1EDAh:05BFh
	call	far 1EDAh:04A2h
	or	ax,ax
	jnz	0D9Ch

l0800_0D88:
	lea	di,[bp+0FCE8h]
	push	ss
	push	di
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l0800_0D9C:
	push	0Bh
	call	far 1AB8h:1C32h
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	call	far 1AB8h:13A3h
	mov	[bp+0FEFAh],ax
	push	word ptr [bp+0FEFAh]
	call	far 1EDAh:023Fh
	mov	[bp+0FEFCh],ax
	mov	[bp+0FEFEh],dx
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	les	di,[bp+0FEFCh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	call	0024h
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	call	far 1AB8h:112Eh
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	mov	ax,[bp+8h]
	sub	ax,[bp+0Ch]
	shr	ax,1h
	add	ax,[bp+0Ch]
	mov	[bp+0FDF4h],ax
	mov	di,0D0Fh
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	add	ax,[bp+0Eh]
	push	ax
	push	word ptr [bp+0FDF4h]
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	lea	di,[bp+0FBE8h]
	push	ss
	push	di
	mov	di,0D12h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1AB8h:1E0Bh
	add	ax,[bp+0Eh]
	push	ax
	push	word ptr [bp+0FDF4h]
	call	far 1AB8h:108Bh
	call	far 1AB8h:10A8h
	mov	[bp+0FDF6h],ax
	push	0Ah
	call	far 1AB8h:1C32h
	push	word ptr [bp+0FDF6h]
	push	word ptr [bp+0FDF4h]
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	lea	di,[bp+0FBE8h]
	push	ss
	push	di
	mov	di,0D12h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1AB8h:1E0Bh
	add	ax,[bp+0Eh]
	push	ax
	push	word ptr [bp+0FDF4h]
	call	far 1AB8h:108Bh
	mov	byte ptr [bp+0FDF9h],25h
	xor	ax,ax
	mov	[bp+0FDF0h],ax

l0800_0ED3:
	inc	word ptr [bp+0FDF0h]
	cmp	word ptr [bp+0FDF0h],1388h
	jnz	0F07h

l0800_0EDF:
	push	0Bh
	call	far 1AB8h:1C32h
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	add	ax,6h
	push	ax
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	sub	ax,6h
	push	ax
	call	far 1AB8h:1AF6h

l0800_0F07:
	cmp	word ptr [bp+0FDF0h],2710h
	jnz	0F3Dh

l0800_0F0F:
	xor	ax,ax
	mov	[bp+0FDF0h],ax
	push	0h
	call	far 1AB8h:1C32h
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	add	ax,6h
	push	ax
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	sub	ax,6h
	push	ax
	call	far 1AB8h:1AF6h

l0800_0F3D:
	call	far 1E78h:02FBh
	or	al,al
	jnz	0F49h

l0800_0F46:
	jmp	1171h

l0800_0F49:
	push	0h
	call	far 1AB8h:1C32h
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	add	ax,6h
	push	ax
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	sub	ax,6h
	push	ax
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	call	far 1E78h:030Dh
	push	ax
	call	far 1EDAh:1384h
	mov	[bp+0FDF9h],al
	cmp	byte ptr [bp+0FDF9h],0h
	jnz	0FB6h

l0800_0F8E:
	call	far 1E78h:030Dh
	mov	[bp+0FDF9h],al
	mov	al,[bp+0FDF9h]
	cmp	al,4Bh
	jnz	0FA6h

l0800_0F9F:
	mov	byte ptr [bp+0FDF9h],8h
	jmp	0FB6h

l0800_0FA6:
	cmp	al,53h
	jnz	0FB1h

l0800_0FAA:
	mov	byte ptr [bp+0FDF9h],14h
	jmp	0FB6h

l0800_0FB1:
	mov	byte ptr [bp+0FDF9h],0h

l0800_0FB6:
	mov	al,[bp+0FDF9h]
	cmp	al,15h
	jc	1035h

l0800_0FBE:
	cmp	al,0FFh
	ja	1035h

l0800_0FC2:
	mov	di,0D0Fh
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	mov	dx,ax
	mov	ax,[bp+0Ah]
	sub	ax,dx
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10A8h
	cwd
	pop	cx
	pop	bx
	cmp	dx,bx
	jl	0FE9h

l0800_0FE3:
	jg	1032h

l0800_0FE5:
	cmp	ax,cx
	jnc	1032h

l0800_0FE9:
	lea	di,[bp+0FBE8h]
	push	ss
	push	di
	mov	al,[bp+0FDF9h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1AB8h:1492h
	lea	di,[bp+0FAE8h]
	push	ss
	push	di
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FBE8h]
	push	ss
	push	di
	mov	al,[bp+0FDF9h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1EDAh:0AACh
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l0800_1032:
	jmp	1171h

l0800_1035:
	cmp	al,14h
	jnz	109Eh

l0800_1039:
	mov	byte ptr [bp+0FDFAh],0h
	push	word ptr [bp+0FDF6h]
	mov	di,0D17h
	push	cs
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10BBh
	cwd
	pop	cx
	pop	bx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	di,0D19h
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	add	ax,[bp+0FDF6h]
	push	ax
	mov	di,0D17h
	push	cs
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10BBh
	cwd
	pop	cx
	pop	bx
	add	ax,cx
	adc	dx,bx
	push	ax
	call	0024h
	push	word ptr [bp+0FDF6h]
	push	word ptr [bp+0FDF4h]
	call	far 1AB8h:108Bh
	jmp	1171h

l0800_109E:
	cmp	al,8h
	jz	10A5h

l0800_10A2:
	jmp	1171h

l0800_10A5:
	call	far 1AB8h:10A8h
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0FDF6h]
	xor	dx,dx
	cmp	dx,bx
	jl	10C5h

l0800_10B9:
	jle	10BEh

l0800_10BB:
	jmp	1171h

l0800_10BE:
	cmp	ax,cx
	jc	10C5h

l0800_10C2:
	jmp	1171h

l0800_10C5:
	call	far 1AB8h:10A8h
	mov	[bp+0FDF2h],ax
	mov	di,0D17h
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10A8h
	cwd
	pop	cx
	pop	bx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	di,0D17h
	push	cs
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10BBh
	cwd
	pop	cx
	pop	bx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	di,0D17h
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10A8h
	cwd
	pop	cx
	pop	bx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	di,0D17h
	push	cs
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10BBh
	cwd
	pop	cx
	pop	bx
	add	ax,cx
	adc	dx,bx
	push	ax
	call	0024h
	mov	di,0D17h
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	mov	dx,ax
	mov	ax,[bp+0FDF2h]
	sub	ax,dx
	push	ax
	push	word ptr [bp+0FDF4h]
	call	far 1AB8h:108Bh
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	mov	al,[bp+0FDFAh]
	xor	ah,ah
	push	ax
	push	1h
	call	far 1EDAh:0BD0h

l0800_1171:
	cmp	byte ptr [bp+0FDF9h],0Dh
	jz	1182h

l0800_1178:
	cmp	byte ptr [bp+0FDF9h],1Bh
	jz	1182h

l0800_117F:
	jmp	0ED3h

l0800_1182:
	cmp	byte ptr [bp+0FDF9h],1Bh
	jnz	119Dh

l0800_1189:
	lea	di,[bp+0FCE8h]
	push	ss
	push	di
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l0800_119D:
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	les	di,[bp+0FEFCh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [bp+0FEFEh]
	push	word ptr [bp+0FEFCh]
	push	word ptr [bp+0FEFAh]
	call	far 1EDAh:0254h
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	les	di,[bp+10h]
	push	es
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	ret	0Ch
0800:11D8                         0E 43 6F 64 65 20 4D 69         .Code Mi
0800:11E0 73 73 69 6F 6E 20 3A 07 52 41 44 2E 44 41 54    ssion :.RAD.DAT 

;; fn0800_11EF: 0800:11EF
;;   Called from:
;;     0800:3F4A (in fn0800_3D9D)
fn0800_11EF proc
	enter	18Ch,0h
	call	far 1206h:0066h
	lea	di,[bp+0FE74h]
	push	ss
	push	di
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,68h
	push	ax
	push	8Eh
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,68h
	push	ax
	push	0A0h
	mov	di,11D8h
	push	cs
	push	di
	call	0D20h
	lea	di,[bp-8h]
	push	ss
	push	di
	push	6h
	call	far 1EDAh:0A39h
	call	far 1206h:0038h
	mov	di,11E7h
	push	cs
	push	di
	call	far 0C74h:0000h
	or	al,al
	jnz	124Ch

l0800_1249:
	call	0000h

l0800_124C:
	lea	di,[bp+0FF78h]
	push	ss
	push	di
	mov	di,11E7h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FF78h]
	push	ss
	push	di
	push	219h
	call	far 1EDAh:0FD0h
	call	far 1EDAh:04A9h
	mov	word ptr [598Eh],0FFFFh
	mov	word ptr [5990h],0FFFFh

l0800_127B:
	add	word ptr [598Eh],1h
	adc	word ptr [5990h],0h
	lea	di,[bp+0FF78h]
	push	ss
	push	di
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:1085h
	add	sp,4h
	call	far 1EDAh:04A9h
	mov	di,5CB4h
	push	ds
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	call	far 1EDAh:0B24h
	jz	12D5h

l0800_12AE:
	lea	di,[bp+0FF78h]
	push	ss
	push	di
	call	far 1EDAh:1185h
	call	far 1EDAh:04A9h
	or	al,al
	jnz	12D5h

l0800_12C2:
	mov	al,[0002h]
	xor	ah,ah
	dec	ax
	cwd
	cmp	dx,[5990h]
	jnz	127Bh

l0800_12CF:
	cmp	ax,[598Eh]
	jnz	127Bh

l0800_12D5:
	lea	di,[bp+0FF78h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	call	far 1EDAh:04A9h
	lea	di,[bp-8h]
	push	ss
	push	di
	mov	di,5ED6h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	mov	di,5CB4h
	push	ds
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	call	far 1EDAh:0B24h
	jz	1313h

l0800_1307:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h

l0800_1313:
	leave
	ret

;; fn0800_1315: 0800:1315
;;   Called from:
;;     0800:14D4 (in fn0800_149F)
;;     0800:16B7 (in fn0800_166D)
;;     0800:188A (in fn0800_184C)
;;     0800:1E7E (in fn0800_1E3F)
;;     0800:202D (in fn0800_2004)
;;     0800:220A (in fn0800_21E7)
;;     0800:24A9 (in fn0800_2401)
;;     0800:321D (in fn0800_31B7)
;;     0800:3984 (in fn0800_391E)
fn0800_1315 proc
	push	bp
	mov	bp,sp
	push	1h
	push	3h
	call	far 1AB8h:1175h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:1B3Eh
	push	0Bh
	call	far 1AB8h:1C32h
	mov	ax,[bp+0Ah]
	sub	ax,3h
	push	ax
	push	word ptr [bp+8h]
	mov	ax,[bp+6h]
	add	ax,3h
	push	ax
	push	word ptr [bp+8h]
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp+6h]
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	sub	ax,3h
	push	ax
	push	word ptr [bp+8h]
	mov	ax,[bp+0Ah]
	sub	ax,3h
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	push	word ptr [bp+4h]
	call	far 1AB8h:1AF6h
	push	8h
	call	far 1AB8h:1C32h
	mov	ax,[bp+6h]
	add	ax,3h
	push	ax
	push	word ptr [bp+8h]
	mov	ax,[bp+6h]
	add	ax,3h
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+6h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp+4h]
	call	far 1AB8h:1AF6h
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+4h]
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+4h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:1AF6h
	leave
	ret	8h
0800:147F                                              00                .
0800:1480 00 00 00 00 00 00 00 FE FF FF 07 00 00 00 00 00 ................
0800:1490 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    ............... 

;; fn0800_149F: 0800:149F
;;   Called from:
;;     0800:4008 (in fn0800_3D9D)
fn0800_149F proc
	enter	10Eh,0h
	call	far 1AB8h:0F80h
	mov	word ptr [bp-2h],2Ah
	mov	word ptr [bp-6h],6Ah
	call	far 1AB8h:10CEh
	sub	ax,2Ah
	mov	[bp-4h],ax
	call	far 1AB8h:10E1h
	sub	ax,6Ah
	mov	[bp-8h],ax
	push	word ptr [bp-2h]
	push	word ptr [bp-6h]
	push	word ptr [bp-4h]
	push	word ptr [bp-8h]
	call	1315h
	mov	ax,[bp-2h]
	add	ax,8h
	mov	[bp-2h],ax
	mov	ax,[bp-6h]
	add	ax,8h
	mov	[bp-6h],ax
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	mov	byte ptr [bp-0Bh],1h
	jmp	1506h

l0800_1503:
	inc	byte ptr [bp-0Bh]

l0800_1506:
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	mov	al,[di+0FF06h]
	mov	[bp-0Dh],al
	mov	al,1h
	cmp	al,[bp-0Dh]
	jbe	1521h

l0800_151E:
	jmp	15F8h

l0800_1521:
	mov	[bp-0Ch],al
	jmp	1529h

l0800_1526:
	inc	byte ptr [bp-0Ch]

l0800_1529:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-0Ch]
	xor	ah,ah
	shl	ax,3h
	add	ax,[bp-2h]
	dec	ax
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	dec	ax
	push	ax
	lea	di,[bp+0FEF2h]
	push	ss
	push	di
	mov	al,[bp-0Ch]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,dx
	mov	al,[di+0FF06h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1AB8h:1D82h
	mov	al,[bp-0Ch]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,dx
	mov	al,[di+0FF06h]
	push	ax
	mov	di,147Fh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	159Fh

l0800_1596:
	push	0Ah
	call	far 1AB8h:1C32h
	jmp	15A6h

l0800_159F:
	push	0Bh
	call	far 1AB8h:1C32h

l0800_15A6:
	mov	al,[bp-0Ch]
	xor	ah,ah
	shl	ax,3h
	add	ax,[bp-2h]
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	push	ax
	lea	di,[bp+0FEF2h]
	push	ss
	push	di
	mov	al,[bp-0Ch]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,dx
	mov	al,[di+0FF06h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1AB8h:1D82h
	push	1Eh
	call	far 1E78h:029Ch
	mov	al,[bp-0Ch]
	cmp	al,[bp-0Dh]
	jz	15F8h

l0800_15F5:
	jmp	1526h

l0800_15F8:
	push	1F4h
	call	far 1E78h:029Ch
	cmp	byte ptr [bp-0Bh],12h
	jz	1609h

l0800_1606:
	jmp	1503h

l0800_1609:
	call	far 1E78h:030Dh
	mov	word ptr [bp-0Ah],1h
	jmp	1618h

l0800_1615:
	inc	word ptr [bp-0Ah]

l0800_1618:
	mov	ax,[bp-4h]
	sub	ax,[bp-2h]
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp-2h]
	push	ax
	mov	ax,[bp-8h]
	sub	ax,[bp-6h]
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp-6h]
	push	ax
	push	0h
	call	far 1AB8h:1E54h
	cmp	word ptr [bp-0Ah],7D00h
	jnz	1615h

l0800_1646:
	call	far 1AB8h:0F80h
	leave
	ret
0800:164D                                        00 00 00              ...
0800:1650 00 00 00 FF 03 FE FF FF 07 00 00 00 00 00 00 00 ................
0800:1660 00 00 00 00 00 00 00 00 00 00 00 00 00          .............   

;; fn0800_166D: 0800:166D
;;   Called from:
;;     0800:2B19 (in fn0800_2827)
;;     0800:30E8 (in fn0800_2C0C)
fn0800_166D proc
	enter	10Eh,0h
	call	far 1AB8h:0F80h
	call	far 13E2h:0080h

l0800_167B:
	call	far 1E78h:02FBh
	or	al,al
	jz	168Bh

l0800_1684:
	call	far 1E78h:030Dh
	jmp	167Bh

l0800_168B:
	mov	word ptr [bp-2h],2Ah
	mov	word ptr [bp-6h],6Ah
	call	far 1AB8h:10CEh
	sub	ax,2Ah
	mov	[bp-4h],ax
	call	far 1AB8h:10E1h
	sub	ax,6Ah
	mov	[bp-8h],ax
	push	word ptr [bp-2h]
	push	word ptr [bp-6h]
	push	word ptr [bp-4h]
	push	word ptr [bp-8h]
	call	1315h
	mov	ax,[bp-2h]
	add	ax,8h
	mov	[bp-2h],ax
	mov	ax,[bp-6h]
	add	ax,8h
	mov	[bp-6h],ax
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	mov	byte ptr [bp-0Bh],1h
	jmp	16E9h

l0800_16E6:
	inc	byte ptr [bp-0Bh]

l0800_16E9:
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	mov	al,[di+1106h]
	mov	[bp-0Dh],al
	mov	al,1h
	cmp	al,[bp-0Dh]
	jbe	1704h

l0800_1701:
	jmp	17DBh

l0800_1704:
	mov	[bp-0Ch],al
	jmp	170Ch

l0800_1709:
	inc	byte ptr [bp-0Ch]

l0800_170C:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-0Ch]
	xor	ah,ah
	shl	ax,3h
	add	ax,[bp-2h]
	dec	ax
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	dec	ax
	push	ax
	lea	di,[bp+0FEF2h]
	push	ss
	push	di
	mov	al,[bp-0Ch]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,dx
	mov	al,[di+1106h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1AB8h:1D82h
	mov	al,[bp-0Ch]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,dx
	mov	al,[di+1106h]
	push	ax
	mov	di,164Dh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	1782h

l0800_1779:
	push	0Ah
	call	far 1AB8h:1C32h
	jmp	1789h

l0800_1782:
	push	0Bh
	call	far 1AB8h:1C32h

l0800_1789:
	mov	al,[bp-0Ch]
	xor	ah,ah
	shl	ax,3h
	add	ax,[bp-2h]
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	push	ax
	lea	di,[bp+0FEF2h]
	push	ss
	push	di
	mov	al,[bp-0Ch]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,dx
	mov	al,[di+1106h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1AB8h:1D82h
	push	1Eh
	call	far 1E78h:029Ch
	mov	al,[bp-0Ch]
	cmp	al,[bp-0Dh]
	jz	17DBh

l0800_17D8:
	jmp	1709h

l0800_17DB:
	push	1F4h
	call	far 1E78h:029Ch
	cmp	byte ptr [bp-0Bh],12h
	jz	17ECh

l0800_17E9:
	jmp	16E6h

l0800_17EC:
	call	far 1E78h:030Dh
	mov	word ptr [bp-0Ah],1h
	jmp	17FBh

l0800_17F8:
	inc	word ptr [bp-0Ah]

l0800_17FB:
	mov	ax,[bp-4h]
	sub	ax,[bp-2h]
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp-2h]
	push	ax
	mov	ax,[bp-8h]
	sub	ax,[bp-6h]
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp-6h]
	push	ax
	push	0h
	call	far 1AB8h:1E54h
	cmp	word ptr [bp-0Ah],7D00h
	jnz	17F8h

l0800_1829:
	call	far 1AB8h:0F80h
	leave
	ret
0800:1830 07 46 4C 45 43 48 45 53 06 45 53 50 41 43 45 02 .FLECHES.ESPACE.
0800:1840 46 31 02 46 32 02 46 33 03 45 53 43             F1.F2.F3.ESC    

;; fn0800_184C: 0800:184C
;;   Called from:
;;     0800:3EEB (in fn0800_3D9D)
;;     0800:3F23 (in fn0800_3D9D)
;;     0800:400B (in fn0800_3D9D)
fn0800_184C proc
	push	bp
	mov	bp,sp
	call	far 1206h:0066h
	call	far 1AB8h:0F80h
	call	far 13E2h:003Bh
	push	8h
	call	far 1AB8h:1C32h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	push	0h
	push	27Fh
	push	177h
	call	far 1AB8h:112Eh
	push	3h
	push	17Bh
	push	27Ch
	push	1DAh
	call	1315h
	mov	byte ptr [53DEh],0h
	mov	byte ptr [53DCh],0h
	mov	byte ptr [53DBh],0h
	xor	ax,ax
	mov	[53D4h],ax
	jmp	18A7h

l0800_18A3:
	inc	word ptr [53D4h]

l0800_18A7:
	mov	al,[53D4h]
	push	ax
	call	09C2h
	call	far 1206h:0066h
	cmp	word ptr [53D4h],8h
	jnz	18A3h

l0800_18BA:
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	8h
	call	far 1AB8h:1C32h
	push	43h
	push	1CEh
	mov	di,1830h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	93h
	push	1CEh
	mov	di,1838h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0E3h
	push	1CEh
	mov	di,1830h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	12Fh
	push	1CEh
	mov	di,183Fh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	163h
	push	1CEh
	mov	di,1842h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	197h
	push	1CEh
	mov	di,1845h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	1CBh
	push	1CEh
	mov	di,1848h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0Bh
	call	far 1AB8h:1C32h
	push	44h
	push	1CFh
	mov	di,1830h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	94h
	push	1CFh
	mov	di,1838h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0E4h
	push	1CFh
	mov	di,1830h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	130h
	push	1CFh
	mov	di,183Fh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	164h
	push	1CFh
	mov	di,1842h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	198h
	push	1CFh
	mov	di,1845h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	1CCh
	push	1CFh
	mov	di,1848h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0h
	call	far 1AB8h:1C32h
	push	1h
	push	198h
	push	16h
	call	04CCh
	push	ax
	push	1D1h
	push	9Ch
	push	1B4h
	call	far 1206h:01ACh
	call	far 1206h:0038h
	leave
	ret

;; fn0800_19E1: 0800:19E1
;;   Called from:
;;     0800:1F37 (in fn0800_1E3F)
;;     0800:1F84 (in fn0800_1E3F)
;;     0800:20FA (in fn0800_2004)
;;     0800:2140 (in fn0800_2004)
;;     0800:22AF (in fn0800_21E7)
;;     0800:22C3 (in fn0800_21E7)
;;     0800:22D5 (in fn0800_21E7)
;;     0800:22E7 (in fn0800_21E7)
;;     0800:2300 (in fn0800_21E7)
;;     0800:2314 (in fn0800_21E7)
;;     0800:232D (in fn0800_21E7)
;;     0800:2341 (in fn0800_21E7)
;;     0800:2353 (in fn0800_21E7)
;;     0800:2365 (in fn0800_21E7)
;;     0800:39F1 (in fn0800_391E)
;;     0800:3A03 (in fn0800_391E)
;;     0800:3AE2 (in fn0800_391E)
;;     0800:3B81 (in fn0800_391E)
;;     0800:3BB1 (in fn0800_391E)
;;     0800:3F16 (in fn0800_3D9D)
;;     0800:3F47 (in fn0800_3D9D)
;;     0800:3F5E (in fn0800_3D9D)
;;     0800:3FC7 (in fn0800_3D9D)
;;     0800:3FDD (in fn0800_3D9D)
;;     0800:3FF8 (in fn0800_3D9D)
;;     0800:4044 (in fn0800_3D9D)
;;     0800:405F (in fn0800_3D9D)
;;     0800:407D (in fn0800_3D9D)
;;     0800:411A (in fn0800_3D9D)
;;     0800:414E (in fn0800_3D9D)
fn0800_19E1 proc
	enter	108h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	call	far 1206h:0066h
	push	1h
	push	0h
	push	3h
	call	far 1AB8h:1536h
	push	1h
	push	3h
	call	far 1AB8h:1175h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1E0Bh
	shr	ax,1h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ch]
	cwd
	sub	ax,cx
	sbb	dx,bx
	sub	ax,5h
	sbb	dx,0h
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+53E2h],ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1E0Bh
	shr	ax,1h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ch]
	cwd
	add	ax,cx
	adc	dx,bx
	add	ax,5h
	adc	dx,0h
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+53FEh],ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ah]
	cwd
	sub	ax,cx
	sbb	dx,bx
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+53F0h],ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ah]
	cwd
	add	ax,cx
	adc	dx,bx
	add	ax,5h
	adc	dx,0h
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+540Ch],ax
	mov	ax,[bp+0Ch]
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+541Ah],ax
	mov	ax,[bp+0Ah]
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+5428h],ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	imul	di,[bp+0Eh],1Ah
	add	di,541Eh
	push	ds
	push	di
	push	19h
	call	far 1EDAh:0A39h
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	ax,[di+53E2h]
	mov	[bp+0FEFEh],ax
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	ax,[di+53FEh]
	mov	[bp+0FEFAh],ax
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	ax,[di+53F0h]
	mov	[bp+0FEFCh],ax
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	ax,[di+540Ch]
	mov	[bp+0FEF8h],ax
	push	word ptr [bp+0FEFEh]
	push	word ptr [bp+0FEFCh]
	push	word ptr [bp+0FEFAh]
	push	word ptr [bp+0FEF8h]
	call	far 1AB8h:1B3Eh
	push	0Bh
	call	far 1AB8h:1C32h
	cmp	byte ptr [bp+4h],0h
	jz	1B53h

l0800_1B4C:
	push	0h
	call	far 1AB8h:1C32h

l0800_1B53:
	mov	ax,[bp+0FEFEh]
	sub	ax,3h
	push	ax
	push	word ptr [bp+0FEFCh]
	mov	ax,[bp+0FEFAh]
	add	ax,3h
	push	ax
	push	word ptr [bp+0FEFCh]
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0FEFEh]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	0Bh
	call	far 1AB8h:1C32h
	mov	ax,[bp+0FEFEh]
	dec	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp+0FEFAh]
	mov	ax,[bp+0FEFCh]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	cmp	byte ptr [bp+4h],0h
	jz	1BBFh

l0800_1BB8:
	push	0h
	call	far 1AB8h:1C32h

l0800_1BBF:
	mov	ax,[bp+0FEFEh]
	sub	ax,3h
	push	ax
	push	word ptr [bp+0FEFCh]
	mov	ax,[bp+0FEFEh]
	sub	ax,3h
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0FEFEh]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFEh]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	0Bh
	call	far 1AB8h:1C32h
	mov	ax,[bp+0FEFEh]
	dec	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0FEFEh]
	dec	ax
	push	ax
	push	word ptr [bp+0FEF8h]
	call	far 1AB8h:1AF6h
	push	8h
	call	far 1AB8h:1C32h
	cmp	byte ptr [bp+4h],0h
	jz	1C35h

l0800_1C2E:
	push	0h
	call	far 1AB8h:1C32h

l0800_1C35:
	mov	ax,[bp+0FEFAh]
	add	ax,3h
	push	ax
	push	word ptr [bp+0FEFCh]
	mov	ax,[bp+0FEFAh]
	add	ax,3h
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0FEFAh]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp+0FEF8h]
	call	far 1AB8h:1AF6h
	push	8h
	call	far 1AB8h:1C32h
	mov	ax,[bp+0FEFAh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	cmp	byte ptr [bp+4h],0h
	jz	1CA3h

l0800_1C9C:
	push	0h
	call	far 1AB8h:1C32h

l0800_1CA3:
	mov	ax,[bp+0FEFEh]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0FEFEh]
	dec	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	8h
	call	far 1AB8h:1C32h
	push	word ptr [bp+0FEFEh]
	push	word ptr [bp+0FEF8h]
	push	word ptr [bp+0FEFAh]
	push	word ptr [bp+0FEF8h]
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp+0FEFEh]
	sub	ax,4h
	push	ax
	mov	ax,[bp+0FEFCh]
	dec	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	add	ax,4h
	push	ax
	mov	ax,[bp+0FEF8h]
	add	ax,3h
	push	ax
	call	far 1AB8h:112Eh
	push	1h
	call	far 1AB8h:1C32h
	cmp	byte ptr [bp+4h],0h
	jz	1D3Bh

l0800_1D34:
	push	0Eh
	call	far 1AB8h:1C32h

l0800_1D3B:
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	call	far 1206h:0038h
	leave
	ret	0Ch

;; fn0800_1D55: 0800:1D55
;;   Called from:
;;     0800:3ED9 (in fn0800_3D9D)
fn0800_1D55 proc
	enter	0Ah,0h

l0800_1D59:
	lea	di,[bp-4h]
	push	ss
	push	di
	lea	di,[bp-6h]
	push	ss
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	call	far 1206h:0094h
	cmp	word ptr [bp-4h],0h
	jnz	1D59h

l0800_1D73:
	mov	byte ptr [bp-1h],0h
	mov	byte ptr [bp-9h],1h
	jmp	1D80h

l0800_1D7D:
	inc	byte ptr [bp-9h]

l0800_1D80:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53E2h]
	cmp	ax,[bp-6h]
	jge	1DD5h

l0800_1D92:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53FEh]
	cmp	ax,[bp-6h]
	jle	1DD5h

l0800_1DA4:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53F0h]
	cmp	ax,[bp-8h]
	jge	1DD5h

l0800_1DB6:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+540Ch]
	cmp	ax,[bp-8h]
	jle	1DD5h

l0800_1DC8:
	mov	al,[bp-9h]
	xor	ah,ah
	add	ax,3Ah
	mov	[bp-1h],al
	jmp	1DDBh

l0800_1DD5:
	cmp	byte ptr [bp-9h],7h
	jnz	1D7Dh

l0800_1DDB:
	mov	al,[bp-1h]
	leave
	ret
0800:1DE0 02 C0 18 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:1DF0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:1E00 1E 20 20 20 20 20 20 50 52 45 53 53 45 5A 20 55 .      PRESSEZ U
0800:1E10 4E 45 20 54 4F 55 43 48 45 20 20 20 20 20 20 00 NE TOUCHE      .
0800:1E20 00 00 00 00 00 00 00 80 00 00 00 80 00 00 00 00 ................
0800:1E30 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    ............... 

;; fn0800_1E3F: 0800:1E3F
;;   Called from:
;;     0800:2150 (in fn0800_2004)
fn0800_1E3F proc
	enter	0Ch,0h

l0800_1E43:
	call	far 1E78h:02FBh
	or	al,al
	jz	1E53h

l0800_1E4C:
	call	far 1E78h:030Dh
	jmp	1E43h

l0800_1E53:
	mov	word ptr [bp-2h],2Ah
	mov	word ptr [bp-6h],14h
	call	far 1AB8h:10CEh
	sub	ax,2Ah
	mov	[bp-4h],ax
	mov	word ptr [bp-8h],16Ah
	call	far 1206h:0066h
	push	word ptr [bp-2h]
	push	word ptr [bp-6h]
	push	word ptr [bp-4h]
	push	word ptr [bp-8h]
	call	1315h
	mov	ax,[bp-2h]
	add	ax,8h
	mov	[bp-2h],ax
	mov	ax,[bp-6h]
	add	ax,8h
	mov	[bp-6h],ax
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	mov	byte ptr [bp-0Bh],1h
	jmp	1EB0h

l0800_1EAD:
	inc	byte ptr [bp-0Bh]

l0800_1EB0:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-2h]
	dec	ax
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	dec	ax
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,2306h
	push	ds
	push	di
	call	far 1AB8h:1D82h
	mov	al,[bp-0Bh]
	push	ax
	mov	di,1DE0h
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	1EF7h

l0800_1EEE:
	push	0Ah
	call	far 1AB8h:1C32h
	jmp	1EFEh

l0800_1EF7:
	push	0Bh
	call	far 1AB8h:1C32h

l0800_1EFE:
	push	word ptr [bp-2h]
	mov	al,[bp-0Bh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,2306h
	push	ds
	push	di
	call	far 1AB8h:1D82h
	cmp	byte ptr [bp-0Bh],14h
	jnz	1EADh

l0800_1F28:
	push	5h
	push	140h
	push	14Ah
	mov	di,1E00h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_1F3A:
	call	far 1E78h:02FBh
	or	al,al
	jnz	1F4Eh

l0800_1F43:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	1F3Ah

l0800_1F4E:
	call	far 1E78h:02FBh
	or	al,al
	jz	1F75h

l0800_1F57:
	call	far 1E78h:030Dh
	push	ax
	mov	di,1E1Fh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	1F75h

l0800_1F69:
	cmp	byte ptr [53D8h],0h
	jz	1F75h

l0800_1F70:
	mov	byte ptr [0002h],0FFh

l0800_1F75:
	push	5h
	push	140h
	push	14Ah
	mov	di,1E00h
	push	cs
	push	di
	push	1h
	call	19E1h
	call	far 1206h:0066h
	push	96h
	call	far 1E78h:029Ch
	mov	ax,[bp-2h]
	sub	ax,0Ch
	push	ax
	mov	ax,[bp-6h]
	sub	ax,0Ch
	push	ax
	mov	ax,[bp-4h]
	add	ax,4h
	push	ax
	mov	ax,[bp-8h]
	add	ax,4h
	push	ax
	call	0024h
	leave
	ret
0800:1FB5                12 90 03 00 00 00 00 00 00 00 00      ...........
0800:1FC0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:1FD0 00 00 00 00 00 0E 20 20 20 53 55 49 54 45 2E 2E ......   SUITE..
0800:1FE0 2E 20 20 20 00 00 00 00 00 00 00 00 00 20 00 00 .   ......... ..
0800:1FF0 00 20 00 00 00 00 00 00 00 00 00 00 00 00 00 00 . ..............
0800:2000 00 00 00 00                                     ....            

;; fn0800_2004: 0800:2004
;;   Called from:
;;     0800:40F8 (in fn0800_3D9D)
fn0800_2004 proc
	enter	0Ah,0h
	mov	byte ptr [53D8h],0h
	mov	word ptr [bp-2h],9Ch
	mov	word ptr [bp-6h],14h
	mov	word ptr [bp-4h],1E0h
	mov	word ptr [bp-8h],16Ah
	push	word ptr [bp-2h]
	push	word ptr [bp-6h]
	push	word ptr [bp-4h]
	push	word ptr [bp-8h]
	call	1315h
	mov	ax,[bp-2h]
	add	ax,8h
	mov	[bp-2h],ax
	mov	ax,[bp-6h]
	add	ax,0Ch
	mov	[bp-6h],ax
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	mov	byte ptr [bp-9h],1h
	jmp	205Fh

l0800_205C:
	inc	byte ptr [bp-9h]

l0800_205F:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	sub	ax,[bp-2h]
	shr	ax,1h
	add	ax,[bp-2h]
	dec	ax
	push	ax
	mov	al,[bp-9h]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	dec	ax
	push	ax
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,3706h
	push	ds
	push	di
	call	far 1AB8h:1D82h
	mov	al,[bp-9h]
	push	ax
	mov	di,1FB5h
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	20AEh

l0800_20A5:
	push	0Ah
	call	far 1AB8h:1C32h
	jmp	20B5h

l0800_20AE:
	push	0Bh
	call	far 1AB8h:1C32h

l0800_20B5:
	mov	ax,[bp-4h]
	sub	ax,[bp-2h]
	shr	ax,1h
	add	ax,[bp-2h]
	push	ax
	mov	al,[bp-9h]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	push	ax
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,3706h
	push	ds
	push	di
	call	far 1AB8h:1D82h
	cmp	byte ptr [bp-9h],15h
	jz	20EBh

l0800_20E8:
	jmp	205Ch

l0800_20EB:
	push	5h
	push	140h
	push	14Ah
	mov	di,1FD5h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_20FD:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2111h

l0800_2106:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	20FDh

l0800_2111:
	call	far 1E78h:02FBh
	or	al,al
	jz	2131h

l0800_211A:
	call	far 1E78h:030Dh
	push	ax
	mov	di,1FE4h
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	2131h

l0800_212C:
	mov	byte ptr [53D8h],1h

l0800_2131:
	push	5h
	push	140h
	push	14Ah
	mov	di,1FD5h
	push	cs
	push	di
	push	1h
	call	19E1h
	call	far 1206h:0066h
	push	96h
	call	far 1E78h:029Ch
	call	1E3Fh
	leave
	ret
0800:2155                03 52 41 44 16 56 65 72 73 69 6F      .RAD.Versio
0800:2160 6E 20 65 6E 72 65 67 69 73 74 72 82 65 20 3A 20 n enregistr.e : 
0800:2170 09 20 74 61 62 6C 65 61 75 78 03 46 31 3A 01 20 . tableaux.F1:. 
0800:2180 0B 20 20 46 31 3A 4A 45 55 20 20 20 0A 46 32 3A .  F1:JEU   .F2:
0800:2190 4D 49 53 53 49 4F 4E 0A 20 20 46 33 3A 44 45 4D MISSION.  F3:DEM
0800:21A0 4F 20 0A 46 34 3A 53 49 4C 45 4E 43 45 0B 20 20 O .F4:SILENCE.  
0800:21B0 46 35 3A 45 44 49 54 20 20 0B 20 20 46 35 3A 49 F5:EDIT  .  F5:I
0800:21C0 4E 46 4F 20 20 0A 46 36 3A 4E 4F 54 49 43 45 20 NFO  .F6:NOTICE 
0800:21D0 16 20 20 20 46 37 3A 52 45 54 4F 55 52 20 41 55 .   F7:RETOUR AU
0800:21E0 20 44 4F 53 20 20 20                             DOS            

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

;; fn0800_2401: 0800:2401
;;   Called from:
;;     0800:2F51 (in fn0800_2C0C)
fn0800_2401 proc
	enter	282h,0h
	mov	di,236Ah
	push	cs
	push	di
	call	far 0C74h:0000h
	or	al,al
	jnz	2416h

l0800_2413:
	jmp	280Eh

l0800_2416:
	call	far 1E78h:02FBh
	or	al,al
	jz	2426h

l0800_241F:
	call	far 1E78h:030Dh
	jmp	2416h

l0800_2426:
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	mov	di,2372h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	push	100h
	call	far 1EDAh:0FD0h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	push	word ptr [5990h]
	push	word ptr [598Eh]
	call	far 1EDAh:1123h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:1085h
	add	sp,4h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	cmp	byte ptr [bp+0FF01h],20h
	jnz	2480h

l0800_247D:
	jmp	280Eh

l0800_2480:
	call	far 1206h:0066h
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,82h
	push	ax
	push	96h
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,82h
	push	ax
	push	0E6h
	call	1315h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	4h
	call	far 1AB8h:1C32h
	push	140h
	push	0A4h
	mov	di,237Ah
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	1h
	call	far 1AB8h:1C32h
	push	140h
	push	0B4h
	mov	di,238Eh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	140h
	push	0C0h
	mov	di,23ACh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	140h
	push	0CCh
	mov	di,23C3h
	push	cs
	push	di
	call	far 1AB8h:1D82h

l0800_2505:
	call	far 1E78h:02FBh
	or	al,al
	jz	2505h

l0800_250E:
	mov	al,[5CDEh]
	mov	[53D9h],al
	mov	al,[5CDFh]
	mov	[53DAh],al
	mov	al,[5CDAh]
	mov	[53DBh],al
	mov	al,[5CDBh]
	mov	[53DCh],al
	cmp	byte ptr [5CDCh],0Ah
	jbe	2532h

l0800_252D:
	mov	byte ptr [5CDCh],0Ah

l0800_2532:
	mov	al,[5CDCh]
	mov	[53DDh],al
	mov	al,[5CDDh]
	mov	[53DEh],al
	xor	ax,ax
	mov	[53D6h],ax
	jmp	2549h

l0800_2545:
	inc	word ptr [53D6h]

l0800_2549:
	xor	ax,ax
	mov	[53D4h],ax
	jmp	2554h

l0800_2550:
	inc	word ptr [53D4h]

l0800_2554:
	imul	ax,[53D4h],16h
	inc	ax
	push	ax
	imul	ax,[53D6h],16h
	inc	ax
	push	ax
	mov	ax,[53D4h]
	imul	di,[53D6h],1Dh
	add	di,ax
	mov	al,[di+5CE0h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5992h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	word ptr [53D4h],1Ch
	jnz	2550h

l0800_258B:
	cmp	word ptr [53D6h],10h
	jnz	2545h

l0800_2592:
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,23E1h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	25B2h

l0800_25A3:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	jmp	280Eh

l0800_25B2:
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	0Fh
	push	184h
	push	114h
	push	18Fh
	call	005Ah
	push	8h
	call	far 1AB8h:1C32h
	push	93h
	push	189h
	mov	di,23E8h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0Ch
	call	far 1AB8h:1C32h
	push	94h
	push	18Ah
	mov	di,23E8h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	call	04E3h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,5ED6h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	call	0619h
	call	0BECh
	call	far 1206h:0066h
	mov	al,[53D9h]
	push	ax
	call	04CCh
	push	ax
	mov	al,[53DAh]
	push	ax
	call	04CCh
	push	ax
	call	far 0C74h:06B7h
	call	far 1206h:0038h
	mov	al,[53DDh]
	xor	ah,ah
	imul	ax,ax,3Ch
	cwd
	push	dx
	push	ax
	call	00C1h
	mov	byte ptr [bp+0FE7Fh],1h

l0800_264E:
	call	far 1E78h:02FBh
	or	al,al
	jz	265Eh

l0800_2657:
	call	far 1E78h:030Dh
	jmp	264Eh

l0800_265E:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2672h

l0800_2667:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	265Eh

l0800_2672:
	call	far 1E78h:02FBh
	or	al,al
	jz	2692h

l0800_267B:
	call	far 1E78h:030Dh
	mov	[53D2h],al
	cmp	byte ptr [53D2h],1Bh
	jnz	2690h

l0800_268A:
	call	0103h
	jmp	280Eh

l0800_2690:
	jmp	26A3h

l0800_2692:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	26A3h

l0800_269D:
	call	031Bh
	mov	[53D2h],al

l0800_26A3:
	cmp	byte ptr [53D2h],1Bh
	jnz	26B0h

l0800_26AA:
	call	0103h
	jmp	280Eh

l0800_26B0:
	cmp	byte ptr [bp+0FE7Fh],0FFh
	jnc	26CAh

l0800_26B7:
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[53D2h],al
	inc	byte ptr [bp+0FE7Fh]

l0800_26CA:
	mov	al,[53D2h]
	cmp	al,3Bh
	jnz	26F2h

l0800_26D1:
	push	0Eh
	call	09C2h
	cmp	byte ptr [53DBh],0h
	jbe	26EAh

l0800_26DD:
	call	far 0C74h:522Ch
	or	al,al
	jz	26EAh

l0800_26E6:
	dec	byte ptr [53DBh]

l0800_26EA:
	push	5h
	call	09C2h
	jmp	27F7h

l0800_26F2:
	cmp	al,3Ch
	jnz	272Ah

l0800_26F6:
	push	0Fh
	call	09C2h
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[58BDh],al
	inc	byte ptr [bp+0FE7Fh]
	cmp	byte ptr [53DCh],0h
	jbe	2722h

l0800_2715:
	call	far 0C74h:542Bh
	or	al,al
	jz	2722h

l0800_271E:
	dec	byte ptr [53DCh]

l0800_2722:
	push	6h
	call	09C2h
	jmp	27F7h

l0800_272A:
	cmp	al,3Dh
	jnz	274Fh

l0800_272E:
	push	10h
	call	09C2h
	cmp	byte ptr [53DEh],0h
	jbe	2747h

l0800_273A:
	call	far 0C74h:5258h
	or	al,al
	jz	2747h

l0800_2743:
	dec	byte ptr [53DEh]

l0800_2747:
	push	7h
	call	09C2h
	jmp	27F7h

l0800_274F:
	cmp	al,1Bh
	jnz	275Ch

l0800_2753:
	call	0103h
	jmp	280Eh
0800:2759                            E9 9B 00                      ...    

l0800_275C:
	cmp	al,48h
	jnz	2772h

l0800_2760:
	push	9h
	call	09C2h
	call	far 0C74h:51AAh
	push	0h
	call	09C2h
	jmp	27F7h

l0800_2772:
	cmp	al,4Bh
	jnz	27ABh

l0800_2776:
	push	0Ah
	call	09C2h
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[58BDh],al
	inc	byte ptr [bp+0FE7Fh]
	call	far 0C74h:54F0h
	or	al,al
	jnz	27A4h

l0800_2797:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_27A4:
	push	1h
	call	09C2h
	jmp	27F7h

l0800_27AB:
	cmp	al,4Dh
	jnz	27E4h

l0800_27AF:
	push	0Ch
	call	09C2h
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[58BDh],al
	inc	byte ptr [bp+0FE7Fh]
	call	far 0C74h:54B1h
	or	al,al
	jnz	27DDh

l0800_27D0:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_27DD:
	push	3h
	call	09C2h
	jmp	27F7h

l0800_27E4:
	cmp	al,50h
	jnz	27F7h

l0800_27E8:
	push	0Dh
	call	09C2h
	call	far 0C74h:51B2h
	push	4h
	call	09C2h

l0800_27F7:
	call	0C71h
	call	0877h
	or	al,al
	jnz	280Bh

l0800_2801:
	cmp	byte ptr [58B3h],0h
	jnz	280Bh

l0800_2808:
	jmp	264Eh

l0800_280B:
	call	0103h

l0800_280E:
	leave
	ret
0800:2810 07 52 61 64 2E 68 6C 70 06 4E 4F 4E 41 4D 45 07 .Rad.hlp.NONAME.
0800:2820 52 41 44 2E 48 4C 50                            RAD.HLP         

;; fn0800_2827: 0800:2827
;;   Called from:
;;     0800:3EF3 (in fn0800_3D9D)
fn0800_2827 proc
	enter	282h,0h

l0800_282B:
	mov	di,2810h
	push	cs
	push	di
	call	far 0C74h:0000h
	or	al,al
	jnz	283Ch

l0800_2839:
	jmp	2B41h

l0800_283C:
	call	far 1E78h:02FBh
	or	al,al
	jz	284Ch

l0800_2845:
	call	far 1E78h:030Dh
	jmp	283Ch

l0800_284C:
	call	far 1206h:0066h
	call	far 13E2h:003Bh
	call	01FEh
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2818h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	2879h

l0800_286A:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	jmp	2B41h

l0800_2879:
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	mov	di,281Fh
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	push	100h
	call	far 1EDAh:0FD0h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	push	word ptr [5990h]
	push	word ptr [598Eh]
	call	far 1EDAh:1123h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:1085h
	add	sp,4h
	lea	di,[bp+0FE80h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	cmp	byte ptr [bp+0FF01h],20h
	jnz	28D3h

l0800_28D0:
	jmp	2B41h

l0800_28D3:
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	0Fh
	push	184h
	push	114h
	push	18Fh
	call	005Ah
	push	8h
	call	far 1AB8h:1C32h
	push	94h
	push	18Ah
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	94h
	push	18Ah
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	call	04E3h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,5ED6h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	call	0619h
	call	0BECh
	call	far 13E2h:00FBh
	push	8h
	push	0h
	call	far 1AB8h:1342h
	call	far 1206h:0066h
	mov	al,[53D9h]
	push	ax
	call	04CCh
	push	ax
	mov	al,[53DAh]
	push	ax
	call	04CCh
	push	ax
	call	far 0C74h:06B7h
	call	far 1206h:0038h
	mov	al,[53DDh]
	xor	ah,ah
	imul	ax,ax,3Ch
	cwd
	push	dx
	push	ax
	call	00C1h
	mov	byte ptr [bp+0FE7Fh],1h

l0800_297D:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2991h

l0800_2986:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	2997h

l0800_2991:
	call	0103h
	jmp	2B41h

l0800_2997:
	cmp	byte ptr [bp+0FE7Fh],0FFh
	jnc	29B1h

l0800_299E:
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[53D2h],al
	inc	byte ptr [bp+0FE7Fh]

l0800_29B1:
	mov	al,[53D2h]
	cmp	al,3Bh
	jnz	29D9h

l0800_29B8:
	push	0Eh
	call	09C2h
	cmp	byte ptr [53DBh],0h
	jbe	29D1h

l0800_29C4:
	call	far 0C74h:522Ch
	or	al,al
	jz	29D1h

l0800_29CD:
	dec	byte ptr [53DBh]

l0800_29D1:
	push	5h
	call	09C2h
	jmp	2ADEh

l0800_29D9:
	cmp	al,3Ch
	jnz	2A11h

l0800_29DD:
	push	0Fh
	call	09C2h
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[58BDh],al
	inc	byte ptr [bp+0FE7Fh]
	cmp	byte ptr [53DCh],0h
	jbe	2A09h

l0800_29FC:
	call	far 0C74h:542Bh
	or	al,al
	jz	2A09h

l0800_2A05:
	dec	byte ptr [53DCh]

l0800_2A09:
	push	6h
	call	09C2h
	jmp	2ADEh

l0800_2A11:
	cmp	al,3Dh
	jnz	2A36h

l0800_2A15:
	push	10h
	call	09C2h
	cmp	byte ptr [53DEh],0h
	jbe	2A2Eh

l0800_2A21:
	call	far 0C74h:5258h
	or	al,al
	jz	2A2Eh

l0800_2A2A:
	dec	byte ptr [53DEh]

l0800_2A2E:
	push	7h
	call	09C2h
	jmp	2ADEh

l0800_2A36:
	cmp	al,1Bh
	jnz	2A43h

l0800_2A3A:
	call	0103h
	jmp	2B41h
0800:2A40 E9 9B 00                                        ...             

l0800_2A43:
	cmp	al,48h
	jnz	2A59h

l0800_2A47:
	push	9h
	call	09C2h
	call	far 0C74h:51AAh
	push	0h
	call	09C2h
	jmp	2ADEh

l0800_2A59:
	cmp	al,4Bh
	jnz	2A92h

l0800_2A5D:
	push	0Ah
	call	09C2h
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[58BDh],al
	inc	byte ptr [bp+0FE7Fh]
	call	far 0C74h:54F0h
	or	al,al
	jnz	2A8Bh

l0800_2A7E:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_2A8B:
	push	1h
	call	09C2h
	jmp	2ADEh

l0800_2A92:
	cmp	al,4Dh
	jnz	2ACBh

l0800_2A96:
	push	0Ch
	call	09C2h
	mov	al,[bp+0FE7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[bp+di+0FF00h]
	mov	[58BDh],al
	inc	byte ptr [bp+0FE7Fh]
	call	far 0C74h:54B1h
	or	al,al
	jnz	2AC4h

l0800_2AB7:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_2AC4:
	push	3h
	call	09C2h
	jmp	2ADEh

l0800_2ACB:
	cmp	al,50h
	jnz	2ADEh

l0800_2ACF:
	push	0Dh
	call	09C2h
	call	far 0C74h:51B2h
	push	4h
	call	09C2h

l0800_2ADE:
	call	0C71h
	call	0877h
	or	al,al
	jnz	2AF2h

l0800_2AE8:
	cmp	byte ptr [58B3h],0h
	jnz	2AF2h

l0800_2AEF:
	jmp	297Dh

l0800_2AF2:
	call	0103h
	call	0877h
	or	al,al
	jz	2B39h

l0800_2AFC:
	add	word ptr [598Eh],1h
	adc	word ptr [5990h],0h
	mov	al,[0002h]
	xor	ah,ah
	xor	dx,dx
	cmp	dx,[5990h]
	jnz	2B1Eh

l0800_2B13:
	cmp	ax,[598Eh]
	jnz	2B1Eh

l0800_2B19:
	call	166Dh
	jmp	2B41h

l0800_2B1E:
	cmp	word ptr [5990h],0h
	jnz	2B39h

l0800_2B25:
	cmp	word ptr [598Eh],0FAh
	jnz	2B39h

l0800_2B2D:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h

l0800_2B39:
	call	far 1206h:0066h
	jmp	282Bh

l0800_2B41:
	leave
	ret
0800:2B43          06 4E 4F 4E 41 4D 45 04 44 45 4D 4F 07    .NONAME.DEMO.
0800:2B50 52 41 44 2E 4D 45 4D 2A 49 6D 70 6F 73 73 69 62 RAD.MEM*Impossib
0800:2B60 6C 65 20 64 27 61 63 63 82 64 65 72 20 85 20 52 le d'acc.der . R
0800:2B70 61 64 2E 6D 65 6D 20 65 6E 20 82 63 72 69 74 75 ad.mem en .critu
0800:2B80 72 65 2C 76 82 72 69 66 69 65 7A 20 71 75 65 20 re,v.rifiez que 
0800:2B90 6C 61 20 64 69 73 71 75 65 74 74 65 20 6E 27 65 la disquette n'e
0800:2BA0 73 74 20 70 61 73 20 70 72 6F 74 82 67 82 65 2A st pas prot.g.e*
0800:2BB0 6F 75 20 74 72 61 6E 73 66 82 72 65 7A 20 6C 65 ou transf.rez le
0800:2BC0 20 70 72 6F 67 72 61 6D 6D 65 20 73 75 72 20 64  programme sur d
0800:2BD0 69 73 71 75 65 20 64 75 72 2E 12 50 52 45 53 53 isque dur..PRESS
0800:2BE0 45 5A 20 55 4E 45 20 54 4F 55 43 48 45 1E 44 45 EZ UNE TOUCHE.DE
0800:2BF0 4D 4F 3A 50 72 65 73 73 65 7A 20 45 73 63 61 70 MO:Pressez Escap
0800:2C00 65 20 70 6F 75 72 20 66 69 6E 69 72             e pour finir    

;; fn0800_2C0C: 0800:2C0C
;;   Called from:
;;     0800:3F26 (in fn0800_3D9D)
;;     0800:400E (in fn0800_3D9D)
fn0800_2C0C proc
	enter	102h,0h

l0800_2C10:
	call	far 1E78h:02FBh
	or	al,al
	jz	2C20h

l0800_2C19:
	call	far 1E78h:030Dh
	jmp	2C10h

l0800_2C20:
	call	far 1206h:0066h
	call	far 13E2h:003Bh
	call	01FEh
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B43h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	2C4Dh

l0800_2C3E:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	jmp	3110h

l0800_2C4D:
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	2C61h

l0800_2C5E:
	jmp	2D2Bh

l0800_2C61:
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	di,2B4Fh
	push	cs
	push	di
	call	far 1EDAh:04F5h
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	call	far 1EDAh:056Ah
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	di,5ECEh
	push	ds
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	call	far 1EDAh:05BFh
	call	far 1EDAh:04A2h
	or	ax,ax
	jnz	2CAAh

l0800_2CA7:
	jmp	2D2Bh

l0800_2CAA:
	push	word ptr [0B8ACh]
	call	far 1E78h:016Bh
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,2B57h
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	call	far 1EDAh:04A9h
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,2B82h
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	call	far 1EDAh:04A9h
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,2BAFh
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	call	far 1EDAh:04A9h
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,2BDAh
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	call	far 1EDAh:04A9h
	call	far 1E78h:030Dh
	xor	ax,ax
	call	far 1EDAh:00E9h

l0800_2D2B:
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	0Fh
	push	184h
	push	114h
	push	18Fh
	call	005Ah
	push	8h
	call	far 1AB8h:1C32h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	2D77h

l0800_2D65:
	push	93h
	push	189h
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	jmp	2D87h

l0800_2D77:
	push	93h
	push	189h
	mov	di,2BEDh
	push	cs
	push	di
	call	far 1AB8h:1D82h

l0800_2D87:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	2DB1h

l0800_2D9F:
	push	94h
	push	18Ah
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	jmp	2DC1h

l0800_2DB1:
	push	94h
	push	18Ah
	mov	di,2BEDh
	push	cs
	push	di
	call	far 1AB8h:1D82h

l0800_2DC1:
	call	04E3h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,5ED6h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	call	0619h
	call	0BECh
	call	far 13E2h:00FBh
	push	8h
	push	0h
	call	far 1AB8h:1342h
	call	far 1206h:0066h
	mov	al,[53D9h]
	push	ax
	call	04CCh
	push	ax
	mov	al,[53DAh]
	push	ax
	call	04CCh
	push	ax
	call	far 0C74h:06B7h
	call	far 1206h:0038h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	2E37h

l0800_2E19:
	push	0Bh
	call	09C2h

l0800_2E1E:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2E32h

l0800_2E27:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	2E1Eh

l0800_2E32:
	push	2h
	call	09C2h

l0800_2E37:
	mov	al,[53DDh]
	xor	ah,ah
	imul	ax,ax,3Ch
	cwd
	push	dx
	push	ax
	call	00C1h
	mov	byte ptr [bp-1h],1h

l0800_2E49:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2E71h

l0800_2E52:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jnz	2E71h

l0800_2E5D:
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	2E71h

l0800_2E6E:
	jmp	3087h

l0800_2E71:
	call	far 1E78h:02FBh
	or	al,al
	jz	2EA3h

l0800_2E7A:
	call	far 1E78h:030Dh
	mov	[53D2h],al
	cmp	byte ptr [53D2h],0h
	jnz	2E91h

l0800_2E89:
	call	far 1E78h:030Dh
	mov	[53D2h],al

l0800_2E91:
	call	far 1E78h:02FBh
	or	al,al
	jz	2EA1h

l0800_2E9A:
	call	far 1E78h:030Dh
	jmp	2E91h

l0800_2EA1:
	jmp	2EA9h

l0800_2EA3:
	call	031Bh
	mov	[53D2h],al

l0800_2EA9:
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	2ED2h

l0800_2EBA:
	cmp	byte ptr [53D2h],1Bh
	jz	2ECFh

l0800_2EC1:
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+5CBBh]
	mov	[53D2h],al

l0800_2ECF:
	inc	byte ptr [bp-1h]

l0800_2ED2:
	mov	al,[53D2h]
	cmp	al,3Bh
	jnz	2EFAh

l0800_2ED9:
	push	0Eh
	call	09C2h
	cmp	byte ptr [53DBh],0h
	jbe	2EF2h

l0800_2EE5:
	call	far 0C74h:522Ch
	or	al,al
	jz	2EF2h

l0800_2EEE:
	dec	byte ptr [53DBh]

l0800_2EF2:
	push	5h
	call	09C2h
	jmp	3087h

l0800_2EFA:
	cmp	al,3Ch
	jnz	2F1Fh

l0800_2EFE:
	push	0Fh
	call	09C2h
	cmp	byte ptr [53DCh],0h
	jbe	2F17h

l0800_2F0A:
	call	far 0C74h:542Bh
	or	al,al
	jz	2F17h

l0800_2F13:
	dec	byte ptr [53DCh]

l0800_2F17:
	push	6h
	call	09C2h
	jmp	3087h

l0800_2F1F:
	cmp	al,3Dh
	jnz	2F44h

l0800_2F23:
	push	10h
	call	09C2h
	cmp	byte ptr [53DEh],0h
	jbe	2F3Ch

l0800_2F2F:
	call	far 0C74h:5258h
	or	al,al
	jz	2F3Ch

l0800_2F38:
	dec	byte ptr [53DEh]

l0800_2F3C:
	push	7h
	call	09C2h
	jmp	3087h

l0800_2F44:
	cmp	al,3Fh
	jz	2F4Ch

l0800_2F48:
	cmp	al,2Ch
	jnz	2FACh

l0800_2F4C:
	mov	byte ptr [58B2h],0h
	call	2401h
	mov	byte ptr [58B2h],1h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	0Fh
	push	184h
	push	114h
	push	18Fh
	call	005Ah
	push	8h
	call	far 1AB8h:1C32h
	push	93h
	push	189h
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	94h
	push	18Ah
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	jmp	3087h

l0800_2FAC:
	cmp	al,1Bh
	jnz	2FB9h

l0800_2FB0:
	call	0103h
	jmp	3110h
0800:2FB6                   E9 CE 00                            ...       

l0800_2FB9:
	cmp	al,20h
	jnz	2FFAh

l0800_2FBD:
	mov	ax,[58D8h]
	mov	dx,[58DAh]
	mov	[58D0h],ax
	mov	[58D2h],dx
	call	0103h
	push	0Bh
	call	09C2h

l0800_2FD3:
	call	far 1E78h:02FBh
	or	al,al
	jnz	2FE7h

l0800_2FDC:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	2FD3h

l0800_2FE7:
	push	2h
	call	09C2h
	push	word ptr [58D2h]
	push	word ptr [58D0h]
	call	00C1h
	jmp	3087h

l0800_2FFA:
	cmp	al,44h
	jnz	3013h

l0800_2FFE:
	cmp	byte ptr [58B0h],0h
	jz	300Ch

l0800_3005:
	mov	byte ptr [58B0h],0h
	jmp	3011h

l0800_300C:
	mov	byte ptr [58B0h],1h

l0800_3011:
	jmp	3087h

l0800_3013:
	cmp	al,48h
	jnz	3028h

l0800_3017:
	push	9h
	call	09C2h
	call	far 0C74h:51AAh
	push	0h
	call	09C2h
	jmp	3087h

l0800_3028:
	cmp	al,4Bh
	jnz	304Eh

l0800_302C:
	push	0Ah
	call	09C2h
	call	far 0C74h:54F0h
	or	al,al
	jnz	3047h

l0800_303A:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_3047:
	push	1h
	call	09C2h
	jmp	3087h

l0800_304E:
	cmp	al,4Dh
	jnz	3074h

l0800_3052:
	push	0Ch
	call	09C2h
	call	far 0C74h:54B1h
	or	al,al
	jnz	306Dh

l0800_3060:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_306D:
	push	3h
	call	09C2h
	jmp	3087h

l0800_3074:
	cmp	al,50h
	jnz	3087h

l0800_3078:
	push	0Dh
	call	09C2h
	call	far 0C74h:51B2h
	push	4h
	call	09C2h

l0800_3087:
	call	0C71h
	call	0877h
	or	al,al
	jnz	309Bh

l0800_3091:
	cmp	byte ptr [58B3h],0h
	jnz	309Bh

l0800_3098:
	jmp	2E49h

l0800_309B:
	call	0103h
	mov	di,5ECEh
	push	ds
	push	di
	mov	di,2B4Ah
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	30B1h

l0800_30AF:
	jmp	3110h

l0800_30B1:
	call	0877h
	or	al,al
	jz	3108h

l0800_30B8:
	call	0768h

l0800_30BB:
	call	far 1E78h:02FBh
	or	al,al
	jz	30CBh

l0800_30C4:
	call	far 1E78h:030Dh
	jmp	30BBh

l0800_30CB:
	add	word ptr [598Eh],1h
	adc	word ptr [5990h],0h
	mov	al,[0002h]
	xor	ah,ah
	xor	dx,dx
	cmp	dx,[5990h]
	jnz	30EDh

l0800_30E2:
	cmp	ax,[598Eh]
	jnz	30EDh

l0800_30E8:
	call	166Dh
	jmp	3110h

l0800_30ED:
	cmp	word ptr [5990h],0h
	jnz	3108h

l0800_30F4:
	cmp	word ptr [598Eh],0FAh
	jnz	3108h

l0800_30FC:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h

l0800_3108:
	call	far 1206h:0066h
	jmp	2C20h

l0800_3110:
	leave
	ret
0800:3112       40 20 20 20 20 20 20 20 20 20 20 20 20 20   @             
0800:3120 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20                 
0800:3130 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20                 
0800:3140 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20                 
0800:3150 20 20 20 07 46 4C 45 43 48 45 53 06 45 53 50 41    .FLECHES.ESPA
0800:3160 43 45 02 46 31 02 46 32 02 46 33 03 45 53 43 00 CE.F1.F2.F3.ESC.
0800:3170 00 00 00 00 00 00 38 00 29 01 00 00 00 00 00 00 ......8.).......
0800:3180 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:3190 00 00 00 00 00 00 10 00 28 00 00 00 00 00 00 00 ........(.......
0800:31A0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 07 ................
0800:31B0 52 41 44 2E 48 4C 50                            RAD.HLP         

;; fn0800_31B7: 0800:31B7
;;   Called from:
;;     0800:40EA (in fn0800_3D9D)
fn0800_31B7 proc
	enter	284h,0h

l0800_31BB:
	call	far 1E78h:02FBh
	or	al,al
	jz	31CBh

l0800_31C4:
	call	far 1E78h:030Dh
	jmp	31BBh

l0800_31CB:
	mov	di,3112h
	push	cs
	push	di
	lea	di,[bp+0FDFCh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	call	far 1206h:0066h
	push	8h
	call	far 1AB8h:1C32h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	push	0h
	push	27Fh
	push	177h
	call	far 1AB8h:112Eh
	push	0h
	push	179h
	push	27Fh
	push	1DFh
	call	0024h
	push	3h
	push	17Bh
	push	27Ch
	push	1DAh
	call	1315h
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,5ECEh
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,5ED6h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	mov	al,[5CDEh]
	mov	[53D9h],al
	mov	al,[5CDFh]
	mov	[53DAh],al
	mov	al,[5CDAh]
	mov	[53DBh],al
	mov	al,[5CDBh]
	mov	[53DCh],al
	cmp	byte ptr [5CDCh],0Ah
	jbe	3266h

l0800_3261:
	mov	byte ptr [5CDCh],0Ah

l0800_3266:
	mov	al,[5CDCh]
	mov	[53DDh],al
	mov	al,[5CDDh]
	mov	[53DEh],al
	mov	byte ptr [bp-2h],0h
	jmp	327Bh

l0800_3278:
	inc	byte ptr [bp-2h]

l0800_327B:
	mov	al,[bp-2h]
	push	ax
	call	09C2h
	call	far 1206h:0066h
	cmp	byte ptr [bp-2h],8h
	jnz	3278h

l0800_328D:
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	8h
	call	far 1AB8h:1C32h
	push	43h
	push	1CEh
	mov	di,3153h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	93h
	push	1CEh
	mov	di,315Bh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0E3h
	push	1CEh
	mov	di,3153h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	12Fh
	push	1CEh
	mov	di,3162h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	163h
	push	1CEh
	mov	di,3165h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	197h
	push	1CEh
	mov	di,3168h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	1CBh
	push	1CEh
	mov	di,316Bh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0Bh
	call	far 1AB8h:1C32h
	push	44h
	push	1CFh
	mov	di,3153h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	94h
	push	1CFh
	mov	di,315Bh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0E4h
	push	1CFh
	mov	di,3153h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	130h
	push	1CFh
	mov	di,3162h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	164h
	push	1CFh
	mov	di,3165h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	198h
	push	1CFh
	mov	di,3168h
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	1CCh
	push	1CFh
	mov	di,316Bh
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	0h
	call	far 1AB8h:1C32h
	push	1h
	push	16h
	call	04CCh
	push	ax
	call	far 1206h:00FFh
	push	198h
	push	1D1h
	call	far 1206h:012Dh
	push	9Ch
	push	1B4h
	call	far 1206h:00D1h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	0Fh
	push	184h
	push	114h
	push	18Fh
	call	005Ah
	push	8h
	call	far 1AB8h:1C32h
	push	93h
	push	189h
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	94h
	push	18Ah
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1AB8h:1D82h
	call	04E3h
	call	0619h
	call	0BECh
	push	8h
	push	0h
	call	far 1AB8h:1342h
	mov	al,[53D9h]
	push	ax
	call	04CCh
	push	ax
	mov	al,[53DAh]
	push	ax
	call	04CCh
	push	ax
	call	far 0C74h:06B7h
	push	0Bh
	call	09C2h

l0800_3433:
	call	far 1E78h:02FBh
	or	al,al
	jnz	3447h

l0800_343C:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	3433h

l0800_3447:
	push	2h
	call	09C2h
	mov	al,[53DDh]
	xor	ah,ah
	imul	ax,ax,3Ch
	cwd
	push	dx
	push	ax
	call	00C1h
	mov	byte ptr [bp-1h],1h

l0800_345E:
	call	far 1E78h:02FBh
	or	al,al
	jnz	3475h

l0800_3467:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jnz	3475h

l0800_3472:
	jmp	364Ah

l0800_3475:
	call	far 1E78h:02FBh
	or	al,al
	jz	34A7h

l0800_347E:
	call	far 1E78h:030Dh
	mov	[53D2h],al
	cmp	byte ptr [53D2h],0h
	jnz	3495h

l0800_348D:
	call	far 1E78h:030Dh
	mov	[53D2h],al

l0800_3495:
	call	far 1E78h:02FBh
	or	al,al
	jz	34A5h

l0800_349E:
	call	far 1E78h:030Dh
	jmp	3495h

l0800_34A5:
	jmp	34ADh

l0800_34A7:
	call	031Bh
	mov	[53D2h],al

l0800_34AD:
	mov	al,[53D2h]
	cmp	al,3Bh
	jnz	34D5h

l0800_34B4:
	push	0Eh
	call	09C2h
	cmp	byte ptr [53DBh],0h
	jbe	34CDh

l0800_34C0:
	call	far 0C74h:522Ch
	or	al,al
	jz	34CDh

l0800_34C9:
	dec	byte ptr [53DBh]

l0800_34CD:
	push	5h
	call	09C2h
	jmp	35FAh

l0800_34D5:
	cmp	al,3Ch
	jnz	34FAh

l0800_34D9:
	push	0Fh
	call	09C2h
	cmp	byte ptr [53DCh],0h
	jbe	34F2h

l0800_34E5:
	call	far 0C74h:542Bh
	or	al,al
	jz	34F2h

l0800_34EE:
	dec	byte ptr [53DCh]

l0800_34F2:
	push	6h
	call	09C2h
	jmp	35FAh

l0800_34FA:
	cmp	al,3Dh
	jnz	351Fh

l0800_34FE:
	push	10h
	call	09C2h
	cmp	byte ptr [53DEh],0h
	jbe	3517h

l0800_350A:
	call	far 0C74h:5258h
	or	al,al
	jz	3517h

l0800_3513:
	dec	byte ptr [53DEh]

l0800_3517:
	push	7h
	call	09C2h
	jmp	35FAh

l0800_351F:
	cmp	al,1Bh
	jnz	352Ch

l0800_3523:
	call	0103h
	jmp	36E4h
0800:3529                            E9 CE 00                      ...    

l0800_352C:
	cmp	al,20h
	jnz	356Dh

l0800_3530:
	mov	ax,[58D8h]
	mov	dx,[58DAh]
	mov	[58D0h],ax
	mov	[58D2h],dx
	call	0103h
	push	0Bh
	call	09C2h

l0800_3546:
	call	far 1E78h:02FBh
	or	al,al
	jnz	355Ah

l0800_354F:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	3546h

l0800_355A:
	push	2h
	call	09C2h
	push	word ptr [58D2h]
	push	word ptr [58D0h]
	call	00C1h
	jmp	35FAh

l0800_356D:
	cmp	al,44h
	jnz	3586h

l0800_3571:
	cmp	byte ptr [58B0h],0h
	jz	357Fh

l0800_3578:
	mov	byte ptr [58B0h],0h
	jmp	3584h

l0800_357F:
	mov	byte ptr [58B0h],1h

l0800_3584:
	jmp	35FAh

l0800_3586:
	cmp	al,48h
	jnz	359Bh

l0800_358A:
	push	9h
	call	09C2h
	call	far 0C74h:51AAh
	push	0h
	call	09C2h
	jmp	35FAh

l0800_359B:
	cmp	al,4Bh
	jnz	35C1h

l0800_359F:
	push	0Ah
	call	09C2h
	call	far 0C74h:54F0h
	or	al,al
	jnz	35BAh

l0800_35AD:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_35BA:
	push	1h
	call	09C2h
	jmp	35FAh

l0800_35C1:
	cmp	al,4Dh
	jnz	35E7h

l0800_35C5:
	push	0Ch
	call	09C2h
	call	far 0C74h:54B1h
	or	al,al
	jnz	35E0h

l0800_35D3:
	push	0Eh
	call	09C2h
	call	08C0h
	push	5h
	call	09C2h

l0800_35E0:
	push	3h
	call	09C2h
	jmp	35FAh

l0800_35E7:
	cmp	al,50h
	jnz	35FAh

l0800_35EB:
	push	0Dh
	call	09C2h
	call	far 0C74h:51B2h
	push	4h
	call	09C2h

l0800_35FA:
	mov	al,[53D2h]
	push	ax
	mov	di,316Fh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	364Ah

l0800_360A:
	mov	dl,[53D2h]
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	mov	[bp+di+0FDFCh],dl
	cmp	byte ptr [bp-1h],0FFh
	jnc	3622h

l0800_361F:
	inc	byte ptr [bp-1h]

l0800_3622:
	mov	al,[53D2h]
	push	ax
	mov	di,318Fh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	364Ah

l0800_3632:
	mov	dl,[58BCh]
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	mov	[bp+di+0FDFCh],dl
	cmp	byte ptr [bp-1h],0FFh
	jnc	364Ah

l0800_3647:
	inc	byte ptr [bp-1h]

l0800_364A:
	call	0C71h
	call	0877h
	or	al,al
	jnz	365Eh

l0800_3654:
	cmp	byte ptr [58B3h],0h
	jnz	365Eh

l0800_365B:
	jmp	345Eh

l0800_365E:
	call	0877h
	or	al,al
	jz	36C9h

l0800_3665:
	lea	di,[bp+0FD7Ch]
	push	ss
	push	di
	mov	di,31AFh
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FD7Ch]
	push	ss
	push	di
	push	100h
	call	far 1EDAh:0FD0h
	call	far 1EDAh:04A9h
	lea	di,[bp+0FD7Ch]
	push	ss
	push	di
	push	word ptr [5990h]
	push	word ptr [598Eh]
	call	far 1EDAh:1123h
	call	far 1EDAh:04A9h
	lea	di,[bp+0FD7Ch]
	push	ss
	push	di
	lea	di,[bp+0FDFCh]
	push	ss
	push	di
	call	far 1EDAh:108Ch
	add	sp,4h
	call	far 1EDAh:04A9h
	lea	di,[bp+0FD7Ch]
	push	ss
	push	di
	call	far 1EDAh:1051h
	call	far 1EDAh:04A9h

l0800_36C9:
	call	0103h
	call	0768h

l0800_36CF:
	call	far 1E78h:02FBh
	or	al,al
	jz	36DFh

l0800_36D8:
	call	far 1E78h:030Dh
	jmp	36CFh

l0800_36DF:
	call	far 1206h:0066h

l0800_36E4:
	leave
	ret

;; fn0800_36E6: 0800:36E6
;;   Called from:
;;     0800:39A3 (in fn0800_391E)
fn0800_36E6 proc
	push	bp
	mov	bp,sp
	push	1h
	push	3h
	call	far 1AB8h:1175h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:1B3Eh
	push	8h
	call	far 1AB8h:1C32h
	mov	ax,[bp+0Ah]
	sub	ax,3h
	push	ax
	push	word ptr [bp+8h]
	mov	ax,[bp+6h]
	add	ax,3h
	push	ax
	push	word ptr [bp+8h]
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp+6h]
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	sub	ax,3h
	push	ax
	push	word ptr [bp+8h]
	mov	ax,[bp+0Ah]
	sub	ax,3h
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	push	word ptr [bp+4h]
	call	far 1AB8h:1AF6h
	push	0Bh
	call	far 1AB8h:1C32h
	mov	ax,[bp+6h]
	add	ax,3h
	push	ax
	push	word ptr [bp+8h]
	mov	ax,[bp+6h]
	add	ax,3h
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+6h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp+4h]
	call	far 1AB8h:1AF6h
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+4h]
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+4h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:1AF6h
	leave
	ret	8h

;; fn0800_3850: 0800:3850
;;   Called from:
;;     0800:3B32 (in fn0800_391E)
fn0800_3850 proc
	enter	0Ah,0h

l0800_3854:
	lea	di,[bp-4h]
	push	ss
	push	di
	lea	di,[bp-6h]
	push	ss
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	call	far 1206h:0094h
	cmp	word ptr [bp-4h],0h
	jnz	3854h

l0800_386E:
	mov	byte ptr [bp-1h],0h
	mov	byte ptr [bp-9h],1h
	jmp	387Bh

l0800_3878:
	inc	byte ptr [bp-9h]

l0800_387B:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53E2h]
	cmp	ax,[bp-6h]
	jge	38D3h

l0800_388D:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53FEh]
	cmp	ax,[bp-6h]
	jle	38D3h

l0800_389F:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53F0h]
	cmp	ax,[bp-8h]
	jge	38D3h

l0800_38B1:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+540Ch]
	cmp	ax,[bp-8h]
	jle	38D3h

l0800_38C3:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D07h]
	mov	[bp-1h],al
	jmp	38D9h

l0800_38D3:
	cmp	byte ptr [bp-9h],2h
	jnz	3878h

l0800_38D9:
	mov	al,[bp-1h]
	leave
	ret	2h
0800:38E0 07 52 41 44 2E 44 4F 43 0B 20 53 20 3A 20 53 55 .RAD.DOC. S : SU
0800:38F0 49 54 45 20 09 20 46 20 3A 20 46 49 4E 20 00 00 ITE . F : FIN ..
0800:3900 00 00 00 00 00 00 40 00 08 00 00 00 00 00 00 00 ......@.........
0800:3910 00 00 00 00 00 00 00 00 00 00 00 00 00 00       ..............  

;; fn0800_391E: 0800:391E
;;   Called from:
;;     0800:4129 (in fn0800_3D9D)
fn0800_391E proc
	enter	210h,0h
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	mov	di,38E0h
	push	cs
	push	di
	call	far 1EDAh:04F5h
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	call	far 1EDAh:0565h
	call	far 1EDAh:04A2h
	or	ax,ax
	jz	3949h

l0800_3946:
	jmp	3BF0h

l0800_3949:
	call	far 1E78h:02FBh
	or	al,al
	jz	3959h

l0800_3952:
	call	far 1E78h:030Dh
	jmp	3949h

l0800_3959:
	mov	word ptr [bp-2h],2Ah
	mov	word ptr [bp-6h],14h
	call	far 1AB8h:10CEh
	sub	ax,2Ah
	mov	[bp-4h],ax
	mov	word ptr [bp-8h],16Ah
	call	far 1206h:0066h
	push	word ptr [bp-2h]
	push	word ptr [bp-6h]
	push	word ptr [bp-4h]
	push	word ptr [bp-8h]
	call	1315h
	mov	ax,[bp-2h]
	add	ax,8h
	push	ax
	mov	ax,[bp-6h]
	add	ax,0Ah
	push	ax
	mov	ax,[bp-4h]
	sub	ax,8h
	push	ax
	mov	ax,[bp-8h]
	sub	ax,32h
	push	ax
	call	36E6h
	push	1h
	push	7h
	call	far 1AB8h:1175h
	mov	ax,[bp-2h]
	add	ax,8h
	push	ax
	mov	ax,[bp-6h]
	add	ax,0Dh
	push	ax
	mov	ax,[bp-4h]
	sub	ax,9h
	push	ax
	mov	ax,[bp-8h]
	sub	ax,34h
	push	ax
	call	far 1AB8h:1B3Eh
	mov	ax,[bp-2h]
	add	ax,30h
	mov	[bp-0Ah],ax
	mov	ax,[bp-6h]
	add	ax,0Ch
	mov	[bp-0Ch],ax
	push	1h
	push	0F0h
	push	14Eh
	mov	di,38E8h
	push	cs
	push	di
	push	0h
	call	19E1h
	push	2h
	push	190h
	push	14Eh
	mov	di,38F4h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_3A06:
	call	far 1206h:0066h
	push	1h
	push	7h
	call	far 1AB8h:1175h
	mov	ax,[bp-2h]
	add	ax,8h
	push	ax
	mov	ax,[bp-6h]
	add	ax,0Dh
	push	ax
	mov	ax,[bp-4h]
	sub	ax,9h
	push	ax
	mov	ax,[bp-8h]
	sub	ax,34h
	push	ax
	call	far 1AB8h:1B3Eh
	mov	al,[4D06h]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1C32h
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	push	2h
	push	0h
	push	4h
	call	far 1AB8h:1536h
	mov	byte ptr [bp-0Fh],1h
	jmp	3A5Dh

l0800_3A5A:
	inc	byte ptr [bp-0Fh]

l0800_3A5D:
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	lea	di,[bp+0FDF0h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0896h
	call	far 1EDAh:081Ah
	call	far 1EDAh:04A9h
	push	word ptr [bp-0Ah]
	mov	al,[bp-0Fh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-0Ch]
	push	ax
	lea	di,[bp+0FDF0h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	cmp	byte ptr [bp-0Fh],14h
	jnz	3A5Ah

l0800_3A9B:
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	call	far 1EDAh:0918h
	call	far 1EDAh:04A9h
	or	al,al
	jz	3AD3h

l0800_3AAF:
	mov	ax,[53E4h]
	sub	ax,4h
	push	ax
	mov	ax,[53F2h]
	dec	ax
	push	ax
	mov	ax,[5400h]
	add	ax,4h
	push	ax
	mov	ax,[540Eh]
	add	ax,3h
	push	ax
	call	005Ah
	call	far 1206h:0038h
	jmp	3AE5h

l0800_3AD3:
	push	1h
	push	0F0h
	push	14Eh
	mov	di,38E8h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_3AE5:
	mov	byte ptr [53D2h],0FFh
	call	far 1E78h:02FBh
	or	al,al
	jz	3B26h

l0800_3AF3:
	call	far 1E78h:030Dh
	mov	[53D2h],al
	cmp	byte ptr [53D2h],0h
	jnz	3B0Ah

l0800_3B02:
	call	far 1E78h:030Dh
	mov	[53D2h],al

l0800_3B0A:
	call	far 1E78h:02FBh
	or	al,al
	jz	3B1Ah

l0800_3B13:
	call	far 1E78h:030Dh
	jmp	3B0Ah

l0800_3B1A:
	mov	al,[53D2h]
	push	ax
	call	far 1EDAh:1384h
	mov	[53D2h],al

l0800_3B26:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	3B38h

l0800_3B31:
	push	bp
	call	3850h
	mov	[53D2h],al

l0800_3B38:
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	call	far 1EDAh:0918h
	call	far 1EDAh:04A9h
	or	al,al
	jz	3B58h

l0800_3B4C:
	cmp	byte ptr [53D2h],53h
	jnz	3B58h

l0800_3B53:
	mov	byte ptr [53D2h],0h

l0800_3B58:
	mov	al,[53D2h]
	push	ax
	mov	di,38FEh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	3B6Bh

l0800_3B68:
	jmp	3AE5h

l0800_3B6B:
	cmp	byte ptr [53D2h],53h
	jnz	3B84h

l0800_3B72:
	push	1h
	push	0F0h
	push	14Eh
	mov	di,38E8h
	push	cs
	push	di
	push	1h
	call	19E1h

l0800_3B84:
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	call	far 1EDAh:0918h
	call	far 1EDAh:04A9h
	or	al,al
	jnz	3BA2h

l0800_3B98:
	cmp	byte ptr [53D2h],46h
	jz	3BA2h

l0800_3B9F:
	jmp	3A06h

l0800_3BA2:
	push	2h
	push	190h
	push	14Eh
	mov	di,38F4h
	push	cs
	push	di
	push	1h
	call	19E1h
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	call	far 1EDAh:05BFh
	call	far 1EDAh:04A9h
	call	far 1206h:0066h
	push	96h
	call	far 1E78h:029Ch
	mov	ax,[bp-2h]
	sub	ax,14h
	push	ax
	mov	ax,[bp-6h]
	sub	ax,0Ch
	push	ax
	mov	ax,[bp-4h]
	add	ax,4h
	push	ax
	mov	ax,[bp-8h]
	add	ax,4h
	push	ax
	call	0024h

l0800_3BF0:
	leave
	ret

;; fn0800_3BF2: 0800:3BF2
;;   Called from:
;;     0800:3D14 (in fn0800_3CFA)
fn0800_3BF2 proc
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	push	es
	push	di
	les	di,[bp+6h]
	add	di,2h
	push	es
	push	di
	les	di,[bp+6h]
	add	di,4h
	push	es
	push	di
	les	di,[bp+6h]
	add	di,6h
	push	es
	push	di
	call	far 1E5Fh:00A2h
	les	di,[bp+6h]
	mov	ax,es:[di]
	xor	dx,dx
	mov	cx,7E40h
	mov	bx,5h
	call	far 1EDAh:096Fh
	mov	cx,ax
	mov	bx,dx
	les	di,[bp+6h]
	imul	ax,es:[di+2h],1770h
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	mov	cx,ax
	mov	bx,dx
	les	di,[bp+6h]
	imul	ax,es:[di+4h],64h
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	mov	cx,ax
	mov	bx,dx
	les	di,[bp+6h]
	mov	ax,es:[di+6h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	les	di,[bp+6h]
	mov	es:[di+8h],ax
	mov	es:[di+0Ah],dx
	leave
	retf	4h

;; fn0800_3C72: 0800:3C72
;;   Called from:
;;     0800:3D2B (in fn0800_3CFA)
fn0800_3C72 proc
	enter	0Ch,0h
	lea	di,[bp-6h]
	push	ss
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	lea	di,[bp-0Ah]
	push	ss
	push	di
	lea	di,[bp-0Ch]
	push	ss
	push	di
	call	far 1E5Fh:00A2h
	mov	ax,[bp-6h]
	xor	dx,dx
	mov	cx,7E40h
	mov	bx,5h
	call	far 1EDAh:096Fh
	mov	cx,ax
	mov	bx,dx
	imul	ax,[bp-8h],1770h
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	mov	cx,ax
	mov	bx,dx
	imul	ax,[bp-0Ah],64h
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp-0Ch]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	les	di,[bp+6h]
	mov	es:[di+0Ch],ax
	mov	es:[di+0Eh],dx
	les	di,[bp+6h]
	mov	ax,es:[di+0Ch]
	mov	dx,es:[di+0Eh]
	les	di,[bp+6h]
	sub	ax,es:[di+8h]
	sbb	dx,es:[di+0Ah]
	mov	[bp-4h],ax
	mov	[bp-2h],dx
	mov	ax,[bp-4h]
	mov	dx,[bp-2h]
	leave
	retf	4h

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

;; fn0800_3D9D: 0800:3D9D
;;   Called from:
;;     0800:4423 (in fn0800_4255)
fn0800_3D9D proc
	enter	106h,0h
	call	far 1206h:0066h
	call	far 13E2h:003Bh
	call	far 1AB8h:0F80h
	cmp	byte ptr [53DFh],0h
	jnz	3DBAh

l0800_3DB7:
	call	3CFAh

l0800_3DBA:
	call	far 13E2h:0080h
	call	21E7h
	push	7h
	call	far 1AB8h:1C32h
	push	1h
	push	0h
	push	2h
	call	far 1AB8h:1536h
	call	far 1206h:0066h
	push	140h
	push	1CEh
	mov	di,3D5Ah
	push	cs
	push	di
	call	far 1AB8h:1D82h
	push	2h
	push	0h
	push	0h
	push	0h
	call	far 1AB8h:1CBAh
	push	2h
	push	2h
	call	far 1AB8h:1342h
	push	2h
	call	far 1AB8h:1C32h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	6Ah
	push	16Dh
	push	203h
	push	1C9h
	call	far 1AB8h:112Eh
	push	79h
	push	19Bh
	call	far 0C74h:06B7h
	push	9Ch
	push	14h
	push	1E0h
	push	16Ah
	push	140h
	push	0B4h
	call	far 1206h:01ACh
	call	far 1206h:0038h

l0800_3E46:
	mov	byte ptr [58E0h],0h
	mov	byte ptr [bp-1h],0FFh
	call	far 1E78h:02FBh
	or	al,al
	jnz	3E64h

l0800_3E58:
	cmp	byte ptr [58E0h],0h
	jnz	3E64h

l0800_3E5F:
	call	far 0C74h:54B1h

l0800_3E64:
	call	far 1E78h:02FBh
	or	al,al
	jnz	3E79h

l0800_3E6D:
	cmp	byte ptr [58E0h],0h
	jnz	3E79h

l0800_3E74:
	call	far 0C74h:54B1h

l0800_3E79:
	call	far 1E78h:02FBh
	or	al,al
	jnz	3E8Eh

l0800_3E82:
	cmp	byte ptr [58E0h],0h
	jnz	3E8Eh

l0800_3E89:
	call	far 0C74h:54F0h

l0800_3E8E:
	call	far 1E78h:02FBh
	or	al,al
	jnz	3EA3h

l0800_3E97:
	cmp	byte ptr [58E0h],0h
	jnz	3EA3h

l0800_3E9E:
	call	far 0C74h:54F0h

l0800_3EA3:
	call	far 1E78h:02FBh
	or	al,al
	jz	3ED2h

l0800_3EAC:
	call	far 1E78h:030Dh
	mov	[bp-1h],al
	cmp	byte ptr [bp-1h],0h
	jnz	3EC2h

l0800_3EBA:
	call	far 1E78h:030Dh
	mov	[bp-1h],al

l0800_3EC2:
	call	far 1E78h:02FBh
	or	al,al
	jz	3ED2h

l0800_3ECB:
	call	far 1E78h:030Dh
	jmp	3EC2h

l0800_3ED2:
	cmp	byte ptr [58E0h],0h
	jz	3EDFh

l0800_3ED9:
	call	1D55h
	mov	[bp-1h],al

l0800_3EDF:
	mov	al,[bp-1h]
	cmp	al,21h
	jnz	3F01h

l0800_3EE6:
	call	far 1206h:0066h
	call	184Ch
	mov	byte ptr [58B2h],0h
	call	2827h
	mov	byte ptr [58B2h],1h
	jmp	415Eh
0800:3EFE                                           E9 33               .3
0800:3F00 02                                              .               

l0800_3F01:
	cmp	al,3Bh
	jnz	3F2Fh

l0800_3F05:
	push	1h
	push	word ptr [541Ch]
	push	word ptr [542Ah]
	mov	di,5438h
	push	ds
	push	di
	push	1h
	call	19E1h
	call	far 0C74h:51AAh
	call	far 1206h:0066h
	call	184Ch
	call	2C0Ch
	jmp	415Eh
0800:3F2C                                     E9 05 02                ... 

l0800_3F2F:
	cmp	al,3Ch
	jz	3F36h

l0800_3F33:
	jmp	3FE3h

l0800_3F36:
	push	2h
	push	word ptr [541Eh]
	push	word ptr [542Ch]
	mov	di,5452h
	push	ds
	push	di
	push	1h
	call	19E1h
	call	11EFh
	push	2h
	push	word ptr [541Eh]
	push	word ptr [542Ch]
	mov	di,5452h
	push	ds
	push	di
	push	0h
	call	19E1h
	push	1h
	push	3h
	call	far 1AB8h:1175h
	mov	ax,[53E4h]
	sub	ax,4h
	push	ax
	mov	ax,[53F2h]
	dec	ax
	push	ax
	mov	ax,[5400h]
	add	ax,4h
	push	ax
	mov	ax,[540Eh]
	add	ax,3h
	push	ax
	call	far 1AB8h:1B3Eh
	cmp	word ptr [5990h],0h
	jnz	3F97h

l0800_3F90:
	cmp	word ptr [598Eh],1h
	jz	3FCCh

l0800_3F97:
	push	1h
	push	word ptr [541Ch]
	push	word ptr [542Ah]
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	mov	di,3D7Fh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,5ED6h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,3D83h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	0h
	call	19E1h
	jmp	3FE0h

l0800_3FCC:
	push	1h
	push	word ptr [541Ch]
	push	word ptr [542Ah]
	mov	di,3D85h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_3FE0:
	jmp	4134h

l0800_3FE3:
	cmp	al,3Dh
	jnz	4023h

l0800_3FE7:
	push	3h
	push	word ptr [5420h]
	push	word ptr [542Eh]
	mov	di,546Ch
	push	ds
	push	di
	push	1h
	call	19E1h
	xor	ax,ax
	mov	[598Eh],ax
	mov	[5990h],ax
	call	far 1206h:0066h
	call	149Fh
	call	184Ch
	call	2C0Ch
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	jmp	415Eh
0800:4020 E9 11 01                                        ...             

l0800_4023:
	cmp	al,3Eh
	jnz	4065h

l0800_4027:
	cmp	byte ptr [58B0h],0h
	jz	4049h

l0800_402E:
	mov	byte ptr [58B0h],0h
	push	4h
	push	word ptr [5422h]
	push	word ptr [5430h]
	mov	di,5486h
	push	ds
	push	di
	push	1h
	call	19E1h
	jmp	4062h

l0800_4049:
	mov	byte ptr [58B0h],1h
	push	4h
	push	word ptr [5422h]
	push	word ptr [5430h]
	mov	di,5486h
	push	ds
	push	di
	push	0h
	call	19E1h

l0800_4062:
	jmp	4134h

l0800_4065:
	cmp	al,3Fh
	jz	406Ch

l0800_4069:
	jmp	4105h

l0800_406C:
	push	5h
	push	word ptr [5424h]
	push	word ptr [5432h]
	mov	di,54A0h
	push	ds
	push	di
	push	1h
	call	19E1h
	call	far 1206h:0066h
	push	64h
	call	far 1E78h:029Ch
	cmp	byte ptr [0002h],1Eh
	jbe	40F8h

l0800_4093:
	push	2h
	push	0h
	push	2Ah
	push	0h
	call	far 1AB8h:1CBAh
	push	2h
	push	2h
	call	far 1AB8h:1342h
	call	far 1206h:0066h
	push	8h
	push	0h
	call	far 1AB8h:1342h
	mov	di,5ED6h
	push	ds
	push	di
	mov	di,3D91h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	40D9h

l0800_40C8:
	mov	di,3D96h
	push	cs
	push	di
	mov	di,5ED6h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h

l0800_40D9:
	mov	di,5ED6h
	push	ds
	push	di
	call	far 1229h:0DCCh
	cmp	byte ptr [5CB3h],0h
	jnz	40EDh

l0800_40EA:
	call	31B7h

l0800_40ED:
	cmp	byte ptr [5CB3h],0h
	jz	4093h

l0800_40F4:
	jmp	415Eh
0800:40F6                   EB 03                               ..        

l0800_40F8:
	call	2004h
	call	21E7h
	call	far 1206h:0038h
	jmp	4134h

l0800_4105:
	cmp	al,40h
	jnz	4134h

l0800_4109:
	push	6h
	push	word ptr [5426h]
	push	word ptr [5434h]
	mov	di,54BAh
	push	ds
	push	di
	push	1h
	call	19E1h
	push	64h
	call	far 1E78h:029Ch
	call	far 1206h:0066h
	call	391Eh
	call	21E7h
	call	far 1206h:0038h

l0800_4134:
	cmp	byte ptr [bp-1h],41h
	jz	413Dh

l0800_413A:
	jmp	3E46h

l0800_413D:
	push	7h
	push	word ptr [5428h]
	push	word ptr [5436h]
	mov	di,54D4h
	push	ds
	push	di
	push	1h
	call	19E1h
	call	far 0C74h:0A35h
	call	far 1206h:0066h
	call	0000h

l0800_415E:
	leave
	ret
0800:4160 07 52 41 44 2E 44 41 54                         .RAD.DAT        

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

;; fn0800_4255: 0800:4255
fn0800_4255 proc
	call	far 1EDAh:0000h
	call	far 1E78h:0000h
	call	far 1AB8h:17AEh
	call	far 13E2h:0220h
	call	far 13C8h:0139h
	call	far 13C1h:0067h
	call	far 133Fh:0816h
	call	far 1206h:0217h
	call	far 11C8h:03CFh
	call	far 0C74h:552Fh
	call	far 0C43h:02FBh
	enter	200h,0h
	mov	di,41C7h
	push	cs
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	1h
	call	far 1EDAh:1216h
	call	far 1EDAh:0AD8h
	or	ax,ax
	jnz	42C6h

l0800_42AB:
	mov	di,41C9h
	push	cs
	push	di
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	push	1h
	call	far 1EDAh:1216h
	call	far 1EDAh:0AD8h
	or	ax,ax
	jz	42CBh

l0800_42C6:
	call	far 11C8h:0394h

l0800_42CB:
	mov	word ptr [58E6h],7h
	mov	byte ptr [53DFh],0h
	call	far 1EDAh:1265h
	mov	[bp-2h],ax
	mov	ax,1h
	cmp	ax,[bp-2h]
	ja	4335h

l0800_42E6:
	mov	[53D6h],ax
	jmp	42EFh

l0800_42EB:
	inc	word ptr [53D6h]

l0800_42EF:
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	push	word ptr [53D6h]
	call	far 1EDAh:1216h
	mov	di,53D4h
	push	ds
	push	di
	call	far 1EDAh:0F71h
	mov	[53DFh],al
	cmp	word ptr [53D4h],0h
	jnz	432Dh

l0800_4312:
	mov	al,[53DFh]
	push	ax
	mov	di,41CBh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	432Dh

l0800_4322:
	mov	al,[53DFh]
	xor	ah,ah
	imul	ax,ax,7h
	mov	[58E6h],ax

l0800_432D:
	mov	ax,[53D6h]
	cmp	ax,[bp-2h]
	jnz	42EBh

l0800_4335:
	mov	di,41EBh
	push	cs
	push	di
	call	far 0C43h:00B9h
	call	far 1E78h:030Dh

l0800_4344:
	call	far 1E78h:02FBh
	or	al,al
	jz	4354h

l0800_434D:
	call	far 1E78h:030Dh
	jmp	4344h

l0800_4354:
	call	far 13E2h:0001h
	or	al,al
	jnz	4367h

l0800_435D:
	mov	di,41F3h
	push	cs
	push	di
	call	far 13E2h:0193h

l0800_4367:
	call	far 1EDAh:0E07h
	mov	byte ptr [58BEh],0h
	call	far 13E2h:003Bh
	push	0h
	mov	di,550Eh
	push	ds
	push	di
	push	4Fh
	call	far 1EDAh:129Eh
	mov	al,[550Fh]
	push	ax
	mov	di,421Eh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	43D7h

l0800_4394:
	push	0Fh
	push	3Fh
	push	3Fh
	push	3Fh
	call	far 1AB8h:1CBAh
	push	0Fh
	push	0Fh
	call	far 1AB8h:1342h
	push	1h
	push	0h
	push	4h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	push	ax
	push	1BAh
	mov	di,423Eh
	push	cs
	push	di
	call	far 1AB8h:1D82h

l0800_43D7:
	xor	ax,ax
	mov	[58E2h],ax
	push	1h
	push	0Fh
	call	far 1AB8h:1175h
	mov	byte ptr [58B0h],1h
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	call	far 0C74h:03D4h
	call	03F8h
	call	4168h
	push	1h
	push	16h
	call	04CCh
	push	ax
	call	far 1206h:00FFh
	push	1B0h
	push	1D1h
	call	far 1206h:012Dh
	push	64h
	push	1C2h
	call	far 1206h:00D1h

l0800_4423:
	call	3D9Dh
	jmp	4423h
0800:4428                         C9 31 C0 9A E9 00 DA 1E         .1......
