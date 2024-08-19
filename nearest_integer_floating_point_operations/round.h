#define myround(num) ((num >= 0.0f) ? __myround_get_res(num, 1.0f):__myround_get_res(num, -1.0f))
#define __myround_get_res(num, sign) (sign*num - (int)(sign*num) >= 0.5) ? sign*(float)((int)(num*sign) + 1):sign*(float)((int)(sign*num)) 

/*
In function form logic of my macro
float round(float num) {
        if (num >= 0.0f) {
                if (num - (int)num >= 0.5)
                        return (float)((int)num+1);
                else
                        return (float)((int)num);
        } else {
                num *= -1.0f;
                if (num - (int)num >= 0.5)
                        return (-1.0f)*(float)((int)num+1);
                else
                        return (-1.0f)*(float)((int)num);
        }
}
*/
