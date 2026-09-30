;;; Segment 1229 (1229:0000)

;; fn1229_0000: 1229:0000
;;   Called from:
;;     1229:00A7 (in fn1229_0040)
;;     1229:0315 (in fn1229_0040)
fn1229_0000 proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
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
	retf	8h
1229:0036                   02 41 41 04 41 41 41 41 01 41       .AA.AAAA.A

;; fn1229_0040: 1229:0040
;;   Called from:
;;     1229:05AB (in fn1229_050A)
;;     1229:0689 (in fn1229_061B)
;;     1229:07A4 (in fn1229_0735)
;;     1229:0863 (in fn1229_0735)
fn1229_0040 proc
	enter	410h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	push	0Bh
	call	far 1AB8h:1C32h
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	call	far 1AB8h:13A3h
	mov	[bp+0FEFAh],ax
	push	word ptr [bp+0FEFAh]
	call	far 1EDAh:023Fh
	mov	[bp+0FEFCh],ax
	mov	[bp+0FEFEh],dx
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	les	di,[bp+0FEFCh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	cs
	call	0000h
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	call	far 1AB8h:112Eh
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	mov	ax,[bp+0Ah]
	sub	ax,[bp+0Eh]
	shr	ax,1h
	add	ax,[bp+0Eh]
	mov	[bp+0FDF4h],ax
	mov	di,36h
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	add	ax,[bp+10h]
	push	ax
	push	word ptr [bp+0FDF4h]
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	mov	di,39h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1AB8h:1E0Bh
	add	ax,[bp+10h]
	push	ax
	push	word ptr [bp+0FDF4h]
	call	far 1AB8h:108Bh
	call	far 1AB8h:10A8h
	mov	[bp+0FDF6h],ax
	mov	byte ptr [bp+0FDFAh],0h
	mov	byte ptr [bp+0FDF9h],25h
	xor	ax,ax
	mov	[bp+0FDF0h],ax

l1229_0142:
	inc	word ptr [bp+0FDF0h]
	cmp	word ptr [bp+0FDF0h],1388h
	jnz	0176h

l1229_014E:
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

l1229_0176:
	cmp	word ptr [bp+0FDF0h],2710h
	jnz	01ACh

l1229_017E:
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

l1229_01AC:
	call	far 1E78h:02FBh
	or	al,al
	jnz	01B8h

l1229_01B5:
	jmp	0349h

l1229_01B8:
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
	mov	al,[bp+0FDF9h]
	cmp	al,15h
	jc	0275h

l1229_01FE:
	cmp	al,0FFh
	ja	0275h

l1229_0202:
	mov	di,36h
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	mov	dx,ax
	mov	ax,[bp+0Ch]
	sub	ax,dx
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10A8h
	cwd
	pop	cx
	pop	bx
	cmp	dx,bx
	jl	0229h

l1229_0223:
	jg	0272h

l1229_0225:
	cmp	ax,cx
	jnc	0272h

l1229_0229:
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	mov	al,[bp+0FDF9h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1AB8h:1492h
	lea	di,[bp+0FBF0h]
	push	ss
	push	di
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FCF0h]
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

l1229_0272:
	jmp	0349h

l1229_0275:
	cmp	al,8h
	jz	027Ch

l1229_0279:
	jmp	0349h

l1229_027C:
	call	far 1AB8h:10A8h
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0FDF6h]
	xor	dx,dx
	cmp	dx,bx
	jl	029Ch

l1229_0290:
	jle	0295h

l1229_0292:
	jmp	0349h

l1229_0295:
	cmp	ax,cx
	jc	029Ch

l1229_0299:
	jmp	0349h

l1229_029C:
	call	far 1AB8h:10A8h
	mov	[bp+0FDF2h],ax
	mov	di,3Eh
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
	mov	di,3Eh
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
	mov	di,3Eh
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
	mov	di,3Eh
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
	push	cs
	call	0000h
	mov	di,3Eh
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

l1229_0349:
	cmp	byte ptr [bp+0FDF9h],0Dh
	jz	0353h

l1229_0350:
	jmp	0142h

l1229_0353:
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
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
	les	di,[bp+12h]
	push	es
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	retf	0Ch
1229:038E                                           06 4E               .N
1229:0390 4F 4E 41 4D 45 07 52 41 44 2E 44 41 54          ONAME.RAD.DAT   

