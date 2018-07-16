//
// File: pred_z_pid_angle.h
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
#ifndef RTW_HEADER_pred_z_pid_angle_h_
#define RTW_HEADER_pred_z_pid_angle_h_
#include <stddef.h>
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#ifndef pred_z_pid_angle_COMMON_INCLUDES_
# define pred_z_pid_angle_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // pred_z_pid_angle_COMMON_INCLUDES_

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

// Custom Type definition for MATLAB Function: '<S4>/empuxo '
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  int32_T f0;
  int32_T f1;
} struct_T;

#endif                                 //typedef_struct_T

#ifndef struct_tag_scZlGNcmSdXsfgNftx2nQBF
#define struct_tag_scZlGNcmSdXsfgNftx2nQBF

struct tag_scZlGNcmSdXsfgNftx2nQBF
{
  char_T DataType[6];
  real_T MaxIter;
  real_T FeasibilityTol;
  boolean_T IntegrityChecks;
};

#endif                                 //struct_tag_scZlGNcmSdXsfgNftx2nQBF

#ifndef typedef_scZlGNcmSdXsfgNftx2nQBF
#define typedef_scZlGNcmSdXsfgNftx2nQBF

typedef struct tag_scZlGNcmSdXsfgNftx2nQBF scZlGNcmSdXsfgNftx2nQBF;

#endif                                 //typedef_scZlGNcmSdXsfgNftx2nQBF

#ifndef struct_tag_swOzE9bX13QNZl3RlXYqsLG
#define struct_tag_swOzE9bX13QNZl3RlXYqsLG

struct tag_swOzE9bX13QNZl3RlXYqsLG
{
  char_T DataType[6];
  real_T MaxIter;
  real_T FeasibilityTol;
  boolean_T IntegrityChecks;
  boolean_T UseSuboptimalSolution;
};

#endif                                 //struct_tag_swOzE9bX13QNZl3RlXYqsLG

#ifndef typedef_swOzE9bX13QNZl3RlXYqsLG
#define typedef_swOzE9bX13QNZl3RlXYqsLG

typedef struct tag_swOzE9bX13QNZl3RlXYqsLG swOzE9bX13QNZl3RlXYqsLG;

#endif                                 //typedef_swOzE9bX13QNZl3RlXYqsLG

