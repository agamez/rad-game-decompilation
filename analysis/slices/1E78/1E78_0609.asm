;; fn1E78_0609: 1E78:0609
;;   Called from:
;;     1E78:0030 (in fn1E78_002E)
;;     1E78:0048 (in fn1E78_002E)
;;     1E78:00AF (in fn1E78_0097)
;;     1E78:00BC (in fn1E78_0097)
;;     1E78:00C6 (in fn1E78_0097)
;;     1E78:00DA (in fn1E78_0097)
;;     1E78:00E1 (in fn1E78_0097)
;;     1E78:00E7 (in fn1E78_00E5)
;;     1E78:00F2 (in fn1E78_00E5)
;;     1E78:01CF (in fn1E78_01C0)
;;     1E78:04A1 (in fn1E78_047C)
;;     1E78:04B5 (in fn1E78_047C)
;;     1E78:04F0 (in fn1E78_04D5)
;;     1E78:04FA (in fn1E78_04F6)
;;     1E78:0501 (in fn1E78_04FD)
fn1E78_0609 proc
	push	si
	push	di
	push	bp
	push	es
	int	10h
	pop	es
	pop	bp
	pop	di
	pop	si
	ret
1E78:0614             00 00 00 00 00 00 00 00 00 00 00 00     ............
