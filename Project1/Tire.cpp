#include "Tire.h"
#include <cmath>
#include <iostream>
#include "Inputs.h"
#include "Outputs.h"

Tire::Tire() {};

void Tire::set_position(char axle, char side) {
    AXLE = (axle == 'F') ? 1 : -1; // 1 for front axle, -1 for rear axle
    SIDE = (side == 'R') ? 1 : -1; // 1 for right tire, -1 for left tire
}

void Tire::set_parameters(Tire_inputs& input) {

    //Longitudinal parameters
    p_Cx1 = input.p_Cx1;
    p_Dx1 = input.p_Dx1;
    p_Dx2 = input.p_Dx2;
    p_Dx3 = input.p_Dx3;
    p_Ex1 = input.p_Ex1;
    p_Ex2 = input.p_Ex2;
    p_Ex3 = input.p_Ex3;
    p_Ex4 = input.p_Ex4;
    p_Kx1 = input.p_Kx1;
    p_Kx2 = input.p_Kx2;
    p_Kx3 = input.p_Kx3;
    p_Hx1 = input.p_Hx1;
    p_Hx2 = input.p_Hx2;
    p_Vx1 = input.p_Vx1;
    p_Vx2 = input.p_Vx2;

    //Lateral parameters
    p_Cy1 = input.p_Cy1;
    p_Dy1 = -input.p_Dy1;
    p_Dy2 = -input.p_Dy2;
    p_Dy3 = input.p_Dy3;
    p_Ey1 = input.p_Ey1;
    p_Ey2 = input.p_Ey2;
    p_Ey3 = input.p_Ey3;
    p_Ey4 = input.p_Ey4;
    p_Ky1 = -input.p_Ky1;
    p_Ky2 = input.p_Ky2;
    p_Ky3 = input.p_Ky3;
    p_Hy1 = input.p_Hy1;
    p_Hy2 = input.p_Hy2;
    p_Hy3 = input.p_Hy3;
    p_Vy1 = input.p_Vy1;
    p_Vy2 = input.p_Vy2;
    p_Vy3 = input.p_Vy3;
    p_Vy4 = input.p_Vy4;

    //Other parameters
    r_u = input.r_u / 1000.0;
    a_rr = input.a_rr;
    b_rr = input.b_rr;
    F_z_o = input.F_z_o;
    K_T = input.K_T * 1000.0;
}

void Tire::set_alpha(double lat_sign) {
    alpha = (delta - theta) * AXLE * SIDE;
    //if (lat_sign < 0) {alpha = -alpha;}
}

void Tire::set_K_T() { K_T = K_T; } // [N/m] Tire stiffness     FUNCTION INPUT

void Tire::set_r() { r = r_u - F_z / K_T; } // [m] Tire radius

void Tire::set_Pacejka() {
    df_z = (F_z - F_z_o) / F_z_o; // [-] Normalized change in nominal wheel load

    // Lateral Pacejka factors
    C_y = p_Cy1; // [-] Lateral shape factor C
    mu_y = (p_Dy1 + p_Dy2 * df_z) * (1 - p_Dy3 * gamma * gamma) / 2; // [-] Lateral friction coefficient
    D_y = mu_y * F_z; // [-] Lateral peak factor D
    E_y = (p_Ey1 + p_Ey2 * df_z) * (1 - (p_Ey3 + p_Ey4 * gamma)); // [-] Lateral curvature factor E
    K_y_alpha = 1000 * p_Ky1 * F_z_o * sin(2 * atan(F_z / (1000 * p_Ky2 * F_z_o))) * (1 - p_Ky3 * abs(gamma)); // [N/rad] Lateral slip stiffness
    B_y = K_y_alpha / (C_y * D_y + 1e-10); // [-] Lateral stiffness factor B
    S_Vy_gamma = F_z * (p_Vy3 + p_Vy4 * df_z) * gamma; // [N] Vertical shift due to camber
    S_Vy = (F_z * (p_Vy1 + p_Vy2 * df_z) + S_Vy_gamma); // [N] Vertical shift
    S_Hy = ((p_Hy1 + p_Hy2 * df_z) + (p_Hy3 * gamma)); // [rad] Horizontal shift
    alpha_y = (alpha + S_Hy); // [rad] Equivalent slip angle

    //Longitudinal Pacejka factors
    C_x = p_Cx1; // [-] Longitudinal shape factor C
    mu_x = (p_Dx1 + p_Dx2 * df_z) * (1 - p_Dx3 * gamma * gamma) / 2; // [-] Longitudinal friction coefficient
    D_x = mu_x * F_z; // [-] Longitudinal peak factor D
    E_x = (p_Ex1 + p_Ex2 * df_z + p_Ex3 * df_z * df_z) * (1 - p_Ex4 * copysign(1.0, kappa)); // [-] Longitudinal curvature factor E
    K_x_kappa = F_z * (p_Kx1 + p_Kx2 * df_z) * exp(p_Kx3 * df_z); // [N/rad] Longitudinal slip stiffness
    B_x = K_x_kappa / (C_x * D_x); // [-] Longitudinal stiffness factor B
    S_Hx = (p_Hx1 + p_Hx2 * df_z) * 1e-10; // [rad] Horizontal shift
    S_Vx = F_z * (p_Vx1 + p_Vx2 * df_z) * 0.0; // [N] Vertical shift
}

