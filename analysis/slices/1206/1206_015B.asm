;; fn1206_015B: 1206:015B
;;   Called from:
;;     0800:0321 (in fn0800_031B)
;;     0800:03C9 (in fn0800_031B)
;;     0800:07E9 (in fn0800_0768)
;;     0800:0837 (in fn0800_0768)
;;     0800:1F45 (in fn0800_1E3F)
;;     0800:2108 (in fn0800_2004)
;;     0800:2669 (in fn0800_2401)
;;     0800:2694 (in fn0800_2401)
;;     0800:2988 (in fn0800_2827)
;;     0800:2E29 (in fn0800_2C0C)
;;     0800:2E54 (in fn0800_2C0C)
;;     0800:2FDE (in fn0800_2C0C)
;;     0800:343E (in fn0800_31B7)
;;     0800:3469 (in fn0800_31B7)
;;     0800:3551 (in fn0800_31B7)
;;     0800:3B28 (in fn0800_391E)
;;     0C74:36F5 (in fn0C74_3615)
;;     0C74:38A1 (in fn0C74_37C3)
fn1206_015B proc
	enter	8h,0h
	mov	byte ptr [bp-1h],0h
	cmp	byte ptr [597Eh],0h
	jnz	016Ch

l1206_016A:
	jmp	01A5h

l1206_016C:
	lea	di,[bp-4h]
	push	ss
	push	di
	lea	di,[bp-6h]
	push	ss
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	push	cs
	call	0094h
	mov	ax,[bp-6h]
	mov	[5982h],ax
	mov	ax,[bp-8h]
	mov	[5984h],ax
	cmp	word ptr [bp-4h],0h
	jnz	0193h

l1206_0191:
	jmp	01A5h

l1206_0193:
	cmp	word ptr [bp+6h],0h
	jz	01A1h

l1206_0199:
	mov	ax,[bp-4h]
	cmp	ax,[bp+6h]
	jnz	01A5h

l1206_01A1:
	mov	byte ptr [bp-1h],1h

l1206_01A5:
	mov	al,[bp-1h]
	leave
	retf	2h
