#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

std::string command {};
std::string parameter {};

int main(void) {
	std::system("clear");
	while (true) {
	std::cout << "Command:~@ ";
	std::cin >> command;
	if (command == "help") {
		std::cout << "Commands:\n";
		std::cout << "help\n	Shows this menu\n\n";
		std::cout << "list\n	Lists all files in system\n\n";
		std::cout << "write {parameter}:\n	Creates and writes to a new file (must specify file suffix such as .txt)\n\n";
		std::cout << "open {parameter}:\n	Reads a text files\n\n";
		std::cout << "delete {parameter}:\n	Deletes the specified file\n\n";
		std::cout << "check {parameter}:\n	Checks if file exists\n\n";
	}
	else if (command == "write") {
		std::cin >> parameter;
		std::string wfile {};
		wfile = "files/" + parameter;
		std::ifstream file;
		file.open (wfile);
		if (file.is_open()){
			std::cout << "Sorry, that file already exists!\n";
			file.close();
		}
		else {
			file.close();
			std::system("clear");
			std::cout << "Writing to file: " << parameter << "\n";
			std::ofstream file;
			file.open (wfile);
			std::string content {};
			std::getline(std::cin >> std::ws, content);
			file << content;
			file.close();
		}
	}
	else if (command == "open"){
		std::cin >> parameter;
		std::string wfile{};
		wfile = "files/" + parameter;
		std::ifstream file;
		file.open (wfile);
		if (file.is_open()) {
			std::system("clear");
			std::string line;
			while (std::getline(file,line)){
				std::cout << line << '\n';
			}
		}
		else {
			std::cout << "Sorry, that file does not exist\n";
			file.close();
		}
	}
	else if (command == "check") {
		std::cin >> parameter;
		std::ifstream file;
		file.open (parameter);
		if (file.is_open()) {
			std::cout << parameter << " exists\n";
		} else {
			std::cout << parameter << " does not exist\n";
		}
	}
	else if (command == "list") {
		std::string path = "./files";
		std::string toOut;
		for (const auto & entry : std::filesystem::directory_iterator(path)) {
			toOut = entry.path();
			std::cout << toOut.substr(8) << std::endl;
		}
	}
	else if (command == "delete") {
		std::cin >> parameter;
		std::string wfile = "files/" + parameter;
		std::ifstream file;
		file.open (wfile);
		if (file.is_open()) {
			std::remove(wfile.c_str());
			std::cout << parameter << " has been successfully removed\n";
		} else {
			std::cout << "Can not remove " << parameter << ", file does not exist\n";
		}
	}
	else {
		std::cout << "that is not a valid command\n";
	}
	}
}
