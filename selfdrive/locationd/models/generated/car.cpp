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
void err_fun(double *nom_x, double *delta_x, double *out_6320531096693148158) {
   out_6320531096693148158[0] = delta_x[0] + nom_x[0];
   out_6320531096693148158[1] = delta_x[1] + nom_x[1];
   out_6320531096693148158[2] = delta_x[2] + nom_x[2];
   out_6320531096693148158[3] = delta_x[3] + nom_x[3];
   out_6320531096693148158[4] = delta_x[4] + nom_x[4];
   out_6320531096693148158[5] = delta_x[5] + nom_x[5];
   out_6320531096693148158[6] = delta_x[6] + nom_x[6];
   out_6320531096693148158[7] = delta_x[7] + nom_x[7];
   out_6320531096693148158[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5645716242889632752) {
   out_5645716242889632752[0] = -nom_x[0] + true_x[0];
   out_5645716242889632752[1] = -nom_x[1] + true_x[1];
   out_5645716242889632752[2] = -nom_x[2] + true_x[2];
   out_5645716242889632752[3] = -nom_x[3] + true_x[3];
   out_5645716242889632752[4] = -nom_x[4] + true_x[4];
   out_5645716242889632752[5] = -nom_x[5] + true_x[5];
   out_5645716242889632752[6] = -nom_x[6] + true_x[6];
   out_5645716242889632752[7] = -nom_x[7] + true_x[7];
   out_5645716242889632752[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2845650287939090092) {
   out_2845650287939090092[0] = 1.0;
   out_2845650287939090092[1] = 0;
   out_2845650287939090092[2] = 0;
   out_2845650287939090092[3] = 0;
   out_2845650287939090092[4] = 0;
   out_2845650287939090092[5] = 0;
   out_2845650287939090092[6] = 0;
   out_2845650287939090092[7] = 0;
   out_2845650287939090092[8] = 0;
   out_2845650287939090092[9] = 0;
   out_2845650287939090092[10] = 1.0;
   out_2845650287939090092[11] = 0;
   out_2845650287939090092[12] = 0;
   out_2845650287939090092[13] = 0;
   out_2845650287939090092[14] = 0;
   out_2845650287939090092[15] = 0;
   out_2845650287939090092[16] = 0;
   out_2845650287939090092[17] = 0;
   out_2845650287939090092[18] = 0;
   out_2845650287939090092[19] = 0;
   out_2845650287939090092[20] = 1.0;
   out_2845650287939090092[21] = 0;
   out_2845650287939090092[22] = 0;
   out_2845650287939090092[23] = 0;
   out_2845650287939090092[24] = 0;
   out_2845650287939090092[25] = 0;
   out_2845650287939090092[26] = 0;
   out_2845650287939090092[27] = 0;
   out_2845650287939090092[28] = 0;
   out_2845650287939090092[29] = 0;
   out_2845650287939090092[30] = 1.0;
   out_2845650287939090092[31] = 0;
   out_2845650287939090092[32] = 0;
   out_2845650287939090092[33] = 0;
   out_2845650287939090092[34] = 0;
   out_2845650287939090092[35] = 0;
   out_2845650287939090092[36] = 0;
   out_2845650287939090092[37] = 0;
   out_2845650287939090092[38] = 0;
   out_2845650287939090092[39] = 0;
   out_2845650287939090092[40] = 1.0;
   out_2845650287939090092[41] = 0;
   out_2845650287939090092[42] = 0;
   out_2845650287939090092[43] = 0;
   out_2845650287939090092[44] = 0;
   out_2845650287939090092[45] = 0;
   out_2845650287939090092[46] = 0;
   out_2845650287939090092[47] = 0;
   out_2845650287939090092[48] = 0;
   out_2845650287939090092[49] = 0;
   out_2845650287939090092[50] = 1.0;
   out_2845650287939090092[51] = 0;
   out_2845650287939090092[52] = 0;
   out_2845650287939090092[53] = 0;
   out_2845650287939090092[54] = 0;
   out_2845650287939090092[55] = 0;
   out_2845650287939090092[56] = 0;
   out_2845650287939090092[57] = 0;
   out_2845650287939090092[58] = 0;
   out_2845650287939090092[59] = 0;
   out_2845650287939090092[60] = 1.0;
   out_2845650287939090092[61] = 0;
   out_2845650287939090092[62] = 0;
   out_2845650287939090092[63] = 0;
   out_2845650287939090092[64] = 0;
   out_2845650287939090092[65] = 0;
   out_2845650287939090092[66] = 0;
   out_2845650287939090092[67] = 0;
   out_2845650287939090092[68] = 0;
   out_2845650287939090092[69] = 0;
   out_2845650287939090092[70] = 1.0;
   out_2845650287939090092[71] = 0;
   out_2845650287939090092[72] = 0;
   out_2845650287939090092[73] = 0;
   out_2845650287939090092[74] = 0;
   out_2845650287939090092[75] = 0;
   out_2845650287939090092[76] = 0;
   out_2845650287939090092[77] = 0;
   out_2845650287939090092[78] = 0;
   out_2845650287939090092[79] = 0;
   out_2845650287939090092[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8841561670931812130) {
   out_8841561670931812130[0] = state[0];
   out_8841561670931812130[1] = state[1];
   out_8841561670931812130[2] = state[2];
   out_8841561670931812130[3] = state[3];
   out_8841561670931812130[4] = state[4];
   out_8841561670931812130[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8841561670931812130[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8841561670931812130[7] = state[7];
   out_8841561670931812130[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8198088697078644734) {
   out_8198088697078644734[0] = 1;
   out_8198088697078644734[1] = 0;
   out_8198088697078644734[2] = 0;
   out_8198088697078644734[3] = 0;
   out_8198088697078644734[4] = 0;
   out_8198088697078644734[5] = 0;
   out_8198088697078644734[6] = 0;
   out_8198088697078644734[7] = 0;
   out_8198088697078644734[8] = 0;
   out_8198088697078644734[9] = 0;
   out_8198088697078644734[10] = 1;
   out_8198088697078644734[11] = 0;
   out_8198088697078644734[12] = 0;
   out_8198088697078644734[13] = 0;
   out_8198088697078644734[14] = 0;
   out_8198088697078644734[15] = 0;
   out_8198088697078644734[16] = 0;
   out_8198088697078644734[17] = 0;
   out_8198088697078644734[18] = 0;
   out_8198088697078644734[19] = 0;
   out_8198088697078644734[20] = 1;
   out_8198088697078644734[21] = 0;
   out_8198088697078644734[22] = 0;
   out_8198088697078644734[23] = 0;
   out_8198088697078644734[24] = 0;
   out_8198088697078644734[25] = 0;
   out_8198088697078644734[26] = 0;
   out_8198088697078644734[27] = 0;
   out_8198088697078644734[28] = 0;
   out_8198088697078644734[29] = 0;
   out_8198088697078644734[30] = 1;
   out_8198088697078644734[31] = 0;
   out_8198088697078644734[32] = 0;
   out_8198088697078644734[33] = 0;
   out_8198088697078644734[34] = 0;
   out_8198088697078644734[35] = 0;
   out_8198088697078644734[36] = 0;
   out_8198088697078644734[37] = 0;
   out_8198088697078644734[38] = 0;
   out_8198088697078644734[39] = 0;
   out_8198088697078644734[40] = 1;
   out_8198088697078644734[41] = 0;
   out_8198088697078644734[42] = 0;
   out_8198088697078644734[43] = 0;
   out_8198088697078644734[44] = 0;
   out_8198088697078644734[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8198088697078644734[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8198088697078644734[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8198088697078644734[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8198088697078644734[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8198088697078644734[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8198088697078644734[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8198088697078644734[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8198088697078644734[53] = -9.8000000000000007*dt;
   out_8198088697078644734[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8198088697078644734[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8198088697078644734[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8198088697078644734[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8198088697078644734[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8198088697078644734[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8198088697078644734[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8198088697078644734[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8198088697078644734[62] = 0;
   out_8198088697078644734[63] = 0;
   out_8198088697078644734[64] = 0;
   out_8198088697078644734[65] = 0;
   out_8198088697078644734[66] = 0;
   out_8198088697078644734[67] = 0;
   out_8198088697078644734[68] = 0;
   out_8198088697078644734[69] = 0;
   out_8198088697078644734[70] = 1;
   out_8198088697078644734[71] = 0;
   out_8198088697078644734[72] = 0;
   out_8198088697078644734[73] = 0;
   out_8198088697078644734[74] = 0;
   out_8198088697078644734[75] = 0;
   out_8198088697078644734[76] = 0;
   out_8198088697078644734[77] = 0;
   out_8198088697078644734[78] = 0;
   out_8198088697078644734[79] = 0;
   out_8198088697078644734[80] = 1;
}
void h_25(double *state, double *unused, double *out_203138435742136564) {
   out_203138435742136564[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4708458029850149414) {
   out_4708458029850149414[0] = 0;
   out_4708458029850149414[1] = 0;
   out_4708458029850149414[2] = 0;
   out_4708458029850149414[3] = 0;
   out_4708458029850149414[4] = 0;
   out_4708458029850149414[5] = 0;
   out_4708458029850149414[6] = 1;
   out_4708458029850149414[7] = 0;
   out_4708458029850149414[8] = 0;
}
void h_24(double *state, double *unused, double *out_2752629259026154701) {
   out_2752629259026154701[0] = state[4];
   out_2752629259026154701[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8261818804050822143) {
   out_8261818804050822143[0] = 0;
   out_8261818804050822143[1] = 0;
   out_8261818804050822143[2] = 0;
   out_8261818804050822143[3] = 0;
   out_8261818804050822143[4] = 1;
   out_8261818804050822143[5] = 0;
   out_8261818804050822143[6] = 0;
   out_8261818804050822143[7] = 0;
   out_8261818804050822143[8] = 0;
   out_8261818804050822143[9] = 0;
   out_8261818804050822143[10] = 0;
   out_8261818804050822143[11] = 0;
   out_8261818804050822143[12] = 0;
   out_8261818804050822143[13] = 0;
   out_8261818804050822143[14] = 1;
   out_8261818804050822143[15] = 0;
   out_8261818804050822143[16] = 0;
   out_8261818804050822143[17] = 0;
}
void h_30(double *state, double *unused, double *out_3840587963996158914) {
   out_3840587963996158914[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2190125071342900787) {
   out_2190125071342900787[0] = 0;
   out_2190125071342900787[1] = 0;
   out_2190125071342900787[2] = 0;
   out_2190125071342900787[3] = 0;
   out_2190125071342900787[4] = 1;
   out_2190125071342900787[5] = 0;
   out_2190125071342900787[6] = 0;
   out_2190125071342900787[7] = 0;
   out_2190125071342900787[8] = 0;
}
void h_26(double *state, double *unused, double *out_5399952989532072635) {
   out_5399952989532072635[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8449961348724205638) {
   out_8449961348724205638[0] = 0;
   out_8449961348724205638[1] = 0;
   out_8449961348724205638[2] = 0;
   out_8449961348724205638[3] = 0;
   out_8449961348724205638[4] = 0;
   out_8449961348724205638[5] = 0;
   out_8449961348724205638[6] = 0;
   out_8449961348724205638[7] = 1;
   out_8449961348724205638[8] = 0;
}
void h_27(double *state, double *unused, double *out_8920975355610828890) {
   out_8920975355610828890[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4364888383143325698) {
   out_4364888383143325698[0] = 0;
   out_4364888383143325698[1] = 0;
   out_4364888383143325698[2] = 0;
   out_4364888383143325698[3] = 1;
   out_4364888383143325698[4] = 0;
   out_4364888383143325698[5] = 0;
   out_4364888383143325698[6] = 0;
   out_4364888383143325698[7] = 0;
   out_4364888383143325698[8] = 0;
}
void h_29(double *state, double *unused, double *out_9066495179831483861) {
   out_9066495179831483861[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1679893727028508603) {
   out_1679893727028508603[0] = 0;
   out_1679893727028508603[1] = 1;
   out_1679893727028508603[2] = 0;
   out_1679893727028508603[3] = 0;
   out_1679893727028508603[4] = 0;
   out_1679893727028508603[5] = 0;
   out_1679893727028508603[6] = 0;
   out_1679893727028508603[7] = 0;
   out_1679893727028508603[8] = 0;
}
void h_28(double *state, double *unused, double *out_4524095450437877081) {
   out_4524095450437877081[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6762292744098039177) {
   out_6762292744098039177[0] = 1;
   out_6762292744098039177[1] = 0;
   out_6762292744098039177[2] = 0;
   out_6762292744098039177[3] = 0;
   out_6762292744098039177[4] = 0;
   out_6762292744098039177[5] = 0;
   out_6762292744098039177[6] = 0;
   out_6762292744098039177[7] = 0;
   out_6762292744098039177[8] = 0;
}
void h_31(double *state, double *unused, double *out_72055626542369325) {
   out_72055626542369325[0] = state[8];
}
void H_31(double *state, double *unused, double *out_9076169450957557114) {
   out_9076169450957557114[0] = 0;
   out_9076169450957557114[1] = 0;
   out_9076169450957557114[2] = 0;
   out_9076169450957557114[3] = 0;
   out_9076169450957557114[4] = 0;
   out_9076169450957557114[5] = 0;
   out_9076169450957557114[6] = 0;
   out_9076169450957557114[7] = 0;
   out_9076169450957557114[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_6320531096693148158) {
  err_fun(nom_x, delta_x, out_6320531096693148158);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5645716242889632752) {
  inv_err_fun(nom_x, true_x, out_5645716242889632752);
}
void car_H_mod_fun(double *state, double *out_2845650287939090092) {
  H_mod_fun(state, out_2845650287939090092);
}
void car_f_fun(double *state, double dt, double *out_8841561670931812130) {
  f_fun(state,  dt, out_8841561670931812130);
}
void car_F_fun(double *state, double dt, double *out_8198088697078644734) {
  F_fun(state,  dt, out_8198088697078644734);
}
void car_h_25(double *state, double *unused, double *out_203138435742136564) {
  h_25(state, unused, out_203138435742136564);
}
void car_H_25(double *state, double *unused, double *out_4708458029850149414) {
  H_25(state, unused, out_4708458029850149414);
}
void car_h_24(double *state, double *unused, double *out_2752629259026154701) {
  h_24(state, unused, out_2752629259026154701);
}
void car_H_24(double *state, double *unused, double *out_8261818804050822143) {
  H_24(state, unused, out_8261818804050822143);
}
void car_h_30(double *state, double *unused, double *out_3840587963996158914) {
  h_30(state, unused, out_3840587963996158914);
}
void car_H_30(double *state, double *unused, double *out_2190125071342900787) {
  H_30(state, unused, out_2190125071342900787);
}
void car_h_26(double *state, double *unused, double *out_5399952989532072635) {
  h_26(state, unused, out_5399952989532072635);
}
void car_H_26(double *state, double *unused, double *out_8449961348724205638) {
  H_26(state, unused, out_8449961348724205638);
}
void car_h_27(double *state, double *unused, double *out_8920975355610828890) {
  h_27(state, unused, out_8920975355610828890);
}
void car_H_27(double *state, double *unused, double *out_4364888383143325698) {
  H_27(state, unused, out_4364888383143325698);
}
void car_h_29(double *state, double *unused, double *out_9066495179831483861) {
  h_29(state, unused, out_9066495179831483861);
}
void car_H_29(double *state, double *unused, double *out_1679893727028508603) {
  H_29(state, unused, out_1679893727028508603);
}
void car_h_28(double *state, double *unused, double *out_4524095450437877081) {
  h_28(state, unused, out_4524095450437877081);
}
void car_H_28(double *state, double *unused, double *out_6762292744098039177) {
  H_28(state, unused, out_6762292744098039177);
}
void car_h_31(double *state, double *unused, double *out_72055626542369325) {
  h_31(state, unused, out_72055626542369325);
}
void car_H_31(double *state, double *unused, double *out_9076169450957557114) {
  H_31(state, unused, out_9076169450957557114);
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