;; fn1229_039D: 1229:039D
;;   Called from:
;;     1229:0E1E (in fn1229_0DCC)
fn1229_039D proc
	enter	82h,0h
	cmp	byte ptr [6BBAh],0h
	jz	03BBh

l1229_03A8:
	mov	di,6BBAh
	push	ds
	push	di
	mov	di,6BB2h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	jmp	03CCh

l1229_03BB:
	mov	di,38Eh
	push	cs
	push	di
	mov	di,6BB2h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h

l1229_03CC:
	mov	byte ptr [bp+0FF7Fh],1h
	jmp	03D7h

l1229_03D3:
	inc	byte ptr [bp+0FF7Fh]

l1229_03D7:
	mov	al,[bp+0FF7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+6BB2h]
	push	ax
	call	far 1EDAh:1384h
	mov	dl,al
	mov	al,[bp+0FF7Fh]
	xor	ah,ah
	mov	di,ax
	mov	[di+6BB2h],dl
	cmp	byte ptr [bp+0FF7Fh],6h
	jnz	03D3h

l1229_03FE:
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,395h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp-80h]
	push	ss
	push	di
	push	219h
	call	far 1EDAh:0FD0h
	mov	word ptr [598Eh],0FFFFh
	mov	word ptr [5990h],0FFFFh

l1229_0426:
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:1085h
	add	sp,4h
	add	word ptr [598Eh],1h
	adc	word ptr [5990h],0h
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1185h
	or	al,al
	jnz	0472h

l1229_0450:
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,6BB2h
	push	ds
	push	di
	call	far 1EDAh:0B24h
	jz	0472h

l1229_0461:
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,38Eh
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	0426h

l1229_0472:
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	leave
	ret
1229:047E                                           07 52               .R
1229:0480 41 44 2E 44 41 54                               AD.DAT          

;; fn1229_0486: 1229:0486
;;   Called from:
;;     1229:0FBB (in fn1229_0DCC)
;;     1229:101F (in fn1229_0DCC)
fn1229_0486 proc
	enter	82h,0h
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,47Eh
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
	call	far 1EDAh:04A2h
	or	ax,ax
	jz	04F2h

l1229_04D3:
	sub	word ptr [598Eh],1h
	sbb	word ptr [5990h],0h
	push	96h
	call	far 1E78h:02C7h
	push	1F4h
	call	far 1E78h:029Ch
	call	far 1E78h:02F4h

l1229_04F2:
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	call	far 1EDAh:04A9h
	leave
	ret
1229:0503          01 20 01 28 02 29 3A                      . .(.):      

;; fn1229_050A: 1229:050A
;;   Called from:
;;     1229:0897 (in fn1229_0735)
;;     1229:08A6 (in fn1229_0735)
;;     1229:08B5 (in fn1229_0735)
;;     1229:08C4 (in fn1229_0735)
;;     1229:08D3 (in fn1229_0735)
;;     1229:08EE (in fn1229_0735)
fn1229_050A proc
	enter	40Ah,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	lea	di,[bp+0FBF6h]
	push	ss
	push	di
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,68h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,10h
	push	ax
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,68h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,10h
	push	ax
	lea	di,[bp+0FDF6h]
	push	ss
	push	di
	mov	di,503h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	mov	di,505h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FCF6h]
	push	ss
	push	di
	mov	al,[bp+4h]
	xor	ah,ah
	xor	dx,dx
	push	dx
	push	ax
	call	far 13C1h:0036h
	call	far 1EDAh:0AACh
	mov	di,507h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	cs
	call	0040h
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	lea	di,[bp+0FEF8h]
	push	ss
	push	di
	call	far 1EDAh:0F71h
	mov	[bp+0FEF6h],ax
	cmp	word ptr [bp+0FEF8h],0h
	jz	05E1h

l1229_05D8:
	mov	al,[bp+4h]
	xor	ah,ah
	mov	[bp+0FEF6h],ax

l1229_05E1:
	mov	al,[bp+0FEF6h]
	mov	[bp-1h],al

l1229_05E8:
	call	far 1E78h:02FBh
	or	al,al
	jnz	05E8h

l1229_05F1:
	mov	al,[bp-1h]
	leave
	ret	6h
