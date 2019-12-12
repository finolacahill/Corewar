.name "TESTOUILLES"
.comment "sisi 347"

ld %2, r1
st r1, :live
st r1, r2

live: live %0
