#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_8525401177982619601);
void live_err_fun(double *nom_x, double *delta_x, double *out_8775778101559615400);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_3151838771831391302);
void live_H_mod_fun(double *state, double *out_3833022333204318420);
void live_f_fun(double *state, double dt, double *out_1996869927713755037);
void live_F_fun(double *state, double dt, double *out_4021870063276843765);
void live_h_4(double *state, double *unused, double *out_3668188715208378334);
void live_H_4(double *state, double *unused, double *out_2282283793614235186);
void live_h_9(double *state, double *unused, double *out_8934620254367429967);
void live_H_9(double *state, double *unused, double *out_5004935141650212284);
void live_h_10(double *state, double *unused, double *out_5652294238724568586);
void live_H_10(double *state, double *unused, double *out_2179883819768248388);
void live_h_12(double *state, double *unused, double *out_2915438202472378913);
void live_H_12(double *state, double *unused, double *out_8663542170656968182);
void live_h_35(double *state, double *unused, double *out_4183134385413414213);
void live_H_35(double *state, double *unused, double *out_5917979138331954473);
void live_h_32(double *state, double *unused, double *out_7545866714895519612);
void live_H_32(double *state, double *unused, double *out_1215543048699112659);
void live_h_13(double *state, double *unused, double *out_4268724754332213776);
void live_H_13(double *state, double *unused, double *out_6745363184363988088);
void live_h_14(double *state, double *unused, double *out_8934620254367429967);
void live_H_14(double *state, double *unused, double *out_5004935141650212284);
void live_h_33(double *state, double *unused, double *out_2420598194288857673);
void live_H_33(double *state, double *unused, double *out_2767422133693096869);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}