1229:05F8                         01 20 1E 20 41 20 45 54         . . A ET
1229:0600 45 20 4D 4F 44 49 46 49 45 2E 20 53 41 55 56 45 E MODIFIE. SAUVE
1229:0610 52 28 4F 2F 4E 29 20 3F 3A 01 4F                R(O/N) ?:.O     

;; fn1229_061B: 1229:061B
;;   Called from:
;;     1229:0FA7 (in fn1229_0DCC)
;;     1229:100B (in fn1229_0DCC)
;;     1229:1064 (in fn1229_0DCC)
;;     1229:10A2 (in fn1229_0DCC)
fn1229_061B proc
	enter	208h,0h
	mov	byte ptr [bp-1h],0h
	lea	di,[bp+0FDF8h]
	push	ss
	push	di
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,0B0h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,10h
	push	ax
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,0B0h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,10h
	push	ax
	lea	di,[bp+0FEF8h]
	push	ss
	push	di
	mov	di,5F8h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,5FAh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	cs
	call	0040h
	lea	di,[bp-4h]
	push	ss
	push	di
	push	1h
	call	far 1EDAh:0A39h
	lea	di,[bp-4h]
	push	ss
	push	di
	mov	di,619h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	06AEh

l1229_06AA:
	mov	byte ptr [bp-1h],1h

l1229_06AE:
	push	0Fh
	call	far 1AB8h:1C32h

l1229_06B5:
	call	far 1E78h:02FBh
	or	al,al
	jnz	06B5h

l1229_06BE:
	mov	al,[bp-1h]
	leave
	ret
1229:06C3          05 4E 6F 6D 20 28 03 29 20 3A 05 41 69    .Nom (.) :.Ai
1229:06D0 64 65 28 01 29 02 20 3A 0C 4E 6F 6D 62 72 65 20 de(.). :.Nombre 
1229:06E0 50 75 73 68 73 0C 4E 6F 6D 62 72 65 20 70 6F 6E Pushs.Nombre pon
1229:06F0 74 73 0C 4E 6F 6D 62 72 65 20 42 6C 61 73 74 0C ts.Nombre Blast.
1229:0700 43 6F 6F 72 64 58 20 52 6F 62 6F 74 0C 43 6F 6F CoordX Robot.Coo
1229:0710 72 64 59 20 52 6F 62 6F 74 0C 44 82 6C 61 69 20 rdY Robot.D.lai 
1229:0720 64 65 20 6A 65 75 07 52 41 44 2E 44 41 54 06 4E de jeu.RAD.DAT.N
1229:0730 4F 4E 41 4D 45                                  ONAME           

;; fn1229_0735: 1229:0735
;;   Called from:
;;     1229:0FAE (in fn1229_0DCC)
;;     1229:1012 (in fn1229_0DCC)
;;     1229:106B (in fn1229_0DCC)
;;     1229:10A9 (in fn1229_0DCC)
fn1229_0735 proc
	enter	79Ch,0h
	call	far 133Fh:0137h
	lea	di,[bp+0F964h]
	push	ss
	push	di
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,68h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,10h
	push	ax
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,68h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,10h
	push	ax
	lea	di,[bp+0FA64h]
	push	ss
	push	di
	mov	di,6C3h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,6C9h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	cs
	call	0040h
	lea	di,[bp+0FC64h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp+0FC64h],0h
	jz	07CFh

l1229_07BD:
	lea	di,[bp+0FC64h]
	push	ss
	push	di
	mov	di,5CB4h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h

