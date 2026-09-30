;;; Segment 133F (133F:0000)
133F:0000 00 12 45 72 72 65 75 72 20 67 72 61 70 68 69 71 ..Erreur graphiq
133F:0010 75 65 3A 20 28 28 63 61 72 74 65 20 67 72 61 70 ue: ((carte grap
133F:0020 68 69 71 75 65 20 70 72 6F 62 61 62 6C 65 6D 65 hique probableme
133F:0030 6E 74 20 61 62 73 65 6E 74 65 20 21 29 18 50 72 nt absente !).Pr
133F:0040 6F 67 72 61 6D 6D 65 20 69 6E 74 65 72 72 6F 6D ogramme interrom
133F:0050 70 75 20 2E 2E 2E                               pu ...          

;; fn133F_0056: 133F:0056
;;   Called from:
;;     133F:0819 (in fn133F_0816)
fn133F_0056 proc
	enter	20Ch,0h
	xor	ax,ax
	mov	[bp-2h],ax
	lea	di,[bp-2h]
	push	ss
	push	di
	lea	di,[bp-4h]
	push	ss
	push	di
	mov	di,0h
	push	cs
	push	di
	call	far 1AB8h:0BAEh
	call	far 1AB8h:04F3h
	mov	[bp-6h],ax
	cmp	word ptr [bp-6h],0h
	jz	00E0h

l133F_0081:
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,1h
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	lea	di,[bp+0FDF4h]
	push	ss
	push	di
	push	word ptr [bp-6h]
	call	far 1AB8h:027Eh
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,14h
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,3Dh
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	mov	ax,1h
	call	far 1EDAh:00E9h

l133F_00E0:
	call	far 13C8h:0000h
	or	al,al
	jz	0113h

l133F_00E9:
	mov	di,0B6AEh
	push	ds
	push	di
	mov	di,0B6B0h
	push	ds
	push	di
	call	far 13C8h:000Dh
	cmp	word ptr [0B6AEh],0h
	jz	0113h

l133F_00FF:
	push	0h
	push	27Fh
	call	far 13C8h:00BFh
	push	0h
	push	1DFh
	call	far 13C8h:00E4h

l133F_0113:
	mov	byte ptr [0B59Dh],0h
	mov	byte ptr [0B5A2h],0h
	mov	byte ptr [6CD0h],0h
	mov	byte ptr [0B59Ch],0h
	push	0h
	call	far 1AB8h:1250h
	push	0Fh
	call	far 1AB8h:1C32h
	leave
	retf

;; fn133F_0137: 133F:0137
;;   Called from:
;;     1229:0739 (in fn1229_0735)
;;     1229:0CD2 (in fn1229_0CCE)
;;     1229:0EB1 (in fn1229_0DCC)
;;     1229:0F28 (in fn1229_0DCC)
;;     1229:0F9B (in fn1229_0DCC)
;;     1229:0FFF (in fn1229_0DCC)
;;     1229:10C6 (in fn1229_0DCC)
;;     1229:10FE (in fn1229_0DCC)
fn133F_0137 proc
	push	bp
	mov	bp,sp
	call	far 13C8h:004Fh
	leave
	retf

;; fn133F_0141: 133F:0141
;;   Called from:
;;     1229:09F0 (in fn1229_0735)
;;     1229:0E24 (in fn1229_0DCC)
;;     1229:0F14 (in fn1229_0DCC)
;;     1229:0F7D (in fn1229_0DCC)
;;     1229:0FC6 (in fn1229_0DCC)
;;     1229:102A (in fn1229_0DCC)
;;     1229:10CE (in fn1229_0DCC)
;;     133F:0520 (in fn133F_04DE)
fn133F_0141 proc
	push	bp
	mov	bp,sp
	call	far 13C8h:0038h
	leave
	retf

;; fn133F_014B: 133F:014B
;;   Called from:
;;     133F:02D7 (in fn133F_026B)
;;     133F:0491 (in fn133F_0352)
fn133F_014B proc
	enter	100h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	word ptr [bp+0Ch]
	push	0h
	push	word ptr [bp+0Ah]
	call	far 1AB8h:1536h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1E0Bh
	shr	ax,1h
	inc	ax
	mov	dx,ax
	mov	ax,[bp+10h]
	sub	ax,dx
	push	ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	inc	ax
	mov	dx,ax
	mov	ax,[bp+0Eh]
	sub	ax,dx
	push	ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1E0Bh
	shr	ax,1h
	inc	ax
	add	ax,[bp+10h]
	push	ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	inc	ax
	add	ax,[bp+0Eh]
	push	ax
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
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	leave
	retf	0Ch

;; fn133F_0200: 133F:0200
;;   Called from:
;;     1229:0D8E (in fn1229_0CCE)
;;     133F:04C0 (in fn133F_04B1)
fn133F_0200 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Ch]
	mov	[6CC8h],ax
	mov	ax,[bp+0Ah]
	mov	[6CCAh],ax
	mov	ax,[bp+8h]
	mov	[6CCCh],ax
	mov	ax,[bp+6h]
	mov	[6CCEh],ax
	leave
	retf	8h

