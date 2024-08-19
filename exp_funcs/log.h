#define __log_uncorrectable_arg_() {\
		__asm__ __volatile__ (\
	            "movq %0, %%rdi\n\t" 							/* Prepare message pointer for write syscall */\
		    "movl $1, %%eax\n\t" 							/* Write syscall number */\
		    "movq $1, %%rsi\n\t" 							/* File descriptor (stdout) */\
		    "movl $19, %%edx\n\t" 							/* Length of the message */\
		    "syscall\n\t"        							/* Perform the write syscall */\
		    "movq $60, %%rax\n\t" 							/* Prepare exit syscall number */\
		    "movl $0, %%edi\n\t"  							/* Exit code */\
		    "syscall"             							/* Perform the exit syscall */\
		    :												\
		    : "r" ("Log argument is 0 or negative")			                /* Message pointer passed as a parameter */\
		    : "%rax", "%rdi", "%rsi", "%rdx" 						/* Clobber list */\
		);\
}

double mylog(double x) {
    if (x <= 0)
		 __log_uncorrectable_arg_();

    double res, term, term_squared, numerator;
    int n;

    /* TAYLOR */
	res = 0.0f;
	term = (x-1)/(x+1);
	term_squared = term*term;
	numerator = term;
	n = 1;
    for (;;term = numerator / n, res += term, numerator *= term_squared, n += 2)
    	if (term < EPSILON && term > -EPSILON)
    		break;
	
	res *= 2;
    return res;
}