// Block signals and states (auto storage) for system '<Root>'
typedef struct {
  real_T UnitDelay_DSTATE_o[3];        // '<S4>/Unit Delay'
  real_T DiscreteTimeIntegrator_DSTATE[6];// '<S2>/Discrete-Time Integrator'
  real_T tmp_data[16129];
  real_T Linv_data[100];
  real_T A_data[100];
  real_T Hinv[100];
  real_T a_data[100];
  real_T RLinv_data[100];
  real_T D_data[100];
  real_T H_data[100];
  real_T a_data_m[100];
  real_T TL_data[100];
  real_T QQ_data[100];
  real_T RR_data[100];
  real_T b_A_data[100];
  real_T b_b0[38];
  real_T lam[38];
  real_T cTol[38];
  real_T varargin_1[38];
  real_T dv0[10];
  real_T deltau_data[10];
  real_T AcRow[10];
  real_T r_data[10];
  real_T z_data[10];
  real_T D_data_c[10];
  real_T b_b_data[10];
  real_T work[10];
  real_T tau_data[10];
  real_T work_k[10];
  real_T Sum1[6];                      // '<S2>/Sum1'
  real_T Sum[6];                       // '<S2>/Sum'
  real_T B_c[100];
  real_T b_A_data_b[100];
  real_T b_A_data_p[100];
  real_T B_cv[100];
  real_T tau_data_f[10];
  real_T work_data[10];
  real_T vn1_data[10];
  real_T vn2_data[10];
  real_T w1;
  real_T w2;
  real_T w3;
  real_T T;                            // '<S4>/u to T'
  real_T tau_fi;                       // '<S2>/tau_fi'
  real_T tau_theta;                    // '<S2>/tau_theta'
  real_T rMin;
  real_T Xnorm0;
  real_T cMin;
  real_T zTa;
  real_T t;
  real_T d0;
  real_T c_c;
  real_T b_atmp;
  real_T xnorm;
  real_T b_c;
  real_T scale;
  real_T absxk;
  real_T t_g;
  real_T smax;
  real_T s;
  real_T smax_g;
  real_T s_m;
  real_T absxk_n;
  real_T t_p;
  real_T wj;
  real_T xnorm_l;
  real_T scale_j;
  real_T absxk_d;
  real_T t_gu;
  real_T c;
  int32_T Linv_sizes[2];
  int32_T B_sizes[2];
  int32_T RLinv_sizes[2];
  int32_T D_sizes[2];
  int32_T H_sizes[2];
  int32_T QQ_sizes[2];
  int32_T RR_sizes[2];
  int32_T b_A_sizes[2];
  int32_T jpvt_data[10];
  int32_T b_A_sizes_l[2];
  int32_T jpvt_sizes[2];
  int32_T jmax;
  int32_T jj;
  int32_T b_j;
  int32_T ix;
  int32_T iy;
  int32_T k;
  int32_T b_iy;
  int32_T f;
  int32_T ia;
  int32_T br;
  int32_T ar;
  int32_T ia_d;
  int32_T b_cr;
  int32_T c_d;
  int32_T ib;
  int32_T b_ic;
  int32_T i;
  int32_T m;
  int32_T br_l;
  int32_T ar_o;
  int32_T ia_b;
  int32_T ib_n;
  int32_T b_ic_b;
  int32_T ixstart;
  int32_T i_l;
  int32_T z_sizes;
  int32_T m_h;
  int32_T br_b;
  int32_T ar_d;
  int32_T ia_e;
  int32_T ib_b;
  int32_T b_ic_j;
  int32_T b_b_sizes;
  int32_T TL_sizes_idx_0;
  int32_T m_f;
  int32_T e_i;
  int32_T itau;
  int32_T iaii;
  int32_T lastv;
  int32_T lastc;
  int32_T ix_a;
  int32_T iy_j;
  int32_T d;
  int32_T e;
  int32_T b_ia;
  int32_T jA;
  int32_T b_ix;
  int32_T m_j;
  int32_T mn;
  int32_T i_i;
  int32_T mmi;
  int32_T i_ip1;
  int32_T i_o;
  int32_T knt;
  int32_T iy_n;
  int32_T c_ix;
  int32_T d_i;
  int32_T ijA;
  int32_T b_jBcol;
  int32_T b_kAcol;
  int32_T c_i;
  int32_T loop_ub;
  int32_T n;
  int32_T nmi;
  int16_T iA1[38];
  int16_T iC[38];
  int8_T ipiv[10];
  boolean_T iA[38];
} DW;

// Constant parameters (auto storage)
typedef struct {
  // Expression: Ac
  //  Referenced by: '<S4>/empuxo '

  real_T empuxo_Ac[380];

  // Expression: Phi_F
  //  Referenced by: '<S4>/empuxo '

  real_T empuxo_Phi_F[30];

  // Expression: Phi_Phi
  //  Referenced by: '<S4>/empuxo '

  real_T empuxo_Phi_Phi[100];

  // Expression: Phi_R
  //  Referenced by: '<S4>/empuxo '

  real_T empuxo_Phi_R[10];

  // Expression: b0
  //  Referenced by: '<S4>/empuxo '

  real_T empuxo_b0[38];
} ConstP;

// External inputs (root inport signals with auto storage)
typedef struct {
  real_T xr[6];                        // '<Root>/xr'
  real_T xpr[6];                       // '<Root>/xpr'
  real_T x[6];                         // '<Root>/x'
  real_T xp[6];                        // '<Root>/xp'
} ExtU;

// External outputs (root outports fed by signals with auto storage)
typedef struct {
  real_T w[4];                         // '<Root>/w'
} ExtY;

// Real-time Model Data Structure
struct tag_RTM {
  const char_T * volatile errorStatus;
};

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

// Constant parameters (auto storage)
extern const ConstP rtConstP;

