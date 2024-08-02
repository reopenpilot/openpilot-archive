#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_7122946553243274237);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_190832680628474598);
void car_H_mod_fun(double *state, double *out_1724911219010081507);
void car_f_fun(double *state, double dt, double *out_4005893408128944833);
void car_F_fun(double *state, double dt, double *out_9114928829732894524);
void car_h_25(double *state, double *unused, double *out_3205075429217995583);
void car_H_25(double *state, double *unused, double *out_7841977598755789393);
void car_h_24(double *state, double *unused, double *out_1675954323987673279);
void car_H_24(double *state, double *unused, double *out_7046840876151439087);
void car_h_30(double *state, double *unused, double *out_432374099036026767);
void car_H_30(double *state, double *unused, double *out_3688076133462145468);
void car_h_26(double *state, double *unused, double *out_4569299168624818878);
void car_H_26(double *state, double *unused, double *out_4100474279881733169);
void car_h_27(double *state, double *unused, double *out_6259699472484715268);
void car_H_27(double *state, double *unused, double *out_5537875339812124412);
void car_h_29(double *state, double *unused, double *out_511135753865635668);
void car_H_29(double *state, double *unused, double *out_3824512612942573379);
void car_h_28(double *state, double *unused, double *out_6863015357161192785);
void car_H_28(double *state, double *unused, double *out_5788142884507899630);
void car_h_31(double *state, double *unused, double *out_8797057513470062762);
void car_H_31(double *state, double *unused, double *out_7872623560632749821);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}