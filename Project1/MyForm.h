#pragma once
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include "Inputs.h"
#include "Outputs.h"
#include "Vehicle.h"
#include "Tire.h"
#include "YMD.h"
#include "Tire_selection.h"
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
		Vehicle* vehicle;
		YMD_Carrier* YMD_carrier;
		Tire_selection* tire_selection;
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
	private: System::Windows::Forms::NumericUpDown^ input_delta_d_des;
	private: System::Windows::Forms::TextBox^ textBox30;
	private: System::Windows::Forms::NumericUpDown^ input_kappa_des;
	private: System::Windows::Forms::TextBox^ textBox31;
	private: System::Windows::Forms::NumericUpDown^ input_beta_des;
	private: System::Windows::Forms::TextBox^ textBox32;
	private: System::Windows::Forms::NumericUpDown^ input_R_min;
	private: System::Windows::Forms::TextBox^ textBox33;
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
	private: System::Windows::Forms::NumericUpDown^ input_lat_ratio_custom;
	private: System::Windows::Forms::TextBox^ textBox39;
	private: System::Windows::Forms::NumericUpDown^ input_lon_ratio_custom;
	private: System::Windows::Forms::ComboBox^ input_steering_input;
	private: System::Windows::Forms::TextBox^ textBox38;
	private: System::Windows::Forms::ComboBox^ input_pedals_input;
	private: System::Windows::Forms::TextBox^ textBox37;
	private: System::Windows::Forms::GroupBox^ groupBox10;
	private: System::Windows::Forms::TextBox^ textBox40;
	private: System::Windows::Forms::ComboBox^ input_corner_side;
	private: System::Windows::Forms::TextBox^ textBox41;
	private: System::Windows::Forms::ComboBox^ input_corner_type;
	private: System::Windows::Forms::TextBox^ textBox42;
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
private: System::Windows::Forms::Label^ output_F_z_fi;
private: System::Windows::Forms::Label^ output_F_z_fo;
private: System::Windows::Forms::Label^ output_F_z_ri;
private: System::Windows::Forms::Label^ output_F_z_ro;
private: System::Windows::Forms::Label^ output_F_x_comb_fi;
private: System::Windows::Forms::Label^ output_F_x_comb_fo;
private: System::Windows::Forms::Label^ output_F_x_comb_ri;
private: System::Windows::Forms::Label^ output_F_x_comb_ro;
private: System::Windows::Forms::Label^ output_F_y_comb_fi;
private: System::Windows::Forms::Label^ output_F_y_comb_fo;
private: System::Windows::Forms::Label^ output_F_y_comb_ri;
private: System::Windows::Forms::Label^ output_F_y_comb_ro;
private: System::Windows::Forms::Label^ output_F_lon_fi;
private: System::Windows::Forms::Label^ output_F_lon_fo;
private: System::Windows::Forms::Label^ output_F_lon_ri;
private: System::Windows::Forms::Label^ output_F_lon_ro;
private: System::Windows::Forms::Label^ output_F_lat_fi;
private: System::Windows::Forms::Label^ output_F_lat_fo;
private: System::Windows::Forms::Label^ output_F_lat_ri;
private: System::Windows::Forms::Label^ output_F_lat_ro;
private: System::Windows::Forms::Label^ output_kappa_fi;
private: System::Windows::Forms::Label^ output_kappa_fo;
private: System::Windows::Forms::Label^ output_kappa_ri;
private: System::Windows::Forms::Label^ output_kappa_ro;
private: System::Windows::Forms::Label^ output_alpha_fi;
private: System::Windows::Forms::Label^ output_alpha_fo;
private: System::Windows::Forms::Label^ output_alpha_ri;
private: System::Windows::Forms::Label^ output_alpha_ro;
private: System::Windows::Forms::Label^ output_T_fi;
private: System::Windows::Forms::Label^ output_T_fo;
private: System::Windows::Forms::Label^ output_T_ri;
private: System::Windows::Forms::Label^ output_T_ro;
private: System::Windows::Forms::Label^ output_V;
private: System::Windows::Forms::Label^ output_bias_now;
private: System::Windows::Forms::Label^ output_iter;
private: System::Windows::Forms::Label^ output_a_rad;



private: System::Windows::Forms::ComboBox^ input_rear_arb;
private: System::Windows::Forms::TextBox^ textBox84;
private: System::Windows::Forms::ComboBox^ input_front_arb;
private: System::Windows::Forms::TextBox^ textBox83;
private: System::Windows::Forms::GroupBox^ groupBox15;
private: System::Windows::Forms::NumericUpDown^ input_f_arb_1;
private: System::Windows::Forms::TextBox^ textBox86;
private: System::Windows::Forms::NumericUpDown^ input_f_arb_5;
private: System::Windows::Forms::TextBox^ textBox89;
private: System::Windows::Forms::NumericUpDown^ input_f_arb_4;
private: System::Windows::Forms::TextBox^ textBox88;
private: System::Windows::Forms::NumericUpDown^ input_f_arb_3;
private: System::Windows::Forms::TextBox^ textBox87;
private: System::Windows::Forms::NumericUpDown^ input_f_arb_2;
private: System::Windows::Forms::TextBox^ textBox85;
private: System::Windows::Forms::GroupBox^ groupBox16;
private: System::Windows::Forms::NumericUpDown^ input_r_arb_5;
private: System::Windows::Forms::TextBox^ textBox90;
private: System::Windows::Forms::NumericUpDown^ input_r_arb_4;
private: System::Windows::Forms::TextBox^ textBox91;
private: System::Windows::Forms::NumericUpDown^ input_r_arb_3;
private: System::Windows::Forms::TextBox^ textBox92;
private: System::Windows::Forms::NumericUpDown^ input_r_arb_2;
private: System::Windows::Forms::TextBox^ textBox93;
private: System::Windows::Forms::NumericUpDown^ input_r_arb_1;
private: System::Windows::Forms::TextBox^ textBox94;
private: System::Windows::Forms::GroupBox^ groupBox6;
private: System::Windows::Forms::SplitContainer^ splitContainer3;
private: System::Windows::Forms::TabControl^ tabControl3;
private: System::Windows::Forms::TabPage^ tabPage8;
private: System::Windows::Forms::TabPage^ tabPage9;
private: System::Windows::Forms::NumericUpDown^ input_h_r_f_0;
private: System::Windows::Forms::TextBox^ textBox19;
private: System::Windows::Forms::NumericUpDown^ input_h_r_f_1;
private: System::Windows::Forms::TextBox^ textBox21;
private: System::Windows::Forms::NumericUpDown^ input_h_r_f_2;
private: System::Windows::Forms::TextBox^ textBox95;
private: System::Windows::Forms::NumericUpDown^ input_p_r_r_0;
private: System::Windows::Forms::TextBox^ textBox111;
private: System::Windows::Forms::NumericUpDown^ input_p_r_r_1;
private: System::Windows::Forms::TextBox^ textBox112;
private: System::Windows::Forms::NumericUpDown^ input_p_r_r_2;
private: System::Windows::Forms::TextBox^ textBox113;
private: System::Windows::Forms::NumericUpDown^ input_p_r_f_0;
private: System::Windows::Forms::TextBox^ textBox105;
private: System::Windows::Forms::NumericUpDown^ input_p_r_f_1;
private: System::Windows::Forms::TextBox^ textBox106;
private: System::Windows::Forms::NumericUpDown^ input_p_r_f_2;

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
private: System::Windows::Forms::NumericUpDown^ input_p_p_r_0;

private: System::Windows::Forms::TextBox^ textBox108;
private: System::Windows::Forms::NumericUpDown^ input_p_p_r_1;

private: System::Windows::Forms::TextBox^ textBox109;
private: System::Windows::Forms::NumericUpDown^ input_p_p_r_2;

private: System::Windows::Forms::TextBox^ textBox110;
private: System::Windows::Forms::NumericUpDown^ input_p_p_f_0;

private: System::Windows::Forms::TextBox^ textBox114;
private: System::Windows::Forms::NumericUpDown^ input_p_p_f_1;

