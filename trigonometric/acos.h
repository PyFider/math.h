#define myacos(num, accuracy) (__myacos_s_tart_((num), (accuracy)))
#define __myacos_s_tart_(num, acc) ((PI/2)-myasin(num, acc))
