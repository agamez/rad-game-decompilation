;; fn1E78_029C: 1E78:029C
;;   Called from:
;;     0800:15E8 (in fn0800_149F)
;;     0800:15FB (in fn0800_149F)
;;     0800:17CB (in fn0800_166D)
;;     0800:17DE (in fn0800_166D)
;;     0800:1F8F (in fn0800_1E3F)
;;     0800:214B (in fn0800_2004)
;;     0800:3BCC (in fn0800_391E)
;;     0800:4087 (in fn0800_3D9D)
;;     0800:411F (in fn0800_3D9D)
;;     0C74:02E6 (in fn0C74_02D8)
;;     0C74:0370 (in fn0C74_02D8)
;;     0C74:039E (in fn0C74_02D8)
;;     0C74:0854 (in fn0C74_076B)
;;     0C74:0B18 (in fn0C74_0A35)
;;     0C74:2CA2 (in fn0C74_2BBD)
;;     0C74:2D17 (in fn0C74_2BBD)
;;     0C74:31CA (in fn0C74_2E5A)
;;     0C74:35A9 (in fn0C74_3236)
;;     1229:04E8 (in fn1229_0486)
;;     1229:0E6D (in fn1229_0DCC)
fn1E78_029C proc
	mov	bx,sp
	mov	dx,ss:[bx+4h]
	or	dx,dx
	jz	02BCh

l1E78_02A6:
	mov	ax,40h
	mov	es,ax
	xor	di,di
	mov	al,es:[di]
	mov	bx,[0B8B4h]

l1E78_02B4:
	mov	cx,bx
	call	02BFh
	dec	dx
	jnz	02B4h

l1E78_02BC:
	retf	2h