l1229_07CF:
	lea	di,[bp+0F864h]
	push	ss
	push	di
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,128h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,10h
	push	ax
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,128h
	push	ax
	call	far 1AB8h:10E1h
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,10h
	push	ax
	lea	di,[bp+0FA64h]
	push	ss
	push	di
	mov	di,6CDh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,6D3h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0F964h]
	push	ss
	push	di
	mov	di,4FC4h
	push	ds
	push	di
	push	1h
	mov	al,[5CBBh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,1Eh
	sub	ax,dx
	push	ax
	call	far 1EDAh:0A6Bh
	call	far 1EDAh:0AACh
	mov	di,6D5h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	push	cs
	call	0040h
	lea	di,[bp+0FB64h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp+0FB64h],0h
	jz	088Eh

l1229_087C:
	lea	di,[bp+0FB64h]
	push	ss
	push	di
	mov	di,5CBBh
	push	ds
	push	di
	push	1Eh
	call	far 1EDAh:0A39h

l1229_088E:
	mov	di,6D8h
	push	cs
	push	di
	mov	al,[5CDAh]
	push	ax
	call	050Ah
	mov	[5CDAh],al
	mov	di,6E5h
	push	cs
	push	di
	mov	al,[5CDBh]
	push	ax
	call	050Ah
	mov	[5CDBh],al
	mov	di,6F2h
	push	cs
	push	di
	mov	al,[5CDDh]
	push	ax
	call	050Ah
	mov	[5CDDh],al
	mov	di,6FFh
	push	cs
	push	di
	mov	al,[5CDEh]
	push	ax
	call	050Ah
	mov	[5CDEh],al
	mov	di,70Ch
	push	cs
	push	di
	mov	al,[5CDFh]
	push	ax
	call	050Ah
	mov	[5CDFh],al
	cmp	byte ptr [5CDCh],0Ah
	jbe	08E5h

l1229_08E0:
	mov	byte ptr [5CDCh],0Ah

l1229_08E5:
	mov	di,719h
	push	cs
	push	di
	mov	al,[5CDCh]
	push	ax
	call	050Ah
	mov	[5CDCh],al
	cmp	byte ptr [5CDCh],0Ah
	jbe	0900h

l1229_08FB:
	mov	byte ptr [5CDCh],0Ah

l1229_0900:
	push	0Fh
	call	far 1AB8h:1C32h
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,726h
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
	push	word ptr [5990h]
	push	word ptr [598Eh]
	call	far 1EDAh:1123h
	call	far 1EDAh:04A9h
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:108Ch
	add	sp,4h
	call	far 1EDAh:04A9h
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1185h
	call	far 1EDAh:04A9h
	or	al,al
	jz	09C9h

l1229_0969:
	mov	di,72Eh
	push	cs
	push	di
	lea	di,[bp+0FD66h]
	push	ss
	push	di
	push	6h
	call	far 1EDAh:0A39h
	mov	byte ptr [bp+0FD8Ch],63h
	mov	byte ptr [bp+0FD8Dh],63h
	mov	byte ptr [bp+0FD8Eh],0Ah
	mov	byte ptr [bp+0FD8Fh],63h
	mov	byte ptr [bp+0FD90h],0h
	mov	byte ptr [bp+0FD91h],0h
	mov	di,4DD6h
	push	ds
	push	di
	lea	di,[bp+0FD92h]
	push	ss
	push	di
	push	1EDh
	call	far 1EDAh:0953h
	mov	byte ptr [bp+0FD6Dh],0h
	lea	di,[bp-80h]
	push	ss
	push	di
	lea	di,[bp+0FD66h]
	push	ss
	push	di
	call	far 1EDAh:108Ch
	add	sp,4h
	call	far 1EDAh:04A9h

l1229_09C9:
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
	call	far 133Fh:0141h
	leave
	ret
1229:09F7                      01 30                             .0       

;; fn1229_09F9: 1229:09F9
;;   Called from:
;;     1229:0B8E (in fn1229_0AA8)
;;     1229:0BC3 (in fn1229_0AA8)
;;     1229:0BDF (in fn1229_0AA8)
;;     1229:0BFB (in fn1229_0AA8)
;;     1229:0C17 (in fn1229_0AA8)
fn1229_09F9 proc
	enter	200h,0h
	mov	al,[bp+4h]
	xor	ah,ah
	xor	dx,dx
	push	dx
	push	ax
	push	0h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0F26h
	cmp	byte ptr [bp+4h],0Ah
	jnc	0A45h

l1229_0A1C:
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	mov	di,9F7h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l1229_0A45:
	cmp	byte ptr [bp+4h],64h
	jnc	0A74h

l1229_0A4B:
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	mov	di,9F7h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l1229_0A74:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	les	di,[bp+6h]
	push	es
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	ret	2h
1229:0A8B                                  01 20 05 54 49            . .TI
1229:0A90 4D 45 3A 06 20 50 55 53 48 3A 06 20 42 4C 4F 57 ME:. PUSH:. BLOW
1229:0AA0 3A 06 20 50 41 53 53 3A                         :. PASS:        

;; fn1229_0AA8: 1229:0AA8
;;   Called from:
;;     1229:0CF7 (in fn1229_0CCE)
;;     1229:0FC3 (in fn1229_0DCC)
;;     1229:1027 (in fn1229_0DCC)
fn1229_0AA8 proc
	enter	602h,0h
	push	1h
	push	1h
	push	27Eh
	push	176h
	push	1h
	call	far 1AB8h:0F93h
	call	far 1AB8h:1028h
	push	0h
	push	0h
	push	27Fh
	push	1DFh
	push	1h
	call	far 1AB8h:0F93h
	mov	byte ptr [bp-2h],0h
	jmp	0ADCh

l1229_0AD9:
	inc	byte ptr [bp-2h]

l1229_0ADC:
	mov	byte ptr [bp-1h],0h
	jmp	0AE5h

l1229_0AE2:
	inc	byte ptr [bp-1h]

l1229_0AE5:
	mov	al,[bp-1h]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-2h]
	xor	ah,ah
	imul	di,ax,1Dh
	add	di,dx
	cmp	byte ptr [di+5CE0h],0h
	jz	0B3Ah

