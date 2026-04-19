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
void err_fun(double *nom_x, double *delta_x, double *out_8963914457910857508) {
   out_8963914457910857508[0] = delta_x[0] + nom_x[0];
   out_8963914457910857508[1] = delta_x[1] + nom_x[1];
   out_8963914457910857508[2] = delta_x[2] + nom_x[2];
   out_8963914457910857508[3] = delta_x[3] + nom_x[3];
   out_8963914457910857508[4] = delta_x[4] + nom_x[4];
   out_8963914457910857508[5] = delta_x[5] + nom_x[5];
   out_8963914457910857508[6] = delta_x[6] + nom_x[6];
   out_8963914457910857508[7] = delta_x[7] + nom_x[7];
   out_8963914457910857508[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3690391334373159898) {
   out_3690391334373159898[0] = -nom_x[0] + true_x[0];
   out_3690391334373159898[1] = -nom_x[1] + true_x[1];
   out_3690391334373159898[2] = -nom_x[2] + true_x[2];
   out_3690391334373159898[3] = -nom_x[3] + true_x[3];
   out_3690391334373159898[4] = -nom_x[4] + true_x[4];
   out_3690391334373159898[5] = -nom_x[5] + true_x[5];
   out_3690391334373159898[6] = -nom_x[6] + true_x[6];
   out_3690391334373159898[7] = -nom_x[7] + true_x[7];
   out_3690391334373159898[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5320442536077183291) {
   out_5320442536077183291[0] = 1.0;
   out_5320442536077183291[1] = 0;
   out_5320442536077183291[2] = 0;
   out_5320442536077183291[3] = 0;
   out_5320442536077183291[4] = 0;
   out_5320442536077183291[5] = 0;
   out_5320442536077183291[6] = 0;
   out_5320442536077183291[7] = 0;
   out_5320442536077183291[8] = 0;
   out_5320442536077183291[9] = 0;
   out_5320442536077183291[10] = 1.0;
   out_5320442536077183291[11] = 0;
   out_5320442536077183291[12] = 0;
   out_5320442536077183291[13] = 0;
   out_5320442536077183291[14] = 0;
   out_5320442536077183291[15] = 0;
   out_5320442536077183291[16] = 0;
   out_5320442536077183291[17] = 0;
   out_5320442536077183291[18] = 0;
   out_5320442536077183291[19] = 0;
   out_5320442536077183291[20] = 1.0;
   out_5320442536077183291[21] = 0;
   out_5320442536077183291[22] = 0;
   out_5320442536077183291[23] = 0;
   out_5320442536077183291[24] = 0;
   out_5320442536077183291[25] = 0;
   out_5320442536077183291[26] = 0;
   out_5320442536077183291[27] = 0;
   out_5320442536077183291[28] = 0;
   out_5320442536077183291[29] = 0;
   out_5320442536077183291[30] = 1.0;
   out_5320442536077183291[31] = 0;
   out_5320442536077183291[32] = 0;
   out_5320442536077183291[33] = 0;
   out_5320442536077183291[34] = 0;
   out_5320442536077183291[35] = 0;
   out_5320442536077183291[36] = 0;
   out_5320442536077183291[37] = 0;
   out_5320442536077183291[38] = 0;
   out_5320442536077183291[39] = 0;
   out_5320442536077183291[40] = 1.0;
   out_5320442536077183291[41] = 0;
   out_5320442536077183291[42] = 0;
   out_5320442536077183291[43] = 0;
   out_5320442536077183291[44] = 0;
   out_5320442536077183291[45] = 0;
   out_5320442536077183291[46] = 0;
   out_5320442536077183291[47] = 0;
   out_5320442536077183291[48] = 0;
   out_5320442536077183291[49] = 0;
   out_5320442536077183291[50] = 1.0;
   out_5320442536077183291[51] = 0;
   out_5320442536077183291[52] = 0;
   out_5320442536077183291[53] = 0;
   out_5320442536077183291[54] = 0;
   out_5320442536077183291[55] = 0;
   out_5320442536077183291[56] = 0;
   out_5320442536077183291[57] = 0;
   out_5320442536077183291[58] = 0;
   out_5320442536077183291[59] = 0;
   out_5320442536077183291[60] = 1.0;
   out_5320442536077183291[61] = 0;
   out_5320442536077183291[62] = 0;
   out_5320442536077183291[63] = 0;
   out_5320442536077183291[64] = 0;
   out_5320442536077183291[65] = 0;
   out_5320442536077183291[66] = 0;
   out_5320442536077183291[67] = 0;
   out_5320442536077183291[68] = 0;
   out_5320442536077183291[69] = 0;
   out_5320442536077183291[70] = 1.0;
   out_5320442536077183291[71] = 0;
   out_5320442536077183291[72] = 0;
   out_5320442536077183291[73] = 0;
   out_5320442536077183291[74] = 0;
   out_5320442536077183291[75] = 0;
   out_5320442536077183291[76] = 0;
   out_5320442536077183291[77] = 0;
   out_5320442536077183291[78] = 0;
   out_5320442536077183291[79] = 0;
   out_5320442536077183291[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3215647447738557253) {
   out_3215647447738557253[0] = state[0];
   out_3215647447738557253[1] = state[1];
   out_3215647447738557253[2] = state[2];
   out_3215647447738557253[3] = state[3];
   out_3215647447738557253[4] = state[4];
   out_3215647447738557253[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3215647447738557253[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3215647447738557253[7] = state[7];
   out_3215647447738557253[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8370961493089902910) {
   out_8370961493089902910[0] = 1;
   out_8370961493089902910[1] = 0;
   out_8370961493089902910[2] = 0;
   out_8370961493089902910[3] = 0;
   out_8370961493089902910[4] = 0;
   out_8370961493089902910[5] = 0;
   out_8370961493089902910[6] = 0;
   out_8370961493089902910[7] = 0;
   out_8370961493089902910[8] = 0;
   out_8370961493089902910[9] = 0;
   out_8370961493089902910[10] = 1;
   out_8370961493089902910[11] = 0;
   out_8370961493089902910[12] = 0;
   out_8370961493089902910[13] = 0;
   out_8370961493089902910[14] = 0;
   out_8370961493089902910[15] = 0;
   out_8370961493089902910[16] = 0;
   out_8370961493089902910[17] = 0;
   out_8370961493089902910[18] = 0;
   out_8370961493089902910[19] = 0;
   out_8370961493089902910[20] = 1;
   out_8370961493089902910[21] = 0;
   out_8370961493089902910[22] = 0;
   out_8370961493089902910[23] = 0;
   out_8370961493089902910[24] = 0;
   out_8370961493089902910[25] = 0;
   out_8370961493089902910[26] = 0;
   out_8370961493089902910[27] = 0;
   out_8370961493089902910[28] = 0;
   out_8370961493089902910[29] = 0;
   out_8370961493089902910[30] = 1;
   out_8370961493089902910[31] = 0;
   out_8370961493089902910[32] = 0;
   out_8370961493089902910[33] = 0;
   out_8370961493089902910[34] = 0;
   out_8370961493089902910[35] = 0;
   out_8370961493089902910[36] = 0;
   out_8370961493089902910[37] = 0;
   out_8370961493089902910[38] = 0;
   out_8370961493089902910[39] = 0;
   out_8370961493089902910[40] = 1;
   out_8370961493089902910[41] = 0;
   out_8370961493089902910[42] = 0;
   out_8370961493089902910[43] = 0;
   out_8370961493089902910[44] = 0;
   out_8370961493089902910[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8370961493089902910[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8370961493089902910[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8370961493089902910[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8370961493089902910[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8370961493089902910[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8370961493089902910[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8370961493089902910[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8370961493089902910[53] = -9.8000000000000007*dt;
   out_8370961493089902910[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8370961493089902910[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8370961493089902910[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8370961493089902910[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8370961493089902910[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8370961493089902910[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8370961493089902910[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8370961493089902910[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8370961493089902910[62] = 0;
   out_8370961493089902910[63] = 0;
   out_8370961493089902910[64] = 0;
   out_8370961493089902910[65] = 0;
   out_8370961493089902910[66] = 0;
   out_8370961493089902910[67] = 0;
   out_8370961493089902910[68] = 0;
   out_8370961493089902910[69] = 0;
   out_8370961493089902910[70] = 1;
   out_8370961493089902910[71] = 0;
   out_8370961493089902910[72] = 0;
   out_8370961493089902910[73] = 0;
   out_8370961493089902910[74] = 0;
   out_8370961493089902910[75] = 0;
   out_8370961493089902910[76] = 0;
   out_8370961493089902910[77] = 0;
   out_8370961493089902910[78] = 0;
   out_8370961493089902910[79] = 0;
   out_8370961493089902910[80] = 1;
}
void h_25(double *state, double *unused, double *out_3308608408930185204) {
   out_3308608408930185204[0] = state[6];
}
void H_25(double *state, double *unused, double *out_3023921450234221662) {
   out_3023921450234221662[0] = 0;
   out_3023921450234221662[1] = 0;
   out_3023921450234221662[2] = 0;
   out_3023921450234221662[3] = 0;
   out_3023921450234221662[4] = 0;
   out_3023921450234221662[5] = 0;
   out_3023921450234221662[6] = 1;
   out_3023921450234221662[7] = 0;
   out_3023921450234221662[8] = 0;
}
void h_24(double *state, double *unused, double *out_8414429955721093303) {
   out_8414429955721093303[0] = state[4];
   out_8414429955721093303[1] = state[5];
}
void H_24(double *state, double *unused, double *out_851271851228722096) {
   out_851271851228722096[0] = 0;
   out_851271851228722096[1] = 0;
   out_851271851228722096[2] = 0;
   out_851271851228722096[3] = 0;
   out_851271851228722096[4] = 1;
   out_851271851228722096[5] = 0;
   out_851271851228722096[6] = 0;
   out_851271851228722096[7] = 0;
   out_851271851228722096[8] = 0;
   out_851271851228722096[9] = 0;
   out_851271851228722096[10] = 0;
   out_851271851228722096[11] = 0;
   out_851271851228722096[12] = 0;
   out_851271851228722096[13] = 0;
   out_851271851228722096[14] = 1;
   out_851271851228722096[15] = 0;
   out_851271851228722096[16] = 0;
   out_851271851228722096[17] = 0;
}
void h_30(double *state, double *unused, double *out_7245196169894843053) {
   out_7245196169894843053[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1503774879893386536) {
   out_1503774879893386536[0] = 0;
   out_1503774879893386536[1] = 0;
   out_1503774879893386536[2] = 0;
   out_1503774879893386536[3] = 0;
   out_1503774879893386536[4] = 1;
   out_1503774879893386536[5] = 0;
   out_1503774879893386536[6] = 0;
   out_1503774879893386536[7] = 0;
   out_1503774879893386536[8] = 0;
}
void h_26(double *state, double *unused, double *out_1496584920399978883) {
   out_1496584920399978883[0] = state[7];
}
void H_26(double *state, double *unused, double *out_717581868639834562) {
   out_717581868639834562[0] = 0;
   out_717581868639834562[1] = 0;
   out_717581868639834562[2] = 0;
   out_717581868639834562[3] = 0;
   out_717581868639834562[4] = 0;
   out_717581868639834562[5] = 0;
   out_717581868639834562[6] = 0;
   out_717581868639834562[7] = 1;
   out_717581868639834562[8] = 0;
}
void h_27(double *state, double *unused, double *out_6121160512200038587) {
   out_6121160512200038587[0] = state[3];
}
void H_27(double *state, double *unused, double *out_719819191290556681) {
   out_719819191290556681[0] = 0;
   out_719819191290556681[1] = 0;
   out_719819191290556681[2] = 0;
   out_719819191290556681[3] = 1;
   out_719819191290556681[4] = 0;
   out_719819191290556681[5] = 0;
   out_719819191290556681[6] = 0;
   out_719819191290556681[7] = 0;
   out_719819191290556681[8] = 0;
}
void h_29(double *state, double *unused, double *out_6199874636153862918) {
   out_6199874636153862918[0] = state[1];
}
void H_29(double *state, double *unused, double *out_993543535578994352) {
   out_993543535578994352[0] = 0;
   out_993543535578994352[1] = 1;
   out_993543535578994352[2] = 0;
   out_993543535578994352[3] = 0;
   out_993543535578994352[4] = 0;
   out_993543535578994352[5] = 0;
   out_993543535578994352[6] = 0;
   out_993543535578994352[7] = 0;
   out_993543535578994352[8] = 0;
}
void h_28(double *state, double *unused, double *out_1119487244539192942) {
   out_1119487244539192942[0] = state[0];
}
void H_28(double *state, double *unused, double *out_970086735986331899) {
   out_970086735986331899[0] = 1;
   out_970086735986331899[1] = 0;
   out_970086735986331899[2] = 0;
   out_970086735986331899[3] = 0;
   out_970086735986331899[4] = 0;
   out_970086735986331899[5] = 0;
   out_970086735986331899[6] = 0;
   out_970086735986331899[7] = 0;
   out_970086735986331899[8] = 0;
}
void h_31(double *state, double *unused, double *out_3583802471214691093) {
   out_3583802471214691093[0] = state[8];
}
void H_31(double *state, double *unused, double *out_3054567412111182090) {
   out_3054567412111182090[0] = 0;
   out_3054567412111182090[1] = 0;
   out_3054567412111182090[2] = 0;
   out_3054567412111182090[3] = 0;
   out_3054567412111182090[4] = 0;
   out_3054567412111182090[5] = 0;
   out_3054567412111182090[6] = 0;
   out_3054567412111182090[7] = 0;
   out_3054567412111182090[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8963914457910857508) {
  err_fun(nom_x, delta_x, out_8963914457910857508);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3690391334373159898) {
  inv_err_fun(nom_x, true_x, out_3690391334373159898);
}
void car_H_mod_fun(double *state, double *out_5320442536077183291) {
  H_mod_fun(state, out_5320442536077183291);
}
void car_f_fun(double *state, double dt, double *out_3215647447738557253) {
  f_fun(state,  dt, out_3215647447738557253);
}
void car_F_fun(double *state, double dt, double *out_8370961493089902910) {
  F_fun(state,  dt, out_8370961493089902910);
}
void car_h_25(double *state, double *unused, double *out_3308608408930185204) {
  h_25(state, unused, out_3308608408930185204);
}
void car_H_25(double *state, double *unused, double *out_3023921450234221662) {
  H_25(state, unused, out_3023921450234221662);
}
void car_h_24(double *state, double *unused, double *out_8414429955721093303) {
  h_24(state, unused, out_8414429955721093303);
}
void car_H_24(double *state, double *unused, double *out_851271851228722096) {
  H_24(state, unused, out_851271851228722096);
}
void car_h_30(double *state, double *unused, double *out_7245196169894843053) {
  h_30(state, unused, out_7245196169894843053);
}
void car_H_30(double *state, double *unused, double *out_1503774879893386536) {
  H_30(state, unused, out_1503774879893386536);
}
void car_h_26(double *state, double *unused, double *out_1496584920399978883) {
  h_26(state, unused, out_1496584920399978883);
}
void car_H_26(double *state, double *unused, double *out_717581868639834562) {
  H_26(state, unused, out_717581868639834562);
}
void car_h_27(double *state, double *unused, double *out_6121160512200038587) {
  h_27(state, unused, out_6121160512200038587);
}
void car_H_27(double *state, double *unused, double *out_719819191290556681) {
  H_27(state, unused, out_719819191290556681);
}
void car_h_29(double *state, double *unused, double *out_6199874636153862918) {
  h_29(state, unused, out_6199874636153862918);
}
void car_H_29(double *state, double *unused, double *out_993543535578994352) {
  H_29(state, unused, out_993543535578994352);
}
void car_h_28(double *state, double *unused, double *out_1119487244539192942) {
  h_28(state, unused, out_1119487244539192942);
}
void car_H_28(double *state, double *unused, double *out_970086735986331899) {
  H_28(state, unused, out_970086735986331899);
}
void car_h_31(double *state, double *unused, double *out_3583802471214691093) {
  h_31(state, unused, out_3583802471214691093);
}
void car_H_31(double *state, double *unused, double *out_3054567412111182090) {
  H_31(state, unused, out_3054567412111182090);
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