;; fn133F_021F: 133F:021F
;;   Called from:
;;     133F:05E4 (in fn133F_0528)
;;     133F:060B (in fn133F_0528)
;;     133F:0632 (in fn133F_0528)
;;     133F:0659 (in fn133F_0528)
;;     133F:07F7 (in fn133F_0528)
fn133F_021F proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+8h]
	cmp	ax,[6CC8h]
	jle	0252h

l133F_022B:
	mov	ax,[bp+8h]
	cmp	ax,[6CCCh]
	jge	0252h

l133F_0234:
	mov	ax,[bp+6h]
	cmp	ax,[6CCAh]
	jle	0252h

l133F_023D:
	mov	ax,[bp+6h]
	cmp	ax,[6CCEh]
	jge	0252h

l133F_0246:
	mov	ax,[bp+8h]
	mov	[6CC4h],ax
	mov	ax,[bp+6h]
	mov	[6CC6h],ax

l133F_0252:
	leave
	retf	4h

;; fn133F_0256: 133F:0256
;;   Called from:
;;     1229:0DAC (in fn1229_0CCE)
fn133F_0256 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+8h]
	mov	[6CC0h],ax
	mov	ax,[bp+6h]
	mov	[6CC2h],ax
	leave
	retf	4h
133F:0269                            01 3A                         .:     

