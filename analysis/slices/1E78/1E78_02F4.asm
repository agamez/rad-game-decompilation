;; fn1E78_02F4: 1E78:02F4
;;   Called from:
;;     11C8:0345 (in fn11C8_033B)
;;     1229:04ED (in fn1229_0486)
;;     1229:0E9D (in fn1229_0DCC)
fn1E78_02F4 proc
	in	al,61h
	and	al,0FCh
	out	61h,al
	retf
