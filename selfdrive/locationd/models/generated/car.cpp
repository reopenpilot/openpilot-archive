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
void err_fun(double *nom_x, double *delta_x, double *out_4756830923943155660) {
   out_4756830923943155660[0] = delta_x[0] + nom_x[0];
   out_4756830923943155660[1] = delta_x[1] + nom_x[1];
   out_4756830923943155660[2] = delta_x[2] + nom_x[2];
   out_4756830923943155660[3] = delta_x[3] + nom_x[3];
   out_4756830923943155660[4] = delta_x[4] + nom_x[4];
   out_4756830923943155660[5] = delta_x[5] + nom_x[5];
   out_4756830923943155660[6] = delta_x[6] + nom_x[6];
   out_4756830923943155660[7] = delta_x[7] + nom_x[7];
   out_4756830923943155660[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_9000188679074390687) {
   out_9000188679074390687[0] = -nom_x[0] + true_x[0];
   out_9000188679074390687[1] = -nom_x[1] + true_x[1];
   out_9000188679074390687[2] = -nom_x[2] + true_x[2];
   out_9000188679074390687[3] = -nom_x[3] + true_x[3];
   out_9000188679074390687[4] = -nom_x[4] + true_x[4];
   out_9000188679074390687[5] = -nom_x[5] + true_x[5];
   out_9000188679074390687[6] = -nom_x[6] + true_x[6];
   out_9000188679074390687[7] = -nom_x[7] + true_x[7];
   out_9000188679074390687[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5532999626545989618) {
   out_5532999626545989618[0] = 1.0;
   out_5532999626545989618[1] = 0;
   out_5532999626545989618[2] = 0;
   out_5532999626545989618[3] = 0;
   out_5532999626545989618[4] = 0;
   out_5532999626545989618[5] = 0;
   out_5532999626545989618[6] = 0;
   out_5532999626545989618[7] = 0;
   out_5532999626545989618[8] = 0;
   out_5532999626545989618[9] = 0;
   out_5532999626545989618[10] = 1.0;
   out_5532999626545989618[11] = 0;
   out_5532999626545989618[12] = 0;
   out_5532999626545989618[13] = 0;
   out_5532999626545989618[14] = 0;
   out_5532999626545989618[15] = 0;
   out_5532999626545989618[16] = 0;
   out_5532999626545989618[17] = 0;
   out_5532999626545989618[18] = 0;
   out_5532999626545989618[19] = 0;
   out_5532999626545989618[20] = 1.0;
   out_5532999626545989618[21] = 0;
   out_5532999626545989618[22] = 0;
   out_5532999626545989618[23] = 0;
   out_5532999626545989618[24] = 0;
   out_5532999626545989618[25] = 0;
   out_5532999626545989618[26] = 0;
   out_5532999626545989618[27] = 0;
   out_5532999626545989618[28] = 0;
   out_5532999626545989618[29] = 0;
   out_5532999626545989618[30] = 1.0;
   out_5532999626545989618[31] = 0;
   out_5532999626545989618[32] = 0;
   out_5532999626545989618[33] = 0;
   out_5532999626545989618[34] = 0;
   out_5532999626545989618[35] = 0;
   out_5532999626545989618[36] = 0;
   out_5532999626545989618[37] = 0;
   out_5532999626545989618[38] = 0;
   out_5532999626545989618[39] = 0;
   out_5532999626545989618[40] = 1.0;
   out_5532999626545989618[41] = 0;
   out_5532999626545989618[42] = 0;
   out_5532999626545989618[43] = 0;
   out_5532999626545989618[44] = 0;
   out_5532999626545989618[45] = 0;
   out_5532999626545989618[46] = 0;
   out_5532999626545989618[47] = 0;
   out_5532999626545989618[48] = 0;
   out_5532999626545989618[49] = 0;
   out_5532999626545989618[50] = 1.0;
   out_5532999626545989618[51] = 0;
   out_5532999626545989618[52] = 0;
   out_5532999626545989618[53] = 0;
   out_5532999626545989618[54] = 0;
   out_5532999626545989618[55] = 0;
   out_5532999626545989618[56] = 0;
   out_5532999626545989618[57] = 0;
   out_5532999626545989618[58] = 0;
   out_5532999626545989618[59] = 0;
   out_5532999626545989618[60] = 1.0;
   out_5532999626545989618[61] = 0;
   out_5532999626545989618[62] = 0;
   out_5532999626545989618[63] = 0;
   out_5532999626545989618[64] = 0;
   out_5532999626545989618[65] = 0;
   out_5532999626545989618[66] = 0;
   out_5532999626545989618[67] = 0;
   out_5532999626545989618[68] = 0;
   out_5532999626545989618[69] = 0;
   out_5532999626545989618[70] = 1.0;
   out_5532999626545989618[71] = 0;
   out_5532999626545989618[72] = 0;
   out_5532999626545989618[73] = 0;
   out_5532999626545989618[74] = 0;
   out_5532999626545989618[75] = 0;
   out_5532999626545989618[76] = 0;
   out_5532999626545989618[77] = 0;
   out_5532999626545989618[78] = 0;
   out_5532999626545989618[79] = 0;
   out_5532999626545989618[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4167411836503292574) {
   out_4167411836503292574[0] = state[0];
   out_4167411836503292574[1] = state[1];
   out_4167411836503292574[2] = state[2];
   out_4167411836503292574[3] = state[3];
   out_4167411836503292574[4] = state[4];
   out_4167411836503292574[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4167411836503292574[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4167411836503292574[7] = state[7];
   out_4167411836503292574[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8590541513710137823) {
   out_8590541513710137823[0] = 1;
   out_8590541513710137823[1] = 0;
   out_8590541513710137823[2] = 0;
   out_8590541513710137823[3] = 0;
   out_8590541513710137823[4] = 0;
   out_8590541513710137823[5] = 0;
   out_8590541513710137823[6] = 0;
   out_8590541513710137823[7] = 0;
   out_8590541513710137823[8] = 0;
   out_8590541513710137823[9] = 0;
   out_8590541513710137823[10] = 1;
   out_8590541513710137823[11] = 0;
   out_8590541513710137823[12] = 0;
   out_8590541513710137823[13] = 0;
   out_8590541513710137823[14] = 0;
   out_8590541513710137823[15] = 0;
   out_8590541513710137823[16] = 0;
   out_8590541513710137823[17] = 0;
   out_8590541513710137823[18] = 0;
   out_8590541513710137823[19] = 0;
   out_8590541513710137823[20] = 1;
   out_8590541513710137823[21] = 0;
   out_8590541513710137823[22] = 0;
   out_8590541513710137823[23] = 0;
   out_8590541513710137823[24] = 0;
   out_8590541513710137823[25] = 0;
   out_8590541513710137823[26] = 0;
   out_8590541513710137823[27] = 0;
   out_8590541513710137823[28] = 0;
   out_8590541513710137823[29] = 0;
   out_8590541513710137823[30] = 1;
   out_8590541513710137823[31] = 0;
   out_8590541513710137823[32] = 0;
   out_8590541513710137823[33] = 0;
   out_8590541513710137823[34] = 0;
   out_8590541513710137823[35] = 0;
   out_8590541513710137823[36] = 0;
   out_8590541513710137823[37] = 0;
   out_8590541513710137823[38] = 0;
   out_8590541513710137823[39] = 0;
   out_8590541513710137823[40] = 1;
   out_8590541513710137823[41] = 0;
   out_8590541513710137823[42] = 0;
   out_8590541513710137823[43] = 0;
   out_8590541513710137823[44] = 0;
   out_8590541513710137823[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_8590541513710137823[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_8590541513710137823[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8590541513710137823[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_8590541513710137823[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_8590541513710137823[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_8590541513710137823[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_8590541513710137823[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_8590541513710137823[53] = -9.8000000000000007*dt;
   out_8590541513710137823[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8590541513710137823[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8590541513710137823[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8590541513710137823[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8590541513710137823[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8590541513710137823[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8590541513710137823[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8590541513710137823[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8590541513710137823[62] = 0;
   out_8590541513710137823[63] = 0;
   out_8590541513710137823[64] = 0;
   out_8590541513710137823[65] = 0;
   out_8590541513710137823[66] = 0;
   out_8590541513710137823[67] = 0;
   out_8590541513710137823[68] = 0;
   out_8590541513710137823[69] = 0;
   out_8590541513710137823[70] = 1;
   out_8590541513710137823[71] = 0;
   out_8590541513710137823[72] = 0;
   out_8590541513710137823[73] = 0;
   out_8590541513710137823[74] = 0;
   out_8590541513710137823[75] = 0;
   out_8590541513710137823[76] = 0;
   out_8590541513710137823[77] = 0;
   out_8590541513710137823[78] = 0;
   out_8590541513710137823[79] = 0;
   out_8590541513710137823[80] = 1;
}
void h_25(double *state, double *unused, double *out_7202228893738593090) {
   out_7202228893738593090[0] = state[6];
}
void H_25(double *state, double *unused, double *out_1785192819948740025) {
   out_1785192819948740025[0] = 0;
   out_1785192819948740025[1] = 0;
   out_1785192819948740025[2] = 0;
   out_1785192819948740025[3] = 0;
   out_1785192819948740025[4] = 0;
   out_1785192819948740025[5] = 0;
   out_1785192819948740025[6] = 1;
   out_1785192819948740025[7] = 0;
   out_1785192819948740025[8] = 0;
}
void h_24(double *state, double *unused, double *out_7128733627970278444) {
   out_7128733627970278444[0] = state[4];
   out_7128733627970278444[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1772732778853583111) {
   out_1772732778853583111[0] = 0;
   out_1772732778853583111[1] = 0;
   out_1772732778853583111[2] = 0;
   out_1772732778853583111[3] = 0;
   out_1772732778853583111[4] = 1;
   out_1772732778853583111[5] = 0;
   out_1772732778853583111[6] = 0;
   out_1772732778853583111[7] = 0;
   out_1772732778853583111[8] = 0;
   out_1772732778853583111[9] = 0;
   out_1772732778853583111[10] = 0;
   out_1772732778853583111[11] = 0;
   out_1772732778853583111[12] = 0;
   out_1772732778853583111[13] = 0;
   out_1772732778853583111[14] = 1;
   out_1772732778853583111[15] = 0;
   out_1772732778853583111[16] = 0;
   out_1772732778853583111[17] = 0;
}
void h_30(double *state, double *unused, double *out_258329870510295235) {
   out_258329870510295235[0] = state[4];
}
void H_30(double *state, double *unused, double *out_733140138558508602) {
   out_733140138558508602[0] = 0;
   out_733140138558508602[1] = 0;
   out_733140138558508602[2] = 0;
   out_733140138558508602[3] = 0;
   out_733140138558508602[4] = 1;
   out_733140138558508602[5] = 0;
   out_733140138558508602[6] = 0;
   out_733140138558508602[7] = 0;
   out_733140138558508602[8] = 0;
}
void h_26(double *state, double *unused, double *out_8645166757099240716) {
   out_8645166757099240716[0] = state[7];
}
void H_26(double *state, double *unused, double *out_5526696138822796249) {
   out_5526696138822796249[0] = 0;
   out_5526696138822796249[1] = 0;
   out_5526696138822796249[2] = 0;
   out_5526696138822796249[3] = 0;
   out_5526696138822796249[4] = 0;
   out_5526696138822796249[5] = 0;
   out_5526696138822796249[6] = 0;
   out_5526696138822796249[7] = 1;
   out_5526696138822796249[8] = 0;
}
void h_27(double *state, double *unused, double *out_4822057521104374741) {
   out_4822057521104374741[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2956734209742451819) {
   out_2956734209742451819[0] = 0;
   out_2956734209742451819[1] = 0;
   out_2956734209742451819[2] = 0;
   out_2956734209742451819[3] = 1;
   out_2956734209742451819[4] = 0;
   out_2956734209742451819[5] = 0;
   out_2956734209742451819[6] = 0;
   out_2956734209742451819[7] = 0;
   out_2956734209742451819[8] = 0;
}
void h_29(double *state, double *unused, double *out_4664870852753245596) {
   out_4664870852753245596[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1243371482872900786) {
   out_1243371482872900786[0] = 0;
   out_1243371482872900786[1] = 1;
   out_1243371482872900786[2] = 0;
   out_1243371482872900786[3] = 0;
   out_1243371482872900786[4] = 0;
   out_1243371482872900786[5] = 0;
   out_1243371482872900786[6] = 0;
   out_1243371482872900786[7] = 0;
   out_1243371482872900786[8] = 0;
}
void h_28(double *state, double *unused, double *out_8623013284944331230) {
   out_8623013284944331230[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3839027534196629788) {
   out_3839027534196629788[0] = 1;
   out_3839027534196629788[1] = 0;
   out_3839027534196629788[2] = 0;
   out_3839027534196629788[3] = 0;
   out_3839027534196629788[4] = 0;
   out_3839027534196629788[5] = 0;
   out_3839027534196629788[6] = 0;
   out_3839027534196629788[7] = 0;
   out_3839027534196629788[8] = 0;
}
void h_31(double *state, double *unused, double *out_4041299222984972556) {
   out_4041299222984972556[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1754546858071779597) {
   out_1754546858071779597[0] = 0;
   out_1754546858071779597[1] = 0;
   out_1754546858071779597[2] = 0;
   out_1754546858071779597[3] = 0;
   out_1754546858071779597[4] = 0;
   out_1754546858071779597[5] = 0;
   out_1754546858071779597[6] = 0;
   out_1754546858071779597[7] = 0;
   out_1754546858071779597[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_4756830923943155660) {
  err_fun(nom_x, delta_x, out_4756830923943155660);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_9000188679074390687) {
  inv_err_fun(nom_x, true_x, out_9000188679074390687);
}
void car_H_mod_fun(double *state, double *out_5532999626545989618) {
  H_mod_fun(state, out_5532999626545989618);
}
void car_f_fun(double *state, double dt, double *out_4167411836503292574) {
  f_fun(state,  dt, out_4167411836503292574);
}
void car_F_fun(double *state, double dt, double *out_8590541513710137823) {
  F_fun(state,  dt, out_8590541513710137823);
}
void car_h_25(double *state, double *unused, double *out_7202228893738593090) {
  h_25(state, unused, out_7202228893738593090);
}
void car_H_25(double *state, double *unused, double *out_1785192819948740025) {
  H_25(state, unused, out_1785192819948740025);
}
void car_h_24(double *state, double *unused, double *out_7128733627970278444) {
  h_24(state, unused, out_7128733627970278444);
}
void car_H_24(double *state, double *unused, double *out_1772732778853583111) {
  H_24(state, unused, out_1772732778853583111);
}
void car_h_30(double *state, double *unused, double *out_258329870510295235) {
  h_30(state, unused, out_258329870510295235);
}
void car_H_30(double *state, double *unused, double *out_733140138558508602) {
  H_30(state, unused, out_733140138558508602);
}
void car_h_26(double *state, double *unused, double *out_8645166757099240716) {
  h_26(state, unused, out_8645166757099240716);
}
void car_H_26(double *state, double *unused, double *out_5526696138822796249) {
  H_26(state, unused, out_5526696138822796249);
}
void car_h_27(double *state, double *unused, double *out_4822057521104374741) {
  h_27(state, unused, out_4822057521104374741);
}
void car_H_27(double *state, double *unused, double *out_2956734209742451819) {
  H_27(state, unused, out_2956734209742451819);
}
void car_h_29(double *state, double *unused, double *out_4664870852753245596) {
  h_29(state, unused, out_4664870852753245596);
}
void car_H_29(double *state, double *unused, double *out_1243371482872900786) {
  H_29(state, unused, out_1243371482872900786);
}
void car_h_28(double *state, double *unused, double *out_8623013284944331230) {
  h_28(state, unused, out_8623013284944331230);
}
void car_H_28(double *state, double *unused, double *out_3839027534196629788) {
  H_28(state, unused, out_3839027534196629788);
}
void car_h_31(double *state, double *unused, double *out_4041299222984972556) {
  h_31(state, unused, out_4041299222984972556);
}
void car_H_31(double *state, double *unused, double *out_1754546858071779597) {
  H_31(state, unused, out_1754546858071779597);
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
