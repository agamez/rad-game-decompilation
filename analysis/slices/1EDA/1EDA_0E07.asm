;; fn1EDA_0E07: 1EDA:0E07
;;   Called from:
;;     0800:4367 (in fn0800_4255)
fn1EDA_0E07 proc
	mov	ah,2Ch
	int	21h
	mov	[5382h],cx
	mov	[5384h],dx
	retf
