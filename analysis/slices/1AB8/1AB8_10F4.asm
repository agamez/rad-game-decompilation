;; fn1AB8_10F4: 1AB8:10F4
;;   Called from:
;;     0800:0A50 (in fn0800_09C2)
;;     0800:1327 (in fn0800_1315)
;;     0800:186B (in fn0800_184C)
;;     0800:1A17 (in fn0800_19E1)
;;     0800:31F0 (in fn0800_31B7)
;;     0800:36F8 (in fn0800_36E6)
;;     0800:3E0C (in fn0800_3D9D)
;;     0C74:10A3 (in fn0C74_0FA1)
;;     0C74:1756 (in fn0C74_0FA1)
;;     0C74:18E4 (in fn0C74_0FA1)
;;     0C74:200A (in fn0C74_1F08)
;;     0C74:287C (in fn0C74_1F08)
;;     0C74:2FA5 (in fn0C74_2E5A)
;;     0C74:3380 (in fn0C74_3236)
;;     0C74:3980 (in fn0C74_396E)
;;     0C74:3F86 (in fn0C74_3F74)
;;     0C74:45E0 (in fn0C74_45CE)
;;     0C74:49A3 (in fn0C74_4999)
;;     0C74:53D2 (in fn0C74_5258)
;;     1AB8:0B7A (in fn1AB8_0AEE)
fn1AB8_10F4 proc
	push	bp
	mov	bp,sp
	cmp	word ptr [bp+0Ah],4h
	ja	1103h

l1AB8_10FD:
	cmp	word ptr [bp+6h],3h
	jbe	110Bh

l1AB8_1103:
	mov	word ptr [0B818h],0FFF5h
	jmp	112Ah

l1AB8_110B:
	mov	ax,[bp+0Ah]
	mov	[0B85Ch],ax
	mov	ax,[bp+8h]
	mov	[0B85Eh],ax
	mov	ax,[bp+6h]
	mov	[0B860h],ax
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1CFFh

l1AB8_112A:
	pop	bp
	retf	6h
