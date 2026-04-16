#include "Inputs.h"
#include <string>
#include <fstream>
#include <algorithm>

std::string sto_(std::string string) {
    std::replace(string.begin(), string.end(), ' ', '_');
    return string;
}

std::string _tos(std::string string) {
    std::replace(string.begin(), string.end(), '_', ' ');
    return string;
}

void save_inputs(const Vehicle_inputs& vehicle_inputs, const std::string& file_name) {
    std::ofstream ostream(file_name);

    //Simulation inputs
    ostream << "V_input" << '=' << vehicle_inputs.V_input << '\n';
    ostream << "R_min" << '=' << vehicle_inputs.R_min << '\n';
    ostream << "beta_des" << '=' << vehicle_inputs.beta_des << '\n';
    ostream << "delta_d_des" << '=' << vehicle_inputs.delta_d_des << '\n';
    ostream << "kappa_des" << '=' << vehicle_inputs.kappa_des << '\n';
    ostream << "lon_ratio_custom" << '=' << vehicle_inputs.lon_ratio_custom << '\n';
    ostream << "lat_ratio_custom" << '=' << vehicle_inputs.lat_ratio_custom << '\n';
    ostream << "delta_f_static" << '=' << vehicle_inputs.delta_f_static << '\n';
    ostream << "delta_r_static" << '=' << vehicle_inputs.delta_r_static << '\n';
    ostream << "gamma_f_static" << '=' << vehicle_inputs.gamma_f_static << '\n';
    ostream << "gamma_r_static" << '=' << vehicle_inputs.gamma_r_static << '\n';
    ostream << "BB_input" << '=' << vehicle_inputs.BB_input << '\n';
    ostream << "DB_input" << '=' << vehicle_inputs.DB_input << '\n';
    ostream << "corner_type" << '=' << static_cast<int>(vehicle_inputs.corner_type) << '\n';
    ostream << "corner_side" << '=' << static_cast<int>(vehicle_inputs.corner_side) << '\n';
    ostream << "pedals_input" << '=' << static_cast<int>(vehicle_inputs.pedals_input) << '\n';
    ostream << "steering_input" << '=' << static_cast<int>(vehicle_inputs.steering_input) << '\n';
    ostream << "front_tires" << '=' << vehicle_inputs.front_tires_selection << '\n';
    ostream << "rear_tires" << '=' << vehicle_inputs.rear_tires_selection << '\n';
    ostream << "front_arb" << '=' << static_cast<int>(vehicle_inputs.front_arb) << '\n';
    ostream << "rear_arb" << '=' << static_cast<int>(vehicle_inputs.rear_arb) << '\n';
	ostream << "force_velocity" << '=' << vehicle_inputs.force_velocity << '\n';
    ostream << "force_a_lon" << '=' << vehicle_inputs.force_a_lon << '\n';
    ostream << "max_beta" << '=' << vehicle_inputs.max_beta << '\n';
	ostream << "num_beta" << '=' << vehicle_inputs.num_beta << '\n';
	ostream << "max_delta_d" << '=' << vehicle_inputs.max_delta_d << '\n';
	ostream << "num_delta_d" << '=' << vehicle_inputs.num_delta_d << '\n';
    ostream << "a_lon_des" << '=' << vehicle_inputs.a_lon_des << '\n';

    //Vehicle inputs
    ostream << "m" << '=' << vehicle_inputs.m << '\n';
    ostream << "x" << '=' << vehicle_inputs.x << '\n';
    ostream << "y" << '=' << vehicle_inputs.y << '\n';
    ostream << "L" << '=' << vehicle_inputs.L << '\n';
    ostream << "t_f" << '=' << vehicle_inputs.t_f << '\n';
    ostream << "t_r" << '=' << vehicle_inputs.t_r << '\n';
    ostream << "h_CG" << '=' << vehicle_inputs.h_CG << '\n';
    ostream << "m_u_fi" << '=' << vehicle_inputs.m_u_fi << '\n';
    ostream << "m_u_fo" << '=' << vehicle_inputs.m_u_fo << '\n';
    ostream << "m_u_ri" << '=' << vehicle_inputs.m_u_ri << '\n';
    ostream << "m_u_ro" << '=' << vehicle_inputs.m_u_ro << '\n';
    ostream << "brake_config" << '=' << static_cast<int>(vehicle_inputs.brake_config) << '\n';
    ostream << "brake_type_f" << '=' << static_cast<int>(vehicle_inputs.brake_type_f) << '\n';
    ostream << "brake_type_r" << '=' << static_cast<int>(vehicle_inputs.brake_type_r) << '\n';
    ostream << "drive_config" << '=' << static_cast<int>(vehicle_inputs.drive_config) << '\n';
    ostream << "diff_type_f" << '=' << static_cast<int>(vehicle_inputs.diff_type_f) << '\n';
    ostream << "diff_type_r" << '=' << static_cast<int>(vehicle_inputs.diff_type_r) << '\n';

	ostream << "F_down_2" << '=' << vehicle_inputs.F_down_2 << '\n';
	ostream << "F_down_1" << '=' << vehicle_inputs.F_down_1 << '\n';
	ostream << "F_down_0" << '=' << vehicle_inputs.F_down_0 << '\n';
	ostream << "F_down_x_2" << '=' << vehicle_inputs.F_down_x_2 << '\n';
	ostream << "F_down_x_1" << '=' << vehicle_inputs.F_down_x_1 << '\n';
	ostream << "F_down_x_0" << '=' << vehicle_inputs.F_down_x_0 << '\n';
	ostream << "F_down_y_2" << '=' << vehicle_inputs.F_down_y_2 << '\n';
	ostream << "F_down_y_1" << '=' << vehicle_inputs.F_down_y_1 << '\n';
	ostream << "F_down_y_0" << '=' << vehicle_inputs.F_down_y_0 << '\n';
	ostream << "F_drag_2" << '=' << vehicle_inputs.F_drag_2 << '\n';
	ostream << "F_drag_1" << '=' << vehicle_inputs.F_drag_1 << '\n';
	ostream << "F_drag_0" << '=' << vehicle_inputs.F_drag_0 << '\n';
	ostream << "F_drag_z_2" << '=' << vehicle_inputs.F_drag_z_2 << '\n';
	ostream << "F_drag_z_1" << '=' << vehicle_inputs.F_drag_z_1 << '\n';
	ostream << "F_drag_z_0" << '=' << vehicle_inputs.F_drag_z_0 << '\n';
	ostream << "F_drag_y_2" << '=' << vehicle_inputs.F_drag_y_2 << '\n';
	ostream << "F_drag_y_1" << '=' << vehicle_inputs.F_drag_y_1 << '\n';
	ostream << "F_drag_y_0" << '=' << vehicle_inputs.F_drag_y_0 << '\n';

    //Suspension inputs
    ostream << "k_susp_f" << '=' << vehicle_inputs.k_susp_f << '\n';
    ostream << "k_susp_r" << '=' << vehicle_inputs.k_susp_r << '\n';
    ostream << "k_r_C_deg" << '=' << vehicle_inputs.k_r_C_deg << '\n';
    ostream << "k_r_C_dist" << '=' << vehicle_inputs.k_r_C_dist << '\n';
    ostream << "k_p_C_deg" << '=' << vehicle_inputs.k_p_C_deg << '\n';
    ostream << "k_p_C_dist" << '=' << vehicle_inputs.k_p_C_dist << '\n';
    ostream << "f_arb_1" << '=' << vehicle_inputs.f_arb_1 << '\n';
    ostream << "f_arb_2" << '=' << vehicle_inputs.f_arb_2 << '\n';
    ostream << "f_arb_3" << '=' << vehicle_inputs.f_arb_3 << '\n';
    ostream << "f_arb_4" << '=' << vehicle_inputs.f_arb_4 << '\n';
    ostream << "f_arb_5" << '=' << vehicle_inputs.f_arb_5 << '\n';
    ostream << "r_arb_1" << '=' << vehicle_inputs.r_arb_1 << '\n';
    ostream << "r_arb_2" << '=' << vehicle_inputs.r_arb_2 << '\n';
    ostream << "r_arb_3" << '=' << vehicle_inputs.r_arb_3 << '\n';
    ostream << "r_arb_4" << '=' << vehicle_inputs.r_arb_4 << '\n';
    ostream << "r_arb_5" << '=' << vehicle_inputs.r_arb_5 << '\n';

	ostream << "h_r_f_2" << '=' << vehicle_inputs.h_r_f_2 << '\n';
	ostream << "h_r_f_1" << '=' << vehicle_inputs.h_r_f_1 << '\n';
	ostream << "h_r_f_0" << '=' << vehicle_inputs.h_r_f_0 << '\n';
	ostream << "off_r_f_2" << '=' << vehicle_inputs.off_r_f_2 << '\n';
	ostream << "off_r_f_1" << '=' << vehicle_inputs.off_r_f_1 << '\n';
	ostream << "off_r_f_0" << '=' << vehicle_inputs.off_r_f_0 << '\n';
	ostream << "p_r_f_2" << '=' << vehicle_inputs.p_r_f_2 << '\n';
	ostream << "p_r_f_1" << '=' << vehicle_inputs.p_r_f_1 << '\n';
	ostream << "p_r_f_0" << '=' << vehicle_inputs.p_r_f_0 << '\n';
	ostream << "h_r_r_2" << '=' << vehicle_inputs.h_r_r_2 << '\n';
	ostream << "h_r_r_1" << '=' << vehicle_inputs.h_r_r_1 << '\n';
	ostream << "h_r_r_0" << '=' << vehicle_inputs.h_r_r_0 << '\n';
	ostream << "off_r_r_2" << '=' << vehicle_inputs.off_r_r_2 << '\n';
	ostream << "off_r_r_1" << '=' << vehicle_inputs.off_r_r_1 << '\n';
	ostream << "off_r_r_0" << '=' << vehicle_inputs.off_r_r_0 << '\n';
	ostream << "p_r_r_2" << '=' << vehicle_inputs.p_r_r_2 << '\n';
	ostream << "p_r_r_1" << '=' << vehicle_inputs.p_r_r_1 << '\n';
	ostream << "p_r_r_0" << '=' << vehicle_inputs.p_r_r_0 << '\n';
	ostream << "h_p_i_2" << '=' << vehicle_inputs.h_p_i_2 << '\n';
	ostream << "h_p_i_1" << '=' << vehicle_inputs.h_p_i_1 << '\n';
	ostream << "h_p_i_0" << '=' << vehicle_inputs.h_p_i_0 << '\n';
	ostream << "n_p_i_2" << '=' << vehicle_inputs.n_p_i_2 << '\n';
	ostream << "n_p_i_1" << '=' << vehicle_inputs.n_p_i_1 << '\n';
	ostream << "n_p_i_0" << '=' << vehicle_inputs.n_p_i_0 << '\n';
	ostream << "p_p_f_2" << '=' << vehicle_inputs.p_p_f_2 << '\n';
	ostream << "p_p_f_1" << '=' << vehicle_inputs.p_p_f_1 << '\n';
	ostream << "p_p_f_0" << '=' << vehicle_inputs.p_p_f_0 << '\n';
	ostream << "h_p_o_2" << '=' << vehicle_inputs.h_p_o_2 << '\n';
	ostream << "h_p_o_1" << '=' << vehicle_inputs.h_p_o_1 << '\n';
	ostream << "h_p_o_0" << '=' << vehicle_inputs.h_p_o_0 << '\n';
	ostream << "n_p_o_2" << '=' << vehicle_inputs.n_p_o_2 << '\n';
	ostream << "n_p_o_1" << '=' << vehicle_inputs.n_p_o_1 << '\n';
	ostream << "n_p_o_0" << '=' << vehicle_inputs.n_p_o_0 << '\n';
	ostream << "p_p_r_2" << '=' << vehicle_inputs.p_p_r_2 << '\n';
	ostream << "p_p_r_1" << '=' << vehicle_inputs.p_p_r_1 << '\n';
	ostream << "p_p_r_0" << '=' << vehicle_inputs.p_p_r_0 << '\n';
	ostream << "ackermann_2" << '=' << vehicle_inputs.ackermann_2 << '\n';
	ostream << "ackermann_1" << '=' << vehicle_inputs.ackermann_1 << '\n';
	ostream << "bs_f_2" << '=' << vehicle_inputs.bs_f_2 << '\n';
	ostream << "bs_f_1" << '=' << vehicle_inputs.bs_f_1 << '\n';
	ostream << "bs_r_2" << '=' << vehicle_inputs.bs_r_2 << '\n';
	ostream << "bs_r_1" << '=' << vehicle_inputs.bs_r_1 << '\n';
	ostream << "bc_f_2" << '=' << vehicle_inputs.bc_f_2 << '\n';
	ostream << "bc_f_1" << '=' << vehicle_inputs.bc_f_1 << '\n';
	ostream << "bc_r_2" << '=' << vehicle_inputs.bc_r_2 << '\n';
	ostream << "bc_r_1" << '=' << vehicle_inputs.bc_r_1 << '\n';
	ostream << "sc_f_2" << '=' << vehicle_inputs.sc_f_2 << '\n';
	ostream << "sc_f_1" << '=' << vehicle_inputs.sc_f_1 << '\n';
	ostream << "sc_r_2" << '=' << vehicle_inputs.sc_r_2 << '\n';
	ostream << "sc_r_1" << '=' << vehicle_inputs.sc_r_1 << '\n';
	ostream << "MR_s_f_2" << '=' << vehicle_inputs.MR_s_f_2 << '\n';
	ostream << "MR_s_f_1" << '=' << vehicle_inputs.MR_s_f_1 << '\n';
	ostream << "MR_s_f_0" << '=' << vehicle_inputs.MR_s_f_0 << '\n';
	ostream << "MR_s_r_2" << '=' << vehicle_inputs.MR_s_r_2 << '\n';
	ostream << "MR_s_r_1" << '=' << vehicle_inputs.MR_s_r_1 << '\n';
	ostream << "MR_s_r_0" << '=' << vehicle_inputs.MR_s_r_0 << '\n';
	ostream << "MR_arb_f_2" << '=' << vehicle_inputs.MR_arb_f_2 << '\n';
	ostream << "MR_arb_f_1" << '=' << vehicle_inputs.MR_arb_f_1 << '\n';
	ostream << "MR_arb_f_0" << '=' << vehicle_inputs.MR_arb_f_0 << '\n';
	ostream << "MR_arb_r_2" << '=' << vehicle_inputs.MR_arb_r_2 << '\n';
	ostream << "MR_arb_r_1" << '=' << vehicle_inputs.MR_arb_r_1 << '\n';
	ostream << "MR_arb_r_0" << '=' << vehicle_inputs.MR_arb_r_0 << '\n';
}

