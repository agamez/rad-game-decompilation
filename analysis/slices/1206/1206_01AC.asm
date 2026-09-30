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
