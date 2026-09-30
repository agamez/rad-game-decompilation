;; fn1AB8_10E1: 1AB8:10E1
;;   Called from:
;;     0800:0049 (in fn0800_0024)
;;     0800:14BD (in fn0800_149F)
;;     0800:16A0 (in fn0800_166D)
;;     0C74:00A1 (in fn0C74_007C)
;;     0C74:05BC (in fn0C74_05B8)
;;     0C74:0645 (in fn0C74_05B8)
;;     1229:0025 (in fn1229_0000)
;;     1229:0536 (in fn1229_050A)
;;     1229:0554 (in fn1229_050A)
;;     1229:0638 (in fn1229_061B)
;;     1229:0656 (in fn1229_061B)
;;     1229:0753 (in fn1229_0735)
;;     1229:0771 (in fn1229_0735)
;;     1229:07E4 (in fn1229_0735)
;;     1229:0802 (in fn1229_0735)
;;     1229:0D88 (in fn1229_0CCE)
;;     1229:0D9D (in fn1229_0CCE)
;;     133F:01DE (in fn133F_014B)
;;     133F:04FF (in fn133F_04DE)
fn1AB8_10E1 proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	ax,[0B7C4h]
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf
