;; fn1EDA_0FA2: 1EDA:0FA2
;;   Called from:
;;     0800:017F (in fn0800_0147)
;;     0800:020C (in fn0800_01FE)
;;     0800:0422 (in fn0800_03F8)
;;     0800:1257 (in fn0800_11EF)
;;     0800:2431 (in fn0800_2401)
;;     0800:2884 (in fn0800_2827)
;;     0800:3670 (in fn0800_31B7)
;;     0800:4187 (in fn0800_4168)
;;     0C43:00DE (in fn0C43_00B9)
;;     0C74:0420 (in fn0C74_03D4)
;;     1229:0408 (in fn1229_039D)
;;     1229:0494 (in fn1229_0486)
;;     1229:0911 (in fn1229_0735)
;;     1AB8:08E9 (in fn1AB8_0887)
;;     1AB8:091B (in fn1AB8_0887)
fn1EDA_0FA2 proc
	mov	bx,sp
	push	ds
	les	di,ss:[bx+8h]
	lds	si,ss:[bx+4h]
	cld
	xor	ax,ax
	stosw
	mov	ax,0D7B0h
	stosw
	xor	ax,ax
	mov	cx,16h

l1EDA_0FBA:
	rep stosw

l1EDA_0FBC:
	lodsb
	cmp	al,4Fh
	jbe	0FC3h

l1EDA_0FC1:
	mov	al,4Fh

l1EDA_0FC3:
	mov	cl,al
	xor	ch,ch
	rep movsb
	xor	al,al
	stosb
	pop	ds
	retf	8h
