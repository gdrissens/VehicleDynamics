#pragma once
#include <cmath>
#include <iostream>
#include "Inputs.h"
#include "Outputs.h"
#include "Tire.h"
#include "State_variables.h"

class Vehicle {

private:

	Vehicle_inputs vehicle_inputs;

    Tire_inputs front_tires{}, rear_tires{};

    const double pi = 3.14159265358979323846; // Define Pi constant

    //Tires
    Tire fi, fo, ri, ro;

    //Corner input
    Corner_type corner_type = Corner_type::Steady;
    Corner_side corner_side = Corner_side::Right;

    //Driver input
    Pedals_input pedals_input = Pedals_input::Coasting;
    Steering_input steering_input = Steering_input::Straight;
    double lon_ratio_custom = 0.0, lat_ratio_custom = 0.0, lon_ratio = 0.0, lat_ratio = 0.0, lon_input = 0.0, lat_input = 0.0;
    int lon_sign = 0.0;

    //Drive and Brake bias
	Actuator_config drive_config = Actuator_config::All, brake_config = Actuator_config::All;
    double BB_input = 0.0, BB = 0.0, DB_input = 0.0, DB = 0.0, bias = 0.0, bias_first = 0.0, bias_now = 0.0;

    //Differential and Brake configurations
	Actuator_type brake_type_f = Actuator_type::Inboard, brake_type_r = Actuator_type::Inboard,
        diff_type_f = Actuator_type::Inboard, diff_type_r = Actuator_type::Inboard;

    //Setup parameters
    double delta_f_static = 0.0, delta_r_static = 0.0, gamma_f_static = 0.0, gamma_r_static = 0.0;

    //Vehicle size
    double L = 0.0, t_f = 0.0, t_r = 0.0;

    //Masses and weights

    const double g = 9.81; // [m/s^2]

    //Total masses and weights
    double m = 0.0, x = 0.0, y = 0.0, W = 0.0, W_fi = 0.0, W_fo = 0.0, W_ri = 0.0, W_ro = 0.0;

    //Unsprung masses
    double m_u_fi = 0.0, m_u_fo = 0.0, m_u_ri = 0.0, m_u_ro = 0.0, m_u = 0.0;

    //Sprung masses
    double m_s = 0.0;

    //CG location
    double h_CG = 0.0, a = 0.0, b = 0.0, a_s = 0.0, b_s = 0.0, c = 0.0, c_s = 0.0;

    //Wheel displacements
    double w_fi = 0.0, w_fo = 0.0, w_ri = 0.0, w_ro = 0.0;

    //Ackermann geometry

        //Actual cornering radius calculation
    double R_min = 0.0, R = 0.0, beta_des = 0.0, beta_deg = 0.0, beta = 0.0, R_a = 0.0, S_f = 0.0, S_r = 0.0;

    //Steering angles
    double delta_d_des = 0.0, delta_d_deg = 0.0;

    //Slip ratios
    double kappa_des = 0.0;

    //Accelerations

        //Lateral accelerations
    double F_lat = 0.0, a_lat = 0.0;

    //Longitudinal accelerations
    double F_lon = 0.0, a_lon = 0.0, a_lon_des = 0.0;
	bool force_a_lon = false;

    //Cornering radial accelerations
    double F_rad = 0.0, a_rad = 0.0;

    //Sprung and unsprung masses CG location
    double h_CG_s = 0.0, h_CG_u_fi = 0.0, h_CG_u_fo = 0.0, h_CG_u_ri = 0.0, h_CG_u_ro = 0.0, h_CG_u = 0.0;

    //Suspension geometry

        //Roll suspension parameters
    double h_r_f = 0.0, h_r_r = 0.0, off_r_f = 0.0, off_r_r = 0.0, n_r_fi = 0.0, n_r_fo = 0.0, n_r_ri = 0.0, n_r_ro = 0.0,
        p_r_fi = 0.0, p_r_fo = 0.0, p_r_ri = 0.0, p_r_ro = 0.0, q_r_fi = 0.0, q_r_fo = 0.0, q_r_ri = 0.0, q_r_ro = 0.0;

    //Pitch suspension parameters
    double h_p_i = 0.0, h_p_o = 0.0, n_p_fi = 0.0, n_p_fo = 0.0, n_p_ri = 0.0, n_p_ro = 0.0,
        p_p_fi = 0.0, p_p_fo = 0.0, p_p_ri = 0.0, p_p_ro = 0.0, q_p_fi = 0.0, q_p_fo = 0.0, q_p_ri = 0.0, q_p_ro = 0.0;

    //Suspension stiffnesses

        //Chassis torsional stiffness
    double k_r_C_deg = 0.0, k_r_C = 0.0, k_r_C_dist = 0.0, k_r_C_f = 0.0, k_r_C_r = 0.0, k_p_C_deg = 0.0, k_p_C = 0.0, k_p_C_dist = 0.0, k_p_C_i = 0.0, k_p_C_o = 0.0;

    //Springs and anti-roll bars
    double k_susp_f = 0.0, k_susp_r = 0.0, k_arb_f = 0.0, k_arb_r = 0.0;