l1229_0AFD:
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
	mov	dx,ax
	mov	al,[bp-2h]
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

l1229_0B3A:
	cmp	byte ptr [bp-1h],1Ch
	jnz	0AE2h

l1229_0B40:
	cmp	byte ptr [bp-2h],10h
	jnz	0AD9h

l1229_0B46:
	push	word ptr [50C4h]
	push	178h
	push	27Eh
	push	182h
	push	1h
	call	far 1AB8h:0F93h
	call	far 1AB8h:1028h
	push	0h
	push	0h
	push	27Fh
	push	1DFh
	push	1h
	call	far 1AB8h:0F93h
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	push	2h
	push	0h
	push	4h
	call	far 1AB8h:1536h
	lea	di,[bp+0FDFEh]
	push	ss
	push	di
	mov	al,[598Eh]
	push	ax
	call	09F9h
	mov	di,0A8Bh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:0AACh
	mov	di,0A8Bh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,0A8Dh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FCFEh]
	push	ss
	push	di
	mov	al,[5CDCh]
	push	ax
	call	09F9h
	call	far 1EDAh:0AACh
	mov	di,0A93h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FBFEh]
	push	ss
	push	di
	mov	al,[5CDAh]
	push	ax
	call	09F9h
	call	far 1EDAh:0AACh
	mov	di,0A9Ah
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FAFEh]
	push	ss
	push	di
	mov	al,[5CDDh]
	push	ax
	call	09F9h
	call	far 1EDAh:0AACh
	mov	di,0AA1h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0F9FEh]
	push	ss
	push	di
	mov	al,[5CDBh]
	push	ax
	call	09F9h
	call	far 1EDAh:0AACh
	mov	di,0A8Bh
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,5CBBh
	push	ds
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	mov	ax,[50C4h]
	add	ax,16h
	push	ax
	push	17Dh
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	leave
	ret

;; fn1229_0C58: 1229:0C58
;;   Called from:
;;     1229:0CFA (in fn1229_0CCE)
;;     1229:10CB (in fn1229_0DCC)
fn1229_0C58 proc
	enter	4h,0h
	mov	al,[6CBAh]
	mov	[bp-3h],al
	mov	byte ptr [bp-1h],0h
	jmp	0C6Bh

l1229_0C68:
	inc	byte ptr [bp-1h]

l1229_0C6B:
	mov	byte ptr [bp-2h],0h
	jmp	0C74h

l1229_0C71:
	inc	byte ptr [bp-2h]

l1229_0C74:
	mov	al,[bp-2h]
	xor	ah,ah
	imul	ax,ax,16h
	add	ax,59h
	push	ax
	mov	al,[bp-1h]
	xor	ah,ah
	imul	ax,ax,16h
	add	ax,187h
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5992h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	inc	byte ptr [bp-3h]
	cmp	byte ptr [bp-2h],18h
	jnz	0C71h

l1229_0CAC:
	cmp	byte ptr [bp-1h],3h
	jnz	0C68h

l1229_0CB2:
	leave
	ret
1229:0CB4             04 53 77 61 70 03 3C 3C 2D 03 2B 3E     .Swap.<<-.+>
1229:0CC0 3E 04 54 65 73 74 04 51 75 69 74 00 01 25       >.Test.Quit..%  

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

