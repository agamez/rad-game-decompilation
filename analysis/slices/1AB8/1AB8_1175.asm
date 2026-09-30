;; fn1AB8_1175: 1AB8:1175
;;   Called from:
;;     0800:0061 (in fn0800_005A)
;;     0800:131C (in fn0800_1315)
;;     0800:1A0C (in fn0800_19E1)
;;     0800:36ED (in fn0800_36E6)
;;     0800:39AA (in fn0800_391E)
;;     0800:3A0F (in fn0800_391E)
;;     0800:3F65 (in fn0800_3D9D)
;;     0800:43E0 (in fn0800_4255)
;;     0C74:00E2 (in fn0C74_00DB)
;;     1AB8:0B6C (in fn1AB8_0AEE)
;;     1AB8:1041 (in fn1AB8_1028)
;;     1AB8:1079 (in fn1AB8_1028)
fn1AB8_1175 proc
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+8h],0Bh
	jbe	1186h

l1AB8_117E:
	mov	word ptr [0B818h],0FFF5h
	jmp	119Ch

l1AB8_1186:
	mov	ax,[bp+8h]
	mov	[0B862h],ax
	mov	ax,[bp+6h]
	mov	[0B864h],ax
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1D5Bh

l1AB8_119C:
	pop	bp
	retf	4h
