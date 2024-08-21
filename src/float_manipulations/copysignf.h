#define mycopysignf(x, y) ((float)(((x >= 0.0f) ? x:-x)*((y >= 0.0f) ? 1.0f:-1.0f)))
