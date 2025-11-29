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
void car_err_fun(double *nom_x, double *delta_x, double *out_5430471743703628025);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3119006140182869805);
void car_H_mod_fun(double *state, double *out_8243656043750077585);
void car_f_fun(double *state, double dt, double *out_8245401355847018673);
void car_F_fun(double *state, double dt, double *out_2231314064370560999);
void car_h_25(double *state, double *unused, double *out_4907576450740410272);
void car_H_25(double *state, double *unused, double *out_5469066146654994867);
void car_h_24(double *state, double *unused, double *out_3525197881519364844);
void car_H_24(double *state, double *unused, double *out_6850457424892874552);
void car_h_30(double *state, double *unused, double *out_3505611992589953304);
void car_H_30(double *state, double *unused, double *out_2950733188147746240);
void car_h_26(double *state, double *unused, double *out_6873218347760597121);
void car_H_26(double *state, double *unused, double *out_2164540176894194266);
void car_h_27(double *state, double *unused, double *out_54803546940882960);
void car_H_27(double *state, double *unused, double *out_5125496499948171151);
void car_h_29(double *state, double *unused, double *out_2750212729369093950);
void car_H_29(double *state, double *unused, double *out_2440501843833354056);
void car_h_28(double *state, double *unused, double *out_4112133440010064166);
void car_H_28(double *state, double *unused, double *out_7522900860902884630);
void car_h_31(double *state, double *unused, double *out_469580621949294508);
void car_H_31(double *state, double *unused, double *out_2790748279127545742);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}