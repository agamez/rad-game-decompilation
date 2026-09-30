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
