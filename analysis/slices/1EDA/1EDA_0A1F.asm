;; fn1EDA_0A1F: 1EDA:0A1F
;;   Called from:
;;     0800:0694 (in fn0800_0619)
;;     0800:06C0 (in fn0800_0619)
;;     0800:06F3 (in fn0800_0619)
;;     0800:072F (in fn0800_0619)
;;     0800:0AD5 (in fn0800_0AA1)
;;     0800:0B76 (in fn0800_0B42)
;;     0800:0E4B (in fn0800_0D20)
;;     0800:0E9B (in fn0800_0D20)
;;     0800:100A (in fn0800_0D20)
;;     0800:2246 (in fn0800_21E7)
;;     0800:2294 (in fn0800_21E7)
;;     0800:3FAC (in fn0800_3D9D)
;;     0C74:0151 (in fn0C74_011E)
;;     0C74:023F (in fn0C74_020C)
;;     1229:0107 (in fn1229_0040)
;;     1229:024A (in fn1229_0040)
;;     1229:056E (in fn1229_050A)
;;     1229:0670 (in fn1229_061B)
;;     1229:078B (in fn1229_0735)
;;     1229:081C (in fn1229_0735)
;;     1229:0A27 (in fn1229_09F9)
;;     1229:0A56 (in fn1229_09F9)
;;     133F:02BE (in fn133F_026B)
;;     13E2:01CE (in fn13E2_0193)
;;     1AB8:02E9 (in fn1AB8_027E)
;;     1AB8:0323 (in fn1AB8_027E)
;;     1AB8:03AE (in fn1AB8_027E)
;;     1AB8:0454 (in fn1AB8_027E)
;;     1AB8:04BC (in fn1AB8_027E)
;;     1AB8:08D9 (in fn1AB8_0887)
;;     1AB8:09AE (in fn1AB8_097B)
;;     1AB8:0D35 (in fn1AB8_0BAE)
;;     1AB8:1619 (in fn1AB8_1536)
fn1EDA_0A1F proc
	cld
	mov	bx,sp
	mov	dx,ds
	les	di,ss:[bx+8h]
	lds	si,ss:[bx+4h]
	lodsb
	stosb
	mov	cl,al
	xor	ch,ch
	rep movsb
	mov	ds,dx
	retf	4h
