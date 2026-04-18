#pragma once
#include "Vehicle.h"
#include "Inputs.h"
#include "Outputs.h"

class Simulation_controller
{
	private: 
		Vehicle vehicle;

	public:

		void run_simulation(Vehicle_inputs& inputs, Vehicle_outputs& outputs);

		void run_YMD(Vehicle_inputs& inputs, Vehicle_outputs& outputs, YMD_Carrier& YMD_carrier);

		void load_form(Vehicle_inputs& inputs, Vehicle_outputs& outputs);
};

