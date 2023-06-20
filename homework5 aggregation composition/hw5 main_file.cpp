#include "composition.h"
#include "aggregation.h"


int main() {

	/*Human_body human;
	Human_body not_a_human(true, true, false, true, false, 34, 2, false);*/

	/*Quitar yamaha;*/

	/*Cinema_building cinema(6);*/


	/*Character character("Gandalf", 454532, true);
	Movie movie("Lord of the rings", 2001, "Peter Jackson", character);
	Book book("The Hobbit", 1938, "John Tolkien", character);*/


	Floor floor("wood", "brown");
	Livingroom livingroom(true, true, 20, floor);
	Bedroom bedroom(true, true, floor);


}