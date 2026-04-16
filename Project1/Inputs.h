#pragma once
#include <string>
#include <vector>
#include <array>
#include "State_variables.h"

struct Tire_inputs {
	double p_Cy1, p_Dy1, p_Dy2, p_Dy3, p_Ey1, p_Ey2, p_Ey3, p_Ey4, p_Ky1, p_Ky2, p_Ky3, p_Hy1, p_Hy2, p_Hy3, p_Vy1, p_Vy2, p_Vy3, p_Vy4;
	double p_Cx1, p_Dx1, p_Dx2, p_Dx3, p_Ex1, p_Ex2, p_Ex3, p_Ex4, p_Kx1, p_Kx2, p_Kx3, p_Hx1, p_Hx2, p_Vx1, p_Vx2;
	double r_u, a_rr, b_rr, F_z_o, K_T;
};

struct Vehicle_inputs {
	//Simulation inputs
	double R_min, V_input, beta_des, delta_d_des, kappa_des, lon_ratio_custom, lat_ratio_custom;
	double BB_input, DB_input, delta_f_static, delta_r_static, gamma_f_static, gamma_r_static;
	double F_down_2, F_down_1, F_down_0, F_down_x_2, F_down_x_1, F_down_x_0, F_down_y_2, F_down_y_1, F_down_y_0;
	double F_drag_2, F_drag_1, F_drag_0, F_drag_z_2, F_drag_z_1, F_drag_z_0, F_drag_y_2, F_drag_y_1, F_drag_y_0;
	bool force_velocity, force_a_lon;
	double max_beta, num_beta, max_delta_d, num_delta_d, a_lon_des;
	std::string front_tires_selection, rear_tires_selection;
	Actuator_type brake_type_f, brake_type_r, diff_type_f, diff_type_r;
	Actuator_config brake_config, drive_config;
	Corner_side corner_side;
	Corner_type corner_type;
	Pedals_input pedals_input;
	Steering_input steering_input;
	Arb_setup front_arb, rear_arb;


	//Vehicle inputs
	double m, x, y, L, t_f, t_r, h_CG, m_u_fi, m_u_fo, m_u_ri, m_u_ro;
	//std::string brake_config, drive_config, brake_type_f, brake_type_r, diff_type_f, diff_type_r;

	//Suspension inputs
	double k_susp_f, k_susp_r, k_r_C_deg, k_r_C_dist, k_p_C_deg, k_p_C_dist;
	double f_arb_1, f_arb_2, f_arb_3, f_arb_4, f_arb_5, r_arb_1, r_arb_2, r_arb_3, r_arb_4, r_arb_5;
	double h_r_f_2, h_r_f_1, h_r_f_0, off_r_f_2, off_r_f_1, off_r_f_0, p_r_f_2, p_r_f_1, p_r_f_0;
	double h_r_r_2, h_r_r_1, h_r_r_0, off_r_r_2, off_r_r_1, off_r_r_0, p_r_r_2, p_r_r_1, p_r_r_0;
	double h_p_i_2, h_p_i_1, h_p_i_0, n_p_i_2, n_p_i_1, n_p_i_0, p_p_f_2, p_p_f_1, p_p_f_0;
	double h_p_o_2, h_p_o_1, h_p_o_0, n_p_o_2, n_p_o_1, n_p_o_0, p_p_r_2, p_p_r_1, p_p_r_0;
	double ackermann_2, ackermann_1, bs_f_2, bs_f_1, bs_r_2, bs_r_1;
	double bc_f_2, bc_f_1, bc_r_2, bc_r_1, sc_f_2, sc_f_1, sc_r_2, sc_r_1;
	double MR_s_f_2, MR_s_f_1, MR_s_f_0, MR_s_r_2, MR_s_r_1, MR_s_r_0, MR_arb_f_2, MR_arb_f_1, MR_arb_f_0, MR_arb_r_2, MR_arb_r_1, MR_arb_r_0;

};

std::string _tos(std::string string);

std::string sto_(std::string string);

void save_inputs(const Vehicle_inputs& vehicle_inputs, const std::string& file_name);

bool load_inputs(Vehicle_inputs& vehicle_inputs, const std::string& file_name);

void save_tire_inputs(const Tire_inputs& tire_struct, const std::string& file_name);

bool load_tire_inputs(Tire_inputs& tire_struct, const std::string& file_name);