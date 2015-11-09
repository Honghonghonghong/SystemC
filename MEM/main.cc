#include "mem.h"
#include "test.h"
#include <stdint.h>

int sc_main(int argc, char **argv){
	sc_signal<uint32_t> sig_mem_addr;
	sc_signal<bool> sig_mem_is_rd, sig_mem_is_wr;
	sc_signal<uint32_t> sig_mem_din;

	sc_signal<uint32_t> sig_mem_dout;

	sc_set_time_resolution(1, SC_NS);
	sc_clock sig_clock("clock", 10, SC_NS);

	MEM mem("mem", NULL, 128);
	mem.addr(sig_mem_addr);
	mem.is_rd(sig_mem_is_rd);
	mem.is_wr(sig_mem_is_wr);
	mem.din(sig_mem_din);
	mem.dout(sig_mem_dout);
	
	/*
		sc_in<bool> clock;
	sc_out<uint32_t> mem_addr, mem_din;
	sc_out<bool> mem_is_rd, mem_is_wr;
	
	sc_in<uint32_t> mem_dout;//del*/
	
	TEST test("test");
	test.clock(sig_clock);
	test.mem_addr(sig_mem_addr);
	test.mem_is_rd(sig_mem_is_rd);
	test.mem_is_wr(sig_mem_is_wr);
	test.mem_din(sig_mem_din);
	test.mem_dout(sig_mem_dout);

	sc_trace_file *tf = sc_create_vcd_trace_file("wave");
	((vcd_trace_file*)tf) -> sc_set_vcd_time_unit(-9);
	sc_trace(tf, sig_clock, "clock");
	
	sc_trace(tf, mem.addr, "mem.addr");
	sc_trace(tf, mem.is_rd, "is_rd");
	sc_trace(tf, mem.is_wr, "is_wr");
	sc_trace(tf, mem.din, "mem.din");
	sc_trace(tf, mem.dout, "mem.dout");
	//sc_trace(tf, mem.mem_data[0], "mem0");
	//sc_trace(tf, mem.mem_data[1], "mem1");
	
	for(int i = 0; i<128; i++)
	{
		int f, s, t;
		f = i/100;
		s = (i-f*100)/10;
		t = (i-f*100-s*10);
		
		char buffer[4];
		buffer[0]='0'+f;
		buffer[1]='0'+s;
		buffer[2]='0'+t;
		buffer[3]='\0';
		
		sc_trace(tf, mem.mem_data[i], buffer);
	}
	
		

	sc_start(1000, SC_NS);
	sc_close_vcd_trace_file(tf);
	
	return 0;

}
