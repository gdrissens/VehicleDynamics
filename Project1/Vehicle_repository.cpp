#include "Vehicle_repository.h"


void Vehicle_repository::upgrade_version(Vehicle_inputs& inputs) {
	// Implement logic to upgrade older versions of the configuration to the current version
	// This may involve setting default values for new fields, converting units, etc.
	if (inputs.version < CURRENT_VERSION) {
		// Example: If a new field was added in version 1, set a default value for it
		if (inputs.version < 1) {
			// Set default values for any new fields added in version 1
		}
		// Add more upgrade logic as needed for future versions
		inputs.version = CURRENT_VERSION; // Update version after upgrading
	}
}

void Vehicle_repository::validate(const Vehicle_inputs& inputs) {
	// Implement validation logic for the vehicle configuration
	// Check for required fields, value ranges, and consistency

	upgrade_version(const_cast<Vehicle_inputs&>(inputs)); // Upgrade version if needed

	if (inputs.R_min <= 0) {
		throw ("Minimum turning radius must be greater than zero.");
	}
	if (inputs.V_input <= 0) {
		throw ("Input velocity must be greater than zero.");
	}
	if (abs(inputs.kappa_des) > 100) {
		throw ("Slip ratio must be between -100% and 100%.");
	}
	if (inputs.BB_input < 0 || inputs.BB_input > 100) {
		throw ("Break bias must be between 0% and 100%.");
	}
	if (inputs.DB_input < 0 || inputs.DB_input > 100) {
		throw ("Drive bias must be between 0% and 100%.");
	}
	if (inputs.m <= 0) {
		throw ("Mass must be greater than zero.");
	}
	if (inputs.x < 0 || inputs.x > 100) {
		throw ("Mass longitudinal distribution must be between 0% and 100%.");
	}
	if (inputs.y < 0 || inputs.y > 100) {
		throw ("Mass lateral distribution must be be between 0% and 100%.");
	}
	if (inputs.L <= 0) {
		throw ("Wheelbase must be greater than zero.");
	}
	if (inputs.t_f <= 0) {
		throw ("Front track length must be greater than zero.");
	}
	if (inputs.t_r <= 0) {
		throw ("Rear track length must be greater than zero.");
	}
	if (inputs.h_CG <= 0) {
		throw ("Center of gravity height must be greater than zero.");
	}
	if (inputs.m_u_fi <= 0 || inputs.m_u_fo <= 0 || inputs.m_u_ri <= 0 || inputs.m_u_ro <= 0) {
		throw ("Unsprung masses must be greater than zero.");
	}
	if (inputs.k_susp_f <= 0) {
		throw ("Front suspension stiffness must be greater than zero.");
	}
	if (inputs.k_susp_r <= 0) {
		throw ("Rear suspension stiffness must be greater than zero.");
	}
	if (inputs.k_r_C_deg <= 0) {
		throw ("Chassis torsional roll stiffness must be greater than zero.");
	}
	if (inputs.k_r_C_dist < 0 || inputs.k_r_C_dist > 100) {
		throw ("Chassis torsional roll stiffness distribution must be between 0% and 100%.");
	}
	if (inputs.k_p_C_deg <= 0) {
		throw ("Chassis torsional pitch stiffness must be greater than zero.");
	}
	if (inputs.k_p_C_dist < 0 || inputs.k_p_C_dist > 100) {
		throw ("Chassis torsional pitch stiffness distribution must be between 0% and 100%.");
	}
	if (inputs.f_arb_1 <= 0 || inputs.f_arb_2 <= 0 || inputs.f_arb_3 <= 0 || inputs.f_arb_4 <= 0 || inputs.f_arb_5 <= 0) {
		throw ("Front anti-rol bar stiffnesses must be greater than zero.");
	}
	if (inputs.r_arb_1 <= 0 || inputs.r_arb_2 <= 0 || inputs.r_arb_3 <= 0 || inputs.r_arb_4 <= 0 || inputs.r_arb_5 <= 0) {
		throw ("Rear anti-rol bar stiffnesses must be greater than zero.");
	}
	if (inputs.front_tires_selection.empty() || inputs.rear_tires_selection.empty()) {
		throw ("Tire selections cannot be empty.");
	}

	// Add more validation checks as needed
}