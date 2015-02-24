#include <sstream>
#include "Controller.h"

std::string Controller::getFirstWord(std::string userCmd) {
	std::istringstream iss(userCmd);
	std::string firstWord;
	iss >> firstWord;
	return firstWord;
};

DS::CommandType Controller::determineCmdType(std::string cmdTypeString) {
    return DS::ADD; //example
}

DS::UIObject Controller::handleInput(std::string input) {
    std::string cmdTypeString = getFirstWord(input);
    DS::CommandType commandType = determineCmdType(input);
    /*
    switch (commandType) {

    }*/

    // below is just a sample uiobj. 
	DS::TASK task;
	task.taskID = 1;
	task.taskName = "eat hamburger";

	DS::SINGLE_DAY singleDay;
	singleDay.tasksThisDay.push_back(task);

	DS::TaskList myTaskList;
	myTaskList.push_back(singleDay);

	DS::UIObject sampleUIObj;
	sampleUIObj.headerText = "Tasks for today:";
	sampleUIObj.taskList = myTaskList;

	return sampleUIObj;
}

Controller::Controller(void) {
}


Controller::~Controller(void) {
}
