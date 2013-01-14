//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <CheckLst.hpp>
#include <Menus.hpp>
#include "Unit2.h"
#include "Unit3.h"
#include "cspin.h"
#include <ExtCtrls.hpp>
#include <vector>
#include "cspin.h"

#define MAX_TERM 20

struct MolingState {
	int molingNum;
	bool termsState[MAX_TERM];
};

struct MolingNode {
	int MolingStateID;
	std::vector<int> termsSet;
	std::vector<int> chieldsID;
};

//---------------------------------------------------------------------------
class TMainMenuForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TCheckListBox *TermsCheckListBox;
	TMainMenu *MainMenu;
	TMenuItem *FileMenu;
	TMenuItem *AddMolingMenu;
	TMenuItem *ExitMenu;
	TMemo *ResultMemo;
	TMenuItem *DictionaryMenu;
	TMenuItem *TermMenu;
	TMenuItem *RelationshipMenu;
	TMenuItem *QualitativeFeature;
	TMenuItem *QuantitativeAttribute;
	TMenuItem *LogLingLink;
	TButton *SearchButton;
	TMenuItem *MolingsMenu;
	TLabel *Label2;
	TRadioGroup *SearchModeRadioGroup;
	TGroupBox *SearchLimitGroupBox;
	TGroupBox *CohesionGroupBox;
	TCheckBox *LimitCheckBox;
	TCheckBox *CohesionCheckBox;
	TCSpinEdit *LimitCSpinEdit;
	TCSpinEdit *CohesionCSpinEdit;
	TLabel *Label3;
	TLabel *Label4;
	TMenuItem *SourceMenu;
	TGroupBox *GroupBox1;
	TCSpinEdit *DeepCSpinEdit;
	TLabel *Label5;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall MolingsMenuClick(TObject *Sender);
	void __fastcall TermMenuClick(TObject *Sender);
	void __fastcall RelationshipMenuClick(TObject *Sender);
	void __fastcall QualitativeFeatureClick(TObject *Sender);
	void __fastcall QuantitativeAttributeClick(TObject *Sender);
	void __fastcall LogLingLinkClick(TObject *Sender);
	void __fastcall LimitCheckBoxClick(TObject *Sender);
	void __fastcall CohesionCheckBoxClick(TObject *Sender);
	void __fastcall AddMolingMenuClick(TObject *Sender);
	void __fastcall ExitMenuClick(TObject *Sender);
	void __fastcall SourceMenuClick(TObject *Sender);
	void __fastcall SearchButtonClick(TObject *Sender);
	void __fastcall SearchModeRadioGroupClick(TObject *Sender);
private:	// User declarations
	TViewForm *Viewer;
	TAddMolingForm *AddMoling;
	std::vector<Moling> molings;
	std::vector< std::vector<String> > terms;

	void loadMolings(char *fileName);
	void loadTerms();
public:		// User declarations
	__fastcall TMainMenuForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainMenuForm *MainMenuForm;
//---------------------------------------------------------------------------
#endif
