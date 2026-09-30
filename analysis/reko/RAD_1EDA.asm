;;; Segment 1EDA (1EDA:0000)

;; fn1EDA_0000: 1EDA:0000
;;   Called from:
;;     0800:4255 (in fn0800_4255)
fn1EDA_0000 proc
	mov	dx,2014h
	mov	ds,dx
	mov	[537Ch],es
	xor	bp,bp
	mov	ax,sp
	add	ax,13h
	mov	cl,4h
	shr	ax,cl
	mov	dx,ss
	add	ax,dx
	mov	[534Eh],ax
	mov	[5350h],ax
	add	ax,[5348h]
	mov	[5352h],ax
	mov	[535Ch],ax
	mov	[5360h],ax
	mov	[5368h],ax
	mov	dx,es:[0002h]
	mov	[5364h],dx
	mov	word ptr [536Eh],0A9h
	mov	[5370h],cs
	mov	di,0BABCh
	mov	si,1EEh
	mov	cx,13h
	nop

l1EDA_004B:
	cld
	lodsb	al,cs:[si]
	mov	ah,35h
	int	21h
	mov	[di],bx
	mov	[di+2h],es
	add	di,4h
	loop	004Bh

l1EDA_005C:
	push	ds
	push	cs
	pop	ds
	mov	dx,0DFh
	mov	ax,2500h
	int	21h
	mov	dx,0E6h
	mov	ax,2523h
	int	21h
	mov	dx,0AEh
	mov	ax,2524h
	int	21h
	mov	dx,0D7h
	mov	ax,253Fh
	int	21h
	pop	ds
	mov	ax,0B8BCh
	push	ds
	push	ax
	push	ds
	push	ax
	mov	ax,218h
	push	cs
	push	ax
	push	cs
	call	04F5h
	push	cs
	call	0565h
	mov	ax,0B9BCh
	push	ds
	push	ax
	push	ds
	push	ax
	mov	ax,218h
	push	cs
	push	ax
	push	cs
	call	04F5h
	push	cs
	call	056Ah
	retf
1EDA:00A9                            33 C0 CA 02 00 FB 83          3......
1EDA:00B0 C4 06 58 83 E7 1F 81 C7 96 00 80 FC 39 73 03 BF ..X.........9s..
1EDA:00C0 FF FF 57 B4 54 CD 21 8B EC 80 4E 16 01 58 5B 59 ..W.T.!...N..X[Y
1EDA:00D0 5A 5E 5F 5D 1F 07 CF B8 D0 00 83 C4 06 EB 03 B8 Z^_]............
1EDA:00E0 C8 00                                           ..              

;; fn1EDA_00E2: 1EDA:00E2
;;   Called from:
;;     1EDA:0251 (in fn1EDA_023F)
;;     1EDA:026B (in fn1EDA_0254)
;;     1EDA:04B4 (in fn1EDA_04A9)
;;     1EDA:04DC (in fn1EDA_04B7)
;;     1EDA:09F5 (in fn1EDA_098A)
fn1EDA_00E2 proc
	pop	cx
	pop	bx
	jmp	00EDh
1EDA:00E6                   B8 FF 00                            ...       

;; fn1EDA_00E9: 1EDA:00E9
;;   Called from:
;;     0800:001D (in fn0800_0000)
;;     0800:2D26 (in fn0800_2C0C)
;;     0C74:0410 (in fn0C74_03D4)
;;     133F:00DB (in fn133F_0056)
;;     13E2:01FF (in fn13E2_0193)
;;     1AB8:00D2 (in fn1AB8_008B)
fn1EDA_00E9 proc
	xor	cx,cx
	xor	bx,bx

;; fn1EDA_00ED: 1EDA:00ED
;;   Called from:
;;     1EDA:00E4 (in fn1EDA_00E2)
;;     1EDA:00EB (in fn1EDA_00E9)
fn1EDA_00ED proc
	mov	dx,2014h
	mov	ds,dx
	sti
	mov	[5376h],ax
	mov	ax,cx
	or	ax,bx
	jz	011Bh

;; fn1EDA_00FC: 1EDA:00FC
;;   Called from:
;;     1EDA:00FA (in fn1EDA_00ED)
;;     1EDA:00FA (in fn1EDA_00ED)
fn1EDA_00FC proc
	mov	ax,[5354h]

l1EDA_00FF:
	or	ax,ax
	jz	0114h

l1EDA_0103:
	mov	es,ax
	cmp	bx,es:[0010h]
	jz	0112h

l1EDA_010C:
	mov	ax,es:[0014h]
	jmp	00FFh

l1EDA_0112:
	mov	bx,es

l1EDA_0114:
	sub	bx,[537Ch]
	sub	bx,10h

;; fn1EDA_011B: 1EDA:011B
;;   Called from:
;;     1EDA:00FA (in fn1EDA_00ED)
;;     1EDA:00FA (in fn1EDA_00ED)
;;     1EDA:0118 (in fn1EDA_00FC)
fn1EDA_011B proc
	mov	[5378h],cx
	mov	[537Ah],bx
	les	bx,[5372h]
	mov	ax,es
	or	ax,bx
	jz	0140h

l1EDA_012D:
	xor	ax,ax
	mov	[5372h],ax
	mov	[5374h],ax
	mov	[5380h],ax
	mov	ax,123h
	push	cs
	push	ax
	push	es
	push	bx
	retf

l1EDA_0140:
	mov	ax,0B8BCh
	push	ds
	push	ax
	push	cs
	call	05BFh
	mov	ax,0B9BCh
	push	ds
	push	ax
	push	cs
	call	05BFh
	mov	di,0BABCh
	mov	si,1EEh
	mov	cx,13h
	nop

l1EDA_015C:
	cld
	lodsb	al,cs:[si]
	mov	ah,25h
	push	ds
	lds	dx,[di]
	int	21h
	pop	ds
	add	di,4h
	loop	015Ch

l1EDA_016C:
	mov	ax,[5378h]
	or	ax,[537Ah]
	jz	019Eh

l1EDA_0175:
	mov	bx,201h
	call	01A5h
	mov	ax,[5376h]
	call	01B3h
	mov	bx,210h
	call	01A5h
	mov	ax,[537Ah]
	call	01CDh
	mov	al,3Ah
	call	01E7h
	mov	ax,[5378h]
	call	01CDh
	mov	bx,215h
	call	01A5h

l1EDA_019E:
	mov	ax,[5376h]
	mov	ah,4Ch
	int	21h

;; fn1EDA_01A5: 1EDA:01A5
;;   Called from:
;;     1EDA:0178 (in fn1EDA_011B)
;;     1EDA:0184 (in fn1EDA_011B)
;;     1EDA:019B (in fn1EDA_011B)
fn1EDA_01A5 proc
	mov	al,cs:[bx]
	or	al,al
	jz	01B2h

l1EDA_01AC:
	call	01E7h
	inc	bx
	jmp	01A5h

l1EDA_01B2:
	ret

;; fn1EDA_01B3: 1EDA:01B3
;;   Called from:
;;     1EDA:017E (in fn1EDA_011B)
fn1EDA_01B3 proc
	mov	cl,64h
	call	01BFh
	mov	cl,0Ah
	call	01BFh
	jmp	01C3h

;; fn1EDA_01BF: 1EDA:01BF
;;   Called from:
;;     1EDA:01B5 (in fn1EDA_01B3)
;;     1EDA:01BA (in fn1EDA_01B3)
fn1EDA_01BF proc
	xor	ah,ah
	div	cl

l1EDA_01C3:
	add	al,30h
	push	ax
	call	01E7h
	pop	ax
	mov	al,ah
	ret

;; fn1EDA_01CD: 1EDA:01CD
;;   Called from:
;;     1EDA:018A (in fn1EDA_011B)
;;     1EDA:0195 (in fn1EDA_011B)
fn1EDA_01CD proc
	push	ax
	mov	al,ah
	call	01D4h
	pop	ax

;; fn1EDA_01D4: 1EDA:01D4
;;   Called from:
;;     1EDA:01D0 (in fn1EDA_01CD)
;;     1EDA:01D3 (in fn1EDA_01CD)
fn1EDA_01D4 proc
	push	ax
	mov	cl,4h
	shr	al,cl
	call	01DFh
	pop	ax
	and	al,0Fh

;; fn1EDA_01DF: 1EDA:01DF
;;   Called from:
;;     1EDA:01D9 (in fn1EDA_01D4)
;;     1EDA:01DD (in fn1EDA_01D4)
fn1EDA_01DF proc
	add	al,30h
	cmp	al,3Ah
	jc	01E7h

l1EDA_01E5:
	add	al,7h

;; fn1EDA_01E7: 1EDA:01E7
;;   Called from:
;;     1EDA:018F (in fn1EDA_011B)
;;     1EDA:01AC (in fn1EDA_01A5)
;;     1EDA:01C6 (in fn1EDA_01BF)
;;     1EDA:01C6 (in fn1EDA_01B3)
;;     1EDA:01E3 (in fn1EDA_01DF)
;;     1EDA:01E5 (in fn1EDA_01DF)
fn1EDA_01E7 proc
	mov	dl,al
	mov	ah,6h
	int	21h
	ret
1EDA:01EE                                           00 02               ..
1EDA:01F0 1B 21 23 24 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F .!#$456789:;<=>?
1EDA:0200 75 52 75 6E 74 69 6D 65 20 65 72 72 6F 72 20 00 uRuntime error .
1EDA:0210 20 61 74 20 00 2E 0D 0A 00 50 6F 72 74 69 6F 6E  at .....Portion
1EDA:0220 73 20 43 6F 70 79 72 69 67 68 74 20 28 63 29 20 s Copyright (c) 
1EDA:0230 31 39 38 33 2C 39 30 20 42 6F 72 6C 61 6E 64    1983,90 Borland 

;; fn1EDA_023F: 1EDA:023F
;;   Called from:
;;     0800:01A7 (in fn0800_0147)
;;     0800:044B (in fn0800_03F8)
;;     0800:046C (in fn0800_03F8)
;;     0800:0DBC (in fn0800_0D20)
;;     0C43:010B (in fn0C43_00B9)
;;     0C74:045A (in fn0C74_03D4)
;;     0C74:0485 (in fn0C74_03D4)
;;     0C74:04F8 (in fn0C74_03D4)
;;     0C74:0544 (in fn0C74_03D4)
;;     0C74:0620 (in fn0C74_05B8)
;;     0C74:0E99 (in fn0C74_0E2E)
;;     0C74:0EA7 (in fn0C74_0E2E)
;;     0C74:0FB8 (in fn0C74_0FA1)
;;     0C74:0FC6 (in fn0C74_0FA1)
;;     0C74:1182 (in fn0C74_0FA1)
;;     0C74:1190 (in fn0C74_0FA1)
;;     0C74:13DB (in fn0C74_0FA1)
;;     0C74:1539 (in fn0C74_0FA1)
;;     0C74:16FF (in fn0C74_0FA1)
;;     0C74:1798 (in fn0C74_0FA1)
;;     0C74:1818 (in fn0C74_0FA1)
;;     0C74:19B5 (in fn0C74_0FA1)
;;     0C74:1A5B (in fn0C74_0FA1)
;;     0C74:1BA0 (in fn0C74_1B3B)
;;     0C74:1E00 (in fn0C74_1D95)
;;     0C74:1E0E (in fn0C74_1D95)
;;     0C74:1F1F (in fn0C74_1F08)
;;     0C74:1F2D (in fn0C74_1F08)
;;     0C74:20E9 (in fn0C74_1F08)
;;     0C74:20F7 (in fn0C74_1F08)
;;     0C74:2342 (in fn0C74_1F08)
;;     0C74:24A0 (in fn0C74_1F08)
;;     0C74:269B (in fn0C74_1F08)
;;     0C74:27E8 (in fn0C74_1F08)
;;     0C74:294D (in fn0C74_1F08)
;;     0C74:29F3 (in fn0C74_1F08)
;;     0C74:2B10 (in fn0C74_2AD9)
;;     0C74:2BEC (in fn0C74_2BBD)
;;     0C74:2BFA (in fn0C74_2BBD)
;;     0C74:2EFA (in fn0C74_2E5A)
;;     0C74:2F4C (in fn0C74_2E5A)
;;     0C74:3046 (in fn0C74_2E5A)
;;     0C74:32D5 (in fn0C74_3236)
;;     0C74:3327 (in fn0C74_3236)
;;     0C74:3421 (in fn0C74_3236)
;;     0C74:4F04 (in fn0C74_4DAC)
;;     0C74:50EF (in fn0C74_4FD7)
;;     0C74:53A9 (in fn0C74_5258)
;;     1229:0077 (in fn1229_0040)
fn1EDA_023F proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+6h]
	call	0308h
	pop	bp
	jc	024Eh

l1EDA_024B:
	retf	2h

l1EDA_024E:
	mov	ax,0CBh
	jmp	00E2h

