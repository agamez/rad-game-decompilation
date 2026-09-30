;; fn1AB8_10CE: 1AB8:10CE
;;   Called from:
;;     0800:0043 (in fn0800_0024)
;;     0800:11FE (in fn0800_11EF)
;;     0800:1210 (in fn0800_11EF)
;;     0800:14B2 (in fn0800_149F)
;;     0800:1695 (in fn0800_166D)
;;     0800:1E5D (in fn0800_1E3F)
;;     0800:2485 (in fn0800_2401)
;;     0800:2497 (in fn0800_2401)
;;     0800:3963 (in fn0800_391E)
;;     0800:43BE (in fn0800_4255)
;;     0C74:009B (in fn0C74_007C)
;;     1229:001F (in fn1229_0000)
;;     1229:0527 (in fn1229_050A)
;;     1229:0545 (in fn1229_050A)
;;     1229:0629 (in fn1229_061B)
;;     1229:0647 (in fn1229_061B)
;;     1229:0744 (in fn1229_0735)
;;     1229:0762 (in fn1229_0735)
;;     1229:07D5 (in fn1229_0735)
;;     1229:07F3 (in fn1229_0735)
;;     1229:0D82 (in fn1229_0CCE)
;;     1229:0D97 (in fn1229_0CCE)
;;     133F:01D8 (in fn133F_014B)
;;     133F:04F9 (in fn133F_04DE)
fn1AB8_10CE proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	ax,[0B7C2h]
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf
