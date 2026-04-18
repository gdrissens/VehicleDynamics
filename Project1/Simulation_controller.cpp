#include "Simulation_controller.h"

void Simulation_controller::run_simulation(Vehicle_inputs& inputs, Vehicle_outputs& outputs) {
	save_inputs(inputs, "Vehicle_params_1.txt");
	vehicle.set_tires("Tires\\" + inputs.front_tires_selection + ".txt", "Tires\\" + inputs.rear_tires_selection + ".txt");
	vehicle.set_parameters(inputs);
	vehicle.solver();
	vehicle.output(outputs);
}

void Simulation_controller::run_YMD(Vehicle_inputs& inputs, Vehicle_outputs& outputs, YMD_Carrier& YMD_carrier) {
	save_inputs(inputs, "Vehicle_params_1.txt");
	vehicle.set_tires("Tires\\" + inputs.front_tires_selection + ".txt", "Tires\\" + inputs.rear_tires_selection + ".txt");
	vehicle.set_parameters(inputs);
	vehicle.YMD(YMD_carrier);
	vehicle.solver();
	vehicle.output(outputs);
}

void Simulation_controller::load_form(Vehicle_inputs& inputs, Vehicle_outputs& outputs) {
	if (load_inputs(inputs, "Vehicle_params_1.txt")) {
		run_simulation(inputs, outputs);
	}
}