;; fn1EDA_0254: 1EDA:0254
;;   Called from:
;;     0800:04BA (in fn0800_03F8)
;;     0800:11BC (in fn0800_0D20)
;;     0C43:00B0 (in fn0C43_0095)
;;     0C74:05A6 (in fn0C74_03D4)
;;     0C74:06B0 (in fn0C74_05B8)
;;     0C74:0F8A (in fn0C74_0E2E)
;;     0C74:0F98 (in fn0C74_0E2E)
;;     0C74:108A (in fn0C74_0FA1)
;;     0C74:1098 (in fn0C74_0FA1)
;;     0C74:12F5 (in fn0C74_0FA1)
;;     0C74:1303 (in fn0C74_0FA1)
;;     0C74:13A9 (in fn0C74_0FA1)
;;     0C74:1456 (in fn0C74_0FA1)
;;     0C74:146D (in fn0C74_0FA1)
;;     0C74:1507 (in fn0C74_0FA1)
;;     0C74:15BD (in fn0C74_0FA1)
;;     0C74:15CB (in fn0C74_0FA1)
;;     0C74:174B (in fn0C74_0FA1)
;;     0C74:17F8 (in fn0C74_0FA1)
;;     0C74:18D9 (in fn0C74_0FA1)
;;     0C74:195D (in fn0C74_0FA1)
;;     0C74:196B (in fn0C74_0FA1)
;;     0C74:1A30 (in fn0C74_0FA1)
;;     0C74:1AD8 (in fn0C74_0FA1)
;;     0C74:1CA3 (in fn0C74_1B3B)
;;     0C74:1D52 (in fn0C74_1B3B)
;;     0C74:1EF1 (in fn0C74_1D95)
;;     0C74:1EFF (in fn0C74_1D95)
;;     0C74:1FF1 (in fn0C74_1F08)
;;     0C74:1FFF (in fn0C74_1F08)
;;     0C74:225C (in fn0C74_1F08)
;;     0C74:226A (in fn0C74_1F08)
;;     0C74:2310 (in fn0C74_1F08)
;;     0C74:23C6 (in fn0C74_1F08)
;;     0C74:23D4 (in fn0C74_1F08)
;;     0C74:246E (in fn0C74_1F08)
;;     0C74:2524 (in fn0C74_1F08)
;;     0C74:2532 (in fn0C74_1F08)
;;     0C74:275C (in fn0C74_1F08)
;;     0C74:2871 (in fn0C74_1F08)
;;     0C74:2915 (in fn0C74_1F08)
;;     0C74:2923 (in fn0C74_1F08)
;;     0C74:29C8 (in fn0C74_1F08)
;;     0C74:2A70 (in fn0C74_1F08)
;;     0C74:2BB6 (in fn0C74_2AD9)
;;     0C74:2C64 (in fn0C74_2BBD)
;;     0C74:2E2C (in fn0C74_2BBD)
;;     0C74:301A (in fn0C74_2E5A)
;;     0C74:31AE (in fn0C74_2E5A)
;;     0C74:322C (in fn0C74_2E5A)
;;     0C74:33F5 (in fn0C74_3236)
;;     0C74:358D (in fn0C74_3236)
;;     0C74:360B (in fn0C74_3236)
;;     0C74:4F7E (in fn0C74_4DAC)
;;     0C74:5162 (in fn0C74_4FD7)
;;     0C74:541B (in fn0C74_5258)
;;     1229:0372 (in fn1229_0040)
fn1EDA_0254 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+6h]
	les	cx,[bp+8h]
	mov	bx,es
	call	03D3h
	pop	bp
	jc	0268h

l1EDA_0265:
	retf	6h

l1EDA_0268:
	mov	ax,0CCh
	jmp	00E2h
1EDA:026E                                           8B DC               ..
1EDA:0270 36 C4 7F 04 FC A1 5E 53 AB A1 60 53 AB CA 04 00 6.....^S..`S....
1EDA:0280 8B DC 36 C4 7F 04 26 C4 3D 89 3E 5E 53 8C 06 60 ..6...&.=.>^S..`
1EDA:0290 53 89 3E 66 53 8C 06 68 53 CA 04 00 BB B1 02 EB S.>fS..hS.......
1EDA:02A0 37 81 C2 00 10 EB 05 03 44 04 72 F5 03 54 06 C5 7.......D.r..T..
1EDA:02B0 34 8C DB 3B DF 75 F0 C3 BB D1 02 EB 1B 3B 54 06 4..;.u.......;T.
1EDA:02C0 77 0D 72 05 3B 44 04 73 06 8B 44 04 8B 54 06 C5 w.r.;D.s..D..T..
1EDA:02D0 34 8C DB 3B DF 75 E6 C3 A1 62 53 8B 16 64 53 2B 4..;.u...bS..dS+
1EDA:02E0 06 5E 53 1B 16 60 53 25 0F 00 1E 8B 3E 60 53 C5 .^S..`S%....>`S.
1EDA:02F0 36 66 53 FF D3 1F B1 04 D3 C2 8B CA 80 E1 F0 83 6fS.............
1EDA:0300 E2 0F 03 C1 83 D2 00 CB                         ........        

;; fn1EDA_0308: 1EDA:0308
;;   Called from:
;;     1EDA:0245 (in fn1EDA_023F)
fn1EDA_0308 proc
	or	ax,ax
	jz	0382h

l1EDA_030C:
	mov	[0BB08h],ax

l1EDA_030F:
	call	0491h
	mov	di,5366h
	mov	cx,ds
	mov	es,cx

l1EDA_0319:
	mov	cx,di
	mov	bx,es
	les	di,es:[di]
	mov	si,es
	cmp	si,[5360h]
	jz	0383h

l1EDA_0328:
	cmp	dx,es:[di+6h]
	ja	0319h

l1EDA_032E:
	jc	0336h

l1EDA_0330:
	cmp	ax,es:[di+4h]
	ja	0319h

l1EDA_0336:
	push	es
	push	di
	push	bx
	push	cx
	mov	cx,es:[di]
	mov	bx,es:[di+2h]
	jz	0376h

l1EDA_0343:
	push	bx
	push	cx
	mov	cx,es:[di+4h]
	mov	bx,es:[di+6h]
	sub	cx,ax
	sbb	bx,dx
	and	cx,0Fh
	add	ax,di
	add	dx,si
	add	al,0F0h
	adc	dx,0h
	and	al,0Fh
	mov	di,ax
	mov	es,dx
	pop	word ptr es:[di]
	pop	word ptr es:[di+2h]
	mov	es:[di+4h],cx
	mov	es:[di+6h],bx
	mov	cx,di
	mov	bx,es

l1EDA_0376:
	pop	di
	pop	es
	mov	es:[di],cx
	mov	es:[di+2h],bx
	pop	ax
	pop	dx
	clc

l1EDA_0382:
	ret

l1EDA_0383:
	add	ax,di
	add	dx,si
	add	al,0F0h
	adc	dx,0h
	and	al,0Fh
	cmp	dx,[5364h]
	jc	039Ch

l1EDA_0394:
	ja	03BBh

l1EDA_0396:
	cmp	ax,[5362h]
	ja	03BBh

l1EDA_039C:
	push	es
	push	di
	mov	di,cx
	mov	es,bx
	mov	[535Eh],ax
	mov	[5360h],dx
	mov	es:[di],ax
	mov	es:[di+2h],dx
	xor	ax,ax
	push	ax
	call	dword ptr [536Eh]
	pop	ax
	pop	dx
	clc
	ret

l1EDA_03BB:
	push	word ptr [0BB08h]
	call	dword ptr [536Eh]
	cmp	al,1h
	jc	0382h

l1EDA_03C7:
	jz	03CFh

l1EDA_03C9:
	mov	ax,[0BB08h]
	jmp	030Fh

l1EDA_03CF:
	xor	ax,ax
	cwd
	ret

;; fn1EDA_03D3: 1EDA:03D3
;;   Called from:
;;     1EDA:025F (in fn1EDA_0254)
fn1EDA_03D3 proc
	or	ax,ax
	jz	0431h

l1EDA_03D7:
	test	cx,0FFF7h
	jnz	0430h

l1EDA_03DD:
	cmp	bx,[535Ch]
	ja	03EBh

l1EDA_03E3:
	jc	0430h

l1EDA_03E5:
	cmp	cx,[535Ah]
	jc	0430h

l1EDA_03EB:
	cmp	bx,[5360h]
	jc	03F9h

l1EDA_03F1:
	ja	0430h

l1EDA_03F3:
	cmp	cx,[535Eh]
	jnc	0430h

l1EDA_03F9:
	call	0491h
	mov	di,cx
	mov	es,bx
	mov	es:[di+4h],ax
	mov	es:[di+6h],dx
	mov	di,5366h
	mov	ax,ds
	mov	es,ax

l1EDA_040F:
	mov	ax,di
	mov	dx,es
	les	di,es:[di]
	mov	si,es
	cmp	bx,si
	ja	040Fh

l1EDA_041C:
	jc	0424h

l1EDA_041E:
	cmp	cx,di
	ja	040Fh

l1EDA_0422:
	jz	0430h

l1EDA_0424:
	push	dx
	push	ax
	call	0432h
	pop	cx
	pop	bx
	call	0432h
	clc
	ret

l1EDA_0430:
	stc

l1EDA_0431:
	ret

;; fn1EDA_0432: 1EDA:0432
;;   Called from:
;;     1EDA:0426 (in fn1EDA_03D3)
;;     1EDA:042B (in fn1EDA_03D3)
fn1EDA_0432 proc
	mov	ax,di
	mov	dx,es
	mov	di,cx
	mov	es,bx
	add	cx,es:[di+4h]
	add	bx,es:[di+6h]
	add	cl,0F0h
	adc	bx,0h
	and	cl,0Fh
	cmp	bx,dx
	jnz	0489h

l1EDA_044F:
	cmp	cx,ax
	jnz	0489h

l1EDA_0453:
	cmp	dx,[5360h]
	jnz	0468h

l1EDA_0459:
	cmp	ax,[535Eh]
	jnz	0468h

l1EDA_045F:
	mov	[535Eh],di
	mov	[5360h],es
	ret

l1EDA_0468:
	push	ds
	push	di
	mov	si,ax
	mov	ds,dx
	cld
	movsw
	movsw
	lodsw
	xchg	dx,ax
	lodsw
	xchg	dx,ax
	add	ax,es:[di]
	add	dx,es:[di+2h]
	add	al,0F0h
	adc	dx,0h
	and	al,0Fh
	stosw
	xchg	dx,ax
	stosw
	pop	di
	pop	ds
	ret

l1EDA_0489:
	mov	es:[di],ax
	mov	es:[di+2h],dx
	ret

;; fn1EDA_0491: 1EDA:0491
;;   Called from:
;;     1EDA:030F (in fn1EDA_0308)
;;     1EDA:03F9 (in fn1EDA_03D3)
fn1EDA_0491 proc
	add	ax,7h
	mov	dx,ax
	rcr	dx,1h
	shr	dx,1h
	shr	dx,1h
	shr	dx,1h
	and	ax,8h
	ret

;; fn1EDA_04A2: 1EDA:04A2
;;   Called from:
;;     0800:0D7F (in fn0800_0D20)
;;     0800:2C9E (in fn0800_2C0C)
;;     0800:393D (in fn0800_391E)
;;     0C43:00F0 (in fn0C43_00B9)
;;     1229:04CA (in fn1229_0486)
;;     1AB8:08FC (in fn1AB8_0887)
;;     1AB8:092E (in fn1AB8_0887)
;;     1AB8:0A91 (in fn1AB8_097B)
;;     1AB8:16E4 (in fn1AB8_1536)
fn1EDA_04A2 proc
	xor	ax,ax
	xchg	[5380h],ax
	retf

;; fn1EDA_04A9: 1EDA:04A9
;;   Called from:
;;     0800:126A (in fn0800_11EF)
;;     0800:1298 (in fn0800_11EF)
;;     0800:12B9 (in fn0800_11EF)
;;     0800:12E0 (in fn0800_11EF)
;;     0800:2CC9 (in fn0800_2C0C)
;;     0800:2CE4 (in fn0800_2C0C)
;;     0800:2CFF (in fn0800_2C0C)
;;     0800:2D1A (in fn0800_2C0C)
;;     0800:3683 (in fn0800_31B7)
;;     0800:369B (in fn0800_31B7)
;;     0800:36B4 (in fn0800_31B7)
;;     0800:36C4 (in fn0800_31B7)
;;     0800:3A76 (in fn0800_391E)
;;     0800:3AA6 (in fn0800_391E)
;;     0800:3B43 (in fn0800_391E)
;;     0800:3B8F (in fn0800_391E)
;;     0800:3BBF (in fn0800_391E)
;;     0800:4199 (in fn0800_4168)
;;     0800:41A8 (in fn0800_4168)
;;     0800:41C0 (in fn0800_4168)
;;     0C43:012E (in fn0C43_00B9)
;;     0C43:0159 (in fn0C43_00B9)
;;     0C43:017C (in fn0C43_00B9)
;;     0C43:01AF (in fn0C43_00B9)
;;     0C43:01F9 (in fn0C43_00B9)
;;     0C43:022E (in fn0C43_00B9)
;;     0C43:024A (in fn0C43_00B9)
;;     0C43:0281 (in fn0C43_00B9)
;;     1229:04FC (in fn1229_0486)
;;     1229:0923 (in fn1229_0735)
;;     1229:093A (in fn1229_0735)
;;     1229:0951 (in fn1229_0735)
;;     1229:0960 (in fn1229_0735)
;;     1229:09C4 (in fn1229_0735)
;;     1229:09D3 (in fn1229_0735)
;;     1229:09EB (in fn1229_0735)
;;     1AB8:00AC (in fn1AB8_008B)
;;     1AB8:00CA (in fn1AB8_008B)
fn1EDA_04A9 proc
	cmp	word ptr [5380h],0h
	jnz	04B1h

