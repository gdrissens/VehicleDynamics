#pragma once
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <stdlib.h>
#include "Inputs.h"
#include "Outputs.h"
#include "Vehicle.h"
#include "Tire.h"
#include "YMD.h"
#include "Tire_selection.h"
#include "Spring_selection.h"
#include "Simulation_controller.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Sumário para MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private:
		Vehicle_inputs* vehicle_inputs;
		Tire_inputs* tire_inputs;
		Tire_inputs* front_tires;
		Tire_inputs* rear_tires;
		YMD_Carrier* YMD_carrier;
		Tire_selection* tire_selection;
		Spring_selection* spring_selection;
		Simulation_controller* sim_controller;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::TextBox^ textBox26;
	private: System::Windows::Forms::NumericUpDown^ input_delta_d_deg;




	private: System::Windows::Forms::NumericUpDown^ input_beta_deg;



	private: System::Windows::Forms::NumericUpDown^ input_R;


	private: System::Windows::Forms::NumericUpDown^ input_V_input;
	private: System::Windows::Forms::GroupBox^ groupBox9;
	private: System::Windows::Forms::TextBox^ textBox27;
	private: System::Windows::Forms::NumericUpDown^ input_gamma_r_static;
	private: System::Windows::Forms::TextBox^ textBox28;
	private: System::Windows::Forms::NumericUpDown^ input_BB_input;
	private: System::Windows::Forms::TextBox^ textBox29;
	private: System::Windows::Forms::NumericUpDown^ input_gamma_f_static;
	private: System::Windows::Forms::TextBox^ textBox34;
	private: System::Windows::Forms::NumericUpDown^ input_delta_r_static;
	private: System::Windows::Forms::TextBox^ textBox35;
	private: System::Windows::Forms::NumericUpDown^ input_delta_f_static;
	private: System::Windows::Forms::TextBox^ textBox36;
	private: System::Windows::Forms::NumericUpDown^ input_DB_input;



	private: System::Windows::Forms::ComboBox^ input_steering_input;
	private: System::Windows::Forms::TextBox^ textBox38;
	private: System::Windows::Forms::ComboBox^ input_pedals_input;
	private: System::Windows::Forms::TextBox^ textBox37;






	private: System::Windows::Forms::GroupBox^ groupBox11;
	private: System::Windows::Forms::NumericUpDown^ input_p_Dy1;
	private: System::Windows::Forms::TextBox^ textBox43;
	private: System::Windows::Forms::NumericUpDown^ input_p_Cy1;
	private: System::Windows::Forms::TextBox^ textBox44;
	private: System::Windows::Forms::TextBox^ textBox45;
	private: System::Windows::Forms::TextBox^ textBox60;
	private: System::Windows::Forms::TextBox^ textBox59;
	private: System::Windows::Forms::TextBox^ textBox58;
	private: System::Windows::Forms::TextBox^ textBox57;
	private: System::Windows::Forms::TextBox^ textBox56;
	private: System::Windows::Forms::TextBox^ textBox55;
	private: System::Windows::Forms::TextBox^ textBox54;
	private: System::Windows::Forms::TextBox^ textBox53;
	private: System::Windows::Forms::TextBox^ textBox52;
	private: System::Windows::Forms::TextBox^ textBox51;
	private: System::Windows::Forms::TextBox^ textBox50;
	private: System::Windows::Forms::TextBox^ textBox49;
	private: System::Windows::Forms::TextBox^ textBox48;
	private: System::Windows::Forms::TextBox^ textBox47;
	private: System::Windows::Forms::TextBox^ textBox46;
private: System::Windows::Forms::NumericUpDown^ input_p_Vy4;
private: System::Windows::Forms::NumericUpDown^ input_p_Vy3;
private: System::Windows::Forms::NumericUpDown^ input_p_Vy2;
private: System::Windows::Forms::NumericUpDown^ input_p_Vy1;
private: System::Windows::Forms::NumericUpDown^ input_p_Hy3;
private: System::Windows::Forms::NumericUpDown^ input_p_Hy2;
private: System::Windows::Forms::NumericUpDown^ input_p_Hy1;
private: System::Windows::Forms::NumericUpDown^ input_p_Ky3;
private: System::Windows::Forms::NumericUpDown^ input_p_Ky2;
private: System::Windows::Forms::NumericUpDown^ input_p_Ky1;
private: System::Windows::Forms::NumericUpDown^ input_p_Ey4;
private: System::Windows::Forms::NumericUpDown^ input_p_Ey3;
private: System::Windows::Forms::NumericUpDown^ input_p_Ey2;
private: System::Windows::Forms::NumericUpDown^ input_p_Ey1;
private: System::Windows::Forms::NumericUpDown^ input_p_Dy3;
private: System::Windows::Forms::NumericUpDown^ input_p_Dy2;
private: System::Windows::Forms::GroupBox^ groupBox12;
private: System::Windows::Forms::NumericUpDown^ input_p_Vx2;
private: System::Windows::Forms::NumericUpDown^ input_p_Vx1;
private: System::Windows::Forms::NumericUpDown^ input_p_Hx2;
private: System::Windows::Forms::NumericUpDown^ input_p_Hx1;
private: System::Windows::Forms::NumericUpDown^ input_p_Kx3;
private: System::Windows::Forms::NumericUpDown^ input_p_Kx2;
private: System::Windows::Forms::NumericUpDown^ input_p_Kx1;
private: System::Windows::Forms::NumericUpDown^ input_p_Ex4;
private: System::Windows::Forms::NumericUpDown^ input_p_Ex3;
private: System::Windows::Forms::NumericUpDown^ input_p_Ex2;
private: System::Windows::Forms::NumericUpDown^ input_p_Ex1;
private: System::Windows::Forms::NumericUpDown^ input_p_Dx3;
private: System::Windows::Forms::NumericUpDown^ input_p_Dx2;
private: System::Windows::Forms::TextBox^ textBox64;
private: System::Windows::Forms::TextBox^ textBox65;
private: System::Windows::Forms::TextBox^ textBox66;
private: System::Windows::Forms::TextBox^ textBox67;
private: System::Windows::Forms::TextBox^ textBox68;
private: System::Windows::Forms::TextBox^ textBox69;
private: System::Windows::Forms::TextBox^ textBox70;
private: System::Windows::Forms::TextBox^ textBox71;
private: System::Windows::Forms::TextBox^ textBox72;
private: System::Windows::Forms::TextBox^ textBox73;
private: System::Windows::Forms::TextBox^ textBox74;
private: System::Windows::Forms::TextBox^ textBox75;
private: System::Windows::Forms::TextBox^ textBox76;
private: System::Windows::Forms::NumericUpDown^ input_p_Dx1;
private: System::Windows::Forms::TextBox^ textBox77;
private: System::Windows::Forms::NumericUpDown^ input_p_Cx1;
private: System::Windows::Forms::TextBox^ textBox78;
private: System::Windows::Forms::GroupBox^ groupBox13;
private: System::Windows::Forms::TextBox^ textBox61;
private: System::Windows::Forms::NumericUpDown^ input_F_z_o;
private: System::Windows::Forms::NumericUpDown^ input_b_rr;
private: System::Windows::Forms::TextBox^ textBox62;
private: System::Windows::Forms::TextBox^ textBox63;
private: System::Windows::Forms::NumericUpDown^ input_a_rr;
private: System::Windows::Forms::NumericUpDown^ input_r_u;
private: System::Windows::Forms::TextBox^ textBox79;
private: System::Windows::Forms::TextBox^ textBox80;
private: System::Windows::Forms::NumericUpDown^ input_K_T;
private: System::Windows::Forms::GroupBox^ groupBox14;
private: System::Windows::Forms::Button^ tire_save;
private: System::Windows::Forms::Button^ tire_delete;
private: System::Windows::Forms::Button^ tire_new;
private: System::Windows::Forms::ComboBox^ tire_name;
private: System::Collections::Generic::List<System::String^>^ tire_list;
private: System::Collections::Generic::List<System::String^>^ spring_list;
private: System::Windows::Forms::ComboBox^ input_rear_tires_selection;
private: System::Windows::Forms::TextBox^ textBox81;
private: System::Windows::Forms::ComboBox^ input_front_tires_selection;
private: System::Windows::Forms::TextBox^ textBox82;
private: System::Windows::Forms::SplitContainer^ splitContainer2;
private: System::Windows::Forms::TabControl^ tabControl2;
private: System::Windows::Forms::TabPage^ tabPage6;
private: System::Windows::Forms::TabPage^ tabPage7;
private: System::Windows::Forms::Label^ output_a_lat;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
private: System::Windows::Forms::Label^ output_M_yaw;
private: System::Windows::Forms::Label^ output_F_lat;
private: System::Windows::Forms::Label^ output_phi_deg;
private: System::Windows::Forms::Label^ output_F_lon;
private: System::Windows::Forms::Label^ output_psi_deg;
private: System::Windows::Forms::Label^ output_a_lon;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ output_F_z_fl;
private: System::Windows::Forms::Label^ output_F_z_fr;
private: System::Windows::Forms::Label^ output_F_z_rl;
private: System::Windows::Forms::Label^ output_F_z_rr;




private: System::Windows::Forms::Label^ output_F_x_comb_fl;
private: System::Windows::Forms::Label^ output_F_x_comb_fr;
private: System::Windows::Forms::Label^ output_F_x_comb_rl;
private: System::Windows::Forms::Label^ output_F_x_comb_rr;




private: System::Windows::Forms::Label^ output_F_y_comb_fl;
private: System::Windows::Forms::Label^ output_F_y_comb_fr;
private: System::Windows::Forms::Label^ output_F_y_comb_rl;
private: System::Windows::Forms::Label^ output_F_y_comb_rr;




private: System::Windows::Forms::Label^ output_F_lon_fl;
private: System::Windows::Forms::Label^ output_F_lon_fr;
private: System::Windows::Forms::Label^ output_F_lon_rl;
private: System::Windows::Forms::Label^ output_F_lon_rr;




private: System::Windows::Forms::Label^ output_F_lat_fl;
private: System::Windows::Forms::Label^ output_F_lat_fr;
private: System::Windows::Forms::Label^ output_F_lat_rl;
private: System::Windows::Forms::Label^ output_F_lat_rr;




private: System::Windows::Forms::Label^ output_kappa_fl;
private: System::Windows::Forms::Label^ output_kappa_fr;
private: System::Windows::Forms::Label^ output_kappa_rl;
private: System::Windows::Forms::Label^ output_kappa_rr;




private: System::Windows::Forms::Label^ output_alpha_fl;
private: System::Windows::Forms::Label^ output_alpha_fr;
private: System::Windows::Forms::Label^ output_alpha_rl;
private: System::Windows::Forms::Label^ output_alpha_rr;




private: System::Windows::Forms::Label^ output_T_fl;
private: System::Windows::Forms::Label^ output_T_fr;
private: System::Windows::Forms::Label^ output_T_rl;
private: System::Windows::Forms::Label^ output_T_rr;




private: System::Windows::Forms::Label^ output_V;
private: System::Windows::Forms::Label^ output_bias_now;
private: System::Windows::Forms::Label^ output_iter;
private: System::Windows::Forms::Label^ output_a_rad;
private: System::Windows::Forms::ComboBox^ input_rear_arb_setup;





private: System::Windows::Forms::TextBox^ textBox84;
private: System::Windows::Forms::ComboBox^ input_front_arb_setup;


private: System::Windows::Forms::TextBox^ textBox83;






















private: System::Windows::Forms::GroupBox^ groupBox6;




private: System::Windows::Forms::NumericUpDown^ input_h_r_f_0;
private: System::Windows::Forms::TextBox^ textBox19;
private: System::Windows::Forms::NumericUpDown^ input_h_r_f_1;
private: System::Windows::Forms::TextBox^ textBox21;
private: System::Windows::Forms::NumericUpDown^ input_h_r_f_2;
private: System::Windows::Forms::TextBox^ textBox95;
private: System::Windows::Forms::NumericUpDown^ input_q_r_r_0;

private: System::Windows::Forms::TextBox^ textBox111;
private: System::Windows::Forms::NumericUpDown^ input_q_r_r_1;

private: System::Windows::Forms::TextBox^ textBox112;
private: System::Windows::Forms::NumericUpDown^ input_q_r_r_2;

private: System::Windows::Forms::TextBox^ textBox113;
private: System::Windows::Forms::NumericUpDown^ input_q_r_f_0;

private: System::Windows::Forms::TextBox^ textBox105;
private: System::Windows::Forms::NumericUpDown^ input_q_r_f_1;

private: System::Windows::Forms::TextBox^ textBox106;
private: System::Windows::Forms::NumericUpDown^ input_q_r_f_2;


private: System::Windows::Forms::TextBox^ textBox107;
private: System::Windows::Forms::NumericUpDown^ input_off_r_r_0;

private: System::Windows::Forms::TextBox^ textBox102;
private: System::Windows::Forms::NumericUpDown^ input_off_r_r_1;

private: System::Windows::Forms::TextBox^ textBox103;
private: System::Windows::Forms::NumericUpDown^ input_off_r_r_2;

private: System::Windows::Forms::TextBox^ textBox104;
private: System::Windows::Forms::NumericUpDown^ input_off_r_f_0;

private: System::Windows::Forms::TextBox^ textBox99;
private: System::Windows::Forms::NumericUpDown^ input_off_r_f_1;

private: System::Windows::Forms::TextBox^ textBox100;
private: System::Windows::Forms::NumericUpDown^ input_off_r_f_2;

private: System::Windows::Forms::TextBox^ textBox101;
private: System::Windows::Forms::NumericUpDown^ input_h_r_r_0;

private: System::Windows::Forms::TextBox^ textBox96;
private: System::Windows::Forms::NumericUpDown^ input_h_r_r_1;

private: System::Windows::Forms::TextBox^ textBox97;
private: System::Windows::Forms::NumericUpDown^ input_h_r_r_2;

private: System::Windows::Forms::TextBox^ textBox98;
private: System::Windows::Forms::GroupBox^ groupBox17;
private: System::Windows::Forms::NumericUpDown^ input_q_p_r_0;


private: System::Windows::Forms::TextBox^ textBox108;
private: System::Windows::Forms::NumericUpDown^ input_q_p_r_1;


private: System::Windows::Forms::TextBox^ textBox109;
private: System::Windows::Forms::NumericUpDown^ input_q_p_r_2;


private: System::Windows::Forms::TextBox^ textBox110;
private: System::Windows::Forms::NumericUpDown^ input_q_p_f_0;


private: System::Windows::Forms::TextBox^ textBox114;
private: System::Windows::Forms::NumericUpDown^ input_q_p_f_1;


private: System::Windows::Forms::TextBox^ textBox115;
private: System::Windows::Forms::NumericUpDown^ input_q_p_f_2;



private: System::Windows::Forms::TextBox^ textBox116;
private: System::Windows::Forms::NumericUpDown^ input_n_p_o_0;

private: System::Windows::Forms::TextBox^ textBox117;
private: System::Windows::Forms::NumericUpDown^ input_n_p_o_1;

private: System::Windows::Forms::TextBox^ textBox118;
private: System::Windows::Forms::NumericUpDown^ input_n_p_o_2;

private: System::Windows::Forms::TextBox^ textBox119;
private: System::Windows::Forms::NumericUpDown^ input_n_p_i_0;

private: System::Windows::Forms::TextBox^ textBox120;
private: System::Windows::Forms::NumericUpDown^ input_n_p_i_1;

private: System::Windows::Forms::TextBox^ textBox121;
private: System::Windows::Forms::NumericUpDown^ input_n_p_i_2;

private: System::Windows::Forms::TextBox^ textBox122;
private: System::Windows::Forms::NumericUpDown^ input_h_p_o_0;

private: System::Windows::Forms::TextBox^ textBox123;
private: System::Windows::Forms::NumericUpDown^ input_h_p_o_1;

private: System::Windows::Forms::TextBox^ textBox124;
private: System::Windows::Forms::NumericUpDown^ input_h_p_o_2;

private: System::Windows::Forms::TextBox^ textBox125;
private: System::Windows::Forms::NumericUpDown^ input_h_p_i_0;

private: System::Windows::Forms::TextBox^ textBox126;
private: System::Windows::Forms::NumericUpDown^ input_h_p_i_1;

private: System::Windows::Forms::TextBox^ textBox127;
private: System::Windows::Forms::NumericUpDown^ input_h_p_i_2;

private: System::Windows::Forms::TextBox^ textBox128;
private: System::Windows::Forms::GroupBox^ groupBox19;








private: System::Windows::Forms::TextBox^ textBox132;
private: System::Windows::Forms::NumericUpDown^ input_bs_r_1;

private: System::Windows::Forms::TextBox^ textBox133;
private: System::Windows::Forms::NumericUpDown^ input_bs_r_2;

private: System::Windows::Forms::TextBox^ textBox134;


private: System::Windows::Forms::TextBox^ textBox147;
private: System::Windows::Forms::NumericUpDown^ input_bs_f_1;

private: System::Windows::Forms::TextBox^ textBox148;
private: System::Windows::Forms::NumericUpDown^ input_bs_f_2;

private: System::Windows::Forms::TextBox^ textBox149;


private: System::Windows::Forms::TextBox^ textBox150;
private: System::Windows::Forms::NumericUpDown^ input_ackermann_1;

private: System::Windows::Forms::TextBox^ textBox151;
private: System::Windows::Forms::NumericUpDown^ input_ackermann_2;

private: System::Windows::Forms::TextBox^ textBox152;
private: System::Windows::Forms::GroupBox^ groupBox18;
private: System::Windows::Forms::NumericUpDown^ input_MR_arb_r_0;

private: System::Windows::Forms::TextBox^ textBox135;
private: System::Windows::Forms::NumericUpDown^ input_MR_arb_r_1;

private: System::Windows::Forms::TextBox^ textBox136;
private: System::Windows::Forms::NumericUpDown^ input_MR_arb_r_2;

private: System::Windows::Forms::TextBox^ textBox137;
private: System::Windows::Forms::NumericUpDown^ input_MR_arb_f_0;

private: System::Windows::Forms::TextBox^ textBox138;
private: System::Windows::Forms::NumericUpDown^ input_MR_arb_f_1;

private: System::Windows::Forms::TextBox^ textBox139;
private: System::Windows::Forms::NumericUpDown^ input_MR_arb_f_2;

private: System::Windows::Forms::TextBox^ textBox140;
private: System::Windows::Forms::NumericUpDown^ input_MR_s_r_0;

private: System::Windows::Forms::TextBox^ textBox141;
private: System::Windows::Forms::NumericUpDown^ input_MR_s_r_1;

private: System::Windows::Forms::TextBox^ textBox142;
private: System::Windows::Forms::NumericUpDown^ input_MR_s_r_2;

private: System::Windows::Forms::TextBox^ textBox143;
private: System::Windows::Forms::NumericUpDown^ input_MR_s_f_0;


private: System::Windows::Forms::TextBox^ textBox144;
private: System::Windows::Forms::NumericUpDown^ input_MR_s_f_1;


private: System::Windows::Forms::TextBox^ textBox145;
private: System::Windows::Forms::NumericUpDown^ input_MR_s_f_2;


private: System::Windows::Forms::TextBox^ textBox146;
private: System::Windows::Forms::GroupBox^ groupBox20;


private: System::Windows::Forms::TextBox^ textBox129;
private: System::Windows::Forms::NumericUpDown^ input_bc_f_1;

private: System::Windows::Forms::TextBox^ textBox130;
private: System::Windows::Forms::NumericUpDown^ input_bc_f_2;

private: System::Windows::Forms::TextBox^ textBox131;


private: System::Windows::Forms::TextBox^ textBox153;
private: System::Windows::Forms::NumericUpDown^ input_sc_r_1;

private: System::Windows::Forms::TextBox^ textBox154;
private: System::Windows::Forms::NumericUpDown^ input_sc_r_2;

private: System::Windows::Forms::TextBox^ textBox155;


private: System::Windows::Forms::TextBox^ textBox156;
private: System::Windows::Forms::NumericUpDown^ input_sc_f_1;

private: System::Windows::Forms::TextBox^ textBox157;
private: System::Windows::Forms::NumericUpDown^ input_sc_f_2;

private: System::Windows::Forms::TextBox^ textBox158;


private: System::Windows::Forms::TextBox^ textBox159;
private: System::Windows::Forms::NumericUpDown^ input_bc_r_1;

private: System::Windows::Forms::TextBox^ textBox160;
private: System::Windows::Forms::NumericUpDown^ input_bc_r_2;

private: System::Windows::Forms::TextBox^ textBox161;
private: System::Windows::Forms::GroupBox^ groupBox21;
private: System::Windows::Forms::NumericUpDown^ input_F_drag_y_0;

private: System::Windows::Forms::TextBox^ textBox162;
private: System::Windows::Forms::NumericUpDown^ input_F_drag_y_1;

private: System::Windows::Forms::TextBox^ textBox163;
private: System::Windows::Forms::NumericUpDown^ input_F_drag_y_2;

private: System::Windows::Forms::TextBox^ textBox164;
private: System::Windows::Forms::NumericUpDown^ input_F_drag_z_0;

private: System::Windows::Forms::TextBox^ textBox165;
private: System::Windows::Forms::NumericUpDown^ input_F_drag_z_1;

private: System::Windows::Forms::TextBox^ textBox166;
private: System::Windows::Forms::NumericUpDown^ input_F_drag_z_2;

private: System::Windows::Forms::TextBox^ textBox167;
private: System::Windows::Forms::NumericUpDown^ input_F_drag_0;

private: System::Windows::Forms::TextBox^ textBox168;
private: System::Windows::Forms::NumericUpDown^ input_F_drag_1;

private: System::Windows::Forms::TextBox^ textBox169;
private: System::Windows::Forms::NumericUpDown^ input_F_drag_2;

private: System::Windows::Forms::TextBox^ textBox170;
private: System::Windows::Forms::NumericUpDown^ input_F_down_y_0;

private: System::Windows::Forms::TextBox^ textBox171;
private: System::Windows::Forms::NumericUpDown^ input_F_down_y_1;

private: System::Windows::Forms::TextBox^ textBox172;
private: System::Windows::Forms::NumericUpDown^ input_F_down_y_2;

private: System::Windows::Forms::TextBox^ textBox173;
private: System::Windows::Forms::NumericUpDown^ input_F_down_x_0;

private: System::Windows::Forms::TextBox^ textBox174;
private: System::Windows::Forms::NumericUpDown^ input_F_down_x_1;

private: System::Windows::Forms::TextBox^ textBox175;
private: System::Windows::Forms::NumericUpDown^ input_F_down_x_2;

private: System::Windows::Forms::TextBox^ textBox176;
private: System::Windows::Forms::NumericUpDown^ input_F_down_0;

private: System::Windows::Forms::TextBox^ textBox177;
private: System::Windows::Forms::NumericUpDown^ input_F_down_1;

private: System::Windows::Forms::TextBox^ textBox178;
private: System::Windows::Forms::NumericUpDown^ input_F_down_2;

private: System::Windows::Forms::TextBox^ textBox179;
private: System::Windows::Forms::CheckBox^ input_force_velocity;
private: System::Windows::Forms::Label^ output_R;
private: System::Windows::Forms::DataVisualization::Charting::Chart^ YMD;
private: System::Windows::Forms::Button^ RUN_YMD;
private: System::Windows::Forms::SplitContainer^ splitContainer4;
private: System::Windows::Forms::TextBox^ textBox182;
private: System::Windows::Forms::NumericUpDown^ input_num_delta_d;

private: System::Windows::Forms::TextBox^ textBox183;
private: System::Windows::Forms::NumericUpDown^ input_max_delta_d;

private: System::Windows::Forms::TextBox^ textBox181;
private: System::Windows::Forms::NumericUpDown^ input_num_beta;

private: System::Windows::Forms::TextBox^ textBox180;
private: System::Windows::Forms::NumericUpDown^ input_max_beta;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
private: System::Windows::Forms::NumericUpDown^ input_a_lon_des;

private: System::Windows::Forms::TextBox^ textBox184;

private: System::Windows::Forms::TabPage^ debugPage;
private: System::Windows::Forms::Label^ output_debug1;
private: System::Windows::Forms::Label^ output_debug3;


private: System::Windows::Forms::Label^ output_debug2;
private: System::Windows::Forms::Label^ output_debug4;
private: System::Windows::Forms::Label^ output_golden_total;
private: System::Windows::Forms::Label^ output_golden_single;
private: System::Windows::Forms::Label^ output_brents_total;
private: System::Windows::Forms::Label^ output_brents_single;
private: System::Windows::Forms::Label^ output_iter_total;
private: System::Windows::Forms::NumericUpDown^ input_con_delta_d;

private: System::Windows::Forms::TextBox^ textBox40;
private: System::Windows::Forms::NumericUpDown^ input_con_beta;

private: System::Windows::Forms::TextBox^ textBox39;
private: System::Windows::Forms::ComboBox^ input_diff_lock_r;

private: System::Windows::Forms::ComboBox^ input_diff_lock_f;

private: System::Windows::Forms::TextBox^ textBox41;
private: System::Windows::Forms::TextBox^ textBox42;
private: System::Windows::Forms::NumericUpDown^ input_debug_iter;
private: System::Windows::Forms::CheckBox^ input_force_debug_iter;
private: System::Windows::Forms::CheckBox^ input_force_radius;


private: System::Windows::Forms::NumericUpDown^ fake_DB;
private: System::Windows::Forms::NumericUpDown^ fake_BB;






private: System::Windows::Forms::TextBox^ textBox32;

private: System::Windows::Forms::TextBox^ textBox186;

private: System::Windows::Forms::TextBox^ textBox187;

private: System::Windows::Forms::TextBox^ textBox188;

private: System::Windows::Forms::TextBox^ textBox189;
private: System::Windows::Forms::NumericUpDown^ input_diff_k_lock_f;

private: System::Windows::Forms::TextBox^ textBox185;
private: System::Windows::Forms::NumericUpDown^ input_diff_preload_f;

private: System::Windows::Forms::TextBox^ textBox33;
private: System::Windows::Forms::NumericUpDown^ input_diff_bTBR_f;

private: System::Windows::Forms::TextBox^ textBox30;
private: System::Windows::Forms::NumericUpDown^ input_diff_dTBR_f;
private: System::Windows::Forms::NumericUpDown^ input_diff_k_lock_r;

private: System::Windows::Forms::NumericUpDown^ input_diff_preload_r;

private: System::Windows::Forms::NumericUpDown^ input_diff_bTBR_r;

private: System::Windows::Forms::NumericUpDown^ input_diff_dTBR_r;
private: System::Windows::Forms::TabControl^ tabControl4;
private: System::Windows::Forms::TabPage^ tabPage10;
private: System::Windows::Forms::TabPage^ tabPage11;
private: System::Windows::Forms::TabPage^ tabPage12;
private: System::Windows::Forms::TabPage^ tabPage13;
private: System::Windows::Forms::TabPage^ tabPage14;
private: System::Windows::Forms::NumericUpDown^ fake_k_lock_r;
private: System::Windows::Forms::NumericUpDown^ fake_preload_r;
private: System::Windows::Forms::NumericUpDown^ fake_bTBR_r;
private: System::Windows::Forms::NumericUpDown^ fake_dTBR_r;
private: System::Windows::Forms::NumericUpDown^ fake_k_lock_f;
private: System::Windows::Forms::NumericUpDown^ fake_preload_f;
private: System::Windows::Forms::NumericUpDown^ fake_bTBR_f;
private: System::Windows::Forms::NumericUpDown^ fake_dTBR_f;
private: System::Windows::Forms::TextBox^ textBox31;
private: System::Windows::Forms::TextBox^ Display_corner_or_velocity;
private: System::Windows::Forms::GroupBox^ groupBox10;
private: System::Windows::Forms::ComboBox^ spring_name;
private: System::Windows::Forms::Button^ spring_save;
private: System::Windows::Forms::Button^ spring_delete;
private: System::Windows::Forms::Button^ spring_new;
private: System::Windows::Forms::ComboBox^ input_front_arb_selection;
private: System::Windows::Forms::ComboBox^ input_rear_arb_selection;
private: System::Windows::Forms::ComboBox^ spring_setups;
private: System::Windows::Forms::Button^ Spring_remove;
private: System::Windows::Forms::Button^ spring_add;
private: System::Windows::Forms::NumericUpDown^ spring_stiffness;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::GroupBox^ groupBox22;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::GroupBox^ groupBox16;
private: System::Windows::Forms::GroupBox^ groupBox15;
private: System::Windows::Forms::TextBox^ textBox85;
private: System::Windows::Forms::TextBox^ textBox86;
private: System::Windows::Forms::TextBox^ textBox87;
private: System::Windows::Forms::TextBox^ textBox88;
private: System::Windows::Forms::TextBox^ textBox89;
private: System::Windows::Forms::TextBox^ textBox90;
private: System::Windows::Forms::Label^ output_h_CG_s;
private: System::Windows::Forms::Label^ output_m_s;
private: System::Windows::Forms::Label^ output_h_CG_u_rr;
private: System::Windows::Forms::Label^ output_h_CG_u_rl;
private: System::Windows::Forms::Label^ output_h_CG_u_fr;
private: System::Windows::Forms::Label^ output_h_CG_u_fl;
private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::GroupBox^ groupBox23;
private: System::Windows::Forms::TextBox^ textBox91;
private: System::Windows::Forms::Label^ output_r_deg;
private: System::Windows::Forms::TextBox^ textBox92;
private: System::Windows::Forms::LinkLabel^ linkLabelThesis;
private: System::Windows::Forms::LinkLabel^ linkLabelUserGuide;
private: System::Windows::Forms::LinkLabel^ linkLabelAdditions;































		   Vehicle_outputs* vehicle_outputs;

	public:
		MyForm(void)
		{
			InitializeComponent();
			vehicle_inputs = new Vehicle_inputs();
			vehicle_outputs = new Vehicle_outputs();
			tire_inputs = new Tire_inputs();
			tire_list = gcnew System::Collections::Generic::List<System::String^>();
			spring_list = gcnew System::Collections::Generic::List<System::String^>();
			YMD_carrier = new YMD_Carrier();
			tire_selection = new Tire_selection();
			spring_selection = new Spring_selection();
			sim_controller = new Simulation_controller();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			//delete vehicle_inputs;
			//delete vehicle_outputs;
			//delete tire_inputs;
			//delete vehicle;
			//delete tire_list;
		}
private: System::Windows::Forms::TabControl^ tabControl1;
protected:

protected:

	protected:

	protected:

	protected:

	protected:

	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;

	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::NumericUpDown^ input_m;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::NumericUpDown^ input_x;

	private: System::Windows::Forms::TextBox^ textBox7;
private: System::Windows::Forms::NumericUpDown^ input_m_u_rr;


	private: System::Windows::Forms::TextBox^ textBox6;
private: System::Windows::Forms::NumericUpDown^ input_m_u_rl;


	private: System::Windows::Forms::TextBox^ textBox5;
private: System::Windows::Forms::NumericUpDown^ input_m_u_fr;


	private: System::Windows::Forms::TextBox^ textBox4;
private: System::Windows::Forms::NumericUpDown^ input_m_u_fl;


	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::NumericUpDown^ input_y;

	private: System::Windows::Forms::GroupBox^ groupBox2;

	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::NumericUpDown^ input_t_r;

	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::NumericUpDown^ input_t_f;

	private: System::Windows::Forms::TextBox^ textBox16;
	private: System::Windows::Forms::NumericUpDown^ input_L;

	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::NumericUpDown^ input_h_CG;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::ComboBox^ input_brake_config;
	private: System::Windows::Forms::ComboBox^ input_brake_type_r;
	private: System::Windows::Forms::ComboBox^ input_brake_type_f;

	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::ComboBox^ input_diff_type_r;

	private: System::Windows::Forms::ComboBox^ input_diff_type_f;
private: System::Windows::Forms::ComboBox^ input_drive_config;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox17;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::TextBox^ textBox18;
private: System::Windows::Forms::NumericUpDown^ input_k_susp_r;

private: System::Windows::Forms::NumericUpDown^ input_k_susp_f;
	private: System::Windows::Forms::TextBox^ textBox20;
	private: System::Windows::Forms::GroupBox^ groupBox7;
private: System::Windows::Forms::NumericUpDown^ input_k_p_C_deg;
	private: System::Windows::Forms::TextBox^ textBox25;
	private: System::Windows::Forms::TextBox^ textBox22;
private: System::Windows::Forms::NumericUpDown^ input_k_r_C_dist;

private: System::Windows::Forms::NumericUpDown^ input_k_r_C_deg;
	private: System::Windows::Forms::TextBox^ textBox23;
private: System::Windows::Forms::TextBox^ textBox24;
private: System::Windows::Forms::NumericUpDown^ input_k_p_C_dist;
private: System::Windows::Forms::Button^ RUN;
private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->RUN_YMD = (gcnew System::Windows::Forms::Button());
			this->RUN = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->linkLabelAdditions = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabelUserGuide = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabelThesis = (gcnew System::Windows::Forms::LinkLabel());
			this->textBox92 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox23 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox91 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox14 = (gcnew System::Windows::Forms::GroupBox());
			this->tire_name = (gcnew System::Windows::Forms::ComboBox());
			this->tire_save = (gcnew System::Windows::Forms::Button());
			this->tire_delete = (gcnew System::Windows::Forms::Button());
			this->tire_new = (gcnew System::Windows::Forms::Button());
			this->groupBox13 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox80 = (gcnew System::Windows::Forms::TextBox());
			this->input_K_T = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox61 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_z_o = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_b_rr = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox62 = (gcnew System::Windows::Forms::TextBox());
			this->textBox63 = (gcnew System::Windows::Forms::TextBox());
			this->input_a_rr = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_r_u = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox79 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox12 = (gcnew System::Windows::Forms::GroupBox());
			this->input_p_Vx2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Vx1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Hx2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Hx1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Kx3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Kx2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Kx1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Ex4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Ex3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Ex2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Ex1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Dx3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Dx2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox64 = (gcnew System::Windows::Forms::TextBox());
			this->textBox65 = (gcnew System::Windows::Forms::TextBox());
			this->textBox66 = (gcnew System::Windows::Forms::TextBox());
			this->textBox67 = (gcnew System::Windows::Forms::TextBox());
			this->textBox68 = (gcnew System::Windows::Forms::TextBox());
			this->textBox69 = (gcnew System::Windows::Forms::TextBox());
			this->textBox70 = (gcnew System::Windows::Forms::TextBox());
			this->textBox71 = (gcnew System::Windows::Forms::TextBox());
			this->textBox72 = (gcnew System::Windows::Forms::TextBox());
			this->textBox73 = (gcnew System::Windows::Forms::TextBox());
			this->textBox74 = (gcnew System::Windows::Forms::TextBox());
			this->textBox75 = (gcnew System::Windows::Forms::TextBox());
			this->textBox76 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_Dx1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox77 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_Cx1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox78 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->input_p_Vy4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Vy3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Vy2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Vy1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Hy3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Hy2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Hy1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Ky3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Ky2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Ky1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Ey4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Ey3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Ey2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Ey1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Dy3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_p_Dy2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox60 = (gcnew System::Windows::Forms::TextBox());
			this->textBox59 = (gcnew System::Windows::Forms::TextBox());
			this->textBox58 = (gcnew System::Windows::Forms::TextBox());
			this->textBox57 = (gcnew System::Windows::Forms::TextBox());
			this->textBox56 = (gcnew System::Windows::Forms::TextBox());
			this->textBox55 = (gcnew System::Windows::Forms::TextBox());
			this->textBox54 = (gcnew System::Windows::Forms::TextBox());
			this->textBox53 = (gcnew System::Windows::Forms::TextBox());
			this->textBox52 = (gcnew System::Windows::Forms::TextBox());
			this->textBox51 = (gcnew System::Windows::Forms::TextBox());
			this->textBox50 = (gcnew System::Windows::Forms::TextBox());
			this->textBox49 = (gcnew System::Windows::Forms::TextBox());
			this->textBox48 = (gcnew System::Windows::Forms::TextBox());
			this->textBox47 = (gcnew System::Windows::Forms::TextBox());
			this->textBox46 = (gcnew System::Windows::Forms::TextBox());
			this->textBox45 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_Dy1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox43 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_Cy1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox44 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl4 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage10 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox16 = (gcnew System::Windows::Forms::GroupBox());
			this->output_h_CG_s = (gcnew System::Windows::Forms::Label());
			this->output_m_s = (gcnew System::Windows::Forms::Label());
			this->textBox89 = (gcnew System::Windows::Forms::TextBox());
			this->textBox90 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox15 = (gcnew System::Windows::Forms::GroupBox());
			this->output_h_CG_u_rr = (gcnew System::Windows::Forms::Label());
			this->output_h_CG_u_rl = (gcnew System::Windows::Forms::Label());
			this->output_h_CG_u_fr = (gcnew System::Windows::Forms::Label());
			this->output_h_CG_u_fl = (gcnew System::Windows::Forms::Label());
			this->textBox85 = (gcnew System::Windows::Forms::TextBox());
			this->textBox86 = (gcnew System::Windows::Forms::TextBox());
			this->textBox87 = (gcnew System::Windows::Forms::TextBox());
			this->textBox88 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->input_m_u_fl = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_m_u_rr = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_m_u_fr = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->input_m_u_rl = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->input_t_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_t_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_L = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_CG = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->input_y = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->input_x = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->input_m = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabPage13 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->input_brake_type_r = (gcnew System::Windows::Forms::ComboBox());
			this->input_brake_type_f = (gcnew System::Windows::Forms::ComboBox());
			this->input_brake_config = (gcnew System::Windows::Forms::ComboBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox186 = (gcnew System::Windows::Forms::TextBox());
			this->textBox187 = (gcnew System::Windows::Forms::TextBox());
			this->textBox188 = (gcnew System::Windows::Forms::TextBox());
			this->textBox189 = (gcnew System::Windows::Forms::TextBox());
			this->textBox185 = (gcnew System::Windows::Forms::TextBox());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->input_diff_lock_r = (gcnew System::Windows::Forms::ComboBox());
			this->input_diff_lock_f = (gcnew System::Windows::Forms::ComboBox());
			this->textBox41 = (gcnew System::Windows::Forms::TextBox());
			this->textBox42 = (gcnew System::Windows::Forms::TextBox());
			this->input_diff_type_r = (gcnew System::Windows::Forms::ComboBox());
			this->input_diff_type_f = (gcnew System::Windows::Forms::ComboBox());
			this->input_drive_config = (gcnew System::Windows::Forms::ComboBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->input_diff_k_lock_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_diff_preload_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_diff_bTBR_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_diff_dTBR_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_diff_k_lock_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_diff_preload_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_diff_bTBR_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_diff_dTBR_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->fake_k_lock_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->fake_preload_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->fake_bTBR_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->fake_dTBR_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->fake_k_lock_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->fake_preload_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->fake_bTBR_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->fake_dTBR_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabPage11 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox21 = (gcnew System::Windows::Forms::GroupBox());
			this->input_F_drag_y_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox162 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_drag_y_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox163 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_drag_y_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox164 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_drag_z_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox165 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_drag_z_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox166 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_drag_z_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox167 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_drag_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox168 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_drag_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox169 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_drag_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox170 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_down_y_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox171 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_down_y_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox172 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_down_y_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox173 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_down_x_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox174 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_down_x_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox175 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_down_x_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox176 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_down_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox177 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_down_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox178 = (gcnew System::Windows::Forms::TextBox());
			this->input_F_down_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox179 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage12 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox22 = (gcnew System::Windows::Forms::GroupBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->input_front_arb_selection = (gcnew System::Windows::Forms::ComboBox());
			this->input_rear_arb_selection = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->Spring_remove = (gcnew System::Windows::Forms::Button());
			this->spring_add = (gcnew System::Windows::Forms::Button());
			this->spring_stiffness = (gcnew System::Windows::Forms::NumericUpDown());
			this->spring_setups = (gcnew System::Windows::Forms::ComboBox());
			this->spring_name = (gcnew System::Windows::Forms::ComboBox());
			this->spring_save = (gcnew System::Windows::Forms::Button());
			this->spring_delete = (gcnew System::Windows::Forms::Button());
			this->spring_new = (gcnew System::Windows::Forms::Button());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->input_k_p_C_dist = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_k_p_C_deg = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->input_k_r_C_dist = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_k_r_C_deg = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->input_k_susp_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_k_susp_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage14 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox20 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox159 = (gcnew System::Windows::Forms::TextBox());
			this->input_bc_r_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox160 = (gcnew System::Windows::Forms::TextBox());
			this->input_bc_r_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox161 = (gcnew System::Windows::Forms::TextBox());
			this->textBox129 = (gcnew System::Windows::Forms::TextBox());
			this->input_bc_f_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox130 = (gcnew System::Windows::Forms::TextBox());
			this->input_bc_f_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox131 = (gcnew System::Windows::Forms::TextBox());
			this->textBox153 = (gcnew System::Windows::Forms::TextBox());
			this->input_sc_r_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox154 = (gcnew System::Windows::Forms::TextBox());
			this->input_sc_r_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox155 = (gcnew System::Windows::Forms::TextBox());
			this->textBox156 = (gcnew System::Windows::Forms::TextBox());
			this->input_sc_f_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox157 = (gcnew System::Windows::Forms::TextBox());
			this->input_sc_f_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox158 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox17 = (gcnew System::Windows::Forms::GroupBox());
			this->input_q_p_r_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox108 = (gcnew System::Windows::Forms::TextBox());
			this->input_q_p_r_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox109 = (gcnew System::Windows::Forms::TextBox());
			this->input_q_p_r_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox110 = (gcnew System::Windows::Forms::TextBox());
			this->input_q_p_f_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox114 = (gcnew System::Windows::Forms::TextBox());
			this->input_q_p_f_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox115 = (gcnew System::Windows::Forms::TextBox());
			this->input_q_p_f_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox116 = (gcnew System::Windows::Forms::TextBox());
			this->input_n_p_o_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox117 = (gcnew System::Windows::Forms::TextBox());
			this->input_n_p_o_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox118 = (gcnew System::Windows::Forms::TextBox());
			this->input_n_p_o_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox119 = (gcnew System::Windows::Forms::TextBox());
			this->input_n_p_i_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox120 = (gcnew System::Windows::Forms::TextBox());
			this->input_n_p_i_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox121 = (gcnew System::Windows::Forms::TextBox());
			this->input_n_p_i_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox122 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_p_o_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox123 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_p_o_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox124 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_p_o_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox125 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_p_i_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox126 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_p_i_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox127 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_p_i_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox128 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox19 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox132 = (gcnew System::Windows::Forms::TextBox());
			this->input_bs_r_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox133 = (gcnew System::Windows::Forms::TextBox());
			this->input_bs_r_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox134 = (gcnew System::Windows::Forms::TextBox());
			this->textBox147 = (gcnew System::Windows::Forms::TextBox());
			this->input_bs_f_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox148 = (gcnew System::Windows::Forms::TextBox());
			this->input_bs_f_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox149 = (gcnew System::Windows::Forms::TextBox());
			this->textBox150 = (gcnew System::Windows::Forms::TextBox());
			this->input_ackermann_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox151 = (gcnew System::Windows::Forms::TextBox());
			this->input_ackermann_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox152 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox18 = (gcnew System::Windows::Forms::GroupBox());
			this->input_MR_arb_r_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox135 = (gcnew System::Windows::Forms::TextBox());
			this->input_MR_arb_r_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox136 = (gcnew System::Windows::Forms::TextBox());
			this->input_MR_arb_r_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox137 = (gcnew System::Windows::Forms::TextBox());
			this->input_MR_arb_f_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox138 = (gcnew System::Windows::Forms::TextBox());
			this->input_MR_arb_f_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox139 = (gcnew System::Windows::Forms::TextBox());
			this->input_MR_arb_f_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox140 = (gcnew System::Windows::Forms::TextBox());
			this->input_MR_s_r_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox141 = (gcnew System::Windows::Forms::TextBox());
			this->input_MR_s_r_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox142 = (gcnew System::Windows::Forms::TextBox());
			this->input_MR_s_r_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox143 = (gcnew System::Windows::Forms::TextBox());
			this->input_MR_s_f_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox144 = (gcnew System::Windows::Forms::TextBox());
			this->input_MR_s_f_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox145 = (gcnew System::Windows::Forms::TextBox());
			this->input_MR_s_f_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox146 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->input_q_r_r_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox111 = (gcnew System::Windows::Forms::TextBox());
			this->input_q_r_r_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox112 = (gcnew System::Windows::Forms::TextBox());
			this->input_q_r_r_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox113 = (gcnew System::Windows::Forms::TextBox());
			this->input_q_r_f_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox105 = (gcnew System::Windows::Forms::TextBox());
			this->input_q_r_f_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox106 = (gcnew System::Windows::Forms::TextBox());
			this->input_q_r_f_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox107 = (gcnew System::Windows::Forms::TextBox());
			this->input_off_r_r_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox102 = (gcnew System::Windows::Forms::TextBox());
			this->input_off_r_r_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox103 = (gcnew System::Windows::Forms::TextBox());
			this->input_off_r_r_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox104 = (gcnew System::Windows::Forms::TextBox());
			this->input_off_r_f_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox99 = (gcnew System::Windows::Forms::TextBox());
			this->input_off_r_f_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox100 = (gcnew System::Windows::Forms::TextBox());
			this->input_off_r_f_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox101 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_r_r_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox96 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_r_r_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox97 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_r_r_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox98 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_r_f_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_r_f_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->input_h_r_f_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox95 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->input_force_debug_iter = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->input_rear_arb_setup = (gcnew System::Windows::Forms::ComboBox());
			this->textBox84 = (gcnew System::Windows::Forms::TextBox());
			this->input_front_arb_setup = (gcnew System::Windows::Forms::ComboBox());
			this->textBox83 = (gcnew System::Windows::Forms::TextBox());
			this->input_rear_tires_selection = (gcnew System::Windows::Forms::ComboBox());
			this->textBox81 = (gcnew System::Windows::Forms::TextBox());
			this->input_front_tires_selection = (gcnew System::Windows::Forms::ComboBox());
			this->textBox82 = (gcnew System::Windows::Forms::TextBox());
			this->textBox36 = (gcnew System::Windows::Forms::TextBox());
			this->input_DB_input = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->input_gamma_r_static = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->input_BB_input = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->input_gamma_f_static = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox34 = (gcnew System::Windows::Forms::TextBox());
			this->input_delta_r_static = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox35 = (gcnew System::Windows::Forms::TextBox());
			this->input_delta_f_static = (gcnew System::Windows::Forms::NumericUpDown());
			this->fake_DB = (gcnew System::Windows::Forms::NumericUpDown());
			this->fake_BB = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->input_force_radius = (gcnew System::Windows::Forms::CheckBox());
			this->input_a_lon_des = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox184 = (gcnew System::Windows::Forms::TextBox());
			this->input_V_input = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_force_velocity = (gcnew System::Windows::Forms::CheckBox());
			this->input_steering_input = (gcnew System::Windows::Forms::ComboBox());
			this->textBox38 = (gcnew System::Windows::Forms::TextBox());
			this->input_pedals_input = (gcnew System::Windows::Forms::ComboBox());
			this->textBox37 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->input_delta_d_deg = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->input_beta_deg = (gcnew System::Windows::Forms::NumericUpDown());
			this->Display_corner_or_velocity = (gcnew System::Windows::Forms::TextBox());
			this->input_R = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_debug_iter = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->output_r_deg = (gcnew System::Windows::Forms::Label());
			this->output_R = (gcnew System::Windows::Forms::Label());
			this->output_V = (gcnew System::Windows::Forms::Label());
			this->output_bias_now = (gcnew System::Windows::Forms::Label());
			this->output_iter = (gcnew System::Windows::Forms::Label());
			this->output_a_rad = (gcnew System::Windows::Forms::Label());
			this->output_a_lat = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->output_F_z_fl = (gcnew System::Windows::Forms::Label());
			this->output_F_z_fr = (gcnew System::Windows::Forms::Label());
			this->output_F_z_rl = (gcnew System::Windows::Forms::Label());
			this->output_F_z_rr = (gcnew System::Windows::Forms::Label());
			this->output_F_x_comb_fl = (gcnew System::Windows::Forms::Label());
			this->output_F_x_comb_fr = (gcnew System::Windows::Forms::Label());
			this->output_F_x_comb_rl = (gcnew System::Windows::Forms::Label());
			this->output_F_x_comb_rr = (gcnew System::Windows::Forms::Label());
			this->output_F_y_comb_fl = (gcnew System::Windows::Forms::Label());
			this->output_F_y_comb_fr = (gcnew System::Windows::Forms::Label());
			this->output_F_y_comb_rl = (gcnew System::Windows::Forms::Label());
			this->output_F_y_comb_rr = (gcnew System::Windows::Forms::Label());
			this->output_F_lon_fl = (gcnew System::Windows::Forms::Label());
			this->output_F_lon_fr = (gcnew System::Windows::Forms::Label());
			this->output_F_lon_rl = (gcnew System::Windows::Forms::Label());
			this->output_F_lon_rr = (gcnew System::Windows::Forms::Label());
			this->output_F_lat_fl = (gcnew System::Windows::Forms::Label());
			this->output_F_lat_fr = (gcnew System::Windows::Forms::Label());
			this->output_F_lat_rl = (gcnew System::Windows::Forms::Label());
			this->output_F_lat_rr = (gcnew System::Windows::Forms::Label());
			this->output_kappa_fl = (gcnew System::Windows::Forms::Label());
			this->output_kappa_fr = (gcnew System::Windows::Forms::Label());
			this->output_kappa_rl = (gcnew System::Windows::Forms::Label());
			this->output_kappa_rr = (gcnew System::Windows::Forms::Label());
			this->output_alpha_fl = (gcnew System::Windows::Forms::Label());
			this->output_alpha_fr = (gcnew System::Windows::Forms::Label());
			this->output_alpha_rl = (gcnew System::Windows::Forms::Label());
			this->output_alpha_rr = (gcnew System::Windows::Forms::Label());
			this->output_T_fl = (gcnew System::Windows::Forms::Label());
			this->output_T_fr = (gcnew System::Windows::Forms::Label());
			this->output_T_rl = (gcnew System::Windows::Forms::Label());
			this->output_T_rr = (gcnew System::Windows::Forms::Label());
			this->output_M_yaw = (gcnew System::Windows::Forms::Label());
			this->output_F_lat = (gcnew System::Windows::Forms::Label());
			this->output_phi_deg = (gcnew System::Windows::Forms::Label());
			this->output_F_lon = (gcnew System::Windows::Forms::Label());
			this->output_psi_deg = (gcnew System::Windows::Forms::Label());
			this->output_a_lon = (gcnew System::Windows::Forms::Label());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer4 = (gcnew System::Windows::Forms::SplitContainer());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->input_con_delta_d = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox40 = (gcnew System::Windows::Forms::TextBox());
			this->input_con_beta = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox39 = (gcnew System::Windows::Forms::TextBox());
			this->input_max_delta_d = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_num_beta = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_num_delta_d = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox182 = (gcnew System::Windows::Forms::TextBox());
			this->textBox180 = (gcnew System::Windows::Forms::TextBox());
			this->input_max_beta = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox183 = (gcnew System::Windows::Forms::TextBox());
			this->textBox181 = (gcnew System::Windows::Forms::TextBox());
			this->YMD = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->debugPage = (gcnew System::Windows::Forms::TabPage());
			this->output_iter_total = (gcnew System::Windows::Forms::Label());
			this->output_golden_total = (gcnew System::Windows::Forms::Label());
			this->output_golden_single = (gcnew System::Windows::Forms::Label());
			this->output_brents_total = (gcnew System::Windows::Forms::Label());
			this->output_brents_single = (gcnew System::Windows::Forms::Label());
			this->output_debug4 = (gcnew System::Windows::Forms::Label());
			this->output_debug3 = (gcnew System::Windows::Forms::Label());
			this->output_debug2 = (gcnew System::Windows::Forms::Label());
			this->output_debug1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->panel1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox23->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabPage5->SuspendLayout();
			this->groupBox14->SuspendLayout();
			this->groupBox13->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_K_T))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_z_o))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_b_rr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_a_rr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_u))->BeginInit();
			this->groupBox12->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vx2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vx1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Hx2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Hx1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Kx3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Kx2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Kx1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ex4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ex3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ex2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ex1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dx3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dx2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dx1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Cx1))->BeginInit();
			this->groupBox11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vy4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vy3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vy2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vy1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Hy3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Hy2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Hy1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ky3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ky2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ky1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ey4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ey3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ey2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ey1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dy3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dy2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dy1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Cy1))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->tabControl4->SuspendLayout();
			this->tabPage10->SuspendLayout();
			this->groupBox16->SuspendLayout();
			this->groupBox15->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_fl))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_rr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_fr))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_rl))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_t_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_t_f))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_L))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_CG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_y))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_x))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m))->BeginInit();
			this->tabPage13->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_k_lock_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_preload_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_bTBR_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_dTBR_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_k_lock_f))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_preload_f))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_bTBR_f))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_dTBR_f))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_k_lock_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_preload_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_bTBR_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_dTBR_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_k_lock_f))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_preload_f))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_bTBR_f))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_dTBR_f))->BeginInit();
			this->tabPage11->SuspendLayout();
			this->groupBox21->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_y_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_y_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_y_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_z_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_z_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_z_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_y_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_y_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_y_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_x_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_x_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_x_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_2))->BeginInit();
			this->tabPage12->SuspendLayout();
			this->groupBox22->SuspendLayout();
			this->groupBox10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->spring_stiffness))->BeginInit();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_p_C_dist))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_p_C_deg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_r_C_dist))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_r_C_deg))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_susp_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_susp_f))->BeginInit();
			this->tabPage14->SuspendLayout();
			this->groupBox20->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_f_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_f_2))->BeginInit();
			this->groupBox17->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_r_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_f_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_f_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_o_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_o_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_o_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_i_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_i_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_i_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_o_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_o_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_o_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_i_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_i_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_i_2))->BeginInit();
			this->groupBox19->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bs_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bs_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bs_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bs_f_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_ackermann_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_ackermann_2))->BeginInit();
			this->groupBox18->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_r_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_f_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_f_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_r_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_f_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_f_2))->BeginInit();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_r_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_f_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_f_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_r_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_f_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_f_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_r_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_f_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_f_2))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->groupBox9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_DB_input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_gamma_r_static))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_BB_input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_gamma_f_static))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_delta_r_static))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_delta_f_static))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_DB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_BB))->BeginInit();
			this->groupBox8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_a_lon_des))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_V_input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_delta_d_deg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_beta_deg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_R))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_debug_iter))->BeginInit();
			this->tabControl2->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tabPage7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer4))->BeginInit();
			this->splitContainer4->Panel1->SuspendLayout();
			this->splitContainer4->Panel2->SuspendLayout();
			this->splitContainer4->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_con_delta_d))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_con_beta))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_max_delta_d))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_num_beta))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_num_delta_d))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_max_beta))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->YMD))->BeginInit();
			this->debugPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Window;
			this->panel1->Controls->Add(this->RUN_YMD);
			this->panel1->Controls->Add(this->RUN);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(97, 675);
			this->panel1->TabIndex = 1;
			// 
			// RUN_YMD
			// 
			this->RUN_YMD->BackColor = System::Drawing::Color::Red;
			this->RUN_YMD->Dock = System::Windows::Forms::DockStyle::Top;
			this->RUN_YMD->Location = System::Drawing::Point(0, 78);
			this->RUN_YMD->Name = L"RUN_YMD";
			this->RUN_YMD->Size = System::Drawing::Size(97, 78);
			this->RUN_YMD->TabIndex = 1;
			this->RUN_YMD->Text = L"YMD";
			this->RUN_YMD->UseVisualStyleBackColor = false;
			this->RUN_YMD->Click += gcnew System::EventHandler(this, &MyForm::RUN_YMD_Click);
			// 
			// RUN
			// 
			this->RUN->BackColor = System::Drawing::Color::SpringGreen;
			this->RUN->Dock = System::Windows::Forms::DockStyle::Top;
			this->RUN->Location = System::Drawing::Point(0, 0);
			this->RUN->Name = L"RUN";
			this->RUN->Size = System::Drawing::Size(97, 78);
			this->RUN->TabIndex = 0;
			this->RUN->Text = L"SINGLE RUN";
			this->RUN->UseVisualStyleBackColor = false;
			this->RUN->Click += gcnew System::EventHandler(this, &MyForm::RUN_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->debugPage);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1083, 675);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->linkLabelAdditions);
			this->tabPage1->Controls->Add(this->linkLabelUserGuide);
			this->tabPage1->Controls->Add(this->linkLabelThesis);
			this->tabPage1->Controls->Add(this->textBox92);
			this->tabPage1->Controls->Add(this->groupBox23);
			this->tabPage1->Location = System::Drawing::Point(4, 35);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1075, 636);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Welcome";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// linkLabelAdditions
			// 
			this->linkLabelAdditions->AutoSize = true;
			this->linkLabelAdditions->BackColor = System::Drawing::SystemColors::Control;
			this->linkLabelAdditions->Location = System::Drawing::Point(633, 205);
			this->linkLabelAdditions->Name = L"linkLabelAdditions";
			this->linkLabelAdditions->Size = System::Drawing::Size(64, 26);
			this->linkLabelAdditions->TabIndex = 5;
			this->linkLabelAdditions->TabStop = true;
			this->linkLabelAdditions->Text = L"Thesis";
			this->linkLabelAdditions->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabelAdditions_LinkClicked);
			// 
			// linkLabelUserGuide
			// 
			this->linkLabelUserGuide->AutoSize = true;
			this->linkLabelUserGuide->BackColor = System::Drawing::SystemColors::Control;
			this->linkLabelUserGuide->Location = System::Drawing::Point(761, 203);
			this->linkLabelUserGuide->Name = L"linkLabelUserGuide";
			this->linkLabelUserGuide->Size = System::Drawing::Size(105, 26);
			this->linkLabelUserGuide->TabIndex = 4;
			this->linkLabelUserGuide->TabStop = true;
			this->linkLabelUserGuide->Text = L"User Guide";
			this->linkLabelUserGuide->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabelUserGuide_LinkClicked);
			// 
			// linkLabelThesis
			// 
			this->linkLabelThesis->AutoSize = true;
			this->linkLabelThesis->BackColor = System::Drawing::SystemColors::Control;
			this->linkLabelThesis->Location = System::Drawing::Point(489, 203);
			this->linkLabelThesis->Name = L"linkLabelThesis";
			this->linkLabelThesis->Size = System::Drawing::Size(64, 26);
			this->linkLabelThesis->TabIndex = 3;
			this->linkLabelThesis->TabStop = true;
			this->linkLabelThesis->Text = L"Thesis";
			this->linkLabelThesis->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabelThesis_LinkClicked);
			// 
			// textBox92
			// 
			this->textBox92->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->textBox92->Location = System::Drawing::Point(453, 6);
			this->textBox92->Multiline = true;
			this->textBox92->Name = L"textBox92";
			this->textBox92->ReadOnly = true;
			this->textBox92->Size = System::Drawing::Size(429, 252);
			this->textBox92->TabIndex = 2;
			this->textBox92->Text = resources->GetString(L"textBox92.Text");
			// 
			// groupBox23
			// 
			this->groupBox23->Controls->Add(this->textBox91);
			this->groupBox23->Controls->Add(this->pictureBox1);
			this->groupBox23->Location = System::Drawing::Point(6, 6);
			this->groupBox23->Name = L"groupBox23";
			this->groupBox23->Size = System::Drawing::Size(441, 487);
			this->groupBox23->TabIndex = 1;
			this->groupBox23->TabStop = false;
			this->groupBox23->Text = L"Sign convention";
			// 
			// textBox91
			// 
			this->textBox91->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->textBox91->Location = System::Drawing::Point(6, 199);
			this->textBox91->Multiline = true;
			this->textBox91->Name = L"textBox91";
			this->textBox91->ReadOnly = true;
			this->textBox91->Size = System::Drawing::Size(429, 282);
			this->textBox91->TabIndex = 1;
			this->textBox91->Text = resources->GetString(L"textBox91.Text");
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 29);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(435, 164);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->groupBox14);
			this->tabPage5->Controls->Add(this->groupBox13);
			this->tabPage5->Controls->Add(this->groupBox12);
			this->tabPage5->Controls->Add(this->groupBox11);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(1075, 649);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Tires";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// groupBox14
			// 
			this->groupBox14->Controls->Add(this->tire_name);
			this->groupBox14->Controls->Add(this->tire_save);
			this->groupBox14->Controls->Add(this->tire_delete);
			this->groupBox14->Controls->Add(this->tire_new);
			this->groupBox14->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox14->Location = System::Drawing::Point(6, 6);
			this->groupBox14->Name = L"groupBox14";
			this->groupBox14->Size = System::Drawing::Size(241, 113);
			this->groupBox14->TabIndex = 55;
			this->groupBox14->TabStop = false;
			this->groupBox14->Text = L"Tire name";
			// 
			// tire_name
			// 
			this->tire_name->FormattingEnabled = true;
			this->tire_name->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"\t" });
			this->tire_name->Location = System::Drawing::Point(6, 26);
			this->tire_name->Name = L"tire_name";
			this->tire_name->Size = System::Drawing::Size(229, 34);
			this->tire_name->TabIndex = 8;
			this->tire_name->SelectionChangeCommitted += gcnew System::EventHandler(this, &MyForm::tire_name_SelectionChangeCommitted);
			// 
			// tire_save
			// 
			this->tire_save->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tire_save->Location = System::Drawing::Point(150, 66);
			this->tire_save->Name = L"tire_save";
			this->tire_save->Size = System::Drawing::Size(42, 35);
			this->tire_save->TabIndex = 7;
			this->tire_save->Text = L"Save";
			this->tire_save->UseVisualStyleBackColor = true;
			this->tire_save->Click += gcnew System::EventHandler(this, &MyForm::tire_save_Click);
			// 
			// tire_delete
			// 
			this->tire_delete->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tire_delete->Location = System::Drawing::Point(97, 66);
			this->tire_delete->Name = L"tire_delete";
			this->tire_delete->Size = System::Drawing::Size(47, 35);
			this->tire_delete->TabIndex = 5;
			this->tire_delete->Text = L"Delete";
			this->tire_delete->UseVisualStyleBackColor = true;
			this->tire_delete->Click += gcnew System::EventHandler(this, &MyForm::tire_delete_Click);
			// 
			// tire_new
			// 
			this->tire_new->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tire_new->Location = System::Drawing::Point(49, 66);
			this->tire_new->Name = L"tire_new";
			this->tire_new->Size = System::Drawing::Size(42, 35);
			this->tire_new->TabIndex = 4;
			this->tire_new->Text = L"New";
			this->tire_new->UseVisualStyleBackColor = true;
			this->tire_new->Click += gcnew System::EventHandler(this, &MyForm::tire_new_Click);
			// 
			// groupBox13
			// 
			this->groupBox13->Controls->Add(this->textBox80);
			this->groupBox13->Controls->Add(this->input_K_T);
			this->groupBox13->Controls->Add(this->textBox61);
			this->groupBox13->Controls->Add(this->input_F_z_o);
			this->groupBox13->Controls->Add(this->input_b_rr);
			this->groupBox13->Controls->Add(this->textBox62);
			this->groupBox13->Controls->Add(this->textBox63);
			this->groupBox13->Controls->Add(this->input_a_rr);
			this->groupBox13->Controls->Add(this->input_r_u);
			this->groupBox13->Controls->Add(this->textBox79);
			this->groupBox13->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox13->Location = System::Drawing::Point(639, 9);
			this->groupBox13->Name = L"groupBox13";
			this->groupBox13->Size = System::Drawing::Size(241, 286);
			this->groupBox13->TabIndex = 54;
			this->groupBox13->TabStop = false;
			this->groupBox13->Text = L"Other";
			// 
			// textBox80
			// 
			this->textBox80->BackColor = System::Drawing::SystemColors::Window;
			this->textBox80->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox80->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox80->Location = System::Drawing::Point(6, 237);
			this->textBox80->Multiline = true;
			this->textBox80->Name = L"textBox80";
			this->textBox80->ReadOnly = true;
			this->textBox80->Size = System::Drawing::Size(138, 45);
			this->textBox80->TabIndex = 10;
			this->textBox80->Text = L"Tire vertical stiffness [N/mm]";
			// 
			// input_K_T
			// 
			this->input_K_T->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_K_T->DecimalPlaces = 2;
			this->input_K_T->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_K_T->Location = System::Drawing::Point(150, 246);
			this->input_K_T->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->input_K_T->Name = L"input_K_T";
			this->input_K_T->Size = System::Drawing::Size(74, 27);
			this->input_K_T->TabIndex = 9;
			this->input_K_T->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 133358, 0, 0, 196608 });
			// 
			// textBox61
			// 
			this->textBox61->BackColor = System::Drawing::SystemColors::Window;
			this->textBox61->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox61->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox61->Location = System::Drawing::Point(6, 186);
			this->textBox61->Multiline = true;
			this->textBox61->Name = L"textBox61";
			this->textBox61->ReadOnly = true;
			this->textBox61->Size = System::Drawing::Size(138, 45);
			this->textBox61->TabIndex = 8;
			this->textBox61->Text = L"Nominal tire load [N]";
			// 
			// input_F_z_o
			// 
			this->input_F_z_o->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_z_o->DecimalPlaces = 2;
			this->input_F_z_o->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_z_o->Location = System::Drawing::Point(150, 195);
			this->input_F_z_o->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_z_o->Name = L"input_F_z_o";
			this->input_F_z_o->Size = System::Drawing::Size(74, 27);
			this->input_F_z_o->TabIndex = 7;
			this->input_F_z_o->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 667, 0, 0, 0 });
			// 
			// input_b_rr
			// 
			this->input_b_rr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_b_rr->DecimalPlaces = 4;
			this->input_b_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_b_rr->Location = System::Drawing::Point(150, 147);
			this->input_b_rr->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_b_rr->Name = L"input_b_rr";
			this->input_b_rr->Size = System::Drawing::Size(74, 27);
			this->input_b_rr->TabIndex = 5;
			this->input_b_rr->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 52, 0, 0, 196608 });
			// 
			// textBox62
			// 
			this->textBox62->BackColor = System::Drawing::SystemColors::Window;
			this->textBox62->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox62->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox62->Location = System::Drawing::Point(6, 138);
			this->textBox62->Multiline = true;
			this->textBox62->Name = L"textBox62";
			this->textBox62->ReadOnly = true;
			this->textBox62->Size = System::Drawing::Size(138, 45);
			this->textBox62->TabIndex = 6;
			this->textBox62->Text = L"Rolling resistance parameter \"b\" [1/N]";
			// 
			// textBox63
			// 
			this->textBox63->BackColor = System::Drawing::SystemColors::Window;
			this->textBox63->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox63->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox63->Location = System::Drawing::Point(6, 87);
			this->textBox63->Multiline = true;
			this->textBox63->Name = L"textBox63";
			this->textBox63->ReadOnly = true;
			this->textBox63->Size = System::Drawing::Size(138, 45);
			this->textBox63->TabIndex = 4;
			this->textBox63->Text = L"Rolling resistance parameter \"a\" [-]";
			// 
			// input_a_rr
			// 
			this->input_a_rr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_a_rr->DecimalPlaces = 4;
			this->input_a_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_a_rr->Location = System::Drawing::Point(150, 94);
			this->input_a_rr->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_a_rr->Name = L"input_a_rr";
			this->input_a_rr->Size = System::Drawing::Size(74, 27);
			this->input_a_rr->TabIndex = 3;
			this->input_a_rr->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 258, 0, 0, 262144 });
			// 
			// input_r_u
			// 
			this->input_r_u->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_r_u->DecimalPlaces = 2;
			this->input_r_u->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_r_u->Location = System::Drawing::Point(150, 41);
			this->input_r_u->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->input_r_u->Name = L"input_r_u";
			this->input_r_u->Size = System::Drawing::Size(74, 27);
			this->input_r_u->TabIndex = 0;
			this->input_r_u->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2286, 0, 0, 65536 });
			// 
			// textBox79
			// 
			this->textBox79->BackColor = System::Drawing::SystemColors::Window;
			this->textBox79->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox79->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox79->Location = System::Drawing::Point(6, 32);
			this->textBox79->Multiline = true;
			this->textBox79->Name = L"textBox79";
			this->textBox79->ReadOnly = true;
			this->textBox79->Size = System::Drawing::Size(138, 45);
			this->textBox79->TabIndex = 2;
			this->textBox79->Text = L"Unloaded tire radius [mm]";
			// 
			// groupBox12
			// 
			this->groupBox12->Controls->Add(this->input_p_Vx2);
			this->groupBox12->Controls->Add(this->input_p_Vx1);
			this->groupBox12->Controls->Add(this->input_p_Hx2);
			this->groupBox12->Controls->Add(this->input_p_Hx1);
			this->groupBox12->Controls->Add(this->input_p_Kx3);
			this->groupBox12->Controls->Add(this->input_p_Kx2);
			this->groupBox12->Controls->Add(this->input_p_Kx1);
			this->groupBox12->Controls->Add(this->input_p_Ex4);
			this->groupBox12->Controls->Add(this->input_p_Ex3);
			this->groupBox12->Controls->Add(this->input_p_Ex2);
			this->groupBox12->Controls->Add(this->input_p_Ex1);
			this->groupBox12->Controls->Add(this->input_p_Dx3);
			this->groupBox12->Controls->Add(this->input_p_Dx2);
			this->groupBox12->Controls->Add(this->textBox64);
			this->groupBox12->Controls->Add(this->textBox65);
			this->groupBox12->Controls->Add(this->textBox66);
			this->groupBox12->Controls->Add(this->textBox67);
			this->groupBox12->Controls->Add(this->textBox68);
			this->groupBox12->Controls->Add(this->textBox69);
			this->groupBox12->Controls->Add(this->textBox70);
			this->groupBox12->Controls->Add(this->textBox71);
			this->groupBox12->Controls->Add(this->textBox72);
			this->groupBox12->Controls->Add(this->textBox73);
			this->groupBox12->Controls->Add(this->textBox74);
			this->groupBox12->Controls->Add(this->textBox75);
			this->groupBox12->Controls->Add(this->textBox76);
			this->groupBox12->Controls->Add(this->input_p_Dx1);
			this->groupBox12->Controls->Add(this->textBox77);
			this->groupBox12->Controls->Add(this->input_p_Cx1);
			this->groupBox12->Controls->Add(this->textBox78);
			this->groupBox12->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox12->Location = System::Drawing::Point(446, 9);
			this->groupBox12->Name = L"groupBox12";
			this->groupBox12->Size = System::Drawing::Size(187, 529);
			this->groupBox12->TabIndex = 53;
			this->groupBox12->TabStop = false;
			this->groupBox12->Text = L"Longitudinal";
			// 
			// input_p_Vx2
			// 
			this->input_p_Vx2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Vx2->DecimalPlaces = 7;
			this->input_p_Vx2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Vx2->Location = System::Drawing::Point(70, 490);
			this->input_p_Vx2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Vx2->Name = L"input_p_Vx2";
			this->input_p_Vx2->Size = System::Drawing::Size(110, 27);
			this->input_p_Vx2->TabIndex = 49;
			this->input_p_Vx2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 547334, 0, 0, -2147024896 });
			// 
			// input_p_Vx1
			// 
			this->input_p_Vx1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Vx1->DecimalPlaces = 7;
			this->input_p_Vx1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Vx1->Location = System::Drawing::Point(70, 457);
			this->input_p_Vx1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Vx1->Name = L"input_p_Vx1";
			this->input_p_Vx1->Size = System::Drawing::Size(110, 27);
			this->input_p_Vx1->TabIndex = 48;
			this->input_p_Vx1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 230756, 0, 0, -2147024896 });
			// 
			// input_p_Hx2
			// 
			this->input_p_Hx2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Hx2->DecimalPlaces = 8;
			this->input_p_Hx2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Hx2->Location = System::Drawing::Point(70, 424);
			this->input_p_Hx2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Hx2->Name = L"input_p_Hx2";
			this->input_p_Hx2->Size = System::Drawing::Size(110, 27);
			this->input_p_Hx2->TabIndex = 47;
			this->input_p_Hx2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 149605, 0, 0, 524288 });
			// 
			// input_p_Hx1
			// 
			this->input_p_Hx1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Hx1->DecimalPlaces = 8;
			this->input_p_Hx1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Hx1->Location = System::Drawing::Point(71, 391);
			this->input_p_Hx1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Hx1->Name = L"input_p_Hx1";
			this->input_p_Hx1->Size = System::Drawing::Size(110, 27);
			this->input_p_Hx1->TabIndex = 46;
			this->input_p_Hx1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 773539, 0, 0, 589824 });
			// 
			// input_p_Kx3
			// 
			this->input_p_Kx3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Kx3->DecimalPlaces = 6;
			this->input_p_Kx3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Kx3->Location = System::Drawing::Point(70, 358);
			this->input_p_Kx3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Kx3->Name = L"input_p_Kx3";
			this->input_p_Kx3->Size = System::Drawing::Size(110, 27);
			this->input_p_Kx3->TabIndex = 45;
			this->input_p_Kx3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 302759, 0, 0, -2147090432 });
			// 
			// input_p_Kx2
			// 
			this->input_p_Kx2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Kx2->DecimalPlaces = 8;
			this->input_p_Kx2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Kx2->Location = System::Drawing::Point(70, 325);
			this->input_p_Kx2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Kx2->Name = L"input_p_Kx2";
			this->input_p_Kx2->Size = System::Drawing::Size(110, 27);
			this->input_p_Kx2->TabIndex = 44;
			this->input_p_Kx2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 284881, 0, 0, -2146762752 });
			// 
			// input_p_Kx1
			// 
			this->input_p_Kx1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Kx1->DecimalPlaces = 4;
			this->input_p_Kx1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Kx1->Location = System::Drawing::Point(70, 292);
			this->input_p_Kx1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Kx1->Name = L"input_p_Kx1";
			this->input_p_Kx1->Size = System::Drawing::Size(110, 27);
			this->input_p_Kx1->TabIndex = 43;
			this->input_p_Kx1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 565587, 0, 0, 262144 });
			// 
			// input_p_Ex4
			// 
			this->input_p_Ex4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Ex4->DecimalPlaces = 5;
			this->input_p_Ex4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Ex4->Location = System::Drawing::Point(71, 259);
			this->input_p_Ex4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Ex4->Name = L"input_p_Ex4";
			this->input_p_Ex4->Size = System::Drawing::Size(110, 27);
			this->input_p_Ex4->TabIndex = 42;
			this->input_p_Ex4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59049, 0, 0, -2147155968 });
			// 
			// input_p_Ex3
			// 
			this->input_p_Ex3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Ex3->DecimalPlaces = 5;
			this->input_p_Ex3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Ex3->Location = System::Drawing::Point(71, 226);
			this->input_p_Ex3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Ex3->Name = L"input_p_Ex3";
			this->input_p_Ex3->Size = System::Drawing::Size(110, 27);
			this->input_p_Ex3->TabIndex = 41;
			this->input_p_Ex3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 198825, 0, 0, -2147155968 });
			// 
			// input_p_Ex2
			// 
			this->input_p_Ex2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Ex2->DecimalPlaces = 6;
			this->input_p_Ex2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Ex2->Location = System::Drawing::Point(71, 193);
			this->input_p_Ex2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Ex2->Name = L"input_p_Ex2";
			this->input_p_Ex2->Size = System::Drawing::Size(110, 27);
			this->input_p_Ex2->TabIndex = 40;
			this->input_p_Ex2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 363558, 0, 0, 393216 });
			// 
			// input_p_Ex1
			// 
			this->input_p_Ex1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Ex1->DecimalPlaces = 6;
			this->input_p_Ex1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Ex1->Location = System::Drawing::Point(71, 160);
			this->input_p_Ex1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Ex1->Name = L"input_p_Ex1";
			this->input_p_Ex1->Size = System::Drawing::Size(110, 27);
			this->input_p_Ex1->TabIndex = 39;
			this->input_p_Ex1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 132474, 0, 0, -2147090432 });
			// 
			// input_p_Dx3
			// 
			this->input_p_Dx3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Dx3->DecimalPlaces = 4;
			this->input_p_Dx3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Dx3->Location = System::Drawing::Point(71, 127);
			this->input_p_Dx3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Dx3->Name = L"input_p_Dx3";
			this->input_p_Dx3->Size = System::Drawing::Size(110, 27);
			this->input_p_Dx3->TabIndex = 38;
			this->input_p_Dx3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 19316, 0, 0, 196608 });
			// 
			// input_p_Dx2
			// 
			this->input_p_Dx2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Dx2->DecimalPlaces = 6;
			this->input_p_Dx2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Dx2->Location = System::Drawing::Point(71, 94);
			this->input_p_Dx2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Dx2->Name = L"input_p_Dx2";
			this->input_p_Dx2->Size = System::Drawing::Size(110, 27);
			this->input_p_Dx2->TabIndex = 37;
			this->input_p_Dx2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99395, 0, 0, -2147090432 });
			// 
			// textBox64
			// 
			this->textBox64->BackColor = System::Drawing::SystemColors::Window;
			this->textBox64->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox64->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox64->Location = System::Drawing::Point(6, 492);
			this->textBox64->Multiline = true;
			this->textBox64->Name = L"textBox64";
			this->textBox64->ReadOnly = true;
			this->textBox64->Size = System::Drawing::Size(58, 25);
			this->textBox64->TabIndex = 30;
			this->textBox64->Text = L"pVx2";
			// 
			// textBox65
			// 
			this->textBox65->BackColor = System::Drawing::SystemColors::Window;
			this->textBox65->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox65->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox65->Location = System::Drawing::Point(6, 459);
			this->textBox65->Multiline = true;
			this->textBox65->Name = L"textBox65";
			this->textBox65->ReadOnly = true;
			this->textBox65->Size = System::Drawing::Size(58, 25);
			this->textBox65->TabIndex = 28;
			this->textBox65->Text = L"pVx1";
			// 
			// textBox66
			// 
			this->textBox66->BackColor = System::Drawing::SystemColors::Window;
			this->textBox66->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox66->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox66->Location = System::Drawing::Point(6, 426);
			this->textBox66->Multiline = true;
			this->textBox66->Name = L"textBox66";
			this->textBox66->ReadOnly = true;
			this->textBox66->Size = System::Drawing::Size(58, 25);
			this->textBox66->TabIndex = 26;
			this->textBox66->Text = L"pHx2";
			// 
			// textBox67
			// 
			this->textBox67->BackColor = System::Drawing::SystemColors::Window;
			this->textBox67->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox67->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox67->Location = System::Drawing::Point(6, 393);
			this->textBox67->Multiline = true;
			this->textBox67->Name = L"textBox67";
			this->textBox67->ReadOnly = true;
			this->textBox67->Size = System::Drawing::Size(58, 25);
			this->textBox67->TabIndex = 24;
			this->textBox67->Text = L"pHx1";
			// 
			// textBox68
			// 
			this->textBox68->BackColor = System::Drawing::SystemColors::Window;
			this->textBox68->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox68->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox68->Location = System::Drawing::Point(6, 360);
			this->textBox68->Multiline = true;
			this->textBox68->Name = L"textBox68";
			this->textBox68->ReadOnly = true;
			this->textBox68->Size = System::Drawing::Size(58, 25);
			this->textBox68->TabIndex = 22;
			this->textBox68->Text = L"pKx3";
			// 
			// textBox69
			// 
			this->textBox69->BackColor = System::Drawing::SystemColors::Window;
			this->textBox69->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox69->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox69->Location = System::Drawing::Point(6, 327);
			this->textBox69->Multiline = true;
			this->textBox69->Name = L"textBox69";
			this->textBox69->ReadOnly = true;
			this->textBox69->Size = System::Drawing::Size(58, 25);
			this->textBox69->TabIndex = 20;
			this->textBox69->Text = L"pKx2";
			// 
			// textBox70
			// 
			this->textBox70->BackColor = System::Drawing::SystemColors::Window;
			this->textBox70->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox70->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox70->Location = System::Drawing::Point(6, 294);
			this->textBox70->Multiline = true;
			this->textBox70->Name = L"textBox70";
			this->textBox70->ReadOnly = true;
			this->textBox70->Size = System::Drawing::Size(58, 25);
			this->textBox70->TabIndex = 18;
			this->textBox70->Text = L"pKx1";
			// 
			// textBox71
			// 
			this->textBox71->BackColor = System::Drawing::SystemColors::Window;
			this->textBox71->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox71->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox71->Location = System::Drawing::Point(6, 261);
			this->textBox71->Multiline = true;
			this->textBox71->Name = L"textBox71";
			this->textBox71->ReadOnly = true;
			this->textBox71->Size = System::Drawing::Size(58, 25);
			this->textBox71->TabIndex = 16;
			this->textBox71->Text = L"pEx4";
			// 
			// textBox72
			// 
			this->textBox72->BackColor = System::Drawing::SystemColors::Window;
			this->textBox72->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox72->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox72->Location = System::Drawing::Point(6, 228);
			this->textBox72->Multiline = true;
			this->textBox72->Name = L"textBox72";
			this->textBox72->ReadOnly = true;
			this->textBox72->Size = System::Drawing::Size(58, 25);
			this->textBox72->TabIndex = 14;
			this->textBox72->Text = L"pEx3";
			// 
			// textBox73
			// 
			this->textBox73->BackColor = System::Drawing::SystemColors::Window;
			this->textBox73->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox73->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox73->Location = System::Drawing::Point(6, 195);
			this->textBox73->Multiline = true;
			this->textBox73->Name = L"textBox73";
			this->textBox73->ReadOnly = true;
			this->textBox73->Size = System::Drawing::Size(58, 25);
			this->textBox73->TabIndex = 12;
			this->textBox73->Text = L"pEx2";
			// 
			// textBox74
			// 
			this->textBox74->BackColor = System::Drawing::SystemColors::Window;
			this->textBox74->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox74->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox74->Location = System::Drawing::Point(6, 162);
			this->textBox74->Multiline = true;
			this->textBox74->Name = L"textBox74";
			this->textBox74->ReadOnly = true;
			this->textBox74->Size = System::Drawing::Size(58, 25);
			this->textBox74->TabIndex = 10;
			this->textBox74->Text = L"pEx1";
			// 
			// textBox75
			// 
			this->textBox75->BackColor = System::Drawing::SystemColors::Window;
			this->textBox75->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox75->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox75->Location = System::Drawing::Point(6, 129);
			this->textBox75->Multiline = true;
			this->textBox75->Name = L"textBox75";
			this->textBox75->ReadOnly = true;
			this->textBox75->Size = System::Drawing::Size(58, 25);
			this->textBox75->TabIndex = 8;
			this->textBox75->Text = L"pDx3";
			// 
			// textBox76
			// 
			this->textBox76->BackColor = System::Drawing::SystemColors::Window;
			this->textBox76->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox76->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox76->Location = System::Drawing::Point(6, 96);
			this->textBox76->Multiline = true;
			this->textBox76->Name = L"textBox76";
			this->textBox76->ReadOnly = true;
			this->textBox76->Size = System::Drawing::Size(58, 25);
			this->textBox76->TabIndex = 6;
			this->textBox76->Text = L"pDx2";
			// 
			// input_p_Dx1
			// 
			this->input_p_Dx1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Dx1->DecimalPlaces = 5;
			this->input_p_Dx1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Dx1->Location = System::Drawing::Point(71, 61);
			this->input_p_Dx1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Dx1->Name = L"input_p_Dx1";
			this->input_p_Dx1->Size = System::Drawing::Size(110, 27);
			this->input_p_Dx1->TabIndex = 3;
			this->input_p_Dx1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 296086, 0, 0, 327680 });
			// 
			// textBox77
			// 
			this->textBox77->BackColor = System::Drawing::SystemColors::Window;
			this->textBox77->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox77->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox77->Location = System::Drawing::Point(6, 63);
			this->textBox77->Multiline = true;
			this->textBox77->Name = L"textBox77";
			this->textBox77->ReadOnly = true;
			this->textBox77->Size = System::Drawing::Size(58, 25);
			this->textBox77->TabIndex = 4;
			this->textBox77->Text = L"pDx1";
			// 
			// input_p_Cx1
			// 
			this->input_p_Cx1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Cx1->DecimalPlaces = 5;
			this->input_p_Cx1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Cx1->Location = System::Drawing::Point(71, 30);
			this->input_p_Cx1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Cx1->Name = L"input_p_Cx1";
			this->input_p_Cx1->Size = System::Drawing::Size(110, 27);
			this->input_p_Cx1->TabIndex = 0;
			this->input_p_Cx1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// textBox78
			// 
			this->textBox78->BackColor = System::Drawing::SystemColors::Window;
			this->textBox78->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox78->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox78->Location = System::Drawing::Point(6, 32);
			this->textBox78->Multiline = true;
			this->textBox78->Name = L"textBox78";
			this->textBox78->ReadOnly = true;
			this->textBox78->Size = System::Drawing::Size(58, 25);
			this->textBox78->TabIndex = 2;
			this->textBox78->Text = L"pCx1";
			// 
			// groupBox11
			// 
			this->groupBox11->Controls->Add(this->input_p_Vy4);
			this->groupBox11->Controls->Add(this->input_p_Vy3);
			this->groupBox11->Controls->Add(this->input_p_Vy2);
			this->groupBox11->Controls->Add(this->input_p_Vy1);
			this->groupBox11->Controls->Add(this->input_p_Hy3);
			this->groupBox11->Controls->Add(this->input_p_Hy2);
			this->groupBox11->Controls->Add(this->input_p_Hy1);
			this->groupBox11->Controls->Add(this->input_p_Ky3);
			this->groupBox11->Controls->Add(this->input_p_Ky2);
			this->groupBox11->Controls->Add(this->input_p_Ky1);
			this->groupBox11->Controls->Add(this->input_p_Ey4);
			this->groupBox11->Controls->Add(this->input_p_Ey3);
			this->groupBox11->Controls->Add(this->input_p_Ey2);
			this->groupBox11->Controls->Add(this->input_p_Ey1);
			this->groupBox11->Controls->Add(this->input_p_Dy3);
			this->groupBox11->Controls->Add(this->input_p_Dy2);
			this->groupBox11->Controls->Add(this->textBox60);
			this->groupBox11->Controls->Add(this->textBox59);
			this->groupBox11->Controls->Add(this->textBox58);
			this->groupBox11->Controls->Add(this->textBox57);
			this->groupBox11->Controls->Add(this->textBox56);
			this->groupBox11->Controls->Add(this->textBox55);
			this->groupBox11->Controls->Add(this->textBox54);
			this->groupBox11->Controls->Add(this->textBox53);
			this->groupBox11->Controls->Add(this->textBox52);
			this->groupBox11->Controls->Add(this->textBox51);
			this->groupBox11->Controls->Add(this->textBox50);
			this->groupBox11->Controls->Add(this->textBox49);
			this->groupBox11->Controls->Add(this->textBox48);
			this->groupBox11->Controls->Add(this->textBox47);
			this->groupBox11->Controls->Add(this->textBox46);
			this->groupBox11->Controls->Add(this->textBox45);
			this->groupBox11->Controls->Add(this->input_p_Dy1);
			this->groupBox11->Controls->Add(this->textBox43);
			this->groupBox11->Controls->Add(this->input_p_Cy1);
			this->groupBox11->Controls->Add(this->textBox44);
			this->groupBox11->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox11->Location = System::Drawing::Point(253, 9);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(187, 624);
			this->groupBox11->TabIndex = 19;
			this->groupBox11->TabStop = false;
			this->groupBox11->Text = L"Lateral";
			// 
			// input_p_Vy4
			// 
			this->input_p_Vy4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Vy4->DecimalPlaces = 5;
			this->input_p_Vy4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Vy4->Location = System::Drawing::Point(70, 589);
			this->input_p_Vy4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Vy4->Name = L"input_p_Vy4";
			this->input_p_Vy4->Size = System::Drawing::Size(110, 27);
			this->input_p_Vy4->TabIndex = 52;
			this->input_p_Vy4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 290347, 0, 0, -2147155968 });
			// 
			// input_p_Vy3
			// 
			this->input_p_Vy3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Vy3->DecimalPlaces = 5;
			this->input_p_Vy3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Vy3->Location = System::Drawing::Point(70, 556);
			this->input_p_Vy3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Vy3->Name = L"input_p_Vy3";
			this->input_p_Vy3->Size = System::Drawing::Size(110, 27);
			this->input_p_Vy3->TabIndex = 51;
			this->input_p_Vy3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99486, 0, 0, 327680 });
			// 
			// input_p_Vy2
			// 
			this->input_p_Vy2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Vy2->DecimalPlaces = 7;
			this->input_p_Vy2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Vy2->Location = System::Drawing::Point(70, 523);
			this->input_p_Vy2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Vy2->Name = L"input_p_Vy2";
			this->input_p_Vy2->Size = System::Drawing::Size(110, 27);
			this->input_p_Vy2->TabIndex = 50;
			this->input_p_Vy2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 330034, 0, 0, 458752 });
			// 
			// input_p_Vy1
			// 
			this->input_p_Vy1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Vy1->DecimalPlaces = 7;
			this->input_p_Vy1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Vy1->Location = System::Drawing::Point(70, 490);
			this->input_p_Vy1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Vy1->Name = L"input_p_Vy1";
			this->input_p_Vy1->Size = System::Drawing::Size(110, 27);
			this->input_p_Vy1->TabIndex = 49;
			this->input_p_Vy1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 199972, 0, 0, -2147024896 });
			// 
			// input_p_Hy3
			// 
			this->input_p_Hy3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Hy3->DecimalPlaces = 6;
			this->input_p_Hy3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Hy3->Location = System::Drawing::Point(70, 457);
			this->input_p_Hy3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Hy3->Name = L"input_p_Hy3";
			this->input_p_Hy3->Size = System::Drawing::Size(110, 27);
			this->input_p_Hy3->TabIndex = 48;
			this->input_p_Hy3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 144589, 0, 0, 393216 });
			// 
			// input_p_Hy2
			// 
			this->input_p_Hy2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Hy2->DecimalPlaces = 8;
			this->input_p_Hy2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Hy2->Location = System::Drawing::Point(70, 424);
			this->input_p_Hy2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Hy2->Name = L"input_p_Hy2";
			this->input_p_Hy2->Size = System::Drawing::Size(110, 27);
			this->input_p_Hy2->TabIndex = 47;
			this->input_p_Hy2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 338222, 0, 0, -2146893824 });
			// 
			// input_p_Hy1
			// 
			this->input_p_Hy1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Hy1->DecimalPlaces = 6;
			this->input_p_Hy1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Hy1->Location = System::Drawing::Point(71, 391);
			this->input_p_Hy1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Hy1->Name = L"input_p_Hy1";
			this->input_p_Hy1->Size = System::Drawing::Size(110, 27);
			this->input_p_Hy1->TabIndex = 46;
			this->input_p_Hy1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1055, 0, 0, 393216 });
			// 
			// input_p_Ky3
			// 
			this->input_p_Ky3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Ky3->DecimalPlaces = 5;
			this->input_p_Ky3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Ky3->Location = System::Drawing::Point(70, 358);
			this->input_p_Ky3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Ky3->Name = L"input_p_Ky3";
			this->input_p_Ky3->Size = System::Drawing::Size(110, 27);
			this->input_p_Ky3->TabIndex = 45;
			this->input_p_Ky3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 377863, 0, 0, 327680 });
			// 
			// input_p_Ky2
			// 
			this->input_p_Ky2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Ky2->DecimalPlaces = 5;
			this->input_p_Ky2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Ky2->Location = System::Drawing::Point(70, 325);
			this->input_p_Ky2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Ky2->Name = L"input_p_Ky2";
			this->input_p_Ky2->Size = System::Drawing::Size(110, 27);
			this->input_p_Ky2->TabIndex = 44;
			this->input_p_Ky2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 214319, 0, 0, 327680 });
			// 
			// input_p_Ky1
			// 
			this->input_p_Ky1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Ky1->DecimalPlaces = 4;
			this->input_p_Ky1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Ky1->Location = System::Drawing::Point(70, 292);
			this->input_p_Ky1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Ky1->Name = L"input_p_Ky1";
			this->input_p_Ky1->Size = System::Drawing::Size(110, 27);
			this->input_p_Ky1->TabIndex = 43;
			this->input_p_Ky1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 581312, 0, 0, 262144 });
			// 
			// input_p_Ey4
			// 
			this->input_p_Ey4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Ey4->DecimalPlaces = 5;
			this->input_p_Ey4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Ey4->Location = System::Drawing::Point(71, 259);
			this->input_p_Ey4->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Ey4->Name = L"input_p_Ey4";
			this->input_p_Ey4->Size = System::Drawing::Size(110, 27);
			this->input_p_Ey4->TabIndex = 42;
			this->input_p_Ey4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 107811, 0, 0, 327680 });
			// 
			// input_p_Ey3
			// 
			this->input_p_Ey3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Ey3->DecimalPlaces = 2;
			this->input_p_Ey3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Ey3->Location = System::Drawing::Point(71, 226);
			this->input_p_Ey3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Ey3->Name = L"input_p_Ey3";
			this->input_p_Ey3->Size = System::Drawing::Size(110, 27);
			this->input_p_Ey3->TabIndex = 41;
			// 
			// input_p_Ey2
			// 
			this->input_p_Ey2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Ey2->DecimalPlaces = 6;
			this->input_p_Ey2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Ey2->Location = System::Drawing::Point(71, 193);
			this->input_p_Ey2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Ey2->Name = L"input_p_Ey2";
			this->input_p_Ey2->Size = System::Drawing::Size(110, 27);
			this->input_p_Ey2->TabIndex = 40;
			this->input_p_Ey2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 684853, 0, 0, 393216 });
			// 
			// input_p_Ey1
			// 
			this->input_p_Ey1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Ey1->DecimalPlaces = 5;
			this->input_p_Ey1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Ey1->Location = System::Drawing::Point(71, 160);
			this->input_p_Ey1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Ey1->Name = L"input_p_Ey1";
			this->input_p_Ey1->Size = System::Drawing::Size(110, 27);
			this->input_p_Ey1->TabIndex = 39;
			this->input_p_Ey1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 59049, 0, 0, -2147155968 });
			// 
			// input_p_Dy3
			// 
			this->input_p_Dy3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Dy3->DecimalPlaces = 4;
			this->input_p_Dy3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Dy3->Location = System::Drawing::Point(71, 127);
			this->input_p_Dy3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Dy3->Name = L"input_p_Dy3";
			this->input_p_Dy3->Size = System::Drawing::Size(110, 27);
			this->input_p_Dy3->TabIndex = 38;
			this->input_p_Dy3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 151193, 0, 0, 262144 });
			// 
			// input_p_Dy2
			// 
			this->input_p_Dy2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Dy2->DecimalPlaces = 7;
			this->input_p_Dy2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Dy2->Location = System::Drawing::Point(71, 94);
			this->input_p_Dy2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Dy2->Name = L"input_p_Dy2";
			this->input_p_Dy2->Size = System::Drawing::Size(110, 27);
			this->input_p_Dy2->TabIndex = 37;
			this->input_p_Dy2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 451906, 0, 0, 458752 });
			// 
			// textBox60
			// 
			this->textBox60->BackColor = System::Drawing::SystemColors::Window;
			this->textBox60->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox60->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox60->Location = System::Drawing::Point(6, 591);
			this->textBox60->Multiline = true;
			this->textBox60->Name = L"textBox60";
			this->textBox60->ReadOnly = true;
			this->textBox60->Size = System::Drawing::Size(58, 25);
			this->textBox60->TabIndex = 36;
			this->textBox60->Text = L"pVy4";
			// 
			// textBox59
			// 
			this->textBox59->BackColor = System::Drawing::SystemColors::Window;
			this->textBox59->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox59->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox59->Location = System::Drawing::Point(6, 558);
			this->textBox59->Multiline = true;
			this->textBox59->Name = L"textBox59";
			this->textBox59->ReadOnly = true;
			this->textBox59->Size = System::Drawing::Size(58, 25);
			this->textBox59->TabIndex = 34;
			this->textBox59->Text = L"pVy3";
			// 
			// textBox58
			// 
			this->textBox58->BackColor = System::Drawing::SystemColors::Window;
			this->textBox58->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox58->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox58->Location = System::Drawing::Point(6, 525);
			this->textBox58->Multiline = true;
			this->textBox58->Name = L"textBox58";
			this->textBox58->ReadOnly = true;
			this->textBox58->Size = System::Drawing::Size(58, 25);
			this->textBox58->TabIndex = 32;
			this->textBox58->Text = L"pVy2";
			// 
			// textBox57
			// 
			this->textBox57->BackColor = System::Drawing::SystemColors::Window;
			this->textBox57->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox57->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox57->Location = System::Drawing::Point(6, 492);
			this->textBox57->Multiline = true;
			this->textBox57->Name = L"textBox57";
			this->textBox57->ReadOnly = true;
			this->textBox57->Size = System::Drawing::Size(58, 25);
			this->textBox57->TabIndex = 30;
			this->textBox57->Text = L"pVy1";
			// 
			// textBox56
			// 
			this->textBox56->BackColor = System::Drawing::SystemColors::Window;
			this->textBox56->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox56->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox56->Location = System::Drawing::Point(6, 459);
			this->textBox56->Multiline = true;
			this->textBox56->Name = L"textBox56";
			this->textBox56->ReadOnly = true;
			this->textBox56->Size = System::Drawing::Size(58, 25);
			this->textBox56->TabIndex = 28;
			this->textBox56->Text = L"pHy3";
			// 
			// textBox55
			// 
			this->textBox55->BackColor = System::Drawing::SystemColors::Window;
			this->textBox55->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox55->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox55->Location = System::Drawing::Point(6, 426);
			this->textBox55->Multiline = true;
			this->textBox55->Name = L"textBox55";
			this->textBox55->ReadOnly = true;
			this->textBox55->Size = System::Drawing::Size(58, 25);
			this->textBox55->TabIndex = 26;
			this->textBox55->Text = L"pHy2";
			// 
			// textBox54
			// 
			this->textBox54->BackColor = System::Drawing::SystemColors::Window;
			this->textBox54->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox54->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox54->Location = System::Drawing::Point(6, 393);
			this->textBox54->Multiline = true;
			this->textBox54->Name = L"textBox54";
			this->textBox54->ReadOnly = true;
			this->textBox54->Size = System::Drawing::Size(58, 25);
			this->textBox54->TabIndex = 24;
			this->textBox54->Text = L"pHy1";
			// 
			// textBox53
			// 
			this->textBox53->BackColor = System::Drawing::SystemColors::Window;
			this->textBox53->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox53->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox53->Location = System::Drawing::Point(6, 360);
			this->textBox53->Multiline = true;
			this->textBox53->Name = L"textBox53";
			this->textBox53->ReadOnly = true;
			this->textBox53->Size = System::Drawing::Size(58, 25);
			this->textBox53->TabIndex = 22;
			this->textBox53->Text = L"pKy3";
			// 
			// textBox52
			// 
			this->textBox52->BackColor = System::Drawing::SystemColors::Window;
			this->textBox52->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox52->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox52->Location = System::Drawing::Point(6, 327);
			this->textBox52->Multiline = true;
			this->textBox52->Name = L"textBox52";
			this->textBox52->ReadOnly = true;
			this->textBox52->Size = System::Drawing::Size(58, 25);
			this->textBox52->TabIndex = 20;
			this->textBox52->Text = L"pKy2";
			// 
			// textBox51
			// 
			this->textBox51->BackColor = System::Drawing::SystemColors::Window;
			this->textBox51->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox51->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox51->Location = System::Drawing::Point(6, 294);
			this->textBox51->Multiline = true;
			this->textBox51->Name = L"textBox51";
			this->textBox51->ReadOnly = true;
			this->textBox51->Size = System::Drawing::Size(58, 25);
			this->textBox51->TabIndex = 18;
			this->textBox51->Text = L"pKy1";
			// 
			// textBox50
			// 
			this->textBox50->BackColor = System::Drawing::SystemColors::Window;
			this->textBox50->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox50->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox50->Location = System::Drawing::Point(6, 261);
			this->textBox50->Multiline = true;
			this->textBox50->Name = L"textBox50";
			this->textBox50->ReadOnly = true;
			this->textBox50->Size = System::Drawing::Size(58, 25);
			this->textBox50->TabIndex = 16;
			this->textBox50->Text = L"pEy4";
			// 
			// textBox49
			// 
			this->textBox49->BackColor = System::Drawing::SystemColors::Window;
			this->textBox49->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox49->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox49->Location = System::Drawing::Point(6, 228);
			this->textBox49->Multiline = true;
			this->textBox49->Name = L"textBox49";
			this->textBox49->ReadOnly = true;
			this->textBox49->Size = System::Drawing::Size(58, 25);
			this->textBox49->TabIndex = 14;
			this->textBox49->Text = L"pEy3";
			// 
			// textBox48
			// 
			this->textBox48->BackColor = System::Drawing::SystemColors::Window;
			this->textBox48->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox48->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox48->Location = System::Drawing::Point(6, 195);
			this->textBox48->Multiline = true;
			this->textBox48->Name = L"textBox48";
			this->textBox48->ReadOnly = true;
			this->textBox48->Size = System::Drawing::Size(58, 25);
			this->textBox48->TabIndex = 12;
			this->textBox48->Text = L"pEy2";
			// 
			// textBox47
			// 
			this->textBox47->BackColor = System::Drawing::SystemColors::Window;
			this->textBox47->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox47->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox47->Location = System::Drawing::Point(6, 162);
			this->textBox47->Multiline = true;
			this->textBox47->Name = L"textBox47";
			this->textBox47->ReadOnly = true;
			this->textBox47->Size = System::Drawing::Size(58, 25);
			this->textBox47->TabIndex = 10;
			this->textBox47->Text = L"pEy1";
			// 
			// textBox46
			// 
			this->textBox46->BackColor = System::Drawing::SystemColors::Window;
			this->textBox46->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox46->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox46->Location = System::Drawing::Point(6, 129);
			this->textBox46->Multiline = true;
			this->textBox46->Name = L"textBox46";
			this->textBox46->ReadOnly = true;
			this->textBox46->Size = System::Drawing::Size(58, 25);
			this->textBox46->TabIndex = 8;
			this->textBox46->Text = L"pDy3";
			// 
			// textBox45
			// 
			this->textBox45->BackColor = System::Drawing::SystemColors::Window;
			this->textBox45->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox45->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox45->Location = System::Drawing::Point(6, 96);
			this->textBox45->Multiline = true;
			this->textBox45->Name = L"textBox45";
			this->textBox45->ReadOnly = true;
			this->textBox45->Size = System::Drawing::Size(58, 25);
			this->textBox45->TabIndex = 6;
			this->textBox45->Text = L"pDy2";
			// 
			// input_p_Dy1
			// 
			this->input_p_Dy1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Dy1->DecimalPlaces = 5;
			this->input_p_Dy1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Dy1->Location = System::Drawing::Point(71, 61);
			this->input_p_Dy1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Dy1->Name = L"input_p_Dy1";
			this->input_p_Dy1->Size = System::Drawing::Size(110, 27);
			this->input_p_Dy1->TabIndex = 3;
			this->input_p_Dy1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 293292, 0, 0, -2147155968 });
			// 
			// textBox43
			// 
			this->textBox43->BackColor = System::Drawing::SystemColors::Window;
			this->textBox43->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox43->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox43->Location = System::Drawing::Point(6, 63);
			this->textBox43->Multiline = true;
			this->textBox43->Name = L"textBox43";
			this->textBox43->ReadOnly = true;
			this->textBox43->Size = System::Drawing::Size(58, 25);
			this->textBox43->TabIndex = 4;
			this->textBox43->Text = L"pDy1";
			// 
			// input_p_Cy1
			// 
			this->input_p_Cy1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_Cy1->DecimalPlaces = 5;
			this->input_p_Cy1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_Cy1->Location = System::Drawing::Point(71, 30);
			this->input_p_Cy1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->input_p_Cy1->Name = L"input_p_Cy1";
			this->input_p_Cy1->Size = System::Drawing::Size(110, 27);
			this->input_p_Cy1->TabIndex = 0;
			this->input_p_Cy1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// textBox44
			// 
			this->textBox44->BackColor = System::Drawing::SystemColors::Window;
			this->textBox44->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox44->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox44->Location = System::Drawing::Point(6, 32);
			this->textBox44->Multiline = true;
			this->textBox44->Name = L"textBox44";
			this->textBox44->ReadOnly = true;
			this->textBox44->Size = System::Drawing::Size(58, 25);
			this->textBox44->TabIndex = 2;
			this->textBox44->Text = L"pCy1";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->tabControl4);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1075, 649);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Vehicle";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabControl4
			// 
			this->tabControl4->Controls->Add(this->tabPage10);
			this->tabControl4->Controls->Add(this->tabPage13);
			this->tabControl4->Controls->Add(this->tabPage11);
			this->tabControl4->Controls->Add(this->tabPage12);
			this->tabControl4->Controls->Add(this->tabPage14);
			this->tabControl4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl4->Location = System::Drawing::Point(3, 3);
			this->tabControl4->Name = L"tabControl4";
			this->tabControl4->SelectedIndex = 0;
			this->tabControl4->Size = System::Drawing::Size(1069, 643);
			this->tabControl4->TabIndex = 24;
			// 
			// tabPage10
			// 
			this->tabPage10->Controls->Add(this->groupBox16);
			this->tabPage10->Controls->Add(this->groupBox15);
			this->tabPage10->Controls->Add(this->groupBox2);
			this->tabPage10->Controls->Add(this->groupBox1);
			this->tabPage10->Location = System::Drawing::Point(4, 35);
			this->tabPage10->Name = L"tabPage10";
			this->tabPage10->Padding = System::Windows::Forms::Padding(3);
			this->tabPage10->Size = System::Drawing::Size(1061, 604);
			this->tabPage10->TabIndex = 0;
			this->tabPage10->Text = L"Mass and Size";
			this->tabPage10->UseVisualStyleBackColor = true;
			// 
			// groupBox16
			// 
			this->groupBox16->Controls->Add(this->output_h_CG_s);
			this->groupBox16->Controls->Add(this->output_m_s);
			this->groupBox16->Controls->Add(this->textBox89);
			this->groupBox16->Controls->Add(this->textBox90);
			this->groupBox16->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox16->Location = System::Drawing::Point(253, 260);
			this->groupBox16->Name = L"groupBox16";
			this->groupBox16->Size = System::Drawing::Size(241, 137);
			this->groupBox16->TabIndex = 17;
			this->groupBox16->TabStop = false;
			this->groupBox16->Text = L"Sprung mass";
			// 
			// output_h_CG_s
			// 
			this->output_h_CG_s->AutoSize = true;
			this->output_h_CG_s->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->output_h_CG_s->Location = System::Drawing::Point(152, 91);
			this->output_h_CG_s->Name = L"output_h_CG_s";
			this->output_h_CG_s->Size = System::Drawing::Size(57, 19);
			this->output_h_CG_s->TabIndex = 20;
			this->output_h_CG_s->Text = L"label25";
			// 
			// output_m_s
			// 
			this->output_m_s->AutoSize = true;
			this->output_m_s->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->output_m_s->Location = System::Drawing::Point(152, 38);
			this->output_m_s->Name = L"output_m_s";
			this->output_m_s->Size = System::Drawing::Size(57, 19);
			this->output_m_s->TabIndex = 19;
			this->output_m_s->Text = L"label24";
			// 
			// textBox89
			// 
			this->textBox89->BackColor = System::Drawing::SystemColors::Window;
			this->textBox89->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox89->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox89->Location = System::Drawing::Point(6, 83);
			this->textBox89->Multiline = true;
			this->textBox89->Name = L"textBox89";
			this->textBox89->ReadOnly = true;
			this->textBox89->Size = System::Drawing::Size(157, 48);
			this->textBox89->TabIndex = 18;
			this->textBox89->Text = L"Sprung masses CG height";
			// 
			// textBox90
			// 
			this->textBox90->BackColor = System::Drawing::SystemColors::Window;
			this->textBox90->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox90->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox90->Location = System::Drawing::Point(2, 38);
			this->textBox90->Multiline = true;
			this->textBox90->Name = L"textBox90";
			this->textBox90->ReadOnly = true;
			this->textBox90->Size = System::Drawing::Size(157, 25);
			this->textBox90->TabIndex = 17;
			this->textBox90->Text = L"Sprung masses";
			// 
			// groupBox15
			// 
			this->groupBox15->Controls->Add(this->output_h_CG_u_rr);
			this->groupBox15->Controls->Add(this->output_h_CG_u_rl);
			this->groupBox15->Controls->Add(this->output_h_CG_u_fr);
			this->groupBox15->Controls->Add(this->output_h_CG_u_fl);
			this->groupBox15->Controls->Add(this->textBox85);
			this->groupBox15->Controls->Add(this->textBox86);
			this->groupBox15->Controls->Add(this->textBox87);
			this->groupBox15->Controls->Add(this->textBox88);
			this->groupBox15->Controls->Add(this->textBox4);
			this->groupBox15->Controls->Add(this->textBox7);
			this->groupBox15->Controls->Add(this->input_m_u_fl);
			this->groupBox15->Controls->Add(this->input_m_u_rr);
			this->groupBox15->Controls->Add(this->input_m_u_fr);
			this->groupBox15->Controls->Add(this->textBox5);
			this->groupBox15->Controls->Add(this->textBox6);
			this->groupBox15->Controls->Add(this->input_m_u_rl);
			this->groupBox15->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox15->Location = System::Drawing::Point(253, 7);
			this->groupBox15->Name = L"groupBox15";
			this->groupBox15->Size = System::Drawing::Size(497, 251);
			this->groupBox15->TabIndex = 17;
			this->groupBox15->TabStop = false;
			this->groupBox15->Text = L"Unsprung masses";
			// 
			// output_h_CG_u_rr
			// 
			this->output_h_CG_u_rr->AutoSize = true;
			this->output_h_CG_u_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->output_h_CG_u_rr->Location = System::Drawing::Point(413, 200);
			this->output_h_CG_u_rr->Name = L"output_h_CG_u_rr";
			this->output_h_CG_u_rr->Size = System::Drawing::Size(57, 19);
			this->output_h_CG_u_rr->TabIndex = 24;
			this->output_h_CG_u_rr->Text = L"label28";
			// 
			// output_h_CG_u_rl
			// 
			this->output_h_CG_u_rl->AutoSize = true;
			this->output_h_CG_u_rl->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->output_h_CG_u_rl->Location = System::Drawing::Point(413, 147);
			this->output_h_CG_u_rl->Name = L"output_h_CG_u_rl";
			this->output_h_CG_u_rl->Size = System::Drawing::Size(57, 19);
			this->output_h_CG_u_rl->TabIndex = 23;
			this->output_h_CG_u_rl->Text = L"label29";
			// 
			// output_h_CG_u_fr
			// 
			this->output_h_CG_u_fr->AutoSize = true;
			this->output_h_CG_u_fr->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->output_h_CG_u_fr->Location = System::Drawing::Point(413, 95);
			this->output_h_CG_u_fr->Name = L"output_h_CG_u_fr";
			this->output_h_CG_u_fr->Size = System::Drawing::Size(57, 19);
			this->output_h_CG_u_fr->TabIndex = 22;
			this->output_h_CG_u_fr->Text = L"label27";
			// 
			// output_h_CG_u_fl
			// 
			this->output_h_CG_u_fl->AutoSize = true;
			this->output_h_CG_u_fl->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->output_h_CG_u_fl->Location = System::Drawing::Point(413, 42);
			this->output_h_CG_u_fl->Name = L"output_h_CG_u_fl";
			this->output_h_CG_u_fl->Size = System::Drawing::Size(57, 19);
			this->output_h_CG_u_fl->TabIndex = 21;
			this->output_h_CG_u_fl->Text = L"label26";
			// 
			// textBox85
			// 
			this->textBox85->BackColor = System::Drawing::SystemColors::Window;
			this->textBox85->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox85->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox85->Location = System::Drawing::Point(264, 33);
			this->textBox85->Multiline = true;
			this->textBox85->Name = L"textBox85";
			this->textBox85->ReadOnly = true;
			this->textBox85->Size = System::Drawing::Size(157, 47);
			this->textBox85->TabIndex = 15;
			this->textBox85->Text = L"Front left unsprung mass CG height";
			// 
			// textBox86
			// 
			this->textBox86->BackColor = System::Drawing::SystemColors::Window;
			this->textBox86->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox86->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox86->Location = System::Drawing::Point(264, 188);
			this->textBox86->Multiline = true;
			this->textBox86->Name = L"textBox86";
			this->textBox86->ReadOnly = true;
			this->textBox86->Size = System::Drawing::Size(157, 38);
			this->textBox86->TabIndex = 18;
			this->textBox86->Text = L"Rear right unsprung mass CG height";
			// 
			// textBox87
			// 
			this->textBox87->BackColor = System::Drawing::SystemColors::Window;
			this->textBox87->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox87->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox87->Location = System::Drawing::Point(264, 86);
			this->textBox87->Multiline = true;
			this->textBox87->Name = L"textBox87";
			this->textBox87->ReadOnly = true;
			this->textBox87->Size = System::Drawing::Size(157, 47);
			this->textBox87->TabIndex = 16;
			this->textBox87->Text = L"Front right unsprung mass CG height";
			// 
			// textBox88
			// 
			this->textBox88->BackColor = System::Drawing::SystemColors::Window;
			this->textBox88->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox88->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox88->Location = System::Drawing::Point(264, 137);
			this->textBox88->Multiline = true;
			this->textBox88->Name = L"textBox88";
			this->textBox88->ReadOnly = true;
			this->textBox88->Size = System::Drawing::Size(157, 47);
			this->textBox88->TabIndex = 17;
			this->textBox88->Text = L"Rear left unsprung mass CG height";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Window;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(6, 33);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(157, 47);
			this->textBox4->TabIndex = 8;
			this->textBox4->Text = L"Front left unsprung masses [kg]";
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::SystemColors::Window;
			this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(6, 188);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(157, 38);
			this->textBox7->TabIndex = 14;
			this->textBox7->Text = L"Rear right unsprung masses [kg]";
			// 
			// input_m_u_fl
			// 
			this->input_m_u_fl->DecimalPlaces = 2;
			this->input_m_u_fl->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_m_u_fl->Location = System::Drawing::Point(173, 42);
			this->input_m_u_fl->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_m_u_fl->Name = L"input_m_u_fl";
			this->input_m_u_fl->Size = System::Drawing::Size(66, 27);
			this->input_m_u_fl->TabIndex = 7;
			this->input_m_u_fl->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 0 });
			// 
			// input_m_u_rr
			// 
			this->input_m_u_rr->DecimalPlaces = 2;
			this->input_m_u_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_m_u_rr->Location = System::Drawing::Point(173, 197);
			this->input_m_u_rr->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_m_u_rr->Name = L"input_m_u_rr";
			this->input_m_u_rr->Size = System::Drawing::Size(66, 27);
			this->input_m_u_rr->TabIndex = 13;
			this->input_m_u_rr->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 0 });
			// 
			// input_m_u_fr
			// 
			this->input_m_u_fr->DecimalPlaces = 2;
			this->input_m_u_fr->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_m_u_fr->Location = System::Drawing::Point(173, 95);
			this->input_m_u_fr->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_m_u_fr->Name = L"input_m_u_fr";
			this->input_m_u_fr->Size = System::Drawing::Size(66, 27);
			this->input_m_u_fr->TabIndex = 9;
			this->input_m_u_fr->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 0 });
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::Window;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(6, 86);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(157, 47);
			this->textBox5->TabIndex = 10;
			this->textBox5->Text = L"Front right unsprung masses [kg]";
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::SystemColors::Window;
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(6, 137);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(157, 47);
			this->textBox6->TabIndex = 12;
			this->textBox6->Text = L"Rear left unsprung masses [kg]";
			// 
			// input_m_u_rl
			// 
			this->input_m_u_rl->DecimalPlaces = 2;
			this->input_m_u_rl->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_m_u_rl->Location = System::Drawing::Point(173, 146);
			this->input_m_u_rl->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_m_u_rl->Name = L"input_m_u_rl";
			this->input_m_u_rl->Size = System::Drawing::Size(66, 27);
			this->input_m_u_rl->TabIndex = 11;
			this->input_m_u_rl->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 0 });
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->input_t_r);
			this->groupBox2->Controls->Add(this->input_t_f);
			this->groupBox2->Controls->Add(this->input_L);
			this->groupBox2->Controls->Add(this->textBox14);
			this->groupBox2->Controls->Add(this->textBox15);
			this->groupBox2->Controls->Add(this->textBox16);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(6, 260);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(241, 190);
			this->groupBox2->TabIndex = 17;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Size";
			// 
			// input_t_r
			// 
			this->input_t_r->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_t_r->DecimalPlaces = 2;
			this->input_t_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_t_r->Location = System::Drawing::Point(150, 141);
			this->input_t_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_t_r->Name = L"input_t_r";
			this->input_t_r->Size = System::Drawing::Size(74, 27);
			this->input_t_r->TabIndex = 5;
			this->input_t_r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1250, 0, 0, 0 });
			// 
			// input_t_f
			// 
			this->input_t_f->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_t_f->DecimalPlaces = 2;
			this->input_t_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_t_f->Location = System::Drawing::Point(150, 83);
			this->input_t_f->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_t_f->Name = L"input_t_f";
			this->input_t_f->Size = System::Drawing::Size(74, 27);
			this->input_t_f->TabIndex = 3;
			this->input_t_f->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1250, 0, 0, 0 });
			// 
			// input_L
			// 
			this->input_L->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_L->DecimalPlaces = 2;
			this->input_L->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_L->Location = System::Drawing::Point(150, 30);
			this->input_L->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_L->Name = L"input_L";
			this->input_L->Size = System::Drawing::Size(74, 27);
			this->input_L->TabIndex = 0;
			this->input_L->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1535, 0, 0, 0 });
			// 
			// textBox14
			// 
			this->textBox14->BackColor = System::Drawing::SystemColors::Window;
			this->textBox14->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox14->Location = System::Drawing::Point(6, 143);
			this->textBox14->Multiline = true;
			this->textBox14->Name = L"textBox14";
			this->textBox14->ReadOnly = true;
			this->textBox14->Size = System::Drawing::Size(157, 25);
			this->textBox14->TabIndex = 6;
			this->textBox14->Text = L"Rear track [mm]";
			// 
			// textBox15
			// 
			this->textBox15->BackColor = System::Drawing::SystemColors::Window;
			this->textBox15->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox15->Location = System::Drawing::Point(6, 85);
			this->textBox15->Multiline = true;
			this->textBox15->Name = L"textBox15";
			this->textBox15->ReadOnly = true;
			this->textBox15->Size = System::Drawing::Size(157, 25);
			this->textBox15->TabIndex = 4;
			this->textBox15->Text = L"Front track [mm]";
			// 
			// textBox16
			// 
			this->textBox16->BackColor = System::Drawing::SystemColors::Window;
			this->textBox16->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox16->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox16->Location = System::Drawing::Point(6, 32);
			this->textBox16->Multiline = true;
			this->textBox16->Name = L"textBox16";
			this->textBox16->ReadOnly = true;
			this->textBox16->Size = System::Drawing::Size(157, 25);
			this->textBox16->TabIndex = 2;
			this->textBox16->Text = L"Wheelbase [mm]";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox8);
			this->groupBox1->Controls->Add(this->input_h_CG);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->input_y);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->input_x);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->input_m);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(6, 7);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(241, 251);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Total mass";
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::SystemColors::Window;
			this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(6, 200);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(157, 47);
			this->textBox8->TabIndex = 16;
			this->textBox8->Text = L"Height of the center of gravity [mm]";
			// 
			// input_h_CG
			// 
			this->input_h_CG->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_CG->DecimalPlaces = 2;
			this->input_h_CG->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_CG->Location = System::Drawing::Point(169, 210);
			this->input_h_CG->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_CG->Name = L"input_h_CG";
			this->input_h_CG->Size = System::Drawing::Size(66, 27);
			this->input_h_CG->TabIndex = 15;
			this->input_h_CG->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 236, 0, 0, 0 });
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Window;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(6, 143);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(157, 47);
			this->textBox3->TabIndex = 6;
			this->textBox3->Text = L"Lateral mass distribution [%right]";
			// 
			// input_y
			// 
			this->input_y->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_y->DecimalPlaces = 2;
			this->input_y->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_y->Location = System::Drawing::Point(169, 153);
			this->input_y->Name = L"input_y";
			this->input_y->Size = System::Drawing::Size(66, 27);
			this->input_y->TabIndex = 5;
			this->input_y->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Window;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(6, 85);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(157, 47);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"Longitudinal mass distribution [%front]";
			// 
			// input_x
			// 
			this->input_x->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_x->DecimalPlaces = 2;
			this->input_x->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_x->Location = System::Drawing::Point(169, 95);
			this->input_x->Name = L"input_x";
			this->input_x->Size = System::Drawing::Size(66, 27);
			this->input_x->TabIndex = 3;
			this->input_x->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 48, 0, 0, 0 });
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(6, 32);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(157, 47);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Vehicle mass (with driver) [kg]";
			// 
			// input_m
			// 
			this->input_m->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_m->DecimalPlaces = 2;
			this->input_m->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_m->Location = System::Drawing::Point(169, 42);
			this->input_m->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_m->Name = L"input_m";
			this->input_m->Size = System::Drawing::Size(66, 27);
			this->input_m->TabIndex = 0;
			this->input_m->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3035, 0, 0, 65536 });
			// 
			// tabPage13
			// 
			this->tabPage13->Controls->Add(this->groupBox3);
			this->tabPage13->Controls->Add(this->groupBox4);
			this->tabPage13->Location = System::Drawing::Point(4, 22);
			this->tabPage13->Name = L"tabPage13";
			this->tabPage13->Padding = System::Windows::Forms::Padding(3);
			this->tabPage13->Size = System::Drawing::Size(1061, 617);
			this->tabPage13->TabIndex = 3;
			this->tabPage13->Text = L"Brakes and Differentials";
			this->tabPage13->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->input_brake_type_r);
			this->groupBox3->Controls->Add(this->input_brake_type_f);
			this->groupBox3->Controls->Add(this->input_brake_config);
			this->groupBox3->Controls->Add(this->textBox9);
			this->groupBox3->Controls->Add(this->textBox10);
			this->groupBox3->Controls->Add(this->textBox11);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(512, 6);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(241, 190);
			this->groupBox3->TabIndex = 18;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Brakes";
			// 
			// input_brake_type_r
			// 
			this->input_brake_type_r->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_brake_type_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_brake_type_r->FormattingEnabled = true;
			this->input_brake_type_r->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Inboard", L"Outboard" });
			this->input_brake_type_r->Location = System::Drawing::Point(114, 152);
			this->input_brake_type_r->Name = L"input_brake_type_r";
			this->input_brake_type_r->Size = System::Drawing::Size(121, 27);
			this->input_brake_type_r->TabIndex = 9;
			// 
			// input_brake_type_f
			// 
			this->input_brake_type_f->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_brake_type_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_brake_type_f->FormattingEnabled = true;
			this->input_brake_type_f->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Inboard", L"Outboard" });
			this->input_brake_type_f->Location = System::Drawing::Point(114, 94);
			this->input_brake_type_f->Name = L"input_brake_type_f";
			this->input_brake_type_f->Size = System::Drawing::Size(121, 27);
			this->input_brake_type_f->TabIndex = 8;
			// 
			// input_brake_config
			// 
			this->input_brake_config->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_brake_config->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_brake_config->FormattingEnabled = true;
			this->input_brake_config->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"All wheels", L"Front wheels", L"Rear wheels" });
			this->input_brake_config->Location = System::Drawing::Point(114, 35);
			this->input_brake_config->Name = L"input_brake_config";
			this->input_brake_config->Size = System::Drawing::Size(121, 27);
			this->input_brake_config->TabIndex = 7;
			this->input_brake_config->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::input_brake_config_SelectedIndexChanged);
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::SystemColors::Window;
			this->textBox9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(6, 143);
			this->textBox9->Multiline = true;
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(102, 44);
			this->textBox9->TabIndex = 6;
			this->textBox9->Text = L"Rear brakes mounting";
			// 
			// textBox10
			// 
			this->textBox10->BackColor = System::Drawing::SystemColors::Window;
			this->textBox10->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox10->Location = System::Drawing::Point(6, 85);
			this->textBox10->Multiline = true;
			this->textBox10->Name = L"textBox10";
			this->textBox10->ReadOnly = true;
			this->textBox10->Size = System::Drawing::Size(102, 49);
			this->textBox10->TabIndex = 4;
			this->textBox10->Text = L"Front brakes mounting";
			// 
			// textBox11
			// 
			this->textBox11->BackColor = System::Drawing::SystemColors::Window;
			this->textBox11->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox11->Location = System::Drawing::Point(6, 32);
			this->textBox11->Multiline = true;
			this->textBox11->Name = L"textBox11";
			this->textBox11->ReadOnly = true;
			this->textBox11->Size = System::Drawing::Size(102, 37);
			this->textBox11->TabIndex = 2;
			this->textBox11->Text = L"Brake configuration";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBox186);
			this->groupBox4->Controls->Add(this->textBox187);
			this->groupBox4->Controls->Add(this->textBox188);
			this->groupBox4->Controls->Add(this->textBox189);
			this->groupBox4->Controls->Add(this->textBox185);
			this->groupBox4->Controls->Add(this->textBox33);
			this->groupBox4->Controls->Add(this->textBox30);
			this->groupBox4->Controls->Add(this->textBox32);
			this->groupBox4->Controls->Add(this->input_diff_lock_r);
			this->groupBox4->Controls->Add(this->input_diff_lock_f);
			this->groupBox4->Controls->Add(this->textBox41);
			this->groupBox4->Controls->Add(this->textBox42);
			this->groupBox4->Controls->Add(this->input_diff_type_r);
			this->groupBox4->Controls->Add(this->input_diff_type_f);
			this->groupBox4->Controls->Add(this->input_drive_config);
			this->groupBox4->Controls->Add(this->textBox12);
			this->groupBox4->Controls->Add(this->textBox13);
			this->groupBox4->Controls->Add(this->textBox17);
			this->groupBox4->Controls->Add(this->input_diff_k_lock_r);
			this->groupBox4->Controls->Add(this->input_diff_preload_r);
			this->groupBox4->Controls->Add(this->input_diff_bTBR_r);
			this->groupBox4->Controls->Add(this->input_diff_dTBR_r);
			this->groupBox4->Controls->Add(this->input_diff_k_lock_f);
			this->groupBox4->Controls->Add(this->input_diff_preload_f);
			this->groupBox4->Controls->Add(this->input_diff_bTBR_f);
			this->groupBox4->Controls->Add(this->input_diff_dTBR_f);
			this->groupBox4->Controls->Add(this->fake_k_lock_r);
			this->groupBox4->Controls->Add(this->fake_preload_r);
			this->groupBox4->Controls->Add(this->fake_bTBR_r);
			this->groupBox4->Controls->Add(this->fake_dTBR_r);
			this->groupBox4->Controls->Add(this->fake_k_lock_f);
			this->groupBox4->Controls->Add(this->fake_preload_f);
			this->groupBox4->Controls->Add(this->fake_bTBR_f);
			this->groupBox4->Controls->Add(this->fake_dTBR_f);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox4->Location = System::Drawing::Point(6, 6);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(500, 423);
			this->groupBox4->TabIndex = 19;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Differentials";
			// 
			// textBox186
			// 
			this->textBox186->BackColor = System::Drawing::SystemColors::Window;
			this->textBox186->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox186->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox186->Location = System::Drawing::Point(257, 361);
			this->textBox186->Multiline = true;
			this->textBox186->Name = L"textBox186";
			this->textBox186->ReadOnly = true;
			this->textBox186->Size = System::Drawing::Size(157, 47);
			this->textBox186->TabIndex = 30;
			this->textBox186->Text = L"Rear differential stiffness [Nm/Nm]";
			// 
			// textBox187
			// 
			this->textBox187->BackColor = System::Drawing::SystemColors::Window;
			this->textBox187->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox187->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox187->Location = System::Drawing::Point(257, 310);
			this->textBox187->Multiline = true;
			this->textBox187->Name = L"textBox187";
			this->textBox187->ReadOnly = true;
			this->textBox187->Size = System::Drawing::Size(157, 47);
			this->textBox187->TabIndex = 28;
			this->textBox187->Text = L"Rear differential preload [Nm]";
			// 
			// textBox188
			// 
			this->textBox188->BackColor = System::Drawing::SystemColors::Window;
			this->textBox188->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox188->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox188->Location = System::Drawing::Point(257, 257);
			this->textBox188->Multiline = true;
			this->textBox188->Name = L"textBox188";
			this->textBox188->ReadOnly = true;
			this->textBox188->Size = System::Drawing::Size(157, 47);
			this->textBox188->TabIndex = 26;
			this->textBox188->Text = L"Rear differential braking TBR";
			// 
			// textBox189
			// 
			this->textBox189->BackColor = System::Drawing::SystemColors::Window;
			this->textBox189->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox189->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox189->Location = System::Drawing::Point(257, 206);
			this->textBox189->Multiline = true;
			this->textBox189->Name = L"textBox189";
			this->textBox189->ReadOnly = true;
			this->textBox189->Size = System::Drawing::Size(157, 47);
			this->textBox189->TabIndex = 24;
			this->textBox189->Text = L"Rear differential driving TBR";
			// 
			// textBox185
			// 
			this->textBox185->BackColor = System::Drawing::SystemColors::Window;
			this->textBox185->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox185->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox185->Location = System::Drawing::Point(6, 363);
			this->textBox185->Multiline = true;
			this->textBox185->Name = L"textBox185";
			this->textBox185->ReadOnly = true;
			this->textBox185->Size = System::Drawing::Size(157, 47);
			this->textBox185->TabIndex = 22;
			this->textBox185->Text = L"Front differential stiffness [Nm/Nm]";
			// 
			// textBox33
			// 
			this->textBox33->BackColor = System::Drawing::SystemColors::Window;
			this->textBox33->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox33->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox33->Location = System::Drawing::Point(6, 312);
			this->textBox33->Multiline = true;
			this->textBox33->Name = L"textBox33";
			this->textBox33->ReadOnly = true;
			this->textBox33->Size = System::Drawing::Size(157, 47);
			this->textBox33->TabIndex = 20;
			this->textBox33->Text = L"Front differential preload [Nm]";
			// 
			// textBox30
			// 
			this->textBox30->BackColor = System::Drawing::SystemColors::Window;
			this->textBox30->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox30->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox30->Location = System::Drawing::Point(6, 259);
			this->textBox30->Multiline = true;
			this->textBox30->Name = L"textBox30";
			this->textBox30->ReadOnly = true;
			this->textBox30->Size = System::Drawing::Size(157, 47);
			this->textBox30->TabIndex = 18;
			this->textBox30->Text = L"Front differential braking TBR";
			// 
			// textBox32
			// 
			this->textBox32->BackColor = System::Drawing::SystemColors::Window;
			this->textBox32->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox32->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox32->Location = System::Drawing::Point(6, 208);
			this->textBox32->Multiline = true;
			this->textBox32->Name = L"textBox32";
			this->textBox32->ReadOnly = true;
			this->textBox32->Size = System::Drawing::Size(157, 47);
			this->textBox32->TabIndex = 14;
			this->textBox32->Text = L"Front differential driving TBR";
			// 
			// input_diff_lock_r
			// 
			this->input_diff_lock_r->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_diff_lock_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_lock_r->FormattingEnabled = true;
			this->input_diff_lock_r->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Open", L"Geared", L"Ramp", L"Trac-loc",
					L"Locked"
			});
			this->input_diff_lock_r->Location = System::Drawing::Point(365, 159);
			this->input_diff_lock_r->Name = L"input_diff_lock_r";
			this->input_diff_lock_r->Size = System::Drawing::Size(121, 27);
			this->input_diff_lock_r->TabIndex = 13;
			this->input_diff_lock_r->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::input_diff_lock_r_SelectedIndexChanged);
			// 
			// input_diff_lock_f
			// 
			this->input_diff_lock_f->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_diff_lock_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_lock_f->FormattingEnabled = true;
			this->input_diff_lock_f->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Open", L"Geared", L"Ramp", L"Trac-loc",
					L"Locked"
			});
			this->input_diff_lock_f->Location = System::Drawing::Point(114, 162);
			this->input_diff_lock_f->Name = L"input_diff_lock_f";
			this->input_diff_lock_f->Size = System::Drawing::Size(121, 27);
			this->input_diff_lock_f->TabIndex = 12;
			this->input_diff_lock_f->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::input_diff_lock_f_SelectedIndexChanged);
			// 
			// textBox41
			// 
			this->textBox41->BackColor = System::Drawing::SystemColors::Window;
			this->textBox41->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox41->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox41->Location = System::Drawing::Point(257, 140);
			this->textBox41->Multiline = true;
			this->textBox41->Name = L"textBox41";
			this->textBox41->ReadOnly = true;
			this->textBox41->Size = System::Drawing::Size(102, 65);
			this->textBox41->TabIndex = 11;
			this->textBox41->Text = L"Rear differential locking";
			// 
			// textBox42
			// 
			this->textBox42->BackColor = System::Drawing::SystemColors::Window;
			this->textBox42->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox42->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox42->Location = System::Drawing::Point(6, 143);
			this->textBox42->Multiline = true;
			this->textBox42->Name = L"textBox42";
			this->textBox42->ReadOnly = true;
			this->textBox42->Size = System::Drawing::Size(102, 62);
			this->textBox42->TabIndex = 10;
			this->textBox42->Text = L"Front differential locking";
			// 
			// input_diff_type_r
			// 
			this->input_diff_type_r->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_diff_type_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_type_r->FormattingEnabled = true;
			this->input_diff_type_r->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Inboard", L"Outboard" });
			this->input_diff_type_r->Location = System::Drawing::Point(365, 91);
			this->input_diff_type_r->Name = L"input_diff_type_r";
			this->input_diff_type_r->Size = System::Drawing::Size(121, 27);
			this->input_diff_type_r->TabIndex = 9;
			// 
			// input_diff_type_f
			// 
			this->input_diff_type_f->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_diff_type_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_type_f->FormattingEnabled = true;
			this->input_diff_type_f->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Inboard", L"Outboard" });
			this->input_diff_type_f->Location = System::Drawing::Point(114, 94);
			this->input_diff_type_f->Name = L"input_diff_type_f";
			this->input_diff_type_f->Size = System::Drawing::Size(121, 27);
			this->input_diff_type_f->TabIndex = 8;
			// 
			// input_drive_config
			// 
			this->input_drive_config->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_drive_config->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_drive_config->FormattingEnabled = true;
			this->input_drive_config->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"All wheels", L"Front wheels", L"Rear wheels" });
			this->input_drive_config->Location = System::Drawing::Point(114, 35);
			this->input_drive_config->Name = L"input_drive_config";
			this->input_drive_config->Size = System::Drawing::Size(121, 27);
			this->input_drive_config->TabIndex = 7;
			this->input_drive_config->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::input_drive_config_SelectedIndexChanged);
			// 
			// textBox12
			// 
			this->textBox12->BackColor = System::Drawing::SystemColors::Window;
			this->textBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox12->Location = System::Drawing::Point(257, 72);
			this->textBox12->Multiline = true;
			this->textBox12->Name = L"textBox12";
			this->textBox12->ReadOnly = true;
			this->textBox12->Size = System::Drawing::Size(102, 65);
			this->textBox12->TabIndex = 6;
			this->textBox12->Text = L"Rear differential mounting";
			// 
			// textBox13
			// 
			this->textBox13->BackColor = System::Drawing::SystemColors::Window;
			this->textBox13->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox13->Location = System::Drawing::Point(6, 75);
			this->textBox13->Multiline = true;
			this->textBox13->Name = L"textBox13";
			this->textBox13->ReadOnly = true;
			this->textBox13->Size = System::Drawing::Size(102, 62);
			this->textBox13->TabIndex = 4;
			this->textBox13->Text = L"Front differential mounting";
			// 
			// textBox17
			// 
			this->textBox17->BackColor = System::Drawing::SystemColors::Window;
			this->textBox17->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox17->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox17->Location = System::Drawing::Point(6, 32);
			this->textBox17->Multiline = true;
			this->textBox17->Name = L"textBox17";
			this->textBox17->ReadOnly = true;
			this->textBox17->Size = System::Drawing::Size(102, 37);
			this->textBox17->TabIndex = 2;
			this->textBox17->Text = L"Drive configuration";
			// 
			// input_diff_k_lock_r
			// 
			this->input_diff_k_lock_r->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_diff_k_lock_r->DecimalPlaces = 2;
			this->input_diff_k_lock_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_k_lock_r->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_diff_k_lock_r->Location = System::Drawing::Point(420, 371);
			this->input_diff_k_lock_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->input_diff_k_lock_r->Name = L"input_diff_k_lock_r";
			this->input_diff_k_lock_r->Size = System::Drawing::Size(66, 27);
			this->input_diff_k_lock_r->TabIndex = 34;
			this->input_diff_k_lock_r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// input_diff_preload_r
			// 
			this->input_diff_preload_r->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_diff_preload_r->DecimalPlaces = 2;
			this->input_diff_preload_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_preload_r->Location = System::Drawing::Point(420, 320);
			this->input_diff_preload_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_diff_preload_r->Name = L"input_diff_preload_r";
			this->input_diff_preload_r->Size = System::Drawing::Size(66, 27);
			this->input_diff_preload_r->TabIndex = 33;
			this->input_diff_preload_r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// input_diff_bTBR_r
			// 
			this->input_diff_bTBR_r->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_diff_bTBR_r->DecimalPlaces = 2;
			this->input_diff_bTBR_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_bTBR_r->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_diff_bTBR_r->Location = System::Drawing::Point(420, 267);
			this->input_diff_bTBR_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_diff_bTBR_r->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->input_diff_bTBR_r->Name = L"input_diff_bTBR_r";
			this->input_diff_bTBR_r->Size = System::Drawing::Size(66, 27);
			this->input_diff_bTBR_r->TabIndex = 32;
			this->input_diff_bTBR_r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// input_diff_dTBR_r
			// 
			this->input_diff_dTBR_r->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_diff_dTBR_r->DecimalPlaces = 2;
			this->input_diff_dTBR_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_dTBR_r->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_diff_dTBR_r->Location = System::Drawing::Point(420, 216);
			this->input_diff_dTBR_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_diff_dTBR_r->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->input_diff_dTBR_r->Name = L"input_diff_dTBR_r";
			this->input_diff_dTBR_r->Size = System::Drawing::Size(66, 27);
			this->input_diff_dTBR_r->TabIndex = 31;
			this->input_diff_dTBR_r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// input_diff_k_lock_f
			// 
			this->input_diff_k_lock_f->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_diff_k_lock_f->DecimalPlaces = 2;
			this->input_diff_k_lock_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_k_lock_f->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_diff_k_lock_f->Location = System::Drawing::Point(169, 371);
			this->input_diff_k_lock_f->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->input_diff_k_lock_f->Name = L"input_diff_k_lock_f";
			this->input_diff_k_lock_f->Size = System::Drawing::Size(66, 27);
			this->input_diff_k_lock_f->TabIndex = 23;
			this->input_diff_k_lock_f->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// input_diff_preload_f
			// 
			this->input_diff_preload_f->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_diff_preload_f->DecimalPlaces = 2;
			this->input_diff_preload_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_preload_f->Location = System::Drawing::Point(169, 320);
			this->input_diff_preload_f->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_diff_preload_f->Name = L"input_diff_preload_f";
			this->input_diff_preload_f->Size = System::Drawing::Size(66, 27);
			this->input_diff_preload_f->TabIndex = 21;
			this->input_diff_preload_f->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// input_diff_bTBR_f
			// 
			this->input_diff_bTBR_f->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_diff_bTBR_f->DecimalPlaces = 2;
			this->input_diff_bTBR_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_bTBR_f->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_diff_bTBR_f->Location = System::Drawing::Point(169, 267);
			this->input_diff_bTBR_f->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_diff_bTBR_f->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->input_diff_bTBR_f->Name = L"input_diff_bTBR_f";
			this->input_diff_bTBR_f->Size = System::Drawing::Size(66, 27);
			this->input_diff_bTBR_f->TabIndex = 19;
			this->input_diff_bTBR_f->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// input_diff_dTBR_f
			// 
			this->input_diff_dTBR_f->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_diff_dTBR_f->DecimalPlaces = 2;
			this->input_diff_dTBR_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_dTBR_f->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_diff_dTBR_f->Location = System::Drawing::Point(169, 216);
			this->input_diff_dTBR_f->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_diff_dTBR_f->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->input_diff_dTBR_f->Name = L"input_diff_dTBR_f";
			this->input_diff_dTBR_f->Size = System::Drawing::Size(66, 27);
			this->input_diff_dTBR_f->TabIndex = 17;
			this->input_diff_dTBR_f->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// fake_k_lock_r
			// 
			this->fake_k_lock_r->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->fake_k_lock_r->DecimalPlaces = 2;
			this->fake_k_lock_r->Enabled = false;
			this->fake_k_lock_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fake_k_lock_r->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->fake_k_lock_r->Location = System::Drawing::Point(420, 371);
			this->fake_k_lock_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->fake_k_lock_r->Name = L"fake_k_lock_r";
			this->fake_k_lock_r->Size = System::Drawing::Size(66, 27);
			this->fake_k_lock_r->TabIndex = 42;
			this->fake_k_lock_r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// fake_preload_r
			// 
			this->fake_preload_r->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->fake_preload_r->DecimalPlaces = 2;
			this->fake_preload_r->Enabled = false;
			this->fake_preload_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fake_preload_r->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->fake_preload_r->Location = System::Drawing::Point(420, 320);
			this->fake_preload_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->fake_preload_r->Name = L"fake_preload_r";
			this->fake_preload_r->Size = System::Drawing::Size(66, 27);
			this->fake_preload_r->TabIndex = 41;
			this->fake_preload_r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// fake_bTBR_r
			// 
			this->fake_bTBR_r->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->fake_bTBR_r->DecimalPlaces = 2;
			this->fake_bTBR_r->Enabled = false;
			this->fake_bTBR_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fake_bTBR_r->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->fake_bTBR_r->Location = System::Drawing::Point(420, 267);
			this->fake_bTBR_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->fake_bTBR_r->Name = L"fake_bTBR_r";
			this->fake_bTBR_r->Size = System::Drawing::Size(66, 27);
			this->fake_bTBR_r->TabIndex = 40;
			this->fake_bTBR_r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// fake_dTBR_r
			// 
			this->fake_dTBR_r->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->fake_dTBR_r->DecimalPlaces = 2;
			this->fake_dTBR_r->Enabled = false;
			this->fake_dTBR_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fake_dTBR_r->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->fake_dTBR_r->Location = System::Drawing::Point(420, 216);
			this->fake_dTBR_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->fake_dTBR_r->Name = L"fake_dTBR_r";
			this->fake_dTBR_r->Size = System::Drawing::Size(66, 27);
			this->fake_dTBR_r->TabIndex = 39;
			this->fake_dTBR_r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// fake_k_lock_f
			// 
			this->fake_k_lock_f->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->fake_k_lock_f->DecimalPlaces = 2;
			this->fake_k_lock_f->Enabled = false;
			this->fake_k_lock_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fake_k_lock_f->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->fake_k_lock_f->Location = System::Drawing::Point(169, 371);
			this->fake_k_lock_f->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->fake_k_lock_f->Name = L"fake_k_lock_f";
			this->fake_k_lock_f->Size = System::Drawing::Size(66, 27);
			this->fake_k_lock_f->TabIndex = 38;
			this->fake_k_lock_f->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// fake_preload_f
			// 
			this->fake_preload_f->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->fake_preload_f->DecimalPlaces = 2;
			this->fake_preload_f->Enabled = false;
			this->fake_preload_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fake_preload_f->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->fake_preload_f->Location = System::Drawing::Point(169, 320);
			this->fake_preload_f->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->fake_preload_f->Name = L"fake_preload_f";
			this->fake_preload_f->Size = System::Drawing::Size(66, 27);
			this->fake_preload_f->TabIndex = 37;
			this->fake_preload_f->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// fake_bTBR_f
			// 
			this->fake_bTBR_f->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->fake_bTBR_f->DecimalPlaces = 2;
			this->fake_bTBR_f->Enabled = false;
			this->fake_bTBR_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fake_bTBR_f->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->fake_bTBR_f->Location = System::Drawing::Point(169, 267);
			this->fake_bTBR_f->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->fake_bTBR_f->Name = L"fake_bTBR_f";
			this->fake_bTBR_f->Size = System::Drawing::Size(66, 27);
			this->fake_bTBR_f->TabIndex = 36;
			this->fake_bTBR_f->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// fake_dTBR_f
			// 
			this->fake_dTBR_f->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->fake_dTBR_f->DecimalPlaces = 2;
			this->fake_dTBR_f->Enabled = false;
			this->fake_dTBR_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fake_dTBR_f->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->fake_dTBR_f->Location = System::Drawing::Point(169, 216);
			this->fake_dTBR_f->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->fake_dTBR_f->Name = L"fake_dTBR_f";
			this->fake_dTBR_f->Size = System::Drawing::Size(66, 27);
			this->fake_dTBR_f->TabIndex = 35;
			this->fake_dTBR_f->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// tabPage11
			// 
			this->tabPage11->Controls->Add(this->groupBox21);
			this->tabPage11->Location = System::Drawing::Point(4, 22);
			this->tabPage11->Name = L"tabPage11";
			this->tabPage11->Padding = System::Windows::Forms::Padding(3);
			this->tabPage11->Size = System::Drawing::Size(1061, 617);
			this->tabPage11->TabIndex = 1;
			this->tabPage11->Text = L"Aerodynamics";
			this->tabPage11->UseVisualStyleBackColor = true;
			// 
			// groupBox21
			// 
			this->groupBox21->Controls->Add(this->input_F_drag_y_0);
			this->groupBox21->Controls->Add(this->textBox162);
			this->groupBox21->Controls->Add(this->input_F_drag_y_1);
			this->groupBox21->Controls->Add(this->textBox163);
			this->groupBox21->Controls->Add(this->input_F_drag_y_2);
			this->groupBox21->Controls->Add(this->textBox164);
			this->groupBox21->Controls->Add(this->input_F_drag_z_0);
			this->groupBox21->Controls->Add(this->textBox165);
			this->groupBox21->Controls->Add(this->input_F_drag_z_1);
			this->groupBox21->Controls->Add(this->textBox166);
			this->groupBox21->Controls->Add(this->input_F_drag_z_2);
			this->groupBox21->Controls->Add(this->textBox167);
			this->groupBox21->Controls->Add(this->input_F_drag_0);
			this->groupBox21->Controls->Add(this->textBox168);
			this->groupBox21->Controls->Add(this->input_F_drag_1);
			this->groupBox21->Controls->Add(this->textBox169);
			this->groupBox21->Controls->Add(this->input_F_drag_2);
			this->groupBox21->Controls->Add(this->textBox170);
			this->groupBox21->Controls->Add(this->input_F_down_y_0);
			this->groupBox21->Controls->Add(this->textBox171);
			this->groupBox21->Controls->Add(this->input_F_down_y_1);
			this->groupBox21->Controls->Add(this->textBox172);
			this->groupBox21->Controls->Add(this->input_F_down_y_2);
			this->groupBox21->Controls->Add(this->textBox173);
			this->groupBox21->Controls->Add(this->input_F_down_x_0);
			this->groupBox21->Controls->Add(this->textBox174);
			this->groupBox21->Controls->Add(this->input_F_down_x_1);
			this->groupBox21->Controls->Add(this->textBox175);
			this->groupBox21->Controls->Add(this->input_F_down_x_2);
			this->groupBox21->Controls->Add(this->textBox176);
			this->groupBox21->Controls->Add(this->input_F_down_0);
			this->groupBox21->Controls->Add(this->textBox177);
			this->groupBox21->Controls->Add(this->input_F_down_1);
			this->groupBox21->Controls->Add(this->textBox178);
			this->groupBox21->Controls->Add(this->input_F_down_2);
			this->groupBox21->Controls->Add(this->textBox179);
			this->groupBox21->Location = System::Drawing::Point(6, 7);
			this->groupBox21->Name = L"groupBox21";
			this->groupBox21->Size = System::Drawing::Size(548, 200);
			this->groupBox21->TabIndex = 23;
			this->groupBox21->TabStop = false;
			this->groupBox21->Text = L"Aerodynamics";
			// 
			// input_F_drag_y_0
			// 
			this->input_F_drag_y_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_drag_y_0->DecimalPlaces = 4;
			this->input_F_drag_y_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_drag_y_0->Location = System::Drawing::Point(436, 246);
			this->input_F_drag_y_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_drag_y_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_drag_y_0->Name = L"input_F_drag_y_0";
			this->input_F_drag_y_0->Size = System::Drawing::Size(74, 27);
			this->input_F_drag_y_0->TabIndex = 81;
			this->input_F_drag_y_0->Visible = false;
			// 
			// textBox162
			// 
			this->textBox162->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox162->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox162->Location = System::Drawing::Point(392, 248);
			this->textBox162->Multiline = true;
			this->textBox162->Name = L"textBox162";
			this->textBox162->Size = System::Drawing::Size(49, 25);
			this->textBox162->TabIndex = 80;
			this->textBox162->Text = L"* V +";
			this->textBox162->Visible = false;
			// 
			// input_F_drag_y_1
			// 
			this->input_F_drag_y_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_drag_y_1->DecimalPlaces = 4;
			this->input_F_drag_y_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_drag_y_1->Location = System::Drawing::Point(312, 246);
			this->input_F_drag_y_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_drag_y_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_drag_y_1->Name = L"input_F_drag_y_1";
			this->input_F_drag_y_1->Size = System::Drawing::Size(74, 27);
			this->input_F_drag_y_1->TabIndex = 79;
			this->input_F_drag_y_1->Visible = false;
			// 
			// textBox163
			// 
			this->textBox163->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox163->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox163->Location = System::Drawing::Point(257, 248);
			this->textBox163->Multiline = true;
			this->textBox163->Name = L"textBox163";
			this->textBox163->Size = System::Drawing::Size(49, 25);
			this->textBox163->TabIndex = 78;
			this->textBox163->Text = L"* V² +";
			this->textBox163->Visible = false;
			// 
			// input_F_drag_y_2
			// 
			this->input_F_drag_y_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_drag_y_2->DecimalPlaces = 4;
			this->input_F_drag_y_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_drag_y_2->Location = System::Drawing::Point(177, 246);
			this->input_F_drag_y_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_drag_y_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_drag_y_2->Name = L"input_F_drag_y_2";
			this->input_F_drag_y_2->Size = System::Drawing::Size(74, 27);
			this->input_F_drag_y_2->TabIndex = 76;
			this->input_F_drag_y_2->Visible = false;
			// 
			// textBox164
			// 
			this->textBox164->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox164->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox164->Location = System::Drawing::Point(6, 235);
			this->textBox164->Multiline = true;
			this->textBox164->Name = L"textBox164";
			this->textBox164->Size = System::Drawing::Size(165, 44);
			this->textBox164->TabIndex = 77;
			this->textBox164->Text = L"Lateral drag distribution [%right]";
			this->textBox164->Visible = false;
			// 
			// input_F_drag_z_0
			// 
			this->input_F_drag_z_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_drag_z_0->DecimalPlaces = 4;
			this->input_F_drag_z_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_drag_z_0->Location = System::Drawing::Point(436, 204);
			this->input_F_drag_z_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_drag_z_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_drag_z_0->Name = L"input_F_drag_z_0";
			this->input_F_drag_z_0->Size = System::Drawing::Size(74, 27);
			this->input_F_drag_z_0->TabIndex = 75;
			this->input_F_drag_z_0->Visible = false;
			// 
			// textBox165
			// 
			this->textBox165->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox165->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox165->Location = System::Drawing::Point(392, 206);
			this->textBox165->Multiline = true;
			this->textBox165->Name = L"textBox165";
			this->textBox165->Size = System::Drawing::Size(49, 25);
			this->textBox165->TabIndex = 74;
			this->textBox165->Text = L"* V +";
			this->textBox165->Visible = false;
			// 
			// input_F_drag_z_1
			// 
			this->input_F_drag_z_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_drag_z_1->DecimalPlaces = 4;
			this->input_F_drag_z_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_drag_z_1->Location = System::Drawing::Point(312, 204);
			this->input_F_drag_z_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_drag_z_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_drag_z_1->Name = L"input_F_drag_z_1";
			this->input_F_drag_z_1->Size = System::Drawing::Size(74, 27);
			this->input_F_drag_z_1->TabIndex = 73;
			this->input_F_drag_z_1->Visible = false;
			// 
			// textBox166
			// 
			this->textBox166->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox166->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox166->Location = System::Drawing::Point(257, 206);
			this->textBox166->Multiline = true;
			this->textBox166->Name = L"textBox166";
			this->textBox166->Size = System::Drawing::Size(49, 25);
			this->textBox166->TabIndex = 72;
			this->textBox166->Text = L"* V² +";
			this->textBox166->Visible = false;
			// 
			// input_F_drag_z_2
			// 
			this->input_F_drag_z_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_drag_z_2->DecimalPlaces = 4;
			this->input_F_drag_z_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_drag_z_2->Location = System::Drawing::Point(177, 204);
			this->input_F_drag_z_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_drag_z_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_drag_z_2->Name = L"input_F_drag_z_2";
			this->input_F_drag_z_2->Size = System::Drawing::Size(74, 27);
			this->input_F_drag_z_2->TabIndex = 70;
			this->input_F_drag_z_2->Visible = false;
			// 
			// textBox167
			// 
			this->textBox167->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox167->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox167->Location = System::Drawing::Point(6, 193);
			this->textBox167->Multiline = true;
			this->textBox167->Name = L"textBox167";
			this->textBox167->Size = System::Drawing::Size(165, 44);
			this->textBox167->TabIndex = 71;
			this->textBox167->Text = L"Drag pressure center height [mm]";
			this->textBox167->Visible = false;
			// 
			// input_F_drag_0
			// 
			this->input_F_drag_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_drag_0->DecimalPlaces = 4;
			this->input_F_drag_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_drag_0->Location = System::Drawing::Point(436, 162);
			this->input_F_drag_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_drag_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_drag_0->Name = L"input_F_drag_0";
			this->input_F_drag_0->Size = System::Drawing::Size(74, 27);
			this->input_F_drag_0->TabIndex = 69;
			// 
			// textBox168
			// 
			this->textBox168->BackColor = System::Drawing::SystemColors::Window;
			this->textBox168->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox168->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox168->Location = System::Drawing::Point(392, 164);
			this->textBox168->Multiline = true;
			this->textBox168->Name = L"textBox168";
			this->textBox168->ReadOnly = true;
			this->textBox168->Size = System::Drawing::Size(49, 25);
			this->textBox168->TabIndex = 68;
			this->textBox168->Text = L"* V +";
			// 
			// input_F_drag_1
			// 
			this->input_F_drag_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_drag_1->DecimalPlaces = 4;
			this->input_F_drag_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_drag_1->Location = System::Drawing::Point(312, 162);
			this->input_F_drag_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_drag_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_drag_1->Name = L"input_F_drag_1";
			this->input_F_drag_1->Size = System::Drawing::Size(74, 27);
			this->input_F_drag_1->TabIndex = 67;
			// 
			// textBox169
			// 
			this->textBox169->BackColor = System::Drawing::SystemColors::Window;
			this->textBox169->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox169->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox169->Location = System::Drawing::Point(257, 164);
			this->textBox169->Multiline = true;
			this->textBox169->Name = L"textBox169";
			this->textBox169->ReadOnly = true;
			this->textBox169->Size = System::Drawing::Size(49, 25);
			this->textBox169->TabIndex = 66;
			this->textBox169->Text = L"* V² +";
			// 
			// input_F_drag_2
			// 
			this->input_F_drag_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_drag_2->DecimalPlaces = 4;
			this->input_F_drag_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_drag_2->Location = System::Drawing::Point(177, 162);
			this->input_F_drag_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_drag_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_drag_2->Name = L"input_F_drag_2";
			this->input_F_drag_2->Size = System::Drawing::Size(74, 27);
			this->input_F_drag_2->TabIndex = 64;
			// 
			// textBox170
			// 
			this->textBox170->BackColor = System::Drawing::SystemColors::Window;
			this->textBox170->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox170->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox170->Location = System::Drawing::Point(6, 164);
			this->textBox170->Multiline = true;
			this->textBox170->Name = L"textBox170";
			this->textBox170->ReadOnly = true;
			this->textBox170->Size = System::Drawing::Size(165, 26);
			this->textBox170->TabIndex = 65;
			this->textBox170->Text = L"Total drag [N]";
			// 
			// input_F_down_y_0
			// 
			this->input_F_down_y_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_down_y_0->DecimalPlaces = 4;
			this->input_F_down_y_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_down_y_0->Location = System::Drawing::Point(436, 121);
			this->input_F_down_y_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_down_y_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_down_y_0->Name = L"input_F_down_y_0";
			this->input_F_down_y_0->Size = System::Drawing::Size(74, 27);
			this->input_F_down_y_0->TabIndex = 63;
			// 
			// textBox171
			// 
			this->textBox171->BackColor = System::Drawing::SystemColors::Window;
			this->textBox171->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox171->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox171->Location = System::Drawing::Point(392, 123);
			this->textBox171->Multiline = true;
			this->textBox171->Name = L"textBox171";
			this->textBox171->ReadOnly = true;
			this->textBox171->Size = System::Drawing::Size(49, 25);
			this->textBox171->TabIndex = 62;
			this->textBox171->Text = L"* V +";
			// 
			// input_F_down_y_1
			// 
			this->input_F_down_y_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_down_y_1->DecimalPlaces = 4;
			this->input_F_down_y_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_down_y_1->Location = System::Drawing::Point(312, 121);
			this->input_F_down_y_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_down_y_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_down_y_1->Name = L"input_F_down_y_1";
			this->input_F_down_y_1->Size = System::Drawing::Size(74, 27);
			this->input_F_down_y_1->TabIndex = 61;
			// 
			// textBox172
			// 
			this->textBox172->BackColor = System::Drawing::SystemColors::Window;
			this->textBox172->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox172->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox172->Location = System::Drawing::Point(257, 123);
			this->textBox172->Multiline = true;
			this->textBox172->Name = L"textBox172";
			this->textBox172->ReadOnly = true;
			this->textBox172->Size = System::Drawing::Size(49, 25);
			this->textBox172->TabIndex = 60;
			this->textBox172->Text = L"* V² +";
			// 
			// input_F_down_y_2
			// 
			this->input_F_down_y_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_down_y_2->DecimalPlaces = 4;
			this->input_F_down_y_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_down_y_2->Location = System::Drawing::Point(177, 121);
			this->input_F_down_y_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_down_y_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_down_y_2->Name = L"input_F_down_y_2";
			this->input_F_down_y_2->Size = System::Drawing::Size(74, 27);
			this->input_F_down_y_2->TabIndex = 58;
			// 
			// textBox173
			// 
			this->textBox173->BackColor = System::Drawing::SystemColors::Window;
			this->textBox173->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox173->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox173->Location = System::Drawing::Point(6, 110);
			this->textBox173->Multiline = true;
			this->textBox173->Name = L"textBox173";
			this->textBox173->ReadOnly = true;
			this->textBox173->Size = System::Drawing::Size(165, 44);
			this->textBox173->TabIndex = 59;
			this->textBox173->Text = L"Lateral downforce distribution [%right]";
			// 
			// input_F_down_x_0
			// 
			this->input_F_down_x_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_down_x_0->DecimalPlaces = 4;
			this->input_F_down_x_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_down_x_0->Location = System::Drawing::Point(436, 81);
			this->input_F_down_x_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_down_x_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_down_x_0->Name = L"input_F_down_x_0";
			this->input_F_down_x_0->Size = System::Drawing::Size(74, 27);
			this->input_F_down_x_0->TabIndex = 57;
			// 
			// textBox174
			// 
			this->textBox174->BackColor = System::Drawing::SystemColors::Window;
			this->textBox174->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox174->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox174->Location = System::Drawing::Point(392, 83);
			this->textBox174->Multiline = true;
			this->textBox174->Name = L"textBox174";
			this->textBox174->ReadOnly = true;
			this->textBox174->Size = System::Drawing::Size(49, 25);
			this->textBox174->TabIndex = 56;
			this->textBox174->Text = L"* V +";
			// 
			// input_F_down_x_1
			// 
			this->input_F_down_x_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_down_x_1->DecimalPlaces = 4;
			this->input_F_down_x_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_down_x_1->Location = System::Drawing::Point(312, 81);
			this->input_F_down_x_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_down_x_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_down_x_1->Name = L"input_F_down_x_1";
			this->input_F_down_x_1->Size = System::Drawing::Size(74, 27);
			this->input_F_down_x_1->TabIndex = 55;
			// 
			// textBox175
			// 
			this->textBox175->BackColor = System::Drawing::SystemColors::Window;
			this->textBox175->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox175->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox175->Location = System::Drawing::Point(257, 83);
			this->textBox175->Multiline = true;
			this->textBox175->Name = L"textBox175";
			this->textBox175->ReadOnly = true;
			this->textBox175->Size = System::Drawing::Size(49, 25);
			this->textBox175->TabIndex = 54;
			this->textBox175->Text = L"* V² +";
			// 
			// input_F_down_x_2
			// 
			this->input_F_down_x_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_down_x_2->DecimalPlaces = 4;
			this->input_F_down_x_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_down_x_2->Location = System::Drawing::Point(177, 81);
			this->input_F_down_x_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_down_x_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_down_x_2->Name = L"input_F_down_x_2";
			this->input_F_down_x_2->Size = System::Drawing::Size(74, 27);
			this->input_F_down_x_2->TabIndex = 52;
			// 
			// textBox176
			// 
			this->textBox176->BackColor = System::Drawing::SystemColors::Window;
			this->textBox176->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox176->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox176->Location = System::Drawing::Point(6, 70);
			this->textBox176->Multiline = true;
			this->textBox176->Name = L"textBox176";
			this->textBox176->ReadOnly = true;
			this->textBox176->Size = System::Drawing::Size(165, 44);
			this->textBox176->TabIndex = 53;
			this->textBox176->Text = L"Longitudinal downforce distribution [%front]";
			// 
			// input_F_down_0
			// 
			this->input_F_down_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_down_0->DecimalPlaces = 4;
			this->input_F_down_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_down_0->Location = System::Drawing::Point(436, 43);
			this->input_F_down_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_down_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_down_0->Name = L"input_F_down_0";
			this->input_F_down_0->Size = System::Drawing::Size(74, 27);
			this->input_F_down_0->TabIndex = 51;
			// 
			// textBox177
			// 
			this->textBox177->BackColor = System::Drawing::SystemColors::Window;
			this->textBox177->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox177->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox177->Location = System::Drawing::Point(392, 45);
			this->textBox177->Multiline = true;
			this->textBox177->Name = L"textBox177";
			this->textBox177->ReadOnly = true;
			this->textBox177->Size = System::Drawing::Size(49, 25);
			this->textBox177->TabIndex = 50;
			this->textBox177->Text = L"* V +";
			// 
			// input_F_down_1
			// 
			this->input_F_down_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_down_1->DecimalPlaces = 4;
			this->input_F_down_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_down_1->Location = System::Drawing::Point(312, 43);
			this->input_F_down_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_down_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_down_1->Name = L"input_F_down_1";
			this->input_F_down_1->Size = System::Drawing::Size(74, 27);
			this->input_F_down_1->TabIndex = 49;
			// 
			// textBox178
			// 
			this->textBox178->BackColor = System::Drawing::SystemColors::Window;
			this->textBox178->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox178->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox178->Location = System::Drawing::Point(257, 45);
			this->textBox178->Multiline = true;
			this->textBox178->Name = L"textBox178";
			this->textBox178->ReadOnly = true;
			this->textBox178->Size = System::Drawing::Size(49, 25);
			this->textBox178->TabIndex = 48;
			this->textBox178->Text = L"* V² +";
			// 
			// input_F_down_2
			// 
			this->input_F_down_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_F_down_2->DecimalPlaces = 4;
			this->input_F_down_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_F_down_2->Location = System::Drawing::Point(177, 43);
			this->input_F_down_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_F_down_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_F_down_2->Name = L"input_F_down_2";
			this->input_F_down_2->Size = System::Drawing::Size(74, 27);
			this->input_F_down_2->TabIndex = 46;
			// 
			// textBox179
			// 
			this->textBox179->BackColor = System::Drawing::SystemColors::Window;
			this->textBox179->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox179->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox179->Location = System::Drawing::Point(6, 43);
			this->textBox179->Multiline = true;
			this->textBox179->Name = L"textBox179";
			this->textBox179->ReadOnly = true;
			this->textBox179->Size = System::Drawing::Size(165, 20);
			this->textBox179->TabIndex = 47;
			this->textBox179->Text = L"Total downforce [N]";
			// 
			// tabPage12
			// 
			this->tabPage12->Controls->Add(this->groupBox22);
			this->tabPage12->Controls->Add(this->groupBox10);
			this->tabPage12->Controls->Add(this->groupBox7);
			this->tabPage12->Controls->Add(this->groupBox5);
			this->tabPage12->Location = System::Drawing::Point(4, 22);
			this->tabPage12->Name = L"tabPage12";
			this->tabPage12->Padding = System::Windows::Forms::Padding(3);
			this->tabPage12->Size = System::Drawing::Size(1061, 617);
			this->tabPage12->TabIndex = 2;
			this->tabPage12->Text = L"Springs";
			this->tabPage12->UseVisualStyleBackColor = true;
			// 
			// groupBox22
			// 
			this->groupBox22->Controls->Add(this->label23);
			this->groupBox22->Controls->Add(this->label22);
			this->groupBox22->Controls->Add(this->input_front_arb_selection);
			this->groupBox22->Controls->Add(this->input_rear_arb_selection);
			this->groupBox22->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox22->Location = System::Drawing::Point(253, 263);
			this->groupBox22->Name = L"groupBox22";
			this->groupBox22->Size = System::Drawing::Size(241, 158);
			this->groupBox22->TabIndex = 57;
			this->groupBox22->TabStop = false;
			this->groupBox22->Text = L"Select ARB";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->label23->Location = System::Drawing::Point(6, 94);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(70, 19);
			this->label23->TabIndex = 58;
			this->label23->Text = L"Rear ARB";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->label22->Location = System::Drawing::Point(6, 32);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(73, 19);
			this->label22->TabIndex = 18;
			this->label22->Text = L"Front ARB";
			// 
			// input_front_arb_selection
			// 
			this->input_front_arb_selection->FormattingEnabled = true;
			this->input_front_arb_selection->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"No ARB" });
			this->input_front_arb_selection->Location = System::Drawing::Point(6, 54);
			this->input_front_arb_selection->Name = L"input_front_arb_selection";
			this->input_front_arb_selection->Size = System::Drawing::Size(229, 34);
			this->input_front_arb_selection->TabIndex = 9;
			this->input_front_arb_selection->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::input_front_arb_selection_SelectedIndexChanged);
			// 
			// input_rear_arb_selection
			// 
			this->input_rear_arb_selection->FormattingEnabled = true;
			this->input_rear_arb_selection->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"No ARB" });
			this->input_rear_arb_selection->Location = System::Drawing::Point(6, 113);
			this->input_rear_arb_selection->Name = L"input_rear_arb_selection";
			this->input_rear_arb_selection->Size = System::Drawing::Size(229, 34);
			this->input_rear_arb_selection->TabIndex = 57;
			this->input_rear_arb_selection->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::input_rear_arb_selection_SelectedIndexChanged);
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->label21);
			this->groupBox10->Controls->Add(this->label20);
			this->groupBox10->Controls->Add(this->label19);
			this->groupBox10->Controls->Add(this->label18);
			this->groupBox10->Controls->Add(this->Spring_remove);
			this->groupBox10->Controls->Add(this->spring_add);
			this->groupBox10->Controls->Add(this->spring_stiffness);
			this->groupBox10->Controls->Add(this->spring_setups);
			this->groupBox10->Controls->Add(this->spring_name);
			this->groupBox10->Controls->Add(this->spring_save);
			this->groupBox10->Controls->Add(this->spring_delete);
			this->groupBox10->Controls->Add(this->spring_new);
			this->groupBox10->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox10->Location = System::Drawing::Point(253, 6);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(241, 251);
			this->groupBox10->TabIndex = 56;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Create ARB";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->label21->Location = System::Drawing::Point(2, 32);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(76, 19);
			this->label21->TabIndex = 17;
			this->label21->Text = L"ARB name";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->label20->Location = System::Drawing::Point(171, 215);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(59, 19);
			this->label20->TabIndex = 16;
			this->label20->Text = L"[N/mm]";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->label19->Location = System::Drawing::Point(171, 183);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(59, 19);
			this->label19->TabIndex = 15;
			this->label19->Text = L"[N/mm]";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->label18->Location = System::Drawing::Point(26, 158);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(183, 19);
			this->label18->TabIndex = 14;
			this->label18->Text = L"Add setup or remove setup";
			// 
			// Spring_remove
			// 
			this->Spring_remove->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Spring_remove->Location = System::Drawing::Point(10, 215);
			this->Spring_remove->Name = L"Spring_remove";
			this->Spring_remove->Size = System::Drawing::Size(63, 27);
			this->Spring_remove->TabIndex = 13;
			this->Spring_remove->Text = L"Remove";
			this->Spring_remove->UseVisualStyleBackColor = true;
			this->Spring_remove->Click += gcnew System::EventHandler(this, &MyForm::Spring_remove_Click);
			// 
			// spring_add
			// 
			this->spring_add->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->spring_add->Location = System::Drawing::Point(10, 181);
			this->spring_add->Name = L"spring_add";
			this->spring_add->Size = System::Drawing::Size(63, 27);
			this->spring_add->TabIndex = 12;
			this->spring_add->Text = L"Add";
			this->spring_add->UseVisualStyleBackColor = true;
			this->spring_add->Click += gcnew System::EventHandler(this, &MyForm::spring_add_Click);
			// 
			// spring_stiffness
			// 
			this->spring_stiffness->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->spring_stiffness->DecimalPlaces = 2;
			this->spring_stiffness->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->spring_stiffness->Location = System::Drawing::Point(95, 180);
			this->spring_stiffness->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->spring_stiffness->Name = L"spring_stiffness";
			this->spring_stiffness->Size = System::Drawing::Size(74, 27);
			this->spring_stiffness->TabIndex = 11;
			this->spring_stiffness->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// spring_setups
			// 
			this->spring_setups->BackColor = System::Drawing::SystemColors::Window;
			this->spring_setups->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->spring_setups->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->spring_setups->FormattingEnabled = true;
			this->spring_setups->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"10", L"15", L"20", L"400" });
			this->spring_setups->Location = System::Drawing::Point(95, 213);
			this->spring_setups->Name = L"spring_setups";
			this->spring_setups->Size = System::Drawing::Size(74, 27);
			this->spring_setups->TabIndex = 9;
			// 
			// spring_name
			// 
			this->spring_name->FormattingEnabled = true;
			this->spring_name->Location = System::Drawing::Point(4, 54);
			this->spring_name->Name = L"spring_name";
			this->spring_name->Size = System::Drawing::Size(229, 34);
			this->spring_name->TabIndex = 8;
			this->spring_name->SelectionChangeCommitted += gcnew System::EventHandler(this, &MyForm::spring_name_SelectionChangeCommitted);
			// 
			// spring_save
			// 
			this->spring_save->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->spring_save->Location = System::Drawing::Point(148, 94);
			this->spring_save->Name = L"spring_save";
			this->spring_save->Size = System::Drawing::Size(42, 35);
			this->spring_save->TabIndex = 7;
			this->spring_save->Text = L"Save";
			this->spring_save->UseVisualStyleBackColor = true;
			this->spring_save->Click += gcnew System::EventHandler(this, &MyForm::spring_save_Click);
			// 
			// spring_delete
			// 
			this->spring_delete->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->spring_delete->Location = System::Drawing::Point(95, 94);
			this->spring_delete->Name = L"spring_delete";
			this->spring_delete->Size = System::Drawing::Size(47, 35);
			this->spring_delete->TabIndex = 5;
			this->spring_delete->Text = L"Delete";
			this->spring_delete->UseVisualStyleBackColor = true;
			this->spring_delete->Click += gcnew System::EventHandler(this, &MyForm::spring_delete_Click);
			// 
			// spring_new
			// 
			this->spring_new->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->spring_new->Location = System::Drawing::Point(47, 94);
			this->spring_new->Name = L"spring_new";
			this->spring_new->Size = System::Drawing::Size(42, 35);
			this->spring_new->TabIndex = 4;
			this->spring_new->Text = L"New";
			this->spring_new->UseVisualStyleBackColor = true;
			this->spring_new->Click += gcnew System::EventHandler(this, &MyForm::spring_new_Click);
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->textBox24);
			this->groupBox7->Controls->Add(this->input_k_p_C_dist);
			this->groupBox7->Controls->Add(this->input_k_p_C_deg);
			this->groupBox7->Controls->Add(this->textBox25);
			this->groupBox7->Controls->Add(this->textBox22);
			this->groupBox7->Controls->Add(this->input_k_r_C_dist);
			this->groupBox7->Controls->Add(this->input_k_r_C_deg);
			this->groupBox7->Controls->Add(this->textBox23);
			this->groupBox7->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox7->Location = System::Drawing::Point(6, 149);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(241, 282);
			this->groupBox7->TabIndex = 19;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Chassis";
			// 
			// textBox24
			// 
			this->textBox24->BackColor = System::Drawing::SystemColors::Window;
			this->textBox24->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox24->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox24->Location = System::Drawing::Point(6, 199);
			this->textBox24->Multiline = true;
			this->textBox24->Name = L"textBox24";
			this->textBox24->ReadOnly = true;
			this->textBox24->Size = System::Drawing::Size(138, 64);
			this->textBox24->TabIndex = 8;
			this->textBox24->Text = L"Chassis pitch stiffness distribution [%right]";
			// 
			// input_k_p_C_dist
			// 
			this->input_k_p_C_dist->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_k_p_C_dist->DecimalPlaces = 2;
			this->input_k_p_C_dist->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_k_p_C_dist->Location = System::Drawing::Point(150, 217);
			this->input_k_p_C_dist->Name = L"input_k_p_C_dist";
			this->input_k_p_C_dist->Size = System::Drawing::Size(74, 27);
			this->input_k_p_C_dist->TabIndex = 7;
			this->input_k_p_C_dist->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// input_k_p_C_deg
			// 
			this->input_k_p_C_deg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_k_p_C_deg->DecimalPlaces = 2;
			this->input_k_p_C_deg->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_k_p_C_deg->Location = System::Drawing::Point(150, 162);
			this->input_k_p_C_deg->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->input_k_p_C_deg->Name = L"input_k_p_C_deg";
			this->input_k_p_C_deg->Size = System::Drawing::Size(74, 27);
			this->input_k_p_C_deg->TabIndex = 5;
			this->input_k_p_C_deg->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9000, 0, 0, 0 });
			// 
			// textBox25
			// 
			this->textBox25->BackColor = System::Drawing::SystemColors::Window;
			this->textBox25->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox25->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox25->Location = System::Drawing::Point(6, 153);
			this->textBox25->Multiline = true;
			this->textBox25->Name = L"textBox25";
			this->textBox25->ReadOnly = true;
			this->textBox25->Size = System::Drawing::Size(138, 45);
			this->textBox25->TabIndex = 6;
			this->textBox25->Text = L"Chassis pitch stiffness [Nm/°]";
			// 
			// textBox22
			// 
			this->textBox22->BackColor = System::Drawing::SystemColors::Window;
			this->textBox22->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox22->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox22->Location = System::Drawing::Point(6, 83);
			this->textBox22->Multiline = true;
			this->textBox22->Name = L"textBox22";
			this->textBox22->ReadOnly = true;
			this->textBox22->Size = System::Drawing::Size(138, 64);
			this->textBox22->TabIndex = 4;
			this->textBox22->Text = L"Chassis roll stiffness distribution [%front]";
			// 
			// input_k_r_C_dist
			// 
			this->input_k_r_C_dist->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_k_r_C_dist->DecimalPlaces = 2;
			this->input_k_r_C_dist->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_k_r_C_dist->Location = System::Drawing::Point(150, 101);
			this->input_k_r_C_dist->Name = L"input_k_r_C_dist";
			this->input_k_r_C_dist->Size = System::Drawing::Size(74, 27);
			this->input_k_r_C_dist->TabIndex = 3;
			this->input_k_r_C_dist->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// input_k_r_C_deg
			// 
			this->input_k_r_C_deg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_k_r_C_deg->DecimalPlaces = 2;
			this->input_k_r_C_deg->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_k_r_C_deg->Location = System::Drawing::Point(150, 41);
			this->input_k_r_C_deg->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->input_k_r_C_deg->Name = L"input_k_r_C_deg";
			this->input_k_r_C_deg->Size = System::Drawing::Size(74, 27);
			this->input_k_r_C_deg->TabIndex = 0;
			this->input_k_r_C_deg->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1600, 0, 0, 0 });
			// 
			// textBox23
			// 
			this->textBox23->BackColor = System::Drawing::SystemColors::Window;
			this->textBox23->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox23->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox23->Location = System::Drawing::Point(6, 32);
			this->textBox23->Multiline = true;
			this->textBox23->Name = L"textBox23";
			this->textBox23->ReadOnly = true;
			this->textBox23->Size = System::Drawing::Size(138, 45);
			this->textBox23->TabIndex = 2;
			this->textBox23->Text = L"Chassis roll stiffness [Nm/°]";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->textBox18);
			this->groupBox5->Controls->Add(this->input_k_susp_r);
			this->groupBox5->Controls->Add(this->input_k_susp_f);
			this->groupBox5->Controls->Add(this->textBox20);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox5->Location = System::Drawing::Point(6, 6);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(241, 138);
			this->groupBox5->TabIndex = 18;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Springs";
			// 
			// textBox18
			// 
			this->textBox18->BackColor = System::Drawing::SystemColors::Window;
			this->textBox18->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox18->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox18->Location = System::Drawing::Point(6, 83);
			this->textBox18->Multiline = true;
			this->textBox18->Name = L"textBox18";
			this->textBox18->ReadOnly = true;
			this->textBox18->Size = System::Drawing::Size(138, 45);
			this->textBox18->TabIndex = 4;
			this->textBox18->Text = L"Rear springs stiffness [N/mm]";
			// 
			// input_k_susp_r
			// 
			this->input_k_susp_r->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_k_susp_r->DecimalPlaces = 2;
			this->input_k_susp_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_k_susp_r->Location = System::Drawing::Point(150, 92);
			this->input_k_susp_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_k_susp_r->Name = L"input_k_susp_r";
			this->input_k_susp_r->Size = System::Drawing::Size(74, 27);
			this->input_k_susp_r->TabIndex = 3;
			this->input_k_susp_r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 42710, 0, 0, 196608 });
			// 
			// input_k_susp_f
			// 
			this->input_k_susp_f->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_k_susp_f->DecimalPlaces = 2;
			this->input_k_susp_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_k_susp_f->Location = System::Drawing::Point(150, 41);
			this->input_k_susp_f->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_k_susp_f->Name = L"input_k_susp_f";
			this->input_k_susp_f->Size = System::Drawing::Size(74, 27);
			this->input_k_susp_f->TabIndex = 0;
			this->input_k_susp_f->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 42710, 0, 0, 196608 });
			// 
			// textBox20
			// 
			this->textBox20->BackColor = System::Drawing::SystemColors::Window;
			this->textBox20->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox20->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox20->Location = System::Drawing::Point(6, 32);
			this->textBox20->Multiline = true;
			this->textBox20->Name = L"textBox20";
			this->textBox20->ReadOnly = true;
			this->textBox20->Size = System::Drawing::Size(138, 45);
			this->textBox20->TabIndex = 2;
			this->textBox20->Text = L"Front springs stiffness [N/mm]";
			// 
			// tabPage14
			// 
			this->tabPage14->Controls->Add(this->groupBox20);
			this->tabPage14->Controls->Add(this->groupBox17);
			this->tabPage14->Controls->Add(this->groupBox19);
			this->tabPage14->Controls->Add(this->groupBox18);
			this->tabPage14->Controls->Add(this->groupBox6);
			this->tabPage14->Location = System::Drawing::Point(4, 22);
			this->tabPage14->Name = L"tabPage14";
			this->tabPage14->Padding = System::Windows::Forms::Padding(3);
			this->tabPage14->Size = System::Drawing::Size(1061, 617);
			this->tabPage14->TabIndex = 4;
			this->tabPage14->Text = L"Kinematics";
			this->tabPage14->UseVisualStyleBackColor = true;
			// 
			// groupBox20
			// 
			this->groupBox20->Controls->Add(this->textBox159);
			this->groupBox20->Controls->Add(this->input_bc_r_1);
			this->groupBox20->Controls->Add(this->textBox160);
			this->groupBox20->Controls->Add(this->input_bc_r_2);
			this->groupBox20->Controls->Add(this->textBox161);
			this->groupBox20->Controls->Add(this->textBox129);
			this->groupBox20->Controls->Add(this->input_bc_f_1);
			this->groupBox20->Controls->Add(this->textBox130);
			this->groupBox20->Controls->Add(this->input_bc_f_2);
			this->groupBox20->Controls->Add(this->textBox131);
			this->groupBox20->Controls->Add(this->textBox153);
			this->groupBox20->Controls->Add(this->input_sc_r_1);
			this->groupBox20->Controls->Add(this->textBox154);
			this->groupBox20->Controls->Add(this->input_sc_r_2);
			this->groupBox20->Controls->Add(this->textBox155);
			this->groupBox20->Controls->Add(this->textBox156);
			this->groupBox20->Controls->Add(this->input_sc_f_1);
			this->groupBox20->Controls->Add(this->textBox157);
			this->groupBox20->Controls->Add(this->input_sc_f_2);
			this->groupBox20->Controls->Add(this->textBox158);
			this->groupBox20->Location = System::Drawing::Point(560, 351);
			this->groupBox20->Name = L"groupBox20";
			this->groupBox20->Size = System::Drawing::Size(548, 198);
			this->groupBox20->TabIndex = 71;
			this->groupBox20->TabStop = false;
			this->groupBox20->Text = L"Camber";
			// 
			// textBox159
			// 
			this->textBox159->BackColor = System::Drawing::SystemColors::Window;
			this->textBox159->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox159->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox159->Location = System::Drawing::Point(392, 153);
			this->textBox159->Multiline = true;
			this->textBox159->Name = L"textBox159";
			this->textBox159->ReadOnly = true;
			this->textBox159->Size = System::Drawing::Size(49, 25);
			this->textBox159->TabIndex = 68;
			this->textBox159->Text = L"* w";
			// 
			// input_bc_r_1
			// 
			this->input_bc_r_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_bc_r_1->DecimalPlaces = 4;
			this->input_bc_r_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_bc_r_1->Location = System::Drawing::Point(312, 151);
			this->input_bc_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_bc_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_bc_r_1->Name = L"input_bc_r_1";
			this->input_bc_r_1->Size = System::Drawing::Size(74, 27);
			this->input_bc_r_1->TabIndex = 67;
			// 
			// textBox160
			// 
			this->textBox160->BackColor = System::Drawing::SystemColors::Window;
			this->textBox160->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox160->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox160->Location = System::Drawing::Point(257, 153);
			this->textBox160->Multiline = true;
			this->textBox160->Name = L"textBox160";
			this->textBox160->ReadOnly = true;
			this->textBox160->Size = System::Drawing::Size(49, 25);
			this->textBox160->TabIndex = 66;
			this->textBox160->Text = L"* w² +";
			// 
			// input_bc_r_2
			// 
			this->input_bc_r_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_bc_r_2->DecimalPlaces = 4;
			this->input_bc_r_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_bc_r_2->Location = System::Drawing::Point(177, 151);
			this->input_bc_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_bc_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_bc_r_2->Name = L"input_bc_r_2";
			this->input_bc_r_2->Size = System::Drawing::Size(74, 27);
			this->input_bc_r_2->TabIndex = 64;
			// 
			// textBox161
			// 
			this->textBox161->BackColor = System::Drawing::SystemColors::Window;
			this->textBox161->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox161->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox161->Location = System::Drawing::Point(6, 153);
			this->textBox161->Multiline = true;
			this->textBox161->Name = L"textBox161";
			this->textBox161->ReadOnly = true;
			this->textBox161->Size = System::Drawing::Size(165, 25);
			this->textBox161->TabIndex = 65;
			this->textBox161->Text = L"Rear bump [°]";
			// 
			// textBox129
			// 
			this->textBox129->BackColor = System::Drawing::SystemColors::Window;
			this->textBox129->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox129->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox129->Location = System::Drawing::Point(392, 110);
			this->textBox129->Multiline = true;
			this->textBox129->Name = L"textBox129";
			this->textBox129->ReadOnly = true;
			this->textBox129->Size = System::Drawing::Size(49, 25);
			this->textBox129->TabIndex = 62;
			this->textBox129->Text = L"* w";
			// 
			// input_bc_f_1
			// 
			this->input_bc_f_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_bc_f_1->DecimalPlaces = 4;
			this->input_bc_f_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_bc_f_1->Location = System::Drawing::Point(312, 108);
			this->input_bc_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_bc_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_bc_f_1->Name = L"input_bc_f_1";
			this->input_bc_f_1->Size = System::Drawing::Size(74, 27);
			this->input_bc_f_1->TabIndex = 61;
			// 
			// textBox130
			// 
			this->textBox130->BackColor = System::Drawing::SystemColors::Window;
			this->textBox130->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox130->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox130->Location = System::Drawing::Point(257, 110);
			this->textBox130->Multiline = true;
			this->textBox130->Name = L"textBox130";
			this->textBox130->ReadOnly = true;
			this->textBox130->Size = System::Drawing::Size(49, 25);
			this->textBox130->TabIndex = 60;
			this->textBox130->Text = L"* w² +";
			// 
			// input_bc_f_2
			// 
			this->input_bc_f_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_bc_f_2->DecimalPlaces = 4;
			this->input_bc_f_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_bc_f_2->Location = System::Drawing::Point(177, 108);
			this->input_bc_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_bc_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_bc_f_2->Name = L"input_bc_f_2";
			this->input_bc_f_2->Size = System::Drawing::Size(74, 27);
			this->input_bc_f_2->TabIndex = 58;
			// 
			// textBox131
			// 
			this->textBox131->BackColor = System::Drawing::SystemColors::Window;
			this->textBox131->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox131->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox131->Location = System::Drawing::Point(6, 110);
			this->textBox131->Multiline = true;
			this->textBox131->Name = L"textBox131";
			this->textBox131->ReadOnly = true;
			this->textBox131->Size = System::Drawing::Size(165, 25);
			this->textBox131->TabIndex = 59;
			this->textBox131->Text = L"Front bump [°]";
			// 
			// textBox153
			// 
			this->textBox153->BackColor = System::Drawing::SystemColors::Window;
			this->textBox153->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox153->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox153->Location = System::Drawing::Point(392, 70);
			this->textBox153->Multiline = true;
			this->textBox153->Name = L"textBox153";
			this->textBox153->ReadOnly = true;
			this->textBox153->Size = System::Drawing::Size(49, 25);
			this->textBox153->TabIndex = 56;
			this->textBox153->Text = L"* δ";
			// 
			// input_sc_r_1
			// 
			this->input_sc_r_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_sc_r_1->DecimalPlaces = 4;
			this->input_sc_r_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_sc_r_1->Location = System::Drawing::Point(312, 68);
			this->input_sc_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_sc_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_sc_r_1->Name = L"input_sc_r_1";
			this->input_sc_r_1->Size = System::Drawing::Size(74, 27);
			this->input_sc_r_1->TabIndex = 55;
			// 
			// textBox154
			// 
			this->textBox154->BackColor = System::Drawing::SystemColors::Window;
			this->textBox154->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox154->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox154->Location = System::Drawing::Point(257, 70);
			this->textBox154->Multiline = true;
			this->textBox154->Name = L"textBox154";
			this->textBox154->ReadOnly = true;
			this->textBox154->Size = System::Drawing::Size(49, 25);
			this->textBox154->TabIndex = 54;
			this->textBox154->Text = L"* δ² +";
			// 
			// input_sc_r_2
			// 
			this->input_sc_r_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_sc_r_2->DecimalPlaces = 4;
			this->input_sc_r_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_sc_r_2->Location = System::Drawing::Point(177, 68);
			this->input_sc_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_sc_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_sc_r_2->Name = L"input_sc_r_2";
			this->input_sc_r_2->Size = System::Drawing::Size(74, 27);
			this->input_sc_r_2->TabIndex = 52;
			// 
			// textBox155
			// 
			this->textBox155->BackColor = System::Drawing::SystemColors::Window;
			this->textBox155->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox155->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox155->Location = System::Drawing::Point(6, 70);
			this->textBox155->Multiline = true;
			this->textBox155->Name = L"textBox155";
			this->textBox155->ReadOnly = true;
			this->textBox155->Size = System::Drawing::Size(165, 23);
			this->textBox155->TabIndex = 53;
			this->textBox155->Text = L"Rear steering [°]";
			// 
			// textBox156
			// 
			this->textBox156->BackColor = System::Drawing::SystemColors::Window;
			this->textBox156->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox156->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox156->Location = System::Drawing::Point(392, 32);
			this->textBox156->Multiline = true;
			this->textBox156->Name = L"textBox156";
			this->textBox156->ReadOnly = true;
			this->textBox156->Size = System::Drawing::Size(49, 25);
			this->textBox156->TabIndex = 50;
			this->textBox156->Text = L"* δ";
			// 
			// input_sc_f_1
			// 
			this->input_sc_f_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_sc_f_1->DecimalPlaces = 4;
			this->input_sc_f_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_sc_f_1->Location = System::Drawing::Point(312, 30);
			this->input_sc_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_sc_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_sc_f_1->Name = L"input_sc_f_1";
			this->input_sc_f_1->Size = System::Drawing::Size(74, 27);
			this->input_sc_f_1->TabIndex = 49;
			// 
			// textBox157
			// 
			this->textBox157->BackColor = System::Drawing::SystemColors::Window;
			this->textBox157->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox157->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox157->Location = System::Drawing::Point(257, 32);
			this->textBox157->Multiline = true;
			this->textBox157->Name = L"textBox157";
			this->textBox157->ReadOnly = true;
			this->textBox157->Size = System::Drawing::Size(49, 25);
			this->textBox157->TabIndex = 48;
			this->textBox157->Text = L"* δ² +";
			// 
			// input_sc_f_2
			// 
			this->input_sc_f_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_sc_f_2->DecimalPlaces = 4;
			this->input_sc_f_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_sc_f_2->Location = System::Drawing::Point(177, 30);
			this->input_sc_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_sc_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_sc_f_2->Name = L"input_sc_f_2";
			this->input_sc_f_2->Size = System::Drawing::Size(74, 27);
			this->input_sc_f_2->TabIndex = 46;
			// 
			// textBox158
			// 
			this->textBox158->BackColor = System::Drawing::SystemColors::Window;
			this->textBox158->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox158->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox158->Location = System::Drawing::Point(6, 32);
			this->textBox158->Multiline = true;
			this->textBox158->Name = L"textBox158";
			this->textBox158->ReadOnly = true;
			this->textBox158->Size = System::Drawing::Size(165, 32);
			this->textBox158->TabIndex = 47;
			this->textBox158->Text = L"Front steering [°]";
			// 
			// groupBox17
			// 
			this->groupBox17->Controls->Add(this->input_q_p_r_0);
			this->groupBox17->Controls->Add(this->textBox108);
			this->groupBox17->Controls->Add(this->input_q_p_r_1);
			this->groupBox17->Controls->Add(this->textBox109);
			this->groupBox17->Controls->Add(this->input_q_p_r_2);
			this->groupBox17->Controls->Add(this->textBox110);
			this->groupBox17->Controls->Add(this->input_q_p_f_0);
			this->groupBox17->Controls->Add(this->textBox114);
			this->groupBox17->Controls->Add(this->input_q_p_f_1);
			this->groupBox17->Controls->Add(this->textBox115);
			this->groupBox17->Controls->Add(this->input_q_p_f_2);
			this->groupBox17->Controls->Add(this->textBox116);
			this->groupBox17->Controls->Add(this->input_n_p_o_0);
			this->groupBox17->Controls->Add(this->textBox117);
			this->groupBox17->Controls->Add(this->input_n_p_o_1);
			this->groupBox17->Controls->Add(this->textBox118);
			this->groupBox17->Controls->Add(this->input_n_p_o_2);
			this->groupBox17->Controls->Add(this->textBox119);
			this->groupBox17->Controls->Add(this->input_n_p_i_0);
			this->groupBox17->Controls->Add(this->textBox120);
			this->groupBox17->Controls->Add(this->input_n_p_i_1);
			this->groupBox17->Controls->Add(this->textBox121);
			this->groupBox17->Controls->Add(this->input_n_p_i_2);
			this->groupBox17->Controls->Add(this->textBox122);
			this->groupBox17->Controls->Add(this->input_h_p_o_0);
			this->groupBox17->Controls->Add(this->textBox123);
			this->groupBox17->Controls->Add(this->input_h_p_o_1);
			this->groupBox17->Controls->Add(this->textBox124);
			this->groupBox17->Controls->Add(this->input_h_p_o_2);
			this->groupBox17->Controls->Add(this->textBox125);
			this->groupBox17->Controls->Add(this->input_h_p_i_0);
			this->groupBox17->Controls->Add(this->textBox126);
			this->groupBox17->Controls->Add(this->input_h_p_i_1);
			this->groupBox17->Controls->Add(this->textBox127);
			this->groupBox17->Controls->Add(this->input_h_p_i_2);
			this->groupBox17->Controls->Add(this->textBox128);
			this->groupBox17->Location = System::Drawing::Point(6, 297);
			this->groupBox17->Name = L"groupBox17";
			this->groupBox17->Size = System::Drawing::Size(548, 288);
			this->groupBox17->TabIndex = 82;
			this->groupBox17->TabStop = false;
			this->groupBox17->Text = L"Pitch kinematics";
			// 
			// input_q_p_r_0
			// 
			this->input_q_p_r_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_p_r_0->DecimalPlaces = 4;
			this->input_q_p_r_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_p_r_0->Location = System::Drawing::Point(468, 255);
			this->input_q_p_r_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_p_r_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_p_r_0->Name = L"input_q_p_r_0";
			this->input_q_p_r_0->Size = System::Drawing::Size(74, 27);
			this->input_q_p_r_0->TabIndex = 81;
			// 
			// textBox108
			// 
			this->textBox108->BackColor = System::Drawing::SystemColors::Window;
			this->textBox108->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox108->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox108->Location = System::Drawing::Point(424, 257);
			this->textBox108->Multiline = true;
			this->textBox108->Name = L"textBox108";
			this->textBox108->ReadOnly = true;
			this->textBox108->Size = System::Drawing::Size(49, 25);
			this->textBox108->TabIndex = 80;
			this->textBox108->Text = L"* φ +";
			// 
			// input_q_p_r_1
			// 
			this->input_q_p_r_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_p_r_1->DecimalPlaces = 4;
			this->input_q_p_r_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_p_r_1->Location = System::Drawing::Point(344, 255);
			this->input_q_p_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_p_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_p_r_1->Name = L"input_q_p_r_1";
			this->input_q_p_r_1->Size = System::Drawing::Size(74, 27);
			this->input_q_p_r_1->TabIndex = 79;
			// 
			// textBox109
			// 
			this->textBox109->BackColor = System::Drawing::SystemColors::Window;
			this->textBox109->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox109->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox109->Location = System::Drawing::Point(289, 257);
			this->textBox109->Multiline = true;
			this->textBox109->Name = L"textBox109";
			this->textBox109->ReadOnly = true;
			this->textBox109->Size = System::Drawing::Size(49, 25);
			this->textBox109->TabIndex = 78;
			this->textBox109->Text = L"* φ² +";
			// 
			// input_q_p_r_2
			// 
			this->input_q_p_r_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_p_r_2->DecimalPlaces = 4;
			this->input_q_p_r_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_p_r_2->Location = System::Drawing::Point(209, 255);
			this->input_q_p_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_p_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_p_r_2->Name = L"input_q_p_r_2";
			this->input_q_p_r_2->Size = System::Drawing::Size(74, 27);
			this->input_q_p_r_2->TabIndex = 76;
			// 
			// textBox110
			// 
			this->textBox110->BackColor = System::Drawing::SystemColors::Window;
			this->textBox110->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox110->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox110->Location = System::Drawing::Point(6, 246);
			this->textBox110->Multiline = true;
			this->textBox110->Name = L"textBox110";
			this->textBox110->ReadOnly = true;
			this->textBox110->Size = System::Drawing::Size(197, 44);
			this->textBox110->TabIndex = 77;
			this->textBox110->Text = L"Rear pitch instant center longitudinal position [mm]";
			// 
			// input_q_p_f_0
			// 
			this->input_q_p_f_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_p_f_0->DecimalPlaces = 4;
			this->input_q_p_f_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_p_f_0->Location = System::Drawing::Point(468, 214);
			this->input_q_p_f_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_p_f_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_p_f_0->Name = L"input_q_p_f_0";
			this->input_q_p_f_0->Size = System::Drawing::Size(74, 27);
			this->input_q_p_f_0->TabIndex = 75;
			// 
			// textBox114
			// 
			this->textBox114->BackColor = System::Drawing::SystemColors::Window;
			this->textBox114->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox114->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox114->Location = System::Drawing::Point(424, 216);
			this->textBox114->Multiline = true;
			this->textBox114->Name = L"textBox114";
			this->textBox114->ReadOnly = true;
			this->textBox114->Size = System::Drawing::Size(49, 25);
			this->textBox114->TabIndex = 74;
			this->textBox114->Text = L"* φ +";
			// 
			// input_q_p_f_1
			// 
			this->input_q_p_f_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_p_f_1->DecimalPlaces = 4;
			this->input_q_p_f_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_p_f_1->Location = System::Drawing::Point(344, 214);
			this->input_q_p_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_p_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_p_f_1->Name = L"input_q_p_f_1";
			this->input_q_p_f_1->Size = System::Drawing::Size(74, 27);
			this->input_q_p_f_1->TabIndex = 73;
			// 
			// textBox115
			// 
			this->textBox115->BackColor = System::Drawing::SystemColors::Window;
			this->textBox115->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox115->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox115->Location = System::Drawing::Point(289, 216);
			this->textBox115->Multiline = true;
			this->textBox115->Name = L"textBox115";
			this->textBox115->ReadOnly = true;
			this->textBox115->Size = System::Drawing::Size(49, 25);
			this->textBox115->TabIndex = 72;
			this->textBox115->Text = L"* φ² +";
			// 
			// input_q_p_f_2
			// 
			this->input_q_p_f_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_p_f_2->DecimalPlaces = 4;
			this->input_q_p_f_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_p_f_2->Location = System::Drawing::Point(209, 214);
			this->input_q_p_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_p_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_p_f_2->Name = L"input_q_p_f_2";
			this->input_q_p_f_2->Size = System::Drawing::Size(74, 27);
			this->input_q_p_f_2->TabIndex = 70;
			// 
			// textBox116
			// 
			this->textBox116->BackColor = System::Drawing::SystemColors::Window;
			this->textBox116->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox116->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox116->Location = System::Drawing::Point(6, 205);
			this->textBox116->Multiline = true;
			this->textBox116->Name = L"textBox116";
			this->textBox116->ReadOnly = true;
			this->textBox116->Size = System::Drawing::Size(185, 61);
			this->textBox116->TabIndex = 71;
			this->textBox116->Text = L"Front pitch instant center longitudinal position [mm]";
			// 
			// input_n_p_o_0
			// 
			this->input_n_p_o_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_n_p_o_0->DecimalPlaces = 4;
			this->input_n_p_o_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_n_p_o_0->Location = System::Drawing::Point(468, 171);
			this->input_n_p_o_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_o_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_o_0->Name = L"input_n_p_o_0";
			this->input_n_p_o_0->Size = System::Drawing::Size(74, 27);
			this->input_n_p_o_0->TabIndex = 69;
			// 
			// textBox117
			// 
			this->textBox117->BackColor = System::Drawing::SystemColors::Window;
			this->textBox117->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox117->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox117->Location = System::Drawing::Point(424, 173);
			this->textBox117->Multiline = true;
			this->textBox117->Name = L"textBox117";
			this->textBox117->ReadOnly = true;
			this->textBox117->Size = System::Drawing::Size(49, 25);
			this->textBox117->TabIndex = 68;
			this->textBox117->Text = L"* φ +";
			// 
			// input_n_p_o_1
			// 
			this->input_n_p_o_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_n_p_o_1->DecimalPlaces = 4;
			this->input_n_p_o_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_n_p_o_1->Location = System::Drawing::Point(344, 171);
			this->input_n_p_o_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_o_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_o_1->Name = L"input_n_p_o_1";
			this->input_n_p_o_1->Size = System::Drawing::Size(74, 27);
			this->input_n_p_o_1->TabIndex = 67;
			// 
			// textBox118
			// 
			this->textBox118->BackColor = System::Drawing::SystemColors::Window;
			this->textBox118->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox118->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox118->Location = System::Drawing::Point(289, 173);
			this->textBox118->Multiline = true;
			this->textBox118->Name = L"textBox118";
			this->textBox118->ReadOnly = true;
			this->textBox118->Size = System::Drawing::Size(49, 25);
			this->textBox118->TabIndex = 66;
			this->textBox118->Text = L"* φ² +";
			// 
			// input_n_p_o_2
			// 
			this->input_n_p_o_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_n_p_o_2->DecimalPlaces = 4;
			this->input_n_p_o_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_n_p_o_2->Location = System::Drawing::Point(209, 171);
			this->input_n_p_o_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_o_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_o_2->Name = L"input_n_p_o_2";
			this->input_n_p_o_2->Size = System::Drawing::Size(74, 27);
			this->input_n_p_o_2->TabIndex = 64;
			// 
			// textBox119
			// 
			this->textBox119->BackColor = System::Drawing::SystemColors::Window;
			this->textBox119->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox119->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox119->Location = System::Drawing::Point(6, 162);
			this->textBox119->Multiline = true;
			this->textBox119->Name = L"textBox119";
			this->textBox119->ReadOnly = true;
			this->textBox119->Size = System::Drawing::Size(197, 44);
			this->textBox119->TabIndex = 65;
			this->textBox119->Text = L"Right pitch center longitudianl offset [mm]";
			// 
			// input_n_p_i_0
			// 
			this->input_n_p_i_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_n_p_i_0->DecimalPlaces = 4;
			this->input_n_p_i_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_n_p_i_0->Location = System::Drawing::Point(468, 83);
			this->input_n_p_i_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_i_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_i_0->Name = L"input_n_p_i_0";
			this->input_n_p_i_0->Size = System::Drawing::Size(74, 27);
			this->input_n_p_i_0->TabIndex = 63;
			// 
			// textBox120
			// 
			this->textBox120->BackColor = System::Drawing::SystemColors::Window;
			this->textBox120->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox120->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox120->Location = System::Drawing::Point(424, 85);
			this->textBox120->Multiline = true;
			this->textBox120->Name = L"textBox120";
			this->textBox120->ReadOnly = true;
			this->textBox120->Size = System::Drawing::Size(49, 25);
			this->textBox120->TabIndex = 62;
			this->textBox120->Text = L"* φ +";
			// 
			// input_n_p_i_1
			// 
			this->input_n_p_i_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_n_p_i_1->DecimalPlaces = 4;
			this->input_n_p_i_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_n_p_i_1->Location = System::Drawing::Point(344, 83);
			this->input_n_p_i_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_i_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_i_1->Name = L"input_n_p_i_1";
			this->input_n_p_i_1->Size = System::Drawing::Size(74, 27);
			this->input_n_p_i_1->TabIndex = 61;
			// 
			// textBox121
			// 
			this->textBox121->BackColor = System::Drawing::SystemColors::Window;
			this->textBox121->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox121->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox121->Location = System::Drawing::Point(289, 85);
			this->textBox121->Multiline = true;
			this->textBox121->Name = L"textBox121";
			this->textBox121->ReadOnly = true;
			this->textBox121->Size = System::Drawing::Size(49, 25);
			this->textBox121->TabIndex = 60;
			this->textBox121->Text = L"* φ² +";
			// 
			// input_n_p_i_2
			// 
			this->input_n_p_i_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_n_p_i_2->DecimalPlaces = 4;
			this->input_n_p_i_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_n_p_i_2->Location = System::Drawing::Point(209, 83);
			this->input_n_p_i_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_i_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_i_2->Name = L"input_n_p_i_2";
			this->input_n_p_i_2->Size = System::Drawing::Size(74, 27);
			this->input_n_p_i_2->TabIndex = 58;
			// 
			// textBox122
			// 
			this->textBox122->BackColor = System::Drawing::SystemColors::Window;
			this->textBox122->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox122->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox122->Location = System::Drawing::Point(6, 74);
			this->textBox122->Multiline = true;
			this->textBox122->Name = L"textBox122";
			this->textBox122->ReadOnly = true;
			this->textBox122->Size = System::Drawing::Size(197, 44);
			this->textBox122->TabIndex = 59;
			this->textBox122->Text = L"Left pitch center longitudinal offset [mm]";
			// 
			// input_h_p_o_0
			// 
			this->input_h_p_o_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_p_o_0->DecimalPlaces = 4;
			this->input_h_p_o_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_p_o_0->Location = System::Drawing::Point(468, 127);
			this->input_h_p_o_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_o_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_o_0->Name = L"input_h_p_o_0";
			this->input_h_p_o_0->Size = System::Drawing::Size(74, 27);
			this->input_h_p_o_0->TabIndex = 57;
			// 
			// textBox123
			// 
			this->textBox123->BackColor = System::Drawing::SystemColors::Window;
			this->textBox123->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox123->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox123->Location = System::Drawing::Point(424, 129);
			this->textBox123->Multiline = true;
			this->textBox123->Name = L"textBox123";
			this->textBox123->ReadOnly = true;
			this->textBox123->Size = System::Drawing::Size(49, 25);
			this->textBox123->TabIndex = 56;
			this->textBox123->Text = L"* φ +";
			// 
			// input_h_p_o_1
			// 
			this->input_h_p_o_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_p_o_1->DecimalPlaces = 4;
			this->input_h_p_o_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_p_o_1->Location = System::Drawing::Point(344, 127);
			this->input_h_p_o_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_o_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_o_1->Name = L"input_h_p_o_1";
			this->input_h_p_o_1->Size = System::Drawing::Size(74, 27);
			this->input_h_p_o_1->TabIndex = 55;
			// 
			// textBox124
			// 
			this->textBox124->BackColor = System::Drawing::SystemColors::Window;
			this->textBox124->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox124->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox124->Location = System::Drawing::Point(289, 129);
			this->textBox124->Multiline = true;
			this->textBox124->Name = L"textBox124";
			this->textBox124->ReadOnly = true;
			this->textBox124->Size = System::Drawing::Size(49, 25);
			this->textBox124->TabIndex = 54;
			this->textBox124->Text = L"* φ² +";
			// 
			// input_h_p_o_2
			// 
			this->input_h_p_o_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_p_o_2->DecimalPlaces = 4;
			this->input_h_p_o_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_p_o_2->Location = System::Drawing::Point(209, 127);
			this->input_h_p_o_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_o_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_o_2->Name = L"input_h_p_o_2";
			this->input_h_p_o_2->Size = System::Drawing::Size(74, 27);
			this->input_h_p_o_2->TabIndex = 52;
			// 
			// textBox125
			// 
			this->textBox125->BackColor = System::Drawing::SystemColors::Window;
			this->textBox125->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox125->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox125->Location = System::Drawing::Point(6, 118);
			this->textBox125->Multiline = true;
			this->textBox125->Name = L"textBox125";
			this->textBox125->ReadOnly = true;
			this->textBox125->Size = System::Drawing::Size(197, 44);
			this->textBox125->TabIndex = 53;
			this->textBox125->Text = L"Right pitch center height [mm]";
			// 
			// input_h_p_i_0
			// 
			this->input_h_p_i_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_p_i_0->DecimalPlaces = 4;
			this->input_h_p_i_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_p_i_0->Location = System::Drawing::Point(468, 41);
			this->input_h_p_i_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_i_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_i_0->Name = L"input_h_p_i_0";
			this->input_h_p_i_0->Size = System::Drawing::Size(74, 27);
			this->input_h_p_i_0->TabIndex = 51;
			// 
			// textBox126
			// 
			this->textBox126->BackColor = System::Drawing::SystemColors::Window;
			this->textBox126->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox126->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox126->Location = System::Drawing::Point(424, 43);
			this->textBox126->Multiline = true;
			this->textBox126->Name = L"textBox126";
			this->textBox126->ReadOnly = true;
			this->textBox126->Size = System::Drawing::Size(49, 25);
			this->textBox126->TabIndex = 50;
			this->textBox126->Text = L"* φ +";
			// 
			// input_h_p_i_1
			// 
			this->input_h_p_i_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_p_i_1->DecimalPlaces = 4;
			this->input_h_p_i_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_p_i_1->Location = System::Drawing::Point(344, 41);
			this->input_h_p_i_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_i_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_i_1->Name = L"input_h_p_i_1";
			this->input_h_p_i_1->Size = System::Drawing::Size(74, 27);
			this->input_h_p_i_1->TabIndex = 49;
			// 
			// textBox127
			// 
			this->textBox127->BackColor = System::Drawing::SystemColors::Window;
			this->textBox127->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox127->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox127->Location = System::Drawing::Point(289, 43);
			this->textBox127->Multiline = true;
			this->textBox127->Name = L"textBox127";
			this->textBox127->ReadOnly = true;
			this->textBox127->Size = System::Drawing::Size(49, 25);
			this->textBox127->TabIndex = 48;
			this->textBox127->Text = L"* φ² +";
			// 
			// input_h_p_i_2
			// 
			this->input_h_p_i_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_p_i_2->DecimalPlaces = 4;
			this->input_h_p_i_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_p_i_2->Location = System::Drawing::Point(209, 41);
			this->input_h_p_i_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_i_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_i_2->Name = L"input_h_p_i_2";
			this->input_h_p_i_2->Size = System::Drawing::Size(74, 27);
			this->input_h_p_i_2->TabIndex = 46;
			// 
			// textBox128
			// 
			this->textBox128->BackColor = System::Drawing::SystemColors::Window;
			this->textBox128->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox128->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox128->Location = System::Drawing::Point(6, 44);
			this->textBox128->Multiline = true;
			this->textBox128->Name = L"textBox128";
			this->textBox128->ReadOnly = true;
			this->textBox128->Size = System::Drawing::Size(197, 24);
			this->textBox128->TabIndex = 47;
			this->textBox128->Text = L"Left pitch center height [mm]";
			// 
			// groupBox19
			// 
			this->groupBox19->Controls->Add(this->textBox132);
			this->groupBox19->Controls->Add(this->input_bs_r_1);
			this->groupBox19->Controls->Add(this->textBox133);
			this->groupBox19->Controls->Add(this->input_bs_r_2);
			this->groupBox19->Controls->Add(this->textBox134);
			this->groupBox19->Controls->Add(this->textBox147);
			this->groupBox19->Controls->Add(this->input_bs_f_1);
			this->groupBox19->Controls->Add(this->textBox148);
			this->groupBox19->Controls->Add(this->input_bs_f_2);
			this->groupBox19->Controls->Add(this->textBox149);
			this->groupBox19->Controls->Add(this->textBox150);
			this->groupBox19->Controls->Add(this->input_ackermann_1);
			this->groupBox19->Controls->Add(this->textBox151);
			this->groupBox19->Controls->Add(this->input_ackermann_2);
			this->groupBox19->Controls->Add(this->textBox152);
			this->groupBox19->Location = System::Drawing::Point(560, 201);
			this->groupBox19->Name = L"groupBox19";
			this->groupBox19->Size = System::Drawing::Size(548, 144);
			this->groupBox19->TabIndex = 70;
			this->groupBox19->TabStop = false;
			this->groupBox19->Text = L"Steering";
			// 
			// textBox132
			// 
			this->textBox132->BackColor = System::Drawing::SystemColors::Window;
			this->textBox132->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox132->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox132->Location = System::Drawing::Point(392, 110);
			this->textBox132->Multiline = true;
			this->textBox132->Name = L"textBox132";
			this->textBox132->ReadOnly = true;
			this->textBox132->Size = System::Drawing::Size(49, 25);
			this->textBox132->TabIndex = 62;
			this->textBox132->Text = L"* w";
			// 
			// input_bs_r_1
			// 
			this->input_bs_r_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_bs_r_1->DecimalPlaces = 4;
			this->input_bs_r_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_bs_r_1->Location = System::Drawing::Point(312, 108);
			this->input_bs_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_bs_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_bs_r_1->Name = L"input_bs_r_1";
			this->input_bs_r_1->Size = System::Drawing::Size(74, 27);
			this->input_bs_r_1->TabIndex = 61;
			// 
			// textBox133
			// 
			this->textBox133->BackColor = System::Drawing::SystemColors::Window;
			this->textBox133->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox133->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox133->Location = System::Drawing::Point(257, 110);
			this->textBox133->Multiline = true;
			this->textBox133->Name = L"textBox133";
			this->textBox133->ReadOnly = true;
			this->textBox133->Size = System::Drawing::Size(49, 25);
			this->textBox133->TabIndex = 60;
			this->textBox133->Text = L"* w² +";
			// 
			// input_bs_r_2
			// 
			this->input_bs_r_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_bs_r_2->DecimalPlaces = 4;
			this->input_bs_r_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_bs_r_2->Location = System::Drawing::Point(177, 108);
			this->input_bs_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_bs_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_bs_r_2->Name = L"input_bs_r_2";
			this->input_bs_r_2->Size = System::Drawing::Size(74, 27);
			this->input_bs_r_2->TabIndex = 58;
			// 
			// textBox134
			// 
			this->textBox134->BackColor = System::Drawing::SystemColors::Window;
			this->textBox134->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox134->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox134->Location = System::Drawing::Point(6, 110);
			this->textBox134->Multiline = true;
			this->textBox134->Name = L"textBox134";
			this->textBox134->ReadOnly = true;
			this->textBox134->Size = System::Drawing::Size(165, 25);
			this->textBox134->TabIndex = 59;
			this->textBox134->Text = L"Rear bump steer [°]";
			// 
			// textBox147
			// 
			this->textBox147->BackColor = System::Drawing::SystemColors::Window;
			this->textBox147->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox147->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox147->Location = System::Drawing::Point(392, 70);
			this->textBox147->Multiline = true;
			this->textBox147->Name = L"textBox147";
			this->textBox147->ReadOnly = true;
			this->textBox147->Size = System::Drawing::Size(49, 25);
			this->textBox147->TabIndex = 56;
			this->textBox147->Text = L"* w";
			// 
			// input_bs_f_1
			// 
			this->input_bs_f_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_bs_f_1->DecimalPlaces = 4;
			this->input_bs_f_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_bs_f_1->Location = System::Drawing::Point(312, 68);
			this->input_bs_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_bs_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_bs_f_1->Name = L"input_bs_f_1";
			this->input_bs_f_1->Size = System::Drawing::Size(74, 27);
			this->input_bs_f_1->TabIndex = 55;
			// 
			// textBox148
			// 
			this->textBox148->BackColor = System::Drawing::SystemColors::Window;
			this->textBox148->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox148->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox148->Location = System::Drawing::Point(257, 70);
			this->textBox148->Multiline = true;
			this->textBox148->Name = L"textBox148";
			this->textBox148->ReadOnly = true;
			this->textBox148->Size = System::Drawing::Size(49, 25);
			this->textBox148->TabIndex = 54;
			this->textBox148->Text = L"* w² +";
			// 
			// input_bs_f_2
			// 
			this->input_bs_f_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_bs_f_2->DecimalPlaces = 4;
			this->input_bs_f_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_bs_f_2->Location = System::Drawing::Point(177, 68);
			this->input_bs_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_bs_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_bs_f_2->Name = L"input_bs_f_2";
			this->input_bs_f_2->Size = System::Drawing::Size(74, 27);
			this->input_bs_f_2->TabIndex = 52;
			// 
			// textBox149
			// 
			this->textBox149->BackColor = System::Drawing::SystemColors::Window;
			this->textBox149->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox149->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox149->Location = System::Drawing::Point(6, 70);
			this->textBox149->Multiline = true;
			this->textBox149->Name = L"textBox149";
			this->textBox149->ReadOnly = true;
			this->textBox149->Size = System::Drawing::Size(165, 23);
			this->textBox149->TabIndex = 53;
			this->textBox149->Text = L"Front bump steer [°]";
			// 
			// textBox150
			// 
			this->textBox150->BackColor = System::Drawing::SystemColors::Window;
			this->textBox150->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox150->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox150->Location = System::Drawing::Point(392, 32);
			this->textBox150->Multiline = true;
			this->textBox150->Name = L"textBox150";
			this->textBox150->ReadOnly = true;
			this->textBox150->Size = System::Drawing::Size(49, 25);
			this->textBox150->TabIndex = 50;
			this->textBox150->Text = L"* δd";
			// 
			// input_ackermann_1
			// 
			this->input_ackermann_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_ackermann_1->DecimalPlaces = 4;
			this->input_ackermann_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_ackermann_1->Location = System::Drawing::Point(312, 30);
			this->input_ackermann_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_ackermann_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_ackermann_1->Name = L"input_ackermann_1";
			this->input_ackermann_1->Size = System::Drawing::Size(74, 27);
			this->input_ackermann_1->TabIndex = 49;
			// 
			// textBox151
			// 
			this->textBox151->BackColor = System::Drawing::SystemColors::Window;
			this->textBox151->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox151->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox151->Location = System::Drawing::Point(257, 32);
			this->textBox151->Multiline = true;
			this->textBox151->Name = L"textBox151";
			this->textBox151->ReadOnly = true;
			this->textBox151->Size = System::Drawing::Size(49, 25);
			this->textBox151->TabIndex = 48;
			this->textBox151->Text = L"* δd² +";
			// 
			// input_ackermann_2
			// 
			this->input_ackermann_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_ackermann_2->DecimalPlaces = 4;
			this->input_ackermann_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_ackermann_2->Location = System::Drawing::Point(177, 30);
			this->input_ackermann_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_ackermann_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_ackermann_2->Name = L"input_ackermann_2";
			this->input_ackermann_2->Size = System::Drawing::Size(74, 27);
			this->input_ackermann_2->TabIndex = 46;
			// 
			// textBox152
			// 
			this->textBox152->BackColor = System::Drawing::SystemColors::Window;
			this->textBox152->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox152->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox152->Location = System::Drawing::Point(6, 32);
			this->textBox152->Multiline = true;
			this->textBox152->Name = L"textBox152";
			this->textBox152->ReadOnly = true;
			this->textBox152->Size = System::Drawing::Size(165, 32);
			this->textBox152->TabIndex = 47;
			this->textBox152->Text = L"Ackermann [°]";
			// 
			// groupBox18
			// 
			this->groupBox18->Controls->Add(this->input_MR_arb_r_0);
			this->groupBox18->Controls->Add(this->textBox135);
			this->groupBox18->Controls->Add(this->input_MR_arb_r_1);
			this->groupBox18->Controls->Add(this->textBox136);
			this->groupBox18->Controls->Add(this->input_MR_arb_r_2);
			this->groupBox18->Controls->Add(this->textBox137);
			this->groupBox18->Controls->Add(this->input_MR_arb_f_0);
			this->groupBox18->Controls->Add(this->textBox138);
			this->groupBox18->Controls->Add(this->input_MR_arb_f_1);
			this->groupBox18->Controls->Add(this->textBox139);
			this->groupBox18->Controls->Add(this->input_MR_arb_f_2);
			this->groupBox18->Controls->Add(this->textBox140);
			this->groupBox18->Controls->Add(this->input_MR_s_r_0);
			this->groupBox18->Controls->Add(this->textBox141);
			this->groupBox18->Controls->Add(this->input_MR_s_r_1);
			this->groupBox18->Controls->Add(this->textBox142);
			this->groupBox18->Controls->Add(this->input_MR_s_r_2);
			this->groupBox18->Controls->Add(this->textBox143);
			this->groupBox18->Controls->Add(this->input_MR_s_f_0);
			this->groupBox18->Controls->Add(this->textBox144);
			this->groupBox18->Controls->Add(this->input_MR_s_f_1);
			this->groupBox18->Controls->Add(this->textBox145);
			this->groupBox18->Controls->Add(this->input_MR_s_f_2);
			this->groupBox18->Controls->Add(this->textBox146);
			this->groupBox18->Location = System::Drawing::Point(560, 9);
			this->groupBox18->Name = L"groupBox18";
			this->groupBox18->Size = System::Drawing::Size(548, 186);
			this->groupBox18->TabIndex = 23;
			this->groupBox18->TabStop = false;
			this->groupBox18->Text = L"Motion ratios";
			// 
			// input_MR_arb_r_0
			// 
			this->input_MR_arb_r_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_arb_r_0->DecimalPlaces = 4;
			this->input_MR_arb_r_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_arb_r_0->Location = System::Drawing::Point(436, 149);
			this->input_MR_arb_r_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_arb_r_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_arb_r_0->Name = L"input_MR_arb_r_0";
			this->input_MR_arb_r_0->Size = System::Drawing::Size(74, 27);
			this->input_MR_arb_r_0->TabIndex = 69;
			// 
			// textBox135
			// 
			this->textBox135->BackColor = System::Drawing::SystemColors::Window;
			this->textBox135->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox135->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox135->Location = System::Drawing::Point(392, 151);
			this->textBox135->Multiline = true;
			this->textBox135->Name = L"textBox135";
			this->textBox135->ReadOnly = true;
			this->textBox135->Size = System::Drawing::Size(49, 25);
			this->textBox135->TabIndex = 68;
			this->textBox135->Text = L"* w +";
			// 
			// input_MR_arb_r_1
			// 
			this->input_MR_arb_r_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_arb_r_1->DecimalPlaces = 4;
			this->input_MR_arb_r_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_arb_r_1->Location = System::Drawing::Point(312, 149);
			this->input_MR_arb_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_arb_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_arb_r_1->Name = L"input_MR_arb_r_1";
			this->input_MR_arb_r_1->Size = System::Drawing::Size(74, 27);
			this->input_MR_arb_r_1->TabIndex = 67;
			// 
			// textBox136
			// 
			this->textBox136->BackColor = System::Drawing::SystemColors::Window;
			this->textBox136->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox136->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox136->Location = System::Drawing::Point(257, 151);
			this->textBox136->Multiline = true;
			this->textBox136->Name = L"textBox136";
			this->textBox136->ReadOnly = true;
			this->textBox136->Size = System::Drawing::Size(49, 25);
			this->textBox136->TabIndex = 66;
			this->textBox136->Text = L"* w² +";
			// 
			// input_MR_arb_r_2
			// 
			this->input_MR_arb_r_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_arb_r_2->DecimalPlaces = 4;
			this->input_MR_arb_r_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_arb_r_2->Location = System::Drawing::Point(177, 149);
			this->input_MR_arb_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_arb_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_arb_r_2->Name = L"input_MR_arb_r_2";
			this->input_MR_arb_r_2->Size = System::Drawing::Size(74, 27);
			this->input_MR_arb_r_2->TabIndex = 64;
			// 
			// textBox137
			// 
			this->textBox137->BackColor = System::Drawing::SystemColors::Window;
			this->textBox137->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox137->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox137->Location = System::Drawing::Point(6, 151);
			this->textBox137->Multiline = true;
			this->textBox137->Name = L"textBox137";
			this->textBox137->ReadOnly = true;
			this->textBox137->Size = System::Drawing::Size(165, 25);
			this->textBox137->TabIndex = 65;
			this->textBox137->Text = L"Rear ARB [mm/mm]";
			// 
			// input_MR_arb_f_0
			// 
			this->input_MR_arb_f_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_arb_f_0->DecimalPlaces = 4;
			this->input_MR_arb_f_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_arb_f_0->Location = System::Drawing::Point(436, 108);
			this->input_MR_arb_f_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_arb_f_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_arb_f_0->Name = L"input_MR_arb_f_0";
			this->input_MR_arb_f_0->Size = System::Drawing::Size(74, 27);
			this->input_MR_arb_f_0->TabIndex = 63;
			// 
			// textBox138
			// 
			this->textBox138->BackColor = System::Drawing::SystemColors::Window;
			this->textBox138->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox138->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox138->Location = System::Drawing::Point(392, 110);
			this->textBox138->Multiline = true;
			this->textBox138->Name = L"textBox138";
			this->textBox138->ReadOnly = true;
			this->textBox138->Size = System::Drawing::Size(49, 25);
			this->textBox138->TabIndex = 62;
			this->textBox138->Text = L"* w +";
			// 
			// input_MR_arb_f_1
			// 
			this->input_MR_arb_f_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_arb_f_1->DecimalPlaces = 4;
			this->input_MR_arb_f_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_arb_f_1->Location = System::Drawing::Point(312, 108);
			this->input_MR_arb_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_arb_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_arb_f_1->Name = L"input_MR_arb_f_1";
			this->input_MR_arb_f_1->Size = System::Drawing::Size(74, 27);
			this->input_MR_arb_f_1->TabIndex = 61;
			// 
			// textBox139
			// 
			this->textBox139->BackColor = System::Drawing::SystemColors::Window;
			this->textBox139->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox139->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox139->Location = System::Drawing::Point(257, 110);
			this->textBox139->Multiline = true;
			this->textBox139->Name = L"textBox139";
			this->textBox139->ReadOnly = true;
			this->textBox139->Size = System::Drawing::Size(49, 25);
			this->textBox139->TabIndex = 60;
			this->textBox139->Text = L"* w² +";
			// 
			// input_MR_arb_f_2
			// 
			this->input_MR_arb_f_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_arb_f_2->DecimalPlaces = 4;
			this->input_MR_arb_f_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_arb_f_2->Location = System::Drawing::Point(177, 108);
			this->input_MR_arb_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_arb_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_arb_f_2->Name = L"input_MR_arb_f_2";
			this->input_MR_arb_f_2->Size = System::Drawing::Size(74, 27);
			this->input_MR_arb_f_2->TabIndex = 58;
			// 
			// textBox140
			// 
			this->textBox140->BackColor = System::Drawing::SystemColors::Window;
			this->textBox140->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox140->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox140->Location = System::Drawing::Point(6, 110);
			this->textBox140->Multiline = true;
			this->textBox140->Name = L"textBox140";
			this->textBox140->ReadOnly = true;
			this->textBox140->Size = System::Drawing::Size(165, 25);
			this->textBox140->TabIndex = 59;
			this->textBox140->Text = L"Front ARB [mm/mm]";
			// 
			// input_MR_s_r_0
			// 
			this->input_MR_s_r_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_s_r_0->DecimalPlaces = 4;
			this->input_MR_s_r_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_s_r_0->Location = System::Drawing::Point(436, 68);
			this->input_MR_s_r_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_s_r_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_s_r_0->Name = L"input_MR_s_r_0";
			this->input_MR_s_r_0->Size = System::Drawing::Size(74, 27);
			this->input_MR_s_r_0->TabIndex = 57;
			// 
			// textBox141
			// 
			this->textBox141->BackColor = System::Drawing::SystemColors::Window;
			this->textBox141->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox141->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox141->Location = System::Drawing::Point(392, 70);
			this->textBox141->Multiline = true;
			this->textBox141->Name = L"textBox141";
			this->textBox141->ReadOnly = true;
			this->textBox141->Size = System::Drawing::Size(49, 25);
			this->textBox141->TabIndex = 56;
			this->textBox141->Text = L"* w +";
			// 
			// input_MR_s_r_1
			// 
			this->input_MR_s_r_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_s_r_1->DecimalPlaces = 4;
			this->input_MR_s_r_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_s_r_1->Location = System::Drawing::Point(312, 68);
			this->input_MR_s_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_s_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_s_r_1->Name = L"input_MR_s_r_1";
			this->input_MR_s_r_1->Size = System::Drawing::Size(74, 27);
			this->input_MR_s_r_1->TabIndex = 55;
			// 
			// textBox142
			// 
			this->textBox142->BackColor = System::Drawing::SystemColors::Window;
			this->textBox142->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox142->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox142->Location = System::Drawing::Point(257, 70);
			this->textBox142->Multiline = true;
			this->textBox142->Name = L"textBox142";
			this->textBox142->ReadOnly = true;
			this->textBox142->Size = System::Drawing::Size(49, 25);
			this->textBox142->TabIndex = 54;
			this->textBox142->Text = L"* w² +";
			// 
			// input_MR_s_r_2
			// 
			this->input_MR_s_r_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_s_r_2->DecimalPlaces = 4;
			this->input_MR_s_r_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_s_r_2->Location = System::Drawing::Point(177, 68);
			this->input_MR_s_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_s_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_s_r_2->Name = L"input_MR_s_r_2";
			this->input_MR_s_r_2->Size = System::Drawing::Size(74, 27);
			this->input_MR_s_r_2->TabIndex = 52;
			// 
			// textBox143
			// 
			this->textBox143->BackColor = System::Drawing::SystemColors::Window;
			this->textBox143->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox143->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox143->Location = System::Drawing::Point(6, 70);
			this->textBox143->Multiline = true;
			this->textBox143->Name = L"textBox143";
			this->textBox143->ReadOnly = true;
			this->textBox143->Size = System::Drawing::Size(165, 23);
			this->textBox143->TabIndex = 53;
			this->textBox143->Text = L"Rear springs [mm/mm]";
			// 
			// input_MR_s_f_0
			// 
			this->input_MR_s_f_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_s_f_0->DecimalPlaces = 4;
			this->input_MR_s_f_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_s_f_0->Location = System::Drawing::Point(436, 30);
			this->input_MR_s_f_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_s_f_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_s_f_0->Name = L"input_MR_s_f_0";
			this->input_MR_s_f_0->Size = System::Drawing::Size(74, 27);
			this->input_MR_s_f_0->TabIndex = 51;
			// 
			// textBox144
			// 
			this->textBox144->BackColor = System::Drawing::SystemColors::Window;
			this->textBox144->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox144->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox144->Location = System::Drawing::Point(392, 32);
			this->textBox144->Multiline = true;
			this->textBox144->Name = L"textBox144";
			this->textBox144->ReadOnly = true;
			this->textBox144->Size = System::Drawing::Size(49, 25);
			this->textBox144->TabIndex = 50;
			this->textBox144->Text = L"* w +";
			// 
			// input_MR_s_f_1
			// 
			this->input_MR_s_f_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_s_f_1->DecimalPlaces = 4;
			this->input_MR_s_f_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_s_f_1->Location = System::Drawing::Point(312, 30);
			this->input_MR_s_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_s_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_s_f_1->Name = L"input_MR_s_f_1";
			this->input_MR_s_f_1->Size = System::Drawing::Size(74, 27);
			this->input_MR_s_f_1->TabIndex = 49;
			// 
			// textBox145
			// 
			this->textBox145->BackColor = System::Drawing::SystemColors::Window;
			this->textBox145->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox145->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox145->Location = System::Drawing::Point(257, 32);
			this->textBox145->Multiline = true;
			this->textBox145->Name = L"textBox145";
			this->textBox145->ReadOnly = true;
			this->textBox145->Size = System::Drawing::Size(49, 25);
			this->textBox145->TabIndex = 48;
			this->textBox145->Text = L"* w² +";
			// 
			// input_MR_s_f_2
			// 
			this->input_MR_s_f_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_MR_s_f_2->DecimalPlaces = 4;
			this->input_MR_s_f_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_MR_s_f_2->Location = System::Drawing::Point(177, 30);
			this->input_MR_s_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_MR_s_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_MR_s_f_2->Name = L"input_MR_s_f_2";
			this->input_MR_s_f_2->Size = System::Drawing::Size(74, 27);
			this->input_MR_s_f_2->TabIndex = 46;
			// 
			// textBox146
			// 
			this->textBox146->BackColor = System::Drawing::SystemColors::Window;
			this->textBox146->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox146->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox146->Location = System::Drawing::Point(6, 32);
			this->textBox146->Multiline = true;
			this->textBox146->Name = L"textBox146";
			this->textBox146->ReadOnly = true;
			this->textBox146->Size = System::Drawing::Size(165, 32);
			this->textBox146->TabIndex = 47;
			this->textBox146->Text = L"Front springs [mm/mm]";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->input_q_r_r_0);
			this->groupBox6->Controls->Add(this->textBox111);
			this->groupBox6->Controls->Add(this->input_q_r_r_1);
			this->groupBox6->Controls->Add(this->textBox112);
			this->groupBox6->Controls->Add(this->input_q_r_r_2);
			this->groupBox6->Controls->Add(this->textBox113);
			this->groupBox6->Controls->Add(this->input_q_r_f_0);
			this->groupBox6->Controls->Add(this->textBox105);
			this->groupBox6->Controls->Add(this->input_q_r_f_1);
			this->groupBox6->Controls->Add(this->textBox106);
			this->groupBox6->Controls->Add(this->input_q_r_f_2);
			this->groupBox6->Controls->Add(this->textBox107);
			this->groupBox6->Controls->Add(this->input_off_r_r_0);
			this->groupBox6->Controls->Add(this->textBox102);
			this->groupBox6->Controls->Add(this->input_off_r_r_1);
			this->groupBox6->Controls->Add(this->textBox103);
			this->groupBox6->Controls->Add(this->input_off_r_r_2);
			this->groupBox6->Controls->Add(this->textBox104);
			this->groupBox6->Controls->Add(this->input_off_r_f_0);
			this->groupBox6->Controls->Add(this->textBox99);
			this->groupBox6->Controls->Add(this->input_off_r_f_1);
			this->groupBox6->Controls->Add(this->textBox100);
			this->groupBox6->Controls->Add(this->input_off_r_f_2);
			this->groupBox6->Controls->Add(this->textBox101);
			this->groupBox6->Controls->Add(this->input_h_r_r_0);
			this->groupBox6->Controls->Add(this->textBox96);
			this->groupBox6->Controls->Add(this->input_h_r_r_1);
			this->groupBox6->Controls->Add(this->textBox97);
			this->groupBox6->Controls->Add(this->input_h_r_r_2);
			this->groupBox6->Controls->Add(this->textBox98);
			this->groupBox6->Controls->Add(this->input_h_r_f_0);
			this->groupBox6->Controls->Add(this->textBox19);
			this->groupBox6->Controls->Add(this->input_h_r_f_1);
			this->groupBox6->Controls->Add(this->textBox21);
			this->groupBox6->Controls->Add(this->input_h_r_f_2);
			this->groupBox6->Controls->Add(this->textBox95);
			this->groupBox6->Location = System::Drawing::Point(6, 6);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(548, 288);
			this->groupBox6->TabIndex = 22;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Roll kinematics";
			// 
			// input_q_r_r_0
			// 
			this->input_q_r_r_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_r_r_0->DecimalPlaces = 4;
			this->input_q_r_r_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_r_r_0->Location = System::Drawing::Point(468, 246);
			this->input_q_r_r_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_r_r_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_r_r_0->Name = L"input_q_r_r_0";
			this->input_q_r_r_0->Size = System::Drawing::Size(74, 27);
			this->input_q_r_r_0->TabIndex = 81;
			// 
			// textBox111
			// 
			this->textBox111->BackColor = System::Drawing::SystemColors::Window;
			this->textBox111->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox111->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox111->Location = System::Drawing::Point(424, 248);
			this->textBox111->Multiline = true;
			this->textBox111->Name = L"textBox111";
			this->textBox111->ReadOnly = true;
			this->textBox111->Size = System::Drawing::Size(49, 25);
			this->textBox111->TabIndex = 80;
			this->textBox111->Text = L"* Ψ +";
			// 
			// input_q_r_r_1
			// 
			this->input_q_r_r_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_r_r_1->DecimalPlaces = 4;
			this->input_q_r_r_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_r_r_1->Location = System::Drawing::Point(344, 246);
			this->input_q_r_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_r_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_r_r_1->Name = L"input_q_r_r_1";
			this->input_q_r_r_1->Size = System::Drawing::Size(74, 27);
			this->input_q_r_r_1->TabIndex = 79;
			// 
			// textBox112
			// 
			this->textBox112->BackColor = System::Drawing::SystemColors::Window;
			this->textBox112->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox112->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox112->Location = System::Drawing::Point(289, 248);
			this->textBox112->Multiline = true;
			this->textBox112->Name = L"textBox112";
			this->textBox112->ReadOnly = true;
			this->textBox112->Size = System::Drawing::Size(49, 25);
			this->textBox112->TabIndex = 78;
			this->textBox112->Text = L"* Ψ² +";
			// 
			// input_q_r_r_2
			// 
			this->input_q_r_r_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_r_r_2->DecimalPlaces = 4;
			this->input_q_r_r_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_r_r_2->Location = System::Drawing::Point(209, 246);
			this->input_q_r_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_r_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_r_r_2->Name = L"input_q_r_r_2";
			this->input_q_r_r_2->Size = System::Drawing::Size(74, 27);
			this->input_q_r_r_2->TabIndex = 76;
			// 
			// textBox113
			// 
			this->textBox113->BackColor = System::Drawing::SystemColors::Window;
			this->textBox113->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox113->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox113->Location = System::Drawing::Point(6, 235);
			this->textBox113->Multiline = true;
			this->textBox113->Name = L"textBox113";
			this->textBox113->ReadOnly = true;
			this->textBox113->Size = System::Drawing::Size(197, 44);
			this->textBox113->TabIndex = 77;
			this->textBox113->Text = L"Rear roll instant center lateral position [mm]";
			// 
			// input_q_r_f_0
			// 
			this->input_q_r_f_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_r_f_0->DecimalPlaces = 4;
			this->input_q_r_f_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_r_f_0->Location = System::Drawing::Point(468, 122);
			this->input_q_r_f_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_r_f_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_r_f_0->Name = L"input_q_r_f_0";
			this->input_q_r_f_0->Size = System::Drawing::Size(74, 27);
			this->input_q_r_f_0->TabIndex = 75;
			// 
			// textBox105
			// 
			this->textBox105->BackColor = System::Drawing::SystemColors::Window;
			this->textBox105->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox105->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox105->Location = System::Drawing::Point(424, 124);
			this->textBox105->Multiline = true;
			this->textBox105->Name = L"textBox105";
			this->textBox105->ReadOnly = true;
			this->textBox105->Size = System::Drawing::Size(49, 25);
			this->textBox105->TabIndex = 74;
			this->textBox105->Text = L"* Ψ +";
			// 
			// input_q_r_f_1
			// 
			this->input_q_r_f_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_r_f_1->DecimalPlaces = 4;
			this->input_q_r_f_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_r_f_1->Location = System::Drawing::Point(344, 122);
			this->input_q_r_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_r_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_r_f_1->Name = L"input_q_r_f_1";
			this->input_q_r_f_1->Size = System::Drawing::Size(74, 27);
			this->input_q_r_f_1->TabIndex = 73;
			// 
			// textBox106
			// 
			this->textBox106->BackColor = System::Drawing::SystemColors::Window;
			this->textBox106->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox106->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox106->Location = System::Drawing::Point(289, 124);
			this->textBox106->Multiline = true;
			this->textBox106->Name = L"textBox106";
			this->textBox106->ReadOnly = true;
			this->textBox106->Size = System::Drawing::Size(49, 25);
			this->textBox106->TabIndex = 72;
			this->textBox106->Text = L"* Ψ² +";
			// 
			// input_q_r_f_2
			// 
			this->input_q_r_f_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_q_r_f_2->DecimalPlaces = 4;
			this->input_q_r_f_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_q_r_f_2->Location = System::Drawing::Point(209, 122);
			this->input_q_r_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_q_r_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_q_r_f_2->Name = L"input_q_r_f_2";
			this->input_q_r_f_2->Size = System::Drawing::Size(74, 27);
			this->input_q_r_f_2->TabIndex = 70;
			// 
			// textBox107
			// 
			this->textBox107->BackColor = System::Drawing::SystemColors::Window;
			this->textBox107->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox107->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox107->Location = System::Drawing::Point(6, 111);
			this->textBox107->Multiline = true;
			this->textBox107->Name = L"textBox107";
			this->textBox107->ReadOnly = true;
			this->textBox107->Size = System::Drawing::Size(197, 44);
			this->textBox107->TabIndex = 71;
			this->textBox107->Text = L"Front roll instant center lateral position [mm]";
			// 
			// input_off_r_r_0
			// 
			this->input_off_r_r_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_off_r_r_0->DecimalPlaces = 4;
			this->input_off_r_r_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_off_r_r_0->Location = System::Drawing::Point(468, 207);
			this->input_off_r_r_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_r_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_r_0->Name = L"input_off_r_r_0";
			this->input_off_r_r_0->Size = System::Drawing::Size(74, 27);
			this->input_off_r_r_0->TabIndex = 69;
			// 
			// textBox102
			// 
			this->textBox102->BackColor = System::Drawing::SystemColors::Window;
			this->textBox102->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox102->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox102->Location = System::Drawing::Point(424, 209);
			this->textBox102->Multiline = true;
			this->textBox102->Name = L"textBox102";
			this->textBox102->ReadOnly = true;
			this->textBox102->Size = System::Drawing::Size(49, 25);
			this->textBox102->TabIndex = 68;
			this->textBox102->Text = L"* Ψ +";
			// 
			// input_off_r_r_1
			// 
			this->input_off_r_r_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_off_r_r_1->DecimalPlaces = 4;
			this->input_off_r_r_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_off_r_r_1->Location = System::Drawing::Point(344, 207);
			this->input_off_r_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_r_1->Name = L"input_off_r_r_1";
			this->input_off_r_r_1->Size = System::Drawing::Size(74, 27);
			this->input_off_r_r_1->TabIndex = 67;
			// 
			// textBox103
			// 
			this->textBox103->BackColor = System::Drawing::SystemColors::Window;
			this->textBox103->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox103->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox103->Location = System::Drawing::Point(289, 209);
			this->textBox103->Multiline = true;
			this->textBox103->Name = L"textBox103";
			this->textBox103->ReadOnly = true;
			this->textBox103->Size = System::Drawing::Size(49, 25);
			this->textBox103->TabIndex = 66;
			this->textBox103->Text = L"* Ψ² +";
			// 
			// input_off_r_r_2
			// 
			this->input_off_r_r_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_off_r_r_2->DecimalPlaces = 4;
			this->input_off_r_r_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_off_r_r_2->Location = System::Drawing::Point(209, 207);
			this->input_off_r_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_r_2->Name = L"input_off_r_r_2";
			this->input_off_r_r_2->Size = System::Drawing::Size(74, 27);
			this->input_off_r_r_2->TabIndex = 64;
			// 
			// textBox104
			// 
			this->textBox104->BackColor = System::Drawing::SystemColors::Window;
			this->textBox104->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox104->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox104->Location = System::Drawing::Point(6, 196);
			this->textBox104->Multiline = true;
			this->textBox104->Name = L"textBox104";
			this->textBox104->ReadOnly = true;
			this->textBox104->Size = System::Drawing::Size(197, 44);
			this->textBox104->TabIndex = 65;
			this->textBox104->Text = L"Rear roll center lateral offset [mm]";
			// 
			// input_off_r_f_0
			// 
			this->input_off_r_f_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_off_r_f_0->DecimalPlaces = 4;
			this->input_off_r_f_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_off_r_f_0->Location = System::Drawing::Point(468, 84);
			this->input_off_r_f_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_f_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_f_0->Name = L"input_off_r_f_0";
			this->input_off_r_f_0->Size = System::Drawing::Size(74, 27);
			this->input_off_r_f_0->TabIndex = 63;
			// 
			// textBox99
			// 
			this->textBox99->BackColor = System::Drawing::SystemColors::Window;
			this->textBox99->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox99->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox99->Location = System::Drawing::Point(424, 86);
			this->textBox99->Multiline = true;
			this->textBox99->Name = L"textBox99";
			this->textBox99->ReadOnly = true;
			this->textBox99->Size = System::Drawing::Size(49, 25);
			this->textBox99->TabIndex = 62;
			this->textBox99->Text = L"* Ψ +";
			// 
			// input_off_r_f_1
			// 
			this->input_off_r_f_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_off_r_f_1->DecimalPlaces = 4;
			this->input_off_r_f_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_off_r_f_1->Location = System::Drawing::Point(344, 84);
			this->input_off_r_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_f_1->Name = L"input_off_r_f_1";
			this->input_off_r_f_1->Size = System::Drawing::Size(74, 27);
			this->input_off_r_f_1->TabIndex = 61;
			// 
			// textBox100
			// 
			this->textBox100->BackColor = System::Drawing::SystemColors::Window;
			this->textBox100->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox100->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox100->Location = System::Drawing::Point(289, 86);
			this->textBox100->Multiline = true;
			this->textBox100->Name = L"textBox100";
			this->textBox100->ReadOnly = true;
			this->textBox100->Size = System::Drawing::Size(49, 25);
			this->textBox100->TabIndex = 60;
			this->textBox100->Text = L"* Ψ² +";
			// 
			// input_off_r_f_2
			// 
			this->input_off_r_f_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_off_r_f_2->DecimalPlaces = 4;
			this->input_off_r_f_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_off_r_f_2->Location = System::Drawing::Point(209, 84);
			this->input_off_r_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_f_2->Name = L"input_off_r_f_2";
			this->input_off_r_f_2->Size = System::Drawing::Size(74, 27);
			this->input_off_r_f_2->TabIndex = 58;
			// 
			// textBox101
			// 
			this->textBox101->BackColor = System::Drawing::SystemColors::Window;
			this->textBox101->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox101->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox101->Location = System::Drawing::Point(6, 73);
			this->textBox101->Multiline = true;
			this->textBox101->Name = L"textBox101";
			this->textBox101->ReadOnly = true;
			this->textBox101->Size = System::Drawing::Size(197, 44);
			this->textBox101->TabIndex = 59;
			this->textBox101->Text = L"Front roll center lateral offset [mm]";
			// 
			// input_h_r_r_0
			// 
			this->input_h_r_r_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_r_r_0->DecimalPlaces = 4;
			this->input_h_r_r_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_r_r_0->Location = System::Drawing::Point(468, 165);
			this->input_h_r_r_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_r_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_r_0->Name = L"input_h_r_r_0";
			this->input_h_r_r_0->Size = System::Drawing::Size(74, 27);
			this->input_h_r_r_0->TabIndex = 57;
			// 
			// textBox96
			// 
			this->textBox96->BackColor = System::Drawing::SystemColors::Window;
			this->textBox96->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox96->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox96->Location = System::Drawing::Point(424, 167);
			this->textBox96->Multiline = true;
			this->textBox96->Name = L"textBox96";
			this->textBox96->ReadOnly = true;
			this->textBox96->Size = System::Drawing::Size(49, 25);
			this->textBox96->TabIndex = 56;
			this->textBox96->Text = L"* Ψ +";
			// 
			// input_h_r_r_1
			// 
			this->input_h_r_r_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_r_r_1->DecimalPlaces = 4;
			this->input_h_r_r_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_r_r_1->Location = System::Drawing::Point(344, 165);
			this->input_h_r_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_r_1->Name = L"input_h_r_r_1";
			this->input_h_r_r_1->Size = System::Drawing::Size(74, 27);
			this->input_h_r_r_1->TabIndex = 55;
			// 
			// textBox97
			// 
			this->textBox97->BackColor = System::Drawing::SystemColors::Window;
			this->textBox97->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox97->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox97->Location = System::Drawing::Point(289, 167);
			this->textBox97->Multiline = true;
			this->textBox97->Name = L"textBox97";
			this->textBox97->ReadOnly = true;
			this->textBox97->Size = System::Drawing::Size(49, 25);
			this->textBox97->TabIndex = 54;
			this->textBox97->Text = L"* Ψ² +";
			// 
			// input_h_r_r_2
			// 
			this->input_h_r_r_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_r_r_2->DecimalPlaces = 4;
			this->input_h_r_r_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_r_r_2->Location = System::Drawing::Point(209, 165);
			this->input_h_r_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_r_2->Name = L"input_h_r_r_2";
			this->input_h_r_r_2->Size = System::Drawing::Size(74, 27);
			this->input_h_r_r_2->TabIndex = 52;
			// 
			// textBox98
			// 
			this->textBox98->BackColor = System::Drawing::SystemColors::Window;
			this->textBox98->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox98->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox98->Location = System::Drawing::Point(6, 164);
			this->textBox98->Multiline = true;
			this->textBox98->Name = L"textBox98";
			this->textBox98->ReadOnly = true;
			this->textBox98->Size = System::Drawing::Size(197, 25);
			this->textBox98->TabIndex = 53;
			this->textBox98->Text = L"Rear roll center height [mm]";
			// 
			// input_h_r_f_0
			// 
			this->input_h_r_f_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_r_f_0->DecimalPlaces = 4;
			this->input_h_r_f_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_r_f_0->Location = System::Drawing::Point(468, 43);
			this->input_h_r_f_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_f_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_f_0->Name = L"input_h_r_f_0";
			this->input_h_r_f_0->Size = System::Drawing::Size(74, 27);
			this->input_h_r_f_0->TabIndex = 51;
			// 
			// textBox19
			// 
			this->textBox19->BackColor = System::Drawing::SystemColors::Window;
			this->textBox19->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox19->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox19->Location = System::Drawing::Point(424, 45);
			this->textBox19->Multiline = true;
			this->textBox19->Name = L"textBox19";
			this->textBox19->ReadOnly = true;
			this->textBox19->Size = System::Drawing::Size(49, 25);
			this->textBox19->TabIndex = 50;
			this->textBox19->Text = L"* Ψ +";
			// 
			// input_h_r_f_1
			// 
			this->input_h_r_f_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_r_f_1->DecimalPlaces = 4;
			this->input_h_r_f_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_r_f_1->Location = System::Drawing::Point(344, 43);
			this->input_h_r_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_f_1->Name = L"input_h_r_f_1";
			this->input_h_r_f_1->Size = System::Drawing::Size(74, 27);
			this->input_h_r_f_1->TabIndex = 49;
			// 
			// textBox21
			// 
			this->textBox21->BackColor = System::Drawing::SystemColors::Window;
			this->textBox21->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox21->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox21->Location = System::Drawing::Point(289, 45);
			this->textBox21->Multiline = true;
			this->textBox21->Name = L"textBox21";
			this->textBox21->ReadOnly = true;
			this->textBox21->Size = System::Drawing::Size(49, 25);
			this->textBox21->TabIndex = 48;
			this->textBox21->Text = L"* Ψ² +";
			// 
			// input_h_r_f_2
			// 
			this->input_h_r_f_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_r_f_2->DecimalPlaces = 4;
			this->input_h_r_f_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_r_f_2->Location = System::Drawing::Point(209, 43);
			this->input_h_r_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_f_2->Name = L"input_h_r_f_2";
			this->input_h_r_f_2->Size = System::Drawing::Size(74, 27);
			this->input_h_r_f_2->TabIndex = 46;
			// 
			// textBox95
			// 
			this->textBox95->BackColor = System::Drawing::SystemColors::Window;
			this->textBox95->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox95->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox95->Location = System::Drawing::Point(6, 45);
			this->textBox95->Multiline = true;
			this->textBox95->Name = L"textBox95";
			this->textBox95->ReadOnly = true;
			this->textBox95->Size = System::Drawing::Size(197, 28);
			this->textBox95->TabIndex = 47;
			this->textBox95->Text = L"Front roll center height [mm]";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->splitContainer2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1075, 649);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Simulation";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(3, 3);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->input_force_debug_iter);
			this->splitContainer2->Panel1->Controls->Add(this->groupBox9);
			this->splitContainer2->Panel1->Controls->Add(this->groupBox8);
			this->splitContainer2->Panel1->Controls->Add(this->input_debug_iter);
			this->splitContainer2->Panel1MinSize = 450;
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->tabControl2);
			this->splitContainer2->Size = System::Drawing::Size(1069, 643);
			this->splitContainer2->SplitterDistance = 500;
			this->splitContainer2->TabIndex = 22;
			// 
			// input_force_debug_iter
			// 
			this->input_force_debug_iter->AutoSize = true;
			this->input_force_debug_iter->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_force_debug_iter->Location = System::Drawing::Point(78, 567);
			this->input_force_debug_iter->Name = L"input_force_debug_iter";
			this->input_force_debug_iter->Size = System::Drawing::Size(114, 19);
			this->input_force_debug_iter->TabIndex = 26;
			this->input_force_debug_iter->Text = L"Force debug iter";
			this->input_force_debug_iter->UseVisualStyleBackColor = true;
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->input_rear_arb_setup);
			this->groupBox9->Controls->Add(this->textBox84);
			this->groupBox9->Controls->Add(this->input_front_arb_setup);
			this->groupBox9->Controls->Add(this->textBox83);
			this->groupBox9->Controls->Add(this->input_rear_tires_selection);
			this->groupBox9->Controls->Add(this->textBox81);
			this->groupBox9->Controls->Add(this->input_front_tires_selection);
			this->groupBox9->Controls->Add(this->textBox82);
			this->groupBox9->Controls->Add(this->textBox36);
			this->groupBox9->Controls->Add(this->input_DB_input);
			this->groupBox9->Controls->Add(this->textBox27);
			this->groupBox9->Controls->Add(this->input_gamma_r_static);
			this->groupBox9->Controls->Add(this->textBox28);
			this->groupBox9->Controls->Add(this->input_BB_input);
			this->groupBox9->Controls->Add(this->textBox29);
			this->groupBox9->Controls->Add(this->input_gamma_f_static);
			this->groupBox9->Controls->Add(this->textBox34);
			this->groupBox9->Controls->Add(this->input_delta_r_static);
			this->groupBox9->Controls->Add(this->textBox35);
			this->groupBox9->Controls->Add(this->input_delta_f_static);
			this->groupBox9->Controls->Add(this->fake_DB);
			this->groupBox9->Controls->Add(this->fake_BB);
			this->groupBox9->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox9->Location = System::Drawing::Point(250, 3);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(241, 446);
			this->groupBox9->TabIndex = 17;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Setup";
			// 
			// input_rear_arb_setup
			// 
			this->input_rear_arb_setup->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_rear_arb_setup->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_rear_arb_setup->FormattingEnabled = true;
			this->input_rear_arb_setup->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"1/5", L"2/5", L"3/5", L"4/5", L"5/5",
					L"No ARB"
			});
			this->input_rear_arb_setup->Location = System::Drawing::Point(114, 398);
			this->input_rear_arb_setup->Name = L"input_rear_arb_setup";
			this->input_rear_arb_setup->Size = System::Drawing::Size(121, 27);
			this->input_rear_arb_setup->TabIndex = 28;
			// 
			// textBox84
			// 
			this->textBox84->BackColor = System::Drawing::SystemColors::Window;
			this->textBox84->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox84->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox84->Location = System::Drawing::Point(6, 390);
			this->textBox84->Multiline = true;
			this->textBox84->Name = L"textBox84";
			this->textBox84->ReadOnly = true;
			this->textBox84->Size = System::Drawing::Size(102, 40);
			this->textBox84->TabIndex = 27;
			this->textBox84->Text = L"Rear ARB setup";
			// 
			// input_front_arb_setup
			// 
			this->input_front_arb_setup->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_front_arb_setup->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_front_arb_setup->FormattingEnabled = true;
			this->input_front_arb_setup->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"1/5", L"2/5", L"3/5", L"4/5", L"5/5",
					L"No ARB"
			});
			this->input_front_arb_setup->Location = System::Drawing::Point(114, 358);
			this->input_front_arb_setup->Name = L"input_front_arb_setup";
			this->input_front_arb_setup->Size = System::Drawing::Size(121, 27);
			this->input_front_arb_setup->TabIndex = 26;
			// 
			// textBox83
			// 
			this->textBox83->BackColor = System::Drawing::SystemColors::Window;
			this->textBox83->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox83->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox83->Location = System::Drawing::Point(6, 348);
			this->textBox83->Multiline = true;
			this->textBox83->Name = L"textBox83";
			this->textBox83->ReadOnly = true;
			this->textBox83->Size = System::Drawing::Size(102, 40);
			this->textBox83->TabIndex = 25;
			this->textBox83->Text = L"Front ARB setup";
			// 
			// input_rear_tires_selection
			// 
			this->input_rear_tires_selection->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_rear_tires_selection->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_rear_tires_selection->FormattingEnabled = true;
			this->input_rear_tires_selection->Location = System::Drawing::Point(59, 309);
			this->input_rear_tires_selection->Name = L"input_rear_tires_selection";
			this->input_rear_tires_selection->Size = System::Drawing::Size(176, 27);
			this->input_rear_tires_selection->TabIndex = 24;
			// 
			// textBox81
			// 
			this->textBox81->BackColor = System::Drawing::SystemColors::Window;
			this->textBox81->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox81->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox81->Location = System::Drawing::Point(6, 302);
			this->textBox81->Multiline = true;
			this->textBox81->Name = L"textBox81";
			this->textBox81->ReadOnly = true;
			this->textBox81->Size = System::Drawing::Size(47, 39);
			this->textBox81->TabIndex = 23;
			this->textBox81->Text = L"Rear tires";
			// 
			// input_front_tires_selection
			// 
			this->input_front_tires_selection->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_front_tires_selection->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_front_tires_selection->FormattingEnabled = true;
			this->input_front_tires_selection->Location = System::Drawing::Point(59, 263);
			this->input_front_tires_selection->Name = L"input_front_tires_selection";
			this->input_front_tires_selection->Size = System::Drawing::Size(176, 27);
			this->input_front_tires_selection->TabIndex = 22;
			// 
			// textBox82
			// 
			this->textBox82->BackColor = System::Drawing::SystemColors::Window;
			this->textBox82->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox82->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox82->Location = System::Drawing::Point(6, 254);
			this->textBox82->Multiline = true;
			this->textBox82->Name = L"textBox82";
			this->textBox82->ReadOnly = true;
			this->textBox82->Size = System::Drawing::Size(47, 42);
			this->textBox82->TabIndex = 21;
			this->textBox82->Text = L"Front tires";
			// 
			// textBox36
			// 
			this->textBox36->BackColor = System::Drawing::SystemColors::Window;
			this->textBox36->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox36->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox36->Location = System::Drawing::Point(6, 220);
			this->textBox36->Multiline = true;
			this->textBox36->Name = L"textBox36";
			this->textBox36->ReadOnly = true;
			this->textBox36->Size = System::Drawing::Size(157, 27);
			this->textBox36->TabIndex = 18;
			this->textBox36->Text = L"Drive bias [%front]";
			// 
			// input_DB_input
			// 
			this->input_DB_input->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_DB_input->DecimalPlaces = 2;
			this->input_DB_input->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_DB_input->Location = System::Drawing::Point(169, 220);
			this->input_DB_input->Name = L"input_DB_input";
			this->input_DB_input->Size = System::Drawing::Size(66, 27);
			this->input_DB_input->TabIndex = 17;
			this->input_DB_input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			// 
			// textBox27
			// 
			this->textBox27->BackColor = System::Drawing::SystemColors::Window;
			this->textBox27->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox27->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox27->Location = System::Drawing::Point(6, 145);
			this->textBox27->Multiline = true;
			this->textBox27->Name = L"textBox27";
			this->textBox27->ReadOnly = true;
			this->textBox27->Size = System::Drawing::Size(157, 37);
			this->textBox27->TabIndex = 16;
			this->textBox27->Text = L"Rear camber [°]";
			// 
			// input_gamma_r_static
			// 
			this->input_gamma_r_static->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_gamma_r_static->DecimalPlaces = 2;
			this->input_gamma_r_static->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_gamma_r_static->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_gamma_r_static->Location = System::Drawing::Point(169, 146);
			this->input_gamma_r_static->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_gamma_r_static->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, System::Int32::MinValue });
			this->input_gamma_r_static->Name = L"input_gamma_r_static";
			this->input_gamma_r_static->Size = System::Drawing::Size(66, 27);
			this->input_gamma_r_static->TabIndex = 15;
			// 
			// textBox28
			// 
			this->textBox28->BackColor = System::Drawing::SystemColors::Window;
			this->textBox28->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox28->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox28->Location = System::Drawing::Point(6, 183);
			this->textBox28->Multiline = true;
			this->textBox28->Name = L"textBox28";
			this->textBox28->ReadOnly = true;
			this->textBox28->Size = System::Drawing::Size(157, 27);
			this->textBox28->TabIndex = 8;
			this->textBox28->Text = L"Brake bias [%front]";
			// 
			// input_BB_input
			// 
			this->input_BB_input->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_BB_input->DecimalPlaces = 2;
			this->input_BB_input->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_BB_input->Location = System::Drawing::Point(169, 183);
			this->input_BB_input->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 101, 0, 0, 0 });
			this->input_BB_input->Name = L"input_BB_input";
			this->input_BB_input->Size = System::Drawing::Size(66, 27);
			this->input_BB_input->TabIndex = 7;
			this->input_BB_input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 70, 0, 0, 0 });
			// 
			// textBox29
			// 
			this->textBox29->BackColor = System::Drawing::SystemColors::Window;
			this->textBox29->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox29->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox29->Location = System::Drawing::Point(6, 111);
			this->textBox29->Multiline = true;
			this->textBox29->Name = L"textBox29";
			this->textBox29->ReadOnly = true;
			this->textBox29->Size = System::Drawing::Size(157, 37);
			this->textBox29->TabIndex = 6;
			this->textBox29->Text = L"Front camber [°]";
			// 
			// input_gamma_f_static
			// 
			this->input_gamma_f_static->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_gamma_f_static->DecimalPlaces = 2;
			this->input_gamma_f_static->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_gamma_f_static->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_gamma_f_static->Location = System::Drawing::Point(169, 111);
			this->input_gamma_f_static->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_gamma_f_static->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, System::Int32::MinValue });
			this->input_gamma_f_static->Name = L"input_gamma_f_static";
			this->input_gamma_f_static->Size = System::Drawing::Size(66, 27);
			this->input_gamma_f_static->TabIndex = 5;
			// 
			// textBox34
			// 
			this->textBox34->BackColor = System::Drawing::SystemColors::Window;
			this->textBox34->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox34->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox34->Location = System::Drawing::Point(6, 78);
			this->textBox34->Multiline = true;
			this->textBox34->Name = L"textBox34";
			this->textBox34->ReadOnly = true;
			this->textBox34->Size = System::Drawing::Size(157, 20);
			this->textBox34->TabIndex = 4;
			this->textBox34->Text = L"Rear toe [°]";
			// 
			// input_delta_r_static
			// 
			this->input_delta_r_static->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_delta_r_static->DecimalPlaces = 2;
			this->input_delta_r_static->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_delta_r_static->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_delta_r_static->Location = System::Drawing::Point(169, 76);
			this->input_delta_r_static->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_delta_r_static->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, System::Int32::MinValue });
			this->input_delta_r_static->Name = L"input_delta_r_static";
			this->input_delta_r_static->Size = System::Drawing::Size(66, 27);
			this->input_delta_r_static->TabIndex = 3;
			// 
			// textBox35
			// 
			this->textBox35->BackColor = System::Drawing::SystemColors::Window;
			this->textBox35->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox35->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox35->Location = System::Drawing::Point(6, 44);
			this->textBox35->Multiline = true;
			this->textBox35->Name = L"textBox35";
			this->textBox35->ReadOnly = true;
			this->textBox35->Size = System::Drawing::Size(157, 30);
			this->textBox35->TabIndex = 2;
			this->textBox35->Text = L"Front toe [°]";
			// 
			// input_delta_f_static
			// 
			this->input_delta_f_static->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_delta_f_static->DecimalPlaces = 2;
			this->input_delta_f_static->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_delta_f_static->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_delta_f_static->Location = System::Drawing::Point(169, 42);
			this->input_delta_f_static->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_delta_f_static->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, System::Int32::MinValue });
			this->input_delta_f_static->Name = L"input_delta_f_static";
			this->input_delta_f_static->Size = System::Drawing::Size(66, 27);
			this->input_delta_f_static->TabIndex = 0;
			// 
			// fake_DB
			// 
			this->fake_DB->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->fake_DB->DecimalPlaces = 2;
			this->fake_DB->Enabled = false;
			this->fake_DB->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fake_DB->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->fake_DB->Location = System::Drawing::Point(169, 220);
			this->fake_DB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->fake_DB->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->fake_DB->Name = L"fake_DB";
			this->fake_DB->Size = System::Drawing::Size(66, 27);
			this->fake_DB->TabIndex = 30;
			// 
			// fake_BB
			// 
			this->fake_BB->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->fake_BB->DecimalPlaces = 2;
			this->fake_BB->Enabled = false;
			this->fake_BB->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fake_BB->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->fake_BB->Location = System::Drawing::Point(169, 183);
			this->fake_BB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->fake_BB->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->fake_BB->Name = L"fake_BB";
			this->fake_BB->Size = System::Drawing::Size(66, 27);
			this->fake_BB->TabIndex = 29;
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->input_force_radius);
			this->groupBox8->Controls->Add(this->input_a_lon_des);
			this->groupBox8->Controls->Add(this->textBox184);
			this->groupBox8->Controls->Add(this->input_V_input);
			this->groupBox8->Controls->Add(this->input_force_velocity);
			this->groupBox8->Controls->Add(this->input_steering_input);
			this->groupBox8->Controls->Add(this->textBox38);
			this->groupBox8->Controls->Add(this->input_pedals_input);
			this->groupBox8->Controls->Add(this->textBox37);
			this->groupBox8->Controls->Add(this->textBox26);
			this->groupBox8->Controls->Add(this->input_delta_d_deg);
			this->groupBox8->Controls->Add(this->textBox31);
			this->groupBox8->Controls->Add(this->input_beta_deg);
			this->groupBox8->Controls->Add(this->Display_corner_or_velocity);
			this->groupBox8->Controls->Add(this->input_R);
			this->groupBox8->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox8->Location = System::Drawing::Point(3, 3);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(241, 371);
			this->groupBox8->TabIndex = 8;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Driver";
			// 
			// input_force_radius
			// 
			this->input_force_radius->AutoSize = true;
			this->input_force_radius->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_force_radius->Location = System::Drawing::Point(107, 35);
			this->input_force_radius->Name = L"input_force_radius";
			this->input_force_radius->Size = System::Drawing::Size(134, 19);
			this->input_force_radius->TabIndex = 26;
			this->input_force_radius->Text = L"Corner radius input";
			this->input_force_radius->UseVisualStyleBackColor = true;
			this->input_force_radius->Click += gcnew System::EventHandler(this, &MyForm::input_force_radius_Click);
			// 
			// input_a_lon_des
			// 
			this->input_a_lon_des->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_a_lon_des->DecimalPlaces = 2;
			this->input_a_lon_des->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_a_lon_des->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_a_lon_des->Location = System::Drawing::Point(169, 228);
			this->input_a_lon_des->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->input_a_lon_des->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, System::Int32::MinValue });
			this->input_a_lon_des->Name = L"input_a_lon_des";
			this->input_a_lon_des->Size = System::Drawing::Size(66, 27);
			this->input_a_lon_des->TabIndex = 14;
			this->input_a_lon_des->ValueChanged += gcnew System::EventHandler(this, &MyForm::input_a_lon_des_ValueChanged);
			// 
			// textBox184
			// 
			this->textBox184->BackColor = System::Drawing::SystemColors::Window;
			this->textBox184->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox184->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox184->Location = System::Drawing::Point(6, 216);
			this->textBox184->Multiline = true;
			this->textBox184->Name = L"textBox184";
			this->textBox184->ReadOnly = true;
			this->textBox184->Size = System::Drawing::Size(157, 39);
			this->textBox184->TabIndex = 13;
			this->textBox184->Text = L"Longitudinal acceleration [g]";
			// 
			// input_V_input
			// 
			this->input_V_input->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_V_input->DecimalPlaces = 2;
			this->input_V_input->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_V_input->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_V_input->Location = System::Drawing::Point(169, 60);
			this->input_V_input->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_V_input->Name = L"input_V_input";
			this->input_V_input->Size = System::Drawing::Size(66, 27);
			this->input_V_input->TabIndex = 0;
			this->input_V_input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			// 
			// input_force_velocity
			// 
			this->input_force_velocity->AutoSize = true;
			this->input_force_velocity->Checked = true;
			this->input_force_velocity->CheckState = System::Windows::Forms::CheckState::Checked;
			this->input_force_velocity->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_force_velocity->Location = System::Drawing::Point(6, 35);
			this->input_force_velocity->Name = L"input_force_velocity";
			this->input_force_velocity->Size = System::Drawing::Size(101, 19);
			this->input_force_velocity->TabIndex = 25;
			this->input_force_velocity->Text = L"Velocity input";
			this->input_force_velocity->UseVisualStyleBackColor = true;
			this->input_force_velocity->Click += gcnew System::EventHandler(this, &MyForm::input_force_velocity_Click);
			// 
			// input_steering_input
			// 
			this->input_steering_input->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_steering_input->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_steering_input->FormattingEnabled = true;
			this->input_steering_input->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Steering", L"Straight" });
			this->input_steering_input->Location = System::Drawing::Point(114, 332);
			this->input_steering_input->Name = L"input_steering_input";
			this->input_steering_input->Size = System::Drawing::Size(121, 27);
			this->input_steering_input->TabIndex = 20;
			this->input_steering_input->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::input_steering_input_SelectedIndexChanged);
			// 
			// textBox38
			// 
			this->textBox38->BackColor = System::Drawing::SystemColors::Window;
			this->textBox38->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox38->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox38->Location = System::Drawing::Point(6, 335);
			this->textBox38->Multiline = true;
			this->textBox38->Name = L"textBox38";
			this->textBox38->ReadOnly = true;
			this->textBox38->Size = System::Drawing::Size(102, 30);
			this->textBox38->TabIndex = 19;
			this->textBox38->Text = L"Steering input";
			// 
			// input_pedals_input
			// 
			this->input_pedals_input->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->input_pedals_input->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_pedals_input->FormattingEnabled = true;
			this->input_pedals_input->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Braking", L"Driving", L"Coasting", L"Cruising" });
			this->input_pedals_input->Location = System::Drawing::Point(114, 274);
			this->input_pedals_input->Name = L"input_pedals_input";
			this->input_pedals_input->Size = System::Drawing::Size(121, 27);
			this->input_pedals_input->TabIndex = 18;
			this->input_pedals_input->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::input_pedals_input_SelectedIndexChanged);
			// 
			// textBox37
			// 
			this->textBox37->BackColor = System::Drawing::SystemColors::Window;
			this->textBox37->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox37->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox37->Location = System::Drawing::Point(6, 277);
			this->textBox37->Multiline = true;
			this->textBox37->Name = L"textBox37";
			this->textBox37->ReadOnly = true;
			this->textBox37->Size = System::Drawing::Size(102, 19);
			this->textBox37->TabIndex = 17;
			this->textBox37->Text = L"Pedals input";
			// 
			// textBox26
			// 
			this->textBox26->BackColor = System::Drawing::SystemColors::Window;
			this->textBox26->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox26->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox26->Location = System::Drawing::Point(6, 165);
			this->textBox26->Multiline = true;
			this->textBox26->Name = L"textBox26";
			this->textBox26->ReadOnly = true;
			this->textBox26->Size = System::Drawing::Size(157, 47);
			this->textBox26->TabIndex = 16;
			this->textBox26->Text = L"Steering wheel angle  (δd) [°]";
			// 
			// input_delta_d_deg
			// 
			this->input_delta_d_deg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_delta_d_deg->DecimalPlaces = 2;
			this->input_delta_d_deg->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_delta_d_deg->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->input_delta_d_deg->Location = System::Drawing::Point(169, 175);
			this->input_delta_d_deg->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_delta_d_deg->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_delta_d_deg->Name = L"input_delta_d_deg";
			this->input_delta_d_deg->Size = System::Drawing::Size(66, 27);
			this->input_delta_d_deg->TabIndex = 15;
			this->input_delta_d_deg->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->input_delta_d_deg->ValueChanged += gcnew System::EventHandler(this, &MyForm::input_delta_d_deg_ValueChanged);
			// 
			// textBox31
			// 
			this->textBox31->BackColor = System::Drawing::SystemColors::Window;
			this->textBox31->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox31->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox31->Location = System::Drawing::Point(6, 108);
			this->textBox31->Multiline = true;
			this->textBox31->Name = L"textBox31";
			this->textBox31->ReadOnly = true;
			this->textBox31->Size = System::Drawing::Size(157, 47);
			this->textBox31->TabIndex = 6;
			this->textBox31->Text = L"Chassis slip angle (β) [°]";
			// 
			// input_beta_deg
			// 
			this->input_beta_deg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_beta_deg->DecimalPlaces = 2;
			this->input_beta_deg->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_beta_deg->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
			this->input_beta_deg->Location = System::Drawing::Point(169, 118);
			this->input_beta_deg->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 89, 0, 0, 0 });
			this->input_beta_deg->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 89, 0, 0, System::Int32::MinValue });
			this->input_beta_deg->Name = L"input_beta_deg";
			this->input_beta_deg->Size = System::Drawing::Size(66, 27);
			this->input_beta_deg->TabIndex = 5;
			this->input_beta_deg->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->input_beta_deg->ValueChanged += gcnew System::EventHandler(this, &MyForm::input_beta_deg_ValueChanged);
			// 
			// Display_corner_or_velocity
			// 
			this->Display_corner_or_velocity->BackColor = System::Drawing::SystemColors::Window;
			this->Display_corner_or_velocity->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Display_corner_or_velocity->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Display_corner_or_velocity->ForeColor = System::Drawing::SystemColors::WindowText;
			this->Display_corner_or_velocity->Location = System::Drawing::Point(6, 62);
			this->Display_corner_or_velocity->Multiline = true;
			this->Display_corner_or_velocity->Name = L"Display_corner_or_velocity";
			this->Display_corner_or_velocity->ReadOnly = true;
			this->Display_corner_or_velocity->Size = System::Drawing::Size(157, 20);
			this->Display_corner_or_velocity->TabIndex = 4;
			this->Display_corner_or_velocity->Text = L"Vehicle velocity [km/h]";
			// 
			// input_R
			// 
			this->input_R->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_R->DecimalPlaces = 2;
			this->input_R->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_R->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_R->Location = System::Drawing::Point(169, 60);
			this->input_R->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->input_R->Name = L"input_R";
			this->input_R->Size = System::Drawing::Size(66, 27);
			this->input_R->TabIndex = 3;
			this->input_R->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9125, 0, 0, 196608 });
			// 
			// input_debug_iter
			// 
			this->input_debug_iter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_debug_iter->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_debug_iter->Location = System::Drawing::Point(100, 534);
			this->input_debug_iter->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_debug_iter->Name = L"input_debug_iter";
			this->input_debug_iter->Size = System::Drawing::Size(66, 27);
			this->input_debug_iter->TabIndex = 9;
			this->input_debug_iter->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabPage6);
			this->tabControl2->Controls->Add(this->tabPage7);
			this->tabControl2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl2->Location = System::Drawing::Point(0, 0);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(565, 643);
			this->tabControl2->TabIndex = 0;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->output_r_deg);
			this->tabPage6->Controls->Add(this->output_R);
			this->tabPage6->Controls->Add(this->output_V);
			this->tabPage6->Controls->Add(this->output_bias_now);
			this->tabPage6->Controls->Add(this->output_iter);
			this->tabPage6->Controls->Add(this->output_a_rad);
			this->tabPage6->Controls->Add(this->output_a_lat);
			this->tabPage6->Controls->Add(this->tableLayoutPanel1);
			this->tabPage6->Controls->Add(this->output_M_yaw);
			this->tabPage6->Controls->Add(this->output_F_lat);
			this->tabPage6->Controls->Add(this->output_phi_deg);
			this->tabPage6->Controls->Add(this->output_F_lon);
			this->tabPage6->Controls->Add(this->output_psi_deg);
			this->tabPage6->Controls->Add(this->output_a_lon);
			this->tabPage6->Location = System::Drawing::Point(4, 35);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(557, 604);
			this->tabPage6->TabIndex = 0;
			this->tabPage6->Text = L"Single run";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// output_r_deg
			// 
			this->output_r_deg->AutoSize = true;
			this->output_r_deg->Location = System::Drawing::Point(6, 362);
			this->output_r_deg->Name = L"output_r_deg";
			this->output_r_deg->Size = System::Drawing::Size(85, 26);
			this->output_r_deg->TabIndex = 31;
			this->output_r_deg->Text = L"Yaw rate";
			// 
			// output_R
			// 
			this->output_R->AutoSize = true;
			this->output_R->Location = System::Drawing::Point(365, 496);
			this->output_R->Name = L"output_R";
			this->output_R->Size = System::Drawing::Size(126, 26);
			this->output_R->TabIndex = 30;
			this->output_R->Text = L"Corner radius";
			// 
			// output_V
			// 
			this->output_V->AutoSize = true;
			this->output_V->Location = System::Drawing::Point(365, 466);
			this->output_V->Name = L"output_V";
			this->output_V->Size = System::Drawing::Size(80, 26);
			this->output_V->TabIndex = 26;
			this->output_V->Text = L"Velocity";
			// 
			// output_bias_now
			// 
			this->output_bias_now->AutoSize = true;
			this->output_bias_now->Location = System::Drawing::Point(365, 432);
			this->output_bias_now->Name = L"output_bias_now";
			this->output_bias_now->Size = System::Drawing::Size(46, 26);
			this->output_bias_now->TabIndex = 25;
			this->output_bias_now->Text = L"bias";
			// 
			// output_iter
			// 
			this->output_iter->AutoSize = true;
			this->output_iter->Location = System::Drawing::Point(365, 399);
			this->output_iter->Name = L"output_iter";
			this->output_iter->Size = System::Drawing::Size(41, 26);
			this->output_iter->TabIndex = 24;
			this->output_iter->Text = L"iter";
			// 
			// output_a_rad
			// 
			this->output_a_rad->AutoSize = true;
			this->output_a_rad->Location = System::Drawing::Point(6, 466);
			this->output_a_rad->Name = L"output_a_rad";
			this->output_a_rad->Size = System::Drawing::Size(77, 26);
			this->output_a_rad->TabIndex = 23;
			this->output_a_rad->Text = L"Rad acc";
			// 
			// output_a_lat
			// 
			this->output_a_lat->AutoSize = true;
			this->output_a_lat->Location = System::Drawing::Point(5, 434);
			this->output_a_lat->Name = L"output_a_lat";
			this->output_a_lat->Size = System::Drawing::Size(71, 26);
			this->output_a_lat->TabIndex = 4;
			this->output_a_lat->Text = L"Lat acc";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::White;
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 5;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel1->Controls->Add(this->label6, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label7, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label8, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->label9, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->label10, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label11, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label12, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label13, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label14, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->label15, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->label16, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->label17, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->output_F_z_fl, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->output_F_z_fr, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->output_F_z_rl, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->output_F_z_rr, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->output_F_x_comb_fl, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->output_F_x_comb_fr, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->output_F_x_comb_rl, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->output_F_x_comb_rr, 4, 2);
			this->tableLayoutPanel1->Controls->Add(this->output_F_y_comb_fl, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->output_F_y_comb_fr, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->output_F_y_comb_rl, 3, 3);
			this->tableLayoutPanel1->Controls->Add(this->output_F_y_comb_rr, 4, 3);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lon_fl, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lon_fr, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lon_rl, 3, 4);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lon_rr, 4, 4);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lat_fl, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lat_fr, 2, 5);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lat_rl, 3, 5);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lat_rr, 4, 5);
			this->tableLayoutPanel1->Controls->Add(this->output_kappa_fl, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->output_kappa_fr, 2, 6);
			this->tableLayoutPanel1->Controls->Add(this->output_kappa_rl, 3, 6);
			this->tableLayoutPanel1->Controls->Add(this->output_kappa_rr, 4, 6);
			this->tableLayoutPanel1->Controls->Add(this->output_alpha_fl, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->output_alpha_fr, 2, 7);
			this->tableLayoutPanel1->Controls->Add(this->output_alpha_rl, 3, 7);
			this->tableLayoutPanel1->Controls->Add(this->output_alpha_rr, 4, 7);
			this->tableLayoutPanel1->Controls->Add(this->output_T_fl, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->output_T_fr, 2, 8);
			this->tableLayoutPanel1->Controls->Add(this->output_T_rl, 3, 8);
			this->tableLayoutPanel1->Controls->Add(this->output_T_rr, 4, 8);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Font = (gcnew System::Drawing::Font(L"Calibri", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tableLayoutPanel1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 9;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 11.11111F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(551, 320);
			this->tableLayoutPanel1->TabIndex = 22;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label6->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label6->Location = System::Drawing::Point(114, 1);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(103, 34);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Front Left";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label7->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label7->Location = System::Drawing::Point(224, 1);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(103, 34);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Front Right";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label8->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label8->Location = System::Drawing::Point(334, 1);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(103, 34);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Rear Left";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label9->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label9->Location = System::Drawing::Point(444, 1);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(103, 34);
			this->label9->TabIndex = 3;
			this->label9->Text = L"Rear Right";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label10->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label10->Location = System::Drawing::Point(4, 36);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(103, 34);
			this->label10->TabIndex = 4;
			this->label10->Text = L"Vertical load";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label11->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label11->Location = System::Drawing::Point(4, 71);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(103, 34);
			this->label11->TabIndex = 5;
			this->label11->Text = L"Longitudinal tire force";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label12->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label12->Location = System::Drawing::Point(4, 106);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(103, 34);
			this->label12->TabIndex = 6;
			this->label12->Text = L"Lateral tire force";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label13->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label13->Location = System::Drawing::Point(4, 141);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(103, 34);
			this->label13->TabIndex = 7;
			this->label13->Text = L"Longitudinal chassis force";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label14->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label14->Location = System::Drawing::Point(4, 176);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(103, 34);
			this->label14->TabIndex = 8;
			this->label14->Text = L"Lateral chassis force";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label15->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label15->Location = System::Drawing::Point(4, 211);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(103, 34);
			this->label15->TabIndex = 9;
			this->label15->Text = L"Slip ratio";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label16->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label16->Location = System::Drawing::Point(4, 246);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(103, 34);
			this->label16->TabIndex = 10;
			this->label16->Text = L"Slip angle";
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label17->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->label17->Location = System::Drawing::Point(4, 281);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(103, 38);
			this->label17->TabIndex = 11;
			this->label17->Text = L"Torque";
			this->label17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_z_fl
			// 
			this->output_F_z_fl->AutoSize = true;
			this->output_F_z_fl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_z_fl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_z_fl->Location = System::Drawing::Point(114, 36);
			this->output_F_z_fl->Name = L"output_F_z_fl";
			this->output_F_z_fl->Size = System::Drawing::Size(103, 34);
			this->output_F_z_fl->TabIndex = 12;
			this->output_F_z_fl->Text = L"OUTPUT";
			this->output_F_z_fl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_z_fr
			// 
			this->output_F_z_fr->AutoSize = true;
			this->output_F_z_fr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_z_fr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_z_fr->Location = System::Drawing::Point(224, 36);
			this->output_F_z_fr->Name = L"output_F_z_fr";
			this->output_F_z_fr->Size = System::Drawing::Size(103, 34);
			this->output_F_z_fr->TabIndex = 13;
			this->output_F_z_fr->Text = L"OUTPUT";
			this->output_F_z_fr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_z_rl
			// 
			this->output_F_z_rl->AutoSize = true;
			this->output_F_z_rl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_z_rl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_z_rl->Location = System::Drawing::Point(334, 36);
			this->output_F_z_rl->Name = L"output_F_z_rl";
			this->output_F_z_rl->Size = System::Drawing::Size(103, 34);
			this->output_F_z_rl->TabIndex = 14;
			this->output_F_z_rl->Text = L"OUTPUT";
			this->output_F_z_rl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_z_rr
			// 
			this->output_F_z_rr->AutoSize = true;
			this->output_F_z_rr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_z_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_z_rr->Location = System::Drawing::Point(444, 36);
			this->output_F_z_rr->Name = L"output_F_z_rr";
			this->output_F_z_rr->Size = System::Drawing::Size(103, 34);
			this->output_F_z_rr->TabIndex = 15;
			this->output_F_z_rr->Text = L"OUTPUT";
			this->output_F_z_rr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_x_comb_fl
			// 
			this->output_F_x_comb_fl->AutoSize = true;
			this->output_F_x_comb_fl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_x_comb_fl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_x_comb_fl->Location = System::Drawing::Point(114, 71);
			this->output_F_x_comb_fl->Name = L"output_F_x_comb_fl";
			this->output_F_x_comb_fl->Size = System::Drawing::Size(103, 34);
			this->output_F_x_comb_fl->TabIndex = 16;
			this->output_F_x_comb_fl->Text = L"OUTPUT";
			this->output_F_x_comb_fl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_x_comb_fr
			// 
			this->output_F_x_comb_fr->AutoSize = true;
			this->output_F_x_comb_fr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_x_comb_fr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_x_comb_fr->Location = System::Drawing::Point(224, 71);
			this->output_F_x_comb_fr->Name = L"output_F_x_comb_fr";
			this->output_F_x_comb_fr->Size = System::Drawing::Size(103, 34);
			this->output_F_x_comb_fr->TabIndex = 17;
			this->output_F_x_comb_fr->Text = L"OUTPUT";
			this->output_F_x_comb_fr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_x_comb_rl
			// 
			this->output_F_x_comb_rl->AutoSize = true;
			this->output_F_x_comb_rl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_x_comb_rl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_x_comb_rl->Location = System::Drawing::Point(334, 71);
			this->output_F_x_comb_rl->Name = L"output_F_x_comb_rl";
			this->output_F_x_comb_rl->Size = System::Drawing::Size(103, 34);
			this->output_F_x_comb_rl->TabIndex = 18;
			this->output_F_x_comb_rl->Text = L"OUTPUT";
			this->output_F_x_comb_rl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_x_comb_rr
			// 
			this->output_F_x_comb_rr->AutoSize = true;
			this->output_F_x_comb_rr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_x_comb_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_x_comb_rr->Location = System::Drawing::Point(444, 71);
			this->output_F_x_comb_rr->Name = L"output_F_x_comb_rr";
			this->output_F_x_comb_rr->Size = System::Drawing::Size(103, 34);
			this->output_F_x_comb_rr->TabIndex = 19;
			this->output_F_x_comb_rr->Text = L"OUTPUT";
			this->output_F_x_comb_rr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_y_comb_fl
			// 
			this->output_F_y_comb_fl->AutoSize = true;
			this->output_F_y_comb_fl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_y_comb_fl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_y_comb_fl->Location = System::Drawing::Point(114, 106);
			this->output_F_y_comb_fl->Name = L"output_F_y_comb_fl";
			this->output_F_y_comb_fl->Size = System::Drawing::Size(103, 34);
			this->output_F_y_comb_fl->TabIndex = 20;
			this->output_F_y_comb_fl->Text = L"OUTPUT";
			this->output_F_y_comb_fl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_y_comb_fr
			// 
			this->output_F_y_comb_fr->AutoSize = true;
			this->output_F_y_comb_fr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_y_comb_fr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_y_comb_fr->Location = System::Drawing::Point(224, 106);
			this->output_F_y_comb_fr->Name = L"output_F_y_comb_fr";
			this->output_F_y_comb_fr->Size = System::Drawing::Size(103, 34);
			this->output_F_y_comb_fr->TabIndex = 21;
			this->output_F_y_comb_fr->Text = L"OUTPUT";
			this->output_F_y_comb_fr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_y_comb_rl
			// 
			this->output_F_y_comb_rl->AutoSize = true;
			this->output_F_y_comb_rl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_y_comb_rl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_y_comb_rl->Location = System::Drawing::Point(334, 106);
			this->output_F_y_comb_rl->Name = L"output_F_y_comb_rl";
			this->output_F_y_comb_rl->Size = System::Drawing::Size(103, 34);
			this->output_F_y_comb_rl->TabIndex = 22;
			this->output_F_y_comb_rl->Text = L"OUTPUT";
			this->output_F_y_comb_rl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_y_comb_rr
			// 
			this->output_F_y_comb_rr->AutoSize = true;
			this->output_F_y_comb_rr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_y_comb_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_y_comb_rr->Location = System::Drawing::Point(444, 106);
			this->output_F_y_comb_rr->Name = L"output_F_y_comb_rr";
			this->output_F_y_comb_rr->Size = System::Drawing::Size(103, 34);
			this->output_F_y_comb_rr->TabIndex = 23;
			this->output_F_y_comb_rr->Text = L"OUTPUT";
			this->output_F_y_comb_rr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lon_fl
			// 
			this->output_F_lon_fl->AutoSize = true;
			this->output_F_lon_fl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lon_fl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lon_fl->Location = System::Drawing::Point(114, 141);
			this->output_F_lon_fl->Name = L"output_F_lon_fl";
			this->output_F_lon_fl->Size = System::Drawing::Size(103, 34);
			this->output_F_lon_fl->TabIndex = 24;
			this->output_F_lon_fl->Text = L"OUTPUT";
			this->output_F_lon_fl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lon_fr
			// 
			this->output_F_lon_fr->AutoSize = true;
			this->output_F_lon_fr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lon_fr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lon_fr->Location = System::Drawing::Point(224, 141);
			this->output_F_lon_fr->Name = L"output_F_lon_fr";
			this->output_F_lon_fr->Size = System::Drawing::Size(103, 34);
			this->output_F_lon_fr->TabIndex = 25;
			this->output_F_lon_fr->Text = L"OUTPUT";
			this->output_F_lon_fr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lon_rl
			// 
			this->output_F_lon_rl->AutoSize = true;
			this->output_F_lon_rl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lon_rl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lon_rl->Location = System::Drawing::Point(334, 141);
			this->output_F_lon_rl->Name = L"output_F_lon_rl";
			this->output_F_lon_rl->Size = System::Drawing::Size(103, 34);
			this->output_F_lon_rl->TabIndex = 26;
			this->output_F_lon_rl->Text = L"OUTPUT";
			this->output_F_lon_rl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lon_rr
			// 
			this->output_F_lon_rr->AutoSize = true;
			this->output_F_lon_rr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lon_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lon_rr->Location = System::Drawing::Point(444, 141);
			this->output_F_lon_rr->Name = L"output_F_lon_rr";
			this->output_F_lon_rr->Size = System::Drawing::Size(103, 34);
			this->output_F_lon_rr->TabIndex = 27;
			this->output_F_lon_rr->Text = L"OUTPUT";
			this->output_F_lon_rr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lat_fl
			// 
			this->output_F_lat_fl->AutoSize = true;
			this->output_F_lat_fl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lat_fl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lat_fl->Location = System::Drawing::Point(114, 176);
			this->output_F_lat_fl->Name = L"output_F_lat_fl";
			this->output_F_lat_fl->Size = System::Drawing::Size(103, 34);
			this->output_F_lat_fl->TabIndex = 28;
			this->output_F_lat_fl->Text = L"OUTPUT";
			this->output_F_lat_fl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lat_fr
			// 
			this->output_F_lat_fr->AutoSize = true;
			this->output_F_lat_fr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lat_fr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lat_fr->Location = System::Drawing::Point(224, 176);
			this->output_F_lat_fr->Name = L"output_F_lat_fr";
			this->output_F_lat_fr->Size = System::Drawing::Size(103, 34);
			this->output_F_lat_fr->TabIndex = 29;
			this->output_F_lat_fr->Text = L"OUTPUT";
			this->output_F_lat_fr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lat_rl
			// 
			this->output_F_lat_rl->AutoSize = true;
			this->output_F_lat_rl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lat_rl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lat_rl->Location = System::Drawing::Point(334, 176);
			this->output_F_lat_rl->Name = L"output_F_lat_rl";
			this->output_F_lat_rl->Size = System::Drawing::Size(103, 34);
			this->output_F_lat_rl->TabIndex = 30;
			this->output_F_lat_rl->Text = L"OUTPUT";
			this->output_F_lat_rl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lat_rr
			// 
			this->output_F_lat_rr->AutoSize = true;
			this->output_F_lat_rr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lat_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lat_rr->Location = System::Drawing::Point(444, 176);
			this->output_F_lat_rr->Name = L"output_F_lat_rr";
			this->output_F_lat_rr->Size = System::Drawing::Size(103, 34);
			this->output_F_lat_rr->TabIndex = 31;
			this->output_F_lat_rr->Text = L"OUTPUT";
			this->output_F_lat_rr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_kappa_fl
			// 
			this->output_kappa_fl->AutoSize = true;
			this->output_kappa_fl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_kappa_fl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_kappa_fl->Location = System::Drawing::Point(114, 211);
			this->output_kappa_fl->Name = L"output_kappa_fl";
			this->output_kappa_fl->Size = System::Drawing::Size(103, 34);
			this->output_kappa_fl->TabIndex = 32;
			this->output_kappa_fl->Text = L"OUTPUT";
			this->output_kappa_fl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_kappa_fr
			// 
			this->output_kappa_fr->AutoSize = true;
			this->output_kappa_fr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_kappa_fr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_kappa_fr->Location = System::Drawing::Point(224, 211);
			this->output_kappa_fr->Name = L"output_kappa_fr";
			this->output_kappa_fr->Size = System::Drawing::Size(103, 34);
			this->output_kappa_fr->TabIndex = 33;
			this->output_kappa_fr->Text = L"OUTPUT";
			this->output_kappa_fr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_kappa_rl
			// 
			this->output_kappa_rl->AutoSize = true;
			this->output_kappa_rl->BackColor = System::Drawing::Color::Transparent;
			this->output_kappa_rl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_kappa_rl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_kappa_rl->Location = System::Drawing::Point(334, 211);
			this->output_kappa_rl->Name = L"output_kappa_rl";
			this->output_kappa_rl->Size = System::Drawing::Size(103, 34);
			this->output_kappa_rl->TabIndex = 34;
			this->output_kappa_rl->Text = L"OUTPUT";
			this->output_kappa_rl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_kappa_rr
			// 
			this->output_kappa_rr->AutoSize = true;
			this->output_kappa_rr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_kappa_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_kappa_rr->Location = System::Drawing::Point(444, 211);
			this->output_kappa_rr->Name = L"output_kappa_rr";
			this->output_kappa_rr->Size = System::Drawing::Size(103, 34);
			this->output_kappa_rr->TabIndex = 35;
			this->output_kappa_rr->Text = L"OUTPUT";
			this->output_kappa_rr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_alpha_fl
			// 
			this->output_alpha_fl->AutoSize = true;
			this->output_alpha_fl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_alpha_fl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_alpha_fl->Location = System::Drawing::Point(114, 246);
			this->output_alpha_fl->Name = L"output_alpha_fl";
			this->output_alpha_fl->Size = System::Drawing::Size(103, 34);
			this->output_alpha_fl->TabIndex = 36;
			this->output_alpha_fl->Text = L"OUTPUT";
			this->output_alpha_fl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_alpha_fr
			// 
			this->output_alpha_fr->AutoSize = true;
			this->output_alpha_fr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_alpha_fr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_alpha_fr->Location = System::Drawing::Point(224, 246);
			this->output_alpha_fr->Name = L"output_alpha_fr";
			this->output_alpha_fr->Size = System::Drawing::Size(103, 34);
			this->output_alpha_fr->TabIndex = 37;
			this->output_alpha_fr->Text = L"OUTPUT";
			this->output_alpha_fr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_alpha_rl
			// 
			this->output_alpha_rl->AutoSize = true;
			this->output_alpha_rl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_alpha_rl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_alpha_rl->Location = System::Drawing::Point(334, 246);
			this->output_alpha_rl->Name = L"output_alpha_rl";
			this->output_alpha_rl->Size = System::Drawing::Size(103, 34);
			this->output_alpha_rl->TabIndex = 38;
			this->output_alpha_rl->Text = L"OUTPUT";
			this->output_alpha_rl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_alpha_rr
			// 
			this->output_alpha_rr->AutoSize = true;
			this->output_alpha_rr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_alpha_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_alpha_rr->Location = System::Drawing::Point(444, 246);
			this->output_alpha_rr->Name = L"output_alpha_rr";
			this->output_alpha_rr->Size = System::Drawing::Size(103, 34);
			this->output_alpha_rr->TabIndex = 39;
			this->output_alpha_rr->Text = L"OUTPUT";
			this->output_alpha_rr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_T_fl
			// 
			this->output_T_fl->AutoSize = true;
			this->output_T_fl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_T_fl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_T_fl->Location = System::Drawing::Point(114, 281);
			this->output_T_fl->Name = L"output_T_fl";
			this->output_T_fl->Size = System::Drawing::Size(103, 38);
			this->output_T_fl->TabIndex = 40;
			this->output_T_fl->Text = L"OUTPUT";
			this->output_T_fl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_T_fr
			// 
			this->output_T_fr->AutoSize = true;
			this->output_T_fr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_T_fr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_T_fr->Location = System::Drawing::Point(224, 281);
			this->output_T_fr->Name = L"output_T_fr";
			this->output_T_fr->Size = System::Drawing::Size(103, 38);
			this->output_T_fr->TabIndex = 41;
			this->output_T_fr->Text = L"OUTPUT";
			this->output_T_fr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_T_rl
			// 
			this->output_T_rl->AutoSize = true;
			this->output_T_rl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_T_rl->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_T_rl->Location = System::Drawing::Point(334, 281);
			this->output_T_rl->Name = L"output_T_rl";
			this->output_T_rl->Size = System::Drawing::Size(103, 38);
			this->output_T_rl->TabIndex = 42;
			this->output_T_rl->Text = L"OUTPUT";
			this->output_T_rl->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_T_rr
			// 
			this->output_T_rr->AutoSize = true;
			this->output_T_rr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_T_rr->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_T_rr->Location = System::Drawing::Point(444, 281);
			this->output_T_rr->Name = L"output_T_rr";
			this->output_T_rr->Size = System::Drawing::Size(103, 38);
			this->output_T_rr->TabIndex = 43;
			this->output_T_rr->Text = L"OUTPUT";
			this->output_T_rr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_M_yaw
			// 
			this->output_M_yaw->AutoSize = true;
			this->output_M_yaw->Location = System::Drawing::Point(6, 326);
			this->output_M_yaw->Name = L"output_M_yaw";
			this->output_M_yaw->Size = System::Drawing::Size(124, 26);
			this->output_M_yaw->TabIndex = 1;
			this->output_M_yaw->Text = L"Yaw moment";
			// 
			// output_F_lat
			// 
			this->output_F_lat->AutoSize = true;
			this->output_F_lat->Location = System::Drawing::Point(6, 536);
			this->output_F_lat->Name = L"output_F_lat";
			this->output_F_lat->Size = System::Drawing::Size(86, 26);
			this->output_F_lat->TabIndex = 2;
			this->output_F_lat->Text = L"Lat force";
			// 
			// output_phi_deg
			// 
			this->output_phi_deg->AutoSize = true;
			this->output_phi_deg->Location = System::Drawing::Point(365, 364);
			this->output_phi_deg->Name = L"output_phi_deg";
			this->output_phi_deg->Size = System::Drawing::Size(106, 26);
			this->output_phi_deg->TabIndex = 7;
			this->output_phi_deg->Text = L"pitch angle";
			// 
			// output_F_lon
			// 
			this->output_F_lon->AutoSize = true;
			this->output_F_lon->Location = System::Drawing::Point(6, 501);
			this->output_F_lon->Name = L"output_F_lon";
			this->output_F_lon->Size = System::Drawing::Size(91, 26);
			this->output_F_lon->TabIndex = 3;
			this->output_F_lon->Text = L"Lon force";
			// 
			// output_psi_deg
			// 
			this->output_psi_deg->AutoSize = true;
			this->output_psi_deg->Location = System::Drawing::Point(365, 326);
			this->output_psi_deg->Name = L"output_psi_deg";
			this->output_psi_deg->Size = System::Drawing::Size(91, 26);
			this->output_psi_deg->TabIndex = 6;
			this->output_psi_deg->Text = L"roll angle";
			// 
			// output_a_lon
			// 
			this->output_a_lon->AutoSize = true;
			this->output_a_lon->Location = System::Drawing::Point(6, 399);
			this->output_a_lon->Name = L"output_a_lon";
			this->output_a_lon->Size = System::Drawing::Size(76, 26);
			this->output_a_lon->TabIndex = 5;
			this->output_a_lon->Text = L"Lon acc";
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->splitContainer4);
			this->tabPage7->Location = System::Drawing::Point(4, 22);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(557, 617);
			this->tabPage7->TabIndex = 1;
			this->tabPage7->Text = L"YMD";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// splitContainer4
			// 
			this->splitContainer4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer4->Location = System::Drawing::Point(3, 3);
			this->splitContainer4->Name = L"splitContainer4";
			this->splitContainer4->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer4.Panel1
			// 
			this->splitContainer4->Panel1->Controls->Add(this->tableLayoutPanel2);
			// 
			// splitContainer4.Panel2
			// 
			this->splitContainer4->Panel2->Controls->Add(this->YMD);
			this->splitContainer4->Size = System::Drawing::Size(551, 611);
			this->splitContainer4->SplitterDistance = 94;
			this->splitContainer4->TabIndex = 1;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 6;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.66667F)));
			this->tableLayoutPanel2->Controls->Add(this->input_con_delta_d, 5, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox40, 4, 1);
			this->tableLayoutPanel2->Controls->Add(this->input_con_beta, 5, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBox39, 4, 0);
			this->tableLayoutPanel2->Controls->Add(this->input_max_delta_d, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->input_num_beta, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->input_num_delta_d, 3, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox182, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox180, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->input_max_beta, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBox183, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox181, 2, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(551, 94);
			this->tableLayoutPanel2->TabIndex = 13;
			// 
			// input_con_delta_d
			// 
			this->input_con_delta_d->DecimalPlaces = 2;
			this->input_con_delta_d->Dock = System::Windows::Forms::DockStyle::Fill;
			this->input_con_delta_d->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_con_delta_d->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_con_delta_d->Location = System::Drawing::Point(458, 50);
			this->input_con_delta_d->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->input_con_delta_d->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->input_con_delta_d->Name = L"input_con_delta_d";
			this->input_con_delta_d->Size = System::Drawing::Size(90, 27);
			this->input_con_delta_d->TabIndex = 16;
			this->input_con_delta_d->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->input_con_delta_d->Visible = false;
			// 
			// textBox40
			// 
			this->textBox40->BackColor = System::Drawing::SystemColors::Window;
			this->textBox40->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox40->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox40->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox40->Location = System::Drawing::Point(367, 50);
			this->textBox40->Multiline = true;
			this->textBox40->Name = L"textBox40";
			this->textBox40->ReadOnly = true;
			this->textBox40->Size = System::Drawing::Size(85, 41);
			this->textBox40->TabIndex = 15;
			this->textBox40->Text = L"Concentration of δ isolines";
			this->textBox40->Visible = false;
			// 
			// input_con_beta
			// 
			this->input_con_beta->DecimalPlaces = 2;
			this->input_con_beta->Dock = System::Windows::Forms::DockStyle::Fill;
			this->input_con_beta->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_con_beta->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_con_beta->Location = System::Drawing::Point(458, 3);
			this->input_con_beta->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->input_con_beta->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->input_con_beta->Name = L"input_con_beta";
			this->input_con_beta->Size = System::Drawing::Size(90, 27);
			this->input_con_beta->TabIndex = 14;
			this->input_con_beta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->input_con_beta->Visible = false;
			// 
			// textBox39
			// 
			this->textBox39->BackColor = System::Drawing::SystemColors::Window;
			this->textBox39->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox39->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox39->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox39->Location = System::Drawing::Point(367, 3);
			this->textBox39->Multiline = true;
			this->textBox39->Name = L"textBox39";
			this->textBox39->ReadOnly = true;
			this->textBox39->Size = System::Drawing::Size(85, 41);
			this->textBox39->TabIndex = 13;
			this->textBox39->Text = L"Concentration of β isolines";
			this->textBox39->Visible = false;
			// 
			// input_max_delta_d
			// 
			this->input_max_delta_d->DecimalPlaces = 2;
			this->input_max_delta_d->Dock = System::Windows::Forms::DockStyle::Fill;
			this->input_max_delta_d->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_max_delta_d->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->input_max_delta_d->Location = System::Drawing::Point(94, 50);
			this->input_max_delta_d->Name = L"input_max_delta_d";
			this->input_max_delta_d->Size = System::Drawing::Size(85, 27);
			this->input_max_delta_d->TabIndex = 9;
			this->input_max_delta_d->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 40, 0, 0, 0 });
			this->input_max_delta_d->ValueChanged += gcnew System::EventHandler(this, &MyForm::input_max_delta_d_ValueChanged);
			// 
			// input_num_beta
			// 
			this->input_num_beta->BackColor = System::Drawing::SystemColors::Window;
			this->input_num_beta->Dock = System::Windows::Forms::DockStyle::Fill;
			this->input_num_beta->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_num_beta->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->input_num_beta->Location = System::Drawing::Point(276, 3);
			this->input_num_beta->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 27, 0, 0, 0 });
			this->input_num_beta->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->input_num_beta->Name = L"input_num_beta";
			this->input_num_beta->ReadOnly = true;
			this->input_num_beta->Size = System::Drawing::Size(85, 27);
			this->input_num_beta->TabIndex = 7;
			this->input_num_beta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			this->input_num_beta->ValueChanged += gcnew System::EventHandler(this, &MyForm::input_num_beta_ValueChanged);
			// 
			// input_num_delta_d
			// 
			this->input_num_delta_d->BackColor = System::Drawing::SystemColors::Window;
			this->input_num_delta_d->Dock = System::Windows::Forms::DockStyle::Fill;
			this->input_num_delta_d->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_num_delta_d->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->input_num_delta_d->Location = System::Drawing::Point(276, 50);
			this->input_num_delta_d->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 27, 0, 0, 0 });
			this->input_num_delta_d->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->input_num_delta_d->Name = L"input_num_delta_d";
			this->input_num_delta_d->ReadOnly = true;
			this->input_num_delta_d->Size = System::Drawing::Size(85, 27);
			this->input_num_delta_d->TabIndex = 11;
			this->input_num_delta_d->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 0 });
			this->input_num_delta_d->ValueChanged += gcnew System::EventHandler(this, &MyForm::input_num_delta_d_ValueChanged);
			// 
			// textBox182
			// 
			this->textBox182->BackColor = System::Drawing::SystemColors::Window;
			this->textBox182->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox182->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox182->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox182->Location = System::Drawing::Point(185, 50);
			this->textBox182->Multiline = true;
			this->textBox182->Name = L"textBox182";
			this->textBox182->ReadOnly = true;
			this->textBox182->Size = System::Drawing::Size(85, 41);
			this->textBox182->TabIndex = 12;
			this->textBox182->Text = L"Number of δd isolines";
			// 
			// textBox180
			// 
			this->textBox180->BackColor = System::Drawing::SystemColors::Window;
			this->textBox180->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox180->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox180->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox180->Location = System::Drawing::Point(3, 3);
			this->textBox180->Multiline = true;
			this->textBox180->Name = L"textBox180";
			this->textBox180->ReadOnly = true;
			this->textBox180->Size = System::Drawing::Size(85, 41);
			this->textBox180->TabIndex = 6;
			this->textBox180->Text = L"Maximum β [°]";
			// 
			// input_max_beta
			// 
			this->input_max_beta->DecimalPlaces = 2;
			this->input_max_beta->Dock = System::Windows::Forms::DockStyle::Fill;
			this->input_max_beta->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_max_beta->Location = System::Drawing::Point(94, 3);
			this->input_max_beta->Name = L"input_max_beta";
			this->input_max_beta->Size = System::Drawing::Size(85, 27);
			this->input_max_beta->TabIndex = 5;
			this->input_max_beta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_max_beta->ValueChanged += gcnew System::EventHandler(this, &MyForm::input_max_beta_ValueChanged);
			// 
			// textBox183
			// 
			this->textBox183->BackColor = System::Drawing::SystemColors::Window;
			this->textBox183->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox183->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox183->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox183->Location = System::Drawing::Point(3, 50);
			this->textBox183->Multiline = true;
			this->textBox183->Name = L"textBox183";
			this->textBox183->ReadOnly = true;
			this->textBox183->Size = System::Drawing::Size(85, 41);
			this->textBox183->TabIndex = 10;
			this->textBox183->Text = L"Maximum δd [°]";
			// 
			// textBox181
			// 
			this->textBox181->BackColor = System::Drawing::SystemColors::Window;
			this->textBox181->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox181->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox181->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox181->Location = System::Drawing::Point(185, 3);
			this->textBox181->Multiline = true;
			this->textBox181->Name = L"textBox181";
			this->textBox181->ReadOnly = true;
			this->textBox181->Size = System::Drawing::Size(85, 41);
			this->textBox181->TabIndex = 8;
			this->textBox181->Text = L"Number of β isolines";
			// 
			// YMD
			// 
			chartArea1->BackColor = System::Drawing::Color::White;
			chartArea1->Name = L"ChartArea1";
			this->YMD->ChartAreas->Add(chartArea1);
			this->YMD->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->YMD->Legends->Add(legend1);
			this->YMD->Location = System::Drawing::Point(0, 0);
			this->YMD->Name = L"YMD";
			this->YMD->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Bright;
			this->YMD->Size = System::Drawing::Size(551, 513);
			this->YMD->TabIndex = 0;
			this->YMD->Text = L"chart1";
			title1->Name = L"Title1";
			this->YMD->Titles->Add(title1);
			// 
			// debugPage
			// 
			this->debugPage->Controls->Add(this->output_iter_total);
			this->debugPage->Controls->Add(this->output_golden_total);
			this->debugPage->Controls->Add(this->output_golden_single);
			this->debugPage->Controls->Add(this->output_brents_total);
			this->debugPage->Controls->Add(this->output_brents_single);
			this->debugPage->Controls->Add(this->output_debug4);
			this->debugPage->Controls->Add(this->output_debug3);
			this->debugPage->Controls->Add(this->output_debug2);
			this->debugPage->Controls->Add(this->output_debug1);
			this->debugPage->Location = System::Drawing::Point(4, 22);
			this->debugPage->Name = L"debugPage";
			this->debugPage->Padding = System::Windows::Forms::Padding(3);
			this->debugPage->Size = System::Drawing::Size(1075, 649);
			this->debugPage->TabIndex = 5;
			this->debugPage->Text = L"Debug";
			this->debugPage->UseVisualStyleBackColor = true;
			// 
			// output_iter_total
			// 
			this->output_iter_total->AutoSize = true;
			this->output_iter_total->Location = System::Drawing::Point(39, 284);
			this->output_iter_total->Name = L"output_iter_total";
			this->output_iter_total->Size = System::Drawing::Size(72, 26);
			this->output_iter_total->TabIndex = 8;
			this->output_iter_total->Text = L"DEBUG";
			// 
			// output_golden_total
			// 
			this->output_golden_total->AutoSize = true;
			this->output_golden_total->Location = System::Drawing::Point(39, 537);
			this->output_golden_total->Name = L"output_golden_total";
			this->output_golden_total->Size = System::Drawing::Size(72, 26);
			this->output_golden_total->TabIndex = 7;
			this->output_golden_total->Text = L"DEBUG";
			// 
			// output_golden_single
			// 
			this->output_golden_single->AutoSize = true;
			this->output_golden_single->Location = System::Drawing::Point(39, 472);
			this->output_golden_single->Name = L"output_golden_single";
			this->output_golden_single->Size = System::Drawing::Size(72, 26);
			this->output_golden_single->TabIndex = 6;
			this->output_golden_single->Text = L"DEBUG";
			// 
			// output_brents_total
			// 
			this->output_brents_total->AutoSize = true;
			this->output_brents_total->Location = System::Drawing::Point(39, 407);
			this->output_brents_total->Name = L"output_brents_total";
			this->output_brents_total->Size = System::Drawing::Size(72, 26);
			this->output_brents_total->TabIndex = 5;
			this->output_brents_total->Text = L"DEBUG";
			// 
			// output_brents_single
			// 
			this->output_brents_single->AutoSize = true;
			this->output_brents_single->Location = System::Drawing::Point(39, 351);
			this->output_brents_single->Name = L"output_brents_single";
			this->output_brents_single->Size = System::Drawing::Size(72, 26);
			this->output_brents_single->TabIndex = 4;
			this->output_brents_single->Text = L"DEBUG";
			// 
			// output_debug4
			// 
			this->output_debug4->AutoSize = true;
			this->output_debug4->Location = System::Drawing::Point(39, 203);
			this->output_debug4->Name = L"output_debug4";
			this->output_debug4->Size = System::Drawing::Size(72, 26);
			this->output_debug4->TabIndex = 3;
			this->output_debug4->Text = L"DEBUG";
			// 
			// output_debug3
			// 
			this->output_debug3->AutoSize = true;
			this->output_debug3->Location = System::Drawing::Point(39, 151);
			this->output_debug3->Name = L"output_debug3";
			this->output_debug3->Size = System::Drawing::Size(72, 26);
			this->output_debug3->TabIndex = 2;
			this->output_debug3->Text = L"DEBUG";
			// 
			// output_debug2
			// 
			this->output_debug2->AutoSize = true;
			this->output_debug2->Location = System::Drawing::Point(39, 95);
			this->output_debug2->Name = L"output_debug2";
			this->output_debug2->Size = System::Drawing::Size(72, 26);
			this->output_debug2->TabIndex = 1;
			this->output_debug2->Text = L"DEBUG";
			// 
			// output_debug1
			// 
			this->output_debug1->AutoSize = true;
			this->output_debug1->Location = System::Drawing::Point(39, 43);
			this->output_debug1->Name = L"output_debug1";
			this->output_debug1->Size = System::Drawing::Size(72, 26);
			this->output_debug1->TabIndex = 0;
			this->output_debug1->Text = L"DEBUG";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(457, 313);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 26);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(449, 305);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 26);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(465, 321);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 26);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(473, 329);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 26);
			this->label4->TabIndex = 5;
			this->label4->Text = L"label1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(481, 337);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(64, 26);
			this->label5->TabIndex = 6;
			this->label5->Text = L"label1";
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->panel1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tabControl1);
			this->splitContainer1->Size = System::Drawing::Size(1184, 675);
			this->splitContainer1->SplitterDistance = 97;
			this->splitContainer1->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1184, 675);
			this->Controls->Add(this->splitContainer1);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Software do diabo 1.0";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing_1);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox23->ResumeLayout(false);
			this->groupBox23->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->groupBox14->ResumeLayout(false);
			this->groupBox13->ResumeLayout(false);
			this->groupBox13->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_K_T))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_z_o))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_b_rr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_a_rr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_u))->EndInit();
			this->groupBox12->ResumeLayout(false);
			this->groupBox12->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vx2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vx1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Hx2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Hx1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Kx3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Kx2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Kx1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ex4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ex3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ex2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ex1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dx3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dx2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dx1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Cx1))->EndInit();
			this->groupBox11->ResumeLayout(false);
			this->groupBox11->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vy4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vy3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vy2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Vy1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Hy3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Hy2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Hy1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ky3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ky2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ky1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ey4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ey3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ey2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Ey1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dy3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dy2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Dy1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_Cy1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabControl4->ResumeLayout(false);
			this->tabPage10->ResumeLayout(false);
			this->groupBox16->ResumeLayout(false);
			this->groupBox16->PerformLayout();
			this->groupBox15->ResumeLayout(false);
			this->groupBox15->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_fl))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_rr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_fr))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_rl))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_t_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_t_f))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_L))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_CG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_y))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_x))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m))->EndInit();
			this->tabPage13->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_k_lock_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_preload_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_bTBR_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_dTBR_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_k_lock_f))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_preload_f))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_bTBR_f))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_diff_dTBR_f))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_k_lock_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_preload_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_bTBR_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_dTBR_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_k_lock_f))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_preload_f))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_bTBR_f))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_dTBR_f))->EndInit();
			this->tabPage11->ResumeLayout(false);
			this->groupBox21->ResumeLayout(false);
			this->groupBox21->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_y_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_y_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_y_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_z_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_z_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_z_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_drag_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_y_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_y_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_y_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_x_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_x_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_x_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_F_down_2))->EndInit();
			this->tabPage12->ResumeLayout(false);
			this->groupBox22->ResumeLayout(false);
			this->groupBox22->PerformLayout();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->spring_stiffness))->EndInit();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_p_C_dist))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_p_C_deg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_r_C_dist))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_r_C_deg))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_susp_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_susp_f))->EndInit();
			this->tabPage14->ResumeLayout(false);
			this->groupBox20->ResumeLayout(false);
			this->groupBox20->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_r_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_r_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_f_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_f_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_r_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_r_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_f_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_f_2))->EndInit();
			this->groupBox17->ResumeLayout(false);
			this->groupBox17->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_r_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_r_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_r_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_f_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_f_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_p_f_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_o_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_o_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_o_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_i_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_i_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_n_p_i_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_o_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_o_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_o_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_i_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_i_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_p_i_2))->EndInit();
			this->groupBox19->ResumeLayout(false);
			this->groupBox19->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bs_r_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bs_r_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bs_f_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bs_f_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_ackermann_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_ackermann_2))->EndInit();
			this->groupBox18->ResumeLayout(false);
			this->groupBox18->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_r_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_r_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_r_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_f_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_f_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_arb_f_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_r_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_r_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_r_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_f_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_f_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_MR_s_f_2))->EndInit();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_r_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_r_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_r_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_f_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_f_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_q_r_f_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_r_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_r_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_r_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_f_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_f_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_off_r_f_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_r_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_r_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_r_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_f_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_f_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_r_f_2))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_DB_input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_gamma_r_static))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_BB_input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_gamma_f_static))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_delta_r_static))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_delta_f_static))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_DB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fake_BB))->EndInit();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_a_lon_des))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_V_input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_delta_d_deg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_beta_deg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_R))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_debug_iter))->EndInit();
			this->tabControl2->ResumeLayout(false);
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tabPage7->ResumeLayout(false);
			this->splitContainer4->Panel1->ResumeLayout(false);
			this->splitContainer4->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer4))->EndInit();
			this->splitContainer4->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_con_delta_d))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_con_beta))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_max_delta_d))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_num_beta))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_num_delta_d))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_max_beta))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->YMD))->EndInit();
			this->debugPage->ResumeLayout(false);
			this->debugPage->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}

		void MyForm::read_inputs()
		{
			//Simulation inputs
			vehicle_inputs->V_input = System::Convert::ToDouble(input_V_input->Value);
			vehicle_inputs->R = System::Convert::ToDouble(input_R->Value);
			vehicle_inputs->beta_deg = System::Convert::ToDouble(input_beta_deg->Value);
			vehicle_inputs->delta_d_deg = System::Convert::ToDouble(input_delta_d_deg->Value);
			vehicle_inputs->delta_f_static = System::Convert::ToDouble(input_delta_f_static->Value);
			vehicle_inputs->delta_r_static = System::Convert::ToDouble(input_delta_r_static->Value);
			vehicle_inputs->gamma_f_static = System::Convert::ToDouble(input_gamma_f_static->Value);
			vehicle_inputs->gamma_r_static = System::Convert::ToDouble(input_gamma_r_static->Value);
			vehicle_inputs->BB_input = System::Convert::ToDouble(input_BB_input->Value);
			vehicle_inputs->DB_input = System::Convert::ToDouble(input_DB_input->Value);
			vehicle_inputs->pedals_input = static_cast<Pedals_input>(input_pedals_input->SelectedIndex + 1);
			vehicle_inputs->steering_input = static_cast<Steering_input>(input_steering_input->SelectedIndex + 1);
			vehicle_inputs->front_tires_selection = sto_(msclr::interop::marshal_as<std::string>(input_front_tires_selection->Text));
			vehicle_inputs->rear_tires_selection = sto_(msclr::interop::marshal_as<std::string>(input_rear_tires_selection->Text));
			vehicle_inputs->force_velocity = input_force_velocity->Checked;
			vehicle_inputs->max_beta = System::Convert::ToDouble(input_max_beta->Value);
			vehicle_inputs->num_beta = System::Convert::ToDouble(input_num_beta->Value);
			vehicle_inputs->con_beta = System::Convert::ToDouble(input_con_beta->Value);
			vehicle_inputs->max_delta_d = System::Convert::ToDouble(input_max_delta_d->Value);
			vehicle_inputs->num_delta_d = System::Convert::ToDouble(input_num_delta_d->Value);
			vehicle_inputs->con_delta_d = System::Convert::ToDouble(input_con_delta_d->Value);
			vehicle_inputs->a_lon_des = System::Convert::ToDouble(input_a_lon_des->Value);

			//Vehicle inputs
			vehicle_inputs->L = System::Convert::ToDouble(input_L->Value);
			vehicle_inputs->m = System::Convert::ToDouble(input_m->Value);
			vehicle_inputs->x = System::Convert::ToDouble(input_x->Value);
			vehicle_inputs->y = System::Convert::ToDouble(input_y->Value);
			vehicle_inputs->t_f = System::Convert::ToDouble(input_t_f->Value);
			vehicle_inputs->t_r = System::Convert::ToDouble(input_t_r->Value);
			vehicle_inputs->m_u_fl = System::Convert::ToDouble(input_m_u_fl->Value);
			vehicle_inputs->m_u_fr = System::Convert::ToDouble(input_m_u_fr->Value);
			vehicle_inputs->m_u_rl = System::Convert::ToDouble(input_m_u_rl->Value);
			vehicle_inputs->m_u_rr = System::Convert::ToDouble(input_m_u_rr->Value);
			vehicle_inputs->h_CG = System::Convert::ToDouble(input_h_CG->Value);
			vehicle_inputs->brake_config = static_cast<Actuator_config>(input_brake_config->SelectedIndex + 1);
			vehicle_inputs->brake_type_f = static_cast<Actuator_type>(input_brake_type_f->SelectedIndex + 1);
			vehicle_inputs->brake_type_r = static_cast<Actuator_type>(input_brake_type_r->SelectedIndex + 1);
			vehicle_inputs->drive_config = static_cast<Actuator_config>(input_drive_config->SelectedIndex + 1);
			vehicle_inputs->diff_type_f = static_cast<Actuator_type>(input_diff_type_f->SelectedIndex + 1);
			vehicle_inputs->diff_type_r = static_cast<Actuator_type>(input_diff_type_r->SelectedIndex + 1);
			vehicle_inputs->diff_lock_f = static_cast<Actuator_lock>(input_diff_lock_f->SelectedIndex + 1);
			vehicle_inputs->diff_lock_r = static_cast<Actuator_lock>(input_diff_lock_r->SelectedIndex + 1);
			vehicle_inputs->diff_dTBR_f = System::Convert::ToDouble(input_diff_dTBR_f->Value);
			vehicle_inputs->diff_dTBR_r = System::Convert::ToDouble(input_diff_dTBR_r->Value);
			vehicle_inputs->diff_bTBR_f = System::Convert::ToDouble(input_diff_bTBR_f->Value);
			vehicle_inputs->diff_bTBR_r = System::Convert::ToDouble(input_diff_bTBR_r->Value);
			vehicle_inputs->diff_preload_f = System::Convert::ToDouble(input_diff_preload_f->Value);
			vehicle_inputs->diff_preload_r = System::Convert::ToDouble(input_diff_preload_r->Value);
			vehicle_inputs->diff_k_lock_f = System::Convert::ToDouble(input_diff_k_lock_f->Value);
			vehicle_inputs->diff_k_lock_r = System::Convert::ToDouble(input_diff_k_lock_r->Value);

			vehicle_inputs->F_down_2 = System::Convert::ToDouble(input_F_down_2->Value);
			vehicle_inputs->F_down_1 = System::Convert::ToDouble(input_F_down_1->Value);
			vehicle_inputs->F_down_0 = System::Convert::ToDouble(input_F_down_0->Value);
			vehicle_inputs->F_down_x_2 = System::Convert::ToDouble(input_F_down_x_2->Value);
			vehicle_inputs->F_down_x_1 = System::Convert::ToDouble(input_F_down_x_1->Value);
			vehicle_inputs->F_down_x_0 = System::Convert::ToDouble(input_F_down_x_0->Value);
			vehicle_inputs->F_down_y_2 = System::Convert::ToDouble(input_F_down_y_2->Value);
			vehicle_inputs->F_down_y_1 = System::Convert::ToDouble(input_F_down_y_1->Value);
			vehicle_inputs->F_down_y_0 = System::Convert::ToDouble(input_F_down_y_0->Value);
			vehicle_inputs->F_drag_2 = System::Convert::ToDouble(input_F_drag_2->Value);
			vehicle_inputs->F_drag_1 = System::Convert::ToDouble(input_F_drag_1->Value);
			vehicle_inputs->F_drag_0 = System::Convert::ToDouble(input_F_drag_0->Value);
			vehicle_inputs->F_drag_z_2 = System::Convert::ToDouble(input_F_drag_z_2->Value);
			vehicle_inputs->F_drag_z_1 = System::Convert::ToDouble(input_F_drag_z_1->Value);
			vehicle_inputs->F_drag_z_0 = System::Convert::ToDouble(input_F_drag_z_0->Value);
			vehicle_inputs->F_drag_y_2 = System::Convert::ToDouble(input_F_drag_y_2->Value);
			vehicle_inputs->F_drag_y_1 = System::Convert::ToDouble(input_F_drag_y_1->Value);
			vehicle_inputs->F_drag_y_0 = System::Convert::ToDouble(input_F_drag_y_0->Value);

			//Suspension inputs
			vehicle_inputs->k_susp_f = System::Convert::ToDouble(input_k_susp_f->Value);
			vehicle_inputs->k_susp_r = System::Convert::ToDouble(input_k_susp_r->Value);
			vehicle_inputs->k_r_C_deg = System::Convert::ToDouble(input_k_r_C_deg->Value);
			vehicle_inputs->k_r_C_dist = System::Convert::ToDouble(input_k_r_C_dist->Value);
			vehicle_inputs->k_p_C_deg = System::Convert::ToDouble(input_k_p_C_deg->Value);
			vehicle_inputs->k_p_C_dist = System::Convert::ToDouble(input_k_p_C_dist->Value);
			vehicle_inputs->front_arb_selection = System::Convert::ToInt32(input_front_arb_selection->SelectedIndex);
			vehicle_inputs->rear_arb_selection = System::Convert::ToInt32(input_rear_arb_selection->SelectedIndex);
			vehicle_inputs->front_arb_setup = System::Convert::ToInt32(input_front_arb_setup->SelectedIndex);
			vehicle_inputs->rear_arb_setup = System::Convert::ToInt32(input_rear_arb_setup->SelectedIndex);
			vehicle_inputs->k_arb_f = spring_selection->front_ARB[vehicle_inputs->front_arb_setup];
			vehicle_inputs->k_arb_r = spring_selection->rear_ARB[vehicle_inputs->rear_arb_setup];
		
			vehicle_inputs->h_r_f_2 = System::Convert::ToDouble(input_h_r_f_2->Value);
			vehicle_inputs->h_r_f_1 = System::Convert::ToDouble(input_h_r_f_1->Value);
			vehicle_inputs->h_r_f_0 = System::Convert::ToDouble(input_h_r_f_0->Value);
			vehicle_inputs->h_r_r_2 = System::Convert::ToDouble(input_h_r_r_2->Value);
			vehicle_inputs->h_r_r_1 = System::Convert::ToDouble(input_h_r_r_1->Value);
			vehicle_inputs->h_r_r_0 = System::Convert::ToDouble(input_h_r_r_0->Value);
			vehicle_inputs->off_r_f_2 = System::Convert::ToDouble(input_off_r_f_2->Value);
			vehicle_inputs->off_r_f_1 = System::Convert::ToDouble(input_off_r_f_1->Value);
			vehicle_inputs->off_r_f_0 = System::Convert::ToDouble(input_off_r_f_0->Value);
			vehicle_inputs->off_r_r_2 = System::Convert::ToDouble(input_off_r_r_2->Value);
			vehicle_inputs->off_r_r_1 = System::Convert::ToDouble(input_off_r_r_1->Value);
			vehicle_inputs->off_r_r_0 = System::Convert::ToDouble(input_off_r_r_0->Value);
			vehicle_inputs->q_r_f_2 = System::Convert::ToDouble(input_q_r_f_2->Value);
			vehicle_inputs->q_r_f_1 = System::Convert::ToDouble(input_q_r_f_1->Value);
			vehicle_inputs->q_r_f_0 = System::Convert::ToDouble(input_q_r_f_0->Value);
			vehicle_inputs->q_r_r_2 = System::Convert::ToDouble(input_q_r_r_2->Value);
			vehicle_inputs->q_r_r_1 = System::Convert::ToDouble(input_q_r_r_1->Value);
			vehicle_inputs->q_r_r_0 = System::Convert::ToDouble(input_q_r_r_0->Value);
			vehicle_inputs->h_p_i_2 = System::Convert::ToDouble(input_h_p_i_2->Value);
			vehicle_inputs->h_p_i_1 = System::Convert::ToDouble(input_h_p_i_1->Value);
			vehicle_inputs->h_p_i_0 = System::Convert::ToDouble(input_h_p_i_0->Value);
			vehicle_inputs->h_p_o_2 = System::Convert::ToDouble(input_h_p_o_2->Value);
			vehicle_inputs->h_p_o_1 = System::Convert::ToDouble(input_h_p_o_1->Value);
			vehicle_inputs->h_p_o_0 = System::Convert::ToDouble(input_h_p_o_0->Value);
			vehicle_inputs->n_p_i_2 = System::Convert::ToDouble(input_n_p_i_2->Value);
			vehicle_inputs->n_p_i_1 = System::Convert::ToDouble(input_n_p_i_1->Value);
			vehicle_inputs->n_p_i_0 = System::Convert::ToDouble(input_n_p_i_0->Value);
			vehicle_inputs->n_p_o_2 = System::Convert::ToDouble(input_n_p_o_2->Value);
			vehicle_inputs->n_p_o_1 = System::Convert::ToDouble(input_n_p_o_1->Value);
			vehicle_inputs->n_p_o_0 = System::Convert::ToDouble(input_n_p_o_0->Value);
			vehicle_inputs->q_p_f_2 = System::Convert::ToDouble(input_q_p_f_2->Value);
			vehicle_inputs->q_p_f_1 = System::Convert::ToDouble(input_q_p_f_1->Value);
			vehicle_inputs->q_p_f_0 = System::Convert::ToDouble(input_q_p_f_0->Value);
			vehicle_inputs->q_p_r_2 = System::Convert::ToDouble(input_q_p_r_2->Value);
			vehicle_inputs->q_p_r_1 = System::Convert::ToDouble(input_q_p_r_1->Value);
			vehicle_inputs->q_p_r_0 = System::Convert::ToDouble(input_q_p_r_0->Value);

			vehicle_inputs->MR_s_f_2 = System::Convert::ToDouble(input_MR_s_f_2->Value);
			vehicle_inputs->MR_s_f_1 = System::Convert::ToDouble(input_MR_s_f_1->Value);
			vehicle_inputs->MR_s_f_0 = System::Convert::ToDouble(input_MR_s_f_0->Value);
			vehicle_inputs->MR_s_r_2 = System::Convert::ToDouble(input_MR_s_r_2->Value);
			vehicle_inputs->MR_s_r_1 = System::Convert::ToDouble(input_MR_s_r_1->Value);
			vehicle_inputs->MR_s_r_0 = System::Convert::ToDouble(input_MR_s_r_0->Value);
			vehicle_inputs->MR_arb_f_2 = System::Convert::ToDouble(input_MR_arb_f_2->Value);
			vehicle_inputs->MR_arb_f_1 = System::Convert::ToDouble(input_MR_arb_f_1->Value);
			vehicle_inputs->MR_arb_f_0 = System::Convert::ToDouble(input_MR_arb_f_0->Value);
			vehicle_inputs->MR_arb_r_2 = System::Convert::ToDouble(input_MR_arb_r_2->Value);
			vehicle_inputs->MR_arb_r_1 = System::Convert::ToDouble(input_MR_arb_r_1->Value);
			vehicle_inputs->MR_arb_r_0 = System::Convert::ToDouble(input_MR_arb_r_0->Value);
			vehicle_inputs->ackermann_2 = System::Convert::ToDouble(input_ackermann_2->Value);
			vehicle_inputs->ackermann_1 = System::Convert::ToDouble(input_ackermann_1->Value);
			vehicle_inputs->bs_f_2 = System::Convert::ToDouble(input_bs_f_2->Value);
			vehicle_inputs->bs_f_1 = System::Convert::ToDouble(input_bs_f_1->Value);
			vehicle_inputs->bs_r_2 = System::Convert::ToDouble(input_bs_r_2->Value);
			vehicle_inputs->bs_r_1 = System::Convert::ToDouble(input_bs_r_1->Value);
			vehicle_inputs->sc_f_2 = System::Convert::ToDouble(input_sc_f_2->Value);
			vehicle_inputs->sc_f_1 = System::Convert::ToDouble(input_sc_f_1->Value);
			vehicle_inputs->sc_r_2 = System::Convert::ToDouble(input_sc_r_2->Value);
			vehicle_inputs->sc_r_1 = System::Convert::ToDouble(input_sc_r_1->Value);
			vehicle_inputs->bc_f_2 = System::Convert::ToDouble(input_bc_f_2->Value);
			vehicle_inputs->bc_f_1 = System::Convert::ToDouble(input_bc_f_1->Value);
			vehicle_inputs->bc_r_2 = System::Convert::ToDouble(input_bc_r_2->Value);
			vehicle_inputs->bc_r_1 = System::Convert::ToDouble(input_bc_r_1->Value);

#ifdef _DEBUG
			vehicle_inputs->debug_iter = static_cast<int>(input_debug_iter->Value);
			vehicle_inputs->force_debug_iter = input_force_debug_iter->Checked;
#endif
		}

		void MyForm::write_inputs()
		{
			//Simulation inputs
			input_V_input->Value = System::Convert::ToDecimal(vehicle_inputs->V_input);
			input_R->Value = System::Convert::ToDecimal(vehicle_inputs->R);
			input_beta_deg->Value = System::Convert::ToDecimal(vehicle_inputs->beta_deg);
			input_delta_d_deg->Value = System::Convert::ToDecimal(vehicle_inputs->delta_d_deg);
			input_delta_f_static->Value = System::Convert::ToDecimal(vehicle_inputs->delta_f_static);
			input_delta_r_static->Value = System::Convert::ToDecimal(vehicle_inputs->delta_r_static);
			input_gamma_f_static->Value = System::Convert::ToDecimal(vehicle_inputs->gamma_f_static);
			input_gamma_r_static->Value = System::Convert::ToDecimal(vehicle_inputs->gamma_r_static);
			input_BB_input->Value = System::Convert::ToDecimal(vehicle_inputs->BB_input);
			input_DB_input->Value = System::Convert::ToDecimal(vehicle_inputs->DB_input);
			input_pedals_input->SelectedIndex = static_cast<int>(vehicle_inputs->pedals_input) - 1;
			input_steering_input->SelectedIndex = static_cast<int>(vehicle_inputs->steering_input) - 1;
			input_front_tires_selection->Text = gcnew System::String(_tos(vehicle_inputs->front_tires_selection).c_str());
			input_rear_tires_selection->Text = gcnew System::String(_tos(vehicle_inputs->rear_tires_selection).c_str());
			input_force_velocity->Checked = vehicle_inputs->force_velocity;
			input_max_beta->Value = System::Convert::ToDecimal(vehicle_inputs->max_beta);
			input_num_beta->Value = System::Convert::ToDecimal(vehicle_inputs->num_beta);
			input_con_beta->Value = System::Convert::ToDecimal(vehicle_inputs->con_beta);
			input_max_delta_d->Value = System::Convert::ToDecimal(vehicle_inputs->max_delta_d);
			input_num_delta_d->Value = System::Convert::ToDecimal(vehicle_inputs->num_delta_d);
			input_con_delta_d->Value = System::Convert::ToDecimal(vehicle_inputs->con_delta_d);
			input_a_lon_des->Value = System::Convert::ToDecimal(vehicle_inputs->a_lon_des);

			//Vehicle inputs
			input_m->Value = System::Convert::ToDecimal(vehicle_inputs->m);
			input_x->Value = System::Convert::ToDecimal(vehicle_inputs->x);
			input_y->Value = System::Convert::ToDecimal(vehicle_inputs->y);
			input_L->Value = System::Convert::ToDecimal(vehicle_inputs->L);
			input_t_f->Value = System::Convert::ToDecimal(vehicle_inputs->t_f);
			input_t_r->Value = System::Convert::ToDecimal(vehicle_inputs->t_r);
			input_h_CG->Value = System::Convert::ToDecimal(vehicle_inputs->h_CG);
			input_m_u_fl->Value = System::Convert::ToDecimal(vehicle_inputs->m_u_fl);
			input_m_u_fr->Value = System::Convert::ToDecimal(vehicle_inputs->m_u_fr);
			input_m_u_rl->Value = System::Convert::ToDecimal(vehicle_inputs->m_u_rl);
			input_m_u_rr->Value = System::Convert::ToDecimal(vehicle_inputs->m_u_rr);
			input_diff_dTBR_f->Value = System::Convert::ToDecimal(vehicle_inputs->diff_dTBR_f);
			input_diff_dTBR_r->Value = System::Convert::ToDecimal(vehicle_inputs->diff_dTBR_r);
			input_diff_bTBR_f->Value = System::Convert::ToDecimal(vehicle_inputs->diff_bTBR_f);
			input_diff_bTBR_r->Value = System::Convert::ToDecimal(vehicle_inputs->diff_bTBR_r);
			input_diff_preload_f->Value = System::Convert::ToDecimal(vehicle_inputs->diff_preload_f);
			input_diff_preload_r->Value = System::Convert::ToDecimal(vehicle_inputs->diff_preload_r);
			input_diff_k_lock_f->Value = System::Convert::ToDecimal(vehicle_inputs->diff_k_lock_f);
			input_diff_k_lock_r->Value = System::Convert::ToDecimal(vehicle_inputs->diff_k_lock_r);
			input_brake_config->SelectedIndex = static_cast<int>(vehicle_inputs->brake_config) - 1;
			input_brake_type_f->SelectedIndex = static_cast<int>(vehicle_inputs->brake_type_f) - 1;
			input_brake_type_r->SelectedIndex = static_cast<int>(vehicle_inputs->brake_type_r) - 1;
			input_drive_config->SelectedIndex = static_cast<int>(vehicle_inputs->drive_config) - 1;
			input_diff_type_f->SelectedIndex = static_cast<int>(vehicle_inputs->diff_type_f) - 1;
			input_diff_type_r->SelectedIndex = static_cast<int>(vehicle_inputs->diff_type_r) - 1;
			input_diff_lock_f->SelectedIndex = static_cast<int>(vehicle_inputs->diff_lock_f) - 1;
			input_diff_lock_r->SelectedIndex = static_cast<int>(vehicle_inputs->diff_lock_r) - 1;
			
		
			input_F_down_2->Value = System::Convert::ToDecimal(vehicle_inputs->F_down_2);
			input_F_down_1->Value = System::Convert::ToDecimal(vehicle_inputs->F_down_1);
			input_F_down_0->Value = System::Convert::ToDecimal(vehicle_inputs->F_down_0);
			input_F_down_x_2->Value = System::Convert::ToDecimal(vehicle_inputs->F_down_x_2);
			input_F_down_x_1->Value = System::Convert::ToDecimal(vehicle_inputs->F_down_x_1);
			input_F_down_x_0->Value = System::Convert::ToDecimal(vehicle_inputs->F_down_x_0);
			input_F_down_y_2->Value = System::Convert::ToDecimal(vehicle_inputs->F_down_y_2);
			input_F_down_y_1->Value = System::Convert::ToDecimal(vehicle_inputs->F_down_y_1);
			input_F_down_y_0->Value = System::Convert::ToDecimal(vehicle_inputs->F_down_y_0);
			input_F_drag_2->Value = System::Convert::ToDecimal(vehicle_inputs->F_drag_2);
			input_F_drag_1->Value = System::Convert::ToDecimal(vehicle_inputs->F_drag_1);
			input_F_drag_0->Value = System::Convert::ToDecimal(vehicle_inputs->F_drag_0);
			input_F_drag_z_2->Value = System::Convert::ToDecimal(vehicle_inputs->F_drag_z_2);
			input_F_drag_z_1->Value = System::Convert::ToDecimal(vehicle_inputs->F_drag_z_1);
			input_F_drag_z_0->Value = System::Convert::ToDecimal(vehicle_inputs->F_drag_z_0);
			input_F_drag_y_2->Value = System::Convert::ToDecimal(vehicle_inputs->F_drag_y_2);
			input_F_drag_y_1->Value = System::Convert::ToDecimal(vehicle_inputs->F_drag_y_1);
			input_F_drag_y_0->Value = System::Convert::ToDecimal(vehicle_inputs->F_drag_y_0);

			//Suspension inputs
			input_k_susp_f->Value = System::Convert::ToDecimal(vehicle_inputs->k_susp_f);
			input_k_susp_r->Value = System::Convert::ToDecimal(vehicle_inputs->k_susp_r);
			input_k_r_C_deg->Value = System::Convert::ToDecimal(vehicle_inputs->k_r_C_deg);
			input_k_r_C_dist->Value = System::Convert::ToDecimal(vehicle_inputs->k_r_C_dist);
			input_k_p_C_deg->Value = System::Convert::ToDecimal(vehicle_inputs->k_p_C_deg);
			input_k_p_C_dist->Value = System::Convert::ToDecimal(vehicle_inputs->k_p_C_dist);
			input_front_arb_selection->SelectedIndex = System::Convert::ToInt32(vehicle_inputs->front_arb_selection);
			input_rear_arb_selection->SelectedIndex = System::Convert::ToInt32(vehicle_inputs->rear_arb_selection);
			input_front_arb_setup->SelectedIndex = System::Convert::ToInt32(vehicle_inputs->front_arb_setup);
			input_rear_arb_setup->SelectedIndex = System::Convert::ToInt32(vehicle_inputs->rear_arb_setup);

			input_h_r_f_2->Value = System::Convert::ToDecimal(vehicle_inputs->h_r_f_2);
			input_h_r_f_1->Value = System::Convert::ToDecimal(vehicle_inputs->h_r_f_1);
			input_h_r_f_0->Value = System::Convert::ToDecimal(vehicle_inputs->h_r_f_0);
			input_h_r_r_2->Value = System::Convert::ToDecimal(vehicle_inputs->h_r_r_2);
			input_h_r_r_1->Value = System::Convert::ToDecimal(vehicle_inputs->h_r_r_1);
			input_h_r_r_0->Value = System::Convert::ToDecimal(vehicle_inputs->h_r_r_0);
			input_off_r_f_2->Value = System::Convert::ToDecimal(vehicle_inputs->off_r_f_2);
			input_off_r_f_1->Value = System::Convert::ToDecimal(vehicle_inputs->off_r_f_1);
			input_off_r_f_0->Value = System::Convert::ToDecimal(vehicle_inputs->off_r_f_0);
			input_off_r_r_2->Value = System::Convert::ToDecimal(vehicle_inputs->off_r_r_2);
			input_off_r_r_1->Value = System::Convert::ToDecimal(vehicle_inputs->off_r_r_1);
			input_off_r_r_0->Value = System::Convert::ToDecimal(vehicle_inputs->off_r_r_0);
			input_q_r_f_2->Value = System::Convert::ToDecimal(vehicle_inputs->q_r_f_2);
			input_q_r_f_1->Value = System::Convert::ToDecimal(vehicle_inputs->q_r_f_1);
			input_q_r_f_0->Value = System::Convert::ToDecimal(vehicle_inputs->q_r_f_0);
			input_q_r_r_2->Value = System::Convert::ToDecimal(vehicle_inputs->q_r_r_2);
			input_q_r_r_1->Value = System::Convert::ToDecimal(vehicle_inputs->q_r_r_1);
			input_q_r_r_0->Value = System::Convert::ToDecimal(vehicle_inputs->q_r_r_0);
			input_h_p_i_2->Value = System::Convert::ToDecimal(vehicle_inputs->h_p_i_2);
			input_h_p_i_1->Value = System::Convert::ToDecimal(vehicle_inputs->h_p_i_1);
			input_h_p_i_0->Value = System::Convert::ToDecimal(vehicle_inputs->h_p_i_0);
			input_h_p_o_2->Value = System::Convert::ToDecimal(vehicle_inputs->h_p_o_2);
			input_h_p_o_1->Value = System::Convert::ToDecimal(vehicle_inputs->h_p_o_1);
			input_h_p_o_0->Value = System::Convert::ToDecimal(vehicle_inputs->h_p_o_0);
			input_n_p_i_2->Value = System::Convert::ToDecimal(vehicle_inputs->n_p_i_2);
			input_n_p_i_1->Value = System::Convert::ToDecimal(vehicle_inputs->n_p_i_1);
			input_n_p_i_0->Value = System::Convert::ToDecimal(vehicle_inputs->n_p_i_0);
			input_n_p_o_2->Value = System::Convert::ToDecimal(vehicle_inputs->n_p_o_2);
			input_n_p_o_1->Value = System::Convert::ToDecimal(vehicle_inputs->n_p_o_1);
			input_n_p_o_0->Value = System::Convert::ToDecimal(vehicle_inputs->n_p_o_0);
			input_q_p_f_2->Value = System::Convert::ToDecimal(vehicle_inputs->q_p_f_2);
			input_q_p_f_1->Value = System::Convert::ToDecimal(vehicle_inputs->q_p_f_1);
			input_q_p_f_0->Value = System::Convert::ToDecimal(vehicle_inputs->q_p_f_0);
			input_q_p_r_2->Value = System::Convert::ToDecimal(vehicle_inputs->q_p_r_2);
			input_q_p_r_1->Value = System::Convert::ToDecimal(vehicle_inputs->q_p_r_1);
			input_q_p_r_0->Value = System::Convert::ToDecimal(vehicle_inputs->q_p_r_0);
			
			input_MR_s_f_2->Value = System::Convert::ToDecimal(vehicle_inputs->MR_s_f_2);
			input_MR_s_f_1->Value = System::Convert::ToDecimal(vehicle_inputs->MR_s_f_1);
			input_MR_s_f_0->Value = System::Convert::ToDecimal(vehicle_inputs->MR_s_f_0);
			input_MR_s_r_2->Value = System::Convert::ToDecimal(vehicle_inputs->MR_s_r_2);
			input_MR_s_r_1->Value = System::Convert::ToDecimal(vehicle_inputs->MR_s_r_1);
			input_MR_s_r_0->Value = System::Convert::ToDecimal(vehicle_inputs->MR_s_r_0);
			input_MR_arb_f_2->Value = System::Convert::ToDecimal(vehicle_inputs->MR_arb_f_2);
			input_MR_arb_f_1->Value = System::Convert::ToDecimal(vehicle_inputs->MR_arb_f_1);
			input_MR_arb_f_0->Value = System::Convert::ToDecimal(vehicle_inputs->MR_arb_f_0);
			input_MR_arb_r_2->Value = System::Convert::ToDecimal(vehicle_inputs->MR_arb_r_2);
			input_MR_arb_r_1->Value = System::Convert::ToDecimal(vehicle_inputs->MR_arb_r_1);
			input_MR_arb_r_0->Value = System::Convert::ToDecimal(vehicle_inputs->MR_arb_r_0);
			input_ackermann_2->Value = System::Convert::ToDecimal(vehicle_inputs->ackermann_2);
			input_ackermann_1->Value = System::Convert::ToDecimal(vehicle_inputs->ackermann_1);
			input_bs_f_2->Value = System::Convert::ToDecimal(vehicle_inputs->bs_f_2);
			input_bs_f_1->Value = System::Convert::ToDecimal(vehicle_inputs->bs_f_1);
			input_bs_r_2->Value = System::Convert::ToDecimal(vehicle_inputs->bs_r_2);
			input_bs_r_1->Value = System::Convert::ToDecimal(vehicle_inputs->bs_r_1);
			input_sc_f_2->Value = System::Convert::ToDecimal(vehicle_inputs->sc_f_2);
			input_sc_f_1->Value = System::Convert::ToDecimal(vehicle_inputs->sc_f_1);
			input_sc_r_2->Value = System::Convert::ToDecimal(vehicle_inputs->sc_r_2);
			input_sc_r_1->Value = System::Convert::ToDecimal(vehicle_inputs->sc_r_1);
			input_bc_f_2->Value = System::Convert::ToDecimal(vehicle_inputs->bc_f_2);
			input_bc_f_1->Value = System::Convert::ToDecimal(vehicle_inputs->bc_f_1);
			input_bc_r_2->Value = System::Convert::ToDecimal(vehicle_inputs->bc_r_2);
			input_bc_r_1->Value = System::Convert::ToDecimal(vehicle_inputs->bc_r_1);
		}

		void MyForm::write_outputs() {
			output_M_yaw->Text = System::String::Format("Yaw moment: {0:F2} Nm", System::Convert::ToDouble(vehicle_outputs->M_yaw));
			output_r_deg->Text = System::String::Format("Yaw rate: {0:F2} °/s", System::Convert::ToDouble(vehicle_outputs->r_deg));
			output_a_lat->Text = System::String::Format("Lateral acceleration: {0:F2} g", System::Convert::ToDouble(vehicle_outputs->a_lat));
			output_a_lon->Text = System::String::Format("Longitudinal acceleration: {0:F2} g", System::Convert::ToDouble(vehicle_outputs->a_lon));
			output_F_lat->Text = System::String::Format("Lateral force: {0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lat));
			output_F_lon->Text = System::String::Format("Longitudinal force: {0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lon));
			output_a_rad->Text = System::String::Format("Radial acceleration: {0:F2} g", System::Convert::ToDouble(vehicle_outputs->a_rad));
			output_phi_deg->Text = System::String::Format("Pitch angle: {0:F2}°", System::Convert::ToDouble(vehicle_outputs->phi_deg));
			output_psi_deg->Text = System::String::Format("Roll angle: {0:F2}°", System::Convert::ToDouble(vehicle_outputs->psi_deg));
			output_iter->Text = System::String::Format("Iterations: {0}", System::Convert::ToInt32(vehicle_outputs->iter));
			output_V->Text = System::String::Format("Velocity: {0:F2} km/h", System::Convert::ToDouble(vehicle_outputs->V));
			output_R->Text = (abs(vehicle_outputs->R) < 1e5) ? System::String::Format("Corner radius: {0:F2} m", System::Convert::ToDouble(vehicle_outputs->R)) : "Corner radius: 100000+ m";
			output_bias_now->Text = System::String::Format("Current bias: {0:F2}%", System::Convert::ToDouble(vehicle_outputs->bias_now));

			output_alpha_fl->Text = System::String::Format("{0:F2}°", System::Convert::ToDouble(vehicle_outputs->alpha_fl));
			output_alpha_fr->Text = System::String::Format("{0:F2}°", System::Convert::ToDouble(vehicle_outputs->alpha_fr));
			output_alpha_rl->Text = System::String::Format("{0:F2}°", System::Convert::ToDouble(vehicle_outputs->alpha_rl));
			output_alpha_rr->Text = System::String::Format("{0:F2}°", System::Convert::ToDouble(vehicle_outputs->alpha_rr));
			
			output_kappa_fl->Text = System::String::Format("{0:F2}%", System::Convert::ToDouble(vehicle_outputs->kappa_fl));
			output_kappa_fr->Text = System::String::Format("{0:F2}%", System::Convert::ToDouble(vehicle_outputs->kappa_fr));
			output_kappa_rl->Text = System::String::Format("{0:F2}%", System::Convert::ToDouble(vehicle_outputs->kappa_rl));
			output_kappa_rr->Text = System::String::Format("{0:F2}%", System::Convert::ToDouble(vehicle_outputs->kappa_rr));
			
			output_F_z_fl->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_z_fl));
			output_F_z_fr->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_z_fr));
			output_F_z_rl->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_z_rl));
			output_F_z_rr->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_z_rr));

			output_F_x_comb_fl->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_x_comb_fl));
			output_F_x_comb_fr->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_x_comb_fr));
			output_F_x_comb_rl->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_x_comb_rl));
			output_F_x_comb_rr->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_x_comb_rr));

			output_F_y_comb_fl->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_y_comb_fl));
			output_F_y_comb_fr->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_y_comb_fr));
			output_F_y_comb_rl->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_y_comb_rl));
			output_F_y_comb_rr->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_y_comb_rr));

			output_F_lat_fl->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lat_fl));
			output_F_lat_fr->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lat_fr));
			output_F_lat_rl->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lat_rl));
			output_F_lat_rr->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lat_rr));

			output_F_lon_fl->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lon_fl));
			output_F_lon_fr->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lon_fr));
			output_F_lon_rl->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lon_rl));
			output_F_lon_rr->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lon_rr));

			output_T_fl->Text = System::String::Format("{0:F2} Nm", System::Convert::ToDouble(vehicle_outputs->T_fl));
			output_T_fr->Text = System::String::Format("{0:F2} Nm", System::Convert::ToDouble(vehicle_outputs->T_fr));
			output_T_rl->Text = System::String::Format("{0:F2} Nm", System::Convert::ToDouble(vehicle_outputs->T_rl));
			output_T_rr->Text = System::String::Format("{0:F2} Nm", System::Convert::ToDouble(vehicle_outputs->T_rr));

			output_h_CG_u_fl->Text = System::String::Format("{0:F2} mm", System::Convert::ToDouble(vehicle_outputs->h_CG_u_fl));
			output_h_CG_u_fr->Text = System::String::Format("{0:F2} mm", System::Convert::ToDouble(vehicle_outputs->h_CG_u_fr));
			output_h_CG_u_rl->Text = System::String::Format("{0:F2} mm", System::Convert::ToDouble(vehicle_outputs->h_CG_u_rl));
			output_h_CG_u_rr->Text = System::String::Format("{0:F2} mm", System::Convert::ToDouble(vehicle_outputs->h_CG_u_rr));

			output_h_CG_s->Text = System::String::Format("{0:F2} mm", System::Convert::ToDouble(vehicle_outputs->h_CG_s));
			output_m_s->Text = System::String::Format("{0:F2} kg", System::Convert::ToDouble(vehicle_outputs->m_s));
		
#ifdef _DEBUG
			//Debug outputs
			output_debug1->Text = System::String::Format("Debug 1: {0:F2}", System::Convert::ToDouble(vehicle_outputs->debug1));
			output_debug2->Text = System::String::Format("Debug 2: {0:F2}", System::Convert::ToDouble(vehicle_outputs->debug2));
			output_debug3->Text = System::String::Format("Debug 3: {0:F2}", System::Convert::ToDouble(vehicle_outputs->debug3));
			output_debug4->Text = System::String::Format("Debug 4: {0:F2}", System::Convert::ToDouble(vehicle_outputs->debug4));

			output_brents_single->Text = System::String::Format("Brent's Method single run iterations: {0}", System::Convert::ToInt32(vehicle_outputs->brents_single));
			output_brents_total->Text = System::String::Format("Brent's Method total iterations: {0}", System::Convert::ToInt32(vehicle_outputs->brents_total));
			output_golden_single->Text = System::String::Format("Golden Section single run iterations: {0}", System::Convert::ToInt32(vehicle_outputs->golden_single));
			output_golden_total->Text = System::String::Format("Golden Section total iterations: {0}", System::Convert::ToInt32(vehicle_outputs->golden_total));
			output_iter_total->Text = System::String::Format("Main solver total iterations: {0}", System::Convert::ToInt32(vehicle_outputs->iter_total));
#endif
			}

		void MyForm::read_tire_inputs() {
			//Longitudinal parameters
			tire_inputs->p_Cx1 = System::Convert::ToDouble(input_p_Cx1->Value);
			tire_inputs->p_Dx1 = System::Convert::ToDouble(input_p_Dx1->Value);
			tire_inputs->p_Dx2 = System::Convert::ToDouble(input_p_Dx2->Value);
			tire_inputs->p_Dx3 = System::Convert::ToDouble(input_p_Dx3->Value);
			tire_inputs->p_Ex1 = System::Convert::ToDouble(input_p_Ex1->Value);
			tire_inputs->p_Ex2 = System::Convert::ToDouble(input_p_Ex2->Value);
			tire_inputs->p_Ex3 = System::Convert::ToDouble(input_p_Ex3->Value);
			tire_inputs->p_Ex4 = System::Convert::ToDouble(input_p_Ex4->Value);
			tire_inputs->p_Kx1 = System::Convert::ToDouble(input_p_Kx1->Value);
			tire_inputs->p_Kx2 = System::Convert::ToDouble(input_p_Kx2->Value);
			tire_inputs->p_Kx3 = System::Convert::ToDouble(input_p_Kx3->Value);
			tire_inputs->p_Hx1 = System::Convert::ToDouble(input_p_Hx1->Value);
			tire_inputs->p_Hx2 = System::Convert::ToDouble(input_p_Hx2->Value);
			tire_inputs->p_Vx1 = System::Convert::ToDouble(input_p_Vx1->Value);
			tire_inputs->p_Vx2 = System::Convert::ToDouble(input_p_Vx2->Value);

			//Lateral parameters
			tire_inputs->p_Cy1 = System::Convert::ToDouble(input_p_Cy1->Value);
			tire_inputs->p_Dy1 = System::Convert::ToDouble(input_p_Dy1->Value);
			tire_inputs->p_Dy2 = System::Convert::ToDouble(input_p_Dy2->Value);
			tire_inputs->p_Dy3 = System::Convert::ToDouble(input_p_Dy3->Value);
			tire_inputs->p_Ey1 = System::Convert::ToDouble(input_p_Ey1->Value);
			tire_inputs->p_Ey2 = System::Convert::ToDouble(input_p_Ey2->Value);
			tire_inputs->p_Ey3 = System::Convert::ToDouble(input_p_Ey3->Value);
			tire_inputs->p_Ey4 = System::Convert::ToDouble(input_p_Ey4->Value);
			tire_inputs->p_Ky1 = System::Convert::ToDouble(input_p_Ky1->Value);
			tire_inputs->p_Ky2 = System::Convert::ToDouble(input_p_Ky2->Value);
			tire_inputs->p_Ky3 = System::Convert::ToDouble(input_p_Ky3->Value);
			tire_inputs->p_Hy1 = System::Convert::ToDouble(input_p_Hy1->Value);
			tire_inputs->p_Hy2 = System::Convert::ToDouble(input_p_Hy2->Value);
			tire_inputs->p_Hy3 = System::Convert::ToDouble(input_p_Hy3->Value);
			tire_inputs->p_Vy1 = System::Convert::ToDouble(input_p_Vy1->Value);
			tire_inputs->p_Vy2 = System::Convert::ToDouble(input_p_Vy2->Value);
			tire_inputs->p_Vy3 = System::Convert::ToDouble(input_p_Vy3->Value);
			tire_inputs->p_Vy4 = System::Convert::ToDouble(input_p_Vy4->Value);

			//Other parameters
			tire_inputs->r_u = System::Convert::ToDouble(input_r_u->Value);
			tire_inputs->a_rr = System::Convert::ToDouble(input_a_rr->Value);
			tire_inputs->b_rr = System::Convert::ToDouble(input_b_rr->Value);
			tire_inputs->F_z_o = System::Convert::ToDouble(input_F_z_o->Value);
			tire_inputs->K_T = System::Convert::ToDouble(input_K_T->Value);
		}

		void MyForm::write_tire_inputs() {
			//Longitudinal parameters
			input_p_Cx1->Value = System::Convert::ToDecimal(tire_inputs->p_Cx1);
			input_p_Dx1->Value = System::Convert::ToDecimal(tire_inputs->p_Dx1);
			input_p_Dx2->Value = System::Convert::ToDecimal(tire_inputs->p_Dx2);
			input_p_Dx3->Value = System::Convert::ToDecimal(tire_inputs->p_Dx3);
			input_p_Ex1->Value = System::Convert::ToDecimal(tire_inputs->p_Ex1);
			input_p_Ex2->Value = System::Convert::ToDecimal(tire_inputs->p_Ex2);
			input_p_Ex3->Value = System::Convert::ToDecimal(tire_inputs->p_Ex3);
			input_p_Ex4->Value = System::Convert::ToDecimal(tire_inputs->p_Ex4);
			input_p_Kx1->Value = System::Convert::ToDecimal(tire_inputs->p_Kx1);
			input_p_Kx2->Value = System::Convert::ToDecimal(tire_inputs->p_Kx2);
			input_p_Kx3->Value = System::Convert::ToDecimal(tire_inputs->p_Kx3);
			input_p_Hx1->Value = System::Convert::ToDecimal(tire_inputs->p_Hx1);
			input_p_Hx2->Value = System::Convert::ToDecimal(tire_inputs->p_Hx2);
			input_p_Vx1->Value = System::Convert::ToDecimal(tire_inputs->p_Vx1);
			input_p_Vx2->Value = System::Convert::ToDecimal(tire_inputs->p_Vx2);

			//Lateral parameters
			input_p_Cy1->Value = System::Convert::ToDecimal(tire_inputs->p_Cy1);
			input_p_Dy1->Value = System::Convert::ToDecimal(tire_inputs->p_Dy1);
			input_p_Dy2->Value = System::Convert::ToDecimal(tire_inputs->p_Dy2);
			input_p_Dy3->Value = System::Convert::ToDecimal(tire_inputs->p_Dy3);
			input_p_Ey1->Value = System::Convert::ToDecimal(tire_inputs->p_Ey1);
			input_p_Ey2->Value = System::Convert::ToDecimal(tire_inputs->p_Ey2);
			input_p_Ey3->Value = System::Convert::ToDecimal(tire_inputs->p_Ey3);
			input_p_Ey4->Value = System::Convert::ToDecimal(tire_inputs->p_Ey4);
			input_p_Ky1->Value = System::Convert::ToDecimal(tire_inputs->p_Ky1);
			input_p_Ky2->Value = System::Convert::ToDecimal(tire_inputs->p_Ky2);
			input_p_Ky3->Value = System::Convert::ToDecimal(tire_inputs->p_Ky3);
			input_p_Hy1->Value = System::Convert::ToDecimal(tire_inputs->p_Hy1);
			input_p_Hy2->Value = System::Convert::ToDecimal(tire_inputs->p_Hy2);
			input_p_Hy3->Value = System::Convert::ToDecimal(tire_inputs->p_Hy3);
			input_p_Vy1->Value = System::Convert::ToDecimal(tire_inputs->p_Vy1);
			input_p_Vy2->Value = System::Convert::ToDecimal(tire_inputs->p_Vy2);
			input_p_Vy3->Value = System::Convert::ToDecimal(tire_inputs->p_Vy3);
			input_p_Vy4->Value = System::Convert::ToDecimal(tire_inputs->p_Vy4);

			//Other parameters
			input_r_u->Value = System::Convert::ToDecimal(tire_inputs->r_u);
			input_a_rr->Value = System::Convert::ToDecimal(tire_inputs->a_rr);
			input_b_rr->Value = System::Convert::ToDecimal(tire_inputs->b_rr);
			input_F_z_o->Value = System::Convert::ToDecimal(tire_inputs->F_z_o);
			input_K_T->Value = System::Convert::ToDecimal(tire_inputs->K_T);
		}

		String^ selected_tire;

		void select_tire() {
			String^ name = System::Convert::ToString(tire_name->SelectedItem)->Replace(" ", "_");
			tire_selection->select_tire(msclr::interop::marshal_as<std::string>(name), tire_inputs);
			write_tire_inputs();
		}

		void load_tire_list()
		{
			tire_list->Clear();
			for (const auto& s : tire_selection->load_tire_list())
			{
				tire_list->Add((gcnew System::String(s.c_str()))->Replace("_", " "));
			}
			tire_name->Items->Clear();
			input_front_tires_selection->Items->Clear();
			input_rear_tires_selection->Items->Clear();
			tire_name->Items->AddRange(tire_list->ToArray());
			input_front_tires_selection->Items->AddRange(tire_list->ToArray());
			input_rear_tires_selection->Items->AddRange(tire_list->ToArray());
			input_front_tires_selection->SelectedIndex = 0;
			input_rear_tires_selection->SelectedIndex = 0;
		}

		void save_tire() {
			String^ past_name = Convert::ToString(tire_name->SelectedItem)->Replace(" ", "_");
			read_tire_inputs();
			String^ name = tire_name->Text->Replace(" ", "_");
			tire_selection->save_tire(msclr::interop::marshal_as<std::string>(name), tire_inputs);
			load_tire_list();
		}

		void new_tire()
		{
			read_tire_inputs();
			Tire_selection::file_status status = tire_selection->new_tire(tire_inputs);
			if (status == Tire_selection::file_status::DuplicateItem) {
				MessageBox::Show("Tire already exists.");
				return;
			}
			else if (status == Tire_selection::file_status::DuplicateFile) {
				MessageBox::Show("Tire file already exists.");
				return;
			}
			else if (status == Tire_selection::file_status::Success) {
				load_tire_list();
				tire_name->SelectedItem = "New tire";
			}
		}

		void delete_tire()
		{
			String^ name = tire_name->Text;
			System::Windows::Forms::DialogResult result =
				System::Windows::Forms::MessageBox::Show(
					"Do you want to delete the tire '" + name + "'?",
					"Warning",
					System::Windows::Forms::MessageBoxButtons::YesNo,
					System::Windows::Forms::MessageBoxIcon::Warning
				);

			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				Tire_selection::file_status status = tire_selection->delete_tire(msclr::interop::marshal_as<std::string>(name->Replace(" ", "_")));
				if (status == Tire_selection::file_status::EmptyItem) {
					MessageBox::Show("Tire name is empty.");
					return;
				}
				else if (status == Tire_selection::file_status::ItemNotFound) {
					MessageBox::Show("Tire name not found.");
					return;
				}
				else if (status == Tire_selection::file_status::FileNotFound) {
					MessageBox::Show("Tire file not found.");
					return;
				}
				else if (status == Tire_selection::file_status::Success) {
					load_tire_list();
					tire_name->SelectedItem = tire_list[0];
					if (input_front_tires_selection->Text == name) { input_front_tires_selection->Text = tire_list[0]; }
					if (input_rear_tires_selection->Text == name) { input_rear_tires_selection->Text = tire_list[0]; }
				}
			}
		}

		String^ selected_spring;

		void read_spring_inputs() {
			spring_selection->spring_inputs.clear();
			for each (System::Object ^ item in spring_setups->Items) {
				double value = System::Convert::ToDouble(item);
				spring_selection->spring_inputs.push_back(value);
				std::sort(spring_selection->spring_inputs.begin(), spring_selection->spring_inputs.end());
			}
		};

		void write_spring_inputs() {
			spring_setups->Items->Clear();
			for (const auto& value : spring_selection->spring_inputs) {
				spring_setups->Items->Add(System::Convert::ToString(value));
				spring_setups->SelectedIndex = 0;
			}
		};

		void select_spring() {
			String^ name = System::Convert::ToString(spring_name->SelectedItem)->Replace(" ", "_");
			spring_selection->select_spring(msclr::interop::marshal_as<std::string>(name));
			write_spring_inputs();
		}

		void load_spring_list()
		{
			spring_list->Clear();
			for (const auto& s : spring_selection->load_spring_list())
			{
				spring_list->Add((gcnew System::String(s.c_str()))->Replace("_", " "));
			}
			spring_name->Items->Clear();
			input_front_arb_selection->Items->Clear();
			input_rear_arb_selection->Items->Clear();
			spring_name->Items->AddRange(spring_list->ToArray());
			input_front_arb_selection->Items->Add("No ARB");
			input_rear_arb_selection->Items->Add("No ARB");
			input_front_arb_selection->Items->AddRange(spring_list->ToArray());
			input_rear_arb_selection->Items->AddRange(spring_list->ToArray());
			input_front_arb_selection->SelectedIndex = 0;
			input_rear_arb_selection->SelectedIndex = 0;
			front_arb_setup();
			rear_arb_setup();
		}

		void save_spring() {
			String^ past_name = Convert::ToString(spring_name->SelectedItem)->Replace(" ", "_");
			read_spring_inputs();
			String^ name = spring_name->Text->Replace(" ", "_");
			spring_selection->save_spring(msclr::interop::marshal_as<std::string>(name));
			load_spring_list();
		}

		void new_spring()
		{
			read_spring_inputs();
			try { spring_selection->new_spring(spring_selection->spring_inputs); }
			catch (const std::exception& e) {
				MessageBox::Show(gcnew System::String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
				load_spring_list();
				spring_name->SelectedItem = "New spring";
		}

		void delete_spring()
		{
			String^ name = spring_name->Text;
			System::Windows::Forms::DialogResult result =
				System::Windows::Forms::MessageBox::Show(
					"Do you want to delete the spring '" + name + "'?",
					"Warning",
					System::Windows::Forms::MessageBoxButtons::YesNo,
					System::Windows::Forms::MessageBoxIcon::Warning
				);

			if (result == System::Windows::Forms::DialogResult::Yes)
			{
				try {
					spring_selection->delete_spring(msclr::interop::marshal_as<std::string>(name->Replace(" ", "_")));
				}
				catch (const std::exception& e) {
					MessageBox::Show(gcnew System::String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				load_spring_list();
				spring_name->SelectedItem = spring_list[0];
				if (input_front_arb_selection->Text == name) { input_front_arb_selection->Text = spring_list[0]; }
				if (input_rear_arb_selection->Text == name) { input_rear_arb_selection->Text = spring_list[0]; }
			}
		}

		void front_arb_setup() {
			spring_selection->select_front_arb(sto_(msclr::interop::marshal_as<std::string>(input_front_arb_selection->Text)));
			if (input_front_arb_selection->SelectedIndex == 0) {
				input_front_arb_setup->Enabled = false;
				input_front_arb_setup->Items->Clear();
				input_front_arb_setup->Items->Add("No ARB");
			}
			else {
				input_front_arb_setup->Enabled = true;
				input_front_arb_setup->Items->Clear();
				for (int i = 0; i < spring_selection->front_ARB.size(); i++) {
					input_front_arb_setup->Items->Add("Setup " + (i + 1) + "/" + spring_selection->front_ARB.size());
				}
			}
			input_front_arb_setup->SelectedIndex = 0;
		}

		void rear_arb_setup() {
			spring_selection->select_rear_arb(sto_(msclr::interop::marshal_as<std::string>(input_rear_arb_selection->Text)));
			if (input_rear_arb_selection->SelectedIndex == 0) {
				input_rear_arb_setup->Enabled = false;
				input_rear_arb_setup->Items->Clear();
				input_rear_arb_setup->Items->Add("No ARB");
			}
			else {
				input_rear_arb_setup->Enabled = true;
				input_rear_arb_setup->Items->Clear();
				for (int i = 0; i < spring_selection->rear_ARB.size(); i++) {
					input_rear_arb_setup->Items->Add("Setup " + (i + 1) + "/" + spring_selection->rear_ARB.size());
				}
			}
			input_rear_arb_setup->SelectedIndex = 0;
		}

#pragma endregion
private: System::Void RUN_Click(System::Object^ sender, System::EventArgs^ e) {
	read_inputs();
	try {
		sim_controller->run_simulation(*vehicle_inputs, *vehicle_outputs);
	}
	catch (const std::exception& e) {
		MessageBox::Show(gcnew System::String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	write_outputs();
}

private: System::Void RUN_YMD_Click(System::Object^ sender, System::EventArgs^ e) {
	read_inputs();
	try {
		sim_controller->run_YMD(*vehicle_inputs, *vehicle_outputs, *YMD_carrier);
	}
	catch (const std::exception& e) {
		MessageBox::Show(gcnew System::String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	YMD_setup(YMD, *YMD_carrier);
	YMD_clear(YMD);
	YMD_plot(YMD, *YMD_carrier);
	write_outputs();
}

private: System::Void MyForm_FormClosing_1(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	read_inputs();
	save_inputs(*vehicle_inputs, "Files\\Vehicles\\Vehicle_params_1.txt");
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
#ifndef _DEBUG
	this->tabControl1->TabPages->Remove(this->debugPage);
	input_debug_iter->Visible = false;
	input_force_debug_iter->Visible = false;
#endif
	try {
		sim_controller->load_form(*vehicle_inputs, *vehicle_outputs, *YMD_carrier);
	}
	catch (const std::exception& e) {
		MessageBox::Show(gcnew System::String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	YMD_setup(YMD, *YMD_carrier);
	YMD_clear(YMD);
	YMD_plot(YMD, *YMD_carrier);
	
	load_tire_list();
	tire_name->Text = tire_list[0];
	select_tire();
	load_spring_list();
	spring_name->Text = spring_list[0];
	select_spring();
	write_inputs();
	write_outputs();
	if (!input_force_velocity->Checked) { 
		input_force_radius->Checked = true; 
		input_R->Visible = true;
		input_V_input->Visible = false;
		Display_corner_or_velocity->Text = "Corner radius [m]";
	}
	else {
		input_R->Visible = false;
		input_V_input->Visible = true;
		Display_corner_or_velocity->Text = "Vehicle velocity [km/h]";
	}

	input_front_arb_setup->SelectedIndex = vehicle_inputs->front_arb_setup;
	input_rear_arb_setup->SelectedIndex = vehicle_inputs->rear_arb_setup;

#ifdef _DEBUG
	MessageBox::Show("DEBUG MODE ACTIVE", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
#endif

}
private: System::Void tire_save_Click(System::Object^ sender, System::EventArgs^ e) {
	save_tire();
}
private: System::Void tire_new_Click(System::Object^ sender, System::EventArgs^ e) {
	new_tire();
}
private: System::Void tire_delete_Click(System::Object^ sender, System::EventArgs^ e) {
	delete_tire();
}
private: System::Void tire_name_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
	select_tire();
}


private: System::Void input_force_velocity_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!input_force_velocity->Checked) {
		input_force_radius->Checked = true;
		input_R->Visible = true;
		input_V_input->Visible = false;
		Display_corner_or_velocity->Text = "Corner radius [m]";
	}
	else {
		input_force_radius->Checked = false;
		input_R->Visible = false;
		input_V_input->Visible = true;
		Display_corner_or_velocity->Text = "Vehicle velocity [km/h]";
	}
}
private: System::Void input_force_radius_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!input_force_radius->Checked) {
		input_force_velocity->Checked = true;
		input_R->Visible = false;
		input_V_input->Visible = true;
		Display_corner_or_velocity->Text = "Vehicle velocity [km/h]";
	}
	else {
		input_force_velocity->Checked = false;
		input_R->Visible = true;
		input_V_input->Visible = false;
		Display_corner_or_velocity->Text = "Corner radius [m]";
	}
}
private: System::Void input_drive_config_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (input_drive_config->SelectedIndex == 0) {
		input_DB_input->Visible = true;

		int old = 0;

		input_diff_type_f->Enabled = true;
		input_diff_lock_f->Enabled = true;
		old = input_diff_lock_f->SelectedIndex;
		input_diff_lock_f->SelectedIndex = 0;
		input_diff_lock_f->SelectedIndex = 1;
		input_diff_lock_f->SelectedIndex = old;

		input_diff_lock_r->Enabled = true;
		input_diff_type_r->Enabled = true;
		old = input_diff_lock_r->SelectedIndex;
		input_diff_lock_r->SelectedIndex = 0;
		input_diff_lock_r->SelectedIndex = 1;
		input_diff_lock_r->SelectedIndex = old;
	}
	else if (input_drive_config->SelectedIndex == 1) {
		input_DB_input->Visible = false;
		fake_DB->Value = 100;

		input_diff_type_f->Enabled = true;
		input_diff_type_r->Enabled = false;

		input_diff_lock_f->Enabled = true;
		input_diff_lock_r->Enabled = false;

		int old = 0;

		old = input_diff_lock_f->SelectedIndex;
		input_diff_lock_f->SelectedIndex = 0;
		input_diff_lock_f->SelectedIndex = 1;
		input_diff_lock_f->SelectedIndex = old;

		input_diff_dTBR_r->Visible = false;
		input_diff_bTBR_r->Visible = false;
		input_diff_preload_r->Visible = false;
		input_diff_k_lock_r->Visible = false;

		fake_dTBR_r->Value = 1;
		fake_bTBR_r->Value = 1;
		fake_preload_r->Value = 0;
		fake_k_lock_r->Value = 0;
	}
	else if (input_drive_config->SelectedIndex == 2) {
		input_DB_input->Visible = false;
		fake_DB->Value = 0;

		input_diff_type_f->Enabled = false;
		input_diff_type_r->Enabled = true;

		input_diff_lock_f->Enabled = false;
		input_diff_lock_r->Enabled = true;

		int old = 0;

		old = input_diff_lock_r->SelectedIndex;
		input_diff_lock_r->SelectedIndex = 0;
		input_diff_lock_r->SelectedIndex = 1;
		input_diff_lock_r->SelectedIndex = old;

		input_diff_dTBR_f->Visible = false;
		input_diff_bTBR_f->Visible = false;
		input_diff_preload_f->Visible = false;
		input_diff_k_lock_f->Visible = false;

		fake_dTBR_f->Value = 1;
		fake_bTBR_f->Value = 1;
		fake_preload_f->Value = 0;
		fake_k_lock_f->Value = 0;
	}
}
private: System::Void input_brake_config_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (input_brake_config->SelectedIndex == 0) {
		input_BB_input->Visible = true;

		input_brake_type_f->Enabled = true;
		input_brake_type_r->Enabled = true;
	}
	else if (input_brake_config->SelectedIndex == 1) {
		input_BB_input->Visible = false;
		fake_BB->Value = 100;

		input_brake_type_f->Enabled = true;
		input_brake_type_r->Enabled = false;
	}
	else if (input_brake_config->SelectedIndex == 2) {
		input_BB_input->Visible = false;
		fake_BB->Value = 0;

		input_brake_type_f->Enabled = false;
		input_brake_type_r->Enabled = true;
	}
}
private: System::Void input_pedals_input_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (input_pedals_input->SelectedIndex == 0) {
		input_a_lon_des->Value = -Math::Abs(input_a_lon_des->Value);
		input_a_lon_des->Enabled = true;
	}
	else if (input_pedals_input->SelectedIndex == 1) {
		input_a_lon_des->Value = Math::Abs(input_a_lon_des->Value);
		input_a_lon_des->Enabled = true;
	}
	else if (input_pedals_input->SelectedIndex == 2) {
		input_a_lon_des->Value = Math::Abs(input_a_lon_des->Value);
		input_a_lon_des->Enabled = false;
	}
	else if (input_pedals_input->SelectedIndex == 3) {
		input_a_lon_des->Value = 0;
		input_a_lon_des->Enabled = true;
	}
}
private: System::Void input_a_lon_des_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (input_a_lon_des->Value > 0) {
		input_pedals_input->SelectedIndex = 1; //Throttle
	}
	else if (input_a_lon_des->Value < 0) {
		input_pedals_input->SelectedIndex = 0; //Braking
	}
	else if (input_a_lon_des->Value == 0) {
		input_pedals_input->SelectedIndex = 3; //Cruising
	}
}
private: System::Void input_steering_input_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (input_steering_input->SelectedIndex == 1) {
		input_delta_d_deg->Value = 0;
		input_beta_deg->Value = 0;
	}
}
private: System::Void input_beta_deg_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (input_beta_deg->Value == 0 && input_delta_d_deg->Value == 0) {
		input_steering_input->SelectedIndex = 1;
	}
	else {
		input_steering_input->SelectedIndex = 0;
	}
}
private: System::Void input_delta_d_deg_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (input_beta_deg->Value == 0 && input_delta_d_deg->Value == 0) {
		input_steering_input->SelectedIndex = 1;
	}
	else {
		input_steering_input->SelectedIndex = 0;
	}
}
private: System::Void input_max_beta_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (Math::Abs(input_beta_deg->Value) > input_max_beta->Value){
		input_beta_deg->Value = input_max_beta->Value * Math::Sign(input_beta_deg->Value);
	}
}
private: System::Void input_max_delta_d_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if (Math::Abs(input_delta_d_deg->Value) > input_max_delta_d->Value) {
		input_delta_d_deg->Value = input_max_delta_d->Value * Math::Sign(input_delta_d_deg->Value);
	}
}
private: System::Void input_num_beta_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if ((Convert::ToInt16(input_num_beta->Value) + Convert::ToInt16(input_num_delta_d->Value)) > 30) {
		input_num_delta_d->Value = 30 - input_num_beta->Value;
	}
}
private: System::Void input_num_delta_d_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	if((Convert::ToInt16(input_num_beta->Value) + Convert::ToInt16(input_num_delta_d->Value)) > 30) {
		input_num_beta->Value = 30 - input_num_delta_d->Value;
	}
}


private: System::Void input_diff_lock_f_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (input_diff_lock_f->SelectedIndex == 0) {
		input_diff_dTBR_f->Visible = false;
		input_diff_bTBR_f->Visible = false;
		input_diff_preload_f->Visible = false;
		input_diff_k_lock_f->Visible = false;

		fake_dTBR_f->Value = 1;
		fake_bTBR_f->Value = 1;
		fake_preload_f->Value = 0;
		fake_k_lock_f->Value = 0;
	}
	else if (input_diff_lock_f->SelectedIndex == 1) {
		input_diff_dTBR_f->Visible = true;
		input_diff_bTBR_f->Visible = true;
		input_diff_preload_f->Visible = false;
		input_diff_k_lock_f->Visible = false;

		fake_preload_f->Value = 0;
		fake_k_lock_f->Value = 0;
	}
	else if (input_diff_lock_f->SelectedIndex == 2) {
		input_diff_dTBR_f->Visible = true;
		input_diff_bTBR_f->Visible = true;
		input_diff_preload_f->Visible = true;
		input_diff_k_lock_f->Visible = false;

		fake_k_lock_f->Value = 0;
	}
	else if (input_diff_lock_f->SelectedIndex == 3) {
		input_diff_dTBR_f->Visible = false;
		input_diff_bTBR_f->Visible = false;
		input_diff_preload_f->Visible = true;
		input_diff_k_lock_f->Visible = true;

		fake_dTBR_f->Value = 100;
		fake_bTBR_f->Value = 100;
	}
	else if (input_diff_lock_f->SelectedIndex == 4) {
		input_diff_dTBR_f->Visible = false;
		input_diff_bTBR_f->Visible = false;
		input_diff_preload_f->Visible = false;
		input_diff_k_lock_f->Visible = false;

		fake_dTBR_f->Value = 100;
		fake_bTBR_f->Value = 100;
		fake_preload_f->Value = 0;
		fake_k_lock_f->Value = 0;
	}
}
private: System::Void input_diff_lock_r_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (input_diff_lock_r->SelectedIndex == 0) {
		input_diff_dTBR_r->Visible = false;
		input_diff_bTBR_r->Visible = false;
		input_diff_preload_r->Visible = false;
		input_diff_k_lock_r->Visible = false;

		fake_dTBR_r->Value = 1;
		fake_bTBR_r->Value = 1;
		fake_preload_r->Value = 0;
		fake_k_lock_r->Value = 0;
	}
	else if (input_diff_lock_r->SelectedIndex == 1) {
		input_diff_dTBR_r->Visible = true;
		input_diff_bTBR_r->Visible = true;
		input_diff_preload_r->Visible = false;
		input_diff_k_lock_r->Visible = false;

		fake_preload_r->Value = 0;
		fake_k_lock_r->Value = 0;
	}
	else if (input_diff_lock_r->SelectedIndex == 2) {
		input_diff_dTBR_r->Visible = true;
		input_diff_bTBR_r->Visible = true;
		input_diff_preload_r->Visible = true;
		input_diff_k_lock_r->Visible = false;

		fake_k_lock_r->Value = 0;
	}
	else if (input_diff_lock_r->SelectedIndex == 3) {
		input_diff_dTBR_r->Visible = false;
		input_diff_bTBR_r->Visible = false;
		input_diff_preload_r->Visible = true;
		input_diff_k_lock_r->Visible = true;

		fake_dTBR_r->Value = 100;
		fake_bTBR_r->Value = 100;
	}
	else if (input_diff_lock_r->SelectedIndex == 4) {
		input_diff_dTBR_r->Visible = false;
		input_diff_bTBR_r->Visible = false;
		input_diff_preload_r->Visible = false;
		input_diff_k_lock_r->Visible = false;

		fake_dTBR_r->Value = 100;
		fake_bTBR_r->Value = 100;
		fake_preload_r->Value = 0;
		fake_k_lock_r->Value = 0;
	}
}
private: System::Void spring_new_Click(System::Object^ sender, System::EventArgs^ e) {
	new_spring();
}
private: System::Void spring_delete_Click(System::Object^ sender, System::EventArgs^ e) {
	delete_spring();
}
private: System::Void spring_save_Click(System::Object^ sender, System::EventArgs^ e) {
	save_spring();
}
private: System::Void spring_name_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) {
	select_spring();
}
private: System::Void spring_add_Click(System::Object^ sender, System::EventArgs^ e) {
	bool cancel = false;
	for each (System::Object ^ item in spring_setups->Items) {
		if ((System::Convert::ToDouble(spring_stiffness->Value) == System::Convert::ToDouble(item))) {
			cancel = true;
			break;
		}
	}
	if (!cancel){ spring_setups->Items->Add(spring_stiffness->Value); }
	
	save_spring();
	write_spring_inputs();
}
private: System::Void Spring_remove_Click(System::Object^ sender, System::EventArgs^ e) {
	if (spring_setups->Items->Count <= 1)
	{
		MessageBox::Show("The ARB has only one setup.");
	}
	else {
		spring_setups->Items->Remove(spring_setups->Text);
		save_spring();
		write_spring_inputs();
	}
	
}
private: System::Void input_front_arb_selection_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	front_arb_setup();
}
private: System::Void input_rear_arb_selection_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	rear_arb_setup();
}
private: System::Void linkLabelThesis_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::String^ pdfPath = "Files\\Welcome_tab\\Gustavo_Drissen_Thesis.pdf";

	System::Diagnostics::Process::Start(pdfPath);
}
private: System::Void linkLabelUserGuide_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	System::String^ pdfPath = "Files\\Welcome_tab\\User_guide.pdf";

	System::Diagnostics::Process::Start(pdfPath);
}
private: System::Void linkLabelAdditions_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	   System::String^ pdfPath = "Files\\Welcome_tab\\Additions_to_Protto_VD_software_v1.pdf";

	   System::Diagnostics::Process::Start(pdfPath);
}
};
}

