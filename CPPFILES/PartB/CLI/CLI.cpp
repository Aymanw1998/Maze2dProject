#include "../../../HPPFILES/PartB/CLI/CLI.h"

void CLI::start() {
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