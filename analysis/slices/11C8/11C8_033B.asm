;; fn11C8_033B: 11C8:033B
;;   Called from:
;;     0800:03C2 (in fn0800_031B)
;;     0C74:073C (in fn0C74_070D)
;;     0C74:0910 (in fn0C74_076B)
;;     0C74:0BD2 (in fn0C74_0A35)
;;     0C74:2E1B (in fn0C74_2BBD)
;;     0C74:31F1 (in fn0C74_2E5A)
;;     0C74:35D0 (in fn0C74_3236)
;;     0C74:36C9 (in fn0C74_3615)
;;     0C74:3778 (in fn0C74_3615)
;;     0C74:3876 (in fn0C74_37C3)
;;     0C74:3923 (in fn0C74_37C3)
;;     0C74:48B6 (in fn0C74_45CE)
;;     0C74:4916 (in fn0C74_45CE)
;;     0C74:4CCB (in fn0C74_4999)
;;     0C74:4D2D (in fn0C74_4999)
;;     11C8:03B5 (in fn11C8_0394)
fn11C8_033B proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [5976h],0h
	jnz	034Ch

l11C8_0345:
	call	far 1E78h:02F4h
	jmp	0352h

l11C8_034C:
	push	0h
	push	cs
	call	0236h

l11C8_0352:
	leave
	retf