    //Motion ratios
    double MR_s_fi = 0.0, MR_s_fo = 0.0, MR_s_ri = 0.0, MR_s_ro = 0.0, MR_arb_fi = 0.0, MR_arb_fo = 0.0, MR_arb_ri = 0.0, MR_arb_ro = 0.0;

    //Wheel rates
    double K_susp_fi = 0.0, K_susp_fo = 0.0, K_susp_ri = 0.0, K_susp_ro = 0.0, K_arb_fi = 0.0, K_arb_fo = 0.0, K_arb_ri = 0.0, K_arb_ro = 0.0;

    //Roll stiffnesses
    double K_r_C_f = 0.0, K_r_C_r = 0.0, K_r_tot_f = 0.0, K_r_tot_r = 0.0;

    //Pitch stiffnesses
    double K_p_C_i = 0.0, K_p_C_o = 0.0, K_p_tot_i = 0.0, K_p_tot_o = 0.0;

    //Vehicle speed
    double V = 0.0, V_input = 0.0, V_skid = 0.0, V_kmh = 0.0, V_ratio = 0.0;

    //Aerodynamics

        //Downforce
    double F_down = 0.0, F_down_x = 0.0, F_down_y = 0.0, F_down_fi = 0.0, F_down_fo = 0.0, F_down_ri = 0.0, F_down_ro = 0.0;

    //Drag
    double F_drag = 0.0, F_drag_z = 0.0, F_drag_y = 0.0, h_drag = 0.0;

    //Longitudinal load transfer

        //Geometrical longitudinal load transfer
    double dW_lon_s_fi = 0.0, dW_lon_s_fo = 0.0, dW_lon_s_ri = 0.0, dW_lon_s_ro = 0.0, dW_lon_u_fi = 0.0, dW_lon_u_fo = 0.0, dW_lon_u_ri = 0.0, dW_lon_u_ro = 0.0,
        dW_lon_g_fi = 0.0, dW_lon_g_fo = 0.0, dW_lon_g_ri = 0.0, dW_lon_g_ro = 0.0;

    //Pitch moments
    double M_p_s_fi = 0.0, M_p_s_fo = 0.0, M_p_s_ri = 0.0, M_p_s_ro = 0.0, M_p_u_fi = 0.0, M_p_u_fo = 0.0, M_p_u_ri = 0.0, M_p_u_ro = 0.0, M_p_s = 0.0, M_p_u = 0.0, T = 0.0;

    //Pitch angle
    double phi = 0.0, phi_deg = 0.0;

    //Drag longitudinal load transfer
    double M_p_drag = 0.0, dW_lon_drag = 0.0;

    //Total longitudinal load transfer
    double dW_lon_i = 0.0, dW_lon_o = 0.0;

    //Elastic longitudinal load transfer
    double dW_lon_k_fi = 0.0, dW_lon_k_fo = 0.0, dW_lon_k_ri = 0.0, dW_lon_k_ro = 0.0;

    //Lateral load transfer

        //Geometrical lateral load transfer
    double dW_lat_s_fi = 0.0, dW_lat_s_fo = 0.0, dW_lat_s_ri = 0.0, dW_lat_s_ro = 0.0, dW_lat_u_fi = 0.0, dW_lat_u_fo = 0.0, dW_lat_u_ri = 0.0, dW_lat_u_ro = 0.0,
        dW_lat_g_fi = 0.0, dW_lat_g_fo = 0.0, dW_lat_g_ri = 0.0, dW_lat_g_ro = 0.0;

    //Roll moments
    double M_r_s_fi = 0.0, M_r_s_fo = 0.0, M_r_s_ri = 0.0, M_r_s_ro = 0.0, M_r_u_fi = 0.0, M_r_u_fo = 0.0, M_r_u_ri = 0.0, M_r_u_ro = 0.0, M_r_s = 0.0, M_r_u = 0.0;

    //Roll angle
    double psi = 0.0, psi_deg = 0.0;

    //Total lateral load transfer
    double dW_lat_f = 0.0, dW_lat_r = 0.0;

    //Elastic lateral load transfer
    double dW_lat_k_fi = 0.0, dW_lat_k_fo = 0.0, dW_lat_k_ri = 0.0, dW_lat_k_ro = 0.0;

    //Yaw moment
    double M_yaw_fl = 0.0, M_yaw_fr = 0.0, M_yaw_rl = 0.0, M_yaw_rr = 0.0, M_yaw = 0.0;

    //Solver parameters
    int iter = 0.0;
    double max_iter = 0.0, F_z_tol = 0.0;

    //YMD parameters
    double max_beta = 0.0, num_beta = 0.0, max_delta_d = 0.0, num_delta_d = 0.0;

public:
    Vehicle();

    void set_tires(std::string front_tire_file, std::string rear_tire_file);

    void set_parameters(const Vehicle_inputs& vehicle_inputs);

    void solver();

    void solve_kappa();

    void brents_method(Tire& tire, double a, double b);

    void peak_kappa(Tire& tire);

    inline double round_to(double value, int decimals);

    void output(Vehicle_outputs& vehicle_outputs);

    void refresh();

    void YMD(YMD_Carrier& carrier);
};