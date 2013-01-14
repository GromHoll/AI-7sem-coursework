//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#pragma hdrstop

#include "Unit1.h"

using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma link "cspin"
#pragma resource "*.dfm"
TMainMenuForm *MainMenuForm;

struct MolingCombo {
	vector<int> molingIDs;
	bool * terms;
};

void swapMoling(Moling& m1, Moling& m2) {
	Moling t;

	t.ID[0] = m1.ID[0];
	t.ID[1] = m1.ID[1];
	t.ID[2] = m1.ID[2];
	t.ID[3] = m1.ID[3];
	t.ID[4] = m1.ID[4];
	t.ID[5] = m1.ID[5];
	t.kernel = m1.kernel;
	t.codes = m1.codes;
	t.value = m1.value;

	m1.ID[0] = m2.ID[0];
	m1.ID[1] = m2.ID[1];
	m1.ID[2] = m2.ID[2];
	m1.ID[3] = m2.ID[3];
	m1.ID[4] = m2.ID[4];
	m1.ID[5] = m2.ID[5];
	m1.kernel = m2.kernel;
	m1.codes = m2.codes;
	m1.value = m2.value;

	m2.ID[0] = t.ID[0];
	m2.ID[1] = t.ID[1];
	m2.ID[2] = t.ID[2];
	m2.ID[3] = t.ID[3];
	m2.ID[4] = t.ID[4];
	m2.ID[5] = t.ID[5];
	m2.kernel = t.kernel;
	m2.codes = t.codes;
	m2.value = t.value;

}

bool compareMolingID(const Moling& m1, const Moling& m2) {
	for(int i = 0; i < 6; i++) {
		if(m1.ID[i] != m2.ID[i])
			return false;
    }
	return true;
}

