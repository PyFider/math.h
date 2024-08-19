#define myremainder(num1, num2) 	__num1_sign((num1))*__mod_myfabs(num1, (num2))
#define __num1_sign(num1)		((num1)/myfabs((num1)))
#define __mod_myfabs(num1, num2)	(myfabs(myfmod(num1, num2)))

