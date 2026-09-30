;; fn1EDA_023F: 1EDA:023F
;;   Called from:
;;     0800:01A7 (in fn0800_0147)
;;     0800:044B (in fn0800_03F8)
;;     0800:046C (in fn0800_03F8)
;;     0800:0DBC (in fn0800_0D20)
;;     0C43:010B (in fn0C43_00B9)
;;     0C74:045A (in fn0C74_03D4)
;;     0C74:0485 (in fn0C74_03D4)
;;     0C74:04F8 (in fn0C74_03D4)
;;     0C74:0544 (in fn0C74_03D4)
;;     0C74:0620 (in fn0C74_05B8)
;;     0C74:0E99 (in fn0C74_0E2E)
;;     0C74:0EA7 (in fn0C74_0E2E)
;;     0C74:0FB8 (in fn0C74_0FA1)
;;     0C74:0FC6 (in fn0C74_0FA1)
;;     0C74:1182 (in fn0C74_0FA1)
;;     0C74:1190 (in fn0C74_0FA1)
;;     0C74:13DB (in fn0C74_0FA1)
;;     0C74:1539 (in fn0C74_0FA1)
;;     0C74:16FF (in fn0C74_0FA1)
;;     0C74:1798 (in fn0C74_0FA1)
;;     0C74:1818 (in fn0C74_0FA1)
;;     0C74:19B5 (in fn0C74_0FA1)
;;     0C74:1A5B (in fn0C74_0FA1)
;;     0C74:1BA0 (in fn0C74_1B3B)
;;     0C74:1E00 (in fn0C74_1D95)
;;     0C74:1E0E (in fn0C74_1D95)
;;     0C74:1F1F (in fn0C74_1F08)
;;     0C74:1F2D (in fn0C74_1F08)
;;     0C74:20E9 (in fn0C74_1F08)
;;     0C74:20F7 (in fn0C74_1F08)
;;     0C74:2342 (in fn0C74_1F08)
;;     0C74:24A0 (in fn0C74_1F08)
;;     0C74:269B (in fn0C74_1F08)
;;     0C74:27E8 (in fn0C74_1F08)
;;     0C74:294D (in fn0C74_1F08)
;;     0C74:29F3 (in fn0C74_1F08)
;;     0C74:2B10 (in fn0C74_2AD9)
;;     0C74:2BEC (in fn0C74_2BBD)
;;     0C74:2BFA (in fn0C74_2BBD)
;;     0C74:2EFA (in fn0C74_2E5A)
;;     0C74:2F4C (in fn0C74_2E5A)
;;     0C74:3046 (in fn0C74_2E5A)
;;     0C74:32D5 (in fn0C74_3236)
;;     0C74:3327 (in fn0C74_3236)
;;     0C74:3421 (in fn0C74_3236)
;;     0C74:4F04 (in fn0C74_4DAC)
;;     0C74:50EF (in fn0C74_4FD7)
;;     0C74:53A9 (in fn0C74_5258)
;;     1229:0077 (in fn1229_0040)
fn1EDA_023F proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+6h]
	call	0308h
	pop	bp
	jc	024Eh

l1EDA_024B:
	retf	2h

l1EDA_024E:
	mov	ax,0CBh
	jmp	00E2h