;; fn133F_026B: 133F:026B
;;   Called from:
;;     133F:070A (in fn133F_0528)
;;     133F:080B (in fn133F_0528)
fn133F_026B proc
	enter	108h,0h
	mov	ax,[6CC4h]
	sub	ax,[6CC8h]
	cwd
	idiv	word ptr [6CC0h]
	cwd
	push	dx
	push	ax
	push	2h
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0F26h
	mov	ax,[6CC6h]
	sub	ax,[6CCAh]
	cwd
	idiv	word ptr [6CC2h]
	cwd
	push	dx
	push	ax
	push	2h
	lea	di,[bp-8h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0F26h
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	0h
	push	1h
	lea	di,[bp+0FEF8h]
	push	ss
	push	di
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,269h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp-8h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	push	cs
	call	014Bh
	leave
	retf	4h

;; fn133F_02DF: 133F:02DF
;;   Called from:
;;     133F:049F (in fn133F_0352)
fn133F_02DF proc
	enter	200h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l133F_02F6:
	mov	al,[bp+0FF00h]
	xor	ah,ah
	mov	di,ax
	cmp	byte ptr [bp+di+0FF00h],20h
	jnz	0330h

l133F_0305:
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	1h
	mov	al,[bp+0FF00h]
	xor	ah,ah
	dec	ax
	push	ax
	call	far 1EDAh:0A6Bh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	jmp	02F6h

l133F_0330:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	mov	al,[bp+0Ah]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,6DEAh
	push	ds
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	retf	6h

;; fn133F_0352: 133F:0352
;;   Called from:
;;     1229:0D0E (in fn1229_0CCE)
;;     1229:0D24 (in fn1229_0CCE)
;;     1229:0D3A (in fn1229_0CCE)
;;     1229:0D50 (in fn1229_0CCE)
;;     1229:0D66 (in fn1229_0CCE)
fn133F_0352 proc
	enter	104h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	inc	byte ptr [6CD0h]
	mov	dl,[bp+12h]
	mov	al,[6CD0h]
	xor	ah,ah
	mov	di,ax
	mov	[di+6DCAh],dl
	mov	dx,[bp+10h]
	mov	al,[6CD0h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	[di+6CD2h],dx
	mov	dx,[bp+0Ch]
	mov	al,[6CD0h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	[di+6D10h],dx
	mov	dx,[bp+0Eh]
	mov	al,[6CD0h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	[di+6D4Eh],dx
	mov	dx,[bp+0Ah]
	mov	al,[6CD0h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	[di+6D8Ch],dx
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	call	far 1AB8h:112Eh
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	mov	ax,[bp+10h]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Eh]
	add	ax,[50CAh]
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+10h]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Eh]
	add	ax,[50CAh]
	push	ax
	mov	ax,[bp+10h]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ah]
	add	ax,[50CAh]
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+10h]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ah]
	add	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ch]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ah]
	add	ax,[50CAh]
	push	ax
	call	far 1AB8h:1AF6h
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	mov	ax,[bp+0Ch]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ah]
	add	ax,[50CAh]
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+10h]
	sub	ax,[50CAh]
	push	ax
	mov	ax,[bp+0Ah]
	add	ax,[50CAh]
	push	ax
	push	word ptr [bp+10h]
	push	word ptr [bp+0Ah]
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ch]
	sub	ax,[bp+10h]
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,[bp+10h]
	push	ax
	mov	ax,[bp+0Ah]
	sub	ax,[bp+0Eh]
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,[bp+0Eh]
	push	ax
	push	0h
	push	1h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	cs
	call	014Bh
	mov	al,[6CD0h]
	push	ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	cs
	call	02DFh
	leave
	retf	0Eh

;; fn133F_04A7: 133F:04A7
;;   Called from:
;;     1229:0CD7 (in fn1229_0CCE)
;;     1229:10F9 (in fn1229_0DCC)
fn133F_04A7 proc
	push	bp
	mov	bp,sp
	mov	byte ptr [6CD0h],0h
	leave
	retf

;; fn133F_04B1: 133F:04B1
;;   Called from:
;;     1229:0DA3 (in fn1229_0CCE)
;;     133F:0505 (in fn133F_04DE)
fn133F_04B1 proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	0200h
	push	word ptr [bp+0Ch]
	push	word ptr [bp+8h]
	call	far 13C8h:00BFh
	push	word ptr [bp+0Ah]
	push	word ptr [bp+6h]
	call	far 13C8h:00E4h
	leave
	retf	8h

;; fn133F_04DE: 133F:04DE
;;   Called from:
;;     1229:0D79 (in fn1229_0CCE)
fn133F_04DE proc
	enter	106h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	push	0h
	push	0h
	call	far 1AB8h:10CEh
	push	ax
	call	far 1AB8h:10E1h
	push	ax
	push	cs
	call	04B1h
	mov	ax,[bp+10h]
	mov	[0B6B6h],ax
	mov	ax,[bp+0Eh]
	mov	[0B6B8h],ax
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	call	far 13C8h:009Ah
	push	cs
	call	0141h
	leave
	retf	0Ch

;; fn133F_0528: 133F:0528
;;   Called from:
;;     1229:0E41 (in fn1229_0DCC)
;;     1229:0FDE (in fn1229_0DCC)
;;     1229:1042 (in fn1229_0DCC)
;;     1229:1081 (in fn1229_0DCC)
;;     1229:10E6 (in fn1229_0DCC)
fn133F_0528 proc
	enter	6h,0h
	mov	byte ptr [bp-1h],0h
	les	di,[bp+10h]
	xor	ax,ax
	mov	es:[di],ax
	mov	ax,[6CC4h]
	les	di,[bp+0Ch]
	mov	es:[di],ax
	mov	ax,[6CC6h]
	les	di,[bp+8h]
	mov	es:[di],ax
	call	far 1E78h:02FBh
	or	al,al
	jnz	0556h

