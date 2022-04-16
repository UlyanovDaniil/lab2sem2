#include <iostream>
#include "Complex.h"

int main()
{
	TComplex c1;
	TComplex c2(4, 5);
	TComplex c3 = c2;

	std::cout << "c1 = " << c1 << "\tc2 = " << c2 << "\tc3 = " << c3 << "\n";

	c1.SetRe(20);
	c1.SetIm(10);

	std::cout << "re(c1) = " << c1.GetRe() << "\tim(c1) = " << c1.GetIm() << "\n";

	c3 = c2 + c1;

	std::cout << "c3 = c2 + c1 = " << c2 << " + " << c1 << " = " << c3 << "\n";

	c3 = c1 - c2;

	std::cout << "c3 = c1 - c2 = " << c1 << " - " << c2 << " = " << c3 << "\n";

	std::cout << "c1 = " << c1 << "\tc2 = " << c2 << "\n";

	if (c1 == c2)
	{
		std::cout << "c1 = c2" << "\n";
	}
	else
	{
		std::cout << "c1 != c2" << "\n";
	}

	c2 = c1 * c3;

	std::cout << "c2 = c1 * c3 = " << c1 << " * " << c3 << " = " << c2 << "\n";

	c2 = c1 / c3;

	std::cout << "c2 = c1 / c3 = " << c1 << " / " << c3 << " = " << c2 << "\n";

	std::cout << "c2:";

	std::cin >> c2;

	std::cout << "c1 = " << c1 << "\tc2 = " << c2 << "\tc3 = " << c3 << "\n";

	std::cout << "|c2| = " << c2.z() << "\n";

	c3 = c3.complPow(2);
	c1 = c1.complPow(-1);
	c2 = c2.complPow(1.5);

	std::cout << "c3 ^ 2 = " << c3 << "\tc1 ^ -3 = " << c1 << "\tc2 ^ 4.5= " << c2 << "\n";

	c1 = c3.complToComplPow(c2);

	std::cout << "c1 = c3 ^ c2 = " << c3 << " ^ " << c2 << " = " << c1 << "\n";

	std::cout << "c2 = ";
	c2.printTrignmForm();

	return 0;
}