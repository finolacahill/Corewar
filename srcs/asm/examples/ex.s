.name "zork"
.comment "loloolol:wq"

l2: sti	r1,%:live,%1
and	r1,%0,r1
l3:;
live:	live	%1
	zjmp	%:live
