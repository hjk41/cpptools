#ifndef PORT_MATH_H
#define PORT_MATH_H

//--------------------------
#ifdef __cplusplus
extern "C"
{
#endif
//--------------------------
#define isnan(x) ((x) != (x))

double erfc(double x);
void srand48(long int seedval);
long int lrand48(void);
double drand48(void);

//--------------------------
#ifdef __cplusplus
}
#endif
//--------------------------

#endif