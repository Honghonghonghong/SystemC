#include "systemc.h"
#include <stdint.h>

SC_MODULE(TEST) {
    sc_in<bool> clock;
    sc_out<bool> alu_is_imm, alu_in_reset;
	sc_out<sc_uint<4> > alu_in_op;
    sc_out<uint32_t> alu_in_a, alu_in_b, alu_in_imm;
    sc_in<uint32_t> alu_result;
	

    void do_test();

    SC_CTOR(TEST) {
        SC_CTHREAD(do_test, clock.neg());
        alu_is_imm.initialize(0);
        alu_in_a.initialize(0);
        alu_in_b.initialize(0);
        alu_in_imm.initialize(0);
		alu_in_op.initialize(0);
		alu_in_reset.initialize(0);
    }
};

