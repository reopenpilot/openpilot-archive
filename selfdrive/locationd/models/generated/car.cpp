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
void err_fun(double *nom_x, double *delta_x, double *out_1296268209949828951) {
   out_1296268209949828951[0] = delta_x[0] + nom_x[0];
   out_1296268209949828951[1] = delta_x[1] + nom_x[1];
   out_1296268209949828951[2] = delta_x[2] + nom_x[2];
   out_1296268209949828951[3] = delta_x[3] + nom_x[3];
   out_1296268209949828951[4] = delta_x[4] + nom_x[4];
   out_1296268209949828951[5] = delta_x[5] + nom_x[5];
   out_1296268209949828951[6] = delta_x[6] + nom_x[6];
   out_1296268209949828951[7] = delta_x[7] + nom_x[7];
   out_1296268209949828951[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2788730935649598703) {
   out_2788730935649598703[0] = -nom_x[0] + true_x[0];
   out_2788730935649598703[1] = -nom_x[1] + true_x[1];
   out_2788730935649598703[2] = -nom_x[2] + true_x[2];
   out_2788730935649598703[3] = -nom_x[3] + true_x[3];
   out_2788730935649598703[4] = -nom_x[4] + true_x[4];
   out_2788730935649598703[5] = -nom_x[5] + true_x[5];
   out_2788730935649598703[6] = -nom_x[6] + true_x[6];
   out_2788730935649598703[7] = -nom_x[7] + true_x[7];
   out_2788730935649598703[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_5159729146107839471) {
   out_5159729146107839471[0] = 1.0;
   out_5159729146107839471[1] = 0;
   out_5159729146107839471[2] = 0;
   out_5159729146107839471[3] = 0;
   out_5159729146107839471[4] = 0;
   out_5159729146107839471[5] = 0;
   out_5159729146107839471[6] = 0;
   out_5159729146107839471[7] = 0;
   out_5159729146107839471[8] = 0;
   out_5159729146107839471[9] = 0;
   out_5159729146107839471[10] = 1.0;
   out_5159729146107839471[11] = 0;
   out_5159729146107839471[12] = 0;
   out_5159729146107839471[13] = 0;
   out_5159729146107839471[14] = 0;
   out_5159729146107839471[15] = 0;
   out_5159729146107839471[16] = 0;
   out_5159729146107839471[17] = 0;
   out_5159729146107839471[18] = 0;
   out_5159729146107839471[19] = 0;
   out_5159729146107839471[20] = 1.0;
   out_5159729146107839471[21] = 0;
   out_5159729146107839471[22] = 0;
   out_5159729146107839471[23] = 0;
   out_5159729146107839471[24] = 0;
   out_5159729146107839471[25] = 0;
   out_5159729146107839471[26] = 0;
   out_5159729146107839471[27] = 0;
   out_5159729146107839471[28] = 0;
   out_5159729146107839471[29] = 0;
   out_5159729146107839471[30] = 1.0;
   out_5159729146107839471[31] = 0;
   out_5159729146107839471[32] = 0;
   out_5159729146107839471[33] = 0;
   out_5159729146107839471[34] = 0;
   out_5159729146107839471[35] = 0;
   out_5159729146107839471[36] = 0;
   out_5159729146107839471[37] = 0;
   out_5159729146107839471[38] = 0;
   out_5159729146107839471[39] = 0;
   out_5159729146107839471[40] = 1.0;
   out_5159729146107839471[41] = 0;
   out_5159729146107839471[42] = 0;
   out_5159729146107839471[43] = 0;
   out_5159729146107839471[44] = 0;
   out_5159729146107839471[45] = 0;
   out_5159729146107839471[46] = 0;
   out_5159729146107839471[47] = 0;
   out_5159729146107839471[48] = 0;
   out_5159729146107839471[49] = 0;
   out_5159729146107839471[50] = 1.0;
   out_5159729146107839471[51] = 0;
   out_5159729146107839471[52] = 0;
   out_5159729146107839471[53] = 0;
   out_5159729146107839471[54] = 0;
   out_5159729146107839471[55] = 0;
   out_5159729146107839471[56] = 0;
   out_5159729146107839471[57] = 0;
   out_5159729146107839471[58] = 0;
   out_5159729146107839471[59] = 0;
   out_5159729146107839471[60] = 1.0;
   out_5159729146107839471[61] = 0;
   out_5159729146107839471[62] = 0;
   out_5159729146107839471[63] = 0;
   out_5159729146107839471[64] = 0;
   out_5159729146107839471[65] = 0;
   out_5159729146107839471[66] = 0;
   out_5159729146107839471[67] = 0;
   out_5159729146107839471[68] = 0;
   out_5159729146107839471[69] = 0;
   out_5159729146107839471[70] = 1.0;
   out_5159729146107839471[71] = 0;
   out_5159729146107839471[72] = 0;
   out_5159729146107839471[73] = 0;
   out_5159729146107839471[74] = 0;
   out_5159729146107839471[75] = 0;
   out_5159729146107839471[76] = 0;
   out_5159729146107839471[77] = 0;
   out_5159729146107839471[78] = 0;
   out_5159729146107839471[79] = 0;
   out_5159729146107839471[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8709377983519691570) {
   out_8709377983519691570[0] = state[0];
   out_8709377983519691570[1] = state[1];
   out_8709377983519691570[2] = state[2];
   out_8709377983519691570[3] = state[3];
   out_8709377983519691570[4] = state[4];
   out_8709377983519691570[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8709377983519691570[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8709377983519691570[7] = state[7];
   out_8709377983519691570[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2270539376338146151) {
   out_2270539376338146151[0] = 1;
   out_2270539376338146151[1] = 0;
   out_2270539376338146151[2] = 0;
   out_2270539376338146151[3] = 0;
   out_2270539376338146151[4] = 0;
   out_2270539376338146151[5] = 0;
   out_2270539376338146151[6] = 0;
   out_2270539376338146151[7] = 0;
   out_2270539376338146151[8] = 0;
   out_2270539376338146151[9] = 0;
   out_2270539376338146151[10] = 1;
   out_2270539376338146151[11] = 0;
   out_2270539376338146151[12] = 0;
   out_2270539376338146151[13] = 0;
   out_2270539376338146151[14] = 0;
   out_2270539376338146151[15] = 0;
   out_2270539376338146151[16] = 0;
   out_2270539376338146151[17] = 0;
   out_2270539376338146151[18] = 0;
   out_2270539376338146151[19] = 0;
   out_2270539376338146151[20] = 1;
   out_2270539376338146151[21] = 0;
   out_2270539376338146151[22] = 0;
   out_2270539376338146151[23] = 0;
   out_2270539376338146151[24] = 0;
   out_2270539376338146151[25] = 0;
   out_2270539376338146151[26] = 0;
   out_2270539376338146151[27] = 0;
   out_2270539376338146151[28] = 0;
   out_2270539376338146151[29] = 0;
   out_2270539376338146151[30] = 1;
   out_2270539376338146151[31] = 0;
   out_2270539376338146151[32] = 0;
   out_2270539376338146151[33] = 0;
   out_2270539376338146151[34] = 0;
   out_2270539376338146151[35] = 0;
   out_2270539376338146151[36] = 0;
   out_2270539376338146151[37] = 0;
   out_2270539376338146151[38] = 0;
   out_2270539376338146151[39] = 0;
   out_2270539376338146151[40] = 1;
   out_2270539376338146151[41] = 0;
   out_2270539376338146151[42] = 0;
   out_2270539376338146151[43] = 0;
   out_2270539376338146151[44] = 0;
   out_2270539376338146151[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2270539376338146151[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2270539376338146151[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2270539376338146151[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2270539376338146151[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2270539376338146151[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2270539376338146151[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2270539376338146151[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2270539376338146151[53] = -9.8000000000000007*dt;
   out_2270539376338146151[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2270539376338146151[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2270539376338146151[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2270539376338146151[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2270539376338146151[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2270539376338146151[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2270539376338146151[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2270539376338146151[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2270539376338146151[62] = 0;
   out_2270539376338146151[63] = 0;
   out_2270539376338146151[64] = 0;
   out_2270539376338146151[65] = 0;
   out_2270539376338146151[66] = 0;
   out_2270539376338146151[67] = 0;
   out_2270539376338146151[68] = 0;
   out_2270539376338146151[69] = 0;
   out_2270539376338146151[70] = 1;
   out_2270539376338146151[71] = 0;
   out_2270539376338146151[72] = 0;
   out_2270539376338146151[73] = 0;
   out_2270539376338146151[74] = 0;
   out_2270539376338146151[75] = 0;
   out_2270539376338146151[76] = 0;
   out_2270539376338146151[77] = 0;
   out_2270539376338146151[78] = 0;
   out_2270539376338146151[79] = 0;
   out_2270539376338146151[80] = 1;
}
void h_25(double *state, double *unused, double *out_2217806964892823977) {
   out_2217806964892823977[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5841695292656755042) {
   out_5841695292656755042[0] = 0;
   out_5841695292656755042[1] = 0;
   out_5841695292656755042[2] = 0;
   out_5841695292656755042[3] = 0;
   out_5841695292656755042[4] = 0;
   out_5841695292656755042[5] = 0;
   out_5841695292656755042[6] = 1;
   out_5841695292656755042[7] = 0;
   out_5841695292656755042[8] = 0;
}
void h_24(double *state, double *unused, double *out_6105296775999134634) {
   out_6105296775999134634[0] = state[4];
   out_6105296775999134634[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2283769693854431906) {
   out_2283769693854431906[0] = 0;
   out_2283769693854431906[1] = 0;
   out_2283769693854431906[2] = 0;
   out_2283769693854431906[3] = 0;
   out_2283769693854431906[4] = 1;
   out_2283769693854431906[5] = 0;
   out_2283769693854431906[6] = 0;
   out_2283769693854431906[7] = 0;
   out_2283769693854431906[8] = 0;
   out_2283769693854431906[9] = 0;
   out_2283769693854431906[10] = 0;
   out_2283769693854431906[11] = 0;
   out_2283769693854431906[12] = 0;
   out_2283769693854431906[13] = 0;
   out_2283769693854431906[14] = 1;
   out_2283769693854431906[15] = 0;
   out_2283769693854431906[16] = 0;
   out_2283769693854431906[17] = 0;
}
void h_30(double *state, double *unused, double *out_8544144396393360012) {
   out_8544144396393360012[0] = state[4];
}
void H_30(double *state, double *unused, double *out_8077352450925188376) {
   out_8077352450925188376[0] = 0;
   out_8077352450925188376[1] = 0;
   out_8077352450925188376[2] = 0;
   out_8077352450925188376[3] = 0;
   out_8077352450925188376[4] = 1;
   out_8077352450925188376[5] = 0;
   out_8077352450925188376[6] = 0;
   out_8077352450925188376[7] = 0;
   out_8077352450925188376[8] = 0;
}
void h_26(double *state, double *unused, double *out_7298194356507493953) {
   out_7298194356507493953[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8863545462178740350) {
   out_8863545462178740350[0] = 0;
   out_8863545462178740350[1] = 0;
   out_8863545462178740350[2] = 0;
   out_8863545462178740350[3] = 0;
   out_8863545462178740350[4] = 0;
   out_8863545462178740350[5] = 0;
   out_8863545462178740350[6] = 0;
   out_8863545462178740350[7] = 1;
   out_8863545462178740350[8] = 0;
}
void h_27(double *state, double *unused, double *out_3385550765968965714) {
   out_3385550765968965714[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5902589139124763465) {
   out_5902589139124763465[0] = 0;
   out_5902589139124763465[1] = 0;
   out_5902589139124763465[2] = 0;
   out_5902589139124763465[3] = 1;
   out_5902589139124763465[4] = 0;
   out_5902589139124763465[5] = 0;
   out_5902589139124763465[6] = 0;
   out_5902589139124763465[7] = 0;
   out_5902589139124763465[8] = 0;
}
void h_29(double *state, double *unused, double *out_6421315831022044018) {
   out_6421315831022044018[0] = state[1];
}
void H_29(double *state, double *unused, double *out_8587583795239580560) {
   out_8587583795239580560[0] = 0;
   out_8587583795239580560[1] = 1;
   out_8587583795239580560[2] = 0;
   out_8587583795239580560[3] = 0;
   out_8587583795239580560[4] = 0;
   out_8587583795239580560[5] = 0;
   out_8587583795239580560[6] = 0;
   out_8587583795239580560[7] = 0;
   out_8587583795239580560[8] = 0;
}
void h_28(double *state, double *unused, double *out_1616122501691879931) {
   out_1616122501691879931[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3505184778170049986) {
   out_3505184778170049986[0] = 1;
   out_3505184778170049986[1] = 0;
   out_3505184778170049986[2] = 0;
   out_3505184778170049986[3] = 0;
   out_3505184778170049986[4] = 0;
   out_3505184778170049986[5] = 0;
   out_3505184778170049986[6] = 0;
   out_3505184778170049986[7] = 0;
   out_3505184778170049986[8] = 0;
}
void h_31(double *state, double *unused, double *out_6422070511825717907) {
   out_6422070511825717907[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8237337359945388874) {
   out_8237337359945388874[0] = 0;
   out_8237337359945388874[1] = 0;
   out_8237337359945388874[2] = 0;
   out_8237337359945388874[3] = 0;
   out_8237337359945388874[4] = 0;
   out_8237337359945388874[5] = 0;
   out_8237337359945388874[6] = 0;
   out_8237337359945388874[7] = 0;
   out_8237337359945388874[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_1296268209949828951) {
  err_fun(nom_x, delta_x, out_1296268209949828951);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2788730935649598703) {
  inv_err_fun(nom_x, true_x, out_2788730935649598703);
}
void car_H_mod_fun(double *state, double *out_5159729146107839471) {
  H_mod_fun(state, out_5159729146107839471);
}
void car_f_fun(double *state, double dt, double *out_8709377983519691570) {
  f_fun(state,  dt, out_8709377983519691570);
}
void car_F_fun(double *state, double dt, double *out_2270539376338146151) {
  F_fun(state,  dt, out_2270539376338146151);
}
void car_h_25(double *state, double *unused, double *out_2217806964892823977) {
  h_25(state, unused, out_2217806964892823977);
}
void car_H_25(double *state, double *unused, double *out_5841695292656755042) {
  H_25(state, unused, out_5841695292656755042);
}
void car_h_24(double *state, double *unused, double *out_6105296775999134634) {
  h_24(state, unused, out_6105296775999134634);
}
void car_H_24(double *state, double *unused, double *out_2283769693854431906) {
  H_24(state, unused, out_2283769693854431906);
}
void car_h_30(double *state, double *unused, double *out_8544144396393360012) {
  h_30(state, unused, out_8544144396393360012);
}
void car_H_30(double *state, double *unused, double *out_8077352450925188376) {
  H_30(state, unused, out_8077352450925188376);
}
void car_h_26(double *state, double *unused, double *out_7298194356507493953) {
  h_26(state, unused, out_7298194356507493953);
}
void car_H_26(double *state, double *unused, double *out_8863545462178740350) {
  H_26(state, unused, out_8863545462178740350);
}
void car_h_27(double *state, double *unused, double *out_3385550765968965714) {
  h_27(state, unused, out_3385550765968965714);
}
void car_H_27(double *state, double *unused, double *out_5902589139124763465) {
  H_27(state, unused, out_5902589139124763465);
}
void car_h_29(double *state, double *unused, double *out_6421315831022044018) {
  h_29(state, unused, out_6421315831022044018);
}
void car_H_29(double *state, double *unused, double *out_8587583795239580560) {
  H_29(state, unused, out_8587583795239580560);
}
void car_h_28(double *state, double *unused, double *out_1616122501691879931) {
  h_28(state, unused, out_1616122501691879931);
}
void car_H_28(double *state, double *unused, double *out_3505184778170049986) {
  H_28(state, unused, out_3505184778170049986);
}
void car_h_31(double *state, double *unused, double *out_6422070511825717907) {
  h_31(state, unused, out_6422070511825717907);
}
void car_H_31(double *state, double *unused, double *out_8237337359945388874) {
  H_31(state, unused, out_8237337359945388874);
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
