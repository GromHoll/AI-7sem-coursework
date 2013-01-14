//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAddMolingForm *AddMolingForm;
//---------------------------------------------------------------------------
__fastcall TAddMolingForm::TAddMolingForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAddMolingForm::ValueTrackBarChange(TObject *Sender)
{
	ValueEdit->Text = ValueTrackBar->Position;
}
//---------------------------------------------------------------------------
void __fastcall TAddMolingForm::AddButtonClick(TObject *Sender)
{
	Moling m;

	m.ID[0] = IDEdit1->Text.ToInt();
	m.ID[1] = IDEdit2->Text.ToInt();
	m.ID[2] = IDEdit3->Text.ToInt();
	m.ID[3] = IDEdit4->Text.ToInt();
	m.ID[4] = IDEdit5->Text.ToInt();
	m.ID[5] = IDEdit6->Text.ToInt();

	m.kernel = KernelEdit->Text;
	m.codes = CodesEdit->Text;

	m.value = double(ValueTrackBar->Position)/100.0;

	TStringList * SL = new TStringList();
	SL->LoadFromFile("kb.txt");
	SL->Add(molingToStr(m));
	SL->SaveToFile("kb.txt");

	delete SL;

	this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TAddMolingForm::CancelButtonClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

String molingToStr(Moling m) {
	String res;

	for(int i = 0; i < 5; i++)
	{
		res += m.ID[i];
		res += '.';
	}
	res += m.ID[5];
	res += "; ; ";
	res += m.kernel;
	res += "; ";
	res += m.codes;
	res += "; ";
	res += m.value;
	res += "; ;";

	return res;
}


Moling strToMoling(String s) {
	Moling m;

	int posEnd;
	for(int i = 0; i < 5; i++)
	{
		posEnd = s.Pos('.');
		m.ID[i] = s.SubString(0, posEnd - 1).ToInt();
		s = s.SubString(posEnd + 1, s.Length());
	}
	posEnd = s.Pos(';');
	m.ID[5] = s.SubString(0, posEnd - 1).ToInt();
	s = s.SubString(posEnd + 4, s.Length());

	posEnd = s.Pos(';');
	m.kernel = s.SubString(0, posEnd - 1);
	s = s.SubString(posEnd + 2, s.Length());

	posEnd = s.Pos(';');
	m.codes = s.SubString(0, posEnd - 1);
	s = s.SubString(posEnd + 2, s.Length());

	posEnd = s.Pos(';');
	m.value = s.SubString(0, posEnd - 1).ToDouble();

	return m;
}
