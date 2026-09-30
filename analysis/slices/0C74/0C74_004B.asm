;; fn0C74_004B: 0C74:004B
;;   Called from:
;;     0800:052D (in fn0800_04E3)
;;     0800:0553 (in fn0800_04E3)
;;     0800:0579 (in fn0800_04E3)
;;     0800:05A6 (in fn0800_04E3)
;;     0800:05CC (in fn0800_04E3)
;;     0800:05F2 (in fn0800_04E3)
;;     0800:065F (in fn0800_0619)
;;     0800:0AB3 (in fn0800_0AA1)
;;     0800:0B54 (in fn0800_0B42)
;;     0800:225A (in fn0800_21E7)
;;     0C74:0130 (in fn0C74_011E)
;;     0C74:021E (in fn0C74_020C)
fn0C74_004B proc
	enter	100h,0h
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	0h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0F26h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	retf	4h
