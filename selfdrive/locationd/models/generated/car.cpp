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
void err_fun(double *nom_x, double *delta_x, double *out_6452236370958953739) {
   out_6452236370958953739[0] = delta_x[0] + nom_x[0];
   out_6452236370958953739[1] = delta_x[1] + nom_x[1];
   out_6452236370958953739[2] = delta_x[2] + nom_x[2];
   out_6452236370958953739[3] = delta_x[3] + nom_x[3];
   out_6452236370958953739[4] = delta_x[4] + nom_x[4];
   out_6452236370958953739[5] = delta_x[5] + nom_x[5];
   out_6452236370958953739[6] = delta_x[6] + nom_x[6];
   out_6452236370958953739[7] = delta_x[7] + nom_x[7];
   out_6452236370958953739[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_1025168132938650359) {
   out_1025168132938650359[0] = -nom_x[0] + true_x[0];
   out_1025168132938650359[1] = -nom_x[1] + true_x[1];
   out_1025168132938650359[2] = -nom_x[2] + true_x[2];
   out_1025168132938650359[3] = -nom_x[3] + true_x[3];
   out_1025168132938650359[4] = -nom_x[4] + true_x[4];
   out_1025168132938650359[5] = -nom_x[5] + true_x[5];
   out_1025168132938650359[6] = -nom_x[6] + true_x[6];
   out_1025168132938650359[7] = -nom_x[7] + true_x[7];
   out_1025168132938650359[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3402141057055527033) {
   out_3402141057055527033[0] = 1.0;
   out_3402141057055527033[1] = 0;
   out_3402141057055527033[2] = 0;
   out_3402141057055527033[3] = 0;
   out_3402141057055527033[4] = 0;
   out_3402141057055527033[5] = 0;
   out_3402141057055527033[6] = 0;
   out_3402141057055527033[7] = 0;
   out_3402141057055527033[8] = 0;
   out_3402141057055527033[9] = 0;
   out_3402141057055527033[10] = 1.0;
   out_3402141057055527033[11] = 0;
   out_3402141057055527033[12] = 0;
   out_3402141057055527033[13] = 0;
   out_3402141057055527033[14] = 0;
   out_3402141057055527033[15] = 0;
   out_3402141057055527033[16] = 0;
   out_3402141057055527033[17] = 0;
   out_3402141057055527033[18] = 0;
   out_3402141057055527033[19] = 0;
   out_3402141057055527033[20] = 1.0;
   out_3402141057055527033[21] = 0;
   out_3402141057055527033[22] = 0;
   out_3402141057055527033[23] = 0;
   out_3402141057055527033[24] = 0;
   out_3402141057055527033[25] = 0;
   out_3402141057055527033[26] = 0;
   out_3402141057055527033[27] = 0;
   out_3402141057055527033[28] = 0;
   out_3402141057055527033[29] = 0;
   out_3402141057055527033[30] = 1.0;
   out_3402141057055527033[31] = 0;
   out_3402141057055527033[32] = 0;
   out_3402141057055527033[33] = 0;
   out_3402141057055527033[34] = 0;
   out_3402141057055527033[35] = 0;
   out_3402141057055527033[36] = 0;
   out_3402141057055527033[37] = 0;
   out_3402141057055527033[38] = 0;
   out_3402141057055527033[39] = 0;
   out_3402141057055527033[40] = 1.0;
   out_3402141057055527033[41] = 0;
   out_3402141057055527033[42] = 0;
   out_3402141057055527033[43] = 0;
   out_3402141057055527033[44] = 0;
   out_3402141057055527033[45] = 0;
   out_3402141057055527033[46] = 0;
   out_3402141057055527033[47] = 0;
   out_3402141057055527033[48] = 0;
   out_3402141057055527033[49] = 0;
   out_3402141057055527033[50] = 1.0;
   out_3402141057055527033[51] = 0;
   out_3402141057055527033[52] = 0;
   out_3402141057055527033[53] = 0;
   out_3402141057055527033[54] = 0;
   out_3402141057055527033[55] = 0;
   out_3402141057055527033[56] = 0;
   out_3402141057055527033[57] = 0;
   out_3402141057055527033[58] = 0;
   out_3402141057055527033[59] = 0;
   out_3402141057055527033[60] = 1.0;
   out_3402141057055527033[61] = 0;
   out_3402141057055527033[62] = 0;
   out_3402141057055527033[63] = 0;
   out_3402141057055527033[64] = 0;
   out_3402141057055527033[65] = 0;
   out_3402141057055527033[66] = 0;
   out_3402141057055527033[67] = 0;
   out_3402141057055527033[68] = 0;
   out_3402141057055527033[69] = 0;
   out_3402141057055527033[70] = 1.0;
   out_3402141057055527033[71] = 0;
   out_3402141057055527033[72] = 0;
   out_3402141057055527033[73] = 0;
   out_3402141057055527033[74] = 0;
   out_3402141057055527033[75] = 0;
   out_3402141057055527033[76] = 0;
   out_3402141057055527033[77] = 0;
   out_3402141057055527033[78] = 0;
   out_3402141057055527033[79] = 0;
   out_3402141057055527033[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_193046874957989045) {
   out_193046874957989045[0] = state[0];
   out_193046874957989045[1] = state[1];
   out_193046874957989045[2] = state[2];
   out_193046874957989045[3] = state[3];
   out_193046874957989045[4] = state[4];
   out_193046874957989045[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_193046874957989045[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_193046874957989045[7] = state[7];
   out_193046874957989045[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7216222925288119041) {
   out_7216222925288119041[0] = 1;
   out_7216222925288119041[1] = 0;
   out_7216222925288119041[2] = 0;
   out_7216222925288119041[3] = 0;
   out_7216222925288119041[4] = 0;
   out_7216222925288119041[5] = 0;
   out_7216222925288119041[6] = 0;
   out_7216222925288119041[7] = 0;
   out_7216222925288119041[8] = 0;
   out_7216222925288119041[9] = 0;
   out_7216222925288119041[10] = 1;
   out_7216222925288119041[11] = 0;
   out_7216222925288119041[12] = 0;
   out_7216222925288119041[13] = 0;
   out_7216222925288119041[14] = 0;
   out_7216222925288119041[15] = 0;
   out_7216222925288119041[16] = 0;
   out_7216222925288119041[17] = 0;
   out_7216222925288119041[18] = 0;
   out_7216222925288119041[19] = 0;
   out_7216222925288119041[20] = 1;
   out_7216222925288119041[21] = 0;
   out_7216222925288119041[22] = 0;
   out_7216222925288119041[23] = 0;
   out_7216222925288119041[24] = 0;
   out_7216222925288119041[25] = 0;
   out_7216222925288119041[26] = 0;
   out_7216222925288119041[27] = 0;
   out_7216222925288119041[28] = 0;
   out_7216222925288119041[29] = 0;
   out_7216222925288119041[30] = 1;
   out_7216222925288119041[31] = 0;
   out_7216222925288119041[32] = 0;
   out_7216222925288119041[33] = 0;
   out_7216222925288119041[34] = 0;
   out_7216222925288119041[35] = 0;
   out_7216222925288119041[36] = 0;
   out_7216222925288119041[37] = 0;
   out_7216222925288119041[38] = 0;
   out_7216222925288119041[39] = 0;
   out_7216222925288119041[40] = 1;
   out_7216222925288119041[41] = 0;
   out_7216222925288119041[42] = 0;
   out_7216222925288119041[43] = 0;
   out_7216222925288119041[44] = 0;
   out_7216222925288119041[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7216222925288119041[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7216222925288119041[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7216222925288119041[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7216222925288119041[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7216222925288119041[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7216222925288119041[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7216222925288119041[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7216222925288119041[53] = -9.8000000000000007*dt;
   out_7216222925288119041[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7216222925288119041[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7216222925288119041[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7216222925288119041[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7216222925288119041[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7216222925288119041[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7216222925288119041[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7216222925288119041[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7216222925288119041[62] = 0;
   out_7216222925288119041[63] = 0;
   out_7216222925288119041[64] = 0;
   out_7216222925288119041[65] = 0;
   out_7216222925288119041[66] = 0;
   out_7216222925288119041[67] = 0;
   out_7216222925288119041[68] = 0;
   out_7216222925288119041[69] = 0;
   out_7216222925288119041[70] = 1;
   out_7216222925288119041[71] = 0;
   out_7216222925288119041[72] = 0;
   out_7216222925288119041[73] = 0;
   out_7216222925288119041[74] = 0;
   out_7216222925288119041[75] = 0;
   out_7216222925288119041[76] = 0;
   out_7216222925288119041[77] = 0;
   out_7216222925288119041[78] = 0;
   out_7216222925288119041[79] = 0;
   out_7216222925288119041[80] = 1;
}
void h_25(double *state, double *unused, double *out_4164474996844747641) {
   out_4164474996844747641[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5139489071502763172) {
   out_5139489071502763172[0] = 0;
   out_5139489071502763172[1] = 0;
   out_5139489071502763172[2] = 0;
   out_5139489071502763172[3] = 0;
   out_5139489071502763172[4] = 0;
   out_5139489071502763172[5] = 0;
   out_5139489071502763172[6] = 1;
   out_5139489071502763172[7] = 0;
   out_5139489071502763172[8] = 0;
}
void h_24(double *state, double *unused, double *out_95925707150276311) {
   out_95925707150276311[0] = state[4];
   out_95925707150276311[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5536134375856622667) {
   out_5536134375856622667[0] = 0;
   out_5536134375856622667[1] = 0;
   out_5536134375856622667[2] = 0;
   out_5536134375856622667[3] = 0;
   out_5536134375856622667[4] = 1;
   out_5536134375856622667[5] = 0;
   out_5536134375856622667[6] = 0;
   out_5536134375856622667[7] = 0;
   out_5536134375856622667[8] = 0;
   out_5536134375856622667[9] = 0;
   out_5536134375856622667[10] = 0;
   out_5536134375856622667[11] = 0;
   out_5536134375856622667[12] = 0;
   out_5536134375856622667[13] = 0;
   out_5536134375856622667[14] = 1;
   out_5536134375856622667[15] = 0;
   out_5536134375856622667[16] = 0;
   out_5536134375856622667[17] = 0;
}
void h_30(double *state, double *unused, double *out_8659026724778372554) {
   out_8659026724778372554[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2621156112995514545) {
   out_2621156112995514545[0] = 0;
   out_2621156112995514545[1] = 0;
   out_2621156112995514545[2] = 0;
   out_2621156112995514545[3] = 0;
   out_2621156112995514545[4] = 1;
   out_2621156112995514545[5] = 0;
   out_2621156112995514545[6] = 0;
   out_2621156112995514545[7] = 0;
   out_2621156112995514545[8] = 0;
}
void h_26(double *state, double *unused, double *out_8055710840101895037) {
   out_8055710840101895037[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8880992390376819396) {
   out_8880992390376819396[0] = 0;
   out_8880992390376819396[1] = 0;
   out_8880992390376819396[2] = 0;
   out_8880992390376819396[3] = 0;
   out_8880992390376819396[4] = 0;
   out_8880992390376819396[5] = 0;
   out_8880992390376819396[6] = 0;
   out_8880992390376819396[7] = 1;
   out_8880992390376819396[8] = 0;
}
void h_27(double *state, double *unused, double *out_165755778877339066) {
   out_165755778877339066[0] = state[3];
}
void H_27(double *state, double *unused, double *out_397562041811571328) {
   out_397562041811571328[0] = 0;
   out_397562041811571328[1] = 0;
   out_397562041811571328[2] = 0;
   out_397562041811571328[3] = 1;
   out_397562041811571328[4] = 0;
   out_397562041811571328[5] = 0;
   out_397562041811571328[6] = 0;
   out_397562041811571328[7] = 0;
   out_397562041811571328[8] = 0;
}
void h_29(double *state, double *unused, double *out_7715516871876710119) {
   out_7715516871876710119[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2110924768681122361) {
   out_2110924768681122361[0] = 0;
   out_2110924768681122361[1] = 1;
   out_2110924768681122361[2] = 0;
   out_2110924768681122361[3] = 0;
   out_2110924768681122361[4] = 0;
   out_2110924768681122361[5] = 0;
   out_2110924768681122361[6] = 0;
   out_2110924768681122361[7] = 0;
   out_2110924768681122361[8] = 0;
}
void h_28(double *state, double *unused, double *out_4835917488783506579) {
   out_4835917488783506579[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7193323785750652935) {
   out_7193323785750652935[0] = 1;
   out_7193323785750652935[1] = 0;
   out_7193323785750652935[2] = 0;
   out_7193323785750652935[3] = 0;
   out_7193323785750652935[4] = 0;
   out_7193323785750652935[5] = 0;
   out_7193323785750652935[6] = 0;
   out_7193323785750652935[7] = 0;
   out_7193323785750652935[8] = 0;
}
void h_31(double *state, double *unused, double *out_3716797653909301544) {
   out_3716797653909301544[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5108843109625802744) {
   out_5108843109625802744[0] = 0;
   out_5108843109625802744[1] = 0;
   out_5108843109625802744[2] = 0;
   out_5108843109625802744[3] = 0;
   out_5108843109625802744[4] = 0;
   out_5108843109625802744[5] = 0;
   out_5108843109625802744[6] = 0;
   out_5108843109625802744[7] = 0;
   out_5108843109625802744[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6452236370958953739) {
  err_fun(nom_x, delta_x, out_6452236370958953739);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_1025168132938650359) {
  inv_err_fun(nom_x, true_x, out_1025168132938650359);
}
void car_H_mod_fun(double *state, double *out_3402141057055527033) {
  H_mod_fun(state, out_3402141057055527033);
}
void car_f_fun(double *state, double dt, double *out_193046874957989045) {
  f_fun(state,  dt, out_193046874957989045);
}
void car_F_fun(double *state, double dt, double *out_7216222925288119041) {
  F_fun(state,  dt, out_7216222925288119041);
}
void car_h_25(double *state, double *unused, double *out_4164474996844747641) {
  h_25(state, unused, out_4164474996844747641);
}
void car_H_25(double *state, double *unused, double *out_5139489071502763172) {
  H_25(state, unused, out_5139489071502763172);
}
void car_h_24(double *state, double *unused, double *out_95925707150276311) {
  h_24(state, unused, out_95925707150276311);
}
void car_H_24(double *state, double *unused, double *out_5536134375856622667) {
  H_24(state, unused, out_5536134375856622667);
}
void car_h_30(double *state, double *unused, double *out_8659026724778372554) {
  h_30(state, unused, out_8659026724778372554);
}
void car_H_30(double *state, double *unused, double *out_2621156112995514545) {
  H_30(state, unused, out_2621156112995514545);
}
void car_h_26(double *state, double *unused, double *out_8055710840101895037) {
  h_26(state, unused, out_8055710840101895037);
}
void car_H_26(double *state, double *unused, double *out_8880992390376819396) {
  H_26(state, unused, out_8880992390376819396);
}
void car_h_27(double *state, double *unused, double *out_165755778877339066) {
  h_27(state, unused, out_165755778877339066);
}
void car_H_27(double *state, double *unused, double *out_397562041811571328) {
  H_27(state, unused, out_397562041811571328);
}
void car_h_29(double *state, double *unused, double *out_7715516871876710119) {
  h_29(state, unused, out_7715516871876710119);
}
void car_H_29(double *state, double *unused, double *out_2110924768681122361) {
  H_29(state, unused, out_2110924768681122361);
}
void car_h_28(double *state, double *unused, double *out_4835917488783506579) {
  h_28(state, unused, out_4835917488783506579);
}
void car_H_28(double *state, double *unused, double *out_7193323785750652935) {
  H_28(state, unused, out_7193323785750652935);
}
void car_h_31(double *state, double *unused, double *out_3716797653909301544) {
  h_31(state, unused, out_3716797653909301544);
}
void car_H_31(double *state, double *unused, double *out_5108843109625802744) {
  H_31(state, unused, out_5108843109625802744);
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