private: System::Windows::Forms::TextBox^ textBox115;
private: System::Windows::Forms::NumericUpDown^ input_p_p_f_2;


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
private: System::Windows::Forms::CheckBox^ input_force_a_lon;
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






		   Vehicle_outputs* vehicle_outputs;

	public:
		MyForm(void)
		{
			InitializeComponent();
			vehicle_inputs = new Vehicle_inputs();
			vehicle_outputs = new Vehicle_outputs();
			tire_inputs = new Tire_inputs();
			tire_list = gcnew System::Collections::Generic::List<System::String^>();
			vehicle = new Vehicle();
			YMD_carrier = new YMD_Carrier();
			tire_selection = new Tire_selection();
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
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::NumericUpDown^ input_m;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::NumericUpDown^ input_x;

	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::NumericUpDown^ input_m_u_ro;

	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::NumericUpDown^ input_m_u_ri;

	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::NumericUpDown^ input_m_u_fo;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::NumericUpDown^ input_m_u_fi;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->RUN_YMD = (gcnew System::Windows::Forms::Button());
			this->RUN = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
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
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->input_diff_type_r = (gcnew System::Windows::Forms::ComboBox());
			this->input_diff_type_f = (gcnew System::Windows::Forms::ComboBox());
			this->input_drive_config = (gcnew System::Windows::Forms::ComboBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->input_brake_type_r = (gcnew System::Windows::Forms::ComboBox());
			this->input_brake_type_f = (gcnew System::Windows::Forms::ComboBox());
			this->input_brake_config = (gcnew System::Windows::Forms::ComboBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->input_t_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_t_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_L = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->input_m_u_ro = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_h_CG = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->input_m_u_ri = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->input_m_u_fo = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->input_m_u_fi = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->input_y = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->input_x = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->input_m = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->input_k_susp_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_k_susp_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox16 = (gcnew System::Windows::Forms::GroupBox());
			this->input_r_arb_5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox90 = (gcnew System::Windows::Forms::TextBox());
			this->input_r_arb_4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox91 = (gcnew System::Windows::Forms::TextBox());
			this->input_r_arb_3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox92 = (gcnew System::Windows::Forms::TextBox());
			this->input_r_arb_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox93 = (gcnew System::Windows::Forms::TextBox());
			this->input_r_arb_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox94 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->input_k_p_C_dist = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_k_p_C_deg = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->input_k_r_C_dist = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_k_r_C_deg = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox15 = (gcnew System::Windows::Forms::GroupBox());
			this->input_f_arb_5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox89 = (gcnew System::Windows::Forms::TextBox());
			this->input_f_arb_4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox88 = (gcnew System::Windows::Forms::TextBox());
			this->input_f_arb_3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox87 = (gcnew System::Windows::Forms::TextBox());
			this->input_f_arb_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox85 = (gcnew System::Windows::Forms::TextBox());
			this->input_f_arb_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox86 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl3 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox17 = (gcnew System::Windows::Forms::GroupBox());
			this->input_p_p_r_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox108 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_p_r_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox109 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_p_r_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox110 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_p_f_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox114 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_p_f_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox115 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_p_f_2 = (gcnew System::Windows::Forms::NumericUpDown());
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
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->input_p_r_r_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox111 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_r_r_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox112 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_r_r_2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox113 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_r_f_0 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox105 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_r_f_1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox106 = (gcnew System::Windows::Forms::TextBox());
			this->input_p_r_f_2 = (gcnew System::Windows::Forms::NumericUpDown());
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
			this->tabPage9 = (gcnew System::Windows::Forms::TabPage());
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
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->input_rear_arb = (gcnew System::Windows::Forms::ComboBox());
			this->textBox84 = (gcnew System::Windows::Forms::TextBox());
			this->input_front_arb = (gcnew System::Windows::Forms::ComboBox());
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
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->input_a_lon_des = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_force_a_lon = (gcnew System::Windows::Forms::CheckBox());
			this->textBox184 = (gcnew System::Windows::Forms::TextBox());
			this->input_V_input = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_force_velocity = (gcnew System::Windows::Forms::CheckBox());
			this->textBox40 = (gcnew System::Windows::Forms::TextBox());
			this->input_lat_ratio_custom = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox39 = (gcnew System::Windows::Forms::TextBox());
			this->input_lon_ratio_custom = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_steering_input = (gcnew System::Windows::Forms::ComboBox());
			this->textBox38 = (gcnew System::Windows::Forms::TextBox());
			this->input_pedals_input = (gcnew System::Windows::Forms::ComboBox());
			this->textBox37 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->input_delta_d_des = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->input_kappa_des = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->input_beta_des = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->input_R_min = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->input_corner_side = (gcnew System::Windows::Forms::ComboBox());
			this->textBox41 = (gcnew System::Windows::Forms::TextBox());
			this->input_corner_type = (gcnew System::Windows::Forms::ComboBox());
			this->textBox42 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
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
			this->output_F_z_fi = (gcnew System::Windows::Forms::Label());
			this->output_F_z_fo = (gcnew System::Windows::Forms::Label());
			this->output_F_z_ri = (gcnew System::Windows::Forms::Label());
			this->output_F_z_ro = (gcnew System::Windows::Forms::Label());
			this->output_F_x_comb_fi = (gcnew System::Windows::Forms::Label());
			this->output_F_x_comb_fo = (gcnew System::Windows::Forms::Label());
			this->output_F_x_comb_ri = (gcnew System::Windows::Forms::Label());
			this->output_F_x_comb_ro = (gcnew System::Windows::Forms::Label());
			this->output_F_y_comb_fi = (gcnew System::Windows::Forms::Label());
			this->output_F_y_comb_fo = (gcnew System::Windows::Forms::Label());
			this->output_F_y_comb_ri = (gcnew System::Windows::Forms::Label());
			this->output_F_y_comb_ro = (gcnew System::Windows::Forms::Label());
			this->output_F_lon_fi = (gcnew System::Windows::Forms::Label());
			this->output_F_lon_fo = (gcnew System::Windows::Forms::Label());
			this->output_F_lon_ri = (gcnew System::Windows::Forms::Label());
			this->output_F_lon_ro = (gcnew System::Windows::Forms::Label());
			this->output_F_lat_fi = (gcnew System::Windows::Forms::Label());
			this->output_F_lat_fo = (gcnew System::Windows::Forms::Label());
			this->output_F_lat_ri = (gcnew System::Windows::Forms::Label());
			this->output_F_lat_ro = (gcnew System::Windows::Forms::Label());
			this->output_kappa_fi = (gcnew System::Windows::Forms::Label());
			this->output_kappa_fo = (gcnew System::Windows::Forms::Label());
			this->output_kappa_ri = (gcnew System::Windows::Forms::Label());
			this->output_kappa_ro = (gcnew System::Windows::Forms::Label());
			this->output_alpha_fi = (gcnew System::Windows::Forms::Label());
			this->output_alpha_fo = (gcnew System::Windows::Forms::Label());
			this->output_alpha_ri = (gcnew System::Windows::Forms::Label());
			this->output_alpha_ro = (gcnew System::Windows::Forms::Label());
			this->output_T_fi = (gcnew System::Windows::Forms::Label());
			this->output_T_fo = (gcnew System::Windows::Forms::Label());
			this->output_T_ri = (gcnew System::Windows::Forms::Label());
			this->output_T_ro = (gcnew System::Windows::Forms::Label());
			this->output_M_yaw = (gcnew System::Windows::Forms::Label());
			this->output_F_lat = (gcnew System::Windows::Forms::Label());
			this->output_phi_deg = (gcnew System::Windows::Forms::Label());
			this->output_F_lon = (gcnew System::Windows::Forms::Label());
			this->output_psi_deg = (gcnew System::Windows::Forms::Label());
			this->output_a_lon = (gcnew System::Windows::Forms::Label());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer4 = (gcnew System::Windows::Forms::SplitContainer());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->input_num_delta_d = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox182 = (gcnew System::Windows::Forms::TextBox());
			this->input_max_delta_d = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox180 = (gcnew System::Windows::Forms::TextBox());
			this->textBox181 = (gcnew System::Windows::Forms::TextBox());
			this->textBox183 = (gcnew System::Windows::Forms::TextBox());
			this->input_max_beta = (gcnew System::Windows::Forms::NumericUpDown());
			this->input_num_beta = (gcnew System::Windows::Forms::NumericUpDown());
			this->YMD = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->debugPage = (gcnew System::Windows::Forms::TabPage());
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
			this->output_iter_total = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage3->SuspendLayout();
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
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_t_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_t_f))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_L))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_ro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_CG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_ri))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_fo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_fi))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_y))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_x))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_susp_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_susp_f))->BeginInit();
			this->groupBox16->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_arb_5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_arb_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_arb_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_arb_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_arb_1))->BeginInit();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_p_C_dist))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_p_C_deg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_r_C_dist))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_r_C_deg))->BeginInit();
			this->groupBox15->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_f_arb_5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_f_arb_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_f_arb_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_f_arb_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_f_arb_1))->BeginInit();
			this->tabControl3->SuspendLayout();
			this->tabPage8->SuspendLayout();
			this->groupBox17->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_r_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_f_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_f_2))->BeginInit();
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
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_r_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_f_0))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_f_2))->BeginInit();
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
			this->tabPage9->SuspendLayout();
			this->groupBox20->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_bc_f_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_r_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_r_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_f_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_sc_f_2))->BeginInit();
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
			this->groupBox8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_a_lon_des))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_V_input))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_lat_ratio_custom))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_lon_ratio_custom))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_delta_d_des))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_kappa_des))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_beta_des))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_R_min))->BeginInit();
			this->groupBox10->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tabPage7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer4))->BeginInit();
			this->splitContainer4->Panel1->SuspendLayout();
			this->splitContainer4->Panel2->SuspendLayout();
			this->splitContainer4->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_num_delta_d))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_max_delta_d))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_max_beta))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_num_beta))->BeginInit();
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
			this->RUN->Text = L"RUN";
			this->RUN->UseVisualStyleBackColor = false;
			this->RUN->Click += gcnew System::EventHandler(this, &MyForm::RUN_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
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
			this->tabPage1->Location = System::Drawing::Point(4, 35);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1075, 636);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Welcome";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->groupBox21);
			this->tabPage3->Controls->Add(this->groupBox4);
			this->tabPage3->Controls->Add(this->groupBox3);
			this->tabPage3->Controls->Add(this->groupBox2);
			this->tabPage3->Controls->Add(this->groupBox1);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1075, 649);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Vehicle";
			this->tabPage3->UseVisualStyleBackColor = true;
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
			this->groupBox21->Location = System::Drawing::Point(497, 6);
			this->groupBox21->Name = L"groupBox21";
			this->groupBox21->Size = System::Drawing::Size(548, 288);
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
			this->textBox164->Text = L"Lateral drag distribution [%inner]";
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
			this->textBox168->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox168->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox168->Location = System::Drawing::Point(392, 164);
			this->textBox168->Multiline = true;
			this->textBox168->Name = L"textBox168";
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
			this->textBox169->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox169->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox169->Location = System::Drawing::Point(257, 164);
			this->textBox169->Multiline = true;
			this->textBox169->Name = L"textBox169";
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
			this->textBox170->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox170->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox170->Location = System::Drawing::Point(6, 164);
			this->textBox170->Multiline = true;
			this->textBox170->Name = L"textBox170";
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
			this->textBox171->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox171->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox171->Location = System::Drawing::Point(392, 123);
			this->textBox171->Multiline = true;
			this->textBox171->Name = L"textBox171";
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
			this->textBox172->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox172->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox172->Location = System::Drawing::Point(257, 123);
			this->textBox172->Multiline = true;
			this->textBox172->Name = L"textBox172";
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
			this->textBox173->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox173->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox173->Location = System::Drawing::Point(6, 110);
			this->textBox173->Multiline = true;
			this->textBox173->Name = L"textBox173";
			this->textBox173->Size = System::Drawing::Size(165, 44);
			this->textBox173->TabIndex = 59;
			this->textBox173->Text = L"Lateral downforcer distribution [%inner]";
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
			this->textBox174->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox174->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox174->Location = System::Drawing::Point(392, 83);
			this->textBox174->Multiline = true;
			this->textBox174->Name = L"textBox174";
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
			this->textBox175->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox175->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox175->Location = System::Drawing::Point(257, 83);
			this->textBox175->Multiline = true;
			this->textBox175->Name = L"textBox175";
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
			this->textBox176->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox176->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox176->Location = System::Drawing::Point(6, 70);
			this->textBox176->Multiline = true;
			this->textBox176->Name = L"textBox176";
			this->textBox176->Size = System::Drawing::Size(165, 44);
			this->textBox176->TabIndex = 53;
			this->textBox176->Text = L"Longitudinal downforcer distribution [%front]";
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
			this->textBox177->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox177->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox177->Location = System::Drawing::Point(392, 45);
			this->textBox177->Multiline = true;
			this->textBox177->Name = L"textBox177";
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
			this->textBox178->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox178->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox178->Location = System::Drawing::Point(257, 45);
			this->textBox178->Multiline = true;
			this->textBox178->Name = L"textBox178";
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
			this->textBox179->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox179->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox179->Location = System::Drawing::Point(6, 43);
			this->textBox179->Multiline = true;
			this->textBox179->Name = L"textBox179";
			this->textBox179->Size = System::Drawing::Size(165, 20);
			this->textBox179->TabIndex = 47;
			this->textBox179->Text = L"Total downforce [N]";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->input_diff_type_r);
			this->groupBox4->Controls->Add(this->input_diff_type_f);
			this->groupBox4->Controls->Add(this->input_drive_config);
			this->groupBox4->Controls->Add(this->textBox12);
			this->groupBox4->Controls->Add(this->textBox13);
			this->groupBox4->Controls->Add(this->textBox17);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox4->Location = System::Drawing::Point(250, 202);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(241, 190);
			this->groupBox4->TabIndex = 19;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Differentials";
			// 
			// input_diff_type_r
			// 
			this->input_diff_type_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_type_r->FormattingEnabled = true;
			this->input_diff_type_r->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Inboard", L"Outboard" });
			this->input_diff_type_r->Location = System::Drawing::Point(114, 152);
			this->input_diff_type_r->Name = L"input_diff_type_r";
			this->input_diff_type_r->Size = System::Drawing::Size(121, 27);
			this->input_diff_type_r->TabIndex = 9;
			this->input_diff_type_r->Text = L"Select";
			// 
			// input_diff_type_f
			// 
			this->input_diff_type_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_diff_type_f->FormattingEnabled = true;
			this->input_diff_type_f->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Inboard", L"Outboard" });
			this->input_diff_type_f->Location = System::Drawing::Point(114, 94);
			this->input_diff_type_f->Name = L"input_diff_type_f";
			this->input_diff_type_f->Size = System::Drawing::Size(121, 27);
			this->input_diff_type_f->TabIndex = 8;
			this->input_diff_type_f->Text = L"Select";
			// 
			// input_drive_config
			// 
			this->input_drive_config->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_drive_config->FormattingEnabled = true;
			this->input_drive_config->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"All wheels", L"Front wheels", L"Rear wheels" });
			this->input_drive_config->Location = System::Drawing::Point(114, 35);
			this->input_drive_config->Name = L"input_drive_config";
			this->input_drive_config->Size = System::Drawing::Size(121, 27);
			this->input_drive_config->TabIndex = 7;
			this->input_drive_config->Text = L"Select";
			// 
			// textBox12
			// 
			this->textBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox12->Location = System::Drawing::Point(6, 143);
			this->textBox12->Multiline = true;
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(102, 37);
			this->textBox12->TabIndex = 6;
			this->textBox12->Text = L"Rear differential";
			// 
			// textBox13
			// 
			this->textBox13->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox13->Location = System::Drawing::Point(6, 85);
			this->textBox13->Multiline = true;
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(102, 37);
			this->textBox13->TabIndex = 4;
			this->textBox13->Text = L"Front differential";
			// 
			// textBox17
			// 
			this->textBox17->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox17->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox17->Location = System::Drawing::Point(6, 32);
			this->textBox17->Multiline = true;
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(102, 37);
			this->textBox17->TabIndex = 2;
			this->textBox17->Text = L"Drive configuration";
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
			this->groupBox3->Location = System::Drawing::Point(250, 6);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(241, 190);
			this->groupBox3->TabIndex = 18;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Brakes";
			// 
			// input_brake_type_r
			// 
			this->input_brake_type_r->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_brake_type_r->FormattingEnabled = true;
			this->input_brake_type_r->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Inboard", L"Outboard" });
			this->input_brake_type_r->Location = System::Drawing::Point(114, 152);
			this->input_brake_type_r->Name = L"input_brake_type_r";
			this->input_brake_type_r->Size = System::Drawing::Size(121, 27);
			this->input_brake_type_r->TabIndex = 9;
			this->input_brake_type_r->Text = L"Select";
			// 
			// input_brake_type_f
			// 
			this->input_brake_type_f->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_brake_type_f->FormattingEnabled = true;
			this->input_brake_type_f->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Inboard", L"Outboard" });
			this->input_brake_type_f->Location = System::Drawing::Point(114, 94);
			this->input_brake_type_f->Name = L"input_brake_type_f";
			this->input_brake_type_f->Size = System::Drawing::Size(121, 27);
			this->input_brake_type_f->TabIndex = 8;
			this->input_brake_type_f->Text = L"Select";
			// 
			// input_brake_config
			// 
			this->input_brake_config->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_brake_config->FormattingEnabled = true;
			this->input_brake_config->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"All wheels", L"Front wheels", L"Rear wheels" });
			this->input_brake_config->Location = System::Drawing::Point(114, 35);
			this->input_brake_config->Name = L"input_brake_config";
			this->input_brake_config->Size = System::Drawing::Size(121, 27);
			this->input_brake_config->TabIndex = 7;
			this->input_brake_config->Text = L"Select";
			// 
			// textBox9
			// 
			this->textBox9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(6, 152);
			this->textBox9->Multiline = true;
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(102, 25);
			this->textBox9->TabIndex = 6;
			this->textBox9->Text = L"Rear brakes";
			// 
			// textBox10
			// 
			this->textBox10->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox10->Location = System::Drawing::Point(6, 97);
			this->textBox10->Multiline = true;
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(102, 15);
			this->textBox10->TabIndex = 4;
			this->textBox10->Text = L"Front brakes";
			// 
			// textBox11
			// 
			this->textBox11->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox11->Location = System::Drawing::Point(6, 32);
			this->textBox11->Multiline = true;
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(102, 37);
			this->textBox11->TabIndex = 2;
			this->textBox11->Text = L"Brake configuration";
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
			this->groupBox2->Location = System::Drawing::Point(3, 458);
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
			this->textBox14->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox14->Location = System::Drawing::Point(6, 143);
			this->textBox14->Multiline = true;
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(157, 25);
			this->textBox14->TabIndex = 6;
			this->textBox14->Text = L"Rear track [mm]";
			// 
			// textBox15
			// 
			this->textBox15->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox15->Location = System::Drawing::Point(6, 85);
			this->textBox15->Multiline = true;
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(157, 25);
			this->textBox15->TabIndex = 4;
			this->textBox15->Text = L"Front track [mm]";
			// 
			// textBox16
			// 
			this->textBox16->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox16->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox16->Location = System::Drawing::Point(6, 32);
			this->textBox16->Multiline = true;
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(157, 25);
			this->textBox16->TabIndex = 2;
			this->textBox16->Text = L"Wheelbase [mm]";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox8);
			this->groupBox1->Controls->Add(this->textBox7);
			this->groupBox1->Controls->Add(this->input_m_u_ro);
			this->groupBox1->Controls->Add(this->input_h_CG);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->input_m_u_ri);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->input_m_u_fo);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->input_m_u_fi);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->input_y);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->input_x);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->input_m);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(3, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(241, 452);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Mass";
			// 
			// textBox8
			// 
			this->textBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(6, 200);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(157, 47);
			this->textBox8->TabIndex = 16;
			this->textBox8->Text = L"Height of the center of gravity [mm]";
			// 
			// textBox7
			// 
			this->textBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(6, 408);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(157, 38);
			this->textBox7->TabIndex = 14;
			this->textBox7->Text = L"Rear outer unsprung masses [kg]";
			// 
			// input_m_u_ro
			// 
			this->input_m_u_ro->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_m_u_ro->DecimalPlaces = 2;
			this->input_m_u_ro->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_m_u_ro->Location = System::Drawing::Point(169, 418);
			this->input_m_u_ro->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_m_u_ro->Name = L"input_m_u_ro";
			this->input_m_u_ro->Size = System::Drawing::Size(66, 27);
			this->input_m_u_ro->TabIndex = 13;
			this->input_m_u_ro->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 0 });
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
			// textBox6
			// 
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(6, 357);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(157, 47);
			this->textBox6->TabIndex = 12;
			this->textBox6->Text = L"Rear inner unsprung masses [kg]";
			// 
			// input_m_u_ri
			// 
			this->input_m_u_ri->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_m_u_ri->DecimalPlaces = 2;
			this->input_m_u_ri->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_m_u_ri->Location = System::Drawing::Point(169, 367);
			this->input_m_u_ri->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_m_u_ri->Name = L"input_m_u_ri";
			this->input_m_u_ri->Size = System::Drawing::Size(66, 27);
			this->input_m_u_ri->TabIndex = 11;
			this->input_m_u_ri->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 0 });
			// 
			// textBox5
			// 
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(6, 306);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(157, 47);
			this->textBox5->TabIndex = 10;
			this->textBox5->Text = L"Front outer unsprung masses [kg]";
			// 
			// input_m_u_fo
			// 
			this->input_m_u_fo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_m_u_fo->DecimalPlaces = 2;
			this->input_m_u_fo->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_m_u_fo->Location = System::Drawing::Point(169, 316);
			this->input_m_u_fo->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_m_u_fo->Name = L"input_m_u_fo";
			this->input_m_u_fo->Size = System::Drawing::Size(66, 27);
			this->input_m_u_fo->TabIndex = 9;
			this->input_m_u_fo->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 0 });
			// 
			// textBox4
			// 
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(6, 253);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(157, 47);
			this->textBox4->TabIndex = 8;
			this->textBox4->Text = L"Front inner unsprung masses [kg]";
			// 
			// input_m_u_fi
			// 
			this->input_m_u_fi->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_m_u_fi->DecimalPlaces = 2;
			this->input_m_u_fi->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_m_u_fi->Location = System::Drawing::Point(169, 263);
			this->input_m_u_fi->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_m_u_fi->Name = L"input_m_u_fi";
			this->input_m_u_fi->Size = System::Drawing::Size(66, 27);
			this->input_m_u_fi->TabIndex = 7;
			this->input_m_u_fi->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 11, 0, 0, 0 });
			// 
			// textBox3
			// 
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(6, 143);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(157, 47);
			this->textBox3->TabIndex = 6;
			this->textBox3->Text = L"Lateral mass distribution [%right]";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
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
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(6, 85);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
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
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(6, 32);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
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
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->splitContainer3);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(1075, 649);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Suspension";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(3, 3);
			this->splitContainer3->Name = L"splitContainer3";
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->groupBox5);
			this->splitContainer3->Panel1->Controls->Add(this->groupBox16);
			this->splitContainer3->Panel1->Controls->Add(this->groupBox7);
			this->splitContainer3->Panel1->Controls->Add(this->groupBox15);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->tabControl3);
			this->splitContainer3->Size = System::Drawing::Size(1069, 643);
			this->splitContainer3->SplitterDistance = 500;
			this->splitContainer3->TabIndex = 23;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->textBox18);
			this->groupBox5->Controls->Add(this->input_k_susp_r);
			this->groupBox5->Controls->Add(this->input_k_susp_f);
			this->groupBox5->Controls->Add(this->textBox20);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox5->Location = System::Drawing::Point(3, 3);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(241, 138);
			this->groupBox5->TabIndex = 18;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Springs";
			// 
			// textBox18
			// 
			this->textBox18->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox18->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox18->Location = System::Drawing::Point(6, 83);
			this->textBox18->Multiline = true;
			this->textBox18->Name = L"textBox18";
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
			this->textBox20->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox20->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox20->Location = System::Drawing::Point(6, 32);
			this->textBox20->Multiline = true;
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(138, 45);
			this->textBox20->TabIndex = 2;
			this->textBox20->Text = L"Front springs stiffness [N/mm]";
			// 
			// groupBox16
			// 
			this->groupBox16->Controls->Add(this->input_r_arb_5);
			this->groupBox16->Controls->Add(this->textBox90);
			this->groupBox16->Controls->Add(this->input_r_arb_4);
			this->groupBox16->Controls->Add(this->textBox91);
			this->groupBox16->Controls->Add(this->input_r_arb_3);
			this->groupBox16->Controls->Add(this->textBox92);
			this->groupBox16->Controls->Add(this->input_r_arb_2);
			this->groupBox16->Controls->Add(this->textBox93);
			this->groupBox16->Controls->Add(this->input_r_arb_1);
			this->groupBox16->Controls->Add(this->textBox94);
			this->groupBox16->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox16->Location = System::Drawing::Point(250, 290);
			this->groupBox16->Name = L"groupBox16";
			this->groupBox16->Size = System::Drawing::Size(241, 285);
			this->groupBox16->TabIndex = 21;
			this->groupBox16->TabStop = false;
			this->groupBox16->Text = L"Rear ARB";
			// 
			// input_r_arb_5
			// 
			this->input_r_arb_5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_r_arb_5->DecimalPlaces = 2;
			this->input_r_arb_5->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_r_arb_5->Location = System::Drawing::Point(150, 245);
			this->input_r_arb_5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_r_arb_5->Name = L"input_r_arb_5";
			this->input_r_arb_5->Size = System::Drawing::Size(74, 27);
			this->input_r_arb_5->TabIndex = 9;
			this->input_r_arb_5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 95373, 0, 0, 196608 });
			// 
			// textBox90
			// 
			this->textBox90->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox90->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox90->Location = System::Drawing::Point(6, 236);
			this->textBox90->Multiline = true;
			this->textBox90->Name = L"textBox90";
			this->textBox90->Size = System::Drawing::Size(138, 45);
			this->textBox90->TabIndex = 10;
			this->textBox90->Text = L"Setup 5 stiffness [N/mm]";
			// 
			// input_r_arb_4
			// 
			this->input_r_arb_4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_r_arb_4->DecimalPlaces = 2;
			this->input_r_arb_4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_r_arb_4->Location = System::Drawing::Point(150, 194);
			this->input_r_arb_4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_r_arb_4->Name = L"input_r_arb_4";
			this->input_r_arb_4->Size = System::Drawing::Size(74, 27);
			this->input_r_arb_4->TabIndex = 7;
			this->input_r_arb_4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 95373, 0, 0, 196608 });
			// 
			// textBox91
			// 
			this->textBox91->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox91->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox91->Location = System::Drawing::Point(6, 185);
			this->textBox91->Multiline = true;
			this->textBox91->Name = L"textBox91";
			this->textBox91->Size = System::Drawing::Size(138, 45);
			this->textBox91->TabIndex = 8;
			this->textBox91->Text = L"Setup 4 stiffness [N/mm]";
			// 
			// input_r_arb_3
			// 
			this->input_r_arb_3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_r_arb_3->DecimalPlaces = 2;
			this->input_r_arb_3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_r_arb_3->Location = System::Drawing::Point(150, 143);
			this->input_r_arb_3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_r_arb_3->Name = L"input_r_arb_3";
			this->input_r_arb_3->Size = System::Drawing::Size(74, 27);
			this->input_r_arb_3->TabIndex = 5;
			this->input_r_arb_3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 95373, 0, 0, 196608 });
			// 
			// textBox92
			// 
			this->textBox92->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox92->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox92->Location = System::Drawing::Point(6, 134);
			this->textBox92->Multiline = true;
			this->textBox92->Name = L"textBox92";
			this->textBox92->Size = System::Drawing::Size(138, 45);
			this->textBox92->TabIndex = 6;
			this->textBox92->Text = L"Setup 3 stiffness [N/mm]";
			// 
			// input_r_arb_2
			// 
			this->input_r_arb_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_r_arb_2->DecimalPlaces = 2;
			this->input_r_arb_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_r_arb_2->Location = System::Drawing::Point(150, 92);
			this->input_r_arb_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_r_arb_2->Name = L"input_r_arb_2";
			this->input_r_arb_2->Size = System::Drawing::Size(74, 27);
			this->input_r_arb_2->TabIndex = 3;
			this->input_r_arb_2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 95373, 0, 0, 196608 });
			// 
			// textBox93
			// 
			this->textBox93->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox93->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox93->Location = System::Drawing::Point(6, 83);
			this->textBox93->Multiline = true;
			this->textBox93->Name = L"textBox93";
			this->textBox93->Size = System::Drawing::Size(138, 45);
			this->textBox93->TabIndex = 4;
			this->textBox93->Text = L"Setup 2 stiffness [N/mm]";
			// 
			// input_r_arb_1
			// 
			this->input_r_arb_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_r_arb_1->DecimalPlaces = 2;
			this->input_r_arb_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_r_arb_1->Location = System::Drawing::Point(150, 41);
			this->input_r_arb_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_r_arb_1->Name = L"input_r_arb_1";
			this->input_r_arb_1->Size = System::Drawing::Size(74, 27);
			this->input_r_arb_1->TabIndex = 0;
			this->input_r_arb_1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 95373, 0, 0, 196608 });
			// 
			// textBox94
			// 
			this->textBox94->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox94->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox94->Location = System::Drawing::Point(6, 32);
			this->textBox94->Multiline = true;
			this->textBox94->Name = L"textBox94";
			this->textBox94->Size = System::Drawing::Size(138, 45);
			this->textBox94->TabIndex = 2;
			this->textBox94->Text = L"Setup 1 stiffness [N/mm]";
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
			this->groupBox7->Location = System::Drawing::Point(3, 137);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(241, 282);
			this->groupBox7->TabIndex = 19;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Chassis";
			// 
			// textBox24
			// 
			this->textBox24->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox24->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox24->Location = System::Drawing::Point(6, 199);
			this->textBox24->Multiline = true;
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(138, 64);
			this->textBox24->TabIndex = 8;
			this->textBox24->Text = L"Chassis pitching stiffness distribution [%front]";
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
			this->input_k_p_C_deg->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			// 
			// textBox25
			// 
			this->textBox25->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox25->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox25->Location = System::Drawing::Point(6, 153);
			this->textBox25->Multiline = true;
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(138, 45);
			this->textBox25->TabIndex = 6;
			this->textBox25->Text = L"Chassis pitching stiffness [Nm/°]";
			// 
			// textBox22
			// 
			this->textBox22->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox22->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox22->Location = System::Drawing::Point(6, 83);
			this->textBox22->Multiline = true;
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(138, 64);
			this->textBox22->TabIndex = 4;
			this->textBox22->Text = L"Chassis torsional stiffness distribution [%front]";
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
			this->textBox23->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox23->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox23->Location = System::Drawing::Point(6, 32);
			this->textBox23->Multiline = true;
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(138, 45);
			this->textBox23->TabIndex = 2;
			this->textBox23->Text = L"Chassis torsional stiffness [Nm/°]";
			// 
			// groupBox15
			// 
			this->groupBox15->Controls->Add(this->input_f_arb_5);
			this->groupBox15->Controls->Add(this->textBox89);
			this->groupBox15->Controls->Add(this->input_f_arb_4);
			this->groupBox15->Controls->Add(this->textBox88);
			this->groupBox15->Controls->Add(this->input_f_arb_3);
			this->groupBox15->Controls->Add(this->textBox87);
			this->groupBox15->Controls->Add(this->input_f_arb_2);
			this->groupBox15->Controls->Add(this->textBox85);
			this->groupBox15->Controls->Add(this->input_f_arb_1);
			this->groupBox15->Controls->Add(this->textBox86);
			this->groupBox15->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox15->Location = System::Drawing::Point(250, 3);
			this->groupBox15->Name = L"groupBox15";
			this->groupBox15->Size = System::Drawing::Size(241, 285);
			this->groupBox15->TabIndex = 20;
			this->groupBox15->TabStop = false;
			this->groupBox15->Text = L"Front ARB";
			// 
			// input_f_arb_5
			// 
			this->input_f_arb_5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_f_arb_5->DecimalPlaces = 2;
			this->input_f_arb_5->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_f_arb_5->Location = System::Drawing::Point(150, 245);
			this->input_f_arb_5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_f_arb_5->Name = L"input_f_arb_5";
			this->input_f_arb_5->Size = System::Drawing::Size(74, 27);
			this->input_f_arb_5->TabIndex = 9;
			this->input_f_arb_5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 95373, 0, 0, 196608 });
			// 
			// textBox89
			// 
			this->textBox89->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox89->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox89->Location = System::Drawing::Point(6, 236);
			this->textBox89->Multiline = true;
			this->textBox89->Name = L"textBox89";
			this->textBox89->Size = System::Drawing::Size(138, 45);
			this->textBox89->TabIndex = 10;
			this->textBox89->Text = L"Setup 5 stiffness [N/mm]";
			// 
			// input_f_arb_4
			// 
			this->input_f_arb_4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_f_arb_4->DecimalPlaces = 2;
			this->input_f_arb_4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_f_arb_4->Location = System::Drawing::Point(150, 194);
			this->input_f_arb_4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_f_arb_4->Name = L"input_f_arb_4";
			this->input_f_arb_4->Size = System::Drawing::Size(74, 27);
			this->input_f_arb_4->TabIndex = 7;
			this->input_f_arb_4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 95373, 0, 0, 196608 });
			// 
			// textBox88
			// 
			this->textBox88->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox88->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox88->Location = System::Drawing::Point(6, 185);
			this->textBox88->Multiline = true;
			this->textBox88->Name = L"textBox88";
			this->textBox88->Size = System::Drawing::Size(138, 45);
			this->textBox88->TabIndex = 8;
			this->textBox88->Text = L"Setup 4 stiffness [N/mm]";
			// 
			// input_f_arb_3
			// 
			this->input_f_arb_3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_f_arb_3->DecimalPlaces = 2;
			this->input_f_arb_3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_f_arb_3->Location = System::Drawing::Point(150, 143);
			this->input_f_arb_3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_f_arb_3->Name = L"input_f_arb_3";
			this->input_f_arb_3->Size = System::Drawing::Size(74, 27);
			this->input_f_arb_3->TabIndex = 5;
			this->input_f_arb_3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 95373, 0, 0, 196608 });
			// 
			// textBox87
			// 
			this->textBox87->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox87->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox87->Location = System::Drawing::Point(6, 134);
			this->textBox87->Multiline = true;
			this->textBox87->Name = L"textBox87";
			this->textBox87->Size = System::Drawing::Size(138, 45);
			this->textBox87->TabIndex = 6;
			this->textBox87->Text = L"Setup 3 stiffness [N/mm]";
			// 
			// input_f_arb_2
			// 
			this->input_f_arb_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_f_arb_2->DecimalPlaces = 2;
			this->input_f_arb_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_f_arb_2->Location = System::Drawing::Point(150, 92);
			this->input_f_arb_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_f_arb_2->Name = L"input_f_arb_2";
			this->input_f_arb_2->Size = System::Drawing::Size(74, 27);
			this->input_f_arb_2->TabIndex = 3;
			this->input_f_arb_2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 95373, 0, 0, 196608 });
			// 
			// textBox85
			// 
			this->textBox85->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox85->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox85->Location = System::Drawing::Point(6, 83);
			this->textBox85->Multiline = true;
			this->textBox85->Name = L"textBox85";
			this->textBox85->Size = System::Drawing::Size(138, 45);
			this->textBox85->TabIndex = 4;
			this->textBox85->Text = L"Setup 2 stiffness [N/mm]";
			// 
			// input_f_arb_1
			// 
			this->input_f_arb_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_f_arb_1->DecimalPlaces = 2;
			this->input_f_arb_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_f_arb_1->Location = System::Drawing::Point(150, 41);
			this->input_f_arb_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_f_arb_1->Name = L"input_f_arb_1";
			this->input_f_arb_1->Size = System::Drawing::Size(74, 27);
			this->input_f_arb_1->TabIndex = 0;
			this->input_f_arb_1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 95373, 0, 0, 196608 });
			// 
			// textBox86
			// 
			this->textBox86->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox86->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox86->Location = System::Drawing::Point(6, 32);
			this->textBox86->Multiline = true;
			this->textBox86->Name = L"textBox86";
			this->textBox86->Size = System::Drawing::Size(138, 45);
			this->textBox86->TabIndex = 2;
			this->textBox86->Text = L"Setup 1 stiffness [N/mm]";
			// 
			// tabControl3
			// 
			this->tabControl3->Controls->Add(this->tabPage8);
			this->tabControl3->Controls->Add(this->tabPage9);
			this->tabControl3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl3->Location = System::Drawing::Point(0, 0);
			this->tabControl3->Name = L"tabControl3";
			this->tabControl3->SelectedIndex = 0;
			this->tabControl3->Size = System::Drawing::Size(565, 643);
			this->tabControl3->TabIndex = 23;
			// 
			// tabPage8
			// 
			this->tabPage8->Controls->Add(this->groupBox17);
			this->tabPage8->Controls->Add(this->groupBox6);
			this->tabPage8->Location = System::Drawing::Point(4, 35);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Padding = System::Windows::Forms::Padding(3);
			this->tabPage8->Size = System::Drawing::Size(557, 604);
			this->tabPage8->TabIndex = 0;
			this->tabPage8->Text = L"Geometric centers";
			this->tabPage8->UseVisualStyleBackColor = true;
			// 
			// groupBox17
			// 
			this->groupBox17->Controls->Add(this->input_p_p_r_0);
			this->groupBox17->Controls->Add(this->textBox108);
			this->groupBox17->Controls->Add(this->input_p_p_r_1);
			this->groupBox17->Controls->Add(this->textBox109);
			this->groupBox17->Controls->Add(this->input_p_p_r_2);
			this->groupBox17->Controls->Add(this->textBox110);
			this->groupBox17->Controls->Add(this->input_p_p_f_0);
			this->groupBox17->Controls->Add(this->textBox114);
			this->groupBox17->Controls->Add(this->input_p_p_f_1);
			this->groupBox17->Controls->Add(this->textBox115);
			this->groupBox17->Controls->Add(this->input_p_p_f_2);
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
			this->groupBox17->Location = System::Drawing::Point(3, 288);
			this->groupBox17->Name = L"groupBox17";
			this->groupBox17->Size = System::Drawing::Size(548, 288);
			this->groupBox17->TabIndex = 82;
			this->groupBox17->TabStop = false;
			this->groupBox17->Text = L"Pitch kinematics";
			// 
			// input_p_p_r_0
			// 
			this->input_p_p_r_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_p_r_0->DecimalPlaces = 4;
			this->input_p_p_r_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_p_r_0->Location = System::Drawing::Point(436, 246);
			this->input_p_p_r_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_p_r_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_p_r_0->Name = L"input_p_p_r_0";
			this->input_p_p_r_0->Size = System::Drawing::Size(74, 27);
			this->input_p_p_r_0->TabIndex = 81;
			// 
			// textBox108
			// 
			this->textBox108->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox108->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox108->Location = System::Drawing::Point(392, 248);
			this->textBox108->Multiline = true;
			this->textBox108->Name = L"textBox108";
			this->textBox108->Size = System::Drawing::Size(49, 25);
			this->textBox108->TabIndex = 80;
			this->textBox108->Text = L"* φ +";
			// 
			// input_p_p_r_1
			// 
			this->input_p_p_r_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_p_r_1->DecimalPlaces = 4;
			this->input_p_p_r_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_p_r_1->Location = System::Drawing::Point(312, 246);
			this->input_p_p_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_p_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_p_r_1->Name = L"input_p_p_r_1";
			this->input_p_p_r_1->Size = System::Drawing::Size(74, 27);
			this->input_p_p_r_1->TabIndex = 79;
			// 
			// textBox109
			// 
			this->textBox109->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox109->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox109->Location = System::Drawing::Point(257, 248);
			this->textBox109->Multiline = true;
			this->textBox109->Name = L"textBox109";
			this->textBox109->Size = System::Drawing::Size(49, 25);
			this->textBox109->TabIndex = 78;
			this->textBox109->Text = L"* φ² +";
			// 
			// input_p_p_r_2
			// 
			this->input_p_p_r_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_p_r_2->DecimalPlaces = 4;
			this->input_p_p_r_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_p_r_2->Location = System::Drawing::Point(177, 246);
			this->input_p_p_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_p_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_p_r_2->Name = L"input_p_p_r_2";
			this->input_p_p_r_2->Size = System::Drawing::Size(74, 27);
			this->input_p_p_r_2->TabIndex = 76;
			// 
			// textBox110
			// 
			this->textBox110->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox110->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox110->Location = System::Drawing::Point(6, 235);
			this->textBox110->Multiline = true;
			this->textBox110->Name = L"textBox110";
			this->textBox110->Size = System::Drawing::Size(165, 44);
			this->textBox110->TabIndex = 77;
			this->textBox110->Text = L"Rear pitch instant center height [mm]";
			// 
			// input_p_p_f_0
			// 
			this->input_p_p_f_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_p_f_0->DecimalPlaces = 4;
			this->input_p_p_f_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_p_f_0->Location = System::Drawing::Point(436, 204);
			this->input_p_p_f_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_p_f_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_p_f_0->Name = L"input_p_p_f_0";
			this->input_p_p_f_0->Size = System::Drawing::Size(74, 27);
			this->input_p_p_f_0->TabIndex = 75;
			// 
			// textBox114
			// 
			this->textBox114->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox114->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox114->Location = System::Drawing::Point(392, 206);
			this->textBox114->Multiline = true;
			this->textBox114->Name = L"textBox114";
			this->textBox114->Size = System::Drawing::Size(49, 25);
			this->textBox114->TabIndex = 74;
			this->textBox114->Text = L"* φ +";
			// 
			// input_p_p_f_1
			// 
			this->input_p_p_f_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_p_f_1->DecimalPlaces = 4;
			this->input_p_p_f_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_p_f_1->Location = System::Drawing::Point(312, 204);
			this->input_p_p_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_p_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_p_f_1->Name = L"input_p_p_f_1";
			this->input_p_p_f_1->Size = System::Drawing::Size(74, 27);
			this->input_p_p_f_1->TabIndex = 73;
			// 
			// textBox115
			// 
			this->textBox115->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox115->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox115->Location = System::Drawing::Point(257, 206);
			this->textBox115->Multiline = true;
			this->textBox115->Name = L"textBox115";
			this->textBox115->Size = System::Drawing::Size(49, 25);
			this->textBox115->TabIndex = 72;
			this->textBox115->Text = L"* φ² +";
			// 
			// input_p_p_f_2
			// 
			this->input_p_p_f_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_p_f_2->DecimalPlaces = 4;
			this->input_p_p_f_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_p_f_2->Location = System::Drawing::Point(177, 204);
			this->input_p_p_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_p_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_p_f_2->Name = L"input_p_p_f_2";
			this->input_p_p_f_2->Size = System::Drawing::Size(74, 27);
			this->input_p_p_f_2->TabIndex = 70;
			// 
			// textBox116
			// 
			this->textBox116->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox116->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox116->Location = System::Drawing::Point(6, 193);
			this->textBox116->Multiline = true;
			this->textBox116->Name = L"textBox116";
			this->textBox116->Size = System::Drawing::Size(165, 44);
			this->textBox116->TabIndex = 71;
			this->textBox116->Text = L"Front pitch instant center height [mm]";
			// 
			// input_n_p_o_0
			// 
			this->input_n_p_o_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_n_p_o_0->DecimalPlaces = 4;
			this->input_n_p_o_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_n_p_o_0->Location = System::Drawing::Point(436, 162);
			this->input_n_p_o_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_o_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_o_0->Name = L"input_n_p_o_0";
			this->input_n_p_o_0->Size = System::Drawing::Size(74, 27);
			this->input_n_p_o_0->TabIndex = 69;
			// 
			// textBox117
			// 
			this->textBox117->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox117->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox117->Location = System::Drawing::Point(392, 164);
			this->textBox117->Multiline = true;
			this->textBox117->Name = L"textBox117";
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
			this->input_n_p_o_1->Location = System::Drawing::Point(312, 162);
			this->input_n_p_o_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_o_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_o_1->Name = L"input_n_p_o_1";
			this->input_n_p_o_1->Size = System::Drawing::Size(74, 27);
			this->input_n_p_o_1->TabIndex = 67;
			// 
			// textBox118
			// 
			this->textBox118->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox118->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox118->Location = System::Drawing::Point(257, 164);
			this->textBox118->Multiline = true;
			this->textBox118->Name = L"textBox118";
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
			this->input_n_p_o_2->Location = System::Drawing::Point(177, 162);
			this->input_n_p_o_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_o_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_o_2->Name = L"input_n_p_o_2";
			this->input_n_p_o_2->Size = System::Drawing::Size(74, 27);
			this->input_n_p_o_2->TabIndex = 64;
			// 
			// textBox119
			// 
			this->textBox119->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox119->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox119->Location = System::Drawing::Point(6, 151);
			this->textBox119->Multiline = true;
			this->textBox119->Name = L"textBox119";
			this->textBox119->Size = System::Drawing::Size(165, 44);
			this->textBox119->TabIndex = 65;
			this->textBox119->Text = L"Outer pitch center lateral offset [mm]";
			// 
			// input_n_p_i_0
			// 
			this->input_n_p_i_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_n_p_i_0->DecimalPlaces = 4;
			this->input_n_p_i_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_n_p_i_0->Location = System::Drawing::Point(436, 121);
			this->input_n_p_i_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_i_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_i_0->Name = L"input_n_p_i_0";
			this->input_n_p_i_0->Size = System::Drawing::Size(74, 27);
			this->input_n_p_i_0->TabIndex = 63;
			// 
			// textBox120
			// 
			this->textBox120->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox120->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox120->Location = System::Drawing::Point(392, 123);
			this->textBox120->Multiline = true;
			this->textBox120->Name = L"textBox120";
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
			this->input_n_p_i_1->Location = System::Drawing::Point(312, 121);
			this->input_n_p_i_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_i_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_i_1->Name = L"input_n_p_i_1";
			this->input_n_p_i_1->Size = System::Drawing::Size(74, 27);
			this->input_n_p_i_1->TabIndex = 61;
			// 
			// textBox121
			// 
			this->textBox121->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox121->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox121->Location = System::Drawing::Point(257, 123);
			this->textBox121->Multiline = true;
			this->textBox121->Name = L"textBox121";
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
			this->input_n_p_i_2->Location = System::Drawing::Point(177, 121);
			this->input_n_p_i_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_n_p_i_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_n_p_i_2->Name = L"input_n_p_i_2";
			this->input_n_p_i_2->Size = System::Drawing::Size(74, 27);
			this->input_n_p_i_2->TabIndex = 58;
			// 
			// textBox122
			// 
			this->textBox122->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox122->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox122->Location = System::Drawing::Point(6, 110);
			this->textBox122->Multiline = true;
			this->textBox122->Name = L"textBox122";
			this->textBox122->Size = System::Drawing::Size(165, 44);
			this->textBox122->TabIndex = 59;
			this->textBox122->Text = L"Inner pitch center lateral offset [mm]";
			// 
			// input_h_p_o_0
			// 
			this->input_h_p_o_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_p_o_0->DecimalPlaces = 4;
			this->input_h_p_o_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_p_o_0->Location = System::Drawing::Point(436, 81);
			this->input_h_p_o_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_o_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_o_0->Name = L"input_h_p_o_0";
			this->input_h_p_o_0->Size = System::Drawing::Size(74, 27);
			this->input_h_p_o_0->TabIndex = 57;
			// 
			// textBox123
			// 
			this->textBox123->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox123->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox123->Location = System::Drawing::Point(392, 83);
			this->textBox123->Multiline = true;
			this->textBox123->Name = L"textBox123";
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
			this->input_h_p_o_1->Location = System::Drawing::Point(312, 81);
			this->input_h_p_o_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_o_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_o_1->Name = L"input_h_p_o_1";
			this->input_h_p_o_1->Size = System::Drawing::Size(74, 27);
			this->input_h_p_o_1->TabIndex = 55;
			// 
			// textBox124
			// 
			this->textBox124->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox124->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox124->Location = System::Drawing::Point(257, 83);
			this->textBox124->Multiline = true;
			this->textBox124->Name = L"textBox124";
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
			this->input_h_p_o_2->Location = System::Drawing::Point(177, 81);
			this->input_h_p_o_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_o_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_o_2->Name = L"input_h_p_o_2";
			this->input_h_p_o_2->Size = System::Drawing::Size(74, 27);
			this->input_h_p_o_2->TabIndex = 52;
			// 
			// textBox125
			// 
			this->textBox125->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox125->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox125->Location = System::Drawing::Point(6, 70);
			this->textBox125->Multiline = true;
			this->textBox125->Name = L"textBox125";
			this->textBox125->Size = System::Drawing::Size(165, 44);
			this->textBox125->TabIndex = 53;
			this->textBox125->Text = L"Outer pitch center height [mm]";
			// 
			// input_h_p_i_0
			// 
			this->input_h_p_i_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_p_i_0->DecimalPlaces = 4;
			this->input_h_p_i_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_p_i_0->Location = System::Drawing::Point(436, 43);
			this->input_h_p_i_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_i_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_i_0->Name = L"input_h_p_i_0";
			this->input_h_p_i_0->Size = System::Drawing::Size(74, 27);
			this->input_h_p_i_0->TabIndex = 51;
			// 
			// textBox126
			// 
			this->textBox126->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox126->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox126->Location = System::Drawing::Point(392, 45);
			this->textBox126->Multiline = true;
			this->textBox126->Name = L"textBox126";
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
			this->input_h_p_i_1->Location = System::Drawing::Point(312, 43);
			this->input_h_p_i_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_i_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_i_1->Name = L"input_h_p_i_1";
			this->input_h_p_i_1->Size = System::Drawing::Size(74, 27);
			this->input_h_p_i_1->TabIndex = 49;
			// 
			// textBox127
			// 
			this->textBox127->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox127->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox127->Location = System::Drawing::Point(257, 45);
			this->textBox127->Multiline = true;
			this->textBox127->Name = L"textBox127";
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
			this->input_h_p_i_2->Location = System::Drawing::Point(177, 43);
			this->input_h_p_i_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_p_i_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_p_i_2->Name = L"input_h_p_i_2";
			this->input_h_p_i_2->Size = System::Drawing::Size(74, 27);
			this->input_h_p_i_2->TabIndex = 46;
			// 
			// textBox128
			// 
			this->textBox128->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox128->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox128->Location = System::Drawing::Point(6, 32);
			this->textBox128->Multiline = true;
			this->textBox128->Name = L"textBox128";
			this->textBox128->Size = System::Drawing::Size(165, 44);
			this->textBox128->TabIndex = 47;
			this->textBox128->Text = L"Inner pitch center height [mm]";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->input_p_r_r_0);
			this->groupBox6->Controls->Add(this->textBox111);
			this->groupBox6->Controls->Add(this->input_p_r_r_1);
			this->groupBox6->Controls->Add(this->textBox112);
			this->groupBox6->Controls->Add(this->input_p_r_r_2);
			this->groupBox6->Controls->Add(this->textBox113);
			this->groupBox6->Controls->Add(this->input_p_r_f_0);
			this->groupBox6->Controls->Add(this->textBox105);
			this->groupBox6->Controls->Add(this->input_p_r_f_1);
			this->groupBox6->Controls->Add(this->textBox106);
			this->groupBox6->Controls->Add(this->input_p_r_f_2);
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
			this->groupBox6->Location = System::Drawing::Point(3, 3);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(548, 288);
			this->groupBox6->TabIndex = 22;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Roll kinematics";
			// 
			// input_p_r_r_0
			// 
			this->input_p_r_r_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_r_r_0->DecimalPlaces = 4;
			this->input_p_r_r_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_r_r_0->Location = System::Drawing::Point(436, 246);
			this->input_p_r_r_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_r_r_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_r_r_0->Name = L"input_p_r_r_0";
			this->input_p_r_r_0->Size = System::Drawing::Size(74, 27);
			this->input_p_r_r_0->TabIndex = 81;
			// 
			// textBox111
			// 
			this->textBox111->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox111->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox111->Location = System::Drawing::Point(392, 248);
			this->textBox111->Multiline = true;
			this->textBox111->Name = L"textBox111";
			this->textBox111->Size = System::Drawing::Size(49, 25);
			this->textBox111->TabIndex = 80;
			this->textBox111->Text = L"* Ψ +";
			// 
			// input_p_r_r_1
			// 
			this->input_p_r_r_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_r_r_1->DecimalPlaces = 4;
			this->input_p_r_r_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_r_r_1->Location = System::Drawing::Point(312, 246);
			this->input_p_r_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_r_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_r_r_1->Name = L"input_p_r_r_1";
			this->input_p_r_r_1->Size = System::Drawing::Size(74, 27);
			this->input_p_r_r_1->TabIndex = 79;
			// 
			// textBox112
			// 
			this->textBox112->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox112->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox112->Location = System::Drawing::Point(257, 248);
			this->textBox112->Multiline = true;
			this->textBox112->Name = L"textBox112";
			this->textBox112->Size = System::Drawing::Size(49, 25);
			this->textBox112->TabIndex = 78;
			this->textBox112->Text = L"* Ψ² +";
			// 
			// input_p_r_r_2
			// 
			this->input_p_r_r_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_r_r_2->DecimalPlaces = 4;
			this->input_p_r_r_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_r_r_2->Location = System::Drawing::Point(177, 246);
			this->input_p_r_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_r_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_r_r_2->Name = L"input_p_r_r_2";
			this->input_p_r_r_2->Size = System::Drawing::Size(74, 27);
			this->input_p_r_r_2->TabIndex = 76;
			// 
			// textBox113
			// 
			this->textBox113->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox113->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox113->Location = System::Drawing::Point(6, 235);
			this->textBox113->Multiline = true;
			this->textBox113->Name = L"textBox113";
			this->textBox113->Size = System::Drawing::Size(165, 44);
			this->textBox113->TabIndex = 77;
			this->textBox113->Text = L"Rear roll instant center height [mm]";
			// 
			// input_p_r_f_0
			// 
			this->input_p_r_f_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_r_f_0->DecimalPlaces = 4;
			this->input_p_r_f_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_r_f_0->Location = System::Drawing::Point(436, 204);
			this->input_p_r_f_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_r_f_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_r_f_0->Name = L"input_p_r_f_0";
			this->input_p_r_f_0->Size = System::Drawing::Size(74, 27);
			this->input_p_r_f_0->TabIndex = 75;
			// 
			// textBox105
			// 
			this->textBox105->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox105->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox105->Location = System::Drawing::Point(392, 206);
			this->textBox105->Multiline = true;
			this->textBox105->Name = L"textBox105";
			this->textBox105->Size = System::Drawing::Size(49, 25);
			this->textBox105->TabIndex = 74;
			this->textBox105->Text = L"* Ψ +";
			// 
			// input_p_r_f_1
			// 
			this->input_p_r_f_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_r_f_1->DecimalPlaces = 4;
			this->input_p_r_f_1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_r_f_1->Location = System::Drawing::Point(312, 204);
			this->input_p_r_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_r_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_r_f_1->Name = L"input_p_r_f_1";
			this->input_p_r_f_1->Size = System::Drawing::Size(74, 27);
			this->input_p_r_f_1->TabIndex = 73;
			// 
			// textBox106
			// 
			this->textBox106->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox106->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox106->Location = System::Drawing::Point(257, 206);
			this->textBox106->Multiline = true;
			this->textBox106->Name = L"textBox106";
			this->textBox106->Size = System::Drawing::Size(49, 25);
			this->textBox106->TabIndex = 72;
			this->textBox106->Text = L"* Ψ² +";
			// 
			// input_p_r_f_2
			// 
			this->input_p_r_f_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_p_r_f_2->DecimalPlaces = 4;
			this->input_p_r_f_2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_p_r_f_2->Location = System::Drawing::Point(177, 204);
			this->input_p_r_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_p_r_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_p_r_f_2->Name = L"input_p_r_f_2";
			this->input_p_r_f_2->Size = System::Drawing::Size(74, 27);
			this->input_p_r_f_2->TabIndex = 70;
			// 
			// textBox107
			// 
			this->textBox107->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox107->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox107->Location = System::Drawing::Point(6, 193);
			this->textBox107->Multiline = true;
			this->textBox107->Name = L"textBox107";
			this->textBox107->Size = System::Drawing::Size(165, 44);
			this->textBox107->TabIndex = 71;
			this->textBox107->Text = L"Front roll instant center height [mm]";
			// 
			// input_off_r_r_0
			// 
			this->input_off_r_r_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_off_r_r_0->DecimalPlaces = 4;
			this->input_off_r_r_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_off_r_r_0->Location = System::Drawing::Point(436, 162);
			this->input_off_r_r_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_r_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_r_0->Name = L"input_off_r_r_0";
			this->input_off_r_r_0->Size = System::Drawing::Size(74, 27);
			this->input_off_r_r_0->TabIndex = 69;
			// 
			// textBox102
			// 
			this->textBox102->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox102->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox102->Location = System::Drawing::Point(392, 164);
			this->textBox102->Multiline = true;
			this->textBox102->Name = L"textBox102";
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
			this->input_off_r_r_1->Location = System::Drawing::Point(312, 162);
			this->input_off_r_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_r_1->Name = L"input_off_r_r_1";
			this->input_off_r_r_1->Size = System::Drawing::Size(74, 27);
			this->input_off_r_r_1->TabIndex = 67;
			// 
			// textBox103
			// 
			this->textBox103->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox103->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox103->Location = System::Drawing::Point(257, 164);
			this->textBox103->Multiline = true;
			this->textBox103->Name = L"textBox103";
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
			this->input_off_r_r_2->Location = System::Drawing::Point(177, 162);
			this->input_off_r_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_r_2->Name = L"input_off_r_r_2";
			this->input_off_r_r_2->Size = System::Drawing::Size(74, 27);
			this->input_off_r_r_2->TabIndex = 64;
			// 
			// textBox104
			// 
			this->textBox104->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox104->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox104->Location = System::Drawing::Point(6, 151);
			this->textBox104->Multiline = true;
			this->textBox104->Name = L"textBox104";
			this->textBox104->Size = System::Drawing::Size(165, 44);
			this->textBox104->TabIndex = 65;
			this->textBox104->Text = L"Rear roll center lateral offset [mm]";
			// 
			// input_off_r_f_0
			// 
			this->input_off_r_f_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_off_r_f_0->DecimalPlaces = 4;
			this->input_off_r_f_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_off_r_f_0->Location = System::Drawing::Point(436, 121);
			this->input_off_r_f_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_f_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_f_0->Name = L"input_off_r_f_0";
			this->input_off_r_f_0->Size = System::Drawing::Size(74, 27);
			this->input_off_r_f_0->TabIndex = 63;
			// 
			// textBox99
			// 
			this->textBox99->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox99->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox99->Location = System::Drawing::Point(392, 123);
			this->textBox99->Multiline = true;
			this->textBox99->Name = L"textBox99";
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
			this->input_off_r_f_1->Location = System::Drawing::Point(312, 121);
			this->input_off_r_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_f_1->Name = L"input_off_r_f_1";
			this->input_off_r_f_1->Size = System::Drawing::Size(74, 27);
			this->input_off_r_f_1->TabIndex = 61;
			// 
			// textBox100
			// 
			this->textBox100->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox100->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox100->Location = System::Drawing::Point(257, 123);
			this->textBox100->Multiline = true;
			this->textBox100->Name = L"textBox100";
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
			this->input_off_r_f_2->Location = System::Drawing::Point(177, 121);
			this->input_off_r_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_off_r_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_off_r_f_2->Name = L"input_off_r_f_2";
			this->input_off_r_f_2->Size = System::Drawing::Size(74, 27);
			this->input_off_r_f_2->TabIndex = 58;
			// 
			// textBox101
			// 
			this->textBox101->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox101->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox101->Location = System::Drawing::Point(6, 110);
			this->textBox101->Multiline = true;
			this->textBox101->Name = L"textBox101";
			this->textBox101->Size = System::Drawing::Size(165, 44);
			this->textBox101->TabIndex = 59;
			this->textBox101->Text = L"Front roll center lateral offset [mm]";
			// 
			// input_h_r_r_0
			// 
			this->input_h_r_r_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_r_r_0->DecimalPlaces = 4;
			this->input_h_r_r_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_r_r_0->Location = System::Drawing::Point(436, 81);
			this->input_h_r_r_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_r_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_r_0->Name = L"input_h_r_r_0";
			this->input_h_r_r_0->Size = System::Drawing::Size(74, 27);
			this->input_h_r_r_0->TabIndex = 57;
			// 
			// textBox96
			// 
			this->textBox96->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox96->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox96->Location = System::Drawing::Point(392, 83);
			this->textBox96->Multiline = true;
			this->textBox96->Name = L"textBox96";
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
			this->input_h_r_r_1->Location = System::Drawing::Point(312, 81);
			this->input_h_r_r_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_r_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_r_1->Name = L"input_h_r_r_1";
			this->input_h_r_r_1->Size = System::Drawing::Size(74, 27);
			this->input_h_r_r_1->TabIndex = 55;
			// 
			// textBox97
			// 
			this->textBox97->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox97->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox97->Location = System::Drawing::Point(257, 83);
			this->textBox97->Multiline = true;
			this->textBox97->Name = L"textBox97";
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
			this->input_h_r_r_2->Location = System::Drawing::Point(177, 81);
			this->input_h_r_r_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_r_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_r_2->Name = L"input_h_r_r_2";
			this->input_h_r_r_2->Size = System::Drawing::Size(74, 27);
			this->input_h_r_r_2->TabIndex = 52;
			// 
			// textBox98
			// 
			this->textBox98->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox98->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox98->Location = System::Drawing::Point(6, 70);
			this->textBox98->Multiline = true;
			this->textBox98->Name = L"textBox98";
			this->textBox98->Size = System::Drawing::Size(165, 44);
			this->textBox98->TabIndex = 53;
			this->textBox98->Text = L"Rear roll center height [mm]";
			// 
			// input_h_r_f_0
			// 
			this->input_h_r_f_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_h_r_f_0->DecimalPlaces = 4;
			this->input_h_r_f_0->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_h_r_f_0->Location = System::Drawing::Point(436, 43);
			this->input_h_r_f_0->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_f_0->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_f_0->Name = L"input_h_r_f_0";
			this->input_h_r_f_0->Size = System::Drawing::Size(74, 27);
			this->input_h_r_f_0->TabIndex = 51;
			// 
			// textBox19
			// 
			this->textBox19->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox19->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox19->Location = System::Drawing::Point(392, 45);
			this->textBox19->Multiline = true;
			this->textBox19->Name = L"textBox19";
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
			this->input_h_r_f_1->Location = System::Drawing::Point(312, 43);
			this->input_h_r_f_1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_f_1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_f_1->Name = L"input_h_r_f_1";
			this->input_h_r_f_1->Size = System::Drawing::Size(74, 27);
			this->input_h_r_f_1->TabIndex = 49;
			// 
			// textBox21
			// 
			this->textBox21->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox21->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox21->Location = System::Drawing::Point(257, 45);
			this->textBox21->Multiline = true;
			this->textBox21->Name = L"textBox21";
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
			this->input_h_r_f_2->Location = System::Drawing::Point(177, 43);
			this->input_h_r_f_2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_h_r_f_2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_h_r_f_2->Name = L"input_h_r_f_2";
			this->input_h_r_f_2->Size = System::Drawing::Size(74, 27);
			this->input_h_r_f_2->TabIndex = 46;
			// 
			// textBox95
			// 
			this->textBox95->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox95->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox95->Location = System::Drawing::Point(6, 32);
			this->textBox95->Multiline = true;
			this->textBox95->Name = L"textBox95";
			this->textBox95->Size = System::Drawing::Size(165, 44);
			this->textBox95->TabIndex = 47;
			this->textBox95->Text = L"Front roll center height [mm]";
			// 
			// tabPage9
			// 
			this->tabPage9->Controls->Add(this->groupBox20);
			this->tabPage9->Controls->Add(this->groupBox19);
			this->tabPage9->Controls->Add(this->groupBox18);
			this->tabPage9->Location = System::Drawing::Point(4, 22);
			this->tabPage9->Name = L"tabPage9";
			this->tabPage9->Padding = System::Windows::Forms::Padding(3);
			this->tabPage9->Size = System::Drawing::Size(557, 617);
			this->tabPage9->TabIndex = 1;
			this->tabPage9->Text = L"Other kinematics";
			this->tabPage9->UseVisualStyleBackColor = true;
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
			this->groupBox20->Location = System::Drawing::Point(3, 338);
			this->groupBox20->Name = L"groupBox20";
			this->groupBox20->Size = System::Drawing::Size(548, 198);
			this->groupBox20->TabIndex = 71;
			this->groupBox20->TabStop = false;
			this->groupBox20->Text = L"Camber";
			// 
			// textBox159
			// 
			this->textBox159->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox159->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox159->Location = System::Drawing::Point(392, 153);
			this->textBox159->Multiline = true;
			this->textBox159->Name = L"textBox159";
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
			this->textBox160->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox160->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox160->Location = System::Drawing::Point(257, 153);
			this->textBox160->Multiline = true;
			this->textBox160->Name = L"textBox160";
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
			this->textBox161->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox161->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox161->Location = System::Drawing::Point(6, 153);
			this->textBox161->Multiline = true;
			this->textBox161->Name = L"textBox161";
			this->textBox161->Size = System::Drawing::Size(165, 25);
			this->textBox161->TabIndex = 65;
			this->textBox161->Text = L"Rear bump [°]";
			// 
			// textBox129
			// 
			this->textBox129->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox129->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox129->Location = System::Drawing::Point(392, 110);
			this->textBox129->Multiline = true;
			this->textBox129->Name = L"textBox129";
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
			this->textBox130->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox130->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox130->Location = System::Drawing::Point(257, 110);
			this->textBox130->Multiline = true;
			this->textBox130->Name = L"textBox130";
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
			this->textBox131->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox131->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox131->Location = System::Drawing::Point(6, 110);
			this->textBox131->Multiline = true;
			this->textBox131->Name = L"textBox131";
			this->textBox131->Size = System::Drawing::Size(165, 25);
			this->textBox131->TabIndex = 59;
			this->textBox131->Text = L"Front bump [°]";
			// 
			// textBox153
			// 
			this->textBox153->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox153->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox153->Location = System::Drawing::Point(392, 70);
			this->textBox153->Multiline = true;
			this->textBox153->Name = L"textBox153";
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
			this->textBox154->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox154->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox154->Location = System::Drawing::Point(257, 70);
			this->textBox154->Multiline = true;
			this->textBox154->Name = L"textBox154";
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
			this->textBox155->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox155->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox155->Location = System::Drawing::Point(6, 70);
			this->textBox155->Multiline = true;
			this->textBox155->Name = L"textBox155";
			this->textBox155->Size = System::Drawing::Size(165, 23);
			this->textBox155->TabIndex = 53;
			this->textBox155->Text = L"Rear steering [°]";
			// 
			// textBox156
			// 
			this->textBox156->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox156->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox156->Location = System::Drawing::Point(392, 32);
			this->textBox156->Multiline = true;
			this->textBox156->Name = L"textBox156";
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
			this->textBox157->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox157->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox157->Location = System::Drawing::Point(257, 32);
			this->textBox157->Multiline = true;
			this->textBox157->Name = L"textBox157";
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
			this->textBox158->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox158->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox158->Location = System::Drawing::Point(6, 32);
			this->textBox158->Multiline = true;
			this->textBox158->Name = L"textBox158";
			this->textBox158->Size = System::Drawing::Size(165, 32);
			this->textBox158->TabIndex = 47;
			this->textBox158->Text = L"Front steering [°]";
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
			this->groupBox19->Location = System::Drawing::Point(3, 188);
			this->groupBox19->Name = L"groupBox19";
			this->groupBox19->Size = System::Drawing::Size(548, 144);
			this->groupBox19->TabIndex = 70;
			this->groupBox19->TabStop = false;
			this->groupBox19->Text = L"Steering";
			// 
			// textBox132
			// 
			this->textBox132->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox132->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox132->Location = System::Drawing::Point(392, 110);
			this->textBox132->Multiline = true;
			this->textBox132->Name = L"textBox132";
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
			this->textBox133->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox133->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox133->Location = System::Drawing::Point(257, 110);
			this->textBox133->Multiline = true;
			this->textBox133->Name = L"textBox133";
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
			this->textBox134->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox134->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox134->Location = System::Drawing::Point(6, 110);
			this->textBox134->Multiline = true;
			this->textBox134->Name = L"textBox134";
			this->textBox134->Size = System::Drawing::Size(165, 25);
			this->textBox134->TabIndex = 59;
			this->textBox134->Text = L"Rear bump steer [°]";
			// 
			// textBox147
			// 
			this->textBox147->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox147->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox147->Location = System::Drawing::Point(392, 70);
			this->textBox147->Multiline = true;
			this->textBox147->Name = L"textBox147";
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
			this->textBox148->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox148->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox148->Location = System::Drawing::Point(257, 70);
			this->textBox148->Multiline = true;
			this->textBox148->Name = L"textBox148";
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
			this->textBox149->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox149->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox149->Location = System::Drawing::Point(6, 70);
			this->textBox149->Multiline = true;
			this->textBox149->Name = L"textBox149";
			this->textBox149->Size = System::Drawing::Size(165, 23);
			this->textBox149->TabIndex = 53;
			this->textBox149->Text = L"Front bump steer [°]";
			// 
			// textBox150
			// 
			this->textBox150->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox150->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox150->Location = System::Drawing::Point(392, 32);
			this->textBox150->Multiline = true;
			this->textBox150->Name = L"textBox150";
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
			this->textBox151->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox151->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox151->Location = System::Drawing::Point(257, 32);
			this->textBox151->Multiline = true;
			this->textBox151->Name = L"textBox151";
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
			this->textBox152->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox152->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox152->Location = System::Drawing::Point(6, 32);
			this->textBox152->Multiline = true;
			this->textBox152->Name = L"textBox152";
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
			this->groupBox18->Location = System::Drawing::Point(3, 3);
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
			this->textBox135->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox135->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox135->Location = System::Drawing::Point(392, 151);
			this->textBox135->Multiline = true;
			this->textBox135->Name = L"textBox135";
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
			this->textBox136->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox136->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox136->Location = System::Drawing::Point(257, 151);
			this->textBox136->Multiline = true;
			this->textBox136->Name = L"textBox136";
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
			this->textBox137->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox137->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox137->Location = System::Drawing::Point(6, 151);
			this->textBox137->Multiline = true;
			this->textBox137->Name = L"textBox137";
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
			this->textBox138->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox138->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox138->Location = System::Drawing::Point(392, 110);
			this->textBox138->Multiline = true;
			this->textBox138->Name = L"textBox138";
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
			this->textBox139->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox139->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox139->Location = System::Drawing::Point(257, 110);
			this->textBox139->Multiline = true;
			this->textBox139->Name = L"textBox139";
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
			this->textBox140->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox140->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox140->Location = System::Drawing::Point(6, 110);
			this->textBox140->Multiline = true;
			this->textBox140->Name = L"textBox140";
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
			this->textBox141->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox141->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox141->Location = System::Drawing::Point(392, 70);
			this->textBox141->Multiline = true;
			this->textBox141->Name = L"textBox141";
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
			this->textBox142->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox142->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox142->Location = System::Drawing::Point(257, 70);
			this->textBox142->Multiline = true;
			this->textBox142->Name = L"textBox142";
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
			this->textBox143->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox143->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox143->Location = System::Drawing::Point(6, 70);
			this->textBox143->Multiline = true;
			this->textBox143->Name = L"textBox143";
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
			this->textBox144->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox144->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox144->Location = System::Drawing::Point(392, 32);
			this->textBox144->Multiline = true;
			this->textBox144->Name = L"textBox144";
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
			this->textBox145->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox145->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox145->Location = System::Drawing::Point(257, 32);
			this->textBox145->Multiline = true;
			this->textBox145->Name = L"textBox145";
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
			this->textBox146->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox146->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox146->Location = System::Drawing::Point(6, 32);
			this->textBox146->Multiline = true;
			this->textBox146->Name = L"textBox146";
			this->textBox146->Size = System::Drawing::Size(165, 32);
			this->textBox146->TabIndex = 47;
			this->textBox146->Text = L"Front springs [mm/mm]";
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
			this->groupBox14->Location = System::Drawing::Point(392, 300);
			this->groupBox14->Name = L"groupBox14";
			this->groupBox14->Size = System::Drawing::Size(241, 113);
			this->groupBox14->TabIndex = 55;
			this->groupBox14->TabStop = false;
			this->groupBox14->Text = L"Tire selection";
			// 
			// tire_name
			// 
			this->tire_name->FormattingEnabled = true;
			this->tire_name->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"batata" });
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
			this->groupBox13->Location = System::Drawing::Point(392, 6);
			this->groupBox13->Name = L"groupBox13";
			this->groupBox13->Size = System::Drawing::Size(241, 286);
			this->groupBox13->TabIndex = 54;
			this->groupBox13->TabStop = false;
			this->groupBox13->Text = L"Other";
			// 
			// textBox80
			// 
			this->textBox80->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox80->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox80->Location = System::Drawing::Point(6, 237);
			this->textBox80->Multiline = true;
			this->textBox80->Name = L"textBox80";
			this->textBox80->Size = System::Drawing::Size(138, 45);
			this->textBox80->TabIndex = 10;
			this->textBox80->Text = L"Tire radial stiffness [N/mm]";
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
			this->textBox61->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox61->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox61->Location = System::Drawing::Point(6, 186);
			this->textBox61->Multiline = true;
			this->textBox61->Name = L"textBox61";
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
			this->textBox62->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox62->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox62->Location = System::Drawing::Point(6, 138);
			this->textBox62->Multiline = true;
			this->textBox62->Name = L"textBox62";
			this->textBox62->Size = System::Drawing::Size(138, 45);
			this->textBox62->TabIndex = 6;
			this->textBox62->Text = L"Rolling resistance parameter \"b\" [1/N]";
			// 
			// textBox63
			// 
			this->textBox63->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox63->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox63->Location = System::Drawing::Point(6, 87);
			this->textBox63->Multiline = true;
			this->textBox63->Name = L"textBox63";
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
			this->textBox79->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox79->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox79->Location = System::Drawing::Point(6, 32);
			this->textBox79->Multiline = true;
			this->textBox79->Name = L"textBox79";
			this->textBox79->Size = System::Drawing::Size(138, 45);
			this->textBox79->TabIndex = 2;
			this->textBox79->Text = L"Undeflected tire radius [mm]";
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
			this->groupBox12->Location = System::Drawing::Point(199, 6);
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
			this->textBox64->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox64->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox64->Location = System::Drawing::Point(6, 492);
			this->textBox64->Multiline = true;
			this->textBox64->Name = L"textBox64";
			this->textBox64->Size = System::Drawing::Size(58, 25);
			this->textBox64->TabIndex = 30;
			this->textBox64->Text = L"pVx2";
			// 
			// textBox65
			// 
			this->textBox65->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox65->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox65->Location = System::Drawing::Point(6, 459);
			this->textBox65->Multiline = true;
			this->textBox65->Name = L"textBox65";
			this->textBox65->Size = System::Drawing::Size(58, 25);
			this->textBox65->TabIndex = 28;
			this->textBox65->Text = L"pVx1";
			// 
			// textBox66
			// 
			this->textBox66->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox66->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox66->Location = System::Drawing::Point(6, 426);
			this->textBox66->Multiline = true;
			this->textBox66->Name = L"textBox66";
			this->textBox66->Size = System::Drawing::Size(58, 25);
			this->textBox66->TabIndex = 26;
			this->textBox66->Text = L"pHx2";
			// 
			// textBox67
			// 
			this->textBox67->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox67->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox67->Location = System::Drawing::Point(6, 393);
			this->textBox67->Multiline = true;
			this->textBox67->Name = L"textBox67";
			this->textBox67->Size = System::Drawing::Size(58, 25);
			this->textBox67->TabIndex = 24;
			this->textBox67->Text = L"pHx1";
			// 
			// textBox68
			// 
			this->textBox68->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox68->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox68->Location = System::Drawing::Point(6, 360);
			this->textBox68->Multiline = true;
			this->textBox68->Name = L"textBox68";
			this->textBox68->Size = System::Drawing::Size(58, 25);
			this->textBox68->TabIndex = 22;
			this->textBox68->Text = L"pKx3";
			// 
			// textBox69
			// 
			this->textBox69->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox69->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox69->Location = System::Drawing::Point(6, 327);
			this->textBox69->Multiline = true;
			this->textBox69->Name = L"textBox69";
			this->textBox69->Size = System::Drawing::Size(58, 25);
			this->textBox69->TabIndex = 20;
			this->textBox69->Text = L"pKx2";
			// 
			// textBox70
			// 
			this->textBox70->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox70->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox70->Location = System::Drawing::Point(6, 294);
			this->textBox70->Multiline = true;
			this->textBox70->Name = L"textBox70";
			this->textBox70->Size = System::Drawing::Size(58, 25);
			this->textBox70->TabIndex = 18;
			this->textBox70->Text = L"pKx1";
			// 
			// textBox71
			// 
			this->textBox71->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox71->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox71->Location = System::Drawing::Point(6, 261);
			this->textBox71->Multiline = true;
			this->textBox71->Name = L"textBox71";
			this->textBox71->Size = System::Drawing::Size(58, 25);
			this->textBox71->TabIndex = 16;
			this->textBox71->Text = L"pEx4";
			// 
			// textBox72
			// 
			this->textBox72->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox72->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox72->Location = System::Drawing::Point(6, 228);
			this->textBox72->Multiline = true;
			this->textBox72->Name = L"textBox72";
			this->textBox72->Size = System::Drawing::Size(58, 25);
			this->textBox72->TabIndex = 14;
			this->textBox72->Text = L"pEx3";
			// 
			// textBox73
			// 
			this->textBox73->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox73->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox73->Location = System::Drawing::Point(6, 195);
			this->textBox73->Multiline = true;
			this->textBox73->Name = L"textBox73";
			this->textBox73->Size = System::Drawing::Size(58, 25);
			this->textBox73->TabIndex = 12;
			this->textBox73->Text = L"pEx2";
			// 
			// textBox74
			// 
			this->textBox74->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox74->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox74->Location = System::Drawing::Point(6, 162);
			this->textBox74->Multiline = true;
			this->textBox74->Name = L"textBox74";
			this->textBox74->Size = System::Drawing::Size(58, 25);
			this->textBox74->TabIndex = 10;
			this->textBox74->Text = L"pEx1";
			// 
			// textBox75
			// 
			this->textBox75->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox75->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox75->Location = System::Drawing::Point(6, 129);
			this->textBox75->Multiline = true;
			this->textBox75->Name = L"textBox75";
			this->textBox75->Size = System::Drawing::Size(58, 25);
			this->textBox75->TabIndex = 8;
			this->textBox75->Text = L"pDx3";
			// 
			// textBox76
			// 
			this->textBox76->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox76->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox76->Location = System::Drawing::Point(6, 96);
			this->textBox76->Multiline = true;
			this->textBox76->Name = L"textBox76";
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
			this->textBox77->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox77->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox77->Location = System::Drawing::Point(6, 63);
			this->textBox77->Multiline = true;
			this->textBox77->Name = L"textBox77";
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
			this->textBox78->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox78->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox78->Location = System::Drawing::Point(6, 32);
			this->textBox78->Multiline = true;
			this->textBox78->Name = L"textBox78";
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
			this->groupBox11->Location = System::Drawing::Point(6, 6);
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
			this->textBox60->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox60->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox60->Location = System::Drawing::Point(6, 591);
			this->textBox60->Multiline = true;
			this->textBox60->Name = L"textBox60";
			this->textBox60->Size = System::Drawing::Size(58, 25);
			this->textBox60->TabIndex = 36;
			this->textBox60->Text = L"pVy4";
			// 
			// textBox59
			// 
			this->textBox59->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox59->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox59->Location = System::Drawing::Point(6, 558);
			this->textBox59->Multiline = true;
			this->textBox59->Name = L"textBox59";
			this->textBox59->Size = System::Drawing::Size(58, 25);
			this->textBox59->TabIndex = 34;
			this->textBox59->Text = L"pVy3";
			// 
			// textBox58
			// 
			this->textBox58->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox58->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox58->Location = System::Drawing::Point(6, 525);
			this->textBox58->Multiline = true;
			this->textBox58->Name = L"textBox58";
			this->textBox58->Size = System::Drawing::Size(58, 25);
			this->textBox58->TabIndex = 32;
			this->textBox58->Text = L"pVy2";
			// 
			// textBox57
			// 
			this->textBox57->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox57->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox57->Location = System::Drawing::Point(6, 492);
			this->textBox57->Multiline = true;
			this->textBox57->Name = L"textBox57";
			this->textBox57->Size = System::Drawing::Size(58, 25);
			this->textBox57->TabIndex = 30;
			this->textBox57->Text = L"pVy1";
			// 
			// textBox56
			// 
			this->textBox56->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox56->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox56->Location = System::Drawing::Point(6, 459);
			this->textBox56->Multiline = true;
			this->textBox56->Name = L"textBox56";
			this->textBox56->Size = System::Drawing::Size(58, 25);
			this->textBox56->TabIndex = 28;
			this->textBox56->Text = L"pHy3";
			// 
			// textBox55
			// 
			this->textBox55->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox55->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox55->Location = System::Drawing::Point(6, 426);
			this->textBox55->Multiline = true;
			this->textBox55->Name = L"textBox55";
			this->textBox55->Size = System::Drawing::Size(58, 25);
			this->textBox55->TabIndex = 26;
			this->textBox55->Text = L"pHy2";
			// 
			// textBox54
			// 
			this->textBox54->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox54->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox54->Location = System::Drawing::Point(6, 393);
			this->textBox54->Multiline = true;
			this->textBox54->Name = L"textBox54";
			this->textBox54->Size = System::Drawing::Size(58, 25);
			this->textBox54->TabIndex = 24;
			this->textBox54->Text = L"pHy1";
			// 
			// textBox53
			// 
			this->textBox53->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox53->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox53->Location = System::Drawing::Point(6, 360);
			this->textBox53->Multiline = true;
			this->textBox53->Name = L"textBox53";
			this->textBox53->Size = System::Drawing::Size(58, 25);
			this->textBox53->TabIndex = 22;
			this->textBox53->Text = L"pKy3";
			// 
			// textBox52
			// 
			this->textBox52->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox52->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox52->Location = System::Drawing::Point(6, 327);
			this->textBox52->Multiline = true;
			this->textBox52->Name = L"textBox52";
			this->textBox52->Size = System::Drawing::Size(58, 25);
			this->textBox52->TabIndex = 20;
			this->textBox52->Text = L"pKy2";
			// 
			// textBox51
			// 
			this->textBox51->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox51->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox51->Location = System::Drawing::Point(6, 294);
			this->textBox51->Multiline = true;
			this->textBox51->Name = L"textBox51";
			this->textBox51->Size = System::Drawing::Size(58, 25);
			this->textBox51->TabIndex = 18;
			this->textBox51->Text = L"pKy1";
			// 
			// textBox50
			// 
			this->textBox50->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox50->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox50->Location = System::Drawing::Point(6, 261);
			this->textBox50->Multiline = true;
			this->textBox50->Name = L"textBox50";
			this->textBox50->Size = System::Drawing::Size(58, 25);
			this->textBox50->TabIndex = 16;
			this->textBox50->Text = L"pEy4";
			// 
			// textBox49
			// 
			this->textBox49->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox49->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox49->Location = System::Drawing::Point(6, 228);
			this->textBox49->Multiline = true;
			this->textBox49->Name = L"textBox49";
			this->textBox49->Size = System::Drawing::Size(58, 25);
			this->textBox49->TabIndex = 14;
			this->textBox49->Text = L"pEy3";
			// 
			// textBox48
			// 
			this->textBox48->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox48->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox48->Location = System::Drawing::Point(6, 195);
			this->textBox48->Multiline = true;
			this->textBox48->Name = L"textBox48";
			this->textBox48->Size = System::Drawing::Size(58, 25);
			this->textBox48->TabIndex = 12;
			this->textBox48->Text = L"pEy2";
			// 
			// textBox47
			// 
			this->textBox47->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox47->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox47->Location = System::Drawing::Point(6, 162);
			this->textBox47->Multiline = true;
			this->textBox47->Name = L"textBox47";
			this->textBox47->Size = System::Drawing::Size(58, 25);
			this->textBox47->TabIndex = 10;
			this->textBox47->Text = L"pEy1";
			// 
			// textBox46
			// 
			this->textBox46->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox46->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox46->Location = System::Drawing::Point(6, 129);
			this->textBox46->Multiline = true;
			this->textBox46->Name = L"textBox46";
			this->textBox46->Size = System::Drawing::Size(58, 25);
			this->textBox46->TabIndex = 8;
			this->textBox46->Text = L"pDy3";
			// 
			// textBox45
			// 
			this->textBox45->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox45->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox45->Location = System::Drawing::Point(6, 96);
			this->textBox45->Multiline = true;
			this->textBox45->Name = L"textBox45";
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
			this->textBox43->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox43->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox43->Location = System::Drawing::Point(6, 63);
			this->textBox43->Multiline = true;
			this->textBox43->Name = L"textBox43";
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
			this->textBox44->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox44->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox44->Location = System::Drawing::Point(6, 32);
			this->textBox44->Multiline = true;
			this->textBox44->Name = L"textBox44";
			this->textBox44->Size = System::Drawing::Size(58, 25);
			this->textBox44->TabIndex = 2;
			this->textBox44->Text = L"pCy1";
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
			this->splitContainer2->Panel1->Controls->Add(this->groupBox9);
			this->splitContainer2->Panel1->Controls->Add(this->groupBox8);
			this->splitContainer2->Panel1->Controls->Add(this->groupBox10);
			this->splitContainer2->Panel1MinSize = 450;
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->tabControl2);
			this->splitContainer2->Size = System::Drawing::Size(1069, 643);
			this->splitContainer2->SplitterDistance = 500;
			this->splitContainer2->TabIndex = 22;
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->input_rear_arb);
			this->groupBox9->Controls->Add(this->textBox84);
			this->groupBox9->Controls->Add(this->input_front_arb);
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
			this->groupBox9->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox9->Location = System::Drawing::Point(250, 3);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(241, 446);
			this->groupBox9->TabIndex = 17;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Setup";
			// 
			// input_rear_arb
			// 
			this->input_rear_arb->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_rear_arb->FormattingEnabled = true;
			this->input_rear_arb->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1/5", L"2/5", L"3/5", L"4/5", L"5/5" });
			this->input_rear_arb->Location = System::Drawing::Point(114, 398);
			this->input_rear_arb->Name = L"input_rear_arb";
			this->input_rear_arb->Size = System::Drawing::Size(121, 27);
			this->input_rear_arb->TabIndex = 28;
			this->input_rear_arb->Text = L"Select";
			// 
			// textBox84
			// 
			this->textBox84->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox84->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox84->Location = System::Drawing::Point(6, 390);
			this->textBox84->Multiline = true;
			this->textBox84->Name = L"textBox84";
			this->textBox84->Size = System::Drawing::Size(102, 40);
			this->textBox84->TabIndex = 27;
			this->textBox84->Text = L"Rear ARB setup";
			// 
			// input_front_arb
			// 
			this->input_front_arb->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_front_arb->FormattingEnabled = true;
			this->input_front_arb->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"1/5", L"2/5", L"3/5", L"4/5", L"5/5" });
			this->input_front_arb->Location = System::Drawing::Point(114, 358);
			this->input_front_arb->Name = L"input_front_arb";
			this->input_front_arb->Size = System::Drawing::Size(121, 27);
			this->input_front_arb->TabIndex = 26;
			this->input_front_arb->Text = L"Select";
			// 
			// textBox83
			// 
			this->textBox83->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox83->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox83->Location = System::Drawing::Point(6, 348);
			this->textBox83->Multiline = true;
			this->textBox83->Name = L"textBox83";
			this->textBox83->Size = System::Drawing::Size(102, 40);
			this->textBox83->TabIndex = 25;
			this->textBox83->Text = L"Front ARB setup";
			// 
			// input_rear_tires_selection
			// 
			this->input_rear_tires_selection->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_rear_tires_selection->FormattingEnabled = true;
			this->input_rear_tires_selection->Location = System::Drawing::Point(59, 309);
			this->input_rear_tires_selection->Name = L"input_rear_tires_selection";
			this->input_rear_tires_selection->Size = System::Drawing::Size(176, 27);
			this->input_rear_tires_selection->TabIndex = 24;
			this->input_rear_tires_selection->Text = L"Select";
			// 
			// textBox81
			// 
			this->textBox81->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox81->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox81->Location = System::Drawing::Point(6, 302);
			this->textBox81->Multiline = true;
			this->textBox81->Name = L"textBox81";
			this->textBox81->Size = System::Drawing::Size(47, 39);
			this->textBox81->TabIndex = 23;
			this->textBox81->Text = L"Rear tires";
			// 
			// input_front_tires_selection
			// 
			this->input_front_tires_selection->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_front_tires_selection->FormattingEnabled = true;
			this->input_front_tires_selection->Location = System::Drawing::Point(59, 263);
			this->input_front_tires_selection->Name = L"input_front_tires_selection";
			this->input_front_tires_selection->Size = System::Drawing::Size(176, 27);
			this->input_front_tires_selection->TabIndex = 22;
			this->input_front_tires_selection->Text = L"Select";
			// 
			// textBox82
			// 
			this->textBox82->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox82->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox82->Location = System::Drawing::Point(6, 254);
			this->textBox82->Multiline = true;
			this->textBox82->Name = L"textBox82";
			this->textBox82->Size = System::Drawing::Size(47, 42);
			this->textBox82->TabIndex = 21;
			this->textBox82->Text = L"Front tires";
			// 
			// textBox36
			// 
			this->textBox36->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox36->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox36->Location = System::Drawing::Point(6, 220);
			this->textBox36->Multiline = true;
			this->textBox36->Name = L"textBox36";
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
			this->input_DB_input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 33, 0, 0, 0 });
			// 
			// textBox27
			// 
			this->textBox27->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox27->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox27->Location = System::Drawing::Point(6, 145);
			this->textBox27->Multiline = true;
			this->textBox27->Name = L"textBox27";
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
			this->textBox28->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox28->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox28->Location = System::Drawing::Point(6, 183);
			this->textBox28->Multiline = true;
			this->textBox28->Name = L"textBox28";
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
			this->input_BB_input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 75, 0, 0, 0 });
			// 
			// textBox29
			// 
			this->textBox29->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox29->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox29->Location = System::Drawing::Point(6, 111);
			this->textBox29->Multiline = true;
			this->textBox29->Name = L"textBox29";
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
			this->textBox34->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox34->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox34->Location = System::Drawing::Point(6, 78);
			this->textBox34->Multiline = true;
			this->textBox34->Name = L"textBox34";
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
			this->textBox35->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox35->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox35->Location = System::Drawing::Point(6, 32);
			this->textBox35->Multiline = true;
			this->textBox35->Name = L"textBox35";
			this->textBox35->Size = System::Drawing::Size(157, 47);
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
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->input_a_lon_des);
			this->groupBox8->Controls->Add(this->input_force_a_lon);
			this->groupBox8->Controls->Add(this->textBox184);
			this->groupBox8->Controls->Add(this->input_V_input);
			this->groupBox8->Controls->Add(this->input_force_velocity);
			this->groupBox8->Controls->Add(this->textBox40);
			this->groupBox8->Controls->Add(this->input_lat_ratio_custom);
			this->groupBox8->Controls->Add(this->textBox39);
			this->groupBox8->Controls->Add(this->input_lon_ratio_custom);
			this->groupBox8->Controls->Add(this->input_steering_input);
			this->groupBox8->Controls->Add(this->textBox38);
			this->groupBox8->Controls->Add(this->input_pedals_input);
			this->groupBox8->Controls->Add(this->textBox37);
			this->groupBox8->Controls->Add(this->textBox26);
			this->groupBox8->Controls->Add(this->input_delta_d_des);
			this->groupBox8->Controls->Add(this->textBox30);
			this->groupBox8->Controls->Add(this->input_kappa_des);
			this->groupBox8->Controls->Add(this->textBox31);
			this->groupBox8->Controls->Add(this->input_beta_des);
			this->groupBox8->Controls->Add(this->textBox32);
			this->groupBox8->Controls->Add(this->input_R_min);
			this->groupBox8->Controls->Add(this->textBox33);
			this->groupBox8->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox8->Location = System::Drawing::Point(3, 3);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(241, 595);
			this->groupBox8->TabIndex = 8;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Driver";
			// 
			// input_a_lon_des
			// 
			this->input_a_lon_des->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_a_lon_des->DecimalPlaces = 2;
			this->input_a_lon_des->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_a_lon_des->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->input_a_lon_des->Location = System::Drawing::Point(169, 312);
			this->input_a_lon_des->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->input_a_lon_des->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, System::Int32::MinValue });
			this->input_a_lon_des->Name = L"input_a_lon_des";
			this->input_a_lon_des->Size = System::Drawing::Size(66, 27);
			this->input_a_lon_des->TabIndex = 14;
			// 
			// input_force_a_lon
			// 
			this->input_force_a_lon->AutoSize = true;
			this->input_force_a_lon->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_force_a_lon->Location = System::Drawing::Point(20, 350);
			this->input_force_a_lon->Name = L"input_force_a_lon";
			this->input_force_a_lon->Size = System::Drawing::Size(198, 19);
			this->input_force_a_lon->TabIndex = 26;
			this->input_force_a_lon->Text = L"Force longitudinal acceleration";
			this->input_force_a_lon->UseVisualStyleBackColor = true;
			// 
			// textBox184
			// 
			this->textBox184->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox184->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox184->Location = System::Drawing::Point(6, 312);
			this->textBox184->Multiline = true;
			this->textBox184->Name = L"textBox184";
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
			this->input_V_input->Location = System::Drawing::Point(169, 42);
			this->input_V_input->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_V_input->Name = L"input_V_input";
			this->input_V_input->Size = System::Drawing::Size(66, 27);
			this->input_V_input->TabIndex = 0;
			this->input_V_input->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			// 
			// input_force_velocity
			// 
			this->input_force_velocity->AutoSize = true;
			this->input_force_velocity->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_force_velocity->Location = System::Drawing::Point(20, 53);
			this->input_force_velocity->Name = L"input_force_velocity";
			this->input_force_velocity->Size = System::Drawing::Size(102, 19);
			this->input_force_velocity->TabIndex = 25;
			this->input_force_velocity->Text = L"Force velocity";
			this->input_force_velocity->UseVisualStyleBackColor = true;
			// 
			// textBox40
			// 
			this->textBox40->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox40->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox40->Location = System::Drawing::Point(6, 529);
			this->textBox40->Multiline = true;
			this->textBox40->Name = L"textBox40";
			this->textBox40->Size = System::Drawing::Size(157, 40);
			this->textBox40->TabIndex = 24;
			this->textBox40->Text = L"Custom lateral ratio [%]";
			// 
			// input_lat_ratio_custom
			// 
			this->input_lat_ratio_custom->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_lat_ratio_custom->DecimalPlaces = 2;
			this->input_lat_ratio_custom->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_lat_ratio_custom->Location = System::Drawing::Point(169, 529);
			this->input_lat_ratio_custom->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->input_lat_ratio_custom->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, System::Int32::MinValue });
			this->input_lat_ratio_custom->Name = L"input_lat_ratio_custom";
			this->input_lat_ratio_custom->Size = System::Drawing::Size(66, 27);
			this->input_lat_ratio_custom->TabIndex = 23;
			this->input_lat_ratio_custom->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			// 
			// textBox39
			// 
			this->textBox39->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox39->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox39->Location = System::Drawing::Point(6, 483);
			this->textBox39->Multiline = true;
			this->textBox39->Name = L"textBox39";
			this->textBox39->Size = System::Drawing::Size(157, 40);
			this->textBox39->TabIndex = 22;
			this->textBox39->Text = L"Custom longitudinal ratio [%]";
			// 
			// input_lon_ratio_custom
			// 
			this->input_lon_ratio_custom->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_lon_ratio_custom->DecimalPlaces = 2;
			this->input_lon_ratio_custom->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_lon_ratio_custom->Location = System::Drawing::Point(169, 485);
			this->input_lon_ratio_custom->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_lon_ratio_custom->Name = L"input_lon_ratio_custom";
			this->input_lon_ratio_custom->Size = System::Drawing::Size(66, 27);
			this->input_lon_ratio_custom->TabIndex = 21;
			this->input_lon_ratio_custom->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			// 
			// input_steering_input
			// 
			this->input_steering_input->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_steering_input->FormattingEnabled = true;
			this->input_steering_input->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Steering", L"Straight", L"Custom" });
			this->input_steering_input->Location = System::Drawing::Point(114, 433);
			this->input_steering_input->Name = L"input_steering_input";
			this->input_steering_input->Size = System::Drawing::Size(121, 27);
			this->input_steering_input->TabIndex = 20;
			this->input_steering_input->Text = L"Select";
			// 
			// textBox38
			// 
			this->textBox38->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox38->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox38->Location = System::Drawing::Point(6, 436);
			this->textBox38->Multiline = true;
			this->textBox38->Name = L"textBox38";
			this->textBox38->Size = System::Drawing::Size(102, 30);
			this->textBox38->TabIndex = 19;
			this->textBox38->Text = L"Steering input";
			// 
			// input_pedals_input
			// 
			this->input_pedals_input->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_pedals_input->FormattingEnabled = true;
			this->input_pedals_input->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Braking", L"Driving", L"Coasting", L"Cruising",
					L"Custom"
			});
			this->input_pedals_input->Location = System::Drawing::Point(114, 375);
			this->input_pedals_input->Name = L"input_pedals_input";
			this->input_pedals_input->Size = System::Drawing::Size(121, 27);
			this->input_pedals_input->TabIndex = 18;
			this->input_pedals_input->Text = L"Select";
			// 
			// textBox37
			// 
			this->textBox37->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox37->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox37->Location = System::Drawing::Point(6, 378);
			this->textBox37->Multiline = true;
			this->textBox37->Name = L"textBox37";
			this->textBox37->Size = System::Drawing::Size(102, 19);
			this->textBox37->TabIndex = 17;
			this->textBox37->Text = L"Pedals input";
			// 
			// textBox26
			// 
			this->textBox26->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox26->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox26->Location = System::Drawing::Point(6, 200);
			this->textBox26->Multiline = true;
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(157, 47);
			this->textBox26->TabIndex = 16;
			this->textBox26->Text = L"Steering wheel angle [°]";
			// 
			// input_delta_d_des
			// 
			this->input_delta_d_des->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_delta_d_des->DecimalPlaces = 2;
			this->input_delta_d_des->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_delta_d_des->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->input_delta_d_des->Location = System::Drawing::Point(169, 210);
			this->input_delta_d_des->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->input_delta_d_des->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->input_delta_d_des->Name = L"input_delta_d_des";
			this->input_delta_d_des->Size = System::Drawing::Size(66, 27);
			this->input_delta_d_des->TabIndex = 15;
			this->input_delta_d_des->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			// 
			// textBox30
			// 
			this->textBox30->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox30->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox30->Location = System::Drawing::Point(6, 263);
			this->textBox30->Multiline = true;
			this->textBox30->Name = L"textBox30";
			this->textBox30->Size = System::Drawing::Size(157, 27);
			this->textBox30->TabIndex = 8;
			this->textBox30->Text = L"Desired slip ratio [%]";
			// 
			// input_kappa_des
			// 
			this->input_kappa_des->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_kappa_des->DecimalPlaces = 2;
			this->input_kappa_des->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_kappa_des->Location = System::Drawing::Point(169, 263);
			this->input_kappa_des->Name = L"input_kappa_des";
			this->input_kappa_des->Size = System::Drawing::Size(66, 27);
			this->input_kappa_des->TabIndex = 7;
			this->input_kappa_des->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			// 
			// textBox31
			// 
			this->textBox31->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox31->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox31->Location = System::Drawing::Point(6, 143);
			this->textBox31->Multiline = true;
			this->textBox31->Name = L"textBox31";
			this->textBox31->Size = System::Drawing::Size(157, 47);
			this->textBox31->TabIndex = 6;
			this->textBox31->Text = L"Chassis slip angle (β) [°]";
			// 
			// input_beta_des
			// 
			this->input_beta_des->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_beta_des->DecimalPlaces = 2;
			this->input_beta_des->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_beta_des->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
			this->input_beta_des->Location = System::Drawing::Point(169, 153);
			this->input_beta_des->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 89, 0, 0, 0 });
			this->input_beta_des->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 89, 0, 0, System::Int32::MinValue });
			this->input_beta_des->Name = L"input_beta_des";
			this->input_beta_des->Size = System::Drawing::Size(66, 27);
			this->input_beta_des->TabIndex = 5;
			this->input_beta_des->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// textBox32
			// 
			this->textBox32->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox32->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox32->Location = System::Drawing::Point(6, 97);
			this->textBox32->Multiline = true;
			this->textBox32->Name = L"textBox32";
			this->textBox32->Size = System::Drawing::Size(157, 20);
			this->textBox32->TabIndex = 4;
			this->textBox32->Text = L"Corner radius [m]";
			// 
			// input_R_min
			// 
			this->input_R_min->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->input_R_min->DecimalPlaces = 2;
			this->input_R_min->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_R_min->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->input_R_min->Location = System::Drawing::Point(169, 95);
			this->input_R_min->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->input_R_min->Name = L"input_R_min";
			this->input_R_min->Size = System::Drawing::Size(66, 27);
			this->input_R_min->TabIndex = 3;
			this->input_R_min->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9125, 0, 0, 196608 });
			this->input_R_min->ValueChanged += gcnew System::EventHandler(this, &MyForm::input_R_min_ValueChanged);
			// 
			// textBox33
			// 
			this->textBox33->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox33->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox33->Location = System::Drawing::Point(6, 32);
			this->textBox33->Multiline = true;
			this->textBox33->Name = L"textBox33";
			this->textBox33->Size = System::Drawing::Size(177, 47);
			this->textBox33->TabIndex = 2;
			this->textBox33->Text = L"Desired velocity [km/h]";
			// 
			// groupBox10
			// 
			this->groupBox10->Controls->Add(this->input_corner_side);
			this->groupBox10->Controls->Add(this->textBox41);
			this->groupBox10->Controls->Add(this->input_corner_type);
			this->groupBox10->Controls->Add(this->textBox42);
			this->groupBox10->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox10->Location = System::Drawing::Point(250, 455);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(241, 143);
			this->groupBox10->TabIndex = 19;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Corner";
			// 
			// input_corner_side
			// 
			this->input_corner_side->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_corner_side->FormattingEnabled = true;
			this->input_corner_side->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Right", L"Left" });
			this->input_corner_side->Location = System::Drawing::Point(114, 95);
			this->input_corner_side->Name = L"input_corner_side";
			this->input_corner_side->Size = System::Drawing::Size(121, 27);
			this->input_corner_side->TabIndex = 24;
			this->input_corner_side->Text = L"Select";
			// 
			// textBox41
			// 
			this->textBox41->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox41->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox41->Location = System::Drawing::Point(6, 98);
			this->textBox41->Multiline = true;
			this->textBox41->Name = L"textBox41";
			this->textBox41->Size = System::Drawing::Size(102, 30);
			this->textBox41->TabIndex = 23;
			this->textBox41->Text = L"Corner side";
			// 
			// input_corner_type
			// 
			this->input_corner_type->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_corner_type->FormattingEnabled = true;
			this->input_corner_type->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Steady-state", L"Transient" });
			this->input_corner_type->Location = System::Drawing::Point(114, 37);
			this->input_corner_type->Name = L"input_corner_type";
			this->input_corner_type->Size = System::Drawing::Size(121, 27);
			this->input_corner_type->TabIndex = 22;
			this->input_corner_type->Text = L"Select";
			// 
			// textBox42
			// 
			this->textBox42->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox42->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox42->Location = System::Drawing::Point(6, 40);
			this->textBox42->Multiline = true;
			this->textBox42->Name = L"textBox42";
			this->textBox42->Size = System::Drawing::Size(102, 19);
			this->textBox42->TabIndex = 21;
			this->textBox42->Text = L"Corner type";
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
			this->tabPage6->Text = L"Outputs";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// output_R
			// 
			this->output_R->AutoSize = true;
			this->output_R->Location = System::Drawing::Point(365, 496);
			this->output_R->Name = L"output_R";
			this->output_R->Size = System::Drawing::Size(64, 26);
			this->output_R->TabIndex = 30;
			this->output_R->Text = L"label7";
			// 
			// output_V
			// 
			this->output_V->AutoSize = true;
			this->output_V->Location = System::Drawing::Point(365, 466);
			this->output_V->Name = L"output_V";
			this->output_V->Size = System::Drawing::Size(64, 26);
			this->output_V->TabIndex = 26;
			this->output_V->Text = L"label7";
			// 
			// output_bias_now
			// 
			this->output_bias_now->AutoSize = true;
			this->output_bias_now->Location = System::Drawing::Point(365, 432);
			this->output_bias_now->Name = L"output_bias_now";
			this->output_bias_now->Size = System::Drawing::Size(64, 26);
			this->output_bias_now->TabIndex = 25;
			this->output_bias_now->Text = L"label7";
			// 
			// output_iter
			// 
			this->output_iter->AutoSize = true;
			this->output_iter->Location = System::Drawing::Point(365, 399);
			this->output_iter->Name = L"output_iter";
			this->output_iter->Size = System::Drawing::Size(64, 26);
			this->output_iter->TabIndex = 24;
			this->output_iter->Text = L"label7";
			// 
			// output_a_rad
			// 
			this->output_a_rad->AutoSize = true;
			this->output_a_rad->Location = System::Drawing::Point(6, 431);
			this->output_a_rad->Name = L"output_a_rad";
			this->output_a_rad->Size = System::Drawing::Size(64, 26);
			this->output_a_rad->TabIndex = 23;
			this->output_a_rad->Text = L"label8";
			// 
			// output_a_lat
			// 
			this->output_a_lat->AutoSize = true;
			this->output_a_lat->Location = System::Drawing::Point(5, 399);
			this->output_a_lat->Name = L"output_a_lat";
			this->output_a_lat->Size = System::Drawing::Size(64, 26);
			this->output_a_lat->TabIndex = 4;
			this->output_a_lat->Text = L"label8";
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
			this->tableLayoutPanel1->Controls->Add(this->output_F_z_fi, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->output_F_z_fo, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->output_F_z_ri, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->output_F_z_ro, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->output_F_x_comb_fi, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->output_F_x_comb_fo, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->output_F_x_comb_ri, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->output_F_x_comb_ro, 4, 2);
			this->tableLayoutPanel1->Controls->Add(this->output_F_y_comb_fi, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->output_F_y_comb_fo, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->output_F_y_comb_ri, 3, 3);
			this->tableLayoutPanel1->Controls->Add(this->output_F_y_comb_ro, 4, 3);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lon_fi, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lon_fo, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lon_ri, 3, 4);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lon_ro, 4, 4);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lat_fi, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lat_fo, 2, 5);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lat_ri, 3, 5);
			this->tableLayoutPanel1->Controls->Add(this->output_F_lat_ro, 4, 5);
			this->tableLayoutPanel1->Controls->Add(this->output_kappa_fi, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->output_kappa_fo, 2, 6);
			this->tableLayoutPanel1->Controls->Add(this->output_kappa_ri, 3, 6);
			this->tableLayoutPanel1->Controls->Add(this->output_kappa_ro, 4, 6);
			this->tableLayoutPanel1->Controls->Add(this->output_alpha_fi, 1, 7);
			this->tableLayoutPanel1->Controls->Add(this->output_alpha_fo, 2, 7);
			this->tableLayoutPanel1->Controls->Add(this->output_alpha_ri, 3, 7);
			this->tableLayoutPanel1->Controls->Add(this->output_alpha_ro, 4, 7);
			this->tableLayoutPanel1->Controls->Add(this->output_T_fi, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->output_T_fo, 2, 8);
			this->tableLayoutPanel1->Controls->Add(this->output_T_ri, 3, 8);
			this->tableLayoutPanel1->Controls->Add(this->output_T_ro, 4, 8);
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
			this->label6->Text = L"Front inner";
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
			this->label7->Text = L"Front outer";
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
			this->label8->Text = L"Rear inner";
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
			this->label9->Text = L"Rear outer";
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
			// output_F_z_fi
			// 
			this->output_F_z_fi->AutoSize = true;
			this->output_F_z_fi->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_z_fi->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_z_fi->Location = System::Drawing::Point(114, 36);
			this->output_F_z_fi->Name = L"output_F_z_fi";
			this->output_F_z_fi->Size = System::Drawing::Size(103, 34);
			this->output_F_z_fi->TabIndex = 12;
			this->output_F_z_fi->Text = L"OUTPUT";
			this->output_F_z_fi->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_z_fo
			// 
			this->output_F_z_fo->AutoSize = true;
			this->output_F_z_fo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_z_fo->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_z_fo->Location = System::Drawing::Point(224, 36);
			this->output_F_z_fo->Name = L"output_F_z_fo";
			this->output_F_z_fo->Size = System::Drawing::Size(103, 34);
			this->output_F_z_fo->TabIndex = 13;
			this->output_F_z_fo->Text = L"OUTPUT";
			this->output_F_z_fo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_z_ri
			// 
			this->output_F_z_ri->AutoSize = true;
			this->output_F_z_ri->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_z_ri->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_z_ri->Location = System::Drawing::Point(334, 36);
			this->output_F_z_ri->Name = L"output_F_z_ri";
			this->output_F_z_ri->Size = System::Drawing::Size(103, 34);
			this->output_F_z_ri->TabIndex = 14;
			this->output_F_z_ri->Text = L"OUTPUT";
			this->output_F_z_ri->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_z_ro
			// 
			this->output_F_z_ro->AutoSize = true;
			this->output_F_z_ro->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_z_ro->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_z_ro->Location = System::Drawing::Point(444, 36);
			this->output_F_z_ro->Name = L"output_F_z_ro";
			this->output_F_z_ro->Size = System::Drawing::Size(103, 34);
			this->output_F_z_ro->TabIndex = 15;
			this->output_F_z_ro->Text = L"OUTPUT";
			this->output_F_z_ro->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_x_comb_fi
			// 
			this->output_F_x_comb_fi->AutoSize = true;
			this->output_F_x_comb_fi->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_x_comb_fi->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_x_comb_fi->Location = System::Drawing::Point(114, 71);
			this->output_F_x_comb_fi->Name = L"output_F_x_comb_fi";
			this->output_F_x_comb_fi->Size = System::Drawing::Size(103, 34);
			this->output_F_x_comb_fi->TabIndex = 16;
			this->output_F_x_comb_fi->Text = L"OUTPUT";
			this->output_F_x_comb_fi->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_x_comb_fo
			// 
			this->output_F_x_comb_fo->AutoSize = true;
			this->output_F_x_comb_fo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_x_comb_fo->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_x_comb_fo->Location = System::Drawing::Point(224, 71);
			this->output_F_x_comb_fo->Name = L"output_F_x_comb_fo";
			this->output_F_x_comb_fo->Size = System::Drawing::Size(103, 34);
			this->output_F_x_comb_fo->TabIndex = 17;
			this->output_F_x_comb_fo->Text = L"OUTPUT";
			this->output_F_x_comb_fo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_x_comb_ri
			// 
			this->output_F_x_comb_ri->AutoSize = true;
			this->output_F_x_comb_ri->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_x_comb_ri->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_x_comb_ri->Location = System::Drawing::Point(334, 71);
			this->output_F_x_comb_ri->Name = L"output_F_x_comb_ri";
			this->output_F_x_comb_ri->Size = System::Drawing::Size(103, 34);
			this->output_F_x_comb_ri->TabIndex = 18;
			this->output_F_x_comb_ri->Text = L"OUTPUT";
			this->output_F_x_comb_ri->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_x_comb_ro
			// 
			this->output_F_x_comb_ro->AutoSize = true;
			this->output_F_x_comb_ro->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_x_comb_ro->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_x_comb_ro->Location = System::Drawing::Point(444, 71);
			this->output_F_x_comb_ro->Name = L"output_F_x_comb_ro";
			this->output_F_x_comb_ro->Size = System::Drawing::Size(103, 34);
			this->output_F_x_comb_ro->TabIndex = 19;
			this->output_F_x_comb_ro->Text = L"OUTPUT";
			this->output_F_x_comb_ro->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_y_comb_fi
			// 
			this->output_F_y_comb_fi->AutoSize = true;
			this->output_F_y_comb_fi->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_y_comb_fi->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_y_comb_fi->Location = System::Drawing::Point(114, 106);
			this->output_F_y_comb_fi->Name = L"output_F_y_comb_fi";
			this->output_F_y_comb_fi->Size = System::Drawing::Size(103, 34);
			this->output_F_y_comb_fi->TabIndex = 20;
			this->output_F_y_comb_fi->Text = L"OUTPUT";
			this->output_F_y_comb_fi->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_y_comb_fo
			// 
			this->output_F_y_comb_fo->AutoSize = true;
			this->output_F_y_comb_fo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_y_comb_fo->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_y_comb_fo->Location = System::Drawing::Point(224, 106);
			this->output_F_y_comb_fo->Name = L"output_F_y_comb_fo";
			this->output_F_y_comb_fo->Size = System::Drawing::Size(103, 34);
			this->output_F_y_comb_fo->TabIndex = 21;
			this->output_F_y_comb_fo->Text = L"OUTPUT";
			this->output_F_y_comb_fo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_y_comb_ri
			// 
			this->output_F_y_comb_ri->AutoSize = true;
			this->output_F_y_comb_ri->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_y_comb_ri->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_y_comb_ri->Location = System::Drawing::Point(334, 106);
			this->output_F_y_comb_ri->Name = L"output_F_y_comb_ri";
			this->output_F_y_comb_ri->Size = System::Drawing::Size(103, 34);
			this->output_F_y_comb_ri->TabIndex = 22;
			this->output_F_y_comb_ri->Text = L"OUTPUT";
			this->output_F_y_comb_ri->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_y_comb_ro
			// 
			this->output_F_y_comb_ro->AutoSize = true;
			this->output_F_y_comb_ro->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_y_comb_ro->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_y_comb_ro->Location = System::Drawing::Point(444, 106);
			this->output_F_y_comb_ro->Name = L"output_F_y_comb_ro";
			this->output_F_y_comb_ro->Size = System::Drawing::Size(103, 34);
			this->output_F_y_comb_ro->TabIndex = 23;
			this->output_F_y_comb_ro->Text = L"OUTPUT";
			this->output_F_y_comb_ro->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lon_fi
			// 
			this->output_F_lon_fi->AutoSize = true;
			this->output_F_lon_fi->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lon_fi->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lon_fi->Location = System::Drawing::Point(114, 141);
			this->output_F_lon_fi->Name = L"output_F_lon_fi";
			this->output_F_lon_fi->Size = System::Drawing::Size(103, 34);
			this->output_F_lon_fi->TabIndex = 24;
			this->output_F_lon_fi->Text = L"OUTPUT";
			this->output_F_lon_fi->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lon_fo
			// 
			this->output_F_lon_fo->AutoSize = true;
			this->output_F_lon_fo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lon_fo->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lon_fo->Location = System::Drawing::Point(224, 141);
			this->output_F_lon_fo->Name = L"output_F_lon_fo";
			this->output_F_lon_fo->Size = System::Drawing::Size(103, 34);
			this->output_F_lon_fo->TabIndex = 25;
			this->output_F_lon_fo->Text = L"OUTPUT";
			this->output_F_lon_fo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lon_ri
			// 
			this->output_F_lon_ri->AutoSize = true;
			this->output_F_lon_ri->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lon_ri->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lon_ri->Location = System::Drawing::Point(334, 141);
			this->output_F_lon_ri->Name = L"output_F_lon_ri";
			this->output_F_lon_ri->Size = System::Drawing::Size(103, 34);
			this->output_F_lon_ri->TabIndex = 26;
			this->output_F_lon_ri->Text = L"OUTPUT";
			this->output_F_lon_ri->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lon_ro
			// 
			this->output_F_lon_ro->AutoSize = true;
			this->output_F_lon_ro->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lon_ro->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lon_ro->Location = System::Drawing::Point(444, 141);
			this->output_F_lon_ro->Name = L"output_F_lon_ro";
			this->output_F_lon_ro->Size = System::Drawing::Size(103, 34);
			this->output_F_lon_ro->TabIndex = 27;
			this->output_F_lon_ro->Text = L"OUTPUT";
			this->output_F_lon_ro->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lat_fi
			// 
			this->output_F_lat_fi->AutoSize = true;
			this->output_F_lat_fi->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lat_fi->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lat_fi->Location = System::Drawing::Point(114, 176);
			this->output_F_lat_fi->Name = L"output_F_lat_fi";
			this->output_F_lat_fi->Size = System::Drawing::Size(103, 34);
			this->output_F_lat_fi->TabIndex = 28;
			this->output_F_lat_fi->Text = L"OUTPUT";
			this->output_F_lat_fi->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lat_fo
			// 
			this->output_F_lat_fo->AutoSize = true;
			this->output_F_lat_fo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lat_fo->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lat_fo->Location = System::Drawing::Point(224, 176);
			this->output_F_lat_fo->Name = L"output_F_lat_fo";
			this->output_F_lat_fo->Size = System::Drawing::Size(103, 34);
			this->output_F_lat_fo->TabIndex = 29;
			this->output_F_lat_fo->Text = L"OUTPUT";
			this->output_F_lat_fo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lat_ri
			// 
			this->output_F_lat_ri->AutoSize = true;
			this->output_F_lat_ri->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lat_ri->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lat_ri->Location = System::Drawing::Point(334, 176);
			this->output_F_lat_ri->Name = L"output_F_lat_ri";
			this->output_F_lat_ri->Size = System::Drawing::Size(103, 34);
			this->output_F_lat_ri->TabIndex = 30;
			this->output_F_lat_ri->Text = L"OUTPUT";
			this->output_F_lat_ri->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_F_lat_ro
			// 
			this->output_F_lat_ro->AutoSize = true;
			this->output_F_lat_ro->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_F_lat_ro->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_F_lat_ro->Location = System::Drawing::Point(444, 176);
			this->output_F_lat_ro->Name = L"output_F_lat_ro";
			this->output_F_lat_ro->Size = System::Drawing::Size(103, 34);
			this->output_F_lat_ro->TabIndex = 31;
			this->output_F_lat_ro->Text = L"OUTPUT";
			this->output_F_lat_ro->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_kappa_fi
			// 
			this->output_kappa_fi->AutoSize = true;
			this->output_kappa_fi->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_kappa_fi->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_kappa_fi->Location = System::Drawing::Point(114, 211);
			this->output_kappa_fi->Name = L"output_kappa_fi";
			this->output_kappa_fi->Size = System::Drawing::Size(103, 34);
			this->output_kappa_fi->TabIndex = 32;
			this->output_kappa_fi->Text = L"OUTPUT";
			this->output_kappa_fi->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_kappa_fo
			// 
			this->output_kappa_fo->AutoSize = true;
			this->output_kappa_fo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_kappa_fo->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_kappa_fo->Location = System::Drawing::Point(224, 211);
			this->output_kappa_fo->Name = L"output_kappa_fo";
			this->output_kappa_fo->Size = System::Drawing::Size(103, 34);
			this->output_kappa_fo->TabIndex = 33;
			this->output_kappa_fo->Text = L"OUTPUT";
			this->output_kappa_fo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_kappa_ri
			// 
			this->output_kappa_ri->AutoSize = true;
			this->output_kappa_ri->BackColor = System::Drawing::Color::Transparent;
			this->output_kappa_ri->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_kappa_ri->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_kappa_ri->Location = System::Drawing::Point(334, 211);
			this->output_kappa_ri->Name = L"output_kappa_ri";
			this->output_kappa_ri->Size = System::Drawing::Size(103, 34);
			this->output_kappa_ri->TabIndex = 34;
			this->output_kappa_ri->Text = L"OUTPUT";
			this->output_kappa_ri->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_kappa_ro
			// 
			this->output_kappa_ro->AutoSize = true;
			this->output_kappa_ro->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_kappa_ro->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_kappa_ro->Location = System::Drawing::Point(444, 211);
			this->output_kappa_ro->Name = L"output_kappa_ro";
			this->output_kappa_ro->Size = System::Drawing::Size(103, 34);
			this->output_kappa_ro->TabIndex = 35;
			this->output_kappa_ro->Text = L"OUTPUT";
			this->output_kappa_ro->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_alpha_fi
			// 
			this->output_alpha_fi->AutoSize = true;
			this->output_alpha_fi->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_alpha_fi->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_alpha_fi->Location = System::Drawing::Point(114, 246);
			this->output_alpha_fi->Name = L"output_alpha_fi";
			this->output_alpha_fi->Size = System::Drawing::Size(103, 34);
			this->output_alpha_fi->TabIndex = 36;
			this->output_alpha_fi->Text = L"OUTPUT";
			this->output_alpha_fi->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_alpha_fo
			// 
			this->output_alpha_fo->AutoSize = true;
			this->output_alpha_fo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_alpha_fo->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_alpha_fo->Location = System::Drawing::Point(224, 246);
			this->output_alpha_fo->Name = L"output_alpha_fo";
			this->output_alpha_fo->Size = System::Drawing::Size(103, 34);
			this->output_alpha_fo->TabIndex = 37;
			this->output_alpha_fo->Text = L"OUTPUT";
			this->output_alpha_fo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_alpha_ri
			// 
			this->output_alpha_ri->AutoSize = true;
			this->output_alpha_ri->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_alpha_ri->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_alpha_ri->Location = System::Drawing::Point(334, 246);
			this->output_alpha_ri->Name = L"output_alpha_ri";
			this->output_alpha_ri->Size = System::Drawing::Size(103, 34);
			this->output_alpha_ri->TabIndex = 38;
			this->output_alpha_ri->Text = L"OUTPUT";
			this->output_alpha_ri->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_alpha_ro
			// 
			this->output_alpha_ro->AutoSize = true;
			this->output_alpha_ro->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_alpha_ro->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_alpha_ro->Location = System::Drawing::Point(444, 246);
			this->output_alpha_ro->Name = L"output_alpha_ro";
			this->output_alpha_ro->Size = System::Drawing::Size(103, 34);
			this->output_alpha_ro->TabIndex = 39;
			this->output_alpha_ro->Text = L"OUTPUT";
			this->output_alpha_ro->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_T_fi
			// 
			this->output_T_fi->AutoSize = true;
			this->output_T_fi->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_T_fi->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_T_fi->Location = System::Drawing::Point(114, 281);
			this->output_T_fi->Name = L"output_T_fi";
			this->output_T_fi->Size = System::Drawing::Size(103, 38);
			this->output_T_fi->TabIndex = 40;
			this->output_T_fi->Text = L"OUTPUT";
			this->output_T_fi->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_T_fo
			// 
			this->output_T_fo->AutoSize = true;
			this->output_T_fo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_T_fo->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_T_fo->Location = System::Drawing::Point(224, 281);
			this->output_T_fo->Name = L"output_T_fo";
			this->output_T_fo->Size = System::Drawing::Size(103, 38);
			this->output_T_fo->TabIndex = 41;
			this->output_T_fo->Text = L"OUTPUT";
			this->output_T_fo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_T_ri
			// 
			this->output_T_ri->AutoSize = true;
			this->output_T_ri->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_T_ri->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_T_ri->Location = System::Drawing::Point(334, 281);
			this->output_T_ri->Name = L"output_T_ri";
			this->output_T_ri->Size = System::Drawing::Size(103, 38);
			this->output_T_ri->TabIndex = 42;
			this->output_T_ri->Text = L"OUTPUT";
			this->output_T_ri->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_T_ro
			// 
			this->output_T_ro->AutoSize = true;
			this->output_T_ro->Dock = System::Windows::Forms::DockStyle::Fill;
			this->output_T_ro->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->output_T_ro->Location = System::Drawing::Point(444, 281);
			this->output_T_ro->Name = L"output_T_ro";
			this->output_T_ro->Size = System::Drawing::Size(103, 38);
			this->output_T_ro->TabIndex = 43;
			this->output_T_ro->Text = L"OUTPUT";
			this->output_T_ro->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// output_M_yaw
			// 
			this->output_M_yaw->AutoSize = true;
			this->output_M_yaw->Location = System::Drawing::Point(6, 326);
			this->output_M_yaw->Name = L"output_M_yaw";
			this->output_M_yaw->Size = System::Drawing::Size(64, 26);
			this->output_M_yaw->TabIndex = 1;
			this->output_M_yaw->Text = L"label1";
			// 
			// output_F_lat
			// 
			this->output_F_lat->AutoSize = true;
			this->output_F_lat->Location = System::Drawing::Point(6, 501);
			this->output_F_lat->Name = L"output_F_lat";
			this->output_F_lat->Size = System::Drawing::Size(64, 26);
			this->output_F_lat->TabIndex = 2;
			this->output_F_lat->Text = L"label6";
			// 
			// output_phi_deg
			// 
			this->output_phi_deg->AutoSize = true;
			this->output_phi_deg->Location = System::Drawing::Point(365, 364);
			this->output_phi_deg->Name = L"output_phi_deg";
			this->output_phi_deg->Size = System::Drawing::Size(64, 26);
			this->output_phi_deg->TabIndex = 7;
			this->output_phi_deg->Text = L"label7";
			// 
			// output_F_lon
			// 
			this->output_F_lon->AutoSize = true;
			this->output_F_lon->Location = System::Drawing::Point(6, 466);
			this->output_F_lon->Name = L"output_F_lon";
			this->output_F_lon->Size = System::Drawing::Size(64, 26);
			this->output_F_lon->TabIndex = 3;
			this->output_F_lon->Text = L"label7";
			// 
			// output_psi_deg
			// 
			this->output_psi_deg->AutoSize = true;
			this->output_psi_deg->Location = System::Drawing::Point(365, 326);
			this->output_psi_deg->Name = L"output_psi_deg";
			this->output_psi_deg->Size = System::Drawing::Size(64, 26);
			this->output_psi_deg->TabIndex = 6;
			this->output_psi_deg->Text = L"label6";
			// 
			// output_a_lon
			// 
			this->output_a_lon->AutoSize = true;
			this->output_a_lon->Location = System::Drawing::Point(6, 364);
			this->output_a_lon->Name = L"output_a_lon";
			this->output_a_lon->Size = System::Drawing::Size(64, 26);
			this->output_a_lon->TabIndex = 5;
			this->output_a_lon->Text = L"label9";
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
			this->tableLayoutPanel2->Controls->Add(this->input_num_delta_d, 3, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox182, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->input_max_delta_d, 3, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBox180, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->textBox181, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->textBox183, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->input_max_beta, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->input_num_beta, 1, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(551, 94);
			this->tableLayoutPanel2->TabIndex = 13;
			// 
			// input_num_delta_d
			// 
			this->input_num_delta_d->DecimalPlaces = 2;
			this->input_num_delta_d->Dock = System::Windows::Forms::DockStyle::Fill;
			this->input_num_delta_d->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_num_delta_d->Location = System::Drawing::Point(276, 50);
			this->input_num_delta_d->Name = L"input_num_delta_d";
			this->input_num_delta_d->Size = System::Drawing::Size(85, 27);
			this->input_num_delta_d->TabIndex = 11;
			this->input_num_delta_d->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9125, 0, 0, 196608 });
			// 
			// textBox182
			// 
			this->textBox182->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox182->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox182->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox182->Location = System::Drawing::Point(185, 50);
			this->textBox182->Multiline = true;
			this->textBox182->Name = L"textBox182";
			this->textBox182->Size = System::Drawing::Size(85, 41);
			this->textBox182->TabIndex = 12;
			this->textBox182->Text = L"Number of δd isolines";
			// 
			// input_max_delta_d
			// 
			this->input_max_delta_d->DecimalPlaces = 2;
			this->input_max_delta_d->Dock = System::Windows::Forms::DockStyle::Fill;
			this->input_max_delta_d->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_max_delta_d->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->input_max_delta_d->Location = System::Drawing::Point(276, 3);
			this->input_max_delta_d->Name = L"input_max_delta_d";
			this->input_max_delta_d->Size = System::Drawing::Size(85, 27);
			this->input_max_delta_d->TabIndex = 9;
			this->input_max_delta_d->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9125, 0, 0, 196608 });
			// 
			// textBox180
			// 
			this->textBox180->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox180->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox180->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox180->Location = System::Drawing::Point(3, 3);
			this->textBox180->Multiline = true;
			this->textBox180->Name = L"textBox180";
			this->textBox180->Size = System::Drawing::Size(85, 41);
			this->textBox180->TabIndex = 6;
			this->textBox180->Text = L"Maximum β [°]";
			// 
			// textBox181
			// 
			this->textBox181->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox181->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox181->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox181->Location = System::Drawing::Point(3, 50);
			this->textBox181->Multiline = true;
			this->textBox181->Name = L"textBox181";
			this->textBox181->Size = System::Drawing::Size(85, 41);
			this->textBox181->TabIndex = 8;
			this->textBox181->Text = L"Number of β isolines";
			// 
			// textBox183
			// 
			this->textBox183->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox183->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox183->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox183->Location = System::Drawing::Point(185, 3);
			this->textBox183->Multiline = true;
			this->textBox183->Name = L"textBox183";
			this->textBox183->Size = System::Drawing::Size(85, 41);
			this->textBox183->TabIndex = 10;
			this->textBox183->Text = L"Maximum δd [°]";
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
			this->input_max_beta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9125, 0, 0, 196608 });
			// 
			// input_num_beta
			// 
			this->input_num_beta->DecimalPlaces = 2;
			this->input_num_beta->Dock = System::Windows::Forms::DockStyle::Fill;
			this->input_num_beta->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_num_beta->Location = System::Drawing::Point(94, 50);
			this->input_num_beta->Name = L"input_num_beta";
			this->input_num_beta->Size = System::Drawing::Size(85, 27);
			this->input_num_beta->TabIndex = 7;
			this->input_num_beta->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9125, 0, 0, 196608 });
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
			this->debugPage->Location = System::Drawing::Point(4, 35);
			this->debugPage->Name = L"debugPage";
			this->debugPage->Padding = System::Windows::Forms::Padding(3);
			this->debugPage->Size = System::Drawing::Size(1075, 636);
			this->debugPage->TabIndex = 5;
			this->debugPage->Text = L"Debug";
			this->debugPage->UseVisualStyleBackColor = true;
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
			// output_iter_total
			// 
			this->output_iter_total->AutoSize = true;
			this->output_iter_total->Location = System::Drawing::Point(39, 284);
			this->output_iter_total->Name = L"output_iter_total";
			this->output_iter_total->Size = System::Drawing::Size(72, 26);
			this->output_iter_total->TabIndex = 8;
			this->output_iter_total->Text = L"DEBUG";
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1184, 675);
			this->Controls->Add(this->splitContainer1);
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing_1);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
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
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_t_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_t_f))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_L))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_ro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_h_CG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_ri))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_fo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m_u_fi))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_y))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_x))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_m))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_susp_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_susp_f))->EndInit();
			this->groupBox16->ResumeLayout(false);
			this->groupBox16->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_arb_5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_arb_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_arb_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_arb_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_r_arb_1))->EndInit();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_p_C_dist))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_p_C_deg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_r_C_dist))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_k_r_C_deg))->EndInit();
			this->groupBox15->ResumeLayout(false);
			this->groupBox15->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_f_arb_5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_f_arb_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_f_arb_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_f_arb_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_f_arb_1))->EndInit();
			this->tabControl3->ResumeLayout(false);
			this->tabPage8->ResumeLayout(false);
			this->groupBox17->ResumeLayout(false);
			this->groupBox17->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_r_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_r_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_r_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_f_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_f_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_p_f_2))->EndInit();
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
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_r_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_r_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_r_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_f_0))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_f_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_p_r_f_2))->EndInit();
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
			this->tabPage9->ResumeLayout(false);
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
			this->tabPage2->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
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
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_a_lon_des))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_V_input))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_lat_ratio_custom))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_lon_ratio_custom))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_delta_d_des))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_kappa_des))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_beta_des))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_R_min))->EndInit();
			this->groupBox10->ResumeLayout(false);
			this->groupBox10->PerformLayout();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_num_delta_d))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_max_delta_d))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_max_beta))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_num_beta))->EndInit();
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
			vehicle_inputs->R_min = System::Convert::ToDouble(input_R_min->Value);
			vehicle_inputs->beta_des = System::Convert::ToDouble(input_beta_des->Value);
			vehicle_inputs->delta_d_des = System::Convert::ToDouble(input_delta_d_des->Value);
			vehicle_inputs->kappa_des = System::Convert::ToDouble(input_kappa_des->Value);
			vehicle_inputs->lon_ratio_custom = System::Convert::ToDouble(input_lon_ratio_custom->Value);
			vehicle_inputs->lat_ratio_custom = System::Convert::ToDouble(input_lat_ratio_custom->Value);
			vehicle_inputs->delta_f_static = System::Convert::ToDouble(input_delta_f_static->Value);
			vehicle_inputs->delta_r_static = System::Convert::ToDouble(input_delta_r_static->Value);
			vehicle_inputs->gamma_f_static = System::Convert::ToDouble(input_gamma_f_static->Value);
			vehicle_inputs->gamma_r_static = System::Convert::ToDouble(input_gamma_r_static->Value);
			vehicle_inputs->BB_input = System::Convert::ToDouble(input_BB_input->Value);
			vehicle_inputs->DB_input = System::Convert::ToDouble(input_DB_input->Value);
			vehicle_inputs->corner_type = static_cast<Corner_type>(input_corner_type->SelectedIndex + 1);
			vehicle_inputs->corner_side = static_cast<Corner_side>(input_corner_side->SelectedIndex + 1);
			vehicle_inputs->pedals_input = static_cast<Pedals_input>(input_pedals_input->SelectedIndex + 1);
			vehicle_inputs->steering_input = static_cast<Steering_input>(input_steering_input->SelectedIndex + 1);
			vehicle_inputs->front_tires_selection = sto_(msclr::interop::marshal_as<std::string>(input_front_tires_selection->Text));
			vehicle_inputs->rear_tires_selection = sto_(msclr::interop::marshal_as<std::string>(input_rear_tires_selection->Text));
			vehicle_inputs->front_arb = static_cast<Arb_setup>(input_front_arb->SelectedIndex + 1);
			vehicle_inputs->rear_arb = static_cast<Arb_setup>(input_rear_arb->SelectedIndex + 1);
			vehicle_inputs->force_velocity = input_force_velocity->Checked;
			vehicle_inputs->force_a_lon = input_force_a_lon->Checked;
			vehicle_inputs->max_beta = System::Convert::ToDouble(input_max_beta->Value);
			vehicle_inputs->num_beta = System::Convert::ToDouble(input_num_beta->Value);
			vehicle_inputs->max_delta_d = System::Convert::ToDouble(input_max_delta_d->Value);
			vehicle_inputs->num_delta_d = System::Convert::ToDouble(input_num_delta_d->Value);
			vehicle_inputs->a_lon_des = System::Convert::ToDouble(input_a_lon_des->Value);

			//Vehicle inputs
			vehicle_inputs->L = System::Convert::ToDouble(input_L->Value);
			vehicle_inputs->m = System::Convert::ToDouble(input_m->Value);
			vehicle_inputs->x = System::Convert::ToDouble(input_x->Value);
			vehicle_inputs->y = System::Convert::ToDouble(input_y->Value);
			vehicle_inputs->t_f = System::Convert::ToDouble(input_t_f->Value);
			vehicle_inputs->t_r = System::Convert::ToDouble(input_t_r->Value);
			vehicle_inputs->m_u_fi = System::Convert::ToDouble(input_m_u_fi->Value);
			vehicle_inputs->m_u_fo = System::Convert::ToDouble(input_m_u_fo->Value);
			vehicle_inputs->m_u_ri = System::Convert::ToDouble(input_m_u_ri->Value);
			vehicle_inputs->m_u_ro = System::Convert::ToDouble(input_m_u_ro->Value);
			vehicle_inputs->h_CG = System::Convert::ToDouble(input_h_CG->Value);
			vehicle_inputs->brake_config = static_cast<Actuator_config>(input_brake_config->SelectedIndex + 1);
			vehicle_inputs->brake_type_f = static_cast<Actuator_type>(input_brake_type_f->SelectedIndex + 1);
			vehicle_inputs->brake_type_r = static_cast<Actuator_type>(input_brake_type_r->SelectedIndex + 1);
			vehicle_inputs->drive_config = static_cast<Actuator_config>(input_drive_config->SelectedIndex + 1);
			vehicle_inputs->diff_type_f = static_cast<Actuator_type>(input_diff_type_f->SelectedIndex + 1);
			vehicle_inputs->diff_type_r = static_cast<Actuator_type>(input_diff_type_r->SelectedIndex + 1);

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
			vehicle_inputs->f_arb_1 = System::Convert::ToDouble(input_f_arb_1->Value);
			vehicle_inputs->f_arb_2 = System::Convert::ToDouble(input_f_arb_2->Value);
			vehicle_inputs->f_arb_3 = System::Convert::ToDouble(input_f_arb_3->Value);
			vehicle_inputs->f_arb_4 = System::Convert::ToDouble(input_f_arb_4->Value);
			vehicle_inputs->f_arb_5 = System::Convert::ToDouble(input_f_arb_5->Value);
			vehicle_inputs->r_arb_1 = System::Convert::ToDouble(input_r_arb_1->Value);
			vehicle_inputs->r_arb_2 = System::Convert::ToDouble(input_r_arb_2->Value);
			vehicle_inputs->r_arb_3 = System::Convert::ToDouble(input_r_arb_3->Value);
			vehicle_inputs->r_arb_4 = System::Convert::ToDouble(input_r_arb_4->Value);
			vehicle_inputs->r_arb_5 = System::Convert::ToDouble(input_r_arb_5->Value);
		
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
			vehicle_inputs->p_r_f_2 = System::Convert::ToDouble(input_p_r_f_2->Value);
			vehicle_inputs->p_r_f_1 = System::Convert::ToDouble(input_p_r_f_1->Value);
			vehicle_inputs->p_r_f_0 = System::Convert::ToDouble(input_p_r_f_0->Value);
			vehicle_inputs->p_r_r_2 = System::Convert::ToDouble(input_p_r_r_2->Value);
			vehicle_inputs->p_r_r_1 = System::Convert::ToDouble(input_p_r_r_1->Value);
			vehicle_inputs->p_r_r_0 = System::Convert::ToDouble(input_p_r_r_0->Value);
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
			vehicle_inputs->p_p_f_2 = System::Convert::ToDouble(input_p_p_f_2->Value);
			vehicle_inputs->p_p_f_1 = System::Convert::ToDouble(input_p_p_f_1->Value);
			vehicle_inputs->p_p_f_0 = System::Convert::ToDouble(input_p_p_f_0->Value);
			vehicle_inputs->p_p_r_2 = System::Convert::ToDouble(input_p_p_r_2->Value);
			vehicle_inputs->p_p_r_1 = System::Convert::ToDouble(input_p_p_r_1->Value);
			vehicle_inputs->p_p_r_0 = System::Convert::ToDouble(input_p_p_r_0->Value);

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
		}

		void MyForm::write_inputs()
		{
			//Simulation inputs
			input_V_input->Value = System::Convert::ToDecimal(vehicle_inputs->V_input);
			input_R_min->Value = System::Convert::ToDecimal(vehicle_inputs->R_min);
			input_beta_des->Value = System::Convert::ToDecimal(vehicle_inputs->beta_des);
			input_delta_d_des->Value = System::Convert::ToDecimal(vehicle_inputs->delta_d_des);
			input_kappa_des->Value = System::Convert::ToDecimal(vehicle_inputs->kappa_des);
			input_lon_ratio_custom->Value = System::Convert::ToDecimal(vehicle_inputs->lon_ratio_custom);
			input_lat_ratio_custom->Value = System::Convert::ToDecimal(vehicle_inputs->lat_ratio_custom);
			input_delta_f_static->Value = System::Convert::ToDecimal(vehicle_inputs->delta_f_static);
			input_delta_r_static->Value = System::Convert::ToDecimal(vehicle_inputs->delta_r_static);
			input_gamma_f_static->Value = System::Convert::ToDecimal(vehicle_inputs->gamma_f_static);
			input_gamma_r_static->Value = System::Convert::ToDecimal(vehicle_inputs->gamma_r_static);
			input_BB_input->Value = System::Convert::ToDecimal(vehicle_inputs->BB_input);
			input_DB_input->Value = System::Convert::ToDecimal(vehicle_inputs->DB_input);
			input_corner_type->SelectedIndex = static_cast<int>(vehicle_inputs->corner_type) - 1;
			input_corner_side->SelectedIndex = static_cast<int>(vehicle_inputs->corner_side) - 1;
			input_pedals_input->SelectedIndex = static_cast<int>(vehicle_inputs->pedals_input) - 1;
			input_steering_input->SelectedIndex = static_cast<int>(vehicle_inputs->steering_input) - 1;
			input_front_tires_selection->Text = gcnew System::String(_tos(vehicle_inputs->front_tires_selection).c_str());
			input_rear_tires_selection->Text = gcnew System::String(_tos(vehicle_inputs->rear_tires_selection).c_str());
			input_front_arb->SelectedIndex = static_cast<int>(vehicle_inputs->front_arb) - 1;
			input_rear_arb->SelectedIndex = static_cast<int>(vehicle_inputs->rear_arb) - 1;
			input_force_velocity->Checked = vehicle_inputs->force_velocity;
			input_force_a_lon->Checked = vehicle_inputs->force_a_lon;
			input_max_beta->Value = System::Convert::ToDecimal(vehicle_inputs->max_beta);
			input_num_beta->Value = System::Convert::ToDecimal(vehicle_inputs->num_beta);
			input_max_delta_d->Value = System::Convert::ToDecimal(vehicle_inputs->max_delta_d);
			input_num_delta_d->Value = System::Convert::ToDecimal(vehicle_inputs->num_delta_d);
			input_a_lon_des->Value = System::Convert::ToDecimal(vehicle_inputs->a_lon_des);

			//Vehicle inputs
			input_m->Value = System::Convert::ToDecimal(vehicle_inputs->m);
			input_x->Value = System::Convert::ToDecimal(vehicle_inputs->x);
			input_y->Value = System::Convert::ToDecimal(vehicle_inputs->y);
			input_L->Value = System::Convert::ToDecimal(vehicle_inputs->L);
			input_t_f->Value = System::Convert::ToDecimal(vehicle_inputs->t_f);
			input_t_r->Value = System::Convert::ToDecimal(vehicle_inputs->t_r);
			input_h_CG->Value = System::Convert::ToDecimal(vehicle_inputs->h_CG);
			input_m_u_fi->Value = System::Convert::ToDecimal(vehicle_inputs->m_u_fi);
			input_m_u_fo->Value = System::Convert::ToDecimal(vehicle_inputs->m_u_fo);
			input_m_u_ri->Value = System::Convert::ToDecimal(vehicle_inputs->m_u_ri);
			input_m_u_ro->Value = System::Convert::ToDecimal(vehicle_inputs->m_u_ro);
			input_brake_config->SelectedIndex = static_cast<int>(vehicle_inputs->brake_config) - 1;
			input_brake_type_f->SelectedIndex = static_cast<int>(vehicle_inputs->brake_type_f) - 1;
			input_brake_type_r->SelectedIndex = static_cast<int>(vehicle_inputs->brake_type_r) - 1;
			input_drive_config->SelectedIndex = static_cast<int>(vehicle_inputs->drive_config) - 1;
			input_diff_type_f->SelectedIndex = static_cast<int>(vehicle_inputs->diff_type_f) - 1;
			input_diff_type_r->SelectedIndex = static_cast<int>(vehicle_inputs->diff_type_r) - 1;
		
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
			input_f_arb_1->Value = System::Convert::ToDecimal(vehicle_inputs->f_arb_1);
			input_f_arb_2->Value = System::Convert::ToDecimal(vehicle_inputs->f_arb_2);
			input_f_arb_3->Value = System::Convert::ToDecimal(vehicle_inputs->f_arb_3);
			input_f_arb_4->Value = System::Convert::ToDecimal(vehicle_inputs->f_arb_4);
			input_f_arb_5->Value = System::Convert::ToDecimal(vehicle_inputs->f_arb_5);
			input_r_arb_1->Value = System::Convert::ToDecimal(vehicle_inputs->r_arb_1);
			input_r_arb_2->Value = System::Convert::ToDecimal(vehicle_inputs->r_arb_2);
			input_r_arb_3->Value = System::Convert::ToDecimal(vehicle_inputs->r_arb_3);
			input_r_arb_4->Value = System::Convert::ToDecimal(vehicle_inputs->r_arb_4);
			input_r_arb_5->Value = System::Convert::ToDecimal(vehicle_inputs->r_arb_5);

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
			input_p_r_f_2->Value = System::Convert::ToDecimal(vehicle_inputs->p_r_f_2);
			input_p_r_f_1->Value = System::Convert::ToDecimal(vehicle_inputs->p_r_f_1);
			input_p_r_f_0->Value = System::Convert::ToDecimal(vehicle_inputs->p_r_f_0);
			input_p_r_r_2->Value = System::Convert::ToDecimal(vehicle_inputs->p_r_r_2);
			input_p_r_r_1->Value = System::Convert::ToDecimal(vehicle_inputs->p_r_r_1);
			input_p_r_r_0->Value = System::Convert::ToDecimal(vehicle_inputs->p_r_r_0);
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
			input_p_p_f_2->Value = System::Convert::ToDecimal(vehicle_inputs->p_p_f_2);
			input_p_p_f_1->Value = System::Convert::ToDecimal(vehicle_inputs->p_p_f_1);
			input_p_p_f_0->Value = System::Convert::ToDecimal(vehicle_inputs->p_p_f_0);
			input_p_p_r_2->Value = System::Convert::ToDecimal(vehicle_inputs->p_p_r_2);
			input_p_p_r_1->Value = System::Convert::ToDecimal(vehicle_inputs->p_p_r_1);
			input_p_p_r_0->Value = System::Convert::ToDecimal(vehicle_inputs->p_p_r_0);
			
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
			output_a_lat->Text = System::String::Format("Lateral acceleration: {0:F2} g", System::Convert::ToDouble(vehicle_outputs->a_lat));
			output_a_lon->Text = System::String::Format("Longitudinal acceleration: {0:F2} g", System::Convert::ToDouble(vehicle_outputs->a_lon));
			output_F_lat->Text = System::String::Format("Lateral force: {0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lat));
			output_F_lon->Text = System::String::Format("Longitudinal force: {0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lon));
			output_a_rad->Text = System::String::Format("Radial acceleration: {0:F2} g", System::Convert::ToDouble(vehicle_outputs->a_rad));
			output_phi_deg->Text = System::String::Format("Pitch angle: {0:F2}°", System::Convert::ToDouble(vehicle_outputs->phi_deg));
			output_psi_deg->Text = System::String::Format("Roll angle: {0:F2}°", System::Convert::ToDouble(vehicle_outputs->psi_deg));
			output_iter->Text = System::String::Format("Iterations: {0}", System::Convert::ToInt32(vehicle_outputs->iter));
			output_V->Text = System::String::Format("Velocity: {0:F2} km/h", System::Convert::ToDouble(vehicle_outputs->V));
			output_R->Text = (vehicle_outputs->R < 1e5) ? System::String::Format("Turn radius: {0:F2} m", System::Convert::ToDouble(vehicle_outputs->R)) : "Turn radius: straight line";
			output_bias_now->Text = System::String::Format("Current bias: {0:F2}%", System::Convert::ToDouble(vehicle_outputs->bias_now));

			output_alpha_fi->Text = System::String::Format("{0:F2}°", System::Convert::ToDouble(vehicle_outputs->alpha_fi));
			output_alpha_fo->Text = System::String::Format("{0:F2}°", System::Convert::ToDouble(vehicle_outputs->alpha_fo));
			output_alpha_ri->Text = System::String::Format("{0:F2}°", System::Convert::ToDouble(vehicle_outputs->alpha_ri));
			output_alpha_ro->Text = System::String::Format("{0:F2}°", System::Convert::ToDouble(vehicle_outputs->alpha_ro));
			
			output_kappa_fi->Text = System::String::Format("{0:F2}%", System::Convert::ToDouble(vehicle_outputs->kappa_fi));
			output_kappa_fo->Text = System::String::Format("{0:F2}%", System::Convert::ToDouble(vehicle_outputs->kappa_fo));
			output_kappa_ri->Text = System::String::Format("{0:F2}%", System::Convert::ToDouble(vehicle_outputs->kappa_ri));
			output_kappa_ro->Text = System::String::Format("{0:F2}%", System::Convert::ToDouble(vehicle_outputs->kappa_ro));
			
			output_F_z_fi->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_z_fi));
			output_F_z_fo->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_z_fo));
			output_F_z_ri->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_z_ri));
			output_F_z_ro->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_z_ro));

			output_F_x_comb_fi->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_x_comb_fi));
			output_F_x_comb_fo->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_x_comb_fo));
			output_F_x_comb_ri->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_x_comb_ri));
			output_F_x_comb_ro->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_x_comb_ro));

			output_F_y_comb_fi->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_y_comb_fi));
			output_F_y_comb_fo->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_y_comb_fo));
			output_F_y_comb_ri->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_y_comb_ri));
			output_F_y_comb_ro->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_y_comb_ro));

			output_F_lat_fi->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lat_fi));
			output_F_lat_fo->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lat_fo));
			output_F_lat_ri->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lat_ri));
			output_F_lat_ro->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lat_ro));

			output_F_lon_fi->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lon_fi));
			output_F_lon_fo->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lon_fo));
			output_F_lon_ri->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lon_ri));
			output_F_lon_ro->Text = System::String::Format("{0:F2} N", System::Convert::ToDouble(vehicle_outputs->F_lon_ro));

			output_T_fi->Text = System::String::Format("{0:F2} Nm", System::Convert::ToDouble(vehicle_outputs->T_fi));
			output_T_fo->Text = System::String::Format("{0:F2} Nm", System::Convert::ToDouble(vehicle_outputs->T_fo));
			output_T_ri->Text = System::String::Format("{0:F2} Nm", System::Convert::ToDouble(vehicle_outputs->T_ri));
			output_T_ro->Text = System::String::Format("{0:F2} Nm", System::Convert::ToDouble(vehicle_outputs->T_ro));
		
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
			output_iter_total->Text = System::String::Format("Total main solver iterations: {0}", System::Convert::ToInt32(vehicle_outputs->iter_total));
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
	save_inputs(*vehicle_inputs, "Vehicle_params_1.txt");
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
#ifndef _DEBUG
	this->tabControl1->TabPages->Remove(this->debugPage);
#endif
	try {
		sim_controller->load_form(*vehicle_inputs, *vehicle_outputs);
	}
	catch (const std::exception& e) {
		MessageBox::Show(gcnew System::String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	write_inputs();
	write_outputs();
	load_tire_list();
	select_tire();
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
private: System::Void input_R_min_ValueChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
};
}

