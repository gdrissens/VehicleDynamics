#pragma once
struct Vehicle_outputs {
	double phi_deg, psi_deg, M_yaw, F_lat, F_lon, a_lat, a_lon, a_rad, iter, V, R, bias_now;
	double kappa_fi, kappa_fo, kappa_ri, kappa_ro, alpha_fi, alpha_fo, alpha_ri, alpha_ro;
	double F_x_comb_fi, F_x_comb_fo, F_x_comb_ri, F_x_comb_ro, F_y_comb_fi, F_y_comb_fo, F_y_comb_ri, F_y_comb_ro;
	double F_lon_fi, F_lon_fo, F_lon_ri, F_lon_ro, F_lat_fi, F_lat_fo, F_lat_ri, F_lat_ro;
	double F_z_fi, F_z_fo, F_z_ri, F_z_ro, T_fi, T_fo, T_ri, T_ro;

#ifdef _DEBUG	
	double debug1, debug2, debug3;
#endif
};

struct YMD_Carrier {
	std::vector <std::vector<double>> a_lat_isobeta;
	std::vector <std::vector<double>> a_lon_isobeta;
	std::vector <std::vector<double>> M_yaw_isobeta;
	std::vector <std::vector<double>> a_lat_isodelta;
	std::vector <std::vector<double>> a_lon_isodelta;
	std::vector <std::vector<double>> M_yaw_isodelta;
	std::vector <std::vector<double>> control;
	std::vector <std::vector<double>> stability;
	std::vector <std::vector<double>> delta_isodelta;
	std::vector <std::vector<double>> beta_isodelta;
	std::vector <std::vector<double>> delta_isobeta;
	std::vector <std::vector<double>> beta_isobeta;
	std::vector<double> beta_iso;
	std::vector<double> delta_iso;
	double single_a_lat = 0.0, single_M_yaw = 0.0;
	double min_a_lat = 0.0, max_a_lat = 0.0;
};