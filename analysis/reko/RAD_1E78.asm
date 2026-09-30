;;; Segment 1E78 (1E78:0000)

;; fn1E78_0000: 1E78:0000
;;   Called from:
;;     0800:425A (in fn0800_4255)
fn1E78_0000 proc
	push	bp
	mov	bp,sp
	call	002Eh
	mov	di,0B8BCh
	push	ds
	push	di
	push	cs
	call	032Fh
	mov	di,0B8BCh
	push	ds
	push	di
	call	far 1EDAh:0565h
	mov	di,0B9BCh
	push	ds
	push	di
	push	cs
	call	032Fh
	mov	di,0B9BCh
	push	ds
	push	di
	call	far 1EDAh:056Ah
	pop	bp
	retf

;; fn1E78_002E: 1E78:002E
;;   Called from:
;;     1E78:0003 (in fn1E78_0000)
fn1E78_002E proc
	mov	ah,0Fh
	call	0609h
	cmp	al,7h
	jz	0041h

l1E78_0037:
	cmp	al,3h
	jbe	0041h

l1E78_003B:
	mov	ax,3h
	call	0097h

l1E78_0041:
	call	00E5h
	mov	ah,8h
	xor	bh,bh
	call	0609h
	mov	al,ah
	and	al,7Fh
	mov	[0B8B8h],al
	mov	[0B8AEh],al
	xor	ax,ax
	mov	[0B8A9h],al
	mov	[0B8B9h],al
	mov	[0B8BAh],al
	inc	ax
	mov	[0B8A8h],al
	mov	ax,40h
	mov	es,ax
	mov	di,6Ch
	mov	al,es:[di]

l1E78_006F:
	cmp	al,es:[di]
	jz	006Fh

l1E78_0074:
	mov	al,es:[di]
	mov	cx,0FFFFh
	call	02BFh
	mov	ax,37h
	xchg	cx,ax
	not	ax
	xor	dx,dx
	div	cx
	mov	[0B8B4h],ax
	push	ds
	push	cs
	pop	ds
	mov	dx,12Dh
	mov	ax,251Bh
	int	21h
	pop	ds
	ret

;; fn1E78_0097: 1E78:0097
;;   Called from:
;;     1E78:003E (in fn1E78_002E)
;;     1E78:0171 (in fn1E78_016B)
fn1E78_0097 proc
	mov	dx,40h
	mov	es,dx
	and	byte ptr es:[0087h],0FEh
	cmp	al,7h
	jz	00ACh

l1E78_00A6:
	cmp	al,4h
	jc	00ACh

l1E78_00AA:
	mov	al,3h

l1E78_00AC:
	push	ax
	mov	ah,0h
	call	0609h
	pop	ax
	or	ah,ah
	jz	00E4h

l1E78_00B7:
	mov	ax,1112h
	mov	bl,0h
	call	0609h
	mov	ax,1130h
	mov	bh,0h
	mov	dl,0h
	call	0609h
	cmp	dl,2Ah
	jnz	00E4h

l1E78_00CE:
	or	byte ptr es:[0087h],1h
	mov	ax,100h
	mov	cx,600h
	call	0609h
	mov	ah,12h
	mov	bl,20h
	call	0609h

l1E78_00E4:
	ret

;; fn1E78_00E5: 1E78:00E5
;;   Called from:
;;     1E78:0041 (in fn1E78_002E)
;;     1E78:0174 (in fn1E78_016B)
fn1E78_00E5 proc
	mov	ah,0Fh
	call	0609h
	push	ax
	mov	ax,1130h
	mov	bh,0h
	mov	dl,0h
	call	0609h
	pop	ax
	mov	cl,0h
	or	dl,dl
	jnz	0104h

l1E78_00FC:
	mov	dl,18h
	cmp	al,3h
	ja	0104h

l1E78_0102:
	mov	cl,1h

l1E78_0104:
	mov	dh,dl
	mov	dl,ah
	dec	dl
	mov	ah,0h
	cmp	dh,18h
	jbe	0113h

l1E78_0111:
	mov	ah,1h

l1E78_0113:
	mov	[0B8ACh],ax
	mov	[0B8B6h],dx
	mov	[0B8ABh],cl
	mov	byte ptr [0B8AAh],1h
	xor	ax,ax
	mov	[0B8B0h],ax
	mov	[0B8B2h],dx
	ret
