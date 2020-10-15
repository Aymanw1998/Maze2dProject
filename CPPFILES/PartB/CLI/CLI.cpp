#include "../../../HPPFILES/PartB/CLI/CLI.h"
void help() {
	std::cout << "The commonds you can write are:" << std::endl;
	std::cout << "1) dir <path> -> Displays all the files in the folder" << std::endl;
	std::cout << "2) generate maze <name> <size> -> create 'name' maze with 'rows' size" << std::endl;
	std::cout << "3) display <name> -> Print to the user the maze whose name is 'name'" << std::endl;
	std::cout << "4) display solution <name> -> Presenting the solution (calculated route)" << std::endl;
	std::cout << "5) file size <name> -> Displays the size of the maze in the file" << std::endl;
	std::cout << "6) load maze <file name> <name> -> Upload the maze from 'file name' and give it new name: 'name'" << std::endl;
	std::cout << "7) maze size <name> , Displays the size of 'name' maze n memory" << std::endl;
	std::cout << "8) save maze <name> <file name> , Create and Save the 'name' maze to 'file name'" << std::endl;
	std::cout << "9) solve <name> <algorithm> -> Calculate the best route according to the algorithm and which maze want" << std::endl;
	std::cout << "		- 'BFS' for 'BFS algorithm'" << std::endl;
	std::cout << "		- 'AStartM' for 'A* distance_Manhattan algorithm'" << std::endl;
	std::cout << "		- 'AStartA' for 'A* airline_distance algorithm'" << std::endl;
}
void CLI::start() {
	std::cout << "Enter 'help' for know what you can be written" << std::endl;
	std::string command = "";
	Model* model = new MyModel();
	View* view = new MyView(m_in,m_out);
	m_controller = new MyController(view, model);
	model->addObserver(*m_controller);
	while (command.compare("exit")) {
		std::cout << ">>";
		command = view->input();
		if (command.compare("exit") == 0)
			continue;
		else if (command.compare("help") == 0)
		{
			help(); continue;
		}
		FonctionsForHelps f;
		Command* commandClass;
		auto tokens = f.arrayWords(command);
		if (tokens.size() == 1) {
			view->print("Error: Command does not exist");
				continue;
		}
		if (tokens[0].compare("dir") == 0 || tokens[0].compare("solve") == 0 || 
			(tokens[0].compare("display") == 0 && tokens[1].compare("solution") != 0))
			commandClass = m_controller->get(tokens[0]);
		else commandClass = m_controller->get(tokens[0] + " " + tokens[1]);
		if (commandClass != nullptr) {
			try {
				commandClass->doCommand(tokens);
			}
			catch (const char* e) {
				m_controller->update(e);
			}
		}
		else view->print("Error: Command does not exist");

	}
	std::vector<std::string> names = model->namesMazes();
	for (auto& name : names) {
		std::vector<std::string> tokens = {"save","maze" ,name,name + ".data" };
		m_controller->get("save maze")->doCommand(tokens);
	}

	delete view; delete model;
}