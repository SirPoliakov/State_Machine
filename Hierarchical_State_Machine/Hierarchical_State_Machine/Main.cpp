#include "SubMachineState.h"
#include "Transition.h"
#include "TrueFalseCondition.h"


void proceed(UpdateResult& res)
{
	for (auto action : res.actions)
	{
		action->proceedAction();
	}
}

int main() 
{	
	// -------------- CONDITIONS --------------- //

	TrueCondition* _TrueCond = new TrueCondition();
	FalseCondition* _FalseCond = new FalseCondition();


	// -------------- ACTIONS --------------- //

	// - A Actions :
	Action* _A_Action = new Action("A active");
	Action* _A_EntryAction = new Action("Entering A");
	Action* _A_ExitAction = new Action("Exiting A");

	// - B Actions :
	Action* _B_Action = new Action("B active");
	Action* _B_EntryAction = new Action("Entering B");
	Action* _B_ExitAction = new Action("Exiting B");

	// - C Actions :
	Action* _C_Action = new Action("C active");
	Action* _C_EntryAction = new Action("Entering C");
	Action* _C_ExitAction = new Action("Exiting C");

	// - L Actions :
	Action* _L_Action = new Action("L active");
	Action* _L_EntryAction = new Action("Entering L");
	Action* _L_ExitAction = new Action("Exiting L");

	// - M Actions :
	Action* _M_Action = new Action("M active");
	Action* _M_EntryAction = new Action("Entering M");
	Action* _M_ExitAction = new Action("Exiting M");

	// - N Actions :
	Action* _N_Action = new Action("N active");
	Action* _N_EntryAction = new Action("Entering N");
	Action* _N_ExitAction = new Action("Exiting N");

	// - Transition Actions:
	Action* _1_Action = new Action("Doing 1 Transition");
	Action* _2_Action = new Action("Doing 2 Transition");
	Action* _3_Action = new Action("Doing 3 Transition");
	Action* _4_Action = new Action("Doing 4 Transition");
	Action* _5_Action = new Action("Doing 5 Transition");
	Action* _6_Action = new Action("Doing 6 Transition");
	Action* _7_Action = new Action("Doing 7 Transition");


	// -------------- TRANSITIONS --------------- //

	Transition* _1_AB_Trans = new Transition(_1_Action, _FalseCond, 0);
	Transition* _2_MC_Trans = new Transition(_2_Action, _TrueCond, -1);
	Transition* _3_BN_Trans = new Transition(_3_Action, _FalseCond, 1);
	Transition* _4_LM_Trans = new Transition(_4_Action, _FalseCond, 0);
	Transition* _5_MN_Trans = new Transition(_5_Action, _FalseCond, 0);
	Transition* _6_NL_Trans = new Transition(_6_Action, _FalseCond, 0);
	Transition* _7_NM_Trans = new Transition(_7_Action, _FalseCond, 0);

	std::vector<Transition*> _M_Trans{ _5_MN_Trans, _2_MC_Trans };
	std::vector<Transition*> _N_Trans{ _6_NL_Trans, _7_NM_Trans };
	std::vector<Transition*> _A_Trans{ _1_AB_Trans };
	std::vector<Transition*> _B_Trans{ _3_BN_Trans };
	std::vector<Transition*> _C_Trans{};
	std::vector<Transition*> _L_Trans{ _4_LM_Trans };

	// -------------- STATES --------------- //

	State* _M_State = new State(_M_Action, _M_EntryAction, _M_ExitAction, _M_Trans, nullptr);
	State* _N_State = new State(_N_Action, _N_EntryAction, _N_ExitAction, _N_Trans, nullptr);
	State* _A_State = new State(_A_Action, _A_EntryAction, _A_ExitAction, _A_Trans, nullptr);
	State* _B_State = new State(_B_Action, _B_EntryAction, _B_ExitAction, _B_Trans, nullptr);
	State* _C_State = new State(_C_Action, _C_EntryAction, _C_ExitAction, _C_Trans, nullptr);

	SubMachineState* _L_SubMS = new SubMachineState(_A_State, _L_Action, _L_EntryAction, _L_ExitAction, _L_Trans, nullptr);
	
	_A_State->addParent(_L_SubMS);
	_B_State->addParent(_L_SubMS);
	_C_State->addParent(_L_SubMS);
	
	

	// -------------- TARGET STATES --------------- //

	_1_AB_Trans->setTargetedState(_B_State);
	_2_MC_Trans->setTargetedState(_C_State);
	_3_BN_Trans->setTargetedState(_N_State);
	_4_LM_Trans->setTargetedState(_M_State);
	_5_MN_Trans->setTargetedState(_N_State);
	_6_NL_Trans->setTargetedState(_L_SubMS);
	_7_NM_Trans->setTargetedState(_M_State);

	HierarchicalStateMachine* _ABCLMN_StateMachine = new HierarchicalStateMachine(_L_SubMS, _M_State);
	_L_SubMS->HierarchicalStateMachine::addParent(_ABCLMN_StateMachine);
	_L_SubMS->State::addParent(_ABCLMN_StateMachine);
	_M_State->addParent(_ABCLMN_StateMachine);
	_N_State->addParent(_ABCLMN_StateMachine);


	UpdateResult res = _ABCLMN_StateMachine->update();
	proceed(res); 
	res.clear();
	// = _ABCLMN_StateMachine->update();
	//proceed(res);
	//res.clean();
	//res = _ABCLMN_StateMachine->update();
	//proceed(res);
	//res = _ABCLMN_StateMachine->update();
	//proceed(res);


	return 0;
}