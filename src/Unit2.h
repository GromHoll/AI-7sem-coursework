//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>

//---------------------------------------------------------------------------
struct Moling
{
	int ID[6];
	String kernel;
	String codes;
	double value;
};

String molingToStr(Moling m);
Moling strToMoling(String s);
//---------------------------------------------------------------------------
class TAddMolingForm : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TEdit *IDEdit1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *IDEdit4;
	TEdit *IDEdit2;
	TEdit *IDEdit3;
	TEdit *IDEdit6;
	TEdit *IDEdit5;
	TLabel *Label7;
	TEdit *KernelEdit;
	TLabel *Label8;
	TEdit *CodesEdit;
	TLabel *Label9;
	TEdit *ValueEdit;
	TTrackBar *ValueTrackBar;
	TButton *CancelButton;
	TButton *AddButton;
	void __fastcall ValueTrackBarChange(TObject *Sender);
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAddMolingForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddMolingForm *AddMolingForm;
//---------------------------------------------------------------------------
#endif