1E78:012D                                        50 1E B8              P..
1E78:0130 14 20 8E D8 80 3E A8 B8 00 74 05 C6 06 BA B8 01 . ...>...t......
1E78:0140 1F 58 CF                                        .X.             

;; fn1E78_0143: 1E78:0143
;;   Called from:
;;     1E78:032B (in fn1E78_030D)
fn1E78_0143 proc
	cmp	byte ptr [0B8BAh],0h
	jnz	014Bh

l1E78_014A:
	ret

l1E78_014B:
	mov	byte ptr [0B8BAh],0h

l1E78_0150:
	mov	ah,1h
	int	16h
	jz	015Ch

l1E78_0156:
	mov	ah,0h
	int	16h
	jmp	0150h

l1E78_015C:
	mov	al,5Eh
	call	047Ch
	mov	al,43h
	call	047Ch
	call	0475h
	int	23h

;; fn1E78_016B: 1E78:016B
;;   Called from:
;;     0800:0011 (in fn0800_0000)
;;     0800:2CAE (in fn0800_2C0C)
;;     0C74:03F3 (in fn0C74_03D4)
;;     13E2:01B8 (in fn13E2_0193)
;;     1E78:0169 (in fn1E78_0143)
fn1E78_016B proc
	mov	bx,sp
	mov	ax,ss:[bx+4h]
	call	0097h
	call	00E5h
	mov	al,[0B8B8h]
	mov	[0B8AEh],al
	retf	2h
1E78:0180 8B DC 36 8A 57 0A 36 8A 77 08 36 8A 4F 06 36 8A ..6.W.6.w.6.O.6.
1E78:0190 6F 04 3A D1 77 27 3A F5 77 23 FE CA 78 1F FE CE o.:.w':.w#..x...
1E78:01A0 78 1B FE C9 3A 0E B6 B8 77 13 FE CD 3A 2E B7 B8 x...:...w...:...
1E78:01B0 77 0B 89 16 B0 B8 89 0E B2 B8 E8 40 03 CA 08 00 w..........@....

;; fn1E78_01C0: 1E78:01C0
;;   Called from:
;;     11C8:0096 (in fn11C8_0092)
fn1E78_01C0 proc
	mov	ax,600h
	mov	bh,[0B8AEh]
	mov	cx,[0B8B0h]
	mov	dx,[0B8B2h]
	call	0609h
	mov	dx,[0B8B0h]
	call	04FDh
	retf
1E78:01DA                               E8 19 03 B8 00 06           ......
1E78:01E0 8A 3E AE B8 8B CA 8A 16 B2 B8 E8 1C 04 CB B8 01 .>..............
1E78:01F0 07 EB 03 B8 01 06 50 E8 FC 02 58 8A 3E AE B8 8A ......P...X.>...
1E78:0200 0E B0 B8 8A EE 8B 16 B2 B8 3A EE 75 02 32 C0 E8 .........:.u.2..
1E78:0210 F7 03 CB 8B DC 36 8A 57 06 36 8A 77 04 FE CA 02 .....6.W.6.w....
1E78:0220 16 B0 B8 72 17 3A 16 B2 B8 77 11 FE CE 02 36 B1 ...r.:...w....6.
1E78:0230 B8 72 09 3A 36 B3 B8 77 03 E8 C1 02 CA 04 00 E8 .r.:6..w........
1E78:0240 B4 02 8A C2 2A 06 B0 B8 FE C0 CB E8 A8 02 8A C6 ....*...........
1E78:0250 2A 06 B1 B8 FE C0 CB 8B DC 36 8A 47 04 A8 F0 74 *........6.G...t
1E78:0260 04 24 0F 0C 80 80 26 AE B8 70 08 06 AE B8 CA 02 .$....&..p......
1E78:0270 00 8B DC 36 8A 47 04 24 07 B1 04 D2 E0 80 26 AE ...6.G.$......&.
1E78:0280 B8 8F 08 06 AE B8 CA 02 00 80 26 AE B8 F7 CB 80 ..........&.....
1E78:0290 0E AE B8 08 CB A0 B8 B8 A2 AE B8 CB             ............    

