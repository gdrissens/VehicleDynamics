#include "Simulation_controller.h"

void Simulation_controller::run_simulation(Vehicle_inputs& inputs, Vehicle_outputs& outputs) {
	vehicle_repository.upgrade_version(inputs);
	vehicle_repository.validate(inputs);
	save_inputs(inputs, "Files\\Vehicles\\Vehicle_params_1.txt");
	vehicle.set_tires("Files\\Tires\\" + inputs.front_tires_selection + ".txt", "Files\\Tires\\" + inputs.rear_tires_selection + ".txt");
	vehicle.set_parameters(inputs);
	vehicle.solver();
	vehicle.output(outputs);
}

void Simulation_controller::run_YMD(Vehicle_inputs& inputs, Vehicle_outputs& outputs, YMD_Carrier& YMD_carrier) {
	vehicle_repository.upgrade_version(inputs);
	vehicle_repository.validate(inputs);
	save_inputs(inputs, "Files\\Vehicles\\Vehicle_params_1.txt");
	vehicle.set_tires("Files\\Tires\\" + inputs.front_tires_selection + ".txt", "Files\\Tires\\" + inputs.rear_tires_selection + ".txt");
	vehicle.set_parameters(inputs);
	vehicle.YMD(YMD_carrier);
	vehicle.solver();
	vehicle.output(outputs);
}

void Simulation_controller::load_form(Vehicle_inputs& inputs, Vehicle_outputs& outputs, YMD_Carrier& YMD_carrier) {
	if (load_inputs(inputs, "Files\\Vehicles\\Vehicle_params_1.txt")) {
		run_simulation(inputs, outputs);	
	}
}