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
