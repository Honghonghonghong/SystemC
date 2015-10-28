#include "systemc.h"
#include <stdint.h>


SC_MODULE(MUX_2X1) {
    sc_in<bool> select;
    sc_in<uint32_t> in_0, in_1;
    sc_out<uint32_t> out;

    void do_mux_2x1();

    SC_CTOR(MUX_2X1) {
        SC_METHOD(do_mux_2x1);
        sensitive << select << in_0 << in_1;
        out.initialize(0);
    }
};

SC_MODULE(MUX_4X1) {
	sc_in<sc_uint<4> > op;
	sc_in<uint32_t> addR, subR, andR, orrR;
	sc_out<uint32_t> out;

	void do_mux_4x1();

	SC_CTOR(MUX_4X1) {
		SC_METHOD(do_mux_4x1);
		sensitive << op << addR << subR << andR<< orrR;
		out.initialize(0);
	}
};

SC_MODULE(ADDER) {
    sc_in<uint32_t> a, b;
    sc_out<uint32_t> result;

    void do_adder();

    SC_CTOR(ADDER) {
        SC_METHOD(do_adder);
        sensitive << a << b;
        result.initialize(0);
    }
};

SC_MODULE(SUBM){
    sc_in<uint32_t> a, b;
    sc_out<uint32_t> result;

    void do_subm();

    SC_CTOR(SUBM) {
        SC_METHOD(do_subm);
        sensitive << a << b;
        result.initialize(0);
    }
};
SC_MODULE(ANDM){
    sc_in<uint32_t> a, b;
    sc_out<uint32_t> result;

    void do_andm();

    SC_CTOR(ANDM) {
        SC_METHOD(do_andm);
        sensitive << a << b;
        result.initialize(0);
    }
};

SC_MODULE(ORRM){
    sc_in<uint32_t> a, b;
    sc_out<uint32_t> result;

    void do_orrm();

    SC_CTOR(ORRM) {
        SC_METHOD(do_orrm);
        sensitive << a << b;
        result.initialize(0);
    }
};

SC_MODULE(ALU) {
    sc_in<uint32_t> in_a, in_b, in_imm;
    sc_in<bool> is_imm;
	sc_in<sc_uint<4> > in_op;
    sc_out<uint32_t> result;

    MUX_2X1 mux_in2;
	MUX_4X1 mux_4x1;
    ADDER   adder;
	SUBM	subm;
	ANDM	andm;
	ORRM	orrm;
	
    sc_signal<uint32_t> sig_mux_in2_out;
	sc_signal<uint32_t> sig_add_result, sig_sub_result, sig_and_result, sig_orr_result;

    SC_CTOR(ALU) :
            mux_in2("mux_in2"),
			mux_4x1("mux_4x1"),
            adder("adder"),
			subm("subm"),
			andm("andm"),
			orrm("orrm")
			
    {
        mux_in2.select(is_imm);
        mux_in2.in_0(in_b);
        mux_in2.in_1(in_imm);
        mux_in2.out(sig_mux_in2_out);

		mux_4x1.op(in_op);
		mux_4x1.andR(sig_and_result);
		mux_4x1.addR(sig_add_result);
		mux_4x1.orrR(sig_orr_result);
		mux_4x1.subR(sig_sub_result);
		mux_4x1.out(result);

        adder.a(in_a);
        adder.b(sig_mux_in2_out);
		adder.result(sig_add_result);        
		//adder.result(result);

		subm.a(in_a);
		subm.b(sig_mux_in2_out);
		subm.result(sig_sub_result);
		
		andm.a(in_a);
		andm.b(sig_mux_in2_out);
		andm.result(sig_and_result);
		
		orrm.a(in_a);
		orrm.b(sig_mux_in2_out);
		orrm.result(sig_orr_result);

        result.initialize(0);
    }
};

