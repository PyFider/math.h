#define mycopysignl(x, y) ((long double)(((x >= 0.0f) ? x:-x)*((y >= 0.0f) ? 1.0f:-1.0f)))