;; fn1E78_029C: 1E78:029C
;;   Called from:
;;     0800:15E8 (in fn0800_149F)
;;     0800:15FB (in fn0800_149F)
;;     0800:17CB (in fn0800_166D)
;;     0800:17DE (in fn0800_166D)
;;     0800:1F8F (in fn0800_1E3F)
;;     0800:214B (in fn0800_2004)
;;     0800:3BCC (in fn0800_391E)
;;     0800:4087 (in fn0800_3D9D)
;;     0800:411F (in fn0800_3D9D)
;;     0C74:02E6 (in fn0C74_02D8)
;;     0C74:0370 (in fn0C74_02D8)
;;     0C74:039E (in fn0C74_02D8)
;;     0C74:0854 (in fn0C74_076B)
;;     0C74:0B18 (in fn0C74_0A35)
;;     0C74:2CA2 (in fn0C74_2BBD)
;;     0C74:2D17 (in fn0C74_2BBD)
;;     0C74:31CA (in fn0C74_2E5A)
;;     0C74:35A9 (in fn0C74_3236)
;;     1229:04E8 (in fn1229_0486)
;;     1229:0E6D (in fn1229_0DCC)
fn1E78_029C proc
	mov	bx,sp
	mov	dx,ss:[bx+4h]
	or	dx,dx
	jz	02BCh

l1E78_02A6:
	mov	ax,40h
	mov	es,ax
	xor	di,di
	mov	al,es:[di]
	mov	bx,[0B8B4h]

l1E78_02B4:
	mov	cx,bx
	call	02BFh
	dec	dx
	jnz	02B4h

l1E78_02BC:
	retf	2h

;; fn1E78_02BF: 1E78:02BF
;;   Called from:
;;     1E78:007A (in fn1E78_002E)
;;     1E78:02B6 (in fn1E78_029C)
fn1E78_02BF proc
	cmp	al,es:[di]
	jnz	02C6h

l1E78_02C4:
	loop	02BFh

l1E78_02C6:
	ret

;; fn1E78_02C7: 1E78:02C7
;;   Called from:
;;     11C8:0361 (in fn11C8_0354)
;;     1229:04E0 (in fn1229_0486)
;;     1229:0E66 (in fn1229_0DCC)
fn1E78_02C7 proc
	mov	bx,sp
	mov	bx,ss:[bx+4h]
	mov	ax,34DDh
	mov	dx,12h
	cmp	dx,bx
	jnc	02F1h

l1E78_02D7:
	div	bx
	mov	bx,ax
	in	al,61h
	test	al,3h
	jnz	02E9h

l1E78_02E1:
	or	al,3h
	out	61h,al
	mov	al,0B6h
	out	43h,al

l1E78_02E9:
	mov	al,bl
	out	42h,al
	mov	al,bh
	out	42h,al

l1E78_02F1:
	retf	2h

;; fn1E78_02F4: 1E78:02F4
;;   Called from:
;;     11C8:0345 (in fn11C8_033B)
;;     1229:04ED (in fn1229_0486)
;;     1229:0E9D (in fn1229_0DCC)
fn1E78_02F4 proc
	in	al,61h
	and	al,0FCh
	out	61h,al
	retf

;; fn1E78_02FB: 1E78:02FB
;;   Called from:
;;     0800:07F2 (in fn0800_0768)
;;     0800:0840 (in fn0800_0768)
;;     0800:0852 (in fn0800_0768)
;;     0800:085E (in fn0800_0768)
;;     0800:08FF (in fn0800_08E9)
;;     0800:0F3D (in fn0800_0D20)
;;     0800:167B (in fn0800_166D)
;;     0800:1E43 (in fn0800_1E3F)
;;     0800:1F3A (in fn0800_1E3F)
;;     0800:1F4E (in fn0800_1E3F)
;;     0800:20FD (in fn0800_2004)
;;     0800:2111 (in fn0800_2004)
;;     0800:2416 (in fn0800_2401)
;;     0800:2505 (in fn0800_2401)
;;     0800:264E (in fn0800_2401)
;;     0800:265E (in fn0800_2401)
;;     0800:2672 (in fn0800_2401)
;;     0800:283C (in fn0800_2827)
;;     0800:297D (in fn0800_2827)
;;     0800:2C10 (in fn0800_2C0C)
;;     0800:2E1E (in fn0800_2C0C)
;;     0800:2E49 (in fn0800_2C0C)
;;     0800:2E71 (in fn0800_2C0C)
;;     0800:2E91 (in fn0800_2C0C)
;;     0800:2FD3 (in fn0800_2C0C)
;;     0800:30BB (in fn0800_2C0C)
;;     0800:31BB (in fn0800_31B7)
;;     0800:3433 (in fn0800_31B7)
;;     0800:345E (in fn0800_31B7)
;;     0800:3475 (in fn0800_31B7)
;;     0800:3495 (in fn0800_31B7)
;;     0800:3546 (in fn0800_31B7)
;;     0800:36CF (in fn0800_31B7)
;;     0800:3949 (in fn0800_391E)
;;     0800:3AEA (in fn0800_391E)
;;     0800:3B0A (in fn0800_391E)
;;     0800:3E4F (in fn0800_3D9D)
;;     0800:3E64 (in fn0800_3D9D)
;;     0800:3E79 (in fn0800_3D9D)
;;     0800:3E8E (in fn0800_3D9D)
;;     0800:3EA3 (in fn0800_3D9D)
;;     0800:3EC2 (in fn0800_3D9D)
;;     0800:4344 (in fn0800_4255)
;;     0C74:36E5 (in fn0C74_3615)
;;     0C74:3891 (in fn0C74_37C3)
;;     1229:01AC (in fn1229_0040)
;;     1229:05E8 (in fn1229_050A)
;;     1229:06B5 (in fn1229_061B)
;;     133F:054A (in fn133F_0528)
fn1E78_02FB proc
	cmp	byte ptr [0B8B9h],0h
	jnz	030Ah

