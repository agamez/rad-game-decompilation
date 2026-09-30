;; fn0800_0103: 0800:0103
;;   Called from:
;;     0800:268A (in fn0800_2401)
;;     0800:26AA (in fn0800_2401)
;;     0800:2753 (in fn0800_2401)
;;     0800:280B (in fn0800_2401)
;;     0800:2991 (in fn0800_2827)
;;     0800:2A3A (in fn0800_2827)
;;     0800:2AF2 (in fn0800_2827)
;;     0800:2FB0 (in fn0800_2C0C)
;;     0800:2FCB (in fn0800_2C0C)
;;     0800:309B (in fn0800_2C0C)
;;     0800:3523 (in fn0800_31B7)
;;     0800:353E (in fn0800_31B7)
;;     0800:36C9 (in fn0800_31B7)
fn0800_0103 proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [58BEh],0h
	jnz	010Fh

l0800_010D:
	jmp	0123h

l0800_010F:
	push	1Ch
	push	word ptr [58C2h]
	push	word ptr [58C0h]
	call	far 1E5Fh:0171h
	mov	byte ptr [58BEh],0h

l0800_0123:
	leave
	ret
0800:0125                07 52 41 44 2E 53 54 52 19 46 69      .RAD.STR.Fi
0800:0130 63 68 69 65 72 20 64 65 20 64 6F 6E 6E 82 65 73 chier de donn.es
0800:0140 20 61 62 73 65 6E 74                             absent