;; fn1229_0DCC: 1229:0DCC
;;   Called from:
;;     0800:40DE (in fn0800_3D9D)
fn1229_0DCC proc
	enter	102h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	call	far 1AB8h:0F80h
	push	0Fh
	push	3Fh
	push	3Fh
	push	3Fh
	call	far 1AB8h:1CBAh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	di,6BBAh
	push	ds
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	mov	byte ptr [62DBh],0h
	mov	byte ptr [62CBh],1h
	mov	byte ptr [6CBAh],0h
	push	1h
	call	far 13C8h:0111h
	call	039Dh
	call	0CCEh
	call	far 133Fh:0141h
	mov	byte ptr [bp+0FEFFh],0h

l1229_0E2E:
	mov	di,62CEh
	push	ds
	push	di
	mov	di,62D0h
	push	ds
	push	di
	mov	di,62D2h
	push	ds
	push	di
	mov	al,[50C7h]
	push	ax
	call	far 133Fh:0528h
	or	al,al
	jnz	0E4Dh

l1229_0E4A:
	jmp	10EFh

l1229_0E4D:
	cmp	word ptr [62CEh],1h
	jnz	0EA2h

l1229_0E54:
	cmp	word ptr [62D0h],59h
	jle	0EA2h

l1229_0E5B:
	cmp	word ptr [62D2h],187h
	jle	0EA2h

l1229_0E63:
	push	0F0h
	call	far 1E78h:02C7h
	push	64h
	call	far 1E78h:029Ch
	mov	ax,[62D2h]
	sub	ax,187h
	cwd
	mov	cx,16h
	idiv	cx
	imul	ax,ax,19h
	mov	bx,ax
	mov	ax,[62D0h]
	sub	ax,59h
	cwd
	mov	cx,16h
	idiv	cx
	add	ax,bx
	mov	dx,ax
	mov	al,[6CBAh]
	xor	ah,ah
	add	ax,dx
	mov	[62CBh],al
	call	far 1E78h:02F4h

l1229_0EA2:
	cmp	word ptr [62CEh],1h
	jnz	0F19h

l1229_0EA9:
	cmp	word ptr [62D2h],177h
	jge	0F19h