l1E78_0302:
	mov	ah,1h
	int	16h
	mov	al,0h
	jz	030Ch

l1E78_030A:
	mov	al,1h

l1E78_030C:
	retf

;; fn1E78_030D: 1E78:030D
;;   Called from:
;;     0800:0867 (in fn0800_0768)
;;     0800:0908 (in fn0800_08E9)
;;     0800:0F78 (in fn0800_0D20)
;;     0800:0F8E (in fn0800_0D20)
;;     0800:1609 (in fn0800_149F)
;;     0800:1684 (in fn0800_166D)
;;     0800:17EC (in fn0800_166D)
;;     0800:1E4C (in fn0800_1E3F)
;;     0800:1F57 (in fn0800_1E3F)
;;     0800:211A (in fn0800_2004)
;;     0800:241F (in fn0800_2401)
;;     0800:2657 (in fn0800_2401)
;;     0800:267B (in fn0800_2401)
;;     0800:2845 (in fn0800_2827)
;;     0800:2C19 (in fn0800_2C0C)
;;     0800:2D1F (in fn0800_2C0C)
;;     0800:2E7A (in fn0800_2C0C)
;;     0800:2E89 (in fn0800_2C0C)
;;     0800:2E9A (in fn0800_2C0C)
;;     0800:30C4 (in fn0800_2C0C)
;;     0800:31C4 (in fn0800_31B7)
;;     0800:347E (in fn0800_31B7)
;;     0800:348D (in fn0800_31B7)
;;     0800:349E (in fn0800_31B7)
;;     0800:36D8 (in fn0800_31B7)
;;     0800:3952 (in fn0800_391E)
;;     0800:3AF3 (in fn0800_391E)
;;     0800:3B02 (in fn0800_391E)
;;     0800:3B13 (in fn0800_391E)
;;     0800:3EAC (in fn0800_3D9D)
;;     0800:3EBA (in fn0800_3D9D)
;;     0800:3ECB (in fn0800_3D9D)
;;     0800:433F (in fn0800_4255)
;;     0800:434D (in fn0800_4255)
;;     1229:01E7 (in fn1229_0040)
;;     133F:0556 (in fn133F_0528)
;;     133F:05A2 (in fn133F_0528)
fn1E78_030D proc
	mov	al,[0B8B9h]
	mov	byte ptr [0B8B9h],0h
	or	al,al
	jnz	032Bh

l1E78_0319:
	xor	ah,ah
	int	16h
	or	al,al
	jnz	032Bh

l1E78_0321:
	mov	[0B8B9h],ah
	or	ah,ah
	jnz	032Bh

l1E78_0329:
	mov	al,3h

l1E78_032B:
	call	0143h
	retf

;; fn1E78_032F: 1E78:032F
;;   Called from:
;;     1E78:000B (in fn1E78_0000)
;;     1E78:001E (in fn1E78_0000)
fn1E78_032F proc
	mov	bx,sp
	push	ds
	lds	di,ss:[bx+4h]
	mov	word ptr [di+2h],0D7B0h
	mov	word ptr [di+4h],80h
	lea	ax,[di+80h]
	mov	[di+0Ch],ax
	mov	[di+0Eh],ds
	mov	word ptr [di+10h],35Ah
	mov	[di+12h],cs
	mov	byte ptr [di+30h],0h
	pop	ds
	retf	4h
