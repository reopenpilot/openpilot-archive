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
void err_fun(double *nom_x, double *delta_x, double *out_5988043674990340612) {
   out_5988043674990340612[0] = delta_x[0] + nom_x[0];
   out_5988043674990340612[1] = delta_x[1] + nom_x[1];
   out_5988043674990340612[2] = delta_x[2] + nom_x[2];
   out_5988043674990340612[3] = delta_x[3] + nom_x[3];
   out_5988043674990340612[4] = delta_x[4] + nom_x[4];
   out_5988043674990340612[5] = delta_x[5] + nom_x[5];
   out_5988043674990340612[6] = delta_x[6] + nom_x[6];
   out_5988043674990340612[7] = delta_x[7] + nom_x[7];
   out_5988043674990340612[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6542235054988891671) {
   out_6542235054988891671[0] = -nom_x[0] + true_x[0];
   out_6542235054988891671[1] = -nom_x[1] + true_x[1];
   out_6542235054988891671[2] = -nom_x[2] + true_x[2];
   out_6542235054988891671[3] = -nom_x[3] + true_x[3];
   out_6542235054988891671[4] = -nom_x[4] + true_x[4];
   out_6542235054988891671[5] = -nom_x[5] + true_x[5];
   out_6542235054988891671[6] = -nom_x[6] + true_x[6];
   out_6542235054988891671[7] = -nom_x[7] + true_x[7];
   out_6542235054988891671[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8514494013080158613) {
   out_8514494013080158613[0] = 1.0;
   out_8514494013080158613[1] = 0;
   out_8514494013080158613[2] = 0;
   out_8514494013080158613[3] = 0;
   out_8514494013080158613[4] = 0;
   out_8514494013080158613[5] = 0;
   out_8514494013080158613[6] = 0;
   out_8514494013080158613[7] = 0;
   out_8514494013080158613[8] = 0;
   out_8514494013080158613[9] = 0;
   out_8514494013080158613[10] = 1.0;
   out_8514494013080158613[11] = 0;
   out_8514494013080158613[12] = 0;
   out_8514494013080158613[13] = 0;
   out_8514494013080158613[14] = 0;
   out_8514494013080158613[15] = 0;
   out_8514494013080158613[16] = 0;
   out_8514494013080158613[17] = 0;
   out_8514494013080158613[18] = 0;
   out_8514494013080158613[19] = 0;
   out_8514494013080158613[20] = 1.0;
   out_8514494013080158613[21] = 0;
   out_8514494013080158613[22] = 0;
   out_8514494013080158613[23] = 0;
   out_8514494013080158613[24] = 0;
   out_8514494013080158613[25] = 0;
   out_8514494013080158613[26] = 0;
   out_8514494013080158613[27] = 0;
   out_8514494013080158613[28] = 0;
   out_8514494013080158613[29] = 0;
   out_8514494013080158613[30] = 1.0;
   out_8514494013080158613[31] = 0;
   out_8514494013080158613[32] = 0;
   out_8514494013080158613[33] = 0;
   out_8514494013080158613[34] = 0;
   out_8514494013080158613[35] = 0;
   out_8514494013080158613[36] = 0;
   out_8514494013080158613[37] = 0;
   out_8514494013080158613[38] = 0;
   out_8514494013080158613[39] = 0;
   out_8514494013080158613[40] = 1.0;
   out_8514494013080158613[41] = 0;
   out_8514494013080158613[42] = 0;
   out_8514494013080158613[43] = 0;
   out_8514494013080158613[44] = 0;
   out_8514494013080158613[45] = 0;
   out_8514494013080158613[46] = 0;
   out_8514494013080158613[47] = 0;
   out_8514494013080158613[48] = 0;
   out_8514494013080158613[49] = 0;
   out_8514494013080158613[50] = 1.0;
   out_8514494013080158613[51] = 0;
   out_8514494013080158613[52] = 0;
   out_8514494013080158613[53] = 0;
   out_8514494013080158613[54] = 0;
   out_8514494013080158613[55] = 0;
   out_8514494013080158613[56] = 0;
   out_8514494013080158613[57] = 0;
   out_8514494013080158613[58] = 0;
   out_8514494013080158613[59] = 0;
   out_8514494013080158613[60] = 1.0;
   out_8514494013080158613[61] = 0;
   out_8514494013080158613[62] = 0;
   out_8514494013080158613[63] = 0;
   out_8514494013080158613[64] = 0;
   out_8514494013080158613[65] = 0;
   out_8514494013080158613[66] = 0;
   out_8514494013080158613[67] = 0;
   out_8514494013080158613[68] = 0;
   out_8514494013080158613[69] = 0;
   out_8514494013080158613[70] = 1.0;
   out_8514494013080158613[71] = 0;
   out_8514494013080158613[72] = 0;
   out_8514494013080158613[73] = 0;
   out_8514494013080158613[74] = 0;
   out_8514494013080158613[75] = 0;
   out_8514494013080158613[76] = 0;
   out_8514494013080158613[77] = 0;
   out_8514494013080158613[78] = 0;
   out_8514494013080158613[79] = 0;
   out_8514494013080158613[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1676658603594809674) {
   out_1676658603594809674[0] = state[0];
   out_1676658603594809674[1] = state[1];
   out_1676658603594809674[2] = state[2];
   out_1676658603594809674[3] = state[3];
   out_1676658603594809674[4] = state[4];
   out_1676658603594809674[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_1676658603594809674[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1676658603594809674[7] = state[7];
   out_1676658603594809674[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5051818034348085702) {
   out_5051818034348085702[0] = 1;
   out_5051818034348085702[1] = 0;
   out_5051818034348085702[2] = 0;
   out_5051818034348085702[3] = 0;
   out_5051818034348085702[4] = 0;
   out_5051818034348085702[5] = 0;
   out_5051818034348085702[6] = 0;
   out_5051818034348085702[7] = 0;
   out_5051818034348085702[8] = 0;
   out_5051818034348085702[9] = 0;
   out_5051818034348085702[10] = 1;
   out_5051818034348085702[11] = 0;
   out_5051818034348085702[12] = 0;
   out_5051818034348085702[13] = 0;
   out_5051818034348085702[14] = 0;
   out_5051818034348085702[15] = 0;
   out_5051818034348085702[16] = 0;
   out_5051818034348085702[17] = 0;
   out_5051818034348085702[18] = 0;
   out_5051818034348085702[19] = 0;
   out_5051818034348085702[20] = 1;
   out_5051818034348085702[21] = 0;
   out_5051818034348085702[22] = 0;
   out_5051818034348085702[23] = 0;
   out_5051818034348085702[24] = 0;
   out_5051818034348085702[25] = 0;
   out_5051818034348085702[26] = 0;
   out_5051818034348085702[27] = 0;
   out_5051818034348085702[28] = 0;
   out_5051818034348085702[29] = 0;
   out_5051818034348085702[30] = 1;
   out_5051818034348085702[31] = 0;
   out_5051818034348085702[32] = 0;
   out_5051818034348085702[33] = 0;
   out_5051818034348085702[34] = 0;
   out_5051818034348085702[35] = 0;
   out_5051818034348085702[36] = 0;
   out_5051818034348085702[37] = 0;
   out_5051818034348085702[38] = 0;
   out_5051818034348085702[39] = 0;
   out_5051818034348085702[40] = 1;
   out_5051818034348085702[41] = 0;
   out_5051818034348085702[42] = 0;
   out_5051818034348085702[43] = 0;
   out_5051818034348085702[44] = 0;
   out_5051818034348085702[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5051818034348085702[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5051818034348085702[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5051818034348085702[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5051818034348085702[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5051818034348085702[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5051818034348085702[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5051818034348085702[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5051818034348085702[53] = -9.8000000000000007*dt;
   out_5051818034348085702[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5051818034348085702[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5051818034348085702[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5051818034348085702[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5051818034348085702[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5051818034348085702[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5051818034348085702[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5051818034348085702[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5051818034348085702[62] = 0;
   out_5051818034348085702[63] = 0;
   out_5051818034348085702[64] = 0;
   out_5051818034348085702[65] = 0;
   out_5051818034348085702[66] = 0;
   out_5051818034348085702[67] = 0;
   out_5051818034348085702[68] = 0;
   out_5051818034348085702[69] = 0;
   out_5051818034348085702[70] = 1;
   out_5051818034348085702[71] = 0;
   out_5051818034348085702[72] = 0;
   out_5051818034348085702[73] = 0;
   out_5051818034348085702[74] = 0;
   out_5051818034348085702[75] = 0;
   out_5051818034348085702[76] = 0;
   out_5051818034348085702[77] = 0;
   out_5051818034348085702[78] = 0;
   out_5051818034348085702[79] = 0;
   out_5051818034348085702[80] = 1;
}
void h_25(double *state, double *unused, double *out_1355330477950111364) {
   out_1355330477950111364[0] = state[6];
}
void H_25(double *state, double *unused, double *out_659046103507336800) {
   out_659046103507336800[0] = 0;
   out_659046103507336800[1] = 0;
   out_659046103507336800[2] = 0;
   out_659046103507336800[3] = 0;
   out_659046103507336800[4] = 0;
   out_659046103507336800[5] = 0;
   out_659046103507336800[6] = 1;
   out_659046103507336800[7] = 0;
   out_659046103507336800[8] = 0;
}
void h_24(double *state, double *unused, double *out_4179867709037876452) {
   out_4179867709037876452[0] = state[4];
   out_4179867709037876452[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2831695702512836366) {
   out_2831695702512836366[0] = 0;
   out_2831695702512836366[1] = 0;
   out_2831695702512836366[2] = 0;
   out_2831695702512836366[3] = 0;
   out_2831695702512836366[4] = 1;
   out_2831695702512836366[5] = 0;
   out_2831695702512836366[6] = 0;
   out_2831695702512836366[7] = 0;
   out_2831695702512836366[8] = 0;
   out_2831695702512836366[9] = 0;
   out_2831695702512836366[10] = 0;
   out_2831695702512836366[11] = 0;
   out_2831695702512836366[12] = 0;
   out_2831695702512836366[13] = 0;
   out_2831695702512836366[14] = 1;
   out_2831695702512836366[15] = 0;
   out_2831695702512836366[16] = 0;
   out_2831695702512836366[17] = 0;
}
void h_30(double *state, double *unused, double *out_1512517146301240509) {
   out_1512517146301240509[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1859286854999911827) {
   out_1859286854999911827[0] = 0;
   out_1859286854999911827[1] = 0;
   out_1859286854999911827[2] = 0;
   out_1859286854999911827[3] = 0;
   out_1859286854999911827[4] = 1;
   out_1859286854999911827[5] = 0;
   out_1859286854999911827[6] = 0;
   out_1859286854999911827[7] = 0;
   out_1859286854999911827[8] = 0;
}
void h_26(double *state, double *unused, double *out_6514190413962086154) {
   out_6514190413962086154[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4400549422381393024) {
   out_4400549422381393024[0] = 0;
   out_4400549422381393024[1] = 0;
   out_4400549422381393024[2] = 0;
   out_4400549422381393024[3] = 0;
   out_4400549422381393024[4] = 0;
   out_4400549422381393024[5] = 0;
   out_4400549422381393024[6] = 0;
   out_4400549422381393024[7] = 1;
   out_4400549422381393024[8] = 0;
}
void h_27(double *state, double *unused, double *out_8109444423752599487) {
   out_8109444423752599487[0] = state[3];
}
void H_27(double *state, double *unused, double *out_4082880926183855044) {
   out_4082880926183855044[0] = 0;
   out_4082880926183855044[1] = 0;
   out_4082880926183855044[2] = 0;
   out_4082880926183855044[3] = 1;
   out_4082880926183855044[4] = 0;
   out_4082880926183855044[5] = 0;
   out_4082880926183855044[6] = 0;
   out_4082880926183855044[7] = 0;
   out_4082880926183855044[8] = 0;
}
void h_29(double *state, double *unused, double *out_4590002289431953881) {
   out_4590002289431953881[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2369518199314304011) {
   out_2369518199314304011[0] = 0;
   out_2369518199314304011[1] = 1;
   out_2369518199314304011[2] = 0;
   out_2369518199314304011[3] = 0;
   out_2369518199314304011[4] = 0;
   out_2369518199314304011[5] = 0;
   out_2369518199314304011[6] = 0;
   out_2369518199314304011[7] = 0;
   out_2369518199314304011[8] = 0;
}
void h_28(double *state, double *unused, double *out_2687954476645617787) {
   out_2687954476645617787[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2712880817755226563) {
   out_2712880817755226563[0] = 1;
   out_2712880817755226563[1] = 0;
   out_2712880817755226563[2] = 0;
   out_2712880817755226563[3] = 0;
   out_2712880817755226563[4] = 0;
   out_2712880817755226563[5] = 0;
   out_2712880817755226563[6] = 0;
   out_2712880817755226563[7] = 0;
   out_2712880817755226563[8] = 0;
}
void h_31(double *state, double *unused, double *out_7206074454371125706) {
   out_7206074454371125706[0] = state[8];
}
void H_31(double *state, double *unused, double *out_628400141630376372) {
   out_628400141630376372[0] = 0;
   out_628400141630376372[1] = 0;
   out_628400141630376372[2] = 0;
   out_628400141630376372[3] = 0;
   out_628400141630376372[4] = 0;
   out_628400141630376372[5] = 0;
   out_628400141630376372[6] = 0;
   out_628400141630376372[7] = 0;
   out_628400141630376372[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5988043674990340612) {
  err_fun(nom_x, delta_x, out_5988043674990340612);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6542235054988891671) {
  inv_err_fun(nom_x, true_x, out_6542235054988891671);
}
void car_H_mod_fun(double *state, double *out_8514494013080158613) {
  H_mod_fun(state, out_8514494013080158613);
}
void car_f_fun(double *state, double dt, double *out_1676658603594809674) {
  f_fun(state,  dt, out_1676658603594809674);
}
void car_F_fun(double *state, double dt, double *out_5051818034348085702) {
  F_fun(state,  dt, out_5051818034348085702);
}
void car_h_25(double *state, double *unused, double *out_1355330477950111364) {
  h_25(state, unused, out_1355330477950111364);
}
void car_H_25(double *state, double *unused, double *out_659046103507336800) {
  H_25(state, unused, out_659046103507336800);
}
void car_h_24(double *state, double *unused, double *out_4179867709037876452) {
  h_24(state, unused, out_4179867709037876452);
}
void car_H_24(double *state, double *unused, double *out_2831695702512836366) {
  H_24(state, unused, out_2831695702512836366);
}
void car_h_30(double *state, double *unused, double *out_1512517146301240509) {
  h_30(state, unused, out_1512517146301240509);
}
void car_H_30(double *state, double *unused, double *out_1859286854999911827) {
  H_30(state, unused, out_1859286854999911827);
}
void car_h_26(double *state, double *unused, double *out_6514190413962086154) {
  h_26(state, unused, out_6514190413962086154);
}
void car_H_26(double *state, double *unused, double *out_4400549422381393024) {
  H_26(state, unused, out_4400549422381393024);
}
void car_h_27(double *state, double *unused, double *out_8109444423752599487) {
  h_27(state, unused, out_8109444423752599487);
}
void car_H_27(double *state, double *unused, double *out_4082880926183855044) {
  H_27(state, unused, out_4082880926183855044);
}
void car_h_29(double *state, double *unused, double *out_4590002289431953881) {
  h_29(state, unused, out_4590002289431953881);
}
void car_H_29(double *state, double *unused, double *out_2369518199314304011) {
  H_29(state, unused, out_2369518199314304011);
}
void car_h_28(double *state, double *unused, double *out_2687954476645617787) {
  h_28(state, unused, out_2687954476645617787);
}
void car_H_28(double *state, double *unused, double *out_2712880817755226563) {
  H_28(state, unused, out_2712880817755226563);
}
void car_h_31(double *state, double *unused, double *out_7206074454371125706) {
  h_31(state, unused, out_7206074454371125706);
}
void car_H_31(double *state, double *unused, double *out_628400141630376372) {
  H_31(state, unused, out_628400141630376372);
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
