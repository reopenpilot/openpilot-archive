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
void car_err_fun(double *nom_x, double *delta_x, double *out_8963914457910857508);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3690391334373159898);
void car_H_mod_fun(double *state, double *out_5320442536077183291);
void car_f_fun(double *state, double dt, double *out_3215647447738557253);
void car_F_fun(double *state, double dt, double *out_8370961493089902910);
void car_h_25(double *state, double *unused, double *out_3308608408930185204);
void car_H_25(double *state, double *unused, double *out_3023921450234221662);
void car_h_24(double *state, double *unused, double *out_8414429955721093303);
void car_H_24(double *state, double *unused, double *out_851271851228722096);
void car_h_30(double *state, double *unused, double *out_7245196169894843053);
void car_H_30(double *state, double *unused, double *out_1503774879893386536);
void car_h_26(double *state, double *unused, double *out_1496584920399978883);
void car_H_26(double *state, double *unused, double *out_717581868639834562);
void car_h_27(double *state, double *unused, double *out_6121160512200038587);
void car_H_27(double *state, double *unused, double *out_719819191290556681);
void car_h_29(double *state, double *unused, double *out_6199874636153862918);
void car_H_29(double *state, double *unused, double *out_993543535578994352);
void car_h_28(double *state, double *unused, double *out_1119487244539192942);
void car_H_28(double *state, double *unused, double *out_970086735986331899);
void car_h_31(double *state, double *unused, double *out_3583802471214691093);
void car_H_31(double *state, double *unused, double *out_3054567412111182090);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}