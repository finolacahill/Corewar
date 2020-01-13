.name "xXx_Awesome_chamP_xXx"
.comment "compote aux pommes"

live_loop:	live %0
			zjmp %:live_loop

ld %0, r2
aff r2
st r1, r3

init_reg:	st r3, r1

init_att:	sti r1, %:att, %1
			sti r1, %:live, %1
			sti r1, %:live_loop, %1
			ld %0, r2
			aff r2
			fork %:att
			fork %:live_loop

live:		live %0
			zjmp %:init_reg		

att:		live %0
