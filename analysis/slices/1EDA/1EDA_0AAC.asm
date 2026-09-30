;; fn1EDA_0AAC: 1EDA:0AAC
;;   Called from:
;;     0800:069E (in fn0800_0619)
;;     0800:06CA (in fn0800_0619)
;;     0800:06FD (in fn0800_0619)
;;     0800:0739 (in fn0800_0619)
;;     0800:0ADF (in fn0800_0AA1)
;;     0800:0B80 (in fn0800_0B42)
;;     0800:0E56 (in fn0800_0D20)
;;     0800:0EA6 (in fn0800_0D20)
;;     0800:0EB1 (in fn0800_0D20)
;;     0800:101F (in fn0800_0D20)
;;     0800:225F (in fn0800_21E7)
;;     0800:2269 (in fn0800_21E7)
;;     0800:229E (in fn0800_21E7)
;;     0800:22A8 (in fn0800_21E7)
;;     0800:3FB6 (in fn0800_3D9D)
;;     0800:3FC0 (in fn0800_3D9D)
;;     0C74:015B (in fn0C74_011E)
;;     0C74:0249 (in fn0C74_020C)
;;     1229:0112 (in fn1229_0040)
;;     1229:025F (in fn1229_0040)
;;     1229:0579 (in fn1229_050A)
;;     1229:0583 (in fn1229_050A)
;;     1229:059C (in fn1229_050A)
;;     1229:05A6 (in fn1229_050A)
;;     1229:067A (in fn1229_061B)
;;     1229:0684 (in fn1229_061B)
;;     1229:0795 (in fn1229_0735)
;;     1229:079F (in fn1229_0735)
;;     1229:0826 (in fn1229_0735)
;;     1229:0830 (in fn1229_0735)
;;     1229:0854 (in fn1229_0735)
;;     1229:085E (in fn1229_0735)
;;     1229:0A32 (in fn1229_09F9)
;;     1229:0A61 (in fn1229_09F9)
;;     1229:0B96 (in fn1229_0AA8)
;;     1229:0BA0 (in fn1229_0AA8)
;;     1229:0BAA (in fn1229_0AA8)
;;     1229:0BB4 (in fn1229_0AA8)
;;     1229:0BC6 (in fn1229_0AA8)
;;     1229:0BD0 (in fn1229_0AA8)
;;     1229:0BE2 (in fn1229_0AA8)
;;     1229:0BEC (in fn1229_0AA8)
;;     1229:0BFE (in fn1229_0AA8)
;;     1229:0C08 (in fn1229_0AA8)
;;     1229:0C1A (in fn1229_0AA8)
;;     1229:0C24 (in fn1229_0AA8)
;;     1229:0C2E (in fn1229_0AA8)
;;     133F:02C8 (in fn133F_026B)
;;     133F:02D2 (in fn133F_026B)
;;     13E2:01D8 (in fn13E2_0193)
;;     13E2:01E2 (in fn13E2_0193)
;;     13E2:01EC (in fn13E2_0193)
;;     1AB8:02F3 (in fn1AB8_027E)
;;     1AB8:02FD (in fn1AB8_027E)
;;     1AB8:032D (in fn1AB8_027E)
;;     1AB8:0337 (in fn1AB8_027E)
;;     1AB8:03B8 (in fn1AB8_027E)
;;     1AB8:03C2 (in fn1AB8_027E)
;;     1AB8:045E (in fn1AB8_027E)
;;     1AB8:0468 (in fn1AB8_027E)
;;     1AB8:04D0 (in fn1AB8_027E)
;;     1AB8:04DA (in fn1AB8_027E)
;;     1AB8:08E4 (in fn1AB8_0887)
;;     1AB8:09B8 (in fn1AB8_097B)
;;     1AB8:0D3F (in fn1AB8_0BAE)
;;     1AB8:1623 (in fn1AB8_1536)
;;     1EDA:0BA0 (in fn1EDA_0B7C)
;;     1EDA:0BBA (in fn1EDA_0B7C)
;;     1EDA:0C0F (in fn1EDA_0BD0)
fn1EDA_0AAC proc
	cld
	mov	bx,sp
	mov	dx,ds
	les	di,ss:[bx+8h]
	lds	si,ss:[bx+4h]
	mov	cl,es:[di]
	xor	ch,ch
	lodsb
	add	es:[di],al
	jnc	0ACCh

l1EDA_0AC4:
	mov	byte ptr es:[di],0FFh
	mov	al,cl
	not	al

l1EDA_0ACC:
	add	di,cx
	inc	di
	mov	cl,al
	rep movsb
	mov	ds,dx
	retf	4h
