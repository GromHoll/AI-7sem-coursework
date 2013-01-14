//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TViewForm *ViewForm;
//---------------------------------------------------------------------------
__fastcall TViewForm::TViewForm(TComponent* Owner)
	: TForm(Owner)
{
	fileName = String();
}
//---------------------------------------------------------------------------

void TViewForm::loadLines(char * fileNameNew) {

	fileName = String(fileNameNew);

	Memo->Lines->LoadFromFile(fileName);
}
//---------------------------------------------------------------------------

void __fastcall TViewForm::SaveButtonClick(TObject *Sender)
{
	TStringList * list = new TStringList();

	list->AddStrings(Memo->Lines);
	list->Sort();

	list->SaveToFile(fileName);

	delete list;

	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TViewForm::CancelButtonClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

