#pragma once
#include <filesystem>
#include <fstream>
#include <string>
#include "Inputs.h"

class Tire_selection
{
private:
	std::string selected_tire;
	std::vector<std::string> tire_list;
	Tire_inputs* tire_inputs;
	Tire_inputs* front_tires;
	Tire_inputs* rear_tires;

public:
	enum class file_status { Success, FileNotFound, ItemNotFound, DuplicateItem, DuplicateFile, DuplicateDirectory, EmptyItem };

	void select_tire(std::string name, Tire_inputs* tire_inputs);

	std::vector<std::string> load_tire_list();

	void save_tire(std::string name, Tire_inputs* tire_inputs);

	file_status new_tire(Tire_inputs* tire_inputs);

	file_status delete_tire(std::string name);

	
};