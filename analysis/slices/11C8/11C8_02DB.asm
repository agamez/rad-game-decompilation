;; fn11C8_02DB: 11C8:02DB
;;   Called from:
;;     11C8:02F7 (in fn11C8_02F0)
;;     11C8:02FE (in fn11C8_02F0)
;;     11C8:0305 (in fn11C8_02F0)
;;     11C8:030C (in fn11C8_02F0)
;;     11C8:0313 (in fn11C8_02F0)
;;     11C8:031A (in fn11C8_02F0)
;;     11C8:0321 (in fn11C8_02F0)
;;     11C8:0328 (in fn11C8_02F0)
;;     11C8:032F (in fn11C8_02F0)
;;     11C8:0336 (in fn11C8_02F0)
;;     11C8:0375 (in fn11C8_0354)
;;     11C8:0387 (in fn11C8_0354)
;;     11C8:03AF (in fn11C8_0394)
fn11C8_02DB proc
	push	bp
	mov	bp,sp
	mov	al,[bp+6h]
	push	ax
	call	0282h
	mov	al,[bp+4h]
	push	ax
	call	0296h
	leave
	ret	4h
