//
// File: pred_z_pid_angle.cpp
//
// Code generated for Simulink model 'pred_z_pid_angle'.
//
// Model version                  : 1.363
// Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
// C/C++ source code generated on : Thu May 31 17:50:13 2018
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//

#include "pred_z_pid_angle.h"
#define NumBitsPerChar                 8U

extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern "C" {
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  extern void rt_InitInfAndNaN(size_t realSize);
  extern boolean_T rtIsInf(real_T value);
  extern boolean_T rtIsInfF(real32_T value);
  extern boolean_T rtIsNaN(real_T value);
  extern boolean_T rtIsNaNF(real32_T value);
  typedef struct {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  } BigEndianIEEEDouble;

  typedef struct {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  } LittleEndianIEEEDouble;

  typedef struct {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  } IEEESingle;
}                                      // extern "C"
  extern "C"
{
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}

extern "C" {
  extern real_T rtGetInf(void);
  extern real32_T rtGetInfF(void);
  extern real_T rtGetMinusInf(void);
  extern real32_T rtGetMinusInfF(void);
}                                      // extern "C"
  extern "C"
{
  extern real_T rtGetNaN(void);
  extern real32_T rtGetNaNF(void);
}                                      // extern "C"

extern "C" {
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  boolean_T rtIsNaN(real_T value)
  {
    return (boolean_T)((value!=value) ? 1U : 0U);
  }

  // Test if single-precision value is not a number
  boolean_T rtIsNaNF(real32_T value)
  {
    return (boolean_T)(((value!=value) ? 1U : 0U));
  }
}
  extern "C"
{
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T inf = 0.0;
    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T minf = 0.0;
    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}

