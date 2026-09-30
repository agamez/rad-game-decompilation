;; fn1EDA_096F: 1EDA:096F
;;   Called from:
;;     0800:3C28 (in fn0800_3BF2)
;;     0800:3C9A (in fn0800_3C72)
;;     0C74:1042 (in fn0C74_0FA1)
;;     0C74:15F4 (in fn0C74_0FA1)
;;     0C74:16CE (in fn0C74_0FA1)
;;     0C74:184A (in fn0C74_0FA1)
;;     0C74:18BD (in fn0C74_0FA1)
;;     0C74:197D (in fn0C74_0FA1)
;;     0C74:1AF3 (in fn0C74_0FA1)
;;     0C74:1C2B (in fn0C74_1B3B)
;;     0C74:1D6D (in fn0C74_1B3B)
;;     0C74:1FA9 (in fn0C74_1F08)
;;     0C74:255B (in fn0C74_1F08)
;;     0C74:2651 (in fn0C74_1F08)
;;     0C74:26CD (in fn0C74_1F08)
;;     0C74:2740 (in fn0C74_1F08)
;;     0C74:28F9 (in fn0C74_1F08)
;;     0C74:2A8B (in fn0C74_1F08)
;;     0C74:2B86 (in fn0C74_2AD9)
;;     1AB8:1216 (in fn1AB8_11FB)
fn1EDA_096F proc
	mov	si,ax
	mov	di,dx
	mul	cx
	push	ax
	push	dx
	mov	ax,si
	mul	bx
	mov	bx,ax
	mov	ax,di
	mul	cx
	mov	cx,ax
	pop	dx
	pop	ax
	add	dx,bx
	add	dx,cx
	retf