l1EDA_04B0:
	retf

l1EDA_04B1:
	mov	ax,[5380h]
	jmp	00E2h

;; fn1EDA_04B7: 1EDA:04B7
;;   Called from:
;;     13C8:0121 (in fn13C8_0111)
fn1EDA_04B7 proc
	mov	si,sp
	mov	es,ss:[si+2h]
	cmp	dx,es:[di+2h]
	jg	04CAh

l1EDA_04C3:
	jl	04D9h

l1EDA_04C5:
	cmp	ax,es:[di]
	jc	04D9h

l1EDA_04CA:
	cmp	dx,es:[di+6h]
	jl	04D8h

l1EDA_04D0:
	jg	04D9h

l1EDA_04D2:
	cmp	ax,es:[di+4h]
	ja	04D9h

l1EDA_04D8:
	retf

l1EDA_04D9:
	mov	ax,0C9h
	jmp	00E2h
1EDA:04DF                                              05                .
1EDA:04E0 00 02 2B C4 73 09 F7 D8 3B 06 7E 53 72 01 CB B8 ..+.s...;.~Sr...
1EDA:04F0 CA 00 E9 ED FB                                  .....           

;; fn1EDA_04F5: 1EDA:04F5
;;   Called from:
;;     0800:0D4C (in fn0800_0D20)
;;     0800:2C6C (in fn0800_2C0C)
;;     0800:392D (in fn0800_391E)
;;     1EDA:008C (in fn1EDA_0000)
;;     1EDA:00A0 (in fn1EDA_0000)
fn1EDA_04F5 proc
	mov	bx,sp
	push	ds
	les	di,ss:[bx+8h]
	lds	si,ss:[bx+4h]
	cld
	xor	ax,ax
	stosw
	mov	ax,0D7B0h
	stosw
	mov	ax,80h
	stosw
	xor	ax,ax
	stosw
	stosw
	stosw
	lea	ax,[di+74h]
	stosw
	mov	ax,es
	stosw
	mov	ax,60Ch
	stosw
	mov	ax,cs
	stosw
	xor	ax,ax
	mov	cx,0Eh

l1EDA_0524:
	rep stosw

l1EDA_0526:
	lodsb
	cmp	al,4Fh
	jbe	052Dh

l1EDA_052B:
	mov	al,4Fh

l1EDA_052D:
	mov	cl,al
	xor	ch,ch
	rep movsb
	xor	al,al
	stosb
	pop	ds
	retf	8h
1EDA:053A                               8B DC 36 C4 7F 0A           ..6...
1EDA:0540 36 8B 47 04 26 89 45 04 36 8B 47 06 26 89 45 0C 6.G.&.E.6.G.&.E.
1EDA:0550 36 8B 47 08 26 89 45 0E 33 C0 26 89 45 08 26 89 6.G.&.E.3.&.E.&.
1EDA:0560 45 0A CA 0A 00                                  E....           

;; fn1EDA_0565: 1EDA:0565
;;   Called from:
;;     0800:0D57 (in fn0800_0D20)
;;     0800:3938 (in fn0800_391E)
;;     1E78:0014 (in fn1E78_0000)
;;     1EDA:0090 (in fn1EDA_0000)
fn1EDA_0565 proc
	mov	dx,0D7B1h
	jmp	0572h

;; fn1EDA_056A: 1EDA:056A
;;   Called from:
;;     0800:2C77 (in fn0800_2C0C)
;;     1E78:0027 (in fn1E78_0000)
;;     1EDA:00A4 (in fn1EDA_0000)
fn1EDA_056A proc
	mov	dx,0D7B2h
	jmp	0572h
1EDA:056F                                              BA                .
1EDA:0570 B3 D7                                           ..              

;; fn1EDA_0572: 1EDA:0572
;;   Called from:
;;     1EDA:0568 (in fn1EDA_0565)
;;     1EDA:056D (in fn1EDA_056A)
fn1EDA_0572 proc
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	mov	ax,es:[di+2h]
	cmp	ax,0D7B1h
	jz	0593h

l1EDA_0581:
	cmp	ax,0D7B2h
	jz	0593h

l1EDA_0586:
	cmp	ax,0D7B0h
	jz	059Bh

l1EDA_058B:
	mov	word ptr [5380h],66h
	jmp	05B7h

l1EDA_0593:
	push	dx
	push	es
	push	di
	push	cs
	call	05BFh
	pop	dx

l1EDA_059B:
	xor	ax,ax
	mov	es:[di+2h],dx
	mov	es:[di+8h],ax
	mov	es:[di+0Ah],ax
	mov	bx,10h
	call	05FBh
	jz	05B7h

l1EDA_05B1:
	mov	word ptr es:[di+2h],0D7B0h

l1EDA_05B7:
	pop	bp
	retf	4h
1EDA:05BB                                  B0 00 EB 02               .... 

;; fn1EDA_05BF: 1EDA:05BF
;;   Called from:
;;     0800:0D7A (in fn0800_0D20)
;;     0800:2C99 (in fn0800_2C0C)
;;     0800:3BBA (in fn0800_391E)
;;     1EDA:0145 (in fn1EDA_011B)
;;     1EDA:014E (in fn1EDA_011B)
;;     1EDA:0596 (in fn1EDA_0572)
fn1EDA_05BF proc
	mov	al,1h
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	cmp	word ptr es:[di+2h],0D7B1h
	jz	05E7h

l1EDA_05CF:
	cmp	word ptr es:[di+2h],0D7B2h
	jz	05DFh

l1EDA_05D7:
	mov	word ptr [5380h],67h
	jmp	05F7h

l1EDA_05DF:
	push	ax
	mov	bx,14h
	call	05FBh
	pop	ax

l1EDA_05E7:
	or	al,al
	jz	05F7h

l1EDA_05EB:
	mov	bx,1Ch
	call	05FBh
	mov	word ptr es:[di+2h],0D7B0h

l1EDA_05F7:
	pop	bp
	retf	4h

;; fn1EDA_05FB: 1EDA:05FB
;;   Called from:
;;     1EDA:05AC (in fn1EDA_0572)
;;     1EDA:05E3 (in fn1EDA_05BF)
;;     1EDA:05EE (in fn1EDA_05BF)
fn1EDA_05FB proc
	push	es
	push	di
	push	es
	push	di
	call	dword ptr es:[bx+di]
	or	ax,ax
	jz	0609h

l1EDA_0606:
	mov	[5380h],ax

l1EDA_0609:
	pop	di
	pop	es
	ret
1EDA:060C                                     8B DC 1E 36             ...6
1EDA:0610 C5 7F 04 33 C9 89 0D B8 00 3D 81 7D 02 B1 D7 74 ...3.....=.}...t
1EDA:0620 0D B0 02 FF 05 81 7D 02 B3 D7 74 02 B4 3C 80 7D ......}...t..<.}
1EDA:0630 30 00 74 09 8D 55 30 CD 21 72 4F 89 05 B8 E8 06 0.t..U0.!rO.....
1EDA:0640 33 C9 8B D9 81 7D 02 B1 D7 74 29 8B 1D B8 00 44 3....}...t)....D
1EDA:0650 CD 21 B8 3D 07 8B C8 8C CB F6 C2 80 75 11 81 7D .!.=........u..}
1EDA:0660 02 B3 D7 75 03 E8 26 00 B8 18 07 33 C9 8B D9 C7 ...u..&....3....
1EDA:0670 45 02 B2 D7 89 45 14 8C 4D 16 89 4D 18 89 5D 1A E....E..M..M..].
1EDA:0680 C7 45 1C 5D 07 8C 4D 1E 33 C0 1F CA 04 00 33 D2 .E.]..M.3.....3.
1EDA:0690 33 C9 8B 1D B8 02 42 CD 21 2D 80 00 83 DA 00 73 3.....B.!-.....s
1EDA:06A0 04 33 C0 33 D2 8B CA 8B D0 8B 1D B8 00 42 CD 21 .3.3.........B.!
1EDA:06B0 8D 95 80 00 B9 80 00 8B 1D B4 3F CD 21 73 02 33 ..........?.!s.3
1EDA:06C0 C0 33 DB 3B D8 74 20 80 B9 80 00 1A 74 03 43 EB .3.;.t .....t.C.
1EDA:06D0 F2 8B D3 2B D0 B9 FF FF 8B 1D B8 02 42 CD 21 33 ...+........B.!3
1EDA:06E0 C9 8B 1D B4 40 CD 21 C3 8B DC 1E 36 C4 7F 04 26 ....@.!....6...&
1EDA:06F0 C5 55 0C 26 8B 4D 04 26 8B 1D B4 3F CD 21 72 10 .U.&.M.&...?.!r.
1EDA:0700 26 89 45 0A 33 C0 26 C7 45 08 00 00 1F CA 04 00 &.E.3.&.E.......
1EDA:0710 26 C7 45 0A 00 00 EB EE 8B DC 1E 36 C4 7F 04 26 &.E........6...&
1EDA:0720 C5 55 0C 33 C9 26 87 4D 08 26 8B 1D B4 40 CD 21 .U.3.&.M.&...@.!
1EDA:0730 72 07 2B C1 74 03 B8 65 00 1F CA 04 00 8B DC 1E r.+.t..e........
1EDA:0740 36 C4 7F 04 26 C5 55 0C 33 C9 26 87 4D 08 26 8B 6...&.U.3.&.M.&.
1EDA:0750 1D B4 40 CD 21 72 02 33 C0 1F CA 04 00 8B DC 36 ..@.!r.3.......6
1EDA:0760 C4 7F 04 26 8B 1D 83 FB 04 76 06 B4 3E CD 21 72 ...&.....v..>.!r
1EDA:0770 02 33 C0 CA 04 00                               .3....          

;; fn1EDA_0776: 1EDA:0776
;;   Called from:
;;     1EDA:0822 (in fn1EDA_081A)
;;     1EDA:089F (in fn1EDA_0896)
;;     1EDA:0922 (in fn1EDA_0918)
fn1EDA_0776 proc
	cmp	word ptr [5380h],0h
	jnz	0785h

l1EDA_077D:
	cmp	word ptr es:[di+2h],0D7B1h
	jnz	0792h

l1EDA_0785:
	mov	bx,es:[di+8h]
	mov	dx,es:[di+0Ah]
	les	di,es:[di+0Ch]
	ret

l1EDA_0792:
	mov	word ptr [5380h],68h
	jmp	0785h

;; fn1EDA_079A: 1EDA:079A
;;   Called from:
;;     1EDA:0827 (in fn1EDA_081A)
;;     1EDA:0833 (in fn1EDA_081A)
;;     1EDA:08AA (in fn1EDA_0896)
;;     1EDA:0927 (in fn1EDA_0918)
fn1EDA_079A proc
	cmp	bx,dx
	jz	07A3h

l1EDA_079E:
	mov	al,es:[bx+di]
	clc
	ret

l1EDA_07A3:
	mov	di,sp
	les	di,ss:[di+2h]
	call	07E9h
	mov	dx,ax
	cmp	bx,dx
	jnz	079Eh

l1EDA_07B2:
	mov	al,1Ah
	stc
	ret

;; fn1EDA_07B6: 1EDA:07B6
;;   Called from:
;;     1EDA:0850 (in fn1EDA_0848)
;;     1EDA:08D7 (in fn1EDA_08CE)
fn1EDA_07B6 proc
	cmp	word ptr [5380h],0h
	jnz	07C5h

l1EDA_07BD:
	cmp	word ptr es:[di+2h],0D7B2h
	jnz	07D2h

l1EDA_07C5:
	mov	bx,es:[di+8h]
	mov	dx,es:[di+4h]
	les	di,es:[di+0Ch]
	ret

l1EDA_07D2:
	mov	word ptr [5380h],69h
	jmp	07C5h

;; fn1EDA_07DA: 1EDA:07DA
;;   Called from:
;;     1EDA:0857 (in fn1EDA_0848)
;;     1EDA:085C (in fn1EDA_0848)
;;     1EDA:08EC (in fn1EDA_08CE)
;;     1EDA:08FC (in fn1EDA_08CE)
fn1EDA_07DA proc
	mov	es:[bx+di],al
	inc	bx
	cmp	bx,dx
	jz	07E3h

l1EDA_07E2:
	ret

l1EDA_07E3:
	mov	di,sp
	les	di,ss:[di+2h]

;; fn1EDA_07E9: 1EDA:07E9
;;   Called from:
;;     1EDA:07A9 (in fn1EDA_079A)
fn1EDA_07E9 proc
	push	cx
	push	si
	push	ds
	mov	dx,2014h
	mov	ds,dx
	mov	es:[di+8h],bx
	push	es
	push	di
	push	es
	push	di
	call	dword ptr es:[di+14h]
	or	ax,ax
	jz	0804h

;; fn1EDA_0801: 1EDA:0801
;;   Called from:
;;     1EDA:07FF (in fn1EDA_07E9)
;;     1EDA:07FF (in fn1EDA_07DA)
;;     1EDA:07FF (in fn1EDA_07DA)
fn1EDA_0801 proc
	mov	[5380h],ax

l1EDA_0804:
	pop	di
	pop	es
	mov	ax,es:[di+0Ah]
	mov	bx,es:[di+8h]
	mov	dx,es:[di+4h]
	les	di,es:[di+0Ch]
	pop	ds
	pop	si
	pop	cx
	ret

