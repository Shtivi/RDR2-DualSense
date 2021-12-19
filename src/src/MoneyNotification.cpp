#include "Main.h"

struct {
	alignas(8) int f_0;
	alignas(8) int f_1;
	alignas(8) int f_2;
	alignas(8) int f_3;
} Var0;

struct {
	alignas(8) int f_0;
	alignas(8) const char* f_1;
	alignas(8) const char* f_2;
	alignas(8) int f_3;
	alignas(8) int f_4;
	alignas(8) int f_5;
	alignas(8) int f_6;
	alignas(8) int f_7;
} Var13;


const char* Var13_f_1;
const char* Var13_f_2 = "ITEMTYPE_TEXTURES";

void showMoneyNotification(int amountCents, int duration)
{
	Var0.f_0 = -2;
	Var0.f_1 = 0;
	Var0.f_2 = 0;
	Var0.f_3 = 0;
	Var0.f_0 = duration;

	Var13_f_1 = MISC::VAR_STRING(2, "CASH_STRING", amountCents);

	Var13.f_0 = 0;
	Var13.f_1 = Var13_f_1;
	Var13.f_2 = Var13_f_2;
	Var13.f_3 = 1831944558;
	Var13.f_4 = 0;
	Var13.f_5 = 109029619;
	Var13.f_6 = 0;
	UIFEED::_0xB249EBCB30DD88E0((Any)&Var0, (Any)&Var13, 1);
}