// Class declaration for model pred_z_pid_angle
class mpcqp_solver_douglas_v4ModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  mpcqp_solver_douglas_v4ModelClass();

  // Destructor
  ~mpcqp_solver_douglas_v4ModelClass();

  // Real-Time Model get method
  RT_MODEL * getRTM();

  // private data and function members
 private:
  // Block signals and states
  DW rtDW;

  // Real-Time Model
  RT_MODEL rtM;

  // private member function(s) for subsystem '<Root>'
  void eye(int8_T varargin_1, real_T I_data[], int32_T I_sizes[2]);
  int32_T rankFromQR(const real_T A_data[], const int32_T A_sizes[2]);
  void LSQFromQR(const real_T A_data[], const int32_T A_sizes[2], const real_T
                 tau_data[], const int32_T jpvt_data[], int32_T rankA, real_T
                 Y_data[], int32_T Y_sizes[2]);
  real_T xnrm2(int32_T n, const real_T x_data[], int32_T ix0);
  real_T xzlarfg(int32_T n, real_T *alpha1, real_T x_data[], int32_T ix0);
  void xzlarf(int32_T m, int32_T n, int32_T iv0, real_T tau, real_T C_data[],
              int32_T ic0, real_T work_data[]);
  void qrsolve(const real_T A_data[], const int32_T A_sizes[2], real_T Y_data[],
               int32_T Y_sizes[2]);
  void mldivide(const real_T A_data[], const int32_T A_sizes[2], real_T Y_data[],
                int32_T Y_sizes[2]);
  void Unconstrained(const real_T Hinv[100], const real_T f[10], real_T x_data[],
                     int16_T n);
  real_T norm(const real_T x_data[], const int32_T x_sizes);
  void abs_b4(const real_T x[38], real_T y[38]);
  real_T xnrm2_c(int32_T n, const real_T x_data[], int32_T ix0);
  void xgeqrf(real_T A_data[], int32_T A_sizes[2], real_T tau_data[], int32_T
              *tau_sizes);
  void qr(const real_T A_data[], const int32_T A_sizes[2], real_T Q_data[],
          int32_T Q_sizes[2], real_T R_data[], int32_T R_sizes[2]);
  real_T KWIKfactor(const real_T b_Ac[380], const int16_T iC[38], int16_T nA,
                    const real_T Linv_data[], const int32_T Linv_sizes[2],
                    real_T RLinv_data[], int32_T RLinv_sizes[2], real_T D_data[],
                    int32_T D_sizes[2], real_T H_data[], int32_T H_sizes[2],
                    int16_T n);
  void DropConstraint(int16_T kDrop, int16_T iA[38], int16_T *nA, int16_T iC[38]);
  void abs_b(const real_T x[10], real_T y[10]);
  void qpkwik(const real_T Linv_data[], const int32_T Linv_sizes[2], const
              real_T Hinv[100], const real_T f[10], const real_T b_Ac[380],
              const real_T b[38], int16_T n, real_T x_data[], int32_T *x_sizes,
              real_T lambda[38], real_T *status, int16_T iA[38]);
  void mpcqpsolver(const real_T Linv_data[], const int32_T Linv_sizes[2], const
                   real_T f[10], const real_T A[380], const real_T b[38], real_T
                   x_data[], int32_T *x_sizes, real_T *status, boolean_T iA[38]);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Controle PSI' : Unused code path elimination
//  Block '<S2>/Controle Phi' : Unused code path elimination
//  Block '<S2>/Controle Theta' : Unused code path elimination
//  Block '<S2>/T' : Unused code path elimination
//  Block '<S2>/w' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'pred_z_pid_angle'
//  '<S1>'   : 'pred_z_pid_angle/MATLAB Function2'
//  '<S2>'   : 'pred_z_pid_angle/controle'
//  '<S3>'   : 'pred_z_pid_angle/controle/U Feedback Real'
//  '<S4>'   : 'pred_z_pid_angle/controle/altitude_mpc'
//  '<S5>'   : 'pred_z_pid_angle/controle/omega_control'
//  '<S6>'   : 'pred_z_pid_angle/controle/tau_fi'
//  '<S7>'   : 'pred_z_pid_angle/controle/tau_psi '
//  '<S8>'   : 'pred_z_pid_angle/controle/tau_theta'
//  '<S9>'   : 'pred_z_pid_angle/controle/altitude_mpc/empuxo '
//  '<S10>'  : 'pred_z_pid_angle/controle/altitude_mpc/u to T'

#endif                                 // RTW_HEADER_pred_z_pid_angle_h_

//
// File trailer for generated code.
//
// [EOF]
//