;; fn1EDA_081A: 1EDA:081A
;;   Called from:
;;     0800:3A71 (in fn0800_391E)
fn1EDA_081A proc
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	push	es
	push	di
	call	0776h
	jnz	083Bh

l1EDA_0827:
	call	079Ah
	cmp	al,1Ah
	jz	083Bh

l1EDA_082E:
	inc	bx
	cmp	al,0Dh
	jnz	0827h

l1EDA_0833:
	call	079Ah
	cmp	al,0Ah
	jnz	083Bh

l1EDA_083A:
	inc	bx

l1EDA_083B:
	pop	di
	pop	es
	mov	es:[di+8h],bx
	call	0879h
	pop	bp
	retf	4h

;; fn1EDA_0848: 1EDA:0848
;;   Called from:
;;     0800:2C8E (in fn0800_2C0C)
;;     0800:2CC4 (in fn0800_2C0C)
;;     0800:2CDF (in fn0800_2C0C)
;;     0800:2CFA (in fn0800_2C0C)
;;     0800:2D15 (in fn0800_2C0C)
;;     0C74:0409 (in fn0C74_03D4)
;;     133F:00A7 (in fn133F_0056)
;;     133F:00BD (in fn133F_0056)
;;     133F:00D3 (in fn133F_0056)
;;     13E2:01F8 (in fn13E2_0193)
;;     1AB8:00A7 (in fn1AB8_008B)
;;     1AB8:00C5 (in fn1AB8_008B)
fn1EDA_0848 proc
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	push	es
	push	di
	call	07B6h
	jnz	085Fh

l1EDA_0855:
	mov	al,0Dh
	call	07DAh
	mov	al,0Ah
	call	07DAh

l1EDA_085F:
	pop	di
	pop	es
	mov	es:[di+8h],bx
	call	0879h
	pop	bp
	retf	4h

;; fn1EDA_086C: 1EDA:086C
;;   Called from:
;;     0800:0D6F (in fn0800_0D20)
;;     11C8:0217 (in fn11C8_0092)
fn1EDA_086C proc
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	call	0879h
	pop	bp
	retf	4h

;; fn1EDA_0879: 1EDA:0879
;;   Called from:
;;     1EDA:0841 (in fn1EDA_081A)
;;     1EDA:0865 (in fn1EDA_0848)
;;     1EDA:0872 (in fn1EDA_086C)
fn1EDA_0879 proc
	cmp	word ptr es:[di+1Ah],0h
	jnz	0881h

l1EDA_0880:
	ret

l1EDA_0881:
	cmp	word ptr [5380h],0h
	jnz	0895h

l1EDA_0888:
	push	es
	push	di
	call	dword ptr es:[di+18h]
	or	ax,ax
	jz	0895h

l1EDA_0892:
	mov	[5380h],ax

l1EDA_0895:
	ret

;; fn1EDA_0896: 1EDA:0896
;;   Called from:
;;     0800:0D6A (in fn0800_0D20)
;;     0800:3A6C (in fn0800_391E)
fn1EDA_0896 proc
	push	bp
	mov	bp,sp
	push	ds
	les	di,[bp+0Ch]
	push	es
	push	di
	call	0776h
	lds	si,[bp+8h]
	mov	cx,0h
	jnz	08BFh

l1EDA_08AA:
	call	079Ah
	cmp	al,0Dh
	jz	08BFh

l1EDA_08B1:
	cmp	al,1Ah
	jz	08BFh

l1EDA_08B5:
	inc	bx
	inc	cx
	inc	si
	mov	[si],al
	cmp	cx,[bp+6h]
	jnz	08AAh

l1EDA_08BF:
	sub	si,cx
	mov	[si],cl
	pop	di
	pop	es
	mov	es:[di+8h],bx
	pop	ds
	pop	bp
	retf	6h

;; fn1EDA_08CE: 1EDA:08CE
;;   Called from:
;;     0800:2C89 (in fn0800_2C0C)
;;     0800:2CBF (in fn0800_2C0C)
;;     0800:2CDA (in fn0800_2C0C)
;;     0800:2CF5 (in fn0800_2C0C)
;;     0800:2D10 (in fn0800_2C0C)
;;     0C74:0404 (in fn0C74_03D4)
;;     11C8:01FC (in fn11C8_0092)
;;     11C8:0212 (in fn11C8_0092)
;;     133F:008D (in fn133F_0056)
;;     133F:00A2 (in fn133F_0056)
;;     133F:00B8 (in fn133F_0056)
;;     133F:00CE (in fn133F_0056)
;;     13E2:01F3 (in fn13E2_0193)
;;     1AB8:00A2 (in fn1AB8_008B)
;;     1AB8:00C0 (in fn1AB8_008B)
fn1EDA_08CE proc
	push	bp
	mov	bp,sp
	push	ds
	les	di,[bp+0Ch]
	push	es
	push	di
	call	07B6h
	jnz	0901h

l1EDA_08DC:
	lds	si,[bp+8h]
	mov	cx,[bp+6h]
	cld
	lodsb
	xor	ah,ah
	sub	cx,ax
	jle	08F6h

l1EDA_08EA:
	mov	al,20h
	call	07DAh
	loop	08EAh

l1EDA_08F1:
	mov	al,[si-1h]
	xor	ah,ah

l1EDA_08F6:
	mov	cx,ax
	jcxz	0901h

l1EDA_08FA:
	cld
	lodsb
	call	07DAh
	loop	08FAh

l1EDA_0901:
	pop	di
	pop	es
	mov	es:[di+8h],bx
	pop	ds
	pop	bp
	retf	6h
1EDA:090C                                     B1 03 EB 0A             ....
1EDA:0910 B1 02 EB 06 B1 01 EB 02                         ........        

;; fn1EDA_0918: 1EDA:0918
;;   Called from:
;;     0800:3AA1 (in fn0800_391E)
;;     0800:3B3E (in fn0800_391E)
;;     0800:3B8A (in fn0800_391E)
fn1EDA_0918 proc
	mov	cl,0h
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	push	es
	push	di
	call	0776h
	jnz	0943h

l1EDA_0927:
	call	079Ah
	cmp	al,1Ah
	jz	0947h

l1EDA_092E:
	test	cl,1h
	jz	0937h

l1EDA_0933:
	cmp	al,0Dh
	jz	0947h

l1EDA_0937:
	test	cl,2h
	jz	0943h

l1EDA_093C:
	cmp	al,20h
	ja	0943h

l1EDA_0940:
	inc	bx
	jmp	0927h

l1EDA_0943:
	mov	al,0h
	jmp	0949h

l1EDA_0947:
	mov	al,1h

l1EDA_0949:
	pop	di
	pop	es
	mov	es:[di+8h],bx
	pop	bp
	retf	4h

;; fn1EDA_0953: 1EDA:0953
;;   Called from:
;;     1229:09A7 (in fn1229_0735)
;;     1AB8:11B4 (in fn1AB8_11A0)
;;     1AB8:11E4 (in fn1AB8_11A0)
;;     1AB8:139A (in fn1AB8_1384)
fn1EDA_0953 proc
	mov	bx,sp
	mov	dx,ds
	lds	si,ss:[bx+0Ah]
	les	di,ss:[bx+6h]
	mov	cx,ss:[bx+4h]
	cld
	rep movsb
	mov	ds,dx
	retf	0Ah
1EDA:096B                                  8B C8 8B DA               .... 

;; fn1EDA_096F: 1EDA:096F
;;   Called from:
;;     0800:3C28 (in fn0800_3BF2)
;;     0800:3C9A (in fn0800_3C72)
;;     0C74:1042 (in fn0C74_0FA1)
;;     0C74:15F4 (in fn0C74_0FA1)
;;     0C74:16CE (in fn0C74_0FA1)
;;     0C74:184A (in fn0C74_0FA1)
;;     0C74:18BD (in fn0C74_0FA1)
;;     0C74:197D (in fn0C74_0FA1)
;;     0C74:1AF3 (in fn0C74_0FA1)
;;     0C74:1C2B (in fn0C74_1B3B)
;;     0C74:1D6D (in fn0C74_1B3B)
;;     0C74:1FA9 (in fn0C74_1F08)
;;     0C74:255B (in fn0C74_1F08)
;;     0C74:2651 (in fn0C74_1F08)
;;     0C74:26CD (in fn0C74_1F08)
;;     0C74:2740 (in fn0C74_1F08)
;;     0C74:28F9 (in fn0C74_1F08)
;;     0C74:2A8B (in fn0C74_1F08)
;;     0C74:2B86 (in fn0C74_2AD9)
;;     1AB8:1216 (in fn1AB8_11FB)
fn1EDA_096F proc
	mov	si,ax
	mov	di,dx
	mul	cx
	push	ax
	push	dx
	mov	ax,si
	mul	bx
	mov	bx,ax
	mov	ax,di
	mul	cx
	mov	cx,ax
	pop	dx
	pop	ax
	add	dx,bx
	add	dx,cx
	retf

;; fn1EDA_098A: 1EDA:098A
;;   Called from:
;;     0800:0C80 (in fn0800_0C71)
;;     0800:0C98 (in fn0800_0C71)
;;     0C74:031F (in fn0C74_02D8)
;;     0C74:0337 (in fn0C74_02D8)
;;     0C74:104C (in fn0C74_0FA1)
;;     0C74:15FE (in fn0C74_0FA1)
;;     0C74:16D8 (in fn0C74_0FA1)
;;     0C74:1854 (in fn0C74_0FA1)
;;     0C74:18C7 (in fn0C74_0FA1)
;;     0C74:1987 (in fn0C74_0FA1)
;;     0C74:1AFD (in fn0C74_0FA1)
;;     0C74:1C35 (in fn0C74_1B3B)
;;     0C74:1D77 (in fn0C74_1B3B)
;;     0C74:1FB3 (in fn0C74_1F08)
;;     0C74:2565 (in fn0C74_1F08)
;;     0C74:265B (in fn0C74_1F08)
;;     0C74:26D7 (in fn0C74_1F08)
;;     0C74:274A (in fn0C74_1F08)
;;     0C74:2903 (in fn0C74_1F08)
;;     0C74:2A95 (in fn0C74_1F08)
;;     0C74:2B90 (in fn0C74_2AD9)
;;     1AB8:121D (in fn1AB8_11FB)
;;     1EDA:117E (in fn1EDA_116A)
fn1EDA_098A proc
	push	bp
	mov	bp,cx
	or	bp,bx
	jz	09F1h

l1EDA_0991:
	or	bx,bx
	pushf
	jns	09A0h

l1EDA_0996:
	not	cx
	not	bx
	add	cx,1h
	adc	bx,0h

l1EDA_09A0:
	or	dx,dx
	pushf
	jns	09AFh

l1EDA_09A5:
	not	ax
	not	dx
	add	ax,1h
	adc	dx,0h

l1EDA_09AF:
	mov	si,cx
	mov	di,bx
	xor	cx,cx
	xor	bx,bx
	mov	bp,21h

l1EDA_09BA:
	rcl	cx,1h
	rcl	bx,1h
	sub	cx,si
	sbb	bx,di
	jnc	09C8h

l1EDA_09C4:
	add	cx,si
	adc	bx,di

l1EDA_09C8:
	cmc
	rcl	ax,1h
	rcl	dx,1h
	dec	bp
	jnz	09BAh

l1EDA_09D0:
	popf
	jns	09E2h

l1EDA_09D3:
	not	cx
	not	bx
	add	cx,1h
	adc	bx,0h
	popf
	jns	09E5h

l1EDA_09E0:
	jmp	09EFh

l1EDA_09E2:
	popf
	jns	09EFh

l1EDA_09E5:
	not	ax
	not	dx
	add	ax,1h
	adc	dx,0h

l1EDA_09EF:
	pop	bp
	retf

l1EDA_09F1:
	pop	bp
	mov	ax,0C8h
	jmp	00E2h
1EDA:09F8                         83 E1 1F 74 06 D1 EA D1         ...t....
1EDA:0A00 D8 E2 FA CB 83 E1 1F 74 06 D1 E0 D1 D2 E2 FA CB .......t........
1EDA:0A10 0B D2 7D 0A F7 D0 F7 D2 05 01 00 83 D2 00 CB    ..}............ 

;; fn1EDA_0A1F: 1EDA:0A1F
;;   Called from:
;;     0800:0694 (in fn0800_0619)
;;     0800:06C0 (in fn0800_0619)
;;     0800:06F3 (in fn0800_0619)
;;     0800:072F (in fn0800_0619)
;;     0800:0AD5 (in fn0800_0AA1)
;;     0800:0B76 (in fn0800_0B42)
;;     0800:0E4B (in fn0800_0D20)
;;     0800:0E9B (in fn0800_0D20)
;;     0800:100A (in fn0800_0D20)
;;     0800:2246 (in fn0800_21E7)
;;     0800:2294 (in fn0800_21E7)
;;     0800:3FAC (in fn0800_3D9D)
;;     0C74:0151 (in fn0C74_011E)
;;     0C74:023F (in fn0C74_020C)
;;     1229:0107 (in fn1229_0040)
;;     1229:024A (in fn1229_0040)
;;     1229:056E (in fn1229_050A)
;;     1229:0670 (in fn1229_061B)
;;     1229:078B (in fn1229_0735)
;;     1229:081C (in fn1229_0735)
;;     1229:0A27 (in fn1229_09F9)
;;     1229:0A56 (in fn1229_09F9)
;;     133F:02BE (in fn133F_026B)
;;     13E2:01CE (in fn13E2_0193)
;;     1AB8:02E9 (in fn1AB8_027E)
;;     1AB8:0323 (in fn1AB8_027E)
;;     1AB8:03AE (in fn1AB8_027E)
;;     1AB8:0454 (in fn1AB8_027E)
;;     1AB8:04BC (in fn1AB8_027E)
;;     1AB8:08D9 (in fn1AB8_0887)
;;     1AB8:09AE (in fn1AB8_097B)
;;     1AB8:0D35 (in fn1AB8_0BAE)
;;     1AB8:1619 (in fn1AB8_1536)
fn1EDA_0A1F proc
	cld
	mov	bx,sp
	mov	dx,ds
	les	di,ss:[bx+8h]
	lds	si,ss:[bx+4h]
	lodsb
	stosb
	mov	cl,al
	xor	ch,ch
	rep movsb
	mov	ds,dx
	retf	4h

