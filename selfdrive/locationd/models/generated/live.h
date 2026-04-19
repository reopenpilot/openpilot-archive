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
void live_H(double *in_vec, double *out_2632835212853184137);
void live_err_fun(double *nom_x, double *delta_x, double *out_1843898899245895096);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_1611454429855269765);
void live_H_mod_fun(double *state, double *out_1259795895112199841);
void live_f_fun(double *state, double dt, double *out_6830549774015684837);
void live_F_fun(double *state, double dt, double *out_8217549350877791630);
void live_h_4(double *state, double *unused, double *out_5378886082110512434);
void live_H_4(double *state, double *unused, double *out_1900459449141774403);
void live_h_9(double *state, double *unused, double *out_2101713836123357992);
void live_H_9(double *state, double *unused, double *out_1659269802512183758);
void live_h_10(double *state, double *unused, double *out_1908795528379772592);
void live_H_10(double *state, double *unused, double *out_4989442872472670455);
void live_h_12(double *state, double *unused, double *out_1381166433505103290);
void live_H_12(double *state, double *unused, double *out_3118996958890187392);
void live_h_35(double *state, double *unused, double *out_6764207990363251174);
void live_H_35(double *state, double *unused, double *out_1466202608230832973);
void live_h_32(double *state, double *unused, double *out_8860486149158658086);
void live_H_32(double *state, double *unused, double *out_9137616143371664476);
void live_h_13(double *state, double *unused, double *out_3126614606237615744);
void live_H_13(double *state, double *unused, double *out_2109407362549598589);
void live_h_14(double *state, double *unused, double *out_2101713836123357992);
void live_H_14(double *state, double *unused, double *out_1659269802512183758);
void live_h_33(double *state, double *unused, double *out_5376787931687130658);
void live_H_33(double *state, double *unused, double *out_4616759612869690577);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}