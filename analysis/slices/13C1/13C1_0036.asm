;; fn13C1_0036: 13C1:0036
;;   Called from:
;;     1229:0597 (in fn1229_050A)
fn13C1_0036 proc
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
