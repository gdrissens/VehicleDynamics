#include "Vehicle.h"
#include "Tire.h"
#include <cmath>
#include <iostream>
#include <vector>
#include "Inputs.h"
#include "Outputs.h"

Vehicle::Vehicle() {};

    void Vehicle::set_tires(std::string front_tire_file, std::string rear_tire_file) {
        load_tire_inputs(front_tires, front_tire_file), load_tire_inputs(rear_tires, rear_tire_file);

        fi.set_position('F', 'I'), fo.set_position('F', 'O'), ri.set_position('R', 'I'), ro.set_position('R', 'O');

        fi.set_parameters(front_tires), fo.set_parameters(front_tires), ri.set_parameters(rear_tires), ro.set_parameters(rear_tires);

    }

    void Vehicle::set_parameters(const Vehicle_inputs& inputs) {

        vehicle_inputs = inputs;


        //Driver input
        pedals_input = vehicle_inputs.pedals_input; // (INPUT)
        steering_input = vehicle_inputs.steering_input; // (INPUT)

        //Drive and Brake bias
        drive_config = vehicle_inputs.drive_config; // (INPUT)
        brake_config = vehicle_inputs.brake_config; // (INPUT)
        BB_input = vehicle_inputs.BB_input; // [%front] Brake bias (front) (INPUT)
        DB_input = vehicle_inputs.DB_input; // [%front] Torque bias (front) (INPUT)

        //Differential and Brake configurations
        brake_type_f = vehicle_inputs.brake_type_f; // (INPUT)
        brake_type_r = vehicle_inputs.brake_type_r; // (INPUT)
        diff_type_f = vehicle_inputs.diff_type_f; // (INPUT)
        diff_type_r = vehicle_inputs.diff_type_r; // (INPUT)

        //Setup parameters
        delta_f_static = vehicle_inputs.delta_f_static; // [deg] Front static toe angle (+ out) (INPUT)
        delta_r_static = vehicle_inputs.delta_r_static; // [deg] Rear static toe angle (+ out) (INPUT)
        gamma_f_static = vehicle_inputs.gamma_f_static * pi / 180; // [rad] Front static camber angle (INPUT)
        gamma_r_static = vehicle_inputs.gamma_r_static * pi / 180; // [rad] Rear static camber angle (INPUT)

        //Vehicle size
        L = vehicle_inputs.L / 1000.0; // [m] Wheelbase length (INPUT)
        t_f = vehicle_inputs.t_f / 1000.0; // [m] Front track length (INPUT)
        t_r = vehicle_inputs.t_r / 1000.0; // [m] Rear track length (INPUT)

        //Masses and weights

        //Total masses and weights
        m = vehicle_inputs.m; // [kg] Total vehicle mass (w/driver) (INPUT)
        x = vehicle_inputs.x; // [%front] Front load distribution (INPUT)
        y = vehicle_inputs.y; // [%right] Left load distribution (INPUT)

        //Unsprung masses
        m_u_fi = vehicle_inputs.m_u_fi; // [kg] Front inner unsprung mass (INPUT)
        m_u_fo = vehicle_inputs.m_u_fo; // [kg] Front outer unsprung mass (INPUT)
        m_u_ri = vehicle_inputs.m_u_ri; // [kg] Rear inner unsprung mass (INPUT)
        m_u_ro = vehicle_inputs.m_u_ro; // [kg] Rear outer unsprung mass (INPUT)

        //CG location
        h_CG = vehicle_inputs.h_CG / 1000.0; // [m] Height of the center of gravity (INPUT)

        //Ackermann geometry

        //Actual cornering radius calculation
        R = vehicle_inputs.R; // [m] Minimum cornering radius (from CG) (INPUT)
        beta_deg = vehicle_inputs.beta_deg; // [deg] Desired vehicle sideslip angle (INPUT)

        //Steering angles
        delta_d_deg = vehicle_inputs.delta_d_deg; // [deg] Desired front outer wheel steering angle (MAX 115)                            INPUT

        //Slip ratios
        kappa_des = vehicle_inputs.kappa_des / 100.0; // [-] Desired slip ratio (INPUT)

        //Chassis torsional stiffness
        k_r_C_deg = vehicle_inputs.k_r_C_deg; // [N*m/deg] Chassis torsional stiffness (INPUT)
        k_r_C_dist = vehicle_inputs.k_r_C_dist; // [%front] Chassis torsional stiffness distribution to the front suspension (INPUT)
        k_p_C_deg = vehicle_inputs.k_p_C_deg; // [N*m/deg] Chassis pitching stiffness (INPUT)
        k_p_C_dist = vehicle_inputs.k_p_C_dist; // [%left] Chassis pitching stiffness distribution to the left suspension (INPUT)

        //Springs and anti-roll bars
        k_susp_f = vehicle_inputs.k_susp_f * 1000.0; // [N/m] Front suspension spring stiffness (INPUT)
        k_susp_r = vehicle_inputs.k_susp_r * 1000.0; // [N/m] Rear suspension spring stiffness (INPUT)
		switch (vehicle_inputs.front_arb) {
            case Arb_setup::one: k_arb_f = vehicle_inputs.f_arb_1 * 1000.0; break; // [N/m] Front anti-roll bar stiffness (INPUT)
            case Arb_setup::two: k_arb_f = vehicle_inputs.f_arb_2 * 1000.0; break; // [N/m] Front anti-roll bar stiffness (INPUT)
            case Arb_setup::three: k_arb_f = vehicle_inputs.f_arb_3 * 1000.0; break; // [N/m] Front anti-roll bar stiffness (INPUT)
            case Arb_setup::four: k_arb_f = vehicle_inputs.f_arb_4 * 1000.0; break; // [N/m] Front anti-roll bar stiffness (INPUT)
            case Arb_setup::five: k_arb_f = vehicle_inputs.f_arb_5 * 1000.0; break; // [N/m] Front anti-roll bar stiffness (INPUT)
            default: k_arb_f = (vehicle_inputs.f_arb_1) * 1000.0; break;
        }
        switch (vehicle_inputs.rear_arb) {
            case Arb_setup::one: k_arb_r = vehicle_inputs.r_arb_1 * 1000.0; break; // [N/m] Rear anti-roll bar stiffness (INPUT)
            case Arb_setup::two: k_arb_r = vehicle_inputs.r_arb_2 * 1000.0; break; // [N/m] Rear anti-roll bar stiffness (INPUT)
            case Arb_setup::three: k_arb_r = vehicle_inputs.r_arb_3 * 1000.0; break; // [N/m] Rear anti-roll bar stiffness (INPUT)
            case Arb_setup::four: k_arb_r = vehicle_inputs.r_arb_4 * 1000.0; break; // [N/m] Rear anti-roll bar stiffness (INPUT)
            case Arb_setup::five: k_arb_r = vehicle_inputs.r_arb_5 * 1000.0; break; // [N/m] Rear anti-roll bar stiffness (INPUT)
            default: k_arb_r = (vehicle_inputs.r_arb_1) * 1000.0; break;
		}

        //Vehicle speed
        V = V_input = vehicle_inputs.V_input; // [km/h] Vehicle speed input (INPUT)
        V_ratio = 1.0;
    }

    void Vehicle::solver() {

        //refresh();

        vehicle_parameters();

        ackermann_diagram();

        //Slip angles
        fi.set_alpha(a_rad), fo.set_alpha(a_rad), ri.set_alpha(a_rad), ro.set_alpha(a_rad);

        //Slip ratios
        fi.kappa = fo.kappa = ri.kappa = ro.kappa = kappa_des; // [-] Wheel slip ratios

		chassis_stiffnesses();

        //Main iterative loop
        iter = 0; // Iteration counters for slip ratio calculations
        F_z_tol = 0.01; // [N] Acceptable wheel load error for the iterative process
        max_iter = 50; // Maximum number of iterations for the iterative process

        do {
            
            update_tires();

            accelerations();

            unsprung_masses();

            suspension_kinematics();

            aerodynamics();

            longitudinal_load_transfer();

            lateral_load_transfer();

            update_wheel_loads_and_displacements();

            iter++;
            if (iter > max_iter) { break; }
            bias_now = (fi.T + fo.T) / (fi.T + fo.T + ri.T + ro.T);

        } while (fi.F_z_err > F_z_tol || fo.F_z_err > F_z_tol || ri.F_z_err > F_z_tol || ro.F_z_err > F_z_tol);

        yaw_moment();
    }

    void Vehicle::vehicle_parameters() {

        //Driver input
        if (vehicle_inputs.force_a_lon) {
            force_a_lon = true;
            a_lon_des = vehicle_inputs.a_lon_des * g;
        }
        if (pedals_input == Pedals_input::Cruising) { force_a_lon = true; a_lon_des = 0.0; }
        if (pedals_input == Pedals_input::Coasting) { force_a_lon = false; kappa_des = 0.0; }
		if (pedals_input == Pedals_input::Driving) { lon_sign  = 1.0; }
		if (pedals_input == Pedals_input::Braking) { lon_sign = -1.0; }

        //Drive and Brake bias
        DB = (drive_config == Actuator_config::Front) ? 100.0 : (drive_config == Actuator_config::Rear) ? 0.0 : DB_input; // [%front] Torque bias
        BB = (brake_config == Actuator_config::Front) ? 100.0 : (brake_config == Actuator_config::Rear) ? 0.0 : BB_input; // [%front] Brake bias
        bias = (lon_sign >= 0) ? DB / 100.0 : BB / 100.0; // [%front] Torque or brake bias

        //Masses and weights

        //Total masses and weights
        W = m * g; // [N] Total weight of the vehicle (w/driver)
        wheel_loads();

        //Unsprung masses
        m_u = m_u_fi + m_u_fo + m_u_ri + m_u_ro; // [kg] Total unsprung mass

        //Sprung masses
        m_s = m - m_u; // [kg] Total sprung mass

        //Wheel loads
        fi.F_z = W_fi; // [N] Front inner wheel load
        fo.F_z = W_fo; // [N] Front outer wheel load
        ri.F_z = W_ri; // [N] Rear inner wheel load
        ro.F_z = W_ro; // [N] Rear outer wheel load

        //CG location
        a = L * (1 - x / 100); // [m] Distance from the front axle to the CG
        b = L * x / 100; // [m] Distance from the rear axle to the CG
        a_s = (m * a - (m_u_ri + m_u_ro) * L) / m_s; // [m] Distance from the front axle to the sprung mass CG
        b_s = (m * b - (m_u_fi + m_u_fo) * L) / m_s; // [m] Distance from the rear axle to the sprung mass CG
    }

    void Vehicle::wheel_loads() {
        W_fi = W * x / 100.0 * y / 100.0; // [N] Front inner weight
        W_fo = W * x / 100.0 * (1 - y / 100.0); // [N] Front outer weight
        W_ri = W * (1 - x / 100.0) * y / 100.0; // [N] Rear inner weight
        W_ro = W * (1 - x / 100.0) * (1 - y / 100.0); // [N] Rear outer weight
    }

    void Vehicle::ackermann_diagram() {
       //Ackermann geometry

       //Actual cornering radius calculation
        beta_deg = vehicle_inputs.beta_deg;
        beta = beta_deg < 1E-10 && beta_deg > -1E-10 ? 0 : beta_deg * pi / 180.0; // [rad] Vehicle sideslip angle   
        R_a = R * cos(beta); // [m] Actual cornering radius
        S_f = a + R * sin(beta); // [m]
        S_r = L - S_f; // [m]

        //Tire cornering radius
        fi.R = sqrt((R_a - t_f / 2) * (R_a - t_f / 2) + S_f * S_f); // [m] Front inner wheel cornering radius
        fo.R = sqrt((R_a + t_f / 2) * (R_a + t_f / 2) + S_f * S_f); // [m] Front outer wheel cornering radius
        ri.R = sqrt((R_a - t_r / 2) * (R_a - t_r / 2) + S_r * S_r); // [m] Rear inner wheel cornering radius
        ro.R = sqrt((R_a + t_r / 2) * (R_a + t_r / 2) + S_r * S_r); // [m] Rear outer wheel cornering radius

        //Steering angles
        delta_d_deg = vehicle_inputs.delta_d_deg;
        fi.delta = (abs(delta_d_deg * delta_d_deg * vehicle_inputs.ackermann_2 + delta_d_deg * vehicle_inputs.ackermann_1) + delta_f_static) * pi / 180.0 * copysign(1.0, delta_d_deg); // [rad] Front outer wheel steering angle (INPUT)
        fo.delta = (abs(delta_d_deg * delta_d_deg * vehicle_inputs.ackermann_2 + delta_d_deg * vehicle_inputs.ackermann_1) - delta_f_static) * pi / 180.0 * copysign(1.0, delta_d_deg); // [rad] Front inner wheel steering angle (INPUT)
        ri.delta = (delta_r_static) * pi / 180; // [rad] Rear inner wheel steering angle
        ro.delta = (delta_r_static) * pi / 180; // [rad] Rear outer wheel steering angle

        //Effective steering angles
        fi.theta = atan(S_f / (R_a - t_f / 2)); // [rad] Front inner wheel effective steering angle
        fo.theta = atan(S_f / (R_a + t_f / 2)); // [rad] Front outer wheel effective steering angle
        ri.theta = atan(S_r / (R_a - t_r / 2)); // [rad] Rear inner wheel effective steering angle
        ro.theta = atan(S_r / (R_a + t_r / 2)); // [rad] Rear outer wheel effective steering angle
    }

    void Vehicle::chassis_stiffnesses() {

        //Chassis torsional stiffness
        k_r_C = k_r_C_deg * 180.0 / pi; // [N*m/rad] Chassis torsional stiffness
        k_r_C_f = k_r_C * k_r_C_dist / 100.0; // [N*m/rad] Chassis torsional stiffness to the front suspension
        k_r_C_r = k_r_C * (1 - k_r_C_dist / 100.0); // [N*m/rad] Chassis torsional stiffness to the rear suspension
        k_p_C = k_p_C_deg * 180.0 / pi; // [N*m/rad] Chassis pitching stiffness
        k_p_C_i = k_p_C * k_p_C_dist / 100.0; // [N*m/rad] Chassis pitching stiffness to the inner suspension
        k_p_C_o = k_p_C * (1 - k_p_C_dist / 100.0); // [N*m/rad] Chassis pitching stiffness to the outter suspension
		}

    void Vehicle::update_tires() {
        //Tires

           //Radial tire stiffness
        fi.set_K_T(), fo.set_K_T(), ri.set_K_T(), ro.set_K_T();

        //Tire radius
        fi.set_r(), fo.set_r(), ri.set_r(), ro.set_r();

        //Pacejka parameters
        fi.set_Pacejka(), fo.set_Pacejka(), ri.set_Pacejka(), ro.set_Pacejka();

        //Lateral Pacejka
        fi.set_F_y(V_ratio), fo.set_F_y(V_ratio), ri.set_F_y(V_ratio), ro.set_F_y(V_ratio);

        //Longitudinal Pacejka and Longitudinal modified Nicolas-Comstock
        solve_kappa();

        //Lateral modified Nicolas-Comstock
        fi.set_F_y_comb(a_rad), fo.set_F_y_comb(a_rad), ri.set_F_y_comb(a_rad), ro.set_F_y_comb(a_rad);

        //Reaction torques
        fi.set_T_r(lon_sign, brake_type_f, diff_type_f), fo.set_T_r(lon_sign, brake_type_f, diff_type_f), ri.set_T_r(lon_sign, brake_type_r, diff_type_r), ro.set_T_r(lon_sign, brake_type_r, diff_type_r);
    
        //Tires rolling resistances
        fi.set_F_rr(V), fo.set_F_rr(V), ri.set_F_rr(V), ro.set_F_rr(V);
    }

    void Vehicle::accelerations() {
        //Accelerations

                //Lateral accelerations
        fi.set_F_lat(), fo.set_F_lat(), ri.set_F_lat(), ro.set_F_lat();
        F_lat = fi.F_lat + fo.F_lat + ri.F_lat + ro.F_lat; // [N] Total lateral force
        a_lat = F_lat / W; // [g] Vehicle lateral acceleration

        //Longitudinal accelerations
        fi.set_F_lon(), fo.set_F_lon(), ri.set_F_lon(), ro.set_F_lon();
        F_lon = fi.F_lon + fo.F_lon + ri.F_lon + ro.F_lon - F_drag; // [N] Total longitudinal force
        a_lon = F_lon / W; // [g] Vehicle longitudinal acceleration

        //Cornering radial accelerations
        fi.set_F_rad(), fo.set_F_rad(), ri.set_F_rad(), ro.set_F_rad();
        F_rad = fi.F_rad + fo.F_rad + ri.F_rad + ro.F_rad - F_drag * sin(beta); // [N] Total cornering radial force
        a_rad = (abs(F_rad / W) < 1e-10) ? 1e-10 : F_rad / W; // [g] Vehicle cornering radial acceleration

        //Set corner side
        if (a_lat < 0) { 
            if (iter == 0) {
                y = 100.0 - y; // Adjust left load distribution if cornering to the left
                wheel_loads(); // Update wheel loads based on the new cornering direction
            }

            if (!vehicle_inputs.force_velocity) {
                R = -abs(R); // [m] Cornering radius (from CG)
                ackermann_diagram();
                fi.set_alpha(a_lat), fo.set_alpha(a_lat), ri.set_alpha(a_lat), ro.set_alpha(a_lat);
                fi.set_F_y_comb(a_lat), fo.set_F_y_comb(a_lat), ri.set_F_y_comb(a_lat), ro.set_F_y_comb(a_lat);
            }
        }
    }

    void Vehicle::unsprung_masses() {
        //Sprung and unsprung masses CG location

        h_CG_u_fi = fi.r; // [m] Height of the unsprung mass CG        
        h_CG_u_fo = fo.r; // [m] Height of the unsprung mass CG        
        h_CG_u_ri = ri.r; // [m] Height of the unsprung mass CG
        h_CG_u_ro = ro.r; // [m] Height of the unsprung mass CG    
        h_CG_u = (h_CG_u_fi * m_u_fi + h_CG_u_fo * m_u_fo + h_CG_u_ri * m_u_ri + h_CG_u_ro * m_u_ro) / m_u; // [m] Height of the unsprung masses CG
        h_CG_s = (m * h_CG - m_u * h_CG_u) / m_s; // [m] Height of the sprung mass CG           
    }

    void Vehicle::suspension_kinematics(){
        //Suspension geometry

        //Roll suspension parameters
        h_r_f = (psi_deg * psi_deg * vehicle_inputs.h_r_f_2 + psi_deg * vehicle_inputs.h_r_f_1 + vehicle_inputs.h_r_f_0) / 1000.0; // [m] Height of the front roll center                                            INPUT
        h_r_r = (psi_deg * psi_deg * vehicle_inputs.h_r_r_2 + psi_deg * vehicle_inputs.h_r_r_1 + vehicle_inputs.h_r_r_0) / 1000.0; // [m] Height of the rear roll center                                              INPUT
        off_r_f = (psi_deg * psi_deg * vehicle_inputs.off_r_f_2 + psi_deg * vehicle_inputs.off_r_f_1 + vehicle_inputs.off_r_f_0) / 1000.0; // [m] Front roll center offset from the vehicle center line (+ inner)            INPUT
        off_r_r = (psi_deg * psi_deg * vehicle_inputs.off_r_r_2 + psi_deg * vehicle_inputs.off_r_r_1 + vehicle_inputs.off_r_r_0) / 1000.0; // [m] Rear roll center offset from the vehicle center line (+ inner)             INPUT
        n_r_fi = t_f / 2 - off_r_f; // [m] Front roll center distance from the front inner wheel
        n_r_fo = t_f / 2 + off_r_f; // [m] Front roll center distance from the front outer wheel
        n_r_ri = t_r / 2 - off_r_r; // [m] Rear roll center distance from the rear inner wheel
        n_r_ro = t_r / 2 + off_r_r; // [m] Rear roll center distance from the rear outer wheel
        p_r_fi = (psi_deg * psi_deg * vehicle_inputs.p_r_f_2 + psi_deg * vehicle_inputs.p_r_f_1 + vehicle_inputs.p_r_f_0) / 1000.0; // [m] Front inner roll instantaneous center height                               INPUT
        p_r_fo = (-psi_deg * psi_deg * vehicle_inputs.p_r_f_2 - psi_deg * vehicle_inputs.p_r_f_1 + vehicle_inputs.p_r_f_0) / 1000.0; // [m] Front outer roll instantaneous center height                              INPUT
        p_r_ri = (psi_deg * psi_deg * vehicle_inputs.p_r_r_2 + psi_deg * vehicle_inputs.p_r_r_1 + vehicle_inputs.p_r_r_0) / 1000.0; // [m] Rear inner roll instantaneous center height                                INPUT
        p_r_ro = (-psi_deg * psi_deg * vehicle_inputs.p_r_r_2 - psi_deg * vehicle_inputs.p_r_r_1 + vehicle_inputs.p_r_r_0) / 1000.0; // [m] Rear outer roll instantaneous center height                               INPUT
        q_r_fi = p_r_fi / h_r_f * n_r_fi; // [m] Front inner roll instantaneous center distance from the wheel medium plane
        q_r_fo = p_r_fo / h_r_f * n_r_fo; // [m] Front outer roll instantaneous center distance from the wheel medium plane
        q_r_ri = p_r_ri / h_r_r * n_r_ri; // [m] Rear inner roll instantaneous center distance from the wheel medium plane
        q_r_ro = p_r_ro / h_r_r * n_r_ro; // [m] Rear outer roll instantaneous center distance from the wheel medium plane

        //Pitch suspension parameters
        h_p_i = (phi_deg * phi_deg * vehicle_inputs.h_p_i_2 + phi_deg * vehicle_inputs.h_p_i_1 + vehicle_inputs.h_p_i_0) / 1000.0; // [m] Height of the inner pitch center                                           INPUT
        h_p_o = (phi_deg * phi_deg * vehicle_inputs.h_p_o_2 + phi_deg * vehicle_inputs.h_p_o_1 + vehicle_inputs.h_p_o_0) / 1000.0; // [m] Height of the outer pitch center                                          INPUT
        n_p_fi = (phi_deg * phi_deg * vehicle_inputs.n_p_i_2 + phi_deg * vehicle_inputs.n_p_i_1 + vehicle_inputs.n_p_i_0) / 1000.0; // [m] Inner pitch center distance from the front axle                          INPUT
        n_p_fo = (phi_deg * phi_deg * vehicle_inputs.n_p_i_2 + phi_deg * vehicle_inputs.n_p_i_1 + vehicle_inputs.n_p_i_0) / 1000.0; // [m] Outer pitch center distance from the front axle                         INPUT
        n_p_ri = (phi_deg * phi_deg * vehicle_inputs.n_p_o_2 + phi_deg * vehicle_inputs.n_p_o_1 + vehicle_inputs.n_p_o_0) / 1000.0; // [m] Inner pitch center distance from the rear axle                           INPUT
        n_p_ro = (phi_deg * phi_deg * vehicle_inputs.n_p_o_2 + phi_deg * vehicle_inputs.n_p_o_1 + vehicle_inputs.n_p_o_0) / 1000.0; // [m] Outer pitch center distance from the rear axle                          INPUT
        p_p_fi = (phi_deg * phi_deg * vehicle_inputs.p_p_f_2 + phi_deg * vehicle_inputs.p_p_f_1 + vehicle_inputs.p_p_f_0) / 1000.0; // [m] Front inner pitch instantaneous center height                             INPUT
        p_p_fo = (phi_deg * phi_deg * vehicle_inputs.p_p_f_2 + phi_deg * vehicle_inputs.p_p_f_1 + vehicle_inputs.p_p_f_0) / 1000.0; // [m] Front outer pitch instantaneous center height                            INPUT
        p_p_ri = (phi_deg * phi_deg * vehicle_inputs.p_p_r_2 + phi_deg * vehicle_inputs.p_p_r_1 + vehicle_inputs.p_p_r_0) / 1000.0; // [m] Rear inner pitch instantaneous center height                              INPUT
        p_p_ro = (phi_deg * phi_deg * vehicle_inputs.p_p_r_2 + phi_deg * vehicle_inputs.p_p_r_1 + vehicle_inputs.p_p_r_0) / 1000.0; // [m] Rear outer pitch instantaneous center height                             INPUT
        q_p_fi = p_p_fi / h_p_i * n_p_fi; // [m] Front inner pitch instantaneous center distance from the front axle
        q_p_fo = p_p_fo / h_p_o * n_p_fo; // [m] Front outer pitch instantaneous center distance from the front axle
        q_p_ri = p_p_ri / h_p_i * n_p_ri; // [m] Rear inner pitch instantaneous center distance from the rear axle
        q_p_ro = p_p_ro / h_p_o * n_p_ro; // [m] Rear outer pitch instantaneous center distance from the rear axle

        //Suspension stiffnesses

            //Motion ratios
        MR_s_fi = w_fi * w_fi * 1e6 * vehicle_inputs.MR_s_f_2 + w_fi * 1e3 * vehicle_inputs.MR_s_f_1 + vehicle_inputs.MR_s_f_0; // [-] Front inner spring motion ratio              FUNCTION INPUT
        MR_s_fo = w_fo * w_fo * 1e6 * vehicle_inputs.MR_s_f_2 + w_fo * 1e3 * vehicle_inputs.MR_s_f_1 + vehicle_inputs.MR_s_f_0; // [-] Front outer spring motion ratio             FUNCTION INPUT
        MR_s_ri = w_ri * w_ri * 1e6 * vehicle_inputs.MR_s_r_2 + w_ri * 1e3 * vehicle_inputs.MR_s_r_1 + vehicle_inputs.MR_s_r_0; // [-] Rear inner spring motion ratio               FUNCTION INPUT
        MR_s_ro = w_ro * w_ro * 1e6 * vehicle_inputs.MR_s_r_2 + w_ro * 1e3 * vehicle_inputs.MR_s_r_1 + vehicle_inputs.MR_s_r_0; // [-] Rear outer spring motion ratio              FUNCTION INPUT
        MR_arb_fi = w_fi * w_fi * 1e6 * vehicle_inputs.MR_arb_f_2 + w_fi * 1e3 * vehicle_inputs.MR_arb_f_1 + vehicle_inputs.MR_arb_f_0; // [-] Front inner anti-roll bar motion ratio     FUNCTION INPUT
        MR_arb_fo = w_fo * w_fo * 1e6 * vehicle_inputs.MR_arb_f_2 + w_fo * 1e3 * vehicle_inputs.MR_arb_f_1 + vehicle_inputs.MR_arb_f_0; // [-] Front outer anti-roll bar motion ratio    FUNCTION INPUT
        MR_arb_ri = w_ri * w_ri * 1e6 * vehicle_inputs.MR_arb_r_2 + w_ri * 1e3 * vehicle_inputs.MR_arb_r_1 + vehicle_inputs.MR_arb_r_0; // [-] Rear inner anti-roll bar motion ratio      FUNCTION INPUT
        MR_arb_ro = w_ro * w_ro * 1e6 * vehicle_inputs.MR_arb_r_2 + w_ro * 1e3 * vehicle_inputs.MR_arb_r_1 + vehicle_inputs.MR_arb_r_0; // [-] Rear outer anti-roll bar motion ratio     FUNCTION INPUT

        //Wheel rates
        K_susp_fi = k_susp_f / (MR_s_fi * MR_s_fi); // [N/m] Front inner wheel rate
        K_susp_fo = k_susp_f / (MR_s_fo * MR_s_fo); // [N/m] Front outer wheel rate
        K_susp_ri = k_susp_r / (MR_s_ri * MR_s_ri); // [N/m] Rear inner wheel rate
        K_susp_ro = k_susp_r / (MR_s_ro * MR_s_ro); // [N/m] Rear outer wheel rate
        K_arb_fi = k_arb_f / (MR_arb_fi * MR_arb_fi); // [N/m] Front inner wheel rate
        K_arb_fo = k_arb_f / (MR_arb_fo * MR_arb_fo); // [N/m] Front outer wheel rate
        K_arb_ri = k_arb_r / (MR_arb_ri * MR_arb_ri); // [N/m] Rear inner wheel rate
        K_arb_ro = k_arb_r / (MR_arb_ro * MR_arb_ro); // [N/m] Rear outer wheel rate

        //Roll stiffnesses
        K_r_C_f = k_r_C_f * t_f * t_f; // [N/m] Front roll stiffness due to the chassis
        K_r_C_r = k_r_C_r * t_r * t_r; // [N/m] Rear roll stiffness due to the chassis
        K_r_tot_f = 1 / (1 / K_r_C_f + 1 / fi.K_T + 1 / fo.K_T + 1 / (K_susp_fi + K_arb_fi) + 1 / (K_susp_fo + K_arb_fo)); // [N/m] Front total roll stiffness
        K_r_tot_r = 1 / (1 / K_r_C_r + 1 / ri.K_T + 1 / ro.K_T + 1 / (K_susp_ri + K_arb_ri) + 1 / (K_susp_ro + K_arb_ro)); // [N/m] Rear total roll stiffness

        //Pitch stiffnesses
        K_p_C_i = k_p_C_i * L * L; // [N/m] Inner pitch stiffness due to the chassis
        K_p_C_o = k_p_C_o * L * L; // [N/m] Outer pitch stiffness due to the chassis
        K_p_tot_i = 1 / (1 / K_p_C_i + 1 / fi.K_T + 1 / ri.K_T + 1 / K_susp_fi + 1 / K_susp_ri); // [N/m] Inner total pitch stiffness
        K_p_tot_o = 1 / (1 / K_p_C_o + 1 / fo.K_T + 1 / ro.K_T + 1 / K_susp_fo + 1 / K_susp_ro); // [N/m] Outer total pitch stiffness
    }

    void Vehicle::aerodynamics() {
        //Aerodynamics

               //Vehicle speed
        V_skid = sqrt(a_rad * g * R); // [m/s] Vehicle skid speed
        V = std::min(V_input / 3.6, V_skid); // [m/s] Vehicle speed
        V_kmh = V * 3.6; // [km/h] Vehicle speed

        if (vehicle_inputs.force_velocity) {
            V = V_input / 3.6; // [m/s] Vehicle speed
            R = V_input * V_input / (a_rad * g); // [m] Cornering radius (from CG)
            R_a = R * cos(beta); // [m] Actual cornering radius
            S_f = a + R * sin(beta); // [m]
            S_r = L - S_f; // [m]
            fi.R = sqrt((R_a - t_f / 2) * (R_a - t_f / 2) + S_f * S_f); // [m] Front inner wheel cornering radius
            fo.R = sqrt((R_a + t_f / 2) * (R_a + t_f / 2) + S_f * S_f); // [m] Front outer wheel cornering radius
            ri.R = sqrt((R_a - t_r / 2) * (R_a - t_r / 2) + S_r * S_r); // [m] Rear inner wheel cornering radius
            ro.R = sqrt((R_a + t_r / 2) * (R_a + t_r / 2) + S_r * S_r); // [m] Rear outer wheel cornering radius
            fi.theta = atan(S_f / (R_a - t_f / 2)); // [rad] Front inner wheel effective steering angle
            fo.theta = atan(S_f / (R_a + t_f / 2)); // [rad] Front outer wheel effective steering angle
            ri.theta = atan(S_r / (R_a - t_r / 2)); // [rad] Rear inner wheel effective steering angle
            ro.theta = atan(S_r / (R_a + t_r / 2)); // [rad] Rear outer wheel effective steering angle
            fi.set_alpha(a_rad), fo.set_alpha(a_rad), ri.set_alpha(a_rad), ro.set_alpha(a_rad);
			fi.set_F_y_comb(a_rad), fo.set_F_y_comb(a_rad), ri.set_F_y_comb(a_rad), ro.set_F_y_comb(a_rad);
        }

        //Downforce
        F_down = (V_kmh * V_kmh * vehicle_inputs.F_down_2 + V_kmh * vehicle_inputs.F_down_1); // [N] Total downforce                         FUNCTION INPUT
        F_down_x = (V_kmh * V_kmh * vehicle_inputs.F_down_x_2 + V_kmh * vehicle_inputs.F_down_x_1 + vehicle_inputs.F_down_x_0); // [%front] Downforce distribution to the front axle FUNCTION INPUT
        F_down_y = V_kmh * V_kmh * vehicle_inputs.F_down_y_2 + V_kmh * vehicle_inputs.F_down_y_1 + vehicle_inputs.F_down_y_0; // [%inner] Downforce distribution to the inner side                      FUNCTION INPUT
        F_down_fi = F_down * F_down_x / 100.0 * F_down_y / 100.0; // [N] Front inner downforce
        F_down_fo = F_down * F_down_x / 100.0 * (1 - F_down_y / 100.0); // [N] Front outter downforce
        F_down_ri = F_down * (1 - F_down_x / 100.0) * F_down_y / 100.0; // [N] Rear inner downforce
        F_down_ro = F_down * (1 - F_down_x / 100.0) * (1 - F_down_y / 100.0); // [N] Rear outter downforce

        //Drag
        F_drag = (V_kmh * V_kmh * vehicle_inputs.F_drag_2 + V_kmh * vehicle_inputs.F_drag_1); // [N] Total drag force                    FUNCTION INPUT
        F_drag_z = (V_kmh * V_kmh * vehicle_inputs.F_drag_z_2 + V_kmh * vehicle_inputs.F_drag_z_1 + vehicle_inputs.F_drag_z_0) / 1000.0; // [m] Height of the drag force application point                   INPUT
        F_drag_y = V_kmh * V_kmh * vehicle_inputs.F_drag_y_2 + V_kmh * vehicle_inputs.F_drag_y_1 + vehicle_inputs.F_drag_y_0; // [%inner] Inner position of the drag force application point         INPUT
        h_drag = F_drag_z; // [m] Distance from the drag force application point to the pitch axis
    }

    void Vehicle::longitudinal_load_transfer() {
        //Longitudinal load transfer

        //Sprung masses longitudinal load transfer
        dW_lon_s_fi = m_s / m * (fi.F_lon * h_p_i - fi.T_r) / n_p_fi; // [N] Front inner sprung mass longitudinal load transfer
        dW_lon_s_fo = m_s / m * (fo.F_lon * h_p_o - fo.T_r) / n_p_fo; // [N] Front outer sprung mass longitudinal load transfer
        dW_lon_s_ri = m_s / m * (ri.F_lon * h_p_i - ri.T_r) / n_p_ri; // [N] Rear inner sprung mass longitudinal load transfer
        dW_lon_s_ro = m_s / m * (ro.F_lon * h_p_o - ro.T_r) / n_p_ro; // [N] Rear outer sprung mass longitudinal load transfer

        //Unsprung masses longitudinal load transfer
        dW_lon_u_fi = m_u / m * (fi.F_lon * h_CG_u - fi.T_r) / q_p_fi; // [N] Front inner unsprung mass longitudinal load transfer
        dW_lon_u_fo = m_u / m * (fo.F_lon * h_CG_u - fo.T_r) / q_p_fo; // [N] Front outer unsprung mass longitudinal load transfer
        dW_lon_u_ri = m_u / m * (ri.F_lon * h_CG_u - ri.T_r) / q_p_ri; // [N] Rear inner unsprung mass longitudinal load transfer
        dW_lon_u_ro = m_u / m * (ro.F_lon * h_CG_u - ro.T_r) / q_p_ro; // [N] Rear outer unsprung mass longitudinal load transfer

        //Geometric longitudinal load transfer
        dW_lon_g_fi = dW_lon_s_fi + dW_lon_u_fi; // [N] Front inner geometric longitudinal load transfer
        dW_lon_g_fo = dW_lon_s_fo + dW_lon_u_fo; // [N] Front outer geometric longitudinal load transfer
        dW_lon_g_ri = dW_lon_s_ri + dW_lon_u_ri; // [N] Rear inner geometric longitudinal load transfer
        dW_lon_g_ro = dW_lon_s_ro + dW_lon_u_ro; // [N] Rear outer geometric longitudinal load transfer

        //Pitch moments
        M_p_s_fi = m_s / m * fi.F_lon * (h_CG_s - h_p_i); // [N*m] Front inner sprung mass pitch moment
        M_p_s_fo = m_s / m * fo.F_lon * (h_CG_s - h_p_o); // [N*m] Front outer sprung mass pitch moment
        M_p_s_ri = m_s / m * ri.F_lon * (h_CG_s - h_p_i); // [N*m] Rear inner sprung mass pitch moment
        M_p_s_ro = m_s / m * ro.F_lon * (h_CG_s - h_p_o); // [N*m] Rear outer sprung mass pitch moment
        M_p_u_fi = dW_lon_u_fi * (q_p_fi - n_p_fi); // [N*m] Front inner unsprung mass pitch moment
        M_p_u_fo = dW_lon_u_fo * (q_p_fo - n_p_fo); // [N*m] Front outer unsprung mass pitch moment
        M_p_u_ri = dW_lon_u_ri * (q_p_ri - n_p_ri); // [N*m] Rear inner unsprung mass pitch moment
        M_p_u_ro = dW_lon_u_ro * (q_p_ro - n_p_ro); // [N*m] Rear outer unsprung mass pitch moment
        M_p_s = M_p_s_fi + M_p_s_fo + M_p_s_ri + M_p_s_ro; // [N*m] Total sprung mass pitch moment
        M_p_u = M_p_u_fi + M_p_u_fo + M_p_u_ri + M_p_u_ro; // [N*m] Total unsprung mass pitch moment
        T = fi.T_r + fo.T_r + ri.T_r + ro.T_r; // [N*m] Total reaction torque

        //Drag longitudinal load transfer
        M_p_drag = F_drag * h_drag; // [N*m] Pitch moment due to drag
        dW_lon_drag = F_drag * F_drag_z / L; // [N] Longitudinal load transfer due to drag

        //Pitch angle
        phi = (T + M_p_drag + M_p_s + M_p_u + dW_lon_g_fi * n_p_fi + dW_lon_g_fo * n_p_fo + dW_lon_g_ri * n_p_ri + dW_lon_g_ro * n_p_ro
            - L * (K_p_tot_i * (dW_lon_g_fi / K_susp_fi + dW_lon_g_ri / K_susp_ri) + K_p_tot_o * (dW_lon_g_fo / K_susp_fo + dW_lon_g_ro / K_susp_ro))) / (K_p_tot_i + K_p_tot_o) / L / L; // [rad] Pitch angle
        phi_deg = phi * 180.0 / pi; // [deg] Pitch angle

        //Total longitudinal load transfer
        dW_lon_i = phi * L * K_p_tot_i + (dW_lon_g_fi / K_susp_fi + dW_lon_g_ri / K_susp_ri) * K_p_tot_i; // [N] Inner longitudinal load transfer
        dW_lon_o = phi * L * K_p_tot_o + (dW_lon_g_fo / K_susp_fo + dW_lon_g_ro / K_susp_ro) * K_p_tot_o; // [N] Outer longitudinal load transfer

        //Elastic longitudinal load transfer
        dW_lon_k_fi = dW_lon_i - dW_lon_g_fi - dW_lon_drag / 2; // [N] Front inner elastic longitudinal load transfer
        dW_lon_k_fo = dW_lon_o - dW_lon_g_fo - dW_lon_drag / 2; // [N] Front outer elastic longitudinal load transfer
        dW_lon_k_ri = dW_lon_i - dW_lon_g_ri - dW_lon_drag / 2; // [N] Rear inner elastic longitudinal load transfer
        dW_lon_k_ro = dW_lon_o - dW_lon_g_ro - dW_lon_drag / 2; // [N] Rear outer elastic longitudinal load transfer
    }

    void Vehicle::lateral_load_transfer() {
        //Lateral load transfer

                //Sprung masses lateral load transfer
        dW_lat_s_fi = m_s / m * fi.F_lat * h_r_f / n_r_fi; // [N] Front inner sprung mass lateral load transfer
        dW_lat_s_fo = m_s / m * fo.F_lat * h_r_f / n_r_fo; // [N] Front outer sprung mass lateral load transfer
        dW_lat_s_ri = m_s / m * ri.F_lat * h_r_r / n_r_ri; // [N] Rear inner sprung mass lateral load transfer
        dW_lat_s_ro = m_s / m * ro.F_lat * h_r_r / n_r_ro; // [N] Rear outer sprung mass lateral load transfer

        //Unsprung masses lateral load transfer
        dW_lat_u_fi = m_u / m * fi.F_lat * h_CG_u / q_r_fi; // [N] Front inner unsprung mass lateral load transfer
        dW_lat_u_fo = m_u / m * fo.F_lat * h_CG_u / q_r_fo; // [N] Front outer unsprung mass lateral load transfer
        dW_lat_u_ri = m_u / m * ri.F_lat * h_CG_u / q_r_ri; // [N] Rear inner unsprung mass lateral load transfer
        dW_lat_u_ro = m_u / m * ro.F_lat * h_CG_u / q_r_ro; // [N] Rear outer unsprung mass lateral load transfer

        //Geometric lateral load transfer
        dW_lat_g_fi = dW_lat_s_fi + dW_lat_u_fi; // [N] Front inner geometric lateral load transfer
        dW_lat_g_fo = dW_lat_s_fo + dW_lat_u_fo; // [N] Front outer geometric lateral load transfer
        dW_lat_g_ri = dW_lat_s_ri + dW_lat_u_ri; // [N] Rear inner geometric lateral load transfer
        dW_lat_g_ro = dW_lat_s_ro + dW_lat_u_ro; // [N] Rear outer geometric lateral load transfer

        //Roll moments
        M_r_s_fi = m_s / m * fi.F_lat * (h_CG_s - h_r_f); // [N*m] Front inner sprung mass roll moment
        M_r_s_fo = m_s / m * fo.F_lat * (h_CG_s - h_r_f); // [N*m] Front outer sprung mass roll moment
        M_r_s_ri = m_s / m * ri.F_lat * (h_CG_s - h_r_r); // [N*m] Rear inner sprung mass roll moment
        M_r_s_ro = m_s / m * ro.F_lat * (h_CG_s - h_r_r); // [N*m] Rear outer sprung mass roll moment
        M_r_u_fi = dW_lat_u_fi * (q_r_fi - n_r_fi); // [N*m] Front inner unsprung mass roll moment
        M_r_u_fo = dW_lat_u_fo * (q_r_fo - n_r_fo); // [N*m] Front outer unsprung mass roll moment
        M_r_u_ri = dW_lat_u_ri * (q_r_ri - n_r_ri); // [N*m] Rear inner unsprung mass roll moment
        M_r_u_ro = dW_lat_u_ro * (q_r_ro - n_r_ro); // [N*m] Rear outer unsprung mass roll moment
        M_r_s = M_r_s_fi + M_r_s_fo + M_r_s_ri + M_r_s_ro; // [N*m] Total sprung mass roll moment
        M_r_u = M_r_u_fi + M_r_u_fo + M_r_u_ri + M_r_u_ro; // [N*m] Total unsprung mass roll moment

        //Roll angle
        psi = abs(M_r_s + M_r_u + dW_lat_g_fi * n_r_fi + dW_lat_g_fo * n_r_fo + dW_lat_g_ri * n_r_ri + dW_lat_g_ro * n_r_ro
            - t_f * K_r_tot_f * (dW_lat_g_fi / (K_susp_fi + K_arb_fi) + dW_lat_g_fo / (K_susp_fo + K_arb_fo)) - t_r * K_r_tot_r * (dW_lat_g_ri / (K_susp_ri + K_arb_ri) + dW_lat_g_ro / (K_susp_ro + K_arb_ro)))
            / (K_r_tot_f * t_f * t_f + K_r_tot_r * t_r * t_r); // [rad] Roll angle
        psi_deg = psi * 180.0 / pi; // [deg] Roll angle

        //Total lateral load transfer
        dW_lat_f = round_to(psi * K_r_tot_f * t_f + abs(dW_lat_g_fi / (K_susp_fi + K_arb_fi) + dW_lat_g_fo / (K_susp_fo + K_arb_fo)) * K_r_tot_f, 2); // [N] Front lateral load transfer
        dW_lat_r = round_to(psi * K_r_tot_r * t_r + abs(dW_lat_g_ri / (K_susp_ri + K_arb_ri) + dW_lat_g_ro / (K_susp_ro + K_arb_ro)) * K_r_tot_r, 2); // [N] Rear lateral load transfer

        //Elastic lateral load transfer
        dW_lat_k_fi = abs(dW_lat_f - dW_lat_g_fi); // [N] Front inner elastic lateral load transfer
        dW_lat_k_fo = abs(dW_lat_f - dW_lat_g_fo); // [N] Front outer elastic lateral load transfer
        dW_lat_k_ri = abs(dW_lat_r - dW_lat_g_ri); // [N] Rear inner elastic lateral load transfer
        dW_lat_k_ro = abs(dW_lat_r - dW_lat_g_ro); // [N] Rear outer elastic lateral load transfer
    }

    void Vehicle::update_wheel_loads_and_displacements() {
        //Wheel loads

        fi.set_F_z_past(), fo.set_F_z_past(), ri.set_F_z_past(), ro.set_F_z_past();

        fi.F_z = round_to(W_fi - dW_lon_i - abs(dW_lat_f) + F_down_fi - dW_lon_drag / 2, 3); // [N] Front inner tire vertical load
        fo.F_z = round_to(W_fo - dW_lon_o + abs(dW_lat_f) + F_down_fo - dW_lon_drag / 2, 3); // [N] Front outer tire vertical load
        ri.F_z = round_to(W_ri + dW_lon_i - abs(dW_lat_r) + F_down_ri + dW_lon_drag / 2, 3); // [N] Rear inner tire vertical load
        ro.F_z = round_to(W_ro + dW_lon_o + abs(dW_lat_r) + F_down_ro + dW_lon_drag / 2, 3); // [N] Rear outer tire vertical load

        fi.set_F_z_err(), fo.set_F_z_err(), ri.set_F_z_err(), ro.set_F_z_err();

        //Wheel displacements

        w_fi = round_to(-(dW_lat_k_fi) / (K_susp_fi + K_arb_fi) + (F_down_fi - dW_lon_k_fi) / K_susp_fi, 5); // [m] Front inner tire vertical displacement
        w_fo = round_to((dW_lat_k_fo) / (K_susp_fo + K_arb_fo) + (F_down_fo - dW_lon_k_fo) / K_susp_fo, 5); // [m] Front outer tire vertical displacement
        w_ri = round_to(-(dW_lat_k_ri) / (K_susp_ri + K_arb_ri) + (F_down_ri + dW_lon_k_ri) / K_susp_ri, 5); // [m] Rear inner tire vertical displacement
        w_ro = round_to((dW_lat_k_ro) / (K_susp_ro + K_arb_ro) + (F_down_ro + dW_lon_k_ro) / K_susp_ro, 5); // [m] Rear outer tire vertical displacement

        //fi.delta = round_to(((delta_d_deg * delta_d_deg * vehicle_inputs.ackermann_2 + delta_d_deg * vehicle_inputs.ackermann_1 + delta_f_static) + (w_fi * w_fi * 1e6 * vehicle_inputs.bs_f_2 + w_fi * 1e3 * vehicle_inputs.bs_f_1) * 0) * pi / 180.0, 5); // [rad] Front outer wheel steering angle
        //fo.delta = round_to((-(delta_d_deg * delta_d_deg * vehicle_inputs.ackermann_2 + delta_d_deg * vehicle_inputs.ackermann_1 + delta_f_static) + (w_fo * w_fo * 1e6 * vehicle_inputs.bs_f_2 + w_fo * 1e3 * vehicle_inputs.bs_f_1) * 0) * pi / 180.0, 5); // [rad] Front inner wheel steering angle                      FUNCTION INPUT
        //ri.delta = round_to((delta_r_static + (w_ri * w_ri * vehicle_inputs.bs_r_2 + w_ri * vehicle_inputs.bs_r_1) * 0) * pi / 180.0, 5); // [rad] Rear inner wheel steering angle
        //ro.delta = round_to((-delta_r_static + (w_ro * w_ro * vehicle_inputs.bs_r_2 + w_ro * vehicle_inputs.bs_r_1) * 0) * pi / 180.0, 5);// [rad] Rear outer wheel steering angle

        fi.gamma = round_to(-psi + gamma_f_static + ((w_fi * w_fi * 1e6 * vehicle_inputs.bc_f_2 + w_fi * 1e3 * vehicle_inputs.bc_f_1) + (fi.delta * fi.delta * 180 * 180 / pi / pi * vehicle_inputs.sc_f_2 + fi.delta * 180 / pi * vehicle_inputs.sc_f_1)) * pi / 180.0, 5); // [rad] Front inner tire camber angle
        fo.gamma = round_to(psi + gamma_f_static + ((w_fo * w_fo * 1e6 * vehicle_inputs.bc_f_2 + w_fo * 1e3 * vehicle_inputs.bc_f_1) - (fo.delta * fo.delta * 180 * 180 / pi / pi * vehicle_inputs.sc_f_2 + fo.delta * 180 / pi * vehicle_inputs.sc_f_1)) * pi / 180.0, 5); // [rad] Front outer tire camber angle
        ri.gamma = round_to(-psi + gamma_r_static + (w_ri * w_ri * 1e6 * vehicle_inputs.bc_r_2 + w_ri * 1e3 * vehicle_inputs.bc_r_1) * pi / 180.0, 5); // [rad] Rear inner tire camber angle
        ro.gamma = round_to(psi + gamma_r_static + (w_ro * w_ro * 1e6 * vehicle_inputs.bc_r_2 + w_ro * 1e3 * vehicle_inputs.bc_r_1) * pi / 180.0, 5); // [rad] Rear outer tire camber angle

    }

    void Vehicle::yaw_moment() {
        //Yaw moment
        M_yaw_fl = fi.F_lat * a - fi.F_lon * t_f / 2 * (a_rad < 0 ? -1 : 1); // [N*m] Front inner tire yaw moment
        M_yaw_fr = fo.F_lat * a + fo.F_lon * t_f / 2 * (a_rad < 0 ? -1 : 1); // [N*m] Front outer tire yaw moment
        M_yaw_rl = -ri.F_lat * b - ri.F_lon * t_r / 2 * (a_rad < 0 ? -1 : 1); // [N*m] Rear inner tire yaw moment
        M_yaw_rr = -ro.F_lat * b + ro.F_lon * t_r / 2 * (a_rad < 0 ? -1 : 1); // [N*m] Rear outer tire yaw moment
        M_yaw = M_yaw_fl + M_yaw_fr + M_yaw_rl + M_yaw_rr; // [N*m] Vehicle yaw moment
    }

    // Solver function for slip ratios to comply with axle torque and bias constraints
    void Vehicle::solve_kappa() {

        //Equivalent slip ratios
        fi.set_kappa_x(), fo.set_kappa_x(), ri.set_kappa_x(), ro.set_kappa_x();

        //Longitudinal Pacejka
        fi.set_F_x(), fo.set_F_x(), ri.set_F_x(), ro.set_F_x();

        //Longitudinal modified Nicolas-Comstock
        fi.set_F_x_comb(lon_sign), fo.set_F_x_comb(lon_sign), ri.set_F_x_comb(lon_sign), ro.set_F_x_comb(lon_sign);

        //Torques
        fi.set_T(), fo.set_T(), ri.set_T(), ro.set_T();

        if (bias > 0.5 && iter != 0) {
            if (W_fi < W_fo) {
                if (force_a_lon) {
                    fi.F_x_comb_tar = (m * a_lon_des + F_drag + fi.F_y_comb * sin(fi.delta) + fo.F_y_comb * sin(fo.delta) - ri.F_y_comb * sin(ri.delta) - ro.F_y_comb * sin(ro.delta) + fi.F_rr * cos(fi.delta) + fo.F_rr * cos(fo.delta) + ri.F_rr * cos(ri.delta) + ro.F_rr * cos(ro.delta)) / (cos(fi.delta) + cos(fo.delta) * fi.r / fo.r + cos(ri.delta) * fi.r / ri.r * (1 - bias) / bias + cos(ro.delta) * fi.r / ro.r * (1 - bias) / bias);
                    brents_method(fi, 0.0, 1.0);
                    kappa_des = fi.kappa;
                }

                fi.kappa = kappa_des;
                fo.F_x_comb_tar = fi.T / fo.r;
                peak_kappa(fo);
                if (fo.peak_kappa > kappa_des) { brents_method(fo, -0.1, 1); }
                else {
                    brents_method(fo, fo.peak_kappa, 1);
                    if (fo.kappa > kappa_des + 0.001) { brents_method(fo, -0.1, fo.peak_kappa); }
                }
            }
            else if (W_fi >= W_fo) {
                if (force_a_lon) {
                    fo.F_x_comb_tar = (m * a_lon_des + F_drag + fi.F_y_comb * sin(fi.delta) + fo.F_y_comb * sin(fo.delta) - ri.F_y_comb * sin(ri.delta) - ro.F_y_comb * sin(ro.delta) + fi.F_rr * cos(fi.delta) + fo.F_rr * cos(fo.delta) + ri.F_rr * cos(ri.delta) + ro.F_rr * cos(ro.delta)) / (cos(fo.delta) + cos(fi.delta) * fo.r / fi.r + cos(ri.delta) * fo.r / ri.r * (1 - bias) / bias + cos(ro.delta) * fo.r / ro.r * (1 - bias) / bias);
                    brents_method(fo, 0.0, 1.0);
                    kappa_des = fo.kappa;
                }

                fo.kappa = kappa_des;
                fi.F_x_comb_tar = fo.T / fi.r;
                peak_kappa(fi);
                if (fi.peak_kappa > kappa_des) { brents_method(fi, -0.1, 1); }
                else {
                    brents_method(fi, fi.peak_kappa, 1);
                    if (fi.kappa > kappa_des + 0.001) { brents_method(fi, -0.1, fi.peak_kappa); }
                }
            }
            ri.F_x_comb_tar = (1 - bias) / bias * (fi.T + fo.T) / (2 * ri.r);
            ro.F_x_comb_tar = (1 - bias) / bias * (fi.T + fo.T) / (2 * ro.r);
            peak_kappa(ri);
            if (ri.peak_kappa > kappa_des) { brents_method(ri, -0.1, 1); }
            else { brents_method(ri, ri.peak_kappa, 1); }
            peak_kappa(ro);
            if (ro.peak_kappa > kappa_des) { brents_method(ro, -0.1, 1); }
            else { brents_method(ro, ro.peak_kappa, 1); }
        }
        else if (bias <= 0.5 && iter != 0) {
            if (W_ri < W_ro) {
                if (force_a_lon) {
                    ri.F_x_comb_tar = (m * a_lon_des + F_drag + fi.F_y_comb * sin(fi.delta) + fo.F_y_comb * sin(fo.delta) - ri.F_y_comb * sin(ri.delta) - ro.F_y_comb * sin(ro.delta) + fi.F_rr * cos(fi.delta) + fo.F_rr * cos(fo.delta) + ri.F_rr * cos(ri.delta) + ro.F_rr * cos(ro.delta)) / (cos(ri.delta) + cos(ro.delta) * ri.r / ro.r + cos(fi.delta) * ri.r / fi.r * bias / (1 - bias) + cos(fo.delta) * ri.r / fo.r * bias / (1 - bias));
                    brents_method(ri, 0.0, 1.0);
                    kappa_des = ri.kappa;
                }

                ri.kappa = kappa_des;
                ro.F_x_comb_tar = ri.T / ro.r;
                peak_kappa(ro);
                if (ro.peak_kappa > kappa_des) { brents_method(ro, -0.1, 1); }
                else {
                    brents_method(ro, ro.peak_kappa, 1);
                    if (ro.kappa > kappa_des + 0.001) { brents_method(ro, -0.1, ro.peak_kappa); }
                }
            }
            else if (W_ri >= W_ro) {
                if (force_a_lon) {
                    ro.F_x_comb_tar = (m * a_lon_des + F_drag + fi.F_y_comb * sin(fi.delta) + fo.F_y_comb * sin(fo.delta) - ri.F_y_comb * sin(ri.delta) - ro.F_y_comb * sin(ro.delta) + fi.F_rr * cos(fi.delta) + fo.F_rr * cos(fo.delta) + ri.F_rr * cos(ri.delta) + ro.F_rr * cos(ro.delta)) / (cos(ro.delta) + cos(ri.delta) * ro.r / ri.r + cos(fi.delta) * ro.r / fi.r * bias / (1 - bias) + cos(fo.delta) * ro.r / fo.r * bias / (1 - bias));
                    brents_method(ro, 0.0, 1.0);
                    kappa_des = ro.kappa;
                }
                ro.kappa = kappa_des;
                ri.F_x_comb_tar = ro.T / ri.r;
                peak_kappa(ri);
                if (ri.peak_kappa > kappa_des) { brents_method(ri, -0.1, 1); }
                else {
                    brents_method(ri, ri.peak_kappa, 1);
                    if (ri.kappa > kappa_des + 0.001) { brents_method(ri, -0.1, ri.peak_kappa); }
                }
            }
            fi.F_x_comb_tar = bias / (1 - bias) * (ri.T + ro.T) / (2 * fi.r);
            fo.F_x_comb_tar = bias / (1 - bias) * (ri.T + ro.T) / (2 * fo.r);
            peak_kappa(fi);
            if (fi.peak_kappa > kappa_des) { brents_method(fi, -0.1, 1); }
            else { brents_method(fi, fi.peak_kappa, 1); }
            peak_kappa(fo);
            if (fo.peak_kappa > kappa_des) { brents_method(fo, -0.1, 1); }
            else { brents_method(fo, fo.peak_kappa, 1); }
        }
    }

    // Brent's method for finding root of f(x) = target
    void Vehicle::brents_method(Tire& tire, double a, double b) {
        double tol = 1e-4; int max_iter = 40;

        auto f = [&](double x) {
            tire.kappa = x;
            tire.set_kappa_x();
            tire.set_F_x();
            tire.set_F_x_comb(lon_sign);
            return tire.F_x_comb;
            };

        // Adjust function to find root of f(x) - target = 0
        auto g = [&](double x) {return f(x) - tire.F_x_comb_tar; };

        double search_radius = 0.001;
        double max_search_radius = b;
        double step = search_radius;
        int expand_iter = 0;
        double b_best = -1e10;
        double b_temp = 0;
        double fa, fb, fb_best, s, fs;

        // Expand search interval until we bracket the root
        while (g(a) * g(b) >= 0 && expand_iter < max_search_radius / search_radius) {
            b_temp += step;
            fb = g(b_temp);
            fb_best = g(b_best);
            b_best = abs(fb) < abs(fb_best) ? b_temp : b_best;
            b = b_best;
            //cout << "b adjusted to: " << b << ", g(a): " << ra << ", g(b): " << rb <<endl;
            expand_iter++;
        }

        if (g(a) * g(b) >= 0) {
            tire.F_x_comb = f(b_best);
            tire.set_T();
            return;
        }

        fa = g(a);
        fb = g(b);

        // Check if root is bracketed
        if (fa * fb >= 0) {
            std::cerr << "Error: Root not bracketed in [" << a << ", " << b << "]" << std::endl;
            std::cerr << "f(a) - target = " << fa << ", f(b) - target = " << fb << std::endl;
            throw std::invalid_argument("Root not bracketed in the given interval");
        }

        if (abs(fa) < abs(fb)) {
            std::swap(a, b);
            std::swap(fa, fb);
        }

        double c = a;
        double fc = fa;
        bool mflag = true;
        double d = 0.0;

        for (int iter = 0; iter < max_iter; ++iter) {
            brents_iter_single += 1;
            if (abs(fb) < tol) {
                //std::cout << "Brent's method converged after " << iter << " iterations" << std::endl;
                tire.F_x_comb = f(b);
                tire.set_T();
                return;
            }

            if (abs(fa - fc) > tol && abs(fb - fc) > tol) {
                // Inverse quadratic interpolation
                s = a * fb * fc / ((fa - fb) * (fa - fc)) +
                    b * fa * fc / ((fb - fa) * (fb - fc)) +
                    c * fa * fb / ((fc - fa) * (fc - fb));

                if ((s - b) * (s - (3 * a + b) / 4) > 0 ||
                    (mflag && abs(s - b) >= abs(b - c) / 2) ||
                    (!mflag && abs(s - b) >= abs(c - d) / 2))
                {
                    // Conditions for interpolation not satisfied, use bisection
                    s = (a + b) / 2;
                    mflag = true;
                }
                else
                {
                    mflag = false;
                }
            }
            else {
                // Secant method
                s = b - fb * (b - a) / (fb - fa);
                mflag = true;
            }

            // Check if we can use the new point
            fs = g(s);
            d = c;
            c = b;
            fc = fb;

            if (fa * fs < 0) {
                b = s;
                fb = fs;
            }
            else {
                a = s;
                fa = fs;
            }

            // Update for next iteration
            if (abs(fa) < abs(fb)) {
                std::swap(a, b);
                std::swap(fa, fb);
            }
        }

        std::cout << "Brent's method reached maximum iterations" << std::endl;
        tire.F_x_comb = f(b);
        tire.set_T();
    };

    void Vehicle::peak_kappa(Tire& tire) {
        double x_l = 0.0, x_u = 1.0;
        const double goldenRatio = (sqrt(5.0) - 1.0) / 2.0;

        auto f = [&](double x) {
            tire.kappa = x;
            tire.set_kappa_x();
            tire.set_F_x();
            tire.set_F_x_comb(lon_sign);
            return tire.F_x_comb;
            };

        double tolerance = 1e-4;
        double x1 = x_l + goldenRatio * (x_u - x_l);
        double x2 = x_u - goldenRatio * (x_u - x_l);

        int iter = 0;
        double f1 = f(x1);
        double f2 = f(x2);

        while (abs(x_u - x_l) > tolerance) {
			golden_iter_single += 1;

            if (f1 > f2) {  // Peak is in [x2, x_u]
                x_l = x2;
                x2 = x1;
                f2 = f1;
                x1 = x_l + goldenRatio * (x_u - x_l);
                f1 = f(x1);
            }
            else {  // Peak is in [xl, x_1]
                x_u = x1;
                x1 = x2;
                f1 = f2;
                x2 = x_u - goldenRatio * (x_u - x_l);
                f2 = f(x2);
            }
            iter++;
            if (iter > 40) {
                break;
            }
        }

        double x_m = (x_u + x_l) / 2.0;
        //f((x_m));
        tire.peak_kappa = x_m;
        return;
    }

    inline double Vehicle::round_to(double value, int decimals) {
        double scale = std::pow(10.0, decimals);
        return round(value * scale) / scale;
    }

    void Vehicle::output(Vehicle_outputs& vehicle_outputs) {
        vehicle_outputs.M_yaw = M_yaw;
        vehicle_outputs.a_lat = a_lat;
        vehicle_outputs.a_lon = a_lon;
        vehicle_outputs.a_rad = a_rad;
        vehicle_outputs.F_lat = F_lat;
        vehicle_outputs.F_lon = F_lon;
        vehicle_outputs.psi_deg = psi_deg;
        vehicle_outputs.phi_deg = phi_deg;
        vehicle_outputs.iter = iter;
        vehicle_outputs.bias_now = bias_now * 100.0;
        vehicle_outputs.V = V * 3.6;
        vehicle_outputs.R = R;

        vehicle_outputs.F_z_fi = fi.F_z;
        vehicle_outputs.F_z_fo = fo.F_z;
        vehicle_outputs.F_z_ri = ri.F_z;
        vehicle_outputs.F_z_ro = ro.F_z;

        vehicle_outputs.F_x_comb_fi = fi.F_x_comb;
        vehicle_outputs.F_x_comb_fo = fo.F_x_comb;
        vehicle_outputs.F_x_comb_ri = ri.F_x_comb;
        vehicle_outputs.F_x_comb_ro = ro.F_x_comb;

        vehicle_outputs.F_y_comb_fi = fi.F_y_comb;
        vehicle_outputs.F_y_comb_fo = fo.F_y_comb;
        vehicle_outputs.F_y_comb_ri = ri.F_y_comb;
        vehicle_outputs.F_y_comb_ro = ro.F_y_comb;

        vehicle_outputs.F_lon_fi = fi.F_lon;
        vehicle_outputs.F_lon_fo = fo.F_lon;
        vehicle_outputs.F_lon_ri = ri.F_lon;
        vehicle_outputs.F_lon_ro = ro.F_lon;

        vehicle_outputs.F_lat_fi = fi.F_lat;
        vehicle_outputs.F_lat_fo = fo.F_lat;
        vehicle_outputs.F_lat_ri = ri.F_lat;
        vehicle_outputs.F_lat_ro = ro.F_lat;

        vehicle_outputs.kappa_fi = fi.kappa * 100.0;
        vehicle_outputs.kappa_fo = fo.kappa * 100.0;
        vehicle_outputs.kappa_ri = ri.kappa * 100.0;
        vehicle_outputs.kappa_ro = ro.kappa * 100.0;

        vehicle_outputs.alpha_fi = fi.alpha * 180 / pi;
        vehicle_outputs.alpha_fo = fo.alpha * 180 / pi;
        vehicle_outputs.alpha_ri = ri.alpha * 180 / pi;
        vehicle_outputs.alpha_ro = ro.alpha * 180 / pi;

        vehicle_outputs.T_fi = fi.T;
        vehicle_outputs.T_fo = fo.T;
        vehicle_outputs.T_ri = ri.T;
        vehicle_outputs.T_ro = ro.T;

#ifdef _DEBUG   
        vehicle_outputs.debug1 = fi.delta * 180 / pi;
        vehicle_outputs.debug2 = fo.delta * 180 / pi;
        vehicle_outputs.debug3 = ri.delta * 180 / pi;
        vehicle_outputs.debug4 = ro.delta * 180 / pi;

		vehicle_outputs.brents_single = brents_iter_single;
		vehicle_outputs.brents_total = brents_iter_total;
		vehicle_outputs.golden_single = golden_iter_single;
		vehicle_outputs.golden_total = golden_iter_total;
        vehicle_outputs.iter_total = iter_total;
#endif
    };

    void Vehicle::refresh() {
        lon_sign = 1.0;
        BB = 0.0, DB = 0.0, bias = 0.0, bias_first = 0.0, bias_now = 0.0;
        W = 0.0, W_fi = 0.0, W_fo = 0.0, W_ri = 0.0, W_ro = 0.0;
        m_u = 0.0;
        m_s = 0.0;
        a = 0.0, b = 0.0, a_s = 0.0, b_s = 0.0;
        w_fi = 0.0, w_fo = 0.0, w_ri = 0.0, w_ro = 0.0;
        R = 0.0, beta_deg = 0.0, beta = 0.0, R_a = 0.0, S_f = 0.0, S_r = 0.0;
        delta_d_deg = 0.0;
        F_lat = 0.0, a_lat = 0.0;
        F_lon = 0.0, a_lon = 0.0, a_lon_des = 0.0;
        F_rad = 0.0, a_rad = 0.0;
        h_CG_s = 0.0, h_CG_u_fi = 0.0, h_CG_u_fo = 0.0, h_CG_u_ri = 0.0, h_CG_u_ro = 0.0, h_CG_u = 0.0;
        h_r_f = 0.0, h_r_r = 0.0, off_r_f = 0.0, off_r_r = 0.0, n_r_fi = 0.0, n_r_fo = 0.0, n_r_ri = 0.0, n_r_ro = 0.0,
                    p_r_fi = 0.0, p_r_fo = 0.0, p_r_ri = 0.0, p_r_ro = 0.0, q_r_fi = 0.0, q_r_fo = 0.0, q_r_ri = 0.0, q_r_ro = 0.0;
        h_p_i = 0.0, h_p_o = 0.0, n_p_fi = 0.0, n_p_fo = 0.0, n_p_ri = 0.0, n_p_ro = 0.0,
                    p_p_fi = 0.0, p_p_fo = 0.0, p_p_ri = 0.0, p_p_ro = 0.0, q_p_fi = 0.0, q_p_fo = 0.0, q_p_ri = 0.0, q_p_ro = 0.0;
        k_r_C = 0.0, k_r_C_f = 0.0, k_r_C_r = 0.0, k_p_C = 0.0, k_p_C_i = 0.0, k_p_C_o = 0.0;
        MR_s_fi = 0.0, MR_s_fo = 0.0, MR_s_ri = 0.0, MR_s_ro = 0.0, MR_arb_fi = 0.0, MR_arb_fo = 0.0, MR_arb_ri = 0.0, MR_arb_ro = 0.0;
        K_susp_fi = 0.0, K_susp_fo = 0.0, K_susp_ri = 0.0, K_susp_ro = 0.0, K_arb_fi = 0.0, K_arb_fo = 0.0, K_arb_ri = 0.0, K_arb_ro = 0.0;
        K_r_C_f = 0.0, K_r_C_r = 0.0, K_r_tot_f = 0.0, K_r_tot_r = 0.0;
        K_p_C_i = 0.0, K_p_C_o = 0.0, K_p_tot_i = 0.0, K_p_tot_o = 0.0;
        V_skid = 0.0, V_kmh = 0.0;
        F_down = 0.0, F_down_x = 0.0, F_down_y = 0.0, F_down_fi = 0.0, F_down_fo = 0.0, F_down_ri = 0.0, F_down_ro = 0.0;
        F_drag = 0.0, F_drag_z = 0.0, F_drag_y = 0.0, h_drag = 0.0;
        dW_lon_s_fi = 0.0, dW_lon_s_fo = 0.0, dW_lon_s_ri = 0.0, dW_lon_s_ro = 0.0, dW_lon_u_fi = 0.0, dW_lon_u_fo = 0.0, dW_lon_u_ri = 0.0, dW_lon_u_ro = 0.0,
                    dW_lon_g_fi = 0.0, dW_lon_g_fo = 0.0, dW_lon_g_ri = 0.0, dW_lon_g_ro = 0.0;
        M_p_s_fi = 0.0, M_p_s_fo = 0.0, M_p_s_ri = 0.0, M_p_s_ro = 0.0, M_p_u_fi = 0.0, M_p_u_fo = 0.0, M_p_u_ri = 0.0, M_p_u_ro = 0.0, M_p_s = 0.0, M_p_u = 0.0, T = 0.0;
        phi = 0.0, phi_deg = 0.0;
        M_p_drag = 0.0, dW_lon_drag = 0.0;
        dW_lon_i = 0.0, dW_lon_o = 0.0;
        dW_lon_k_fi = 0.0, dW_lon_k_fo = 0.0, dW_lon_k_ri = 0.0, dW_lon_k_ro = 0.0;
        dW_lat_s_fi = 0.0, dW_lat_s_fo = 0.0, dW_lat_s_ri = 0.0, dW_lat_s_ro = 0.0, dW_lat_u_fi = 0.0, dW_lat_u_fo = 0.0, dW_lat_u_ri = 0.0, dW_lat_u_ro = 0.0,
                    dW_lat_g_fi = 0.0, dW_lat_g_fo = 0.0, dW_lat_g_ri = 0.0, dW_lat_g_ro = 0.0;
        M_r_s_fi = 0.0, M_r_s_fo = 0.0, M_r_s_ri = 0.0, M_r_s_ro = 0.0, M_r_u_fi = 0.0, M_r_u_fo = 0.0, M_r_u_ri = 0.0, M_r_u_ro = 0.0, M_r_s = 0.0, M_r_u = 0.0;
        psi = 0.0, psi_deg = 0.0;
        dW_lat_f = 0.0, dW_lat_r = 0.0;
        dW_lat_k_fi = 0.0, dW_lat_k_fo = 0.0, dW_lat_k_ri = 0.0, dW_lat_k_ro = 0.0;
        M_yaw_fl = 0.0, M_yaw_fr = 0.0, M_yaw_rl = 0.0, M_yaw_rr = 0.0, M_yaw = 0.0;
        brents_iter_single = 0, golden_iter_single = 0;
    }

    void Vehicle::YMD(YMD_Carrier& carrier) {

		Vehicle copy = *this; // Create a copy of the current vehicle state to preserve original values during YMD

		brents_iter_total = 0;
		golden_iter_total = 0;
        iter_total = 0;

		carrier.max_a_lat = carrier.min_a_lat = 0.0; // Reset max and min lateral acceleration for YMD
        max_beta = vehicle_inputs.max_beta;
        num_beta = vehicle_inputs.num_beta;
        max_delta_d = vehicle_inputs.max_delta_d;
        num_delta_d = vehicle_inputs.num_delta_d;

        copy.force_a_lon = true;

        if (copy.a_lon_des < 0) { copy.pedals_input = Pedals_input::Braking; }
        else { copy.pedals_input = Pedals_input::Driving; }

        int control = 0.0;
        int stability = 0.0;
        int delta_d_past = 0.0;
		int beta_past = 0.0;

        std::vector<double> BETA_ISO(0);
        std::vector<double> DELTA_ISO(0);

        //delta isolines
        std::vector <std::vector<double>> A_LAT_ISODELTA_2(0);
        std::vector <std::vector<double>> A_LON_ISODELTA_2(0);
        std::vector <std::vector<double>> M_YAW_ISODELTA_2(0);
        std::vector <std::vector<double>> STABILITY_2(0);
        std::vector <std::vector<double>> BETA_ISODELTA_2(0);
        std::vector <std::vector<double>> DELTA_ISODELTA_2(0);

        std::vector<double> A_LAT_ISODELTA(0);
		std::vector<double> A_LON_ISODELTA(0);
        std::vector<double> M_YAW_ISODELTA(0);
        std::vector<double> STABILITY(0);
        std::vector<double> BETA_ISODELTA(0);
        std::vector<double> DELTA_ISODELTA(0);

        for (double j = -max_delta_d; j <= max_delta_d; j += max_delta_d * 2 / num_delta_d) {

            copy.delta_d_deg = j;

			A_LAT_ISODELTA.clear();
			A_LON_ISODELTA.clear();
			M_YAW_ISODELTA.clear();
			STABILITY.clear();
            BETA_ISODELTA.clear();
            DELTA_ISODELTA.clear();

            copy.beta_deg = -max_beta;

            for (int i = 0; i <= 50; i++) {

                beta_past = copy.beta_deg;
                copy.beta_deg += max_beta * 2 / 50;

                copy.solver();
				brents_iter_total += copy.brents_iter_single;
				golden_iter_total += copy.golden_iter_single;
				iter_total += copy.iter;

                //A_LAT_ISODELTA.push_back(round_to(j < 0.0 ? -copy.a_lat : copy.a_lat, 2));
                A_LAT_ISODELTA.push_back(round_to(copy.a_lat, 2));
                A_LON_ISODELTA.push_back(round_to(copy.a_lon, 2));
                //M_YAW_ISODELTA.push_back(j < 0.0 ? -copy.M_yaw : copy.M_yaw);
                M_YAW_ISODELTA.push_back(copy.M_yaw);
                BETA_ISODELTA.push_back(copy.beta_deg);
                DELTA_ISODELTA.push_back(j);

                if (i != 0) stability = abs(M_YAW_ISODELTA[i] - M_YAW_ISODELTA[i - 1]) / (copy.beta_deg - beta_past);
                STABILITY.push_back(stability);

				if ((j < 0.0 ? -copy.a_lat : copy.a_lat) > carrier.max_a_lat) {
					carrier.max_a_lat = round_to((j < 0.0 ? -copy.a_lat : copy.a_lat), 1); 
                    carrier.max_a_lat += (remainder(carrier.max_a_lat, 0.2) == 0.0 ? 0.2 : 0.1);
                }
                if ((j < 0.0 ? -copy.a_lat : copy.a_lat) < carrier.min_a_lat) { 
                    carrier.min_a_lat = round_to((j < 0.0 ? -copy.a_lat : copy.a_lat), 1); 
                    carrier.min_a_lat -= (remainder(carrier.min_a_lat, 0.2) == 0.0 ? 0.2 : 0.1);
                }
            }

			A_LAT_ISODELTA_2.push_back(A_LAT_ISODELTA);
			A_LON_ISODELTA_2.push_back(A_LON_ISODELTA);
			M_YAW_ISODELTA_2.push_back(M_YAW_ISODELTA);
            BETA_ISODELTA_2.push_back(BETA_ISODELTA);
            DELTA_ISODELTA_2.push_back(DELTA_ISODELTA);
			STABILITY_2.push_back(STABILITY);

            //DELTA_ISO.push_back(j < 0.0 ? -copy.delta_d_des : copy.delta_d_des);
            DELTA_ISO.push_back(copy.delta_d_deg);
        }

		carrier.a_lat_isodelta = A_LAT_ISODELTA_2;
		carrier.a_lon_isodelta = A_LON_ISODELTA_2;
        carrier.M_yaw_isodelta = M_YAW_ISODELTA_2;
        carrier.beta_isodelta = BETA_ISODELTA_2;
        carrier.delta_isodelta = DELTA_ISODELTA_2;
		carrier.stability = STABILITY_2;
		carrier.delta_iso = DELTA_ISO;

        copy.beta_deg = vehicle_inputs.beta_deg; // Reset to original value after YMD
        copy.delta_d_deg = vehicle_inputs.delta_d_deg; // Reset to original value after YMD

        //beta isolines
        std::vector <std::vector<double>> A_LAT_ISOBETA_2(0);
		std::vector <std::vector<double>> A_LON_ISOBETA_2(0);
        std::vector <std::vector<double>> M_YAW_ISOBETA_2(0);
        std::vector <std::vector<double>> CONTROL_2(0);
        std::vector <std::vector<double>> BETA_ISOBETA_2(0);
        std::vector <std::vector<double>> DELTA_ISOBETA_2(0);

        std::vector<double> A_LAT_ISOBETA(0);
		std::vector<double> A_LON_ISOBETA(0);
        std::vector<double> M_YAW_ISOBETA(0);
        std::vector<double> CONTROL(0);
        std::vector<double> BETA_ISOBETA(0);
        std::vector<double> DELTA_ISOBETA(0);

        for (double j = -max_beta / 2; j <= max_beta / 2; j += max_beta / num_beta) {

            //j < 0.0 ? copy.beta_des = -j : copy.beta_des = j;
            copy.beta_deg = j;

            A_LAT_ISOBETA.clear();
			A_LON_ISOBETA.clear();
			M_YAW_ISOBETA.clear();
			CONTROL.clear();
            BETA_ISOBETA.clear();
            DELTA_ISOBETA.clear();

			copy.delta_d_deg = -max_delta_d;

            for (int i = 0; i < num_delta_d; i++) {

				delta_d_past = copy.delta_d_deg;
				copy.delta_d_deg += max_delta_d * 2 / num_delta_d;

                copy.solver();
                brents_iter_total += copy.brents_iter_single;
				golden_iter_total += copy.golden_iter_single;
				iter_total += copy.iter;

                //A_LAT_ISOBETA.push_back(round_to(j < 0.0 ? -copy.a_lat : copy.a_lat, 2));
                A_LAT_ISOBETA.push_back(round_to(copy.a_lat, 2));
				A_LON_ISOBETA.push_back(round_to(copy.a_lon, 2));
                M_YAW_ISOBETA.push_back(copy.M_yaw);
                BETA_ISOBETA.push_back(j);
                DELTA_ISOBETA.push_back(copy.delta_d_deg);

                if (i != 0) control = abs(M_YAW_ISOBETA[i] - M_YAW_ISOBETA[i - 1]) / (copy.delta_d_deg - delta_d_past);
				CONTROL.push_back(control);
            }

            A_LAT_ISOBETA_2.push_back(A_LAT_ISOBETA);
			A_LON_ISOBETA_2.push_back(A_LON_ISOBETA);
            M_YAW_ISOBETA_2.push_back(M_YAW_ISOBETA);
            BETA_ISOBETA_2.push_back(BETA_ISOBETA);
            DELTA_ISOBETA_2.push_back(DELTA_ISOBETA);
			CONTROL_2.push_back(CONTROL);
            //BETA_ISO.push_back(j < 0.0 ? -copy.beta_des : copy.beta_des);
            BETA_ISO.push_back(copy.beta_deg);
        }

        carrier.a_lat_isobeta = A_LAT_ISOBETA_2;
		carrier.a_lon_isobeta = A_LON_ISOBETA_2;
        carrier.M_yaw_isobeta = M_YAW_ISOBETA_2;
        carrier.beta_isobeta = BETA_ISOBETA_2;
        carrier.delta_isobeta = DELTA_ISOBETA_2;
		carrier.control = CONTROL_2;
		carrier.beta_iso = BETA_ISO;

        solver();

        carrier.single_a_lat = a_lat;
        carrier.single_M_yaw = M_yaw;
    }