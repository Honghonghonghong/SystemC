#include "systemc.h"
#include <stdint.h>

SC_MODULE(TEST)	{
	sc_in<bool> clock;
	sc_out<uint32_t> mem_addr, mem_din;
	sc_out<bool> mem_is_rd, mem_is_wr;
	
	sc_in<uint32_t> mem_dout;//del

	void do_test();

	SC_CTOR(TEST){
		SC_CTHREAD(do_test, clock.neg());
		
		mem_addr.initialize(0);
		mem_din.initialize(0);
		mem_is_rd.initialize(0);
		mem_is_wr.initialize(0);

	}

};
