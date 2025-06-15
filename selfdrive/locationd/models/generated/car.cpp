#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4788797279981293652) {
   out_4788797279981293652[0] = delta_x[0] + nom_x[0];
   out_4788797279981293652[1] = delta_x[1] + nom_x[1];
   out_4788797279981293652[2] = delta_x[2] + nom_x[2];
   out_4788797279981293652[3] = delta_x[3] + nom_x[3];
   out_4788797279981293652[4] = delta_x[4] + nom_x[4];
   out_4788797279981293652[5] = delta_x[5] + nom_x[5];
   out_4788797279981293652[6] = delta_x[6] + nom_x[6];
   out_4788797279981293652[7] = delta_x[7] + nom_x[7];
   out_4788797279981293652[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4134860755922451640) {
   out_4134860755922451640[0] = -nom_x[0] + true_x[0];
   out_4134860755922451640[1] = -nom_x[1] + true_x[1];
   out_4134860755922451640[2] = -nom_x[2] + true_x[2];
   out_4134860755922451640[3] = -nom_x[3] + true_x[3];
   out_4134860755922451640[4] = -nom_x[4] + true_x[4];
   out_4134860755922451640[5] = -nom_x[5] + true_x[5];
   out_4134860755922451640[6] = -nom_x[6] + true_x[6];
   out_4134860755922451640[7] = -nom_x[7] + true_x[7];
   out_4134860755922451640[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3255324825430708188) {
   out_3255324825430708188[0] = 1.0;
   out_3255324825430708188[1] = 0;
   out_3255324825430708188[2] = 0;
   out_3255324825430708188[3] = 0;
   out_3255324825430708188[4] = 0;
   out_3255324825430708188[5] = 0;
   out_3255324825430708188[6] = 0;
   out_3255324825430708188[7] = 0;
   out_3255324825430708188[8] = 0;
   out_3255324825430708188[9] = 0;
   out_3255324825430708188[10] = 1.0;
   out_3255324825430708188[11] = 0;
   out_3255324825430708188[12] = 0;
   out_3255324825430708188[13] = 0;
   out_3255324825430708188[14] = 0;
   out_3255324825430708188[15] = 0;
   out_3255324825430708188[16] = 0;
   out_3255324825430708188[17] = 0;
   out_3255324825430708188[18] = 0;
   out_3255324825430708188[19] = 0;
   out_3255324825430708188[20] = 1.0;
   out_3255324825430708188[21] = 0;
   out_3255324825430708188[22] = 0;
   out_3255324825430708188[23] = 0;
   out_3255324825430708188[24] = 0;
   out_3255324825430708188[25] = 0;
   out_3255324825430708188[26] = 0;
   out_3255324825430708188[27] = 0;
   out_3255324825430708188[28] = 0;
   out_3255324825430708188[29] = 0;
   out_3255324825430708188[30] = 1.0;
   out_3255324825430708188[31] = 0;
   out_3255324825430708188[32] = 0;
   out_3255324825430708188[33] = 0;
   out_3255324825430708188[34] = 0;
   out_3255324825430708188[35] = 0;
   out_3255324825430708188[36] = 0;
   out_3255324825430708188[37] = 0;
   out_3255324825430708188[38] = 0;
   out_3255324825430708188[39] = 0;
   out_3255324825430708188[40] = 1.0;
   out_3255324825430708188[41] = 0;
   out_3255324825430708188[42] = 0;
   out_3255324825430708188[43] = 0;
   out_3255324825430708188[44] = 0;
   out_3255324825430708188[45] = 0;
   out_3255324825430708188[46] = 0;
   out_3255324825430708188[47] = 0;
   out_3255324825430708188[48] = 0;
   out_3255324825430708188[49] = 0;
   out_3255324825430708188[50] = 1.0;
   out_3255324825430708188[51] = 0;
   out_3255324825430708188[52] = 0;
   out_3255324825430708188[53] = 0;
   out_3255324825430708188[54] = 0;
   out_3255324825430708188[55] = 0;
   out_3255324825430708188[56] = 0;
   out_3255324825430708188[57] = 0;
   out_3255324825430708188[58] = 0;
   out_3255324825430708188[59] = 0;
   out_3255324825430708188[60] = 1.0;
   out_3255324825430708188[61] = 0;
   out_3255324825430708188[62] = 0;
   out_3255324825430708188[63] = 0;
   out_3255324825430708188[64] = 0;
   out_3255324825430708188[65] = 0;
   out_3255324825430708188[66] = 0;
   out_3255324825430708188[67] = 0;
   out_3255324825430708188[68] = 0;
   out_3255324825430708188[69] = 0;
   out_3255324825430708188[70] = 1.0;
   out_3255324825430708188[71] = 0;
   out_3255324825430708188[72] = 0;
   out_3255324825430708188[73] = 0;
   out_3255324825430708188[74] = 0;
   out_3255324825430708188[75] = 0;
   out_3255324825430708188[76] = 0;
   out_3255324825430708188[77] = 0;
   out_3255324825430708188[78] = 0;
   out_3255324825430708188[79] = 0;
   out_3255324825430708188[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5476243798218477271) {
   out_5476243798218477271[0] = state[0];
   out_5476243798218477271[1] = state[1];
   out_5476243798218477271[2] = state[2];
   out_5476243798218477271[3] = state[3];
   out_5476243798218477271[4] = state[4];
   out_5476243798218477271[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5476243798218477271[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5476243798218477271[7] = state[7];
   out_5476243798218477271[8] = state[8];
}
void F_fun(double *state, double dt, double *out_6591062828934895506) {
   out_6591062828934895506[0] = 1;
   out_6591062828934895506[1] = 0;
   out_6591062828934895506[2] = 0;
   out_6591062828934895506[3] = 0;
   out_6591062828934895506[4] = 0;
   out_6591062828934895506[5] = 0;
   out_6591062828934895506[6] = 0;
   out_6591062828934895506[7] = 0;
   out_6591062828934895506[8] = 0;
   out_6591062828934895506[9] = 0;
   out_6591062828934895506[10] = 1;
   out_6591062828934895506[11] = 0;
   out_6591062828934895506[12] = 0;
   out_6591062828934895506[13] = 0;
   out_6591062828934895506[14] = 0;
   out_6591062828934895506[15] = 0;
   out_6591062828934895506[16] = 0;
   out_6591062828934895506[17] = 0;
   out_6591062828934895506[18] = 0;
   out_6591062828934895506[19] = 0;
   out_6591062828934895506[20] = 1;
   out_6591062828934895506[21] = 0;
   out_6591062828934895506[22] = 0;
   out_6591062828934895506[23] = 0;
   out_6591062828934895506[24] = 0;
   out_6591062828934895506[25] = 0;
   out_6591062828934895506[26] = 0;
   out_6591062828934895506[27] = 0;
   out_6591062828934895506[28] = 0;
   out_6591062828934895506[29] = 0;
   out_6591062828934895506[30] = 1;
   out_6591062828934895506[31] = 0;
   out_6591062828934895506[32] = 0;
   out_6591062828934895506[33] = 0;
   out_6591062828934895506[34] = 0;
   out_6591062828934895506[35] = 0;
   out_6591062828934895506[36] = 0;
   out_6591062828934895506[37] = 0;
   out_6591062828934895506[38] = 0;
   out_6591062828934895506[39] = 0;
   out_6591062828934895506[40] = 1;
   out_6591062828934895506[41] = 0;
   out_6591062828934895506[42] = 0;
   out_6591062828934895506[43] = 0;
   out_6591062828934895506[44] = 0;
   out_6591062828934895506[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_6591062828934895506[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_6591062828934895506[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6591062828934895506[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_6591062828934895506[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_6591062828934895506[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_6591062828934895506[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_6591062828934895506[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_6591062828934895506[53] = -9.8000000000000007*dt;
   out_6591062828934895506[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_6591062828934895506[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_6591062828934895506[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6591062828934895506[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6591062828934895506[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_6591062828934895506[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_6591062828934895506[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_6591062828934895506[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6591062828934895506[62] = 0;
   out_6591062828934895506[63] = 0;
   out_6591062828934895506[64] = 0;
   out_6591062828934895506[65] = 0;
   out_6591062828934895506[66] = 0;
   out_6591062828934895506[67] = 0;
   out_6591062828934895506[68] = 0;
   out_6591062828934895506[69] = 0;
   out_6591062828934895506[70] = 1;
   out_6591062828934895506[71] = 0;
   out_6591062828934895506[72] = 0;
   out_6591062828934895506[73] = 0;
   out_6591062828934895506[74] = 0;
   out_6591062828934895506[75] = 0;
   out_6591062828934895506[76] = 0;
   out_6591062828934895506[77] = 0;
   out_6591062828934895506[78] = 0;
   out_6591062828934895506[79] = 0;
   out_6591062828934895506[80] = 1;
}
void h_25(double *state, double *unused, double *out_430382737830584898) {
   out_430382737830584898[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4166465942712079583) {
   out_4166465942712079583[0] = 0;
   out_4166465942712079583[1] = 0;
   out_4166465942712079583[2] = 0;
   out_4166465942712079583[3] = 0;
   out_4166465942712079583[4] = 0;
   out_4166465942712079583[5] = 0;
   out_4166465942712079583[6] = 1;
   out_4166465942712079583[7] = 0;
   out_4166465942712079583[8] = 0;
}
void h_24(double *state, double *unused, double *out_1176694169682285485) {
   out_1176694169682285485[0] = state[4];
   out_1176694169682285485[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2753437694673670746) {
   out_2753437694673670746[0] = 0;
   out_2753437694673670746[1] = 0;
   out_2753437694673670746[2] = 0;
   out_2753437694673670746[3] = 0;
   out_2753437694673670746[4] = 1;
   out_2753437694673670746[5] = 0;
   out_2753437694673670746[6] = 0;
   out_2753437694673670746[7] = 0;
   out_2753437694673670746[8] = 0;
   out_2753437694673670746[9] = 0;
   out_2753437694673670746[10] = 0;
   out_2753437694673670746[11] = 0;
   out_2753437694673670746[12] = 0;
   out_2753437694673670746[13] = 0;
   out_2753437694673670746[14] = 1;
   out_2753437694673670746[15] = 0;
   out_2753437694673670746[16] = 0;
   out_2753437694673670746[17] = 0;
}
void h_30(double *state, double *unused, double *out_2631170746352051334) {
   out_2631170746352051334[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1648132984204830956) {
   out_1648132984204830956[0] = 0;
   out_1648132984204830956[1] = 0;
   out_1648132984204830956[2] = 0;
   out_1648132984204830956[3] = 0;
   out_1648132984204830956[4] = 1;
   out_1648132984204830956[5] = 0;
   out_1648132984204830956[6] = 0;
   out_1648132984204830956[7] = 0;
   out_1648132984204830956[8] = 0;
}
void h_26(double *state, double *unused, double *out_1649086653016753222) {
   out_1649086653016753222[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7907969261586135807) {
   out_7907969261586135807[0] = 0;
   out_7907969261586135807[1] = 0;
   out_7907969261586135807[2] = 0;
   out_7907969261586135807[3] = 0;
   out_7907969261586135807[4] = 0;
   out_7907969261586135807[5] = 0;
   out_7907969261586135807[6] = 0;
   out_7907969261586135807[7] = 1;
   out_7907969261586135807[8] = 0;
}
void h_27(double *state, double *unused, double *out_2174022582978112753) {
   out_2174022582978112753[0] = state[3];
}
void H_27(double *state, double *unused, double *out_6470568201655744564) {
   out_6470568201655744564[0] = 0;
   out_6470568201655744564[1] = 0;
   out_6470568201655744564[2] = 0;
   out_6470568201655744564[3] = 1;
   out_6470568201655744564[4] = 0;
   out_6470568201655744564[5] = 0;
   out_6470568201655744564[6] = 0;
   out_6470568201655744564[7] = 0;
   out_6470568201655744564[8] = 0;
}
void h_29(double *state, double *unused, double *out_2331209251329241898) {
   out_2331209251329241898[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8183930928525295597) {
   out_8183930928525295597[0] = 0;
   out_8183930928525295597[1] = 1;
   out_8183930928525295597[2] = 0;
   out_8183930928525295597[3] = 0;
   out_8183930928525295597[4] = 0;
   out_8183930928525295597[5] = 0;
   out_8183930928525295597[6] = 0;
   out_8183930928525295597[7] = 0;
   out_8183930928525295597[8] = 0;
}
void h_28(double *state, double *unused, double *out_4986574686247966136) {
   out_4986574686247966136[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6220300656959969346) {
   out_6220300656959969346[0] = 1;
   out_6220300656959969346[1] = 0;
   out_6220300656959969346[2] = 0;
   out_6220300656959969346[3] = 0;
   out_6220300656959969346[4] = 0;
   out_6220300656959969346[5] = 0;
   out_6220300656959969346[6] = 0;
   out_6220300656959969346[7] = 0;
   out_6220300656959969346[8] = 0;
}
void h_31(double *state, double *unused, double *out_7633598694816570868) {
   out_7633598694816570868[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4135819980835119155) {
   out_4135819980835119155[0] = 0;
   out_4135819980835119155[1] = 0;
   out_4135819980835119155[2] = 0;
   out_4135819980835119155[3] = 0;
   out_4135819980835119155[4] = 0;
   out_4135819980835119155[5] = 0;
   out_4135819980835119155[6] = 0;
   out_4135819980835119155[7] = 0;
   out_4135819980835119155[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_4788797279981293652) {
  err_fun(nom_x, delta_x, out_4788797279981293652);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4134860755922451640) {
  inv_err_fun(nom_x, true_x, out_4134860755922451640);
}
void car_H_mod_fun(double *state, double *out_3255324825430708188) {
  H_mod_fun(state, out_3255324825430708188);
}
void car_f_fun(double *state, double dt, double *out_5476243798218477271) {
  f_fun(state,  dt, out_5476243798218477271);
}
void car_F_fun(double *state, double dt, double *out_6591062828934895506) {
  F_fun(state,  dt, out_6591062828934895506);
}
void car_h_25(double *state, double *unused, double *out_430382737830584898) {
  h_25(state, unused, out_430382737830584898);
}
void car_H_25(double *state, double *unused, double *out_4166465942712079583) {
  H_25(state, unused, out_4166465942712079583);
}
void car_h_24(double *state, double *unused, double *out_1176694169682285485) {
  h_24(state, unused, out_1176694169682285485);
}
void car_H_24(double *state, double *unused, double *out_2753437694673670746) {
  H_24(state, unused, out_2753437694673670746);
}
void car_h_30(double *state, double *unused, double *out_2631170746352051334) {
  h_30(state, unused, out_2631170746352051334);
}
void car_H_30(double *state, double *unused, double *out_1648132984204830956) {
  H_30(state, unused, out_1648132984204830956);
}
void car_h_26(double *state, double *unused, double *out_1649086653016753222) {
  h_26(state, unused, out_1649086653016753222);
}
void car_H_26(double *state, double *unused, double *out_7907969261586135807) {
  H_26(state, unused, out_7907969261586135807);
}
void car_h_27(double *state, double *unused, double *out_2174022582978112753) {
  h_27(state, unused, out_2174022582978112753);
}
void car_H_27(double *state, double *unused, double *out_6470568201655744564) {
  H_27(state, unused, out_6470568201655744564);
}
void car_h_29(double *state, double *unused, double *out_2331209251329241898) {
  h_29(state, unused, out_2331209251329241898);
}
void car_H_29(double *state, double *unused, double *out_8183930928525295597) {
  H_29(state, unused, out_8183930928525295597);
}
void car_h_28(double *state, double *unused, double *out_4986574686247966136) {
  h_28(state, unused, out_4986574686247966136);
}
void car_H_28(double *state, double *unused, double *out_6220300656959969346) {
  H_28(state, unused, out_6220300656959969346);
}
void car_h_31(double *state, double *unused, double *out_7633598694816570868) {
  h_31(state, unused, out_7633598694816570868);
}
void car_H_31(double *state, double *unused, double *out_4135819980835119155) {
  H_31(state, unused, out_4135819980835119155);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
