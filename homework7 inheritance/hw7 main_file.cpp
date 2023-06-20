#include"Pets.h"

int main() {

	Dog dog("Dog", "retrivier", 3, true, true, false, true);

	dog.show_info();

	Cat cat("kuroneko", "breedless", 25, true, "green", "black");

	cat.show_info();

	Parrot parrot("john silver", "cockatoo", 100, true, true, false, "white and yellow");

	parrot.show_info();
}
