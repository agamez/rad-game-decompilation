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