void Tire::set_kappa_x() {
    kappa_x = kappa + S_Hx; // [-] Equivalent slip ratio
}

void Tire::set_F_x() {
    F_x = D_x * sin(C_x * atan(B_x * ((1 - E_x) * kappa_x + E_x / B_x * atan(B_x * kappa_x)))); // [N] Tire longitudinal force
}

void Tire::set_F_y(double V_ratio) {
    F_y = S_Vy + D_y * sin(C_y * atan(B_y * ((1 - E_y) * alpha_y + E_y / B_y * atan(B_y * alpha_y)))) * V_ratio; // [N] Tire lateral force        
}

void Tire::set_F_x_comb(int lon_sign) {
    F_x_comb = lon_sign * F_x * abs(F_y) / sqrt(kappa_x * kappa_x * F_y * F_y + F_x * F_x * tan(alpha_y) * tan(alpha_y)) * sqrt((1 - abs(kappa_x)) * (1 - abs(kappa_x)) * cos(alpha_y) * cos(alpha_y) * F_x * F_x + kappa_x * kappa_x * K_y_alpha * K_y_alpha) / (K_y_alpha); // [N] Tire combined longitudinal force
}

void Tire::set_F_y_comb(double lat_sign) {
    F_y_comb = SIDE * F_y * abs(F_x) / sqrt(kappa_x * kappa_x * F_y * F_y + F_x * F_x * tan(alpha_y) * tan(alpha_y)) * sqrt((1 - abs(kappa_x)) * (1 - abs(kappa_x)) * cos(alpha_y) * cos(alpha_y) * F_y * F_y + sin(alpha_y) * sin(alpha_y) * K_x_kappa * K_x_kappa) / (K_x_kappa * cos(alpha_y)); // [N] Tire combined lateral force
	//if (lat_sign < 0) { F_y_comb = -F_y_comb; }
}

void Tire::set_T() { T = F_x_comb * r; }

void Tire::set_T_r(int lon_sign, Actuator_type brakes, Actuator_type diff) {
    if ((lon_sign > 0 && diff == Actuator_type::Inboard) || (lon_sign < 0 && brakes == Actuator_type::Inboard)) { T_r = T * lon_sign; } // [N*m] Reaction torque
    else { T_r = 0; }
}

void Tire::set_F_lat() { F_lat = F_y_comb * cos(delta) + AXLE * (F_x_comb - F_rr) * sin(delta); } // [N] Lateral force        

void Tire::set_F_lon() { F_lon = -AXLE * F_y_comb * sin(delta) + (F_x_comb - F_rr) * cos(delta); } // [N] Longitudinal force

void Tire::set_F_rad() { F_rad = F_lat * cos(theta) - AXLE * F_lon * sin(theta); } // [N] Cornering radial force

void Tire::set_V_x(double V, double R_v) { V_x = V * R / R_v * cos(alpha); } // [m/s] Tire longitudinal speed

void Tire::set_F_rr(double V) { F_rr = (a_rr + b_rr * V * V * 1E-4) * F_z; } // [N] Longitudinal rolling resistance force

void Tire::set_F_z_past() { F_z_past = F_z; } // [N] Wheel load on previous iteration

void Tire::set_F_z_err() { F_z_err = F_z - F_z_past; } // [N] Wheel load variation between iterations