1E78:035A                               8B DC 1E 36 C5 7F           ...6..
1E78:0360 04 B8 92 03 BB 70 04 8B CB 81 7D 02 B1 D7 74 0A .....p....}...t.
1E78:0370 C7 45 02 B2 D7 B8 3F 04 8B D8 89 45 14 8C 4D 16 .E....?....E..M.
1E78:0380 89 5D 18 8C 4D 1A 89 4D 1C 8C 4D 1E 33 C0 1F CA .]..M..M..M.3...
1E78:0390 04 00 55 8B EC C4 7E 06 26 8B 55 04 4A 4A 26 8B ..U...~.&.U.JJ&.
1E78:03A0 75 08 26 C4 7D 0C 33 DB C6 06 B9 B8 00 0E E8 5C u.&.}.3........\
1E78:03B0 FF B9 01 00 3C 08 74 34 3C 13 74 30 3C 04 74 44 ....<.t4<.t0<.tD
1E78:03C0 49 3C 1B 74 27 3C 01 74 23 3C 06 74 37 3C 1A 74 I<.t'<.t#<.t7<.t
1E78:03D0 46 3C 0D 74 4F 3C 20 72 CF 3B DA 74 CB 26 88 01 F<.tO< r.;.t.&..
1E78:03E0 43 E8 98 00 3B DE 76 C0 8B F3 EB BC 0B DB 74 B8 C...;.v.......t.
1E78:03F0 B0 08 E8 87 00 B0 20 E8 82 00 B0 08 E8 7D 00 4B ...... ......}.K
1E78:0400 E2 EA EB A4 3B DE 74 A0 26 8A 01 3C 20 72 99 E8 ....;.t.&..< r..
1E78:0410 6A 00 43 E2 EF EB 91 80 3E A9 B8 00 74 8A 26 88 j.C.....>...t.&.
1E78:0420 01 43 EB 0A E8 4E 00 26 C7 01 0D 0A 43 43 C4 7E .C...N.&....CC.~
1E78:0430 06 33 C0 26 89 45 08 26 89 5D 0A 5D CA 04 00 8B .3.&.E.&.].]....
1E78:0440 DC 36 C4 7F 04 26 8B 4D 08 26 29 4D 08 E3 19 26 .6...&.M.&)M...&
1E78:0450 C4 7D 0C 80 3E AA B8 00 75 0B 26 8A 05 E8 1C 00 .}..>...u.&.....
1E78:0460 47 E2 F7 EB 03 E8 9C 00 E8 D8 FC 33 C0 CA 04 00 G..........3....
1E78:0470 33 C0 CA 04 00                                  3....           

;; fn1E78_0475: 1E78:0475
;;   Called from:
;;     1E78:0166 (in fn1E78_0143)
fn1E78_0475 proc
	mov	al,0Dh
	call	047Ch
	mov	al,0Ah

;; fn1E78_047C: 1E78:047C
;;   Called from:
;;     1E78:015E (in fn1E78_0143)
;;     1E78:0163 (in fn1E78_0143)
;;     1E78:0477 (in fn1E78_0475)
;;     1E78:047A (in fn1E78_0475)
fn1E78_047C proc
	push	bx
	push	cx
	push	dx
	push	es
	push	ax
	call	04F6h
	pop	ax
	cmp	al,7h
	jz	04B3h

l1E78_0489:
	cmp	al,8h
	jz	04BAh

l1E78_048D:
	cmp	al,0Dh
	jz	04C4h

l1E78_0491:
	cmp	al,0Ah
	jz	04CAh

l1E78_0495:
	mov	ah,9h
	mov	bl,[0B8AEh]
	xor	bh,bh
	mov	cx,1h
	push	dx
	call	0609h
	pop	dx
	inc	dl
	cmp	dl,[0B8B2h]
	jbe	04CDh

l1E78_04AD:
	mov	dl,[0B8B0h]
	jmp	04CAh

l1E78_04B3:
	mov	ah,0Eh
	call	0609h
	jmp	04CDh

l1E78_04BA:
	cmp	dl,[0B8B0h]
	jz	04CDh

l1E78_04C0:
	dec	dl
	jmp	04CDh

l1E78_04C4:
	mov	dl,[0B8B0h]
	jmp	04CDh

l1E78_04CA:
	call	04D5h

l1E78_04CD:
	call	04FDh
	pop	es
	pop	dx
	pop	cx
	pop	bx
	ret

