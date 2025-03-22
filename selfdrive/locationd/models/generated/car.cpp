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
 *                      Code generated with SymPy 1.13.2                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4833700505990300063) {
   out_4833700505990300063[0] = delta_x[0] + nom_x[0];
   out_4833700505990300063[1] = delta_x[1] + nom_x[1];
   out_4833700505990300063[2] = delta_x[2] + nom_x[2];
   out_4833700505990300063[3] = delta_x[3] + nom_x[3];
   out_4833700505990300063[4] = delta_x[4] + nom_x[4];
   out_4833700505990300063[5] = delta_x[5] + nom_x[5];
   out_4833700505990300063[6] = delta_x[6] + nom_x[6];
   out_4833700505990300063[7] = delta_x[7] + nom_x[7];
   out_4833700505990300063[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3150961745119857253) {
   out_3150961745119857253[0] = -nom_x[0] + true_x[0];
   out_3150961745119857253[1] = -nom_x[1] + true_x[1];
   out_3150961745119857253[2] = -nom_x[2] + true_x[2];
   out_3150961745119857253[3] = -nom_x[3] + true_x[3];
   out_3150961745119857253[4] = -nom_x[4] + true_x[4];
   out_3150961745119857253[5] = -nom_x[5] + true_x[5];
   out_3150961745119857253[6] = -nom_x[6] + true_x[6];
   out_3150961745119857253[7] = -nom_x[7] + true_x[7];
   out_3150961745119857253[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4391513468199168225) {
   out_4391513468199168225[0] = 1.0;
   out_4391513468199168225[1] = 0.0;
   out_4391513468199168225[2] = 0.0;
   out_4391513468199168225[3] = 0.0;
   out_4391513468199168225[4] = 0.0;
   out_4391513468199168225[5] = 0.0;
   out_4391513468199168225[6] = 0.0;
   out_4391513468199168225[7] = 0.0;
   out_4391513468199168225[8] = 0.0;
   out_4391513468199168225[9] = 0.0;
   out_4391513468199168225[10] = 1.0;
   out_4391513468199168225[11] = 0.0;
   out_4391513468199168225[12] = 0.0;
   out_4391513468199168225[13] = 0.0;
   out_4391513468199168225[14] = 0.0;
   out_4391513468199168225[15] = 0.0;
   out_4391513468199168225[16] = 0.0;
   out_4391513468199168225[17] = 0.0;
   out_4391513468199168225[18] = 0.0;
   out_4391513468199168225[19] = 0.0;
   out_4391513468199168225[20] = 1.0;
   out_4391513468199168225[21] = 0.0;
   out_4391513468199168225[22] = 0.0;
   out_4391513468199168225[23] = 0.0;
   out_4391513468199168225[24] = 0.0;
   out_4391513468199168225[25] = 0.0;
   out_4391513468199168225[26] = 0.0;
   out_4391513468199168225[27] = 0.0;
   out_4391513468199168225[28] = 0.0;
   out_4391513468199168225[29] = 0.0;
   out_4391513468199168225[30] = 1.0;
   out_4391513468199168225[31] = 0.0;
   out_4391513468199168225[32] = 0.0;
   out_4391513468199168225[33] = 0.0;
   out_4391513468199168225[34] = 0.0;
   out_4391513468199168225[35] = 0.0;
   out_4391513468199168225[36] = 0.0;
   out_4391513468199168225[37] = 0.0;
   out_4391513468199168225[38] = 0.0;
   out_4391513468199168225[39] = 0.0;
   out_4391513468199168225[40] = 1.0;
   out_4391513468199168225[41] = 0.0;
   out_4391513468199168225[42] = 0.0;
   out_4391513468199168225[43] = 0.0;
   out_4391513468199168225[44] = 0.0;
   out_4391513468199168225[45] = 0.0;
   out_4391513468199168225[46] = 0.0;
   out_4391513468199168225[47] = 0.0;
   out_4391513468199168225[48] = 0.0;
   out_4391513468199168225[49] = 0.0;
   out_4391513468199168225[50] = 1.0;
   out_4391513468199168225[51] = 0.0;
   out_4391513468199168225[52] = 0.0;
   out_4391513468199168225[53] = 0.0;
   out_4391513468199168225[54] = 0.0;
   out_4391513468199168225[55] = 0.0;
   out_4391513468199168225[56] = 0.0;
   out_4391513468199168225[57] = 0.0;
   out_4391513468199168225[58] = 0.0;
   out_4391513468199168225[59] = 0.0;
   out_4391513468199168225[60] = 1.0;
   out_4391513468199168225[61] = 0.0;
   out_4391513468199168225[62] = 0.0;
   out_4391513468199168225[63] = 0.0;
   out_4391513468199168225[64] = 0.0;
   out_4391513468199168225[65] = 0.0;
   out_4391513468199168225[66] = 0.0;
   out_4391513468199168225[67] = 0.0;
   out_4391513468199168225[68] = 0.0;
   out_4391513468199168225[69] = 0.0;
   out_4391513468199168225[70] = 1.0;
   out_4391513468199168225[71] = 0.0;
   out_4391513468199168225[72] = 0.0;
   out_4391513468199168225[73] = 0.0;
   out_4391513468199168225[74] = 0.0;
   out_4391513468199168225[75] = 0.0;
   out_4391513468199168225[76] = 0.0;
   out_4391513468199168225[77] = 0.0;
   out_4391513468199168225[78] = 0.0;
   out_4391513468199168225[79] = 0.0;
   out_4391513468199168225[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_108397326077436237) {
   out_108397326077436237[0] = state[0];
   out_108397326077436237[1] = state[1];
   out_108397326077436237[2] = state[2];
   out_108397326077436237[3] = state[3];
   out_108397326077436237[4] = state[4];
   out_108397326077436237[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_108397326077436237[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_108397326077436237[7] = state[7];
   out_108397326077436237[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3321654844413133728) {
   out_3321654844413133728[0] = 1;
   out_3321654844413133728[1] = 0;
   out_3321654844413133728[2] = 0;
   out_3321654844413133728[3] = 0;
   out_3321654844413133728[4] = 0;
   out_3321654844413133728[5] = 0;
   out_3321654844413133728[6] = 0;
   out_3321654844413133728[7] = 0;
   out_3321654844413133728[8] = 0;
   out_3321654844413133728[9] = 0;
   out_3321654844413133728[10] = 1;
   out_3321654844413133728[11] = 0;
   out_3321654844413133728[12] = 0;
   out_3321654844413133728[13] = 0;
   out_3321654844413133728[14] = 0;
   out_3321654844413133728[15] = 0;
   out_3321654844413133728[16] = 0;
   out_3321654844413133728[17] = 0;
   out_3321654844413133728[18] = 0;
   out_3321654844413133728[19] = 0;
   out_3321654844413133728[20] = 1;
   out_3321654844413133728[21] = 0;
   out_3321654844413133728[22] = 0;
   out_3321654844413133728[23] = 0;
   out_3321654844413133728[24] = 0;
   out_3321654844413133728[25] = 0;
   out_3321654844413133728[26] = 0;
   out_3321654844413133728[27] = 0;
   out_3321654844413133728[28] = 0;
   out_3321654844413133728[29] = 0;
   out_3321654844413133728[30] = 1;
   out_3321654844413133728[31] = 0;
   out_3321654844413133728[32] = 0;
   out_3321654844413133728[33] = 0;
   out_3321654844413133728[34] = 0;
   out_3321654844413133728[35] = 0;
   out_3321654844413133728[36] = 0;
   out_3321654844413133728[37] = 0;
   out_3321654844413133728[38] = 0;
   out_3321654844413133728[39] = 0;
   out_3321654844413133728[40] = 1;
   out_3321654844413133728[41] = 0;
   out_3321654844413133728[42] = 0;
   out_3321654844413133728[43] = 0;
   out_3321654844413133728[44] = 0;
   out_3321654844413133728[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3321654844413133728[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3321654844413133728[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3321654844413133728[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3321654844413133728[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3321654844413133728[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3321654844413133728[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3321654844413133728[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3321654844413133728[53] = -9.8000000000000007*dt;
   out_3321654844413133728[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3321654844413133728[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3321654844413133728[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3321654844413133728[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3321654844413133728[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3321654844413133728[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3321654844413133728[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3321654844413133728[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3321654844413133728[62] = 0;
   out_3321654844413133728[63] = 0;
   out_3321654844413133728[64] = 0;
   out_3321654844413133728[65] = 0;
   out_3321654844413133728[66] = 0;
   out_3321654844413133728[67] = 0;
   out_3321654844413133728[68] = 0;
   out_3321654844413133728[69] = 0;
   out_3321654844413133728[70] = 1;
   out_3321654844413133728[71] = 0;
   out_3321654844413133728[72] = 0;
   out_3321654844413133728[73] = 0;
   out_3321654844413133728[74] = 0;
   out_3321654844413133728[75] = 0;
   out_3321654844413133728[76] = 0;
   out_3321654844413133728[77] = 0;
   out_3321654844413133728[78] = 0;
   out_3321654844413133728[79] = 0;
   out_3321654844413133728[80] = 1;
}
void h_25(double *state, double *unused, double *out_5561409136577752067) {
   out_5561409136577752067[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7376670758734769002) {
   out_7376670758734769002[0] = 0;
   out_7376670758734769002[1] = 0;
   out_7376670758734769002[2] = 0;
   out_7376670758734769002[3] = 0;
   out_7376670758734769002[4] = 0;
   out_7376670758734769002[5] = 0;
   out_7376670758734769002[6] = 1;
   out_7376670758734769002[7] = 0;
   out_7376670758734769002[8] = 0;
}
void h_24(double *state, double *unused, double *out_5250416858832704477) {
   out_5250416858832704477[0] = state[4];
   out_5250416858832704477[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7773316063088628497) {
   out_7773316063088628497[0] = 0;
   out_7773316063088628497[1] = 0;
   out_7773316063088628497[2] = 0;
   out_7773316063088628497[3] = 0;
   out_7773316063088628497[4] = 1;
   out_7773316063088628497[5] = 0;
   out_7773316063088628497[6] = 0;
   out_7773316063088628497[7] = 0;
   out_7773316063088628497[8] = 0;
   out_7773316063088628497[9] = 0;
   out_7773316063088628497[10] = 0;
   out_7773316063088628497[11] = 0;
   out_7773316063088628497[12] = 0;
   out_7773316063088628497[13] = 0;
   out_7773316063088628497[14] = 1;
   out_7773316063088628497[15] = 0;
   out_7773316063088628497[16] = 0;
   out_7773316063088628497[17] = 0;
}
void h_30(double *state, double *unused, double *out_1923959608323729717) {
   out_1923959608323729717[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4858337800227520375) {
   out_4858337800227520375[0] = 0;
   out_4858337800227520375[1] = 0;
   out_4858337800227520375[2] = 0;
   out_4858337800227520375[3] = 0;
   out_4858337800227520375[4] = 1;
   out_4858337800227520375[5] = 0;
   out_4858337800227520375[6] = 0;
   out_4858337800227520375[7] = 0;
   out_4858337800227520375[8] = 0;
}
void h_26(double *state, double *unused, double *out_6925632875984575362) {
   out_6925632875984575362[0] = state[7];
}
void H_26(double *state, double *unused, double *out_7328569996100726390) {
   out_7328569996100726390[0] = 0;
   out_7328569996100726390[1] = 0;
   out_7328569996100726390[2] = 0;
   out_7328569996100726390[3] = 0;
   out_7328569996100726390[4] = 0;
   out_7328569996100726390[5] = 0;
   out_7328569996100726390[6] = 0;
   out_7328569996100726390[7] = 1;
   out_7328569996100726390[8] = 0;
}
void h_27(double *state, double *unused, double *out_3142663523509898041) {
   out_3142663523509898041[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7033101112027945286) {
   out_7033101112027945286[0] = 0;
   out_7033101112027945286[1] = 0;
   out_7033101112027945286[2] = 0;
   out_7033101112027945286[3] = 1;
   out_7033101112027945286[4] = 0;
   out_7033101112027945286[5] = 0;
   out_7033101112027945286[6] = 0;
   out_7033101112027945286[7] = 0;
   out_7033101112027945286[8] = 0;
}
void h_29(double *state, double *unused, double *out_573705741813233675) {
   out_573705741813233675[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4348106455913128191) {
   out_4348106455913128191[0] = 0;
   out_4348106455913128191[1] = 1;
   out_4348106455913128191[2] = 0;
   out_4348106455913128191[3] = 0;
   out_4348106455913128191[4] = 0;
   out_4348106455913128191[5] = 0;
   out_4348106455913128191[6] = 0;
   out_4348106455913128191[7] = 0;
   out_4348106455913128191[8] = 0;
}
void h_28(double *state, double *unused, double *out_8905039032785804429) {
   out_8905039032785804429[0] = state[0];
}
void H_28(double *state, double *unused, double *out_9016238600726892851) {
   out_9016238600726892851[0] = 1;
   out_9016238600726892851[1] = 0;
   out_9016238600726892851[2] = 0;
   out_9016238600726892851[3] = 0;
   out_9016238600726892851[4] = 0;
   out_9016238600726892851[5] = 0;
   out_9016238600726892851[6] = 0;
   out_9016238600726892851[7] = 0;
   out_9016238600726892851[8] = 0;
}
void h_31(double *state, double *unused, double *out_6440723806110306278) {
   out_6440723806110306278[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6702361893867374914) {
   out_6702361893867374914[0] = 0;
   out_6702361893867374914[1] = 0;
   out_6702361893867374914[2] = 0;
   out_6702361893867374914[3] = 0;
   out_6702361893867374914[4] = 0;
   out_6702361893867374914[5] = 0;
   out_6702361893867374914[6] = 0;
   out_6702361893867374914[7] = 0;
   out_6702361893867374914[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_4833700505990300063) {
  err_fun(nom_x, delta_x, out_4833700505990300063);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3150961745119857253) {
  inv_err_fun(nom_x, true_x, out_3150961745119857253);
}
void car_H_mod_fun(double *state, double *out_4391513468199168225) {
  H_mod_fun(state, out_4391513468199168225);
}
void car_f_fun(double *state, double dt, double *out_108397326077436237) {
  f_fun(state,  dt, out_108397326077436237);
}
void car_F_fun(double *state, double dt, double *out_3321654844413133728) {
  F_fun(state,  dt, out_3321654844413133728);
}
void car_h_25(double *state, double *unused, double *out_5561409136577752067) {
  h_25(state, unused, out_5561409136577752067);
}
void car_H_25(double *state, double *unused, double *out_7376670758734769002) {
  H_25(state, unused, out_7376670758734769002);
}
void car_h_24(double *state, double *unused, double *out_5250416858832704477) {
  h_24(state, unused, out_5250416858832704477);
}
void car_H_24(double *state, double *unused, double *out_7773316063088628497) {
  H_24(state, unused, out_7773316063088628497);
}
void car_h_30(double *state, double *unused, double *out_1923959608323729717) {
  h_30(state, unused, out_1923959608323729717);
}
void car_H_30(double *state, double *unused, double *out_4858337800227520375) {
  H_30(state, unused, out_4858337800227520375);
}
void car_h_26(double *state, double *unused, double *out_6925632875984575362) {
  h_26(state, unused, out_6925632875984575362);
}
void car_H_26(double *state, double *unused, double *out_7328569996100726390) {
  H_26(state, unused, out_7328569996100726390);
}
void car_h_27(double *state, double *unused, double *out_3142663523509898041) {
  h_27(state, unused, out_3142663523509898041);
}
void car_H_27(double *state, double *unused, double *out_7033101112027945286) {
  H_27(state, unused, out_7033101112027945286);
}
void car_h_29(double *state, double *unused, double *out_573705741813233675) {
  h_29(state, unused, out_573705741813233675);
}
void car_H_29(double *state, double *unused, double *out_4348106455913128191) {
  H_29(state, unused, out_4348106455913128191);
}
void car_h_28(double *state, double *unused, double *out_8905039032785804429) {
  h_28(state, unused, out_8905039032785804429);
}
void car_H_28(double *state, double *unused, double *out_9016238600726892851) {
  H_28(state, unused, out_9016238600726892851);
}
void car_h_31(double *state, double *unused, double *out_6440723806110306278) {
  h_31(state, unused, out_6440723806110306278);
}
void car_H_31(double *state, double *unused, double *out_6702361893867374914) {
  H_31(state, unused, out_6702361893867374914);
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
