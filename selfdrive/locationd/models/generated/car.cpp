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
void err_fun(double *nom_x, double *delta_x, double *out_9032575281006097975) {
   out_9032575281006097975[0] = delta_x[0] + nom_x[0];
   out_9032575281006097975[1] = delta_x[1] + nom_x[1];
   out_9032575281006097975[2] = delta_x[2] + nom_x[2];
   out_9032575281006097975[3] = delta_x[3] + nom_x[3];
   out_9032575281006097975[4] = delta_x[4] + nom_x[4];
   out_9032575281006097975[5] = delta_x[5] + nom_x[5];
   out_9032575281006097975[6] = delta_x[6] + nom_x[6];
   out_9032575281006097975[7] = delta_x[7] + nom_x[7];
   out_9032575281006097975[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4162568133862027595) {
   out_4162568133862027595[0] = -nom_x[0] + true_x[0];
   out_4162568133862027595[1] = -nom_x[1] + true_x[1];
   out_4162568133862027595[2] = -nom_x[2] + true_x[2];
   out_4162568133862027595[3] = -nom_x[3] + true_x[3];
   out_4162568133862027595[4] = -nom_x[4] + true_x[4];
   out_4162568133862027595[5] = -nom_x[5] + true_x[5];
   out_4162568133862027595[6] = -nom_x[6] + true_x[6];
   out_4162568133862027595[7] = -nom_x[7] + true_x[7];
   out_4162568133862027595[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3603539019866225341) {
   out_3603539019866225341[0] = 1.0;
   out_3603539019866225341[1] = 0;
   out_3603539019866225341[2] = 0;
   out_3603539019866225341[3] = 0;
   out_3603539019866225341[4] = 0;
   out_3603539019866225341[5] = 0;
   out_3603539019866225341[6] = 0;
   out_3603539019866225341[7] = 0;
   out_3603539019866225341[8] = 0;
   out_3603539019866225341[9] = 0;
   out_3603539019866225341[10] = 1.0;
   out_3603539019866225341[11] = 0;
   out_3603539019866225341[12] = 0;
   out_3603539019866225341[13] = 0;
   out_3603539019866225341[14] = 0;
   out_3603539019866225341[15] = 0;
   out_3603539019866225341[16] = 0;
   out_3603539019866225341[17] = 0;
   out_3603539019866225341[18] = 0;
   out_3603539019866225341[19] = 0;
   out_3603539019866225341[20] = 1.0;
   out_3603539019866225341[21] = 0;
   out_3603539019866225341[22] = 0;
   out_3603539019866225341[23] = 0;
   out_3603539019866225341[24] = 0;
   out_3603539019866225341[25] = 0;
   out_3603539019866225341[26] = 0;
   out_3603539019866225341[27] = 0;
   out_3603539019866225341[28] = 0;
   out_3603539019866225341[29] = 0;
   out_3603539019866225341[30] = 1.0;
   out_3603539019866225341[31] = 0;
   out_3603539019866225341[32] = 0;
   out_3603539019866225341[33] = 0;
   out_3603539019866225341[34] = 0;
   out_3603539019866225341[35] = 0;
   out_3603539019866225341[36] = 0;
   out_3603539019866225341[37] = 0;
   out_3603539019866225341[38] = 0;
   out_3603539019866225341[39] = 0;
   out_3603539019866225341[40] = 1.0;
   out_3603539019866225341[41] = 0;
   out_3603539019866225341[42] = 0;
   out_3603539019866225341[43] = 0;
   out_3603539019866225341[44] = 0;
   out_3603539019866225341[45] = 0;
   out_3603539019866225341[46] = 0;
   out_3603539019866225341[47] = 0;
   out_3603539019866225341[48] = 0;
   out_3603539019866225341[49] = 0;
   out_3603539019866225341[50] = 1.0;
   out_3603539019866225341[51] = 0;
   out_3603539019866225341[52] = 0;
   out_3603539019866225341[53] = 0;
   out_3603539019866225341[54] = 0;
   out_3603539019866225341[55] = 0;
   out_3603539019866225341[56] = 0;
   out_3603539019866225341[57] = 0;
   out_3603539019866225341[58] = 0;
   out_3603539019866225341[59] = 0;
   out_3603539019866225341[60] = 1.0;
   out_3603539019866225341[61] = 0;
   out_3603539019866225341[62] = 0;
   out_3603539019866225341[63] = 0;
   out_3603539019866225341[64] = 0;
   out_3603539019866225341[65] = 0;
   out_3603539019866225341[66] = 0;
   out_3603539019866225341[67] = 0;
   out_3603539019866225341[68] = 0;
   out_3603539019866225341[69] = 0;
   out_3603539019866225341[70] = 1.0;
   out_3603539019866225341[71] = 0;
   out_3603539019866225341[72] = 0;
   out_3603539019866225341[73] = 0;
   out_3603539019866225341[74] = 0;
   out_3603539019866225341[75] = 0;
   out_3603539019866225341[76] = 0;
   out_3603539019866225341[77] = 0;
   out_3603539019866225341[78] = 0;
   out_3603539019866225341[79] = 0;
   out_3603539019866225341[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5409019209530353296) {
   out_5409019209530353296[0] = state[0];
   out_5409019209530353296[1] = state[1];
   out_5409019209530353296[2] = state[2];
   out_5409019209530353296[3] = state[3];
   out_5409019209530353296[4] = state[4];
   out_5409019209530353296[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5409019209530353296[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5409019209530353296[7] = state[7];
   out_5409019209530353296[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2386433830752924235) {
   out_2386433830752924235[0] = 1;
   out_2386433830752924235[1] = 0;
   out_2386433830752924235[2] = 0;
   out_2386433830752924235[3] = 0;
   out_2386433830752924235[4] = 0;
   out_2386433830752924235[5] = 0;
   out_2386433830752924235[6] = 0;
   out_2386433830752924235[7] = 0;
   out_2386433830752924235[8] = 0;
   out_2386433830752924235[9] = 0;
   out_2386433830752924235[10] = 1;
   out_2386433830752924235[11] = 0;
   out_2386433830752924235[12] = 0;
   out_2386433830752924235[13] = 0;
   out_2386433830752924235[14] = 0;
   out_2386433830752924235[15] = 0;
   out_2386433830752924235[16] = 0;
   out_2386433830752924235[17] = 0;
   out_2386433830752924235[18] = 0;
   out_2386433830752924235[19] = 0;
   out_2386433830752924235[20] = 1;
   out_2386433830752924235[21] = 0;
   out_2386433830752924235[22] = 0;
   out_2386433830752924235[23] = 0;
   out_2386433830752924235[24] = 0;
   out_2386433830752924235[25] = 0;
   out_2386433830752924235[26] = 0;
   out_2386433830752924235[27] = 0;
   out_2386433830752924235[28] = 0;
   out_2386433830752924235[29] = 0;
   out_2386433830752924235[30] = 1;
   out_2386433830752924235[31] = 0;
   out_2386433830752924235[32] = 0;
   out_2386433830752924235[33] = 0;
   out_2386433830752924235[34] = 0;
   out_2386433830752924235[35] = 0;
   out_2386433830752924235[36] = 0;
   out_2386433830752924235[37] = 0;
   out_2386433830752924235[38] = 0;
   out_2386433830752924235[39] = 0;
   out_2386433830752924235[40] = 1;
   out_2386433830752924235[41] = 0;
   out_2386433830752924235[42] = 0;
   out_2386433830752924235[43] = 0;
   out_2386433830752924235[44] = 0;
   out_2386433830752924235[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2386433830752924235[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2386433830752924235[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2386433830752924235[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2386433830752924235[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2386433830752924235[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2386433830752924235[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2386433830752924235[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2386433830752924235[53] = -9.8000000000000007*dt;
   out_2386433830752924235[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2386433830752924235[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2386433830752924235[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2386433830752924235[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2386433830752924235[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2386433830752924235[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2386433830752924235[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2386433830752924235[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2386433830752924235[62] = 0;
   out_2386433830752924235[63] = 0;
   out_2386433830752924235[64] = 0;
   out_2386433830752924235[65] = 0;
   out_2386433830752924235[66] = 0;
   out_2386433830752924235[67] = 0;
   out_2386433830752924235[68] = 0;
   out_2386433830752924235[69] = 0;
   out_2386433830752924235[70] = 1;
   out_2386433830752924235[71] = 0;
   out_2386433830752924235[72] = 0;
   out_2386433830752924235[73] = 0;
   out_2386433830752924235[74] = 0;
   out_2386433830752924235[75] = 0;
   out_2386433830752924235[76] = 0;
   out_2386433830752924235[77] = 0;
   out_2386433830752924235[78] = 0;
   out_2386433830752924235[79] = 0;
   out_2386433830752924235[80] = 1;
}
void h_25(double *state, double *unused, double *out_5285741759795184208) {
   out_5285741759795184208[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1723570984606697899) {
   out_1723570984606697899[0] = 0;
   out_1723570984606697899[1] = 0;
   out_1723570984606697899[2] = 0;
   out_1723570984606697899[3] = 0;
   out_1723570984606697899[4] = 0;
   out_1723570984606697899[5] = 0;
   out_1723570984606697899[6] = 1;
   out_1723570984606697899[7] = 0;
   out_1723570984606697899[8] = 0;
}
void h_24(double *state, double *unused, double *out_8464137135750232912) {
   out_8464137135750232912[0] = state[4];
   out_8464137135750232912[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7495107903033658492) {
   out_7495107903033658492[0] = 0;
   out_7495107903033658492[1] = 0;
   out_7495107903033658492[2] = 0;
   out_7495107903033658492[3] = 0;
   out_7495107903033658492[4] = 1;
   out_7495107903033658492[5] = 0;
   out_7495107903033658492[6] = 0;
   out_7495107903033658492[7] = 0;
   out_7495107903033658492[8] = 0;
   out_7495107903033658492[9] = 0;
   out_7495107903033658492[10] = 0;
   out_7495107903033658492[11] = 0;
   out_7495107903033658492[12] = 0;
   out_7495107903033658492[13] = 0;
   out_7495107903033658492[14] = 1;
   out_7495107903033658492[15] = 0;
   out_7495107903033658492[16] = 0;
   out_7495107903033658492[17] = 0;
}
void h_30(double *state, double *unused, double *out_4455696711267883607) {
   out_4455696711267883607[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2804125345520910299) {
   out_2804125345520910299[0] = 0;
   out_2804125345520910299[1] = 0;
   out_2804125345520910299[2] = 0;
   out_2804125345520910299[3] = 0;
   out_2804125345520910299[4] = 1;
   out_2804125345520910299[5] = 0;
   out_2804125345520910299[6] = 0;
   out_2804125345520910299[7] = 0;
   out_2804125345520910299[8] = 0;
}
void h_26(double *state, double *unused, double *out_815189473444334289) {
   out_815189473444334289[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2017932334267358325) {
   out_2017932334267358325[0] = 0;
   out_2017932334267358325[1] = 0;
   out_2017932334267358325[2] = 0;
   out_2017932334267358325[3] = 0;
   out_2017932334267358325[4] = 0;
   out_2017932334267358325[5] = 0;
   out_2017932334267358325[6] = 0;
   out_2017932334267358325[7] = 1;
   out_2017932334267358325[8] = 0;
}
void h_27(double *state, double *unused, double *out_8763050232632738396) {
   out_8763050232632738396[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4978888657321335210) {
   out_4978888657321335210[0] = 0;
   out_4978888657321335210[1] = 0;
   out_4978888657321335210[2] = 0;
   out_4978888657321335210[3] = 1;
   out_4978888657321335210[4] = 0;
   out_4978888657321335210[5] = 0;
   out_4978888657321335210[6] = 0;
   out_4978888657321335210[7] = 0;
   out_4978888657321335210[8] = 0;
}
void h_29(double *state, double *unused, double *out_1790754346192289861) {
   out_1790754346192289861[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2293894001206518115) {
   out_2293894001206518115[0] = 0;
   out_2293894001206518115[1] = 1;
   out_2293894001206518115[2] = 0;
   out_2293894001206518115[3] = 0;
   out_2293894001206518115[4] = 0;
   out_2293894001206518115[5] = 0;
   out_2293894001206518115[6] = 0;
   out_2293894001206518115[7] = 0;
   out_2293894001206518115[8] = 0;
}
void h_28(double *state, double *unused, double *out_60668065649861265) {
   out_60668065649861265[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7376293018276048689) {
   out_7376293018276048689[0] = 1;
   out_7376293018276048689[1] = 0;
   out_7376293018276048689[2] = 0;
   out_7376293018276048689[3] = 0;
   out_7376293018276048689[4] = 0;
   out_7376293018276048689[5] = 0;
   out_7376293018276048689[6] = 0;
   out_7376293018276048689[7] = 0;
   out_7376293018276048689[8] = 0;
}
void h_31(double *state, double *unused, double *out_3765769907711350496) {
   out_3765769907711350496[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2644140436500709801) {
   out_2644140436500709801[0] = 0;
   out_2644140436500709801[1] = 0;
   out_2644140436500709801[2] = 0;
   out_2644140436500709801[3] = 0;
   out_2644140436500709801[4] = 0;
   out_2644140436500709801[5] = 0;
   out_2644140436500709801[6] = 0;
   out_2644140436500709801[7] = 0;
   out_2644140436500709801[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_9032575281006097975) {
  err_fun(nom_x, delta_x, out_9032575281006097975);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4162568133862027595) {
  inv_err_fun(nom_x, true_x, out_4162568133862027595);
}
void car_H_mod_fun(double *state, double *out_3603539019866225341) {
  H_mod_fun(state, out_3603539019866225341);
}
void car_f_fun(double *state, double dt, double *out_5409019209530353296) {
  f_fun(state,  dt, out_5409019209530353296);
}
void car_F_fun(double *state, double dt, double *out_2386433830752924235) {
  F_fun(state,  dt, out_2386433830752924235);
}
void car_h_25(double *state, double *unused, double *out_5285741759795184208) {
  h_25(state, unused, out_5285741759795184208);
}
void car_H_25(double *state, double *unused, double *out_1723570984606697899) {
  H_25(state, unused, out_1723570984606697899);
}
void car_h_24(double *state, double *unused, double *out_8464137135750232912) {
  h_24(state, unused, out_8464137135750232912);
}
void car_H_24(double *state, double *unused, double *out_7495107903033658492) {
  H_24(state, unused, out_7495107903033658492);
}
void car_h_30(double *state, double *unused, double *out_4455696711267883607) {
  h_30(state, unused, out_4455696711267883607);
}
void car_H_30(double *state, double *unused, double *out_2804125345520910299) {
  H_30(state, unused, out_2804125345520910299);
}
void car_h_26(double *state, double *unused, double *out_815189473444334289) {
  h_26(state, unused, out_815189473444334289);
}
void car_H_26(double *state, double *unused, double *out_2017932334267358325) {
  H_26(state, unused, out_2017932334267358325);
}
void car_h_27(double *state, double *unused, double *out_8763050232632738396) {
  h_27(state, unused, out_8763050232632738396);
}
void car_H_27(double *state, double *unused, double *out_4978888657321335210) {
  H_27(state, unused, out_4978888657321335210);
}
void car_h_29(double *state, double *unused, double *out_1790754346192289861) {
  h_29(state, unused, out_1790754346192289861);
}
void car_H_29(double *state, double *unused, double *out_2293894001206518115) {
  H_29(state, unused, out_2293894001206518115);
}
void car_h_28(double *state, double *unused, double *out_60668065649861265) {
  h_28(state, unused, out_60668065649861265);
}
void car_H_28(double *state, double *unused, double *out_7376293018276048689) {
  H_28(state, unused, out_7376293018276048689);
}
void car_h_31(double *state, double *unused, double *out_3765769907711350496) {
  h_31(state, unused, out_3765769907711350496);
}
void car_H_31(double *state, double *unused, double *out_2644140436500709801) {
  H_31(state, unused, out_2644140436500709801);
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
