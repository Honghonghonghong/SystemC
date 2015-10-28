#include "alu.h"
#include "test.h"
#include <stdint.h>

int sc_main(int argc, char **argv) {
    sc_signal<bool> sig_alu_is_imm;
    sc_signal<uint32_t> sig_alu_in_a, sig_alu_in_b, sig_alu_in_imm;
    sc_signal<uint32_t> sig_alu_result;
	sc_signal<sc_uint<4> > sig_alu_in_op;

    sc_set_time_resolution(1, SC_NS);
    //sc_set_default_time_unit(1, SC_NS);
    sc_clock sig_clock("clock", 10, SC_NS);

    ALU alu("alu");
    alu.is_imm(sig_alu_is_imm);
    alu.in_a(sig_alu_in_a);
    alu.in_b(sig_alu_in_b);
    alu.in_imm(sig_alu_in_imm);
    alu.result(sig_alu_result);
	alu.in_op(sig_alu_in_op);

    TEST test("test");
    test.clock(sig_clock);
    test.alu_is_imm(sig_alu_is_imm);
    test.alu_in_a(sig_alu_in_a);
    test.alu_in_b(sig_alu_in_b);
    test.alu_in_imm(sig_alu_in_imm);
    test.alu_result(sig_alu_result);
    
    test.alu_in_op(sig_alu_in_op);

    sc_trace_file *tf = sc_create_vcd_trace_file("wave");
    ((vcd_trace_file*)tf)->sc_set_vcd_time_unit(-9);
    sc_trace(tf, sig_clock, "clock");

    sc_trace(tf, alu.in_a, "alu.in_a");
    sc_trace(tf, alu.in_b, "alu.in_b");
	sc_trace(tf, alu.in_op, "alu.in_op");
    sc_trace(tf, alu.in_imm, "alu.in_imm");
    sc_trace(tf, alu.is_imm, "alu.is_imm");
    sc_trace(tf, alu.result, "alu.result");

    sc_start(200, SC_NS);
    sc_close_vcd_trace_file(tf);
    return 0;
}
