;; fn1AB8_14F4: 1AB8:14F4
;;   Called from:
;;     0800:0505 (in fn0800_04E3)
;;     0800:063B (in fn0800_0619)
;;     0800:077B (in fn0800_0768)
;;     0800:0E0F (in fn0800_0D20)
;;     0800:14ED (in fn0800_149F)
;;     0800:16D0 (in fn0800_166D)
;;     0800:18C9 (in fn0800_184C)
;;     0800:1A20 (in fn0800_19E1)
;;     0800:1E97 (in fn0800_1E3F)
;;     0800:2046 (in fn0800_2004)
;;     0800:21FA (in fn0800_21E7)
;;     0800:25C1 (in fn0800_2401)
;;     0800:28E2 (in fn0800_2827)
;;     0800:2D3A (in fn0800_2C0C)
;;     0800:2F68 (in fn0800_2C0C)
;;     0800:329C (in fn0800_31B7)
;;     0800:33C6 (in fn0800_31B7)
;;     0800:3A44 (in fn0800_391E)
;;     0800:43B9 (in fn0800_4255)
;;     1229:00CB (in fn1229_0040)
;;     1229:0B74 (in fn1229_0AA8)
;;     133F:0166 (in fn133F_014B)
;;     1AB8:0B93 (in fn1AB8_0AEE)
fn1AB8_14F4 proc
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+8h],0h
	jc	150Fh

l1AB8_14FD:
	cmp	word ptr [bp+8h],2h
	ja	150Fh

l1AB8_1503:
	cmp	word ptr [bp+6h],0h
	jc	150Fh

l1AB8_1509:
	cmp	word ptr [bp+6h],2h
	jbe	1517h

l1AB8_150F:
	mov	word ptr [0B818h],0FFF5h
	jmp	152Dh

l1AB8_1517:
	mov	ax,[bp+8h]
	mov	[0B892h],ax
	mov	ax,[bp+6h]
	mov	[0B894h],ax
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1992h

l1AB8_152D:
	pop	bp
	retf	4h
1AB8:1531    04 2E 43 48 52                                ..CHR
