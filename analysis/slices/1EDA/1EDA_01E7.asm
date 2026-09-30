;; fn1EDA_01E7: 1EDA:01E7
;;   Called from:
;;     1EDA:018F (in fn1EDA_011B)
;;     1EDA:01AC (in fn1EDA_01A5)
;;     1EDA:01C6 (in fn1EDA_01BF)
;;     1EDA:01C6 (in fn1EDA_01B3)
;;     1EDA:01E3 (in fn1EDA_01DF)
;;     1EDA:01E5 (in fn1EDA_01DF)
fn1EDA_01E7 proc
	mov	dl,al
	mov	ah,6h
	int	21h
	ret
1EDA:01EE                                           00 02               ..
1EDA:01F0 1B 21 23 24 34 35 36 37 38 39 3A 3B 3C 3D 3E 3F .!#$456789:;<=>?
1EDA:0200 75 52 75 6E 74 69 6D 65 20 65 72 72 6F 72 20 00 uRuntime error .
1EDA:0210 20 61 74 20 00 2E 0D 0A 00 50 6F 72 74 69 6F 6E  at .....Portion
1EDA:0220 73 20 43 6F 70 79 72 69 67 68 74 20 28 63 29 20 s Copyright (c) 
1EDA:0230 31 39 38 33 2C 39 30 20 42 6F 72 6C 61 6E 64    1983,90 Borland
