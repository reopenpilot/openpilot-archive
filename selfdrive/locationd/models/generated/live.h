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
void live_H(double *in_vec, double *out_3330299665335150522);
void live_err_fun(double *nom_x, double *delta_x, double *out_5734989183320778621);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_3821174537871789323);
void live_H_mod_fun(double *state, double *out_8650807454514871255);
void live_f_fun(double *state, double dt, double *out_2429671371383407100);
void live_F_fun(double *state, double dt, double *out_6503194737009477203);
void live_h_4(double *state, double *unused, double *out_820093648500277523);
void live_H_4(double *state, double *unused, double *out_4404550425541451596);
void live_h_9(double *state, double *unused, double *out_7095721489993404286);
void live_H_9(double *state, double *unused, double *out_7293411977821530938);
void live_h_10(double *state, double *unused, double *out_377239627407354901);
void live_H_10(double *state, double *unused, double *out_1096358219494311690);
void live_h_12(double *state, double *unused, double *out_6090916718237777568);
void live_H_12(double *state, double *unused, double *out_6375065334485649528);
void live_h_35(double *state, double *unused, double *out_403489543226484736);
void live_H_35(double *state, double *unused, double *out_3629502302160635819);
void live_h_32(double *state, double *unused, double *out_5540285923659500535);
void live_H_32(double *state, double *unused, double *out_7970507077893742707);
void live_h_13(double *state, double *unused, double *out_3148899371355467877);
void live_H_13(double *state, double *unused, double *out_8354766124778616633);
void live_h_14(double *state, double *unused, double *out_7095721489993404286);
void live_H_14(double *state, double *unused, double *out_7293411977821530938);
void live_h_33(double *state, double *unused, double *out_5453305054641768625);
void live_H_33(double *state, double *unused, double *out_478945297521778215);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}