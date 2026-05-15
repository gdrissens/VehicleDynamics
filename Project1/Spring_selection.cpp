#include "Spring_selection.h"

void Spring_selection::select_spring(std::string name) {
	selected_spring = sto_(name);
	std::string path = "Files\\Springs\\" + selected_spring + ".txt";

	spring_inputs = load_spring_inputs(path);
}

std::vector<std::string> Spring_selection::load_spring_list()
{
	std::string path = "Files\\Springs\\Spring_list.txt";
	spring_list.clear();
	if (std::filesystem::exists(path)) {
		std::ifstream file(path);
		std::string line;
		while (std::getline(file, line))
		{
			spring_list.push_back(line);
		}
		file.close();   // force release
	}
	std::sort(spring_list.begin(), spring_list.end());  // alphabetical order
	return spring_list;
}

void Spring_selection::save_spring(std::string name) {
	spring_list = load_spring_list();
	std::string new_name = sto_(name);
	for (int i = 0; i < spring_list.size(); i++)
	{
		if (spring_list[i] == selected_spring) {
			spring_list[i] = new_name;
		}
	}
	std::sort(spring_list.begin(), spring_list.end());  // alphabetical order
	std::ofstream file("Files\\Springs\\Spring_list.txt", std::ios::out | std::ios::trunc);
	for (const auto& line : spring_list)
	{
		file << line << '\n';
	}
	file.flush();   // force write
	file.close();   // force release
	save_spring_inputs(spring_inputs, "Files\\Springs\\" + new_name + ".txt");
	if ((std::find(spring_list.begin(), spring_list.end(), selected_spring) == spring_list.end()) && new_name != selected_spring) {
		std::filesystem::remove("Files\\Springs\\" + selected_spring + ".txt");
	}
	selected_spring = new_name;
}

void Spring_selection::new_spring(std::vector<double> spring_inputs)
{
	std::string name = "New_spring";
	if (std::find(spring_list.begin(), spring_list.end(), name) != spring_list.end())
	{
		throw std::invalid_argument("Duplicate spring name.");
	}
	std::string path = "Files\\Springs\\" + name + ".txt";
	// create folder if it doesn't exist
	if (!std::filesystem::exists("Files\\Springs"))
	{
		std::filesystem::create_directory("Files\\Springs");
	}
	if (std::filesystem::exists(path))
	{
		throw std::invalid_argument("File already exists.");
	}
	std::ofstream file(path);
	save_spring_inputs(spring_inputs, path);
	spring_list.push_back(name);
	std::sort(spring_list.begin(), spring_list.end());
	std::ofstream file2("Files\\Springs\\Spring_list.txt");
	for (const auto& line : spring_list)
	{
		file2 << line << '\n';
	}
	load_spring_list();
	selected_spring = name;
}

void Spring_selection::delete_spring(std::string name)
{
	std::string delete_name = sto_(name);
	if (delete_name.empty()) {
		throw std::invalid_argument("Name cannot be empty.");
	}
	if (!(std::find(spring_list.begin(), spring_list.end(), delete_name) != spring_list.end()))
	{
		throw std::invalid_argument("Spring not found.");
	}
	std::string path = "Files\\Springs\\" + delete_name + ".txt";

	if (!std::filesystem::exists(path))
	{
		throw std::invalid_argument("File not found.");
	}
	std::filesystem::remove(path);
	spring_list.erase(std::remove(spring_list.begin(), spring_list.end(), delete_name), spring_list.end());
	std::ofstream file("Files\\Springs\\Spring_list.txt", std::ios::out | std::ios::trunc);
	for (const auto& line : spring_list)
	{
		file << line << '\n';
	}
	file.flush();   // force write
	file.close();   // force release
}

void Spring_selection::select_front_arb(std::string name) {
	front_arb_name = sto_(name);
	std::string path = "Files\\Springs\\" + front_arb_name + ".txt";

	front_ARB = load_spring_inputs(path);
}

void Spring_selection::select_rear_arb(std::string name) {
	rear_arb_name = sto_(name);
	std::string path = "Files\\Springs\\" + rear_arb_name + ".txt";

	rear_ARB = load_spring_inputs(path);
}