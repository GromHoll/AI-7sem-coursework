//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TViewForm : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo;
	TButton *SaveButton;
	TButton *CancelButton;
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall CancelButtonClick(TObject *Sender);

private:	// User declarations
	String fileName;
public:		// User declarations
	__fastcall TViewForm(TComponent* Owner);

	void loadLines(char * fileName);
};
//---------------------------------------------------------------------------
extern PACKAGE TViewForm *ViewForm;
//---------------------------------------------------------------------------
#endif
