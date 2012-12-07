#ifndef __RMATH_H__98A0D7C0_EA52_47BA_9965_0AA09D420C37
#define __RMATH_H__98A0D7C0_EA52_47BA_9965_0AA09D420C37

#include <stdlib.h>

// regular access, col major storage
#define M_IDX(I,J,NCOLS) ((I) * (NCOLS) + (J))
// transposed access, col major storage
#define M_IDX_T(I,J,NCOLS) ((I) + (J) * (NCOLS))

// more consise, use this instead of M_IDX*
#define MIDX(M,I,J) ((M)->v[M_IDX((I),(J),(M)->cols)])
#define MIDXT(M,I,J) ((M)->v[M_IDX_T((I),(J),(M)->cols)])

typedef struct {
	float *v;
	size_t rows;
	size_t cols;
} matf;

matf* matf_new (size_t rows, size_t cols);
void matf_free (matf *A);
matf* matf_cpy (matf *M);
void matf_cpyi (matf *Dst, matf *Src);
matf* matf_new_val (size_t rows, size_t cols, float v);
matf* matf_eye (size_t rows);

void matf_norm_r1 (matf *M, size_t r);
void matf_norm_r (matf *M);
void matf_norm_c1 (matf *M, size_t c);
void matf_norm_c (matf *M);

void matf_set (matf *M, float v);
float dotp (float *p1, int s1, float *p2, int s2, unsigned int n);

matf* matf_apply (matf *A, float (*fp)(float));
void matf_applyi (matf *A, float (*fp)(float));

matf* matf_add (matf *A, matf *B);
void matf_addi (matf *A, matf *B);

matf* matf_sub (matf *A, matf *B);
void matf_subi (matf *A, matf *B);

matf* matf_mul (matf *A, matf *B);
matf* matf_transpose (matf *A);

matf* matf_mul_elems (matf *A, matf *B);
void matf_mul_elemsi (matf *A, matf *B);

matf* matf_mul_scalar (matf *A, float s);
void matf_mul_scalari (matf *A, float s);

void matf_dump_linear (matf *A);
void matf_dump (matf *A);
void matf_dump_transposed (matf *A);


#endif /* __RMATH_H__98A0D7C0_EA52_47BA_9965_0AA09D420C37 */

