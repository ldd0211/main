////////////////////////////////////////////////////////////////////////
//////////////////////////////// "TASK"  //////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//
// "Task" is the most fundamental unit the TaskMaster handles.
//
///////////////////////////////////////////////////////////////////////////
////////////////////////////// "SINGLE DAY" ///////////////////////////////
///////////////////////////////////////////////////////////////////////////
//
// A "Single Day" struct models all the tasks in a single calendar day.
// It comprises a variable taskDate (representing the date of the day
// we are modeling) and a vector of Tasks for that day.
// An example is shown below:
// 
// Sucessfully added "Submit CS2103 CE2" to today.			<--- HEADER TEXT
//
// [Today Fri Jan 1] ===================================	<--- DATE BAR
//
// 2.  ----------------		Remember to bring pencil		<--- TASK
// 3. [8:45am - 11:30am]	Brunch with Jane				<--- TASK  
// 4. [12pm]				Submit CS2103 CE2				<--- TASK
//
///////////////////////////////////////////////////////////////////////////
//////////////////////////////// "TASK LIST" //////////////////////////////
///////////////////////////////////////////////////////////////////////////
//
// A "Task List" is a vector of single days. It is used to hold tasks 
// over a range of days.
//
///////////////////////////////////////////////////////////////////////////
//////////////////////////////// "CHANGES" ////////////////////////////////
///////////////////////////////////////////////////////////////////////////
//
// "Changes" are used to represent state changes in tasks. Such changes 
// can result from add, delete, edit, postpone etc.
//
///////////////////////////////////////////////////////////////////////////
//////////////////////////////// "UI OBJECT" //////////////////////////////
///////////////////////////////////////////////////////////////////////////
//
// A "UI Object" is simply a Task List packaged with a header text for
// ease of printing to the console
//
#pragma once
#include <string>
#include <vector>
#include <ctime>

namespace DS {
	enum CommandType {
		ADD, DELETE, EDIT, POSTPONE, UNDO, 
		SEARCH, VIEW, 
		BLOCK, CONFIRM, 
		STORAGE,
		EXIT_PROGRAM, INVALID
	};

	struct TASK {
		TASK(): taskID(0), isDone(false) {};

		unsigned taskID;
		std::string taskName;
		tm taskStart;
		tm taskEnd;
		bool isDone;
	};

	struct SINGLE_DAY {
		tm taskDate;
		std::vector<TASK> tasksThisDay;
	};

	typedef std::vector<SINGLE_DAY>	TaskList;
	typedef std::vector<SINGLE_DAY>::iterator dayIter;

	struct CHANGES {
		unsigned taskID;
		CommandType cmdType;
		TASK before;
		TASK after;
	};

	struct UIObject {
		std::string headerText;
		TaskList taskList;
	};
}