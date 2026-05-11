#pragma once
struct Vehicle_outputs {
	double phi_deg, psi_deg, M_yaw, F_lat, F_lon, a_lat, a_lon, a_rad, iter, V, R, bias_now;
	double kappa_fl, kappa_fr, kappa_rl, kappa_rr, alpha_fl, alpha_fr, alpha_rl, alpha_rr;
	double F_x_comb_fl, F_x_comb_fr, F_x_comb_rl, F_x_comb_rr, F_y_comb_fl, F_y_comb_fr, F_y_comb_rl, F_y_comb_rr;
	double F_lon_fl, F_lon_fr, F_lon_rl, F_lon_rr, F_lat_fl, F_lat_fr, F_lat_rl, F_lat_rr;
	double F_z_fl, F_z_fr, F_z_rl, F_z_rr, T_fl, T_fr, T_rl, T_rr;

#ifdef _DEBUG	
	double debug1, debug2, debug3, debug4;
	int brents_single, brents_total, golden_single, golden_total;
	int iter_total;
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
	std::vector <std::vector<double>> beta_isodelta;
	std::vector <std::vector<double>> delta_isobeta;
	std::vector <std::vector<int>> cancel_isodelta;
	std::vector <std::vector<int>> cancel_isobeta;
	std::vector<double> beta_iso;
	std::vector<double> delta_iso;
	struct Single_run {
		double a_lat = 0.0, a_lon = 0.0, M_yaw = 0.0, beta = 0.0, delta = 0.0;
	};
	Single_run single_run;
	double max_a_lat = 0.0, max_M_yaw = 0.0;
};