bool load_inputs(Vehicle_inputs& vehicle_inputs, const std::string& file_name) {
    std::ifstream file(file_name);

    if (!file.is_open())
        return false;
    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = line.find('=');
        if (pos == std::string::npos)
            continue;

        std::string name = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        //Simulation inputs
        if (name == "V_input") vehicle_inputs.V_input = std::stod(value);
        else if (name == "R_min") vehicle_inputs.R_min = std::stod(value);
        else if (name == "beta_des") vehicle_inputs.beta_des = std::stod(value);
        else if (name == "delta_d_des") vehicle_inputs.delta_d_des = std::stod(value);
        else if (name == "kappa_des") vehicle_inputs.kappa_des = std::stod(value);
        else if (name == "lon_ratio_custom") vehicle_inputs.lon_ratio_custom = std::stod(value);
        else if (name == "lat_ratio_custom") vehicle_inputs.lat_ratio_custom = std::stod(value);
        else if (name == "delta_f_static") vehicle_inputs.delta_f_static = std::stod(value);
        else if (name == "delta_r_static") vehicle_inputs.delta_r_static = std::stod(value);
        else if (name == "gamma_f_static") vehicle_inputs.gamma_f_static = std::stod(value);
        else if (name == "gamma_r_static") vehicle_inputs.gamma_r_static = std::stod(value);
        else if (name == "BB_input") vehicle_inputs.BB_input = std::stod(value);
        else if (name == "DB_input") vehicle_inputs.DB_input = std::stod(value);
        else if (name == "corner_type") vehicle_inputs.corner_type = static_cast<Corner_type>(std::stoi(value));
        else if (name == "corner_side") vehicle_inputs.corner_side = static_cast<Corner_side>(std::stoi(value));
        else if (name == "pedals_input") vehicle_inputs.pedals_input = static_cast<Pedals_input>(std::stoi(value));
        else if (name == "steering_input") vehicle_inputs.steering_input = static_cast<Steering_input>(std::stoi(value));
        else if (name == "front_tires") vehicle_inputs.front_tires_selection = (value);
        else if (name == "rear_tires") vehicle_inputs.rear_tires_selection = (value);
        else if (name == "front_arb") vehicle_inputs.front_arb = static_cast<Arb_setup>(std::stoi(value));
        else if (name == "rear_arb") vehicle_inputs.rear_arb = static_cast<Arb_setup>(std::stoi(value));
		else if (name == "force_velocity") vehicle_inputs.force_velocity = (value == "1" || value == "true" || value == "True" || value == "TRUE");
        else if (name == "force_a_lon") vehicle_inputs.force_a_lon = (value == "1" || value == "true" || value == "True" || value == "TRUE");
        else if (name == "max_beta") vehicle_inputs.max_beta = std::stod(value);
		else if (name == "num_beta") vehicle_inputs.num_beta = std::stod(value);
		else if (name == "max_delta_d") vehicle_inputs.max_delta_d = std::stod(value);
		else if (name == "num_delta_d") vehicle_inputs.num_delta_d = std::stod(value);
        else if (name == "a_lon_des") vehicle_inputs.a_lon_des = std::stod(value);

        //Vehicle inputs
        if (name == "m") vehicle_inputs.m = std::stod(value);
        else if (name == "x") vehicle_inputs.x = std::stod(value);
        else if (name == "y") vehicle_inputs.y = std::stod(value);
        else if (name == "L") vehicle_inputs.L = std::stod(value);
        else if (name == "t_f") vehicle_inputs.t_f = std::stod(value);
        else if (name == "t_r") vehicle_inputs.t_r = std::stod(value);
        else if (name == "h_CG") vehicle_inputs.h_CG = std::stod(value);
        else if (name == "m_u_fi") vehicle_inputs.m_u_fi = std::stod(value);
        else if (name == "m_u_fo") vehicle_inputs.m_u_fo = std::stod(value);
        else if (name == "m_u_ri") vehicle_inputs.m_u_ri = std::stod(value);
        else if (name == "m_u_ro") vehicle_inputs.m_u_ro = std::stod(value);
        else if (name == "brake_config") vehicle_inputs.brake_config = static_cast<Actuator_config>(std::stoi(value));
        else if (name == "brake_type_f") vehicle_inputs.brake_type_f = static_cast<Actuator_type>(std::stoi(value));
        else if (name == "brake_type_r") vehicle_inputs.brake_type_r = static_cast<Actuator_type>(std::stoi(value));
        else if (name == "drive_config") vehicle_inputs.drive_config = static_cast<Actuator_config>(std::stoi(value));
        else if (name == "diff_type_f") vehicle_inputs.diff_type_f = static_cast<Actuator_type>(std::stoi(value));
        else if (name == "diff_type_r") vehicle_inputs.diff_type_r = static_cast<Actuator_type>(std::stoi(value));

        else if (name == "F_down_2") vehicle_inputs.F_down_2 = std::stod(value);
        else if (name == "F_down_1") vehicle_inputs.F_down_1 = std::stod(value);
        else if (name == "F_down_0") vehicle_inputs.F_down_0 = std::stod(value);
        else if (name == "F_down_x_2") vehicle_inputs.F_down_x_2 = std::stod(value);
        else if (name == "F_down_x_1") vehicle_inputs.F_down_x_1 = std::stod(value);
        else if (name == "F_down_x_0") vehicle_inputs.F_down_x_0 = std::stod(value);
        else if (name == "F_down_y_2") vehicle_inputs.F_down_y_2 = std::stod(value);
        else if (name == "F_down_y_1") vehicle_inputs.F_down_y_1 = std::stod(value);
        else if (name == "F_down_y_0") vehicle_inputs.F_down_y_0 = std::stod(value);
        else if (name == "F_drag_2") vehicle_inputs.F_drag_2 = std::stod(value);
        else if (name == "F_drag_1") vehicle_inputs.F_drag_1 = std::stod(value);
        else if (name == "F_drag_0") vehicle_inputs.F_drag_0 = std::stod(value);
        else if (name == "F_drag_z_2") vehicle_inputs.F_drag_z_2 = std::stod(value);
        else if (name == "F_drag_z_1") vehicle_inputs.F_drag_z_1 = std::stod(value);
        else if (name == "F_drag_z_0") vehicle_inputs.F_drag_z_0 = std::stod(value);
        else if (name == "F_drag_y_2") vehicle_inputs.F_drag_y_2 = std::stod(value);
        else if (name == "F_drag_y_1") vehicle_inputs.F_drag_y_1 = std::stod(value);
        else if (name == "F_drag_y_0") vehicle_inputs.F_drag_y_0 = std::stod(value);

        //Simulation inputs
        if (name == "k_susp_f") vehicle_inputs.k_susp_f = stod(value);
        else if (name == "k_susp_r") vehicle_inputs.k_susp_r = stod(value);
        else if (name == "k_r_C_deg") vehicle_inputs.k_r_C_deg = stod(value);
        else if (name == "k_r_C_dist") vehicle_inputs.k_r_C_dist = stod(value);
        else if (name == "k_p_C_deg") vehicle_inputs.k_p_C_deg = stod(value);
        else if (name == "k_p_C_dist") vehicle_inputs.k_p_C_dist = stod(value);
        else if (name == "f_arb_1") vehicle_inputs.f_arb_1 = stod(value);
        else if (name == "f_arb_2") vehicle_inputs.f_arb_2 = stod(value);
        else if (name == "f_arb_3") vehicle_inputs.f_arb_3 = stod(value);
        else if (name == "f_arb_4") vehicle_inputs.f_arb_4 = stod(value);
        else if (name == "f_arb_5") vehicle_inputs.f_arb_5 = stod(value);
        else if (name == "r_arb_1") vehicle_inputs.r_arb_1 = stod(value);
        else if (name == "r_arb_2") vehicle_inputs.r_arb_2 = stod(value);
        else if (name == "r_arb_3") vehicle_inputs.r_arb_3 = stod(value);
        else if (name == "r_arb_4") vehicle_inputs.r_arb_4 = stod(value);
        else if (name == "r_arb_5") vehicle_inputs.r_arb_5 = stod(value);

        if (name == "h_r_f_2") vehicle_inputs.h_r_f_2 = stod(value);
        else if (name == "h_r_f_1") vehicle_inputs.h_r_f_1 = stod(value);
        else if (name == "h_r_f_0") vehicle_inputs.h_r_f_0 = stod(value);
        else if (name == "off_r_f_2") vehicle_inputs.off_r_f_2 = stod(value);
        else if (name == "off_r_f_1") vehicle_inputs.off_r_f_1 = stod(value);
        else if (name == "off_r_f_0") vehicle_inputs.off_r_f_0 = stod(value);
        else if (name == "p_r_f_2") vehicle_inputs.p_r_f_2 = stod(value);
        else if (name == "p_r_f_1") vehicle_inputs.p_r_f_1 = stod(value);
        else if (name == "p_r_f_0") vehicle_inputs.p_r_f_0 = stod(value);
        else if (name == "h_r_r_2") vehicle_inputs.h_r_r_2 = stod(value);
        else if (name == "h_r_r_1") vehicle_inputs.h_r_r_1 = stod(value);
        else if (name == "h_r_r_0") vehicle_inputs.h_r_r_0 = stod(value);
        else if (name == "off_r_r_2") vehicle_inputs.off_r_r_2 = stod(value);
        else if (name == "off_r_r_1") vehicle_inputs.off_r_r_1 = stod(value);
        else if (name == "off_r_r_0") vehicle_inputs.off_r_r_0 = stod(value);
        else if (name == "p_r_r_2") vehicle_inputs.p_r_r_2 = stod(value);
        else if (name == "p_r_r_1") vehicle_inputs.p_r_r_1 = stod(value);
        else if (name == "p_r_r_0") vehicle_inputs.p_r_r_0 = stod(value);
        else if (name == "h_p_i_2") vehicle_inputs.h_p_i_2 = stod(value);
        else if (name == "h_p_i_1") vehicle_inputs.h_p_i_1 = stod(value);
        else if (name == "h_p_i_0") vehicle_inputs.h_p_i_0 = stod(value);
        else if (name == "n_p_i_2") vehicle_inputs.n_p_i_2 = stod(value);
        else if (name == "n_p_i_1") vehicle_inputs.n_p_i_1 = stod(value);
        else if (name == "n_p_i_0") vehicle_inputs.n_p_i_0 = stod(value);
        else if (name == "p_p_f_2") vehicle_inputs.p_p_f_2 = stod(value);
        else if (name == "p_p_f_1") vehicle_inputs.p_p_f_1 = stod(value);
        else if (name == "p_p_f_0") vehicle_inputs.p_p_f_0 = stod(value);
        else if (name == "h_p_o_2") vehicle_inputs.h_p_o_2 = stod(value);
        else if (name == "h_p_o_1") vehicle_inputs.h_p_o_1 = stod(value);
        else if (name == "h_p_o_0") vehicle_inputs.h_p_o_0 = stod(value);
        else if (name == "n_p_o_2") vehicle_inputs.n_p_o_2 = stod(value);
        else if (name == "n_p_o_1") vehicle_inputs.n_p_o_1 = stod(value);
        else if (name == "n_p_o_0") vehicle_inputs.n_p_o_0 = stod(value);
        else if (name == "p_p_r_2") vehicle_inputs.p_p_r_2 = stod(value);
        else if (name == "p_p_r_1") vehicle_inputs.p_p_r_1 = stod(value);
        else if (name == "p_p_r_0") vehicle_inputs.p_p_r_0 = stod(value);
        else if (name == "ackermann_2") vehicle_inputs.ackermann_2 = stod(value);
        else if (name == "ackermann_1") vehicle_inputs.ackermann_1 = stod(value);
        else if (name == "bs_f_2") vehicle_inputs.bs_f_2 = stod(value);
        else if (name == "bs_f_1") vehicle_inputs.bs_f_1 = stod(value);
        else if (name == "bs_r_2") vehicle_inputs.bs_r_2 = stod(value);
        else if (name == "bs_r_1") vehicle_inputs.bs_r_1 = stod(value);
        else if (name == "bc_f_2") vehicle_inputs.bc_f_2 = stod(value);
        else if (name == "bc_f_1") vehicle_inputs.bc_f_1 = stod(value);
        else if (name == "bc_r_2") vehicle_inputs.bc_r_2 = stod(value);
        else if (name == "bc_r_1") vehicle_inputs.bc_r_1 = stod(value);
        else if (name == "sc_f_2") vehicle_inputs.sc_f_2 = stod(value);
        else if (name == "sc_f_1") vehicle_inputs.sc_f_1 = stod(value);
        else if (name == "sc_r_2") vehicle_inputs.sc_r_2 = stod(value);
        else if (name == "sc_r_1") vehicle_inputs.sc_r_1 = stod(value);
        else if (name == "MR_s_f_2") vehicle_inputs.MR_s_f_2 = stod(value);
        else if (name == "MR_s_f_1") vehicle_inputs.MR_s_f_1 = stod(value);
        else if (name == "MR_s_f_0") vehicle_inputs.MR_s_f_0 = stod(value);
        else if (name == "MR_s_r_2") vehicle_inputs.MR_s_r_2 = stod(value);
        else if (name == "MR_s_r_1") vehicle_inputs.MR_s_r_1 = stod(value);
        else if (name == "MR_s_r_0") vehicle_inputs.MR_s_r_0 = stod(value);
		else if (name == "MR_arb_f_2") vehicle_inputs.MR_arb_f_2 = stod(value);
		else if (name == "MR_arb_f_1") vehicle_inputs.MR_arb_f_1 = stod(value);
		else if (name == "MR_arb_f_0") vehicle_inputs.MR_arb_f_0 = stod(value);
		else if (name == "MR_arb_r_2") vehicle_inputs.MR_arb_r_2 = stod(value);
		else if (name == "MR_arb_r_1") vehicle_inputs.MR_arb_r_1 = stod(value);
		else if (name == "MR_arb_r_0") vehicle_inputs.MR_arb_r_0 = stod(value);
    }
    return true;
}

