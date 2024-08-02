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
void live_H(double *in_vec, double *out_8180120912825541323);
void live_err_fun(double *nom_x, double *delta_x, double *out_2235730839387788341);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_326261295306740191);
void live_H_mod_fun(double *state, double *out_6929195951705016412);
void live_f_fun(double *state, double dt, double *out_6351759004151022937);
void live_F_fun(double *state, double dt, double *out_5502934450495567892);
void live_h_4(double *state, double *unused, double *out_4717029163149753550);
void live_H_4(double *state, double *unused, double *out_5389543225214088268);
void live_h_9(double *state, double *unused, double *out_4046528061737671226);
void live_H_9(double *state, double *unused, double *out_5769981913231015878);
void live_h_10(double *state, double *unused, double *out_2766968380519037456);
void live_H_10(double *state, double *unused, double *out_5999283407405275549);
void live_h_12(double *state, double *unused, double *out_5957037225820983386);
void live_H_12(double *state, double *unused, double *out_991715151828644728);
void live_h_35(double *state, double *unused, double *out_214788844796679554);
void live_H_35(double *state, double *unused, double *out_5292181408138487844);
void live_h_32(double *state, double *unused, double *out_3380641476992712791);
void live_H_32(double *state, double *unused, double *out_8887370067527436113);
void live_h_13(double *state, double *unused, double *out_6498926561649141984);
void live_H_13(double *state, double *unused, double *out_6226855880410704586);
void live_h_14(double *state, double *unused, double *out_4046528061737671226);
void live_H_14(double *state, double *unused, double *out_5769981913231015878);
void live_h_33(double *state, double *unused, double *out_3771926408767014460);
void live_H_33(double *state, double *unused, double *out_4904404885135226585);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}