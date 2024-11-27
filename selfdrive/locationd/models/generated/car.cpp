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
void err_fun(double *nom_x, double *delta_x, double *out_477821258557534908) {
   out_477821258557534908[0] = delta_x[0] + nom_x[0];
   out_477821258557534908[1] = delta_x[1] + nom_x[1];
   out_477821258557534908[2] = delta_x[2] + nom_x[2];
   out_477821258557534908[3] = delta_x[3] + nom_x[3];
   out_477821258557534908[4] = delta_x[4] + nom_x[4];
   out_477821258557534908[5] = delta_x[5] + nom_x[5];
   out_477821258557534908[6] = delta_x[6] + nom_x[6];
   out_477821258557534908[7] = delta_x[7] + nom_x[7];
   out_477821258557534908[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7074898923826282794) {
   out_7074898923826282794[0] = -nom_x[0] + true_x[0];
   out_7074898923826282794[1] = -nom_x[1] + true_x[1];
   out_7074898923826282794[2] = -nom_x[2] + true_x[2];
   out_7074898923826282794[3] = -nom_x[3] + true_x[3];
   out_7074898923826282794[4] = -nom_x[4] + true_x[4];
   out_7074898923826282794[5] = -nom_x[5] + true_x[5];
   out_7074898923826282794[6] = -nom_x[6] + true_x[6];
   out_7074898923826282794[7] = -nom_x[7] + true_x[7];
   out_7074898923826282794[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3338767957256301619) {
   out_3338767957256301619[0] = 1.0;
   out_3338767957256301619[1] = 0;
   out_3338767957256301619[2] = 0;
   out_3338767957256301619[3] = 0;
   out_3338767957256301619[4] = 0;
   out_3338767957256301619[5] = 0;
   out_3338767957256301619[6] = 0;
   out_3338767957256301619[7] = 0;
   out_3338767957256301619[8] = 0;
   out_3338767957256301619[9] = 0;
   out_3338767957256301619[10] = 1.0;
   out_3338767957256301619[11] = 0;
   out_3338767957256301619[12] = 0;
   out_3338767957256301619[13] = 0;
   out_3338767957256301619[14] = 0;
   out_3338767957256301619[15] = 0;
   out_3338767957256301619[16] = 0;
   out_3338767957256301619[17] = 0;
   out_3338767957256301619[18] = 0;
   out_3338767957256301619[19] = 0;
   out_3338767957256301619[20] = 1.0;
   out_3338767957256301619[21] = 0;
   out_3338767957256301619[22] = 0;
   out_3338767957256301619[23] = 0;
   out_3338767957256301619[24] = 0;
   out_3338767957256301619[25] = 0;
   out_3338767957256301619[26] = 0;
   out_3338767957256301619[27] = 0;
   out_3338767957256301619[28] = 0;
   out_3338767957256301619[29] = 0;
   out_3338767957256301619[30] = 1.0;
   out_3338767957256301619[31] = 0;
   out_3338767957256301619[32] = 0;
   out_3338767957256301619[33] = 0;
   out_3338767957256301619[34] = 0;
   out_3338767957256301619[35] = 0;
   out_3338767957256301619[36] = 0;
   out_3338767957256301619[37] = 0;
   out_3338767957256301619[38] = 0;
   out_3338767957256301619[39] = 0;
   out_3338767957256301619[40] = 1.0;
   out_3338767957256301619[41] = 0;
   out_3338767957256301619[42] = 0;
   out_3338767957256301619[43] = 0;
   out_3338767957256301619[44] = 0;
   out_3338767957256301619[45] = 0;
   out_3338767957256301619[46] = 0;
   out_3338767957256301619[47] = 0;
   out_3338767957256301619[48] = 0;
   out_3338767957256301619[49] = 0;
   out_3338767957256301619[50] = 1.0;
   out_3338767957256301619[51] = 0;
   out_3338767957256301619[52] = 0;
   out_3338767957256301619[53] = 0;
   out_3338767957256301619[54] = 0;
   out_3338767957256301619[55] = 0;
   out_3338767957256301619[56] = 0;
   out_3338767957256301619[57] = 0;
   out_3338767957256301619[58] = 0;
   out_3338767957256301619[59] = 0;
   out_3338767957256301619[60] = 1.0;
   out_3338767957256301619[61] = 0;
   out_3338767957256301619[62] = 0;
   out_3338767957256301619[63] = 0;
   out_3338767957256301619[64] = 0;
   out_3338767957256301619[65] = 0;
   out_3338767957256301619[66] = 0;
   out_3338767957256301619[67] = 0;
   out_3338767957256301619[68] = 0;
   out_3338767957256301619[69] = 0;
   out_3338767957256301619[70] = 1.0;
   out_3338767957256301619[71] = 0;
   out_3338767957256301619[72] = 0;
   out_3338767957256301619[73] = 0;
   out_3338767957256301619[74] = 0;
   out_3338767957256301619[75] = 0;
   out_3338767957256301619[76] = 0;
   out_3338767957256301619[77] = 0;
   out_3338767957256301619[78] = 0;
   out_3338767957256301619[79] = 0;
   out_3338767957256301619[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8112854826897606143) {
   out_8112854826897606143[0] = state[0];
   out_8112854826897606143[1] = state[1];
   out_8112854826897606143[2] = state[2];
   out_8112854826897606143[3] = state[3];
   out_8112854826897606143[4] = state[4];
   out_8112854826897606143[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8112854826897606143[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8112854826897606143[7] = state[7];
   out_8112854826897606143[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7129573473174542401) {
   out_7129573473174542401[0] = 1;
   out_7129573473174542401[1] = 0;
   out_7129573473174542401[2] = 0;
   out_7129573473174542401[3] = 0;
   out_7129573473174542401[4] = 0;
   out_7129573473174542401[5] = 0;
   out_7129573473174542401[6] = 0;
   out_7129573473174542401[7] = 0;
   out_7129573473174542401[8] = 0;
   out_7129573473174542401[9] = 0;
   out_7129573473174542401[10] = 1;
   out_7129573473174542401[11] = 0;
   out_7129573473174542401[12] = 0;
   out_7129573473174542401[13] = 0;
   out_7129573473174542401[14] = 0;
   out_7129573473174542401[15] = 0;
   out_7129573473174542401[16] = 0;
   out_7129573473174542401[17] = 0;
   out_7129573473174542401[18] = 0;
   out_7129573473174542401[19] = 0;
   out_7129573473174542401[20] = 1;
   out_7129573473174542401[21] = 0;
   out_7129573473174542401[22] = 0;
   out_7129573473174542401[23] = 0;
   out_7129573473174542401[24] = 0;
   out_7129573473174542401[25] = 0;
   out_7129573473174542401[26] = 0;
   out_7129573473174542401[27] = 0;
   out_7129573473174542401[28] = 0;
   out_7129573473174542401[29] = 0;
   out_7129573473174542401[30] = 1;
   out_7129573473174542401[31] = 0;
   out_7129573473174542401[32] = 0;
   out_7129573473174542401[33] = 0;
   out_7129573473174542401[34] = 0;
   out_7129573473174542401[35] = 0;
   out_7129573473174542401[36] = 0;
   out_7129573473174542401[37] = 0;
   out_7129573473174542401[38] = 0;
   out_7129573473174542401[39] = 0;
   out_7129573473174542401[40] = 1;
   out_7129573473174542401[41] = 0;
   out_7129573473174542401[42] = 0;
   out_7129573473174542401[43] = 0;
   out_7129573473174542401[44] = 0;
   out_7129573473174542401[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7129573473174542401[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7129573473174542401[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7129573473174542401[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7129573473174542401[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7129573473174542401[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7129573473174542401[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7129573473174542401[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7129573473174542401[53] = -9.8000000000000007*dt;
   out_7129573473174542401[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7129573473174542401[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7129573473174542401[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7129573473174542401[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7129573473174542401[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7129573473174542401[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7129573473174542401[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7129573473174542401[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7129573473174542401[62] = 0;
   out_7129573473174542401[63] = 0;
   out_7129573473174542401[64] = 0;
   out_7129573473174542401[65] = 0;
   out_7129573473174542401[66] = 0;
   out_7129573473174542401[67] = 0;
   out_7129573473174542401[68] = 0;
   out_7129573473174542401[69] = 0;
   out_7129573473174542401[70] = 1;
   out_7129573473174542401[71] = 0;
   out_7129573473174542401[72] = 0;
   out_7129573473174542401[73] = 0;
   out_7129573473174542401[74] = 0;
   out_7129573473174542401[75] = 0;
   out_7129573473174542401[76] = 0;
   out_7129573473174542401[77] = 0;
   out_7129573473174542401[78] = 0;
   out_7129573473174542401[79] = 0;
   out_7129573473174542401[80] = 1;
}
void h_25(double *state, double *unused, double *out_3624028796782432856) {
   out_3624028796782432856[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4970485495288545423) {
   out_4970485495288545423[0] = 0;
   out_4970485495288545423[1] = 0;
   out_4970485495288545423[2] = 0;
   out_4970485495288545423[3] = 0;
   out_4970485495288545423[4] = 0;
   out_4970485495288545423[5] = 0;
   out_4970485495288545423[6] = 1;
   out_4970485495288545423[7] = 0;
   out_4970485495288545423[8] = 0;
}
void h_24(double *state, double *unused, double *out_911444303272325363) {
   out_911444303272325363[0] = state[4];
   out_911444303272325363[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8729749251454497159) {
   out_8729749251454497159[0] = 0;
   out_8729749251454497159[1] = 0;
   out_8729749251454497159[2] = 0;
   out_8729749251454497159[3] = 0;
   out_8729749251454497159[4] = 1;
   out_8729749251454497159[5] = 0;
   out_8729749251454497159[6] = 0;
   out_8729749251454497159[7] = 0;
   out_8729749251454497159[8] = 0;
   out_8729749251454497159[9] = 0;
   out_8729749251454497159[10] = 0;
   out_8729749251454497159[11] = 0;
   out_8729749251454497159[12] = 0;
   out_8729749251454497159[13] = 0;
   out_8729749251454497159[14] = 1;
   out_8729749251454497159[15] = 0;
   out_8729749251454497159[16] = 0;
   out_8729749251454497159[17] = 0;
}
void h_30(double *state, double *unused, double *out_7722332095061804720) {
   out_7722332095061804720[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1946204846203071332) {
   out_1946204846203071332[0] = 0;
   out_1946204846203071332[1] = 0;
   out_1946204846203071332[2] = 0;
   out_1946204846203071332[3] = 0;
   out_1946204846203071332[4] = 1;
   out_1946204846203071332[5] = 0;
   out_1946204846203071332[6] = 0;
   out_1946204846203071332[7] = 0;
   out_1946204846203071332[8] = 0;
}
void h_26(double *state, double *unused, double *out_4685546043617472035) {
   out_4685546043617472035[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8711988814162601647) {
   out_8711988814162601647[0] = 0;
   out_8711988814162601647[1] = 0;
   out_8711988814162601647[2] = 0;
   out_8711988814162601647[3] = 0;
   out_8711988814162601647[4] = 0;
   out_8711988814162601647[5] = 0;
   out_8711988814162601647[6] = 0;
   out_8711988814162601647[7] = 1;
   out_8711988814162601647[8] = 0;
}
void h_27(double *state, double *unused, double *out_4567538649684095291) {
   out_4567538649684095291[0] = state[3];
}
void H_27(double *state, double *unused, double *out_228558465597353579) {
   out_228558465597353579[0] = 0;
   out_228558465597353579[1] = 0;
   out_228558465597353579[2] = 0;
   out_228558465597353579[3] = 1;
   out_228558465597353579[4] = 0;
   out_228558465597353579[5] = 0;
   out_228558465597353579[6] = 0;
   out_228558465597353579[7] = 0;
   out_228558465597353579[8] = 0;
}
void h_29(double *state, double *unused, double *out_8665841947963467155) {
   out_8665841947963467155[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1941921192466904612) {
   out_1941921192466904612[0] = 0;
   out_1941921192466904612[1] = 1;
   out_1941921192466904612[2] = 0;
   out_1941921192466904612[3] = 0;
   out_1941921192466904612[4] = 0;
   out_1941921192466904612[5] = 0;
   out_1941921192466904612[6] = 0;
   out_1941921192466904612[7] = 0;
   out_1941921192466904612[8] = 0;
}
void h_28(double *state, double *unused, double *out_7604324701128427976) {
   out_7604324701128427976[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7024320209536435186) {
   out_7024320209536435186[0] = 1;
   out_7024320209536435186[1] = 0;
   out_7024320209536435186[2] = 0;
   out_7024320209536435186[3] = 0;
   out_7024320209536435186[4] = 0;
   out_7024320209536435186[5] = 0;
   out_7024320209536435186[6] = 0;
   out_7024320209536435186[7] = 0;
   out_7024320209536435186[8] = 0;
}
void h_31(double *state, double *unused, double *out_5446048596645078697) {
   out_5446048596645078697[0] = state[8];
}
void H_31(double *state, double *unused, double *out_4939839533411584995) {
   out_4939839533411584995[0] = 0;
   out_4939839533411584995[1] = 0;
   out_4939839533411584995[2] = 0;
   out_4939839533411584995[3] = 0;
   out_4939839533411584995[4] = 0;
   out_4939839533411584995[5] = 0;
   out_4939839533411584995[6] = 0;
   out_4939839533411584995[7] = 0;
   out_4939839533411584995[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_477821258557534908) {
  err_fun(nom_x, delta_x, out_477821258557534908);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7074898923826282794) {
  inv_err_fun(nom_x, true_x, out_7074898923826282794);
}
void car_H_mod_fun(double *state, double *out_3338767957256301619) {
  H_mod_fun(state, out_3338767957256301619);
}
void car_f_fun(double *state, double dt, double *out_8112854826897606143) {
  f_fun(state,  dt, out_8112854826897606143);
}
void car_F_fun(double *state, double dt, double *out_7129573473174542401) {
  F_fun(state,  dt, out_7129573473174542401);
}
void car_h_25(double *state, double *unused, double *out_3624028796782432856) {
  h_25(state, unused, out_3624028796782432856);
}
void car_H_25(double *state, double *unused, double *out_4970485495288545423) {
  H_25(state, unused, out_4970485495288545423);
}
void car_h_24(double *state, double *unused, double *out_911444303272325363) {
  h_24(state, unused, out_911444303272325363);
}
void car_H_24(double *state, double *unused, double *out_8729749251454497159) {
  H_24(state, unused, out_8729749251454497159);
}
void car_h_30(double *state, double *unused, double *out_7722332095061804720) {
  h_30(state, unused, out_7722332095061804720);
}
void car_H_30(double *state, double *unused, double *out_1946204846203071332) {
  H_30(state, unused, out_1946204846203071332);
}
void car_h_26(double *state, double *unused, double *out_4685546043617472035) {
  h_26(state, unused, out_4685546043617472035);
}
void car_H_26(double *state, double *unused, double *out_8711988814162601647) {
  H_26(state, unused, out_8711988814162601647);
}
void car_h_27(double *state, double *unused, double *out_4567538649684095291) {
  h_27(state, unused, out_4567538649684095291);
}
void car_H_27(double *state, double *unused, double *out_228558465597353579) {
  H_27(state, unused, out_228558465597353579);
}
void car_h_29(double *state, double *unused, double *out_8665841947963467155) {
  h_29(state, unused, out_8665841947963467155);
}
void car_H_29(double *state, double *unused, double *out_1941921192466904612) {
  H_29(state, unused, out_1941921192466904612);
}
void car_h_28(double *state, double *unused, double *out_7604324701128427976) {
  h_28(state, unused, out_7604324701128427976);
}
void car_H_28(double *state, double *unused, double *out_7024320209536435186) {
  H_28(state, unused, out_7024320209536435186);
}
void car_h_31(double *state, double *unused, double *out_5446048596645078697) {
  h_31(state, unused, out_5446048596645078697);
}
void car_H_31(double *state, double *unused, double *out_4939839533411584995) {
  H_31(state, unused, out_4939839533411584995);
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
