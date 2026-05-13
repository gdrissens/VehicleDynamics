#include "Tire_selection.h"

void Tire_selection::select_tire(std::string name, Tire_inputs* tire_inputs) {
	selected_tire = sto_(name);
	std::string path = "Tires\\" + selected_tire + ".txt";
	load_tire_inputs(*tire_inputs, path);
}

std::vector<std::string> Tire_selection::load_tire_list()
{
	std::string path = "Tire_list.txt";
	tire_list.clear();
	if (std::filesystem::exists(path)) {
		std::ifstream file(path);
		std::string line;
		while (std::getline(file, line))
		{
			tire_list.push_back(line);
		}
		file.close();   // force release
	}
	std::sort(tire_list.begin(), tire_list.end());  // alphabetical order

	return tire_list;
}

void Tire_selection::save_tire(std::string name, Tire_inputs* tire_inputs) {
	tire_list = load_tire_list();
	std::string new_name = sto_(name);
	for (int i = 0; i < tire_list.size(); i++)
	{
		if (tire_list[i] == selected_tire) {
			tire_list[i] = new_name;
		}
	}
	std::sort(tire_list.begin(), tire_list.end());  // alphabetical order
	std::ofstream file("Tire_list.txt", std::ios::out | std::ios::trunc);
	for (const auto& line : tire_list)
	{
		file << line << '\n';
	}
	file.flush();   // force write
	file.close();   // force release
	save_tire_inputs(*tire_inputs, "Tires\\" + new_name + ".txt");
	if ((std::find(tire_list.begin(), tire_list.end(), selected_tire) == tire_list.end()) && new_name != selected_tire) {
		std::filesystem::remove("Tires\\" + selected_tire + ".txt");
	}
	selected_tire = new_name;
}

Tire_selection::file_status Tire_selection::new_tire(Tire_inputs* tire_inputs)
{
	std::string name = "New_tire";
	if (std::find(tire_list.begin(),tire_list.end(), name) != tire_list.end())
	{
		return file_status::DuplicateItem;
	}
	std::string path = "Tires\\" + name + ".txt";

	// create folder if it doesn't exist
	if (!std::filesystem::exists("Tires"))
	{
		std::filesystem::create_directory("Tires");
	}
	if (std::filesystem::exists(path))
	{
		return file_status::DuplicateFile;
	}
	std::ofstream file(path);
	save_tire_inputs(*tire_inputs, path);
	tire_list.push_back(name);
	std::sort(tire_list.begin(), tire_list.end());
	std::ofstream file2("Tire_list.txt");
	for (const auto& line : tire_list)
	{
		file2 << line << '\n';
	}
	load_tire_list();
	selected_tire = name;
	return file_status::Success;
}

Tire_selection::file_status Tire_selection::delete_tire(std::string name)
{
	std::string delete_name = sto_(name);
	if (delete_name.empty()) {
		return file_status::EmptyItem;
	}
	if (!(std::find(tire_list.begin(), tire_list.end(), delete_name) != tire_list.end()))
	{
		//MessageBox::Show("Tire not found.");
		return file_status::ItemNotFound;
	}
	std::string path = "Tires\\" + delete_name + ".txt";

	if (!std::filesystem::exists(path))
	{
		//MessageBox::Show("File not found.");
		return file_status::FileNotFound;
	}
	std::filesystem::remove(path);
	tire_list.erase(std::remove(tire_list.begin(),tire_list.end(),delete_name),tire_list.end());
	std::ofstream file("Tire_list.txt", std::ios::out | std::ios::trunc);
	for (const auto& line : tire_list)
	{
		file << line << '\n';
	}
	file.flush();   // force write
	file.close();   // force release
	return file_status::Success;
}