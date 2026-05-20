#include "Vehicle_repository.h"


void Vehicle_repository::upgrade_version(Vehicle_inputs& vehicle_inputs) {
	// Implement logic to upgrade older versions of the configuration to the current version
	// This may involve setting default values for new fields, converting units, etc.
	if (vehicle_inputs.version < CURRENT_VERSION) {
		// Example: If a new field was added in version 1, set a default value for it
		if (vehicle_inputs.version < 1) {
			// Set default values for any new fields added in version 1
		}
		// Add more upgrade logic as needed for future versions
		vehicle_inputs.version = CURRENT_VERSION; // Update version after upgrading
	}
}

void Vehicle_repository::validate(const Vehicle_inputs& vehicle_inputs) {
	// Implement validation logic for the vehicle configuration
	// Check for required fields, value ranges, and consistency

	//Vehicle inputs
	if (vehicle_inputs.R <= 0) {
		throw std::runtime_error("Cornering radius must be greater than zero.");
	}
	if (vehicle_inputs.V_input <= 0) {
		throw std::runtime_error("Input velocity must be greater than zero.");
	}
	if (vehicle_inputs.BB_input <= 0 || vehicle_inputs.BB_input >= 100) {
		throw std::runtime_error("Break bias must be between 0% and 100%.");
	}
	if (vehicle_inputs.DB_input <= 0 || vehicle_inputs.DB_input >= 100) {
		throw std::runtime_error("Drive bias must be between 0% and 100%.");
	}
	if (vehicle_inputs.m <= 0) {
		throw std::runtime_error("Mass must be greater than zero.");
	}
	if (vehicle_inputs.x <= 0 || vehicle_inputs.x >= 100) {
		throw std::runtime_error("Mass longitudinal distribution must be between 0% and 100%.");
	}
	if (vehicle_inputs.y <= 0 || vehicle_inputs.y >= 100) {
		throw std::runtime_error("Mass lateral distribution must be between 0% and 100%.");
	}
	if (vehicle_inputs.L <= 0) {
		throw std::runtime_error("Wheelbase must be greater than zero.");
	}
	if (vehicle_inputs.t_f <= 0) {
		throw std::runtime_error("Front track length must be greater than zero.");
	}
	if (vehicle_inputs.t_r <= 0) {
		throw std::runtime_error("Rear track length must be greater than zero.");
	}
	if (vehicle_inputs.h_CG <= 0) {
		throw std::runtime_error("Center of gravity height must be greater than zero.");
	}
	if (vehicle_inputs.m_u_fl <= 0 || vehicle_inputs.m_u_fr <= 0 || vehicle_inputs.m_u_rl <= 0 || vehicle_inputs.m_u_rr <= 0) {
		throw std::runtime_error("Unsprung masses must be greater than zero.");
	}
	if (vehicle_inputs.k_susp_f <= 0) {
		throw std::runtime_error("Front suspension stiffness must be greater than zero.");
	}
	if (vehicle_inputs.k_susp_r <= 0) {
		throw std::runtime_error("Rear suspension stiffness must be greater than zero.");
	}
	if (vehicle_inputs.k_r_C_deg <= 0) {
		throw std::runtime_error("Chassis torsional roll stiffness must be greater than zero.");
	}
	if (vehicle_inputs.k_r_C_dist <= 0 || vehicle_inputs.k_r_C_dist >= 100) {
		throw std::runtime_error("Chassis torsional roll stiffness distribution must be between 0% and 100%.");
	}
	if (vehicle_inputs.k_p_C_deg <= 0) {
		throw std::runtime_error("Chassis torsional pitch stiffness must be greater than zero.");
	}
	if (vehicle_inputs.k_p_C_dist <= 0 || vehicle_inputs.k_p_C_dist >= 100) {
		throw std::runtime_error("Chassis torsional pitch stiffness distribution must be between 0% and 100%.");
	}
	if (vehicle_inputs.front_tires_selection.empty() || vehicle_inputs.rear_tires_selection.empty()) {
		throw std::runtime_error("Tire selections cannot be empty.");
	}
	if (vehicle_inputs.diff_dTBR_f < 0 || vehicle_inputs.diff_bTBR_f < 0 || vehicle_inputs.diff_dTBR_r < 0 || vehicle_inputs.diff_bTBR_r < 0) {
		throw std::runtime_error("Differential TBR must be equal to or greater than 1");
	}
	if (vehicle_inputs.diff_preload_f < 0 || vehicle_inputs.diff_preload_f < 0) {
		throw std::runtime_error("Differential pre-load must not be negative");
	}
	if (vehicle_inputs.diff_k_lock_f < 0 || vehicle_inputs.diff_k_lock_f < 0) {
		throw std::runtime_error("Differential stiffness must not be negative");
	}

	// Add more validation checks as needed
	
}