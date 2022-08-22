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

/*void CreateFile(int Length, string Password, string FileName, std::ofstream PasswordFile) {

	string AppendedPassword = GeneratePassword(Length, Password);
	cout << AppendedPassword << endl;

	PasswordFile.open(FileName, std::ios_base::out);

	if (!PasswordFile.is_open()) {
		cout << "failed to open " << FileName << '\n';
	}
	else {
		PasswordFile.write(AppendedPassword.data(), AppendedPassword.size());
		cout << "Saved password to file" << endl;
	}
}

*/

int main() { //fuck this shit
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