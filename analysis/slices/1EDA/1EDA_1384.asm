;; fn1EDA_1384: 1EDA:1384
;;   Called from:
;;     0800:0F7E (in fn0800_0D20)
;;     0800:3B1E (in fn0800_391E)
;;     1229:01ED (in fn1229_0040)
;;     1229:03E4 (in fn1229_039D)
;;     133F:058B (in fn133F_0528)
fn1EDA_1384 proc
	mov	bx,sp
	mov	al,ss:[bx+4h]
	cmp	al,61h
	jc	1394h

l1EDA_138E:
	cmp	al,7Ah
	ja	1394h

l1EDA_1392:
	sub	al,20h

l1EDA_1394:
	retf	2h
1EDA:1397                      00 00 00 00 00 00 00 00 00        .........
