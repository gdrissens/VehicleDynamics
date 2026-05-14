#pragma once
#include <string>
#include <vector>
#include <array>
#include <filesystem>
#include "State_variables.h"

struct Tire_inputs {
	double p_Cy1 = 0.0, p_Dy1 = 0.0, p_Dy2 = 0.0, p_Dy3 = 0.0, p_Ey1 = 0.0, p_Ey2 = 0.0, p_Ey3 = 0.0, p_Ey4 = 0.0, 
		p_Ky1 = 0.0, p_Ky2 = 0.0, p_Ky3 = 0.0, p_Hy1 = 0.0, p_Hy2 = 0.0, p_Hy3 = 0.0, p_Vy1 = 0.0, p_Vy2 = 0.0, p_Vy3 = 0.0, p_Vy4 = 0.0;
	double p_Cx1 = 0.0, p_Dx1 = 0.0, p_Dx2 = 0.0, p_Dx3 = 0.0, p_Ex1 = 0.0, p_Ex2 = 0.0, p_Ex3 = 0.0, p_Ex4 = 0.0,
		p_Kx1 = 0.0, p_Kx2 = 0.0, p_Kx3 = 0.0, p_Hx1 = 0.0, p_Hx2 = 0.0, p_Vx1 = 0.0, p_Vx2 = 0.0;
	double r_u = 0.0, a_rr = 0.0, b_rr = 0.0, F_z_o = 0.0, K_T = 0.0;
};

struct Vehicle_inputs {

	int version = 0.0;

	//Simulation inputs
	double R = 0.0, V_input = 0.0, beta_deg = 0.0, delta_d_deg = 0.0;
	double BB_input = 0.0, DB_input = 0.0, delta_f_static = 0.0, delta_r_static = 0.0, gamma_f_static = 0.0, gamma_r_static = 0.0;
	bool force_velocity = 0.0;
	double max_beta = 0.0, num_beta = 0.0, con_beta = 0.0, max_delta_d = 0.0, num_delta_d = 0.0, con_delta_d = 0.0, a_lon_des = 0.0;
	std::string front_tires_selection, rear_tires_selection;
	Pedals_input pedals_input;
	Steering_input steering_input;
	Arb_setup front_arb, rear_arb;

	//Vehicle inputs
	double m, x, y, L, t_f, t_r, h_CG, m_u_fl, m_u_fr, m_u_rl, m_u_rr;
	Actuator_type brake_type_f, brake_type_r, diff_type_f, diff_type_r;
	Actuator_config brake_config, drive_config;
	Actuator_lock diff_lock_f, diff_lock_r;
	double diff_dTBR_f, diff_dTBR_r, diff_bTBR_f, diff_bTBR_r, diff_preload_f, diff_preload_r, diff_k_lock_f, diff_k_lock_r;

	//Suspension inputs
	double k_susp_f, k_susp_r, k_r_C_deg, k_r_C_dist, k_p_C_deg, k_p_C_dist;
	double f_arb_1, f_arb_2, f_arb_3, f_arb_4, f_arb_5, r_arb_1, r_arb_2, r_arb_3, r_arb_4, r_arb_5;
	
	double h_r_f_2, h_r_f_1, h_r_f_0; // Front roll center height (funtion of roll angle)
	double off_r_f_2, off_r_f_1, off_r_f_0; // Front roll center lateral offset from the wheel center (function of roll angle)
	double q_r_f_2, q_r_f_1, q_r_f_0; //Front instantaneous roll center height (function of roll angle)
	double h_r_r_2, h_r_r_1, h_r_r_0; // Rear roll center height (function of roll angle)
	double off_r_r_2, off_r_r_1, off_r_r_0; // Rear roll center lateral offset from the wheel center (function of roll angle)
	double q_r_r_2, q_r_r_1, q_r_r_0; // Rear instantaneous roll center height (function of roll angle)
	double h_p_i_2, h_p_i_1, h_p_i_0; // Instantaneous pitch center height (function of pitch angle)
	double n_p_i_2, n_p_i_1, n_p_i_0; // Instantaneous pitch center longitudinal offset (function of pitch angle)
	double q_p_f_2, q_p_f_1, q_p_f_0; // Front instantaneous pitch center height (function of pitch angle)
	double h_p_o_2, h_p_o_1, h_p_o_0; // Outer pitch center height (function of pitch angle)
	double n_p_o_2, n_p_o_1, n_p_o_0; // Outer pitch center longitudinal offset (function of pitch angle)
	double q_p_r_2, q_p_r_1, q_p_r_0; // Rear instantaneous pitch center height (function of pitch angle)
	double ackermann_2, ackermann_1; // Ackermann geometry coefficients (funtion of driver steering angle)
	double bs_f_2, bs_f_1, bs_r_2, bs_r_1; //bump steer coefficients (function of vertical wheel displacement)
	double bc_f_2, bc_f_1, bc_r_2, bc_r_1; //camber change coefficients (function of vertical wheel displacement)
	double sc_f_2, sc_f_1, sc_r_2, sc_r_1; //camber steer coefficients (function of steering angle)
	double MR_s_f_2, MR_s_f_1, MR_s_f_0, MR_s_r_2, MR_s_r_1, MR_s_r_0; //suspension motion ratio coefficients (function of vertical wheel displacement)
	double MR_arb_f_2, MR_arb_f_1, MR_arb_f_0, MR_arb_r_2, MR_arb_r_1, MR_arb_r_0; //anti-roll bar motion ratio coefficients (function of vertical wheel displacement)

	//Aerodynamics inputs
	double F_down_2, F_down_1, F_down_0; //Downforce (function of velocity)
	double F_down_x_2, F_down_x_1, F_down_x_0; //Downforce longitudinal shift (function of velocity)
	double F_down_y_2, F_down_y_1, F_down_y_0; //Downforce lateral shift (function of velocity)
	double F_drag_2, F_drag_1, F_drag_0; //Drag force (function of velocity)
	double F_drag_z_2, F_drag_z_1, F_drag_z_0; //Drag force vertical shift (function of velocity)
	double F_drag_y_2, F_drag_y_1, F_drag_y_0; //Drag force lateral shift (function of velocity)

#ifdef _DEBUG
	int debug_iter = 0;
	bool force_debug_iter = 0;
#endif
};

std::string _tos(std::string string);

std::string sto_(std::string string);

void save_inputs(const Vehicle_inputs& vehicle_inputs, const std::string& file_name);

bool load_inputs(Vehicle_inputs& vehicle_inputs, const std::string& file_name);

void save_tire_inputs(const Tire_inputs& tire_struct, const std::string& file_name);

bool load_tire_inputs(Tire_inputs& tire_struct, const std::string& file_name);