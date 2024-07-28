.global reset 
reset:
	ldr sp,=stack_top //init sp
	bl main  		  // branch main
stop : b stop	      // branch here if main stop