//---------------------------------------------------------------------------
__fastcall TMainMenuForm::TMainMenuForm(TComponent* Owner)
	: TForm(Owner)
{
	Viewer = new TViewForm(this);
	AddMoling = new TAddMolingForm(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::FormCreate(TObject *Sender)
{
	ResultMemo->Clear();

	TermsCheckListBox->Items->LoadFromFile("1.txt");
	loadTerms();

	SearchModeRadioGroup->Items->Add("Any term");
	SearchModeRadioGroup->Items->Add("All terms");
	SearchModeRadioGroup->Items->Add("Logical inference");
	SearchModeRadioGroup->ItemIndex = 0;
    DeepCSpinEdit->Enabled = false;

	loadMolings("kb.txt");
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::MolingsMenuClick(TObject *Sender)
{
	Viewer->Caption = "Molings view";
	Viewer->loadLines("kb.txt");
	Viewer->ShowModal();
	loadMolings("kb.txt");
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::TermMenuClick(TObject *Sender)
{
	Viewer->Caption = "Terms view";
	Viewer->loadLines("1.txt");
	Viewer->ShowModal();

	TermsCheckListBox->Items->LoadFromFile("1.txt");
	loadTerms();
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::RelationshipMenuClick(TObject *Sender)
{
	Viewer->Caption = "Relationships view";
	Viewer->loadLines("2.txt");
	Viewer->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::QualitativeFeatureClick(TObject *Sender)
{
	Viewer->Caption = "Qualitative Feature view";
	Viewer->loadLines("3.txt");
	Viewer->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::QuantitativeAttributeClick(TObject *Sender)
{
	Viewer->Caption = "Quantitative Attribute view";
	Viewer->loadLines("4.txt");
	Viewer->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::LogLingLinkClick(TObject *Sender)
{
	Viewer->Caption = "Logical/Linguistic Link view";
	Viewer->loadLines("5.txt");
	Viewer->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::LimitCheckBoxClick(TObject *Sender)
{
	LimitCSpinEdit->Enabled = !LimitCSpinEdit->Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::CohesionCheckBoxClick(TObject *Sender)
{
 	CohesionCSpinEdit->Enabled = !CohesionCSpinEdit->Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::AddMolingMenuClick(TObject *Sender)
{
	AddMoling->ShowModal();
	loadMolings("kb.txt");
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::ExitMenuClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainMenuForm::SourceMenuClick(TObject *Sender)
{
	Viewer->Caption = "Source view";
	Viewer->loadLines("source.txt");
	Viewer->ShowModal();
}
//---------------------------------------------------------------------------

void TMainMenuForm::loadMolings(char *fileName)
{
    molings.clear();

	TStringList * SL = new TStringList();
	SL->LoadFromFile(fileName);

	Moling m;
	int pos = 0;
	for(int i = 0; i < SL->Count; i++) {
		molings.push_back(strToMoling(SL->Strings[i]));
	}

	for(int i = 0; i < molings.size() - 1; i++) {
		double max = molings[i].value;
		for(int j = i + 1; j < molings.size(); j++) {
			if(max < molings[j].value) {
				max = molings[j].value;
				swapMoling(molings[i], molings[j]);
			}
		}
	}

}

void TMainMenuForm::loadTerms() {

	terms.clear();

	for(int i = 0; i < TermsCheckListBox->Count; i++) {
		vector<String> sinonims;
		String temp = TermsCheckListBox->Items->Strings[i];

		while(temp.Pos(',') != 0) {
			sinonims.push_back(temp.SubString(0, temp.Pos(',') - 1));
			temp = temp.SubString(temp.Pos(',') + 2, temp.Length());
		}
		sinonims.push_back(temp);

		terms.push_back(sinonims);
    }
}

void __fastcall TMainMenuForm::SearchButtonClick(TObject *Sender)
{
	ResultMemo->Clear();

	/* Allocate */

	bool ** matrix;
	matrix = new bool*[terms.size()];
	for(int i = 0; i < terms.size(); i++) {
		matrix[i] = new bool[molings.size()];
	}

	/* Prepare */

	for(int i = 0; i < terms.size(); i++) {
		for(int j = 0; j < molings.size(); j++) {
			matrix[i][j] = false;
			for(int k = 0; k < terms[i].size(); k++) {
				if(molings[j].kernel.LowerCase().Pos(terms[i][k].LowerCase()) != 0) {
					matrix[i][j] = true;
					break;
                }
            }
		}
    }

	/* Find */

	vector<int> searchTerms;
	for(int i = 0; i < TermsCheckListBox->Count; i++) {
		if(TermsCheckListBox->Checked[i]) {
			searchTerms.push_back(i);
		}
	}

	if(searchTerms.size() == 0) {
		ResultMemo->Lines->Add("Terms not checked.");
		return;
	}

	if(searchTerms.size() >= MAX_TERM) {
		ResultMemo->Lines->Add("Too much terms.");
		return;
	}

	if(SearchModeRadioGroup->ItemIndex != 2) {

		vector<Moling> res;
		for(int i = 0; i < molings.size(); i++) {
			if(SearchModeRadioGroup->ItemIndex == 0) {
				for(int j = 0; j < searchTerms.size(); j++) {
					if(matrix[searchTerms[j]][i]) {
						res.push_back(molings[i]);
						break;
					}
				}
			} else {
				bool f = true;
				for(int j = 0; j < searchTerms.size(); j++) {
					if(!matrix[searchTerms[j]][i]) {
						f = false;
						break;
					}
				}
				if(f)
					res.push_back(molings[i]);
			}
		}

		if(res.size() == 0) {
			ResultMemo->Lines->Add("Result is empty.");
			return;
		}

		vector< vector<Moling> > totalRes;

		for(int i = 0; i < res.size(); i++) {
			vector<Moling> newVector;
			newVector.push_back(res[i]);

			if(CohesionCheckBox->Checked) {
				Moling temp;
				temp.ID[0] = res[i].ID[0];
				temp.ID[1] = res[i].ID[1];
				temp.ID[2] = res[i].ID[2];
				temp.ID[3] = res[i].ID[3];
				temp.ID[4] = res[i].ID[4];

				for(int j = 1; j <= CohesionCSpinEdit->Value; j++) {
					temp.ID[5] = res[i].ID[5] - j;
					for(int k = 0; k < molings.size(); k++) {
						if(compareMolingID(temp, molings[k])) {
							newVector.insert(newVector.begin(), molings[k]);
						}
					}
				}

				for(int j = 1; j <= CohesionCSpinEdit->Value; j++) {
					temp.ID[5] = res[i].ID[5] + j;
					for(int k = 0; k < molings.size(); k++) {
						if(compareMolingID(temp, molings[k])) {
							newVector.push_back(molings[k]);
						}
					}
				}
			}
			totalRes.push_back(newVector);
		}

		if(LimitCheckBox->Checked) {
			for(int i = 0; i < totalRes.size() && i < LimitCSpinEdit->Value; i++) {
				for(int j = 0; j < totalRes[i].size(); j++) {
					ResultMemo->Lines->Add(totalRes[i][j].kernel + " (" + totalRes[i][j].value + ")");
				}
				ResultMemo->Lines->Add("");
			}
		} else {
			for(int i = 0; i < totalRes.size(); i++) {
				for(int j = 0; j < totalRes[i].size(); j++) {
					ResultMemo->Lines->Add(totalRes[i][j].kernel + " (" + totalRes[i][j].value + ")");
				}
				ResultMemo->Lines->Add("");
			}
		}

	} else {
		vector<MolingCombo> res;

		vector<MolingCombo> prev;
		vector<MolingCombo> next;

		for(int i = 0; i < molings.size(); i++) {
			for(int j = 0; j < searchTerms.size(); j++) {
				if(matrix[searchTerms[j]][i]) {

					MolingCombo t;
					t.molingIDs.push_back(i);

					t.terms = new bool[terms.size()];
					for(int k = 0; k < terms.size(); k++) {
                    	t.terms[k] = matrix[k][i];
                    }

					prev.push_back(t);
					break;
				}
			}
		}

		for(int i = 0; i < prev.size(); i++) {
			bool f = true;
			for(int j = 0; j < searchTerms.size(); j++) {
				if(!prev[i].terms[searchTerms[j]]) {
					f = false;
					break;
				}
			}
			if(f) {
				res.push_back(prev[i]);
			} else {
				next.push_back(prev[i]);
			}
		}

		prev = next;
		next.clear();

		for(int iter = 1; iter < DeepCSpinEdit->Value; iter++) {
			for(int i = 0; i < prev.size(); i++) {
				for(int j = 0; j < molings.size(); j++) {

				    // Contene this moling now?
					bool f = false;
					for(int k = 0; k < prev[i].molingIDs.size(); k++) {
						if(prev[i].molingIDs[k] == j) {
							f = true;
							break;
						}
					}

					if(f) continue;

					// Have cross?
					f = false;
					for(int k = 0; k < terms.size(); k++) {
						if(prev[i].terms[k] && matrix[k][j]) {
							f = true;
							break;
						}
					}

					if(!f) continue;

					MolingCombo t;
					t.molingIDs = prev[i].molingIDs;
					t.molingIDs.push_back(j);

					t.terms = new bool[terms.size()];
					for(int k = 0; k < terms.size(); k++) {
						t.terms[k] = matrix[k][j] || prev[i].terms[k];
					}

					f = true;
					for(int k = 0; k < searchTerms.size(); k++) {
						if(!t.terms[searchTerms[k]]) {
							f = false;
							break;
						}
					}

					if(f) {
						res.push_back(t);
					} else {
						next.push_back(t);
					}
				}
			}

			for(int i = 0; i < prev.size(); i++) {
				delete[] prev[i].terms;
			}
            prev.clear();
			prev = next;
			next.empty();

		}

		for(int i = 0; i < prev.size(); i++) {
			delete[] prev[i].terms;
		}

  		for(int i = 0; i < res.size(); i++) {
			delete[] res[i].terms;
		}

		vector<MolingCombo> finalRes;

		for(int i = 0; i < res.size(); i++) {
			bool exist = false;
			for(int j = 0; j < finalRes.size(); j++) {
				bool f1 = true;
				if(res[i].molingIDs.size() != finalRes[j].molingIDs.size())
					continue;

				for(int k = 0; k < res[i].molingIDs.size(); k++) {
					bool f2 = false;
					for(int l = 0; l < finalRes[j].molingIDs.size(); l++) {
						if(res[i].molingIDs[k] == finalRes[j].molingIDs[l]) {
							 f2 = true;
							 break;
                        }
					}

					if(!f2) {
						f1 = false;
						break;
                    }
				}

				if(f1) {
					exist = true;
                    break;
                }
			}
			if(!exist)
				finalRes.push_back(res[i]);
		}

		if(finalRes.size() != 0) {
			for(int i = 0; i < finalRes.size(); i++) {
				double v = 1;
				for(int j = 0; j < finalRes[i].molingIDs.size(); j++) {
					ResultMemo->Lines->Add(molings[finalRes[i].molingIDs[j]].kernel
							+ " (" + molings[finalRes[i].molingIDs[j]].value + ")");
					v *= molings[finalRes[i].molingIDs[j]].value;
				}
				ResultMemo->Lines->Add("[ " + String(v) + " ]");
				ResultMemo->Lines->Add("");
            }
		} else {
        	ResultMemo->Lines->Add("Result is empty.");
		}

		res.clear();
		prev.clear();
	}

	/* Delete */

	for(int i = 0; i < terms.size(); i++) {
		delete[] matrix[i];
    }
	delete[] matrix;
}

void __fastcall TMainMenuForm::SearchModeRadioGroupClick(TObject *Sender)
{
	if(SearchModeRadioGroup->ItemIndex == 2) {
		DeepCSpinEdit->Enabled = true;
	} else {
        DeepCSpinEdit->Enabled = false;
    }
}
//---------------------------------------------------------------------------

