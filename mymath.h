#define PI 		3.141592653589793
#define E  		2.718281828459045
#define EPSILON 	1e-10
#define nan		1
#define ACC_TRIG_VAL  100

#include "nearest_integer_floating_point_operations/floor.h"
#include "nearest_integer_floating_point_operations/ceil.h"
#include "nearest_integer_floating_point_operations/trunc.h"
#include "nearest_integer_floating_point_operations/round.h"
#include "nearest_integer_floating_point_operations/lround.h"
#include "nearest_integer_floating_point_operations/llround.h"
#include "nearest_integer_floating_point_operations/rint.h"
#include "nearest_integer_floating_point_operations/lrint.h"
#include "nearest_integer_floating_point_operations/llrint.h"

#include "more/fabs.h"
#include "more/fdim.h"
#include "more/fmax.h"
#include "more/fmin.h"
#include "more/fma.h"
#include "more/fmod.h"
#include "more/remainder.h"

#include "exp_funcs/exp.h"
#include "exp_funcs/log.h"
#include "exp_funcs/log2.h"
#include "exp_funcs/log10.h"
#include "exp_funcs/log1p.h"
#include "exp_funcs/logb.h"
#include "exp_funcs/ilogb.h"
#include "power_functions/pow.h" 
#include "exp_funcs/exp2.h"
#include "exp_funcs/expm1.h"

#include "power_functions/sqrt.h"
#include "power_functions/cbrt.h"
#include "power_functions/hypot.h"

#include "trigonometric/sin.h"
#include "trigonometric/cos.h"
#include "trigonometric/tg.h"
#include "trigonometric/ctg.h"
#include "trigonometric/asin.h"
#include "trigonometric/acos.h"
#include "trigonometric/atg.h"
#include "trigonometric/actg.h"
#include "trigonometric/atg2.h"

#include "hyperbolic_functions/sinh.h"
#include "hyperbolic_functions/cosh.h"
#include "hyperbolic_functions/tgh.h"
#include "hyperbolic_functions/ctgh.h"
#include "hyperbolic_functions/asinh.h" /* TODO */
#include "hyperbolic_functions/acosh.h" /* TODO */
#include "hyperbolic_functions/atgh.h"  /* TODO */
#include "hyperbolic_functions/actgh.h" /* TODO */

/* TODO FLOAT MANIPUTLATIONS */
#include "float_manipulations/frexp.h"
#include "float_manipulations/ldexp.h"
