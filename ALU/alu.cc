#include "alu.h"

void ALU::do_alu()
{
	if(result ==0)
		zero = true;
	else
		zero = false;
}

void MUX_2X1::do_mux_2x1()
{
    out = select ? in_1 : in_0;
    //cout << sc_simulation_time() << " " << out << endl;
}

void MUX_5X2::do_mux_5x2()
{
/*
	if(op.read() == 0x0){}
	else if(op.read() == 0x2)
		out = subR;
	else if(op.read() == 0x4)
		out = addR;
	else if(op.read() == 0xC){}*/
	if(reset){
		out = 0;
	}
	else{
		switch(op.read())//read!
		{
		case 0x0:
			out = andR;
			break;
		case 0x2:
			out = subR;		
			break;
		case 0x4:
			out = addR;
			break;
		case 0xC:
			out = orrR;
			break;
		default:
			break;
		}

	}
	
}

void ADDER::do_adder()
{
    result = a.read() + b.read();
}

void SUBM::do_subm()
{
	if(a>b)
   		result = a - b;
   	else
   		result = b - a;
}

void ANDM::do_andm()
{
    result = a & b;
}

void ORRM::do_orrm()
{
    result = a | b;
}