;; fn1EDA_0A39: 1EDA:0A39
;;   Called from:
;;     0800:0258 (in fn0800_01FE)
;;     0800:066B (in fn0800_0619)
;;     0800:067E (in fn0800_0619)
;;     0800:06AA (in fn0800_0619)
;;     0800:06D6 (in fn0800_0619)
;;     0800:0ABF (in fn0800_0AA1)
;;     0800:0AEB (in fn0800_0AA1)
;;     0800:0B60 (in fn0800_0B42)
;;     0800:0B8C (in fn0800_0B42)
;;     0800:0D32 (in fn0800_0D20)
;;     0800:0D97 (in fn0800_0D20)
;;     0800:102D (in fn0800_0D20)
;;     0800:1198 (in fn0800_0D20)
;;     0800:11CF (in fn0800_0D20)
;;     0800:1231 (in fn0800_11EF)
;;     0800:12F1 (in fn0800_11EF)
;;     0800:19F3 (in fn0800_19E1)
;;     0800:1AF1 (in fn0800_19E1)
;;     0800:2611 (in fn0800_2401)
;;     0800:2932 (in fn0800_2827)
;;     0800:2DD0 (in fn0800_2C0C)
;;     0800:31D9 (in fn0800_31B7)
;;     0800:322C (in fn0800_31B7)
;;     0800:323D (in fn0800_31B7)
;;     0800:40D4 (in fn0800_3D9D)
;;     0C43:00C9 (in fn0C43_00B9)
;;     0C74:0012 (in fn0C74_0000)
;;     0C74:0073 (in fn0C74_004B)
;;     0C74:013B (in fn0C74_011E)
;;     0C74:0167 (in fn0C74_011E)
;;     0C74:0229 (in fn0C74_020C)
;;     0C74:0255 (in fn0C74_020C)
;;     11C8:0068 (in fn11C8_0000)
;;     1229:0052 (in fn1229_0040)
;;     1229:026D (in fn1229_0040)
;;     1229:0385 (in fn1229_0040)
;;     1229:03B4 (in fn1229_039D)
;;     1229:03C7 (in fn1229_039D)
;;     1229:051C (in fn1229_050A)
;;     1229:05B7 (in fn1229_050A)
;;     1229:0694 (in fn1229_061B)
;;     1229:07B1 (in fn1229_0735)
;;     1229:07CA (in fn1229_0735)
;;     1229:0870 (in fn1229_0735)
;;     1229:0889 (in fn1229_0735)
;;     1229:0976 (in fn1229_0735)
;;     1229:0A40 (in fn1229_09F9)
;;     1229:0A6F (in fn1229_09F9)
;;     1229:0A82 (in fn1229_09F9)
;;     1229:0C3C (in fn1229_0AA8)
;;     1229:0DBE (in fn1229_0CCE)
;;     1229:0DDE (in fn1229_0DCC)
;;     1229:0E03 (in fn1229_0DCC)
;;     1229:113A (in fn1229_0DCC)
;;     1229:114B (in fn1229_0DCC)
;;     133F:015D (in fn133F_014B)
;;     133F:02F1 (in fn133F_02DF)
;;     133F:0329 (in fn133F_02DF)
;;     133F:0349 (in fn133F_02DF)
;;     133F:0364 (in fn133F_0352)
;;     133F:04F0 (in fn133F_04DE)
;;     13C1:005E (in fn13C1_0036)
;;     13E2:01A5 (in fn13E2_0193)
;;     1AB8:002B (in fn1AB8_0000)
;;     1AB8:029B (in fn1AB8_027E)
;;     1AB8:02B6 (in fn1AB8_027E)
;;     1AB8:02D1 (in fn1AB8_027E)
;;     1AB8:030B (in fn1AB8_027E)
;;     1AB8:0345 (in fn1AB8_027E)
;;     1AB8:0360 (in fn1AB8_027E)
;;     1AB8:037B (in fn1AB8_027E)
;;     1AB8:0396 (in fn1AB8_027E)
;;     1AB8:03D0 (in fn1AB8_027E)
;;     1AB8:03EB (in fn1AB8_027E)
;;     1AB8:0406 (in fn1AB8_027E)
;;     1AB8:0421 (in fn1AB8_027E)
;;     1AB8:043C (in fn1AB8_027E)
;;     1AB8:0476 (in fn1AB8_027E)
;;     1AB8:0490 (in fn1AB8_027E)
;;     1AB8:04AA (in fn1AB8_027E)
;;     1AB8:04E8 (in fn1AB8_027E)
;;     1AB8:089D (in fn1AB8_0887)
;;     1AB8:08B1 (in fn1AB8_0887)
;;     1AB8:0991 (in fn1AB8_097B)
;;     1AB8:09C6 (in fn1AB8_097B)
;;     1AB8:0BC4 (in fn1AB8_0BAE)
;;     1AB8:0D00 (in fn1AB8_0BAE)
;;     1AB8:0D4D (in fn1AB8_0BAE)
;;     1AB8:14A8 (in fn1AB8_1492)
;;     1AB8:1631 (in fn1AB8_1536)
;;     1AB8:1799 (in fn1AB8_1783)
;;     1EDA:0BC6 (in fn1EDA_0B7C)
;;     1EDA:0C1C (in fn1EDA_0BD0)
fn1EDA_0A39 proc
	cld
	mov	bx,sp
	mov	dx,ds
	lds	si,ss:[bx+0Ah]
	les	di,ss:[bx+6h]
	mov	cx,ss:[bx+4h]
	lodsb
	cmp	al,cl
	jbe	0A51h

l1EDA_0A4F:
	mov	al,cl

l1EDA_0A51:
	stosb
	mov	cl,al
	xor	ch,ch
	rep movsb
	mov	ds,dx
	retf	0Ah
1EDA:0A5D                                        8B DC 36              ..6
1EDA:0A60 C4 7F 04 26 8A 05 32 E4 CA 04 00                ...&..2....     

;; fn1EDA_0A6B: 1EDA:0A6B
;;   Called from:
;;     1229:084F (in fn1229_0735)
;;     133F:031B (in fn133F_02DF)
;;     1EDA:0B97 (in fn1EDA_0B7C)
;;     1EDA:0BB6 (in fn1EDA_0B7C)
;;     1EDA:0BF1 (in fn1EDA_0BD0)
;;     1EDA:0C0B (in fn1EDA_0BD0)
fn1EDA_0A6B proc
	cld
	mov	bx,sp
	mov	dx,ds
	les	di,ss:[bx+0Ch]
	lds	si,ss:[bx+8h]
	mov	al,[si]
	xor	ah,ah
	mov	cx,ss:[bx+6h]
	or	cx,cx
	jg	0A87h

l1EDA_0A84:
	mov	cx,1h

l1EDA_0A87:
	add	si,cx
	sub	ax,cx
	jc	0AA0h

l1EDA_0A8D:
	inc	ax
	mov	cx,ss:[bx+4h]
	or	cx,cx
	jge	0A98h

l1EDA_0A96:
	xor	cx,cx

l1EDA_0A98:
	cmp	ax,cx
	jbe	0AA2h

l1EDA_0A9C:
	mov	ax,cx
	jmp	0AA2h

l1EDA_0AA0:
	xor	ax,ax

l1EDA_0AA2:
	stosb
	mov	cx,ax
	rep movsb
	mov	ds,dx
	retf	8h

;; fn1EDA_0AAC: 1EDA:0AAC
;;   Called from:
;;     0800:069E (in fn0800_0619)
;;     0800:06CA (in fn0800_0619)
;;     0800:06FD (in fn0800_0619)
;;     0800:0739 (in fn0800_0619)
;;     0800:0ADF (in fn0800_0AA1)
;;     0800:0B80 (in fn0800_0B42)
;;     0800:0E56 (in fn0800_0D20)
;;     0800:0EA6 (in fn0800_0D20)
;;     0800:0EB1 (in fn0800_0D20)
;;     0800:101F (in fn0800_0D20)
;;     0800:225F (in fn0800_21E7)
;;     0800:2269 (in fn0800_21E7)
;;     0800:229E (in fn0800_21E7)
;;     0800:22A8 (in fn0800_21E7)
;;     0800:3FB6 (in fn0800_3D9D)
;;     0800:3FC0 (in fn0800_3D9D)
;;     0C74:015B (in fn0C74_011E)
;;     0C74:0249 (in fn0C74_020C)
;;     1229:0112 (in fn1229_0040)
;;     1229:025F (in fn1229_0040)
;;     1229:0579 (in fn1229_050A)
;;     1229:0583 (in fn1229_050A)
;;     1229:059C (in fn1229_050A)
;;     1229:05A6 (in fn1229_050A)
;;     1229:067A (in fn1229_061B)
;;     1229:0684 (in fn1229_061B)
;;     1229:0795 (in fn1229_0735)
;;     1229:079F (in fn1229_0735)
;;     1229:0826 (in fn1229_0735)
;;     1229:0830 (in fn1229_0735)
;;     1229:0854 (in fn1229_0735)
;;     1229:085E (in fn1229_0735)
;;     1229:0A32 (in fn1229_09F9)
;;     1229:0A61 (in fn1229_09F9)
;;     1229:0B96 (in fn1229_0AA8)
;;     1229:0BA0 (in fn1229_0AA8)
;;     1229:0BAA (in fn1229_0AA8)
;;     1229:0BB4 (in fn1229_0AA8)
;;     1229:0BC6 (in fn1229_0AA8)
;;     1229:0BD0 (in fn1229_0AA8)
;;     1229:0BE2 (in fn1229_0AA8)
;;     1229:0BEC (in fn1229_0AA8)
;;     1229:0BFE (in fn1229_0AA8)
;;     1229:0C08 (in fn1229_0AA8)
;;     1229:0C1A (in fn1229_0AA8)
;;     1229:0C24 (in fn1229_0AA8)
;;     1229:0C2E (in fn1229_0AA8)
;;     133F:02C8 (in fn133F_026B)
;;     133F:02D2 (in fn133F_026B)
;;     13E2:01D8 (in fn13E2_0193)
;;     13E2:01E2 (in fn13E2_0193)
;;     13E2:01EC (in fn13E2_0193)
;;     1AB8:02F3 (in fn1AB8_027E)
;;     1AB8:02FD (in fn1AB8_027E)
;;     1AB8:032D (in fn1AB8_027E)
;;     1AB8:0337 (in fn1AB8_027E)
;;     1AB8:03B8 (in fn1AB8_027E)
;;     1AB8:03C2 (in fn1AB8_027E)
;;     1AB8:045E (in fn1AB8_027E)
;;     1AB8:0468 (in fn1AB8_027E)
;;     1AB8:04D0 (in fn1AB8_027E)
;;     1AB8:04DA (in fn1AB8_027E)
;;     1AB8:08E4 (in fn1AB8_0887)
;;     1AB8:09B8 (in fn1AB8_097B)
;;     1AB8:0D3F (in fn1AB8_0BAE)
;;     1AB8:1623 (in fn1AB8_1536)
;;     1EDA:0BA0 (in fn1EDA_0B7C)
;;     1EDA:0BBA (in fn1EDA_0B7C)
;;     1EDA:0C0F (in fn1EDA_0BD0)
fn1EDA_0AAC proc
	cld
	mov	bx,sp
	mov	dx,ds
	les	di,ss:[bx+8h]
	lds	si,ss:[bx+4h]
	mov	cl,es:[di]
	xor	ch,ch
	lodsb
	add	es:[di],al
	jnc	0ACCh

l1EDA_0AC4:
	mov	byte ptr es:[di],0FFh
	mov	al,cl
	not	al

l1EDA_0ACC:
	add	di,cx
	inc	di
	mov	cl,al
	rep movsb
	mov	ds,dx
	retf	4h

;; fn1EDA_0AD8: 1EDA:0AD8
;;   Called from:
;;     0800:42A2 (in fn0800_4255)
;;     0800:42BD (in fn0800_4255)
fn1EDA_0AD8 proc
	cld
	mov	bx,sp
	push	ds
	lds	si,ss:[bx+8h]
	les	di,ss:[bx+4h]
	mov	cl,es:[di]
	xor	ch,ch
	jcxz	0B14h

l1EDA_0AEB:
	inc	di
	lodsb
	cmp	al,1h
	jc	0B1Ah

l1EDA_0AF1:
	ja	0AFBh

l1EDA_0AF3:
	lodsb

l1EDA_0AF4:
	repne scasb

l1EDA_0AF6:
	jnz	0B14h

l1EDA_0AF8:
	dec	di
	jmp	0B1Ah

