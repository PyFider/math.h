double myfrexp(double num, int* e) 
{
    *e = 0;
    if (num == 0)
        return 0.0f;
    
    num *= ((num > 0) ? 1:-1);
    goto greater_one;
    goto lower_half_one;
    goto end;

greater_one:
    if (num >= 1.0f) {
    	num /= 2.0f;
    	(*e)++;
    	goto greater_one;
    }

lower_half_one:
    if (num < 0.5f) {	
    	num *= 2.0f;
	(*e)--;
    	goto lower_half_one;
    }

end:
    return num;
}

/*
UNDERSTAND VERSION(LOWER)
double myfrexp(double num, int* e) 
{
    *e = 0;
    if (num == 0)
        return 0.0f;
    
    num *= ((num > 0) ? 1:-1);
    for (;num >= 1.0f; num /= 2.0f, (*e)++)
        ;
    for (;num < 0.5f; num *= 2.0f, (*e)--)
        ;
}
*/
