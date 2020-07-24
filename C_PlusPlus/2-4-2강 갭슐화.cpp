#include <iostream>

using namespace std;

class SinivelCap    // Äà¹° Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const { cout << "Äà¹° Àü¿ë¾à" << endl; }
};

class SneezeCap    // ÀçÃ¤±â Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const { cout << "ÀçÃ¤±â Àü¿ë¾à" << endl; }
};

class SnuffleCap   // ÄÚ¸·Èû Ã³Ä¡¿ë Ä¸½¶
{
public:
	void Take() const { cout << "ÄÚ¸·Èû Àü¿ë¾à" << endl; }
};

class CAPSULE
{
private:
	SinivelCap a;
	SneezeCap b;
	SnuffleCap c;

public:
	void Take() const
	{
		a.Take();
		b.Take();
		c.Take();
	}
};

class Patient
{
public:
	void EatCapsule(const CAPSULE &cap) const { cap.Take(); }
};

int main242(void)
{
	CAPSULE capsule;
	Patient patient;

	patient.EatCapsule(capsule);
	return 0;
}