;; fn1E78_04D5: 1E78:04D5
;;   Called from:
;;     1E78:04CA (in fn1E78_047C)
fn1E78_04D5 proc
	inc	dh
	cmp	dh,[0B8B3h]
	jbe	04F5h

l1E78_04DD:
	dec	dh
	push	cx
	push	dx
	mov	ax,601h
	mov	bh,[0B8AEh]
	mov	cx,[0B8B0h]
	mov	dx,[0B8B2h]
	call	0609h
	pop	dx
	pop	cx

l1E78_04F5:
	ret

;; fn1E78_04F6: 1E78:04F6
;;   Called from:
;;     1E78:0481 (in fn1E78_047C)
fn1E78_04F6 proc
	mov	ah,3h
	xor	bh,bh
	jmp	0609h

;; fn1E78_04FD: 1E78:04FD
;;   Called from:
;;     1E78:01D6 (in fn1E78_01C0)
;;     1E78:04CD (in fn1E78_047C)
fn1E78_04FD proc
	mov	ah,2h
	xor	bh,bh
	jmp	0609h
1E78:0504             1E B8 40 00 8E D8 8B 16 50 00 1F 8B     ..@.....P...
1E78:0510 DA 8B F7 26 8A 05 3C 07 74 21 3C 08 74 2C 3C 0A ...&..<.t!<.t,<.
1E78:0520 74 35 3C 0D 74 39 47 FE C2 3A 16 B2 B8 76 3C E8 t5<.t9G..:...v<.
1E78:0530 6F 00 E8 A0 FF 8A 16 B0 B8 EB 2C E8 63 00 51 52 o.........,.c.QR
1E78:0540 B8 07 0E E8 C3 00 5A 59 EB 1C E8 54 00 3A 16 B0 ......ZY...T.:..
1E78:0550 B8 74 13 FE CA EB 0F E8 47 00 E8 78 FF EB 07 E8 .t......G..x....
1E78:0560 3F 00 8A 16 B0 B8 47 8B F7 8B DA E2 A6 E8 31 00 ?.....G.......1.
1E78:0570 1E B8 40 00 8E D8 89 16 50 00 8A C6 F6 26 4A 00 ..@.....P....&J.
1E78:0580 32 F6 03 C2 8B C8 8B 16 63 00 B0 0E EE EB 00 8A 2.......c.......
1E78:0590 C5 42 EE EB 00 4A B0 0F EE EB 00 8A C1 42 EE 1F .B...J.......B..
1E78:05A0 C3 3B F7 74 63 51 52 57 1E 06 8B CF 2B CE 8A 16 .;.tcQRW....+...
1E78:05B0 AB B8 8A 36 AE B8 B8 40 00 8E D8 8A C7 F6 26 4A ...6...@......&J
1E78:05C0 00 32 FF 03 C3 D1 E0 8B F8 8B DA 8B 16 63 00 83 .2...........c..
1E78:05D0 C2 06 B8 00 B8 80 3E 49 00 07 75 02 B4 B0 06 1F ......>I..u.....
1E78:05E0 8E C0 FC 0A DB 74 16 AC 8A D8 EC A8 01 75 FB FA .....t.......u..
1E78:05F0 EC A8 01 74 FB 8B C3 AB FB E2 EC EB 06 8A E7 AC ...t............
1E78:0600 AB E2 FC 07 1F 5F 5A 59 C3                      ....._ZY.       

;; fn1E78_0609: 1E78:0609
;;   Called from:
;;     1E78:0030 (in fn1E78_002E)
;;     1E78:0048 (in fn1E78_002E)
;;     1E78:00AF (in fn1E78_0097)
;;     1E78:00BC (in fn1E78_0097)
;;     1E78:00C6 (in fn1E78_0097)
;;     1E78:00DA (in fn1E78_0097)
;;     1E78:00E1 (in fn1E78_0097)
;;     1E78:00E7 (in fn1E78_00E5)
;;     1E78:00F2 (in fn1E78_00E5)
;;     1E78:01CF (in fn1E78_01C0)
;;     1E78:04A1 (in fn1E78_047C)
;;     1E78:04B5 (in fn1E78_047C)
;;     1E78:04F0 (in fn1E78_04D5)
;;     1E78:04FA (in fn1E78_04F6)
;;     1E78:0501 (in fn1E78_04FD)
fn1E78_0609 proc
	push	si
	push	di
	push	bp
	push	es
	int	10h
	pop	es
	pop	bp
	pop	di
	pop	si
	ret
1E78:0614             00 00 00 00 00 00 00 00 00 00 00 00     ............
