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

        fl.set_position('F', 'L'), fr.set_position('F', 'R'), rl.set_position('R', 'L'), rr.set_position('R', 'R');

        fl.set_parameters(front_tires), fr.set_parameters(front_tires), rl.set_parameters(rear_tires), rr.set_parameters(rear_tires);

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

        //Differentials setup
        
			//Front differential
		    front_diff.lock = vehicle_inputs.diff_lock_f; // (INPUT)
            
			if (drive_config == Actuator_config::Rear) { front_diff.lock = Actuator_lock::Open; }

            if (front_diff.lock == Actuator_lock::Open){
                front_diff.dTBR = 1.0;
                front_diff.bTBR = 1.0;
                front_diff.preload = 0.0;
                front_diff.k_lock = 0.0;
			}
            else if (front_diff.lock == Actuator_lock::Geared){
                front_diff.dTBR = vehicle_inputs.diff_dTBR_f; // [Nm / Nm] LSD driving torque balance ratio (INPUT)
                front_diff.bTBR = vehicle_inputs.diff_bTBR_f; // [Nm / Nm] LSD braking torque balance ratio (INPUT)
                front_diff.preload = 0.0;
                front_diff.k_lock = 0.0;
            }
            else if (front_diff.lock == Actuator_lock::Ramp){
                front_diff.dTBR = vehicle_inputs.diff_dTBR_f; // [Nm / Nm] LSD driving torque balance ratio (INPUT)
                front_diff.bTBR = vehicle_inputs.diff_bTBR_f; // [Nm / Nm] LSD braking torque balance ratio (INPUT)
                front_diff.preload = vehicle_inputs.diff_preload_f; // [Nm] Clutch (Ramp and Tracloc) preload torque (INPUT)
                front_diff.k_lock = 0.0;
            }
            else if (front_diff.lock == Actuator_lock::Tracloc) {
                front_diff.dTBR = 100.0;
                front_diff.bTBR = 100.0;
                front_diff.preload = vehicle_inputs.diff_preload_f; // [Nm] Clutch (Ramp and Tracloc) preload torque (INPUT)
                front_diff.k_lock = vehicle_inputs.diff_k_lock_f; // [Nm / Nm] Tracloc torque stiffness (INPUT)
            }
            else if (front_diff.lock == Actuator_lock::Locked) {
                front_diff.dTBR = 100.0;
                front_diff.bTBR = 100.0;
                front_diff.preload = 0.0;
                front_diff.k_lock = 0.0;
            }

		    //Rear differential
            rear_diff.lock = vehicle_inputs.diff_lock_r; // (INPUT)
            if (drive_config == Actuator_config::Front) { rear_diff.lock = Actuator_lock::Open; }

            if (rear_diff.lock == Actuator_lock::Open) {
                rear_diff.dTBR = 1.0;
                rear_diff.bTBR = 1.0;
                rear_diff.preload = 0.0;
                rear_diff.k_lock = 0.0;
            }
            else if (rear_diff.lock == Actuator_lock::Geared) {
                rear_diff.dTBR = vehicle_inputs.diff_dTBR_r; // [Nm / Nm] LSD driving torque balance ratio (INPUT)
                rear_diff.bTBR = vehicle_inputs.diff_bTBR_r; // [Nm / Nm] LSD braking torque balance ratio (INPUT)
                rear_diff.preload = 0.0;
                rear_diff.k_lock = 0.0;
            }
            else if (rear_diff.lock == Actuator_lock::Ramp) {
                rear_diff.dTBR = vehicle_inputs.diff_dTBR_r; // [Nm / Nm] LSD driving torque balance ratio (INPUT)
                rear_diff.bTBR = vehicle_inputs.diff_bTBR_r; // [Nm / Nm] LSD braking torque balance ratio (INPUT)
                rear_diff.preload = vehicle_inputs.diff_preload_r; // [Nm] Clutch (Ramp and Tracloc) preload torque (INPUT)
                rear_diff.k_lock = 0.0;
            }
            else if (rear_diff.lock == Actuator_lock::Tracloc) {
                rear_diff.dTBR = 100.0;
                rear_diff.bTBR = 100.0;
                rear_diff.preload = vehicle_inputs.diff_preload_r; // [Nm] Clutch (Ramp and Tracloc) preload torque (INPUT)
                rear_diff.k_lock = vehicle_inputs.diff_k_lock_r; // [Nm / Nm] Tracloc torque stiffness (INPUT)
            }
            else if (rear_diff.lock == Actuator_lock::Locked) {
                rear_diff.dTBR = 100.0;
                rear_diff.bTBR = 100.0;
                rear_diff.preload = 0.0;
                rear_diff.k_lock = 0.0;
            }

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
        m_u_fl = vehicle_inputs.m_u_fl; // [kg] Front left unsprung mass (INPUT)
        m_u_fr = vehicle_inputs.m_u_fr; // [kg] Front right unsprung mass (INPUT)
        m_u_rl = vehicle_inputs.m_u_rl; // [kg] Rear left unsprung mass (INPUT)
        m_u_rr = vehicle_inputs.m_u_rr; // [kg] Rear right unsprung mass (INPUT)

        //CG location
        h_CG = vehicle_inputs.h_CG / 1000.0; // [m] Height of the center of gravity (INPUT)

        //Ackermann geometry

        //Actual cornering radius calculation
        R = vehicle_inputs.R; // [m] Minimum cornering radius (from CG) (INPUT)
        if (steering_input == Steering_input::Steering) { beta_deg = vehicle_inputs.beta_deg; } // [deg] Desired vehicle sideslip angle (INPUT)
        else { beta_deg = 0.0; }

        //Steering angles
        if (steering_input == Steering_input::Steering) { delta_d_deg = vehicle_inputs.delta_d_deg; } // [deg] Desired front outer wheel steering angle (MAX 115)
		else { delta_d_deg = 0.0; }

		//Longitudinal acceleration
		a_lon_des = vehicle_inputs.a_lon_des; // [g] Desired longitudinal acceleration (INPUT)

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
        V_input = vehicle_inputs.V_input; // [km/h] Vehicle speed input (INPUT)
		V = V_input / 3.6; // [m/s] Vehicle speed
    }

    void Vehicle::solver() {

        fl.refresh(), fr.refresh(), rl.refresh(), rr.refresh();

        refresh();

        vehicle_parameters();

        ackermann_diagram();

        //Slip ratios
        fl.kappa = fr.kappa = rl.kappa = rr.kappa = 0.0; // [-] Wheel slip ratios

		chassis_stiffnesses();

        //Main iterative loop
        iter = 0; // Iteration counters for main solver
        F_z_tol = 0.1; // [N] Acceptable wheel load error for the iterative process
        max_iter = 25; // Maximum number of iterations for the iterative process
        a_lon_tol = 0.01; // [g] Acceptable longitudinal acceleration error for main solver not to be terminated

#ifdef _DEBUG
		if (vehicle_inputs.force_debug_iter) { max_iter = vehicle_inputs.debug_iter; }
#endif

        do {
            
            update_tires();

            accelerations();

            if (iter == 0) { update_tires(); accelerations(); }

            unsprung_masses();

            suspension_kinematics();

            aerodynamics();

            longitudinal_load_transfer();

            if (iter <= 1) { F_lat = fl.F_lat = fr.F_lat = rl.F_lat = rr.F_lat = 0.0; }
            lateral_load_transfer();

            update_wheel_loads_and_displacements();

            bias_now = (fl.T + fr.T) / (fl.T + fr.T + rl.T + rr.T);
            iter++;
            if (iter >= max_iter) { cancel_run = 1; }
            if (iter > 10 && (a_lon < a_lon_des - a_lon_tol || a_lon > a_lon_des + a_lon_tol)) { cancel_run = 1; }

			if (cancel_run == 1) { break; }

        } while (fl.F_z_err > F_z_tol || fr.F_z_err > F_z_tol || rl.F_z_err > F_z_tol || rr.F_z_err > F_z_tol);

        yaw_moment();
        //if ((a_lon < a_lon_des - a_lon_tol || a_lon > a_lon_des + a_lon_tol)) { cancel_run = 1; }
    }

    void Vehicle::vehicle_parameters() {

        //Driver input
        force_a_lon = true;
        a_lon_des = vehicle_inputs.a_lon_des;

        if (pedals_input == Pedals_input::Cruising) { force_a_lon = true; a_lon_des = 0.0; }
        if (pedals_input == Pedals_input::Coasting) { force_a_lon = false; }
		if (pedals_input == Pedals_input::Driving) { lon_sign  = 1; }
		if (pedals_input == Pedals_input::Braking) { lon_sign = -1; }

        //Drive and Brake bias
        DB = (drive_config == Actuator_config::Front) ? 100.0 : (drive_config == Actuator_config::Rear) ? 0.0 : DB_input; // [%front] Torque bias
        BB = (brake_config == Actuator_config::Front) ? 100.0 : (brake_config == Actuator_config::Rear) ? 0.0 : BB_input; // [%front] Brake bias
        bias = (lon_sign >= 0) ? DB / 100.0 : BB / 100.0; // [%front] Torque or brake bias

        //Masses and weights

        //Total masses and weights
        W = m * g; // [N] Total weight of the vehicle (w/driver)
        W_fl = W * x / 100.0 * y / 100.0; // [N] Front left weight
        W_fr = W * x / 100.0 * (1 - y / 100.0); // [N] Front right weight
        W_rl = W * (1 - x / 100.0) * y / 100.0; // [N] Rear left weight
        W_rr = W * (1 - x / 100.0) * (1 - y / 100.0); // [N] Rear right weight

        //Unsprung masses
        m_u = m_u_fl + m_u_fr + m_u_rl + m_u_rr; // [kg] Total unsprung mass

        //Sprung masses
        m_s = m - m_u; // [kg] Total sprung mass

        //Wheel loads
        fl.F_z = W_fl; // [N] Front left wheel load
        fr.F_z = W_fr; // [N] Front right wheel load
        rl.F_z = W_rl; // [N] Rear left wheel load
        rr.F_z = W_rr; // [N] Rear right wheel load

        //CG location
        a = L * (1 - x / 100); // [m] Distance from the front axle to the CG
        b = L * x / 100; // [m] Distance from the rear axle to the CG
        a_s = (m * a - (m_u_rl + m_u_rr) * L) / m_s; // [m] Distance from the front axle to the sprung mass CG
        b_s = (m * b - (m_u_fl + m_u_fr) * L) / m_s; // [m] Distance from the rear axle to the sprung mass CG

        //Steering angles
        fl.delta = (delta_d_deg * delta_d_deg * vehicle_inputs.ackermann_2 + delta_d_deg * vehicle_inputs.ackermann_1 - delta_f_static) * pi / 180.0; // [rad] Front outer wheel steering angle (INPUT)
        fr.delta = (delta_d_deg * delta_d_deg * vehicle_inputs.ackermann_2 + delta_d_deg * vehicle_inputs.ackermann_1 + delta_f_static) * pi / 180.0; // [rad] Front inner wheel steering angle (INPUT)
        rl.delta = (delta_r_static)*pi / 180; // [rad] Rear inner wheel steering angle
        rr.delta = (-delta_r_static) * pi / 180; // [rad] Rear outer wheel steering angleINPUT
    }

    void Vehicle::ackermann_diagram() {
       //Ackermann geometry

       //Actual cornering radius calculation
        beta = beta_deg < 1E-10 && beta_deg > -1E-10 ? 0 : beta_deg * pi / 180.0; // [rad] Vehicle sideslip angle  
        R_a = R * cos(beta); // [m] Actual cornering radius
        S_f = a + R * sin(beta); // [m]
        S_r = L - S_f; // [m]

        //Tire cornering radius
        fl.R = sqrt((R_a + t_f / 2) * (R_a + t_f / 2) + S_f * S_f); // [m] Front left wheel cornering radius
        fr.R = sqrt((R_a - t_f / 2) * (R_a - t_f / 2) + S_f * S_f); // [m] Front right wheel cornering radius
        rl.R = sqrt((R_a + t_r / 2) * (R_a + t_r / 2) + S_r * S_r); // [m] Rear left wheel cornering radius
        rr.R = sqrt((R_a - t_r / 2) * (R_a - t_r / 2) + S_r * S_r); // [m] Rear right wheel cornering radius

        //Effective steering angles
        fl.theta = atan(S_f / (R_a + t_f / 2)); // [rad] Front inner wheel effective steering angle
        fr.theta = atan(S_f / (R_a - t_f / 2)); // [rad] Front outer wheel effective steering angle
        rl.theta = atan(S_r / (R_a + t_r / 2)); // [rad] Rear inner wheel effective steering angle
        rr.theta = atan(S_r / (R_a - t_r / 2)); // [rad] Rear outer wheel effective steering angle

        //Slip angles
        fl.set_alpha(lat_sign), fr.set_alpha(lat_sign), rl.set_alpha(lat_sign), rr.set_alpha(lat_sign);
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

        //Vertical tire stiffness
        fl.set_K_T(), fr.set_K_T(), rl.set_K_T(), rr.set_K_T();

        //Tire radius
        fl.set_r(), fr.set_r(), rl.set_r(), rr.set_r();

        //Tire longitudinal velocity
        fl.set_V_x(V, R), fr.set_V_x(V, R), rl.set_V_x(V, R), rr.set_V_x(V, R);

        //Tire angular velocity
		fl.set_omega(pedals_input), fr.set_omega(pedals_input), rl.set_omega(pedals_input), rr.set_omega(pedals_input);

        //Pacejka parameters
        fl.set_Pacejka(), fr.set_Pacejka(), rl.set_Pacejka(), rr.set_Pacejka();

        //Lateral Pacejka
        fl.set_F_y(), fr.set_F_y(), rl.set_F_y(), rr.set_F_y();

        //Longitudinal Pacejka and Longitudinal modified Nicolas-Comstock
        solve_kappa();

        //Lateral modified Nicolas-Comstock
        fl.set_F_y_comb(a_rad), fr.set_F_y_comb(a_rad), rl.set_F_y_comb(a_rad), rr.set_F_y_comb(a_rad);

        //Reaction torques
        fl.set_T_r(lon_sign, brake_type_f, diff_type_f), fr.set_T_r(lon_sign, brake_type_f, diff_type_f), rl.set_T_r(lon_sign, brake_type_r, diff_type_r), rr.set_T_r(lon_sign, brake_type_r, diff_type_r);
        
        //Tires rolling resistances
        fl.set_F_rr(), fr.set_F_rr(), rl.set_F_rr(), rr.set_F_rr();
    }

    void Vehicle::accelerations() {
        //Accelerations

                //Lateral accelerations
        fl.set_F_lat(), fr.set_F_lat(), rl.set_F_lat(), rr.set_F_lat();
        F_lat = fl.F_lat + fr.F_lat + rl.F_lat + rr.F_lat; // [N] Total lateral force
        a_lat = F_lat / W; // [g] Vehicle lateral acceleration

        //Longitudinal accelerations
        fl.set_F_lon(), fr.set_F_lon(), rl.set_F_lon(), rr.set_F_lon();
        F_lon = fl.F_lon + fr.F_lon + rl.F_lon + rr.F_lon - F_drag; // [N] Total longitudinal force
        a_lon = F_lon / W; // [g] Vehicle longitudinal acceleration

        //Cornering radial accelerations
        fl.set_F_rad(), fr.set_F_rad(), rl.set_F_rad(), rr.set_F_rad();
        F_rad = fl.F_rad + fr.F_rad + rl.F_rad + rr.F_rad - F_drag * sin(beta); // [N] Total cornering radial force
        a_rad = (abs(F_rad / W) < 1e-10) ? 1e-10 : F_rad / W; // [g] Vehicle cornering radial acceleration

        //Set corner side
		if (a_lat >= 0) {
            lat_sign = 1;
        }
        else if (a_lat < 0) { 
            lat_sign = -1;
        }
        if (vehicle_inputs.force_velocity) {
            R = V_input * V_input / (a_rad * g); // [m] Cornering radius (from CG)
			ackermann_diagram();
        }
        else {
            R = abs(R) * lat_sign;
            ackermann_diagram();
        }
    }

    void Vehicle::unsprung_masses() {
        //Sprung and unsprung masses CG location

        h_CG_u_fl = fl.r; // [m] Height of the unsprung mass CG        
        h_CG_u_fr = fr.r; // [m] Height of the unsprung mass CG        
        h_CG_u_rl = rl.r; // [m] Height of the unsprung mass CG
        h_CG_u_rr = rr.r; // [m] Height of the unsprung mass CG    
        h_CG_u = (h_CG_u_fl * m_u_fl + h_CG_u_fr * m_u_fr + h_CG_u_rl * m_u_rl + h_CG_u_rr * m_u_rr) / m_u; // [m] Height of the unsprung masses CG
        h_CG_s = (m * h_CG - m_u * h_CG_u) / m_s; // [m] Height of the sprung mass CG           
    }

    void Vehicle::suspension_kinematics(){
        //Suspension geometry

        //Roll suspension parameters
        h_r_f = (psi_deg * psi_deg * vehicle_inputs.h_r_f_2 + psi_deg * vehicle_inputs.h_r_f_1 + vehicle_inputs.h_r_f_0) / 1000.0; // [m] Height of the front roll center                                            INPUT
        h_r_r = (psi_deg * psi_deg * vehicle_inputs.h_r_r_2 + psi_deg * vehicle_inputs.h_r_r_1 + vehicle_inputs.h_r_r_0) / 1000.0; // [m] Height of the rear roll center                                              INPUT
        off_r_f = (psi_deg * psi_deg * vehicle_inputs.off_r_f_2 + psi_deg * vehicle_inputs.off_r_f_1 + vehicle_inputs.off_r_f_0) / 1000.0; // [m] Front roll center offset from the vehicle center line (+ inner)            INPUT
        off_r_r = (psi_deg * psi_deg * vehicle_inputs.off_r_r_2 + psi_deg * vehicle_inputs.off_r_r_1 + vehicle_inputs.off_r_r_0) / 1000.0; // [m] Rear roll center offset from the vehicle center line (+ inner)             INPUT
        n_r_fl = t_f / 2 - off_r_f; // [m] Front roll center distance from the front inner wheel
        n_r_fr = t_f / 2 + off_r_f; // [m] Front roll center distance from the front outer wheel
        n_r_rl = t_r / 2 - off_r_r; // [m] Rear roll center distance from the rear inner wheel
        n_r_rr = t_r / 2 + off_r_r; // [m] Rear roll center distance from the rear outer wheel
        p_r_fl = (psi_deg * psi_deg * vehicle_inputs.p_r_f_2 + psi_deg * vehicle_inputs.p_r_f_1 + vehicle_inputs.p_r_f_0) / 1000.0; // [m] Front inner roll instantaneous center height                               INPUT
        p_r_fr = (-psi_deg * psi_deg * vehicle_inputs.p_r_f_2 - psi_deg * vehicle_inputs.p_r_f_1 + vehicle_inputs.p_r_f_0) / 1000.0; // [m] Front outer roll instantaneous center height                              INPUT
        p_r_rl = (psi_deg * psi_deg * vehicle_inputs.p_r_r_2 + psi_deg * vehicle_inputs.p_r_r_1 + vehicle_inputs.p_r_r_0) / 1000.0; // [m] Rear inner roll instantaneous center height                                INPUT
        p_r_rr = (-psi_deg * psi_deg * vehicle_inputs.p_r_r_2 - psi_deg * vehicle_inputs.p_r_r_1 + vehicle_inputs.p_r_r_0) / 1000.0; // [m] Rear outer roll instantaneous center height                               INPUT
        q_r_fl = p_r_fl / h_r_f * n_r_fl; // [m] Front inner roll instantaneous center distance from the wheel medium plane
        q_r_fr = p_r_fr / h_r_f * n_r_fr; // [m] Front outer roll instantaneous center distance from the wheel medium plane
        q_r_rl = p_r_rl / h_r_r * n_r_rl; // [m] Rear inner roll instantaneous center distance from the wheel medium plane
        q_r_rr = p_r_rr / h_r_r * n_r_rr; // [m] Rear outer roll instantaneous center distance from the wheel medium plane

        //Pitch suspension parameters
        h_p_l = (phi_deg * phi_deg * vehicle_inputs.h_p_i_2 + phi_deg * vehicle_inputs.h_p_i_1 + vehicle_inputs.h_p_i_0) / 1000.0; // [m] Height of the inner pitch center                                           INPUT
        h_p_r = (phi_deg * phi_deg * vehicle_inputs.h_p_o_2 + phi_deg * vehicle_inputs.h_p_o_1 + vehicle_inputs.h_p_o_0) / 1000.0; // [m] Height of the outer pitch center                                          INPUT
        n_p_fl = (phi_deg * phi_deg * vehicle_inputs.n_p_i_2 + phi_deg * vehicle_inputs.n_p_i_1 + vehicle_inputs.n_p_i_0) / 1000.0; // [m] Inner pitch center distance from the front axle                          INPUT
        n_p_fr = (phi_deg * phi_deg * vehicle_inputs.n_p_i_2 + phi_deg * vehicle_inputs.n_p_i_1 + vehicle_inputs.n_p_i_0) / 1000.0; // [m] Outer pitch center distance from the front axle                         INPUT
        n_p_rl = (phi_deg * phi_deg * vehicle_inputs.n_p_o_2 + phi_deg * vehicle_inputs.n_p_o_1 + vehicle_inputs.n_p_o_0) / 1000.0; // [m] Inner pitch center distance from the rear axle                           INPUT
        n_p_rr = (phi_deg * phi_deg * vehicle_inputs.n_p_o_2 + phi_deg * vehicle_inputs.n_p_o_1 + vehicle_inputs.n_p_o_0) / 1000.0; // [m] Outer pitch center distance from the rear axle                          INPUT
        p_p_fl = (phi_deg * phi_deg * vehicle_inputs.p_p_f_2 + phi_deg * vehicle_inputs.p_p_f_1 + vehicle_inputs.p_p_f_0) / 1000.0; // [m] Front inner pitch instantaneous center height                             INPUT
        p_p_fr = (phi_deg * phi_deg * vehicle_inputs.p_p_f_2 + phi_deg * vehicle_inputs.p_p_f_1 + vehicle_inputs.p_p_f_0) / 1000.0; // [m] Front outer pitch instantaneous center height                            INPUT
        p_p_rl = (phi_deg * phi_deg * vehicle_inputs.p_p_r_2 + phi_deg * vehicle_inputs.p_p_r_1 + vehicle_inputs.p_p_r_0) / 1000.0; // [m] Rear inner pitch instantaneous center height                              INPUT
        p_p_rr = (phi_deg * phi_deg * vehicle_inputs.p_p_r_2 + phi_deg * vehicle_inputs.p_p_r_1 + vehicle_inputs.p_p_r_0) / 1000.0; // [m] Rear outer pitch instantaneous center height                             INPUT
        q_p_fl = p_p_fl / h_p_l * n_p_fl; // [m] Front inner pitch instantaneous center distance from the front axle
        q_p_fr = p_p_fr / h_p_r * n_p_fr; // [m] Front outer pitch instantaneous center distance from the front axle
        q_p_rl = p_p_rl / h_p_l * n_p_rl; // [m] Rear inner pitch instantaneous center distance from the rear axle
        q_p_rr = p_p_rr / h_p_r * n_p_rr; // [m] Rear outer pitch instantaneous center distance from the rear axle

        //Suspension stiffnesses

            //Motion ratios
        MR_s_fl = w_fl * w_fl * 1e6 * vehicle_inputs.MR_s_f_2 + w_fl * 1e3 * vehicle_inputs.MR_s_f_1 + vehicle_inputs.MR_s_f_0; // [-] Front inner spring motion ratio              FUNCTION INPUT
        MR_s_fr = w_fr * w_fr * 1e6 * vehicle_inputs.MR_s_f_2 + w_fr * 1e3 * vehicle_inputs.MR_s_f_1 + vehicle_inputs.MR_s_f_0; // [-] Front outer spring motion ratio             FUNCTION INPUT
        MR_s_rl = w_rl * w_rl * 1e6 * vehicle_inputs.MR_s_r_2 + w_rl * 1e3 * vehicle_inputs.MR_s_r_1 + vehicle_inputs.MR_s_r_0; // [-] Rear inner spring motion ratio               FUNCTION INPUT
        MR_s_rr = w_rr * w_rr * 1e6 * vehicle_inputs.MR_s_r_2 + w_rr * 1e3 * vehicle_inputs.MR_s_r_1 + vehicle_inputs.MR_s_r_0; // [-] Rear outer spring motion ratio              FUNCTION INPUT
        MR_arb_fl = w_fl * w_fl * 1e6 * vehicle_inputs.MR_arb_f_2 + w_fl * 1e3 * vehicle_inputs.MR_arb_f_1 + vehicle_inputs.MR_arb_f_0; // [-] Front inner anti-roll bar motion ratio     FUNCTION INPUT
        MR_arb_fr = w_fr * w_fr * 1e6 * vehicle_inputs.MR_arb_f_2 + w_fr * 1e3 * vehicle_inputs.MR_arb_f_1 + vehicle_inputs.MR_arb_f_0; // [-] Front outer anti-roll bar motion ratio    FUNCTION INPUT
        MR_arb_rl = w_rl * w_rl * 1e6 * vehicle_inputs.MR_arb_r_2 + w_rl * 1e3 * vehicle_inputs.MR_arb_r_1 + vehicle_inputs.MR_arb_r_0; // [-] Rear inner anti-roll bar motion ratio      FUNCTION INPUT
        MR_arb_rr = w_rr * w_rr * 1e6 * vehicle_inputs.MR_arb_r_2 + w_rr * 1e3 * vehicle_inputs.MR_arb_r_1 + vehicle_inputs.MR_arb_r_0; // [-] Rear outer anti-roll bar motion ratio     FUNCTION INPUT

        //Wheel rates
        K_susp_fl = k_susp_f / (MR_s_fl * MR_s_fl); // [N/m] Front inner wheel rate
        K_susp_fr = k_susp_f / (MR_s_fr * MR_s_fr); // [N/m] Front outer wheel rate
        K_susp_rl = k_susp_r / (MR_s_rl * MR_s_rl); // [N/m] Rear inner wheel rate
        K_susp_rr = k_susp_r / (MR_s_rr * MR_s_rr); // [N/m] Rear outer wheel rate
        K_arb_fl = k_arb_f / (MR_arb_fl * MR_arb_fl); // [N/m] Front inner wheel rate
        K_arb_fr = k_arb_f / (MR_arb_fr * MR_arb_fr); // [N/m] Front outer wheel rate
        K_arb_rl = k_arb_r / (MR_arb_rl * MR_arb_rl); // [N/m] Rear inner wheel rate
        K_arb_rr = k_arb_r / (MR_arb_rr * MR_arb_rr); // [N/m] Rear outer wheel rate

        //Roll stiffnesses
        K_r_C_f = k_r_C_f * t_f * t_f; // [N/m] Front roll stiffness due to the chassis
        K_r_C_r = k_r_C_r * t_r * t_r; // [N/m] Rear roll stiffness due to the chassis
        K_r_tot_f = 1 / (1 / K_r_C_f + 1 / fl.K_T + 1 / fr.K_T + 1 / (K_susp_fl + K_arb_fl) + 1 / (K_susp_fr + K_arb_fr)); // [N/m] Front total roll stiffness
        K_r_tot_r = 1 / (1 / K_r_C_r + 1 / rl.K_T + 1 / rr.K_T + 1 / (K_susp_rl + K_arb_rl) + 1 / (K_susp_rr + K_arb_rr)); // [N/m] Rear total roll stiffness

        //Pitch stiffnesses
        K_p_C_l = k_p_C_i * L * L; // [N/m] Inner pitch stiffness due to the chassis
        K_p_C_r = k_p_C_o * L * L; // [N/m] Outer pitch stiffness due to the chassis
        K_p_tot_l = 1 / (1 / K_p_C_l + 1 / fl.K_T + 1 / rl.K_T + 1 / K_susp_fl + 1 / K_susp_rl); // [N/m] Inner total pitch stiffness
        K_p_tot_r = 1 / (1 / K_p_C_r + 1 / fr.K_T + 1 / rr.K_T + 1 / K_susp_fr + 1 / K_susp_rr); // [N/m] Outer total pitch stiffness
    }

    void Vehicle::aerodynamics() {
        //Aerodynamics

               //Vehicle speed
        V_skid = sqrt(a_rad * g * R); // [m/s] Vehicle skid speed

        if (!vehicle_inputs.force_velocity) {
            V = V_skid; // [m/s] Vehicle speed
        }

        V_kmh = V * 3.6; // [km/h] Vehicle speed

        //Downforce
        F_down = (V_kmh * V_kmh * vehicle_inputs.F_down_2 + V_kmh * vehicle_inputs.F_down_1); // [N] Total downforce                         FUNCTION INPUT
        F_down_x = (V_kmh * V_kmh * vehicle_inputs.F_down_x_2 + V_kmh * vehicle_inputs.F_down_x_1 + vehicle_inputs.F_down_x_0); // [%front] Downforce distribution to the front axle FUNCTION INPUT
        F_down_y = V_kmh * V_kmh * vehicle_inputs.F_down_y_2 + V_kmh * vehicle_inputs.F_down_y_1 + vehicle_inputs.F_down_y_0; // [%inner] Downforce distribution to the inner side                      FUNCTION INPUT
        F_down_fl = F_down * F_down_x / 100.0 * F_down_y / 100.0; // [N] Front inner downforce
        F_down_fr = F_down * F_down_x / 100.0 * (1 - F_down_y / 100.0); // [N] Front outer downforce
        F_down_rl = F_down * (1 - F_down_x / 100.0) * F_down_y / 100.0; // [N] Rear inner downforce
        F_down_rr = F_down * (1 - F_down_x / 100.0) * (1 - F_down_y / 100.0); // [N] Rear outer downforce

        //Drag
        F_drag = (V_kmh * V_kmh * vehicle_inputs.F_drag_2 + V_kmh * vehicle_inputs.F_drag_1); // [N] Total drag force                    FUNCTION INPUT
        F_drag_z = (V_kmh * V_kmh * vehicle_inputs.F_drag_z_2 + V_kmh * vehicle_inputs.F_drag_z_1 + vehicle_inputs.F_drag_z_0) / 1000.0; // [m] Height of the drag force application point                   INPUT
        F_drag_y = V_kmh * V_kmh * vehicle_inputs.F_drag_y_2 + V_kmh * vehicle_inputs.F_drag_y_1 + vehicle_inputs.F_drag_y_0; // [%inner] Inner position of the drag force application point         INPUT
        h_drag = F_drag_z; // [m] Distance from the drag force application point to the pitch axis
    }

    void Vehicle::longitudinal_load_transfer() {
        //Longitudinal load transfer

        //Sprung masses longitudinal load transfer
        dW_lon_s_fl = m_s / m * (fl.F_lon * h_p_l - fl.T_r) / n_p_fl; // [N] Front inner sprung mass longitudinal load transfer
        dW_lon_s_fr = m_s / m * (fr.F_lon * h_p_r - fr.T_r) / n_p_fr; // [N] Front outer sprung mass longitudinal load transfer
        dW_lon_s_rl = m_s / m * (rl.F_lon * h_p_l - rl.T_r) / n_p_rl; // [N] Rear inner sprung mass longitudinal load transfer
        dW_lon_s_rr = m_s / m * (rr.F_lon * h_p_r - rr.T_r) / n_p_rr; // [N] Rear outer sprung mass longitudinal load transfer

        //Unsprung masses longitudinal load transfer
        dW_lon_u_fl = m_u / m * (fl.F_lon * h_CG_u - fl.T_r) / q_p_fl; // [N] Front inner unsprung mass longitudinal load transfer
        dW_lon_u_fr = m_u / m * (fr.F_lon * h_CG_u - fr.T_r) / q_p_fr; // [N] Front outer unsprung mass longitudinal load transfer
        dW_lon_u_rl = m_u / m * (rl.F_lon * h_CG_u - rl.T_r) / q_p_rl; // [N] Rear inner unsprung mass longitudinal load transfer
        dW_lon_u_rr = m_u / m * (rr.F_lon * h_CG_u - rr.T_r) / q_p_rr; // [N] Rear outer unsprung mass longitudinal load transfer

        //Geometric longitudinal load transfer
        dW_lon_g_fl = dW_lon_s_fl + dW_lon_u_fl; // [N] Front inner geometric longitudinal load transfer
        dW_lon_g_fr = dW_lon_s_fr + dW_lon_u_fr; // [N] Front outer geometric longitudinal load transfer
        dW_lon_g_rl = dW_lon_s_rl + dW_lon_u_rl; // [N] Rear inner geometric longitudinal load transfer
        dW_lon_g_rr = dW_lon_s_rr + dW_lon_u_rr; // [N] Rear outer geometric longitudinal load transfer

        //Pitch moments
        M_p_s_fl = m_s / m * fl.F_lon * (h_CG_s - h_p_l); // [N*m] Front inner sprung mass pitch moment
        M_p_s_fr = m_s / m * fr.F_lon * (h_CG_s - h_p_r); // [N*m] Front outer sprung mass pitch moment
        M_p_s_rl = m_s / m * rl.F_lon * (h_CG_s - h_p_l); // [N*m] Rear inner sprung mass pitch moment
        M_p_s_rr = m_s / m * rr.F_lon * (h_CG_s - h_p_r); // [N*m] Rear outer sprung mass pitch moment
        M_p_u_fl = dW_lon_u_fl * (q_p_fl - n_p_fl); // [N*m] Front inner unsprung mass pitch moment
        M_p_u_fr = dW_lon_u_fr * (q_p_fr - n_p_fr); // [N*m] Front outer unsprung mass pitch moment
        M_p_u_rl = dW_lon_u_rl * (q_p_rl - n_p_rl); // [N*m] Rear inner unsprung mass pitch moment
        M_p_u_rr = dW_lon_u_rr * (q_p_rr - n_p_rr); // [N*m] Rear outer unsprung mass pitch moment
        M_p_s = M_p_s_fl + M_p_s_fr + M_p_s_rl + M_p_s_rr; // [N*m] Total sprung mass pitch moment
        M_p_u = M_p_u_fl + M_p_u_fr + M_p_u_rl + M_p_u_rr; // [N*m] Total unsprung mass pitch moment
        T = fl.T_r + fr.T_r + rl.T_r + rr.T_r; // [N*m] Total reaction torque

        //Drag longitudinal load transfer
        M_p_drag = F_drag * h_drag * 0.0; // [N*m] Pitch moment due to drag
        dW_lon_drag = F_drag * F_drag_z / L * 0.0; // [N] Longitudinal load transfer due to drag

        //Pitch angle
        phi = (T + M_p_drag + M_p_s + M_p_u + dW_lon_g_fl * n_p_fl + dW_lon_g_fr * n_p_fr + dW_lon_g_rl * n_p_rl + dW_lon_g_rr * n_p_rr
            - L * (K_p_tot_l * (dW_lon_g_fl / K_susp_fl + dW_lon_g_rl / K_susp_rl) + K_p_tot_r * (dW_lon_g_fr / K_susp_fr + dW_lon_g_rr / K_susp_rr))) / (K_p_tot_l + K_p_tot_r) / L / L; // [rad] Pitch angle
        phi_deg = phi * 180.0 / pi; // [deg] Pitch angle

        //Total longitudinal load transfer
        dW_lon_l = phi * L * K_p_tot_l + (dW_lon_g_fl / K_susp_fl + dW_lon_g_rl / K_susp_rl) * K_p_tot_l; // [N] Inner longitudinal load transfer
        dW_lon_r = phi * L * K_p_tot_r + (dW_lon_g_fr / K_susp_fr + dW_lon_g_rr / K_susp_rr) * K_p_tot_r; // [N] Outer longitudinal load transfer

        //Elastic longitudinal load transfer
        dW_lon_k_fl = dW_lon_l - dW_lon_g_fl - dW_lon_drag / 2; // [N] Front inner elastic longitudinal load transfer
        dW_lon_k_fr = dW_lon_r - dW_lon_g_fr - dW_lon_drag / 2; // [N] Front outer elastic longitudinal load transfer
        dW_lon_k_rl = dW_lon_l - dW_lon_g_rl - dW_lon_drag / 2; // [N] Rear inner elastic longitudinal load transfer
        dW_lon_k_rr = dW_lon_r - dW_lon_g_rr - dW_lon_drag / 2; // [N] Rear outer elastic longitudinal load transfer
    }

    void Vehicle::lateral_load_transfer() {
        //Lateral load transfer

                //Sprung masses lateral load transfer
        dW_lat_s_fl = m_s / m * fl.F_lat * h_r_f / n_r_fl; // [N] Front inner sprung mass lateral load transfer
        dW_lat_s_fr = m_s / m * fr.F_lat * h_r_f / n_r_fr; // [N] Front outer sprung mass lateral load transfer
        dW_lat_s_rl = m_s / m * rl.F_lat * h_r_r / n_r_rl; // [N] Rear inner sprung mass lateral load transfer
        dW_lat_s_rr = m_s / m * rr.F_lat * h_r_r / n_r_rr; // [N] Rear outer sprung mass lateral load transfer

        //Unsprung masses lateral load transfer
        dW_lat_u_fl = m_u / m * fl.F_lat * h_CG_u / q_r_fl; // [N] Front inner unsprung mass lateral load transfer
        dW_lat_u_fr = m_u / m * fr.F_lat * h_CG_u / q_r_fr; // [N] Front outer unsprung mass lateral load transfer
        dW_lat_u_rl = m_u / m * rl.F_lat * h_CG_u / q_r_rl; // [N] Rear inner unsprung mass lateral load transfer
        dW_lat_u_rr = m_u / m * rr.F_lat * h_CG_u / q_r_rr; // [N] Rear outer unsprung mass lateral load transfer

        //Geometric lateral load transfer
        dW_lat_g_fl = dW_lat_s_fl + dW_lat_u_fl; // [N] Front inner geometric lateral load transfer
        dW_lat_g_fr = dW_lat_s_fr + dW_lat_u_fr; // [N] Front outer geometric lateral load transfer
        dW_lat_g_rl = dW_lat_s_rl + dW_lat_u_rl; // [N] Rear inner geometric lateral load transfer
        dW_lat_g_rr = dW_lat_s_rr + dW_lat_u_rr; // [N] Rear outer geometric lateral load transfer

        //Roll moments
        M_r_s_fl = m_s / m * fl.F_lat * (h_CG_s - h_r_f); // [N*m] Front inner sprung mass roll moment
        M_r_s_fr = m_s / m * fr.F_lat * (h_CG_s - h_r_f); // [N*m] Front outer sprung mass roll moment
        M_r_s_rl = m_s / m * rl.F_lat * (h_CG_s - h_r_r); // [N*m] Rear inner sprung mass roll moment
        M_r_s_rr = m_s / m * rr.F_lat * (h_CG_s - h_r_r); // [N*m] Rear outer sprung mass roll moment
        
        M_r_u_fl = dW_lat_u_fl * (q_r_fl - n_r_fl); // [N*m] Front inner unsprung mass roll moment
        M_r_u_fr = dW_lat_u_fr * (q_r_fr - n_r_fr); // [N*m] Front outer unsprung mass roll moment
        M_r_u_rl = dW_lat_u_rl * (q_r_rl - n_r_rl); // [N*m] Rear inner unsprung mass roll moment
        M_r_u_rr = dW_lat_u_rr * (q_r_rr - n_r_rr); // [N*m] Rear outer unsprung mass roll moment
        
        M_r_s = M_r_s_fl + M_r_s_fr + M_r_s_rl + M_r_s_rr; // [N*m] Total sprung mass roll moment
        M_r_u = M_r_u_fl + M_r_u_fr + M_r_u_rl + M_r_u_rr; // [N*m] Total unsprung mass roll moment

        //Roll angle
        psi = (M_r_s + M_r_u + dW_lat_g_fl * n_r_fl + dW_lat_g_fr * n_r_fr + dW_lat_g_rl * n_r_rl + dW_lat_g_rr * n_r_rr
            - t_f * K_r_tot_f * (dW_lat_g_fl / (K_susp_fl + K_arb_fl) + dW_lat_g_fr / (K_susp_fr + K_arb_fr)) - t_r * K_r_tot_r * (dW_lat_g_rl / (K_susp_rl + K_arb_rl) + dW_lat_g_rr / (K_susp_rr + K_arb_rr)))
            / (K_r_tot_f * t_f * t_f + K_r_tot_r * t_r * t_r); // [rad] Roll angle
        psi_deg = psi * 180.0 / pi; // [deg] Roll angle

        //Total lateral load transfer
        dW_lat_f = psi * K_r_tot_f * t_f + (dW_lat_g_fl / (K_susp_fl + K_arb_fl) + dW_lat_g_fr / (K_susp_fr + K_arb_fr)) * K_r_tot_f; // [N] Front lateral load transfer
        dW_lat_r = psi * K_r_tot_r * t_r + (dW_lat_g_rl / (K_susp_rl + K_arb_rl) + dW_lat_g_rr / (K_susp_rr + K_arb_rr)) * K_r_tot_r; // [N] Rear lateral load transfer

        //Elastic lateral load transfer
        dW_lat_k_fl = dW_lat_f - dW_lat_g_fl; // [N] Front inner elastic lateral load transfer
        dW_lat_k_fr = dW_lat_f - dW_lat_g_fr; // [N] Front outer elastic lateral load transfer
        dW_lat_k_rl = dW_lat_r - dW_lat_g_rl; // [N] Rear inner elastic lateral load transfer
        dW_lat_k_rr = dW_lat_r - dW_lat_g_rr; // [N] Rear outer elastic lateral load transfer
    }

    void Vehicle::update_wheel_loads_and_displacements() {
        //Wheel loads

        fl.set_F_z_past(), fr.set_F_z_past(), rl.set_F_z_past(), rr.set_F_z_past();

        fl.F_z = W_fl - dW_lon_l + dW_lat_f + F_down_fl - dW_lon_drag / 2; // [N] Front inner tire vertical load
        fr.F_z = W_fr - dW_lon_r - dW_lat_f + F_down_fr - dW_lon_drag / 2; // [N] Front outer tire vertical load
        rl.F_z = W_rl + dW_lon_l + dW_lat_r + F_down_rl + dW_lon_drag / 2; // [N] Rear inner tire vertical load
        rr.F_z = W_rr + dW_lon_r - dW_lat_r + F_down_rr + dW_lon_drag / 2; // [N] Rear outer tire vertical load

        fl.set_F_z_err(), fr.set_F_z_err(), rl.set_F_z_err(), rr.set_F_z_err();

        //Wheel displacements

        w_fl = round_to((dW_lat_k_fl) / (K_susp_fl + K_arb_fl) + (F_down_fl - dW_lon_k_fl) / K_susp_fl, 5); // [m] Front inner tire vertical displacement
        w_fr = round_to((-dW_lat_k_fr) / (K_susp_fr + K_arb_fr) + (F_down_fr - dW_lon_k_fr) / K_susp_fr, 5); // [m] Front outer tire vertical displacement
        w_rl = round_to((dW_lat_k_rl) / (K_susp_rl + K_arb_rl) + (F_down_rl + dW_lon_k_rl) / K_susp_rl, 5); // [m] Rear inner tire vertical displacement
        w_rr = round_to((-dW_lat_k_rr) / (K_susp_rr + K_arb_rr) + (F_down_rr + dW_lon_k_rr) / K_susp_rr, 5); // [m] Rear outer tire vertical displacement

        //fl.delta = round_to(((delta_d_deg * delta_d_deg * vehicle_inputs.ackermann_2 + delta_d_deg * vehicle_inputs.ackermann_1 + delta_f_static) + (w_fl * w_fl * 1e6 * vehicle_inputs.bs_f_2 + w_fl * 1e3 * vehicle_inputs.bs_f_1) * 0) * pi / 180.0, 5); // [rad] Front outer wheel steering angle
        //fr.delta = round_to((-(delta_d_deg * delta_d_deg * vehicle_inputs.ackermann_2 + delta_d_deg * vehicle_inputs.ackermann_1 + delta_f_static) + (w_fr * w_fr * 1e6 * vehicle_inputs.bs_f_2 + w_fr * 1e3 * vehicle_inputs.bs_f_1) * 0) * pi / 180.0, 5); // [rad] Front inner wheel steering angle                      FUNCTION INPUT
        //rl.delta = round_to((delta_r_static + (w_rl * w_rl * vehicle_inputs.bs_r_2 + w_rl * vehicle_inputs.bs_r_1) * 0) * pi / 180.0, 5); // [rad] Rear inner wheel steering angle
        //rr.delta = round_to((-delta_r_static + (w_rr * w_rr * vehicle_inputs.bs_r_2 + w_rr * vehicle_inputs.bs_r_1) * 0) * pi / 180.0, 5);// [rad] Rear outer wheel steering angle

        fl.gamma = round_to(-psi + gamma_f_static + ((w_fl * w_fl * 1e6 * vehicle_inputs.bc_f_2 + w_fl * 1e3 * vehicle_inputs.bc_f_1) + (fl.delta * fl.delta * 180 * 180 / pi / pi * vehicle_inputs.sc_f_2 + fl.delta * 180 / pi * vehicle_inputs.sc_f_1)) * pi / 180.0, 5); // [rad] Front inner tire camber angle
        fr.gamma = round_to(psi + gamma_f_static + ((w_fr * w_fr * 1e6 * vehicle_inputs.bc_f_2 + w_fr * 1e3 * vehicle_inputs.bc_f_1) - (fr.delta * fr.delta * 180 * 180 / pi / pi * vehicle_inputs.sc_f_2 + fr.delta * 180 / pi * vehicle_inputs.sc_f_1)) * pi / 180.0, 5); // [rad] Front outer tire camber angle
        rl.gamma = round_to(-psi + gamma_r_static + (w_rl * w_rl * 1e6 * vehicle_inputs.bc_r_2 + w_rl * 1e3 * vehicle_inputs.bc_r_1) * pi / 180.0, 5); // [rad] Rear inner tire camber angle
        rr.gamma = round_to(psi + gamma_r_static + (w_rr * w_rr * 1e6 * vehicle_inputs.bc_r_2 + w_rr * 1e3 * vehicle_inputs.bc_r_1) * pi / 180.0, 5); // [rad] Rear outer tire camber angle

    }

    void Vehicle::yaw_moment() {
        //Yaw moment
        M_yaw_fl = fl.F_lat * a + fl.F_lon * t_f / 2; // [N*m] Front inner tire yaw moment
        M_yaw_fr = fr.F_lat * a - fr.F_lon * t_f / 2; // [N*m] Front outer tire yaw moment
        M_yaw_rl = -rl.F_lat * b + rl.F_lon * t_r / 2; // [N*m] Rear inner tire yaw moment
        M_yaw_rr = -rr.F_lat * b - rr.F_lon * t_r / 2; // [N*m] Rear outer tire yaw moment
        M_yaw = M_yaw_fl + M_yaw_fr + M_yaw_rl + M_yaw_rr; // [N*m] Vehicle yaw moment
    }

    // Solver function for slip ratios to comply with axle torque and bias constraints
    void Vehicle::solve_kappa() {

        //Equivalent slip ratios
        fl.set_kappa_x(), fr.set_kappa_x(), rl.set_kappa_x(), rr.set_kappa_x();

        //Longitudinal Pacejka
        fl.set_F_x(), fr.set_F_x(), rl.set_F_x(), rr.set_F_x();

        //Longitudinal modified Nicolas-Comstock
        fl.set_F_x_comb(lon_sign), fr.set_F_x_comb(lon_sign), rl.set_F_x_comb(lon_sign), rr.set_F_x_comb(lon_sign);

        //Torques
        fl.set_T(), fr.set_T(), rl.set_T(), rr.set_T();

        auto solve_diffs = [&](diff md, diff sd, Tire& t1, Tire& t2, Tire& t3, Tire& t4) {
            //md = main differential, sd = secondary differential
            //t1 = main tire, t2 = secondary tire on the same axle, t3 and t4 = tires on the other axle

            double t1_tar_num = (m * a_lon_des * g + F_drag + fl.F_y_comb * sin(fl.delta) + fr.F_y_comb * sin(fr.delta) - rl.F_y_comb * sin(rl.delta) - rr.F_y_comb * sin(rr.delta) + fl.F_rr * cos(fl.delta) + fr.F_rr * cos(fr.delta) + rl.F_rr * cos(rl.delta) + rr.F_rr * cos(rr.delta)); //Numerator for the longitudinal force target of the main tire
			double mTBR = (pedals_input == Pedals_input::Braking ? md.bTBR : md.dTBR); //Torque bias ratio of the main differential
			double sTBR = (pedals_input == Pedals_input::Braking ? sd.bTBR : sd.dTBR); //Torque bias ratio of the secondary differential

            //Main tire

            double lock_mdT = 0;
            double slip_mdT = 0;

            double lock_sdT = 0;
            double slip_sdT = 0;

            if (md.lock == Actuator_lock::Tracloc) {
                slip_mdT = abs(t1.T + t2.T) * md.k_lock + md.preload;
            }
            else {
                slip_mdT = (abs(t1.T + t2.T) + md.preload) * (mTBR - 1) / (mTBR + 1);
            }

            if (md.lock != Actuator_lock::Open) {
                if (abs(t2.F_z - t1.F_z) <= 1) {
                    mTBR = 1;
                }
                else if (pedals_input == Pedals_input::Braking) { 
                    t2.kappa = 1 - t2.V_x / t1.V_x * t1.r / t2.r * (1 - t1.kappa); 
                }
                else { 
                    t2.kappa = 1 - t1.V_x / t2.V_x * t2.r / t1.r * (1 - t1.kappa); 
                }
                t2.set_kappa_x();
                t2.set_F_x();
                t2.set_F_x_comb(lon_sign);
                t2.set_T();
            }

			lock_mdT = abs(t1.T - t2.T);

			mdT = slip_mdT * tanh(lock_mdT / slip_mdT) * lon_sign;

            if (sd.lock == Actuator_lock::Tracloc) {
                slip_sdT = abs(t3.T + t4.T) * sd.k_lock + sd.preload;
            }
            else {
                slip_sdT = (abs(t3.T + t4.T) + sd.preload) * (sTBR - 1) / (sTBR + 1);
            }

            if (sd.lock != Actuator_lock::Open) {
                if (abs(t3.F_z - t4.F_z) <= 1) {
                    sTBR = 1;
                }
                else if (pedals_input == Pedals_input::Braking) { 
                    t4.kappa = 1 - t4.V_x / t3.V_x * t3.r / t4.r * (1 - t3.kappa); 
                }
                else { 
                    t4.kappa = 1 - t3.V_x / t4.V_x * t4.r / t3.r * (1 - t3.kappa); 
                }
                t4.set_kappa_x();
                t4.set_F_x();
                t4.set_F_x_comb(lon_sign);
                t4.set_T();
            }

            lock_sdT = abs(t3.T - t4.T);

            sdT = std::min(slip_sdT, lock_sdT) * lon_sign;
                    
            if (bias > 0.5) {
                t1.F_x_comb_tar = (t1_tar_num - mdT * cos(t2.delta) / t2.r + (-sdT - mdT * (1 - bias) / bias) * cos(t3.delta) / (2 * t3.r) + (sdT - mdT * (1 - bias) / bias) * cos(t4.delta) / (2 * t4.r))
                    / (cos(t1.delta) + cos(t2.delta) * t1.r / t2.r + cos(t3.delta) * t1.r / t3.r * (1 - bias) / bias + cos(t4.delta) * t1.r / t4.r * (1 - bias) / bias);
            }

            else if (bias <= 0.5) {
                t1.F_x_comb_tar = (t1_tar_num - mdT * cos(t2.delta) / t2.r + (-sdT - mdT * bias / (1 - bias)) * cos(t3.delta) / (2 * t3.r) + (sdT - mdT * bias / (1 - bias)) * cos(t4.delta) / (2 * t4.r))
                    / (cos(t1.delta) + cos(t2.delta) * t1.r / t2.r + cos(t3.delta) * t1.r / t3.r * bias / (1 - bias) + cos(t4.delta) * t1.r / t4.r * bias / (1 - bias));
            }
     
            brents_method(t1);

			//Secondary tire on the same axle

            t2.F_x_comb_tar = (t1.T + mdT) / t2.r;
            brents_method(t2);

            //Third and fourth tires on different axle

            if (bias > 0.5) {
                t3.F_x_comb_tar = ((1 - bias) * (t1.T + t2.T) - sdT * bias) / (2 * t3.r * bias);
                t4.F_x_comb_tar = ((1 - bias) * (t1.T + t2.T) + sdT * bias) / (2 * t4.r * bias);
            }
            else if (bias <= 0.5) {
                t3.F_x_comb_tar = (bias * (t1.T + t2.T) - sdT * (1 - bias)) / (2 * t3.r * (1 - bias));
                t4.F_x_comb_tar = (bias * (t1.T + t2.T) + sdT * (1 - bias)) / (2 * t4.r * (1 - bias));
            }

            brents_method(t3);
            brents_method(t4);

            
            

               

        };

        

        if (iter != 0 && pedals_input != Pedals_input::Coasting) {

            if (bias > 0.5) {
                if (fl.F_z < fr.F_z) {
                    if (rl.F_z < rr.F_z) {
                        solve_diffs(front_diff, rear_diff, fl, fr, rl, rr);
                    }
                    else {
                        solve_diffs(front_diff, rear_diff, fl, fr, rr, rl);
                    }
                }
                else {
                    if (rr.F_z < rl.F_z) {
                        solve_diffs(front_diff, rear_diff, fr, fl, rr, rl);
                    }
                    else {
						solve_diffs(front_diff, rear_diff, fr, fl, rl, rr);
                    }
                }
            }
            else if (bias <= 0.5) {
                if (rl.F_z < rr.F_z) {
                    if (fl.F_z < fr.F_z) {
                        solve_diffs(rear_diff, front_diff, rl, rr, fl, fr);
                    }
                    else {
                        solve_diffs(rear_diff, front_diff, rl, rr, fr, fl);
                    }
                }
                else {
                    if (fr.F_z < fl.F_z) {
                        solve_diffs(rear_diff, front_diff, rr, rl, fr, fl);
                    }
                    else {
                        solve_diffs(rear_diff, front_diff, rr, rl, fl, fr);
                    }
                }
            }
        }

    }

    // Brent's method for finding root of f(x) = target
    void Vehicle::brents_method(Tire& tire) {
        double tol = 0.01; int max_iter = 100;
        double a = -0.1;
        double b = 1.0;

        if (iter >= 5) {
            a = tire.kappa - 0.1;
            b = tire.kappa + 0.1;
        }

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

        double tolerance = 1e-3;
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
        vehicle_outputs.psi_deg = -psi_deg;
        vehicle_outputs.phi_deg = phi_deg;
        vehicle_outputs.iter = iter;
        vehicle_outputs.bias_now = bias_now * 100.0;
        vehicle_outputs.V = V * 3.6;
        vehicle_outputs.R = R;

        vehicle_outputs.F_z_fl = fl.F_z;
        vehicle_outputs.F_z_fr = fr.F_z;
        vehicle_outputs.F_z_rl = rl.F_z;
        vehicle_outputs.F_z_rr = rr.F_z;

        vehicle_outputs.F_x_comb_fl = fl.F_x_comb;
        vehicle_outputs.F_x_comb_fr = fr.F_x_comb;
        vehicle_outputs.F_x_comb_rl = rl.F_x_comb;
        vehicle_outputs.F_x_comb_rr = rr.F_x_comb;

        vehicle_outputs.F_y_comb_fl = fl.F_y_comb;
        vehicle_outputs.F_y_comb_fr = fr.F_y_comb;
        vehicle_outputs.F_y_comb_rl = rl.F_y_comb;
        vehicle_outputs.F_y_comb_rr = rr.F_y_comb;

        vehicle_outputs.F_lon_fl = fl.F_lon;
        vehicle_outputs.F_lon_fr = fr.F_lon;
        vehicle_outputs.F_lon_rl = rl.F_lon;
        vehicle_outputs.F_lon_rr = rr.F_lon;

        vehicle_outputs.F_lat_fl = fl.F_lat;
        vehicle_outputs.F_lat_fr = fr.F_lat;
        vehicle_outputs.F_lat_rl = rl.F_lat;
        vehicle_outputs.F_lat_rr = rr.F_lat;

        vehicle_outputs.kappa_fl = fl.kappa * 100.0;
        vehicle_outputs.kappa_fr = fr.kappa * 100.0;
        vehicle_outputs.kappa_rl = rl.kappa * 100.0;
        vehicle_outputs.kappa_rr = rr.kappa * 100.0;

        vehicle_outputs.alpha_fl = fl.alpha * 180 / pi;
        vehicle_outputs.alpha_fr = fr.alpha * 180 / pi;
        vehicle_outputs.alpha_rl = rl.alpha * 180 / pi;
        vehicle_outputs.alpha_rr = rr.alpha * 180 / pi;

        vehicle_outputs.T_fl = fl.T;
        vehicle_outputs.T_fr = fr.T;
        vehicle_outputs.T_rl = rl.T;
        vehicle_outputs.T_rr = rr.T;

#ifdef _DEBUG   
        vehicle_outputs.debug1 = rl.F_x_comb_tar;
        vehicle_outputs.debug2 = rr.F_x_comb_tar;
        vehicle_outputs.debug3 = rl.T / rr.T;
        vehicle_outputs.debug4 = dW_lat_r;

		vehicle_outputs.brents_single = brents_iter_single;
		vehicle_outputs.brents_total = brents_iter_total;
		vehicle_outputs.golden_single = golden_iter_single;
		vehicle_outputs.golden_total = golden_iter_total;
        vehicle_outputs.iter_total = iter_total;
#endif
#ifndef _DEBUG
        if (cancel_run) {
            throw std::runtime_error("Single run simulation failed. The vehicle is not able to reach the desired conditions");
        }
#endif
    };

    void Vehicle::refresh() {
        lon_sign = 1, lat_sign = 1;
        BB = 0.0, DB = 0.0, bias = 0.0, bias_first = 0.0, bias_now = 0.0;
        W = 0.0, W_fl = 0.0, W_fr = 0.0, W_rl = 0.0, W_rr = 0.0;
        m_u = 0.0;
        m_s = 0.0;
        a = 0.0, b = 0.0, a_s = 0.0, b_s = 0.0;
        w_fl = 0.0, w_fr = 0.0, w_rl = 0.0, w_rr = 0.0;
        beta = 0.0, R_a = 0.0, S_f = 0.0, S_r = 0.0;
        F_lat = 0.0, a_lat = 0.0;
        F_lon = 0.0, a_lon = 0.0, a_lon_des = 0.0;
        F_rad = 0.0, a_rad = 0.0;
        h_CG_s = 0.0, h_CG_u_fl = 0.0, h_CG_u_fr = 0.0, h_CG_u_rl = 0.0, h_CG_u_rr = 0.0, h_CG_u = 0.0;
        h_r_f = 0.0, h_r_r = 0.0, off_r_f = 0.0, off_r_r = 0.0, n_r_fl = 0.0, n_r_fr = 0.0, n_r_rl = 0.0, n_r_rr = 0.0,
                    p_r_fl = 0.0, p_r_fr = 0.0, p_r_rl = 0.0, p_r_rr = 0.0, q_r_fl = 0.0, q_r_fr = 0.0, q_r_rl = 0.0, q_r_rr = 0.0;
        h_p_l = 0.0, h_p_r = 0.0, n_p_fl = 0.0, n_p_fr = 0.0, n_p_rl = 0.0, n_p_rr = 0.0,
                    p_p_fl = 0.0, p_p_fr = 0.0, p_p_rl = 0.0, p_p_rr = 0.0, q_p_fl = 0.0, q_p_fr = 0.0, q_p_rl = 0.0, q_p_rr = 0.0;
        k_r_C = 0.0, k_r_C_f = 0.0, k_r_C_r = 0.0, k_p_C = 0.0, k_p_C_i = 0.0, k_p_C_o = 0.0;
        MR_s_fl = 0.0, MR_s_fr = 0.0, MR_s_rl = 0.0, MR_s_rr = 0.0, MR_arb_fl = 0.0, MR_arb_fr = 0.0, MR_arb_rl = 0.0, MR_arb_rr = 0.0;
        K_susp_fl = 0.0, K_susp_fr = 0.0, K_susp_rl = 0.0, K_susp_rr = 0.0, K_arb_fl = 0.0, K_arb_fr = 0.0, K_arb_rl = 0.0, K_arb_rr = 0.0;
        K_r_C_f = 0.0, K_r_C_r = 0.0, K_r_tot_f = 0.0, K_r_tot_r = 0.0;
        K_p_C_l = 0.0, K_p_C_r = 0.0, K_p_tot_l = 0.0, K_p_tot_r = 0.0;
        V_skid = 0.0, V_kmh = 0.0;
        F_down = 0.0, F_down_x = 0.0, F_down_y = 0.0, F_down_fl = 0.0, F_down_fr = 0.0, F_down_rl = 0.0, F_down_rr = 0.0;
        F_drag = 0.0, F_drag_z = 0.0, F_drag_y = 0.0, h_drag = 0.0;
        dW_lon_s_fl = 0.0, dW_lon_s_fr = 0.0, dW_lon_s_rl = 0.0, dW_lon_s_rr = 0.0, dW_lon_u_fl = 0.0, dW_lon_u_fr = 0.0, dW_lon_u_rl = 0.0, dW_lon_u_rr = 0.0,
                    dW_lon_g_fl = 0.0, dW_lon_g_fr = 0.0, dW_lon_g_rl = 0.0, dW_lon_g_rr = 0.0;
        M_p_s_fl = 0.0, M_p_s_fr = 0.0, M_p_s_rl = 0.0, M_p_s_rr = 0.0, M_p_u_fl = 0.0, M_p_u_fr = 0.0, M_p_u_rl = 0.0, M_p_u_rr = 0.0, M_p_s = 0.0, M_p_u = 0.0, T = 0.0;
        phi = 0.0, phi_deg = 0.0;
        M_p_drag = 0.0, dW_lon_drag = 0.0;
        dW_lon_l = 0.0, dW_lon_r = 0.0;
        dW_lon_k_fl = 0.0, dW_lon_k_fr = 0.0, dW_lon_k_rl = 0.0, dW_lon_k_rr = 0.0;
        dW_lat_s_fl = 0.0, dW_lat_s_fr = 0.0, dW_lat_s_rl = 0.0, dW_lat_s_rr = 0.0, dW_lat_u_fl = 0.0, dW_lat_u_fr = 0.0, dW_lat_u_rl = 0.0, dW_lat_u_rr = 0.0,
                    dW_lat_g_fl = 0.0, dW_lat_g_fr = 0.0, dW_lat_g_rl = 0.0, dW_lat_g_rr = 0.0;
        M_r_s_fl = 0.0, M_r_s_fr = 0.0, M_r_s_rl = 0.0, M_r_s_rr = 0.0, M_r_u_fl = 0.0, M_r_u_fr = 0.0, M_r_u_rl = 0.0, M_r_u_rr = 0.0, M_r_s = 0.0, M_r_u = 0.0;
        psi = 0.0, psi_deg = 0.0;
        dW_lat_f = 0.0, dW_lat_r = 0.0;
        dW_lat_k_fl = 0.0, dW_lat_k_fr = 0.0, dW_lat_k_rl = 0.0, dW_lat_k_rr = 0.0;
        M_yaw_fl = 0.0, M_yaw_fr = 0.0, M_yaw_rl = 0.0, M_yaw_rr = 0.0, M_yaw = 0.0;
        brents_iter_single = 0, golden_iter_single = 0;
        cancel_run = 0, invert_run = 0;
    }

    void Vehicle::YMD(YMD_Carrier& carrier) {

		Vehicle copy = *this; // Create a copy of the current vehicle state to preserve original values during YMD

		brents_iter_total = 0;
		golden_iter_total = 0;
        iter_total = 0;

		carrier.max_a_lat = carrier.max_M_yaw = 0.0; // Reset max lateral acceleration and yaw moment for YMD
        max_beta = vehicle_inputs.max_beta;
        num_beta = vehicle_inputs.num_beta - 1;
        con_beta = vehicle_inputs.con_beta;
        max_delta_d = vehicle_inputs.max_delta_d;
        num_delta_d = vehicle_inputs.num_delta_d - 1;
        con_delta_d = vehicle_inputs.con_delta_d;

        copy.force_a_lon = true;

        if (copy.a_lon_des < 0) { copy.pedals_input = Pedals_input::Braking; }
        else { copy.pedals_input = Pedals_input::Driving; }

        double control = 0.0;
        double stability = 0.0;
        double delta_d_past = 0.0;
		double beta_past = 0.0;

        std::vector<double> BETA_ISO(0);
        std::vector<double> DELTA_ISO(0);

        //delta isolines
        std::vector <std::vector<double>> A_LAT_ISODELTA_2(0);
        std::vector <std::vector<double>> A_LON_ISODELTA_2(0);
        std::vector <std::vector<double>> M_YAW_ISODELTA_2(0);
        std::vector <std::vector<double>> STABILITY_2(0);
        std::vector <std::vector<double>> BETA_ISODELTA_2(0);
        std::vector <std::vector<int>> CANCEL_ISODELTA_2(0);

        std::vector<double> A_LAT_ISODELTA(0);
		std::vector<double> A_LON_ISODELTA(0);
        std::vector<double> M_YAW_ISODELTA(0);
        std::vector<double> STABILITY(0);
        std::vector<double> BETA_ISODELTA(0);
        std::vector<int> CANCEL_ISODELTA(0);


        for (double j = 0; j <= num_delta_d; j++) {

            copy.delta_d_deg = max_delta_d * copysign(pow(abs(2 * j / num_delta_d - 1), con_delta_d), 2 * j / num_delta_d - 1);

			A_LAT_ISODELTA.clear();
			A_LON_ISODELTA.clear();
			M_YAW_ISODELTA.clear();
			STABILITY.clear();
            BETA_ISODELTA.clear();
            CANCEL_ISODELTA.clear();

            DELTA_ISO.push_back(copy.delta_d_deg);

            for (int i = 0; i <= num_beta * 2; i++) {

                beta_past = copy.beta_deg;
                copy.beta_deg = max_beta * copysign(pow(abs(2 * i / num_beta / 2 - 1), con_beta), 2 * i / num_beta / 2 - 1);
                
                BETA_ISODELTA.push_back(copy.beta_deg);

                copy.solver();
				brents_iter_total += copy.brents_iter_single;
				golden_iter_total += copy.golden_iter_single;
				iter_total += copy.iter;

                A_LAT_ISODELTA.push_back(round_to(copy.a_lat, 2));
                A_LON_ISODELTA.push_back(round_to(copy.a_lon, 2));
                M_YAW_ISODELTA.push_back(copy.M_yaw);
                
                CANCEL_ISODELTA.push_back(copy.cancel_run);

                if (i != 0) stability = (M_YAW_ISODELTA[i] - M_YAW_ISODELTA[i - 1]) / (copy.beta_deg - beta_past);
                STABILITY.push_back(stability);

				if (abs(copy.a_lat) > carrier.max_a_lat) {
					carrier.max_a_lat = round_to(abs(copy.a_lat), 1); 
                    carrier.max_a_lat += (remainder(carrier.max_a_lat, 0.2) == 0.0 ? 0.2 : 0.1);
                }
                if (abs(copy.M_yaw) > carrier.max_M_yaw) { 
                    carrier.max_M_yaw = round_to(abs(copy.M_yaw) / 10000.0, 1) * 10000.0; 
                }
            }

			A_LAT_ISODELTA_2.push_back(A_LAT_ISODELTA);
			A_LON_ISODELTA_2.push_back(A_LON_ISODELTA);
			M_YAW_ISODELTA_2.push_back(M_YAW_ISODELTA);
            BETA_ISODELTA_2.push_back(BETA_ISODELTA);
            CANCEL_ISODELTA_2.push_back(CANCEL_ISODELTA);
			STABILITY_2.push_back(STABILITY);
        }

		carrier.a_lat_isodelta = A_LAT_ISODELTA_2;
		carrier.a_lon_isodelta = A_LON_ISODELTA_2;
        carrier.M_yaw_isodelta = M_YAW_ISODELTA_2;
        carrier.beta_isodelta = BETA_ISODELTA_2;
        carrier.cancel_isodelta = CANCEL_ISODELTA_2;
		carrier.stability = STABILITY_2;
		carrier.delta_iso = DELTA_ISO;

        copy.beta_deg = vehicle_inputs.beta_deg; // Reset to original value after YMD
        copy.delta_d_deg = vehicle_inputs.delta_d_deg; // Reset to original value after YMD

        //beta isolines
        std::vector <std::vector<double>> A_LAT_ISOBETA_2(0);
		std::vector <std::vector<double>> A_LON_ISOBETA_2(0);
        std::vector <std::vector<double>> M_YAW_ISOBETA_2(0);
        std::vector <std::vector<double>> CONTROL_2(0);
        std::vector <std::vector<double>> DELTA_ISOBETA_2(0);
        std::vector <std::vector<int>> CANCEL_ISOBETA_2(0);

        std::vector<double> A_LAT_ISOBETA(0);
		std::vector<double> A_LON_ISOBETA(0);
        std::vector<double> M_YAW_ISOBETA(0);
        std::vector<double> CONTROL(0);
        std::vector<double> DELTA_ISOBETA(0);
        std::vector<int> CANCEL_ISOBETA(0);

        for (double j = 0; j <= num_beta; j++) {

            copy.beta_deg = max_beta * copysign(pow(abs(2 * j / num_beta - 1), con_beta), 2 * j / num_beta - 1);

            A_LAT_ISOBETA.clear();
			A_LON_ISOBETA.clear();
			M_YAW_ISOBETA.clear();
			CONTROL.clear();
            DELTA_ISOBETA.clear();
            CANCEL_ISOBETA.clear();

            BETA_ISO.push_back(copy.beta_deg);

            for (int i = 0; i <= num_delta_d * 2; i += 1) {

                delta_d_past = copy.delta_d_deg;
                copy.delta_d_deg = max_delta_d * copysign(pow(abs(2 * i / num_delta_d / 2 - 1), con_delta_d), 2 * i / num_delta_d / 2 - 1);

                DELTA_ISOBETA.push_back(copy.delta_d_deg);

                copy.solver();
                brents_iter_total += copy.brents_iter_single;
				golden_iter_total += copy.golden_iter_single;
				iter_total += copy.iter;

                A_LAT_ISOBETA.push_back(round_to(copy.a_lat, 2));
				A_LON_ISOBETA.push_back(round_to(copy.a_lon, 2));
                M_YAW_ISOBETA.push_back(copy.M_yaw);
                
                CANCEL_ISOBETA.push_back(copy.cancel_run);

                if (i != 0) control = (M_YAW_ISOBETA[i] - M_YAW_ISOBETA[i - 1]) / (copy.delta_d_deg - delta_d_past);
				CONTROL.push_back(control);
            }

            A_LAT_ISOBETA_2.push_back(A_LAT_ISOBETA);
			A_LON_ISOBETA_2.push_back(A_LON_ISOBETA);
            M_YAW_ISOBETA_2.push_back(M_YAW_ISOBETA);
            DELTA_ISOBETA_2.push_back(DELTA_ISOBETA);
            CANCEL_ISOBETA_2.push_back(CANCEL_ISOBETA);
			CONTROL_2.push_back(CONTROL);

            
        }

        carrier.a_lat_isobeta = A_LAT_ISOBETA_2;
		carrier.a_lon_isobeta = A_LON_ISOBETA_2;
        carrier.M_yaw_isobeta = M_YAW_ISOBETA_2;
        carrier.delta_isobeta = DELTA_ISOBETA_2;
        carrier.cancel_isobeta = CANCEL_ISOBETA_2;
		carrier.control = CONTROL_2;
		carrier.beta_iso = BETA_ISO;


		copy.beta_deg = vehicle_inputs.beta_deg; // Reset to original value after YMD
		copy.delta_d_deg = vehicle_inputs.delta_d_deg; // Reset to original value after YMD
        copy.solver();

        carrier.single_run.delta = copy.delta_d_deg;
        carrier.single_run.beta = copy.beta_deg;
        carrier.single_run.a_lat = copy.a_lat;
        carrier.single_run.a_lon = copy.a_lon;
        carrier.single_run.M_yaw = copy.M_yaw;
        carrier.single_run.cancel = copy.cancel_run;
    }