#include <iostream>
#include <time.h>
#include <fstream>

#define string std::string
#define endl std::endl
#define cout std::cout

const string AlphaNumericalSystem =
	"abcdefghijklmnopqrstuvwxyz"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	"!@#$%&"
	"0123456789";


string GeneratePassword(int Length, string Password) {
	Password.resize(Length);

	for (int i = 0; i < Length; i++) {
		Password[i] = AlphaNumericalSystem[rand() % AlphaNumericalSystem.length()];
	}

	return Password;
}

void AppendToFile(string Password, int Length)
{
	string AppendedPassword = GeneratePassword(Length, Password);

	std::ofstream outfile("Passwords.txt", std::ios::app);

	if (!outfile.fail()) {
		outfile << AppendedPassword << endl;
		outfile << Password << endl;
		cout << "Saved to file!\n";
	}
}

int main() {
	srand(time(NULL));
	
	int Length;
	string Password;

	string FileName = "Passwords.txt";
	std::ofstream PasswordFile;

	cout << "Enter password length: ";
	std::cin >> Length;

	AppendToFile(Password, Length);
	system("pause");
}
