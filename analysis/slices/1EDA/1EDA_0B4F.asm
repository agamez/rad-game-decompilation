;; fn1EDA_0B4F: 1EDA:0B4F
;;   Called from:
;;     0800:0FF4 (in fn0800_0D20)
;;     0800:101A (in fn0800_0D20)
;;     0800:1568 (in fn0800_149F)
;;     0800:15DC (in fn0800_149F)
;;     0800:174B (in fn0800_166D)
;;     0800:17BF (in fn0800_166D)
;;     11C8:0033 (in fn11C8_0000)
;;     1229:0234 (in fn1229_0040)
;;     1229:025A (in fn1229_0040)
fn1EDA_0B4F proc
	cld
	mov	bx,sp
	les	di,ss:[bx+6h]
	mov	al,1h
	stosb
	mov	al,ss:[bx+4h]
	stosb
	retf	2h
