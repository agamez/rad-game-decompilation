;;; Segment 1206 (1206:0000)

;; fn1206_0000: 1206:0000
;;   Called from:
;;     1206:01B4 (in fn1206_01AC)
fn1206_0000 proc
	enter	6h,0h
	mov	byte ptr [bp-1h],1h
	mov	al,[bp-1h]
	leave
	retf

;; fn1206_000D: 1206:000D
;;   Called from:
;;     1206:01C6 (in fn1206_01AC)
fn1206_000D proc
	enter	14h,0h
	xor	ax,ax
	mov	[bp-14h],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	mov	ax,[bp-14h]
	les	di,[bp+0Ah]
	mov	es:[di],ax
	mov	ax,[bp-12h]
	les	di,[bp+6h]
	mov	es:[di],ax
	leave
	retf	8h

;; fn1206_0038: 1206:0038
;;   Called from:
;;     0800:0A96 (in fn0800_09C2)
;;     0800:0B32 (in fn0800_0AA1)
;;     0800:0BDA (in fn0800_0B42)
;;     0800:1236 (in fn0800_11EF)
;;     0800:19DA (in fn0800_184C)
;;     0800:1D4C (in fn0800_19E1)
;;     0800:2636 (in fn0800_2401)
;;     0800:2965 (in fn0800_2827)
;;     0800:2E03 (in fn0800_2C0C)
;;     0800:3ACC (in fn0800_391E)
;;     0800:3E41 (in fn0800_3D9D)
;;     0800:40FE (in fn0800_3D9D)
;;     0800:412F (in fn0800_3D9D)
;;     0C74:01D9 (in fn0C74_011E)
;;     0C74:02CF (in fn0C74_020C)
fn1206_0038 proc
	enter	14h,0h
	cmp	byte ptr [597Eh],0h
	jnz	0045h

l1206_0043:
	jmp	0064h

l1206_0045:
	cmp	byte ptr [598Ch],0h
	jz	004Eh

l1206_004C:
	jmp	0064h

l1206_004E:
	mov	byte ptr [598Ch],1h
	mov	word ptr [bp-14h],1h
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh

l1206_0064:
	leave
	retf

;; fn1206_0066: 1206:0066
;;   Called from:
;;     0800:0A28 (in fn0800_09C2)
;;     0800:0AF0 (in fn0800_0AA1)
;;     0800:0B91 (in fn0800_0B42)
;;     0800:11F3 (in fn0800_11EF)
;;     0800:184F (in fn0800_184C)
;;     0800:18AE (in fn0800_184C)
;;     0800:19F8 (in fn0800_19E1)
;;     0800:1E6D (in fn0800_1E3F)
;;     0800:1F87 (in fn0800_1E3F)
;;     0800:2143 (in fn0800_2004)
;;     0800:2480 (in fn0800_2401)
;;     0800:261C (in fn0800_2401)
;;     0800:284C (in fn0800_2827)
;;     0800:294B (in fn0800_2827)
;;     0800:2B39 (in fn0800_2827)
;;     0800:2C20 (in fn0800_2C0C)
;;     0800:2DE9 (in fn0800_2C0C)
;;     0800:3108 (in fn0800_2C0C)
;;     0800:31DE (in fn0800_31B7)
;;     0800:3282 (in fn0800_31B7)
;;     0800:36DF (in fn0800_31B7)
;;     0800:3973 (in fn0800_391E)
;;     0800:3A06 (in fn0800_391E)
;;     0800:3BC4 (in fn0800_391E)
;;     0800:3DA1 (in fn0800_3D9D)
;;     0800:3DD4 (in fn0800_3D9D)
;;     0800:3EE6 (in fn0800_3D9D)
;;     0800:3F1E (in fn0800_3D9D)
;;     0800:4003 (in fn0800_3D9D)
;;     0800:4080 (in fn0800_3D9D)
;;     0800:40A9 (in fn0800_3D9D)
;;     0800:4124 (in fn0800_3D9D)
;;     0800:4156 (in fn0800_3D9D)
;;     0C74:0184 (in fn0C74_011E)
;;     0C74:0272 (in fn0C74_020C)
fn1206_0066 proc
	enter	14h,0h
	cmp	byte ptr [597Eh],0h
	jnz	0073h

l1206_0071:
	jmp	0092h

l1206_0073:
	cmp	byte ptr [598Ch],0h
	jnz	007Ch

l1206_007A:
	jmp	0092h

l1206_007C:
	mov	byte ptr [598Ch],0h
	mov	word ptr [bp-14h],2h
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh

l1206_0092:
	leave
	retf

;; fn1206_0094: 1206:0094
;;   Called from:
;;     0800:1D68 (in fn0800_1D55)
;;     0800:3863 (in fn0800_3850)
;;     1206:017B (in fn1206_015B)
;;     1206:01F1 (in fn1206_01AC)
fn1206_0094 proc
	enter	14h,0h
	cmp	byte ptr [597Eh],0h
	jnz	00A1h

l1206_009F:
	jmp	00CDh

l1206_00A1:
	mov	word ptr [bp-14h],3h
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	mov	ax,[bp-10h]
	les	di,[bp+0Ah]
	mov	es:[di],ax
	mov	ax,[bp-0Eh]
	les	di,[bp+6h]
	mov	es:[di],ax
	mov	ax,[bp-12h]
	les	di,[bp+0Eh]
	mov	es:[di],ax

l1206_00CD:
	leave
	retf	0Ch

;; fn1206_00D1: 1206:00D1
;;   Called from:
;;     0800:33B2 (in fn0800_31B7)
;;     0800:441E (in fn0800_4255)
;;     1206:020F (in fn1206_01AC)
fn1206_00D1 proc
	enter	14h,0h
	cmp	byte ptr [597Eh],0h
	jnz	00DEh

l1206_00DC:
	jmp	00FBh

l1206_00DE:
	mov	word ptr [bp-14h],4h
	mov	ax,[bp+8h]
	mov	[bp-10h],ax
	mov	ax,[bp+6h]
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh

l1206_00FB:
	leave
	retf	4h

;; fn1206_00FF: 1206:00FF
;;   Called from:
;;     0800:339C (in fn0800_31B7)
;;     0800:4409 (in fn0800_4255)
;;     1206:01FB (in fn1206_01AC)
fn1206_00FF proc
	enter	14h,0h
	cmp	byte ptr [597Eh],0h
	jnz	010Ch

l1206_010A:
	jmp	0129h

l1206_010C:
	mov	word ptr [bp-14h],7h
	mov	ax,[bp+8h]
	mov	[bp-10h],ax
	mov	ax,[bp+6h]
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh

l1206_0129:
	leave
	retf	4h

;; fn1206_012D: 1206:012D
;;   Called from:
;;     0800:33A7 (in fn0800_31B7)
;;     0800:4414 (in fn0800_4255)
;;     1206:0205 (in fn1206_01AC)
fn1206_012D proc
	enter	14h,0h
	cmp	byte ptr [597Eh],0h
	jnz	013Ah

l1206_0138:
	jmp	0157h

l1206_013A:
	mov	word ptr [bp-14h],8h
	mov	ax,[bp+8h]
	mov	[bp-10h],ax
	mov	ax,[bp+6h]
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh

l1206_0157:
	leave
	retf	4h

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

;; fn1206_01AC: 1206:01AC
;;   Called from:
;;     0800:19D5 (in fn0800_184C)
;;     0800:3E3C (in fn0800_3D9D)
;;     1206:0228 (in fn1206_0217)
fn1206_01AC proc
	push	bp
	mov	bp,sp
	mov	byte ptr [597Eh],0h
	push	cs
	call	0000h
	or	al,al
	jz	0213h

l1206_01BC:
	mov	di,597Ah
	push	ds
	push	di
	mov	di,597Ch
	push	ds
	push	di
	push	cs
	call	000Dh
	cmp	word ptr [597Ah],0h
	jz	01D6h

l1206_01D1:
	mov	byte ptr [597Eh],1h

l1206_01D6:
	cmp	byte ptr [597Eh],0h
	jz	0213h

l1206_01DD:
	mov	byte ptr [598Ch],0h
	mov	di,5980h
	push	ds
	push	di
	mov	di,5982h
	push	ds
	push	di
	mov	di,5984h
	push	ds
	push	di
	push	cs
	call	0094h
	push	word ptr [bp+10h]
	push	word ptr [bp+0Ch]
	push	cs
	call	00FFh
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ah]
	push	cs
	call	012Dh
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	00D1h

l1206_0213:
	leave
	retf	0Ch

;; fn1206_0217: 1206:0217
;;   Called from:
;;     0800:4278 (in fn0800_4255)
fn1206_0217 proc
	push	bp
	mov	bp,sp
	push	0h
	push	0h
	push	27Fh
	push	1DFh
	push	0h
	push	0h
	push	cs
	call	01ACh
	leave
	retf
1206:022E                                           00 00               ..
