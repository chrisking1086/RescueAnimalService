//======================================================================
// Name			: RescueAnimal.cpp
// Author		: Christopher King
// Version		: 1.0
// Description	: Parent Class for all rescue animals(Dogs and Monkeys)
//======================================================================

#include <String>;

using namespace std;
class RescueAnimal{
protected:
	string
		name,
		animalType,
		gender,
		age,
		weight,
		acquisitionDate,
		acquisitionCountry,
		trainingStatus,
		inServiceCountry;
	bool isReserved = false;
};