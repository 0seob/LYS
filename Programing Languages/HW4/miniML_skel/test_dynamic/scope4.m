let a = 3
in let p = proc (z) a
in let f = proc (a) (p 0)
in let a = 5
in (f 2)
