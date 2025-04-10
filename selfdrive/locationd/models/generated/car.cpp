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
void err_fun(double *nom_x, double *delta_x, double *out_7372292753266427481) {
   out_7372292753266427481[0] = delta_x[0] + nom_x[0];
   out_7372292753266427481[1] = delta_x[1] + nom_x[1];
   out_7372292753266427481[2] = delta_x[2] + nom_x[2];
   out_7372292753266427481[3] = delta_x[3] + nom_x[3];
   out_7372292753266427481[4] = delta_x[4] + nom_x[4];
   out_7372292753266427481[5] = delta_x[5] + nom_x[5];
   out_7372292753266427481[6] = delta_x[6] + nom_x[6];
   out_7372292753266427481[7] = delta_x[7] + nom_x[7];
   out_7372292753266427481[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6890334366226816016) {
   out_6890334366226816016[0] = -nom_x[0] + true_x[0];
   out_6890334366226816016[1] = -nom_x[1] + true_x[1];
   out_6890334366226816016[2] = -nom_x[2] + true_x[2];
   out_6890334366226816016[3] = -nom_x[3] + true_x[3];
   out_6890334366226816016[4] = -nom_x[4] + true_x[4];
   out_6890334366226816016[5] = -nom_x[5] + true_x[5];
   out_6890334366226816016[6] = -nom_x[6] + true_x[6];
   out_6890334366226816016[7] = -nom_x[7] + true_x[7];
   out_6890334366226816016[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6044539110131019281) {
   out_6044539110131019281[0] = 1.0;
   out_6044539110131019281[1] = 0;
   out_6044539110131019281[2] = 0;
   out_6044539110131019281[3] = 0;
   out_6044539110131019281[4] = 0;
   out_6044539110131019281[5] = 0;
   out_6044539110131019281[6] = 0;
   out_6044539110131019281[7] = 0;
   out_6044539110131019281[8] = 0;
   out_6044539110131019281[9] = 0;
   out_6044539110131019281[10] = 1.0;
   out_6044539110131019281[11] = 0;
   out_6044539110131019281[12] = 0;
   out_6044539110131019281[13] = 0;
   out_6044539110131019281[14] = 0;
   out_6044539110131019281[15] = 0;
   out_6044539110131019281[16] = 0;
   out_6044539110131019281[17] = 0;
   out_6044539110131019281[18] = 0;
   out_6044539110131019281[19] = 0;
   out_6044539110131019281[20] = 1.0;
   out_6044539110131019281[21] = 0;
   out_6044539110131019281[22] = 0;
   out_6044539110131019281[23] = 0;
   out_6044539110131019281[24] = 0;
   out_6044539110131019281[25] = 0;
   out_6044539110131019281[26] = 0;
   out_6044539110131019281[27] = 0;
   out_6044539110131019281[28] = 0;
   out_6044539110131019281[29] = 0;
   out_6044539110131019281[30] = 1.0;
   out_6044539110131019281[31] = 0;
   out_6044539110131019281[32] = 0;
   out_6044539110131019281[33] = 0;
   out_6044539110131019281[34] = 0;
   out_6044539110131019281[35] = 0;
   out_6044539110131019281[36] = 0;
   out_6044539110131019281[37] = 0;
   out_6044539110131019281[38] = 0;
   out_6044539110131019281[39] = 0;
   out_6044539110131019281[40] = 1.0;
   out_6044539110131019281[41] = 0;
   out_6044539110131019281[42] = 0;
   out_6044539110131019281[43] = 0;
   out_6044539110131019281[44] = 0;
   out_6044539110131019281[45] = 0;
   out_6044539110131019281[46] = 0;
   out_6044539110131019281[47] = 0;
   out_6044539110131019281[48] = 0;
   out_6044539110131019281[49] = 0;
   out_6044539110131019281[50] = 1.0;
   out_6044539110131019281[51] = 0;
   out_6044539110131019281[52] = 0;
   out_6044539110131019281[53] = 0;
   out_6044539110131019281[54] = 0;
   out_6044539110131019281[55] = 0;
   out_6044539110131019281[56] = 0;
   out_6044539110131019281[57] = 0;
   out_6044539110131019281[58] = 0;
   out_6044539110131019281[59] = 0;
   out_6044539110131019281[60] = 1.0;
   out_6044539110131019281[61] = 0;
   out_6044539110131019281[62] = 0;
   out_6044539110131019281[63] = 0;
   out_6044539110131019281[64] = 0;
   out_6044539110131019281[65] = 0;
   out_6044539110131019281[66] = 0;
   out_6044539110131019281[67] = 0;
   out_6044539110131019281[68] = 0;
   out_6044539110131019281[69] = 0;
   out_6044539110131019281[70] = 1.0;
   out_6044539110131019281[71] = 0;
   out_6044539110131019281[72] = 0;
   out_6044539110131019281[73] = 0;
   out_6044539110131019281[74] = 0;
   out_6044539110131019281[75] = 0;
   out_6044539110131019281[76] = 0;
   out_6044539110131019281[77] = 0;
   out_6044539110131019281[78] = 0;
   out_6044539110131019281[79] = 0;
   out_6044539110131019281[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3703214697313371202) {
   out_3703214697313371202[0] = state[0];
   out_3703214697313371202[1] = state[1];
   out_3703214697313371202[2] = state[2];
   out_3703214697313371202[3] = state[3];
   out_3703214697313371202[4] = state[4];
   out_3703214697313371202[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3703214697313371202[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3703214697313371202[7] = state[7];
   out_3703214697313371202[8] = state[8];
}
void F_fun(double *state, double dt, double *out_871911644151068477) {
   out_871911644151068477[0] = 1;
   out_871911644151068477[1] = 0;
   out_871911644151068477[2] = 0;
   out_871911644151068477[3] = 0;
   out_871911644151068477[4] = 0;
   out_871911644151068477[5] = 0;
   out_871911644151068477[6] = 0;
   out_871911644151068477[7] = 0;
   out_871911644151068477[8] = 0;
   out_871911644151068477[9] = 0;
   out_871911644151068477[10] = 1;
   out_871911644151068477[11] = 0;
   out_871911644151068477[12] = 0;
   out_871911644151068477[13] = 0;
   out_871911644151068477[14] = 0;
   out_871911644151068477[15] = 0;
   out_871911644151068477[16] = 0;
   out_871911644151068477[17] = 0;
   out_871911644151068477[18] = 0;
   out_871911644151068477[19] = 0;
   out_871911644151068477[20] = 1;
   out_871911644151068477[21] = 0;
   out_871911644151068477[22] = 0;
   out_871911644151068477[23] = 0;
   out_871911644151068477[24] = 0;
   out_871911644151068477[25] = 0;
   out_871911644151068477[26] = 0;
   out_871911644151068477[27] = 0;
   out_871911644151068477[28] = 0;
   out_871911644151068477[29] = 0;
   out_871911644151068477[30] = 1;
   out_871911644151068477[31] = 0;
   out_871911644151068477[32] = 0;
   out_871911644151068477[33] = 0;
   out_871911644151068477[34] = 0;
   out_871911644151068477[35] = 0;
   out_871911644151068477[36] = 0;
   out_871911644151068477[37] = 0;
   out_871911644151068477[38] = 0;
   out_871911644151068477[39] = 0;
   out_871911644151068477[40] = 1;
   out_871911644151068477[41] = 0;
   out_871911644151068477[42] = 0;
   out_871911644151068477[43] = 0;
   out_871911644151068477[44] = 0;
   out_871911644151068477[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_871911644151068477[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_871911644151068477[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_871911644151068477[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_871911644151068477[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_871911644151068477[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_871911644151068477[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_871911644151068477[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_871911644151068477[53] = -9.8000000000000007*dt;
   out_871911644151068477[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_871911644151068477[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_871911644151068477[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_871911644151068477[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_871911644151068477[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_871911644151068477[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_871911644151068477[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_871911644151068477[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_871911644151068477[62] = 0;
   out_871911644151068477[63] = 0;
   out_871911644151068477[64] = 0;
   out_871911644151068477[65] = 0;
   out_871911644151068477[66] = 0;
   out_871911644151068477[67] = 0;
   out_871911644151068477[68] = 0;
   out_871911644151068477[69] = 0;
   out_871911644151068477[70] = 1;
   out_871911644151068477[71] = 0;
   out_871911644151068477[72] = 0;
   out_871911644151068477[73] = 0;
   out_871911644151068477[74] = 0;
   out_871911644151068477[75] = 0;
   out_871911644151068477[76] = 0;
   out_871911644151068477[77] = 0;
   out_871911644151068477[78] = 0;
   out_871911644151068477[79] = 0;
   out_871911644151068477[80] = 1;
}
void h_25(double *state, double *unused, double *out_2746122198574793256) {
   out_2746122198574793256[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2081667183922004253) {
   out_2081667183922004253[0] = 0;
   out_2081667183922004253[1] = 0;
   out_2081667183922004253[2] = 0;
   out_2081667183922004253[3] = 0;
   out_2081667183922004253[4] = 0;
   out_2081667183922004253[5] = 0;
   out_2081667183922004253[6] = 1;
   out_2081667183922004253[7] = 0;
   out_2081667183922004253[8] = 0;
}
void h_24(double *state, double *unused, double *out_1895793471156721385) {
   out_1895793471156721385[0] = state[4];
   out_1895793471156721385[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1476258414880318883) {
   out_1476258414880318883[0] = 0;
   out_1476258414880318883[1] = 0;
   out_1476258414880318883[2] = 0;
   out_1476258414880318883[3] = 0;
   out_1476258414880318883[4] = 1;
   out_1476258414880318883[5] = 0;
   out_1476258414880318883[6] = 0;
   out_1476258414880318883[7] = 0;
   out_1476258414880318883[8] = 0;
   out_1476258414880318883[9] = 0;
   out_1476258414880318883[10] = 0;
   out_1476258414880318883[11] = 0;
   out_1476258414880318883[12] = 0;
   out_1476258414880318883[13] = 0;
   out_1476258414880318883[14] = 1;
   out_1476258414880318883[15] = 0;
   out_1476258414880318883[16] = 0;
   out_1476258414880318883[17] = 0;
}
void h_30(double *state, double *unused, double *out_7060744398416216476) {
   out_7060744398416216476[0] = state[4];
}
void H_30(double *state, double *unused, double *out_436665774585244374) {
   out_436665774585244374[0] = 0;
   out_436665774585244374[1] = 0;
   out_436665774585244374[2] = 0;
   out_436665774585244374[3] = 0;
   out_436665774585244374[4] = 1;
   out_436665774585244374[5] = 0;
   out_436665774585244374[6] = 0;
   out_436665774585244374[7] = 0;
   out_436665774585244374[8] = 0;
}
void h_26(double *state, double *unused, double *out_8751192233151897436) {
   out_8751192233151897436[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5823170502796060477) {
   out_5823170502796060477[0] = 0;
   out_5823170502796060477[1] = 0;
   out_5823170502796060477[2] = 0;
   out_5823170502796060477[3] = 0;
   out_5823170502796060477[4] = 0;
   out_5823170502796060477[5] = 0;
   out_5823170502796060477[6] = 0;
   out_5823170502796060477[7] = 1;
   out_5823170502796060477[8] = 0;
}
void h_27(double *state, double *unused, double *out_5782908250019125941) {
   out_5782908250019125941[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2660259845769187591) {
   out_2660259845769187591[0] = 0;
   out_2660259845769187591[1] = 0;
   out_2660259845769187591[2] = 0;
   out_2660259845769187591[3] = 1;
   out_2660259845769187591[4] = 0;
   out_2660259845769187591[5] = 0;
   out_2660259845769187591[6] = 0;
   out_2660259845769187591[7] = 0;
   out_2660259845769187591[8] = 0;
}
void h_29(double *state, double *unused, double *out_5203277059441537350) {
   out_5203277059441537350[0] = state[1];
}
void H_29(double *state, double *unused, double *out_946897118899636558) {
   out_946897118899636558[0] = 0;
   out_946897118899636558[1] = 1;
   out_946897118899636558[2] = 0;
   out_946897118899636558[3] = 0;
   out_946897118899636558[4] = 0;
   out_946897118899636558[5] = 0;
   out_946897118899636558[6] = 0;
   out_946897118899636558[7] = 0;
   out_946897118899636558[8] = 0;
}
void h_28(double *state, double *unused, double *out_557001034183800994) {
   out_557001034183800994[0] = state[0];
}
void H_28(double *state, double *unused, double *out_4135501898169894016) {
   out_4135501898169894016[0] = 1;
   out_4135501898169894016[1] = 0;
   out_4135501898169894016[2] = 0;
   out_4135501898169894016[3] = 0;
   out_4135501898169894016[4] = 0;
   out_4135501898169894016[5] = 0;
   out_4135501898169894016[6] = 0;
   out_4135501898169894016[7] = 0;
   out_4135501898169894016[8] = 0;
}
void h_31(double *state, double *unused, double *out_3021316260859299145) {
   out_3021316260859299145[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6449378605029411953) {
   out_6449378605029411953[0] = 0;
   out_6449378605029411953[1] = 0;
   out_6449378605029411953[2] = 0;
   out_6449378605029411953[3] = 0;
   out_6449378605029411953[4] = 0;
   out_6449378605029411953[5] = 0;
   out_6449378605029411953[6] = 0;
   out_6449378605029411953[7] = 0;
   out_6449378605029411953[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_7372292753266427481) {
  err_fun(nom_x, delta_x, out_7372292753266427481);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6890334366226816016) {
  inv_err_fun(nom_x, true_x, out_6890334366226816016);
}
void car_H_mod_fun(double *state, double *out_6044539110131019281) {
  H_mod_fun(state, out_6044539110131019281);
}
void car_f_fun(double *state, double dt, double *out_3703214697313371202) {
  f_fun(state,  dt, out_3703214697313371202);
}
void car_F_fun(double *state, double dt, double *out_871911644151068477) {
  F_fun(state,  dt, out_871911644151068477);
}
void car_h_25(double *state, double *unused, double *out_2746122198574793256) {
  h_25(state, unused, out_2746122198574793256);
}
void car_H_25(double *state, double *unused, double *out_2081667183922004253) {
  H_25(state, unused, out_2081667183922004253);
}
void car_h_24(double *state, double *unused, double *out_1895793471156721385) {
  h_24(state, unused, out_1895793471156721385);
}
void car_H_24(double *state, double *unused, double *out_1476258414880318883) {
  H_24(state, unused, out_1476258414880318883);
}
void car_h_30(double *state, double *unused, double *out_7060744398416216476) {
  h_30(state, unused, out_7060744398416216476);
}
void car_H_30(double *state, double *unused, double *out_436665774585244374) {
  H_30(state, unused, out_436665774585244374);
}
void car_h_26(double *state, double *unused, double *out_8751192233151897436) {
  h_26(state, unused, out_8751192233151897436);
}
void car_H_26(double *state, double *unused, double *out_5823170502796060477) {
  H_26(state, unused, out_5823170502796060477);
}
void car_h_27(double *state, double *unused, double *out_5782908250019125941) {
  h_27(state, unused, out_5782908250019125941);
}
void car_H_27(double *state, double *unused, double *out_2660259845769187591) {
  H_27(state, unused, out_2660259845769187591);
}
void car_h_29(double *state, double *unused, double *out_5203277059441537350) {
  h_29(state, unused, out_5203277059441537350);
}
void car_H_29(double *state, double *unused, double *out_946897118899636558) {
  H_29(state, unused, out_946897118899636558);
}
void car_h_28(double *state, double *unused, double *out_557001034183800994) {
  h_28(state, unused, out_557001034183800994);
}
void car_H_28(double *state, double *unused, double *out_4135501898169894016) {
  H_28(state, unused, out_4135501898169894016);
}
void car_h_31(double *state, double *unused, double *out_3021316260859299145) {
  h_31(state, unused, out_3021316260859299145);
}
void car_H_31(double *state, double *unused, double *out_6449378605029411953) {
  H_31(state, unused, out_6449378605029411953);
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
