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
