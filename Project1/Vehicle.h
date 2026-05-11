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
    Tire fl, fr, rl, rr;

    //Driver input
    Pedals_input pedals_input = Pedals_input::Coasting;
    Steering_input steering_input = Steering_input::Straight;
	int lon_sign = 1.0, lat_sign = 1.0;

    //Drive and Brake bias
	Actuator_config drive_config = Actuator_config::All, brake_config = Actuator_config::All;
    double BB_input = 0.0, BB = 0.0, DB_input = 0.0, DB = 0.0, bias = 0.0, bias_first = 0.0, bias_now = 0.0;

    //Differential and Brake configurations
	Actuator_type brake_type_f = Actuator_type::Inboard, brake_type_r = Actuator_type::Inboard,
        diff_type_f = Actuator_type::Inboard, diff_type_r = Actuator_type::Inboard;

    struct diff {
		Actuator_lock lock = Actuator_lock::Open;
		double bTBR = 1.0; // Braking torque bias ratio (TBR) for Torsen differentials
		double dTBR = 1.0; // Driving torque bias ratio (TBR) for Torsen differentials
		bool locked = false; // Differential lock status
		double hyster = 1; // Hysteresis for clutch differentials
		double relax = 1.0; // Relaxation factor for clutch differentials
    };

	diff front_diff{}, rear_diff{};
    double mdT = 0.0, sdT = 0.0;

    //Setup parameters
    double delta_f_static = 0.0, delta_r_static = 0.0, gamma_f_static = 0.0, gamma_r_static = 0.0;

    //Vehicle size
    double L = 0.0, t_f = 0.0, t_r = 0.0;

    //Masses and weights

    const double g = 9.81; // [m/s^2]

    //Total masses and weights
    double m = 0.0, x = 0.0, y = 0.0, W = 0.0, W_fl = 0.0, W_fr = 0.0, W_rl = 0.0, W_rr = 0.0;

    //Unsprung masses
    double m_u_fl = 0.0, m_u_fr = 0.0, m_u_rl = 0.0, m_u_rr = 0.0, m_u = 0.0;

    //Sprung masses
    double m_s = 0.0;

    //CG location
    double h_CG = 0.0, a = 0.0, b = 0.0, a_s = 0.0, b_s = 0.0;

    //Wheel displacements
    double w_fl = 0.0, w_fr = 0.0, w_rl = 0.0, w_rr = 0.0;

    //Ackermann geometry

        //Actual cornering radius calculation
    double R = 0.0, beta_deg = 0.0, beta = 0.0, R_a = 0.0, S_f = 0.0, S_r = 0.0;

    //Steering angles
    double delta_d_deg = 0.0;

    //Accelerations


        //Lateral accelerations
    double F_lat = 0.0, a_lat = 0.0;

    //Longitudinal accelerations
    double F_lon = 0.0, a_lon = 0.0, a_lon_des = 0.0;
	bool force_a_lon = false;

    //Cornering radial accelerations
    double F_rad = 0.0, a_rad = 0.0;

    //Sprung and unsprung masses CG location
    double h_CG_s = 0.0, h_CG_u_fl = 0.0, h_CG_u_fr = 0.0, h_CG_u_rl = 0.0, h_CG_u_rr = 0.0, h_CG_u = 0.0;

    //Suspension geometry

        //Roll suspension parameters
    double h_r_f = 0.0, h_r_r = 0.0, off_r_f = 0.0, off_r_r = 0.0, n_r_fl = 0.0, n_r_fr = 0.0, n_r_rl = 0.0, n_r_rr = 0.0,
        p_r_fl = 0.0, p_r_fr = 0.0, p_r_rl = 0.0, p_r_rr = 0.0, q_r_fl = 0.0, q_r_fr = 0.0, q_r_rl = 0.0, q_r_rr = 0.0;

    //Pitch suspension parameters
    double h_p_l = 0.0, h_p_r = 0.0, n_p_fl = 0.0, n_p_fr = 0.0, n_p_rl = 0.0, n_p_rr = 0.0,
        p_p_fl = 0.0, p_p_fr = 0.0, p_p_rl = 0.0, p_p_rr = 0.0, q_p_fl = 0.0, q_p_fr = 0.0, q_p_rl = 0.0, q_p_rr = 0.0;

    //Suspension stiffnesses

        //Chassis torsional stiffness
    double k_r_C_deg = 0.0, k_r_C = 0.0, k_r_C_dist = 0.0, k_r_C_f = 0.0, k_r_C_r = 0.0, k_p_C_deg = 0.0, k_p_C = 0.0, k_p_C_dist = 0.0, k_p_C_i = 0.0, k_p_C_o = 0.0;

    //Springs and anti-roll bars
    double k_susp_f = 0.0, k_susp_r = 0.0, k_arb_f = 0.0, k_arb_r = 0.0;

    //Motion ratios
    double MR_s_fl = 0.0, MR_s_fr = 0.0, MR_s_rl = 0.0, MR_s_rr = 0.0, MR_arb_fl = 0.0, MR_arb_fr = 0.0, MR_arb_rl = 0.0, MR_arb_rr = 0.0;

    //Wheel rates
    double K_susp_fl = 0.0, K_susp_fr = 0.0, K_susp_rl = 0.0, K_susp_rr = 0.0, K_arb_fl = 0.0, K_arb_fr = 0.0, K_arb_rl = 0.0, K_arb_rr = 0.0;

    //Roll stiffnesses
    double K_r_C_f = 0.0, K_r_C_r = 0.0, K_r_tot_f = 0.0, K_r_tot_r = 0.0;

    //Pitch stiffnesses
    double K_p_C_l = 0.0, K_p_C_r = 0.0, K_p_tot_l = 0.0, K_p_tot_r = 0.0;

    //Vehicle speed
    double V = 0.0, V_input = 0.0, V_skid = 0.0, V_kmh = 0.0;

    //Aerodynamics

        //Downforce
    double F_down = 0.0, F_down_x = 0.0, F_down_y = 0.0, F_down_fl = 0.0, F_down_fr = 0.0, F_down_rl = 0.0, F_down_rr = 0.0;

    //Drag
    double F_drag = 0.0, F_drag_z = 0.0, F_drag_y = 0.0, h_drag = 0.0;

    //Longitudinal load transfer

        //Geometrical longitudinal load transfer
    double dW_lon_s_fl = 0.0, dW_lon_s_fr = 0.0, dW_lon_s_rl = 0.0, dW_lon_s_rr = 0.0, dW_lon_u_fl = 0.0, dW_lon_u_fr = 0.0, dW_lon_u_rl = 0.0, dW_lon_u_rr = 0.0,
        dW_lon_g_fl = 0.0, dW_lon_g_fr = 0.0, dW_lon_g_rl = 0.0, dW_lon_g_rr = 0.0;

    //Pitch moments
    double M_p_s_fl = 0.0, M_p_s_fr = 0.0, M_p_s_rl = 0.0, M_p_s_rr = 0.0, M_p_u_fl = 0.0, M_p_u_fr = 0.0, M_p_u_rl = 0.0, M_p_u_rr = 0.0, M_p_s = 0.0, M_p_u = 0.0, T = 0.0;
    //Pitch angle
    double phi = 0.0, phi_deg = 0.0;

    //Drag longitudinal load transfer
    double M_p_drag = 0.0, dW_lon_drag = 0.0;

    //Total longitudinal load transfer
    double dW_lon_l = 0.0, dW_lon_r = 0.0;

    //Elastic longitudinal load transfer
    double dW_lon_k_fl = 0.0, dW_lon_k_fr = 0.0, dW_lon_k_rl = 0.0, dW_lon_k_rr = 0.0;

    //Lateral load transfer

        //Geometrical lateral load transfer
    double dW_lat_s_fl = 0.0, dW_lat_s_fr = 0.0, dW_lat_s_rl = 0.0, dW_lat_s_rr = 0.0, dW_lat_u_fl = 0.0, dW_lat_u_fr = 0.0, dW_lat_u_rl = 0.0, dW_lat_u_rr = 0.0,
        dW_lat_g_fl = 0.0, dW_lat_g_fr = 0.0, dW_lat_g_rl = 0.0, dW_lat_g_rr = 0.0;

    //Roll moments
    double M_r_s_fl = 0.0, M_r_s_fr = 0.0, M_r_s_rl = 0.0, M_r_s_rr = 0.0, M_r_u_fl = 0.0, M_r_u_fr = 0.0, M_r_u_rl = 0.0, M_r_u_rr = 0.0, M_r_s = 0.0, M_r_u = 0.0;
    //Roll angle
    double psi = 0.0, psi_deg = 0.0;

    //Total lateral load transfer
    double dW_lat_f = 0.0, dW_lat_r = 0.0;

    //Elastic lateral load transfer
    double dW_lat_k_fl = 0.0, dW_lat_k_fr = 0.0, dW_lat_k_rl = 0.0, dW_lat_k_rr = 0.0;

    //Yaw moment
    double M_yaw_fl = 0.0, M_yaw_fr = 0.0, M_yaw_rl = 0.0, M_yaw_rr = 0.0, M_yaw = 0.0;

    //Solver parameters
    int iter = 0, iter_total = 0, check_load_iter = 0, check_lock_iter = 0;
    double max_iter = 0.0, F_z_tol = 0.0, a_lon_tol = 0.0;
    bool batata = false;

    //YMD parameters
    double max_beta = 0.0, num_beta = 0.0, con_beta = 0.0, max_delta_d = 0.0, num_delta_d = 0.0, con_delta_d = 0.0;
    int cancel_run = 0, invert_run = 0;

	//Debug variables
	int brents_iter_single = 0, brents_iter_total = 0, golden_iter_single = 0, golden_iter_total = 0;

public:
    Vehicle();

    void set_tires(std::string front_tire_file, std::string rear_tire_file);

    void set_parameters(const Vehicle_inputs& vehicle_inputs);

	void vehicle_parameters();

    void ackermann_diagram();

    void chassis_stiffnesses();

    void update_tires();

    void accelerations();

    void unsprung_masses();

	void suspension_kinematics();

    void aerodynamics();

	void longitudinal_load_transfer();

    void lateral_load_transfer();

    void update_wheel_loads_and_displacements();

	void yaw_moment();

    void solver();

    void solve_kappa();

    void brents_method(Tire& tire);

    void peak_kappa(Tire& tire);

    inline double round_to(double value, int decimals);

	void check_loads(diff& diff, Tire& t1, Tire& t2);

    void output(Vehicle_outputs& vehicle_outputs);

    void refresh();

    void YMD(YMD_Carrier& carrier);
};