void save_tire_inputs(const Tire_inputs& tire_struct, const std::string& file_name) {
    std::ofstream ostream(file_name);

    //Longitudinal parameters
    ostream << "p_Cx1" << '=' << tire_struct.p_Cx1 << '\n';
    ostream << "p_Dx1" << '=' << tire_struct.p_Dx1 << '\n';
    ostream << "p_Dx2" << '=' << tire_struct.p_Dx2 << '\n';
    ostream << "p_Dx3" << '=' << tire_struct.p_Dx3 << '\n';
    ostream << "p_Ex1" << '=' << tire_struct.p_Ex1 << '\n';
    ostream << "p_Ex2" << '=' << tire_struct.p_Ex2 << '\n';
    ostream << "p_Ex3" << '=' << tire_struct.p_Ex3 << '\n';
    ostream << "p_Ex4" << '=' << tire_struct.p_Ex4 << '\n';
    ostream << "p_Kx1" << '=' << tire_struct.p_Kx1 << '\n';
    ostream << "p_Kx2" << '=' << tire_struct.p_Kx2 << '\n';
    ostream << "p_Kx3" << '=' << tire_struct.p_Kx3 << '\n';
    ostream << "p_Hx1" << '=' << tire_struct.p_Hx1 << '\n';
    ostream << "p_Hx2" << '=' << tire_struct.p_Hx2 << '\n';
    ostream << "p_Vx1" << '=' << tire_struct.p_Vx1 << '\n';
    ostream << "p_Vx2" << '=' << tire_struct.p_Vx2 << '\n';

    //Lateral parameters
    ostream << "p_Cy1" << '=' << tire_struct.p_Cy1 << '\n';
    ostream << "p_Dy1" << '=' << tire_struct.p_Dy1 << '\n';
    ostream << "p_Dy2" << '=' << tire_struct.p_Dy2 << '\n';
    ostream << "p_Dy3" << '=' << tire_struct.p_Dy3 << '\n';
    ostream << "p_Ey1" << '=' << tire_struct.p_Ey1 << '\n';
    ostream << "p_Ey2" << '=' << tire_struct.p_Ey2 << '\n';
    ostream << "p_Ey3" << '=' << tire_struct.p_Ey3 << '\n';
    ostream << "p_Ey4" << '=' << tire_struct.p_Ey4 << '\n';
    ostream << "p_Ky1" << '=' << tire_struct.p_Ky1 << '\n';
    ostream << "p_Ky2" << '=' << tire_struct.p_Ky2 << '\n';
    ostream << "p_Ky3" << '=' << tire_struct.p_Ky3 << '\n';
    ostream << "p_Hy1" << '=' << tire_struct.p_Hy1 << '\n';
    ostream << "p_Hy2" << '=' << tire_struct.p_Hy2 << '\n';
    ostream << "p_Hy3" << '=' << tire_struct.p_Hy3 << '\n';
    ostream << "p_Vy1" << '=' << tire_struct.p_Vy1 << '\n';
    ostream << "p_Vy2" << '=' << tire_struct.p_Vy2 << '\n';
    ostream << "p_Vy3" << '=' << tire_struct.p_Vy3 << '\n';
    ostream << "p_Vy4" << '=' << tire_struct.p_Vy4 << '\n';

    //Other parameters
    ostream << "r_u" << '=' << tire_struct.r_u << '\n';
    ostream << "a_rr" << '=' << tire_struct.a_rr << '\n';
    ostream << "b_rr" << '=' << tire_struct.b_rr << '\n';
    ostream << "F_z_o" << '=' << tire_struct.F_z_o << '\n';
    ostream << "K_T" << '=' << tire_struct.K_T << '\n';
}