l133F_0553:
	jmp	0715h

l133F_0556:
	call	far 1E78h:030Dh
	mov	[bp-2h],al
	mov	al,[bp-2h]
	cmp	al,0Dh
	jnz	0570h

l133F_0565:
	les	di,[bp+10h]
	mov	word ptr es:[di],1h
	jmp	065Dh

l133F_0570:
	cmp	al,1Bh
	jnz	057Fh

l133F_0574:
	les	di,[bp+10h]
	mov	word ptr es:[di],1Bh
	jmp	065Dh

l133F_057F:
	cmp	al,21h
	jc	059Bh

l133F_0583:
	cmp	al,7Dh
	ja	059Bh

l133F_0587:
	mov	al,[bp-2h]
	push	ax
	call	far 1EDAh:1384h
	xor	ah,ah
	les	di,[bp+10h]
	mov	es:[di],ax
	jmp	065Dh

l133F_059B:
	cmp	al,0h
	jz	05A2h

l133F_059F:
	jmp	065Dh

l133F_05A2:
	call	far 1E78h:030Dh
	mov	[bp-2h],al
	mov	al,[bp-2h]
	cmp	al,3Bh
	jc	05C3h

l133F_05B1:
	cmp	al,40h
	ja	05C3h

l133F_05B5:
	mov	al,[bp-2h]
	xor	ah,ah
	les	di,[bp+10h]
	mov	es:[di],ax
	jmp	065Dh

l133F_05C3:
	cmp	al,4Bh
	jnz	05EAh

l133F_05C7:
	mov	ax,[6CC4h]
	sub	ax,[6CC0h]
	push	ax
	push	word ptr [6CC6h]
	call	far 13C8h:009Ah
	mov	ax,[6CC4h]
	sub	ax,[6CC0h]
	push	ax
	push	word ptr [6CC6h]
	push	cs
	call	021Fh
	jmp	065Dh

l133F_05EA:
	cmp	al,48h
	jnz	0611h

l133F_05EE:
	push	word ptr [6CC4h]
	mov	ax,[6CC6h]
	sub	ax,[6CC2h]
	push	ax
	call	far 13C8h:009Ah
	push	word ptr [6CC4h]
	mov	ax,[6CC6h]
	sub	ax,[6CC2h]
	push	ax
	push	cs
	call	021Fh
	jmp	065Dh

l133F_0611:
	cmp	al,50h
	jnz	0638h

l133F_0615:
	push	word ptr [6CC4h]
	mov	ax,[6CC6h]
	add	ax,[6CC2h]
	push	ax
	call	far 13C8h:009Ah
	push	word ptr [6CC4h]
	mov	ax,[6CC6h]
	add	ax,[6CC2h]
	push	ax
	push	cs
	call	021Fh
	jmp	065Dh

l133F_0638:
	cmp	al,4Dh
	jnz	065Dh

l133F_063C:
	mov	ax,[6CC4h]
	add	ax,[6CC0h]
	push	ax
	push	word ptr [6CC6h]
	call	far 13C8h:009Ah
	mov	ax,[6CC4h]
	add	ax,[6CC0h]
	push	ax
	push	word ptr [6CC6h]
	push	cs
	call	021Fh

l133F_065D:
	les	di,[bp+10h]
	cmp	word ptr es:[di],0h
	jnz	0669h

l133F_0666:
	jmp	06FEh

l133F_0669:
	mov	byte ptr [bp-1h],1h
	les	di,[bp+10h]
	cmp	word ptr es:[di],1h
	jz	0679h

l133F_0676:
	jmp	06FEh

l133F_0679:
	mov	al,[6CD0h]
	mov	[bp-5h],al
	mov	al,1h
	cmp	al,[bp-5h]
	ja	06FEh

