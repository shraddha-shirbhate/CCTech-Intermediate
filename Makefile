# CPPFLAGS:=-save-temps
.PHONY: all
all: testVerify

.PHONY: clean
clean:
	$(RM) *.[adios] *.out *.o ./testVerify