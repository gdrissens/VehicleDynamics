#pragma once
#include <cmath>
#include <iostream>
#include "Inputs.h"
#include "Outputs.h"
#include "State_variables.h"

class Tire {
public:

    Tire();

    int AXLE = 0.0;
    int SIDE = 0.0;

    void set_position(char axle, char side);

    double R = 0.0, V_x = 0.0, omega = 0.0, F_z = 0.0, F_z_past = 0.0, F_z_err = 0.0, r = 0.0, T = 0.0, T_r = 0.0, df_z = 0.0,
        alpha = 0.0, alpha_y = 0.0, delta = 0.0, theta = 0.0, kappa = 0.0, kappa_x = 0.0, peak_kappa = 0.0,
        F_x = 0.0, F_y = 0.0, F_x_comb = 0.0, F_y_comb = 0.0, F_x_comb_tar = 0.0, F_lat = 0.0, F_lon = 0.0, F_rad = 0.0;
    double r_u = 0.0, a_rr = 0.0, b_rr = 0.0, F_z_o = 0.0, K_T = 0.0;
    double gamma = 0.0; // [rad] Camber angle                                       INPUT
    double F_rr = 0.0; // [N] Rolling resistance

    //Lateral Pacejka parameters
    double p_Cy1 = 0.0, p_Dy1 = 0.0, p_Dy2 = 0.0, p_Dy3 = 0.0, p_Ey1 = 0.0, p_Ey2 = 0.0, p_Ey3 = 0.0, p_Ey4 = 0.0, p_Ky1 = 0.0,
        p_Ky2 = 0.0, p_Ky3 = 0.0, p_Hy1 = 0.0, p_Hy2 = 0.0, p_Hy3 = 0.0, p_Vy1 = 0.0, p_Vy2 = 0.0, p_Vy3 = 0.0, p_Vy4 = 0.0;
    double mu_y = 0.0, B_y = 0.0, C_y = 0.0, D_y = 0.0, E_y = 0.0, K_y_alpha = 0.0, S_Hy = 0.0, S_Vy = 0.0, S_Vy_gamma = 0.0;


    //Longitudinal Pacejka parameters
    double p_Cx1 = 0.0, p_Dx1 = 1.0, p_Dx2 = 0.0, p_Dx3 = 0.0, p_Ex1 = 0.0, p_Ex2 = 0.0, p_Ex3 = 0.0,
        p_Ex4 = 0.0, p_Kx1 = 0.0, p_Kx2 = 0.0, p_Kx3 = 0.0, p_Hx1 = 0.0, p_Hx2 = 0.0, p_Vx1 = 0.0, p_Vx2 = 0.0;
    double mu_x = 0.0, B_x = 0.0, C_x = 0.0, D_x = 0.0, E_x = 0.0, K_x_kappa = 0.0, S_Hx = 0.0, S_Vx = 0.0;

    void set_parameters(Tire_inputs& input);

    void set_alpha(double a_rad);

    void set_K_T();

    void set_r();

    void set_Pacejka();

    void set_kappa_x();

    void set_F_x();

    void set_F_y();

    void set_F_x_comb(int lon_sign);

    void set_F_y_comb(double a_rad);

    void set_T();

    void set_T_r(int lon_sign, Actuator_type brakes, Actuator_type diff);

    void set_F_lat();

    void set_F_lon();

    void set_F_rad();

    void set_V_x(double V, double R_v);

    void set_omega(Pedals_input pedals);

    void set_F_rr();

    void set_F_z_past();

    void set_F_z_err();

    inline double round_to(double value, int decimals);

    void refresh();
};