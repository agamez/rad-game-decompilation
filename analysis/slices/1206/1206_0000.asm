;; fn1206_0000: 1206:0000
;;   Called from:
;;     1206:01B4 (in fn1206_01AC)
fn1206_0000 proc
	enter	6h,0h
	mov	byte ptr [bp-1h],1h
	mov	al,[bp-1h]
	leave
	retf