bool load_tire_inputs(Tire_inputs& tire_struct, const std::string& file_name) {
    std::ifstream file(file_name);

    if (!file.is_open())
        return false;
    std::string line;
    while (std::getline(file, line))
    {
        size_t pos = line.find('=');
        if (pos == std::string::npos)
            continue;

        std::string name = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        //Longitudinal parameters
        if (name == "p_Cx1") tire_struct.p_Cx1 = std::stod(value);
        else if (name == "p_Dx1") tire_struct.p_Dx1 = std::stod(value);
        else if (name == "p_Dx2") tire_struct.p_Dx2 = std::stod(value);
        else if (name == "p_Dx3") tire_struct.p_Dx3 = std::stod(value);
        else if (name == "p_Ex1") tire_struct.p_Ex1 = std::stod(value);
        else if (name == "p_Ex2") tire_struct.p_Ex2 = std::stod(value);
        else if (name == "p_Ex3") tire_struct.p_Ex3 = std::stod(value);
        else if (name == "p_Ex4") tire_struct.p_Ex4 = std::stod(value);
        else if (name == "p_Kx1") tire_struct.p_Kx1 = std::stod(value);
        else if (name == "p_Kx2") tire_struct.p_Kx2 = std::stod(value);
        else if (name == "p_Kx3") tire_struct.p_Kx3 = std::stod(value);
        else if (name == "p_Hx1") tire_struct.p_Hx1 = std::stod(value);
        else if (name == "p_Hx2") tire_struct.p_Hx2 = std::stod(value);
        else if (name == "p_Vx1") tire_struct.p_Vx1 = std::stod(value);
        else if (name == "p_Vx2") tire_struct.p_Vx2 = std::stod(value);

        //Lateral parameters
        else if (name == "p_Cy1") tire_struct.p_Cy1 = std::stod(value);
        else if (name == "p_Dy1") tire_struct.p_Dy1 = std::stod(value);
        else if (name == "p_Dy2") tire_struct.p_Dy2 = std::stod(value);
        else if (name == "p_Dy3") tire_struct.p_Dy3 = std::stod(value);
        else if (name == "p_Ey1") tire_struct.p_Ey1 = std::stod(value);
        else if (name == "p_Ey2") tire_struct.p_Ey2 = std::stod(value);
        else if (name == "p_Ey3") tire_struct.p_Ey3 = std::stod(value);
        else if (name == "p_Ey4") tire_struct.p_Ey4 = std::stod(value);
        else if (name == "p_Ky1") tire_struct.p_Ky1 = std::stod(value);
        else if (name == "p_Ky2") tire_struct.p_Ky2 = std::stod(value);
        else if (name == "p_Ky3") tire_struct.p_Ky3 = std::stod(value);
        else if (name == "p_Hy1") tire_struct.p_Hy1 = std::stod(value);
        else if (name == "p_Hy2") tire_struct.p_Hy2 = std::stod(value);
        else if (name == "p_Hy3") tire_struct.p_Hy3 = std::stod(value);
        else if (name == "p_Vy1") tire_struct.p_Vy1 = std::stod(value);
        else if (name == "p_Vy2") tire_struct.p_Vy2 = std::stod(value);
        else if (name == "p_Vy3") tire_struct.p_Vy3 = std::stod(value);
        else if (name == "p_Vy4") tire_struct.p_Vy4 = std::stod(value);

        //Other parameters
        else if (name == "r_u") tire_struct.r_u = std::stod(value);
        else if (name == "a_rr") tire_struct.a_rr = std::stod(value);
        else if (name == "b_rr") tire_struct.b_rr = std::stod(value);
        else if (name == "F_z_o") tire_struct.F_z_o = std::stod(value);
        else if (name == "K_T") tire_struct.K_T = std::stod(value);
    }
}