l1EDA_0AFB:
	xor	ah,ah
	mov	dx,cx
	sub	dx,ax
	jc	0B14h

l1EDA_0B03:
	inc	dx

l1EDA_0B04:
	mov	cx,ax
	rep cmpsb
	jz	0B18h

l1EDA_0B0A:
	sub	cx,ax
	add	si,cx
	add	di,cx
	inc	di
	dec	dx
	jnz	0B04h

l1EDA_0B14:
	xor	ax,ax
	jmp	0B20h

l1EDA_0B18:
	sub	di,ax

l1EDA_0B1A:
	mov	ax,di
	sub	ax,ss:[bx+4h]

l1EDA_0B20:
	pop	ds
	retf	8h

;; fn1EDA_0B24: 1EDA:0B24
;;   Called from:
;;     0800:064A (in fn0800_0619)
;;     0800:12A7 (in fn0800_11EF)
;;     0800:1300 (in fn0800_11EF)
;;     0800:259C (in fn0800_2401)
;;     0800:2863 (in fn0800_2827)
;;     0800:2C37 (in fn0800_2C0C)
;;     0800:2C57 (in fn0800_2C0C)
;;     0800:2D5E (in fn0800_2C0C)
;;     0800:2D98 (in fn0800_2C0C)
;;     0800:2E12 (in fn0800_2C0C)
;;     0800:2E67 (in fn0800_2C0C)
;;     0800:2EB3 (in fn0800_2C0C)
;;     0800:30A8 (in fn0800_2C0C)
;;     0800:40C1 (in fn0800_3D9D)
;;     1229:045A (in fn1229_039D)
;;     1229:046B (in fn1229_039D)
;;     1229:06A3 (in fn1229_061B)
;;     1229:1119 (in fn1229_0DCC)
;;     1AB8:0613 (in fn1AB8_05D3)
;;     1AB8:0677 (in fn1AB8_05D3)
;;     1AB8:06F6 (in fn1AB8_06CA)
;;     1AB8:078D (in fn1AB8_06CA)
fn1EDA_0B24 proc
	cld
	mov	bx,sp
	mov	dx,ds
	lds	si,ss:[bx+8h]
	les	di,ss:[bx+4h]
	lodsb
	mov	ah,es:[di]
	inc	di
	mov	cl,al
	cmp	cl,ah
	jbe	0B3Eh

l1EDA_0B3C:
	mov	cl,ah

l1EDA_0B3E:
	or	cl,cl
	jz	0B48h

l1EDA_0B42:
	xor	ch,ch
	rep cmpsb
	jnz	0B4Ah

l1EDA_0B48:
	cmp	al,ah

l1EDA_0B4A:
	mov	ds,dx
	retf	8h

;; fn1EDA_0B4F: 1EDA:0B4F
;;   Called from:
;;     0800:0FF4 (in fn0800_0D20)
;;     0800:101A (in fn0800_0D20)
;;     0800:1568 (in fn0800_149F)
;;     0800:15DC (in fn0800_149F)
;;     0800:174B (in fn0800_166D)
;;     0800:17BF (in fn0800_166D)
;;     11C8:0033 (in fn11C8_0000)
;;     1229:0234 (in fn1229_0040)
;;     1229:025A (in fn1229_0040)
fn1EDA_0B4F proc
	cld
	mov	bx,sp
	les	di,ss:[bx+6h]
	mov	al,1h
	stosb
	mov	al,ss:[bx+4h]
	stosb
	retf	2h

;; fn1EDA_0B61: 1EDA:0B61
;;   Called from:
;;     1AB8:0609 (in fn1AB8_05D3)
;;     1AB8:06EC (in fn1AB8_06CA)
;;     1AB8:0788 (in fn1AB8_06CA)
fn1EDA_0B61 proc
	cld
	mov	bx,sp
	mov	dx,ds
	les	di,ss:[bx+0Ah]
	lds	si,ss:[bx+6h]
	mov	ax,ss:[bx+4h]
	stosb
	mov	cx,ax
	rep movsb
	mov	ds,dx
	retf	6h

;; fn1EDA_0B7C: 1EDA:0B7C
;;   Called from:
;;     11C8:0043 (in fn11C8_0000)
fn1EDA_0B7C proc
	push	bp
	mov	bp,sp
	sub	sp,200h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	mov	ax,1h
	push	ax
	mov	ax,[bp+6h]
	dec	ax
	push	ax
	push	cs
	call	0A6Bh
	les	di,[bp+0Eh]
	push	es
	push	di
	push	cs
	call	0AACh
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	push	word ptr [bp+6h]
	mov	ax,0FFh
	push	ax
	push	cs
	call	0A6Bh
	push	cs
	call	0AACh
	les	di,[bp+0Ah]
	push	es
	push	di
	push	word ptr [bp+8h]
	push	cs
	call	0A39h
	mov	sp,bp
	pop	bp
	retf	0Ch

;; fn1EDA_0BD0: 1EDA:0BD0
;;   Called from:
;;     0800:116C (in fn0800_0D20)
;;     1229:0344 (in fn1229_0040)
fn1EDA_0BD0 proc
	push	bp
	mov	bp,sp
	sub	sp,200h
	cmp	word ptr [bp+6h],0h
	jle	0C20h

l1EDA_0BDD:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	mov	ax,1h
	push	ax
	mov	ax,[bp+8h]
	dec	ax
	push	ax
	push	cs
	call	0A6Bh
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	mov	ax,[bp+8h]
	add	ax,[bp+6h]
	push	ax
	mov	ax,0FFh
	push	ax
	push	cs
	call	0A6Bh
	push	cs
	call	0AACh
	les	di,[bp+0Ah]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	push	cs
	call	0A39h

l1EDA_0C20:
	mov	sp,bp
	pop	bp
	retf	8h
1EDA:0C26                   FC 8B DC 8C DA 36 C4 7F 0A 36       .....6...6
1EDA:0C30 C5 77 06 36 8B 5F 04 8A CF 32 ED 32 C0 F3 AA 8A .w.6._...2.2....
1EDA:0C40 CB F3 A4 B1 20 2A CB 2A CF F3 AA 8E DA CA 06 00 .... *.*........
1EDA:0C50 FC 8B DC 36 C4 7F 04 B9 10 00 33 C0 F3 AB CB 8B ...6......3.....
1EDA:0C60 DC 36 C4 7F 06 36 8A 47 04 8A D8 32 FF B1 03 D3 .6...6.G...2....
1EDA:0C70 EB 8A C8 80 E1 07 B0 01 D2 E0 26 08 01 CA 02 00 ..........&.....
1EDA:0C80 8B DC 36 C4 7F 08 36 8A 47 06 36 8A 57 04 2A D0 ..6...6.G.6.W.*.
1EDA:0C90 72 1F FE C2 8A D8 32 FF B1 03 D3 EB 8A C8 80 E1 r.....2.........
1EDA:0CA0 07 B0 01 D2 E0 26 08 01 D0 C0 83 D3 00 FE CA 75 .....&.........u
1EDA:0CB0 F4 CA 04 00 FC 8B DC 8C DA 36 C5 77 0A 36 C4 7F .........6.w.6..
1EDA:0CC0 06 36 8B 5F 04 8A CF 32 ED 03 F1 8A CB F3 A4 8E .6._...2........
1EDA:0CD0 DA CA 0A 00                                     ....            

;; fn1EDA_0CD4: 1EDA:0CD4
;;   Called from:
;;     0800:0A7C (in fn0800_09C2)
;;     0800:0A8F (in fn0800_09C2)
;;     0800:158F (in fn0800_149F)
;;     0800:1772 (in fn0800_166D)
;;     0800:1EE7 (in fn0800_1E3F)
;;     0800:1F62 (in fn0800_1E3F)
;;     0800:209E (in fn0800_2004)
;;     0800:2125 (in fn0800_2004)
;;     0800:3603 (in fn0800_31B7)
;;     0800:362B (in fn0800_31B7)
;;     0800:3B61 (in fn0800_391E)
;;     0800:431B (in fn0800_4255)
;;     0800:438D (in fn0800_4255)
;;     0C74:017D (in fn0C74_011E)
;;     0C74:01D2 (in fn0C74_011E)
;;     0C74:026B (in fn0C74_020C)
;;     0C74:02C8 (in fn0C74_020C)
;;     0C74:0810 (in fn0C74_076B)
fn1EDA_0CD4 proc
	mov	bx,sp
	les	di,ss:[bx+4h]
	mov	al,ss:[bx+8h]
	mov	bl,al
	xor	bh,bh
	mov	cl,3h
	shr	bx,cl
	mov	cl,al
	and	cl,7h
	mov	al,1h
	shl	al,cl
	test	es:[bx+di],al
	retf	6h
1EDA:0CF5                FC 8B DC 8C DA 36 C4 7F 08 36 C5      .....6...6.
1EDA:0D00 77 04 B9 10 00 AD 26 0B 05 AB E2 F9 8E DA CA 04 w.....&.........
1EDA:0D10 00 FC 8B DC 8C DA 36 C4 7F 08 36 C5 77 04 B9 10 ......6...6.w...
1EDA:0D20 00 AD F7 D0 26 23 05 AB E2 F7 8E DA CA 04 00 FC ....&#..........
1EDA:0D30 8B DC 8C DA 36 C4 7F 08 36 C5 77 04 B9 10 00 AD ....6...6.w.....
1EDA:0D40 26 23 05 AB E2 F9 8E DA CA 04 00 FC 8B DC 8C DA &#..............
1EDA:0D50 36 C4 7F 08 36 C5 77 04 B9 10 00 F3 A7 8E DA CA 6...6.w.........
1EDA:0D60 08 00 FC 8B DC 8C DA 36 C4 7F 08 36 C5 77 04 B9 .......6...6.w..
1EDA:0D70 10 00 AD 26 0B 05 AF 75 02 E2 F7 8E DA CA 08 00 ...&...u........

;; fn1EDA_0D80: 1EDA:0D80
;;   Called from:
;;     0800:161F (in fn0800_149F)
;;     0800:162F (in fn0800_149F)
;;     0800:1802 (in fn0800_166D)
;;     0800:1812 (in fn0800_166D)
;;     0C74:07D9 (in fn0C74_076B)
;;     0C74:07EC (in fn0C74_076B)
;;     0C74:0829 (in fn0C74_076B)
;;     0C74:083F (in fn0C74_076B)
;;     0C74:085C (in fn0C74_076B)
;;     0C74:0885 (in fn0C74_076B)
;;     0C74:0924 (in fn0C74_076B)
;;     0C74:095B (in fn0C74_076B)
;;     0C74:0A91 (in fn0C74_0A35)
;;     0C74:0AB6 (in fn0C74_0A35)
;;     0C74:0AED (in fn0C74_0A35)
;;     0C74:0B03 (in fn0C74_0A35)
;;     0C74:0B20 (in fn0C74_0A35)
;;     0C74:0B48 (in fn0C74_0A35)
;;     0C74:0BE6 (in fn0C74_0A35)
;;     0C74:0C1D (in fn0C74_0A35)
fn1EDA_0D80 proc
	call	0DCFh
	xor	ax,ax
	mov	bx,sp
	mov	bx,ss:[bx+4h]
	or	bx,bx
	jz	0D93h

l1EDA_0D8F:
	xchg	dx,ax
	div	bx
	xchg	dx,ax

l1EDA_0D93:
	retf	2h
1EDA:0D96                   E8 36 00 93 B8 80 00 B9 20 00       .6...... .
1EDA:0DA0 F6 C6 80 75 0A D1 E3 D1 D2 FE C8 E2 F3 32 C0 80 ...u.........2..
1EDA:0DB0 E6 7F CB E8 19 00 CD 3C 9F 06 CD 0D CD 37 06 82 .......<.....7..
1EDA:0DC0 53 CD 35 E1 CD 35 FD CD 39 D9 CD 3D CB E1 FF    S.5..5..9..=... 

;; fn1EDA_0DCF: 1EDA:0DCF
;;   Called from:
;;     1EDA:0D80 (in fn1EDA_0D80)
fn1EDA_0DCF proc
	mov	ax,[5382h]
	mov	bx,[5384h]
	mov	cx,ax
	mul	word ptr cs:[0E05h]
	shl	cx,1h
	shl	cx,1h
	shl	cx,1h
	add	ch,cl
	add	dx,cx
	add	dx,bx
	shl	bx,1h
	shl	bx,1h
	add	dx,bx
	add	dh,bl
	mov	cl,5h
	shl	bx,cl
	add	dh,bl
	add	ax,1h
	adc	dx,0h
	mov	[5382h],ax
	mov	[5384h],dx
	ret
1EDA:0E05                05 84                                 ..         

;; fn1EDA_0E07: 1EDA:0E07
;;   Called from:
;;     0800:4367 (in fn0800_4255)
fn1EDA_0E07 proc
	mov	ah,2Ch
	int	21h
	mov	[5382h],cx
	mov	[5384h],dx
	retf

;; fn1EDA_0E14: 1EDA:0E14
;;   Called from:
;;     1EDA:0F37 (in fn1EDA_0F26)
fn1EDA_0E14 proc
	push	di
	cld
	mov	bx,ax
	or	dx,dx
	jge	0E29h

l1EDA_0E1C:
	not	bx
	not	dx
	add	bx,1h
	adc	dx,0h
	mov	al,2Dh
	stosb

l1EDA_0E29:
	mov	si,0E66h
	mov	cl,9h