l1229_0EB1:
	call	far 133Fh:0137h
	mov	al,[62CBh]
	push	ax
	mov	ax,[62D0h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	mov	bx,ax
	mov	ax,[62D2h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	di,ax,1Dh
	add	di,bx
	pop	ax
	mov	[di+5CE0h],al
	mov	ax,[62D0h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	ax,[62D2h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[62CBh]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5992h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	byte ptr [bp+0FEFFh],1h
	call	far 133Fh:0141h

l1229_0F19:
	cmp	word ptr [62CEh],2h
	jnz	0F82h

l1229_0F20:
	cmp	word ptr [62D2h],177h
	jge	0F82h

l1229_0F28:
	call	far 133Fh:0137h
	mov	ax,[62D0h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	mov	bx,ax
	mov	ax,[62D2h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	di,ax,1Dh
	add	di,bx
	mov	byte ptr [di+5CE0h],0h
	mov	ax,[62D0h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	ax,[62D2h]
	dec	ax
	cwd
	mov	cx,16h
	idiv	cx
	imul	ax,ax,16h
	inc	ax
	push	ax
	les	di,[5992h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	byte ptr [bp+0FEFFh],1h
	call	far 133Fh:0141h

l1229_0F82:
	mov	ax,[62CEh]
	cmp	ax,2Bh
	jnz	0FEAh

l1229_0F8A:
	cmp	word ptr [5990h],0h
	jl	0F9Bh

l1229_0F91:
	jg	0FE7h

l1229_0F93:
	cmp	word ptr [598Eh],0FAh
	jnc	0FE7h

l1229_0F9B:
	call	far 133Fh:0137h
	cmp	byte ptr [bp+0FEFFh],0h
	jz	0FB1h

l1229_0FA7:
	call	061Bh
	or	al,al
	jz	0FB1h

l1229_0FAE:
	call	0735h

l1229_0FB1:
	add	word ptr [598Eh],1h
	adc	word ptr [5990h],0h
	call	0486h
	mov	byte ptr [bp+0FEFFh],0h
	call	0AA8h
	call	far 133Fh:0141h

l1229_0FCB:
	mov	di,62CEh
	push	ds
	push	di
	mov	di,62D0h
	push	ds
	push	di
	mov	di,62D2h
	push	ds
	push	di
	mov	al,[50C7h]
	push	ax
	call	far 133Fh:0528h
	or	al,al
	jnz	0FCBh

l1229_0FE7:
	jmp	10EFh

l1229_0FEA:
	cmp	ax,2Dh
	jnz	104Eh

l1229_0FEF:
	cmp	word ptr [5990h],0h
	jg	0FFFh

l1229_0FF6:
	jl	104Bh

l1229_0FF8:
	cmp	word ptr [598Eh],1h
	jbe	104Bh

l1229_0FFF:
	call	far 133Fh:0137h
	cmp	byte ptr [bp+0FEFFh],0h
	jz	1015h

l1229_100B:
	call	061Bh
	or	al,al
	jz	1015h

l1229_1012:
	call	0735h

l1229_1015:
	sub	word ptr [598Eh],1h
	sbb	word ptr [5990h],0h
	call	0486h
	mov	byte ptr [bp+0FEFFh],0h
	call	0AA8h
	call	far 133Fh:0141h

l1229_102F:
	mov	di,62CEh
	push	ds
	push	di
	mov	di,62D0h
	push	ds
	push	di
	mov	di,62D2h
	push	ds
	push	di
	mov	al,[50C7h]
	push	ax
	call	far 133Fh:0528h
	or	al,al
	jnz	102Fh

l1229_104B:
	jmp	10EFh

l1229_104E:
	cmp	ax,51h
	jnz	108Ch

l1229_1053:
	mov	byte ptr [62DBh],1h
	mov	byte ptr [5CB3h],1h
	cmp	byte ptr [bp+0FEFFh],0h
	jz	106Eh

l1229_1064:
	call	061Bh
	or	al,al
	jz	106Eh

l1229_106B:
	call	0735h

l1229_106E:
	mov	di,62CEh
	push	ds
	push	di
	mov	di,62D0h
	push	ds
	push	di
	mov	di,62D2h
	push	ds
	push	di
	mov	al,[50C7h]
	push	ax
	call	far 133Fh:0528h
	or	al,al
	jnz	106Eh

l1229_108A:
	jmp	10EFh

l1229_108C:
	cmp	ax,54h
	jnz	10AEh

l1229_1091:
	mov	byte ptr [5CB3h],0h
	mov	byte ptr [62DBh],1h
	cmp	byte ptr [bp+0FEFFh],0h
	jz	10ACh

l1229_10A2:
	call	061Bh
	or	al,al
	jz	10ACh

l1229_10A9:
	call	0735h

l1229_10AC:
	jmp	10EFh

l1229_10AE:
	cmp	ax,53h
	jnz	10EFh

l1229_10B3:
	cmp	byte ptr [6CBAh],64h
	jnz	10C1h

l1229_10BA:
	mov	byte ptr [6CBAh],0h
	jmp	10C6h

l1229_10C1:
	mov	byte ptr [6CBAh],64h

l1229_10C6:
	call	far 133Fh:0137h
	call	0C58h
	call	far 133Fh:0141h

l1229_10D3:
	mov	di,62CEh
	push	ds
	push	di
	mov	di,62D0h
	push	ds
	push	di
	mov	di,62D2h
	push	ds
	push	di
	mov	al,[50C7h]
	push	ax
	call	far 133Fh:0528h
	or	al,al
	jnz	10D3h

l1229_10EF:
	cmp	byte ptr [62DBh],0h
	jnz	10F9h

l1229_10F6:
	jmp	0E2Eh

l1229_10F9:
	call	far 133Fh:04A7h
	call	far 133Fh:0137h
	cmp	byte ptr [5CB3h],0h
	jz	1150h

l1229_110A:
	call	far 1AB8h:0F80h
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,0DC5h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	112Eh

l1229_1120:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	jmp	1150h

l1229_112E:
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,5ED6h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	mov	di,5ED6h
	push	ds
	push	di
	mov	di,5ECEh
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h

l1229_1150:
	leave
	retf	4h
1229:1154             00 00 00 00 00 00 00 00 00 00 00 00     ............
