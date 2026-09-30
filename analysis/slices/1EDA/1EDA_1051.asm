;; fn1EDA_1051: 1EDA:1051
;;   Called from:
;;     0800:01EF (in fn0800_0147)
;;     0800:0247 (in fn0800_01FE)
;;     0800:04C5 (in fn0800_03F8)
;;     0800:12DB (in fn0800_11EF)
;;     0800:2471 (in fn0800_2401)
;;     0800:28C4 (in fn0800_2827)
;;     0800:36BF (in fn0800_31B7)
;;     0800:41BB (in fn0800_4168)
;;     0C43:00A1 (in fn0C43_0095)
;;     0C74:05B1 (in fn0C74_03D4)
;;     1229:0477 (in fn1229_039D)
;;     1229:04F7 (in fn1229_0486)
;;     1229:09E6 (in fn1229_0735)
;;     1AB8:0962 (in fn1AB8_0887)
;;     1AB8:0A8C (in fn1AB8_097B)
;;     1AB8:16AC (in fn1AB8_1536)
;;     1AB8:16DF (in fn1AB8_1536)
;;     1EDA:1001 (in fn1EDA_0FD0)
fn1EDA_1051 proc
	mov	bx,sp
	les	di,ss:[bx+4h]
	call	1076h
	jnz	1073h

l1EDA_105C:
	mov	bx,es:[di]
	cmp	bx,4h
	jbe	106Dh

l1EDA_1064:
	mov	ah,3Eh
	int	21h
	jnc	106Dh

l1EDA_106A:
	mov	[5380h],ax

l1EDA_106D:
	mov	word ptr es:[di+2h],0D7B0h

l1EDA_1073:
	retf	4h
