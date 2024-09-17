#include "StateMachine.h"
#include "SmallSizeCondition.h"
#include "BigSizeCondition.h"
#include "WinCondition.h"
#include "TrueCondition.h"
#include "EscapedCondition.h"
#include<cstdlib>


using namespace std;

void proceedActions(vector<Action>& actions) {
	for (auto& action : actions) {
		action.proceedAction();
	}
}

int main() {

	//// the exemple I use is the following: Let's say my pawn is a simple man-at-arm roaming a zone in some lvl.
	//// He has 3 states : 
	////					 - On Guard (when roaming)
	////					 - Fighting (when detecting a small oponent); 
	////					 - Run Away (either because loosing fight after attacking or detecting a bigger opponent
	//// let's create a bunch of actions for all these states and situation

	//BigSizeCondition* bigSizeCond = nullptr;
	//SmallSizeCondition* smallSizeCond = nullptr;

	//std::cout << "How tall is the enemy ?" << std::endl;
	//float size;
	//std::cin >> size;
	//bigSizeCond = new BigSizeCondition(size);
	//smallSizeCond = new SmallSizeCondition(size);

	///*std::cout << "How far have you run away from the enemy? " << std::endl;
	//int steps;
	//std::cin >> steps;*/

	//
	//WinCondition* myWinCond = new WinCondition();
	////EscapedCondition* myEscapedCond = new EscapedCondition(steps);
	////TrueCondition* initCond = new TrueCondition();


	//////------- ACTIONS ------- //
	////
	//////Transition Actions:
	//const Action seeTallEnemyAction("I'm seeing a big enemy");
	//const Action seeSmallEnemyAction("I'm seeing a small enemy");
	//const Action losingFightAction("I'm losing my fight");
	//const Action escapedAction("Phew! I escaped.");
	//const Action initAction("OK, let's start guarding!.");
	////
	////// State Actions:
	//const Action onGuardAction("I'm on guard");
	//const Action fightAction("I'm fighting");
	//const Action runAwayAction("I'm running away");

	////// Entry-Exit Actions
	//const Action onGuardEntryAction("I'm start guarding");
	//const Action onGuardExitAction("I'm stop guarding");
	//const Action fightEntryAction("I'm entering a fight");
	//const Action fightExitAction("I stop fighting ");
	//const Action runAwayEntryAction("I start running away");
	//const Action runAwayExitAction("I'm stop running away");

	////// ------ TRANSITIONS ------ //
	//Transition* seeTallEnemyTrans = new Transition(seeTallEnemyAction, bigSizeCond);
	//Transition* seeSmallEnemyTrans = new Transition(seeSmallEnemyAction, smallSizeCond);
	//Transition* loosingFightTrans = new Transition(losingFightAction, myWinCond);
	//Transition* escapedTrans = new Transition(escapedAction, myWinCond);

	//std::vector<Transition*> onGuardTransitions{ seeSmallEnemyTrans, seeTallEnemyTrans };
	//std::vector<Transition*> fightTransitions{ loosingFightTrans };
	//std::vector<Transition*> runAwayTransitions{ escapedTrans };

	////// ------ STATES ------- //
	//State* onGuardState = new State(onGuardAction, onGuardEntryAction, onGuardExitAction, onGuardTransitions);
	//State* fightState = new State(fightAction, fightEntryAction, fightExitAction, fightTransitions);
	//State* runAwayState = new State(runAwayAction, runAwayEntryAction, runAwayExitAction, runAwayTransitions);

	////// ------ TARGETED STATES ------ //
	//seeTallEnemyTrans->setTargetedState(runAwayState);
	//seeSmallEnemyTrans->setTargetedState(fightState);
	//loosingFightTrans->setTargetedState(runAwayState);
	//escapedTrans->setTargetedState(onGuardState);

	//StateMachine machine(runAwayState);
	//std::vector<Action> actions = machine.update();
	//proceedActions(actions);
	//actions = machine.update();
	//proceedActions(actions);
	//actions = machine.update();
	//proceedActions(actions);
	

	// ----------------- 2ND EXAMPLE ------------------ //

	//------- conditions ------- //
	TrueCondition* cond = new TrueCondition();

	//------- actions ------- //
	//transition actions:
	const Action seeTrashAction("Trash spotted!");
	const Action pickedTrashAction("I picked up the trash!");
	const Action disposedTrashAction("Trash disposed!!");
	
	
	// state actions:
	const Action searchAction("I'm searching");
	const Action headToTrashAction("I'm heading to Trash");
	const Action headToCompactorAction("I'm heading to Compactor");

	// entry-exit actions
	const Action searchEntryAction("I enter in Search State");
	const Action searchExitAction("I exit search State");
	const Action headToTrashEntryAction("I enter in HeadToTrash State");
	const Action headToTrashExitAction("I exit HeadToTrash State");
	const Action headToCompactorEntryAction("I enter in HeadToCompactor State");
	const Action headToCompactorExitAction("I exit HeadToCompactor State");

	// ------ transitions ------ //
	Transition* detectTrashTrans = new Transition(seeTrashAction, cond);
	Transition* pickupTrans = new Transition(pickedTrashAction, cond);
	Transition* trashDisposedTrans = new Transition(disposedTrashAction, cond);

	std::vector<Transition*> searchTransitions{ detectTrashTrans };
	std::vector<Transition*> headToTrashTransitions{ pickupTrans };
	std::vector<Transition*> headToCompactorTransitions{ trashDisposedTrans };

	// ------ states ------- //
	State* searchState = new State(searchAction, searchEntryAction, searchExitAction, searchTransitions);
	State* headToTrashState = new State(headToTrashAction, headToTrashEntryAction, headToTrashExitAction, headToTrashTransitions);
	State* headToCompactorState = new State(headToCompactorAction, headToCompactorEntryAction, headToCompactorExitAction, headToCompactorTransitions);

	// ------ targeted states ------ //
	trashDisposedTrans->setTargetedState(searchState);
	detectTrashTrans->setTargetedState(headToTrashState);
	pickupTrans->setTargetedState(headToCompactorState);
	

	StateMachine machine(searchState);
	std::vector<Action> actions = machine.update();
	proceedActions(actions);
	actions = machine.update();
	proceedActions(actions);
	actions = machine.update();
	proceedActions(actions);

	
	return 0;
}