l1EDA_0E2E:
	cmp	dx,cs:[si+2h]
	jc	0E3Bh

l1EDA_0E34:
	ja	0E42h

l1EDA_0E36:
	cmp	bx,cs:[si]
	jnc	0E42h

l1EDA_0E3B:
	add	si,4h
	dec	cl
	jnz	0E2Eh

l1EDA_0E42:
	inc	cl

l1EDA_0E44:
	mov	al,2Fh

l1EDA_0E46:
	inc	al
	sub	bx,cs:[si]
	sbb	dx,cs:[si+2h]
	jnc	0E46h

l1EDA_0E51:
	add	bx,cs:[si]
	adc	dx,cs:[si+2h]
	add	si,4h
	stosb
	dec	cl
	jnz	0E44h

l1EDA_0E60:
	mov	cx,di
	pop	di
	sub	cx,di
	ret
1EDA:0E66                   00 CA 9A 3B 00 E1 F5 05 80 96       ...;......
1EDA:0E70 98 00 40 42 0F 00 A0 86 01 00 10 27 00 00 E8 03 ..@B.......'....
1EDA:0E80 00 00 64 00 00 00 0A 00 00 00 01 00 00 00       ..d...........  

;; fn1EDA_0E8E: 1EDA:0E8E
;;   Called from:
;;     1EDA:0F88 (in fn1EDA_0F71)
fn1EDA_0E8E proc
	xor	ax,ax
	xor	dx,dx
	xor	si,si
	jcxz	0EEFh

l1EDA_0E96:
	cmp	byte ptr es:[di],2Bh
	jz	0EA3h

l1EDA_0E9C:
	cmp	byte ptr es:[di],2Dh
	jnz	0EA7h

l1EDA_0EA2:
	inc	si

l1EDA_0EA3:
	inc	di
	dec	cx
	jcxz	0EEFh

l1EDA_0EA7:
	cmp	byte ptr es:[di],24h
	jz	0EF1h

l1EDA_0EAD:
	mov	bl,es:[di]
	sub	bl,3Ah
	add	bl,0Ah
	jnc	0EE0h

l1EDA_0EB8:
	test	dx,0F000h
	jnz	0EEFh

l1EDA_0EBE:
	push	bx
	shl	ax,1h
	rcl	dx,1h
	push	dx
	push	ax
	shl	ax,1h
	rcl	dx,1h
	shl	ax,1h
	rcl	dx,1h
	pop	bx
	add	ax,bx
	pop	bx
	adc	dx,bx
	pop	bx
	xor	bh,bh
	add	ax,bx
	adc	dx,0h
	js	0EEFh

l1EDA_0EDD:
	inc	di
	loop	0EADh

l1EDA_0EE0:
	dec	si
	jnz	0EEDh

l1EDA_0EE3:
	not	ax
	not	dx
	add	ax,1h
	adc	dx,0h

l1EDA_0EED:
	clc
	ret

l1EDA_0EEF:
	stc
	ret

l1EDA_0EF1:
	inc	di
	dec	cx
	jcxz	0EEFh

l1EDA_0EF5:
	mov	bl,es:[di]
	cmp	bl,61h
	jc	0F00h

l1EDA_0EFD:
	sub	bl,20h

l1EDA_0F00:
	sub	bl,3Ah
	add	bl,0Ah
	jc	0F13h

l1EDA_0F08:
	sub	bl,17h
	add	bl,6h
	jnc	0EE0h

l1EDA_0F10:
	add	bl,0Ah

l1EDA_0F13:
	mov	bh,4h

l1EDA_0F15:
	shl	ax,1h
	rcl	dx,1h
	jc	0EEFh

l1EDA_0F1B:
	dec	bh
	jnz	0F15h

l1EDA_0F1F:
	or	al,bl
	inc	di
	loop	0EF5h

l1EDA_0F24:
	jmp	0EE0h

;; fn1EDA_0F26: 1EDA:0F26
;;   Called from:
;;     0C74:0060 (in fn0C74_004B)
;;     1229:0A11 (in fn1229_09F9)
;;     133F:0287 (in fn133F_026B)
;;     133F:02A4 (in fn133F_026B)
;;     13C1:004B (in fn13C1_0036)
;;     1AB8:0018 (in fn1AB8_0000)
fn1EDA_0F26 proc
	push	bp
	mov	bp,sp
	sub	sp,20h
	mov	ax,[bp+0Eh]
	mov	dx,[bp+10h]
	lea	di,[bp-20h]
	push	ss
	pop	es
	call	0E14h
	push	ds
	mov	si,di
	push	ss
	pop	ds
	les	di,[bp+8h]
	mov	dx,[bp+6h]
	mov	ax,[bp+0Ch]
	cmp	ax,dx
	jle	0F4Eh

l1EDA_0F4C:
	mov	ax,dx

l1EDA_0F4E:
	cmp	cx,dx
	jle	0F54h

l1EDA_0F52:
	mov	cx,dx

l1EDA_0F54:
	cmp	ax,cx
	jge	0F5Ah

l1EDA_0F58:
	mov	ax,cx

l1EDA_0F5A:
	cld
	stosb
	sub	ax,cx
	jz	0F68h

l1EDA_0F60:
	push	cx
	mov	cx,ax
	mov	al,20h

l1EDA_0F65:
	rep stosb

l1EDA_0F67:
	pop	cx

l1EDA_0F68:
	rep movsb
	pop	ds
	mov	sp,bp
	pop	bp
	retf	0Ch

;; fn1EDA_0F71: 1EDA:0F71
;;   Called from:
;;     0800:4303 (in fn0800_4255)
;;     1229:05C8 (in fn1229_050A)
fn1EDA_0F71 proc
	push	bp
	mov	bp,sp
	les	di,[bp+0Ah]
	mov	cl,es:[di]
	xor	ch,ch
	inc	di
	jcxz	0F88h

l1EDA_0F7F:
	cmp	byte ptr es:[di],20h
	jnz	0F88h

l1EDA_0F85:
	inc	di
	loop	0F7Fh

l1EDA_0F88:
	call	0E8Eh
	jc	0F8Fh

l1EDA_0F8D:
	jcxz	0F98h

l1EDA_0F8F:
	mov	cx,di
	sub	cx,[bp+0Ah]
	xor	ax,ax
	xor	dx,dx

l1EDA_0F98:
	les	di,[bp+6h]
	mov	es:[di],cx
	pop	bp
	retf	8h

;; fn1EDA_0FA2: 1EDA:0FA2
;;   Called from:
;;     0800:017F (in fn0800_0147)
;;     0800:020C (in fn0800_01FE)
;;     0800:0422 (in fn0800_03F8)
;;     0800:1257 (in fn0800_11EF)
;;     0800:2431 (in fn0800_2401)
;;     0800:2884 (in fn0800_2827)
;;     0800:3670 (in fn0800_31B7)
;;     0800:4187 (in fn0800_4168)
;;     0C43:00DE (in fn0C43_00B9)
;;     0C74:0420 (in fn0C74_03D4)
;;     1229:0408 (in fn1229_039D)
;;     1229:0494 (in fn1229_0486)
;;     1229:0911 (in fn1229_0735)
;;     1AB8:08E9 (in fn1AB8_0887)
;;     1AB8:091B (in fn1AB8_0887)
fn1EDA_0FA2 proc
	mov	bx,sp
	push	ds
	les	di,ss:[bx+8h]
	lds	si,ss:[bx+4h]
	cld
	xor	ax,ax
	stosw
	mov	ax,0D7B0h
	stosw
	xor	ax,ax
	mov	cx,16h

l1EDA_0FBA:
	rep stosw

l1EDA_0FBC:
	lodsb
	cmp	al,4Fh
	jbe	0FC3h

l1EDA_0FC1:
	mov	al,4Fh

l1EDA_0FC3:
	mov	cl,al
	xor	ch,ch
	rep movsb
	xor	al,al
	stosb
	pop	ds
	retf	8h

;; fn1EDA_0FD0: 1EDA:0FD0
;;   Called from:
;;     0800:018E (in fn0800_0147)
;;     0800:0219 (in fn0800_01FE)
;;     0800:0431 (in fn0800_03F8)
;;     0800:1265 (in fn0800_11EF)
;;     0800:243F (in fn0800_2401)
;;     0800:2892 (in fn0800_2827)
;;     0800:367E (in fn0800_31B7)
;;     0800:4194 (in fn0800_4168)
;;     0C43:00EB (in fn0C43_00B9)
;;     0C74:042F (in fn0C74_03D4)
;;     1229:0415 (in fn1229_039D)
;;     1229:04A1 (in fn1229_0486)
;;     1229:091E (in fn1229_0735)
;;     1AB8:08F7 (in fn1AB8_0887)
;;     1AB8:0929 (in fn1AB8_0887)
fn1EDA_0FD0 proc
	mov	al,[5386h]
	mov	ah,3Dh
	xor	dx,dx
	jmp	0FDFh
1EDA:0FD9                            B8 00 3C BA 01 00             ..<... 

l1EDA_0FDF:
	push	bp
	mov	bp,sp
	les	di,[bp+8h]
	cmp	word ptr es:[di+2h],0D7B0h
	jz	1007h

l1EDA_0FED:
	cmp	word ptr es:[di+2h],0D7B3h
	jz	0FFDh

l1EDA_0FF5:
	mov	word ptr [5380h],66h
	jmp	1031h

l1EDA_0FFD:
	push	ax
	push	dx
	push	es
	push	di
	push	cs
	call	1051h
	pop	dx
	pop	ax

l1EDA_1007:
	cmp	byte ptr es:[di+30h],0h
	jz	1020h

l1EDA_100E:
	push	ds
	lea	dx,[di+30h]
	push	es
	pop	ds
	xor	cx,cx
	int	21h
	pop	ds
	jnc	1021h

l1EDA_101B:
	mov	[5380h],ax
	jmp	1031h

l1EDA_1020:
	xchg	dx,ax

l1EDA_1021:
	mov	word ptr es:[di+2h],0D7B3h
	mov	es:[di],ax
	mov	ax,[bp+6h]
	mov	es:[di+4h],ax

l1EDA_1031:
	pop	bp
	retf	6h
1EDA:1035                8B DC 36 C4 7F 04 E8 38 00 75 0E      ..6....8.u.
1EDA:1040 33 C9 26 8B 1D B4 40 CD 21 73 03 A3 80 53 CA 04 3.&...@.!s...S..
1EDA:1050 00                                              .               

;; fn1EDA_1051: 1EDA:1051
;;   Called from:
;;     0800:01EF (in fn0800_0147)
;;     0800:0247 (in fn0800_01FE)
;;     0800:04C5 (in fn0800_03F8)
;;     0800:12DB (in fn0800_11EF)
;;     0800:2471 (in fn0800_2401)
;;     0800:28C4 (in fn0800_2827)
;;     0800:36BF (in fn0800_31B7)
;;     0800:41BB (in fn0800_4168)
;;     0C43:00A1 (in fn0C43_0095)
;;     0C74:05B1 (in fn0C74_03D4)
;;     1229:0477 (in fn1229_039D)
;;     1229:04F7 (in fn1229_0486)
;;     1229:09E6 (in fn1229_0735)
;;     1AB8:0962 (in fn1AB8_0887)
;;     1AB8:0A8C (in fn1AB8_097B)
;;     1AB8:16AC (in fn1AB8_1536)
;;     1AB8:16DF (in fn1AB8_1536)
;;     1EDA:1001 (in fn1EDA_0FD0)
fn1EDA_1051 proc
	mov	bx,sp
	les	di,ss:[bx+4h]
	call	1076h
	jnz	1073h

l1EDA_105C:
	mov	bx,es:[di]
	cmp	bx,4h
	jbe	106Dh

l1EDA_1064:
	mov	ah,3Eh
	int	21h
	jnc	106Dh

l1EDA_106A:
	mov	[5380h],ax

l1EDA_106D:
	mov	word ptr es:[di+2h],0D7B0h

l1EDA_1073:
	retf	4h

;; fn1EDA_1076: 1EDA:1076
;;   Called from:
;;     1EDA:1057 (in fn1EDA_1051)
;;     1EDA:1097 (in fn1EDA_1091)
;;     1EDA:10CD (in fn1EDA_10BB)
;;     1EDA:1129 (in fn1EDA_1123)
fn1EDA_1076 proc
	cmp	word ptr es:[di+2h],0D7B3h
	jz	1084h

l1EDA_107E:
	mov	word ptr [5380h],67h

l1EDA_1084:
	ret

;; fn1EDA_1085: 1EDA:1085
;;   Called from:
;;     0800:023A (in fn0800_01FE)
;;     0800:1290 (in fn0800_11EF)
;;     0800:2463 (in fn0800_2401)
;;     0800:28B6 (in fn0800_2827)
;;     1229:0430 (in fn1229_039D)
;;     1229:04C2 (in fn1229_0486)
fn1EDA_1085 proc
	mov	ah,3Fh
	mov	dx,64h
	jmp	1091h

;; fn1EDA_108C: 1EDA:108C
;;   Called from:
;;     0800:36AC (in fn0800_31B7)
;;     1229:0949 (in fn1229_0735)
;;     1229:09BC (in fn1229_0735)
fn1EDA_108C proc
	mov	ah,40h
	mov	dx,65h

