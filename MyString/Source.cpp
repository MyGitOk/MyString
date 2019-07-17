#include"MyString.h"

int main()
{
	MyString s("mike");
	s.printStr();
	cout << "\nsize - " << s.getSizeStr() << " s\n";

	MyString sCopy(s);
	sCopy.printStr();
	cout << "\nsize - " << sCopy.getSizeStr() << " sCopy\n";

	MyString sEmpty;
	sEmpty.printStr();
	cout << "\nsize - " << sEmpty.getSizeStr() << " sEmpty\n";
	sEmpty = "not empty";
	sEmpty.printStr();
	cout << "\nsize - " << sEmpty.getSizeStr() << " sEmpty\n";
	sEmpty = "more then prev";
	sEmpty.printStr();
	cout << "\nsize - " << sEmpty.getSizeStr() << " sEmpty\n";
	sEmpty = "less th pr";
	sEmpty.printStr();
	cout << "\nsize - " << sEmpty.getSizeStr() << " sEmpty\n";

	sEmpty = s;
	sEmpty.printStr();
	cout << "\nsize - " << sEmpty.getSizeStr() << " sEmpty\n";

	sEmpty.clearStr();
	sEmpty.printStr();
	cout << "\nsize after clear - " << sEmpty.getSizeStr() << " sEmpty\n";
	sEmpty = sCopy;
	sEmpty.printStr();
	cout << "\nsize - " << sEmpty.getSizeStr() << " sEmpty\n";

	MyString s1;
	s1 = sCopy + " & Lera";
	s1.printStr();
	cout << "\nsize - " << s1.getSizeStr() << " s1 = sCopy + Lera\n";
	MyString s2;
	s2 = s1 + sCopy;
	s2.printStr();
	cout << "\nsize - " << s2.getSizeStr() << " s2 = s1 + sCopy\n";
	s1 += " programers";
	s1.printStr();
	cout << "\nsize - " << s1.getSizeStr() << " s1 += \" programers\"\n";
	s1 += s;
	s1.printStr();
	cout << "\nsize - " << s1.getSizeStr() << " s1 += s\n";


	if (s == "mike")
		cout << "s equal \"mike\"\n";
	else
		cout << "s does not equal \"mike\"\n";
	if (s == sCopy)
		cout << "s equal sCopy\n";
	else
		cout << "s does not equal sCopy\n";

	if (s != "mike")
		cout << "s does not equal \"mike\"\n";
	else
		cout << "s equal \"mike\"\n";
	if (s != sCopy)
		cout << "s does not equal sCopy\n";
	else
		cout << "s equal sCopy\n";
}