l133F_0686:
	mov	[bp-4h],al
	jmp	068Eh

l133F_068B:
	inc	byte ptr [bp-4h]

l133F_068E:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6CD2h]
	cmp	ax,[6CC4h]
	jge	06F6h

l133F_06A1:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D10h]
	cmp	ax,[6CC4h]
	jle	06F6h

l133F_06B4:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D4Eh]
	cmp	ax,[6CC6h]
	jge	06F6h

l133F_06C7:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D8Ch]
	cmp	ax,[6CC6h]
	jle	06F6h

l133F_06DA:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+6DCAh]
	mov	[bp-3h],al
	mov	al,[bp-3h]
	xor	ah,ah
	les	di,[bp+10h]
	mov	es:[di],ax
	jmp	080Fh

l133F_06F6:
	mov	al,[bp-4h]
	cmp	al,[bp-5h]
	jnz	068Bh

l133F_06FE:
	cmp	byte ptr [bp+6h],0h
	jz	070Eh

l133F_0704:
	push	26Ah
	push	17Fh
	push	cs
	call	026Bh

l133F_070E:
	mov	byte ptr [bp-1h],1h
	jmp	080Fh

l133F_0715:
	cmp	byte ptr [0B6B2h],0h
	jnz	071Fh

l133F_071C:
	jmp	080Fh

l133F_071F:
	les	di,[bp+10h]
	push	es
	push	di
	les	di,[bp+0Ch]
	push	es
	push	di
	les	di,[bp+8h]
	push	es
	push	di
	call	far 13C8h:0066h
	les	di,[bp+10h]
	cmp	word ptr es:[di],0h
	jnz	073Fh

l133F_073C:
	jmp	07D3h

l133F_073F:
	mov	byte ptr [bp-1h],1h
	les	di,[bp+10h]
	cmp	word ptr es:[di],1h
	jz	074Fh

l133F_074C:
	jmp	07D3h

l133F_074F:
	mov	al,[6CD0h]
	mov	[bp-5h],al
	mov	al,1h
	cmp	al,[bp-5h]
	ja	07D3h

l133F_075C:
	mov	[bp-4h],al
	jmp	0764h

l133F_0761:
	inc	byte ptr [bp-4h]

l133F_0764:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6CD2h]
	cmp	ax,[6CC4h]
	jge	07CBh

l133F_0777:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D10h]
	cmp	ax,[6CC4h]
	jle	07CBh

l133F_078A:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D4Eh]
	cmp	ax,[6CC6h]
	jge	07CBh

l133F_079D:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+6D8Ch]
	cmp	ax,[6CC6h]
	jle	07CBh

l133F_07B0:
	mov	al,[bp-4h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+6DCAh]
	mov	[bp-3h],al
	mov	al,[bp-3h]
	xor	ah,ah
	les	di,[bp+10h]
	mov	es:[di],ax
	jmp	080Fh

l133F_07CB:
	mov	al,[bp-4h]
	cmp	al,[bp-5h]
	jnz	0761h

l133F_07D3:
	les	di,[bp+0Ch]
	mov	ax,es:[di]
	cmp	ax,[6CC4h]
	jnz	07EBh

l133F_07DF:
	les	di,[bp+8h]
	mov	ax,es:[di]
	cmp	ax,[6CC6h]
	jz	080Fh

l133F_07EB:
	les	di,[bp+0Ch]
	push	word ptr es:[di]
	les	di,[bp+8h]
	push	word ptr es:[di]
	push	cs
	call	021Fh
	mov	byte ptr [bp-1h],1h
	cmp	byte ptr [bp+6h],0h
	jz	080Fh

l133F_0805:
	push	26Ah
	push	17Fh
	push	cs
	call	026Bh

l133F_080F:
	mov	al,[bp-1h]
	leave
	retf	0Eh

;; fn133F_0816: 133F:0816
;;   Called from:
;;     0800:4273 (in fn0800_4255)
fn133F_0816 proc
	push	bp
	mov	bp,sp
	push	cs
	call	0056h
	leave
	retf
133F:081F                                              00                .