;; fn1EDA_1091: 1EDA:1091
;;   Called from:
;;     1EDA:108A (in fn1EDA_1085)
;;     1EDA:108E (in fn1EDA_108C)
fn1EDA_1091 proc
	push	bp
	mov	bp,sp
	les	di,[bp+0Ah]
	call	1076h
	jnz	10B7h

l1EDA_109C:
	push	ds
	push	dx
	lds	dx,[bp+6h]
	mov	cx,es:[di+4h]
	mov	bx,es:[di]
	int	21h
	pop	dx
	pop	ds
	jc	10B4h

l1EDA_10AE:
	cmp	ax,cx
	jz	10B7h

l1EDA_10B2:
	mov	ax,dx

l1EDA_10B4:
	mov	[5380h],ax

l1EDA_10B7:
	pop	bp
	retf	4h

;; fn1EDA_10BB: 1EDA:10BB
;;   Called from:
;;     0800:01DE (in fn0800_0147)
;;     0800:04A3 (in fn0800_03F8)
;;     0C43:0129 (in fn0C43_00B9)
;;     0C43:01AA (in fn0C43_00B9)
;;     0C43:0245 (in fn0C43_00B9)
;;     0C43:027C (in fn0C43_00B9)
;;     0C74:04BC (in fn0C74_03D4)
;;     0C74:04DE (in fn0C74_03D4)
;;     0C74:0581 (in fn0C74_03D4)
;;     1AB8:0A82 (in fn1AB8_097B)
;;     1AB8:16D5 (in fn1AB8_1536)
fn1EDA_10BB proc
	mov	bl,3Fh
	mov	cx,64h
	jmp	10C7h
1EDA:10C2       B3 40 B9 65 00                              .@.e.         

l1EDA_10C7:
	push	bp
	mov	bp,sp
	les	di,[bp+10h]
	call	1076h
	jnz	1111h

l1EDA_10D2:
	mov	ax,[bp+0Ah]
	or	ax,ax
	jz	10F5h

l1EDA_10D9:
	push	ds
	push	cx
	mul	word ptr es:[di+4h]
	mov	cx,ax
	lds	dx,[bp+0Ch]
	mov	ah,bl
	mov	bx,es:[di]
	int	21h
	pop	cx
	pop	ds
	jc	110Eh

l1EDA_10EF:
	xor	dx,dx
	div	word ptr es:[di+4h]

l1EDA_10F5:
	les	di,[bp+6h]
	mov	dx,es
	or	dx,di
	jz	1103h

l1EDA_10FE:
	mov	es:[di],ax
	jmp	111Fh

l1EDA_1103:
	cmp	ax,[bp+0Ah]
	jz	111Fh

l1EDA_1108:
	mov	[5380h],cx
	jmp	111Fh

l1EDA_110E:
	mov	[5380h],ax

l1EDA_1111:
	les	di,[bp+6h]
	mov	dx,es
	or	dx,di
	jz	111Fh

l1EDA_111A:
	xor	ax,ax
	mov	es:[di],ax

l1EDA_111F:
	pop	bp
	retf	0Eh

;; fn1EDA_1123: 1EDA:1123
;;   Called from:
;;     0800:022B (in fn0800_01FE)
;;     0800:2452 (in fn0800_2401)
;;     0800:28A5 (in fn0800_2827)
;;     0800:3696 (in fn0800_31B7)
;;     0C43:0177 (in fn0C43_00B9)
;;     0C43:0229 (in fn0C43_00B9)
;;     1229:04B3 (in fn1229_0486)
;;     1229:0935 (in fn1229_0735)
fn1EDA_1123 proc
	push	bp
	mov	bp,sp
	les	di,[bp+0Ah]
	call	1076h
	jnz	114Fh

l1EDA_112E:
	mov	ax,[bp+8h]
	mul	word ptr es:[di+4h]
	mov	cx,ax
	mov	ax,[bp+6h]
	mul	word ptr es:[di+4h]
	add	cx,dx
	mov	dx,ax
	mov	bx,es:[di]
	mov	ax,4200h
	int	21h
	jnc	114Fh

l1EDA_114C:
	mov	[5380h],ax

l1EDA_114F:
	pop	bp
	retf	8h
1EDA:1153          E8 44 00 72 0F 26 8B 4D 04 83 F9 01 74    .D.r.&.M....t
1EDA:1160 06 33 DB 0E E8 23 F8 CA 04 00                   .3...#....      

;; fn1EDA_116A: 1EDA:116A
;;   Called from:
;;     0800:41A3 (in fn0800_4168)
;;     0C43:0154 (in fn0C43_00B9)
;;     1229:09CE (in fn1229_0735)
;;     1AB8:0943 (in fn1AB8_0887)
fn1EDA_116A proc
	call	119Ah
	jc	1182h

l1EDA_116F:
	mov	ax,cx
	mov	dx,bx
	mov	cx,es:[di+4h]
	cmp	cx,1h
	jz	1182h

l1EDA_117C:
	xor	bx,bx
	push	cs
	call	098Ah

l1EDA_1182:
	retf	4h

;; fn1EDA_1185: 1EDA:1185
;;   Called from:
;;     0800:12B4 (in fn0800_11EF)
;;     0C43:01F4 (in fn0C43_00B9)
;;     1229:0447 (in fn1229_039D)
;;     1229:095B (in fn1229_0735)
fn1EDA_1185 proc
	call	119Ah
	jc	1195h

l1EDA_118A:
	sub	ax,cx
	sbb	dx,bx
	jc	1195h

l1EDA_1190:
	mov	al,1h
	retf	4h

l1EDA_1195:
	xor	al,al
	retf	4h

;; fn1EDA_119A: 1EDA:119A
;;   Called from:
;;     1EDA:116A (in fn1EDA_116A)
;;     1EDA:1185 (in fn1EDA_1185)
fn1EDA_119A proc
	mov	bx,sp
	les	di,ss:[bx+6h]
	cmp	word ptr es:[di+2h],0D7B3h
	jnz	11D3h

l1EDA_11A8:
	xor	cx,cx
	xor	dx,dx
	mov	bx,es:[di]
	mov	ax,4201h
	int	21h
	push	dx
	push	ax
	xor	cx,cx
	xor	dx,dx
	mov	bx,es:[di]
	mov	ax,4202h
	int	21h
	pop	bx
	pop	cx
	push	dx
	push	ax
	mov	dx,bx
	mov	bx,es:[di]
	mov	ax,4200h
	int	21h
	pop	cx
	pop	bx
	ret

l1EDA_11D3:
	mov	word ptr [5380h],67h
	xor	ax,ax
	xor	dx,dx
	stc
	ret

;; fn1EDA_11DF: 1EDA:11DF
;;   Called from:
;;     1AB8:05A7 (in fn1AB8_0569)
;;     1AB8:0E3F (in fn1AB8_0BAE)
;;     1AB8:132A (in fn1AB8_129A)
fn1EDA_11DF proc
	mov	bx,sp
	mov	dx,ds
	lds	si,ss:[bx+0Ah]
	les	di,ss:[bx+6h]
	mov	cx,ss:[bx+4h]
	cld
	cmp	si,di
	jnc	11FBh

l1EDA_11F4:
	add	si,cx
	add	di,cx
	dec	si
	dec	di
	std

l1EDA_11FB:
	rep movsb
	mov	ds,dx
	retf	0Ah

;; fn1EDA_1202: 1EDA:1202
;;   Called from:
;;     1AB8:0B50 (in fn1AB8_0AEE)
;;     1AB8:0D7D (in fn1AB8_0BAE)
fn1EDA_1202 proc
	mov	bx,sp
	les	di,ss:[bx+8h]
	mov	cx,ss:[bx+6h]
	mov	al,ss:[bx+4h]
	cld

l1EDA_1211:
	rep stosb

l1EDA_1213:
	retf	8h

;; fn1EDA_1216: 1EDA:1216
;;   Called from:
;;     0800:429D (in fn0800_4255)
;;     0800:42B8 (in fn0800_4255)
;;     0800:42F9 (in fn0800_4255)
fn1EDA_1216 proc
	push	bp
	mov	bp,sp
	mov	dx,[bp+6h]
	or	dx,dx
	jz	1225h

l1EDA_1220:
	call	126Ch
	jmp	1255h

l1EDA_1225:
	mov	ah,30h
	int	21h
	cmp	al,3h
	mov	ax,0h
	jc	1255h

l1EDA_1230:
	mov	es,[537Ch]
	mov	es,es:[002Ch]
	xor	di,di
	cld

l1EDA_123C:
	cmp	al,es:[di]
	jz	1248h

l1EDA_1241:
	mov	cx,0FFFFh
	repne scasb
	jmp	123Ch

l1EDA_1248:
	add	di,3h
	mov	si,di
	mov	cx,100h

l1EDA_1250:
	repne scasb

l1EDA_1252:
	xchg	cx,ax
	not	al

l1EDA_1255:
	push	ds
	push	es
	pop	ds
	les	di,[bp+8h]
	cld
	stosb
	xchg	cx,ax
	rep movsb
	pop	ds
	pop	bp
	retf	2h

;; fn1EDA_1265: 1EDA:1265
;;   Called from:
;;     0800:42D6 (in fn0800_4255)
fn1EDA_1265 proc
	xor	dx,dx
	call	126Ch
	xchg	bx,ax
	retf

;; fn1EDA_126C: 1EDA:126C
;;   Called from:
;;     1EDA:1220 (in fn1EDA_1216)
;;     1EDA:1267 (in fn1EDA_1265)
fn1EDA_126C proc
	mov	es,[537Ch]
	mov	di,80h
	mov	cl,es:[di]
	xor	ch,ch
	inc	di
	xor	bx,bx

l1EDA_127B:
	jcxz	1286h

l1EDA_127D:
	cmp	byte ptr es:[di],20h
	ja	1286h

l1EDA_1283:
	inc	di
	loop	127Dh

l1EDA_1286:
	mov	si,di
	jcxz	1293h

l1EDA_128A:
	cmp	byte ptr es:[di],20h
	jbe	1293h

l1EDA_1290:
	inc	di
	loop	128Ah

l1EDA_1293:
	mov	ax,di
	sub	ax,si
	jz	129Dh

l1EDA_1299:
	inc	bx
	dec	dx
	jnz	127Bh

l1EDA_129D:
	ret

;; fn1EDA_129E: 1EDA:129E
;;   Called from:
;;     0800:437F (in fn0800_4255)
fn1EDA_129E proc
	push	bp
	mov	bp,sp
	sub	sp,80h
	push	ds
	lea	si,[bp-80h]
	push	ss
	pop	ds
	mov	al,[bp+0Ch]
	or	al,al
	jnz	12B8h

l1EDA_12B2:
	mov	ah,19h
	int	21h
	inc	al

l1EDA_12B8:
	mov	dl,al
	add	al,40h
	mov	[si],al
	inc	si
	mov	word ptr [si],5C3Ah
	inc	si
	inc	si
	mov	ah,47h
	int	21h
	jnc	12CEh

l1EDA_12CB:
	mov	byte ptr [si],0h

l1EDA_12CE:
	lea	si,[bp-80h]
	les	di,[bp+8h]
	mov	cx,[bp+6h]
	xor	bx,bx
	cld

l1EDA_12DA:
	lodsb
	or	al,al
	jz	12E5h

l1EDA_12DF:
	inc	bx
	mov	es:[bx+di],al
	loop	12DAh

l1EDA_12E5:
	mov	es:[di],bl
	pop	ds
	mov	sp,bp
	pop	bp
	retf	8h
1EDA:12EF                                              55                U
1EDA:12F0 8B EC 81 EC 80 00 E8 61 00 8B 46 80 0A C0 74 2A .......a..F...t*
1EDA:1300 80 FC 3A 75 20 24 DF 2C 41 8A D0 B4 0E CD 21 B4 ..:u $.,A.....!.
1EDA:1310 19 CD 21 3A C2 74 08 C7 06 80 53 0F 00 EB 0B 80 ..!:.t....S.....
1EDA:1320 7E 82 00 74 05 B4 3B E8 4B 00 8B E5 5D CA 04 00 ~..t..;.K...]...
1EDA:1330 55 8B EC 81 EC 80 00 E8 20 00 B4 39 E8 36 00 8B U....... ..9.6..
1EDA:1340 E5 5D CA 04 00 55 8B EC 81 EC 80 00 E8 0B 00 B4 .]...U..........
1EDA:1350 3A E8 21 00 8B E5 5D CA 04 00 1E C5 76 06 8D 7E :.!...].....v..~
1EDA:1360 80 16 07 FC AC 3C 7F 72 02 B0 7F 98 8B C8 F3 A4 .....<.r........
1EDA:1370 32 C0 AA 1F C3 1E 8D 56 80 16 1F CD 21 1F 73 03 2......V....!.s.
1EDA:1380 A3 80 53 C3                                     ..S.            

;; fn1EDA_1384: 1EDA:1384
;;   Called from:
;;     0800:0F7E (in fn0800_0D20)
;;     0800:3B1E (in fn0800_391E)
;;     1229:01ED (in fn1229_0040)
;;     1229:03E4 (in fn1229_039D)
;;     133F:058B (in fn133F_0528)
fn1EDA_1384 proc
	mov	bx,sp
	mov	al,ss:[bx+4h]
	cmp	al,61h
	jc	1394h

l1EDA_138E:
	cmp	al,7Ah
	ja	1394h

l1EDA_1392:
	sub	al,20h

l1EDA_1394:
	retf	2h
1EDA:1397                      00 00 00 00 00 00 00 00 00        .........
