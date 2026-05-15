#pragma once
#include <filesystem>
#include <fstream>
#include <string>
#include "Inputs.h"

class Spring_selection {
private:
	std::string selected_spring;
	std::string front_arb_name;
	std::string rear_arb_name;
	std::vector<std::string> spring_list;
public:
	std::vector<double> spring_inputs = {0.0};
	std::vector<double> front_ARB = { 0.0 };
	std::vector<double> rear_ARB = { 0.0 };

	void select_spring(std::string name);

	std::vector<std::string> load_spring_list();

	void save_spring(std::string name);

	void new_spring(std::vector<double> spring_inputs);

	void delete_spring(std::string name);

	void Spring_selection::select_front_arb(std::string name);

	void Spring_selection::select_rear_arb(std::string name);
};