extern "C" {
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  real_T rtGetNaN(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;
    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  real32_T rtGetNaNF(void)
  {
    IEEESingle nanF = { { 0 } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}
// Function for MATLAB Function: '<S4>/empuxo '
  void mpcqp_solver_douglas_v4ModelClass::eye(int8_T varargin_1, real_T I_data[],
  int32_T I_sizes[2])
{
  int32_T i;
  int32_T loop_ub;
  I_sizes[0] = varargin_1;
  I_sizes[1] = varargin_1;
  loop_ub = varargin_1 * varargin_1;
  for (i = 0; i < loop_ub; i++) {
    I_data[i] = 0.0;
  }

  if (varargin_1 > 0) {
    for (loop_ub = 0; loop_ub + 1 <= varargin_1; loop_ub++) {
      I_data[loop_ub + varargin_1 * loop_ub] = 1.0;
    }
  }
}

// Function for MATLAB Function: '<S4>/empuxo '
int32_T mpcqp_solver_douglas_v4ModelClass::rankFromQR(const real_T A_data[],
  const int32_T A_sizes[2])
{
  int32_T r;
  r = 0;
  if (A_sizes[1] > 0) {
    while ((r < A_sizes[1]) && (fabs(A_data[A_sizes[0] * r + r]) >= 10.0 * fabs
            (A_data[0]) * 2.2204460492503131E-16)) {
      r++;
    }
  }

  return r;
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::LSQFromQR(const real_T A_data[], const
  int32_T A_sizes[2], const real_T tau_data[], const int32_T jpvt_data[],
  int32_T rankA, real_T Y_data[], int32_T Y_sizes[2])
{
  int32_T i;
  int32_T b_i;
  static const int8_T C[100] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1 };

  int32_T loop_ub;
  int8_T b_idx_0;
  b_idx_0 = (int8_T)A_sizes[1];
  Y_sizes[0] = b_idx_0;
  Y_sizes[1] = 10;
  loop_ub = b_idx_0 * 10;
  for (i = 0; i < loop_ub; i++) {
    Y_data[i] = 0.0;
  }

  for (i = 0; i < 100; i++) {
    rtDW.B_cv[i] = C[i];
  }

  for (loop_ub = 0; loop_ub + 1 <= A_sizes[1]; loop_ub++) {
    if (tau_data[loop_ub] != 0.0) {
      for (i = 0; i < 10; i++) {
        rtDW.wj = rtDW.B_cv[10 * i + loop_ub];
        for (b_i = loop_ub + 1; b_i + 1 < 11; b_i++) {
          rtDW.wj += A_data[A_sizes[0] * loop_ub + b_i] * rtDW.B_cv[10 * i + b_i];
        }

        rtDW.wj *= tau_data[loop_ub];
        if (rtDW.wj != 0.0) {
          rtDW.B_cv[loop_ub + 10 * i] -= rtDW.wj;
          for (b_i = loop_ub + 1; b_i + 1 < 11; b_i++) {
            rtDW.B_cv[b_i + 10 * i] -= A_data[A_sizes[0] * loop_ub + b_i] *
              rtDW.wj;
          }
        }
      }
    }
  }

  for (loop_ub = 0; loop_ub < 10; loop_ub++) {
    for (i = 0; i + 1 <= rankA; i++) {
      Y_data[(jpvt_data[i] + b_idx_0 * loop_ub) - 1] = rtDW.B_cv[10 * loop_ub +
        i];
    }

    for (i = rankA - 1; i + 1 > 0; i--) {
      Y_data[(jpvt_data[i] + b_idx_0 * loop_ub) - 1] /= A_data[A_sizes[0] * i +
        i];
      for (b_i = 0; b_i + 1 <= i; b_i++) {
        Y_data[(jpvt_data[b_i] + b_idx_0 * loop_ub) - 1] -= Y_data[(b_idx_0 *
          loop_ub + jpvt_data[i]) - 1] * A_data[A_sizes[0] * i + b_i];
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/empuxo '
real_T mpcqp_solver_douglas_v4ModelClass::xnrm2(int32_T n, const real_T x_data[],
  int32_T ix0)
{
  real_T y;
  int32_T kend;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x_data[ix0 - 1]);
    } else {
      rtDW.scale_j = 2.2250738585072014E-308;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        rtDW.absxk_d = fabs(x_data[k - 1]);
        if (rtDW.absxk_d > rtDW.scale_j) {
          rtDW.t_gu = rtDW.scale_j / rtDW.absxk_d;
          y = y * rtDW.t_gu * rtDW.t_gu + 1.0;
          rtDW.scale_j = rtDW.absxk_d;
        } else {
          rtDW.t_gu = rtDW.absxk_d / rtDW.scale_j;
          y += rtDW.t_gu * rtDW.t_gu;
        }
      }

      y = rtDW.scale_j * sqrt(y);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T a;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = sqrt(y * y + 1.0) * a;
  } else {
    if (!rtIsNaN(y)) {
      y = a * 1.4142135623730951;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S4>/empuxo '
real_T mpcqp_solver_douglas_v4ModelClass::xzlarfg(int32_T n, real_T *alpha1,
  real_T x_data[], int32_T ix0)
{
  real_T tau;
  int32_T knt;
  int32_T b_k;
  int32_T c_k;
  tau = 0.0;
  rtDW.xnorm_l = xnrm2(n - 1, x_data, ix0);
  if (rtDW.xnorm_l != 0.0) {
    rtDW.xnorm_l = rt_hypotd_snf(*alpha1, rtDW.xnorm_l);
    if (*alpha1 >= 0.0) {
      rtDW.xnorm_l = -rtDW.xnorm_l;
    }

    if (fabs(rtDW.xnorm_l) < 1.0020841800044864E-292) {
      knt = 0;
      do {
        knt++;
        b_k = (ix0 + n) - 2;
        for (c_k = ix0; c_k <= b_k; c_k++) {
          x_data[c_k - 1] *= 9.9792015476736E+291;
        }

        rtDW.xnorm_l *= 9.9792015476736E+291;
        *alpha1 *= 9.9792015476736E+291;
      } while (!(fabs(rtDW.xnorm_l) >= 1.0020841800044864E-292));

      rtDW.xnorm_l = rt_hypotd_snf(*alpha1, xnrm2(n - 1, x_data, ix0));
      if (*alpha1 >= 0.0) {
        rtDW.xnorm_l = -rtDW.xnorm_l;
      }

      tau = (rtDW.xnorm_l - *alpha1) / rtDW.xnorm_l;
      *alpha1 = 1.0 / (*alpha1 - rtDW.xnorm_l);
      b_k = (ix0 + n) - 2;
      for (c_k = ix0; c_k <= b_k; c_k++) {
        x_data[c_k - 1] *= *alpha1;
      }

      for (b_k = 1; b_k <= knt; b_k++) {
        rtDW.xnorm_l *= 1.0020841800044864E-292;
      }

      *alpha1 = rtDW.xnorm_l;
    } else {
      tau = (rtDW.xnorm_l - *alpha1) / rtDW.xnorm_l;
      *alpha1 = 1.0 / (*alpha1 - rtDW.xnorm_l);
      knt = (ix0 + n) - 2;
      for (b_k = ix0; b_k <= knt; b_k++) {
        x_data[b_k - 1] *= *alpha1;
      }

      *alpha1 = rtDW.xnorm_l;
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::xzlarf(int32_T m, int32_T n, int32_T iv0,
  real_T tau, real_T C_data[], int32_T ic0, real_T work_data[])
{
  int32_T lastv;
  int32_T lastc;
  int32_T ix;
  int32_T iy;
  int32_T iac;
  int32_T d;
  int32_T b_ia;
  int32_T jy;
  boolean_T exitg2;
  if (tau != 0.0) {
    lastv = m;
    lastc = iv0 + m;
    while ((lastv > 0) && (C_data[lastc - 2] == 0.0)) {
      lastv--;
      lastc--;
    }

    lastc = n;
    exitg2 = false;
    while ((!exitg2) && (lastc > 0)) {
      iy = (lastc - 1) * 10 + ic0;
      jy = iy;
      do {
        iac = 0;
        if (jy <= (iy + lastv) - 1) {
          if (C_data[jy - 1] != 0.0) {
            iac = 1;
          } else {
            jy++;
          }
        } else {
          lastc--;
          iac = 2;
        }
      } while (iac == 0);

      if (iac == 1) {
        exitg2 = true;
      }
    }
  } else {
    lastv = 0;
    lastc = 0;
  }

  if (lastv > 0) {
    if (lastc != 0) {
      for (iy = 1; iy <= lastc; iy++) {
        work_data[iy - 1] = 0.0;
      }

      iy = 0;
      jy = (lastc - 1) * 10 + ic0;
      for (iac = ic0; iac <= jy; iac += 10) {
        ix = iv0;
        rtDW.c = 0.0;
        d = (iac + lastv) - 1;
        for (b_ia = iac; b_ia <= d; b_ia++) {
          rtDW.c += C_data[b_ia - 1] * C_data[ix - 1];
          ix++;
        }

        work_data[iy] += rtDW.c;
        iy++;
      }
    }

    if (!(-tau == 0.0)) {
      iy = ic0 - 1;
      jy = 0;
      for (iac = 1; iac <= lastc; iac++) {
        if (work_data[jy] != 0.0) {
          rtDW.c = work_data[jy] * -tau;
          ix = iv0;
          d = lastv + iy;
          for (b_ia = iy; b_ia + 1 <= d; b_ia++) {
            C_data[b_ia] += C_data[ix - 1] * rtDW.c;
            ix++;
          }
        }

        jy++;
        iy += 10;
      }
    }
  }
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::qrsolve(const real_T A_data[], const
  int32_T A_sizes[2], real_T Y_data[], int32_T Y_sizes[2])
{
  int32_T pvt;
  int32_T b_n;
  int32_T yk;
  int32_T ix;
  int32_T iy;
  int32_T d_k;
  int32_T work_sizes;
  int8_T c_idx_0;
  rtDW.b_A_sizes_l[0] = 10;
  rtDW.b_A_sizes_l[1] = A_sizes[1];
  b_n = A_sizes[0] * A_sizes[1];
  for (yk = 0; yk < b_n; yk++) {
    rtDW.b_A_data_p[yk] = A_data[yk];
  }

  rtDW.n = A_sizes[1];
  if (A_sizes[1] < 1) {
    b_n = 0;
  } else {
    b_n = A_sizes[1];
  }

  rtDW.jpvt_sizes[0] = 1;
  rtDW.jpvt_sizes[1] = b_n;
  if (b_n > 0) {
    rtDW.jpvt_data[0] = 1;
    yk = 1;
    rtDW.nmi = 2;
    while (rtDW.nmi <= b_n) {
      yk++;
      rtDW.jpvt_data[rtDW.nmi - 1] = yk;
      rtDW.nmi++;
    }
  }

  if (A_sizes[1] != 0) {
    c_idx_0 = (int8_T)A_sizes[1];
    work_sizes = c_idx_0;
    b_n = c_idx_0;
    for (yk = 0; yk < b_n; yk++) {
      rtDW.work_data[yk] = 0.0;
    }

    b_n = 1;
    for (yk = 0; yk + 1 <= rtDW.n; yk++) {
      rtDW.smax_g = 0.0;
      rtDW.s_m = 2.2250738585072014E-308;
      rtDW.nmi = b_n;
      while (rtDW.nmi <= b_n + 9) {
        rtDW.absxk_n = fabs(A_data[rtDW.nmi - 1]);
        if (rtDW.absxk_n > rtDW.s_m) {
          rtDW.t_p = rtDW.s_m / rtDW.absxk_n;
          rtDW.smax_g = rtDW.smax_g * rtDW.t_p * rtDW.t_p + 1.0;
          rtDW.s_m = rtDW.absxk_n;
        } else {
          rtDW.t_p = rtDW.absxk_n / rtDW.s_m;
          rtDW.smax_g += rtDW.t_p * rtDW.t_p;
        }

        rtDW.nmi++;
      }

      rtDW.smax_g = rtDW.s_m * sqrt(rtDW.smax_g);
      rtDW.vn1_data[yk] = rtDW.smax_g;
      rtDW.vn2_data[yk] = rtDW.vn1_data[yk];
      b_n += 10;
    }

    for (b_n = 0; b_n + 1 <= A_sizes[1]; b_n++) {
      yk = b_n * 10 + b_n;
      rtDW.nmi = rtDW.n - b_n;
      if (rtDW.nmi < 1) {
        pvt = 0;
      } else {
        pvt = 1;
        if (rtDW.nmi > 1) {
          ix = b_n;
          rtDW.smax_g = rtDW.vn1_data[b_n];
          for (iy = 2; iy <= rtDW.nmi; iy++) {
            ix++;
            if (rtDW.vn1_data[ix] > rtDW.smax_g) {
              pvt = iy;
              rtDW.smax_g = rtDW.vn1_data[ix];
            }
          }
        }
      }

      pvt = (b_n + pvt) - 1;
      if (pvt + 1 != b_n + 1) {
        ix = 10 * pvt;
        iy = 10 * b_n;
        for (d_k = 0; d_k < 10; d_k++) {
          rtDW.smax_g = rtDW.b_A_data_p[ix];
          rtDW.b_A_data_p[ix] = rtDW.b_A_data_p[iy];
          rtDW.b_A_data_p[iy] = rtDW.smax_g;
          ix++;
          iy++;
        }

        ix = rtDW.jpvt_data[pvt];
        rtDW.jpvt_data[pvt] = rtDW.jpvt_data[b_n];
        rtDW.jpvt_data[b_n] = ix;
        rtDW.vn1_data[pvt] = rtDW.vn1_data[b_n];
        rtDW.vn2_data[pvt] = rtDW.vn2_data[b_n];
      }

      if (b_n + 1 < 10) {
        rtDW.smax_g = rtDW.b_A_data_p[yk];
        rtDW.s_m = xzlarfg(10 - b_n, &rtDW.smax_g, rtDW.b_A_data_p, yk + 2);
        rtDW.tau_data_f[b_n] = rtDW.s_m;
        rtDW.b_A_data_p[yk] = rtDW.smax_g;
      } else {
        rtDW.tau_data_f[9] = 0.0;
      }

      if (b_n + 1 < rtDW.n) {
        rtDW.smax_g = rtDW.b_A_data_p[yk];
        rtDW.b_A_data_p[yk] = 1.0;
        xzlarf(10 - b_n, rtDW.nmi - 1, yk + 1, rtDW.tau_data_f[b_n],
               rtDW.b_A_data_p, (b_n + (b_n + 1) * 10) + 1, rtDW.work_data);
        rtDW.b_A_data_p[yk] = rtDW.smax_g;
      }

      for (yk = b_n + 1; yk + 1 <= rtDW.n; yk++) {
        rtDW.nmi = (10 * yk + b_n) + 1;
        if (rtDW.vn1_data[yk] != 0.0) {
          rtDW.smax_g = fabs(rtDW.b_A_data_p[rtDW.b_A_sizes_l[0] * yk + b_n]) /
            rtDW.vn1_data[yk];
          rtDW.smax_g = 1.0 - rtDW.smax_g * rtDW.smax_g;
          if (rtDW.smax_g < 0.0) {
            rtDW.smax_g = 0.0;
          }

          rtDW.s_m = rtDW.vn1_data[yk] / rtDW.vn2_data[yk];
          rtDW.s_m = rtDW.s_m * rtDW.s_m * rtDW.smax_g;
          if (rtDW.s_m <= 1.4901161193847656E-8) {
            if (b_n + 1 < 10) {
              rtDW.smax_g = 0.0;
              if (9 - b_n == 1) {
                rtDW.smax_g = fabs(rtDW.b_A_data_p[rtDW.nmi]);
              } else {
                rtDW.s_m = 2.2250738585072014E-308;
                pvt = (rtDW.nmi - b_n) + 9;
                while (rtDW.nmi + 1 <= pvt) {
                  rtDW.absxk_n = fabs(rtDW.b_A_data_p[rtDW.nmi]);
                  if (rtDW.absxk_n > rtDW.s_m) {
                    rtDW.t_p = rtDW.s_m / rtDW.absxk_n;
                    rtDW.smax_g = rtDW.smax_g * rtDW.t_p * rtDW.t_p + 1.0;
                    rtDW.s_m = rtDW.absxk_n;
                  } else {
                    rtDW.t_p = rtDW.absxk_n / rtDW.s_m;
                    rtDW.smax_g += rtDW.t_p * rtDW.t_p;
                  }

                  rtDW.nmi++;
                }

                rtDW.smax_g = rtDW.s_m * sqrt(rtDW.smax_g);
              }

              rtDW.vn1_data[yk] = rtDW.smax_g;
              rtDW.vn2_data[yk] = rtDW.vn1_data[yk];
            } else {
              rtDW.vn1_data[yk] = 0.0;
              rtDW.vn2_data[yk] = 0.0;
            }
          } else {
            rtDW.vn1_data[yk] *= sqrt(rtDW.smax_g);
          }
        }
      }
    }
  }

  LSQFromQR(rtDW.b_A_data_p, rtDW.b_A_sizes_l, rtDW.tau_data_f, rtDW.jpvt_data,
            rankFromQR(rtDW.b_A_data_p, rtDW.b_A_sizes_l), Y_data, Y_sizes);
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::mldivide(const real_T A_data[], const
  int32_T A_sizes[2], real_T Y_data[], int32_T Y_sizes[2])
{
  static const int8_T e[100] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1 };

  switch (A_sizes[1]) {
   case 0:
    Y_sizes[0] = 0;
    Y_sizes[1] = 10;
    break;

   case 10:
    rtDW.loop_ub = A_sizes[0] * A_sizes[1];
    for (rtDW.b_jBcol = 0; rtDW.b_jBcol < rtDW.loop_ub; rtDW.b_jBcol++) {
      rtDW.b_A_data_b[rtDW.b_jBcol] = A_data[rtDW.b_jBcol];
    }

    for (rtDW.b_jBcol = 0; rtDW.b_jBcol < 10; rtDW.b_jBcol++) {
      rtDW.ipiv[rtDW.b_jBcol] = (int8_T)(1 + rtDW.b_jBcol);
    }

    for (rtDW.loop_ub = 0; rtDW.loop_ub < 9; rtDW.loop_ub++) {
      rtDW.b_jBcol = rtDW.loop_ub * 11;
      rtDW.iy_n = 0;
      rtDW.b_kAcol = rtDW.b_jBcol;
      rtDW.smax = fabs(rtDW.b_A_data_b[rtDW.b_jBcol]);
      rtDW.c_i = 2;
      while (rtDW.c_i <= 10 - rtDW.loop_ub) {
        rtDW.b_kAcol++;
        rtDW.s = fabs(rtDW.b_A_data_b[rtDW.b_kAcol]);
        if (rtDW.s > rtDW.smax) {
          rtDW.iy_n = rtDW.c_i - 1;
          rtDW.smax = rtDW.s;
        }

        rtDW.c_i++;
      }

      if (rtDW.b_A_data_b[rtDW.b_jBcol + rtDW.iy_n] != 0.0) {
        if (rtDW.iy_n != 0) {
          rtDW.ipiv[rtDW.loop_ub] = (int8_T)((rtDW.loop_ub + rtDW.iy_n) + 1);
          rtDW.b_kAcol = rtDW.loop_ub;
          rtDW.iy_n += rtDW.loop_ub;
          for (rtDW.c_i = 0; rtDW.c_i < 10; rtDW.c_i++) {
            rtDW.smax = rtDW.b_A_data_b[rtDW.b_kAcol];
            rtDW.b_A_data_b[rtDW.b_kAcol] = rtDW.b_A_data_b[rtDW.iy_n];
            rtDW.b_A_data_b[rtDW.iy_n] = rtDW.smax;
            rtDW.b_kAcol += 10;
            rtDW.iy_n += 10;
          }
        }

        rtDW.iy_n = (rtDW.b_jBcol - rtDW.loop_ub) + 10;
        rtDW.b_kAcol = rtDW.b_jBcol + 1;
        while (rtDW.b_kAcol + 1 <= rtDW.iy_n) {
          rtDW.b_A_data_b[rtDW.b_kAcol] /= rtDW.b_A_data_b[rtDW.b_jBcol];
          rtDW.b_kAcol++;
        }
      }

      rtDW.iy_n = rtDW.b_jBcol + 11;
      rtDW.b_kAcol = rtDW.b_jBcol + 10;
      rtDW.c_i = 1;
      while (rtDW.c_i <= 9 - rtDW.loop_ub) {
        rtDW.smax = rtDW.b_A_data_b[rtDW.b_kAcol];
        if (rtDW.b_A_data_b[rtDW.b_kAcol] != 0.0) {
          rtDW.c_ix = rtDW.b_jBcol + 1;
          rtDW.d_i = (rtDW.iy_n - rtDW.loop_ub) + 9;
          rtDW.ijA = rtDW.iy_n;
          while (rtDW.ijA + 1 <= rtDW.d_i) {
            rtDW.b_A_data_b[rtDW.ijA] += rtDW.b_A_data_b[rtDW.c_ix] * -rtDW.smax;
            rtDW.c_ix++;
            rtDW.ijA++;
          }
        }

        rtDW.b_kAcol += 10;
        rtDW.iy_n += 10;
        rtDW.c_i++;
      }
    }

    for (rtDW.b_jBcol = 0; rtDW.b_jBcol < 100; rtDW.b_jBcol++) {
      rtDW.B_c[rtDW.b_jBcol] = e[rtDW.b_jBcol];
    }

    for (rtDW.loop_ub = 0; rtDW.loop_ub < 9; rtDW.loop_ub++) {
      if (rtDW.loop_ub + 1 != rtDW.ipiv[rtDW.loop_ub]) {
        rtDW.b_jBcol = rtDW.ipiv[rtDW.loop_ub] - 1;
        for (rtDW.iy_n = 0; rtDW.iy_n < 10; rtDW.iy_n++) {
          rtDW.b_kAcol = (int32_T)rtDW.B_c[10 * rtDW.iy_n + rtDW.loop_ub];
          rtDW.B_c[rtDW.loop_ub + 10 * rtDW.iy_n] = rtDW.B_c[10 * rtDW.iy_n +
            rtDW.b_jBcol];
          rtDW.B_c[rtDW.b_jBcol + 10 * rtDW.iy_n] = rtDW.b_kAcol;
        }
      }
    }

    for (rtDW.loop_ub = 0; rtDW.loop_ub < 10; rtDW.loop_ub++) {
      rtDW.b_jBcol = 10 * rtDW.loop_ub;
      for (rtDW.iy_n = 0; rtDW.iy_n < 10; rtDW.iy_n++) {
        rtDW.b_kAcol = 10 * rtDW.iy_n;
        if (rtDW.B_c[rtDW.iy_n + rtDW.b_jBcol] != 0.0) {
          rtDW.c_i = rtDW.iy_n + 1;
          while (rtDW.c_i + 1 < 11) {
            rtDW.B_c[rtDW.c_i + rtDW.b_jBcol] -= rtDW.B_c[rtDW.iy_n +
              rtDW.b_jBcol] * rtDW.b_A_data_b[rtDW.c_i + rtDW.b_kAcol];
            rtDW.c_i++;
          }
        }
      }
    }

    for (rtDW.loop_ub = 0; rtDW.loop_ub < 10; rtDW.loop_ub++) {
      rtDW.b_jBcol = 10 * rtDW.loop_ub;
      for (rtDW.iy_n = 9; rtDW.iy_n >= 0; rtDW.iy_n += -1) {
        rtDW.b_kAcol = 10 * rtDW.iy_n;
        if (rtDW.B_c[rtDW.iy_n + rtDW.b_jBcol] != 0.0) {
          rtDW.B_c[rtDW.iy_n + rtDW.b_jBcol] /= rtDW.b_A_data_b[rtDW.iy_n +
            rtDW.b_kAcol];
          rtDW.c_i = 0;
          while (rtDW.c_i + 1 <= rtDW.iy_n) {
            rtDW.B_c[rtDW.c_i + rtDW.b_jBcol] -= rtDW.B_c[rtDW.iy_n +
              rtDW.b_jBcol] * rtDW.b_A_data_b[rtDW.c_i + rtDW.b_kAcol];
            rtDW.c_i++;
          }
        }
      }
    }

    Y_sizes[0] = 10;
    Y_sizes[1] = 10;
    memcpy(&Y_data[0], &rtDW.B_c[0], 100U * sizeof(real_T));
    break;

   default:
    qrsolve(A_data, A_sizes, Y_data, Y_sizes);
    break;
  }
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::Unconstrained(const real_T Hinv[100],
  const real_T f[10], real_T x_data[], int16_T n)
{
  int16_T i;
  real_T tmp;
  int32_T i_0;
  for (i = 1; i <= n; i++) {
    tmp = 0.0;
    for (i_0 = 0; i_0 < 10; i_0++) {
      tmp += -Hinv[(10 * i_0 + i) - 1] * f[i_0];
    }

    x_data[i - 1] = tmp;
  }
}

// Function for MATLAB Function: '<S4>/empuxo '
real_T mpcqp_solver_douglas_v4ModelClass::norm(const real_T x_data[], const
  int32_T x_sizes)
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  int32_T k;
  if (x_sizes == 0) {
    y = 0.0;
  } else {
    y = 0.0;
    if (x_sizes == 1) {
      y = fabs(x_data[0]);
    } else {
      scale = 2.2250738585072014E-308;
      for (k = 1; k <= x_sizes; k++) {
        absxk = fabs(x_data[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::abs_b4(const real_T x[38], real_T y[38])
{
  int32_T k;
  for (k = 0; k < 38; k++) {
    y[k] = fabs(x[k]);
  }
}

// Function for MATLAB Function: '<S4>/empuxo '
real_T mpcqp_solver_douglas_v4ModelClass::xnrm2_c(int32_T n, const real_T
  x_data[], int32_T ix0)
{
  real_T y;
  int32_T kend;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x_data[ix0 - 1]);
    } else {
      rtDW.scale = 2.2250738585072014E-308;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        rtDW.absxk = fabs(x_data[k - 1]);
        if (rtDW.absxk > rtDW.scale) {
          rtDW.t_g = rtDW.scale / rtDW.absxk;
          y = y * rtDW.t_g * rtDW.t_g + 1.0;
          rtDW.scale = rtDW.absxk;
        } else {
          rtDW.t_g = rtDW.absxk / rtDW.scale;
          y += rtDW.t_g * rtDW.t_g;
        }
      }

      y = rtDW.scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::xgeqrf(real_T A_data[], int32_T A_sizes
  [2], real_T tau_data[], int32_T *tau_sizes)
{
  int32_T ix;
  int32_T iy;
  int32_T f;
  int32_T g;
  int32_T b_ia;
  int32_T b_ix;
  boolean_T exitg2;
  rtDW.m_j = A_sizes[0];
  rtDW.mn = A_sizes[0];
  *tau_sizes = (int8_T)rtDW.mn;
  if (A_sizes[0] != 0) {
    memset(&rtDW.work_k[0], 0, 10U * sizeof(real_T));
    rtDW.i_o = 0;
    while (rtDW.i_o + 1 <= rtDW.mn) {
      rtDW.i_i = rtDW.i_o * rtDW.m_j + rtDW.i_o;
      rtDW.mmi = rtDW.m_j - rtDW.i_o;
      if (rtDW.i_o + 1 < rtDW.m_j) {
        rtDW.b_atmp = A_data[rtDW.i_i];
        rtDW.b_c = 0.0;
        if (!(rtDW.mmi <= 0)) {
          rtDW.xnorm = xnrm2_c(rtDW.mmi - 1, A_data, rtDW.i_i + 2);
          if (rtDW.xnorm != 0.0) {
            rtDW.xnorm = rt_hypotd_snf(A_data[rtDW.i_i], rtDW.xnorm);
            if (A_data[rtDW.i_i] >= 0.0) {
              rtDW.xnorm = -rtDW.xnorm;
            }

            if (fabs(rtDW.xnorm) < 1.0020841800044864E-292) {
              rtDW.knt = 0;
              do {
                rtDW.knt++;
                rtDW.i_ip1 = rtDW.i_i + rtDW.mmi;
                for (iy = rtDW.i_i + 1; iy + 1 <= rtDW.i_ip1; iy++) {
                  A_data[iy] *= 9.9792015476736E+291;
                }

                rtDW.xnorm *= 9.9792015476736E+291;
                rtDW.b_atmp *= 9.9792015476736E+291;
              } while (!(fabs(rtDW.xnorm) >= 1.0020841800044864E-292));

              rtDW.xnorm = rt_hypotd_snf(rtDW.b_atmp, xnrm2_c(rtDW.mmi - 1,
                A_data, rtDW.i_i + 2));
              if (rtDW.b_atmp >= 0.0) {
                rtDW.xnorm = -rtDW.xnorm;
              }

              rtDW.b_c = (rtDW.xnorm - rtDW.b_atmp) / rtDW.xnorm;
              rtDW.b_atmp = 1.0 / (rtDW.b_atmp - rtDW.xnorm);
              rtDW.i_ip1 = rtDW.i_i + rtDW.mmi;
              for (iy = rtDW.i_i + 1; iy + 1 <= rtDW.i_ip1; iy++) {
                A_data[iy] *= rtDW.b_atmp;
              }

              rtDW.i_ip1 = 1;
              while (rtDW.i_ip1 <= rtDW.knt) {
                rtDW.xnorm *= 1.0020841800044864E-292;
                rtDW.i_ip1++;
              }

              rtDW.b_atmp = rtDW.xnorm;
            } else {
              rtDW.b_c = (rtDW.xnorm - A_data[rtDW.i_i]) / rtDW.xnorm;
              rtDW.b_atmp = 1.0 / (A_data[rtDW.i_i] - rtDW.xnorm);
              rtDW.knt = rtDW.i_i + rtDW.mmi;
              rtDW.i_ip1 = rtDW.i_i + 1;
              while (rtDW.i_ip1 + 1 <= rtDW.knt) {
                A_data[rtDW.i_ip1] *= rtDW.b_atmp;
                rtDW.i_ip1++;
              }

              rtDW.b_atmp = rtDW.xnorm;
            }
          }
        }

        tau_data[rtDW.i_o] = rtDW.b_c;
        A_data[rtDW.i_i] = rtDW.b_atmp;
      } else {
        tau_data[rtDW.i_o] = 0.0;
      }

      if (rtDW.i_o + 1 < 10) {
        rtDW.b_atmp = A_data[rtDW.i_i];
        A_data[rtDW.i_i] = 1.0;
        rtDW.i_ip1 = ((rtDW.i_o + 1) * rtDW.m_j + rtDW.i_o) + 1;
        if (tau_data[rtDW.i_o] != 0.0) {
          rtDW.knt = (rtDW.i_i + rtDW.mmi) - 1;
          while ((rtDW.mmi > 0) && (A_data[rtDW.knt] == 0.0)) {
            rtDW.mmi--;
            rtDW.knt--;
          }

          rtDW.knt = 9 - rtDW.i_o;
          exitg2 = false;
          while ((!exitg2) && (rtDW.knt > 0)) {
            iy = (rtDW.knt - 1) * rtDW.m_j + rtDW.i_ip1;
            f = iy;
            do {
              b_ix = 0;
              if (f <= (iy + rtDW.mmi) - 1) {
                if (A_data[f - 1] != 0.0) {
                  b_ix = 1;
                } else {
                  f++;
                }
              } else {
                rtDW.knt--;
                b_ix = 2;
              }
            } while (b_ix == 0);

            if (b_ix == 1) {
              exitg2 = true;
            }
          }
        } else {
          rtDW.mmi = 0;
          rtDW.knt = 0;
        }

        if (rtDW.mmi > 0) {
          if (rtDW.knt != 0) {
            for (iy = 1; iy <= rtDW.knt; iy++) {
              rtDW.work_k[iy - 1] = 0.0;
            }

            iy = 0;
            f = (rtDW.knt - 1) * rtDW.m_j + rtDW.i_ip1;
            b_ix = rtDW.i_ip1;
            while ((rtDW.m_j > 0) && (b_ix <= f)) {
              ix = rtDW.i_i;
              rtDW.b_c = 0.0;
              g = (b_ix + rtDW.mmi) - 1;
              for (b_ia = b_ix; b_ia <= g; b_ia++) {
                rtDW.b_c += A_data[b_ia - 1] * A_data[ix];
                ix++;
              }

              rtDW.work_k[iy] += rtDW.b_c;
              iy++;
              b_ix += rtDW.m_j;
            }
          }

          if (!(-tau_data[rtDW.i_o] == 0.0)) {
            rtDW.i_ip1--;
            iy = 0;
            for (f = 1; f <= rtDW.knt; f++) {
              if (rtDW.work_k[iy] != 0.0) {
                rtDW.b_c = rtDW.work_k[iy] * -tau_data[rtDW.i_o];
                b_ix = rtDW.i_i;
                ix = rtDW.mmi + rtDW.i_ip1;
                for (g = rtDW.i_ip1; g + 1 <= ix; g++) {
                  A_data[g] += A_data[b_ix] * rtDW.b_c;
                  b_ix++;
                }
              }

              iy++;
              rtDW.i_ip1 += rtDW.m_j;
            }
          }
        }

        A_data[rtDW.i_i] = rtDW.b_atmp;
      }

      rtDW.i_o++;
    }
  }
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::qr(const real_T A_data[], const int32_T
  A_sizes[2], real_T Q_data[], int32_T Q_sizes[2], real_T R_data[], int32_T
  R_sizes[2])
{
  boolean_T exitg2;
  int8_T b_idx_0;
  rtDW.m_f = A_sizes[0];
  b_idx_0 = (int8_T)A_sizes[0];
  Q_sizes[0] = (int8_T)A_sizes[0];
  Q_sizes[1] = (int8_T)A_sizes[0];
  R_sizes[0] = A_sizes[0];
  R_sizes[1] = A_sizes[1];
  rtDW.b_A_sizes[0] = A_sizes[0];
  rtDW.b_A_sizes[1] = 10;
  rtDW.itau = A_sizes[0] * A_sizes[1];
  for (rtDW.e_i = 0; rtDW.e_i < rtDW.itau; rtDW.e_i++) {
    rtDW.b_A_data[rtDW.e_i] = A_data[rtDW.e_i];
  }

  xgeqrf(rtDW.b_A_data, rtDW.b_A_sizes, rtDW.tau_data, &rtDW.itau);
  rtDW.itau = 0;
  while (rtDW.itau + 1 <= rtDW.m_f) {
    rtDW.e_i = 0;
    while (rtDW.e_i + 1 <= rtDW.itau + 1) {
      R_data[rtDW.e_i + R_sizes[0] * rtDW.itau] = rtDW.b_A_data[rtDW.b_A_sizes[0]
        * rtDW.itau + rtDW.e_i];
      rtDW.e_i++;
    }

    rtDW.e_i = rtDW.itau;
    while (rtDW.e_i + 2 <= rtDW.m_f) {
      R_data[(rtDW.e_i + R_sizes[0] * rtDW.itau) + 1] = 0.0;
      rtDW.e_i++;
    }

    rtDW.itau++;
  }

  rtDW.itau = A_sizes[0];
  while (rtDW.itau + 1 < 11) {
    rtDW.e_i = 0;
    while (rtDW.e_i + 1 <= rtDW.m_f) {
      R_data[rtDW.e_i + R_sizes[0] * rtDW.itau] = rtDW.b_A_data[rtDW.b_A_sizes[0]
        * rtDW.itau + rtDW.e_i];
      rtDW.e_i++;
    }

    rtDW.itau++;
  }

  if (!(A_sizes[0] < 1)) {
    rtDW.itau = A_sizes[0];
    while (rtDW.itau <= rtDW.m_f - 1) {
      rtDW.e_i = rtDW.itau * rtDW.m_f;
      rtDW.iaii = 0;
      while (rtDW.iaii <= rtDW.m_f - 1) {
        rtDW.b_A_data[rtDW.e_i + rtDW.iaii] = 0.0;
        rtDW.iaii++;
      }

      rtDW.b_A_data[rtDW.e_i + rtDW.itau] = 1.0;
      rtDW.itau++;
    }

    rtDW.itau = A_sizes[0] - 1;
    memset(&rtDW.work[0], 0, 10U * sizeof(real_T));
    rtDW.e_i = A_sizes[0];
    while (rtDW.e_i >= 1) {
      rtDW.iaii = ((rtDW.e_i - 1) * rtDW.m_f + rtDW.e_i) - 1;
      if (rtDW.e_i < rtDW.m_f) {
        rtDW.b_A_data[rtDW.iaii] = 1.0;
        rtDW.lastv = rtDW.m_f - rtDW.e_i;
        rtDW.jA = (rtDW.iaii + rtDW.m_f) + 1;
        if (rtDW.tau_data[rtDW.itau] != 0.0) {
          rtDW.lastc = rtDW.iaii + rtDW.lastv;
          while ((rtDW.lastv + 1 > 0) && (rtDW.b_A_data[rtDW.lastc] == 0.0)) {
            rtDW.lastv--;
            rtDW.lastc--;
          }

          rtDW.lastc = rtDW.m_f - rtDW.e_i;
          exitg2 = false;
          while ((!exitg2) && (rtDW.lastc > 0)) {
            rtDW.iy_j = (rtDW.lastc - 1) * rtDW.m_f + rtDW.jA;
            rtDW.d = rtDW.iy_j;
            do {
              rtDW.b_ix = 0;
              if (rtDW.d <= rtDW.iy_j + rtDW.lastv) {
                if (rtDW.b_A_data[rtDW.d - 1] != 0.0) {
                  rtDW.b_ix = 1;
                } else {
                  rtDW.d++;
                }
              } else {
                rtDW.lastc--;
                rtDW.b_ix = 2;
              }
            } while (rtDW.b_ix == 0);

            if (rtDW.b_ix == 1) {
              exitg2 = true;
            }
          }
        } else {
          rtDW.lastv = -1;
          rtDW.lastc = 0;
        }

        if (rtDW.lastv + 1 > 0) {
          if (rtDW.lastc != 0) {
            rtDW.iy_j = 1;
            while (rtDW.iy_j <= rtDW.lastc) {
              rtDW.work[rtDW.iy_j - 1] = 0.0;
              rtDW.iy_j++;
            }

            rtDW.iy_j = 0;
            rtDW.d = (rtDW.lastc - 1) * rtDW.m_f + rtDW.jA;
            rtDW.b_ix = rtDW.jA;
            while (rtDW.b_ix <= rtDW.d) {
              rtDW.ix_a = rtDW.iaii;
              rtDW.c_c = 0.0;
              rtDW.e = rtDW.b_ix + rtDW.lastv;
              rtDW.b_ia = rtDW.b_ix;
              while (rtDW.b_ia <= rtDW.e) {
                rtDW.c_c += rtDW.b_A_data[rtDW.b_ia - 1] *
                  rtDW.b_A_data[rtDW.ix_a];
                rtDW.ix_a++;
                rtDW.b_ia++;
              }

              rtDW.work[rtDW.iy_j] += rtDW.c_c;
              rtDW.iy_j++;
              rtDW.b_ix += rtDW.m_f;
            }
          }

          if (!(-rtDW.tau_data[rtDW.itau] == 0.0)) {
            rtDW.jA--;
            rtDW.iy_j = 0;
            rtDW.d = 1;
            while (rtDW.d <= rtDW.lastc) {
              if (rtDW.work[rtDW.iy_j] != 0.0) {
                rtDW.c_c = rtDW.work[rtDW.iy_j] * -rtDW.tau_data[rtDW.itau];
                rtDW.b_ix = rtDW.iaii;
                rtDW.ix_a = rtDW.lastv + rtDW.jA;
                rtDW.e = rtDW.jA;
                while (rtDW.e + 1 <= rtDW.ix_a + 1) {
                  rtDW.b_A_data[rtDW.e] += rtDW.b_A_data[rtDW.b_ix] * rtDW.c_c;
                  rtDW.b_ix++;
                  rtDW.e++;
                }
              }

              rtDW.iy_j++;
              rtDW.jA += rtDW.m_f;
              rtDW.d++;
            }
          }
        }

        rtDW.lastv = ((rtDW.iaii + rtDW.m_f) - rtDW.e_i) + 1;
        rtDW.lastc = rtDW.iaii + 1;
        while (rtDW.lastc + 1 <= rtDW.lastv) {
          rtDW.b_A_data[rtDW.lastc] *= -rtDW.tau_data[rtDW.itau];
          rtDW.lastc++;
        }
      }

      rtDW.b_A_data[rtDW.iaii] = 1.0 - rtDW.tau_data[rtDW.itau];
      rtDW.lastv = 1;
      while (rtDW.lastv <= rtDW.e_i - 1) {
        rtDW.b_A_data[rtDW.iaii - rtDW.lastv] = 0.0;
        rtDW.lastv++;
      }

      rtDW.itau--;
      rtDW.e_i--;
    }
  }

  rtDW.itau = 0;
  while (rtDW.itau + 1 <= rtDW.m_f) {
    rtDW.e_i = 0;
    while (rtDW.e_i + 1 <= rtDW.m_f) {
      Q_data[rtDW.e_i + b_idx_0 * rtDW.itau] = rtDW.b_A_data[rtDW.b_A_sizes[0] *
        rtDW.itau + rtDW.e_i];
      rtDW.e_i++;
    }

    rtDW.itau++;
  }
}

// Function for MATLAB Function: '<S4>/empuxo '
real_T mpcqp_solver_douglas_v4ModelClass::KWIKfactor(const real_T b_Ac[380],
  const int16_T iC[38], int16_T nA, const real_T Linv_data[], const int32_T
  Linv_sizes[2], real_T RLinv_data[], int32_T RLinv_sizes[2], real_T D_data[],
  int32_T D_sizes[2], real_T H_data[], int32_T H_sizes[2], int16_T n)
{
  real_T Status;
  int16_T i;
  int16_T c_i;
  int16_T b_k;
  int16_T f_i;
  int16_T d_k;
  int8_T Linv_idx_0;
  rtDW.TL_sizes_idx_0 = Linv_sizes[0];
  Status = 1.0;
  rtDW.m_h = RLinv_sizes[0];
  for (rtDW.br_b = 0; rtDW.br_b < 10; rtDW.br_b++) {
    for (rtDW.b_b_sizes = 0; rtDW.b_b_sizes < rtDW.m_h; rtDW.b_b_sizes++) {
      RLinv_data[rtDW.b_b_sizes + RLinv_sizes[0] * rtDW.br_b] = 0.0;
    }
  }

  for (i = 1; i <= nA; i++) {
    Linv_idx_0 = (int8_T)Linv_sizes[0];
    rtDW.m_h = Linv_sizes[0];
    rtDW.ar_d = Linv_idx_0;
    rtDW.b_b_sizes = Linv_idx_0;
    for (rtDW.br_b = 0; rtDW.br_b < rtDW.ar_d; rtDW.br_b++) {
      rtDW.b_b_data[rtDW.br_b] = 0.0;
    }

    if (Linv_sizes[0] != 0) {
      rtDW.br_b = 0;
      while ((rtDW.m_h > 0) && (rtDW.br_b <= 0)) {
        rtDW.br_b = 1;
        while (rtDW.br_b <= rtDW.m_h) {
          rtDW.b_b_data[rtDW.br_b - 1] = 0.0;
          rtDW.br_b++;
        }

        rtDW.br_b = rtDW.m_h;
      }

      rtDW.br_b = 0;
      rtDW.ar_d = 0;
      while ((rtDW.m_h > 0) && (rtDW.ar_d <= 0)) {
        rtDW.ar_d = -1;
        rtDW.ib_b = rtDW.br_b;
        while (rtDW.ib_b + 1 <= rtDW.br_b + 10) {
          if (b_Ac[(iC[i - 1] + 38 * rtDW.ib_b) - 1] != 0.0) {
            rtDW.ia_e = rtDW.ar_d;
            rtDW.b_ic_j = 0;
            while (rtDW.b_ic_j + 1 <= rtDW.m_h) {
              rtDW.ia_e++;
              rtDW.b_b_data[rtDW.b_ic_j] += b_Ac[(iC[i - 1] + 38 * rtDW.ib_b) -
                1] * Linv_data[rtDW.ia_e];
              rtDW.b_ic_j++;
            }
          }

          rtDW.ar_d += rtDW.m_h;
          rtDW.ib_b++;
        }

        rtDW.br_b += 10;
        rtDW.ar_d = rtDW.m_h;
      }
    }

    for (rtDW.br_b = 0; rtDW.br_b < rtDW.b_b_sizes; rtDW.br_b++) {
      RLinv_data[rtDW.br_b + RLinv_sizes[0] * (i - 1)] = rtDW.b_b_data[rtDW.br_b];
    }
  }

  qr(RLinv_data, RLinv_sizes, rtDW.QQ_data, rtDW.QQ_sizes, rtDW.RR_data,
     rtDW.RR_sizes);
  i = 1;
  do {
    rtDW.m_h = 0;
    if (i <= nA) {
      if (fabs(rtDW.RR_data[((i - 1) * rtDW.RR_sizes[0] + i) - 1]) < 1.0E-12) {
        Status = -2.0;
        rtDW.m_h = 1;
      } else {
        i++;
      }
    } else {
      for (c_i = 1; c_i <= n; c_i++) {
        for (f_i = 1; f_i <= n; f_i++) {
          rtDW.br_b = Linv_sizes[0] - 1;
          rtDW.d0 = 0.0;
          for (rtDW.b_b_sizes = 0; rtDW.b_b_sizes <= rtDW.br_b; rtDW.b_b_sizes++)
          {
            rtDW.d0 += Linv_data[(c_i - 1) * Linv_sizes[0] + rtDW.b_b_sizes] *
              rtDW.QQ_data[(f_i - 1) * rtDW.QQ_sizes[0] + rtDW.b_b_sizes];
          }

          rtDW.TL_data[(c_i + rtDW.TL_sizes_idx_0 * (f_i - 1)) - 1] = rtDW.d0;
        }
      }

      rtDW.m_h = RLinv_sizes[0];
      for (rtDW.br_b = 0; rtDW.br_b < 10; rtDW.br_b++) {
        for (rtDW.b_b_sizes = 0; rtDW.b_b_sizes < rtDW.m_h; rtDW.b_b_sizes++) {
          RLinv_data[rtDW.b_b_sizes + RLinv_sizes[0] * rtDW.br_b] = 0.0;
        }
      }

      for (c_i = nA; c_i > 0; c_i--) {
        RLinv_data[(c_i + RLinv_sizes[0] * (c_i - 1)) - 1] = 1.0;
        for (f_i = c_i; f_i <= nA; f_i++) {
          RLinv_data[(c_i + RLinv_sizes[0] * (f_i - 1)) - 1] /= rtDW.RR_data
            [((c_i - 1) * rtDW.RR_sizes[0] + c_i) - 1];
        }

        if (c_i > 1) {
          f_i = (int16_T)(c_i - 1);
          for (d_k = 1; d_k <= f_i; d_k++) {
            for (b_k = c_i; b_k <= nA; b_k++) {
              RLinv_data[(d_k + RLinv_sizes[0] * (b_k - 1)) - 1] -=
                rtDW.RR_data[((c_i - 1) * rtDW.RR_sizes[0] + d_k) - 1] *
                RLinv_data[((b_k - 1) * RLinv_sizes[0] + c_i) - 1];
            }
          }
        }
      }

      for (c_i = 1; c_i <= n; c_i++) {
        for (f_i = c_i; f_i <= n; f_i++) {
          H_data[(c_i + H_sizes[0] * (f_i - 1)) - 1] = 0.0;
          for (d_k = (int16_T)(nA + 1); d_k <= n; d_k++) {
            H_data[(c_i + H_sizes[0] * (f_i - 1)) - 1] -= rtDW.TL_data[((d_k - 1)
              * rtDW.TL_sizes_idx_0 + c_i) - 1] * rtDW.TL_data[((d_k - 1) *
              rtDW.TL_sizes_idx_0 + f_i) - 1];
          }

          H_data[(f_i + H_sizes[0] * (c_i - 1)) - 1] = H_data[((f_i - 1) *
            H_sizes[0] + c_i) - 1];
        }
      }

      for (c_i = 1; c_i <= nA; c_i++) {
        for (f_i = 1; f_i <= n; f_i++) {
          D_data[(f_i + D_sizes[0] * (c_i - 1)) - 1] = 0.0;
          for (d_k = c_i; d_k <= nA; d_k++) {
            D_data[(f_i + D_sizes[0] * (c_i - 1)) - 1] += rtDW.TL_data[((d_k - 1)
              * rtDW.TL_sizes_idx_0 + f_i) - 1] * RLinv_data[((d_k - 1) *
              RLinv_sizes[0] + c_i) - 1];
          }
        }
      }

      rtDW.m_h = 1;
    }
  } while (rtDW.m_h == 0);

  return Status;
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::DropConstraint(int16_T kDrop, int16_T
  iA[38], int16_T *nA, int16_T iC[38])
{
  int16_T i;
  int32_T tmp;
  iA[iC[kDrop - 1] - 1] = 0;
  if (kDrop < *nA) {
    tmp = *nA - 1;
    if (tmp < -32768) {
      tmp = -32768;
    }

    for (i = kDrop; i <= (int16_T)tmp; i++) {
      iC[i - 1] = iC[i];
    }
  }

  iC[*nA - 1] = 0;
  tmp = *nA - 1;
  if (tmp < -32768) {
    tmp = -32768;
  }

  *nA = (int16_T)tmp;
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::abs_b(const real_T x[10], real_T y[10])
{
  int32_T k;
  for (k = 0; k < 10; k++) {
    y[k] = fabs(x[k]);
  }
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::qpkwik(const real_T Linv_data[], const
  int32_T Linv_sizes[2], const real_T Hinv[100], const real_T f[10], const
  real_T b_Ac[380], const real_T b[38], int16_T n, real_T x_data[], int32_T
  *x_sizes, real_T lambda[38], real_T *status, int16_T iA[38])
{
  boolean_T cTolComputed;
  int16_T nA;
  int16_T kDrop;
  int16_T kNext;
  boolean_T isT1Inf;
  boolean_T tempOK;
  int16_T iSave;
  boolean_T exitg3;
  boolean_T guard1;
  int8_T a_idx_0;
  *status = 1.0;
  memset(&iA[0], 0, 38U * sizeof(int16_T));
  memset(&lambda[0], 0, 38U * sizeof(real_T));
  rtDW.ar_o = n;
  for (rtDW.br_l = 0; rtDW.br_l < rtDW.ar_o; rtDW.br_l++) {
    rtDW.r_data[rtDW.br_l] = 0.0;
  }

  rtDW.rMin = 0.0;
  rtDW.RLinv_sizes[0] = Linv_sizes[0];
  rtDW.D_sizes[0] = Linv_sizes[0];
  rtDW.H_sizes[0] = Linv_sizes[0];
  rtDW.RLinv_sizes[1] = Linv_sizes[1];
  rtDW.D_sizes[1] = Linv_sizes[1];
  rtDW.H_sizes[1] = Linv_sizes[1];
  cTolComputed = false;
  for (rtDW.i_l = 0; rtDW.i_l < 38; rtDW.i_l++) {
    rtDW.cTol[rtDW.i_l] = 1.0;
    rtDW.iC[rtDW.i_l] = 0;
  }

  nA = 0;
  *x_sizes = n;
  rtDW.ar_o = n;
  for (rtDW.br_l = 0; rtDW.br_l < rtDW.ar_o; rtDW.br_l++) {
    x_data[rtDW.br_l] = 0.0;
  }

  Unconstrained(Hinv, f, x_data, n);
  rtDW.Xnorm0 = norm(x_data, *x_sizes);
  do {
    rtDW.i_l = 0;
    if (*status <= 10.0) {
      rtDW.cMin = -1.0E-6;
      kNext = 0;
      for (kDrop = 0; kDrop < 38; kDrop++) {
        if (!cTolComputed) {
          rtDW.ixstart = kDrop + 1;
          for (rtDW.br_l = 0; rtDW.br_l < *x_sizes; rtDW.br_l++) {
            rtDW.AcRow[rtDW.br_l] = x_data[rtDW.br_l];
          }

          for (rtDW.br_l = 0; rtDW.br_l < 10; rtDW.br_l++) {
            rtDW.D_data_c[rtDW.br_l] = b_Ac[(38 * rtDW.br_l + rtDW.ixstart) - 1]
              * rtDW.AcRow[rtDW.br_l];
          }

          abs_b(rtDW.D_data_c, rtDW.AcRow);
          rtDW.ixstart = 1;
          rtDW.zTa = rtDW.AcRow[0];
          if (rtIsNaN(rtDW.AcRow[0])) {
            rtDW.m = 2;
            guard1 = false;
            while ((!guard1) && (rtDW.m < 11)) {
              rtDW.ixstart = rtDW.m;
              if (!rtIsNaN(rtDW.AcRow[rtDW.m - 1])) {
                rtDW.zTa = rtDW.AcRow[rtDW.m - 1];
                guard1 = true;
              } else {
                rtDW.m++;
              }
            }
          }

          if (rtDW.ixstart < 10) {
            while (rtDW.ixstart + 1 < 11) {
              if (rtDW.AcRow[rtDW.ixstart] > rtDW.zTa) {
                rtDW.zTa = rtDW.AcRow[rtDW.ixstart];
              }

              rtDW.ixstart++;
            }
          }

          if (!((rtDW.cTol[kDrop] >= rtDW.zTa) || rtIsNaN(rtDW.zTa))) {
            rtDW.cTol[kDrop] = rtDW.zTa;
          }
        }

        if (iA[kDrop] == 0) {
          rtDW.ixstart = kDrop + 1;
          rtDW.zTa = 0.0;
          for (rtDW.br_l = 0; rtDW.br_l < 10; rtDW.br_l++) {
            rtDW.zTa += b_Ac[(38 * rtDW.br_l + rtDW.ixstart) - 1] *
              x_data[rtDW.br_l];
          }

          rtDW.zTa = (rtDW.zTa - b[kDrop]) / rtDW.cTol[kDrop];
          if (rtDW.zTa < rtDW.cMin) {
            rtDW.cMin = rtDW.zTa;
            kNext = (int16_T)(kDrop + 1);
          }
        }
      }

      cTolComputed = true;
      if (kNext <= 0) {
        rtDW.i_l = 1;
      } else {
        do {
          rtDW.ixstart = 0;
          if ((kNext > 0) && (*status <= 10.0)) {
            guard1 = false;
            isT1Inf = false;
            if (nA == 0) {
              rtDW.z_sizes = 10;
              for (rtDW.br_l = 0; rtDW.br_l < 10; rtDW.br_l++) {
                rtDW.D_data_c[rtDW.br_l] = 0.0;
                for (rtDW.m = 0; rtDW.m < 10; rtDW.m++) {
                  rtDW.D_data_c[rtDW.br_l] += b_Ac[(38 * rtDW.m + kNext) - 1] *
                    Hinv[10 * rtDW.m + rtDW.br_l];
                }

                rtDW.z_data[rtDW.br_l] = rtDW.D_data_c[rtDW.br_l];
              }

              isT1Inf = true;
            } else {
              rtDW.cMin = KWIKfactor(b_Ac, rtDW.iC, nA, Linv_data, Linv_sizes,
                rtDW.RLinv_data, rtDW.RLinv_sizes, rtDW.D_data, rtDW.D_sizes,
                rtDW.H_data, rtDW.H_sizes, n);
              if (rtDW.cMin <= 0.0) {
                *status = -2.0;
                rtDW.ixstart = 1;
              } else {
                rtDW.m = rtDW.H_sizes[0];
                rtDW.ar_o = rtDW.H_sizes[0] * rtDW.H_sizes[1];
                for (rtDW.br_l = 0; rtDW.br_l < rtDW.ar_o; rtDW.br_l++) {
                  rtDW.a_data_m[rtDW.br_l] = -rtDW.H_data[rtDW.br_l];
                }

                a_idx_0 = (int8_T)rtDW.H_sizes[0];
                rtDW.ar_o = a_idx_0;
                rtDW.z_sizes = a_idx_0;
                for (rtDW.br_l = 0; rtDW.br_l < rtDW.ar_o; rtDW.br_l++) {
                  rtDW.z_data[rtDW.br_l] = 0.0;
                }

                if (rtDW.H_sizes[0] != 0) {
                  rtDW.br_l = 0;
                  while ((rtDW.m > 0) && (rtDW.br_l <= 0)) {
                    rtDW.br_l = 1;
                    while (rtDW.br_l <= rtDW.m) {
                      rtDW.z_data[rtDW.br_l - 1] = 0.0;
                      rtDW.br_l++;
                    }

                    rtDW.br_l = rtDW.m;
                  }

                  rtDW.br_l = 0;
                  rtDW.ar_o = 0;
                  while ((rtDW.m > 0) && (rtDW.ar_o <= 0)) {
                    rtDW.ar_o = -1;
                    rtDW.ib_n = rtDW.br_l;
                    while (rtDW.ib_n + 1 <= rtDW.br_l + 10) {
                      if (b_Ac[(38 * rtDW.ib_n + kNext) - 1] != 0.0) {
                        rtDW.ia_b = rtDW.ar_o;
                        rtDW.b_ic_b = 0;
                        while (rtDW.b_ic_b + 1 <= rtDW.m) {
                          rtDW.ia_b++;
                          rtDW.z_data[rtDW.b_ic_b] += b_Ac[(38 * rtDW.ib_n +
                            kNext) - 1] * rtDW.a_data_m[rtDW.ia_b];
                          rtDW.b_ic_b++;
                        }
                      }

                      rtDW.ar_o += rtDW.m;
                      rtDW.ib_n++;
                    }

                    rtDW.br_l += 10;
                    rtDW.ar_o = rtDW.m;
                  }
                }

                for (kDrop = 1; kDrop <= nA; kDrop++) {
                  rtDW.ar_o = rtDW.D_sizes[0];
                  for (rtDW.br_l = 0; rtDW.br_l < rtDW.ar_o; rtDW.br_l++) {
                    rtDW.D_data_c[rtDW.br_l] = rtDW.D_data[(kDrop - 1) *
                      rtDW.D_sizes[0] + rtDW.br_l];
                  }

                  rtDW.zTa = 0.0;
                  for (rtDW.br_l = 0; rtDW.br_l < 10; rtDW.br_l++) {
                    rtDW.zTa += b_Ac[(38 * rtDW.br_l + kNext) - 1] *
                      rtDW.D_data_c[rtDW.br_l];
                  }

                  rtDW.r_data[kDrop - 1] = rtDW.zTa;
                }

                isT1Inf = true;
              }
            }

            if (isT1Inf) {
              kDrop = 0;
              rtDW.cMin = 0.0;
              tempOK = true;
              if (nA > 0) {
                iSave = 1;
                exitg3 = false;
                while ((!exitg3) && (iSave <= nA)) {
                  if (rtDW.r_data[iSave - 1] >= 1.0E-12) {
                    tempOK = false;
                    exitg3 = true;
                  } else {
                    iSave++;
                  }
                }
              }

              if (!((nA == 0) || tempOK)) {
                for (iSave = 1; iSave <= nA; iSave++) {
                  if (rtDW.r_data[iSave - 1] > 1.0E-12) {
                    rtDW.zTa = lambda[rtDW.iC[iSave - 1] - 1] /
                      rtDW.r_data[iSave - 1];
                    if ((kDrop == 0) || (rtDW.zTa < rtDW.rMin)) {
                      rtDW.rMin = rtDW.zTa;
                      kDrop = iSave;
                    }
                  }
                }

                if (kDrop > 0) {
                  rtDW.cMin = rtDW.rMin;
                  isT1Inf = false;
                }
              }

              for (rtDW.br_l = 0; rtDW.br_l < rtDW.z_sizes; rtDW.br_l++) {
                rtDW.D_data_c[rtDW.br_l] = rtDW.z_data[rtDW.br_l];
              }

              rtDW.zTa = 0.0;
              for (rtDW.br_l = 0; rtDW.br_l < 10; rtDW.br_l++) {
                rtDW.zTa += b_Ac[(38 * rtDW.br_l + kNext) - 1] *
                  rtDW.D_data_c[rtDW.br_l];
              }

              if (rtDW.zTa <= 0.0) {
                rtDW.zTa = 0.0;
                tempOK = true;
              } else {
                rtDW.t = 0.0;
                for (rtDW.br_l = 0; rtDW.br_l < 10; rtDW.br_l++) {
                  rtDW.t += b_Ac[(38 * rtDW.br_l + kNext) - 1] *
                    x_data[rtDW.br_l];
                }

                rtDW.zTa = (b[kNext - 1] - rtDW.t) / rtDW.zTa;
                tempOK = false;
              }

              if (isT1Inf && tempOK) {
                *status = -1.0;
                rtDW.ixstart = 1;
              } else {
                if (tempOK) {
                  rtDW.t = rtDW.cMin;
                } else if (isT1Inf) {
                  rtDW.t = rtDW.zTa;
                } else if ((rtDW.cMin <= rtDW.zTa) || rtIsNaN(rtDW.zTa)) {
                  rtDW.t = rtDW.cMin;
                } else {
                  rtDW.t = rtDW.zTa;
                }

                for (iSave = 1; iSave <= nA; iSave++) {
                  lambda[rtDW.iC[iSave - 1] - 1] -= rtDW.r_data[iSave - 1] *
                    rtDW.t;
                  if (lambda[rtDW.iC[iSave - 1] - 1] < 0.0) {
                    lambda[rtDW.iC[iSave - 1] - 1] = 0.0;
                  }
                }

                lambda[kNext - 1] += rtDW.t;
                if (rtDW.t == rtDW.cMin) {
                  DropConstraint(kDrop, iA, &nA, rtDW.iC);
                }

                if (!tempOK) {
                  for (rtDW.br_l = 0; rtDW.br_l < *x_sizes; rtDW.br_l++) {
                    x_data[rtDW.br_l] += rtDW.t * rtDW.z_data[rtDW.br_l];
                  }

                  if (rtDW.t == rtDW.zTa) {
                    if (nA == n) {
                      *status = -1.0;
                      rtDW.ixstart = 1;
                    } else {
                      rtDW.br_l = nA + 1;
                      if (rtDW.br_l > 32767) {
                        rtDW.br_l = 32767;
                      }

                      nA = (int16_T)rtDW.br_l;
                      rtDW.iC[(int16_T)rtDW.br_l - 1] = kNext;
                      kDrop = (int16_T)rtDW.br_l;
                      while ((kDrop > 1) && (!(rtDW.iC[kDrop - 1] >
                               rtDW.iC[kDrop - 2]))) {
                        iSave = rtDW.iC[kDrop - 1];
                        rtDW.iC[kDrop - 1] = rtDW.iC[kDrop - 2];
                        rtDW.iC[kDrop - 2] = iSave;
                        kDrop--;
                      }

                      iA[kNext - 1] = 1;
                      kNext = 0;
                      guard1 = true;
                    }
                  } else {
                    guard1 = true;
                  }
                } else {
                  guard1 = true;
                }
              }
            }

            if (guard1) {
              (*status)++;
            }
          } else {
            rtDW.cMin = norm(x_data, *x_sizes);
            if (fabs(rtDW.cMin - rtDW.Xnorm0) > 0.001) {
              rtDW.Xnorm0 = rtDW.cMin;
              abs_b4(b, rtDW.varargin_1);
              for (rtDW.ixstart = 0; rtDW.ixstart < 38; rtDW.ixstart++) {
                if (rtDW.varargin_1[rtDW.ixstart] >= 1.0) {
                  rtDW.cTol[rtDW.ixstart] = rtDW.varargin_1[rtDW.ixstart];
                } else {
                  rtDW.cTol[rtDW.ixstart] = 1.0;
                }
              }

              cTolComputed = false;
            }

            rtDW.ixstart = 2;
          }
        } while (rtDW.ixstart == 0);

        if (rtDW.ixstart == 1) {
          rtDW.i_l = 1;
        }
      }
    } else {
      *status = 0.0;
      rtDW.i_l = 1;
    }
  } while (rtDW.i_l == 0);
}

// Function for MATLAB Function: '<S4>/empuxo '
void mpcqp_solver_douglas_v4ModelClass::mpcqpsolver(const real_T Linv_data[],
  const int32_T Linv_sizes[2], const real_T f[10], const real_T A[380], const
  real_T b[38], real_T x_data[], int32_T *x_sizes, real_T *status, boolean_T iA
  [38])
{
  rtDW.i = Linv_sizes[0];
  rtDW.ar = Linv_sizes[0];
  for (rtDW.br = 0; rtDW.br < rtDW.ar; rtDW.br++) {
    for (rtDW.b_cr = 0; rtDW.b_cr < 10; rtDW.b_cr++) {
      rtDW.a_data[rtDW.b_cr + 10 * rtDW.br] = Linv_data[Linv_sizes[0] *
        rtDW.b_cr + rtDW.br];
    }
  }

  if (Linv_sizes[0] == 1) {
    for (rtDW.br = 0; rtDW.br < 10; rtDW.br++) {
      for (rtDW.b_cr = 0; rtDW.b_cr < 10; rtDW.b_cr++) {
        rtDW.Hinv[rtDW.br + 10 * rtDW.b_cr] = 0.0;
        for (rtDW.ar = 0; rtDW.ar < rtDW.i; rtDW.ar++) {
          rtDW.Hinv[rtDW.br + 10 * rtDW.b_cr] += rtDW.a_data[10 * rtDW.ar +
            rtDW.br] * Linv_data[Linv_sizes[0] * rtDW.b_cr + rtDW.ar];
        }
      }
    }
  } else {
    memset(&rtDW.Hinv[0], 0, 100U * sizeof(real_T));
    for (rtDW.br = 0; rtDW.br <= 91; rtDW.br += 10) {
      rtDW.b_cr = rtDW.br;
      while (rtDW.b_cr + 1 <= rtDW.br + 10) {
        rtDW.Hinv[rtDW.b_cr] = 0.0;
        rtDW.b_cr++;
      }
    }

    rtDW.br = 0;
    for (rtDW.b_cr = 0; rtDW.b_cr <= 91; rtDW.b_cr += 10) {
      rtDW.ar = -1;
      rtDW.c_d = rtDW.br + rtDW.i;
      rtDW.ib = rtDW.br;
      while (rtDW.ib + 1 <= rtDW.c_d) {
        if (Linv_data[rtDW.ib] != 0.0) {
          rtDW.ia_d = rtDW.ar;
          rtDW.b_ic = rtDW.b_cr;
          while (rtDW.b_ic + 1 <= rtDW.b_cr + 10) {
            rtDW.ia_d++;
            rtDW.Hinv[rtDW.b_ic] += Linv_data[rtDW.ib] * rtDW.a_data[rtDW.ia_d];
            rtDW.b_ic++;
          }
        }

        rtDW.ar += 10;
        rtDW.ib++;
      }

      rtDW.br += rtDW.i;
    }
  }

  qpkwik(Linv_data, Linv_sizes, rtDW.Hinv, f, A, b, (int16_T)Linv_sizes[0],
         x_data, x_sizes, rtDW.lam, status, rtDW.iA1);
  for (rtDW.i = 0; rtDW.i < 38; rtDW.i++) {
    iA[rtDW.i] = (rtDW.iA1[rtDW.i] != 0);
  }
}

// Model step function
void mpcqp_solver_douglas_v4ModelClass::step()
{
  boolean_T exitg1;

  // MATLAB Function: '<S4>/empuxo ' incorporates:
  //   Inport: '<Root>/x'
  //   Inport: '<Root>/xp'
  //   Inport: '<Root>/xr'
  //   UnitDelay: '<S4>/Unit Delay'
  memcpy(&rtDW.b_b0[0], &rtConstP.empuxo_b0[0], 38U * sizeof(real_T));

  // coder.extrinsic('quadprog');
  // MATLAB Function 'controle/altitude_mpc/empuxo ': '<S9>:1'
  // Estado anterior - Xf - X Feedback
  // '<S9>:1:7' z = q(3);
  //  altura z
  // '<S9>:1:8' zr = qr(3);
  //  set point de altura
  // '<S9>:1:10' zd = qd(3);
  //  derivada da altura zd
  // '<S9>:1:12' zda = old(1);
  // '<S9>:1:13' za = old(2);
  //  estado anterior
  // '<S9>:1:14' ua = old(3);
  //  controle anterior
  // ua = uold; % Feedback do U real aplicado
  // '<S9>:1:17' Xf = [zd-zda z-za z]';
  // '<S9>:1:19' rw = 0.001;
  // sem peso para a atuacao de controle
  // '<S9>:1:21' R_bar = rw*eye(Nc);
  // restrições relacionadas ao estado inicial
  // '<S9>:1:24' b0(1,1) = ua+delta_Umin;
  rtDW.b_b0[0] = rtDW.UnitDelay_DSTATE_o[2] + -4.0;

  // '<S9>:1:25' b0(2,1) = -ua-delta_Umax;
  rtDW.b_b0[1] = -rtDW.UnitDelay_DSTATE_o[2] - 8.0;

  //  b0(2*Nc+1,1) = Umin-ua;
  //  b0(2*Nc+2,1) = -Umax+ua;
  //  b0
  // criação das matrizes da funcao custo
  // '<S9>:1:31' Hqp = double(Phi_Phi+R_bar);
  // '<S9>:1:32' Fqp = double(Phi_F*Xf-Phi_R*zr);
  // Solucao usando mpcqpsolver
  // '<S9>:1:35' [L, p] = chol(Hqp,'lower');
  eye(10, rtDW.tmp_data, rtDW.Linv_sizes);
  for (rtDW.b_j = 0; rtDW.b_j < 100; rtDW.b_j++) {
    rtDW.A_data[rtDW.b_j] = 0.001 * rtDW.tmp_data[rtDW.b_j] +
      rtConstP.empuxo_Phi_Phi[rtDW.b_j];
  }

  rtDW.jmax = 0;
  rtDW.b_j = 0;
  exitg1 = false;
  while ((!exitg1) && (rtDW.b_j + 1 <= 10)) {
    rtDW.jj = rtDW.b_j * 10 + rtDW.b_j;
    rtDW.w1 = 0.0;
    if (!(rtDW.b_j < 1)) {
      rtDW.ix = rtDW.b_j;
      rtDW.iy = rtDW.b_j;
      rtDW.k = 1;
      while (rtDW.k <= rtDW.b_j) {
        rtDW.w1 += rtDW.A_data[rtDW.ix] * rtDW.A_data[rtDW.iy];
        rtDW.ix += 10;
        rtDW.iy += 10;
        rtDW.k++;
      }
    }

    rtDW.w1 = rtDW.A_data[rtDW.jj] - rtDW.w1;
    if (rtDW.w1 > 0.0) {
      rtDW.w1 = sqrt(rtDW.w1);
      rtDW.A_data[rtDW.jj] = rtDW.w1;
      if (rtDW.b_j + 1 < 10) {
        if (rtDW.b_j != 0) {
          rtDW.ix = rtDW.b_j;
          rtDW.iy = ((rtDW.b_j - 1) * 10 + rtDW.b_j) + 2;
          rtDW.k = rtDW.b_j + 2;
          while (rtDW.k <= rtDW.iy) {
            rtDW.w2 = -rtDW.A_data[rtDW.ix];
            rtDW.b_iy = rtDW.jj + 1;
            rtDW.f = (rtDW.k - rtDW.b_j) + 8;
            rtDW.ia = rtDW.k;
            while (rtDW.ia <= rtDW.f) {
              rtDW.A_data[rtDW.b_iy] += rtDW.A_data[rtDW.ia - 1] * rtDW.w2;
              rtDW.b_iy++;
              rtDW.ia++;
            }

            rtDW.ix += 10;
            rtDW.k += 10;
          }
        }

        rtDW.w1 = 1.0 / rtDW.w1;
        rtDW.ix = (rtDW.jj - rtDW.b_j) + 10;
        rtDW.jj++;
        while (rtDW.jj + 1 <= rtDW.ix) {
          rtDW.A_data[rtDW.jj] *= rtDW.w1;
          rtDW.jj++;
        }
      }

      rtDW.b_j++;
    } else {
      rtDW.A_data[rtDW.jj] = rtDW.w1;
      rtDW.jmax = rtDW.b_j + 1;
      exitg1 = true;
    }
  }

  if (rtDW.jmax == 0) {
    rtDW.jmax = 10;
  } else {
    rtDW.jmax--;
  }

  rtDW.b_j = 1;
  while (rtDW.b_j + 1 <= rtDW.jmax) {
    rtDW.jj = 1;
    while (rtDW.jj <= rtDW.b_j) {
      rtDW.A_data[(rtDW.jj + 10 * rtDW.b_j) - 1] = 0.0;
      rtDW.jj++;
    }

    rtDW.b_j++;
  }

  if (1 > rtDW.jmax) {
    rtDW.jmax = 0;
    rtDW.jj = 0;
  } else {
    rtDW.jj = rtDW.jmax;
  }

  for (rtDW.b_j = 0; rtDW.b_j < rtDW.jj; rtDW.b_j++) {
    for (rtDW.ix = 0; rtDW.ix < rtDW.jmax; rtDW.ix++) {
      rtDW.Linv_data[rtDW.ix + rtDW.jmax * rtDW.b_j] = rtDW.A_data[10 * rtDW.b_j
        + rtDW.ix];
    }
  }

  rtDW.B_sizes[0] = rtDW.jmax;
  rtDW.B_sizes[1] = rtDW.jj;
  for (rtDW.b_j = 0; rtDW.b_j < rtDW.jj; rtDW.b_j++) {
    for (rtDW.ix = 0; rtDW.ix < rtDW.jmax; rtDW.ix++) {
      rtDW.A_data[rtDW.ix + rtDW.jmax * rtDW.b_j] = rtDW.Linv_data[rtDW.jmax *
        rtDW.b_j + rtDW.ix];
    }
  }

  // '<S9>:1:36' Linv = L\eye(size(Hqp,1));
  mldivide(rtDW.A_data, rtDW.B_sizes, rtDW.Linv_data, rtDW.Linv_sizes);

  // '<S9>:1:38' opt_mpc = mpcqpsolverOptions;
  // '<S9>:1:39' opt_mpc.IntegrityChecks=false;
  // '<S9>:1:40' opt_mpc.MaxIter=10;
  // '<S9>:1:41' opt_mpc.UseSuboptimalSolution = true;
  // '<S9>:1:43' iA = false(size(b0));
  // '<S9>:1:44' [deltau, status, iA] = mpcqpsolver(Linv,Fqp,Ac,b0,[], zeros(0,1),iA,opt_mpc);
  rtDW.w1 = rtU.xp[2] - rtDW.UnitDelay_DSTATE_o[0];
  rtDW.T = rtU.x[2] - rtDW.UnitDelay_DSTATE_o[1];
  for (rtDW.b_j = 0; rtDW.b_j < 10; rtDW.b_j++) {
    rtDW.dv0[rtDW.b_j] = ((rtConstP.empuxo_Phi_F[rtDW.b_j + 10] * rtDW.T +
      rtConstP.empuxo_Phi_F[rtDW.b_j] * rtDW.w1) +
                          rtConstP.empuxo_Phi_F[rtDW.b_j + 20] * rtU.x[2]) -
      rtConstP.empuxo_Phi_R[rtDW.b_j] * rtU.xr[2];
  }

  mpcqpsolver(rtDW.Linv_data, rtDW.Linv_sizes, rtDW.dv0, rtConstP.empuxo_Ac,
              rtDW.b_b0, rtDW.deltau_data, &rtDW.jmax, &rtDW.w1, rtDW.iA);

  // MATLAB Function: '<S4>/u to T' incorporates:
  //   MATLAB Function: '<S4>/empuxo '

  // '<S9>:1:46' u = deltau(1);
  //  u = ua+deltau(1);
  // '<S9>:1:49' out = [zd z u]';
  // MATLAB Function 'controle/altitude_mpc/u to T': '<S10>:1'
  // '<S10>:1:3' T = m*(u + g);
  rtDW.T = (rtDW.deltau_data[0] + 9.81) * 1.37;
  for (rtDW.jmax = 0; rtDW.jmax < 6; rtDW.jmax++) {
    // Sum: '<S2>/Sum1' incorporates:
    //   Inport: '<Root>/x'
    //   Inport: '<Root>/xr'
    rtDW.Sum1[rtDW.jmax] = rtU.xr[rtDW.jmax]//@>680
      - rtU.x[rtDW.jmax];

    // Sum: '<S2>/Sum' incorporates:
    //   Inport: '<Root>/xp'
    //   Inport: '<Root>/xpr'
    rtDW.Sum[rtDW.jmax] = rtU.xpr[rtDW.jmax]//@>679
      - rtU.xp[rtDW.jmax];
  }

  // MATLAB Function: '<S2>/tau_fi' incorporates:
  //   DiscreteIntegrator: '<S2>/Discrete-Time Integrator'

  // MATLAB Function 'controle/tau_fi': '<S6>:1'
  // '<S6>:1:3' tau_fi = (Kphp*(e(4))+Kphi*(ei(4))+Kphd*(ep(4)));
  rtDW.tau_fi = (0.05 * rtDW.Sum1[3] + 0.0 * rtDW.DiscreteTimeIntegrator_DSTATE
                 [3]) + 0.001 * rtDW.Sum[3];

  // MATLAB Function: '<S2>/tau_theta' incorporates:
  //   DiscreteIntegrator: '<S2>/Discrete-Time Integrator'

  // MATLAB Function 'controle/tau_theta': '<S8>:1'
  // '<S8>:1:3' tau_theta = (Kthp*(e(5))+Kthi*(ei(5))+Kthd*(ep(5)));
  rtDW.tau_theta = (0.08 * rtDW.Sum1[4] + 0.0 *
                    rtDW.DiscreteTimeIntegrator_DSTATE[4]) + 0.00161 * rtDW.Sum
    [4];

  // MATLAB Function: '<S2>/omega_control'
  // MATLAB Function 'controle/tau_psi ': '<S7>:1'
  // '<S7>:1:3' tau_psi = (Kpsp*(e(6))+Kpsi*(ei(6))+Kpsd*(ep(6)));
  // Caso se queira incluir controle em psi, adicionar: [-tau_psi/(4KD),
  // -tau_psi/(4KD), tau_psi/(4KD), tau_psi/(4KD)], respectivamente.
  // MATLAB Function 'controle/omega_control': '<S5>:1'
  // '<S5>:1:6' w1 = (T/(4*KT)-tau_fi/(4*KT*ly)-tau_theta/(4*KT*lx));
  rtDW.w1 = (rtDW.T / 6.2696E-5 - rtDW.tau_fi / 1.3166159999999998E-5) -
    rtDW.tau_theta / 8.15048E-6;

  // '<S5>:1:7' if w1 > 0
  if (rtDW.w1 > 0.0) {
    // '<S5>:1:8' w1 = w1^(1/2);
    rtDW.w1 = sqrt(rtDW.w1);
  } else {
    // '<S5>:1:9' else
    // '<S5>:1:10' w1 = 0;
    rtDW.w1 = 0.0;
  }

  // '<S5>:1:13' w2 = (T/(4*KT)+tau_fi/(4*KT*ly)+tau_theta/(4*KT*lx));
  rtDW.w2 = (rtDW.T / 6.2696E-5 + rtDW.tau_fi / 1.3166159999999998E-5) +
    rtDW.tau_theta / 8.15048E-6;

  // '<S5>:1:14' if w2 > 0
  if (rtDW.w2 > 0.0) {
    // '<S5>:1:15' w2 = w2^(1/2);
    rtDW.w2 = sqrt(rtDW.w2);
  } else {
    // '<S5>:1:16' else
    // '<S5>:1:17' w2 = 0;
    rtDW.w2 = 0.0;
  }

  // '<S5>:1:20' w3 = (T/(4*KT)+tau_fi/(4*KT*ly)-tau_theta/(4*KT*lx));
  rtDW.w3 = (rtDW.T / 6.2696E-5 + rtDW.tau_fi / 1.3166159999999998E-5) -
    rtDW.tau_theta / 8.15048E-6;

  // '<S5>:1:21' if w3 > 0
  if (rtDW.w3 > 0.0) {
    // '<S5>:1:22' w3 = w3^(1/2);
    rtDW.w3 = sqrt(rtDW.w3);
  } else {
    // '<S5>:1:23' else
    // '<S5>:1:24' w3 = 0;
    rtDW.w3 = 0.0;
  }

  // '<S5>:1:27' w4 = (T/(4*KT)-tau_fi/(4*KT*ly)+tau_theta/(4*KT*lx));
  rtDW.T = (rtDW.T / 6.2696E-5 - rtDW.tau_fi / 1.3166159999999998E-5) +
    rtDW.tau_theta / 8.15048E-6;

  // '<S5>:1:28' if w4 > 0
  if (rtDW.T > 0.0) {
    // '<S5>:1:29' w4 = w4^(1/2);
    rtDW.T = sqrt(rtDW.T);
  } else {
    // '<S5>:1:30' else
    // '<S5>:1:31' w4 = 0;
    rtDW.T = 0.0;
  }

  // Outport: '<Root>/w' incorporates:
  //   MATLAB Function: '<S2>/omega_control'

  // '<S5>:1:34' w = [w1;w2;w3;w4];
  // y = [u(4) u(2) u(3) u(1)]; %antigo
  // y = [u(2) u(4) u(1) u(3)];
  // MATLAB Function 'MATLAB Function2': '<S1>:1'
  // '<S1>:1:6' y = u;
  rtY.w[0] = rtDW.w1;
  rtY.w[1] = rtDW.w2;
  rtY.w[2] = rtDW.w3;
  rtY.w[3] = rtDW.T;

  // Update for UnitDelay: '<S4>/Unit Delay' incorporates:
  //   Inport: '<Root>/x'
  //   Inport: '<Root>/xp'
  //   MATLAB Function: '<S4>/empuxo '

  // MATLAB Function 'controle/U Feedback Real': '<S3>:1'
  // '<S3>:1:4' uold = KT/m*(w(1)^2+w(2)^2+w(3)^2+w(3)^2)-g;
  rtDW.UnitDelay_DSTATE_o[0] = rtU.xp[2];
  rtDW.UnitDelay_DSTATE_o[1] = rtU.x[2];
  rtDW.UnitDelay_DSTATE_o[2] = rtDW.deltau_data[0];

  // Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
  for (rtDW.b_j = 0; rtDW.b_j < 6; rtDW.b_j++) {
    rtDW.DiscreteTimeIntegrator_DSTATE[rtDW.b_j]//@>678
      += 0.01                          //@>678
      * rtDW.Sum1[rtDW.b_j];
  }

  // End of Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
}

// Model initialize function
void mpcqp_solver_douglas_v4ModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // InitializeConditions for UnitDelay: '<S4>/Unit Delay'
  rtDW.UnitDelay_DSTATE_o[0] = 0.0;
  rtDW.UnitDelay_DSTATE_o[1] = 0.0;
  rtDW.UnitDelay_DSTATE_o[2] = -9.81;
}

// Constructor
mpcqp_solver_douglas_v4ModelClass::mpcqp_solver_douglas_v4ModelClass()
{
}

// Destructor
mpcqp_solver_douglas_v4ModelClass::~mpcqp_solver_douglas_v4ModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL * mpcqp_solver_douglas_v4ModelClass::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
