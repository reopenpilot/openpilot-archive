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
void err_fun(double *nom_x, double *delta_x, double *out_5430471743703628025) {
   out_5430471743703628025[0] = delta_x[0] + nom_x[0];
   out_5430471743703628025[1] = delta_x[1] + nom_x[1];
   out_5430471743703628025[2] = delta_x[2] + nom_x[2];
   out_5430471743703628025[3] = delta_x[3] + nom_x[3];
   out_5430471743703628025[4] = delta_x[4] + nom_x[4];
   out_5430471743703628025[5] = delta_x[5] + nom_x[5];
   out_5430471743703628025[6] = delta_x[6] + nom_x[6];
   out_5430471743703628025[7] = delta_x[7] + nom_x[7];
   out_5430471743703628025[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3119006140182869805) {
   out_3119006140182869805[0] = -nom_x[0] + true_x[0];
   out_3119006140182869805[1] = -nom_x[1] + true_x[1];
   out_3119006140182869805[2] = -nom_x[2] + true_x[2];
   out_3119006140182869805[3] = -nom_x[3] + true_x[3];
   out_3119006140182869805[4] = -nom_x[4] + true_x[4];
   out_3119006140182869805[5] = -nom_x[5] + true_x[5];
   out_3119006140182869805[6] = -nom_x[6] + true_x[6];
   out_3119006140182869805[7] = -nom_x[7] + true_x[7];
   out_3119006140182869805[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8243656043750077585) {
   out_8243656043750077585[0] = 1.0;
   out_8243656043750077585[1] = 0;
   out_8243656043750077585[2] = 0;
   out_8243656043750077585[3] = 0;
   out_8243656043750077585[4] = 0;
   out_8243656043750077585[5] = 0;
   out_8243656043750077585[6] = 0;
   out_8243656043750077585[7] = 0;
   out_8243656043750077585[8] = 0;
   out_8243656043750077585[9] = 0;
   out_8243656043750077585[10] = 1.0;
   out_8243656043750077585[11] = 0;
   out_8243656043750077585[12] = 0;
   out_8243656043750077585[13] = 0;
   out_8243656043750077585[14] = 0;
   out_8243656043750077585[15] = 0;
   out_8243656043750077585[16] = 0;
   out_8243656043750077585[17] = 0;
   out_8243656043750077585[18] = 0;
   out_8243656043750077585[19] = 0;
   out_8243656043750077585[20] = 1.0;
   out_8243656043750077585[21] = 0;
   out_8243656043750077585[22] = 0;
   out_8243656043750077585[23] = 0;
   out_8243656043750077585[24] = 0;
   out_8243656043750077585[25] = 0;
   out_8243656043750077585[26] = 0;
   out_8243656043750077585[27] = 0;
   out_8243656043750077585[28] = 0;
   out_8243656043750077585[29] = 0;
   out_8243656043750077585[30] = 1.0;
   out_8243656043750077585[31] = 0;
   out_8243656043750077585[32] = 0;
   out_8243656043750077585[33] = 0;
   out_8243656043750077585[34] = 0;
   out_8243656043750077585[35] = 0;
   out_8243656043750077585[36] = 0;
   out_8243656043750077585[37] = 0;
   out_8243656043750077585[38] = 0;
   out_8243656043750077585[39] = 0;
   out_8243656043750077585[40] = 1.0;
   out_8243656043750077585[41] = 0;
   out_8243656043750077585[42] = 0;
   out_8243656043750077585[43] = 0;
   out_8243656043750077585[44] = 0;
   out_8243656043750077585[45] = 0;
   out_8243656043750077585[46] = 0;
   out_8243656043750077585[47] = 0;
   out_8243656043750077585[48] = 0;
   out_8243656043750077585[49] = 0;
   out_8243656043750077585[50] = 1.0;
   out_8243656043750077585[51] = 0;
   out_8243656043750077585[52] = 0;
   out_8243656043750077585[53] = 0;
   out_8243656043750077585[54] = 0;
   out_8243656043750077585[55] = 0;
   out_8243656043750077585[56] = 0;
   out_8243656043750077585[57] = 0;
   out_8243656043750077585[58] = 0;
   out_8243656043750077585[59] = 0;
   out_8243656043750077585[60] = 1.0;
   out_8243656043750077585[61] = 0;
   out_8243656043750077585[62] = 0;
   out_8243656043750077585[63] = 0;
   out_8243656043750077585[64] = 0;
   out_8243656043750077585[65] = 0;
   out_8243656043750077585[66] = 0;
   out_8243656043750077585[67] = 0;
   out_8243656043750077585[68] = 0;
   out_8243656043750077585[69] = 0;
   out_8243656043750077585[70] = 1.0;
   out_8243656043750077585[71] = 0;
   out_8243656043750077585[72] = 0;
   out_8243656043750077585[73] = 0;
   out_8243656043750077585[74] = 0;
   out_8243656043750077585[75] = 0;
   out_8243656043750077585[76] = 0;
   out_8243656043750077585[77] = 0;
   out_8243656043750077585[78] = 0;
   out_8243656043750077585[79] = 0;
   out_8243656043750077585[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8245401355847018673) {
   out_8245401355847018673[0] = state[0];
   out_8245401355847018673[1] = state[1];
   out_8245401355847018673[2] = state[2];
   out_8245401355847018673[3] = state[3];
   out_8245401355847018673[4] = state[4];
   out_8245401355847018673[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8245401355847018673[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8245401355847018673[7] = state[7];
   out_8245401355847018673[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2231314064370560999) {
   out_2231314064370560999[0] = 1;
   out_2231314064370560999[1] = 0;
   out_2231314064370560999[2] = 0;
   out_2231314064370560999[3] = 0;
   out_2231314064370560999[4] = 0;
   out_2231314064370560999[5] = 0;
   out_2231314064370560999[6] = 0;
   out_2231314064370560999[7] = 0;
   out_2231314064370560999[8] = 0;
   out_2231314064370560999[9] = 0;
   out_2231314064370560999[10] = 1;
   out_2231314064370560999[11] = 0;
   out_2231314064370560999[12] = 0;
   out_2231314064370560999[13] = 0;
   out_2231314064370560999[14] = 0;
   out_2231314064370560999[15] = 0;
   out_2231314064370560999[16] = 0;
   out_2231314064370560999[17] = 0;
   out_2231314064370560999[18] = 0;
   out_2231314064370560999[19] = 0;
   out_2231314064370560999[20] = 1;
   out_2231314064370560999[21] = 0;
   out_2231314064370560999[22] = 0;
   out_2231314064370560999[23] = 0;
   out_2231314064370560999[24] = 0;
   out_2231314064370560999[25] = 0;
   out_2231314064370560999[26] = 0;
   out_2231314064370560999[27] = 0;
   out_2231314064370560999[28] = 0;
   out_2231314064370560999[29] = 0;
   out_2231314064370560999[30] = 1;
   out_2231314064370560999[31] = 0;
   out_2231314064370560999[32] = 0;
   out_2231314064370560999[33] = 0;
   out_2231314064370560999[34] = 0;
   out_2231314064370560999[35] = 0;
   out_2231314064370560999[36] = 0;
   out_2231314064370560999[37] = 0;
   out_2231314064370560999[38] = 0;
   out_2231314064370560999[39] = 0;
   out_2231314064370560999[40] = 1;
   out_2231314064370560999[41] = 0;
   out_2231314064370560999[42] = 0;
   out_2231314064370560999[43] = 0;
   out_2231314064370560999[44] = 0;
   out_2231314064370560999[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2231314064370560999[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2231314064370560999[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2231314064370560999[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2231314064370560999[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2231314064370560999[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2231314064370560999[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2231314064370560999[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2231314064370560999[53] = -9.8000000000000007*dt;
   out_2231314064370560999[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2231314064370560999[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2231314064370560999[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2231314064370560999[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2231314064370560999[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2231314064370560999[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2231314064370560999[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2231314064370560999[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2231314064370560999[62] = 0;
   out_2231314064370560999[63] = 0;
   out_2231314064370560999[64] = 0;
   out_2231314064370560999[65] = 0;
   out_2231314064370560999[66] = 0;
   out_2231314064370560999[67] = 0;
   out_2231314064370560999[68] = 0;
   out_2231314064370560999[69] = 0;
   out_2231314064370560999[70] = 1;
   out_2231314064370560999[71] = 0;
   out_2231314064370560999[72] = 0;
   out_2231314064370560999[73] = 0;
   out_2231314064370560999[74] = 0;
   out_2231314064370560999[75] = 0;
   out_2231314064370560999[76] = 0;
   out_2231314064370560999[77] = 0;
   out_2231314064370560999[78] = 0;
   out_2231314064370560999[79] = 0;
   out_2231314064370560999[80] = 1;
}
void h_25(double *state, double *unused, double *out_4907576450740410272) {
   out_4907576450740410272[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5469066146654994867) {
   out_5469066146654994867[0] = 0;
   out_5469066146654994867[1] = 0;
   out_5469066146654994867[2] = 0;
   out_5469066146654994867[3] = 0;
   out_5469066146654994867[4] = 0;
   out_5469066146654994867[5] = 0;
   out_5469066146654994867[6] = 1;
   out_5469066146654994867[7] = 0;
   out_5469066146654994867[8] = 0;
}
void h_24(double *state, double *unused, double *out_3525197881519364844) {
   out_3525197881519364844[0] = state[4];
   out_3525197881519364844[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6850457424892874552) {
   out_6850457424892874552[0] = 0;
   out_6850457424892874552[1] = 0;
   out_6850457424892874552[2] = 0;
   out_6850457424892874552[3] = 0;
   out_6850457424892874552[4] = 1;
   out_6850457424892874552[5] = 0;
   out_6850457424892874552[6] = 0;
   out_6850457424892874552[7] = 0;
   out_6850457424892874552[8] = 0;
   out_6850457424892874552[9] = 0;
   out_6850457424892874552[10] = 0;
   out_6850457424892874552[11] = 0;
   out_6850457424892874552[12] = 0;
   out_6850457424892874552[13] = 0;
   out_6850457424892874552[14] = 1;
   out_6850457424892874552[15] = 0;
   out_6850457424892874552[16] = 0;
   out_6850457424892874552[17] = 0;
}
void h_30(double *state, double *unused, double *out_3505611992589953304) {
   out_3505611992589953304[0] = state[4];
}
void H_30(double *state, double *unused, double *out_2950733188147746240) {
   out_2950733188147746240[0] = 0;
   out_2950733188147746240[1] = 0;
   out_2950733188147746240[2] = 0;
   out_2950733188147746240[3] = 0;
   out_2950733188147746240[4] = 1;
   out_2950733188147746240[5] = 0;
   out_2950733188147746240[6] = 0;
   out_2950733188147746240[7] = 0;
   out_2950733188147746240[8] = 0;
}
void h_26(double *state, double *unused, double *out_6873218347760597121) {
   out_6873218347760597121[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2164540176894194266) {
   out_2164540176894194266[0] = 0;
   out_2164540176894194266[1] = 0;
   out_2164540176894194266[2] = 0;
   out_2164540176894194266[3] = 0;
   out_2164540176894194266[4] = 0;
   out_2164540176894194266[5] = 0;
   out_2164540176894194266[6] = 0;
   out_2164540176894194266[7] = 1;
   out_2164540176894194266[8] = 0;
}
void h_27(double *state, double *unused, double *out_54803546940882960) {
   out_54803546940882960[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5125496499948171151) {
   out_5125496499948171151[0] = 0;
   out_5125496499948171151[1] = 0;
   out_5125496499948171151[2] = 0;
   out_5125496499948171151[3] = 1;
   out_5125496499948171151[4] = 0;
   out_5125496499948171151[5] = 0;
   out_5125496499948171151[6] = 0;
   out_5125496499948171151[7] = 0;
   out_5125496499948171151[8] = 0;
}
void h_29(double *state, double *unused, double *out_2750212729369093950) {
   out_2750212729369093950[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2440501843833354056) {
   out_2440501843833354056[0] = 0;
   out_2440501843833354056[1] = 1;
   out_2440501843833354056[2] = 0;
   out_2440501843833354056[3] = 0;
   out_2440501843833354056[4] = 0;
   out_2440501843833354056[5] = 0;
   out_2440501843833354056[6] = 0;
   out_2440501843833354056[7] = 0;
   out_2440501843833354056[8] = 0;
}
void h_28(double *state, double *unused, double *out_4112133440010064166) {
   out_4112133440010064166[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7522900860902884630) {
   out_7522900860902884630[0] = 1;
   out_7522900860902884630[1] = 0;
   out_7522900860902884630[2] = 0;
   out_7522900860902884630[3] = 0;
   out_7522900860902884630[4] = 0;
   out_7522900860902884630[5] = 0;
   out_7522900860902884630[6] = 0;
   out_7522900860902884630[7] = 0;
   out_7522900860902884630[8] = 0;
}
void h_31(double *state, double *unused, double *out_469580621949294508) {
   out_469580621949294508[0] = state[8];
}
void H_31(double *state, double *unused, double *out_2790748279127545742) {
   out_2790748279127545742[0] = 0;
   out_2790748279127545742[1] = 0;
   out_2790748279127545742[2] = 0;
   out_2790748279127545742[3] = 0;
   out_2790748279127545742[4] = 0;
   out_2790748279127545742[5] = 0;
   out_2790748279127545742[6] = 0;
   out_2790748279127545742[7] = 0;
   out_2790748279127545742[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5430471743703628025) {
  err_fun(nom_x, delta_x, out_5430471743703628025);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3119006140182869805) {
  inv_err_fun(nom_x, true_x, out_3119006140182869805);
}
void car_H_mod_fun(double *state, double *out_8243656043750077585) {
  H_mod_fun(state, out_8243656043750077585);
}
void car_f_fun(double *state, double dt, double *out_8245401355847018673) {
  f_fun(state,  dt, out_8245401355847018673);
}
void car_F_fun(double *state, double dt, double *out_2231314064370560999) {
  F_fun(state,  dt, out_2231314064370560999);
}
void car_h_25(double *state, double *unused, double *out_4907576450740410272) {
  h_25(state, unused, out_4907576450740410272);
}
void car_H_25(double *state, double *unused, double *out_5469066146654994867) {
  H_25(state, unused, out_5469066146654994867);
}
void car_h_24(double *state, double *unused, double *out_3525197881519364844) {
  h_24(state, unused, out_3525197881519364844);
}
void car_H_24(double *state, double *unused, double *out_6850457424892874552) {
  H_24(state, unused, out_6850457424892874552);
}
void car_h_30(double *state, double *unused, double *out_3505611992589953304) {
  h_30(state, unused, out_3505611992589953304);
}
void car_H_30(double *state, double *unused, double *out_2950733188147746240) {
  H_30(state, unused, out_2950733188147746240);
}
void car_h_26(double *state, double *unused, double *out_6873218347760597121) {
  h_26(state, unused, out_6873218347760597121);
}
void car_H_26(double *state, double *unused, double *out_2164540176894194266) {
  H_26(state, unused, out_2164540176894194266);
}
void car_h_27(double *state, double *unused, double *out_54803546940882960) {
  h_27(state, unused, out_54803546940882960);
}
void car_H_27(double *state, double *unused, double *out_5125496499948171151) {
  H_27(state, unused, out_5125496499948171151);
}
void car_h_29(double *state, double *unused, double *out_2750212729369093950) {
  h_29(state, unused, out_2750212729369093950);
}
void car_H_29(double *state, double *unused, double *out_2440501843833354056) {
  H_29(state, unused, out_2440501843833354056);
}
void car_h_28(double *state, double *unused, double *out_4112133440010064166) {
  h_28(state, unused, out_4112133440010064166);
}
void car_H_28(double *state, double *unused, double *out_7522900860902884630) {
  H_28(state, unused, out_7522900860902884630);
}
void car_h_31(double *state, double *unused, double *out_469580621949294508) {
  h_31(state, unused, out_469580621949294508);
}
void car_H_31(double *state, double *unused, double *out_2790748279127545742) {
  H_31(state, unused, out_2790748279127545742);
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
