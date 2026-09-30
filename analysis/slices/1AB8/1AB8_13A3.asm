;; fn1AB8_13A3: 1AB8:13A3
;;   Called from:
;;     0800:0153 (in fn0800_0147)
;;     0800:043E (in fn0800_03F8)
;;     0800:0DAF (in fn0800_0D20)
;;     0C74:043C (in fn0C74_03D4)
;;     0C74:044D (in fn0C74_03D4)
;;     0C74:0615 (in fn0C74_05B8)
;;     0C74:0E5C (in fn0C74_0E2E)
;;     0C74:0E8E (in fn0C74_0E2E)
;;     0C74:0FAD (in fn0C74_0FA1)
;;     0C74:1177 (in fn0C74_0FA1)
;;     0C74:13D0 (in fn0C74_0FA1)
;;     0C74:152E (in fn0C74_0FA1)
;;     0C74:16F4 (in fn0C74_0FA1)
;;     0C74:178D (in fn0C74_0FA1)
;;     0C74:180D (in fn0C74_0FA1)
;;     0C74:19AA (in fn0C74_0FA1)
;;     0C74:1A50 (in fn0C74_0FA1)
;;     0C74:1B94 (in fn0C74_1B3B)
;;     0C74:1DC3 (in fn0C74_1D95)
;;     0C74:1DF5 (in fn0C74_1D95)
;;     0C74:1F14 (in fn0C74_1F08)
;;     0C74:20DE (in fn0C74_1F08)
;;     0C74:2337 (in fn0C74_1F08)
;;     0C74:2495 (in fn0C74_1F08)
;;     0C74:2690 (in fn0C74_1F08)
;;     0C74:279E (in fn0C74_1F08)
;;     0C74:2942 (in fn0C74_1F08)
;;     0C74:29E8 (in fn0C74_1F08)
;;     0C74:2B04 (in fn0C74_2AD9)
;;     0C74:2BCD (in fn0C74_2BBD)
;;     0C74:2BE1 (in fn0C74_2BBD)
;;     0C74:2EEF (in fn0C74_2E5A)
;;     0C74:2F41 (in fn0C74_2E5A)
;;     0C74:303B (in fn0C74_2E5A)
;;     0C74:32CA (in fn0C74_3236)
;;     0C74:331C (in fn0C74_3236)
;;     0C74:3416 (in fn0C74_3236)
;;     0C74:4EF9 (in fn0C74_4DAC)
;;     0C74:50E4 (in fn0C74_4FD7)
;;     0C74:539E (in fn0C74_5258)
;;     1229:006A (in fn1229_0040)
fn1AB8_13A3 proc
	push	bp
	mov	bp,sp
	sub	sp,4h
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	19A6h
	mov	[bp-4h],ax
	cmp	word ptr [bp-4h],0FFh
	jnz	13C8h

l1AB8_13C2:
	mov	word ptr [0B818h],0FFF5h

l1AB8_13C8:
	mov	ax,[bp-4h]
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf	8h
